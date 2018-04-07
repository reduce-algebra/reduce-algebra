%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:UN-RLISP.SL
% Description:  Program to translate from Rlisp to Lisp 
% Author:       Eric Benson 
% Created:      9-Jan-84 
% Modified:     29-Jan-85 16:32:54 (Jim Ambras)
% Package:      Tools 
% Status:       Open Source: BSD License
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
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 26-Sep-86 (Leigh Stoller)
%  Added compiletime load of chars for char-int.
% 29-Jan-85 16:32:27 (Jim Ambras)
%  Changed ouch calls to writechar calls.  Changed list-to-string calls
%  to list2string.
% 15 Feb 1984 1624-PST (Nancy Kendzierski)
%  Changed some % comments to ; comments.
% 26 Jan 1984 1604-PST (Brian Beach)
%  Corrected file name in header.
% 9 Jan 1984 1321-PST (Brian Beach)
%  Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load clcomp1 chars))

(fluid '(in* out* rlispscantable*))

;;;; UN-RLISP(input-file:string, output-file:string):none
;;; This translates a program written in Rlisp syntax into Lisp syntax,
;;; retaining case and comments.
;;; Loading this utility wipes out some flags for compilation.

; Revision history:
;
; 23-Nov-83 14:57:59  Nancy Kendzierski
;   Added Syslisp handling with (load sys-syntax)
; 21-Sep-83 10:38:37  Nancy Kendzierski, Brian Beach,Jim Ambras
;   Changed heuristic-print-list to push a "(" onto the
;   pending-list and print-pending-open-parens to not
;   print "("'s based on pending-open-list.
; 14 Nov 1983 1511-PST Jim Ambras
;   Added Syslisp compatability.  Lowercase all ids.
;  8 Jun 1983 0932-PDT, Cris Perdue
;   Added compiletime load of clcomp1, common, strings.
;   Brought contents of patch file into main source file.
;  M. L. Griss, 3 June 1983
;   Added *ECHO and SEMIC* to turn off RLISP echo
(compiletime (load common))
(load rlisp) ;  syslisp)
; SysLisp "feature"
; (loadtime (load sys-syntax))
;;;;;;;;;;;;;;;
(imports '(strings))

;;; Nothing but syntax, don't evaluate anything now
(errorprintf "%w" "*** Destroying compiler-related flags!")
(mapobl #'(lambda (x) (remflag1 x 'ignore) (remflag1 x 'eval)))

(copyd 'getpr 'get)
(copyd 'putpr 'put)

(flag '(on off) 'eval)

(defvar token-table () "List of lists of uppercased atoms")
(defvar token-table-end () "Pointer to end of token-table during building")
(defvar current-line () "Sublist of the current line of tokens when building")
(defvar un-rlisp-readtable () "Readtable for token scanner")
(defvar comment-column 40 "Position to start comments in the output file")
(defvar no-tokens-yet t "True if no tokens have been put on this line")
(defvar default-case #'string-upcase
  "Funcall for correct case when none is given in source file")
(defvar pending-open-parens 0 "Open parens waiting to be printed")
(defvar pending-list () "Open parens waiting to be printed")
(defvar list-depth 0 "Depth of nesting of lists being printed")
(defvar last-open-column ()
  "Column at which open paren at this level was printed")
(defvar previous-token () "Last token read")
(defvar previous-lines-tokens (cons () ()) "Previous line of tokens")
(defvar token-found t
  "Flag used to indicate whether token was found on the current line")
(defvar current-token () "Current token being read")

;;; Property list indicators used:
;;; PROPER-CASE: holds the preferred case for a symbol
;;; DIFFERENT-RLISP-FORM: holds the token used in Rlisp for a Lisp name,
;;; e.g. (getpr 'geq 'different-rlisp-form) is >=
;;; NOISE: is true if the token goes away in the translation from Rlisp to
;;; Lisp
;;; READER-TAG: things that read like ^foo ==> (tag foo), e.g.
;;; (getpr 'quote 'reader-tag) is \'

;;; Still a problem: N-ARY operators PLUS, TIMES, AND, OR.

(eval-when (compile)

(defmacro inch maybe-channel
  (if maybe-channel
      `(channelreadchar ,(car maybe-channel))
      `(readchar)))

(defmacro uninch (char . maybe-channel)
  (if maybe-channel
      `(channelunreadchar ,(car maybe-channel) ,char)
      `(unreadchar ,char)))

) ; End of eval-when (compile)

(defun un-rlisp (input-file output-file)
  (let ((token-table ())
	(token-table-end ())
	(current-line ()))
    (when (fboundp 'write-prompt)
      (write-prompt (bldmsg "Converting %w to %w" input-file output-file)))
    (collect-case-and-comments input-file)
    (xread-and-print input-file output-file)))

;;;; COLLECT-CASE-AND-COMMENTS - open the file, process and close
(defun collect-case-and-comments (input-file)
  (let ((rlisp-channel (open input-file ':input)))
    (collect-case-and-comments-aux rlisp-channel)
    (close rlisp-channel)))

;;;; COLLECT-CASE-AND-COMMENTS-AUX - bind the read table and process
(defun collect-case-and-comments-aux (rlisp-channel)
  (setf token-table (cons () ()))
  (let ((currentscantable* un-rlisp-readtable)
	(currentreadmacroindicator* 'un-rlisp-readmacro)
	(*raise T)			; Just to make sure
	(*echo NIL)                     ; turn off ECHO
	(semic* '$)
	(token-table-end token-table))
    (collect-case-and-comments-aux-aux rlisp-channel)))

;;;; COLLECT-CASE-AND-COMMENTS-AUX-AUX - process the file
(defun collect-case-and-comments-aux-aux (rlisp-channel)
  (let ((x (channelreadtokenwithhooks rlisp-channel)))
    (if (end-of-file-p x)
        (setf token-table (cdr token-table))	; all done, remove extra cons
	(add-one-token x)
	(collect-case-and-comments-aux-aux rlisp-channel))))

;;;; ADD-ONE-TOKEN - process a single token in the Rlisp file
(defun add-one-token (x)
  (if (end-of-line-p x)
      (add-end-of-line x)
      (add-normal-token x)))

;;;; ADD-END-OF-LINE - process an end of line character
(defun add-end-of-line (x)
  (setf current-line (cons (cdr x) current-line))	; take off EOL in car
  (start-new-line))

;;;; START-NEW-LINE - start a new line in the token table
(defun start-new-line ()
  (setf (cdr token-table-end) (cons current-line ()))	; tack it on the end
  (setf token-table-end (cdr token-table-end))		; bump the pointer
  (setf current-line ()))				; start a new line

;;;; ADD-NORMAL-TOKEN - tack a token on the line with its correct case
(defun add-normal-token (x)
  (let ((upper-symbol x))
    (setf previous-token current-token)
    (setf current-token upper-symbol)
    (unless (no-corresponding-rlisp upper-symbol)
      (setf current-line (cons upper-symbol current-line)))))

;;;; UPPERCASE-SYMBOL - all-uppercase version of a symbol
(defun uppercase-symbol (x)
  (if (not (symbolp x))
      x
      (intern (string-upcase (get-pname x)))))

;;;; END-OF-LINE-P - token returned by end of line and comment read macro
(defun end-of-line-p (x)
  (and (consp x) (= (car x) 'eol)))

;;;; WHITE-SPACE-P - is it a space, tab or end of line?
(defun white-space-p (x)
  (or (= x #\Space) (= x #\Tab) (= x #\Eol)))

;;;; END-OF-FILE-P - is it the eof marker?
(defun end-of-file-p (x)
  (= x $eof$))

(do ((l  '(\( \) \, \; >> end then else do step until each t nil \'
    expr fexpr macro nexpr symbolic lisp scalar
    default 
    wvar warray wstring wconst wfor range
    declare-wvar declare-warray declare-wstring declare-wconst 
    external internal wdeclare 
    wplus wtimes wsetq
    wplus2 wminus wdifference wtimes2 wquotient wremainder 
    wand wor wxor wnot wshift
    wneq weq wgreaterp wlessp wgeq wleq wgetv wputv) (cdr l)))
    ((null l))
    (putpr (car l) 'noise t))

;;;;  NO-CORRESPONDING-RLISP - tokens that appear in the Lisp from Rlisp
;;; that weren't in the original Rlisp.
;;; This includes the noise-p tokens, since they might show up in the Lisp
;;; occasionally.
(defun no-corresponding-rlisp (x)
  (or (numberp x)			; Various problems
      (getpr x 'noise)
      (and (eq x 'if) (eq previous-token 'else))))	; avoid IF in ELSE IF

;;;; DIFFERENT-RLISP-FORM - tokens that have a different name in Rlisp
(defun different-rlisp-form (x)
  (get x 'different-rlisp-form))

;;;; COMMENT-READ-MACRO - called by the reader when % is seen
;;; returns (EOL . string from start of comment to last white space on next
;;; line
(defun comment-read-macro (channel first-char)
  (do ((chars-list (cons first-char ()) (cons (inch channel) chars-list))
       (past-end-of-line nil))
      ((and past-end-of-line (not (white-space-p (first chars-list))))
       (uninch (first chars-list) channel)
       (cons 'eol (list2string (nreverse (rest chars-list)))))
    (when (= (first chars-list) #\Eol)
          (setf past-end-of-line t))))

;;;; EOL-READ-MACRO - called by the reader when end of line is seen
;;; returns (EOL . string including eol to last white space on next line)
(defun eol-read-macro (channel first-char)
  (let ((chars-list (cons first-char ())))
    (do ((next-char (inch channel) (inch channel)))
        ((not (white-space-p next-char))
	 (uninch next-char channel)
	 (cons 'eol (list2string (nreverse chars-list))))
      (setf chars-list (cons next-char chars-list)))))

(setf un-rlisp-readtable (totalcopy rlispscantable*))
(setf (vref un-rlisp-readtable (char-int #\%)) 11)
(putpr '% 'un-rlisp-readmacro #'comment-read-macro)
(setf (vref un-rlisp-readtable (char-int #\Eol)) 11)
(putpr '\
        'un-rlisp-readmacro #'eol-read-macro)

(do ((pair-list '((** . expt)
		  (<= . leq)
		  (<< . progn)
		  (>= . geq)
		  (\:= . setf)
		  (\:= . setq)
		  (\:= . from)		; in for loop
		  (\[ .  indx)
		  (> . greaterp)
		  (= . equal)
		  (< . lessp)
		  (/ . quotient)
		  (\. . cons)
		  (- . minus)
		  (- . difference)
		  (+ .  plus)
		  (* . times)
		  (\' . quote)
		  (procedure . de)
		  (procedure . df)
		  (procedure . ds)
		  (procedure . dm)
		  (procedure . dn)
		  (begin . prog)
		  (if . cond)
		  (for . foreach)
		  (@ . getmem)
		  (& . loc)
		  (goto . go))
		(cdr pair-list)))
    ((null pair-list))
    (putpr (cdr (first  pair-list))
	   'different-rlisp-form
	   (car (first pair-list))))

(putpr 'quote 'reader-tag '\')
;(putpr 'function 'reader-tag '\#\')

;;;; XREAD-AND-PRINT - second pass, parse the Rlisp file and print it
(defun xread-and-print (input-file output-file)
  (let ((out* (open output-file ':output))
	(dfprint* #'un-rlisp-dfprint)
	(*echo NIL)             ; convince RLISP to not echo          
	(semic* '$)
	(*lower t)              ; Lowercase all id's on output
	(*defn t))
    (linelength 10000)		; Never force newline
    (evin (list input-file))
    (do ()	; Comments and newlines past the end
        ((null token-table))
      (prin2 (first (first token-table)))
      (setf token-table (rest token-table)))
      (setf no-tokens-yet t)
    (close out*)))

;;;; UN-RLISP-DFPRINT - called from Rlisp top loop with a single form
(defun un-rlisp-dfprint (form)
  (let ((currentscantable* lispscantable*))
    (do ()
        ((not (null (rest (first token-table)))))
      (tab-to-comment-column)
      (prin2 (first (first token-table)))	; Print all preceding comments
      (setf no-tokens-yet t)
      (setf token-table (rest token-table)))
    (heuristic-print form)
    (setf previous-lines-tokens (cons () ()))))

;;;; HEURISTIC-PRINT - print the form with comments, case and line breaks
(defun heuristic-print (form)
  (cond ((consp form) (heuristic-print-list form))
        ((vectorp form) (heuristic-print-vector form))
	(t (heuristic-print-atom form))))

;;;; HEURISTIC-PRINT-ATOM - look for proper case and line for atom
(defun heuristic-print-atom (form)
  (if (no-corresponding-rlisp form)	; Could be trouble, may need new line
      (progn '(when (and (eq form 't) (> pending-open-parens 0))
	           (goto-next-line))	; T in last form of COND, probably
	     (heuristic-print-atom-aux-aux form))
      (let ((rlisp-form (different-rlisp-form form)))
	(unless rlisp-form (setf rlisp-form form))
	(heuristic-print-atom-aux rlisp-form form))))

;;;; HEURISTIC-PRINT-ATOM-AUX - look for proper case and line for atom
(defun heuristic-print-atom-aux (rlisp-form form)
  ;; Look for form before rlisp-form
  (let ((table-entry (or (rem-member form (first token-table))
		         (rem-member form previous-lines-tokens)
		         (rem-member rlisp-form (first token-table))
			 (rem-member rlisp-form previous-lines-tokens))))
       (if table-entry
	   (heuristic-print-atom-aux-aux form)
	   (when (null (rest token-table))	; Need fail-soft
     (stderror (bldmsg "%r %r not found" rlisp-form form)))
	   (goto-next-line)
	   (heuristic-print-atom-aux rlisp-form form))))	; try again

(defun goto-next-line ()
  (setf token-found nil)
  (tab-to-comment-column)	; otherwise, move to next line
  (prin2 (first (first token-table)))
  (setf no-tokens-yet t)
  ;; put any remaining entries into the previous line entry
  (nconc previous-lines-tokens (rest (first token-table)))
  (setf token-table (rest token-table)))


;;;; HEURISTIC-PRINT-ATOM-AUX-AUX - actually print the atom
(defun heuristic-print-atom-aux-aux (form)
  (setf token-found t)
  (print-pending-open-parens)
  (prin1 (properly-capitalize form))
  (setf no-tokens-yet nil))

;;;; HEURISTIC-PRINT-LIST
(defun heuristic-print-list (form)
  (let ((tag-form (getpr (car form) 'reader-tag)))
    (if (and tag-form (consp (cdr form)) (null (cddr form)))
      (progn (push tag-form pending-list)
	     (heuristic-print (second form)))
      (setf pending-open-parens (+ pending-open-parens 1))
      (push "(" pending-list)
      (heuristic-print (car form))
      (heuristic-print-tail (cdr form))
      )))

;;;; HEURISTIC-PRINT-TAIL
(defun heuristic-print-tail (tail)
  (cond ((null tail) (prin2 ")"))
        ((atom tail) (prin2 " . ") (heuristic-print tail) (prin2 ")"))
	(t (unless no-tokens-yet (writechar #\Space))
	   (heuristic-print (car tail))
	   (heuristic-print-tail (cdr tail)))))

(defun heuristic-print-vector (form)
  (if (equalp form '[])
      (prin2 '[])
      (push '\[ pending-list)
      (heuristic-print (vref form 0))
      (let ((s (size form)))
	   (do ((i 1 (+ i 1)))
	       ((> i s) (prin2 "]"))
	       (unless no-tokens-yet (writechar #\Space))
	       (heuristic-print (vref form i))))))

;;;; PRINT-PENDING-OPEN-PARENS - print parens before a token
(defun print-pending-open-parens ()
  (do ((x (nreverse pending-list) (cdr x)))
      ((null x))
    (prin2 (first x)))
  (setf pending-list ())
  (setf pending-open-parens 0))

;;;; REM-MEMBER - member on the cdr of 2nd arg, the entry is removed
;;; from the list if it is found
(defun rem-member (key list-and-car)
  (if (null (rest list-and-car))
      nil
      (let ((entry (first (rest list-and-car))))
	   (if (equal key entry)
	       (progn (rplacd list-and-car
			      (rest (rest list-and-car)))
		      entry)
	       (rem-member key (rest list-and-car))))))

;;;; TAB-TO-COMMENT-COLUMN - emit tabs until (posn) = comment-column
;;; If past comment-column, print one tab
;;; If no tokens on the line, don't tab forward
(defun tab-to-comment-column ()
  (unless (or no-tokens-yet
	      (char= (char (first (first token-table)) 0) #\Eol))
	  (let ((here (posn)))
	       (if (> here comment-column)
		   (writechar #\Tab)
		   (tab comment-column)))))

;;;; PROPERLY-CAPITALIZE - returns symbol with preferred case
(defun properly-capitalize (symbol)
  symbol
  )
