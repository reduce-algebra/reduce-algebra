module superv; % REDUCE supervisory functions.

% Author: Anthony C. Hearn.

% Modified by: Jed B. Marti, Francis J. Wright.

% Copyright (c) 1998 Anthony C. Hearn.  All rights reserved.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id: $

fluid '(!*debug
        !*defn
        !*demo
        !*echo
        !*errcont
        !*int
        !*lisp!_hook
        !*mode
        !*output
        !*pret
        !*reduce4
        !*slin
        !*time
        !*rlisp88
        ifl!*
        curline!*
        dfprint!*
        peekchar!*
        errmsg!*
        lispsystem!*
        loopdelimslist!*
        lreadfn!*
        newrule!*
        semic!*
        tslin!*
        !*libreduce!_active);

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
         cursym!*
         curescaped!*
         eof!*
         erfg!*
         forkeywords!*
         ipl!*
         initl!*
         inputbuflis!*
         key!*
         ofl!*
         opl!*
         ogctime!*
         otime!*
         ogctime1!*
         otime1!*
         ogctime2!*
         otime2!*
         ogctime3!*
         otime3!*
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

symbolic procedure printprompt u;
   %Prints the prompt expression for input;
   << ofl!* and wrs nil; prin2 u; ofl!* and wrs cdr ofl!* >>;

symbolic procedure setcloc!*;
   % Used to set for file input a global variable CLOC!* to dotted pair
   % of file name and dotted pair of line and page being read.
   % Currently a place holder for system specific function, since not
   % supported in Standard LISP.  CLOC!* is used in the INTER and RCREF
   % modules.
   cloc!* := if null ifl!* then nil else car ifl!* . (1 . curline!*);

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
                while (y := readch() neq !$eol!$ and
                       y neq !$eof!$) do nil;
                rds cadr x;
                crbuf!* := crbuf;
                crbuf1!* := crbuf1;
                crchar!* := crchar;
                ifl!* := ifl;
                !*echo := echo;
          end
       else<<
             % Read command from current input.
          rds cadr x; !*echo := echo; z := command() >>;
       return z
   end;

symbolic procedure command1;
   % Innermost part of COMMAND. Can be used as hook to editor if needed.
   begin
      scan();
      setcloc!*();
      key!* := cursym!*;
      return xread1 nil
   end;

symbolic procedure command;
   begin scalar errmsg!*,loopdelimslist!*,mode,x,y;
      if !*demo and ifl!* then return commdemo()
       else if null !*slin or !*reduce4 then go to a;
      % Note key!* not set in this case.
      setcloc!*();
      y := if lreadfn!* then lispapply(lreadfn!*,nil) else read();
      go to b;
   a: crchar!* := readch1();  % Initialize crchar!*.
      if crchar!* = !$eol!$ then go to a;
      % Parse input.
      y := command1();
   b: if !*reduce4 then go to c
       else if !*struct then y := structchk y;
      if !*pret and (atom y or null (car y memq '(in out shut)))
        then if null y and cursym!* = 'end then rprint 'end
              else << rprint y; terpri() >>;
      if !*slin then return list('symbolic,y);
      x := form y;
      % Determine target mode.
      if flagp(key!*,'modefn) then mode := key!*
       else if null atom x % and null !*micro!-version
         and null(car x = 'quote)
         and (null(idp car x
                 and (flagp(car x,'nochange)
                       or flagp(car x,'intfn)
                       or car x = 'list))
           or car x memq '(setq setel setf)
                   and eqcar(caddr x,'quote))
        then mode := 'symbolic
       else mode := !*mode;
      return list(mode,convertmode1(x,nil,'symbolic,mode));
   c: if !*debug then << prin2 "Parse: "; prettyprint y >>;
    % Mode analyze input.
      if key!* = '!*semicol!* then go to a;  % Should be a comment.
      if null !*reduce4 then y := form y else y := n!_form y;
%     y := n!_form y;
      if !*debug then << terpri(); prin2 "Form: "; prettyprint y >>;
      return y
   end;

symbolic procedure update!_prompt;
   begin
      statcounter := statcounter + 1;
      promptexp!* :=
         intern list2string append(explode statcounter,
                     if null symchar!* or !*mode = 'algebraic
                     then '(!: ! ) else '(!* ! ));
      setpchar promptexp!*
   end;

symbolic procedure begin1;
   begin1a nil;

% In the code here is the variable now called !~x!~ was just called x
% then there could be a conflict between the binding here and use of x
% as a top-level variable in symbolic mode code in the case where all
% of Reduce is interpreted and where "local" variables are in fact implemented
% using shallow binding and hence behave rather like fluids. In such a
% situation the input
%     symbolic; x := 5; list(x, x);
% used to return an unexpected ((list x x) (list x x)) rather than (5 5).
% I have renamed the delicate variables as (eg) !~x!~ believing that altough
% casual users might well use x as a variable name few will use that.
% Variables such as errmsg!* already have "unusual" names to reduce the
% chances of conflict. The changes here do not provider a technical resolution
% of the underlying issue, but probably make it a lot less liable to bite in
% the real world.

% Before trying to obey any Reduce statements you must call this. For all
% normal use the argument should be NIL. The "prefixchars" stuff is to do
% with reading in Reduce scripts interleaved with TeX using "in_tex".

global '(otime!-set!*);
otime!-set!* := nil;

symbolic procedure prepare!-for!-top!-loop !~prefixchars!~;
   begin
      verbos nil;
      if not otime!-set!* then <<
         otime!* := time();
% The next line is that way for bootstrapping purposes.
         if getd 'gctime then ogctime!* := gctime() else ogctime!* := 0;
         otime1!* := otime2!* := otime3!* := otime!*;
         ogctime1!* := ogctime2!* := ogctime3!* := ogctime!*;
         otime!-set!* := t >>;
      peekchar!* := !~prefixchars!~;
      cursym!* := '!*semicol!*;
      curescaped!* := nil;
   end;

fluid '(!*nat);

symbolic procedure prepare!-for!-web!-top!-level !~prefixchars!~;
   begin
      verbos nil;
      if not otime!-set!* then <<
         otime!* := time();
% The next line is that way for bootstrapping purposes.
         if getd 'gctime then ogctime!* := gctime() else ogctime!* := 0;
         otime1!* := otime2!* := otime3!* := otime!*;
         ogctime1!* := ogctime2!* := ogctime3!* := ogctime!*;
         otime!-set!* := t >>;
      peekchar!* := !~prefixchars!~;
      cursym!* := '!*semicol!*;
      curescaped!* := nil;
% The next three lines are the "web top level" speciality.
      !*echo := nil;
      !*nat := nil;
      !*mode := 'algebraic;
   end;

% This should read one Reduce statement and evaluate or obey what it finds.
% It returns nil in "ordinary" cases and a non-nil value if the case
% that Reduce wishes to quit from its read-eval-print loop. 

symbolic procedure process!-one!-reduce!-statement();
   begin scalar !~parserr!~,!~result!~,!~x!~;
      if terminalp()
        then <<(if !*nosave!* or statcounter=0 then nil
                     else add2buflis());
                   update!_prompt()>> ;
      !*nosave!* := nil;
      !*strind := 0;     % Used by some versions of input editor.
      !~parserr!~ := nil;
      if !*time then lispeval '(showtime nil);   % Since a STAT.
      if !*output and null ofl!* and terminalp() and null !*defn
         and null !*lessspace
        then terpri();
      if tslin!*
        then << !*slin := car tslin!*;
                lreadfn!* := cdr tslin!*;
                tslin!* := nil >>;
      !~x!~ := initl!*;
 b:   if !~x!~ then << sinitl car !~x!~; !~x!~ := cdr !~x!~; go to b >>;
      remflag(forkeywords!*,'delim);
      remflag(repeatkeywords!*,'delim);
      remflag( whilekeywords!*,'delim);
      if !*int then erfg!* := nil;   % To make editing work properly.
      if cursym!* = 'end then << comm1 'end; return '(nil) >>
       % Note that key* was set from *previous* command in following.
       else if terminalp() and null(key!* = 'ed)
        then printprompt promptexp!*;
      !~x!~ := errorset!*('(command),t);
      condterpri();
      if errorp !~x!~ then go to err1;
      !~x!~ := car !~x!~;
      if car !~x!~ = 'symbolic and eqcar(cadr !~x!~,'xmodule)
        then !~result!~ := xmodloop eval cadr !~x!~
       else !~result!~ := begin11 !~x!~;
      if null !~result!~ then return nil
       else if !~result!~ = 'end then return '(nil)
       else if !~result!~ = 'err2 then go to err2
       else if !~result!~ = 'err3 then go to err3;
  c:  if crbuf1!* then <<
         lprim "Closing object improperly removed. Redo edit.";
         crbuf1!* := nil;
         return '(nil) >>
        else if eof!*>4
         then << lprim "End-of-file read"; return list lispeval '(bye) >>
       else if terminalp()
        then << crbuf!* := nil; !*nosave!* := t; return nil >>
       else return '(nil);
  err1:
      if eofcheck() or eof!*>0 then go to c
       else if !~x!~="BEGIN invalid" then return nil;
      !~parserr!~ := t;
  err2:
      resetparser();  % In case parser needs to be modified.
  err3:
      erfg!* := t;
      if null !*int and null !*errcont
        then << !*defn := t;
                   !*echo := t;
                   (if null cmsg!*
                      then lprie "Continuing with parsing only ...");
                   cmsg!* := t >>
       else if null !*errcont
        then << !~result!~ := pause1 !~parserr!~;
                   (if !~result!~ then return lisp null lispeval !~result!~);
                   erfg!* := nil >>
       else erfg!* := nil;
      return nil
   end;

symbolic procedure begin1a !~prefixchars!~;
   begin scalar w;
      prepare!-for!-top!-loop !~prefixchars!~;
  a:  w := process!-one!-reduce!-statement();
      if atom w then go to a
      else return car w;
   end;

% Newrule!* is initialized in the following function, since it is not
% always reinitialized by the rule code.

fluid '(ulimit!* trap!-time!*);
ulimit!* := nil;

symbolic procedure begin11 !~x!~;
   begin scalar errmsg!*,!~mode!~,!~result!~,newrule!*;
      if cursym!* = 'end
         then if terminalp() and null !*lisp!_hook
                then << cursym!* := '!*semicol!*;
                           curescaped!* := nil;
                           !*nosave!* := t;
                           return nil >>
               else << comm1 'end; return 'end >>
       else if eqcar((if !*reduce4 then !~x!~ else cadr !~x!~),'retry)
        then if programl!* then !~x!~ := programl!*
              else << lprim "No previous expression"; return nil >>;
      if null !*reduce4 then << !~mode!~ := car !~x!~; !~x!~ := cadr !~x!~ >>;
      program!* := !~x!~;    % Keep it around for debugging purposes.
      if eofcheck() then return 'c else eof!* := 0;
      add2inputbuf(!~x!~,if !*reduce4 then nil else !~mode!~);
      if null atom !~x!~
          and car !~x!~ memq '(bye quit)
        then if getd 'bye
               then << lispeval !~x!~; !*nosave!* := t; return nil >>
              else << !*byeflag!* := t; return nil >>
       else if null !*reduce4 and eqcar(!~x!~,'ed)
        then <<(if getd 'cedit and terminalp()
                      then cedit cdr !~x!~
                     else lprim "ED not supported");
                   !*nosave!* := t;
                    return nil >>
       else if !*defn
        then if erfg!* then return nil
              else if null flagp(key!*,'ignore)
                and null eqcar(!~x!~,'quote)
               then << (if !~x!~ then dfprint !~x!~ else nil);
                          if null flagp(key!*,'eval) then return nil >>;
      if !*output and ifl!* and !*echo and null !*lessspace
        then terpri();
% If the (Lisp) variable ulimit!* is set to an integer value than that
% represents a resource limit measured in milliseconds of CPU time to
% be allowed for any step of a calculation. This time is not measured
% precisely - what happens is that a timeout is checked for each time
% there is a garbage collection. However because of bootstrapping I do not
% yet have the macro "with-timeout" and so I need to use a forward
% reference to an ordinary function.
      if fixp ulimit!* then <<
        !~result!~ := errorset!_with!_timeout(ulimit!*, !~x!~);
        if not atom !~result!~ then !~result!~ := car !~result!~ >>
      else !~result!~ := errorset!*(!~x!~,t);
      if errorp !~result!~ or erfg!*
        then << programl!* := list(!~mode!~,!~x!~); return 'err2 >>
       else if !*defn then return nil;
      if null !*reduce4
        then if null(!~mode!~ = 'symbolic) then !~x!~ := getsetvars !~x!~ else nil
       else << !~result!~ := car !~result!~;
                  (if null !~result!~ then !~result!~ := mkobject(nil,'noval));
                  !~mode!~ := type !~result!~;
                  !~result!~ := value !~result!~ >>;
      add2resultbuf((if null !*reduce4 then car !~result!~ else !~result!~),
                    !~mode!~);
      if null !*output then return nil
       else if null(semic!* = '!$)
        then if !*reduce4 then (begin
                   terpri();
                   if !~mode!~ = 'noval then return nil
                    else if !*debug then prin2t "Value:";
                   rapply1('print,list list(!~mode!~,!~result!~))
                 end)
       else if !~mode!~ = 'symbolic
              then if null car !~result!~ and null(!*mode = 'symbolic)
                     then nil
              else begin
                  terpri();
                  !~result!~:=
                       errorset!*(list('print,mkquote car !~result!~),t)
                    end
       else if car !~result!~
        then !~result!~ := errorset!*(list('assgnpri,mkquote car !~result!~,
                                       (if !~x!~ then 'list . !~x!~ else nil),
                                       mkquote 'only),
                                  t);
      if null !*reduce4
        then return if errorp !~result!~ then 'err3 else nil
       else if null(!*mode = 'noval) % and !*debug
        then << terpri(); prin2 "of type: "; print !~mode!~ >>;
      return nil
   end;

symbolic procedure getsetvarlis u;
   if null u then nil
    else if atom u then errach list("getsetvarlis",u)
    else if atom car u then car u . getsetvarlis cdr u
    else if caar u memq '(setel setk)   % setk0.
     then getsetvarlis cadar u . getsetvarlis cdr u
    else if caar u = 'setq then mkquote cadar u . getsetvarlis cdr u
    else car u . getsetvarlis cdr u;

symbolic procedure getsetvars u;
   if atom u then nil
    else if car u memq '(setel setk)   % setk0.
     then getsetvarlis cadr u . getsetvars caddr u
    else if car u = 'setq then mkquote cadr u . getsetvars caddr u
    else nil;

flag ('(deflist flag fluid global remflag remprop unfluid),'eval);

symbolic procedure close!-input!-files;
   % Close all input files currently open;
   begin
      if ifl!* then << rds nil; ifl!* := nil >>;
      while ipl!* do <<
         close cadar ipl!*;
         ipl!* := cdr ipl!* >>;
   end;

symbolic procedure close!-output!-files;
   % Close all output files currently open;
   begin
      if ofl!* then << wrs nil; ofl!* := nil >>;
      while opl!* do <<
         close cdar opl!*;
         opl!* := cdr opl!* >>;
   end;

symbolic procedure add2buflis;
   begin
      if null crbuf!* then return nil;
      crbuf!* := reversip crbuf!*;   %put in right order;
      while crbuf!* and seprp car crbuf!* do crbuf!* := cdr crbuf!*;
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
% The extra treatment here when libreduce is in use is included in this
% main definition of add2resultbuf so that at the cost of a small extra test
% here there will not be a need for copying and replacing the main definition.
% Note that functions like lr_results etc are ones in the libreduce package.
      if !*libreduce!_active then <<
         lr!_result();
         if null(semic!* = '!$) then lr!_printer(u,mode);
         lr!_statcounter();
         prin2 statcounter;
         lr!_mode();
         prin2 (if !*mode = 'symbolic then 1 else 0);
         lr!_posttext();
         terpri() >>;
      if mode = 'symbolic
       or (null u and (null !*reduce4 or null(mode = 'empty!_list)))
       or !*nosave!* then return nil;
      if !*reduce4 then putobject('ws,u,mode) else ws := u;
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
   % Looks for special action on a form, otherwise prettyprints it.
   if dfprint!* then lispapply(dfprint!*,list u)
    else if cmsg!* then nil
    else if null eqcar(u,'progn) then prettyprint u
    else while (u := cdr u) do dfprint car u;


symbolic procedure showtime optarg;
   begin scalar x,y;
      x := otime!*;
      otime!* := time();
      x := otime!* - x;
      y := ogctime!*;
      ogctime!* := gctime();
      y := ogctime!* - y;
      if 'psl memq lispsystem!* then x := x - y;
      terpri();
      if optarg then prin2 optarg;
      prin2 "Time: "; prin2 x; prin2 " ms";
      if null(y=0)
        then << prin2 "  plus GC time: "; prin2 y; prin2 " ms" >>;
      terpri();
      return if !*reduce4 then mknovalobj() else nil
   end;

% OK so what is this all about...
% Well for benchmarking I would like to record the time spent in
% a test script. However some test scripts use "showtime" and that
% then interferes. So I introduce a variant on showtime specifically
% for my use that does just the same but that will be independent of
% the original version. I call this "showtime1". And then in a spirit
% of future-proofing I provide two further versions for other people
% to use too. So
%   showtime1;
%   showtime;
%   part A
%   showtime;    % time just for part A
%   part B
%   showtime;    % time just for part B
%   showtime1;   % total time.
% Because the counters used differ (obviously) I found this easiest to
% do my replicating code rather than having a single parameterised
% function.

symbolic procedure showtime1 optarg;
   begin scalar x,y;
      x := otime1!*;
      otime1!* := time();
      x := otime1!* - x;
      y := ogctime1!*;
      ogctime1!* := gctime();
      y := ogctime1!* - y;
      if 'psl memq lispsystem!* then x := x - y;
      terpri();
      if optarg then prin2 optarg;
      prin2 "Time (counter 1): "; prin2 x; prin2 " ms";
      if null(y=0)
        then << prin2 "  plus GC time: "; prin2 y; prin2 " ms" >>;
      terpri();
      return if !*reduce4 then mknovalobj() else nil
   end;

symbolic procedure showtime2 optarg;
   begin scalar x,y;
      x := otime2!*;
      otime2!* := time();
      x := otime2!* - x;
      y := ogctime2!*;
      ogctime2!* := gctime();
      y := ogctime2!* - y;
      if 'psl memq lispsystem!* then x := x - y;
      terpri();
      if optarg then prin2 optarg;
      prin2 "Time (counter 2): "; prin2 x; prin2 " ms";
      if null(y=0)
        then << prin2 "  plus GC time: "; prin2 y; prin2 " ms" >>;
      terpri();
      return if !*reduce4 then mknovalobj() else nil
   end;

symbolic procedure showtime3 optarg;
   begin scalar x,y;
      x := otime3!*;
      otime3!* := time();
      x := otime3!* - x;
      y := ogctime3!*;
      ogctime3!* := gctime();
      y := ogctime3!* - y;
      if 'psl memq lispsystem!* then x := x - y;
      terpri();
      if optarg then prin2 optarg;
      prin2 "Time (counter 3): "; prin2 x; prin2 " ms";
      if null(y=0)
        then << prin2 "  plus GC time: "; prin2 y; prin2 " ms" >>;
      terpri();
      return if !*reduce4 then mknovalobj() else nil
   end;

symbolic procedure resettime;
  << otime!* := time();
     ogctime!* := gctime();
     if !*reduce4 then mknovalobj() else nil >>;

symbolic procedure resettime1;
  << otime1!* := time();
     ogctime1!* := gctime();
     if !*reduce4 then mknovalobj() else nil >>;

symbolic procedure resettime2;
  << otime2!* := time();
     ogctime2!* := gctime();
     if !*reduce4 then mknovalobj() else nil >>;

symbolic procedure resettime3;
  << otime3!* := time();
     ogctime3!* := gctime();
     if !*reduce4 then mknovalobj() else nil >>;


symbolic procedure sinitl u;
   set(u, eval get(u, 'initl));

% Beware - at least under PSL at this stage if you use "_" within a name
% you need to escape it.

symbolic procedure getenv!_if!_not!_empty name;
  begin
    name := getenv name;
    if name = "" then name := nil;
    return name
  end;

symbolic procedure read!-init!-file name;
  % Read a resource file in REDUCE syntax. Quiet input.
  % Algebraic mode is used unless rlisp88 is on.
  % Look for file in home directory. If no home directory
  % is defined, use the current directory.
  begin scalar !*errcont,!*int,base,fname,oldmode,x,y;
   base := getenv!_if!_not!_empty "HOME" or
%          getenv!_if!_not!_empty "home" or
           ((x := getenv "HOMEDRIVE") and
             (y := getenv "HOMEPATH") and
             concat2(x,y)) or
           ".";
% PSL does not have LAST defined at this stage, so I use "car reversip"
% on the list that was newly created by explode2...
   if base neq "" and car reversip explode2 base neq '!/ then
     base := concat2(base,"/");
   fname := if filep(x := concat2(base,concat2(".", % FJW
                                                concat2(name,"rc"))))
               then x
             else if filep(x := concat2(base,concat2(name,".rc"))) % FJW
              then x
             else if filep
                     (x := concat2(base,concat2(name,".INI")))
               then x; % for (Open) VMS
   if null fname then return nil
    else if !*mode neq 'algebraic and null !*rlisp88
     then << oldmode := !*mode; !*mode := 'algebraic >>;
   x := errorset(list('in!_list1,fname,nil),nil,nil);
   if errorp x or erfg!* then <<
      terpri();
      prin2 "***** Error processing resource file ";
      prin2t fname >>;
   close!-input!-files();
   erfg!*:= cmsg!* := !*defn := crbuf!* := nil;
   if oldmode then !*mode := oldmode;
   terpri();
   statcounter := 0
  end;

endmodule;

end;
