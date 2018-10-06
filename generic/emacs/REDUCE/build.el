;;; build.el --- Emacs Lisp support code for "build-core-reduce.sh"

;; Author: Francis J. Wright

;; Ensure that required Emacs Lisp files have been compiled
;; sufficiently recently, then load the REDUCE boot file and start
;; Emacs Standard Lisp ready to accept input, which will come via
;; stdin from the here document in the shell script.

(if (file-newer-than-file-p "esl.el" "esl.elc")
	(byte-compile-file "esl.el"))

(if (or (file-newer-than-file-p "boot.el" "boot.elc")
		(file-newer-than-file-p "esl.elc" "boot.elc"))
	(byte-compile-file "boot.el"))

(if (or (file-newer-than-file-p "eslpretty.el" "eslpretty.elc")
		(file-newer-than-file-p "esl.elc" "eslpretty.elc"))
	(byte-compile-file "eslpretty.el"))

(require 'boot)
(STANDARD-LISP)

;;; build.el ends here
