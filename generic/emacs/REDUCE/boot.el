;;; bool.el --- ESL (Emacs Standard LISP) version of REDUCE 3.3 "boot.red"

;; Edited by FJW to use upper case and Emacs Lisp syntax, i.e. replace
;; ! used as an escape by \. However, nil and t are retained because
;; nil at least is required in some contexts rather than NIL, either
;; by the syntax or in quoted expressions, and the second !  in !!
;; must be retained.

(require 'sl)

;; For the Emacs Lisp compiler:
(defvar CURSYM\*)
(defvar OLDCHAN\*)
(defvar TTYPE\*)
(defvar NXTSYM\*)
(defvar CRCHAR\*)
(defvar \*MODE)
(defvar FNAME\*)

;;;% Standard LISP equivalent of BOOT.RED.

(FLUID '(\*BLOCKP \*MODE))

(GLOBAL '(OLDCHAN\*))

(GLOBAL '(CRCHAR\* CURSYM\* FNAME\* NXTSYM\* TTYPE\* \$EOL\$))

(PUT '\; 'SWITCH\* '(nil \*SEMICOL\*))

(PUT '\( 'SWITCH\* '(nil \*LPAR\*))

(PUT '\) 'SWITCH\* '(nil \*RPAR\*))

(PUT '\, 'SWITCH\* '(nil \*COMMA\*))

(PUT '\. 'SWITCH\* '(nil CONS))

(PUT '\: 'SWITCH\* '(((\= nil SETQ)) \*COLON\*))

(PUT '\*COMMA\* 'INFIX 1)

(PUT 'SETQ 'INFIX 2)

(PUT 'CONS 'INFIX 3)

(FLAG '(\*COMMA\*) 'NARY)

(FLAG '(\*COLON\* \*SEMICOL\* END THEN ELSE) 'DELIM)

(PUT 'BEGIN 'STAT 'BLOCKSTAT)

(PUT 'IF 'STAT 'IFSTAT)

(PUT 'SYMBOLIC 'STAT 'PROCSTAT)

(DE BEGIN2 nil
   (PROG nil
      (SETQ CURSYM\* '\*SEMICOL\*)
A     (COND
         ((EQ CURSYM\* 'END) (PROGN (CLOSE (RDS OLDCHAN\*)) (RETURN nil)))
         (t (PRIN2 (ERRORSET '(EVAL (FORM (XREAD nil))) t t)) ))
      (GO A)))

(DE FORM (U) U)

(DE XREAD (U) (PROGN (SCAN) (XREAD1 U)))

(DE XREAD1 (U)
   (PROG (V W X Y Z Z2)
A     (SETQ Z CURSYM\*)
A1    (COND
         ((OR (NULL (ATOM Z)) (NUMBERP Z)) (SETQ Y nil))
         ((FLAGP Z 'DELIM) (GO END1))
         ((EQ Z '\*LPAR\*) (GO LPAREN))
         ((EQ Z '\*RPAR\*) (GO END1))
         ((SETQ Y (GET Z 'INFIX)) (GO INFX))
         ((SETQ Y (GET Z 'STAT)) (GO STAT)))
A3    (SETQ W (CONS Z W))
NEXT  (SETQ Z (SCAN))
      (GO A1)
LPAREN(SETQ Y nil)
      (COND
         ((EQ (SCAN) '\*RPAR\*)
            (AND W (SETQ W (CONS (LIST (CAR W)) (CDR W)))) )
         ((EQCAR (SETQ Z (XREAD1 'PAREN)) '\*COMMA\*)
            (SETQ W (CONS (CONS (CAR W) (CDR Z)) (CDR W))))
         (t (GO A3)))
      (GO NEXT)
INFX  (SETQ Z2 (MKVAR (CAR W) Z))
UN1   (SETQ W (CDR W))
      (COND
         ((NULL W) (GO UN2))
         (t (SETQ Z2 (CONS (CAR W) (LIST Z2)))) )
      (GO UN1)
UN2   (SETQ V (CONS Z2 V))
PRECED(COND ((NULL X) (GO PR4)) ((LESSP Y (CAR (CAR X))) (GO PR2)))
PR1   (SETQ X (CONS (CONS Y Z) X))
      (GO NEXT)
PR2   (SETQ V
         (CONS
            (COND
               ((AND (EQCAR (CAR V) (CDAR X)) (FLAGP (CDAR X) 'NARY))
                  (CONS (CDAR X) (CONS (CADR V) (CDAR V))))
               (t (CONS (CDAR X) (LIST (CADR V) (CAR V)))) )
            (CDR (CDR V))))
      (SETQ X (CDR X))
      (GO PRECED)
STAT  (SETQ W (CONS (EVAL (LIST Y)) W))
      (SETQ Y nil)
      (GO A)
END1  (COND
         ((AND (AND (NULL V) (NULL W)) (NULL X)) (RETURN nil))
         (t (SETQ Y 0)))
      (GO INFX)
PR4   (COND ((NULL (EQUAL Y 0)) (GO PR1)) (t (RETURN (CAR V)))) ))

(DE EQCAR (U V) (AND (NULL (ATOM U)) (EQ (CAR U) V)))

(DE MKSETQ (U V) (LIST 'SETQ U V))

(DE MKVAR (U V) U)

(DE RREAD nil
   (PROG (X)
      (SETQ X (TOKEN))
      (RETURN
         (COND
            ((AND (EQUAL TTYPE\* 3) (EQ X '\()) (RRDLS))
            (t X)))) )

(DE RRDLS nil
   (PROG (X)
      (SETQ X (RREAD))
      (COND
         ((NULL (EQUAL TTYPE\* 3)) (GO A))
         ((EQ X '\)) (RETURN nil))
         ((NULL (EQ X '\.)) (GO A)))
      (SETQ X (RREAD))
      (TOKEN)
      (RETURN X)
A     (RETURN (CONS X (RRDLS)))) )

(DE TOKEN nil
   (PROG (X Y)
      (SETQ X CRCHAR\*)
A     (COND
         ((SEPRP X) (GO SEPR))
         ((DIGIT X) (GO NUMBER))
         ((LITER X) (GO LETTER))
         ((EQ X '\%) (GO COMENT))
         ((EQ X '\!) (GO ESCAPE))
         ((EQ X '\') (GO QUOTE))
         ((EQ X '\") (GO STRING)))
      (SETQ TTYPE\* 3)
      (COND ((DELCP X) (GO D)))
      (SETQ NXTSYM\* X)
A1    (SETQ CRCHAR\* (READCH))
      (GO C)
ESCAPE(SETQ Y (CONS X Y))
      (SETQ X (READCH))
LETTER(SETQ TTYPE\* 0)
LET1  (SETQ Y (CONS X Y))
      (COND
         ((OR (DIGIT (SETQ X (READCH))) (LITER X)) (GO LET1))
         ((EQ X '\!) (GO ESCAPE)))
      (SETQ NXTSYM\* (INTERN (COMPRESS (REVERSE Y))))
B     (SETQ CRCHAR\* X)
C     (RETURN NXTSYM\*)
NUMBER(SETQ TTYPE\* 2)
NUM1  (SETQ Y (CONS X Y))
      (COND ((DIGIT (SETQ X (READCH))) (GO NUM1)))
      (SETQ NXTSYM\* (COMPRESS (REVERSE Y)))
      (GO B)
QUOTE (SETQ CRCHAR\* (READCH))
      (SETQ NXTSYM\* (LIST 'QUOTE (RREAD)))
      (SETQ TTYPE\* 4)
      (GO C)
STRING(PROG (RAISE)
         (SETQ RAISE \*RAISE)
         (SETQ \*RAISE nil)
   STRINX(SETQ Y (CONS X Y))
         (COND ((NULL (EQ (SETQ X (READCH)) '\")) (GO STRINX)))
         (SETQ Y (CONS X Y))
         (SETQ NXTSYM\* (MKSTRNG (COMPRESS (REVERSE Y))))
         (SETQ \*RAISE RAISE))
      (SETQ TTYPE\* 1)
      (GO A1)
COMENT(COND ((NULL (EQ (READCH) \$EOL\$)) (GO COMENT)))
SEPR  (SETQ X (READCH))
      (GO A)
D     (SETQ NXTSYM\* X)
      (SETQ CRCHAR\* '\ )
      (GO C)))

(SETQ CRCHAR\* '\ )

(DE DELCP (U) (OR (EQ U '\;) (EQ U '\$)))

(DE MKSTRNG (U) U)

(DE SEPRP (U) (OR (EQ U '\ ) (EQ U \$EOL\$)))

(DE SCAN nil
   (PROG (X Y)
      (COND ((NULL (EQ CURSYM\* '\*SEMICOL\*)) (GO B)))
A     (SETQ NXTSYM\* (TOKEN))
B     (COND
         ((OR (NULL (ATOM NXTSYM\*)) (NUMBERP NXTSYM\*)) (GO L))
         ((AND (SETQ X (GET NXTSYM\* 'NEWNAM)) (SETQ NXTSYM\* X))
            (GO B))
         ((EQ NXTSYM\* 'COMMENT) (GO COMM))
         ((AND
             (EQ NXTSYM\* '\')
             (SETQ CURSYM\* (LIST 'QUOTE (RREAD))))
            (GO L1))
         ((NULL (SETQ X (GET NXTSYM\* 'SWITCH\*))) (GO L))
         ((EQ (CADR X) '\*SEMICOL\*)
            (RETURN (SETQ CURSYM\* (CADR X)))) )
SW1   (SETQ NXTSYM\* (TOKEN))
      (COND
         ((OR
             (NULL (CAR X))
             (NULL (SETQ Y (ASSOC NXTSYM\* (CAR X)))) )
            (RETURN (SETQ CURSYM\* (CADR X)))) )
      (SETQ X (CDR Y))
      (GO SW1)
COMM  (COND ((EQ (READCH) '\;) (SETQ CRCHAR\* '\ )) (t (GO COMM)))
      (GO A)
L     (SETQ CURSYM\*
         (COND
            ((NULL (EQCAR NXTSYM\* 'STRING)) NXTSYM\*)
            (t (CONS 'QUOTE (CDR NXTSYM\*)))) )
L1    (SETQ NXTSYM\* (TOKEN))
      (RETURN CURSYM\*)))

(DE IFSTAT nil
   (PROG (CONDX CONDIT)
A     (SETQ CONDX (XREAD t))
      (SETQ CONDIT (NCONC CONDIT (LIST (LIST CONDX (XREAD t)))) )
      (COND
         ((NULL (EQ CURSYM\* 'ELSE)) (GO B))
         ((EQ (SCAN) 'IF) (GO A))
         (t (SETQ CONDIT
               (NCONC CONDIT (LIST (LIST t (XREAD1 t)))) )))
B     (RETURN (CONS 'COND CONDIT))))

(DE PROCSTAT nil
   (PROG (X Y)
      (COND ((EQ CURSYM\* 'SYMBOLIC) (SCAN)))
      (COND
         ((EQ CURSYM\* '\*SEMICOL\*)
            (RETURN (NULL (SETQ \*MODE 'SYMBOLIC)))) )
      (SETQ FNAME\* (SCAN))
      (COND ((ATOM (SETQ X (XREAD1 nil))) (SETQ X (LIST X))))
      (SETQ Y (XREAD nil))
      (COND ((FLAGP (CAR X) 'LOSE) (RETURN nil)))
      (PUTD (CAR X) 'EXPR (LIST 'LAMBDA (CDR X) Y))
      (SETQ FNAME\* nil)
      (RETURN (LIST 'QUOTE (CAR X)))) )

(DE BLOCKSTAT nil
   (PROG (X HOLD VARLIS \*BLOCKP)
A0    (SETQ \*BLOCKP t)
      (SCAN)
      (COND
         ((NULL (OR (EQ CURSYM\* 'INTEGER) (EQ CURSYM\* 'SCALAR)))
            (GO A)))
      (SETQ X (XREAD nil))
      (SETQ VARLIS
         (NCONC
            (COND ((EQCAR X '\*COMMA\*) (CDR X)) (t (LIST X)))
            VARLIS))
      (GO A0)
A     (SETQ HOLD (NCONC HOLD (LIST (XREAD1 nil))))
      (SETQ X CURSYM\*)
      (SCAN)
      (COND ((NOT (EQ X 'END)) (GO A)))
      (RETURN (MKPROG VARLIS HOLD))))

(DE MKPROG (U V) (CONS 'PROG (CONS U V)))

(DE GOSTAT nil 
   (PROG (X) (SCAN) (SETQ X (SCAN)) (SCAN) (RETURN (LIST 'GO X))))

(PUT 'GO 'STAT 'GOSTAT)

(DE RLIS nil
   (PROG (X)
      (SETQ X CURSYM\*)
      (RETURN (COND ((NOT (FLAGP (SCAN) 'DELIM))
                     (LIST X (LIST 'QUOTE (LIST (XREAD1 t)))))
                    (t (LIST X))))))

(RDS OLDCHAN\*)

(provide 'boot)

;;; boot.el ends here
