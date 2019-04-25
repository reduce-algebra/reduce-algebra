;;; trace.lisp --- Standard Lisp on Common Lisp trace facilities

;; Copyright (C) 2019 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Created: 20 February 2019

;; Based on, and hopefully consistent with, the portable REDUCE
;; tracing code in "package/rtrace/rtrace.red".  But this is a
;; completely independent Common Lisp implementation.

;; Must load "sl-on-cl" before loading or compiling this file.

;; ****************************
;; Can be loaded into REDUCE by
;; : lisp load trace
;; (without quotes) or
;; : lisp load "trace.lisp"
;; etc.
;; ****************************

(cl:in-package :common-lisp-user)

(declaim (optimize debug))

(defpackage :standard-lisp-trace
  (:nicknames :sl-trace)
  (:documentation "Standard Lisp on Common Lisp trace facilities")
  (:use :common-lisp)
  (:import-from :sl :eqcar :put)
  (:export :tr :untr :trst :untrst))

(in-package :standard-lisp-trace)

;; The following macros accept a sequence of function names.  The
;; expression `(tr foo bar)' causes the input and output of the
;; functions `foo' and `bar' to be traced.  The expression `(trst foo
;; bar)' causes both the I/O and the assignments to be traced.  The
;; expression `(untr foo bar)' removes all tracing, and `untrst' is a
;; synonym for `untr'.

(defvar *traced-functions* nil
  "List of currently traced functions.")

(defmacro tr (&rest fns)
  "Trace the functions specified.
If no functions are specified then list all traced functions."
  (if fns
	  `(cl:mapcar #'trace1 ',fns)
	  '*traced-functions*))

(defmacro untr (&rest fns)
  "Untrace(set) the functions specified.
Untrace(set) all traced functions if no functions are specified."
  `(cl:mapcar #'untrace1 ',(or fns *traced-functions*)))

(defvar *trace-setq* nil)

(defmacro trst (&rest fns)
  "Traceset the functions specified.
If no functions are specified then list all traced functions."
  (if fns
	  `(let ((*trace-setq* t))
		 (cl:mapcar #'trace1 ',fns))
	  '*traced-functions*))

(setf (macro-function 'untrst) (macro-function 'untr))

(defun trace1 (name)
  "Trace or traceset function NAME.
NAME must be quoted when called!"
  (let* ((defn (and (symbolp name) (fboundp name) (symbol-function name)))
		 (olddefn defn)					; saved for reliable untracing
		 params)
	;; Check function is defined:
    (unless defn
	  (format *trace-output*
			  "***** ~a not yet defined.~%" name)
      (return-from trace1))
	;;
    ;; (when sl::*comp
    ;;   (format *trace-output*
	;; 		  "~a ~a~%"
	;; 		  "Portable tracing does not work reliably with the"
	;; 		  "switch `comp' on, so it has been turned off.")
	;;   (sl::compilation (setq sl::*comp nil)))
	;;
	;; Get a lambda expression and extract the parameters if possible:
	(if (setq defn (function-lambda-expression defn))
		;; Note that a CL function definition may contain
		;; declarations and a documentation string, and the body is
		;; wrapped in a block form,
		;; i.e. defn = (lambda params [decls] [doc] (block name body))
		(setf (caddr defn) (caddar (last defn)))
		(if (setq defn (get-fasl-source name))
			;; defn = (de name arglist body)
			(setq defn (cons 'lambda (cddr defn)))))
	;;
	(if defn
		(progn							; defn = (lambda params body)
		  (if (eqcar (cadddr defn) 'run-traced-function)
              (return-from trace1
				(if (eq (get name 'traced-setq) *trace-setq*)
					;; i.e. both true or both false
					(format *trace-output*
							"*** ~a already traced.~%" name)
					(re-trace1 name)))
			  (setq params (cadr defn))))
        (progn							; defn = compiled form
		  (setq defn olddefn)
          (if *trace-setq*
			  (progn
				(format *trace-output*
						"*** ~a ~a~%~a~%"
						name
						"must be interpreted for portable assignment tracing."
						"*** Tracing arguments and return value only.")
				(setq *trace-setq* nil)))))
	;;
    (unless params
	  (if (setq params (get name 'sl::number-of-args))
		  (progn
            (setq params
				  (loop
					 for i from 1 upto params collect
					   (intern (format nil "Arg~d" i))))
            (format *trace-output*
					"*** ~a is compiled: ~a~%"
					name
					"portable tracing may not show recursive calls."))
		  (progn
            (format *trace-output*
					"***** parameters for ~a unavailable so cannot apply portable tracing.~%"
					name)
            (return-from trace1))))
	;;
	(pushnew name *traced-functions*)
	(if *trace-setq*
		(progn
		  (setq defn (subst 'traced-setq 'setq defn))
		  (put name 'traced-setq t))
		;; in case function has been redefined:
		(remprop name 'traced-setq))
	(put name 'untraced-function olddefn)
	(put name 'traced-function defn)
	(eval `(defun ,name ,params
			 (run-traced-function ',name ',params (list . ,params))))))

(defun re-trace1 (name)
  "Toggle trace/traceset for function NAME.
NAME must be quoted when called!"
  (let ((defn (get name 'traced-function)))
    (if *trace-setq*
		(if (consp defn)
			(progn
			  (setq defn (subst 'traced-setq 'setq defn))
			  (put name 'traced-setq t))
			(return-from re-trace1
			  (format *trace-output*
					  "*** ~a ~a~%~a~%"
					  name
					  "must be interpreted for portable assignment tracing."
					  "*** Tracing arguments and return value only.")))
		(progn
          (setq defn (subst 'setq 'traced-setq defn))
          (remprop name 'traced-setq)))
    (put name 'traced-function defn)
    (format *trace-output* "*** Trace mode of ~a changed.~%" name)
    name))

(defun untrace1 (name)
  "Remove all tracing for function NAME.
NAME must be quoted when called!"
  (let ((olddefn (get name 'untraced-function)))
	(if olddefn (setf (symbol-function name) olddefn))
    (remprop name 'untraced-function)
    (remprop name 'traced-function)
    (remprop name 'traced-setq)
	(setq *traced-functions* (remove name *traced-functions*))
    name))

(defvar trace-depth 0)

(defun run-traced-function (name params args)
  (let ((trace-depth (1+ trace-depth))
		(result (get name 'traced-function)))
    (format *trace-output* "Enter (~a) ~a~%" trace-depth name)
	(loop for param in params for arg in args do
		 (format *trace-output* "   ~a:  ~s~%" param arg))
    (setq result
          (sl::errorset `(apply ,(eval result) ',args) nil nil))
    (if (or (atom result) (cdr result))	; errorp result
		(sl::error 0 sl::emsg*)
        (setq result (car result)))
	(format *trace-output* "Leave (~a) ~a = ~s~%" trace-depth name result)
    result))

(defmacro traced-setq (left right)
  "For symbolic assignments.
Must avoid evaluating the lhs of the assignment, and evaluate
the rhs only once in case of side effects (such as a gensym)."
  `(progn (format *trace-output* "~a := " ',left)
		  ,(if (eqcar right 'traced-setq)
			   `(setq ,left ,right)
			   `(prog1 (prin1 (setq ,left ,right) *trace-output*)
				  (terpri *trace-output*)))))

(defun get-fasl-source (name)
  "Get DE form for function NAME from \"fasl/modulename.lisp\"."
  (let ((*readtable* (copy-readtable nil)) ; read CL syntax
		file pos stream form)
	(when (and
		   (setq file (get name 'sl::defined-in-file)) ; e.g. "pgk/mod.red"
		   (setq pos (position #\/ (setq file (symbol-name file))))) ; e.g. 3
	  (setq file (subseq file pos (- (length file) 3))) ; e.g. "/mod."
	  (setq file (concatenate 'string "fasl" file "lisp")) ; e.g. "fasl/mod.lisp"
	  (when (setq stream (open file :external-format :UTF-8))
		(loop
		   do
			 (setq form (read stream nil sl::$eof$))
		   until
			 (or (and (eqcar form 'sl::de) (eq (cadr form) name))
				 (eq form sl::$eof$)))
		(close stream)
		(unless (eq form sl::$eof$) form)))))

(shadowing-import '(tr untr trst untrst) :sl)
;; The above import wipes any previous properties, so...
(sl::flag '(tr untr trst untrst) 'sl::noform)
(sl::deflist '((tr sl::rlis) (untr sl::rlis) (trst sl::rlis) (untrst sl::rlis))
	'sl::stat)

;;; trace.lisp ends here
