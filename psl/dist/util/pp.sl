%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:PP.SL 
% Description:  Prettyprinter 
% Author:       Douglas Lanam, Hewlett-Packard CRC 
% Created:      
% Modified:     
% Status:       Open Source: BSD License
% Mode:         Lisp 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% PP( LST:list )                        MACRO
% PRETTYPRINT( X:any )                  EXPR
%
%       Revision History:
%
%
%%	November 9, 1983: Douglas
%%		Added copyright notice.  Removed a check to see if we
%%		are in frl syntax (since this is obsolete).
%%	November 2, 1983: Douglas
%%		Added default values for *pp-midway-column* and 
%%		*pp-printing-level*.  Also added declaration to turn
%%		on fast-integers.
%%
%%	September 23, 1983: Douglas
%%		Modified pp to handle (linelength) better.
%%		Removed many unused (and internal) functions.
%%
%       April 18, 1983: Douglas Lanam
%               Modified compiletime to bothtimes,
%               Added a feature to print "defmacro" forms
%               back with the "defmacro" form instead of
%               "dm".
%
%       April 4, 1983: Douglas
%               Take the words "cond" and "lambda" out of strings
%               so that they are not printed in the wrong case.
%
%       March 17, 1983: Douglas
%               Patched bug introduced tuesday in let clause.
%       
%       March 15, 1983: Douglas
%               Modularized code for linear vertical lists.
%               Modified and simplified 
%               special code for cond, do, do*, let, and let*.
%
%       March 10, 1983: Douglas
%               Added dn to lists of functions specially printed.
%               (same as definitions of de,df,dm).  Added a terpri
%               after printing function definitions.
%
%       March 8, 1983: Douglas
%               Added a special feature to prettyprint lambda expression
%               in a more readable fashion.  Added a line to load useful
%               when compiling.
%       
%       March 3, 1983: Douglas
%               Added line to load fast-int when compiling.
%
%       Feb. 23, 1983 Douglas
%               Seperated the testing of specially treated test functions
%               and the printing of these special test functions to 
%               eliminate a recursion problem with special forms in
%               the cdr slot.
%
%       Feb. 10, 1983 Douglas
%         Fixed a bug where special list structures in the cdr position
%         were not handled correctly.
%         Also removed calls to the function "add" since this is not
%         a basic psl function.  Replaced them with "plus".
%
%       Feb. 8, 1983 Douglas
%         Fix of many numerous small bugs and some clean up of code.
%
%       Feb. 5, 1983 Martin L Griss
%         Changed the nflatsize1 definition line to correct parens.
%
%       Dec. 14, 1982 Douglas
%         Fixed bug with sprint-prog and sprint-lamdba, so that it
%         gets the correct left-margin for sub-expression.
%
%       Dec. 13, 1982 Douglas 
%         Removal of old code that put properties on 'de','df','dm',
%         than messed up prettyprint on expressions with that atom
%         in the car of the expression.  Also handles prinlevel, and
%         prinlength.
%         Fix bug with '(quote x y).  Taught system about labels in
%         progs and dos.  Taught system about special forms: do,let,
%         de, df, dm, defmacro, and cond.
%
%       November 1982 Douglas
%         Rewritten to be more compact, more modular,
%         and handle vectors.
%
% <BENSON>YPP.SL.19, 17-Sep-82 09:52:42, Edit by BENSON
% Courtesy of IMSSS, with modifications for PSL
%
%

(bothtimes
  (load useful fast-int))

(compiletime
  (on fast-integers))

(COMPILETIME
     (FLAG '(PP-VAL PP-DEF BROKEN GET-GOOD-DEF
             sprint-dtpr sprint-vector sprint-read-macro
             read-macro-internal-sprint is-read-macrop handle-read-macros
             handle-special-list-structures nflatsize1)
           'INTERNALFUNCTION))

(compiletime
  (fluid '(prinlength prinlevel sprint-level)))

(setq sprint-level 0)

(de pp-warning (x) 
  (let ((out* errout*))
       (princ "%%") (terpri)
       (princ "%%") (printf " %l\n" x)
       (princ "%%") (terpri)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Top level prettyprint functions.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Change the system prettyprint function to use this one.
%%
(de prettyprint (x) (progn (sprint x (posn)) (terpri)))

(df pp (l) (mapc l 'pp1))

(de pp1 (exp)
  (cond ((idp exp) (pp-val exp)
                   (pp-def exp))
        (t (sprint exp 1)
           (terpri))))

(de pp-val (id)
  (cond ((boundp id)
         (terpri)
         (sprint `(setq ,id ',(eval id)) (posn))
         (terpri))))

(DE PP-DEF (ID)
  (PROG (DEF TYPE ORIG-DEF)
        (SETQ DEF (GETD ID))
        TEST 
        (COND ((NULL DEF)
               (cond (ORIG-DEF
                      (pp-WARNING (LIST ID " has no unbroken definition."))))
               (return nil))
              ((CODEP (CDR DEF))
               (pp-WARNING 
                (LIST "Can't prettyprint compiled definition for" ID))
               (return nil))
              ((AND (NOT ORIG-DEF) (BROKEN ID))
               (PROGN (pp-WARNING (LIST "Note:" ID "is broken or traced."))
                      (SETQ ORIG-DEF DEF)
                      (SETQ DEF (CONS (CAR DEF) (GET-GOOD-DEF ID)))
                      (GO TEST))))
        (SETQ TYPE (CAR DEF))
        (TERPRI)
        %;;
        %;; Special case so that things defined with 
        %;; defmacro print out with defmacro.
        %;; defmacro expands into a defmacro-lambda form
        %;; which is a macro that expands into ((lambda ...) ..).
        %;;
        (cond ((eq (caar (cdddr def)) 'defun-lambda)
               (let ((x (cdar (cdddr def))))
                    (let* ((args (cadr (cddr x)))
                           (body (cadr x)))
                          (sprint `(,(cond ((eq type 'macro) 'defmacro)
                                           (t 'defun))
                                     ,id ,args . ,body)
                                  (posn)))))
              ((and (getd 'defun)
                    %;;
                    %;; Only on expr's for now.
                    %;; Must integrate hprl defun/defmacro into psl.
                    %;;
                    (eq type 'expr))
               (sprint (cons 'defun
                             (cons id
                                   (cond ((eq type 'expr) (cddr def))
                                         (t (cons type (cddr def))))))
                       (posn)))
              (t (sprint (cons (cond ((eq type 'expr) 'de)
                                     ((eq type 'macro) 'dm)
                                     ((eq type 'fexpr) 'df)
                                     ((eq type 'nexpr) 'dn))
                               (cons id (cddr def)))
                         (posn))))
        (terpri)))

(DE BROKEN (X) (GET X 'TRACE))

(DE GET-GOOD-DEF (X)
 (PROG (XX)
       (COND ((AND (SETQ XX (GET X 'TRACE))
                   (SETQ XX (ASSOC 'ORIGINALFN XX)))
              (RETURN (CDR XX))))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Functions that decide if there is enough space on the current line.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% *pp-line-length* is the length of the line allowed inside the 
%%      prettyprinter.
%%
%% This is set by pp by checking (linelength nil).
%%
%% *pp-midway-column* : The point at which things should move down instead
%%      of across.
%%
%% *pp-nesting-level* : The number of levels that is considered deep in the
%%      prettyprinter.
%%
%% Set default values for these variables.
%%
(cond ((null (boundp '*pp-line-length*))
       (setq *pp-line-length* 80)))
%%
%% Set default values for these variables.
%%
(cond ((null (boundp '*pp-midway-column*))
       (setq *pp-midway-column* 40)))
%%
%% Set default values for these variables.
%%
(cond ((null (boundp '*pp-nesting-level*))
       (setq *pp-nesting-level* 20)))
%%
%% Because psl will set fluid's to nil, we must set the default first,
%%	then declare them fluid.
%%
(fluid '(*pp-line-length* *pp-midway-column* *pp-nesting-level*))
%%
(de make-room-for (left-margin size flag)
  (cond ((or (greaterp (add1 size) 
		       (difference *pp-line-length* (posn)))
             (lessp (add1 (posn)) left-margin))
         (tab left-margin))))

(de is-read-macrop (exp)
  (and (pairp exp) (atom (car exp)) (pairp (cdr exp)) (null (cddr exp))
       (get (car exp) 'printmacro)))

(de read-macro-internal-sprint (read-macro-c a lm1)
  (make-room-for lm1 (plus2 (flatsize2 read-macro-c) (nflatsize a))
                 (or (pairp a) (vectorp a)))
  (princ read-macro-c)
  (internal-sprint a (plus2 (flatsize2 read-macro-c) lm1)))

(de sprint-read-macro (exp left-margin)
  (let ((c (get (car exp) 'printmacro)))
       (read-macro-internal-sprint c (cadr exp) left-margin)))

(de handle-read-macros (exp left-margin)
  (prog (c)
        (cond ((and (pairp exp)
                    (atom (car exp))
                    (pairp (cdr exp))
                    (null (cddr exp))
                    (setq c (get (car exp) 'printmacro)))
               (read-macro-internal-sprint c (cadr exp) left-margin)
               (return t)))))

(dm define-special-sprint-list-structure (x)
  ((lambda (tag test-if-special sprint-function)
           `(progn (put ',tag 'sprint-test ',test-if-special)
                   (put ',tag 'sprint-function ',sprint-function)))
   (cadr x)
   (caddr x)
   (cadr (cddr x))))

(de handle-special-list-structures (exp left-margin)
  (prog (c test)
        (cond ((pairp exp)
               (cond ((idp (car exp))
                      (setq test (get (car exp) 'sprint-test))
                      (setq c (get (car exp) 'sprint-function))
                      (cond ((and (or (null test)
                                      (apply test (list exp)))
                                  c)
                             (apply c (list exp left-margin))
                             (return t))))
                     ((and (pairp (car exp))
                           (eq (caar exp) 'lambda))
                      (special-sprint-lambda-expression exp left-margin)
                      (return t)))))))

(de handle-special-list-structures-in-cdr-slot (exp left-margin)
  (prog (c test)
        (cond ((and (pairp exp)
                    (atom (car exp)))
               (setq test (get (car exp) 'sprint-test))
               (setq c (get (car exp) 'sprint-function))
               (cond ((and (or (null test)
                               (apply test (list exp)))
                           c)
                      (princ ". ")
                      (apply c (list exp left-margin))
                      (return t)))))))

(define-special-sprint-list-structure lambda sprint-lambda-test sprint-lambda)
(define-special-sprint-list-structure cond sprint-cond-test sprint-cond)
(define-special-sprint-list-structure progn sprint-lambda-test sprint-lambda)
(define-special-sprint-list-structure prog1 sprint-lambda-test sprint-lambda)
(define-special-sprint-list-structure let sprint-let-test sprint-let)
(define-special-sprint-list-structure let* sprint-let-test sprint-let)
(define-special-sprint-list-structure defun sprint-defun-test sprint-defun)
(define-special-sprint-list-structure do sprint-do-test sprint-do)
(define-special-sprint-list-structure do* sprint-do-test sprint-do)
(define-special-sprint-list-structure prog sprint-prog-test sprint-prog)
(define-special-sprint-list-structure de sprint-defun-test sprint-defun)
(define-special-sprint-list-structure df sprint-defun-test sprint-defun)
(define-special-sprint-list-structure dn sprint-defun-test sprint-defun)
(define-special-sprint-list-structure dm sprint-defun-test sprint-defun)
(define-special-sprint-list-structure defmacro sprint-defun-test sprint-defun)

(de sprint-cond-test (exp)
  (and (pairp (cdr exp))
       (pairp (cdr exp))))

(de sprint-cond (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") (princ 'cond) (princ " ") %)
  (sprint-rest-of-vertical-list (cdr exp) (posn)))

(de sprint-defun-test (exp)
  (and (pairp (cdr exp))
       (pairp (cddr exp))))

(de sprint-defun (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") %)
  (let ((a (plus2 1 (posn))))
       (princ (car exp)) (princ " ")
       (internal-sprint (cadr exp) (posn)) (princ " ")
       (internal-sprint (caddr exp) a)
       (sprint-rest-of-vertical-list (cdddr exp) a)))

(defun sprint-rest-of-vertical-list (list left-margin)
  (do ((i list (cdr i)))
      ((null i)  %(
                   (princ ")"))
      (tab left-margin)
      (cond ((atom i)
             (princ ". ") (internal-sprint i (plus2 2 left-margin))
             %(
               (princ ")")
             (return nil))
            ((is-read-macrop i)
             (make-room-for left-margin (plus2 2 (nflatsize i)) nil)
             (princ ". ")
             (sprint-read-macro i left-margin)
             %(
               (princ ")")
             (return nil))
            (t (internal-sprint (car i) left-margin)))))

(de special-sprint-lambda-expression (exp left-margin)
  (princ "((") (princ 'lambda)(princ " ") %))
  (let ((a (posn)))
       (sprint-rest-of-vertical-list (cdar exp) a)
       (sprint-rest-of-vertical-list (cdr exp) (plus2 left-margin 1))))

(de sprint-prog-test (exp)
  (and (pairp (cdr exp))
       (pairp (cddr exp))))

(de sprint-prog (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") %)
  (let ((b (posn))
        (a (plus2 1 (plus2 (posn) (flatsize (car exp))))))
       (princ (car exp)) (princ " ")
       (internal-sprint (cadr exp) a)
       (sprint-rest-of-prog-vertical-list (cddr exp) a b)))

(de sprint-let-test (exp)
  (and (pairp (cdr exp))
       (pairp (cadr exp))))

(de sprint-let (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") %)
  (princ (car exp))
  (princ " (") %)
  (let ((b (posn)))
       (sprint-rest-of-vertical-list (cadr exp) b)
       (let ((c (idifference b 1)))
            (tab c)
            (sprint-rest-of-vertical-list (cddr exp) c))))

(de sprint-do-test (exp)
  (and (pairp exp)
       (pairp (cdr exp))
       (pairp (cadr exp))
       (pairp (cddr exp))
       (pairp (caddr exp))
       (pairp (cdddr exp))))

(de sprint-do (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") %)
  (princ (car exp))
  (princ " (") %)
  (let ((b (posn)))
       (sprint-rest-of-vertical-list (cadr exp) b)
       (let ((c (idifference b 1)))
            (tab c)
            (princ "(") %)
            (sprint-rest-of-vertical-list (caddr exp) b)
            (sprint-rest-of-prog-vertical-list (cdddr exp) c
                                               (idifference b 3)))))

(de sprint-rest-of-prog-vertical-list (exp a b)
  (do ((i exp (cdr i)))
      ((null i)  %(
                   (princ ")"))
      (tab b)
      (cond ((atom i)
             (princ ". ") (internal-sprint i (plus2 2 a) )
             %(
               (princ ")")
             (return nil))
            ((is-read-macrop i)
             (make-room-for a (plus2 2 (nflatsize i)) nil)
             (princ ". ")
             (sprint-read-macro i a)
             %(
               (princ ")")
             (return nil))
            ((atom (car i))
             (internal-sprint (car i) b))
            (t (internal-sprint (car i) a)))))

(de sprint-lambda-test (exp)
  (and (cdr exp)
       (pairp (cdr exp))))

(de sprint-lambda (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (princ "(") %)
  (princ (car exp)) (princ " ")
  (let ((a (posn)))
       (internal-sprint (cadr exp) a)
       (sprint-rest-of-vertical-list (cddr exp) a)))

(de depth-greater-than-n (l n)
  (cond ((weq n 0) t)
        ((pairp l)
         (do ((i l (cdr i)))
             ((null i))
             (cond ((atom i) (return nil))
                   ((and (pairp i)
                         (depth-greater-than-n (car i) (sub1 n)))
                    (return t)))))))

(de sprint-dtpr2 (exp left-margin)
  (make-room-for left-margin (nflatsize exp) nil)
  (prog (lm)
        (princ "(") %)
        (setq lm (plus2 1 (cond ((and (atom (car exp))
                                      (null (vectorp (car exp)))
                                      (lessp (plus2 (posn)
                                                    (nflatsize
                                                     (car exp)))
                                             *pp-midway-column*)
                                      (null (depth-greater-than-n
                                             exp 
                                             *pp-nesting-level*)))
                                 (plus2 1 (plus2 left-margin
                                                 (nflatsize
                                                  (car exp)))))
                                (t left-margin))))
        (do ((a exp (cdr a))
             (i 1 (add1 i))
             (l (add1 left-margin) lm))
            ((null a)   % (
                           (princ ")"))
            (cond ((and (numberp prinlength)
                        (greaterp i prinlength))
                   % (
                      (princ "...)")
                   (return nil)))
            (cond ((atom a) 
                   (make-room-for l (plus2 2 (nflatsize a)) nil)
                   (princ ". ") (internal-sprint a l) 
                   %(
                     (princ ")")
                   (return nil))
                  ((is-read-macrop a)
                   (princ ". ")
                   (sprint-read-macro a (plus2 l 2))
                   %(
                     (princ ")")
                   (return nil))
                  ((handle-special-list-structures-in-cdr-slot a left-margin)
                   %(
                     (princ ")")
                   (return nil))
                  (t (internal-sprint (car a) l)))
            (cond ((cdr a) 
                   (cond ((greaterp (nflatsize (car a))
                                    (difference *pp-line-length* l))
                          (tab l))
                         (t (princ " "))))))))

(de sprint-dtpr (exp left-margin)
  ((lambda
    (sprint-level)
    (cond ((and (numberp prinlevel)
                (greaterp sprint-level prinlevel))
           (princ "#"))
          ((handle-read-macros exp left-margin))
          ((handle-special-list-structures exp left-margin))
          (t (sprint-dtpr2 exp left-margin))))
   (add1 sprint-level)))

(de sprint-vector (vector left-margin)
  ((lambda
    (sprint-level)
    (cond ((and (Numberp prinlevel)
                (greaterp sprint-level prinlevel))
           (princ "#"))
          (t
           (prog (c)
                 (princ "[")
                 (let ((lm (add1 left-margin)))
                      (do ((i 0 (1+ i))
                           (size (size vector)))
                          ((greaterp i size) (princ "]"))
                          (cond ((and (numberp prinlength)
                                      (greaterp i prinlength))
                                 (princ "...]")
                                 (return nil)))
                          (internal-sprint (getv vector i) lm)
                          (cond ((lessp i size)
                                 (cond ((greaterp (nflatsize (getv vector 
                                                                   (plus2 i 1)))
                                                  (difference *pp-line-length*
                                                              lm))
                                        (tab lm))
                                       ((lessp (posn) lm)
                                        (tab lm))
                                       (t (princ " ")))))))))))
   (add1 sprint-level)))

(de internal-sprint (a lm)
  (cond ((lessp (posn) lm)
         (tab lm)))
  (cond ((handle-read-macros a lm))
        ((handle-special-list-structures a lm))
        (t (make-room-for lm (nflatsize a) 
                          (or (pairp a) (vectorp a)))
           (cond ((pairp a) (sprint-dtpr a (posn)))
                 ((vectorp a) (sprint-vector a (posn)))
                 (t (cond ((lessp (posn) lm)
                           (tab lm)))
                    (prin1 a))))))

(de sprint (exp left-margin)
  (let ((a (posn))
        (sprint-level 0)
        (b (linelength nil)))
       (unwind-protect (progn (linelength 0)
                              (setq *pp-line-length*
                                    (cond ((< b 10) 1000)
                                          (t (- b 5))))
                              (setq *pp-midway-column* 
                                    (quotient *pp-line-length* 3))
                              (setq *pp-nesting-level*
                                    (quotient *pp-line-length* 5))
                              (cond ((eq a left-margin))
                                    (t (tab left-margin)))
                              (internal-sprint exp left-margin))
                       (linelength b))
       nil))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Prettyprint information for the quote and backquote.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
(put 'quote 'printmacro "'")
(put 'backquote 'printmacro "`")
(put 'unquote 'printmacro ",")
(put 'unquotel 'printmacro ",@")
(put 'unquoted 'printmacro ",.")
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Functions to measure the printing size needed for an lisp object.
%%      Checks the prinlevel and prinlength variables.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
(de nflatsize (n) (nflatsize1 n sprint-level))

(de nflatsize1 (n currentlevel)
  (cond ((and (numberp prinlevel)
              (wgreaterp currentlevel prinlevel)) 1)
        ((vectorp n)
         (do ((i (size n) (sub1 i))
              (s (iplus2 1 (size n))
                 (iplus2 1 (iplus2 s 
                                   (nflatsize1 (getv n i)
                                               (iplus2 1 currentlevel))))))
             ((wlessp i 0) s)))
        ((atom n) (flatsize n))
        ((is-read-macrop n)
         (let ((c (get (car n) 'printmacro)))
              (iplus2 (flatsize2 c) 
                      (nflatsize1 (cadr n) (iplus2 1 currentlevel)))))
        ((do ((i n (cdr i))
              (s 1 (iplus2 (nflatsize1 (car i) (iplus2 1 currentlevel))
                           (iplus2 1 s))))
             ((null i) s)
             (cond ((atom i)
                    (return (iplus2 3 (iplus2 s (nflatsize1
                                                 i (iplus2 1 currentlevel))))))
                   ((is-read-macrop i)
                    (return
                     (iplus2 3
                             (iplus2 s (nflatsize1
                                        i (iplus2 1 currentlevel)))))))))))

%***************************************************************************
%
% End of Prettyprinter.
%
%***************************************************************************
