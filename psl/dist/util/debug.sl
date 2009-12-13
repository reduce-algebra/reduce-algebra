%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:DEBUG.SL 
% Description:  General tracing capabilities 
% Author:       A. C. Norman, D. Morrison and B. Othmer 
% Created:      A long time ago 
% Modified:     18 Jun 1984 1035-PDT (Brian Beach) 
% Package:      Utilities 
%
% (c) Copyright 1982, University of Utah
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 21-Jun-94 (Herbert Melenk)
%  Use trprinter* to report the result during "Break after call
% 10-Feb-92 (Winfried Neun)
%  Allow multiple setq (like in easy-sl.sl under trst
%  Changed printing routines such that they are (hopefully) more robust
%  in case of recursion caused by printing.
% 26-May-87 (Harold Carr & Leigh Stoller)
%  Changed declaration of *comp from global to fluid to avoid error message
%   at load time.
% 06-Apr-87 (Julian Padget)
%  Rewrote the loadtime code which fixes LOAD1 so that it does not
%   try to bind global variables.
% 26-Mar-87 (Tony Hearn)
%  Added a switch *fulltrace that inhibits the node renaming mechanism
% 31-Jul-84 17:22:26 (Cris Perdue)
%  In -tracedcall fixed (car -brinstack) to check for pairp
%  first so HP-UX won't break.
% 14 Jun 1984 0407-PDT (M. L. Griss, on DEC-20)
%  Wrapped DEFINEROP calls in EVALs so FEXPRs etc will compile correctly
% 14 Jun 1984 0400-PDT (M. L. Griss, on DEC-20)
%  Corrected Author names, and copyright
% 23 Feb 1984 1532-PST (Cris Perdue)
%  Changed "flatten" to "-flatten", conflicted with name of
%  (similar) function in pu:destructure.sl.
%  <PSL.UTIL>DEBUG.RED, 2-Mar-84 10:30:42, Edit by OTHMER
%  Fixed some bugs in -Findentries and -Printpass so that
%  Printx will work when PrinLength is non NIL.
%  <PSL.NEW>DEBUG.RED, 11-Oct-83 15:14:10, Edit by OTHMER
%  Fixed PrintX so that it would check PrinLevel and PrinLength
%  when scanning the argument as well as printing it.  Also
%  wasn't printing '(a . b) correctly.
%  Fixed --Putd so that functions don't lose the USER flag
%  when they are redefined by debug.
%  Fixed Redefined-Putd so that one can decide not to redefine
%  system functions that have been traced, and get the previous
%  definition and properties back.
%  <PSL.NEW>DEBUG.RED, 7-Oct-83 11:16:46, Edit by OTHMER
%  Put a conditional around the definition of -Putd so that
%  one does not get an infinite loop when reloading debug.
%  <PSL.UTIL>DEBUG.RED.20, 21-Jun-83 11:20:12, Edit by OTHMER
%  Made PrintX check the globals prinlength and prinlevel
%  Added macro TRWHEN that checks a predicate before tracing
%  Added macro TRSTSOME that prints values of only specified
%    variables as they are assigned
%  Added Break package including BR, UNBR, BRIN, BRWHEN,
%    *BREAKALL
%  Redefine LOAD1 so that functions in load modules are not
%    traced, broken, or installed under the influence of
%    *TRACEALL, *BREAKALL, or *INSTALL
%  Added global *PRINTNOARGS to control printing of
%    arguments during tracing and breaking
%  Made more robust.  Functions on BREAKDEBUGLIST* cause 
%    debug package to break.  Any debug actions on these
%    functions are trapped.
%  Removed outdated code.
%  <PSL.UTIL>DEBUG.RED.21,  4-Feb-83 13:01:05, Edit by OTHMER
%  Added Br - UnBr from Mini-Trace.Red
%  Added functions UnBrAll, UnTrAll
%  Added globals TracedFns*, BrokenFns*
%  Changed Restr to be a macro that can take a list of file names
%  as argument
%  Removed many lines of code that had been commented out
%  <PSL.UTIL>DEBUG.RED.20,  3-Feb-83 11:00:06, Edit by KESSLER
%  Remove fluid defintion of *mode
%  Edit by Griss, 25 January 1983, fix *MODE and DEFINEROP
%  for REDUCE
%  <PSL.NEW>DEBUG.RED.2, 29-Dec-82 15:28:13, Edit by PERDUE
%  In the fix of 12-december, changed > to -greaterp
%  Also added a << >> pair to -findentries
%  <PSL.UTIL>DEBUG.RED.16, 28-Dec-82 13:50:19, Edit by PERDUE
%  Added -TRSTCOND to handle COND correctly
%  <PSL.UTIL>DEBUG.RED,  12-Dec-82 15:59:45, Edit by GRISS
%    Fixed printx to handle 0 SIZE (i.e. one-element) vectors

%   The debug package works on the principle of embedding the
% definition (or code-pointer) of the function whose behavior is
% to be examined within another definition.  The new definition
% includes a call to the debug function -TRACEDCALL which
% performs the specified debug activities and executes the
% original function.  Information about which debug activities
% are desired is kept on the property list of the function on a
% sub-property-list whose indicator is TRACE.  There are
% functions in the debug package for accessing this
% sub-property-list.
%   Any function for which debug activities have been requested
% is "installed", (i.e., its definition is embedded in a new
% definition), by the debug function -TRINSTALL.  Other
% activities are indicated by the TRACE sub-property-list.
% These activities can be turned off without having the
% original function definition restored because only properties
% on TRACE are involved.  One has to call the function RESTR to
% restore the original definition.

(compiletime (flag '(-lprie -lprim 
		   -pad -idlistp -cirlist -firstn -listofatoms --putd 
		   -labelname -findentries -printpass -prins 
		   -trget -trgetx -trflagp -trput -trputx -trputx1 
		   -trflag -trflag1 -trremprop -trrempropx 
		   -trremflag -trremflag1 
		   -trinstall -argnames 
		   -trrestore -outrace1 -dumptracebuff 
		   -errapply 
		   -enterpri -exitpri -trindent -tracepri1 
		   -tracentrypri1 -tracexpandpri 
		   -mktrst -mktrst1 
		   -btrpush -btrpop -btrdump 
		   -embsubst 
		   -tr1 -mkstub 
		   -plist1 -ppf1 -getc -flatten) 
		 'internalfunction))


(fluid '(ignoredinbacktrace* errorform* *continuableerror))

(setq ignoredinbacktrace* (append '(-tracedcall -apply -get) 
			       ignoredinbacktrace*))


%******************************************************************

% I systematically use names starting with a '-' within this
% package for internal routines that must not interfere with the
% user. This means that the debug package may behave incorrectly
% if user functions or variables have names starting with a '-';

%******************** Globals declarations ************************

(global 
% Boolean valued flags
  '(*breakall            % T -> break all functions defined with PutD
  *btr                   % T -> stack traced function calls for backtrace
  *btrsave               % T -> bactrace things which fail in errorsets
  *install               % T -> "install" trace info on all PUTD'd functions
  *printnoargs           % T -> arguments for functions being
			 % traced or broken are not printed
  *savenames             % controlls saving of substructure names in PRINTX
  *trace                 % T -> print trace information at run time
  *traceall              % T -> trace all functions defined with PUTD
  *trstexpandmacros      % T -> expand macros before embedding SETQs to print
  *trunknown             % T -> never ask for the number of args
  *trcount               % T -> count # of invocations of traced functions
% Other globals intended to be accessed outside of DEBUG
  breakdebuglist*        % List of functions that cause debug to break
  brokenfns*             % List of functions that have been broken
  tracedfns*             % List of functions that have been traced
  emsg*                  %
  erfg*                  % Reduce flag
  msgchnl*               % Channel to output trace information
  ppfprinter*            % Used by PPF to print function bodies 
  propertyprinter*       % Used by PLIST to print property values
  putdhook*              % User hook run after a successful PUTD
  stubprinter*           % For printing arguments in calls on stubs
  stubreader*            % For reading the return value in calls on stubs
  traceminlevel*         % Minimum recursive depth at which to trace
  tracemaxlevel*         % Maximum     "       "   "	"   "	 "
  tracentryhook*         % User hook into traced functions
  tracexithook*          %  "	 "    "     "	     "
  tracexpandhook*        %  "	 "    "     "	     "
  trexprinter*           % Function used to print args/values in traced fns
  trinstallhook*         % User hook called when a function is first traced
  trprinter*             % Function used to print macro expansions
% Globals principally for internal use
  -arbargnames*          % List of ids to be used for unspecified names
  -argindent*            % Number of spaces to indent when printing args
  -brinflag              % T -> BRIN has been called on some functions
  -brinfunctions         % List of functions in which breaking of
			 % functions occurs
  -brinstack             % Stack for calls of functions BRIN'ed
  -btrsavedintervals*    % Saved BTR frames from within errorsets
  -btrstk*               % Stack for bactrace info
  -functionflags*        % Flags which PPF considers printing
  -globalnames*          % Used by PRINTX to store common substructure names
  -indentcutoff*         % Furthest right to indent trace output
  -indentdepth*          % Number of spaces to indent each level trace output
  -invisibleprops*       % Properties which PLIST should ignore
  -invisibleflags*       % Flags which PLIST should ignore
  -installedfns*         % Functions which have had information installed
  -nonstandardfns*       % Properties under which special MACRO's are stored
  -tracebuff*            % Ringbuffer to save recent trace output
  -tracecount*           % Decremented -- if >0 it may suppresses tracing
  -traceflag*))          % Enables tracing
	

(fluid 
  '(*backtrace           % Reduce flag
  *defn                  % Reduce flag
  *msg
  *fulltrace             % on, inhibits node naming
  *usermode 
  prinlevel 
  prinlength 
  *-restrictsetq         % T -> trst on only some variables in a function
  -entrypoints*          % for PRINTX
  -levelnumber*          % Used by Printx to keep track of levels of object printed
  -originalfn*           % fluid argument in EMBed function calls
  -printxcount*          % Used by PRINTX for making up names for EQ structures
  -setqvars*             % Used by trst to list variables to be traced
  -trindent*             % Current level of indentation of trace output
  -visited*))            % for PRINTX
	
(global
  '(*comp))               % Standard Lisp flag

(setq *btr t)
(setq *btrsave t)
(setq *trace t)
(setq *trcount t)
(setq *trstexpandmacros t)
(setq -arbargnames* '(a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13 a14 a15))
(setq -argindent* 3)
(setq breakdebuglist* '(list eval cons prop funboundp memq))
(setq -functionflags* '(eval ignore lose nochange expand noexpand opfn direct))
(setq -indentcutoff* 12)
(setq -indentdepth* 2)
(setq -invisibleprops* '(type *lambdalink))
(setq -nonstandardfns* '(smacro nmacro cmacro))
(setq -tracecount* 0)
(setq -trindent* -1)                   % It's always incremented BEFORE use
(setq -traceflag* t)
(setq *msg t)
(setq ppfprinter* (cond ((getd 'rprint) 'rprint) (t 'prettyprint)))
(setq propertyprinter* (cond ((getd 'prettyprint) 'prettyprint) (t 'print)))
(setq stubprinter* 'printx)
(setq stubreader* (cond ((getd 'xread) '-redreader) (t '-read)))
(setq tracemaxlevel* 10000)             % Essentially no limit
(setq traceminlevel* 0)
(setq trexprinter* (cond ((getd 'rprint) 'rprint) (t 'prettyprint)))
(setq trprinter* 'printx)
(setq brokenfns* nil)
(setq tracedfns* nil)

%JAP: The original brain-damaged code was:
%(cond ((null (getd 'pre-debug-load1)) 
%   (progn (copyd 'pre-debug-load1 'load1) 
%     (putd 'load1 'expr '(lambda (x) 
%             (prog (*traceall *breakall *install) 
%              (pre-debug-load1 x)))))))
%JAP: but *traceall *breakall and *install are globals and should not
%JAP: be bound.
(cond
  ((null (getd 'pre-debug-load1))
   (copyd 'pre-debug-load1 'load1)
   (putd 'load1 'expr '(lambda (x)
    ((lambda (save*traceall save*breakall save*install)
       (setq *traceall nil)
       (setq *breakall nil)
       (setq *install nil)
       (unwind-protect
         (pre-debug-load1 x)
         (progn
           (setq *traceall save*traceall)
	   (setq *breakall save*breakall)
	   (setq *install save*install))))
      *traceall *breakall *install)))))

% Let TRST know about the behaviour of some common FEXPRs

(flag                                   % common FEXPRs which never pass back an unEVALed argument
  '(and 
  list 
  max 
  min 
  or 
  plus 
  progn 
  repeat 
  times 
  while) 
     'trstinside)

(deflist                                % special sorts of FEXPRs
  '((lambda -trstprog)                 % Not really a function, but handled by TRST as such
  (prog -trstprog) 
  (setq -trstsetq) 
  (cond -trstcond)) 
	 'trstinsidefn)

%****************** Utility functions ********************************


% Copy the entrypoints of various key functions so that
% nobody gets muddled by trying to trace or redefine them;

(putd '-append 'expr (cdr (getd 'append)))
(putd '-apply 'expr (cdr (getd 'apply)))
(putd '-atsoc 'expr (cdr (getd 'atsoc)))
(putd '-compress 'expr (cdr (getd 'compress)))
(putd '-equal 'expr (cdr (getd 'equal)))
(putd '-errorset 'expr (cdr (getd 'errorset)))
(putd '-eval 'expr (cdr (getd 'eval)))
(putd '-explode 'expr (cdr (getd 'explode)))
(putd '-flag 'expr (cdr (getd 'flag)))
(putd '-flagp 'expr (cdr (getd 'flagp)))
(putd '-fluid 'expr (cdr (getd 'fluid)))
(putd '-get 'expr (cdr (getd 'get)))
(putd '-getd 'expr (cdr (getd 'getd)))
(putd '-intern 'expr (cdr (getd 'intern)))
(putd '-length 'expr (cdr (getd 'length)))
(putd '-max2 'expr (cdr (getd 'max2)))
(putd '-memq 'expr (cdr (getd 'memq)))
(putd '-min2 'expr (cdr (getd 'min2)))
(putd '-open 'expr (cdr (getd 'open)))
(putd '-plus2 'expr (cdr (getd 'plus2)))
(putd '-posn 'expr (cdr (getd 'posn)))
(putd '-prin1 'expr (cdr (getd 'prin1)))
(putd '-prin2 'expr (cdr (getd 'prin2)))
(putd '-princ 'expr (cdr (getd 'princ)))
(putd '-print 'expr (cdr (getd 'print)))
(putd '-prop 'expr (cdr (getd 'prop)))
(putd '-put 'expr (cdr (getd 'put)))
(cond ((null (getd '-putd)) 
(putd '-putd 'expr (cdr (getd 'putd)))))
(putd '-read 'expr (cdr (getd 'read)))
(putd '-remd 'expr (cdr (getd 'remd)))
(putd '-remprop 'expr (cdr (getd 'remprop)))
(putd '-reverse 'expr (cdr (getd 'reverse)))
(putd '-set 'expr (cdr (getd 'set)))
(putd '-terpri 'expr (cdr (getd 'terpri)))
(putd '-wrs 'expr (cdr (getd 'wrs)))


(compiletime (progn 

(ds alias (x y) 
    (dm x (u) (cons 'y (cdr u)))) 

(alias -difference idifference) 
(alias -greaterp igreaterp) 
(alias -lessp ilessp) 
(alias -sub1 isub1) 
(alias -times2 itimes2) 

(load fast-vector) 
(alias -getv igetv) 
(alias -upbv isizev) 

%alias(-ADD1, IAdd1);
(put '-add1 'cmacro '(lambda (x) (iadd1 x))) nil))


(de -add1 (x)                          % because it gets called from EVAL
    (iadd1 x))

(de -lprie (u) 
(progn (errorprintf "***** %L" u) 
    (setq erfg* t)))

(de -lprim (u) 
    (and *msg (errorprintf "*** %L" u)))


(putd '-reversip 'expr (cdr (getd 'reversip)))
(putd '-mkquote 'expr (cdr (getd 'mkquote)))
(putd '-eqcar 'expr (cdr (getd 'eqcar)))
(putd '-spaces 'expr (cdr (getd 'spaces)))
(putd '-spaces2 'expr (cdr (getd 'spaces2)))
(putd '-prin2t 'expr (cdr (getd 'prin2t)))

(de -pad (l n) 
% Used by stubs
(cond ((fixp n) 
   (cond ((lessp n (-length l)) 
      (-pad (-reversip (cdr (-reverse l))) n)) 
   ((greaterp n (-length l)) 
      (-pad (-append l (list nil)) n)) (t 
   
      l))) (t 

   (rederr "-PAD given nonintegral second arg"))))

(de -idlistp (l) 
% Used by stubs
(or (null l) (and (idp (car l)) (-idlistp (cdr l)))))

(de -cirlist (u n) 
% Returns a circular list consisting of N U's.
% Called by NEWTRBUFF
(prog (a b) 
  (cond ((not (-greaterp n 0)) 
    (return nil))) 
  (setq b (setq a (cons u nil))) 
  (for (from i 2 n 1) (do 
    (setq b (cons u b)))) 
  (return (rplacd a b))))


(de -firstn (n l) 
% Called by -ARGNAMES and -ARGNAMES1
    (cond ((equal n 0) nil) 
    ((null l) (-firstn n (list (gensym)))) (t 
    (cons (car l) (-firstn (-difference n 1) (cdr l))))))

(de -listofatoms (l) 
% Called by -ARGNAMES1
    (cond ((null l) t) 
    ((idp (car l)) (-listofatoms (cdr l))) (t nil)))
    

(de --putd (name type body) 
% as PUTD but never compiles, and preserves TRACE property;
% Called by -TRINSTALL when redefining functions for trace activities
  (prog 
    (comp saver bol save*usermode save*redefmsg saveuserflag) 
    (setq comp *comp)                   % REMEMBER STATE OF *COMP FLAG;
    (setq *comp nil)                    % TURN OFF COMPILATION;
    (setq saver (-get name 'trace)) 
    (setq bol (flagp name 'lose)) 
    (remflag (list name) 'lose)         % IGNORE LOSE FLAG;
    % Turning off usermode and redefmsg make the redefinition quiet
    (setq saveuserflag (flagp name 'user)) 
    (setq save*usermode *usermode) 
    (off usermode) 
    (setq save*redefmsg *redefmsg) 
    (off redefmsg) 
    (setq body (-putd name type body)) 
    (cond (saveuserflag (flag (list name) 'user))) 
    (setq *usermode save*usermode) 
    (setq *redefmsg save*redefmsg) 
    (cond ((not (null saver)) (-put name 'trace saver))) 
    (setq *comp comp)                   % RESTORE COMPILATION FLAG;
    (cond (bol (flag (list name) 'lose))) 
    (return body)))
  


%******* Routines for printing looped and shared structures ******
%
% MAIN ENTRYPOINT:
%
%    PRINTX (A)
%
% -PRINTS THE LIST A. IF *SAVENAMES IS TRUE CYCLES ARE PRESERVED
% BETWEEN CALLS TO -PRINTS;
% PRINTX RETURNS NIL;
% PRINTX checks the globals PRINLENGTH and PRINLEVEL so one can
% control the number of items and the number of levels of an
% object printed.

%VARIABLES USED -
%
% -ENTRYPOINTS*   ASSOCIATION LIST OF POINTS WHERE THE LIST
%		RE-ENTERS ITSELF. VALUE PART OF A-LIST ENTRY
%		IS NIL IF NODE HAS NOT YET BEEN GIVEN A NAME,
%		OTHERWISE IT IS THE NAME USED.
%
% -VISITED*	    LIST OF NODES THAT HAVE BEEN ENCOUNTERED DURING
%		CURRENT SCAN OF LIST
%
% -GLOBALNAMES*   LIKE -ENTRYPOINTS*, BUT STAYS ACTIVE BETWEEN CALLS
%		TO PRINTX
%
% -PRINTXCOUNT* USED TO DECIDE ON A NAME FOR THE NEXT NODE;
%
% -LEVELNUMBER* Counter for number of levels of object being printed

(de -labelname nil 
    (bldmsg "%%L%W" (setq -printxcount* (-plus2 -printxcount* 1))))

(de -findentries (a) 
  (prog (lengthcount) 
    (cond ((numberp prinlength) (setq lengthcount 1))) 
loop (cond ((not (or (pairp a) (vectorp a))) nil) 
      ((-atsoc a -entrypoints*) nil) 
      ((-memq a -visited*) 
	(setq -entrypoints* (cons (cons a nil) -entrypoints*))) (t 
      
      (progn (setq -visited* (cons a -visited*)) 
	(cond ((vectorp a) 
	(prog (n i prinlim) 
	    (setq i 0) 
	    (setq n (-upbv a)) 
            (cond ((and (numberp prinlength) (greaterp n prinlength)) 
               (setq prinlim (difference prinlength 1))) (t 
               (setq prinlim n))) 
	    (while (not (-greaterp i prinlim)) 
	    (progn (-findentries (-getv a i)) 
		(setq i (-add1 i)))))) (t 
	
        
           (progn (cond ((and (numberp prinlevel) 
                (greaterp (setq -levelnumber* (plus -levelnumber* 1)) 
                          prinlevel)) 
                (progn (setq -levelnumber* (difference -levelnumber* 1)) 
                       (return nil))) (t 
            (-findentries (car a)))) 
            (cond ((numberp prinlevel) 
                (setq -levelnumber* (difference -levelnumber* 1)))) 
            (setq a (cdr a)) 
            (cond ((numberp prinlength) 
               (progn (setq lengthcount (plus lengthcount 1)) 
                 (cond ((lessp lengthcount prinlength) (go loop))))) (t 
            (go loop)))))) nil)))))

(de -printpass (a) 
    (cond ((not (or (pairp a) (vectorp a))) (-prin1 a)) (t 
    (prog (w n i prinlim) 
	(cond ((-greaterp (-posn) 50) (-terpri))) 
	(cond ((null !*fulltrace) (setq w (-atsoc a -entrypoints*))))
	(cond ((null w) (go ordinary))) 
	(cond ((cdr w) (return (-prin2 (cdr w))))) 
	(rplacd w (-prin2 (-labelname))) 
	(-prin2 ": ") 
ordinary 
	(cond ((vectorp a) (return 
	(progn (setq n (-upbv a)) 
	    (-princ '![) 
              (cond ((-greaterp n -1)  % perdue fix
	    (progn (-printpass (-getv a 0)) 
                (cond ((and (numberp prinlength) (greaterp n prinlength)) 
                   (setq prinlim (difference prinlength 1))) (t 
                   (setq prinlim n))) 
		(setq i 1) 
		(while (not (-greaterp i prinlim)) 
		(progn (-princ '! ) 
		    (-printpass (-getv a i)) 
		    (setq i (-add1 i)))) 
              (cond ((lessp prinlim n) (-princ " ...")))))) 
	    (-princ '!]))))) 
        (setq n (length a)) 
        (cond ((and (numberp prinlength) (-greaterp n prinlength)) 
            (setq prinlim prinlength)) (t 
        (setq prinlim n))) 
        (setq i 0) 
        (cond ((numberp prinlevel) 
            (progn (setq -levelnumber* (-add1 -levelnumber*)) 
	      (cond ((greaterp -levelnumber* prinlevel) 
	        (progn (-princ "#") 
		  (setq -levelnumber* (sub1 -levelnumber*)) 
		  (return nil))))))) 
	(-princ '!() 
loop 
	(-printpass (car a)) 
	(setq a (cdr a)) 
        (setq i (-add1 i)) 
	(cond ((null a) (go nilend)) 
	((atom a) (go atomend)) 
        ((and (numberp prinlength) (equal i prinlim)) (go nilend)) 
	((and (null !*fulltrace) (setq w (-atsoc a -entrypoints*)))
	 (go labeled)))
blankit 
	(-princ '! ) 
	(go loop) 
labeled 
	(cond ((cdr w) (go refer))) 
	(-princ '! ) 
	(rplacd w (-prin2 (-labelname))) 
	(-prin2 ", ") 
	(go loop) 
refer 
	(-prin2 " . ") 
	(-prin2 (cdr w)) 
	(go nilend) 
atomend 
	(-prin2 " . ") 
	(-prin1 a) 
nilend 
        (cond ((lessp prinlim n) (-princ " ..."))) 
	(-princ '!)) 
        (cond ((numberp prinlevel) 
           (setq -levelnumber* (sub1 -levelnumber*)))) 
	(return nil)))))

(de -prins (a l) 
  (prog 
    (-visited* -entrypoints* -printxcount* -levelnumber*) 
    (setq -levelnumber* 0) 
    (cond ((atom l) (setq -printxcount* 0)) (t 
    (progn (setq -printxcount* (car l)) (setq -entrypoints* (cdr l))))) 
    (-findentries a) 
    (setq -levelnumber* 0) 
    (-printpass a) 
    (return (cons -printxcount* -entrypoints*))))
  

(de printx (a) 
    (progn (cond (*savenames (setq -globalnames* (-prins a -globalnames*))) (t 
       (-prins a nil))) 
      (-terpri) nil))
      
%****************** Trace sub-property-list functions ******************

% The property TRACE is removed from any function that is subject
% to definition or redefinition by PUTD, and so it represents
% a good place to hide information about the function. The following
% set of functions run a sub-property-list stored under this
% indicator;

(de -trget (id ind) 
    (-trgetx (-get id 'trace) ind))

(de -trgetx (l ind) 
% L IS A 'PROPERTY LIST' AND IND IS AN INDICATOR;
    (cond ((null l) nil) 
    ((-eqcar (car l) ind) (cdar l)) (t 
    (-trgetx (cdr l) ind))))

(de -trflagp (id ind) 
    (-memq ind (-get id 'trace)))

(de -trput (id ind val) 
    (-put id 'trace (-trputx (-get id 'trace) ind val)))

(de -trputx (l ind val) 
(cond ((-trputx1 l ind val) l) (t 
(cons (cons ind val) l))))

(de -trputx1 (l ind val) 
(prog nil 
 l (cond ((null l) 
      (return nil))) 
    (cond ((-eqcar (car l) ind) (progn 
      (rplacd (car l) val) 
      (return t)))) 
    (setq l (cdr l)) 
    (go l)))


(de -trflag (l ind) 
(foreach id in l do 
  (-trflag1 id ind)))

(de -trflag1 (id ind) 
(prog (a) 
 (setq a (-get id 'trace)) 
 (cond ((not (-memq ind a)) 
   (-put id 'trace (cons ind a))))))


(de -trremprop (id ind) 
 (progn (setq ind (-trrempropx (-get id 'trace) ind)) 
    (cond ((null ind) (-remprop id 'trace)) (t 
    (-put id 'trace ind)))))

(de -trrempropx (l ind) 
    (cond ((null l) nil) 
    ((-eqcar (car l) ind) (cdr l)) (t 
    (cons (car l) (-trrempropx (cdr l) ind)))))

(de -trremflag (l ind) 
    (foreach id in l do (-trremflag1 id ind)))

(de -trremflag1 (id ind) 
 (progn (setq ind (delete ind (-get id 'trace))) 
    (cond ((null ind) (-remprop id 'trace)) (t 
    (-put id 'trace ind)))))
%******************* Basic functions for TRACE and friends ***********

(de -trinstall (nam argnum) 
% Sets up TRACE properties for function NAM.  This is common to all  TRACE-like
% actions.  Function NAM  is redefined to  dispatch through -TRACEDCALL  which
% takes various actions  (which may simply  be to run  the original  function).
% Important items stored under the TRACE property include ORIGINALFN, which  is
% the original definition,  FNTYPE, the original  function "type" (e.g.   EXPR,
% MACRO ...),  and ARGNAMES,  a list  of the  names of	the arguments  to  NAM.
% arguments to the function.  Runs TRINSTALLHOOK* if non-nil.	Returns non-nil
% if it succeeds, nil if for some reason it fails.
(prog (defn cntr args typ) 
  (cond ((memq nam breakdebuglist*) 
      (progn (printf "%r cannot be traced or broken %n" nam) 
        (return nil)))) 
  (setq defn (-getd nam)) 
  (cond ((null defn) (progn 
    (-lprim (list "Function" nam "is not defined.")) 
    (return nil)))) 
  (setq typ (car defn)) 
  (setq defn (cdr defn)) 
  (cond ((-get nam 'trace) 
    (cond ((and (numberp argnum) (eq typ 'fexpr) 
       (eq (-trget nam 'fntype) 'expr)) (progn 
	 (setq typ 'expr) 
	 (-trremflag (list nam) 'unknownargs) 
	 (setq defn (-trget nam 'originalfn)))) (t 
    
      (return t)))) ((and 
  trinstallhook* 
	  (not (-errapply trinstallhook* (list nam) 'trinstallhook))) 
	    (return nil))) 
  (-trput nam 'originalfn defn) 
  (-trput nam 'fntype typ) 
  (setq args (-argnames nam defn typ argnum)) 
  (cond ((eq args 'unknown) (progn 
    (-trput nam 'argnames -arbargnames*) 
    (-trflag (list nam) 'unknownargs))) (t 
  
    (-trput nam 'argnames args))) 
  (setq cntr (gensym)) 
  (-fluid (list cntr)) 
  (-trput nam 'levelvar cntr) 
  (-set cntr 0) 
  (-trput nam 'counter 0) 
  (cond ((eq args 'unknown) 
    (--putd nam 'fexpr 
	     
	     (list 'lambda 
		    '(-l) 
		    (list (list 'lambda 
				  (list cntr '-trindent*) 
 				  (list '-tracedcall 
					 (-mkquote nam) 
					 '(-evlis -l))) 
 			   (list '-add1 cntr) 
			   '-trindent*)))) (t 
  
    (--putd nam 
	     typ 
	     (list 'lambda 
		    args 
		    (list (list 'lambda 
				  (list cntr '-trindent*) 
				  (list '-tracedcall 
					 (-mkquote nam) 
					 (cons 'list args))) 
			   (list '-add1 cntr) 
			   '-trindent*))))) 
  (cond ((not (-memq nam -installedfns*)) 
    (setq -installedfns* (cons nam -installedfns*)))) 
  (return t)))


(de -trinstallist (u) 
(foreach v in u do (-trinstall v nil)))

(de -argnames (fn defn type nm) 
% Tries to discover the names of the arguments	of FN.	NM is a good guess,  as
% for instance based on the arguments to an EMB procedure.  Returns UNKNOWN  if
% it can't find out.  ON TRUNKNOWN will cause it to return UNKNOWN rather  than
% asking the user.
(cond ((-eqcar defn 'lambda)           % otherwise it must be a code pointer
  (cadr defn)) 
((not (eq type 'expr)) 
  (list (car -arbargnames*))) 

	((or (setq type (-get fn 'arguments*)) (setq type (code-number-of-arguments defn))) 
  (cond ((numberp type) 
    (-firstn type -arbargnames*)) (t 
  
    (car type)))) 
((numberp nm) 
  (-firstn nm -arbargnames*)) 
(*trunknown 
  'unknown) (t 
(-argnames1 fn))))


(fluid '(promptstring*))

(de -argnames1 (fn) 
(prog (n promptstring*) 
  (setq promptstring* (bldmsg "How many arguments does %r take? " fn)) 
again 
  (setq n (read)) 
  (cond ((equal n '?) (progn 
    (-terpri)                          %EXPLAIN OPTIONS;
    (-prin2 "Give a number, a list of atoms (for the names of") 
    (-terpri) 
    (-prin2 "the arguments) or the word 'UNKNOWN'. System security") 
    (-terpri) 
    (-prin2 "will not be good if you say UNKNOWN, but LISP will") 
    (-terpri) 
    (-prin2 "at least try to help you") 
    (-terpri) 
%   -PRIN2 "Number of arguments";
    (go again))) 
  ((equal n 'unknown) 
    (return n)) 
  ((and (fixp n) (not (-lessp n 0))) 
    (return (-firstn n -arbargnames*))) 
  ((-listofatoms n) 
    (return n))) 
  (-terpri) 
  (-prin2 "*** Please try again, ? will explain options ") 
  (go again)))


(de -trrestore (u) 
(prog (bod typ) 
  (cond ((not (-get u 'trace)) 
    (return nil))) 
  (setq bod (-trget u 'originalfn)) 
  (setq typ (-trget u 'fntype)) 
  (cond ((or (null bod) (null typ)) (progn 
    (-lprim (list "Can't restore" u)) 
    (return nil)))) 
  (-remd u) 
  (-putd u typ bod) 
  (-remprop u 'trace)))


(de redefined-putd (nam typ bod) 
% Used in place of PUTD when debug is loaded in order to check
% Install, Breakall, Traceall flags and PUTDHOOK.
(prog (answer saveprop) 
  (setq saveprop (remprop nam 'trace)) 
  (setq answer (-putd nam typ bod)) 
  (cond ((null answer) 
   (progn (put nam 'trace saveprop) 
      (return nil)))) 
  (setq tracedfns* (delq nam tracedfns*)) 
  (setq brokenfns* (delq nam brokenfns*)) 
  (cond ((or *traceall *install *breakall) 
    (-trinstall nam nil))) 
  (cond (*traceall 
     (progn (-trflag (list nam) 'trprint) 
        (setq tracedfns* (cons nam tracedfns*)))) 
  (*breakall 
     (progn (-trflag (list nam) 'brprint) 
        (setq brokenfns* (cons nam brokenfns*))))) 
  (cond (putdhook* 
    (apply putdhook* (list nam)))) 
  (return answer)))


(putd 'putd 'expr (cdr (getd 'redefined-putd)))


(put 'traceall 'simpfg '((t (setq *install t)) (nil (setq *install nil))))
(put 'install 'simpfg '((nil (setq *traceall nil) (setq *breakall nil))))
(put 'breakall 'simpfg '((t (setq *install t)) (nil (setq *install nil))))

%*********************************************************************

(de trout (u) 
% U is a filename.  Redirects trace output there. 
(progn (cond (msgchnl* 
    (close msgchnl*))) 
   (setq msgchnl* (-open u 'output))))

(de stdtrace nil 
(progn (cond (msgchnl* 
    (close msgchnl*))) 
   (setq msgchnl* nil)))

(compiletime (progn 
(dm -outrace (u) 
% Main trace output handler.  -OUTRACE(fn,arg1,...argn) calls fn(arg1,...argn)
% as appropriate to print trace information.
(list '-outrace1 
     (cons 'list (cons (mkquote (cadr u)) (foreach v in (cddr u) collect 
				                         (list '-mkquote v)))))) nil))


(de -outrace1 (-u) 
(prog (-state) 
  (cond (-tracebuff* (progn 
    (rplaca -tracebuff* -u) 
    (setq -tracebuff* (cdr -tracebuff*))))) 
  (cond (*trace (progn 
    (setq -state (-enterpri)) 
    (-eval -u) 
    (-exitpri -state))))))


(de -dumptracebuff (delflg) 
% Prints the ring buffer of saved trace output stored by OUTRACE.
% DELFLG non-nil wipes it clean as well.
(prog (ptr) 
  (cond ((not (-equal (-posn) 0)) 
    (-terpri))) 
  (cond ((null -tracebuff*) (progn 
    (-prin2t "*** No trace information has been saved ***") 
    (return nil)))) 
  (-prin2t "*** Start of saved trace information ***") 
  (setq ptr -tracebuff*) 
  (repeat (progn 
    (-eval (car ptr)) 
    (cond (delflg 
      (rplaca ptr nil))) 
    (setq ptr (cdr ptr))) 
  (eq ptr -tracebuff*)) 
  (-prin2t "*** End of saved trace information ***")))


(de newtrbuff (n) 
% Makes a new ring buffer for trace output with N entries.
(progn (setq -tracebuff* (-cirlist nil n)) nil))
   

(-flag '(newtrbuff) 'opfn)

(newtrbuff 5)

(de -tracedcall (-nam -args) 
% Main routine for handling  traced functions.	Currently  saves the number  of
% invocations of the function,	prints trace information,  causes EMB and  TRST
% functions to	be  handled correctly,	calls  several hooks,  and  stacks  and
% unstacks  information in  the BTR  stack, if	appropriate.  Examines	several
% state variables and  a number of  function specific flags  to determine  what
% must be done.
(prog 
(-a -bod -val -flg -local -state -btrtop -typ -lev -emb 
-trpred -brpred -brflg -brlocal) 
  (cond (*trcount 
    (cond ((setq -a (-trget -nam 'counter)) 
      (-trput -nam 'counter (-add1 -a)))))) 
  (setq -tracecount* (-sub1 -tracecount*)) 
  (cond ((-lessp -tracecount* 1) (progn 
    (setq -traceflag* t) 
    (cond ((-equal -tracecount* 0) (progn 
      (setq -state (-enterpri)) 
      (-prin2 "*** TRACECOUNT reached ***") 
      (-exitpri -state))))))) 
  (cond ((and (not -traceflag*) (-trflagp -nam 'tracewithin)) (progn 
    (setq -traceflag* (setq -local t)) 
    (setq -state (-enterpri)) 
    (-lprim (list "TRACECOUNT =" -tracecount*)) 
    (-exitpri -state)))) 
  (cond (tracentryhook* 
    (setq -flg (-errapply tracentryhook* 
			(list -nam -args) 
			'tracentryhook))) (t 
  
    (setq -flg t))) 
  (cond ((setq -trpred (-trget -nam 'tracewhen)) 
     (cond ((-apply -trpred -args) 
        (setq -flg t)) (t 
     (setq -flg nil))))) 
  (setq -lev (-eval (-trget -nam 'levelvar))) 
  (setq -flg (and -flg -traceflag* (-trflagp -nam 'trprint) 
	   (not (or (-lessp -lev traceminlevel*) 
	       (-greaterp -lev tracemaxlevel*))))) 
  (cond ((-trflagp -nam 'brwithin) 
     (setq -brinstack (cons -nam -brinstack)))) 
  (cond ((or (not -brinflag) -brinstack) 
     (setq -brlocal t))) 
  (setq -brflg t) 
  (cond ((setq -brpred (-trget -nam 'breakwhen)) 
     (cond ((not (-apply -brpred -args)) 
        (setq -brflg nil))))) 
  (setq -brflg (and -brflg -brlocal (-trflagp -nam 'brprint))) 
  (cond ((and -flg (-trflagp -nam 'trst)) 
    (setq -bod (or (-trget -nam 'trstfn) (-trget -nam 'originalfn)))) (t 
  
    (setq -bod (-trget -nam 'originalfn)))) 
  (cond (-flg (progn 
    (setq -trindent* (-add1 -trindent*)) 
    (-outrace -tracentrypri -nam -args -lev -trindent*)))) 
  (cond (*btr 
    (setq -btrtop (-btrpush -nam -args)))) 
  (setq -typ (-trget -nam 'fntype)) 
  (cond ((not (eq -typ 'expr)) 
    (setq -args (list (car -args))))) 
  (cond (-brflg 
    (prog (-state) 
      (setq -state (-enterpri)) 
      (-tracentrypri -nam -args -lev -trindent*) 
      (-exitpri -state) 
      (setq errorform* nil) 
      (printf "Break before entering %r%n" -nam) 
      (setq *continuableerror t) 
      (break)))) 
    
  (cond ((and (-trflagp -nam 'emb) (setq -emb (-trget -nam 'embfn))) 
    (setq -val (-apply -emb (cons -bod -args)))) (t 
  
    (setq -val (-apply -bod -args)))) 
  (cond (-brflg 
    (prog (result) 
      (printf "Break after call %r, value " -nam)
      (apply trprinter* (list -val)) 
      (setq errorform* (mkquote -val)) 
      (setq *continuableerror t) 
      (setq result (break)) 
      (setq -state (-enterpri)) 
      (-tracexitpri -nam result -lev -trindent*) 
      (-exitpri -state)))) 
    
  (cond ((eq -typ 'macro) (progn 
    (cond (tracexpandhook* 
      (-errapply tracexpandhook* 
		 (list -nam -val) 
		 'tracexpandhook))) nil))) 
    
  (cond (*btr 
    (-btrpop -btrtop))) 
  (cond (-flg 
    (-outrace -tracexitpri -nam -val -lev -trindent*))) 
  (cond ((and -local (-greaterp -tracecount* 0)) 
    (setq -traceflag* nil))) 
  (cond ((and (pairp -brinstack) (eq -nam (car -brinstack)))
	 (setq -brinstack (cdr -brinstack)))) 
  (cond (tracexithook* 
    (-errapply tracexithook* (list -nam -val) 'tracexithook))) 
  (return -val)))


(de -errapply (-fn -args -nam) 
(prog (-ans -chn) 
  (setq -ans (-errorset (list '-apply -fn -args) t *backtrace)) 
  (cond ((atom -ans) (progn 
    (setq -chn (-wrs msgchnl*)) 
    (-prin2 "***** Error occured evaluating ") 
    (-prin2 -nam) 
    (-prin2 " *****") 
    (-terpri) 
    (-wrs -chn) 
    (return -ans))) (t 
  
    (return (car -ans))))))


%************ Routines for printing trace information ***************

(de tracecount (n) 
% Suppresses TRACE output until N traced function invocations have passed.
(prog 
  (old) 
  (setq old -tracecount*) 
  (cond ((numberp n) (progn 
    (setq -tracecount* n) 
    (cond ((-greaterp n 0) 
      (setq -traceflag* nil)) (t 
    
      (setq -traceflag* t)))))) 
  (return old)))


(-flag '(tracecount) 'opfn)

(de tracewithin (l) 
% L is a list of function names.  Forces tracing to be enabled within them.
  (progn (cond ((not (-greaterp -tracecount* 0)) (progn 
     (setq -tracecount* 100000) 
     (setq -traceflag* nil) 
     (-lprim "TRACECOUNT set to 100000")))) 
   (foreach u in l conc 
     (cond ((-trinstall u nil) 
       (progn (-trflag1 u 'tracewithin) 
       (list u)))))))

(de trace (l) 
% Enables tracing on each function in the list L.
(foreach fn in l conc 
  (cond ((-trinstall fn nil) (progn 
    (-trflag (list fn) 'trprint) 
    (cond ((not (memq fn tracedfns*)) 
       (setq tracedfns* (cons fn tracedfns*)))) 
    (list fn))))))

(de evtrwhen (l) 
% Places a predicate (car L) on the TRACE property list of the
% function cadr L under the indicator TRACEWHEN.  The function
% will be traced only when the predicate is true.
(prog (fn) 
(setq fn (car l)) 
(cond ((-trinstall fn nil) 
   (progn (-trflag1 fn 'trprint) 
      (-trput fn 'tracewhen 
               (list 'lambda (-trget fn 'argnames) (cadr l))) 
      (cond ((not (memq fn tracedfns*)) 
          (setq tracedfns* (cons fn tracedfns*)))) 
      (list fn))))))


(de untrace (l) 
% Disables tracing for each function in the list L.
(foreach fn in l conc (progn 
  (-trremflag (list fn) 'tracewithin) 
  (-trremflag (list fn) 'trst) 
  (-trremflag (list fn) 'tracewhen) 
  (cond ((-trflagp fn 'trprint) (progn 
    (-trremflag (list fn) 'trprint) 
    fn)) (t 
  (progn 
    (-lprim (list "Function" fn "was not traced.")) nil))))))
    

(de breaker (l) 
%Enables breaking for each function in the list L.
(foreach fn in l conc 
  (cond ((-trinstall fn nil) 
    (progn (-trflag (list fn) 'brprint) 
      (cond ((not (memq fn brokenfns*)) 
         (setq brokenfns* (cons fn brokenfns*)))) 
      (list fn))))))

(de unbreak (l) 
%Disable breaks for each function in the list L.
(foreach fn in l conc 
  (progn (cond ((-trflagp fn 'brwithin) 
     (progn (-trremflag (list fn) 'brwithin) 
       (setq -brinfunctions (delq fn -brinfunctions)) 
       (cond ((null -brinfunctions) 
          (setq -brinflag nil)))))) 
    (-trremflag (list fn) 'breakwhen) 
    (cond ((-trflagp fn 'brprint) 
       (progn (-trremflag (list fn) 'brprint) 
         fn)) (t 
    
      (progn (-lprim (list "Function" fn "Was not broken.")) nil))))))
        

(de breakwithin (l) 
% L is alist of function names.  Breaking of broken functions is
% enabled only within the functions in L.
(progn (setq -brinflag t) 
(cond ((null l) 
  (setq -brinstack nil)) (t 

(foreach fn in l conc 
  (cond ((-trinstall fn nil) 
    (progn (-trflag1 fn 'brwithin) 
      (setq -brinfunctions (cons fn -brinfunctions)) 
      (list fn)))))))))

(de evbrwhen (l) 
% Places a predicate (car L) on TRACE property list of the
% function cadr L under the indicator BREAKWHEN.  The function
% will be broken only when the predicate is true.
(prog (fn) 
  (setq fn (car l)) 
  (cond ((-trinstall fn nil) 
     (progn (-trflag1 fn 'brprint) 
       (-trput fn 'breakwhen 
               (list 'lambda (-trget fn 'argnames) (cadr l))) 
       (cond ((not (memq fn brokenfns*)) 
          (setq brokenfns* (cons fn brokenfns*)))) 
       (list fn))))))


(de -enterpri nil 
(prog (-chn -psn) 
  (setq -chn (-wrs msgchnl*)) 
  (setq -psn (-posn)) 
  (cond ((and (not --intrace) (-greaterp -psn 0)) (-prin2 '<) (-terpri)))
  (return (cons -chn -psn))))


(de -exitpri (-state) 
(prog (-psn) 
  (setq -psn (cdr -state)) 
  (cond ((and (not --intrace) (-greaterp -psn 0)) 
		(cond ((not (-lessp (-posn) -psn)) (-terpri)))
		(-spaces2 (-sub1 -psn)) 
		(-prin2 '>))
	((and (not --intrace) (-greaterp (-posn) 0)) (-terpri))) 
  (-wrs (car -state))))


(de -trindent (-indnt) 
(prog (-n) 
  (setq -n (-times2 -indnt -indentdepth*)) 
  (cond ((not (-greaterp -n -indentcutoff*)) 
    (-spaces2 -n)) (t 
  (progn 
    (-spaces2 -indentcutoff*) 
    (-prin2 '*))))))


(de -tracepri1 (-nam -lev -indnt) 
(progn (-trindent -indnt) 
   (-prin1 -nam) 
   (cond ((-greaterp -lev 1) (progn 
     (-prin2 " (level ") 
     (-prin2 -lev) 
     (-prin2 '!)))))))

(fluid '(--intrace))

(de -tracentrypri (-nam -args -lev -indnt) 
% Handles printing trace information at entry to a function.
(-tracentrypri1 -nam -args -lev -indnt " being entered"))

(de -tracentrypri1 (-nam -args -lev -indnt -s) 
(let ((--intrace --intrace))
(unless --intrace
(setq --intrace t)
(prog (-argnams) 
  (-tracepri1 -nam -lev -indnt) 
  (-prin2 -s) 
  (-terpri) 
  (cond ((not *printnoargs) 
    (progn (setq -argnams (-trget -nam 'argnames)) 
    (while -args (progn 
      (-trindent -indnt) 
      (-spaces -argindent*) 
      (cond (-argnams (progn (-prin2 (car -argnams)) 
			     (setq -argnams (cdr -argnams))))
	    (t (-prin2 '????))) 
      (-prin2 ":	") 
      (apply trprinter* (list (car -args))) 
      (setq -args (cdr -args)) 
      (cond ((and -args (not (equal (-posn) 0))) 
        (-terpri))))) nil))))
(setq --intrace nil))))


(de -tracexpandpri (-nam -exp -lev -indnt) 
% Prints macro expansions.
(progn (-tracepri1 -nam -lev -indnt) 
   (-prin2 " MACRO expansion = ") 
   (apply trexprinter* (list -exp))))

(de -tracexitpri (-nam -val -lev -indnt) 
% Prints information upon exiting a function.
(unless --intrace
(progn (-tracepri1 -nam -lev -indnt) 
   (-prin2 " = ") 
   (apply trprinter* (list -val)))))

%*************** TRST functions ***********************************

(de traceset (l) 
(prog (dfn) 
  (return (foreach fn in l conc 
    (cond ((-trinstall fn nil) (progn 
      (-trflag (list fn) 'trprint) 
      (cond ((not (memq fn tracedfns*)) 
         (setq tracedfns* (cons fn tracedfns*)))) 
      (setq dfn (-trget fn 'originalfn)) 
      (cond ((codep dfn) (progn 
	(-lprim (list "Function" fn "is compiled.  It cannot be traceset.")) nil)) (t 
	
      (progn 
	(-trflag (list fn) 'trst) 
        (cond ((not (-trget fn 'trstfn)) 
	  (-trput fn 'trstfn (-mktrst dfn)))) 
	(list fn)))))))))))


(de untraceset (l) 
(foreach fn in l conc 
  (cond ((-trflagp fn 'trst) (progn 
    (-trremflag (list fn) 'trst) 
    (list fn))) (t 
  (progn 
    (-lprim (list "Function" fn "was not traceset.")) nil)))))
    

(de evtrstsome (l) 
% Trst the function car L for only the variables in cdr L
(prog (fname flatl) 
    (setq flatl (-flatten l)) 
    (setq fname (car flatl)) 
    (setq -setqvars* (cdr flatl)) 
    (on -restrictsetq) 
    (traceset (list fname)) 
    (off -restrictsetq)))


(de -flatten (l) 
% Returns a list of all atoms in L, removing any sublist structure.
(prog (flatl) 
    (foreach x in l do 
       (cond ((atom x) (setq flatl (append flatl (list x)))) (t 
       (setq flatl (append flatl (-flatten x)))))) 
    (return flatl)))


(de -trstpri (-nam -val) 
(progn (-outrace -trstpri1 -nam -val -trindent*) 
   -val))

(de -trstpri1 (-nam -val -indnt) 
(prog (-state) 
  (setq -state (-enterpri)) 
  (-trindent -indnt) 
  (-prin2 -nam) 
  (-prin2 " := ") 
  (apply trprinter* (list -val)) 
  (-exitpri -state)))


(de -mktrst (u) 
(prog (v) 
  (cond ((atom u) 
    (return u))) 
  (cond ((-flagp (car u) 'trstinside) 
    (return (-mktrst1 u)))) 
  (cond ((setq v (-get (car u) 'trstinsidefn)) 
    (return (apply v (list u))))) 
  (cond ((and (idp (car u)) (setq v (-getd (car u)))) (progn 
    (setq v (car v)) 
    (cond ((eq v 'fexpr) 
      (return u))) 
    (cond ((eq v 'macro) 
      (cond (*trstexpandmacros 
	(return (-mktrst (apply (car u) (list u))))) (t 
      
	(return u)))))))) 
  (return (-mktrst1 u))))


(de -mktrst1 (u) 
(foreach v in u collect (-mktrst v)))

% Functions for TRSTing certain special functions

(de -trstsetq (u)
(cond ((or (atom (cdr u)) (atom (cddr u)))
		 (-lprie (list "Malformed expression" u)))
	(t (cons (car u) (-trstsetq1 (cdr u))))))

(de -trstsetq1 (u) 
(cond ((null u) nil)
      ((atom (cdr u)) (-lprie (list "Odd number of args to setq"  u)))
      ((or (not *-restrictsetq) (memq (car u) -setqvars*)) 
	 (append 
	  (list (car u)
		 (list '-trstpri (-mkquote (car u)) (-mktrst (cadr u))))
	  (-trstsetq1 (cddr u))))
      (t  u)))

(de -trstcond (u) 
(cons (car u) 
    (foreach v in (cdr u) collect (-mktrst1 v))))

(de -trstprog (u) 
(cond ((atom (cdr u)) 
  (-lprie (list "Malformed expression" u))) (t 

  (cons (car u) (cons (cadr u) (-mktrst1 (cddr u)))))))

%****************** Heavy handed backtrace routines *******************

(de -btrpush (-nam -args) 
(prog (-ostk) 
  (setq -ostk -btrstk*) 
  (setq -btrstk* (cons (cons -nam -args) -ostk)) 
  (return -ostk)))


(de -btrpop (-ptr) 
(prog (-a) 
  (cond ((and *btrsave (not (eq -ptr (cdr -btrstk*)))) (progn 
    (while (and -btrstk* (not (eq -ptr -btrstk*))) (progn 
      (setq -a (cons (car -btrstk*) -a)) 
      (setq -btrstk* (cdr -btrstk*)))) 
    (cond ((not (eq -ptr -btrstk*)) (progn 
      (-terpri) 
      (-prin2 "***** Internal error in DEBUG: BTR stack underflow *****") 
      (-terpri)))) 
    (setq -btrsavedintervals* (cons -a -btrsavedintervals*)))) (t 
  
    (setq -btrstk* -ptr)))))


(de -btrdump nil 
(prog (stk) 
  (setq stk -btrstk*) 
  (cond ((not (equal (-posn) 0)) 
    (-terpri))) 
  (cond ((and (null stk) (not (and *btrsave -btrsavedintervals*))) (progn 
    (-prin2t "*** No traced functions were left abnormally ***") 
    (return nil)))) 
  (-prin2t "*** Backtrace: ***") 
  (cond (stk (progn 
    (-prin2t "These functions were left abnormally:") 
    (repeat (progn 
      (-tracentrypri1 (caar stk) (cdar stk) 1 1 "") 
      (setq stk (cdr stk))) 
    (null stk))))) 
  (cond (*btrsave 
    (foreach u in -btrsavedintervals* do (progn 
      (-prin2t "These functions were left abnormally, but without") 
      (-prin2t "returning to top level:") 
      (foreach v in u do 
	(-tracentrypri1 (car v) (cdr v) 1 1 "")))))) 
  (-prin2t "*** End of backtrace ***")))


(de btrace (l) 
(progn (setq *btr t) 
   (-btrnewstk) 
   (foreach u in l conc 
     (cond ((-trinstall u nil) (list u))))))

(de -btrnewstk nil 
(setq -btrstk* (setq -btrsavedintervals* nil)))

(-btrnewstk)

(put 'btr 'simpfg '((nil (-btrnewstk)) (t (-btrnewstk))))

%********************* Embed functions ****************************

(de -embsubst (nam fn new) 
(cond ((or (atom fn) (eq (car fn) 'quote)) 
  fn) 
((eq (car fn) nam) 
  (cons new (cons '-originalfn* (cdr fn)))) (t 

  (foreach u in fn collect (-embsubst nam u new)))))

(dm -embcall (-u) 
(list '-apply (cadr -u) (cons 'list (cddr -u))))

(de embfn (nam vars bod) 
(prog (embf) 
  (cond (*defn (progn                   % For REDUCE;
    (outdef (list 'embfn (-mkquote nam) (-mkquote vars) (-mkquote bod))) 
    (return nil)))) 
  (cond ((-trinstall nam (-length vars)) (progn 
    (setq embf (-trget nam 'embfn)) 
    (setq embf (list 'lambda 
		   (cons '-originalfn* vars) 
		   (-embsubst nam bod (cond (embf embf) (t '-embcall))))) 
    (-trput nam 'embfn embf) 
    (-trflag (list nam) 'emb) 
    (return (-mkquote nam)))))))


(de embedfns (u) 
(foreach x in u conc 
  (cond ((-trget x 'embfn) (progn 
    (setq x (list x)) 
    (-trflag x 'emb) 
    x)) (t 
  (progn 
    (-lprim (list "Procedure" x "has no EMB definition")) nil)))))
    

(de unembedfns (u) 
(foreach x in u conc 
  (cond ((-trflagp x 'emb) (progn 
    (setq x (list x)) 
    (-trremflag x 'emb) 
    x)))))

%***************** Function call histogram routines *************

(de -histogram nil 
% Simplistic histogram routine for number of function calls.
(prog (nam nms new m n nm) 
  (cond ((-getd 'treesort)             % If REDIO is available
    (setq -installedfns* (msort -installedfns*)))) 
  (-terpri) 
  (-terpri) 
  (setq n 0) 
  (foreach u in -installedfns* do 
    (cond ((-get u 'trace) (progn 
      (setq n (-max2 (-trget u 'counter) n)) 
      (setq new (cons u new)))))) 
  (setq -installedfns* new) 
  (cond ((greaterp n 0) (setq n (quotient (float (difference (linelength nil) 21)) (float n))))) 
  (foreach u in -installedfns* do (progn 
    (setq nam (-explode u)) 
    (setq nm (-trget u 'counter)) 
    (setq nms (-explode nm)) 
    (setq m (-min2 (length nam) (difference 17 (length nms)))) 
    (for (from i 1 m 1) (do (progn 
      (-princ (car nam)) 
      (setq nam (cdr nam))))) 
    (-princ '!() 
    (while nms (progn 
      (-princ (car nms)) 
      (setq nms (cdr nms)))) 
    (-princ '!)) 
    (-spaces2 20) 
    (cond ((greaterp n 0) 
      (for (from i (fix (times nm n)) 1 -1) (do 
        (-princ '*))))) 
    (-terpri))) 
  (-terpri) 
  (-terpri)))


(de -clearcount nil 
(prog (newval) 
  (foreach u in -installedfns* do 
    (cond ((-get u 'trace) (progn 
      (-trput u 'counter 0) 
      (setq newval (cons u newval)))))) 
  (setq -installedfns* newval)))


% SIMPFG so ON/OFF TRCOUNT will do a histogram

(put 'trcount 'simpfg '((t (-clearcount)) (nil (-histogram))))


%************************ TRACE related statements *********************

(de -tr1 (l fn) 
    (apply fn (list l)))

(dm tr (u) 
    (list 'evtr (mkquote (cdr u))))

(de evtr (u) 
(cond (u 
  (-tr1 u 'trace)) (t 

  (-dumptracebuff nil))))

(dm untr (u) 
    (list 'evuntr (mkquote (cdr u))))

(de untrall nil 
    (progn (evuntr tracedfns*) 
      (setq tracedfns* nil)))

(de evuntr (u) 
(prog (l) 
(cond (u 
  (progn (-tr1 u 'untrace) 
    (foreach l in u do 
       (setq tracedfns* (delq l tracedfns*))))) (t 
(progn 
  (setq -traceflag* nil) 
  (-lprim "TRACECOUNT set to 10000") 
  (setq -tracecount* 10000))))))


(dm trwhen (u) 
  (list 'evtrwhen (mkquote (cdr u))))

(dm trstsome (u) 
  (list 'evtrstsome (mkquote (cdr u))))

(dm br (l) 
  (list 'evbr (mkquote (cdr l))))

(de evbr (l) 
  (-tr1 l 'breaker))

(dm unbr (u) 
  (list 'evunbr (mkquote (cdr u))))

(de evunbr (l) 
  (progn (-tr1 l 'unbreak) 
    (foreach fn in l do 
      (setq brokenfns* (delq fn brokenfns*)))))

(dm brin (u) 
  (list 'evbrin (mkquote (cdr u))))

(de evbrin (l) 
  (-tr1 l 'breakwithin))

(dm brwhen (u) 
  (list 'evbrwhen (mkquote (cdr u))))

(dm restr (u) 
  (list 'evrestr (mkquote (cdr u))))

(de evrestr (u) 
(prog (l) 
   (cond (u 
      (progn (foreach l in u do 
          (-trrestore l)) 
        (setq -installedfns* (delq l -installedfns*)) 
	(setq brokenfns* (delq l brokenfns*)) 
        (setq tracedfns* (delq l tracedfns*)))) (t 
   
      (progn (foreach u in -installedfns* do 
           (-trrestore u)) 
         (setq -installedfns* nil) 
	 (setq brokenfns* nil) 
         (setq tracedfns* nil))))))


(dm trin (u) 
    (list 'evtrin (mkquote (cdr u))))

(de evtrin (u) (-tr1 u 'tracewithin))

(dm trst (u) 
    (list 'evtrst (mkquote (cdr u))))

(de evtrst (u) (-tr1 u 'traceset))

(dm untrst (u) 
    (list 'evuntrst (mkquote (cdr u))))

(de evuntrst (u) (-tr1 u 'untraceset))

(dm btr (u) 
    (list 'evbtr (mkquote (cdr u))))

(de evbtr (u) 
(cond (u 
  (-tr1 u 'btrace)) (t 

  (-btrdump))))

(de resbtr nil (-btrnewstk))

(dm embed (u) 
    (list 'evembed (mkquote (cdr u))))

(de evembed (u) (-tr1 u 'embedfns))

(dm unembed (u) 
    (list 'evunembed (mkquote (cdr u))))

(de evunembed (u) (-tr1 u 'unembedfns))

(dm trcnt (u) 
    (list 'evtrcnt (mkquote (cdr u))))

(de evtrcnt (u) (-tr1 u '-trinstallist))

(cond ((not (funboundp 'definerop)) (progn 
(rlistat '(tr untr trin trst untrst btr 
	embed unembed trcnt restr fstub stub plist ppf) 'noquote) 
(rlistat '(trout trwhen trstsome br unbr brin brwhen) 'noquote) 
(eval '(definerop 'resbtr nil (estat 'resbtr)) )
(eval '(definerop 'stdtrace nil (estat 'stdtrace)) nil))))


(flag '(tr untr btr) 'go)

(flag '(tr trin untr trst untrst btr embed unembed resbtr restr trcnt 
       trout stdtrace) 
     'ignore)


%************************ Stubs *************************************

% These procedures implement  stubs for Rlisp/Reduce.   Usage is  "STUB
% <model   function   invocation>   [,<model   function   invocation>]*
% <semicol>".  For example,  to declare function  FOO, BAR, and  BLETCH
% with formal parameters X,Y,Z for FOO, U for BAR, and none for  BLETCH
% do "STUB FOO(X,Y,Z),BAR U,  BLETCH();".  When a  stub is executed  it
% announces its invocation,  prettyprints its arguments,  and asks  for
% the value to return.  Fexpr stubs may be declared with the  analogous
% statement FSTUB.

(dm stub (u) 
    (list 'evstub (mkquote (cdr u))))

(de evstub (fnlis) 
(foreach y in fnlis do 
  (cond ((not (pairp y)) 
    (cond ((not (idp y)) 
      (-lprie "Function name must be an ID")) (t 
    (progn 
      (-lprim (list "Stub" y "declared as a function of zero arguments")) 
      (-mkstub y nil 'expr))))) 
  ((not (idp (car y))) 
    (-lprie "Function name must be an ID")) 
  ((not (-idlistp (cdr y))) 
    (-lprie "Formal parameter must be an ID")) (t 
  
    (-mkstub (car y) (cdr y) 'expr)))))

(dm fstub (u) 
    (list 'evfstub (mkquote (cdr u))))

(de evfstub (fnlis) 
(foreach y in fnlis do 
   (cond ((not (pairp y)) 
      (-lprie "Arguments to FSTUB must be model function calls")) 
   ((not (idp (car y))) 
      (-lprie "Function name must be an ID")) 
   ((not (-idlistp (cdr y))) 
      (-lprie "Formal parameter must be an ID")) 
   ((neq (-length (cdr y)) 1) 
      (-lprie "An FEXPR must have exactly one formal parameter")) (t 
   
      (-mkstub (car y) (cdr y) 'fexpr)))))


(de -mkstub (name varlis type) 
(putd name 
     type 
     (list 'lambda 
	  varlis 
	  (list '-stub1 
	       (-mkquote name) 
	       (-mkquote varlis) 
	       (cons 'list varlis) 
	       (-mkquote type)))))

(de -stub1 (-pname -anames -avals -type) 
% Weird variable names because of call to EVAL.
(prog (-i) 
   (cond ((neq -type 'expr) 
      (-prin2 -type))) 
   (-prin2 " Stub ") 
   (-prin2 -pname) 
   (-prin2 " called") 
   (-terpri) 
   (-terpri) 
   (setq -i 1) 
   (foreach -u in (pair (-pad -anames (-length -avals)) -avals) do (progn 
      (cond ((car -u) 
	 (-prin2 (car -u))) (t 
      (progn 
	 (-set (-intern (-compress (-append '(a r g) (-explode -i)))) 
	     (cdr -u)) 
	 (-prin2 "Arg #") 
	 (-prin2 -i)))) 
      (-prin2 ": ") 
      (apply stubprinter* (list (cdr -u))) 
      (setq -i (plus -i 1)))) 
   (-prin2t "Return? :") 
   (return (-eval (apply stubreader* nil)))))


(de -redreader nil 
(xread nil))

%*************** Functions for printing useful information *************

(dm plist (u) 
    (list 'evplist (mkquote (cdr u))))

(de evplist (u) 
% Prints the  property	list and  flags  of  U in  a  descent  format,
% prettyprinting nasty	things.   Does	not print  properties  in  the
% global list -INVISIBLEPROPS* or flags in -INVISIBLEFLAGS*.  Usage is
% "PLIST <id> [,<id>]* <semicol>".
(progn (-terpri) 
   (foreach v in u conc 
     (cond ((setq v (-plist1 v)) 
       (list v))))))


(de -plist1 (u) 
(prog (plst flgs hasprops) 
  (-terpri) 
  (cond ((not (idp u)) (progn 
    (-lprie (list u "is not an ID")) 
    (return nil)))) 
  (setq plst (-prop u)) 
  (foreach v in plst do 
    (cond ((and (atom v) (not (-memq v -invisibleflags*))) 
      (setq flgs (cons v flgs))) 
    ((not (-memq (car v) -invisibleprops*)) (progn 
      (cond ((not hasprops) (progn 
	(setq hasprops t) 
	(-prin2 "Properties for ") 
	(-prin1 u) 
	(-prin2t ":") 
	(-terpri)))) 
      (-spaces 4) 
      (-prin1 (car v)) 
      (-prin2 ":") 
      (-spaces 2) 
      (-spaces2 15) 
      (apply propertyprinter* (list (cdr v))))))) 
  (cond (flgs (progn 
    (cond (hasprops 
      (-prin2 "Flags:  ")) (t 
    (progn 
      (-prin2 "Flags for ") 
      (-prin1 u) 
      (-prin2 ":	")))) 
    (foreach v in flgs do (progn 
      (-prin1 v) 
      (-spaces 1))) 
    (-terpri) 
    (-terpri))) 
  ((not hasprops) (progn 
    (-prin2 "No Flags or Properties for ") 
    (-print u) 
    (-terpri)))) 
  (cond ((or hasprops flgs) 
    (return u)))))


(dm ppf (u) 
    (list 'evppf (mkquote (cdr u))))

(de evppf (flis) 
% Pretty prints one or more function definitions, from their
% names.  Usage is "PPF <name> [,<name>]* <semicol>".
(progn (-terpri) 
   (foreach fn in flis conc 
     (cond ((setq fn (-ppf1 fn)) 
       (list fn))))))

(de -ppf1 (fn) 
(prog (bod typ args trc flgs) 
  (cond ((-get fn 'trace) (progn 
    (setq bod (-trget fn 'originalfn)) 
    (cond ((not (codep bod)) 
      (setq bod (caddr bod)))) 
    (setq typ (-trget fn 'fntype)) 
    (cond ((not (-trflagp fn 'unknownargs)) 
      (setq args (-trget fn 'argnames)))) 
    (cond ((-trflagp fn 'trst) 
      (setq trc (cons 'traceset trc))) 
    ((-trflagp fn 'trprint) 
      (setq trc (cons 'traced trc)))) 
    (cond ((-trflagp fn 'tracewithin) 
      (setq trc (cons 'tracedwithin trc)))) 
    (cond ((-trflagp fn 'emb) 
      (setq trc (cons 'embeded trc)))) 
    (cond ((null trc) 
      (setq trc '(installed)))))) 
  ((setq bod (-getc fn)) (progn 
    (setq typ (car bod)) 
    (setq bod (cdr bod)) 
    (cond ((not (codep bod)) (progn 
      (setq args (cadr bod)) 
      (setq bod (cddr bod))))))) (t 
  (progn 
    (-lprie (list "Procedure" fn "is not defined.")) 
    (return nil)))) 
  (foreach u in -functionflags* do 
    (cond ((-flagp fn u) 
      (setq flgs (cons u flgs))))) 
  (cond ((not (equal (-posn) 0)) 
    (-terpri))) 
  (-terpri) 
  (-prin2 typ) 
  (-prin2 " procedure ") 
  (-prin1 fn) 
  (cond (args (progn 
    (-prin2 '!() 
    (foreach u on args do (progn 
      (-prin1 (car u)) 
      (cond ((cdr u) 
	(-prin2 '!,))))) 
    (-prin2 '!))))) 
  (cond ((or trc flgs) (progn 
    (-prin2 " [") 
    (foreach u in (-reversip trc) do (progn 
      (-prin2 u) 
      (-prin2 ';))) 
    (cond (trc (progn 
      (-prin2 "Invoked ") 
      (-prin2 (-trget fn 'counter)) 
      (-prin2 " times") 
      (cond (flgs 
	(-prin2 ';)))))) 
    (cond (flgs (progn 
      (-prin2 "Flagged: ") 
      (foreach u on flgs do (progn 
	(-prin1 (car u)) 
	(cond ((cdr u) 
	  (-prin2 '!,)))))))) 
    (-prin2 '!])))) 
  (cond ((codep bod) (progn 
    (-prin2 " is compiled (") 
    (-prin2 bod) 
    (-prin2t ")."))) (t 
  (progn 
    (-prin2t ':) 
    (foreach form in bod do (apply ppfprinter* (list form))) 
    (-terpri)))) 
  (return fn)))



(de -getc (u) 
% Like GETD,  but  also  looks for  non-standard  functions,  such  as
% SMACROs.  The only non-standard functions looked for are those whose
% tags appear in the list NONSTANDARDFNS*.
(prog (x y) 
  (setq x -nonstandardfns*) 
  (setq y (-getd u)) 
  (while (and x (not y)) (progn 
    (setq y (-get u (car x))) 
    (cond (y 
      (setq y (cons (car x) y)))) 
    (setq x (cdr x)))) 
  (return y)))


(flag '(ppf plist) 'ignore)


