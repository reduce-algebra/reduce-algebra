% Standard LISP BOOT File.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All Rights Reserved.

(fluid '(fname!* !*blockp !*lower !*mode !*raise))

(global '(oldchan!*))

(global '(crchar!* cursym!* nxtsym!* ttype!* !$eol!$))

(put '!; 'switch!* '(nil !*semicol!*))

(put '!( 'switch!* '(nil !*lpar!*))

(put '!) 'switch!* '(nil !*rpar!*))

(put '!, 'switch!* '(nil !*comma!*))

(put '!. 'switch!* '(nil cons))

(put '!= 'switch!* '(nil equal))

(put '!: 'switch!* '(((!= nil setq)) !*colon!*))

(put '!< 'switch!* '(((!= nil leq) (!< nil !*lsqbkt!*)) lessp))

(put '!> 'switch!* '(((!= nil geq) (!> nil !*rsqbkt!*)) greaterp))

% When the real parser is loaded the function mkprec will reset all
% precedence values here. So until then please fully parenthesize
% any expressions.

(put '!*comma!* 'infix 1)

(put 'setq 'infix 2)

(put 'cons 'infix 3)

(put 'equal 'infix 4)

(put 'eq 'infix 5)

(flag '(!*comma!*) 'nary)

(flag '(!*colon!* !*semicol!* end then else) 'delim)

(put 'begin 'stat 'blockstat)

(put 'if 'stat 'ifstat)

(put 'symbolic 'stat 'procstat)

(de begin2 nil
   (prog nil
      (setq cursym!* '!*semicol!*)
a     (cond
         ((eq cursym!* 'end) (progn (rds oldchan!*) (return nil)))
         (t (prin2 (errorset '(eval (form (xread nil))) t t)) ))
      (go a)))

(de form (u) u)

(de xread (u) (progn (scan) (xread1 u)))

(de xread1 (u)
   (prog (v w x y z z2)
a     (setq z cursym!*)
a1    (cond
         ((or (null (atom z)) (numberp z)) (setq y nil))
         ((flagp z 'delim) (go end1))
         ((eq z '!*lpar!*) (go lparen))
         ((eq z '!*rpar!*) (go end1))
         ((and w (setq y (get z 'infix))) (go infx))
         ((setq y (get z 'stat)) (go stat)))
a3    (setq w (cons z w))
next  (setq z (scan))
      (go a1)
lparen(setq y nil)
      (cond
         ((eq (scan) '!*rpar!*)
            (and w (setq w (cons (list (car w)) (cdr w)))) )
         ((eqcar (setq z (xread1 'paren)) '!*comma!*)
            (setq w (cons (cons (car w) (cdr z)) (cdr w))))
         (t (go a3)))
      (go next)
infx  (setq z2 (mkvar (car w) z))
un1   (setq w (cdr w))
      (cond
         ((null w) (go un2))
         (t (setq z2 (cons (car w) (list z2)))) )
      (go un1)
un2   (setq v (cons z2 v))
preced(cond ((null x) (go pr4)) ((lessp y (car (car x))) (go pr2)))
pr1   (setq x (cons (cons y z) x))
      (go next)
pr2   (setq v
         (cons
            (cond
               ((and (eqcar (car v) (cdar x)) (flagp (cdar x) 'nary))
                  (cons (cdar x) (cons (cadr v) (cdar v))))
               (t (cons (cdar x) (list (cadr v) (car v)))) )
            (cdr (cdr v))))
      (setq x (cdr x))
      (go preced)
stat  (setq w (cons (eval (list y)) w))
      (setq y nil)
      (go a)
end1  (cond
         ((and (and (null v) (null w)) (null x)) (return nil))
         (t (setq y 0)))
      (go infx)
pr4   (cond ((null (equal y 0)) (go pr1)) (t (return (car v)))) ))

(de eqcar (u v) (and (null (atom u)) (eq (car u) v)))

(de mksetq (u v) (list 'setq u v))

(de mkvar (u v) u)

(de rread nil
   (prog (x)
      (setq x (token))
      (return
         (cond
            ((and (equal ttype!* 3) (eq x '!()) (rrdls))
            (t x)))) )

(de rrdls nil
   (prog (x r)
a     (setq x (rread))
      (cond
         ((null (equal ttype!* 3)) (go b))
         ((eq x '!)) (return (reverse r)))   % REVERSIP not yet defined.
         ((null (eq x '!.)) (go b)))
      (setq x (rread))
      (token)
      (return (nconc (reverse r) x))
b     (setq r (cons x r))
      (go a)))

(de token nil
   (prog (x y)
      (setq x crchar!*)
a     (cond
         ((seprp x) (go sepr))
         ((digit x) (go number))
         ((liter x) (go letter))
         ((eq x '!%) (go coment))
         ((eq x '!!) (go escape))
         ((eq x '!') (go quote))
         ((eq x '!") (go string)))
      (setq ttype!* 3)
      (cond ((delcp x) (go d)))
      (setq nxtsym!* x)
a1    (setq crchar!* (readch))
      (go c)
escape(setq y (cons x y))
      (setq x (readch))
letter(setq ttype!* 0)
let1  (setq y (cons x y))
      (cond
         ((or (digit (setq x (readch))) (liter x)) (go let1))
         ((eq x '!!) (go escape)))
      (setq nxtsym!* (intern (compress (reverse y))))
b     (setq crchar!* x)
c     (return nxtsym!*)
number(setq ttype!* 2)
num1  (setq y (cons x y))
      (cond ((digit (setq x (readch))) (go num1)))
      (setq nxtsym!* (compress (reverse y)))
      (go b)
quote (setq crchar!* (readch))
      (setq nxtsym!* (list 'quote (rread)))
      (setq ttype!* 4)
      (go c)
string(prog (raise !*lower)
         (setq raise !*raise)
         (setq !*raise nil)
   strinx(setq y (cons x y))
         (cond ((null (eq (setq x (readch)) '!")) (go strinx)))
         (setq y (cons x y))
         (setq nxtsym!* (mkstrng (compress (reverse y))))
         (setq !*raise raise))
      (setq ttype!* 1)
      (go a1)
coment(cond ((null (eq (readch) !$eol!$)) (go coment)))
sepr  (setq x (readch))
      (go a)
d     (setq nxtsym!* x)
      (setq crchar!* '! )
      (go c)))

(setq crchar!* '! )

(de delcp (u) (or (eq u '!;) (eq u '!$)))

(de mkstrng (u) u)

(de seprp (u) (or (eq u '! ) (eq u !$eol!$) (eq u '!
)))

(de scan nil
   (prog (x y)
      (cond ((null (eq cursym!* '!*semicol!*)) (go b)))
a     (setq nxtsym!* (token))
b     (cond
         ((or (null (atom nxtsym!*)) (numberp nxtsym!*)) (go l))
         ((and (setq x (get nxtsym!* 'newnam)) (setq nxtsym!* x))
            (go b))
         ((eq nxtsym!* 'comment) (go comm))
         ((and
             (eq nxtsym!* '!')
             (setq cursym!* (list 'quote (rread))))
            (go l1))
         ((null (setq x (get nxtsym!* 'switch!*))) (go l))
         ((eq (cadr x) '!*semicol!*)
            (return (setq cursym!* (cadr x)))) )
sw1   (setq nxtsym!* (token))
      (cond
         ((or
             (null (car x))
             (null (setq y (assoc nxtsym!* (car x)))) )
            (return (setq cursym!* (cadr x)))) )
      (setq x (cdr y))
      (go sw1)
comm  (cond ((eq (readch) '!;) (setq crchar!* '! )) (t (go comm)))
      (go a)
l     (setq cursym!*
         (cond
            ((null (eqcar nxtsym!* 'string)) nxtsym!*)
            (t (cons 'quote (cdr nxtsym!*)))) )
l1    (setq nxtsym!* (token))
      (return cursym!*)))

(de ifstat nil
   (prog (condx condit)
a     (setq condx (xread t))
      (setq condit (nconc condit (list (list condx (xread t)))) )
      (cond
         ((null (eq cursym!* 'else)) (go b))
         ((eq (scan) 'if) (go a))
         (t (setq condit
               (nconc condit (list (list t (xread1 t)))) )))
b     (return (cons 'cond condit))))

(de procstat nil
   (prog (x y)
      (cond ((eq cursym!* 'symbolic) (scan)))
      (cond
         ((eq cursym!* '!*semicol!*)
            (return (null (setq !*mode 'symbolic)))) )
      (setq fname!* (scan))
      (cond ((atom (setq x (xread1 nil))) (setq x (list x))))
      (setq y (xread nil))
      (cond ((flagp (car x) 'lose) (return nil)))
      (putd (car x) 'expr (list 'lambda (cdr x) y))
      (setq fname!* nil)
      (return (list 'quote (car x)))) )

(de blockstat nil
   (prog (x hold varlis !*blockp)
a0    (setq !*blockp t)
      (scan)
      (cond
         ((null (or (eq cursym!* 'integer) (eq cursym!* 'scalar)))
            (go a)))
      (setq x (xread nil))
      (setq varlis
         (nconc
            (cond ((eqcar x '!*comma!*) (cdr x)) (t (list x)))
            varlis))
      (go a0)
a     (setq hold (nconc hold (list (xread1 nil))))
      (setq x cursym!*)
      (scan)
      (cond ((not (eq x 'end)) (go a)))
      (return (mkprog varlis hold))))

(de mkprog (u v) (cons 'prog (cons u v)))

(de gostat nil
   (prog (x) (scan) (setq x (scan)) (scan) (return (list 'go x))))

(put 'go 'stat 'gostat)

(de rlis nil
   (prog (x)
      (setq x cursym!*)
      (return (list x (list 'quote (list (xread t)))))))

(de endstat nil (prog (x) (setq x cursym!*) (scan) (return (list x))))

% It is only a rather small number of lines of code to support
% both << >> blocks and WHILE statements here, and doing so makes
% it possible to write the full implementation of RLISP in a much
% more civilised way. What I put in here is a little more than is used
% to start with, but matches the eventual implementation. Eg the 'go
% and 'nodel are not relevant until the read parser has been loaded.

(de readprogn nil
   (prog (lst)
   a  (setq lst (cons (xread 'group) lst))
      (cond ((null (eq cursym!* '!*rsqbkt!*)) (go a)))
      (scan)
      (return (cons 'progn (reverse lst)))))

(put '!*lsqbkt!* 'stat 'readprogn)
(flag '(!*lsqbkt!*) 'go)
(flag '(!*rsqbkt!*) 'delim)
(flag '(!*rsqbkt!*) 'nodel)

% There is a "wonderful" mess here! The file support/pslprolo.red gives
% the symbol "do" a newnam that maps it onto "~do" when read. This is to
% avoid conflict with a PSL version of a FOR loop. A consequence is that
% up until pslprolo is read in the input characters "do" are read as the
% symbol with that simple name, while afterwards you get a version with
% a "~" stuck on the front. The test in the code here will continue to test
% for what it used to! So to survive parsing WHILE loops both before and
% after I need to allow for both spellings. 

(de whilstat ()
   (prog (!*blockp bool bool2)
      (cond
         ((flagp 'do 'delim) (setq bool2 t))
         (t (flag '(do !~do) 'delim)))
      (setq bool (xread t))
      (cond
         (bool2 (remflag '(do !~do) 'delim)))
      (cond
         ((and (not (eq cursym!* 'do))
               (not (eq cursym!* '!~do))) (symerr 'while t)))
      (return (list 'while bool (xread t)))))

(dm while (u)
   (prog (body bool lab)
      (setq bool (cadr u))
      (setq body (caddr u))
      (setq lab 'whilelabel)
      (return (list
         'prog nil
    lab  (list 'cond
            (list (list 'not bool) '(return nil)))
         body
         (list 'go lab)))))

(put 'while 'stat 'whilstat)
(flag '(while) 'nochange)

(de repeatstat ()
   (prog (!*blockp body bool)
      (cond
         ((flagp 'until 'delim) (setq bool t))
         (t (flag '(until) 'delim)))
      (setq body (xread t))
      (cond
         ((null bool) (remflag '(until) 'delim)))
      (cond
         ((not (eq cursym!* 'until)) (symerr 'repeat t)))
      (return (list 'repeat body (xread t)))))

(dm repeat (u)
   (progn (terpri) (print (prog (body bool lab)
      (setq body (cadr u))
      (setq bool (caddr u))
      (setq lab 'repeatlabel)
      (return (list
      'prog nil
    lab  body
         (list 'cond
            (list (list 'not bool) (list 'go lab))))))))))

(put 'repeat 'stat 'repeatstat)
(flag '(repeat) 'nochange)

% It is useful to have a temporary version of this in place until the
% real one gets compiled...
(de make!-string!-unique (x) x)

