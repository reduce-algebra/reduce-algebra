% derived from reduce/packages/rlisp/rprintf.red


(de list2widestring (x)
  (prog (r)
    (setq r '(!"))
  top
    (cond
      ((null x) (return (compress (reverse (cons '!" r))))))
    (setq r (cons (car x) r))
    (cond
      ((eq (car x) '!") (setq r (cons '!" r))))
    (setq x (cdr x))
    (go top)))

(fluid '(bldmsg_chars!* !*ll!*))

(setq bldmsg_chars!* nil)

(de p_princ (u blankfirst)
   (prog (w)
      (setq w (explode2 u))
      (cond
         (bldmsg_chars!*
            (progn
               (cond
                  (blankfirst (setq bldmsg_chars!* (cons '!  bldmsg_chars!*))))
               (prog (c)
                  (setq c w)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (setq bldmsg_chars!* (cons c bldmsg_chars!*)))
                     (car c))
                  (setq c (cdr c))
                  (go lab))))
         (t (progn
               (cond
                  (blankfirst
                     (progn
                        (cond
                           ((greaterp (plus (posn) (length w) 1) !*ll!*)
                              (terpri)))
                        (prin2 " ")))
                  ((greaterp (plus (posn) (length w)) !*ll!*) (terpri)))
               (prin2 u)))) ))

(de p_prin (u blankfirst)
   (prog (w)
      (setq w (explode u))
      (cond ((eqcar w '!_) (setq w (cons '!! w))))
      (cond
         (bldmsg_chars!*
            (progn
               (cond
                  (blankfirst (setq bldmsg_chars!* (cons '!  bldmsg_chars!*))))
               (prog (c)
                  (setq c w)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (setq bldmsg_chars!* (cons c bldmsg_chars!*)))
                     (car c))
                  (setq c (cdr c))
                  (go lab))))
         (t (progn
               (cond
                  (blankfirst
                     (progn
                        (cond
                           ((greaterp (plus (posn) (length w) 1) !*ll!*)
                              (terpri)))
                        (prin2 " ")))
                  ((greaterp (plus (posn) (length w)) !*ll!*) (terpri)))
               (prog (c)
                  (setq c w)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (prin2 c)) (car c))
                  (setq c (cdr c))
                  (go lab)))) )))

(fluid '(!*print!-array!* !*print!-length!* !*print!-level!*))

(setq !*print!-array!* t)

(setq !*print!-length!* nil)

(setq !*print!-level!* nil)

(fluid '(!*prinl_visited_nodes!* !*prinl_index!*))

(setq !*prinl_visited_nodes!* (mkhash 10 0 1.5))

(de p_prinl0 (x escaped)
   (prog (!*prinl_index!*)
      (declare (special !*prinl_index!*))
      (setq !*prinl_index!* 0)
      (unwind!-protect
         (progn (p_prinl1 x 0) (p_prinl2 x 0 escaped nil))
         (clrhash !*prinl_visited_nodes!*))
      (return x)))

(de p_prinl1 (x depth)
   (prog (w length)
      (cond
         ((and (fixp !*print!-level!*) (greaterp depth !*print!-level!*))
            (return nil)))
      (setq length 0)
top   (cond
         ((and (atom x) (not (vectorp x)) (not (gensymp x))) (return nil))
         ((setq w (gethash x !*prinl_visited_nodes!*))
            (progn
               (cond
                  ((equal w 0)
                     (progn
                        (setq !*prinl_index!* (plus !*prinl_index!* 1))
                        (puthash x !*prinl_visited_nodes!* !*prinl_index!*))))
               (return nil)))
         (t (progn
               (puthash x !*prinl_visited_nodes!* 0)
               (cond
                  ((vectorp x)
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
                                    (p_prinl1 (getv x i) (plus depth 1))
                                    (setq i (plus2 i 1))
                                    (go lab)))) )))
                  ((not (atom x))
                     (progn
                        (p_prinl1 (car x) (plus depth 1))
                        (cond
                           ((and
                               (fixp !*print!-length!*)
                               (greaterp
                                  (setq length (plus length 1))
                                  !*print!-length!*))
                              (return nil)))
                        (setq x (cdr x))
                        (go top)))) ))) ))

(de p_printref (w blankfirst ch)
   (prog (len)
      (setq len (length (explode w)))
      (cond (blankfirst (setq len (plus len 1))))
      (cond
         ((and (not bldmsg_chars!*) (greaterp (plus (posn) 2 len) !*ll!*))
            (progn (setq blankfirst nil) (terpri))))
      (p_princ "#" blankfirst)
      (p_princ w nil)
      (p_princ ch nil)))

(de p_prinl2 (x depth escaped blankfirst)
   (cond
      ((and (fixp !*print!-level!*) (greaterp depth !*print!-level!*))
         (p_princ "#" blankfirst))
      ((and (atom x) (not (vectorp x)) (not (gensymp x)))
         (progn
            (cond (escaped (p_prin x blankfirst)) (t (p_princ x blankfirst)))) )
      (t (prog (w length)
            (setq w (gethash x !*prinl_visited_nodes!*))
            (cond
               ((and w (not (zerop w)))
                  (progn
                     (cond
                        ((lessp w 0)
                           (progn
                              (p_printref (minus w) blankfirst "#")
                              (return nil)))
                        (t (progn
                              (puthash x !*prinl_visited_nodes!* (minus w))
                              (p_printref w blankfirst "=")
                              (setq blankfirst nil)))) )))
            (cond
               ((vectorp x)
                  (progn
                     (p_princ "%(" blankfirst)
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
                                 (p_prinl2
                                    (getv x i)
                                    (plus depth 1)
                                    escaped
                                    (neq i 0))
                                 (setq i (plus2 i 1))
                                 (go lab))))
                        (t (p_princ "..." nil)))
                     (p_princ ")" nil)
                     (return nil)))
               ((atom x)
                  (progn
                     (cond
                        (escaped (p_prin x blankfirst))
                        (t (p_princ x blankfirst)))
                     (return nil))))
            (p_princ "(" blankfirst)
            (p_prinl2 (car x) (plus depth 1) escaped nil)
            (setq x (cdr x))
            (setq length 0)
      loop  (cond
               ((atom x)
                  (progn
                     (cond
                        ((neq x nil)
                           (progn
                              (p_princ "." t)
                              (p_prinl2 x depth escaped t))))
                     (return (p_princ ")" nil)))) )
            (cond
               ((and
                   (fixp !*print!-length!*)
                   (greaterp (setq length (plus length 1)) !*print!-length!*))
                  (progn (p_princ "..." t) (return (p_princ ")" nil)))) )
            (setq w (gethash x !*prinl_visited_nodes!*))
            (cond
               ((and w (not (zerop w)))
                  (progn
                     (cond
                        ((lessp w 0)
                           (progn
                              (p_princ "." t)
                              (p_printref (minus w) t "#")
                              (return (p_princ ")" nil))))
                        (t (progn
                              (p_princ "." t)
                              (p_prinl2 x (plus depth 1) escaped t)
                              (return (p_princ ")" nil)))) ))) )
            (p_prinl2 (car x) (plus depth 1) escaped t)
            (setq x (cdr x))
            (go loop)))) )

(de printl (x) (progn (prinl x) (terpri) x))

(de printcl (x) (progn (princl x) (terpri) x))

(de princl (x)
   (prog (!*ll!*)
      (declare (special !*ll!*))
      (setq !*ll!* (difference (linelength nil) 2))
      (p_prinl0 x nil)
      (return x)))

(de prinl (x)
   (prog (!*ll!*)
      (declare (special !*ll!*))
      (setq !*ll!* (difference (linelength nil) 2))
      (p_prinl0 x t)
      (return x)))

(de portable_print (x) (progn (portable_prin x) (terpri) x))

(de portable_printc (x) (progn (portable_princ x) (terpri) x))

(de portable_princ (x)
   (prog (!*ll!*)
      (declare (special !*ll!*))
      (setq !*ll!* (difference (linelength nil) 2))
      (p_prinl2 x 0 nil nil)
      (return x)))

(de portable_prin (x)
   (prog (!*ll!*)
      (declare (special !*ll!*))
      (setq !*ll!* (difference (linelength nil) 2))
      (p_prinl2 x 0 t nil)
      (return x)))

(de p_minus (u)
   (cond
      ((eqcar u 'minus) (cadr u))
      ((eqcar u 'plus)
         (cons
            'plus
            (prog (v forall!-result forall!-endptr)
               (setq v (cdr u))
               (cond ((null v) (return nil)))
               (setq forall!-result
                  (setq forall!-endptr
                     (cons ((lambda (v) (p_minus v)) (car v)) nil)))
         looplabel
               (setq v (cdr v))
               (cond ((null v) (return forall!-result)))
               (rplacd
                  forall!-endptr
                  (cons ((lambda (v) (p_minus v)) (car v)) nil))
               (setq forall!-endptr (cdr forall!-endptr))
               (go looplabel))))
      ((eqcar u 'difference) (cons 'plus (cons (p_minus (cadr u)) (cddr u))))
      (t (list 'minus u))))

(de p_diff2minus (u)
   (prog (r)
      (setq r (car u))
      (prog nil
   whilelabel
         (cond ((not (setq u (cdr u))) (return nil)))
         (setq r (cons (p_minus (car u)) r))
         (go whilelabel))
      (return (cons 'plus (reverse r)))) )

(de p_prefix (u prec)
   (cond
      ((atom u) (p_princ u nil))
      ((eqcar u '!*sq) (p_prefix (prepsq (cadr u)) prec))
      (t (prog (op p1)
            (setq op (car u))
            (cond
               ((equal op 'expt)
                  (progn
                     (cond ((greaterp prec 3) (p_princ "(" nil)))
                     (p_prefix (cadr u) 4)
                     (p_princ "^" nil)
                     (p_prefix (caddr u) 3)
                     (cond ((greaterp prec 3) (p_princ ")" nil)))
                     (return nil)))
               ((or (equal op 'times) (equal op 'quotient))
                  (progn
                     (cond ((greaterp prec 2) (p_princ "(" nil)))
                     (p_prefix (car (setq u (cdr u))) 2)
                     (cond
                        ((equal op 'times) (progn (setq p1 2) (setq op "*")))
                        (t (progn (setq p1 3) (setq op "/"))))
                     (prog nil
                  whilelabel
                        (cond
                           ((not (not (atom (setq u (cdr u)))) ) (return nil)))
                        (progn (p_princ op nil) (p_prefix (car u) p1))
                        (go whilelabel))
                     (cond ((greaterp prec 2) (p_princ ")" nil)))
                     (return nil))))
            (cond
               ((equal op 'difference)
                  (return (p_prefix (p_diff2minus (cdr u)) prec)))
               ((equal op 'plus)
                  (progn
                     (cond ((greaterp prec 1) (p_princ "(" nil)))
                     (p_prefix (car (setq u (cdr u))) 1)
                     (prog nil
                  whilelabel
                        (cond
                           ((not (not (atom (setq u (cdr u)))) ) (return nil)))
                        (progn
                           (setq p1 (car u))
                           (cond
                              ((eqcar p1 'minus)
                                 (progn
                                    (setq p1 (cadr p1))
                                    (p_princ " - " nil)))
                              (t (p_princ " + " nil)))
                           (p_prefix p1 1))
                        (go whilelabel))
                     (cond ((greaterp prec 1) (p_princ ")" nil)))
                     (return nil)))
               ((equal op 'minus)
                  (progn
                     (p_princ "-" nil)
                     (cond ((lessp prec 2) (setq prec 2)))
                     (return (p_prefix (cadr u) prec)))) )
            (cond
               ((or (not (atom op)) (and (numberp op) (minusp op)))
                  (progn (p_princ "(" nil) (p_prefix op 0) (p_princ ")" nil)))
               (t (p_princ op nil)))
            (setq op "(")
            (cond
               ((atom (setq u (cdr u))) (p_princ "(" nil))
               (t (prog (x)
                     (setq x u)
               lab   (cond ((null x) (return nil)))
                     ((lambda (x)
                         (progn (p_princ op nil) (setq op ",") (p_prefix x 0)))
                        (car x))
                     (setq x (cdr x))
                     (go lab))))
            (return (p_princ ")" nil)))) ))

(de prin_with_margin (u)
   (print_with_margin_sub
      u
      (posn)
      (difference (linelength nil) 2)
      (function explode)))

(de princ_with_margin (u)
   (print_with_margin_sub
      u
      (posn)
      (difference (linelength nil) 2)
      (function explode2)))

(de print_with_margin (u) (progn (prin_with_margin u) (terpri) u))

(de printc_with_margin (u) (progn (princ_with_margin u) (terpri) u))

(de print_with_margin_sub (u left right explfn)
   (prog (v)
      (cond ((lessp right 10) (setq right 10)))
      (cond
         ((greaterp left (difference right 10))
            (setq left (difference right 10))))
      (setq v u)
      (cond
         ((not (atom v))
            (progn
               (cond ((geq (posn) right) (progn (terpri) (ttab left))))
               (prin2 "(")
               (print_with_margin_sub (car v) left right explfn)
               (prog nil
            whilelabel
                  (cond ((not (not (atom (setq v (cdr v)))) ) (return nil)))
                  (progn
                     (cond
                        ((geq (posn) right) (progn (terpri) (ttab left)))
                        (t (prin2 " ")))
                     (print_with_margin_sub (car v) left right explfn))
                  (go whilelabel))
               (cond
                  ((not (null v))
                     (progn
                        (cond
                           ((geq (posn) (difference right 1))
                              (progn (terpri) (ttab left) (prin2 ". ")))
                           (t (prin2 " .")))
                        (print_with_margin_sub v left right explfn))))
               (cond ((geq (posn) right) (progn (terpri) (ttab left))))
               (prin2 ")")
               (return u))))
      (setq v (apply explfn (list u)))
verylong
      (cond
         ((lessp (plus (posn) (length v)) right)
            (progn
               (prog (c)
                  (setq c v)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (prin2 c)) (car c))
                  (setq c (cdr c))
                  (go lab))
               (return u)))
         ((leq (length v) (difference right left))
            (progn
               (terpri)
               (ttab left)
               (prog (c)
                  (setq c v)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (prin2 c)) (car c))
                  (setq c (cdr c))
                  (go lab))
               (return u)))
         ((lessp (length v) right)
            (progn
               (terpri)
               (ttab (difference right (length v)))
               (prog (c)
                  (setq c v)
            lab   (cond ((null c) (return nil)))
                  ((lambda (c) (prin2 c)) (car c))
                  (setq c (cdr c))
                  (go lab))
               (return u)))
         (t (progn
               (cond
                  ((geq (posn) (difference right 5))
                     (progn (terpri) (ttab left))))
               (prog nil
            whilelabel
                  (cond
                     ((not (lessp (posn) (difference right 1))) (return nil)))
                  (progn (prin2 (car v)) (setq v (cdr v)))
                  (go whilelabel))
               (prin2 "\")
               (terpri)
               (go verylong)))) ))

(de bldmsg_internal (fmt args)
   (prog (bldmsg_chars!* u v)
      (declare (special bldmsg_chars!*))
      (setq bldmsg_chars!* t)
      (printf_internal fmt args)
      (prog nil
   whilelabel
         (cond ((not (not (atom bldmsg_chars!*))) (return nil)))
         (progn
            (setq u (cdr bldmsg_chars!*))
            (rplacd bldmsg_chars!* v)
            (setq v bldmsg_chars!*)
            (setq bldmsg_chars!* u))
         (go whilelabel))
      (return (list2widestring v))))

(de p_posn nil
   (cond
      (bldmsg_chars!*
         (prog (w n)
            (setq n 0)
            (setq w bldmsg_chars!*)
            (prog nil
         whilelabel
               (cond
                  ((not (and (not (atom w)) (not (equal (car w) !$eol!$))))
                     (return nil)))
               (progn (setq n (plus n 1)) (setq w (cdr w)))
               (go whilelabel))
            (return n)))
      (t (posn))))

(global '(p_hexdigits!*))

(setq p_hexdigits!* (mkvect 15))

(putv p_hexdigits!* 0 '!0)

(putv p_hexdigits!* 1 '!1)

(putv p_hexdigits!* 2 '!2)

(putv p_hexdigits!* 3 '!3)

(putv p_hexdigits!* 4 '!4)

(putv p_hexdigits!* 5 '!5)

(putv p_hexdigits!* 6 '!6)

(putv p_hexdigits!* 7 '!7)

(putv p_hexdigits!* 8 '!8)

(putv p_hexdigits!* 9 '!9)

(putv p_hexdigits!* 10 'a)

(putv p_hexdigits!* 11 'b)

(putv p_hexdigits!* 12 'c)

(putv p_hexdigits!* 13 'd)

(putv p_hexdigits!* 14 'e)

(putv p_hexdigits!* 15 'f)

(de p_prinhex (n)
   (cond
      ((not (fixp n)) (p_princ "<not-a-number>" nil))
      (t (prog (b w)
            (cond
               ((geq n 0)
                  (progn
                     (prog nil
                  whilelabel
                        (cond ((not (geq n 16)) (return nil)))
                        (progn
                           (setq b
                              (cons (getv p_hexdigits!* (setq w (mod n 16))) b))
                           (setq n (quotient (difference n w) 16)))
                        (go whilelabel))
                     (setq b (cons (getv p_hexdigits!* (mod n 16)) b))))
               (t (progn
                     (prog nil
                  whilelabel
                        (cond ((not (lessp n (minus 1))) (return nil)))
                        (progn
                           (setq b
                              (cons (getv p_hexdigits!* (setq w (mod n 16))) b))
                           (setq n (quotient (difference n w) 16)))
                        (go whilelabel))
                     (setq b
                        (cons '!~ (cons (getv p_hexdigits!* (mod n 16)) b)))) ))
            (cond
               ((and
                   (null bldmsg_chars!*)
                   (greaterp (plus (posn) (length b)) !*ll!*))
                  (terpri)))
            (prog (c)
               (setq c b)
         lab   (cond ((null c) (return nil)))
               ((lambda (c) (p_princ c nil)) (car c))
               (setq c (cdr c))
               (go lab)))) ))

(de p_prinoctal (n)
   (cond
      ((not (fixp n)) (p_princ "<not-a-number>" nil))
      (t (prog (b w)
            (cond
               ((geq n 0)
                  (progn
                     (prog nil
                  whilelabel
                        (cond ((not (geq n 8)) (return nil)))
                        (progn
                           (setq b (cons (setq w (mod n 8)) b))
                           (setq n (quotient (difference n w) 8)))
                        (go whilelabel))
                     (setq b (cons (mod n 8) b))))
               (t (progn
                     (prog nil
                  whilelabel
                        (cond ((not (lessp n (minus 1))) (return nil)))
                        (progn
                           (setq b (cons (setq w (mod n 8)) b))
                           (setq n (quotient (difference n w) 8)))
                        (go whilelabel))
                     (setq b (cons '!~ (cons (mod n 8) b)))) ))
            (cond
               ((and
                   (null bldmsg_chars!*)
                   (greaterp (plus (posn) (length b)) !*ll!*))
                  (terpri)))
            (prog (c)
               (setq c b)
         lab   (cond ((null c) (return nil)))
               ((lambda (c) (p_princ c nil)) (car c))
               (setq c (cdr c))
               (go lab)))) ))

(de printf_internal (fmt args)
   (prog (a c !*ll!*)
      (declare (special !*ll!*))
      (setq !*ll!* (difference (linelength nil) 2))
      (setq fmt (explode2 fmt))
      (prog nil
   whilelabel
         (cond ((not fmt) (return nil)))
         (progn
            (setq c (car fmt))
            (setq fmt (cdr fmt))
            (cond
               ((neq c '!%) (p_princ c nil))
               (t (progn
                     (setq c (car fmt))
                     (setq fmt (cdr fmt))
                     (cond
                        ((equal c 'f)
                           (progn
                              (cond
                                 ((and
                                     (not bldmsg_chars!*)
                                     (not (zerop (posn))))
                                    (terpri)))) )
                        ((or (equal c 'n) (equal c '!N)) (p_princ !$eol!$ nil))
                        ((equal c '!%) (p_princ c nil))
                        (t (progn
                              (cond
                                 ((null args) (setq a nil))
                                 (t (progn
                                       (setq a (car args))
                                       (setq args (cdr args)))) )
                              (cond
                                 ((and (or (equal c 'b) (equal c '!B)) (fixp a))
                                    (prog (i)
                                       (setq i 1)
                                 lab   (cond
                                          ((minusp (difference a i))
                                             (return nil)))
                                       (p_princ " " nil)
                                       (setq i (plus2 i 1))
                                       (go lab)))
                                 ((or (equal c 'c) (equal c '!C))
                                    (progn
                                       (cond
                                          ((fixp a)
                                             (p_princ
                                                (list2widestring (list a))
                                                nil))
                                          (t (p_princ a nil)))) )
                                 ((or (equal c 'l) (equal c '!L))
                                    (progn
                                       (cond
                                          ((not (atom a))
                                             (progn
                                                (portable_princ (car a))
                                                (prog (x)
                                                   (setq x (cdr a))
                                             lab   (cond
                                                      ((null x) (return nil)))
                                                   ((lambda (x)
                                                       (progn
       (p_princ " " nil)
       (portable_princ x)))
                                                      (car x))
                                                   (setq x (cdr x))
                                                   (go lab)))) )))
                                 ((or (equal c 'o) (equal c '!O))
                                    (p_prinoctal a))
                                 ((or (equal c 'p) (equal c '!P))
                                    (portable_prin a))
                                 ((or (equal c 'q) (equal c '!Q))
                                    (prinl a))
                                 ((or (equal c 'r) (equal c '!R))
                                    (progn
                                       (p_princ "'" nil)
                                       (prinl a)
                                       (p_princ "'" nil)))
                                 ((and (or (equal c 't) (equal c '!T)) (fixp a))
                                    (progn
                                       (cond
                                          ((greaterp (p_posn) a)
                                             (p_princ !$eol!$ nil)))
                                       (prog nil
                                    whilelabel
                                          (cond
                                             ((not (lessp (p_posn) a))
                                                (return nil)))
                                          (p_princ " " nil)
                                          (go whilelabel))))
                                 ((or
                                     (equal c 'w)
                                     (equal c 'd)
                                     (equal c 's)
                                     (equal c '!W)
                                     (equal c '!D)
                                     (equal c '!S))
                                    (portable_princ a))
                                 ((or (equal c 'x) (equal c '!X)) (p_prinhex a))
                                 ((equal c '!@)
                                    (progn
                                       (setq c (car fmt))
                                       (setq fmt (cdr fmt))
                                       (cond
                                          ((or (equal c 'f) (equal c '!F))
                                             (p_prefix (prepf a) 0))
                                          ((or (equal c 'q) (equal c '!Q))
                                             (p_prefix (prepsq a) 0))
                                          ((or (equal c 'p) (equal c '!P))
                                             (p_prefix a 0))
                                          (t (progn
                                                (p_princ "%@" nil)
                                                (p_princ c nil)))) ))
                                 (t (progn
                                       (p_princ "%" nil)
                                       (p_princ c nil)))) ))) ))) )
         (go whilelabel))))

(dm printf (u) (list 'printf_internal (cadr u) (cons 'list (cddr u))))

(dm bldmsg (u) (list 'bldmsg_internal (cadr u) (cons 'list (cddr u))))

(flag '(printf bldmsg) 'variadic)

