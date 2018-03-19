;;; eslpretty.el --- ESL version of "packages/rprint/pretty.red"

;;; Author: A. C. Norman, July 1978.

;;; Converted from REDUCE to Lisp syntax by Francis J. Wright using
;;; ESL REDUCE, then modified slightly to be independent of REDUCE so
;;; that it is available from the start of the REDUCE boot process.

(require 'esl)

(FLUID
   '(BN BUFFERI BUFFERO INDBLANKS INDENTLEVEL INITIALBLANKS LMAR PENDINGRPARS
		RMAR RPARCOUNT STACK))

(GLOBAL '(*QUOTES *PRETTY-SYMMETRIC THIN*))

(SETQ *PRETTY-SYMMETRIC t)
(SETQ *QUOTES t)
(SETQ THIN* 5)

(DE PRETTYPRINT (X) (PROGN (SUPERPRINM X (POSN)) (TERPRI) nil))

(DE SUPERPRINTM (X LMAR) (PROGN (SUPERPRINM X LMAR) (TERPRI) X))

(DE EQCAR (A B) (AND (PAIRP A) (EQ (CAR A) B)))

(DE SPACES (N)
   (PROG (I)
      (SETQ I 1)
LAB   (COND ((MINUSP (DIFFERENCE N I)) (RETURN nil)))
      (PRIN2 '\ )
      (SETQ I (PLUS2 I 1))
      (GO LAB)))

(DE SUPERPRINM (X LMAR)
   (PROG (STACK BUFFERI BUFFERO BN INITIALBLANKS RMAR PENDINGRPARS
         INDENTLEVEL INDBLANKS RPARCOUNT W)
      (SETQ BUFFERI (SETQ BUFFERO (LIST nil)))
      (SETQ INITIALBLANKS 0)
      (SETQ RPARCOUNT 0)
      (SETQ INDBLANKS 0)
      (SETQ RMAR (DIFFERENCE (LINELENGTH nil) 3))
      (COND
         ((LESSP RMAR 25)
            (ERROR
               0
               (LIST
                  (PLUS RMAR 3)
                  "Linelength too short for superprinting"))))
      (SETQ BN 0)
      (SETQ INDENTLEVEL 0)
      (COND ((>= (PLUS LMAR 20) RMAR) (SETQ LMAR (DIFFERENCE RMAR 21))))
      (SETQ W (POSN))
      (COND ((GREATERP W LMAR) (PROGN (TERPRI) (SETQ W 0))))
      (COND ((LESSP W LMAR) (SETQ INITIALBLANKS (DIFFERENCE LMAR W))))
      (PRINDENT X (PLUS LMAR 3))
      (OVERFLOW 'NONE)
      (RETURN X)))

(DE PRINDENT (X N)
   (COND
      ((ATOM X)
         (COND
            ((VECTORP X) (PRVECTOR X N))
            (t (PROG (C)
                  (SETQ C
                     (COND
                        (*PRETTY-SYMMETRIC
                           (COND ((STRINGP X) (EXPLODES X)) (t (EXPLODE X))))
                        (t (EXPLODE2 X))))
            LAB   (COND ((NULL C) (RETURN nil)))
                  ((lambda (C) (PUTCH C)) (CAR C))
                  (SETQ C (CDR C))
                  (GO LAB)))) )
      ((QUOTEP X) (PROGN (PUTCH '\') (PRINDENT (CADR X) (PLUS N 1))))
      (t (PROG (CX)
            (COND
               ((GREATERP (TIMES 4 N) (TIMES 3 RMAR))
                  (PROGN
                     (OVERFLOW 'ALL)
                     (SETQ N (QUOTIENT N 8))
                     (COND
                        ((GREATERP INITIALBLANKS N)
                           (PROGN
                              (SETQ LMAR
                                 (PLUS (DIFFERENCE LMAR INITIALBLANKS) N))
                              (SETQ INITIALBLANKS N)))) )))
            (SETQ STACK (CONS (LIST N nil 0) STACK))
            (PUTCH (CONS 'LPAR (CAR STACK)))
            (SETQ CX (CAR X))
            (PRINDENT CX (PLUS N 1))
            (COND
               ((AND (IDP CX) (NOT (ATOM (CDR X))))
                  (SETQ CX (GET CX 'PPFORMAT)))
               (t (SETQ CX nil)))
            (COND ((AND (EQUAL CX 2) (ATOM (CDDR X))) (SETQ CX nil)))
            (COND
               ((EQUAL CX 'PROG)
                  (PROGN
                     (PUTCH '\ )
                     (PRINDENT (CAR (SETQ X (CDR X))) (PLUS N 3)))) )
            (SETQ X (CDR X))
      SCAN  (COND ((ATOM X) (GO OUTT)))
            (FINISHPENDING)
            (COND
               ((EQUAL CX 'PROG)
                  (PROGN
                     (PUTBLANK)
                     (OVERFLOW BUFFERI)
                     (COND
                        ((ATOM (CAR X))
                           (PROGN
                              (SETQ LMAR
                                 (SETQ INITIALBLANKS
                                    (MAX (DIFFERENCE LMAR 6) 0)))
                              (PRINDENT (CAR X) (DIFFERENCE N 3))
                              (SETQ X (CDR X))
                              (COND
                                 ((AND (NOT (ATOM X)) (ATOM (CAR X)))
                                    (GO SCAN)))
                              (COND
                                 ((GREATERP (PLUS LMAR BN) N) (PUTBLANK))
                                 (t (PROG (I)
                                       (SETQ I (PLUS LMAR BN))
                                 LAB   (COND
                                          ((MINUSP
                                              (DIFFERENCE
                                                 (DIFFERENCE N 1)
                                                 I))
                                             (RETURN nil)))
                                       (PUTCH '\ )
                                       (SETQ I (PLUS2 I 1))
                                       (GO LAB))))
                              (COND ((ATOM X) (GO OUTT)))) ))) )
               ((NUMBERP CX)
                  (PROGN
                     (SETQ CX (DIFFERENCE CX 1))
                     (COND ((EQUAL CX 0) (SETQ CX nil)))
                     (PUTCH '\ )))
               (t (PUTBLANK)))
            (PRINDENT (CAR X) (PLUS N 3))
            (SETQ X (CDR X))
            (GO SCAN)
      OUTT  (COND
               ((NOT (NULL X))
                  (PROGN (FINISHPENDING) (PUTBLANK) (PUTCH '\.) (PUTCH '\ )
                     (PRINDENT X (PLUS N 5)))) )
            (PUTCH (CONS 'RPAR (DIFFERENCE N 3)))
            (COND
               ((AND
                   (EQUAL (CADR (CAR STACK)) 'INDENT)
                   (NOT (NULL (CDDDR (CAR STACK)))) )
                  (OVERFLOW (CAR (CDDDR (CAR STACK)))) )
               (t (ENDLIST (CAR STACK))))
            (SETQ STACK (CDR STACK)))) ))

(DE EXPLODES (X) (EXPLODE X))

(DE PRVECTOR (X N)
   (PROG (BOUND)
      (SETQ BOUND (UPBV X))
      (SETQ STACK (CONS (LIST N nil 0) STACK))
      (PUTCH (CONS 'LSQUARE (CAR STACK)))
      (PRINDENT (GETV X 0) (PLUS N 3))
      (PROG (I)
         (SETQ I 1)
   LAB   (COND ((MINUSP (DIFFERENCE BOUND I)) (RETURN nil)))
         (PROGN (PUTCH '\,) (PUTBLANK) (PRINDENT (GETV X I) (PLUS N 3)))
         (SETQ I (PLUS2 I 1))
         (GO LAB))
      (PUTCH (CONS 'RSQUARE (DIFFERENCE N 3)))
      (ENDLIST (CAR STACK))
      (SETQ STACK (CDR STACK))))

(DE PUTBLANK nil
   (PROG nil
      (PUTCH (CAR STACK))
      (RPLACA (CDDR (CAR STACK)) (PLUS (CADDR (CAR STACK)) 1))
      (RPLACD (CDDR (CAR STACK)) (CONS BUFFERI (CDDDR (CAR STACK))))
      (SETQ INDBLANKS (PLUS INDBLANKS 1))))

(DE ENDLIST (L) (SETQ PENDINGRPARS (CONS L PENDINGRPARS)))

(DE FINISHPENDING nil
   (PROGN
      (PROG (STACKFRAME)
         (SETQ STACKFRAME PENDINGRPARS)
   LAB   (COND ((NULL STACKFRAME) (RETURN nil)))
         ((lambda (STACKFRAME)
             (PROGN
                (COND
                   ((not (equal (CADR STACKFRAME) 'INDENT))
                      (PROG (B)
                         (SETQ B (CDDDR STACKFRAME))
                   LAB   (COND ((NULL B) (RETURN nil)))
                         ((lambda (B)
                             (PROGN
                                (RPLACA B '\ )
                                (SETQ INDBLANKS (DIFFERENCE INDBLANKS 1))))
                            (CAR B))
                         (SETQ B (CDR B))
                         (GO LAB))))
                (RPLACD (CDDR STACKFRAME) t)))
            (CAR STACKFRAME))
         (SETQ STACKFRAME (CDR STACKFRAME))
         (GO LAB))
      (SETQ PENDINGRPARS nil)))

(DE QUOTEP (X)
   (AND *QUOTES (NOT (ATOM X)) (EQUAL (CAR X) 'QUOTE) (NOT (ATOM (CDR X)))
		(NULL (CDDR X))))

(PUT 'PROG 'PPFORMAT 'PROG)
(PUT 'lambda 'PPFORMAT 1)
(PUT 'LAMBDAQ 'PPFORMAT 1)
(PUT 'SETQ 'PPFORMAT 1)
(PUT 'SET 'PPFORMAT 1)
(PUT 'WHILE 'PPFORMAT 1)
(PUT 't 'PPFORMAT 1)
(PUT 'DE 'PPFORMAT 2)
(PUT 'DF 'PPFORMAT 2)
(PUT 'DM 'PPFORMAT 2)
(PUT 'FOREACH 'PPFORMAT 4)

(DE PUTCH (C)
   (PROG nil
      (COND
         ((ATOM C) (SETQ RPARCOUNT 0))
         ((NUMBERP (CAR C)) (PROGN (SETQ RPARCOUNT 0) (GO NOCHECK)))
         ((EQUAL (CAR C) 'RPAR)
            (PROGN
               (SETQ RPARCOUNT (PLUS RPARCOUNT 1))
               (COND
                  ((GREATERP RPARCOUNT 4)
                     (PROGN (PUTCH '\ ) (SETQ RPARCOUNT 2)))) ))
         (t (SETQ RPARCOUNT 0)))
      (PROG nil
   LAB   (COND ((NOT (>= (PLUS LMAR BN) RMAR)) (RETURN nil)))
         (OVERFLOW 'MORE)
         (GO LAB))
NOCHECK
      (SETQ BUFFERI (CDR (RPLACD BUFFERI (LIST C))))
      (SETQ BN (PLUS BN 1))))

(DE OVERFLOW (FLG)
   (PROG (C BLANKSTOSKIP)
      (COND
         ((AND
             (EQUAL INDBLANKS 0)
             (GREATERP INITIALBLANKS 3)
             (EQUAL FLG 'MORE))
            (PROGN
               (SETQ INITIALBLANKS (DIFFERENCE INITIALBLANKS 3))
               (SETQ LMAR (DIFFERENCE LMAR 3))
               (RETURN 'MOVED-LEFT))))
FBLANK(COND
         ((EQUAL BN 0)
            (PROGN
               (COND ((NOT (EQUAL FLG 'MORE)) (RETURN 'EMPTY)))
               (COND ((ATOM (CAR BUFFERO)) (PRIN2 "%+")))
               (TERPRI)
               (SETQ LMAR 0)
               (RETURN 'CONTINUED)))
         (t (PROGN (SPACES INITIALBLANKS) (SETQ INITIALBLANKS 0))))
      (SETQ BUFFERO (CDR BUFFERO))
      (SETQ BN (DIFFERENCE BN 1))
      (SETQ LMAR (PLUS LMAR 1))
      (SETQ C (CAR BUFFERO))
      (COND
         ((ATOM C) (PROGN (PRIN2 C) (GO FBLANK)))
         ((NUMBERP (CAR C))
            (COND
               ((NOT (ATOM BLANKSTOSKIP))
                  (PROGN
                     (PRIN2 '\ )
                     (SETQ INDBLANKS (DIFFERENCE INDBLANKS 1))
                     (COND
                        ((EQ C (CAR BLANKSTOSKIP))
                           (PROGN
                              (RPLACD
                                 BLANKSTOSKIP
                                 (DIFFERENCE (CDR BLANKSTOSKIP) 1))
                              (COND
                                 ((EQUAL (CDR BLANKSTOSKIP) 0)
                                    (SETQ BLANKSTOSKIP t)))) ))
                     (GO FBLANK)))
               (t (GO BLANKFOUND))))
         ((OR (EQUAL (CAR C) 'LPAR) (EQUAL (CAR C) 'LSQUARE))
            (PROGN
               (PRIN2 (GET (CAR C) 'PPCHAR))
               (COND ((EQUAL FLG 'NONE) (GO FBLANK)))
               (SETQ C (CDR C))
               (COND ((NOT (NULL (CDDDR C))) (GO FBLANK)))
               (COND
                  ((GREATERP (CAR C) INDENTLEVEL)
                     (PROGN
                        (SETQ INDENTLEVEL (CAR C))
                        (RPLACA (CDR C) 'INDENT))))
               (GO FBLANK)))
         ((OR (EQUAL (CAR C) 'RPAR) (EQUAL (CAR C) 'RSQUARE))
            (PROGN
               (COND
                  ((LESSP (CDR C) INDENTLEVEL) (SETQ INDENTLEVEL (CDR C))))
               (PRIN2 (GET (CAR C) 'PPCHAR))
               (GO FBLANK)))
         (t (ERROR 0 (LIST C "UNKNOWN TAG IN OVERFLOW"))))
BLANKFOUND
      (COND ((EQCAR (CDDDR C) BUFFERO) (RPLACD (CDDR C) nil)))
      (SETQ INDBLANKS (DIFFERENCE INDBLANKS 1))
      (COND
         ((GREATERP (CAR C) INDENTLEVEL)
            (PROGN
               (COND ((EQUAL FLG 'NONE) (PROGN (PRIN2 '\ ) (GO FBLANK))))
               (COND
                  (BLANKSTOSKIP (SETQ BLANKSTOSKIP nil))
                  (t (PROGN
                        (SETQ INDENTLEVEL (CAR C))
                        (RPLACA (CDR C) 'INDENT)))) )))
      (COND
         ((GREATERP (CADDR C) (DIFFERENCE THIN* 1))
            (PROGN
               (SETQ BLANKSTOSKIP (CONS C (DIFFERENCE (CADDR C) 2)))
               (RPLACA (CDR C) 'THIN)
               (RPLACA (CDDR C) 1)
               (SETQ INDENTLEVEL (DIFFERENCE (CAR C) 1))
               (PRIN2 '\ )
               (GO FBLANK))))
      (RPLACA (CDDR C) (DIFFERENCE (CADDR C) 1))
      (TERPRI)
      (SETQ LMAR (SETQ INITIALBLANKS (CAR C)))
      (COND ((EQ BUFFERO FLG) (RETURN 'TO-FLG)))
      (COND ((OR BLANKSTOSKIP (NOT (EQUAL FLG 'MORE))) (GO FBLANK)))
      (RETURN 'MORE)))

(PUT 'LPAR 'PPCHAR '\()
(PUT 'LSQUARE 'PPCHAR '\[)
(PUT 'RPAR 'PPCHAR '\))
(PUT 'RSQUARE 'PPCHAR '\])

(provide 'eslpretty)

;;; eslpretty.el ends here
