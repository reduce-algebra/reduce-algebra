% arithtest.lsp                                   Copyright A C Norman 2019

% This is intended to help me to test (and hence debug) my new
% arithlib.hpp based arithmetic code in CSL. It runs a numeber of
% calculations in old existing and prospective arithmetic and compares
% results. Values in the two bignum representations can be compared by
% looking at their printed representations.

% Released under BSD license.

% $Id$


(setq !*echo t !*comp t)

(cond ((null (getd 'newplus))
       (terpri)
       (printc " *** This needs a copy of csl configured using --with-arithlib")
       (stop)))

(fluid '(old new w))

% At present I will not be testing using the value 0. That is mainly because
% it causes pain in division. I will need a separate set of tests to
// combine it with other values.

(setq old (setq new '(1 -1)))


(fluid '(a b))
(setq w 10)

% I generate random numbers, some positive some negative...

(dotimes (i 100)
   (setq w (times w 3))
   (setq a (add1 (random!-number w)))
   (setq b (compress (cons '!0 (cons '!Z (explode a)))))
   (setq old (cons a old))
   (setq new (cons b new))
   (setq a (add1 (random!-number w)))
   (setq b (compress (cons '!0 (cons '!Z (explode a)))))
   (setq old (cons (minus a) old))
   (setq new (cons (newminus b) new))
   )

(equal (explode old) (explode new))

(setq w (reverse (pair old new)))

(de check1 (a1 fold fnew)
  (cond
    ((equal (explode (funcall fold (car a1)))
            (explode (funcall fnew (cdr a1)))) nil)
    (t (terpri)
       (printc "*** Error ***")
       (print a1)
       (print fold)
       (print (funcall fold (car a1)))
       (print fnew)
       (print (funcall fnew (cdr a1)))
       (stop 1))))

(de check2 (a1 a2 fold fnew)
  (cond
    ((equal (explode (funcall fold (car a1) (car a2)))
            (explode (funcall fnew (cdr a1) (cdr a2)))) nil)
    (t (terpri)
       (printc "*** Error ***")
       (print a1)
       (print a2)
       (print fold)
       (print (funcall fold (car a1) (car a2)))
       (print fnew)
       (print (funcall fnew (cdr a1) (cdr a2)))
       (stop 1))))

(dolist (x w)
  (check1 x 'minus 'newminus)
  (check1 x 'minusp 'newminusp)
  (check1 x 'add1 'newadd1)
  (check1 x 'sub1 'newsub1)
  (check1 x 'evenp 'newevenp)
  (check1 x 'oddp 'newoddp)
  (check1 x 'lognot 'newlognot)
  )


(dolist (x w)
  (dolist (y w)
    (check2 x y 'plus 'newplus)
    (check2 x y 'difference 'newdifference)
    (check2 x y 'times 'newtimes)
    (check2 x y 'quotient 'newquotient)
    (check2 x y 'remainder 'newremainder)
    (check2 x y 'greaterp 'newgreaterp)
    (check2 x y 'lessp 'newlessp)
    (check2 x y 'geq 'newgeq)
    (check2 x y 'leq 'newleq)
    (check2 x y 'eqn 'neweqn)
    (check2 x y 'logand 'newlogand)
    (check2 x y 'logor 'newlogor)
    (check2 x y 'logxor 'newlogxor)
    (check2 x y 'logeqv 'newlogeqv)
    ))

% Now add a pile of floating point values to the list of test cases

(dolist (xy w)
  (setq w (cons (cons (float (car xy)) (newfloat (cdr xy))) w)))

(dolist (x w)
  (check1 x 'minus 'newminus)
  (check1 x 'minusp 'newminusp)
  (check1 x 'add1 'newadd1)
  (check1 x 'sub1 'newsub1)
  (check1 x 'evenp 'newevenp)
  (check1 x 'oddp 'newoddp)
  (check1 x 'float 'newfloat)
  (check1 x 'floor 'newfloor)
  (check1 x 'ceiling 'newceiling)
  (check1 x 'fix 'newfix)
  (check1 x 'frexp 'newfrexp)
  )

(dolist (x w)
  (dolist (y w)
    (check2 x y 'plus 'newplus)
    (check2 x y 'difference 'newdifference)
    (check2 x y 'times 'newtimes)
    (check2 x y 'quotient 'newquotient)
    (check2 x y 'remainder 'newremainder)
    (check2 x y 'greaterp 'newgreaterp)
    (check2 x y 'lessp 'newlessp)
    (check2 x y 'geq 'newgeq)
    (check2 x y 'leq 'newleq)
    (check2 x y 'eqn 'neweqn)
    ))

(stop)

