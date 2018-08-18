;;; dbuild.el --- build ESL REDUCE "in core" without use of fasl files.
;;; Contains a mix of Emacs Standard LISP and REDUCE source code.

;;; Author: Anthony C. Hearn.
;;; Revised for ESL REDUCE by Francis J. Wright.

(or (file-exists-p "log") (make-directory "log"))

(WRS (OPEN "log/dbuild.log" 'OUTPUT))

;; Assume esl.el and boot.el are already compiled, and ensure they are
;; loaded:
(require 'boot)

(setq *ARGNOCHK t)

(setq *INT nil)					  ; Prevents input buffer being saved.

(setq *MSG nil)

(setq *COMP t)			  ; It's much faster if we compile everything!

(BEGIN2)
RDS(XXX := OPEN("eslprolo.red",'INPUT));
(CLOSE XXX)

(BEGIN2)
RDS(XXX := OPEN("eslbuild.red",'INPUT));
(CLOSE XXX)

(LOAD-PACKAGE-SOURCES 'RLISP 'RLISP)

(BEGIN2)
RDS(XXX := OPEN("eslrend.red",'INPUT));
(CLOSE XXX)

;; The following two packages seem to be needed, and in this order:

(LOAD-PACKAGE-SOURCES 'POLY 'POLY)

(LOAD-PACKAGE-SOURCES 'ALG 'ALG)

;; (LOAD-PACKAGE-SOURCES 'ARITH 'ARITH) ; Needed by roots, specfn*, (psl).

;; (LOAD-PACKAGE-SOURCES 'ENTRY 'SUPPORT)

;; (LOAD-PACKAGE-SOURCES 'REMAKE 'SUPPORT)

(setq *COMP nil)

(CLOSE (WRS nil))

(INITREDUCE)
