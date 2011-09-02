module rlisp;  % Header module for rlisp package.

% Author: Anthony C. Hearn.

global '(date!* version!*);

create!-package('(rlisp newtok support slfns superv tok xread
                  lpri parser block form proc forstat loops statmisc
                  smacro infix switch where list array io inter),
                 nil);

date!* := "15-Oct-93";

version!* := "REDUCE 3.5";

% Hook to Rlisp88.

put('rlisp88,'simpfg,'((t (load!-package 'rlisp88) (rlisp88_on))));

flag('(rlisp88),'switch);

endmodule;


module newtok;  % Functions for introducing infix tokens to the system.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*msg !*redeflg!*);

global '(preclis!* fixedpreclis!*);

% Several operators in REDUCE are used in an infix form (e.g., +,- ).
% The internal alphanumeric names associated with these operators are
% introduced by the function NEWTOK defined below.  This association,
% and the precedence of each infix operator, is initialized in this
% section.  We also associate printing characters with each internal
% alphanumeric name as well.

fixedpreclis!* := '(!*comma!* setq);

preclis!*:= '(or and not member memq equal neq eq geq greaterp leq
              lessp freeof plus difference times quotient expt cons);

deflist ('(
   (not not)
   (plus plus)
   (difference minus)
   (minus minus)
   (times times)
   (quotient recip)
   (recip recip)
 ), 'unary);

flag ('(and or !*comma!* plus times),'nary);

flag ('(cons setq plus times),'right);

deflist ('((minus plus) (recip times)),'alt);

symbolic procedure mkprec;
   begin scalar x,y,z;
        x := append(fixedpreclis!*,preclis!*);
        y := 1;
    a:  if null x then return nil;
        put(car x,'infix,y);
        put(car x,'op,list list(y,y));   % for RPRINT.
        if z := get(car x,'unary) then put(z,'infix,y);
        if and(z,null flagp(z,'nary)) then put(z,'op,list(nil,y));
        x := cdr x;
        y := add1 y;
        go to a
   end;

mkprec();

symbolic procedure newtok u;
   begin scalar !*redeflg!*,x,y;
      if atom u or atom car u or null idp caar u
        then typerr(u,"NEWTOK argument");
      % set up SWITCH* property.
      put(caar u,'switch!*,
          cdr newtok1(car u,cadr u,get(caar u,'switch!*)));
      % set up PRTCH property.
      y := intern compress consescc car u;
      if !*redeflg!* then lprim list(y,"redefined");
      put(cadr u,'prtch,y);
      if x := get(cadr u,'unary) then put(x,'prtch,y)
   end;

symbolic procedure newtok1(charlist,name,propy);
      if null propy then lstchr(charlist,name)
       else if null cdr charlist
        then begin
                if cdr propy and !*msg then !*redeflg!* := t;
                return list(car charlist,car propy,name)
             end
       else car charlist . newtok2(cdr charlist,name,car propy)
                         . cdr propy;

symbolic procedure newtok2(charlist,name,assoclist);
   if null assoclist then list lstchr(charlist,name)
    else if car charlist eq caar assoclist
     then newtok1(charlist,name,cdar assoclist) . cdr assoclist
    else car assoclist . newtok2(charlist,name,cdr assoclist);

symbolic procedure consescc u;
   if null u then nil else '!! . car u . consescc cdr u;

symbolic procedure lstchr(u,v);
   if null cdr u then list(car u,nil,v)
    else list(car u,list lstchr(cdr u,v));

newtok '((!$) !*semicol!*);
newtok '((!;) !*semicol!*);
newtok '((!+) plus);
newtok '((!-) difference);
newtok '((!*) times);
newtok '((!^) expt);
newtok '((!* !*) expt);
newtok '((!/) quotient);
newtok '((!=) equal);
newtok '((!,) !*comma!*);
newtok '((!() !*lpar!*);
newtok '((!)) !*rpar!*);
newtok '((!:) !*colon!*);
newtok '((!: !=) setq);
newtok '((!.) cons);
newtok '((!<) lessp);
newtok '((!< !=) leq);
newtok '((!< !<) !*lsqbkt!*);
newtok '((!>) greaterp);
newtok '((!> !=) geq);
newtok '((!> !>) !*rsqbkt!*);

put('expt,'prtch,'!*!*);   % To ensure that FORTRAN output is correct.

flag('(difference minus plus setq),'spaced);

flag('(newtok),'eval);

endmodule;


module support;   % Basic functions needed to support RLISP and REDUCE.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*backtrace);

global '(!*comp);

symbolic procedure aconc(u,v);
   % Adds element v to the tail of u. u is destroyed in process.
   nconc(u,list v);

symbolic procedure arrayp u; get(u,'rtype) eq 'array;

symbolic procedure atsoc(u,v);
   % This definition allows for a search of a general list.
   if null v then nil
    else if eqcar(car v,u) then car v
    else atsoc(u,cdr v);

symbolic procedure copyd(new,old);
   % Copy the function definition from old id to new.
   begin scalar x;
      x := getd old;
      if null x
        then rerror('rlisp,1,list(old,"has no definition in copyd"));
      putd(new,car x,cdr x);
      return new
   end;

symbolic procedure eqcar(u,v); null atom u and car u eq v;

symbolic procedure errorset!*(u,v); errorset(u,v,!*backtrace);

symbolic procedure flagpcar(u,v);
   null atom u and idp car u and flagp(car u,v);

symbolic procedure idlistp u;
   % True if u is a list of id's.
   null u or null atom u and idp car u and idlistp cdr u;

symbolic procedure listp u;
   % Returns T if U is a top level list.
   null u or null atom u and listp cdr u;

symbolic procedure mkprog(u,v); 'prog . (u . v);

symbolic procedure mkquote u; list('quote,u);

symbolic procedure mksetq(u,v); list('setq,u,v);

symbolic procedure pairvars(u,vars,mode);
   % Sets up pairings of parameters and modes.
   begin scalar x;
   a: if null u then return append(reversip!* x,vars)
       else if null idp car u then symerr("Invalid parameter",nil);
      x := (car u . mode) . x;
      u := cdr u;
      go to a
   end;

symbolic procedure prin2t u; progn(prin2 u, terpri(), u);

% The following is included for compatibility with some old code.
% Its use is discouraged.

symbolic procedure princ u; prin2 u;

symbolic procedure putc(name,type,body);
   % Defines a non-standard function, such as an smacro. Returns NAME.
   begin
      if !*comp and flagp(type,'compile) then compd(name,type,body)
       else put(name,type,body);
      return name
   end;

% flag('(putc),'eval);

symbolic procedure reversip u;
   begin scalar x,y;
    a:  if null u then return y;
        x := cdr u; y := rplacd(u,y); u := x;
        go to a
   end;

symbolic procedure smemq(u,v);
   % True if id U is a member of V at any level (excluding quoted
   % expressions).
   if atom v then u eq v
    else if car v eq 'quote then nil
    else smemq(u,car v) or smemq(u,cdr v);

symbolic procedure subsetp(u,v);
   % True if u is a subset of v.
   null u or car u member v and subsetp(cdr u,v);

symbolic procedure union(x,y);
   if null x then y
    else union(cdr x,if car x member y then y else car x . y);

symbolic procedure intersection(u,v);
   % This definition is consistent with PSL.
   if null u then nil
    else if car u member v
     then car u . intersection(cdr u,delete(car u,v))
    else intersection(cdr u,v);

symbolic procedure u>=v; null(u<v);

symbolic procedure u<=v; null(u>v);

symbolic procedure u neq v; null(u=v);

symbolic procedure setdiff(u,v);
   if null v then u
    else if null u then nil
    else setdiff(delete(car v,u),cdr v);

% symbolic smacro procedure u>=v; null(u<v);

% symbolic smacro procedure u<=v; null(u>v);

% symbolic smacro procedure u neq v; null(u=v);

% List changing alternates (may also be defined as copying functions).

symbolic procedure aconc!*(u,v); nconc(u,list v);  % append(u,list v);

symbolic procedure nconc!*(u,v); nconc(u,v);       % append(u,v);

symbolic procedure reversip!* u; reversip u;       % reverse u;

symbolic procedure rplaca!*(u,v); rplaca(u,v);     % v . cdr u;

symbolic procedure rplacd!*(u,v); rplacd(u,v);     % car u . v;

% The following functions should be provided in the compiler for
% efficient coding.

symbolic procedure lispapply(u,v);
   % I'd like to use idp in the following test, but the TPS package
   % stores code pointers on property lists which then get used here.
   if null atom u
     then rerror('rlisp,2,list("Apply called with non-id arg",u))
    else apply(u,v);

symbolic procedure lispeval u; eval u;

symbolic procedure apply1(u,v); apply(u,list v);

symbolic procedure apply2(u,v,w); apply(u,list(v,w));

symbolic procedure apply3(u,v,w,x); apply(u,list(v,w,x));

% The following function is needed by several modules. It is more
% REDUCE-specific than other functions in this module, but since it
% needs to be defined early on, it might as well go here.

symbolic procedure gettype u;
   % Returns a REDUCE-related type for the expression U.
   % It needs to be more table driven than the current definition.
   if numberp u then 'number
    else if null atom u or null u or null idp u then 'form
    else if get(u,'simpfn) then 'operator
    else if get(u,'avalue) then car get(u,'avalue)
    else if getd u then 'procedure
    else if globalp u then 'global
    else if fluidp u then 'fluid
    else if flagp(u,'parm) then 'parameter
    else get(u,'rtype);

endmodule;


module slfns;  % Complete list of Standard LISP functions.

% Author: Anthony C. Hearn.

global '(!*argnochk slfns!*);

slfns!* := '(
        (abs 1)
        (add1 1)
        (append 2)
        (apply 2)
        (assoc 2)
        (atom 1)
        (car 1)
        (cdr 1)
        (caar 1)
        (cadr 1)
        (cdar 1)
        (cddr 1)
        (caaar 1)
        (caadr 1)
        (cadar 1)
        (caddr 1)
        (cdaar 1)
        (cdadr 1)
        (cddar 1)
        (cdddr 1)
        (caaaar 1)
        (caaadr 1)
        (caadar 1)
        (caaddr 1)
        (cadaar 1)
        (cadadr 1)
        (caddar 1)
        (cadddr 1)
        (cdaaar 1)
        (cdaadr 1)
        (cdadar 1)
        (cdaddr 1)
        (cddaar 1)
        (cddadr 1)
        (cdddar 1)
        (cddddr 1)
        (close 1)
        (codep 1)
        (compress 1)
        (cons 2)
        (constantp 1)
        (de 3)
        (deflist 2)
        (delete 2)
%       (DF 3)                     conflicts with algebraic operator DF
        (difference 2)
        (digit 1)
        (divide 2)
        (dm 3)
        (dn 3)
        (ds 3)
        (eject 0)
        (eq 2)
        (eqn 2)
        (equal 2)
        (error 2)
        (errorset 3)
        (eval 1)
        (evlis 1)
        (expand 2)
        (explode 1)
        (expt 2)
        (fix 1)
        (fixp 1)
        (flag 2)
        (flagp 2)
        (float 1)
        (floatp 1)
        (fluid 1)
        (fluidp 1)
        (function 1)
        (gensym 0)
        (get 2)
        (getd 1)
        (getv 2)
        (global 1)
        (globalp 1)
        (go 1)
        (greaterp 2)
        (idp 1)
        (intern 1)
        (length 1)
        (lessp 2)
        (linelength 1)
        (liter 1)
        (lposn 0)
        (map 2)
        (mapc 2)
        (mapcan 2)
        (mapcar 2)
        (mapcon 2)
        (maplist 2)
        (max2 2)
        (member 2)
        (memq 2)
        (minus 1)
        (minusp 1)
        (min2 2)
        (mkvect 1)
        (nconc 2)
        (not 1)
        (null 1)
        (numberp 1)
        (onep 1)
        (open 2)
        (pagelength 1)
        (pair 2)
        (pairp 1)
        (plus2 2)
        (posn 0)
        (print 1)
        (prin1 1)
        (prin2 1)
        (prog2 2)
        (put 3)
        (putd 3)
        (putv 3)
        (quote 1)
        (quotient 2)
        (rds 1)
        (read 0)
        (readch 0)
        (remainder 2)
        (remd 1)
        (remflag 2)
        (remob 1)
        (remprop 2)
        (return 1)
        (reverse 1)
        (rplaca 2)
        (rplacd 2)
        (sassoc 3)
        (set 2)
        (setq 2)
        (stringp 1)
        (sublis 2)
        (subst 3)
        (sub1 1)
        (terpri 0)
        (times2 2)
        (unfluid 1)
        (upbv 1)
        (vectorp 1)
        (wrs 1)
        (zerop 1)
        );

if !*argnochk then deflist(slfns!*,'number!-of!-args);

endmodule;


module superv; % REDUCE supervisory functions.

% Author: Anthony C. Hearn.

% Modified by: Jed B. Marti.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*defn
        !*demo
        !*echo
        !*errcont
        !*int
        !*lisp_hook
        !*mode
        !*output
        !*pret
        !*slin
        !*time
        dfprint!*
        loopdelimslist!*
        lreadfn!*
        semic!*
        tslin!*);

global '(!$eof!$
         !*byeflag!*
         !*extraecho
         !*lessspace
         !*micro!-version
         !*nosave!*
         !*strind
         !*struct
         cloc!*
         cmsg!*
         crbuf!*
         crbuflis!*
         crbuf1!*
         curline!*
         cursym!*
         eof!*
         erfg!*
         forkeywords!*
         ifl!*
         ipl!*
         initl!*
         inputbuflis!*
         key!*
         ofl!*
         opl!*
         ogctime!*
         otime!*
         program!*
         programl!*
         promptexp!*
         repeatkeywords!*
         resultbuflis!*
         st!*
         statcounter
         symchar!*
         tok!*
         ttype!*
         whilekeywords!*
         ws);

!*output := t;
eof!* := 0;
initl!* := '(fname!* outl!*);
statcounter := 0;

% The true REDUCE supervisory function is BEGIN, again defined in the
% system dependent part of this program.  However, most of the work is
% done by BEGIN1, which is called by BEGIN for every file encountered
% on input;

symbolic procedure errorp u;
   %returns true if U is an ERRORSET error format;
   atom u or cdr u;

symbolic procedure flagp!*!*(u,v); idp u and flagp(u,v);

symbolic procedure printprompt u;
   %Prints the prompt expression for input;
   progn(ofl!* and wrs nil, prin2 u, ofl!* and wrs cdr ofl!*);

symbolic procedure setcloc!*;
   % Used to set for file input a global variable CLOC!* to dotted pair
   % of file name and dotted pair of line and page being read.
   % Currently a place holder for system specific function, since not
   % supported in Standard LISP.  CLOC!* is used in the INTER and RCREF
   % modules.
   cloc!* := if null ifl!* then nil else car ifl!* . (1 . curline!*);

symbolic procedure command1;
   % Innermost part of COMMAND. Can be used as hook to editor if needed.
   begin
      scan();
      setcloc!*();
      key!* := cursym!*;
      return xread1 nil
   end;

symbolic procedure commdemo;
   begin scalar echo,x,y,z,!*demo;
      echo := !*echo;
      !*echo := nil;
      x := ifl!*;
      terpri();
      rds nil;
      y:=readch();
      if null seprp y then
             % Read command line from terminal.
          begin scalar crbuf,crbuf1,crchar,ifl;
                crbuf := crbuf!*;
                crbuf!* := nil;
                crbuf1 := crbuf1!*;
                crbuf1!* := list y;
                crchar := crchar!*;
                crchar!* := '! ;
                ifl := ifl!*;
                ifl!* := nil;
                z := errorset!*('(command),t);
                z := if errorp z then '(algebraic(aeval 0))
                     else car z;
                     % eat rest of line quietly.
             q: y  := readch();
                if y neq !$eol!$ then go to q;
                rds cadr x;
                crbuf!* := crbuf;
                crbuf1!* := crbuf1;
                crchar!* := crchar;
                ifl!* := ifl;
                !*echo := echo;
          end
       else
             % Read command from current input.
          progn(rds cadr x, !*echo := echo, z := command());
       return z
   end;

symbolic procedure command;
   begin scalar loopdelimslist!*,mode,x,y;
      if !*demo and ifl!* then return commdemo();
    % Initialize crchar!*.
   a: crchar!* := readch1();
      if crchar!* = !$eol!$ then go to a;
      if null !*slin then x := command1()
       else progn(key!* := '!;,
                  setcloc!*(),
                  x := (if lreadfn!* then lispapply(lreadfn!*,nil)
                        else read()),
                  if key!* eq '!;
                    then key!* := if atom x then x else car x);
      if !*struct then x := structchk x;
      if !*pret then progn(terpri(),rprint x);
      if null !*slin then x := form x;
      % Now determine target mode.
      if flagp!*!*(key!*,'modefn) then mode := key!*
%      else if key!* eq 'input
%            then if (y := assoc(cadr x,inputbuflis!*))
%                   then return cdr y
%                  else progn(lprim "Entry not found",
%                             terpri(),
%                             go to a)
       else if null atom x % and null !*micro!-version
         and null(car x eq 'quote)
         and (null(idp car x
                 and (flagp(car x,'nochange)
                       or flagp(car x,'intfn)
                       or car x eq 'list))
           or car x memq '(setq setel setf)
                   and eqcar(caddr x,'quote))
        then mode := 'symbolic
       else mode := !*mode;
      return list(mode,convertmode1(x,nil,'symbolic,mode))
   end;

symbolic procedure begin1;
   begin scalar mode,parserr,result,x;
        otime!* := time();
        % the next line is that way for bootstrapping purposes.
        if getd 'gctime then ogctime!* := gctime() else ogctime!* := 0;
        cursym!* := '!*semicol!*;
    a:  if null terminalp() or !*nosave!* then go to b
         else if statcounter>0 then add2buflis();
        statcounter := statcounter + 1;
    %   crbuf1!* := nil;   % For input string editor.
        !*strind := 0;     % Used by some versions of input editor.
        promptexp!* :=
           compress('!! . append(explode statcounter,
                       explode if null symchar!* or !*mode eq 'algebraic
                                 then '!:!  else '!*! ));
        setpchar promptexp!*;
    b:  parserr := nil;
        !*nosave!* := nil;
        if !*time then lispeval '(showtime);   %Since a STAT;
        if !*output and null ofl!* and terminalp() and null !*defn
           and null !*lessspace
          then terpri();
        if tslin!*
          then progn(!*slin := car tslin!*,
                     lreadfn!* := cdr tslin!*,
                     tslin!* := nil);
        mapcar(initl!*,function sinitl);
        remflag(forkeywords!*,'delim);
        remflag(repeatkeywords!*,'delim);
        remflag( whilekeywords!*,'delim);
        if !*int then erfg!* := nil;    %to make editing work properly;
        if cursym!* eq 'end then progn(comm1 'end, return nil)
         % Note that key* was set from *previous* command in following.
         else if terminalp() and null(key!* eq 'ed)
          then printprompt promptexp!*;
        x := errorset!*('(command),t);
        condterpri();
        if errorp x then go to err1;
        x := car x;
        if cursym!* eq 'end
           then if terminalp() and null !*lisp_hook
                  then progn(cursym!* := '!*semicol!*, go to b)
                 else progn(comm1 'end, return nil)
         else if eqcar(cadr x,'retry)
          then if programl!* then x := programl!*
                else progn(lprim "No previous expression",go to a);
        mode := car x;
        x := cadr x;
        program!* := x;    % Keep it around for debugging purposes.
        if eofcheck() then go to c else eof!* := 0;
        add2inputbuf(x,mode);
        if null atom x
            and car x memq '(bye quit)
          then if getd 'bye then progn(lispeval x, go to b)
                else progn(!*byeflag!* := t, return nil)
         else if eqcar(x,'ed)
          then progn((if getd 'cedit and terminalp()
                        then cedit cdr x
                       else lprim "ED not supported"),
                     go to b)
         else if !*defn
          then if erfg!* then go to a
                else if null flagp!*!*(key!*,'ignore)
                  and null eqcar(x,'quote)
                 then go to d;
    b1: if !*output and ifl!* and !*echo and null !*lessspace
          then terpri();
        result := errorset!*((if mode eq 'symbolic then x
                               else list('assgneval,mkquote x)),
                              t);
        if errorp result or erfg!*
          then progn(programl!* := list(mode,x),go to err2)
         else if !*defn then go to a;
        if null(mode eq 'symbolic)
         then progn(x := cdar result,
                    result := list caar result);
        add2resultbuf(car result,mode);
        if null !*output then go to a
         else if null(semic!* eq '!$)
          then if mode eq 'symbolic
                then if null car result and null(!*mode eq 'symbolic)
                       then nil
                 else begin
                    terpri();
                    result:= errorset!*(list('print,mkquote car result),
                                       t)
                      end
         else if car result
          then result := errorset!*(list('varpri,mkquote car result,
                                         mkquote x,
                                         mkquote 'only),
                                    t);
        if errorp result then go to err3 else go to a;
    c:  if crbuf1!* then
          progn(lprim "Closing object improperly removed. Redo edit.",
                  crbuf1!* := nil, go to a)
          else if eof!*>4
           then progn(lprim "End-of-file read", return lispeval '(bye))
         else if terminalp() then progn(crbuf!* := nil, go to b)
         else return nil;
    d:  if x then dfprint x;
        if null flagp!*!*(key!*,'eval) then go to a else go to b1;
    err1:
        if eofcheck() or eof!*>0 then go to c
         else if x="BEGIN invalid" then go to a;
        parserr := t;
    err2:
        resetparser();  %in case parser needs to be modified;
    err3:
        erfg!* := t;
        if null !*int and null !*errcont
          then progn(!*defn := t,
                     !*echo := t,
                     (if null cmsg!*
                        then lprie "Continuing with parsing only ..."),
                     cmsg!* := t)
         else if null !*errcont
          then progn(result := pause1 parserr,
                     (if result then return null lispeval result),
                     erfg!* := nil)
         else erfg!* := nil;
        go to a
   end;

flag ('(deflist flag fluid global remflag remprop unfluid),'eval);

symbolic procedure assgneval u;
   % Evaluate (possible) assignment statements and return results in a
   % form that allows required printing of such assignments.
   begin scalar x,y;
   a: if atom u then go to b
       else if car u eq 'setq then x := ('setq . cadr u) . x
       else if car u eq 'setel
        then x := ('setel . mkquote lispeval cadr u) . x
       else if car u eq 'setk
        then x := ('setk . mkquote if atom (y := lispeval cadr u)
                                     then y
                                    else car y . revlis cdr y) . x
       else go to b;
      u := caddr u;
      go to a;
   b: u := mkquote lispeval u;
   c: if null x then return(lispeval u . u);
      u := list(caar x,cdar x,u);
      x := cdr x;
      go to c
   end;

symbolic procedure close!-input!-files;
   % Close all input files currently open;
   begin
      if ifl!* then progn(rds nil,ifl!* := nil);
  aa: if null ipl!* then return nil;
      close cadar ipl!*;
      ipl!* := cdr ipl!*;
      go to aa
   end;

symbolic procedure close!-output!-files;
   % Close all output files currently open;
   begin
      if ofl!* then progn(wrs nil,ofl!* := nil);
  aa: if null opl!* then return nil;
      close cdar opl!*;
      opl!* := cdr opl!*;
      go to aa
   end;

symbolic procedure add2buflis;
   begin
      if null crbuf!* then return nil;
      crbuf!* := reversip crbuf!*;   %put in right order;
   a: if crbuf!* and seprp car crbuf!*
        then progn(crbuf!* := cdr crbuf!*, go to a);
      crbuflis!* := (statcounter . crbuf!*) . crbuflis!*;
      crbuf!* := nil
   end;

symbolic procedure add2inputbuf(u,mode);
   begin
      if null terminalp() or !*nosave!* then return nil;
      inputbuflis!* := list(statcounter,mode,u) . inputbuflis!*
   end;

symbolic procedure add2resultbuf(u,mode);
   begin
      if mode eq 'symbolic or null u or !*nosave!* then return nil;
      ws := u;
      if terminalp()
        then resultbuflis!* := (statcounter . u) . resultbuflis!*
   end;

symbolic procedure condterpri;
   !*output and !*echo and !*extraecho and (null !*int or ifl!*)
        and null !*defn and null !*demo and terpri();

symbolic procedure eofcheck;
   % true if an end-of-file has been read in current input sequence;
   program!* eq !$eof!$ and ttype!*=3 and (eof!* := eof!*+1);

symbolic procedure resetparser;
   %resets the parser after an error;
   if null !*slin then comm1 t;

symbolic procedure terminalp;
   %true if input is coming from an interactive terminal;
   !*int and null ifl!*;

symbolic procedure dfprint u;
   %Looks for special action on a form, otherwise prettyprints it;
   if dfprint!* then lispapply(dfprint!*,list u)
    else if cmsg!* then nil
    else if null eqcar(u,'progn) then prettyprint u
    else begin
            a:  u := cdr u;
                if null u then return nil;
                dfprint car u;
                go to a
         end;

symbolic procedure showtime;
   begin scalar x,y;
      x := otime!*;
      otime!* := time();
      x := otime!* - x;
      y := ogctime!*;
      ogctime!* := gctime();
      y := ogctime!* - y;
      x := x - y;
      terpri();
      prin2 "Time: "; prin2 x; prin2 " ms";
      if y = 0 then return terpri();
      prin2 "  plus GC time: "; prin2 y; prin2 " ms"
   end;

symbolic procedure sinitl u;
   set(u,eval get(u,'initl));

endmodule;


module tok; % Identifier and reserved character reading.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*adjprec !*defn !*eoldelimp !*lower !*minusliter !*quotenewnam
        semic!*);

% Note *raise is global in following for consistency with the SL Report.

global '(!$eof!$
         !$eol!$
         !*micro!-version
         !*raise
         Comment!*
         crbuf!*
         crbuf1!*
         crchar!*
         curline!*
         cursym!*
         eof!*
         ifl!*
         nxtsym!*
         outl!*
         ttype!*);

flag('(adjprec),'switch);

!*quotenewnam := t;

crchar!* := '! ;

curline!* := 1;

% The function TOKEN defined below is used for reading identifiers
% and reserved characters (such as parentheses and infix operators).
% It is called by the function SCAN, which translates reserved
% characters into their internal name, and sets up the output of the
% input line.  The following definitions of TOKEN and SCAN are quite
% general, but also inefficient.  The reading process can often be
% speeded up considerably if these functions (especially token) are
% written in terms of the explicit LISP used.

symbolic procedure prin2x u;
  outl!* := u . outl!*;

symbolic procedure mkstrng u;
   %converts the uninterned id U into a string;
   %if strings are not constants, this should be replaced by
   %list('string,u);
   u;

symbolic procedure readch1;
   begin scalar x;
      if null terminalp()
        then progn(x := readch(),
                   x eq !$eol!$ and (curline!* := curline!*+1),
                   return x)
       else if crbuf1!*
        then begin x := car crbuf1!*; crbuf1!* := cdr crbuf1!* end
       else x := readch();
      crbuf!* := x . crbuf!*;
      return x
   end;

symbolic procedure tokquote;
   begin
      crchar!* := readch1();
      nxtsym!* := mkquote rread();
      ttype!* := 4;
      return nxtsym!*
   end;

put('!','tokprop,'tokquote);

symbolic procedure token!-number x;
   % Read and return a valid number from input.
   begin scalar dotp,power,sign,y,z;
      power := 0;
      ttype!* := 2;
    num1:
      if y or null(x eq '!)) then y := x . y;
      if dotp then power := power - 1;
    num2:
      if (x := readch1()) eq '!.
         then if dotp
                then rerror('rlisp,3,"Syntax error: improper number")
               else progn(dotp := t, go to num2)
       else if digit x then go to num1
       else if null(x eq 'e) then go to ret;
      % Case of number with embedded or trailing E.
      dotp := t;
      if (x := readch1()) eq '!- then sign := t
       else if x eq '!+ then nil
       else if null digit x then go to ret
       else z := list x;
   nume1:
      if null digit(x := readch1()) then go to nume2;
      z := x . z;
      go to nume1;
   nume2:
      if null z then rerror('rlisp,4,"Syntax error: improper number");
      z := compress reversip!* z;
      if sign then power := power - z else power := power + z;
   ret:
      y := compress reversip!* y;
      nxtsym!* :=
         if dotp then '!:dn!: . (y . power)
         else if !*adjprec then '!:int!: . (y . nil)
         else y;
      crchar!* := x;
      return nxtsym!*
   end;

symbolic procedure token1;
   begin scalar x,y;
        x := crchar!*;
    a:  if seprp x and null(x eq !$eol!$ and !*eoldelimp)
          then progn(x := readch1(), go to a)
         else if digit x then return token!-number x
         else if liter x then go to letter
         else if (y := get(x,'tokprop)) then return lispapply(y,nil)
         else if x eq '!% then go to coment
         else if x eq '!! and null(!*micro!-version and null !*defn)
          then go to escape
         else if x eq '!" then go to string;
        ttype!* := 3;
        if x eq !$eof!$ then prog2(crchar!* := '! ,filenderr());
        nxtsym!* := x;
        if delcp x then crchar!*:= '!  else crchar!*:= readch1();
        if null(x eq '!- and digit crchar!* and !*minusliter)
          then go to c;
        x := token!-number crchar!*;
        if numberp x then return apply1('minus,x);  % For bootstrapping.
        rplaca(cdr x,apply1('minus,cadr x));        % Also for booting.
        return x;
    escape:
        begin scalar raise,!*lower;
           raise := !*raise;
           !*raise := nil;
           y := x . y;
           x := readch1();
           !*raise := raise
        end;
    letter:
        ttype!* := 0;
    let1:
        y := x . y;
        if digit (x := readch1()) or liter x then go to let1
         else if x eq '!! then go to escape
         else if x eq '!- and !*minusliter
          then progn(y := '!! . y, go to let1)
         else if x eq '!_ then go to let1;    % Allow _ as letter.
        nxtsym!* := intern compress reversip!* y;
        crchar!* := x;
    c:  return nxtsym!*;
%   minusl:
%       if digit (x := readch1())
%         then progn(crchar!* := x, return(nxtsym!* := 'minus))
%        else progn(y := '!- . '!! . y, go to letter);
    string:
        begin scalar raise,!*lower;
           raise := !*raise;
           !*raise := nil;
       strinx:
           y := x . y;
           if (x := readch1()) eq !$eof!$
             then progn(!*raise := raise,
                        crchar!* := '! ,
                        rerror('rlisp,29,"End-of-file in string"))
            else if null(x eq '!") then go to strinx;
           y := x . y;
           % Now check for embedded string character.
           x := readch1();
           if x eq '!" then go to strinx;
           nxtsym!* := mkstrng compress reversip!* y;
           !*raise := raise
         end;
        ttype!* := 1;
        crchar!* := x;
        go to c;
    coment:
        if null(readch1() eq !$eol!$) then go to coment;
        x := readch1();
        go to a
   end;

symbolic procedure tokbquote;
   begin
     crchar!* := readch1();
      nxtsym!* := list('backquote,rread());
      ttype!* := 3;
      return nxtsym!*
   end;

put('!`,'tokprop,'tokbquote);

symbolic procedure token;
   %This provides a hook for a faster TOKEN;
   token1();

symbolic procedure filenderr;
   begin
      eof!* := eof!*+1;
      if terminalp() then error1()
       else error(99,if ifl!*
                       then list("End-of-file read in file",car ifl!*)
                      else "End-of-file read")
   end;

symbolic procedure ptoken;
   begin scalar x;
        x := token();
        if x eq '!) and eqcar(outl!*,'! ) then outl!*:= cdr outl!*;
           %an explicit reference to OUTL!* used here;
        prin2x x;
        if null ((x eq '!() or (x eq '!))) then prin2x '! ;
        return x
   end;

symbolic procedure rread1;
   % Modified to use QUOTENEWNAM's for ids.
   % Note that handling of reals uses symbolic mode, regardless of
   % actual mode.
   begin scalar x,y;
        x := ptoken();
        if null (ttype!*=3)
          then return if idp x
                        then if !*quotenewnam
                                and (y := get(x,'quotenewnam))
                               then y
                              else x
                       else if eqcar(x,'!:dn!:)
                        then dnform(x,nil,'symbolic)
                       else x
         else if x eq '!( then return rrdls()
         else if null (x eq '!+ or x eq '!-) then return x;
        y := ptoken();
        if eqcar(y,'!:dn!:) then y := dnform(y,nil,'symbolic);
        if null numberp y
          then progn(nxtsym!* := " ",
                     symerr("Syntax error: improper number",nil))
         else if x eq '!- then y := apply1('minus,y);
           % We need this construct for bootstrapping purposes.
        return y
   end;

symbolic procedure rrdls;
   begin scalar x,y,z;
    a:  x := rread1();
        if null (ttype!*=3) then go to b
         else if x eq '!) then return z
         else if null (x eq '!.) then go to b;
        x := rread1();
        y := ptoken();
        if null (ttype!*=3) or null (y eq '!))
          then progn(nxtsym!* := " ",symerr("Invalid S-expression",nil))
         else return nconc(z,x);
    b: z := nconc(z,list x);
       go to a
   end;

symbolic procedure rread;
   progn(prin2x " '",rread1());

symbolic procedure delcp u;
   % Returns true if U is a semicolon, dollar sign, or other delimiter.
   % This definition replaces the one in the BOOT file.
   flagp(u,'delchar);

flag('(!; !$),'delchar);

symbolic procedure toknump x;
   numberp x or eqcar(x,'!:dn!:) or eqcar(x,'!:int!:);

symbolic procedure scan;
   begin scalar bool,x,y;
        if null (cursym!* eq '!*semicol!*) then go to b;
    a:  nxtsym!* := token();
    b:  if null atom nxtsym!* and null toknump nxtsym!*
          then go to q1
         else if nxtsym!* eq 'else or cursym!* eq '!*semicol!*
         then outl!* := nil;
        prin2x nxtsym!*;
    c:  if null idp nxtsym!* then go to l
         else if (x:=get(nxtsym!*,'newnam)) and
                        (null (x=nxtsym!*)) then go to new
         else if nxtsym!* eq 'Comment then go to comm
         else if nxtsym!* eq '!% and ttype!*=3
%         then progn(prin2t "****** Tell Hearn you got to SCAN comment",
%                    go to comm)
          then go to comm
         else if null(ttype!* = 3) then go to l
         else if nxtsym!* eq !$eof!$ then return filenderr()
         else if nxtsym!* eq '!' then rederr "Invalid QUOTE"
         else if !*eoldelimp and nxtsym!* eq !$eol!$ then go to delim
         else if null (x:= get(nxtsym!*,'switch!*)) then go to l
         else if eqcar(cdr x,'!*semicol!*) then go to delim;
        bool := seprp crchar!*;
   sw1: nxtsym!* := token();
        if null(ttype!* = 3) then go to sw2
         else if nxtsym!* eq !$eof!$ then return filenderr()
         else if car x then go to sw3;
   sw2: cursym!*:=cadr x;
        bool := nil;
        if cursym!* eq '!*rpar!* then go to l2 else return cursym!*;
   sw3: if bool or null (y:= atsoc(nxtsym!*,car x)) then go to sw2;
        prin2x nxtsym!*;
        x := cdr y;
        if null car x and cadr x eq '!*Comment!*
          then progn(comment!* := read!-comment(),go to a);
        go to sw1;
  comm: if delcp crchar!* and null(crchar!* eq !$eol!$)
          then progn(crchar!* := '! , condterpri(), go to a);
        crchar!* := readch();
        go to comm;
  delim:
        semic!*:=nxtsym!*;
        return (cursym!*:='!*semicol!*);
  new:  nxtsym!* := x;
        if stringp x then go to l
        else if atom x then go to c
        else go to l;
  q1:   if null (car nxtsym!* eq 'string) then go to l;
        prin2x " ";
        prin2x cadr(nxtsym!* := mkquote cadr nxtsym!*);
  l:    cursym!*:=nxtsym!*;
        nxtsym!* := token();
        if nxtsym!* eq !$eof!$ and ttype!* = 3 then return filenderr();
  l2:   if numberp nxtsym!*
           or (atom nxtsym!* and null get(nxtsym!*,'switch!*))
          then prin2x " ";
        return cursym!*
   end;

endmodule;


module xread; % Routines for parsing RLISP input.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

fluid '(!*blockp !*eoldelimp);   % !*ignoreeol

global '(cursym!* nxtsym!*);

% The conversion of an RLISP expression to LISP prefix form is carried
% out by the function XREAD.  This function initiates the scanning
% process, and then calls the auxiliary function XREAD1 to perform the
% actual parsing.  Both XREAD and XREAD1 are used by many functions
% whenever an expression must be read;

flag ('(end !*colon!* !*semicol!*),'delim);

symbolic procedure chknewnam u;
   % Check to see if U has a newnam, and return it else return U.
   begin scalar x;
      return if null(x := get(u,'newnam)) or x eq u then u
              else if idp x then chknewnam x
              else x
   end;

symbolic procedure mkvar(u,v); u;

symbolic procedure remcomma u;
   if eqcar(u,'!*comma!*) then cdr u else list u;

symbolic procedure eolcheck;
   if null !*eoldelimp then nil
    else begin
   a: if nxtsym!* eq !$eol!$
        then progn(nxtsym!* := (if cursym!* eq 'end then '!;
                                 else token()),
                   go to a)
     end;

symbolic procedure xread1 u;
   begin scalar v,w,x,y,z,z1,z2;
        % This is the basic function for parsing RLISP input, once
        % tokens have been read by TOKEN and SCAN.  Its one argument
        % U can take a number of values:
        %   FOR:     Parsing of FOR statements
        %   GROUP:   Parsing of group statements after keyword <<
        %   LAMBDA:  Parsing of lambda expressions after keyword lambda
        %   NIL:     Parsing of expressions which can have a comma at
        %            the end for example.
        %   PROC:    Parsing of procedures after keyword PROCEDURE
        %   T:       Default case with standard parsing.
        % Also, if U is flagged STRUCT, it is assumed that the arguments
        % are lists of lists, and so commas are removed.  At present,
        % only MAT is tagged in this manner.
        % The local variables are used as follows:
        % v: expression being built
        % w: prefix operator stack
        % x: infix operator stack
        % y: infix value or stat property
        % z: current symbol
        % z1: next symbol
        % z2: temporary storage;
  a:    z := cursym!*;
  a1:   if null idp z then nil
         else if z eq '!*lpar!* then go to lparen
         else if z eq '!*rpar!* then go to rparen
         else if y := get(z,'infix) then go to infx
         % The next line now commented out was intended to allow a STAT
         % to be used as a label. However, it prevents the definition of
         % a diphthong whose first character is a colon.
%        else if nxtsym!* eq '!: then nil
         else if flagp(z,'delim) then go to delimit
         else if y := get(z,'stat) then go to stat
         else if flagp(z,'type)
          then progn(w := lispapply('decstat,nil) . w, go to a);
  a2:   y := nil;
  a3:   w := z . w;
        % allow for implicit * after a number.
        if toknump z
           and null(z1 eq !$eol!$)
           and idp (z1 := chknewnam nxtsym!*)
           and null flagp(z1,'delim)
           and null(get(z1,'switch!*) and null(z1 eq '!())
           and null get(z1,'infix)
           and null (!*eoldelimp and z1 eq !$eol!$)
          then progn(cursym!* := 'times, go to a)
         else if u eq 'proc and length w > 2
          then symerr("Syntax error in procedure header",nil);
  next: z := scan();
        go to a1;
  lparen:
        eolcheck();
        y := nil;
        if scan() eq '!*rpar!* then go to lp1    % no args
         else if flagpcar(w,'struct) then z := xread1 car w
         else z := xread1 'paren;
        if flagp(u,'struct) then progn(z := remcomma z, go to a3)
         else if null eqcar(z,'!*comma!*) then go to a3
         else if null w         % then go to a3
           then (if u eq 'lambda then go to a3
                 else symerr("Improper delimiter",nil))
         else w := (car w . cdr z) . cdr w;
        go to next;
  lp1:  if w then w := list car w . cdr w;  % Function of no args.
        go to next;
  rparen:
        if null u or u eq 'group or u eq 'proc
          then symerr("Too many right parentheses",nil)
         else go to end1;
  infx: eolcheck();
        if z eq '!*comma!* or null atom (z1 := scan())
                or toknump z1 then go to in1
         else if z1 eq '!*rpar!* % Infix operator used as variable.
                or z1 eq '!*comma!*
                or flagp(z1,'delim)
          then go to in2
         else if z1 eq '!*lpar!* % Infix operator in prefix position.
                    and null eolcheck()     % Side effect important
                    and null atom(z1 := xread 'paren)
                    and car z1 eq '!*comma!*
                    and (z := z . cdr z1)
          then go to a1;
  in1:  if w then go to unwind
         else if null(z := get(z,'unary))
          then symerr("Redundant operator",nil);
        v := '!*!*un!*!* . v;
        go to pr1;
% in2:  if y then if !*ignoreeol then y := nil
%                  else symerr("Redundant operator",nil);
  in2:  if y then y := nil;
        w := z . w;
  in3:  z := z1;
        go to a1;
  unwind:
        % Null w implies a delimiter was found, say, after a comma.
        if null w then symerr("Improper delimiter",nil);
        z2 := mkvar(car w,z);
  un1:  w:= cdr w;
        if null w then go to un2
        % Next line used to be toknump car w, but this test catches more
%        else if null idp car w and null eqcar(car w,'lambda)
         else if atom car w and null idp car w
%           and null eqcar(car w,'lambda)
          then symerr("Missing operator",nil);
        z2 := list(car w,z2);
        go to un1;
  un2:  v:= z2 . v;
  preced:
        if null x then if y=0 then go to end2 else nil
%        else if z eq 'setq then nil
        % Makes parsing a + b := c more natural.
         else if y<caar x
           or (y=caar x
               and ((z eq cdar x and null flagp(z,'nary)
                                 and null flagp(z,'right))
                             or get(cdar x,'alt)))
          then go to pr2;
  pr1:  x:= (y . z) . x;
        if null(z eq '!*comma!*) then go to in3
         else if cdr x or null u or u memq '(lambda paren)
            or flagp(u,'struct)
          then go to next
         else go to end2;
  pr2:  %if cdar x eq 'setq then go to assign else;
        if cadr v eq '!*!*un!*!*
          then (if car v eq '!*!*un!*!* then go to pr1
                else z2 := list(cdar x,car v))
         else z2 := cdar x .
                     if eqcar(car v,cdar x) and flagp(cdar x,'nary)
                       then (cadr v . cdar v)
                      else list(cadr v,car v);
        x:= cdr x;
        v := z2 . cddr v;
        go to preced;
  stat: if null(y eq 'endstat) then eolcheck();
        if null(flagp(z,'go)
           or null(u eq 'proc) and (flagp(y,'endstatfn)
                or (null delcp nxtsym!* and null (nxtsym!* eq '!,))))
          then go to a2;
        w := lispapply(y,nil) . w;
        y := nil;
        go to a;
  delimit:
        if null(cursym!* eq '!*semicol!*) then eolcheck();
        if z eq '!*colon!* and null(u eq 'for)
              and (null !*blockp or null w or null atom car w or cdr w)
           or flagp(z,'nodel)
              and (null u
                      or u eq 'group
                        and null(z memq
                                   '(!*rsqbkt!* !*rcbkt!* !*rsqb!*)))
          then symerr("Improper delimiter",nil)
         else if idp u and (u eq 'paren or flagp(u,'struct))
          then symerr("Too few right parentheses",nil);
  end1:
        if y then symerr("Improper delimiter",nil) % Probably ,).
         else if null v and null w and null x then return nil;
        y := 0;
        go to unwind;
  end2: if null cdr v then return car v
         else print "Please send hearn@rand.org your program!!";
        symerr("Improper delimiter",nil)
   end;

%symbolic procedure getels u;
%   getel(car u . !*evlis cdr u);

%symbolic procedure !*evlis u;
%   mapcar(u,function lispeval);

flag ('(endstat retstat),'endstatfn);

flag ('(else then until),'nodel);

flag ('(begin),'go);

symbolic procedure xread u;
   begin
   a: scan();
      if !*eoldelimp and cursym!* eq '!*semicol!* then go to a;
      return xread1 u
   end;

symbolic procedure expread;  xread t;

flag('(expread xread),'opfn);   % To make them operators.

endmodule;


module lpri; % Functions for printing diagnostic and error messages.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*defn !*echo !*fort !*int !*msg !*nat !*protfg);

global '(cursym!* erfg!* ofl!* outl!*);

symbolic procedure lpri u;
   begin
    a:  if null u then return nil;
        prin2 car u;
        prin2 " ";
        u := cdr u;
        go to a
   end;

symbolic procedure lpriw (u,v);
   begin scalar x;
        u := u . if v and atom v then list v else v;
        if ofl!* and (!*fort or not !*nat or !*defn) then go to c;
        terpri();
    a:  lpri u;
        terpri();
        if null x then go to b;
        wrs cdr x;
        return nil;
    b:  if null ofl!* then return nil;
    c:  x := ofl!*;
        wrs nil;
        go to a
   end;

symbolic procedure lprim u;
   !*msg and lpriw("***",u);

symbolic procedure lprie u;
   begin scalar x;
        if !*int then go to a;
        x:= !*defn;
        !*defn := nil;
    a:  erfg!* := t;
        lpriw ("*****",u);
        if null !*int then !*defn := x
   end;

symbolic procedure printty u;
   begin scalar ofl;
        if null !*fort and !*nat then print u;
        if null ofl!* then return nil;
        ofl := ofl!*;
        wrs nil;
        print u;
        wrs cdr ofl
   end;

symbolic procedure rerror(packagename,number,message);
   rederr message;

symbolic procedure rederr u;
   begin if not !*protfg then lprie u; error1() end;

symbolic procedure symerr(u,v);
   begin scalar x;
        erfg!* := t;
        if numberp cursym!* or not(x := get(cursym!*,'prtch))
          then x := cursym!*;
        terpri();
        if !*echo then terpri();
        outl!*:=car outl!* . '!$!$!$ . cdr outl!*;
        comm1 t;
        mapcar(reversip!* outl!*,function prin2);
        terpri();
        outl!* := nil;
        if null v then rerror('rlisp,5,u)
         else rerror('rlisp,6,
                     x . ("invalid" .
                         (if u then list("in",u,"statement") else nil)))
   end;

symbolic procedure typerr(u,v); rerror('rlisp,6,list(u,"invalid as",v));

endmodule;


module parser;  % Functions for parsing RLISP expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

fluid '(!*backtrace);

global '(cursym!* letl!* nxtsym!*);

%With the exception of assignment statements, which are handled by
%XREAD, statements in REDUCE are introduced by a key-word, which
%initiates a reading process peculiar to that statement.  The key-word
%is recognized (in XREAD1) by the indicator STAT on its property list.
%The corresponding property is the name of the function (of no
%arguments) which carries out the reading sequence.

% ***** COMMENTS *****

symbolic procedure comm1 u;
   begin scalar bool;
        if u eq 'end then go to b;
  a:    if cursym!* eq '!*semicol!*
           or u eq 'end
                and cursym!* memq
                   '(end else then until !*rpar!* !*rsqbkt!*)
          then return nil
         else if u eq 'end and null bool
          then progn(lprim list("END-COMMENT NO LONGER SUPPORTED"),
                     bool := t);
  b:    scan();
        go to a
   end;


% ***** CONDITIONAL STATEMENT *****

symbolic procedure ifstat;
   begin scalar condx,condit;
    a:  condx := xread t;
        if not cursym!* eq 'then then symerr('if,t);
        condit := aconc!*(condit,list(condx,xread t));
        if not cursym!* eq 'else then nil
         else if scan() eq 'if then go to a
         else condit := aconc!*(condit,list(t,xread1 t));
        return ('cond . condit)
   end;

put('if,'stat,'ifstat);

flag ('(then else),'delim);


% ***** FUNCTION STATEMENT *****

symbolic procedure functionstat;
   begin scalar x;
      x := scan();
      return list('function,
                  if x eq '!*lpar!* then xread1 t
                   else if idp x and null(x eq 'lambda)
                    then progn(scan(),x)
                   else symerr("Function",t))
   end;

put('function,'stat,'functionstat);


% ***** LAMBDA STATEMENT *****

symbolic procedure lamstat;
   begin scalar x,y;
        x:= xread 'lambda;
%       x := flagtype(if null x then nil else remcomma x,'scalar);
        if x then x := remcomma x;
        y := list('lambda,x,xread t);
%       remtype x;
        return y
   end;

put ('lambda,'stat,'lamstat);


% ***** GROUP STATEMENT *****

symbolic procedure readprogn;
   %Expects a list of statements terminated by a >>;
   begin scalar lst;
    a:  lst := aconc!*(lst,xread 'group);
        if null(cursym!* eq '!*rsqbkt!*) then go to a;
        scan();
        return ('progn . lst)
   end;

put('!*lsqbkt!*,'stat,'readprogn);

flag('(!*rsqbkt!*),'delim);

flag('(!*rsqbkt!*),'nodel);


% ***** END STATEMENT *****

symbolic procedure endstat;
  %This procedure can also be used for any key-words  which  take  no
  %arguments;
   begin scalar x; x := cursym!*; comm1 'end; return list x end;

put('end,'stat,'endstat);

put('endmodule,'stat,'endstat);

put('bye,'stat,'endstat);

put('quit,'stat,'endstat);

flag('(bye quit),'eval);

put('showtime,'stat,'endstat);

endmodule;


module block;   % Block statement and related operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1993 RAND.  All rights reserved.

fluid '(!*blockp !*rlisp88);

global '(!*vars!* cursym!* nxtsym!*);

% ***** GO statement *****

symbolic procedure gostat;
   begin scalar var;
        var := if eq(scan(),'to) then scan() else cursym!*;
        scan();
        return list('go,var)
   end;

put('go,'stat,'gostat);

put('goto,'newnam,'go);


% ***** Declaration Statement *****

symbolic procedure decl u;
   begin scalar varlis,w;
    a:  if cursym!* eq '!*semicol!* then go to c
         else if not flagp!*!*(cursym!*,'type) then return varlis;
%        else if not(get(cursym!*,'stat) eq 'decstat)
%         then return varlis;
%        else if cursym!* eq 'dcl then go to dclr;
        w := cursym!*;
        if scan() eq 'procedure then return procstat1 w;
        varlis := append(varlis,pairvars(remcomma xread1 nil,nil,w));
%   b:  if not cursym!* eq '!*semicol!* or null u then symerr(nil,t);
        if not cursym!* eq '!*semicol!* or null u then symerr(nil,t);
    c:  scan();
        go to a
%   dclr: varlis := append(varlis,dclstat1());
%       go to b
   end;

put('integer,'initvalue!*,0);

symbolic procedure decstat;
  % Called if a declaration occurs at the top level or not first
  % in a block.
  begin scalar x,y,z;
     if !*blockp then symerr('block,t);
     x := cursym!*;
     y := nxtsym!*;
     z := decl nil;
     if y neq 'procedure
       then rerror('rlisp,7,list(x,"invalid outside block"));
     return z
  end;

% put('integer,'stat,'decstat);

% put('real,'stat,'decstat);

% put('scalar,'stat,'decstat);

flag('(integer real scalar),'type);

symbolic procedure blocktyperr u;
   % Type declaration found at wrong position.
   rerror('rlisp,8,list(u,"invalid except at head of block"));


% ***** Block Statement *****

symbolic procedure blockstat;
   begin scalar hold,varlis,x,!*blockp;
        !*blockp := t;
        scan();
        if cursym!* memq '(nil !*rpar!*)
          then rerror('rlisp,9,"BEGIN invalid");
        varlis := decl t;
    a:  if cursym!* eq 'end and not nxtsym!* eq '!: then go to b;
        x := xread1 nil;
        if eqcar(x,'end) then go to c;
        not cursym!* eq 'end and scan();
        if x then hold := aconc!*(hold,x);
        go to a;
    b:  comm1 'end;
    c:  return mkblock(varlis,hold)
   end;

symbolic procedure mkblock(u,v); 'block . (u . v);

putd('block,'macro,
 '(lambda (u) (cons 'prog
                 (cons (mapcar (cadr u) (function car)) (cddr u)))));

symbolic procedure formblock(u,vars,mode);
   'prog . append(initprogvars cadr u,
              formprog1(cddr u,append(cadr u,vars),mode));

symbolic procedure initprogvars u;
   begin scalar x,y,z;
    a: if null u then return(reversip!* x . reversip!* y)
       else if (z := get(caar u,'initvalue!*))
          or (z := get(cdar u,'initvalue!*))
        then y := mksetq(caar u,z) . y;
      x := caar u . x;
      u := cdr u;
      go to a
   end;

symbolic procedure formprog(u,vars,mode);
   'prog . cadr u . formprog1(cddr u,pairvars(cadr u,vars,mode),mode);

symbolic procedure formprog1(u,vars,mode);
   if null u then nil
    else if null car u then formprog1(cdr u,vars,mode)
        % remove spurious NILs, probably generated by FOR statements.
    else if atom car u then car u . formprog1(cdr u,vars,mode)
    else if idp caar u and flagp(caar u,'modefn)
           then if !*rlisp88 and null(caar u eq 'symbolic)
                  then typerr("algebraic expression","Rlisp88 form")
          else formc(cadar u,vars,caar u) . formprog1(cdr u,vars,mode)
    else formc(car u,vars,mode) . formprog1(cdr u,vars,mode);

put('block,'formfn,'formblock);

put('prog,'formfn,'formprog);

put('begin,'stat,'blockstat);


% ***** Return Statement *****

symbolic procedure retstat;
   if not !*blockp then symerr(nil,t)
    else begin scalar !*blockp;  % To prevent RETURN within a RETURN.
            return list('return,
                if flagp!*!*(scan(),'delim) then nil else xread1 t)
      end;

put('return,'stat,'retstat);

endmodule;


module form;  % Performs a mode analysis of parsed forms.

% Author: Anthony C. Hearn.

% Modifications by: Jed Marti, Arthur C. Norman.

% Copyright (c) 1993 RAND.  All rights reserved.

fluid '(!*!*a2sfn !*cref !*defn !*mode !*rlisp88 current!-modulus
        fname!* ftype!*);

global '(!*argnochk !*composites !*force !*micro!-version !*vars!*
         cursym!*);

!*!*a2sfn := 'aeval;

flag('(algebraic symbolic),'modefn);

symbolic procedure formcond(u,vars,mode);
   'cond . formcond1(cdr u,vars,mode);

symbolic procedure formcond1(u,vars,mode);
   if null u then nil
    else list(formbool(caar u,vars,mode),formc(cadar u,vars,mode))
       % FORM1 here leaves out top level REVAL.
              . formcond1(cdr u,vars,mode);

put('cond,'formfn,'formcond);

symbolic procedure formlamb(u,vars,mode);
   list('lambda,cadr u,form1(caddr u,pairvars(cadr u,vars,mode),mode));

put('lambda,'formfn,'formlamb);

symbolic procedure formprogn(u,vars,mode);
   'progn . formclis(cdr u,vars,mode);

put('progn,'formfn,'formprogn);

symbolic procedure expdrmacro u;
   %returns the macro form for U if expansion is permitted;
   begin scalar x;
      if null(x := getrmacro u) or flagp(u,'noexpand) then return nil
       else if null !*cref and (null !*defn or car x eq 'smacro)
          or flagp(u,'expand) or !*force
        then return x
       else return nil
   end;

symbolic procedure getrmacro u;
   %returns a Reduce macro definition for U, if one exists,
   %in GETD format;
   begin scalar x;
      return if not idp u then nil
       else if (x := getd u) and car x eq 'macro then x
       else if (x := get(u,'smacro)) then 'smacro . x
       else nil
   end;

symbolic procedure applmacro(u,v,w); apply1(u,w . v);

put('macro,'macrofn,'applmacro);

flag('(ed go quote),'noform);

symbolic procedure set!-global!-mode u;
   begin
      !*mode := u;
      return list('null,list('setq,'!*mode,mkquote u))
   end;

symbolic procedure form1(u,vars,mode);
   begin scalar x,y;
      if atom u
        then return if not idp u then u
                     else if u eq 'ed then list u
                     else if flagp(u,'modefn) then set!-global!-mode u
                     else if x:= get(mode,'idfn)
                      then apply2(x,u,vars)
                     else u
       else if not atom car u then return form2(u,vars,mode)
       else if not idp car u then typerr(car u,"operator")
       else if flagp(car u,'noform) then return u
       else if arrayp car u
          and (mode eq 'symbolic or intexprlisp(cdr u,vars))
        then return list('getel,intargfn(u,vars,mode))
       else if cdr u and (get(car u,'rtype) eq 'vector
             or vectorp cadr u or flagpcar(cadr u,'vecfn))
        then return getvect(u,vars,mode)
       else if flagp(car u,'modefn)
        then return convertmode(cadr u,vars,mode,car u)
       else if (x := get(car u,'formfn))
        then return macrochk(apply3(x,u,vars,mode),mode)
       else if get(car u,'stat) eq 'rlis
        then return macrochk(formrlis(u,vars,mode),mode)
%      else if (x := getd car u) and eqcar(x, 'macro) and
%              not(mode eq 'algebraic) then
%            return <<x := apply3(cdr x,u,vars,mode);
%                     formc(x,vars,mode) >>
%      else if flagp(car u,'type) then blocktyperr car u
       else if car u eq '!*comma!*
        then if not atom cadr u and atom caddr u
                 and flagp(caadr u,'type)
%                and(get(caddr u,'stat) eq 'decstat)
               then blocktyperr caadr u
              else rerror('rlisp,10,
                          list("Syntax error: , invalid after",cadr u));
      % Exclude algebraic operator with same name as symbolic function.
      if mode eq 'symbolic or flagp(car u,'opfn)
        then argnochk u;
      x := formlis(cdr u,vars,mode);
      y := if x=cdr u then u else car u . x;
      return if mode eq 'symbolic
              or get(car u,'stat)
              or cdr u and eqcar(cadr u,'quote)
                       and null(!*micro!-version and null !*defn)
              or intexprnp(y,vars) and null !*composites
                 and null current!-modulus
               then macrochk(y,mode)
              else if not(mode eq 'algebraic)
               then convertmode(y,vars,mode,'algebraic)
              else ('list . algid(car u,vars) . x)
   end;

symbolic procedure form2(u,vars,mode);
   begin scalar x;
      if x := get(caar u,'form2fn) then return apply3(x,u,vars,mode)
        else typerr(car u,"operator")
   end;

put('lambda,'form2fn,'formlis);

symbolic procedure argnochk u;
   begin scalar x;
      if null !*argnochk then nil
       else if (x := argsofopr car u) and x neq length cdr u
        then rerror('rlisp,11,list(car u,"called with",
                                   length cdr u,
                                   if length cdr u=1 then "argument"
                                    else "arguments",
                                   "instead of",x))
   end;

symbolic procedure argsofopr u;
   % This function may be optimizable in various implementations.
   get(u,'number!-of!-args);

symbolic procedure intexprnp(u,vars);
   %determines if U is an integer expression;
    if atom u then if numberp u then fixp u
                   else if (u := atsoc(u,vars)) then cdr u eq 'integer
                   else nil
     else idp car u and flagp(car u,'intfn) and intexprlisp(cdr u,vars);

symbolic procedure intexprlisp(u,vars);
   null u or intexprnp(car u,vars) and intexprlisp(cdr u,vars);

flag('(difference minus plus times),'intfn);
   % EXPT is not included in this list, because a negative exponent can
   % cause problems (i.e., result can be rational);

symbolic procedure formlis(u,vars,mode);
   mapcar(u,function (lambda x; form1(x,vars,mode)));

symbolic procedure formclis(u,vars,mode);
   mapcar(u,function (lambda x; formc(x,vars,mode)));

symbolic procedure form u;
   if null !*rlisp88 then form1(u,!*vars!*,!*mode)
    else if null(!*mode eq 'symbolic)
        or flagp(u,'modefn) and null(u eq 'symbolic)
        or flagpcar(u,'modefn) and null(car u eq 'symbolic)
     then typerr("algebraic expression","Rlisp88 form")
    else form1(u,!*vars!*,!*mode);

symbolic procedure macrochk(u,mode);
   begin scalar y;
   %expands U if CAR U is a macro and expansion allowed;
      if atom u then return u
       else if (y := expdrmacro car u)
        and (mode eq 'symbolic or idp car u and flagp(car u,'opfn))
        then return apply3(get(car y,'macrofn),cdr y,cdr u,car u)
       else return u
   end;

put('symbolic,'idfn,'symbid);

symbolic procedure symbid(u,vars);
   <<if fname!* and null(ftype!* memq '(macro smacro))
       and not(atsoc(u,vars) or fluidp u or globalp u
        or null u or u eq t or flagp(u,'share))
       then lprim list("nonlocal use of undeclared variable",u,
                       "in procedure",fname!*);
     u>>;

put('algebraic,'idfn,'algid);

symbolic procedure algid(u,vars);
   if atsoc(u,vars) or flagp(u,'share) then u else mkquote u;

put('integer,'idfn,'intid);

symbolic procedure intid(u,vars);
   begin scalar x,y;
      return if (x := atsoc(u,vars))
        then if cdr x eq 'integer then u
               else if y := get(cdr x,'integer)
                then apply2(y,u,vars)
               else if cdr x eq 'scalar then !*!*a2i(u,vars)
               else rerror('rlisp,12,
                           list(cdr x,"not convertable to INTEGER"))
      else !*!*a2i(mkquote u,vars)
   end;

symbolic procedure convertmode(exprn,vars,target,source);
   convertmode1(form1(exprn,vars,source),vars,target,source);

symbolic procedure convertmode1(exprn,vars,target,source);
   begin scalar x;
      if source eq 'real then source := 'algebraic;
      if target eq 'real then target := 'algebraic;
      if target eq source then return exprn
       else if idp exprn and (x := atsoc(exprn,vars))
          and not(cdr x memq '(integer scalar real))
          and not(cdr x eq source)
        then return convertmode(exprn,vars,target,cdr x)
       else if not (x := get(source,target))
        then typerr(source,target)
       else return apply2(x,exprn,vars)
   end;

put('algebraic,'symbolic,'!*!*a2s);

put('symbolic,'algebraic,'!*!*s2a);

symbolic procedure !*!*a2s(u,vars);
   % It would be nice if we could include the ATSOC(U,VARS) line,
   % since in many cases that would save recomputation. However,
   % in any sequential process, assignments or substitution rules
   % can change the value of a variable, so we have to check its
   % value again.  More comprehensive analysis could certainly
   % optimize this.  We could also avoid wrapping an integer, thus
   % making a mode change only occur within an expression.
    if null u or constantp u and null fixp u
      or intexprnp(u,vars) and null !*composites
                 and null current!-modulus
      or flagpcar(u,'nochange) and not(car u eq 'getel)
     then u
    else list(!*!*a2sfn,u);

symbolic procedure !*!*s2a(u,vars); u;

symbolic procedure formc(u,vars,mode);
   %this needs to be generalized;
   if !*rlisp88 and flagpcar(u,'modefn) and null(car u eq 'symbolic)
     then typerr("algebraic expression","Rlisp88 form")
    else if mode eq 'algebraic and intexprnp(u,vars) then u
    else convertmode(u,vars,'symbolic,mode);

symbolic procedure intargfn(u,vars,mode);
   % transforms array element U into expression with integer arguments.
   % Array name is treated as an algebraic variable;
   'list . form1(car u,vars,'algebraic) .
       mapcar(cdr u,
              function (lambda x;
                        convertmode(x,vars,'integer,mode)));

put('algebraic,'integer,'!*!*a2i);

symbolic procedure !*!*a2i(u,vars);
   if intexprnp(u,vars) then u else list('ieval,u);

symbolic procedure ieval u; !*s2i reval u;

flag('(ieval),'opfn);   % To make it a symbolic operator.

flag('(ieval),'nochange);

put('symbolic,'integer,'!*!*s2i);

symbolic procedure !*!*s2i(u,vars);
   if fixp u then u else list('!*s2i,u);

symbolic procedure !*s2i u;
   if fixp u then u else typerr(u,"integer");

put('integer,'symbolic,'identity);

symbolic procedure identity(u,vars); u;

symbolic procedure formbool(u,vars,mode);
   if mode eq 'symbolic then formc(u,vars,mode)
    else if atom u then if u eq 't then u
           else if not idp u or atsoc(u,vars)
           then list('boolvalue!*,u)
          else list('boolvalue!*,formc!*(u,vars,mode))
    else if intexprlisp(cdr u,vars) and get(car u,'boolfn) then u
    else if idp car u and get(car u,'boolfn)
     then get(car u,'boolfn) . formclis(cdr u,vars,mode)
    else if idp car u and flagp(car u,'boolean)
        then car u .
          mapcar(cdr u,function (lambda x;
            if flagp(car u,'boolargs)
                      then formbool(x,vars,mode)
                     else formc!*(x,vars,mode)))
    else if car u eq 'boolvalue!* then rederr("Too many formbools")
    else if car u eq 'where
     then list('boolvalue!*,
           formc!*(list('where,
                   mkquote list('bool!-eval,formbool(cadr u,vars,mode)),
                   caddr u),
                   vars,mode))
    else list('boolvalue!*,formc!*(u,vars,mode));

symbolic procedure bool!-eval u; lispeval u;

flag('(bool!-eval),'noform);

flag('(bool!-eval),'opfn);  % symbolic operator bool!-eval.

flag('(bool!-eval),'noval);

symbolic procedure boolvalue!* u; u and null(u = 0);

symbolic procedure formc!*(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'reval;
      return formc(u,vars,mode)
   end;

% Functions with side effects must be handled carefully in this model,
% otherwise they are not always evaluated within blocks.

symbolic procedure formrerror(u,vars,mode);
   begin scalar x;
      argnochk u;
      if not fixp caddr u then typerr(caddr u,"RERROR argument");
      x := formc!*(cadddr u,vars,mode);
      if idp cadr u then return list('rerror,mkquote cadr u,caddr u,x)
       else if eqcar(cadr u,'quote) and idp cadadr u
        then return list('rerror,cadr u,caddr u,x)
       else typerr(cadr u,"RERROR argument")
   end;

deflist('((rerror formrerror)),'formfn);   % For bootstrapping.

symbolic procedure formrederr(u,vars,mode);
   list('rederr,formc!*(cadr u,vars,mode));

put('rederr,'formfn,'formrederr);

symbolic procedure formreturn(u,vars,mode);
%  begin scalar x;
%     x := form1(cadr u,vars,mode);  % FORMC here would add REVAL
%     if not(mode memq '(symbolic integer real))
%        and eqcar(x,'setq)             % Should this be more general?
%       then x := list(!*!*a2sfn,x);
%     return list('return,x)
%  end;
   list('return,formc(cadr u,vars,mode));

put('return,'formfn,'formreturn);

symbolic procedure rsverr x;
   rerror('rlisp,13,list (x,"is a reserved identifier"));

symbolic procedure formsetq(u,vars,mode);
   begin scalar x,y,z;   % target
     if idp(z := car(u := cdr u)) then y := atsoc(z,vars);
     if eqcar(cadr u,'quote) then mode := 'symbolic;
%     if idp car u
%          and (y := atsoc(car u,vars)) and not(cdr y eq 'scalar)
%       then target :=  'symbolic   % used to be CDR Y
%     else target := 'symbolic;
      % Make target always SYMBOLIC so that algebraic expressions
      % are evaluated before being stored.
%     x := convertmode(cadr u,vars,target,mode);
      x := convertmode(cadr u,vars,'symbolic,mode);
      return if not atom z
        then if not idp car z then typerr(z,"assignment")
          else if null atom(z := macrochk(z,mode)) and arrayp car z
           then list('setel,intargfn(z,vars,mode),x)
          else if null atom z
               and cdr z and (get(car z,'rtype) eq 'vector
                              or vectorp cadr z
                              or flagpcar(cadr z,'vecfn))
           then putvect(u,vars,mode)
          else if null atom z and (y := get(car z,'setqfn))
           then form1(applsmacro(y,append(cdr z,cdr u),nil),vars,mode)
          else if mode eq 'symbolic and !*rlisp88
%          then rerror(rlisp,1001,list("Unknown LHS of assignment:",z))
           then list('rsetf,form1(z,vars,mode),x)
%          then list('setf,form1(z,vars,mode),x)
             % Uses SETF for symbolic non-id assignments in
             % RLISP88, even though it is not defined in Standard Lisp.
          else list('setk,form1(z,vars,'algebraic),x)
             % algebraic needed above, since SETK expects it.
    else if not idp z then typerr(z,"assignment")
    else if flagp(z,'reserved) and null atsoc(z,vars) then rsverr z
    else if mode eq 'symbolic or y or flagp(z,'share)
         or eqcar(x,'quote)
     then mksetq(symbid(z,vars),x)
    else if vectorp cadr u or flagpcar(cadr u,'vecfn)
     then list('setv,mkquote z,cadr u)
    else list('setk,mkquote z,x)
   end;

put('setq,'formfn,'formsetq);

% Table of SETQFNs.

symbolic procedure setcar(a,b); progn(rplaca(a,b),b);

symbolic procedure setcdr(a,b); progn(rplacd(a,b),b);

put('car,'setqfn,'(lambda (u v) (setcar u v)));

put('cdr,'setqfn,'(lambda (u v) (setcdr u v)));

put('caar,'setqfn,'(lambda (u v) (setcar (car u) v)));

put('cadr,'setqfn,'(lambda (u v) (setcar (cdr u) v)));

put('cdar,'setqfn,'(lambda (u v) (setcdr (car u) v)));

put('cddr,'setqfn,'(lambda (u v) (setcdr (cdr u) v)));

put('caaar,'setqfn,'(lambda (u v) (setcar (caar u) v)));

put('caadr,'setqfn,'(lambda (u v) (setcar (cadr u) v)));

put('cadar,'setqfn,'(lambda (u v) (setcar (cdar u) v)));

put('caddr,'setqfn,'(lambda (u v) (setcar (cddr u) v)));

put('cdaar,'setqfn,'(lambda (u v) (setcdr (caar u) v)));

put('cdadr,'setqfn,'(lambda (u v) (setcdr (cadr u) v)));

put('cddar,'setqfn,'(lambda (u v) (setcdr (cdar u) v)));

put('cdddr,'setqfn,'(lambda (u v) (setcdr (cddr u) v)));

put('caaaar,'setqfn,'(lambda (u v) (setcar (caaar u) v)));

put('caaadr,'setqfn,'(lambda (u v) (setcar (caadr u) v)));

put('caadar,'setqfn,'(lambda (u v) (setcar (cadar u) v)));

put('caaddr,'setqfn,'(lambda (u v) (setcar (caddr u) v)));

put('cadaar,'setqfn,'(lambda (u v) (setcar (cdaar u) v)));

put('cadadr,'setqfn,'(lambda (u v) (setcar (cdadr u) v)));

put('caddar,'setqfn,'(lambda (u v) (setcar (cddar u) v)));

put('cadddr,'setqfn,'(lambda (u v) (setcar (cdddr u) v)));

put('cdaaar,'setqfn,'(lambda (u v) (setcdr (caaar u) v)));

put('cdaadr,'setqfn,'(lambda (u v) (setcdr (caadr u) v)));

put('cdadar,'setqfn,'(lambda (u v) (setcdr (cadar u) v)));

put('cdaddr,'setqfn,'(lambda (u v) (setcdr (caddr u) v)));

put('cddaar,'setqfn,'(lambda (u v) (setcdr (cdaar u) v)));

put('cddadr,'setqfn,'(lambda (u v) (setcdr (cdadr u) v)));

put('cdddar,'setqfn,'(lambda (u v) (setcdr (cddar u) v)));

put('cddddr,'setqfn,'(lambda (u v) (setcdr (cdddr u) v)));

put('nth,'setqfn,'(lambda (l i x) (setcar (pnth l i) x)));

put('getv,'setqfn,'(lambda (v i x) (putv v i x)));

symbolic procedure formfunc(u,vars,mode);
   if idp cadr u then if getrmacro cadr u
     then rerror('rlisp,14,list("Macro",cadr u,"Used as Function"))
        else list('function,cadr u)
    else list('function,form1(cadr u,vars,mode));

put('function,'formfn,'formfunc);

% RLIS is a parser function that reads a list of arguments and returns
% this list as one argument.  It needs to be defined in this module for
% bootstrapping purposes since this definition only works with its form
% function.

symbolic procedure rlis;
   begin scalar x;
        x := cursym!*;
        return if flagp!*!*(scan(),'delim) then list(x,nil)
                else x . remcomma xread1 'lambda
   end;

symbolic procedure flagop u; begin flag(u,'flagop); rlistat u end;

symbolic procedure rlistat u;
   begin
    a:  if null u then return nil;
        put(car u,'stat,'rlis);
        u := cdr u;
        go to a
   end;

rlistat '(flagop);

symbolic procedure formrlis(u,vars,mode);
   if not flagp(car u,'flagop)
     then list(car u,'list .
                  if car u eq 'share then mapcar(cdr u,function mkquote)
                   else formlis(cdr u,vars,'algebraic))
    else if not idlistp cdr u
     then typerr('!*comma!* . cdr u,"identifier list")
    else list('flag,mkquote cdr u,mkquote car u);

symbolic procedure mkarg(u,vars);
   % Returns the "unevaled" form of U.
   if null u or constantp u then u
    else if atom u then if atsoc(u,vars) then u else mkquote u
    else if car u memq '(quote !:dn!: !:int!:) then mkquote u
    else 'list . mapcar(u,function (lambda x; mkarg(x,vars)));

% Form functions needed for number input.

put('!:dn!:,'formfn,'dnform);

% symbolic procedure dnform(u,vars,mode);
%    if mode eq 'symbolic
%      then compress nconc!*(explode cadr u,'!. . 'e . explode cddr u)
%     else progn(if !*adjprec then precmsg length explode abs cadr u,
%                mkquote(quote !:rd!: . cdr u));

symbolic procedure dnform(u,vars,mode);
   if mode eq 'symbolic
     then compress nconc!*(explode cadr u,'!. . 'e . explode cddr u)
    else progn(if !*adjprec then precmsg length explode abs cadr u,
               mkquote if cddr u >= 0
                         then decimal2internal(cadr u,cddr u)
                        else u);

put('!:int!:,'formfn,'intform);

symbolic procedure intform(u,vars,mode);
   if mode eq 'symbolic then mkquote cadr u
   else progn(precmsg length explode abs cadr u, mkquote cadr u);

endmodule;


module proc;   % Procedure statement.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*nosmacros !*redeflg!* fname!* ftype!*);

global '(!*argnochk !*comp !*lose !*micro!-version cursym!* erfg!*
         ftypes!*);

fluid '(!*defn);

!*lose := t;

ftypes!* := '(expr fexpr macro);

symbolic procedure formproc(u,vars,mode);
   begin scalar body,fname!*,name,type,varlis,x,y;
        u := cdr u;
        name := fname!* := car u;
        if cadr u then mode := cadr u;   % overwrite previous mode
        u := cddr u;
        type := ftype!* := car u;
        if flagp(name,'lose) and (!*lose or null !*defn)
          then return progn(lprim list(name,
                            "not defined (LOSE flag)"),
                        nil)
         else if !*redeflg!* and getd name
          then lprim list(name,"redefined");
        varlis := cadr u;
        u := caddr u;
        x := if eqcar(u,'block) then cadr u else nil;
        y := pairxvars(varlis,x,vars,mode);
        if x then u := car u . rplaca!*(cdr u,cdr y);
        body:= form1(u,car y,mode);   % FORMC here would add REVAL.
        if !*nosmacros and type eq 'smacro then type := 'expr;
        if type eq 'expr then body := list('de,name,varlis,body)
         else if type eq 'fexpr then body := list('df,name,varlis,body)
         else if type eq 'macro then body := list('dm,name,varlis,body)
         else if (x := get(type,'procfn))
          then return apply3(x,name,varlis,body)
         else body := list('putc,
                           mkquote name,
                           mkquote type,
                           mkquote list('lambda,varlis,body));
        if not(mode eq 'symbolic)
          then body := list('progn,
                         list('flag,mkquote list name,mkquote 'opfn),
                          body);
        if !*argnochk and type memq '(expr smacro)
          then body := list('progn,
                        list('put,mkquote name,
                                  mkquote 'number!-of!-args,
                                  length varlis),
                          body);
        if !*defn and type memq '(fexpr macro smacro)
          then lispeval body;
        return if !*micro!-version and type memq '(fexpr macro smacro)
                 then nil
                else body
   end;

put('procedure,'formfn,'formproc);

symbolic procedure pairxvars(u,v,vars,mode);
   %Pairs procedure variables and their modes, taking into account
   %the convention which allows a top level prog to change the mode
   %of such a variable;
   begin scalar x,y;
   a: if null u then return append(reversip!* x,vars) . v
       else if (y := atsoc(car u,v))
        then <<v := delete(y,v);
               if not(cdr y eq 'scalar) then x := (car u . cdr y) . x
                else x := (car u . mode) . x>>
       else x := (car u . mode) . x;
      u := cdr u;
      go to a
   end;

symbolic procedure procstat1 mode;
   begin scalar bool,u,type,x,y,z;
        bool := erfg!*;
        if fname!* then go to b
         else if cursym!* eq 'procedure then type := 'expr
         else progn(type := cursym!*,scan());
        if not cursym!* eq 'procedure then go to c;
        x := errorset!*('(xread (quote proc)),nil);
        if errorp x then go to a
         else if atom (x := car x) then x := list x;   % No arguments.
        fname!* := car x;   %function name;
        if idp fname!* % and not(type memq ftypes!*)
          then if null fname!* or (z := gettype fname!*)
                        and not z memq '(procedure operator)
                then go to d
              else if not getd fname!* then flag(list fname!*,'fnc);
           % To prevent invalid use of function name in body.
        u := cdr x;
        y := u;   % Variable list.
        if idlistp y then x := car x . y
         else lprie list(y,"invalid as parameter list");
    a:  z := errorset!*('(xread t),nil);
        if not errorp z then z := car z;
%       if not atom z and eqcar(car z,'!*comment!*) then z := cadr z;
        if null erfg!* then z:=list('procedure,car x,mode,type,y,z);
        remflag(list fname!*,'fnc);
        fname!*:=nil;
        if erfg!* then progn(z := nil,if not bool then error1());
        return z;
    b:  bool := t;
    c:  errorset!*('(symerr (quote procedure) t),nil);
        go to a;
    d:  typerr(list(z,fname!*),"procedure");
        go to a
   end;

symbolic procedure procstat; procstat1 nil;

deflist ('((procedure procstat) (expr procstat) (fexpr procstat)
           (emb procstat) (macro procstat) (smacro procstat)),
        'stat);

% Next line refers to bootstrapping process.

if get('symbolic,'stat) eq 'procstat then remprop('symbolic,'stat);

deflist('((lisp symbolic)),'newnam);

endmodule;


module forstat;   % Definition of REDUCE FOR loops.

% Author: Anthony C. Hearn.

% Copyright (c) 1993 The RAND Corporation.  All rights reserved.

fluid '(!*blockp !*fastfor);

global '(cursym!* foractions!*);

Comment the syntax of the FOR statement is as follows:

                 {step i3 until}
        {i := i1 {             } i2 }
        {        {      :      }    }
   for  {                           } <action> <expr>
        {        { in }             }
        { each i {    }  <list>     }
                 { on }

In all cases, the <expr> is evaluated algebraically within the scope of
the current value of i.  If <action> is DO, then nothing else happens.
In other cases, <action> is a binary operator that causes a result to be
built up and returned by FOR.  In each case, the loop is initialized to
a default value.  The test for the end condition is made before any
action is taken.

The effect of the definition here is to replace all for loops by
semantically equivalent blocks.  As a result, none of the mapping
functions are needed in REDUCE.

To declare a set of actions, one says;

foractions!* := '(do collect conc product sum);

remflag(foractions!*,'delim);    % For bootstrapping purposes.

% To associate a binary function with an action, one says:

deflist('((product times) (sum plus)),'bin);

% And to give these an initial value in a loop:

deflist('((product 1) (sum 0)),'initval);

% NB:  We need to reset for and let delims if an error occurs.  It's
% probably best to do this in the begin1 loop.

% flag('(for),'nochange);

symbolic procedure forstat;
   begin scalar !*blockp;
      return if scan() eq 'all then forallstat()
              else if cursym!* eq 'each then foreachstat()
              else forloop()
   end;

put('for,'stat,'forstat);

symbolic procedure forloop;
   begin scalar action,bool,incr,var,x;
      if flagp('step,'delim) then bool := t else flag('(step),'delim);
      x := errorset!*('(xread1 'for),t);
      if null bool then remflag('(step),'delim) else bool := nil;
      if errorp x then error1() else x := car x;
      if not eqcar(x,'setq) or not idp(var := cadr x)
        then symerr('for,t);
      x := caddr x;
      if cursym!* eq 'step
        then <<if flagp('until,'delim) then bool := t
                else flag('(until),'delim);
               incr := xread t;
               if null bool then remflag('(until),'delim)
                else bool := nil;
               if not cursym!* eq 'until then symerr('for,t)>>
       else if cursym!* eq '!*colon!* then incr := 1
       else symerr('for,t);
      if flagp(car foractions!*,'delim) then bool := t % nested loop
       else flag(foractions!*,'delim);
      incr := list(x,incr,xread t);
      if null bool then remflag(foractions!*,'delim);
      if not((action := cursym!*) memq foractions!*)
        then symerr('for,t);
      return list('for,var,incr,action,xread t)
   end;

symbolic procedure formfor(u,vars,mode);
   begin scalar action,algp,body,endval,incr,initval,var,x;
        %ALGP is used to determine if the loop calculation must be
        %done algebraically or not;
      var := cadr u;
      incr := caddr u;
      incr := list(formc(car incr,vars,mode),
                   formc(cadr incr,vars,mode),
                   formc(caddr incr,vars,mode));
      if not atsoc(var,vars)
        then if intexprnp(car incr,vars) and intexprnp(cadr incr,vars)
               then vars := (var . 'integer) . vars
              else vars := (var . mode) . vars;
      action := cadddr u;
      body := formc(car cddddr u,vars,mode);
      initval := car incr;
      endval := caddr incr;
      incr := cadr incr;
      algp := algmodep initval or algmodep incr or algmodep endval;
      if algp then <<endval := unreval endval; incr := unreval incr>>;
      x := if algp then list('list,''difference,endval,var)
            else list(if !*fastfor then 'idifference else 'difference,
                      endval,var);
      if incr neq 1
        then x := if algp then list('list,''times,incr,x)
                   else list('times,incr,x);
      % We could consider simplifying X here (via reval).
      x := if algp then list('aminusp!:,x)
            else list(if !*fastfor then 'iminusp else 'minusp,x);
      return forformat(action,body,initval,x,
                       if algp
                          then list('aeval!*,list('list,''plus,incr))
                        else list(if !*fastfor then 'iplus2 else 'plus2,
                                  incr),
                       var,vars,mode)
   end;

put('for,'formfn,'formfor);

symbolic procedure algmodep u;
    not atom u and car u memq '(aeval aeval!*);

symbolic procedure aminusp!: u;
   begin scalar x;
      u := aeval!* u;
      x := u;
      if fixp x then return minusp x
       else if not eqcar(x,'!*sq)
        then msgpri(nil,reval u,"invalid in FOR statement",nil,t);
      x := cadr x;
      if fixp car x and fixp cdr x then return minusp car x
       else if not cdr x = 1
             or not (atom(x := car x) or atom car x)
         % Should be DOMAINP, but SMACROs not yet defined.
        then msgpri(nil,reval u,"invalid in FOR statement",nil,t)
       else return apply1('!:minusp,x)
   end;

symbolic procedure foreachstat;
   begin scalar w,x,y,z;
        if not idp(x := scan()) or not (y := scan()) memq '(in on)
          then symerr("FOR EACH",t)
         else if flagp(car foractions!*,'delim) then w := t
         else flag(foractions!*,'delim);
        z := xread t;
        if null w then remflag(foractions!*,'delim);
        w := cursym!*;
        if not w memq foractions!* then symerr("FOR EACH",t);
        return list('foreach,x,y,z,w,xread t)
   end;

put('foreach,'stat,'foreachstat);

symbolic procedure formforeach(u,vars,mode);
   begin scalar action,body,lst,mod,var;
        var := cadr u; u := cddr u;
        mod := car u; u := cdr u;
        lst := formc(car u,vars,mode); u := cdr u;
        if not(mode eq 'symbolic) then lst := list('getrlist,lst);
        action := car u; u := cdr u;
        body := formc(car u,(var . mode) . vars,mode); % was FORMC
        if mod eq 'in
          then body := list(list('lambda,list var,body),list('car,var))
         else if not(mode eq 'symbolic) then typerr(mod,'action);
        return forformat(action,body,lst,
                         list('null,var),list 'cdr,var,vars,mode)
   end;

put('foreach,'formfn,'formforeach);

symbolic procedure forformat(action,body,initval,
                             testexp,updform,var,vars,mode);
   begin scalar result;
       % Next test is to correct structure generated by formfor.
      if algmodep updform and length cadr updform > 2
         then <<result:=gensym();
                updform:= list list('lambda,
                                    list result,
                                    list('aeval!*,
                                         caadr updform .
                                              cadadr updform .
                                              result .
                                              cddadr updform))>>;
      result := gensym();
      return
         sublis(list('body2 .
                if mode eq 'symbolic or intexprnp(body,vars)
                  then list(get(action,'bin),body,result)
                 else list('aeval!*,list('list,mkquote get(action,'bin),
                            unreval body,result)),
               'body3 .
                   if mode eq 'symbolic then body
                      else list('getrlist,body),
               'body . body,
               'initval . initval,
               'nillist . if mode eq 'symbolic then nil else ''(list),
               'result . result,
               'initresult . get(action,'initval),
               'resultlist . if mode eq 'symbolic then result
                              else list('cons,''list,result),
               'testexp . testexp,
               'updfn . car updform,
               'updval . cdr updform,
               'var . var),
          if action eq 'do
            then '(prog (var)
                  (setq var initval)
              lab (cond (testexp (return nil)))
                  body
                  (setq var (updfn var . updval))
                  (go lab))
           else if action eq 'collect
            then '(prog (var result endptr)
                  (setq var initval)
                  (cond (testexp (return nillist)))
                  (setq result (setq endptr (cons body nil)))
                looplabel
                  (setq var (updfn var . updval))
                  (cond (testexp (return resultlist)))
                  (rplacd endptr (cons body nil))
                  (setq endptr (cdr endptr))
                  (go looplabel))
           else if action eq 'conc
            then '(prog (var result endptr)
                  (setq var initval)
               startover
                  (cond (testexp (return nillist)))
                  (setq result body)
                  (setq endptr (lastpair resultlist))
                  (setq var (updfn var . updval))
                  (cond ((atom endptr) (go startover)))
                looplabel
                  (cond (testexp (return result)))
                  (rplacd endptr body3)
                  (setq endptr (lastpair endptr))
                  (setq var (updfn var . updval))
                  (go looplabel))
           else '(prog (var result)
                 (setq var initval)
                 (setq result initresult)
              lab1
                 (cond (testexp (return result)))
                 (setq result body2)
                 (setq var (updfn var . updval))
                 (go lab1)))
   end;

symbolic procedure lastpair u;
   % Return the last pair of the list u.
   if atom u or atom cdr u then u else lastpair cdr u;

symbolic procedure unreval u;
   % Remove spurious aeval or reval in inner expression.
   if atom u or null(car u memq '(aeval reval)) then u else cadr u;

remprop('conc,'newnam);

put('join,'newnam,'conc);   % alternative for CONC

endmodule;


module loops;  % Looping forms other than the FOR statement.

% Author: Anthony C. Hearn

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*blockp);

global '(cursym!*);


% ***** REPEAT STATEMENT *****

symbolic procedure repeatstat;
  begin scalar !*blockp,body,bool;
        if flagp('until,'delim) then bool := t
         else flag('(until),'delim);
        body:= xread t;
        if not bool then remflag('(until),'delim);
        if not cursym!* eq 'until then symerr('repeat,t);
        return list('repeat,body,xread t);
   end;

symbolic macro procedure repeat u;
   begin scalar body,bool,lab;
        body := cadr u; bool := caddr u;
        lab := gensym();
        return mkprog(nil,list(lab,body,
                list('cond,list(list('not,bool),list('go,lab)))))
   end;

put('repeat,'stat,'repeatstat);

flag('(repeat),'nochange);

symbolic procedure formrepeat(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'aeval!*;
      return list('repeat,formc(cadr u,vars,mode),
                  formbool(caddr u,vars,mode))
   end;

put('repeat,'formfn,'formrepeat);


% ***** WHILE STATEMENT *****

symbolic procedure whilstat;
   begin scalar !*blockp,bool,bool2;
        if flagp('do,'delim) then bool2 := t else flag('(do),'delim);
        bool := xread t;
        if not bool2 then remflag('(do),'delim);
        if not cursym!* eq 'do then symerr('while,t);
        return list('while,bool,xread t)
   end;

symbolic macro procedure while u;
   begin scalar body,bool,lab;
        bool := cadr u; body := caddr u;
        lab := gensym();
        return mkprog(nil,list(lab,list('cond,list(list('not,bool),
                list('return,nil))),body,list('go,lab)))
   end;

put('while,'stat,'whilstat);

flag('(while),'nochange);

symbolic procedure formwhile(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'aeval!*;
      return list('while,formbool(cadr u,vars,mode),
                  formc(caddr u,vars,mode))
   end;

put('while,'formfn,'formwhile);

endmodule;


module write;  % Miscellaneous statement definitions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

% ***** DEFINE STATEMENT *****

remprop('define,'stat);

symbolic procedure define u;
   for each x in u do
      if not eqcar(x,'equal) or not idp cadr x
        then typerr(x,"DEFINE declaration")
       else put(cadr x,'newnam,caddr x);

deflist('((define rlis)),'stat);

flag('(define),'eval);

% ***** WRITE STATEMENT *****

symbolic procedure formwrite(u,vars,mode);
   begin scalar bool1,bool2,x,z;
      u := cdr u;
      bool1 := mode eq 'symbolic;
      while u do
        <<x := formc(car u,vars,mode);
          z := (if bool1 then list('prin2,x)
                      else list('writepri,mkarg1(x,vars),
          if not cdr u then if not bool2 then ''only else ''last
           else if not bool2 then ''first else nil)) .
                             z;
          bool2 := t;
          u := cdr u>>;
        if bool1 then z := nil . z;  % Since PRIN2 returns its value.
        return if null z then nil
                else if null cdr z then car z
                else 'progn . reversip!* z
   end;

symbolic procedure writepri(u,v);
   % Output "write" statements.  Write returns NIL.
   begin scalar x; x := assgneval u; varpri(car x,cdr x,v) end;

symbolic procedure mkarg1(u,vars);
   % Returns the "unevaled" form of U for the WRITE command.
   if null u or constantp u then u
    else if atom u then if atsoc(u,vars)
     then list('mkquote,u) else mkquote u
    else if car u eq 'quote then mkquote u
    else if car u eq 'setq
     then list('list,''setq,mkquote cadr u,mkarg1(caddr u,vars))
    else 'list . mapcar(u,function (lambda x; mkarg1(x,vars)));

put('write,'stat,'rlis);

put('write,'formfn,'formwrite);

% ECHOPR is similar to WRITE but, if switch TESTECHO is on, it echoes
% an offline print onto the % screen, in either algebraic or symbolic
% mode.

% Switch is not yet defined.

flag('(testecho),'switch);

put('echopr,'stat,'rlis);

put('echopr,'formfn,'formechopr);

symbolic procedure formechopr(u,vars,mode);
   (lambda x; list ('progn,x,
      list ('cond,list ('(and !*testecho ofl!*),
         list (list ('lambda,'(n),
            list ('progn,x,'(wrs n),nil)),'(wrs nil) ))) ))
       formwrite(u,vars,mode);

endmodule;


module smacro;  % Support for SMACRO expansion.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

symbolic procedure applsmacro(u,vals,name);
   % U is smacro body of form (lambda <varlist> <body>), VALS is
   % argument list, NAME is name of smacro.
   begin scalar body,remvars,varlist,w;
      varlist := cadr u;
      body := caddr u;
      if length varlist neq length vals
        then rerror(rlisp,15,list("Argument mismatch for SMACRO",name));
      if no!-side!-effect!-listp vals or one!-entry!-listp(varlist,body)
        then return subla!-q(pair(varlist,vals),body)
       else if length varlist>1
        then <<w := for each x in varlist collect (x . gensym());
               body := subla!-q(w,body);
               varlist := for each x in w collect cdr x>>;
      for each x in vals do
         <<if no!-side!-effectp x or one!-entryp(car varlist,body)
             then body := subla!-q(list(car varlist . x),body)
            else remvars := aconc(remvars,car varlist . x);
           varlist := cdr varlist>>;
      if null remvars then return body
       else <<w := list('lambda,
                         for each x in remvars collect car x,
                         body) .
                    for each x in remvars collect cdr x;
%             if not eqcar(cadr w,'setq)
%               then <<prin2 "*** smacro: "; print cdr w>>;
              return w>>
   end;

symbolic procedure no!-side!-effectp u;
   if atom u then numberp u or idp u and not(fluidp u or globalp u)
    else if car u eq 'quote then t
    else if flagp!*!*(car u,'nosideeffects)
     then no!-side!-effect!-listp cdr u
    else nil;

symbolic procedure no!-side!-effect!-listp u;
   null u or no!-side!-effectp car u and no!-side!-effect!-listp cdr u;

flag('(car cdr caar cadr cdar cddr caaar caadr cadar caddr cdaar cdadr
       cddar cdddr cons),'nosideeffects);

symbolic procedure one!-entryp(u,v);
   % determines if id U occurs less than twice in V.
   if atom v then t
    else if smemq(u,car v)
     then if smemq(u,cdr v) then nil else one!-entryp(u,car v)
    else one!-entryp(u,cdr v);

symbolic procedure one!-entry!-listp(u,v);
   null u or one!-entryp(car u,v) and one!-entry!-listp(cdr u,v);

symbolic procedure subla!-q(u,v);
   begin scalar x;
        if null u or null v then return v
         else if atom v
                 then return if x:= atsoc(v,u) then cdr x else v
         else if car v eq 'quote then return v
         else return(subla!-q(u,car v) . subla!-q(u,cdr v))
   end;

put('smacro,'macrofn,'applsmacro);

endmodule;


module infix; % Functions for introducing new infix operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*mode);

global '(preclis!*);

symbolic procedure forminfix(u,vars,mode);
   begin scalar x;
      if null(mode eq 'symbolic)
       then x := for each j in cdr u collect list('mkop,mkarg(j,vars));
      u := list(car u,mkarg(cdr u,vars));
      return if x then 'progn . aconc(x,u) else u
   end;

put('infix,'formfn,'forminfix);

symbolic procedure infix x;
   <<for each j in x do
        if not(j member preclis!*) then preclis!* := j . preclis!*;
     mkprec()>>;

symbolic procedure precedence u;
   begin scalar x,y,z;
      preclis!* := delete(car u,preclis!*);
      y := cadr u;
      x := preclis!*;
   a: if null x then rerror(rlisp,16,list (y,"not found"))
       else if y eq car x
        then <<preclis!* :=
                  nconc!*(reversip!* z,car x . (car u . cdr x));
               mkprec();
               return nil>>;
      z := car x . z;
      x := cdr x;
      go to a
   end;

deflist('((infix rlis) (precedence rlis)),'stat);

flag('(infix precedence),'eval);

endmodule;


module switch;  % Support for switches and ON and OFF statements.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

global '(!*switchcheck switchlist!*);

% No references to RPLAC-based functions in this module.

symbolic procedure on u; for each j in u do on1 j;

symbolic procedure off u; for each j in u do off1 j;

symbolic procedure off1 u; onoff(u,nil);

symbolic procedure on1 u; onoff(u,t);

symbolic procedure onoff(u,bool);
   begin scalar x,y;
      if not idp u then typerr(u,"switch")
       else if not flagp(u,'switch)
%       then if !*switchcheck
               then rerror(rlisp,25,list(u,"not defined as switch"));
%             else lpriw("*****",list(u,"not defined as switch"));
      x := intern compress append(explode '!*,explode u);
      if !*switchcheck and lispeval x eq bool then return nil
       else if y := atsoc(bool,get(u,'simpfg))
        then lispeval('progn . append(cdr y,list nil));
      if bool and x eq '!*!r!a!i!s!e then x := '!*raise; % Special case.
       set(x,bool)
   end;

symbolic procedure switch u;
   % Declare list u as switches.
   for each x in u do
      begin scalar y;
         if not idp x then typerr(x,"switch");
         if not x memq switchlist!*
           then switchlist!* := x . switchlist!*;
         flag(list x,'switch);
         y := intern compress append(explode '!*,explode x);
         if not fluidp y and not globalp y then fluid list y
      end;

deflist('((switch rlis)),'stat);   % we use deflist since it's flagged
                                   % eval
flag('(switch),'eval);

put('off,'stat,'rlis);

put('on,'stat,'rlis);

flag ('(off on),'ignore);

% Symbolic mode switches:

switch backtrace,comp,defn,demo,echo,errcont,fastfor,   % eoldelimp
       int,lessspace,msg,output,pret,quotenewnam,raise,time;

put('eoldelimp,'simpfg,'((t (flag (list !$eol!$) 'delchar))
                         (nil (remflag (list !$eol!$) 'delchar))));

endmodule;


module where;  % Support for a where construct.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(fixedpreclis!*);

symbolic procedure formwhere(u,vars,mode);
   begin scalar expn,equivs,y,z;
     expn := cadr u;
     equivs := remcomma caddr u;
     if not(mode eq 'symbolic)
       then return formc(list('whereexp,'list . equivs,expn),vars,mode);
     for each j in equivs do
        if not atom j and car j memq '(equal setq)
          then <<y := caddr j . y; z := cadr j . z>>
         else rerror(rlisp,17,list(j,"invalid in WHERE statement"));
     return formc(list('lambda,reversip z,expn) . reversip y,vars,mode)
   end;

put('where,'formfn,'formwhere);

fixedpreclis!* := 'where . fixedpreclis!*;  % Where has a special place.

mkprec();

endmodule;


module list; % Define a list as a list of expressions in curly brackets.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(orig!* posn!*);

global '(cursym!* simpcount!* simplimit!*);

% Add to system table.

put('list,'tag,'list);

put('list,'rtypefn,'quotelist);

symbolic procedure quotelist u; 'list;

% Parsing interface.

symbolic procedure xreadlist;
   % Expects a list of expressions enclosed by {, }.
   % Used to allow expressions separated by ; - treated these as progn.
   begin scalar cursym,delim,lst;
        if scan() eq '!*rcbkt!* then <<scan(); return list 'list>>;
    a:  lst := aconc(lst,xread1 'group);
        cursym := cursym!*;
        if cursym eq '!*semicol!*
          then symerr("Syntax error: semicolon in list",nil)
         else if scan() eq '!*rcbkt!* and cursym eq '!*comma!*
          then symerr("Syntax error: invalid comma in list",nil);
        if cursym eq '!*rcbkt!*
          then return % if delim eq '!*semicol!*
                      %   then 'progn . lst else
                      'list . lst
         else if null delim then delim := cursym;
%        else if not(delim eq cursym)
%         then symerr("Syntax error: mixed , and ; in list",nil);
        go to a
   end;

put('!*lcbkt!*,'stat,'xreadlist);

newtok '((!{) !*lcbkt!*);

newtok '((!}) !*rcbkt!*);

flag('(!*rcbkt!*),'delim);

flag('(!*rcbkt!*),'nodel);

% Evaluation interface.

put('list,'evfn,'listeval);

put('list,'simpfn,'simpiden);  % This is a little kludgey, but allows
                              % things like dms2deg to work.

symbolic procedure getrlist u;
   if eqcar(u,'list) then cdr u
    else typerr(if eqcar(u,'!*sq) then prepsq cadr u else u,"list");

symbolic procedure listeval(u,v);
   <<if (simpcount!* := simpcount!*+1)>simplimit!*
       then <<simpcount!* := 0;
              rerror(rlisp,18,"Simplification recursion too deep")>>;
     u := if atom u
            then listeval(if flagp(u,'share) then eval u
                           else cadr get(u,'avalue),v)
           else if car u eq 'list
            then makelist for each x in cdr u collect reval1(x,v)
           else ((if x then apply2(x,cdr u,v)
                   else rerror(rlisp,19,"Illegal operation on lists"))
                 where x = get(car u,'listfn));
     simpcount!* := simpcount!* - 1;
     u>>;

symbolic procedure makelist u;
   % Make a list out of elements in u.
   'list . u;


% Length interface.

put('list,'lengthfn,'lengthcdr);

symbolic procedure lengthcdr u; length cdr u;


% Printing interface.

put('list,'prifn,'listpri);

symbolic procedure listpri l;
   % This definition is basically that of INPRINT, except that it
   % decides when to split at the comma by looking at the size of
   % the argument.
   begin scalar orig,split,u;
      u := l;
      l := cdr l;
      prin2!* get('!*lcbkt!*,'prtch);
         % Do it this way so table can change.
      orig := orig!*;
      orig!* := if posn!*<18 then posn!* else orig!*+3;
      if null l then go to b;
      split := treesizep(l,40);   % 40 is arbitrary choice.
   a: maprint(negnumberchk car l,0);
      l := cdr l;
      if null l then go to b;
      oprin '!*comma!*;
      if split then terpri!* t;
      go to a;
   b: prin2!* get('!*rcbkt!*,'prtch);
%     terpri!* nil;
      orig!* := orig;
      return u
   end;

symbolic procedure treesizep(u,n);
   % true if u has recursively more pairs than n.
   treesizep1(u,n)=0;

symbolic procedure treesizep1(u,n);
   if atom u then n - 1
    else if (n := treesizep1(car u,n))>0 then treesizep1(cdr u,n)
    else 0;

% Definitions of operations on lists.

symbolic procedure listeval0 u;
   begin scalar v;
     if (simpcount!* := simpcount!*+1)>simplimit!*
        then <<simpcount!* := 0;
                rerror(rlisp,20,"Simplification recursion too deep")>>;
     if idp u
       then if flagp(u,'share) then u := listeval0 eval u
             else if (v := get(u,'avalue)) and cadr v neq u
              then u := listeval0 cadr v;
     simpcount!* := simpcount!* - 1;
     return u
   end;

% First, second, third and rest are designed so that only the relevant
% elements need be fully evaluated.

symbolic procedure rfirst u;
   begin scalar x;
      u := car u;
      if null(getrtype(x := listeval0 u) eq 'list)
         and null(getrtype(x := aeval u) eq 'list)
        then typerr(u,"list");
      if null cdr x then parterr(u,1) else return reval cadr x
   end;

put('first,'psopfn,'rfirst);

symbolic procedure parterr(u,v);
   msgpri("Expression",u,"does not have part",v,t);

symbolic procedure rsecond u;
   begin scalar x;
      u := car u;
      if null(getrtype(x := listeval0 u) eq 'list)
         and null(getrtype(x := aeval u) eq 'list)
        then typerr(u,"list");
      if null cdr x or null cddr x then parterr(u,2)
       else return reval caddr x
   end;

put('second,'psopfn,'rsecond);

symbolic procedure rthird u;
   begin scalar x;
      u := car u;
      if null(getrtype(x := listeval0 u) eq 'list)
         and null(getrtype(x := aeval u) eq 'list)
        then typerr(u,"list");
      if null cdr x or null cddr x or null cdddr x then parterr(u,3)
       else return reval cadddr x
   end;

put('third,'psopfn,'rthird);

deflist('((first (lambda (x) 'yetunknowntype))
          (second (lambda (x) 'yetunknowntype))
          (third (lambda (x) 'yetunknowntype))
          (part (lambda (x) 'yetunknowntype))),
        'rtypefn);

symbolic procedure rrest u;
   begin scalar x;
      argnochk('cdr . u);
      u := car u;
      if null(getrtype(x := listeval0 u) eq 'list)
         and null(getrtype(x := aeval u) eq 'list)
        then typerr(u,"list");
      if null cdr x then typerr(u,"non-empty list")
       else return 'list . for each y in cddr x collect reval y
   end;

put('rest,'psopfn,'rrest);

deflist('((first 1) (second 1) (third 1) (rest 1)),'number!-of!-args);

symbolic procedure rappend u;
   begin scalar x,y;
      argnochk('append . u);
      if null(getrtype(x := reval car u) eq 'list)
        then typerr(x,"list")
      else if null(getrtype(y := reval cadr u) eq 'list)
       then typerr(y,"list")
      else return 'list . append(cdr x,cdr y)
   end;

put('append,'psopfn,'rappend);

symbolic procedure rcons u;
   begin scalar x,y,z;
      argnochk('cons . u);
      if (y := getrtypeor(x := revlis u)) eq 'hvector
    then return if get('cons,'opmtch) and (z := opmtch('cons . x))
                   then reval z
                 else prepsq subs2 simpdot x
       else if not(getrtype cadr x eq 'list) then typerr(x,"list")
       else return 'list . car x . cdadr x
   end;

put('cons,'psopfn,'rcons);

symbolic procedure rreverse u;
   <<argnochk ('reverse . u);
     if null(getrtype(u := reval car u) eq 'list) then typerr(u,"list")
      else 'list . reverse cdr u>>;

put('reverse,'psopfn,'rreverse);

% Aggregate Property.

symbolic procedure listmap(u,v);
   begin scalar x;
      x := cadr u;
      if null eqcar(x,'list) and null eqcar(x := reval1(x,v),'list)
        then typerr(cadr u,"list");
      return 'list
              . for each j in cdr x collect reval1(car u . j . cddr u,v)
   end;

put('list,'aggregatefn,'listmap);

endmodule;


module array; % Array statement.

% Author: Anthony C. Hearn.
% Modifications by: Nancy Kirkwood.

% These definitions are very careful about bounds checking. Appropriate
% optimizations in a given system might really speed things up.

fluid '(!*rlisp88);

global '(erfg!*);

symbolic procedure getel u;
   % Returns the value of the array element U.
   getel1(cadr get(car u,'avalue),cdr u,get(car u,'dimension));

symbolic procedure getel1(u,v,dims);
   if length v neq length dims
     then rerror(rlisp,21,"Incorrect array reference")
    else if null v then u
    else if car v geq car dims
     then rerror(rlisp,22,"Array out of bounds")
    else getel1(getv(u,car v),cdr v,cdr dims);

symbolic procedure setel(u,v);
   % Sets array element U to V and returns V.
   setel1(cadr get(car u,'avalue),cdr u,v,get(car u,'dimension));

symbolic procedure setel1(u,v,w,dims);
   if length v neq length dims
     then rerror(rlisp,22,"Incorrect array reference")
    else if car v geq car dims
     then rerror(rlisp,23,"Array out of bounds")
    else if null cdr v then putv(u,car v,w)
    else setel1(getv(u,car v),cdr v,w,cdr dims);

symbolic procedure dimension u; get(u,'dimension);


Comment further support for REDUCE arrays;

symbolic procedure typechk(u,v);
   begin scalar x;
      if (x := gettype u) eq v or x eq 'parameter
        then lprim list(v,u,"redefined")
       else if x then typerr(list(x,u),v)
   end;

symbolic procedure arrayfn(u,v);
   % U is the defining mode, V a list of lists, assumed syntactically
   % correct. ARRAYFN declares each element as an array unless a
   % semantic mismatch occurs.
   begin scalar y;
      for each x in v do
         <<typechk(car x,'array);
       y := add1lis for each z in cdr x collect lispeval z;
       if null erfg!*
         then <<put(car x,'rtype,'array);
            put(car x,'avalue,list('array,mkarray1(y,u)));
            put(car x,'dimension,y)>>>>
   end;

flag('(arrayfn),'nochange);

symbolic procedure add1lis u;
   if null u then nil else (car u+1) . add1lis cdr u;

symbolic macro procedure mkarray u;
   if null !*rlisp88 then mkarray1(u,'algebraic) else
     list('mkar1,'list . cdr u);

symbolic procedure mkarray1(u,v);
   % U is a list of positive integers representing array bounds, V
   % the defining mode. Value is an array structure.
   if null u then if v eq 'symbolic then nil else 0
    else begin integer n; scalar x;
      n := car u - 1;
      x := mkvect n;
      for i:=0:n do putv(x,i,mkarray1(cdr u,v));
      return x
   end;

put('array,'stat,'rlis);

flag ('(array arrayfn),'eval);

symbolic procedure formarray(u,vars,mode);
   begin scalar x;
      x := cdr u;
      while x do <<if atom x then typerr(x,"Array List")
                  else if atom car x or not idp caar x
                         or not listp cdar x
                  then typerr(car x,"Array declaration");
                   x := cdr x>>;
      u := for each z in cdr u collect intargfn(z,vars,mode);
      %ARRAY arguments must be returned as quoted structures;
      return list('arrayfn,mkquote mode,'list . u)
   end;

put('array,'formfn,'formarray);

put('array,'rtypefn,'arraychk);

symbolic procedure arraychk u;
   % If arraychk receives NIL, it means that array name is being used
   % as an identifier. We no longer permit this.
   if null u then 'array else nil;
%  nil;

put('array,'evfn,'arrayeval);

symbolic procedure arrayeval(u,v);
   % Eventually we'll support this properly.
   if not atom u then rerror(rlisp,24,"Array arithmetic not defined")
    else u;

put('array,'lengthfn,'arraylength);

symbolic procedure arraylength u; 'list . get(u,'dimension);

endmodule;


module io; % Reduce functions for handling input and output of files.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*echo !*int semic!*);

global '(contl!* curline!* ifl!* ipl!* linelist!* ofl!* opl!* techo!*);

% symbolic procedure filep u;
%    % Returns T if u is the name of an existing file.
%    begin
%       if errorp(u := errorset!*(list('open,mkquote u,''input),nil))
%         then return nil;
%       close car u;
%       return t
%    end;

symbolic procedure file!-transform(u,v);
   % Performs a transformation on the file u.  V is name of function
   % used for the transformation.
   begin scalar echo,ichan,oldichan,val;
      echo := !*echo;
      !*echo := nil;
      ichan := open(u,'input);
      oldichan := rds ichan;
      val := errorset!*(list v,t);
      !*echo := echo;
      close ichan;
      rds oldichan;
      if not errorp val then return car val
   end;

symbolic procedure infile u;
   % Loads the single file u into REDUCE without echoing.
   begin scalar !*int;
   return file!-transform(u,function begin1)
   end;

symbolic procedure in u;
   begin scalar echop;
      echop := null(semic!* eq '!$); % Record echo character from input.
      if null ifl!* then techo!* := !*echo;   % Terminal echo status.
      for each fl in u do in1(fl,echop);
      if ipl!* then ifl!* := car ipl!* else ifl!* := nil;
      if ifl!* then curline!* := caddr ifl!*
   end;

symbolic procedure in1(fl,echop);
   begin scalar chan,echo,ochan,type;
      echo := !*echo;   % Save current echo status.
      chan := open(fl := mkfil fl,'input);
      ochan := rds chan;
      if assoc(fl,linelist!*) then nil;
      curline!* := 1;
      ifl!* := list(fl,chan,1);
      ipl!* := ifl!* . ipl!*;  % Add to input file stack.
      !*echo := echop;
      type := filetype fl;
      if type and (type := get(type,'action)) then lispeval list type
       else begin1();
      rds ochan;
      close chan;
      !*echo := echo;   % Restore echo status.
      if null ipl!* and contl!* then return nil
       else if null ipl!* or null(fl eq caar ipl!*)
        then rederr list("FILE STACK CONFUSION",fl,ipl!*)
       else ipl!* := cdr ipl!*
   end;

symbolic procedure out u;
   % U is a list of one file.
   begin integer n; scalar chan,fl,x;
        n := linelength nil;
        if null u then return nil
         else if car u eq 't then return <<wrs(ofl!* := nil); nil>>;
        fl := mkfil car u;
        if not (x := assoc(fl,opl!*))
          then <<chan := open(fl,'output);
                 if chan
                   then <<ofl!*:= fl . chan; opl!*:= ofl!* . opl!*>>>>
         else ofl!* := x;
        wrs cdr ofl!*;
        linelength n
   end;

symbolic procedure shut u;
   % U is a list of names of files to be shut.
   begin scalar fl1;
      for each fl in u do
       <<if fl1 := assoc((fl := mkfil fl),opl!*)
           then <<opl!* := delete(fl1,opl!*);
                  if fl1=ofl!* then <<ofl!* := nil; wrs nil>>;
                  close cdr fl1>>
         else if not (fl1 := assoc(fl,ipl!*))
          then rerror(rlisp,26,list(fl,"not open"))
         else if fl1 neq ifl!*
          then <<close cadr fl1; ipl!* := delete(fl1,ipl!*)>>
         else rerror(rlisp,27,
                     list("Cannot shut current input file",car fl1))>>
   end;

deflist ('((in rlis) (out rlis) (shut rlis)),'stat);

flag ('(in out shut),'eval);

flag ('(in out shut),'ignore);

endmodule;


module inter; % Functions for interactive support.

% Author: Anthony C. Hearn.

% Copyright (c) 1993 RAND.  All rights reserved.

fluid '(!*echo !*int);

global '(!$eof!$
         !*lessspace
         cloc!*
         contl!*
         curline!*
         edit!*
         eof!*
         erfg!*
         flg!*
         ifl!*
         ipl!*
         key!*
         ofl!*
         opl!*
         techo!*);

symbolic procedure pause;
   %Must appear at the top-most level;
   if null !*int then nil
    else if key!* eq 'pause then pause1 nil
    else %typerr('pause,"lower level command");
         pause1 nil;   % Allow at lower level for now.

symbolic procedure pause1 bool;
   begin scalar x;
      if bool then
        if getd 'edit1 and erfg!* and cloc!* and yesp "Edit?"
          then return <<contl!* := nil;
           if ofl!* then <<lprim list(car ofl!*,'shut);
                           close cdr ofl!*;
                           opl!* := delete(ofl!*,opl!*);
                           ofl!* := nil>>;
           edit1(cloc!*,nil)>>
         else if flg!* then return (edit!* := nil);
      if null ifl!* or yesp "Cont?" then return nil;
      ifl!* := list(car ifl!*,cadr ifl!*,curline!*);
      if x := assoccar(car ifl!*,contl!*)
        then <<contl!* := delete(x,contl!*); close cadar x>>;
      contl!* := (ifl!* . cdr ipl!* . !*echo) . contl!*;
      ifl!* := ipl!* := nil;
      rds nil;
      !*echo := techo!*
   end;

symbolic procedure assoccar(u,v);
   % Returns element of v in which caar of that element = u.
   if null v then nil
    else if u=caaar v then car v
    else assoccar(u,cdr v);

symbolic procedure yesp u;
   begin scalar ifl,ofl,x,y;
        if ifl!*
          then <<ifl := ifl!* := list(car ifl!*,cadr ifl!*,curline!*);
                 rds nil>>;
        if ofl!* then <<ofl:= ofl!*; wrs nil>>;
        if null !*lessspace then terpri();
        if atom u then prin2 u else lpri u;
        prin2t " (Y or N)";
        if null !*lessspace then terpri();
        y := setpchar '!?;
        x := yesp1();
        setpchar y;
        if ofl then wrs cdr ofl;
        if ifl then rds cadr ifl;
        cursym!* := '!*semicol!*;
        return x
   end;

symbolic procedure yesp1;
   % Basic loop for reading response.
   begin scalar bool,x,y;
    a:  x := rread();
        % Assume an end-of-file is the same as "yes".
        if (y := x eq 'y or x eq !$eof!$) or x eq 'n then return y
         else if null bool then <<prin2t "TYPE Y OR N"; bool := t>>;
        go to a
   end;

symbolic procedure cont;
   begin scalar fl,techo;
        if ifl!* then return nil   % CONT only active from terminal.
         else if null contl!* then rerror(rlisp,28,"No file open");
        fl := caar contl!*;
        ipl!* := fl . cadar contl!*;
        techo := cddar contl!*;
        contl!* := cdr contl!*;
        if car fl=caar ipl!* and cadr fl=cadar ipl!*
          then <<ifl!* := fl;
                 if fl then <<rds cadr fl; curline!* := caddr fl>>
                  else rds nil;
                 !*echo := techo>>
         else <<eof!* := 1; lprim list(fl,"not open"); error1()>>
   end;

deflist ('((cont endstat) (pause endstat) (retry endstat)),'stat);

flag ('(cont),'ignore);

endmodule;


end;
