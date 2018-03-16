;;; reduce.el --- Run ESL REDUCE.

;;; Author: Francis J. Wright.
;;; Based on code by Anthony C. Hearn.

;; Run REDUCE on Emacs Lisp with input via the minibuffer and output
;; to a normal buffer.

(require 'esl)

;; Defines LOAD-MODULE.

;; LOAD-PACKAGE is defined in "rlisp/module.red", so...
(LOAD-MODULE 'MODULE)

;; LOAD-PACKAGE calls EVLOAD and each package fasl file calls
;; CREATE!-PACKAGE, both of which are defined in "eslprolo", so...
(LOAD-MODULE 'ESLPROLO)

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

(defun reduce ()
  "Run REDUCE with input via the minibuffer and output via a buffer."
  (interactive)
  (switch-to-buffer
   (setq esl--default-output-buffer
		 (get-buffer-create esl--default-output-buffer-name)))
  (esl-standard-lisp-interaction-mode)
  (goto-char (point-max))  ; in case buffer already exists
  (let (value			   ; value of last sexp
		;; Output to the END of the current buffer:
		;; (standard-output (set-marker esl--marker (point-max)))
		;; The above is proving unreliable, so try this:
		(standard-output (current-buffer))
		;; Make (READCH) read from the minibuffer:
		(esl--readch-use-minibuffer t))
	(if (zerop STATCOUNTER)
		(INITREDUCE)
	  (BEGIN))))

(provide 'reduce)

(reduce)		; Probably bad form, but convenient, to run this here!

;;; reduce.el ends here
