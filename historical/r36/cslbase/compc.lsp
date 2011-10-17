(global '(s!:c_name s!:c_file s!:lisp_name s!:lisp_file))


(dm c!:printf (u) (list 'c!:printf1 (cadr u) (cons 'list (cddr u))))


(de c!:printf1 (fmt args)
   (prog (a c)
      (setq fmt (explode2 fmt))
      (prog nil
   !G67  (cond ((not fmt) (return nil)))
         (progn
            (setq c (car fmt))
            (setq fmt (cdr fmt))
            (cond
               ((and (equal c '!\) (equal (car fmt) 'n))
                  (progn (terpri) (setq fmt (cdr fmt))))
               ((and (equal c '!\) (equal (car fmt) 'q))
                  (progn (princ '!") (setq fmt (cdr fmt))))
               ((equal c '!%)
                  (progn
                     (setq c (car fmt))
                     (setq fmt (cdr fmt))
                     (setq a (car args))
                     (setq args (cdr args))
                     (cond
                        ((equal c 'v)
                           (cond
                              ((flagp a 'c!:live_across_call)
                                 (progn
                                    (princ "stack[")
                                    (princ (minus (get a 'c!:location)))
                                    (princ "]")))
                              (t (princ a))))
                        ((equal c 'a) (prin a))
                        ((equal c 't) (ttab a))
                        (t (princ a)))) )
               (t (princ c))))
         (go !G67))))


(de open_output (name) (open name 'output))


(de s!:cstart (module_name)
   (prog (w)
      (verbos nil)
      (princ "Start of compilation into C for ")
      (prin module_name)
      (terpri)
      (setq w (cons '!" (explodec module_name)))
      (setq s!:c_name (compress (append w '(!. c !"))))
      (setq s!:lisp_name (compress (append w '(!. l s p !"))))
      (setq s!:c_file (open_output s!:c_name))
      (setq s!:lisp_file (open_output s!:lisp_name))
      (cond ((and s!:c_file s!:lisp_file) (return t)))
      (cond (s!:c_file (close s!:c_file)))
      (cond (s!:lisp_file (close s!:lisp_file)))
      (return nil)))


(de s!:cinit (u)
   (prog (o)
      (setq o (wrs s!:lisp_file))
      (princ "Initform: ")
      (prinl u)
      (terpri)
      (wrs o)))


(de s!:cend nil
   (prog nil
      (close s!:c_file)
      (setq s!:c_file nil)
      (close s!:lisp_file)
      (setq s!:lisp_file nil)
      (return nil)))


(de s!:cgen (name nargs body env)
   (prog (w fgg)
      (princ "Cgen:  ")
      (prin name)
      (terpri)
      (princ "nargs: ")
      (prin nargs)
      (terpri)
      (cond
         ((greaterp nargs 10)
            (progn
               (terpri)
               (princ "++++++ Functions with > 10 args or &optional, &rest")
               (terpri)
               (princ "       arge can not be compiled into C")
               (terpri)
               (return 'failed))))
      (prog (l)
         (setq l (reverse body))
   lab   (cond ((null l) (return nil)))
         ((lambda (l)
             (progn
                (prin (car l))
                (princ ": ")
                (setq w (reverse (cdddr l)))
                (cond ((and (not fgg) (greaterp nargs 3)) (setq w (cddr w))))
                (setq fgg t)
                (prog (x)
                   (setq x w)
             lab   (cond ((null x) (return nil)))
                   ((lambda (x) (progn (princ " ") (prin x))) (car x))
                   (setq x (cdr x))
                   (go lab))
                (princ "  ")
                (prin (cadr l))
                (terpri)))
            (car l))
         (setq l (cdr l))
         (go lab))))


