%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:PP-FILE.SL 
% Description:  Program to prettyprint Un-Rlisped programs. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      12-Dec-83 
% Modified:     31-May-84 08:08:10 (Brian Beach) 
% Mode:         Lisp 
% Package:      Utilities 
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
% 31-May-84 08:08:02 (Brian Beach)
%  Added more ugly forms.
% 25-May-84 08:39:03 (Brian Beach)
%  Added stuff for pretty printing LAP.
% 26 Jan 1984 1558-PST (Brian Beach)
%  Corrected file name in header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% Functions for including comments in forms that are read:
%

(fluid '(in* out*))
(fluid '(comment-scan-table*))

(setf comment-scan-table*
  % Same a Lisp scan table, except that "%" is a delimiter like "'" is.
  (let ((new-scan-table (totalcopy lispscantable*)))
    (putv new-scan-table (char !%) 
	  (getv lispscantable* (char '!')))
    new-scan-table
    ))

(de read-comment (channel token)
  % This is a read macro called whenever a "%" is encountered in the
  % input.  All characters from the "%" to the end of the line are collected
  % into a string, and a form '(COMMENT "% Contents of comment") is returned.

  (let ((result     (id2string token))
	(character  (channelreadchar channel)))
    (while (not (or (eq character (char EOF))
		    (eq character (char EOL))))
      (setf result (string-concat result (string character)))
      (setf character (channelreadchar channel))
      )
    (list 'COMMENT result)
    ))

(put '!% 'lispreadmacro 'read-comment)

(de channel-read-with-comments (channel)
  % Reads from CHANNEL and includes comments.

  (let ((lispscantable* comment-scan-table*))
    (channelread channel)
    ))

(de read-with-comments ()
  % Reads from the standard input and includes comments.
  (channel-read-with-comments in*)
  )

%
% Functions for prettyprinting:
%

(fluid '(top-level-comments uglies))

(de prettyprint-file (input-file output-file)
  % Reads INPUT-FILE form by form and produces pretty output in OUTPUT-FILE.
  % Names of all functions encountered are echoed (this is a slow process,
  % and echoing is good for the sanity).

  (let* ((input-channel    (open input-file 'input))
	 (old-out*         out*)
	 (out*             (open output-file 'output))
	 (form             (channel-read-with-comments input-channel))
	 (*lower           t))
    (while (neq form $eof$)
      (prettyprint-form form)
      (when (and (pairp form) (geq (length form) 2) (idp (second form)))
	(channelprint old-out* (second form))
	)
      (setf form (channel-read-with-comments input-channel))
      )
    (close input-channel)
    (close out*)
    ))

(de prettyprint-form (form)
  % Prettyprints FORM to the standard output.  The heuristic used is that
  % there should be blank lines after all top level forms, except for
  % comments.  Not perfect, but not horrible either.

  (let ((pretty-form (pretty-reform form)))
    (prettyprint pretty-form)
    (unless (comment? pretty-form)
      (terpri)
      )))

(de comment? (form)
  % Is FORM a comment?
  
  (and (pairp form)
       (eq (first form) 'comment)
       ))

(de pretty-reform (form)
  % Remove gross things introduced by RLISP.
  
  (remove-uglies form)
  )

(de remove-uglies (form)
  (cond
   ((atom form)                 form)
   ((eq (car form) 'QUOTE)      form)
   ((find-matching-ugly form)   (fix-ugly form))
   ((is-cond? form)             (special-cond-handling form))
   (t                           (cons (remove-uglies (car form))
				      (remove-uglies (cdr form))))
   ))

(de find-matching-ugly (form)
  % Try to find a matching ugly form.  UGLIES is an association list
  % with pairs: (ugly . pretty).  UNIFY will return non-nil when FORM
  % matches one of the ugly halves of the pairs.
  
  (ass #'unify form uglies)
  )

(de fix-ugly (form)
  % Remove an ugly construct from FORM.  Find the matching (ugly . pretty)
  % pair and replace the ugly with the pretty.

  (let* ((pair            (find-matching-ugly form))
	 (ugly-template   (car pair))
	 (pretty-template (cdr pair))
	 (bindings        (unify ugly-template form)))
    (remove-uglies (apply-bindings bindings pretty-template))
    ))

(de is-cond? (form)
  (and (pairp form)
       (eq (first form) 'COND)
       ))
	      
(de special-cond-handling (form)
  (cons 'COND
	(for (in item (rest form))
	     (collect (handle-cond-item item))
	     )))

(de handle-cond-item (item)
  % Check to see if item contains a superfluous PROGN.
  (if (and (pairp item)
	   (geq (length item) 2)
	   (pairp (second item))
	   (eq (first (second item)) 'PROGN))
    (cons (remove-uglies (first item))
	  (append (remove-uglies (rest (second item)))
		  (remove-uglies (rest (rest item)))))
    (remove-uglies item)
    ))

(de unify (form1 form2)
  % Unify the two forms.  Returns a list of binding pairs: 
  % (variable . value).  Returns NIL if there is no match.
  % Returns T if there is a match, but no bindings.
  (cond
   ((is-variable? form1)        (single-binding form1 form2))
   ((is-variable? form2)        (single-binding form2 form1))
   ((atom form1)                (equal form1 form2))
   ((atom form2)                (equal form1 form2))
   (t                           (let ((bind1 (unify (car form1) (car form2))))
				  (when bind1
				    (merge-bindings
				     bind1
				     (unify (cdr form1) (cdr form2))))))
   ))

(de single-binding (variable form)
  (list (cons variable form))
  )

(de merge-bindings (bind-list1 bind-list2)
  (cond
   ((null bind-list1)          nil)
   ((null bind-list2)          nil)
   ((eq bind-list1 t)          bind-list2)
   ((eq bind-list2 t)          bind-list1)
   (t                          (append bind-list1 bind-list2))
   ))

(de apply-bindings (bindings form)
  (sublis bindings form)
  )

(de is-variable? (id)
  (flagp id 'unify-variable)
  )

(flag '(*x* *y* *z*) 'unify-variable)

(setf uglies
  '(
    ( (progn *x*)                          . *x*                 )
    ( (prog nil (return *x*))              . *x*                 )
    ( (cond (*x* . *y*))                   . (when *x* . *y*)    )
    ( (when *x* (progn . *y*))             . (when *x* . *y*)    )
    ( (while *x* (progn . *y*))            . (while *x* . *y*)   )
    ( (when (not *x*) . *y*)               . (unless *x* . *y*)  )
    ( (cond (*x* *y*) (t *z*))             . (if *x* *y* *z*)    )
    ( (defun *x* *y* (progn . *z*))        . (defun *x* *y* . *z*))
    ( (de *x* *y* (progn . *z*))           . (de *x* *y* . *z*)  )
    ( (dm *x* *y* (progn . *z*))           . (dm *x* *y* . *z*)  )
    ( (dn *x* *y* (progn . *z*))           . (dn *x* *y* . *z*)  )
    ( (ds *x* *y* (progn . *z*))           . (ds *x* *y* . *z*)  )
    ( (df *x* *y* (progn . *z*))           . (df *x* *y* . *z*)  )
    ( (let *x* (progn . *y*))              . (let *x* . *y* )    )
    ( (lispvar *x*)                        . *x*                 )
    ( setq                                 . setf                )
    ( (let nil . *x* )                     . (progn *x*)         )
    ))

%
% Hacks to the pretty printer to make programs look decent:
%

(bothtimes (load pp))

(define-special-sprint-list-structure progn list-1-long sprint-compiletime)
(define-special-sprint-list-structure prog1 list-1-long sprint-compiletime)
(define-special-sprint-list-structure lap sprint-lap-test sprint-lap)
(define-special-sprint-list-structure if              list-2-long sprint-if)
(define-special-sprint-list-structure when            list-2-long sprint-if)
(define-special-sprint-list-structure unless          list-2-long sprint-if)
(define-special-sprint-list-structure while           list-2-long sprint-if)
(define-special-sprint-list-structure declare-warray  list-2-long sprint-if)
(define-special-sprint-list-structure declare-wstring list-2-long sprint-if)
(define-special-sprint-list-structure declare-wvar    list-2-long sprint-if)
(define-special-sprint-list-structure declare-wconst  list-2-long sprint-if)
(define-special-sprint-list-structure compiletime     list-1-long sprint-compiletime)
(define-special-sprint-list-structure loadtime        list-1-long sprint-compiletime)
(define-special-sprint-list-structure bothtimes       list-1-long sprint-compiletime)
(define-special-sprint-list-structure comment sprint-comment-test sprint-comment)


(de list-1-long (exp)
  % Check if EXP is a list of length one or more.
  (and (listp exp)
       (geq (length exp) 1)
       ))

(de list-2-long (exp)
  % Check if EXP is a list of length two or more.
  (and (listp exp)
       (geq (length exp) 2)
       ))

(de sprint-compiletime (exp left-margin)
  (princ "(")
  (princ (first exp))
  (sprint-rest-of-vertical-list (rest exp) (plus left-margin 2))
  )

(de sprint-if (exp left-margin)
  (princ "(")
  (princ (first exp))
  (princ " ")
  (internal-sprint (second exp) (posn))
  (sprint-rest-of-vertical-list (rest (rest exp)) (plus left-margin 2))
  )

(de sprint-lap-test (exp)
  (and (pairp (cdr exp))
       (pairp (second exp))
       (eq (first (second exp)) 'QUOTE)
       ))

(de sprint-lap (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") 
  (princ 'lap)
  (princ " ")
  (princ "'")
  (princ "(")
  (sprint-rest-of-lap (first (rest (second exp))) (posn))
  (princ ")")
  )

(fluid '(lap-comment-column))
(setf lap-comment-column 50)

(defun sprint-rest-of-lap (list left-margin)
  (for (in x list)
       (do (when (idp x)
	     (off lower))
	   (tab (cond ((idp x)                (- left-margin 5))
		      ((eqcar x 'comment)     lap-comment-column)
		      (t                      left-margin)))
	   (when (idp x)
	     (terpri))
	   (internal-sprint x (posn))
	   (on lower)
	   )
       )
  (princ ")")
  )

(de sprint-comment-test (exp)
  (and (listp exp)
       (eq (length exp) 2)
       (eq (first exp) 'comment)
       (stringp (second exp))
       ))

(de sprint-comment (exp left-margin)
  %(tab left-margin)
  (princ (second exp))
  (unless (eq left-margin 0)  % HACK!
    (terpri)
    )
  %(tab *pp-line-length*)
  )


(de sprint-defun (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(")
  (let ((a (plus2 1 (posn))))
    (princ (first exp))
    (princ " ")
    (internal-sprint (second exp) (posn)) (princ " ")
    (if (null (third exp))
      (princ "()")
      (internal-sprint (third exp) a)
      )
    (sprint-rest-of-vertical-list (cdddr exp) a)))

