;;; trace.lisp --- Standard Lisp on Common Lisp trace facilities

;; Copyright (C) 2019, 2025, 2026 Francis J. Wright

;; Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
;; Time-stamp: <2026-02-12 17:30:57 franc>
;; Created: 20 February 2019

;; Based on, and hopefully consistent with, the portable REDUCE
;; tracing code in "packages/rtrace/rtrace.red".  But this is a
;; completely independent Common Lisp implementation.

;; Trace a REDUCE function or algebraic operator implemented as a
;; psopfn or simpfn by tracing the underlying Lisp function.

;; ***** Must load "sl-on-cl" before loading or compiling this file. *****

;; ****************************
;; Can be loaded into REDUCE by
;; : lisp load trace
;; (without quotes) or
;; : lisp load "trace.lisp"
;; etc.
;; ****************************

(declaim (optimize #-DEBUG speed #+DEBUG debug #+DEBUG safety))

(defpackage :standard-lisp-trace
  (:nicknames :sl-trace)
  (:documentation "Lower-case Standard Lisp on Common Lisp trace facilities")
  (:use :common-lisp)
  (:import-from :sl :eqcar :put $eof$)
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
List all traced functions if no functions or nil are specified."
  (if (and fns (not (equal fns '(nil))))
      `(cl:mapcar #'trace1 ',fns)
      '*traced-functions*))

(defmacro untr (&rest fns)
  "Untrace(set) the functions specified.
Untrace(set) all traced functions if no functions or nil are specified."
  `(cl:mapcar #'untrace1
              ',(or (and (not (equal fns '(nil))) fns) *traced-functions*)))

(defmacro trst (&rest fns)
  "Traceset the functions specified.
List all traced functions if no functions or nil are specified."
  (if (and fns (not (equal fns '(nil))))
      `(cl:mapcar #'(lambda (name) (trace1 name t)) ',fns)
      '*traced-functions*))

(setf (macro-function 'untrst) (macro-function 'untr))

(defparameter %fasl.lisp-pathname-template%
  (merge-pathnames
   (make-pathname :type "lisp")
   slim::%fasl-directory-pathname%)
  "Absolute pathname of the form \"/.../fasl.<lisp>/???.lisp\".")

(declaim (ftype (cl:function (symbol) cons) get-fasl-source))

(defun get-fasl-source (name)
  "Get DE form for function NAME from file \"/.../fasl.<lisp>/modulename.lisp\"."
  (let ((*readtable* (copy-readtable nil)) ; read CL syntax
        file stream form)
    (when (setq file (get name 'sl::defined-in-file)) ; e.g. |PGK/MOD.RED|
      (setq file (pathname-name
                  (slim::%string-invert-case (symbol-name file)))) ; e.g. "mod"
      (setq file (merge-pathnames file %fasl.lisp-pathname-template%))
      ;; e.g. "/.../fasl.which/mod.lisp"
      (when (setq stream (open file
                               #-CCL :external-format
                               #+CLISP charset:UTF-8
                               #-(or CLISP CCL) :UTF-8
                               :if-does-not-exist nil))
        (loop
           do
             (setq form (read stream nil $eof$))
           until
             (or (and (eqcar form 'sl::de) (eq (cadr form) name))
                 (eq form $eof$)))
        (close stream)
        (unless (eq form $eof$) form)))))

(declaim (ftype (cl:function (symbol boolean) symbol) re-trace1))

(defun re-trace1 (name trace-setq)
  "Toggle trace/traceset for function NAME.
NAME must be quoted when called!"
  (let ((defn (get name 'traced-function)))
    (if trace-setq
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

(defun trace1 (name &optional trace-setq)
  "Trace or traceset function or algebraic operator NAME.
NAME must be quoted when called!"
  (unless  (symbolp name)
    (format *trace-output*
            "~&***** ~a must be a symbol.~%" name)
    (return-from trace1))
  (let (defn newname olddefn params)
    (declare (symbol newname) (list params))
    ;; Check how NAME is implemented; get definition and update NAME
    ;; if necessary:
    (cond ((fboundp name)
           (setq defn (symbol-function name)))
          ((setq newname (get name 'sl::psopfn))
           (format *trace-output*
                   "~&*** ~a implemented as psopfn ~a.~%" name newname)
           (setq name newname
                 defn (and (fboundp newname) (symbol-function newname))))
          ((setq newname (get name 'sl::simpfn))
           (format *trace-output*
                   "~&*** ~a implemented as simpfn ~a.~%" name newname)
           (setq name newname
                 defn (and (fboundp newname) (symbol-function newname)))))
    ;; Check function to be traced is defined:
    (unless defn
      (format *trace-output*
              "~&***** ~a is not defined.~%" name)
      (return-from trace1))
    (setq olddefn defn)                 ; saved for reliable untracing
    ;;
    ;; (when sl::*comp
    ;;   (format *trace-output*
    ;;        "~a ~a~%"
    ;;        "Portable tracing does not work reliably with the"
    ;;        "switch `comp' on, so it has been turned off.")
    ;;   (sl::compilation (setq sl::*comp nil)))
    ;;
    ;; Get a lambda expression and extract the parameters if possible:
    (if (setq defn (function-lambda-expression defn))
        ;; Note that a CL function definition may contain declarations
        ;; and a documentation string, and the body may be wrapped in
        ;; a block form, i.e.
        ;; defn = (lambda params [decls] [doc] body)
        ;; or
        ;; defn = (lambda params [decls] [doc] (block name body))
        (let ((b (car (last defn))))
          (setq defn (list 'lambda (cadr defn)
                           (if (eqcar b 'block) (caddr b) b))))
        ;; Read Lisp source file in fasl directory:
        (if (setq defn (get-fasl-source name))
            ;; defn = (de name arglist body)
            (setq defn (cons 'lambda (cddr defn)))))
    ;;
    (if defn
        (progn                          ; defn = (lambda params body)
          (if (eqcar (caddr defn) 'run-traced-function)
              (return-from trace1
                (if (eq (get name 'traced-setq) trace-setq)
                    ;; i.e. both true or both false
                    (format *trace-output*
                            "~&*** ~a already traced.~%" name)
                    (re-trace1 name trace-setq)))
              ;; wrap params in a list in case params = () = nil!
              (setq params (list (cadr defn)))))
        (progn
          (setq defn olddefn)           ; defn = compiled form
          (when trace-setq
            (format *trace-output*
                    "~&*** ~a ~
must be interpreted for assignment tracing.
    Tracing arguments and return value only."
                    name)
            (setq trace-setq nil))))
    ;;
    (if params
        (setq params (car params))      ; unwrap params
        (progn
          (format *trace-output*
                  "~&*** ~a source unavailable.
    Recursive calls may not be traced.
    Using generic parameter names.~%"
                  name)
          (when (setq params (get name 'sl::number-of-args))
            (setq params
                  (loop for i from 1 upto params collect
                        (format nil "Arg~d" i))))))
    ;;
    (pushnew name *traced-functions*)
    (if trace-setq
        (progn
          (setq defn (subst 'traced-setq 'setq defn))
          (put name 'traced-setq t))
        ;; in case function has been redefined:
        (remprop name 'traced-setq))
    (put name 'untraced-function olddefn)
    (put name 'traced-function defn)
    (eval `(defun ,name (&rest args)
             (run-traced-function ',name ',params args)))))

(defun untrace1 (name)
  "Remove all tracing for function or algebraic operator NAME.
NAME must be quoted when called!"
  (unless  (symbolp name)
    (format *trace-output*
            "~&***** ~a must be a symbol.~%" name)
    (return-from untrace1))
  ;; Check how NAME is implemented; update NAME if necessary:
  (let (defn)
    (cond ((fboundp name))              ; name OK
          ((setq defn (get name 'sl::psopfn))
           (setq name defn))
          ((setq defn (get name 'sl::simpfn))
           (setq name defn))
          (t
           (format *trace-output*
                   "~&***** ~a is not defined.~%" name)
           (return-from untrace1))))
  (let ((olddefn (get name 'untraced-function)))
    (if olddefn
        (progn
          (setf (symbol-function name) olddefn)
          (remprop name 'untraced-function)
          (remprop name 'traced-function)
          (remprop name 'traced-setq)
          (setq *traced-functions* (remove name *traced-functions*))
          name)
        (format *trace-output*
                "~&***** ~a was not traced.~%" name))))

(declaim (fixnum trace-depth))

(defvar trace-depth 0)

(defvar *trpause nil
  "If non-nil then ask whether to continue before each traced execution.
Abort with an error if the answer is no.")

(declaim (ftype (cl:function (symbol list list) function) run-traced-function))

(defun run-traced-function (name params args)
  (let ((trace-depth (1+ trace-depth))
        (result (get name 'traced-function)))
    (format *trace-output* "~&Enter (~d) ~a~%" trace-depth name)
    (if params
        (loop for param in params for arg in args do
              (format *trace-output* "   ~a:  ~s~%" param arg))
        (loop for i fixnum from 1 for arg in args do
              (format *trace-output* "   Arg~d:  ~s~%" i arg)))
    (if (and *trpause (not (y-or-n-p "Continue?")))
        (error "Tracing aborted!"))
    (setq result
          (sl::errorset `(apply ,(eval result) ',args) nil nil))
    (if (or (atom result) (cdr result)) ; errorp result
        (sl::error 0 sl::emsg*)
        (setq result (car result)))
    (format *trace-output* "~&Leave (~d) ~a = ~s~%" trace-depth name result)
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

(shadowing-import '(tr untr trst untrst) :sl)
;; The above import wipes any previous properties, so...
(sl::flag '(tr untr trst untrst) 'sl::noform)
(sl::deflist '((tr sl::rlis) (untr sl::rlis) (trst sl::rlis) (untrst sl::rlis))
    'sl::stat)

;;; trace.lisp ends here
