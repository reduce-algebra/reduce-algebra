%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:STEP.SL 
% Description:  Single-step evaluator 
% Author:       Eric Benson, Hewlett-Packard CRC 
% Created:      30 March 1982 
% Modified:     10-Jan-85 19:19:49
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10-Jan-85 19:02:27 (Cris Perdue)
%  Removed loading of rawio and rawbreak.  Fixed value returned by the
%  function STEP.  Fixed redefinitions of keyboard-input-character and
%  of pbout.  Changed use of ouch to use writechar instead.  Fixed problem
%  with prompt string.  Modified printout to end with EOL so output is
%  flushed to the NMODE buffer.
% 19 Jan 1984 1450-PST (Brian Beach)
%   Added standard header.
% 7 October 1983, MLgriss
%		Improve Interface to NMODE, using (write-message ...)
% 5 October 1983,  MLGriss
%		Defined a dummy KEYBOARD-INPUT-CHARACTER and WRITE-PROMPT
%		for NMODE compatibility
%		Added *VERBOSE-STEP switch	
%		Reduce needs for runtime modules in BARE and NMODE
%		Improve interface of BREAK and STEP to permit
%		recovery from CONT errors inside step.
%		Replace a first in STEP-EVAL by safe-first
% 3 October 1983, MLGriss
%		Change MAKE-VECTOR to init to NIL
%		Put COMPILETIME load ClComp, change ; to % before, remove 
%			.BUILD
%		Embed BREAK loop to turn off stepper if error during step
%		Load RAWIO, RawBreak

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The various redefinitions in this file are basically crocks because
% this assumes it is loaded after facilities such as NMODE, but it
% isn't worth it to try to make them right. /csp
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*nmode-running))

% Switch to COMMON lisp subset

(CompileTime (load Useful CLComp numeric-ops))
(Compiletime (On Fast-integers))

(load ; rawio Rawbreak  ; Needed to get correct BREAK  before redef.
      Evalhook)

(defvar *verbose-step () "If T does more detailed eval")

(defvar step-message* "" "Default Step Message")

(defvar evalhook   () "Called by EVAL if not NIL")

(defvar step-level 0 "Level of recursion while stepping")

(defvar step-form () "Current form being evaluated")

(defvar step-value () "Value of current form")

(defvar step-pending-forms () "Buffer of forms being evaluated")

(defvar abort-step () "Flag to indicate exiting step")

(defvar eval-hook () "The hookfunction set for EVAL")

(defvar step-dispatch (make-vector 127 NIL ())
		      "Dispatch table for character commands")

(defvar inside-step () "Used to indicate that STEP in control")

(defvar step-channel () "I/O Channel used for printing truncated forms.")

(eval-when (compile eval)

;; DEF-STEP-COMMAND - define a character command routine
(defmacro def-step-command (char . form)
  `(vset step-dispatch ,char (function (lambda () ,@form))))
)

;; STEP - user entry point
(defun step (form)
  (let (step-result)
    (let ((promptstring* "Step> ")
	  (inside-step T)
	  (step-level 0)
	  (step-pending-forms ())
	  (step-message* 
	   "Step: C-N = next, SPACE = same level, C-X = finish, C-U = up, C-B = Break")
	  (abort-step ()))
      (change-step-message)
      (setq step-result (step-eval form))
      (terpri))
    (change-step-message)	   
    step-result))

(de change-step-message()
  (step-message step-message*))

(de step-message (S)
  (if *nmode-running (write-message S) (prin2t s)))

;; STEP-EVAL - main routine
(defun step-eval (step-form)
  (if (or abort-step (simple-step-p step-form))
      (eval step-form)
      (let ((step-pending-forms (cons step-form step-pending-forms)))
	   (step-print-form step-form "-> ")
	   (let ((macro-call (macro-p (safe-first step-form))))
		(when macro-call
		      (setq step-form (funcall macro-call step-form))
		      (step-print-form step-form "<->")))
	   (let ((step-value (let ((step-level (add1 step-level)))
				  (step-command))))
		(unless (and abort-step (not (eql abort-step step-level)))
			(setq abort-step ())
			;; Print the non macro-expanded form
			(step-print-value (first step-pending-forms)
					  step-value))
		step-value))))

(defun simple-step-p (x)
;;Test if x is a simple case, so just eval it
	(cond (*verbose-step NIL)
	      ((pairp x) NIL)
	      ((null (idp x)) T)
	      ((unboundp x) NIL)
	      (T T)))

(defun safe-first(x)
	(if (pairp x) (first x) NIL))

;; Control-N - Continue stepping each time
(def-step-command #\
  (evalhookfn step-form #'step-eval))

;; Space - do not step lower levels
(def-step-command #\blank
  (eval step-form))

;; Control-U - go up to next higher evaluation level
(def-step-command #\
  (setq abort-step (- step-level 2))
  (eval step-form))

;; Control-X - abort stepping entirely
(def-step-command #\
  (setq abort-step -1)
  (eval step-form))

;; Control-G - grind the current form
(def-step-command #\bell
  (terpri)
  (prettyprint (first step-pending-forms))
  (step-command))

;; Control-P is the same as Control-G
(vset step-dispatch #\ (vref step-dispatch #\bell))

;; Control-R grinds the form in Rlisp syntax
(def-step-command #\
  (terpri)
  (rprint (first step-pending-forms))			; This will only
  (step-command))					; work in Rlisp


;; Control-E - edit the current form
(def-step-command #\
  (setq step-form (edit step-form))
  (step-command))

;; Control-B - go into a break loop
(def-step-command #\
  (errset-step-break)
  (step-command))

;; Control-L redisplay the last 10 pending forms
(def-step-command #\ff
  (display-last-10)
  (step-command))

;; ? - help
(def-step-command #\?
  (load help)
  (displayhelpfile 'step)
  (step-command))

(defun display-last-10 ()
  (display-aux step-pending-forms 10))

(defun display-aux (b n)
  (let ((step-level (sub1 step-level)))
       (unless (or (null b) (eql n 0))
	       (display-aux (rest b) (sub1 n))
	       (step-print-form (first b) "-> "))))

;; STEP-COMMAND - read a character and dispatch on it
(defun step-command ()
  (let ((c (vref step-dispatch (step-get-char))))
    (if c (funcall c)
      (if (fboundp 'ding) (ding)
	(writechar #\bell))
      (step-command))))

;; STEP-PRINT-FORM - print incoming form with indentation
(defun step-print-form (form herald)
  (tab (min step-level 15))
  (princ herald)
  (channelprin1 step-channel form)
  (terpri))

;; STEP-PRINT-VALUE - print form and result of evaluation
(defun step-print-value (form value)
  (tab (min step-level 15))
  (princ "<- ")
  (channelprin1 step-channel form)
  (terpri)
  (tab (+ (min step-level 15) 3))
  (prin1 value)
  (terpri))

;; STEP-BREAK - errset-protected break loop, and redefinition of Break
(remflag '(Break) 'lose)

(unless (fboundp 'pre-step-break) (copyd 'pre-step-break 'break))

(defun errset-step-break ()
;; So that Q exit will remain in stepper
(prog1
  (let ((step-message* "Break: Q=quit, T=backtrace, C=continue, R=Retry"))
    (change-step-message)
    (errset (pre-step-break) ()))
  (change-step-message)))

(defun step-break()
; Called by BREAK should error occur during stepping of form
 (if (not inside-step) (pre-step-break)
    (prog1 
     (let ((abort-step NIL)
	   (inside-step NIL)
	   (evalhook NIL)
	   (step-message* "Break: Q=quit, T=backtrace, C=continue, R=Retry"))
       (printf "%nBreak at step-level %p, Pending %p %n"
	       step-level step-pending-forms)
       (change-step-message)
       (pre-step-break))
      (change-step-message))))


(copyd 'break 'step-break)

(defun PBString (S)
;; Print a  promptstring using PBOUT
	(Pbout #\CR)
	(Pbout #\LF)
	(for (from i 0 (size s)) (do (pbout (indx s i)))))

(defun step-prompt-string (n)
;; Build a >>>> string
  (concat "Step" (List2String (step-prompt-string-aux (min n 30)))))

(defun step-prompt-string-aux(n)
   (for (from i 0 n) (collect #\>)))

; Get a single character
(defun step-get-char ()
  ;  (let ((promptstring* NIL))
  (do ((ch (keyboard-input-character) (keyboard-input-character)))
      ((not (eql ch #\eol)) ch)))
  ;  )

(unless (fboundp 'pbout)
  (copyd 'pbout 'writechar))

(unless (fboundp 'keyboard-input-character)
  (if (fboundp 'pbin)
    (copyd 'keyboard-input-character 'pbin)
    (copyd 'keyboard-input-character 'readchar)))

(unless (fboundp 'write-prompt) (copyd 'write-prompt 'pbstring))

;; STEP-PUT-CHAR - prints on current channel, truncates to one line
(defun step-put-char (channel ch)
  (if (not (eql ch #\eol))
      (unless (greaterp (posn) 75) (writechar ch))))

(eval-when (load eval)			
; Open a special "truncated" output channel
(let ((specialwritefunction* #'step-put-char)
      (specialreadfunction* #'writeonlychannel)
      (specialclosefunction* #'illegalstandardchannelclose))
     (setq step-channel (open "" 'special)))
)

;; End of file.
