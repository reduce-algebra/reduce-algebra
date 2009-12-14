%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:TOP-LOOP.SL
% Title:        Generalized top loop construct
% Author:       Eric Benson and M. L. Griss
% Created:      19 October 1981
% Modified:     23-Oct-84 14:51:52 (Alan Snyder)
% Package:
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 01-Oct-88  (Tony Hearn)
%  Replaced prin2t by prin2/terpri to reduce dependence on non-SL functions.
% 09-Jun-87 (Leigh Stoller)
%  Moved the initialization of *redefmsg from pre-main to a top-level form.
% 04-Jun-87 (Harold Carr)
%  Installed Mark Swanson's updated HIST.  His comments:
%  HIST does properly initialize historylist*.  This is due to its (supposed)
%  invocation within the toploop after the toploop has done (history-append).
%  The following version of hist performs (hist 'clear) without bus errors,
%  something of an improvement over the original.
% 26-May-87 (Leigh Stoller & Harold Carr)
%  Interchanged calls to evalinitforms and initializeinterrupts so
%   initializeinterrupts is done before trying evaluate any forms.
% 21-Dec-86 (Leigh Stoller)
%  Savesystem now checks the fluid using-other-bps-spaces*. Do not want to
%   unexec if we added bps after heap.
% 06-Dec-84 14:23 (Brian Beach)
%  Added call to INITIALIZEINTERRUPTS to PRE-MAIN.
% 27-Oct-84 11:58 (Brian Beach)
%  Added default values for TOPLOOPPRINT*, TOPLOOPREAD*, and TOPLOOPEVAL* in
%  PRE-MAIN.
% 23-Oct-84 14:50:15 (Alan Snyder)
%  Fix problem introduced in 02-Oct-84 change: Unfortunately, in the current
%  implementation of the package system, PACKAGE-NAME (used in
%  COMPUTE-PROMPT-STRING) is a macro.  As a temporary workaround, evaluate the
%  invocation at execution time.
% 18-Oct-84 10:46:26 (Alan Snyder)
%  Fix bug introduced into TOP-LOOP: $EOF$ should not be quoted.  Fix bug
%  introduced in 02-Oct-84 change: should not use "numeric operators" here.
% 02-Oct-84 09:22:45 (Alan Snyder)
%  Introduced functions HISTORY-STATE, SET-HISTORY-STATE, HISTORY-RESET,
%  HISTORY-APPEND, HISTORY-SET-INPUT, HISTORY-SET-OUTPUT, and HISTORY-FETCH
%  for explicitly manipulating the history list; revised PRE-MAIN, SAVESYSTEM,
%  and TOPLOOP to use these functions.  Introduced function
%  COMPUTE-PROMPT-STRING, used by TOPLOOP; changed the promptstring to include
%  information about *DEFN and *PACKAGE*, and to include an optional level
%  number rather than a huge number of angle brackets.  Removed processing of
%  EVAL and IGNORE flags, now in FASLOUT.SL (for proper interaction with
%  macroexpansion).  Changed HISTPRINT to pad with spaces instead of
%  outputting tab characters (doesn't seem reliable).  Cosmetic changes:
%  rearranged the source file to group related functions together.  Performed
%  further restructuring of TOPLOOP; the internal functions DEFNPRINT and
%  DEFNPRINT1 no longer exist.  Now uses ERRSET instead of ERRORSET.  Recoded
%  HIST and HISTPRINT; HISTPRINT no longer internal.  Removed PACKAGE
%  attribute from the file header.
% 17-Sep-84 09:25:37 (Brian Beach)
%  Moved variable initialization from MAIN to PRE-MAIN.  Some application 
%  programs (namely NMODE) redefine MAIN in order to customize the system.
% 6-Aug-84 16:00:00 (RAM)
%  Declared startuproutine* fluid.
% 05-Apr-84 14:21:01 (Brian Beach)
%  Cleaned up TOPLOOP function.  Added STARTUP-SYSTEM.
% 01-Dec-83 15:03:39 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%  03-Mar-83  Nancy Kendzierski
%  Added declaration of LispScanTable!* as a fluid.
%  <PSL.KERNEL>TOP-LOOP.RED.6,  5-Oct-82 11:02:29, Edit by BENSON
%  Added EvalInitForms, changed SaveSystem to 3 args
%  <PSL.KERNEL>TOP-LOOP.RED.5,  4-Oct-82 18:09:33, Edit by BENSON
%  Added GCTime!*
%  $pi/top-loop.red, Mon Jun 28 10:54:19 1982, Edit by Fish
%  Conditional output: !*Output, Semic!*, !*NoNil.
%  <PSL.INTERP>TOP-LOOP.RED.13, 30-Apr-82 14:32:20, Edit by BENSON
%  Minor change to !*DEFN processing
%  <PSL.INTERP>TOP-LOOP.RED.5, 29-Apr-82 03:56:06, Edit by GRISS
%  Initial attempt to add !*DEFN processing
%<PSL.INTERP>TOP-LOOP.RED.18 24-Nov-81 15:22:25, Edit by BENSON
% Changed Standard!-Lisp to StandardLisp
%
% 01-Dec-83 15:03:39 (Brian Beach)
%   Translated from Rlisp to Lisp.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(toploopread*    % reading function
	 toploopprint*   % printing function
	 toploopeval*    % evaluation function
	 toploopname*    % short name to put in prompt
	 toplooplevel*   % depth of top loop invocations
	 promptstring*   % input prompt
	 lispbanner*     % Welcome banner printed in StandardLisp
	 *emsgp          % whether to print error messages
	 *backtrace      % whether to print backtrace
	 *time           % whether to print timing of evaluation
	 gctime*         % Time spent in garbage collection
	 *defn           % To "output" rather than process
	 dfprint*        % Alternate DEFN print function
	 *output         % Whether to print output.
	 semic*          % Input terminator when in Rlisps.
	 *nonil          % Whether to supress NIL value print.
	 initforms*      % Forms to be evaluated at startup
	 lispscantable*  % CurrentScanTable!* when READing
	 *package*       % Current package
	 *break          % Controls entry into debugger on error
	 startuproutine*
	 using-other-bps-spaces*
	 ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MAIN function and related stuff
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(loadtime (setf *redefmsg t))

(de pre-main ()
(console-print-string "punkt1") (console-newline)
  (cleario)
(console-print-string "punkt2") (console-newline)
  (clearbindings)
(console-print-string "punkt3") (console-newline)
  (initializeinterrupts)
(console-print-string "punkt4") (console-newline)
  (evalinitforms)
(console-print-string "punkt5") (console-newline)
  (setq toplooplevel* -1)
  (setf toploopread*  'read)
  (setf toploopeval*  'eval)
  (setf toploopprint* 'print)
  (history-reset)
  (when (null lispbanner*)
    (setq lispbanner* "Portable Standard LISP"))
  (setq *output t)    % Output ON by default.
  (when (equal (catch 'reset (main)) 'reset)
    (pre-main)
    ))

(de main ()
  %
  % A new system can be created by redefining this function to call whatever
  % top loop is desired.
  %
  (setq startuproutine* 'standardlisp)
  (apply startuproutine* 'nil)
  )

(de reset ()
  (throw 'reset 'reset)
  )

(de standardlisp ()
  % Lisp top loop                                                         
  ((lambda (currentreadmacroindicator* currentscantable*)
           (toploop 'read 'printwithfreshline 'eval "lisp" lispbanner*))
   'lispreadmacro
   lispscantable*))

(de savesystem (banner file initforms)
  (when using-other-bps-spaces*
    (stderror "Cannot unexec after allocating additional bps space"))
  (let ((history (history-state)))
    (history-reset)
    (setq lispbanner* (bldmsg "%w, %w" banner (date)))
    (setq *usermode t)
    (setq initforms* initforms)
    (dumplisp file)
    (setq initforms* nil)
    (set-history-state history)
    NIL
    ))

(de evalinitforms ()
  % Evaluate and clear InitForms*
  (for (in x initforms*)
       (do (eval x)))
  (setq initforms* nil)
  )

(de time () % why is this here???
  % Get run-time in milliseconds
  (sys2int (timc))) % TimC is primitive runtime function

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TOPLOOP
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de toploop (toploopread* toploopprint* toploopeval* toploopname* welcomebanner)
  % Generalized top-loop mechanism
  (let ((toplooplevel* (add1 toplooplevel*)) % FLUID
	(semic* ';) % FLUID -- Take out and put in Rlisp????
	(promptstring* promptstring*) % preserve this FLUID variable
	)
    (prin2 welcomebanner)
    (terpri)
    (while t
      (let ((count (history-append)))
	(setq promptstring* (compute-prompt-string count toplooplevel*)))
      (let ((input-value (top-loop-read)))
	(when (or (eq input-value '$exittoploop$) (eq input-value $eof$))
	  (exit))
	(history-set-input input-value)
	(cond ((not *defn) (top-loop-eval-and-print input-value)) % normal case
	      (dfprint* (funcall dfprint* input-value)) % "Compile"
	      (t (prettyprint input-value))
	      ))))
  (printf "Exiting %w%n" toploopname*)
  )

(de top-loop-read ()
  (while t
    (let ((input-value (errset (funcall toploopread*) t)))
      (when (pairp input-value) (exit (car input-value))))))

(de top-loop-eval-and-print (input-value)
  (let* ((this-gc-time gctime*)
	(time-check (time))
	(output-value (errset (funcall toploopeval* input-value) t))
	)
    (setq time-check (difference (time) time-check))
    (setq this-gc-time (difference gctime* this-gc-time))
    (when (pairp output-value)
      (setq output-value (car output-value))
      (history-set-output output-value)
      (when (and *output (eq semic* ';) 
		 (not (and *nonil (eq output-value nil))))
	(errset (funcall toploopprint* output-value) t))
      (when *time
	(if (equal this-gc-time 0)
	  (printf "Cpu time: %w ms%n" time-check)
	  (printf "Cpu time: %w ms, GC time: %w ms%n" 
		  (difference time-check this-gc-time) this-gc-time)))
      )))

(de printwithfreshline (x)
  (printf "%f%p%n" x))

(de compute-prompt-string (count level)
  (bldmsg "%w %w%w%w%w%w "
	  count
	  (if *defn "*DEFN " "")
	  toploopname* 
	  (if (igreaterp level 0) (bldmsg " (%w)" level) "")
	  (if *package* (bldmsg " [%w:]" (eval '(package-name *package*))) "")
	  (if (or (igreaterp level 0) *package*) " >" ">")
	  ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The HISTORY Mechanism
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(historycount*   % number of entries read so far
	 historylist*    % list of entries read and evaluated
	 ))

(de history-state ()
  % Return a description of the current History.
  (list historycount* historylist*))

(de history-reset ()
  (setq historylist* nil)
  (setq historycount* 0)
  )

(de set-history-state (x)
  (setq historycount* (first x))
  (setq historylist* (second x))
  )

(de history-append ()
  % Add a new entry and return its number.
  (setq historycount* (add1 historycount*))
  (setq historylist* (cons (cons nil nil) historylist*))
  historycount*
  )

(de history-set-input (value)
  (rplaca (car historylist*) value))

(de history-set-output (value)
  (rplacd (car historylist*) value))

(de history-fetch (n)
  % Return the Nth entry in the History list.
  (let ((*break NIL))
    (if (or (ilessp n 0) (igeq n historycount*))
      (stderror (bldmsg "No history entry %r" n))
      (car (pnth (cdr historylist*) (idifference historycount* n))))))

(de inp (n)
  % Return Nth input
  (car (history-fetch n)))

(de redo (n)
  % Re-evaluate Nth input
  (apply toploopeval* (list (car (history-fetch n)))))

(de ans (n)
  % Return Nth output
  (cdr (history-fetch n)))

(dn hist (al)
  % Print history entries:

  % (HIST 'CLEAR) => resets the history list
  % (HIST -n) => print the last N entries  
  % (HIST n) => print entries starting with #N
  % (HIST m n) => print entries #M through #N

  (unless (ilessp historycount* 2)
    (cond ((and (pairp al) (equal (car al) 'clear))
	   (history-reset)
	   (history-append)
	   (history-set-input '(hist clear))
	   nil)
	  ((and (pairp al) (iminusp (car al)))
	   (histprint (cdr historylist*) (isub1 historycount*) 
		      (iminus (car al))))
	  (t
	   (let ((i1 1) (i2 (isub1 historycount*)))
	     (when (pairp al)
	       (setq i1 (max i1 (car al)))
	       (setq al (cdr al)))
	     (when (pairp al)
	       (setq i2 (min i2 (car al))))
	     (histprint 
	      (pnth (cdr historylist*) (idifference historycount* i2)) 
	      i2
	      (iadd1 (idifference i2 i1))))))))

(de histprint (l n m)
  (unless (izerop m)
    (histprint (cdr l) (isub1 n) (isub1 m))
    (printf "%w%tInp: %p%n%tAns: %p%n" n 5 (car (first l)) 5 (cdr (first l)))
    ))

% End of file.
