% arithfns.lsp                          Copyright (C) A C Norman, 2016-2017


% The code here implements arbitrary precision arithmetic using lists
% of digits that are in the range 0 - 9. It has been written emphasising
% simplicity of code rather than even half reasonable performance, and
% so will be unfeasibly slow for real use. However I hope it will compute
% reference results that can be used to check the behaviour of the built-in
% Lisp arithmetic!
% To allow for comparison it assumes that LESSP, QUOTIENT and REMAINDER
% work on native numbers where the comparisons are against 10 and the
% divisions are by 10. It also supposes that native arithmetic on small
% integers (values less than 20) will work, since that is what is used in
% its implementation.

% **************************************************************************
% * Copyright (C) 2017, Codemist.                         A C Norman       *
% *                                                                        *
% * Redistribution and use in source and binary forms, with or without     *
% * modification, are permitted provided that the following conditions are *
% * met:                                                                   *
% *                                                                        *
% *     * Redistributions of source code must retain the relevant          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer.                                                      *
% *     * Redistributions in binary form must reproduce the above          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer in the documentation and/or other materials provided  *
% *       with the distribution.                                           *
% *                                                                        *
% * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
% * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
% * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
% * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
% * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
% * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
% * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
% * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
% * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
% * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
% * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
% * DAMAGE.                                                                *
% *************************************************************************/


(de mynum (n)
  (validate!-number n "mynum")
  (cond
    ((zerop n) nil)
    ((minusp n) (cons '!- (mynum (validate!-number (minus n) "negated"))))
    ((lessp n 10) (list n))
    (t (append (mynum (validate!-number (quotient n 10) (list "quotient" n 10)))
                (list (validate!-number (remainder n 10) "remainder"))))))

(de mynum1 (n)
  (cond
     ((numberp n) (mynum n))
     ((consp n) (cons (mynum1 (car n)) (mynum1 (cdr n))))
     (t n)))

(de myzerop (a)
  (equal a nil))

(de myonep (a)
  (equal a '(1)))

(de myminusp (a)
  (eqcar a '!-))

(de myabs (a)
  (cond
    ((eqcar a '!-) (cdr a))
    (t a)))

(de myplusp (a)
  (and (not (null a))
       (not (eqcar a '!-))))

(de myminus (a)
  (cond
    ((eqcar a '!-) (cdr a))
    ((null a) nil)
    (t (cons '!- a))))

% Note that numbers are stored most significant digit first and in sign
% and magnitude form.

(de mygreaterp (a b)
  (cond
    ((eqcar a '!-)
      (cond
        ((eqcar b '!-) (mygreaterp (cdr b) (cdr a)))
        (t nil)))
    ((eqcar b '!-) t)
    ((equal a b) nil)
    ((greaterp (length a) (length b)) t)
    ((lessp (length a) (length b)) nil)
    ((null a) nil)
    ((equal (car a) (car b)) (mygreaterp (cdr a) (cdr b)))
    (t (greaterp (car a) (car b)))))

(de mylessp (a b) (mygreaterp b a))

(de mygeq (a b) (not (mygreaterp b a)))

(de myleq (a b) (not (mygreaterp a b)))

(de myplus (a b)
  (cond
    ((eqcar a '!-) (mydifference b (cdr a)))
    ((eqcar b '!-) (mydifference a (cdr b)))
    ((null a) b)
    ((null b) a)
    (t (myadd (reverse a) (reverse b) 0))))

(de mydifference (a b)
  (cond
    ((eqcar a '!-) (myminus (myplus b (cdr a))))
    ((eqcar b '!-) (myplus a (cdr b)))
    ((null a) (myminus b))
    ((null b) a)
    ((mygreaterp a b) (mysubtract (reverse a) (reverse b) 0))
    (t (myminus (mysubtract (reverse b) (reverse a) 0)))))

(de myadd1 (a)
  (myplus a '(1)))

(de mysub1 (a)
  (mydifference a '(1)))

% myadd and mysubtract and internal arithmetic on unsigned values where the
% result will be positive. Ha ha ha they take arguments in least significant
% digit first order and an extra argument for carry/borrow.

(de myadd (a b c)
  (prog (d r)
top (cond
      ((and (null a) (null b) (zerop c)) (return r)))
    (cond
      ((null a) (setq d c))
      (t (progn (setq d (plus (car a) c))
         (setq a (cdr a)))))
    (cond
      (b (progn (setq d (plus d (car b)))
         (setq b (cdr b)))))
% d is now the next digit
    (cond
      ((greaterp d 9) (progn 
        (setq d (difference d 10))
        (setq c 1)))
      (t (setq c 0)))
    (setq r (cons d r))
    (go top)))

(de mysubtract (a b c)  % Here a >= b, and the "carry" is either 0 or -1
  (prog (d r)
top (cond
      ((and (null a) (zerop c)) (go done)))
    (cond
      ((null a) (setq d c))
      (t (progn (setq d (plus (car a) c))
         (setq a (cdr a)))))
    (cond
      (b (progn (setq d (difference d (car b)))
         (setq b (cdr b)))))
% d is now the next digit
    (cond
      ((minusp d) (progn
        (setq d (plus d 10))
        (setq c -1)))
      (t (setq c 0)))
    (setq r (cons d r))
    (go top)
done(cond
      ((or (null r) (not (zerop (car r)))) (return r)))
    (setq r (cdr r))
    (go done)))

(de myhalve (a)
  (cond
    ((eqcar a '!-) (myminus (myhalve (myminus a))))
    (t (setq a (myhalve1 a))
      (cond
        ((eqcar a 0) (cdr a))
        (t a)))))

(de myhalve1 (a) % divide a positive number by 2. This code may leave
                 % a (single) leading zero which must be trimmed away.
  (cond
    ((null a) nil)
    ((null (cdr a)) (list (quotient (car a) 2)))
    ((evenp (car a)) (cons (quotient (car a) 2) (myhalve1 (cdr a))))
    (t (cons (quotient (car a) 2)
         (myhalve1 (cons (plus 10 (cadr a)) (cddr a)))))))

(myhalve '(1 0 0))
(myhalve '(5 0))
(myhalve '(2 5))

(de mydouble (a) (myplus a a))

(de myoddp (a)
  (and a (oddp (last a))))

(de myevenp (a)
  (or (null a) (evenp (last a))))

(de mytimes (a b)
  (cond
    ((eqcar a '!-) (myminus (mytimes (cdr a) b)))
    ((eqcar b '!-) (myminus (mytimes a (cdr b))))
    ((null a) nil)
    ((equal a '(1)) b)
    ((myevenp a) (mydouble (mytimes (myhalve a) b)))
    (t (myplus (mydouble (mytimes (myhalve a) b)) b))))

(de myexpt (a n)
  (cond
    ((zerop n) '(1))
    ((onep n) a)
    ((evenp n) (setq n (myexpt a (quotient n 2)))
               (mytimes n n))
    (t (setq n (myexpt a (quotient n 2)))
       (mytimes a (mytimes n n)))))


% (de myquotient (a b)
%   (cond
%     ((eqcar a '!-) (myminus (myquotient (cdr a) b)))
%     ((eqcar b '!-) (myminus (myquotient a (cdr b))))
%     ((null a) nil)
%     ((equal b '(1)) a)
%     ((mylessp a b) nil)
%     (t (myquotient1 a b))))
%
% (de myquotient1 (a b)
%   (cond
%     ((mylessp a b) nil)
%     ((mylessp a (mydouble b)) '(1))
%     (t (prog (w)
%       (setq w (mydouble (myquotient1 (myhalve a) b)))
%       (return (myplus w (myquotient1 (mydifference a (mytimes w b)) b)))))))
%
%
% (de myremainder (a b)
%   (mydifference a (mytimes (myquotient a b) b)))

(de mydivide (a b)
  (prog (a1 a2 q1 r1 q r w w1)
%(terpri)
%(princ "a=") (print a)
%(princ "b=") (print b)
    (setq a1 (myvalof a))
    (setq a2 (myvalof b))
%(princ "a1=") (print a1)
%(princ "a2=") (print a2)
%(princ "b=") (print b)
%(princ "a=") (print a)
    (setq a2 (myvalof b))
    (setq a1 (myvalof a))
%(princ "a2=") (print a2)
%(princ "a1=") (print a1)
%(princ "a=") (print a)
%(princ "b=") (print b)
    (setq a1 (myvalof a))
    (setq a2 (myvalof b))
%(princ "a1=") (print a1)
%(princ "a2=") (print a2)
    (setq w (divide a1 a2))
    (setq q (mynum (car w)))
    (setq r (mynum (cdr w)))
%(princ "w=") (print w)
%(princ "q=") (print q)
%(princ "r=") (print r)
    (setq w1 (myplus (mytimes q b) r))
%(princ "w1=") (print w1)
    (cond
       ((not (equal w1 a)) (progn
        (princ "Divide  ") (print a)
        (princ "by ") (print b)
        (princ "giving ") (print w)
        (princ "q*b+r = ") (print w1)
        (error 1 "Problem with division"))))
    (cond
       ((not (null r))
          (cond
             ((or (and (myminusp a) (not (myminusp r)))
                  (and (not (myminusp a)) (myminusp r)))
              (error 1 "Problem with sign of remainder")))))
    (cond
      ((mygreaterp (myabs b) (myabs r)) nil)
      (t (error 1 "Problem with magnitude of remainder")))
    (return (cons q r))))
    
(de myquotient (a b)
  (car (mydivide a b)))

(de myremainder (a b)
  (cdr (mydivide a b)))


(de mymod (a b)  % sign of result must match sign of b
  (prog (c)
    (setq c (myremainder a b))
    (cond
       ((and (myminusp b) (myplusp c)) (return (myplus b c)))
       ((and (myplusp b) (myminusp c)) (return (myplus b c)))
       (t (return c)))))

(de mylshift (a n)
  (cond
     ((zerop n) a)
     ((greaterp n 0) (mytimes a (mynum (expt 2 n))))
     ((not (eqcar a '!-)) (myquotient a (mynum (expt 2 (minus n)))))
     (t (mydifference (myquotient (myplus a '(1))
             (mynum (expt 2 (minus n)))) '(1)))))

(de mylognot (n)
  (myplus (myminus n) '(!- 1)))

% An  issue about logand and logor is the graceful treatment of all the
% infinite number of leading 1 bits implicit with negative values. I cope
% with this by use of DeMorgan so that I either end up doing OR on two
% positive numbers or AND on numbers where at least the first is positive.

(de mylogand!-bin (a b)
  (cond
    ((or (null a) (null b)) nil)
    ((and (equal a '(!- 1)) (equal b '(!- 1))) a)
    ((myevenp a)
      (cond
        ((myevenp b)
         (append (mylogand!-bin (myhalve a) (myhalve b)) '(0)))
        (t (append (mylogand!-bin (myhalve a) (myhalve (mysub1 b))) '(0)))))
    (t
      (cond
        ((myevenp b)
         (append (mylogand!-bin (myhalve (mysub1 a)) (myhalve b)) '(0)))
        (t (append (mylogand!-bin (myhalve (mysub1 a)) (myhalve (mysub1 b)))
             '(1)))))))

(de flipbits (a)
  (cond
    ((null a) nil)
    ((eqcar a 0) (cons 1 (flipbits (cdr a))))
    (t (cons 0 (flipbits (cdr a))))))

(de mybinnum (a)
  (cond
    ((eqcar a '!-) (mylognot (mybinnum (flipbits (cdr a)))))
    ((null a) nil)
    ((zerop (car a)) (mybinnum (cdr a)))
    (t (prog (r)
     top (cond
           ((null a) (return r)))
         (setq r (mydouble r))
         (cond
           ((not (zerop (car a))) (setq r (myadd1 r))))
         (setq a (cdr a))
         (go top)))))

(de mylogand (a b)
  (mybinnum (mylogand!-bin a b)))

(de mylogor!-bin (a b)
  (cond
    ((or (equal a '(!- 1)) (equal b '(!- 1))) '(!- 1))
    ((and (null a) (null b)) nil)
    ((myevenp a)
      (cond
        ((myevenp b)
         (append (mylogor!-bin (myhalve a) (myhalve b)) '(0)))
        (t (append (mylogor!-bin (myhalve a) (myhalve (mysub1 b))) '(1)))))
    (t
      (cond
        ((myevenp b)
         (append (mylogor!-bin (myhalve (mysub1 a)) (myhalve b)) '(1)))
        (t (append (mylogor!-bin (myhalve (mysub1 a)) (myhalve (mysub1 b)))
             '(1)))))))

(de mylogor (a b)
  (mybinnum (mylogor!-bin a b)))

(de mylogxor!-bin (a b)
  (cond
    ((and (equal a '(!- 1)) (equal b '(!- 1))) nil)
    ((and (null a) (null b)) nil)
    ((and (equal a '(!- 1)) (null b)) '(!- 1))
    ((and (null a) (equal b '(!- 1))) '(!- 1))
    ((myevenp a)
      (cond
        ((myevenp b)
         (append (mylogxor!-bin (myhalve a) (myhalve b)) '(0)))
        (t (append (mylogxor!-bin (myhalve a) (myhalve (mysub1 b))) '(1)))))
    (t
      (cond
        ((myevenp b)
         (append (mylogxor!-bin (myhalve (mysub1 a)) (myhalve b)) '(1)))
        (t (append (mylogxor!-bin (myhalve (mysub1 a)) (myhalve (mysub1 b)))
             '(0)))))))

(de mylogxor (a b)
  (mybinnum (mylogxor!-bin a b)))

(de mylogeqv (a b)
  (mylognot (mylogxor a b)))

%(trace '(mylogand!-bin mybinnum))

%(mylogand '(3 3) '(1 7))
%(mylogand '(!- 3 3) '(1 7))
%(mylogand '(!- 3 3) '(!- 1 7))
%(stop)

(de myprinhex (n)
  (cond
    ((null n) (princ "0"))
    ((eqcar n '!-) (progn (princ "~f") (myprinneg (myplus (myminus n) '(!- 1)))))
    (t (myprinpos n))))

(de myvalof (n)
  (prog (r)
    (cond
      ((eqcar n '!-) (return (minus (myvalof (cdr n))))))
    (setq r 0)
top (cond
      ((null n) (return r)))
    (setq r (plus (times r 10) (car n)))
    (setq n (cdr n))
    (go top)))

(de myprinpos (n)
  (cond
    ((mylessp n '(1 6)) (prinhex (myvalof n)))
    (t (progn (myprinpos (myquotient n '(1 6)))
       (prinhex (myvalof (myremainder n '(1 6))))))))

(de myprinneg (n)
  (cond
    ((mylessp n '(1 6)) (prinhex (logxor 15 (myvalof n))))
    (t (progn (myprinneg (mylshift n -4))
       (prinhex (logxor 15 (myvalof (mymod n '(1 6)))))))))


%+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

% The function that is being checked is called using "funcall" which
% calls it as from the interpreter. That means that if the compiler
% generates in-line code that will need checking independently and if the
% bytecode interpreter has its own special version of anything that too
% will need special treatment...

(de check!-one!-arg (native mine a)
  (prog (r1 r2)
    (validate!-number a (list "one arg" native mine))
    (setq r1
      (mynum1
        (validate!-number (funcall native a)
          (list "one arg result" native mine a))))
    (setq r2 (funcall mine (mynum a)))
    (cond ((equal r1 r2) (return nil)))
    (terpri)
    (princ "+++ Failure with ") (print native)
    (princ "(setq a ") (prin a) (printc ")")
    (princ "computed: ") (prin r1) (princ " ") (myprinhex r1) (terpri)
    (princ "reference:") (prin r2) (princ " ") (myprinhex r2) (terpri)
    (representation a t)
    (representation (funcall native a) t)
    (terpri)
    (printc "+++ Stopping")
    (stop)))

(de check!-minus (a)
  (check!-one!-arg 'minus 'myminus a))

(de check!-one!-plus!-int!-arg (native mine a n)
  (prog (r1 r2)
    (validate!-number a (list "one+n arg" native mine))
    (validate!-number n (list "one+n arg" native mine))
    (setq r1
      (mynum1
        (validate!-number (funcall native a n)
          (list "one+n arg result" native mine a n))))
    (setq r2 (funcall mine (mynum a) n))
    (cond ((equal r1 r2) (return nil)))
    (terpri)
    (princ "+++ Failure with ") (print native)
    (princ "(setq a ") (prin a) (printc ")")
    (princ "(setq n ") (prin n) (printc ")")
    (princ "computed: ") (prin r1) (princ " ") (myprinhex r1) (terpri)
    (princ "reference:") (prin r2) (princ " ") (myprinhex r2) (terpri)
    (representation a t)
    (representation n t)
    (representation (funcall native a n) t)
    (stop)))

(de check!-lshift (a n)
  (check!-one!-plus!-int!-arg 'lshift 'mylshift a n))

(de check!-two!-args (native mine a b)
  (prog (r1 r2)
    (validate!-number a (list "two args" native mine a b))
    (validate!-number b (list "two args" native mine a b))
    (setq r1
      (mynum1
        (validate!-number (funcall native a b)
          (list "two args result" native mine a b))))
    (setq r2 (funcall mine (mynum a) (mynum b)))
    (cond ((equal r1 r2) (return nil)))
    (terpri)
    (princ "+++ Failure with ") (print native)
    (princ "(setq a ") (prin a) (printc ")")
    (princ "(setq b ") (prin b) (printc ")")
    (princ "computed: ") (prin r1) (princ " ") (myprinhex r1) (terpri)
    (princ "reference:") (prin r2) (princ " ") (myprinhex r2) (terpri)
    (representation a t)
    (representation b t)
    (representation (funcall native a b) t)
    (terpri)
    (printc "+++ Stopping")
    (stop)))

(de check!-plus (a b)
  (check!-two!-args 'plus 'myplus a b))

(de check!-difference (a b)
  (check!-two!-args 'difference 'mydifference a b))

(de check!-times (a b)
  (check!-two!-args 'times 'mytimes a b))

(de check!-quotient (a b)
  (check!-two!-args 'quotient 'myquotient a b))

(de check!-mod (a b)
  (check!-two!-args 'mod 'mymod a b))

(de check!-remainder (a b)
  (check!-two!-args 'remainder 'myremainder a b))

(de check!-logand (a b)
  (check!-two!-args 'logand 'mylogand a b))

(de check!-logor (a b)
  (check!-two!-args 'logor 'mylogor a b))

(de check!-logxor (a b)
  (check!-two!-args 'logxor 'mylogxor a b))

(de check!-logeqv (a b)
  (check!-two!-args 'logeqv 'mylogeqv a b))

(de check!-greaterp (a b)
  (check!-two!-args 'greaterp 'mygreaterp a b))


% My expectation is that boundary cases will be most frequent with operands
% near a power of 2, and so I will arrange to check all cases that are
% 2^k-1, 2^k, 2^k+1 or the negative of one of those. I will also check
% these values when combined with 0.

(fluid '(onlydivide))
(setq onlydivide nil)

(de checkall (a b mode)
  (cond
    ((and (eq mode 'quotient) (not (zerop b))) (progn
      (check!-quotient a b)
      (check!-mod a b)
      (check!-remainder a b)))
    ((eq mode 'plus) (progn
      (check!-plus a b)
      (check!-difference a b)
      (check!-greaterp a b)))
    (t
% Well CSL switches to a separate algorithm for integer multiplication
% when numbers get bigger that somewhere around 400 bits - specifically it
% uses Karatsuba's method and uses three threads to do some of the work
% in parallel. The code here does not check huge cases like that! It probably
% ought to.
      (progn
      (check!-times a b)
      (check!-logand a b)
      (check!-logor a b)
      (check!-logxor a b)
      (check!-logeqv a b))))
  nil)

(de checksigns (a b mode)
(prog nil
  (checkall a b mode)
  (checkall (validate!-number (minus a) "minus") b mode)
  (checkall a (validate!-number (minus b) "minus") mode)
  (checkall (minus a) (minus b) mode)))

(de checknear (a b mode)
  (prog nil
  (checksigns a b mode)
  (checksigns (validate!-number (plus a 1) "add1")  b mode) 
  (checksigns (validate!-number (plus a -1) "sub1") b mode) 
  (checksigns a (validate!-number (plus b 1) "add1") mode) 
  (checksigns a (validate!-number (plus b -1) "sub1") mode) 
  (checksigns (plus a 1) (plus b 1) mode) 
  (checksigns (plus a 1) (plus b -1) mode)
  (checksigns (plus a -1) (plus b 1) mode) 
  (checksigns (plus a -1) (plus b -1) mode)
% I want a bunch of pseudo-random tests as well as the deterministic ones
% that explore near predicted edge cases... Note that I have set things
% up so when this test is run it seeds the random number systsem based on
% the time of day and similar things that should mean that multiple runs
% do not purely replicate work that has already been done.
  (cond
    ((and (not (zerop a))
          (not (zerop b))
          (not (onep b))
          (not (onep (minus b))))
% I arrange that the second arg can never be zero here...
      (progn
      (checksigns a (validate!-number (add1 (random!-number b)) "random") mode)
      (checksigns (plus a 1) (validate!-number (add1 (random!-number b)) "random") mode)
      (checksigns (plus a -1) (validate!-number (add1 (random!-number b)) "random") mode)
      (checksigns (validate!-number (random!-number a) "random") b mode)
      (checksigns (validate!-number (random!-number a) "random") (plus b 1) mode)
      (checksigns (validate!-number (random!-number a) "random") (plus b -1) mode)
      (checksigns (validate!-number (random!-number a) "random") (validate!-number (add1 (random!-number b)) "random") mode)
      (checksigns (validate!-number (random!-number a) "random") (validate!-number (add1 (random!-number b)) "random") mode)
      (checksigns (validate!-number (random!-number a) "random") (validate!-number (add1 (random!-number b)) "random") mode)))))
   )

(de checkall1 (a)
   (prog nil
  (check!-minus a)
  (dotimes (i 140)
     (check!-lshift a (difference i 70)))
  ))

(de checksigns1 (a)
  (prog nil
  (checkall1 a)
  (checkall1 (validate!-number (minus a) "minus"))))

(de checknear1 (a)
  (prog nil
  (checksigns1 a)
  (checksigns1 (validate!-number (plus a 1) "add1")) 
  (checksigns1 (validate!-number (plus a -1) "sub1"))))

% end of arithfns.lsp

