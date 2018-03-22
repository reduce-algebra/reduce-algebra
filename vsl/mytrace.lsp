
(de newname (n)
   (intern (compress (cons '~ (explode n)))))

(de argcount (ff)
  (if (member 'psl lispsystem*)
      (code-number-of-arguments (getfcodepointer ff))
      (length (caddr (getd ff)))))

(de mytrace (name)
  (prog (g d a r nargs)
    (setq nargs (argcount name))
    (setq g (newname name))
    (copyd g name)
    (while (not (zerop nargs))
      (progn
        (setq nargs (sub1 nargs))
        (setq a (cons (gensym) a))))
    (setq r (gensym))
    (putd name 'expr (list 'lambda a
       (list 'prog (list r)
         (list 'printargs (list 'quote name) (cons 'list a))
         (list 'setq r (cons g a))
         (list 'printresult (list 'quote name) r)
         (list 'return r))))
    (return name)))

(de printwidth (u)
  (length (explode u)))

(de myprin (u)
  (cond
    ((atom u)
      (when (greaterp (plus (posn) (printwidth u)) 60) (terpri))
      (prin u))
    (t (prog (sep)
      (setq sep '!()
      (while (not (atom u)) (progn
        (when (greaterp (posn) 60) (terpri))
        (prin2 sep)
        (setq sep '! )
        (myprin (car u))
        (setq u (cdr u))))
    (cond
      (u
        (when (greaterp (posn) 58) (terpri))
        (prin2 " . ")
        (myprin u)))
    (when (greaterp (posn) 60) (terpri))
    (prin2 '!))))))

(de printargs (name args)
  (prog (i)
    (prin2 "Calling ") (print name)
    (setq i 0)
    (while args
      (progn
        (prin2 "arg") (prin2 (setq i (add1 i))) (prin2 ": ")
        (myprin (car args))
        (terpri)
        (setq args (cdr args))))))

(de printresult (name value)
  (prin name)
  (princ " = ")
  (myprin value)
  (terpri))

% end of mytrace.lsp

