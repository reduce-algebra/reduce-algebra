(de oem!-supervisor nil (print (eval (read))))


(de break!-loop (a)
   (prog (prompt ifile ofile u v)
      (setq ifile (rds !*debug!-io!*))
      (setq ofile (wrs !*debug!-io!*))
      (setq prompt (setpchar "Break loop (:X exits)> "))
top   (setq u (read))
      (cond
         ((equal u '!:x) (go exit))
         ((equal u '!:q)
            (progn
               (enable!-backtrace nil)
               (princ "Backtrace now disabled")
               (terpri)))
         ((equal u '!:v)
            (progn
               (enable!-backtrace t)
               (princ "Backtrace now enabled")
               (terpri)))
         (t (progn
               (cond
                  ((null u) (setq v nil))
                  (t (setq v (errorset u nil nil))))
               (cond
                  ((atom v)
                     (progn
                        (princ ":Q   quietens backtrace")
                        (terpri)
                        (princ ":V   enables backtrace")
                        (terpri)
                        (princ ":X   exits from break loop")
                        (terpri)
                        (princ "else form for evaluation")
                        (terpri)
                        nil))
                  (t (progn (prin "=> ") (prinl (car v)) (terpri)))) )))
      (go top)
exit  (rds ifile)
      (wrs ofile)
      (setpchar prompt)
      (return nil)))


(global '(s!:gensym!-serial))


(setq s!:gensym!-serial 0)


(de s!:stamp (n)
   (cond
      ((lessp n 0) (append (s!:stamp (minus n)) '(!-)))
      ((equal n 0) nil)
      (t (cons
            (schar "0123456789abcdefghijklmnopqrstuvwxyz" (remainder n 36))
            (s!:stamp (truncate n 36)))) ))


(de dated!-name (base)
   (intern
      (list!-to!-string
         (append
            (explodec base)
            (cons
               '!_
               (append
                  (reverse (s!:stamp (datestamp)))
                  (cons
                     '!_
                     (explodec
                        (setq s!:gensym!-serial
                           (plus s!:gensym!-serial 1)))) ))) )))


(de hashtagged!-name (base value)
   (intern
      (list!-to!-string
         (append
            (explodec base)
            (cons '!_ (append (reverse (s!:stamp (sxhash value))) '(!_)))) )))


(remflag '(sort sortip) 'lose)


(de sort (l pred) (stable!-sortip (append l nil) pred))


(de stable!-sort (l pred) (stable!-sortip (append l nil) pred))


(de sortip (l pred) (stable!-sortip l pred))


(de stable!-sortip (l pred)
   (prog (l1 l2 w)
      (cond ((null l) (return l)))
      (setq l1 l)
      (setq l2 (cdr l))
      (cond ((null l2) (return l)))
      (setq l (cdr l2))
      (cond
         ((null l)
            (progn
               (cond
                  ((apply2 pred (car l2) (car l1))
                     (progn
                        (setq l (car l1))
                        (rplaca l1 (car l2))
                        (rplaca l2 l))))
               (return l1))))
      (setq l l1)
      (prog nil
   !G0   (cond
            ((not (and l2 (not (apply2 pred (car l2) (car l)))) )
               (return nil)))
         (progn (setq l l2) (setq l2 (cdr l2)))
         (go !G0))
      (cond ((null l2) (return l1)))
      (setq l2 l1)
      (setq l (cddr l2))
      (prog nil
   !G1   (cond ((not (and l (cdr l))) (return nil)))
         (progn (setq l2 (cdr l2)) (setq l (cddr l)))
         (go !G1))
      (setq l l2)
      (setq l2 (cdr l2))
      (rplacd l nil)
      (setq l1 (stable!-sortip l1 pred))
      (setq l2 (stable!-sortip l2 pred))
      (setq l (setq w (list nil)))
      (prog nil
   !G2   (cond ((not (and l1 l2)) (return nil)))
         (progn
            (cond
               ((apply2 pred (car l2) (car l1))
                  (progn (rplacd w l2) (setq w l2) (setq l2 (cdr l2))))
               (t (progn (rplacd w l1) (setq w l1) (setq l1 (cdr l1)))) ))
         (go !G2))
      (cond (l1 (setq l2 l1)))
      (rplacd w l2)
      (return (cdr l))))


(fluid
   '(!*prinl!-visited!-nodes!*
       !*prinl!-index!*
       !*prinl!-fn!*
       !*loop!-print!*
       !*print!-array!*
       !*print!-length!*
       !*print!-level!*))


(setq !*print!-length!* (setq !*print!-level!* nil))


(setq !*prinl!-visited!-nodes!* (mkhash 10 0 1.5))


(de s!:prinl0 (x !*prinl!-fn!*)
   (prog (!*prinl!-index!*)
      (setq !*prinl!-index!* 0)
      (unwind!-protect
         (progn (s!:prinl1 x 0) (s!:prinl2 x 0))
         (clrhash !*prinl!-visited!-nodes!*))
      (return x)))


(de s!:prinl1 (x depth)
   (prog (w length)
      (cond
         ((and (fixp !*print!-level!*) (greaterp depth !*print!-level!*))
            (return nil)))
      (setq length 0)
top   (cond
         ((and (atom x) (not (simple!-vector!-p x)) (not (gensymp x)))
            (return nil))
         ((setq w (gethash x !*prinl!-visited!-nodes!*))
            (progn
               (cond
                  ((equal w 0)
                     (progn
                        (setq !*prinl!-index!* (plus !*prinl!-index!* 1))
                        (puthash
                           x
                           !*prinl!-visited!-nodes!*
                           !*prinl!-index!*))))
               (return nil)))
         (t (progn
               (puthash x !*prinl!-visited!-nodes!* 0)
               (cond
                  ((simple!-vector!-p x)
                     (progn
                        (cond
                           (!*print!-array!*
                              (progn
                                 (setq length (upbv x))
                                 (cond
                                    ((and
                                        (fixp !*print!-length!*)
                                        (lessp !*print!-length!* length))
                                       (setq length !*print!-length!*)))
                                 (prog (i)
                                    (setq i 0)
                              lab   (cond
                                       ((minusp (difference length i))
                                          (return nil)))
                                    (s!:prinl1 (getv x i) (plus depth 1))
                                    (setq i (plus2 i 1))
                                    (go lab)))) )))
                  ((not (atom x))
                     (progn
                        (s!:prinl1 (car x) (plus depth 1))
                        (cond
                           ((and
                               (fixp !*print!-length!*)
                               (greaterp
                                  (setq length (plus length 1))
                                  !*print!-length!*))
                              (return nil)))
                        (setq x (cdr x))
                        (go top)))) ))) ))


(de s!:prinl2 (x depth)
   (cond
      ((and (fixp !*print!-level!*) (greaterp depth !*print!-level!*))
         (princ "#"))
      ((and (atom x) (not (simple!-vector!-p x)) (not (gensymp x)))
         (progn (funcall !*prinl!-fn!* x)))
      (t (prog (w length)
            (setq w (gethash x !*prinl!-visited!-nodes!*))
            (cond
               ((not (zerop w))
                  (progn
                     (cond
                        ((lessp w 0)
                           (progn
                              (princ "#")
                              (princ (minus w))
                              (princ "#")
                              (return nil)))
                        (t (progn
                              (puthash x !*prinl!-visited!-nodes!* (minus w))
                              (princ "#")
                              (princ w)
                              (princ "=")))) )))
            (cond
               ((simple!-vector!-p x)
                  (progn
                     (princ "%(")
                     (cond
                        (!*print!-array!*
                           (progn
                              (setq length (upbv x))
                              (cond
                                 ((and
                                     (fixp !*print!-length!*)
                                     (lessp !*print!-length!* length))
                                    (setq length !*print!-length!*)))
                              (prog (i)
                                 (setq i 0)
                           lab   (cond
                                    ((minusp (difference length i))
                                       (return nil)))
                                 (progn
                                    (s!:prinl2 (getv x i) (plus depth 1))
                                    (cond
                                       ((not (equal i (upbv x)))
                                          (princ " "))))
                                 (setq i (plus2 i 1))
                                 (go lab))))
                        (t (princ "...")))
                     (princ ")")
                     (return nil)))
               ((atom x) (return (funcall !*prinl!-fn!* x))))
            (princ "(")
            (setq length 0)
      loop  (s!:prinl2 (car x) (plus depth 1))
            (setq x (cdr x))
            (cond
               ((atom x)
                  (progn
                     (cond
                        ((simple!-vector!-p x)
                           (progn
                              (princ " . %(")
                              (cond
                                 (!*print!-array!*
                                    (progn
                                       (setq length (upbv x))
                                       (cond
                                          ((and
                                              (fixp !*print!-length!*)
                                              (lessp
                                                 !*print!-length!*
                                                 length))
                                             (setq length !*print!-length!*)))
                                       (prog (i)
                                          (setq i 0)
                                    lab   (cond
                                             ((minusp (difference length i))
                                                (return nil)))
                                          (progn
                                             (s!:prinl2
                                                (getv x i)
                                                (plus depth 1))
                                             (cond
                                                ((not (equal i (upbv x)))
                                                   (princ " "))))
                                          (setq i (plus2 i 1))
                                          (go lab))))
                                 (t (princ "...")))
                              (princ ")")))
                        (x (progn (princ " . ") (funcall !*prinl!-fn!* x))))
                     (return (princ ")")))) )
            (cond
               ((and
                   (fixp !*print!-length!*)
                   (greaterp (setq length (plus length 1)) !*print!-length!*))
                  (return (princ " ...)"))))
            (setq w (gethash x !*prinl!-visited!-nodes!*))
            (cond
               ((not (equal w 0))
                  (cond
                     ((lessp w 0)
                        (progn
                           (princ " . #")
                           (princ (minus w))
                           (return (princ "#)"))))
                     (t (progn
                           (princ " . ")
                           (s!:prinl2 x (plus depth 1))
                           (return (princ ")")))) ))
               (t (princ " ")))
            (go loop)))) )


(de printl (x) (progn (prinl x) (terpri) x))


(de printcl (x) (progn (princl x) (terpri) x))


(de princl (x) (s!:prinl0 x (function princ)))


(de prinl (x) (s!:prinl0 x (function prin)))


(de s!:format (dest fmt args)
   (prog (len c a res o)
      (cond
         ((not (null dest))
            (progn
               (cond
                  ((equal dest 't) (setq o (wrs nil)))
                  (t (setq o (wrs dest)))) )))
      (setq len (upbv fmt))
      (prog (i)
         (setq i 0)
   lab   (cond ((minusp (difference len i)) (return nil)))
         (progn
            (setq c (schar fmt i))
            (cond
               ((equal c '!~)
                  (progn
                     (setq i (plus i 1))
                     (setq c (char!-downcase (schar fmt i)))
                     (cond
                        ((equal c '!%)
                           (cond
                              ((null dest) (setq res (cons !$eol!$ res)))
                              (t (terpri))))
                        ((equal c '!~)
                           (cond
                              ((null dest) (setq res (cons '!~ res)))
                              (t (princ '!~))))
                        (t (progn
                              (cond
                                 ((null args) (setq a nil))
                                 (t (progn
                                       (setq a (car args))
                                       (setq args (cdr args)))) )
                              (cond
                                 ((equal c 'a)
                                    (cond
                                       ((null dest)
                                          (prog (k)
                                             (setq k (explode2 a))
                                       lab   (cond ((null k) (return nil)))
                                             ((lambda (k)
                                                 (setq res (cons k res)))
                                                (car k))
                                             (setq k (cdr k))
                                             (go lab)))
                                       (t (princ a))))
                                 ((equal c 's)
                                    (cond
                                       ((null dest)
                                          (prog (k)
                                             (setq k (explode a))
                                       lab   (cond ((null k) (return nil)))
                                             ((lambda (k)
                                                 (setq res (cons k res)))
                                                (car k))
                                             (setq k (cdr k))
                                             (go lab)))
                                       (t (prin a))))
                                 ((null dest)
                                    (prog (k)
                                       (setq k (explode a))
                                 lab   (cond ((null k) (return nil)))
                                       ((lambda (k) (setq res (cons k res)))
                                          (car k))
                                       (setq k (cdr k))
                                       (go lab)))
                                 (t (prin (list '!?!?!? c a)))) ))) ))
               (t (progn
                     (cond
                        ((null dest) (setq res (cons c res)))
                        (t (princ c)))) )))
         (setq i (plus2 i 1))
         (go lab))
      (cond
         ((null dest) (return (list!-to!-string (reversip res))))
         (t (progn (wrs o) (return nil)))) ))


(dm format (u) (list 's!:format (cadr u) (caddr u) (cons 'list (cdddr u))))


(fluid
   '(bn bufferi buffero indblanks indentlevel initialblanks lmar pendingrpars
       rmar rparcount stack))


(global '(!*quotes !*symmetric thin!*))


(setq !*symmetric t)


(setq !*quotes t)


(setq thin!* 5)


(de prettyprint (x) (progn (superprinm x (posn)) (terpri) nil))


(de superprintm (x lmar) (progn (superprinm x lmar) (terpri) x))


(de superprinm (x lmar)
   (prog (stack bufferi buffero bn initialblanks rmar pendingrpars indentlevel
         indblanks rparcount w)
      (setq bufferi (setq buffero (list nil)))
      (setq initialblanks 0)
      (setq rparcount 0)
      (setq indblanks 0)
      (setq rmar (linelength nil))
      (linelength 500)
      (cond
         ((lessp rmar 25)
            (error 0 (list rmar "Linelength too short for superprinting"))))
      (setq bn 0)
      (setq indentlevel 0)
      (cond ((geq (plus lmar 20) rmar) (setq lmar (difference rmar 21))))
      (setq w (posn))
      (cond ((greaterp w lmar) (progn (terpri) (setq w 0))))
      (cond ((lessp w lmar) (setq initialblanks (difference lmar w))))
      (s!:prindent x (plus lmar 3))
      (s!:overflow 'none)
      (linelength rmar)
      (return x)))


(putc 's!:top 'smacro '(lambda nil (car stack)))


(putc 's!:depth 'smacro '(lambda (frm) (car frm)))


(putc 's!:indenting 'smacro '(lambda (frm) (cadr frm)))


(putc 's!:blankcount 'smacro '(lambda (frm) (caddr frm)))


(putc 's!:blanklist 'smacro '(lambda (frm) (cdddr frm)))


(putc 's!:setindenting 'smacro '(lambda (frm val) (rplaca (cdr frm) val)))


(putc 's!:setblankcount 'smacro '(lambda (frm val) (rplaca (cddr frm) val)))


(putc 's!:setblanklist 'smacro '(lambda (frm val) (rplacd (cddr frm) val)))


(putc 's!:newframe 'smacro '(lambda (n) (list n nil 0)))


(putc 's!:blankp 'smacro '(lambda (char) (numberp (car char))))


(de s!:prindent (x n)
   (cond
      ((atom x)
         (cond
            ((simple!-vector!-p x) (s!:prvector x n))
            (t (prog (c)
                  (setq c
                     (cond
                        (!*symmetric
                           (cond
                              ((stringp x) (s!:explodes x))
                              (t (explode x))))
                        (t (explode2 x))))
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (s!:putch c)) (car c))
                  (setq c (cdr c))
                  (go lab)))) )
      ((s!:quotep x) (progn (s!:putch '!') (s!:prindent (cadr x) (plus n 1))))
      (t (prog (cx)
            (cond
               ((greaterp (times 4 n) (times 3 rmar))
                  (progn
                     (s!:overflow 'all)
                     (setq n (truncate n 8))
                     (cond
                        ((greaterp initialblanks n)
                           (progn
                              (setq lmar
                                 (plus (difference lmar initialblanks) n))
                              (setq initialblanks n)))) )))
            (setq stack (cons (list n nil 0) stack))
            (s!:putch (cons 'lpar (car stack)))
            (setq cx (car x))
            (s!:prindent cx (plus n 1))
            (cond
               ((and (idp cx) (not (atom (cdr x))))
                  (setq cx (get cx 's!:ppformat)))
               (t (setq cx nil)))
            (cond ((and (equal cx 2) (atom (cddr x))) (setq cx nil)))
            (cond
               ((equal cx 'prog)
                  (progn
                     (s!:putch '! )
                     (s!:prindent (car (setq x (cdr x))) (plus n 3)))) )
            (setq x (cdr x))
      scan  (cond ((atom x) (go outt)))
            (s!:finishpending)
            (cond
               ((equal cx 'prog)
                  (progn
                     (s!:putblank)
                     (s!:overflow bufferi)
                     (cond
                        ((atom (car x))
                           (progn
                              (setq lmar
                                 (setq initialblanks
                                    (max (difference lmar 6) 0)))
                              (s!:prindent (car x) (difference n 3))
                              (setq x (cdr x))
                              (cond
                                 ((and (not (atom x)) (atom (car x)))
                                    (go scan)))
                              (cond
                                 ((greaterp (plus lmar bn) n) (s!:putblank))
                                 (t (prog (i)
                                       (setq i (plus lmar bn))
                                 lab   (cond
                                          ((minusp
                                              (difference (difference n 1) i))
                                             (return nil)))
                                       (s!:putch '! )
                                       (setq i (plus2 i 1))
                                       (go lab))))
                              (cond ((atom x) (go outt)))) ))) )
               ((numberp cx)
                  (progn
                     (setq cx (difference cx 1))
                     (cond ((equal cx 0) (setq cx nil)))
                     (s!:putch '! )))
               (t (s!:putblank)))
            (s!:prindent (car x) (plus n 3))
            (setq x (cdr x))
            (go scan)
      outt  (cond
               ((not (null x))
                  (progn
                     (s!:finishpending)
                     (s!:putblank)
                     (s!:putch '!.)
                     (s!:putch '! )
                     (s!:prindent x (plus n 5)))) )
            (s!:putch (cons 'rpar (difference n 3)))
            (cond
               ((and
                   (equal (cadr (car stack)) 'indent)
                   (not (null (cdddr (car stack)))) )
                  (s!:overflow (car (cdddr (car stack)))) )
               (t (s!:endlist (car stack))))
            (setq stack (cdr stack)))) ))


(de s!:explodes (x) (explode x))


(de s!:prvector (x n)
   (prog (bound)
      (setq bound (upbv x))
      (setq stack (cons (list n nil 0) stack))
      (s!:putch (cons 'lsquare (car stack)))
      (s!:prindent (getv x 0) (plus n 3))
      (prog (i)
         (setq i 1)
   lab   (cond ((minusp (difference bound i)) (return nil)))
         (progn
            (s!:putch '!,)
            (s!:putblank)
            (s!:prindent (getv x i) (plus n 3)))
         (setq i (plus2 i 1))
         (go lab))
      (s!:putch (cons 'rsquare (difference n 3)))
      (s!:endlist (car stack))
      (setq stack (cdr stack))))


(de s!:putblank nil
   (prog nil
      (s!:putch (car stack))
      (rplaca (cddr (car stack)) (plus (caddr (car stack)) 1))
      (rplacd (cddr (car stack)) (cons bufferi (cdddr (car stack))))
      (setq indblanks (plus indblanks 1))))


(de s!:endlist (l) (setq pendingrpars (cons l pendingrpars)))


(de s!:finishpending nil
   (progn
      (prog (stackframe)
         (setq stackframe pendingrpars)
   lab   (cond ((null stackframe) (return nil)))
         ((lambda (stackframe)
             (progn
                (cond
                   ((neq (cadr stackframe) 'indent)
                      (prog (b)
                         (setq b (cdddr stackframe))
                   lab   (cond ((null b) (return nil)))
                         ((lambda (b)
                             (progn
                                (rplaca b '! )
                                (setq indblanks (difference indblanks 1))))
                            (car b))
                         (setq b (cdr b))
                         (go lab))))
                (rplacd (cddr stackframe) t)))
            (car stackframe))
         (setq stackframe (cdr stackframe))
         (go lab))
      (setq pendingrpars nil)))


(de s!:quotep (x)
   (and !*quotes (not (atom x)) (equal (car x) 'quote) (not (atom (cdr x)))
      (null (cddr x))))


(put 'prog 's!:ppformat 'prog)


(put 'lambda 's!:ppformat 1)


(put 'lambdaq 's!:ppformat 1)


(put 'setq 's!:ppformat 1)


(put 'set 's!:ppformat 1)


(put 'while 's!:ppformat 1)


(put 't 's!:ppformat 1)


(put 'de 's!:ppformat 2)


(put 'df 's!:ppformat 2)


(put 'dm 's!:ppformat 2)


(put 'defun 's!:ppformat 2)


(put 'defmacro 's!:ppformat 2)


(put 'foreach 's!:ppformat 4)


(de s!:putch (c)
   (prog nil
      (cond
         ((atom c) (setq rparcount 0))
         ((numberp (car c)) (progn (setq rparcount 0) (go nocheck)))
         ((equal (car c) 'rpar)
            (progn
               (setq rparcount (plus rparcount 1))
               (cond
                  ((greaterp rparcount 4)
                     (progn (s!:putch '! ) (setq rparcount 2)))) ))
         (t (setq rparcount 0)))
      (prog nil
   !G3   (cond ((not (geq (plus lmar bn) rmar)) (return nil)))
         (s!:overflow 'more)
         (go !G3))
nocheck
      (setq bufferi (cdr (rplacd bufferi (list c))))
      (setq bn (plus bn 1))))


(de s!:overflow (flg)
   (prog (c blankstoskip)
      (cond
         ((and
             (equal indblanks 0)
             (greaterp initialblanks 3)
             (equal flg 'more))
            (progn
               (setq initialblanks (difference initialblanks 3))
               (setq lmar (difference lmar 3))
               (return 'moved!-left))))
fblank(cond
         ((equal bn 0)
            (progn
               (cond ((not (equal flg 'more)) (return 'empty)))
               (cond ((atom (car buffero)) (prin2 "%+")))
               (terpri)
               (setq lmar 0)
               (return 'continued)))
         (t (progn (spaces initialblanks) (setq initialblanks 0))))
      (setq buffero (cdr buffero))
      (setq bn (difference bn 1))
      (setq lmar (plus lmar 1))
      (setq c (car buffero))
      (cond
         ((atom c) (progn (prin2 c) (go fblank)))
         ((numberp (car c))
            (cond
               ((not (atom blankstoskip))
                  (progn
                     (prin2 '! )
                     (setq indblanks (difference indblanks 1))
                     (cond
                        ((eq c (car blankstoskip))
                           (progn
                              (rplacd
                                 blankstoskip
                                 (difference (cdr blankstoskip) 1))
                              (cond
                                 ((equal (cdr blankstoskip) 0)
                                    (setq blankstoskip t)))) ))
                     (go fblank)))
               (t (go blankfound))))
         ((or (equal (car c) 'lpar) (equal (car c) 'lsquare))
            (progn
               (prin2 (get (car c) 's!:ppchar))
               (cond ((equal flg 'none) (go fblank)))
               (setq c (cdr c))
               (cond ((not (null (cdddr c))) (go fblank)))
               (cond
                  ((greaterp (car c) indentlevel)
                     (progn
                        (setq indentlevel (car c))
                        (rplaca (cdr c) 'indent))))
               (go fblank)))
         ((or (equal (car c) 'rpar) (equal (car c) 'rsquare))
            (progn
               (cond ((lessp (cdr c) indentlevel) (setq indentlevel (cdr c))))
               (prin2 (get (car c) 's!:ppchar))
               (go fblank)))
         (t (error 0 (list c "UNKNOWN TAG IN OVERFLOW"))))
blankfound
      (cond ((eqcar (cdddr c) buffero) (rplacd (cddr c) nil)))
      (setq indblanks (difference indblanks 1))
      (cond
         ((greaterp (car c) indentlevel)
            (progn
               (cond ((equal flg 'none) (progn (prin2 '! ) (go fblank))))
               (cond
                  (blankstoskip (setq blankstoskip nil))
                  (t (progn
                        (setq indentlevel (car c))
                        (rplaca (cdr c) 'indent)))) )))
      (cond
         ((greaterp (caddr c) (difference thin!* 1))
            (progn
               (setq blankstoskip (cons c (difference (caddr c) 2)))
               (rplaca (cdr c) 'thin)
               (rplaca (cddr c) 1)
               (setq indentlevel (difference (car c) 1))
               (prin2 '! )
               (go fblank))))
      (rplaca (cddr c) (difference (caddr c) 1))
      (terpri)
      (setq lmar (setq initialblanks (car c)))
      (cond ((eq buffero flg) (return 'to!-flg)))
      (cond ((or blankstoskip (not (equal flg 'more))) (go fblank)))
      (return 'more)))


(put 'lpar 's!:ppchar '!()


(put 'lsquare 's!:ppchar '![)


(put 'rpar 's!:ppchar '!))


(put 'rsquare 's!:ppchar '!])


(de fetch!-url (url !&optional dest)
   (prog (a b c d e w)
      (setq a (open!-url url))
      (cond ((null a) (return nil)))
      (cond
         (dest
            (progn
               (setq d (open dest 'output))
               (cond
                  ((null d)
                     (progn
                        (close a)
                        (return
                           (error 0 "unable to open destination file")))) )
               (setq d (wrs d)))) )
      (setq b (rds a))
      (setq w (linelength 500))
      (prog nil
   !G4   (cond ((not (not (equal (setq c (readch)) !$eof!$))) (return nil)))
         (princ c)
         (go !G4))
      (linelength e)
      (rds b)
      (close a)
      (cond (dest (close (wrs d)))) ))


