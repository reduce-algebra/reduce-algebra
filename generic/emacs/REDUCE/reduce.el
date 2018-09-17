;;; reduce.el --- Load and run ESL REDUCE.

;;; Author: Francis J. Wright.
;;; Based on code by Anthony C. Hearn.

;; Load and run REDUCE on Emacs Lisp with input via the minibuffer and
;; output to a normal buffer.

(add-to-list 'load-path nil)

(require 'esl)							; defines LOAD-MODULE.

;; LOAD-PACKAGE is defined in "rlisp/module.red", so...
(declare-function LOAD-PACKAGE "fasl/module" (U))
(LOAD-MODULE 'MODULE)

;; Each package fasl file calls CREATE!-PACKAGE, which is defined in
;; "eslprolo.red", so...
(LOAD-MODULE 'ESLPROLO)

(defvar LOADED-PACKAGES*)

(setq LOADED-PACKAGES* (list 'MODULE 'ESLPROLO))

(LOAD-PACKAGE 'RLISP)
(LOAD-PACKAGE 'ESLREND)
(LOAD-PACKAGE 'POLY)
(LOAD-PACKAGE 'ALG)	; must be before arith because defines evenp, used in arith!
(LOAD-PACKAGE 'ARITH)
(LOAD-PACKAGE 'MATHPR)
(LOAD-PACKAGE 'ENTRY)

;; (INITREDUCE)
;; Currently need to run STANDARD-LISP then run (INITREDUCE), or...

(with-no-warnings			   ; suppress warning about lack of prefix
  (defvar STATCOUNTER))
(declare-function INITREDUCE "fasl/eslrend" ())
(declare-function BEGIN "fasl/eslrend" ())

(defun REDUCE ()
  ;; reduce (lower case) is an alias for ‘cl-reduce’!
  "Run REDUCE with input via the minibuffer and output via a buffer."
  (interactive)
  (switch-to-buffer
   (setq esl--default-output-buffer
		 (get-buffer-create esl--default-output-buffer-name)))
  ;; (require 'reduce-mode "../reduce-mode.el") ; temporary filename
  ;; (reduce-mode)
  (goto-char (point-max))  ; in case buffer already exists
  (let (value			   ; value of last sexp
		;; Output to the END of the current buffer:
		;; (standard-output (set-marker esl--marker (point-max)))
		;; The above is proving unreliable, so try this:
		(standard-output (current-buffer))
		;; Make (READCH) read from the minibuffer:
		(esl--readch-use-minibuffer t))
	(catch 'QUIT
	  ;; Run the standard REDUCE read-eval-print loop:
	  (if (zerop STATCOUNTER)
		  (INITREDUCE)
		(BEGIN)))))

(provide 'reduce)

(REDUCE)		; Probably bad form, but convenient, to run this here!

;;; reduce.el ends here
