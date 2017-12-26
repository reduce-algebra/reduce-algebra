% This is a collection of commonly useful Lisp
% functions that can be defined in terms of the
% things that are built into vsl. The idea is that
% going
%     ./vsl -z library.lsp
% will create an image file vsl.img that can be loaded
% next time vsl is started, so that the cold-start
% flag (-z) does not then have to be used and all these
% extra functions will be available.

% Because this uses (preserve) this will only work on full vsl
% not minivsl.

(setq blank   '! )
(setq tab     (code!-char 9))
(setq !$eol!$ (code!-char 10))
(setq dollar  '!$)
(setq lpar    '!()
(setq rpar    '!))
(setq f       nil)

(de caar (x)                     % Shorthands for combinations of car/cdr.
    (car (car x)))

(de cadr (x)
    (car (cdr x)))

(de cdar (x)
    (cdr (car x)))

(de cddr (x)
    (cdr (cdr x)))

(de caaar (x)
    (car (car (car x))))

(de caadr (x)
    (car (car (cdr x))))

(de cadar (x)
    (car (cdr (car x))))

(de caddr (x)
    (car (cdr (cdr x))))

(de cdaar (x)
    (cdr (car (car x))))

(de cdadr (x)
    (cdr (car (cdr x))))

(de cddar (x)
    (cdr (cdr (car x))))

(de cdddr (x)
    (cdr (cdr (cdr x))))

(de caaaar (x)
    (car (car (car (car x)))))

(de caaadr (x)
    (car (car (car (cdr x)))))

(de caadar (x)
    (car (car (cdr (car x)))))

(de caaddr (x)
    (car (car (cdr (cdr x)))))

(de cadaar (x)
    (car (cdr (car (car x)))))

(de cadadr (x)
    (car (cdr (car (cdr x)))))

(de caddar (x)
    (car (cdr (cdr (car x)))))

(de cadddr (x)
    (car (cdr (cdr (cdr x)))))

(de cdaaar (x)
    (cdr (car (car (car x)))))

(de cdaadr (x)
    (cdr (car (car (cdr x)))))

(de cdadar (x)
    (cdr (car (cdr (car x)))))

(de cdaddr (x)
    (cdr (car (cdr (cdr x)))))

(de cddaar (x)
    (cdr (cdr (car (car x)))))

(de cddadr (x)
    (cdr (cdr (car (cdr x)))))

(de cdddar (x)
    (cdr (cdr (cdr (car x)))))

(de cddddr (x)
    (cdr (cdr (cdr (cdr x)))))

(de not (x)
   (null x))

(de idp (x)
   (symbolp x))

(de pairp (x)
   (null (atom x)))


(de reverse (x)
   (prog (y)
   loop
      (cond ((null x) (return y)))
      (setq y (cons (car x) y))
      (setq x (cdr x))
      (go loop)))

(de reversip_sub (a b)
   (prog (w)
   loop
      (cond ((null a) (return b)))
      (setq w (cdr a))
      (rplacd a b)
      (setq b a)
      (setq a w)
      (go loop)))

(de reversip (x) (reversip_sub x nil)) % Destructive reverse

(de append (a b)                % Append a pair of lists.
   (cond
      ((null a) b)
      (t (cons (car a) (append (cdr a) b)))))

(de length (l)                  % Find length of a list.
   (cond
      ((null l) 0)
      (t (add1 (length (cdr l))))))

(de last (l)                    % Last element of a (non-empty) list.
   (cond
      ((null l) (error 1 "last on emtpy list"))
      ((null (cdr l)) (car l))
      (t (last (cdr l)))))

(de lastcar (x)         % Not in Standard Lisp
   (cond
      ((null x) nil)
      ((null (cdr x)) (car x))
      (t (lastcar (cdr x)))))

(de lastpair (l)                % Last pair of a (non-empty) list.
   (cond
      ((null l) nil)
      ((null (cdr l)) l)
      (t (lastpair (cdr l)))))

(de member (a l)
   (cond
      ((null l) nil)
      ((equal a (car l)) l)
      (t (member a (cdr l)))))

(de memq (a l)
   (cond
      ((null l) nil)
      ((eq a (car l)) l)
      (t (memq a (cdr l)))))

(de delete (a l)
   (cond
      ((null l) nil)
      ((equal a (car l)) (cdr l))
      (t (cons (car l) (delete a (cdr l))))))

(de intersection (a b)
   (cond
      ((null a) nil)
      ((member (car a) b) (cons (car a) (intersection (cdr a) b)))
      (t (intersection (cdr a) b))))

(de union (a b)
   (cond
      ((null a) b)
      ((member (car a) b) (union (cdr a) b))
      (t (cons (car a) (union (cdr a) b)))))

(de neq (a b)                  % Not equal.
   (null (equal a b)))

(de eqcar (a b)                % Is (car a) the same as b?
   (and (not (atom a)) (eq (car a) b)))

(de assoc (a l)                % Look item up in association list.
   (cond
      ((null l) nil)
      ((and (not (atom (car l)))
            (equal (caar l) a)) (car l))
      (t (assoc a (cdr l)))))

(de atsoc (a l)                % Look item up in association list.
   (cond
      ((null l) nil)
      ((and (not (atom (car l)))
            (eq (caar l) a)) (car l))
      (t (atsoc a (cdr l)))))

(de subst (a b c)              % Substitute a for b in c
   (cond
      ((equal b c) a)
      ((atom c) c)
      (t (cons (subst a b (car c)) (subst a b (cdr c))))))

(de sublis (x y)
   (if (null x) y
      (prog (u)
         (setq u (assoc y x))
         (return (cond
            ((not (atom u)) (cdr u))
            ((atom y) y)
            (t (cons (sublis x (car y))
               (sublis x (cdr y)))))))))

(de subla (x y)
   (if (null x) y
      (prog (u)
         (setq u (atsoc y x))
         (return (cond
            ((not (atom u)) (cdr u))
            ((atom y) y)
            (t (cons (subla x (car y))
               (subla x (cdr y)))))))))

(de pair (u v)
   (cond
      ((or (atom u) (atom v)) nil)
      (t (cons (cons (car u) (car v)) (pair (cdr u) (cdr v))))))

(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

(de prettyprint (x)            % Display something with indentation.
   (terpri)
   (pprint x 0)
   (terpri)
   nil)

(de pprint (x n)               % Sub-function for prettyprint.
   (cond
      ((or (atom x)
           (lessp (length (explode x)) 40)) (prin x))
      (t (princ "(")
         (pprint (car x) (add1 n))
         (pprintail (cdr x) (plus n 3)))))

(de pprintail (x n)            % Sub-function for prettyprint.
   (cond
      ((null x) (princ ")"))
      ((atom x) (princ " . ")
                (prin x)
                (princ ")"))
      (t (terpri)
         (spaces n)
         (pprint (car x) n)
         (pprintail (cdr x) n))))


(de rplacw (a b) (progn (rplaca a (car b)) (rplacd a (cdr b))))

(de expand (l fn)
   (cond
      ((null (cdr l)) (car l))
      (t (list fn (car l) (expand (cdr l) fn)))))

(de mapcar (l fn)
  (prog (r)
 top (cond ((null l) (return (reversip r))))
     (setq r (cons (apply fn (list (car l))) r))
     (setq l (cdr l))
     (go top)))

(de maplist (l fn)
  (prog (r)
 top (cond ((null l) (return (reversip r))))
     (setq r (cons (apply fn (list l)) r))
     (setq l (cdr l))
     (go top)))

(de mapcan (l fn)
  (cond ((null l) nil)
	(t (nconc (apply fn (list (car l))) (mapcan (cdr l) fn)))))

(de mapcon (l fn)
  (cond ((null l) nil)
	(t (nconc (apply fn (list l)) (mapcon (cdr l) fn)))))

(de mapc (l fn)
  (prog ()
 top (cond ((null l) (return nil)))
     (apply fn (list (car l)))
     (setq l (cdr l))
     (go top)))

(de map (l fn)
  (prog ()
 top (cond ((null l) (return nil)))
     (apply fn (list l))
     (setq l (cdr l))
     (go top)))

(de copy (a)
   (cond
      ((atom a) a)
      (t (cons (copy (car a)) (copy (cdr a))))))

(de sassoc (a l fn)
  (cond
     ((atom l) (apply fn nil))
     ((equal a (caar l)) (car l))
     (t (sassoc a (cdr l) fn))))

(de rassoc (x l)        % Not in Standard Lisp
   (prog ()
loop  (cond ((atom l) (return nil))
	    ((equal x (cdar l)) (return (car l)))
	    (t (setq l (cdr l)) (go loop))) ))


(de deflist (a b)
  (prog (r)
top (cond ((null a) (return (reversip r))))
    (put (caar a) b (cadar a))
    (setq r (cons (caar a) r))
    (setq a (cdr a))
    (go top)))

(de expand_backquote (x)
   (cond
      ((and (symbolp x) (null (null x))) (list 'quote x))
      ((atom x) x)                  % nil, number or string
      ((eq (car x) '!,) (cadr x))
      ((eqcar (car x) '!,!@)
         (list 'append (cadar x) (expand_backquote (cdr x))))
      (t (list 'cons (expand_backquote (car x)) (expand_backquote (cdr x))))))

(dm !` (x) (expand_backquote (cadr x)))

(de macroexpand_cond (l)
   (cond
      ((null l) nil)
      (t (cons (macroexpand_list (car l))
               (macroexpand_cond (cdr l))))))

(de macroexpand (x)
   (cond
      ((atom x) x)
      ((not (atom (car x)))
         (cons (macroexpand (car x))
               (macroexpand_list (cdr x))))
      ((eqcar x 'quote) x)
      ((eqcar x 'cond)
         (cons 'cond (macroexpand_cond (cdr x))))
      ((or (eqcar x 'prog) (eqcar x 'lambda))
         (cons (car x) (cons (cadr x)
            (macroexpand_list (cddr x)))))
      ((eqcar (getd (car x)) 'macro)
         (macroexpand (apply (cdr (getd (car x)))
                             (list x))))
      (t (cons (car x) (macroexpand_list (cdr x))))))

(de macroexpand_list (l)
   (cond
      ((null l) nil)
      (t (cons (macroexpand (car l))
               (macroexpand_list (cdr l))))))

% Now a few things not needed by Standard Lisp but maybe helpful
% when using Lisp directly.

(dm !~let (x)              % (!~let ((v1 E1) (v2 E2) ...) body)
   (cons (cons 'lambda (cons (mapcar (cadr x) 'car) (cddr x)))
         (mapcar (cadr x) 'cadr)))

(de expand_let!* (b x)
   (cond
      ((null b) x)
      (t (list (list 'lambda (list (caar b)) (expand_let!* (cdr b) x))
               (cadar b)))))

(dm let!* (x)            % As !~let, but do bindings sequentially
   (expand_let!* (cadr x) (cons 'progn (cddr x))))

(dm if (x)          % (IF predicate yes no)
   `(cond
      (,(cadr x) ,(caddr x))
      (t ,(cond ((atom (cdddr x)) nil) (t (car (cdddr x)))))))

(dm when (x)        % (WHEN predicate yes yes yes ...)
   `(cond
      (,(cadr x) ,@(cddr x))))

(dm while (x)       % (WHILE predicate body body body ...)
   (!~let ((g (gensym)))
      `(prog nil
       ,g (cond ((null ,(cadr x)) (return nil)))
          ,@(cddr x)
          (go ,g)))))

(de make_psetq_vars (u)
   (if (null u)
       nil
       (if (null (cdr u))
           (error "odd number of items in psetq")
           (cons (gensym) (make_psetq_vars (cddr u))))))

(de make_psetq_bindings (vars u)
   (if (null u)
       nil
       (cons
          (list (car vars) (cadr u))
          (make_psetq_bindings (cdr vars) (cddr u)))))

(de make_psetq_assignments (vars u)
   (if (null u)
       nil
       (cons
          (list 'setq (car u) (car vars))
          (make_psetq_assignments (cdr vars) (cddr u)))))

(dm psetq (x)             % parallel setq as in (psetq x X y Y z Z)
   (!~let ((vars (make_psetq_vars (cdr x))))
      `(let!* ,(make_psetq_bindings vars (cdr x))
              ,@(make_psetq_assignments vars (cdr x)))))

% (do ((var init step) ..)
%     (endcondition result ...)
%     body)

(de do_bindings (u)
   (if (null u)
       nil
       (if (atom (car u))
           (cons (car u) (do_bindings (cdr u)))
           (if (null (cdar u))
               (cons (list (caar u) nil) (do_bindings (cdr u)))
               (cons (list (caar u) (cadar u)) (do_bindings (cdr u)))))))

(de do_endtest (u)
   (if (null u)
       nil
       (car u)))

(de do_result (u)
   (if (null u)
       nil
       (cdr u)))

(de do_updates (u)
   (if (null u)
       nil
       (!~let ((v (car u))
             (x (do_updates (cdr u))))
          (if (or (atom v)
                  (null (cdr v))
                  (null (cddr v)))
              x
              (cons (car v) (cons (caddr v) x))))))

(de expand_do (u letter setter)
   (let!* ((bindings (do_bindings (car u)))
           (result (do_result (cadr u)))
           (updates (do_updates (car u)))
           (body (cddr u))
           (endtest (do_endtest (cadr u)))
           (upd (if updates (list (cons setter updates)) nil))
           (res (if (null result)
                    nil
                    (if (null (cdr result))
                        (car result)
                        (cons 'progn result))))
           (x (if (null endtest) nil
                  `((when ,endtest (return ,res)))))
           (g (gensym)))
      (if bindings
         `(,letter ,bindings
             (prog nil
            ,g  ,@x
                ,@body
                ,@upd
                (go ,g)))
         `(prog nil
         ,g    ,@x
               ,@body
               ,@upd
               (go ,g)))))

(dm do (u) (expand_do (cdr u) '!~let 'psetq))

(dm do!* (u) (expand_do (cdr u) 'let!* 'setq))

(de expand_dolist (vir b)
   (prog (l v var init res)
     (setq var (car vir))
     (setq init (car (setq vir (cdr vir))))
     (setq res (cdr vir))
     (setq v (gensym))
     (setq l (gensym))
     (return `(prog (,v ,var)
                (setq ,v ,init)
            ,l  (cond ((null ,v) (return (progn ,@res))))
                (setq ,var (car ,v))
                ,@b
                (setq ,v (cdr ,v))
                (go ,l)))))

(dm dolist (u) (expand_dolist (cadr u) (cddr u)))

(de expand_dotimes (vnr b)
   (prog (l v var count res)
     (setq var (car vnr))
     (setq count (car (setq vnr (cdr vnr))))
     (setq res (cdr vnr))
     (setq v (gensym))
     (setq l (gensym))
     (return `(prog (,v ,var)
                (setq ,v ,count)
                (setq ,var 0)
           ,l   (cond ((geq ,var ,v) (return (progn ,@res))))
                ,@b
                (setq ,var (add1 ,var))
                (go ,l)))))

(dm dotimes (u) (expand_dotimes (cadr u) (cddr u)))

(de nconc (u v)
   (if (atom u) v
      (!~let ((w u))
         (while (not (atom (cdr u))) (setq u (cdr u)))
         (rplacd u v)
         w)))

% Up to here this is as in library.lsp

(de ensure_defined (v)
   (when (atom (errorset v nil nil))
         (eval (list 'setq v nil))))

(de fluid (x)
   (remflag x 'global)
   (flag x 'fluid)
   (dolist (v x) (ensure_defined v)))

(de global (x)
   (remflag x 'fluid)
   (flag x 'global)
   (dolist (v x) (ensure_defined v)))

(de fluidp (x) (flagp x 'fluid))

(de globalp (x) (flagp x 'global))

(de flag (l tag)
   (dolist (v l) (put v tag t)))

(de remflag (l tag)
   (dolist (v l) (remprop v tag)))

(de flagp (v tag) (get v tag))

(de prin2 (x) (princ x))
(de explode2 (x) (explodec x))

(de liter (x)
   (!~let ((c (char!-code x)))
      (or (and (leq 65 c) (leq c 90))
          (and (leq 97 c) (leq c 122)))))

(de digit (x)
   (!~let ((c (char!-code x)))
      (and (leq 48 c) (leq c 57))))

(de intern (x) x)

(de mapobl (f)
  % Apply F to every interned ID
  (mapc (oblist f))

(setq !*raise nil)
(setq !*lower t)

(de putd (name type def)
   (cond
      ((eq type 'expr)
         (eval (cons 'de (cons name (cdr def)))))
      ((eq type 'macro)
         (eval (cons 'dm (cons name (cdr def)))))
      (t (error "unknown type in putd" type))))

(de date () "1 Feb 2012")

(de mkquote (x) (list 'quote x))

(de apply1 (fn a1) (apply fn (list a1)))

(de apply2 (fn a1 a2) (apply fn (list a1 a2)))

(de apply3 (fn a1 a2 a3) (apply fn (list a1 a2 a3)))

(de special!-char (n)
   (cond
      ((equal n 0) (code!-char 32))
      ((equal n 1) (code!-char 10))
      ((equal n 2) (code!-char 8))
      ((equal n 3) (code!-char 9))
      ((equal n 4) (code!-char 11))
      ((equal n 5) (code!-char 12))
      ((equal n 6) (code!-char 13))
      ((equal n 7) (code!-char 127))
      ((equal n 8) !$eof!$)
      ((equal n 9) (code!-char 7))
      ((equal n 10) (code!-char 27))
      (t (error "special-char" n))))

(de expt (a n)
   (cond
      ((zerop n) 1)
      ((onep n) a)
      ((minusp n) (expt (quotient 1.0 a) (minus n)))
      ((zerop (remainder n 2)) (expt (times a a) (quotient n 2)))
      (t (times a (expt (times a a) (quotient (sub1 n) 2))))))

(setq small!-modulus 3)

(de set!-small!-modulus (n)
   (!~let ((r small!-modulus))
      (setq small!-modulus n)
      r))

(de small!-modular!-number (n)
   (setq n (remainder n small!-modulus))
   (when (minusp n) (setq n (plus n small!-modulus)))
   n)

(de small!-modular!-plus (a b)
   (small!-modular!-number (plus a b)))

(de small!-modular!-difference (a b)
   (small!-modular!-number (difference a b)))

(de small!-modular!-times (a b)
   (small!-modular!-number (times a b)))

(de small!-modular!-minus (a)
   (small!-modular!-number (minus a)))

(de small!-modular!-quotient (a b)
   (error "small-modular-quotient not implemented yet" (cons a b)))

(de tolower (x)
   (!~let ((c (char!-code x)))
      (if (and (leq 65 c) (leq c 90))
          (code!-char (plus c 32))
          x)))

(de explode2lc (x)
    (mapcar (explodec x) 'tolower))

(de set!-print!-precision (n) n)

(de constantp (x)
   (or (null x)
       (numberp x)
       (stringp x)
       (eq x t)))

(dm iplus (x) (cons 'plus (cdr x)))
(dm itimes (x) (cons 'times (cdr x)))
(dm ilogand (x) (cons 'logand (cdr x)))
(dm ilogor (x) (cons 'logor (cdr x)))
(dm ilogxor (x) (cons 'logxor (cdr x)))

(de idifference (a b) (difference a b))
(de iquotient (a b) (quotient a b))
(de iremainder (a b) (remainder a b))
(de ilessp (a b) (lessp a b))
(de ileq (a b) (leq a b))
(de igreaterp (a b) (greaterp a b))
(de igeq (a b) (geq a b))
(de iequal (a b) (equal a b))

(de iplus2 (a b) (plus2 a b))
(de itimes2 (a b) (times2 a b))
(de ilogand2 (a b) (logand2 a b))
(de ilogor2 (a b) (logor2 a b))
(de ilogxor2 (a b) (logxor2 a b))

(de iadd1 (a) (add1 a))
(de isub1 (a) (sub1 a))
(de iminus (a) (minus a))
(de iminusp (a) (minusp a))

(de boundp (x)
   (not (atom (errorset x nil nil))))

(dm declare (x) nil)

(de ordp (u v)
   (cond
      ((null u) (null v))
      ((vectorp u) (cond
         ((vectorp v) (ordpv u v))
         (t (atom v))))
      ((atom u) (cond
         ((atom v) (cond
            ((numberp u) (and (numberp v) (not (lessp u v))))
            ((idp v) (orderp u v))
            (t (numberp v))))
         (t nil)))
      ((atom v) t)
      ((equal (car u) (car v)) (ordpl (cdr u) (cdr v)))
      ((flagp (car u) 'noncom) (cond
         ((flagp (car v) 'noncom) (ordp (car u) (car v)))
         (t t)))
      ((flagp (car v) 'noncom) nil)
      (t (ordp (car u) (car v)))))

(de ordpl (u v)
   (cond
      ((atom u) (ordp u v))
      ((equal (car u) (car v)) (ordpl (cdr u) (cdr v)))
      (t (ordp (car u) (car v)))))

(de ordpv (u v)
    (error "ordpv not yet implemented" (cons u v)))

(de orderp (u v)
   (prog ()
      (setq u (explodec u))
      (setq v (explodec v))
      (while (and u v (eq (car u) (car v)))
         (setq u (cdr u) v (cdr v)))
      (cond
         ((and u v)
            (return (lessp (char!-code (car u)) (char!-code (car v)))))
         (v (return t))
         (t (return nil)))))

(dm function (x) (cons 'quote (cdr x)))

(de sort (items fn)
   (prog (tree)
      (dolist (x items)
         (setq tree (sort_insert x tree fn)))
      (return (sort_flatten tree))))

(de sort_insert (item tree fn)
   (cond
      ((null tree) (list!* item nil nil))
      ((apply2 fn item (car tree))
         (sort_insertleft item tree fn))
      (t (sort_insertright item tree fn))))

(de sort_insertleft (item tree fn)
   (list!*
      (car tree)
      (sort_insert item (cadr tree) fn)
      (cddr tree)))

(de sort_insertright (item tree fn)
   (list!*
      (car tree)
      (cadr tree)
      (sort_insert item (cddr tree) fn)))

(de sort_flatten (x)
   (cond
      ((null x) nil)
      (t (append (sort_flatten (cadr x))
         (cons (car x) (sort_flatten (cddr x)))))))

(de gcdn (a b)
   (cond
      ((minusp a) (gcdn (minus a) b))
      ((minusp b) (gcdn a (minus b)))
      ((greaterp b a) (gcdn b a))
      ((zerop b) a)
      (t (gcdn b (remainder a b)))))

(de abs (x)
   (if (minusp x) (minus x) x))

(de max (a b)
   (if (greaterp a b) a b))

(de min (a b)
   (if (lessp a b) a b))

(de msd (n)
   (prog (r)
      (setq r 0)
      (while (not (zerop n))
         (setq n (quotient n 2))
         (setq r (add1 r)))
      (return r)))

(de lsd (n)
   (if (zerop n)
      0
      (prog (r)
         (setq r 0)
         (while (zerop (remainder n 2))
            (setq n (quotient n 2))
            (setq r (add1 r)))
         (return r))))

(de ash (a n) (leftshift a n))

(de ash1 (a n)
   (if (minusp a) (minus (leftshift (minus a) n)) (leftshift a n)))

(de remd (x) (print (list 'remd 'called 'on x)))

(de modulep (x) nil)

(de verbos (x) nil)

(de linelength (n) 80)

(de getenv (x) nil)

(de filep (x) nil)

(de plus2 (a b) (plus a b))
(de times2 (a b) (times a b))
(de logand2 (a b) (logand a b))
(de logor2 (a b) (logor a b))
(de logxor2 (a b) (logxor a b))

(de lengthc (x) (length (explodec x)))

(de gctime () 0)

(de setpchar (x) nil)

(de eqn (a b) (equal a b))

(de threevectorp (x)
   (and (vectorp x) (equal (upbv x) 2)))

(de frexp (x)
   (prog (n)
      (if (zerop x) (return '(0 . 0.0)))
      (setq n 0)
      (while (geq x 1.0)
             (setq x (times x 0.5))
             (setq n (add1 n)))
      (while (lessp x 0.5)
             (setq x (times x 2.0))
             (setq n (sub1 n)))
      (return (cons n x))))

% End of vslcompat.lsp


