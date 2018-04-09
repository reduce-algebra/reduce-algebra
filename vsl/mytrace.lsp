
(de newname (n)
   (intern (compress (cons '~ (explode n)))))

(de myargcount (ff)
  (if (member 'psl lispsystem*)
      (code-number-of-arguments (getfcodepointer ff))
      (length (caddr (getd ff)))))

(de mytrace (name)
  (prog (g d a r nargs l)
    (cond
       ((null (getd name)) (return (list '***** name 'not 'defined)))
       ((flagp name 'traced) (return (list '***** name 'traced 'already)))
       ((flagp name 'lose)
        (remflag (list name) 'lose)
        (setq l t)))
    (setq nargs (myargcount name))
    (setq g (newname name))
    (copyd g name)
    (while (not (zerop nargs))
      (progn
        (setq nargs (sub1 nargs))
        (setq a (cons (gensym) a))))
    (setq r (gensym))
    (putd name 'expr (list 'lambda a
       (list 'prog (list r)
         (list 'myprintargs (list 'quote name) (cons 'list a))
         (list 'setq r (cons g a))
         (list 'myprintresult (list 'quote name) r)
         (list 'return r))))
    (cond
       (l (flag (list name) 'lose)))
    (flag (list name) 'traced)
    (return name)))

(de myprintwidth (u)
  (length (explode u)))

(de myprin (u)
  (cond
    ((atom u)
      (when (greaterp (plus (posn) (myprintwidth u)) 60) (terpri))
      (prin1 u))
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

(de myprintargs (name args)
  (prog (i)
    (prin2 "Calling ") (print name)
    (setq i 0)
    (while args
      (progn
        (prin2 "arg") (prin2 (setq i (add1 i))) (prin2 ": ")
        (myprin (car args))
        (terpri)
        (setq args (cdr args))))))

(de myprintresult (name value)
  (prin1 name)
  (princ " = ")
  (myprin value)
  (terpri))

% end of mytrace.lsp
