;;; reduce.el --- Load and run ESL REDUCE.

;;; Author: Francis J. Wright
;;; Based on code by Anthony C. Hearn.

;; Load and run REDUCE on Emacs Lisp.
;; Interactive input from minibuffer and output to normal buffer.
;; Batch mode input from stdin and output to stdout.

(add-to-list 'load-path nil)

(require 'esl)							; defines LOAD-MODULE.

;; Load core modules silently:
(let ((esl-load-module-nomessage t) (*MSG nil))
  ;; LOAD-PACKAGE is defined in "rlisp/module.red", so...
  (declare-function LOAD-PACKAGE "fasl/module" (U))
  (LOAD-MODULE 'MODULE)

  ;; Each package fasl file calls CREATE!-PACKAGE, which is defined in
  ;; "eslprolo.red", so...
  (LOAD-MODULE 'ESLPROLO)

  (defvar LOADED-PACKAGES* '(ESLPROLO MODULE))

  (LOAD-PACKAGE 'RLISP)
  (LOAD-PACKAGE 'ESLREND)
  (LOAD-PACKAGE 'POLY)
  ;; alg must be before arith because alg defines evenp, used in arith!
  (LOAD-PACKAGE 'ALG)
  (LOAD-PACKAGE 'ARITH)
  (LOAD-PACKAGE 'MATHPR)
  (LOAD-PACKAGE 'ENTRY))

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
		(standard-output (or noninteractive	; in batch mode, output to stdout
							 (current-buffer)))
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
