
% This is a collection of commonly useful Lisp
% functions that can be defined in terms of the
% things that are built into vsl. 

% The vsl system supports big-number arithmetic via Lisp
% code in this file. It can not even read in numbers properly
% until arithmetic is working. So the next two definitions
% instate temporary versions of "plus2" and "times2" that will
% make it possible to read this file.

(de plus2 (u v) (iplus u v))

(de times2 (u v) (itimes u v))

(de minus (u) (iminus u))

% There are a number of pre-defined symbols that stand for
% characters and the like. Define them here.

(setq blank   '! )
(setq tab     (code!-char 9))
(setq !$eol!$ (code!-char 10))
(setq dollar  '!$)
(setq lpar    '!()
(setq rpar    '!))

(setq f       nil)

% The following names are used with "#\name" to get the character code of
% various special characters.

(put 'null      'charvalue 0)
(put 'bell      'charvalue 7)
(put 'backspace 'charvalue 8)
(put 'tab       'charvalue 9)
(put 'lf        'charvalue 10)
(put 'eol       'charvalue 10)
(put 'ff        'charvalue 12)
(put 'cr        'charvalue 13)
(put 'eof       'charvalue -1)
(put 'escape    'charvalue 27)
(put 'space     'charvalue 32)
(put 'rubout    'charvalue 8)
(put 'rub       'charvalue 8)
(put 'delete    'charvalue 127)
(put 'del       'charvalue 127)

% Many combinations of car and cdr are supported. Here I define
% versions that do up to four accesses. These would of course be
% trivial to move into C code!

(de caar (x)
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

% "not" and "eqcar" are used while processing some parts of
% this file and so get defined early.

(de not (x)
   (null x))

(de eqcar (a b)                % Is (car a) the same as b?
   (and (not (atom a)) (eq (car a) b)))

% The vsl kernel checks for a function called macroexpand_list
% whenever it is about to define a function, and expects it to
% expand macros in all the expressions in a list. So before
% I define any macros that could usefully be expanded I will
% define it!

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
      ((atom l) l)
      (t (cons (macroexpand (car l))
               (macroexpand_list (cdr l))))))

% Now I start on defining the proper arithmetic including
% in particular support for big integers. The function
% "expand" is used to map (plus a b c d) onto
% (plus2 a (plus2 b (plus2 c d))) [and similarly for other
% arithmetic functions that take arbitrary numbers of arguments].

(de expand (l fn)
   (cond
      ((null (cdr l)) (car l))
      (t (list fn (car l) (expand (cdr l) fn)))))

(dm plus (u) (expand (cdr u) 'plus2))
(dm times (u) (expand (cdr u) 'times2))
(dm logand (u) (expand (cdr u) 'logand2))
(dm logor (u) (expand (cdr u) 'logor2))
(dm logxor (u) (expand (cdr u) 'logxor2))
(dm max (u) (expand (cdr u) 'max2))
(dm min (u) (expand (cdr u) 'min2))

% The function "iplus2"  behaved like "iplus" but accepts
% exactly two arguments. And similarly for several others.

(de iplus2 (u v) (iplus u v))
(de itimes2 (u v) (itimes u v))
(de ilogand2 (u v) (ilogand u v))
(de ilogor2 (u v) (ilogor u v))
(de ilogxor2 (u v) (ilogxor u v))

% Back to defining what are sometimes merely alternate
% names for very basic operations.

(de idp (x)
   (symbolp x))

(de pairp (x)
   (null (atom x)))

(de prog1 (a b)
   a)

(de prog2 (a b)
   b)

(de reverse (x)
   (prog (y)
   loop
      (cond ((atom x) (return y)))
      (setq y (cons (car x) y))
      (setq x (cdr x))
      (go loop)))

% "reverse" reverses a list, while "reversip" creates the
% reversed version by overwriting the data that makes up its
% input. This may be held to save a little space, but is
% to be used with care.

(de reversip2 (a b)
   (prog (w)
   loop
      (cond ((atom a) (return b)))
      (setq w (cdr a))
      (rplacd a b)
      (setq b a)
      (setq a w)
      (go loop)))

(de reversip (x) (reversip2 x nil)) % Destructive reverse

(de append (a b)                % Append a pair of lists.
   (cond
      ((atom a) b)
      (t (cons (car a) (append (cdr a) b)))))


% I have written various of these in ugly imperative styles so that they
% end up iterative not recursive...

(de length (l)                  % Find length of a list.
   (prog (n)
      (setq n 0)
   top(cond ((atom l) (return n)))
      (setq n (add1 n))
      (setq l (cdr l))
      (go top)))

(de last (l)                    % Last element of a (non-empty) list.
   (cond
      ((atom l) (error 1 "last on emtpy list"))
      ((atom (cdr l)) (car l))
      (t (last (cdr l)))))

(de lastcar (x)                 % Not in Standard Lisp
   (cond
      ((atom x) nil)
      ((atom (cdr x)) (car x))
      (t (lastcar (cdr x)))))

(de lastpair (l)                % Last pair of a (non-empty) list,
   (cond                        % or nil if the input is empty.
      ((atom l) nil)
      ((atom (cdr l)) l)
      (t (lastpair (cdr l)))))
%  #else /* XXX */
%     (prog ()
%        (cond
%           ((null l) (error 1 "last on emtpy list")))
%     top(cond
%          ((atom (cdr l)) (return l)))
%        (setq l (cdr l))
%        (go top)))
%
%  (de lastcar (l)         % Not in Standard Lisp
%     (prog ()
%        (cond
%           ((null l) (error 1 "lastcar on emtpy list")))
%     top(cond
%          ((atom (cdr l)) (return (car l))))
%        (setq l (cdr l))
%        (go top)))
%
%  (de lastpair (l)                % Last pair of a (non-empty) list.
%     (prog ()
%        (cond
%           ((null l) (error 1 "lastpair on emtpy list")))
%     top(cond
%          ((atom (cdr l)) (return l)))
%        (setq l (cdr l))
%        (go top)))
%  #endif /* XXX */

(de member (a l)
   (cond
      ((atom l) nil)
      ((equal a (car l)) l)
      (t (member a (cdr l)))))

% "member" checks it a value is present in a list using the
% "equal" test, while "memq" uses "eq".
%  #else /* XXX */
%    (prog ()
%    top
%      (cond
%        ((null l) (return nil))
%        ((equal a (car l)) (return l)))
%      (setq l (cdr l))
%      (go top)))
%  #endif /* XXX */

(de memq (a l)
   (cond
      ((atom l) nil)
      ((eq a (car l)) l)
      (t (memq a (cdr l)))))
%  #else /* XXX */
%    (prog ()
%    top
%      (cond
%        ((null l) (return nil))
%        ((eq a (car l)) (return l)))
%      (setq l (cdr l))
%      (go top)))
%  #endif /* XXX */

(de delete (a l)
   (cond
      ((atom l) l)
      ((equal a (car l)) (cdr l))
      (t (cons (car l) (delete a (cdr l))))))

(de intersection (a b)
   (cond
      ((atom a) nil)
      ((member (car a) b) (cons (car a) (intersection (cdr a) b)))
      (t (intersection (cdr a) b))))

(de union (a b)
   (cond
      ((atom a) b)
      ((member (car a) b) (union (cdr a) b))
      (t (cons (car a) (union (cdr a) b)))))

(de neq (a b)                  % Not equal.
   (null (equal a b)))

(de assoc (a l)                % Look item up in association list using equal.
   (cond
      ((atom l) nil)
      ((and (not (atom (car l)))
            (equal (caar l) a)) (car l))
      (t (assoc a (cdr l)))))

(de atsoc (a l)                % Look item up in association list using eq.
   (cond
      ((atom l) nil)
      ((and (not (atom (car l)))
            (eq (caar l) a)) (car l))
      (t (atsoc a (cdr l)))))

(de subst (a b c)              % Substitute a for b in c
   (cond
      ((equal b c) a)
      ((atom c) c)
      (t (cons (subst a b (car c)) (subst a b (cdr c))))))

(de sublis (x y)
   (if (atom x) y
      (prog (u)
         (setq u (assoc y x))
         (return (cond
            ((not (atom u)) (cdr u))
            ((atom y) y)
            (t (cons (sublis x (car y))
               (sublis x (cdr y)))))))))

(de subla (x y)
   (if (atom x) y
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

% The prettyprint code here is a version of the code described
% as an example of the use of vsl.

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

% The "map" functions apply some function to each item defined by
% a list.
% mapc and map return nil
% mapcar and maplist build a list out of the computed values
% mapcan and mapcon expect the values to be lists, and use "nconc"
%        to join them.
% map, maplist and mapcon pass a pointer into the list itself
% as argument to the function, while mapc, mapcar and mapcon pass
% items from the list.
% Note that some other Lisp systems have functions like this that take
% the function as their first argument and the list as second, unlike the
% argument order used here.
% The use of awkward variables names such as "!~l" here is because under
% the dynamic scoping regime in vsl if the function passed relied on a
% free variable whose name clashed with a name used locally in these
% definitions there could be confusion.

(de mapcar (!~l !~fn)
  (prog (!~r)
 top (cond ((atom !~l) (return (reversip !~r))))
     (setq !~r (cons (apply !~fn (list (car !~l))) !~r))
     (setq !~l (cdr !~l))
     (go top)))

(de maplist (!~l !~fn)
  (prog (!~r)
 top (cond ((atom !~l) (return (reversip !~r))))
     (setq !~r (cons (apply !~fn (list !~l)) !~r))
     (setq !~l (cdr !~l))
     (go top)))

(de mapcan (!~l !~fn)
  (cond ((atom !~l) nil)
	(t (nconc (apply !~fn (list (car !~l))) (mapcan (cdr !~l) !~fn)))))

(de mapcon (!~l !~fn)
  (cond ((atom !~l) nil)
	(t (nconc (apply !~fn (list !~l)) (mapcon (cdr !~l) !~fn)))))

(de mapc (!~l !~fn)
  (prog ()
 top (cond ((atom !~l) (return nil)))
     (apply !~fn (list (car !~l)))
     (setq !~l (cdr !~l))
     (go top)))

(de map (!~l !~fn)
  (prog ()
 top (cond ((atom !~l) (return nil)))
     (apply !~fn (list !~l))
     (setq !~l (cdr !~l))
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
top (cond ((atom a) (return (reversip r))))
    (put (caar a) b (cadar a))
    (setq r (cons (caar a) r))
    (setq a (cdr a))
    (go top)))

% The Lisp "backquote" capability is coped with in vsl by having
% `(a b c) read in as (!` (a b c)) [and similarly for "," and ",@"]
% and then using macro-expansion to convert into executable code.

(de expand_backquote (x)
   (cond
      ((and (symbolp x) (null (null x))) (list 'quote x))
      ((atom x) x)                  % nil, number or string
      ((eq (car x) '!,) (cadr x))
      ((eq (car x) '!`) (expand_backquote (expand_backquote (cadr x))))
      ((eqcar (car x) '!,!@)
         (list 'append (cadar x) (expand_backquote (cdr x))))
      ((eqcar (car x) '!,!.)
         (list 'nconc (cadar x) (expand_backquote (cdr x))))
      (t (list 'cons (expand_backquote (car x)) (expand_backquote (cdr x))))))

(dm !` (x) (expand_backquote (cadr x)))

% Now a few things not needed by Standard Lisp but maybe helpful
% when using Lisp directly.

% Reduce uses the name "let" and so if I called this what I naturally
% want to there would be a clash and trouble. So I use a mangled name here.
% I also use let!* rather than let in those cases here where I can...

% Both "let" and "let!*" expand naturally into uses of lambda-expressions.

(de let_name (x)
  (if (atom x) x (car x)))

(de let_val (x)
  (if (or (atom x) (atom (cdr x)))
     nil
    (cadr x)))

(dm !~let (x)              % (!~let ((v1 E1) (v2 E2) ...) body)
   (cons (cons 'lambda (cons (mapcar (cadr x) 'let_name) (cddr x)))
         (mapcar (cadr x) 'let_val)))

(de expand_let!* (b x)
   (cond
      ((null b) x)
      (t (list (list 'lambda (list (let_name (car b))) (expand_let!* (cdr b) x))
               (let_val (car b))))))

(dm let!* (x)            % As !~let, but do bindings sequentially
   (expand_let!* (cadr x) (cons 'progn (cddr x))))

% A set of macros provide various neat and easy-to-use control structures.

% Note that tis version of IF allows a sequence of forms in the place
% that gets processed if the predicate evaluates to nil.

(dm if (x)          % (IF predicate yes no*) or (IF predicate yes)
   `(cond
      (,(cadr x) ,(caddr x))
      (t ,@(cdddr x))))

(dm when (x)        % (WHEN predicate yes yes yes ...)
   `(cond
      (,(cadr x) ,@(cddr x))))

(dm unless (x)        % (UNLESS predicate no no no ...)
   `(cond
      ((null ,(cadr x)) ,@(cddr x))))

(dm while (x)       % (WHILE predicate body body body ...)
   (let!* ((g (gensym)))
      `(prog nil
       ,g (cond ((null ,(cadr x)) (return nil)))
          ,@(cddr x)
          (go ,g)))))

% (psetq a A b B) must arrange to evaluate both A and B before
% either is saved in a or b. This can be expressed in terms of
% use of "let" - but the expansion process is a little messy to
% establish.

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
   (let!* ((vars (make_psetq_vars (cdr x))))
      `(let!* ,(make_psetq_bindings vars (cdr x))
              ,@(make_psetq_assignments vars (cdr x)))))

% The "do" macro provides a rather general iteration capabilty
% of the form
% (do ((var init step) ..)
%     (endcondition result ...)
%     body)
% and again can be expressed via macro-expansion into simpler or
% more basic constructions.

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
       (let!* ((v (car u))
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

% "dolist" is much simpler, and is used as in
% (dolist (a '(1 2 3)) (print a))

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

% "dotimes" arranges to perform some actions a fixed number of times,
% counting (starting from 0) in a variable that the user can name.
%   (dotimes (i 10) (prin i) (princ blank) (print (times i i)))

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
      (let!* ((w u))
         (while (not (atom (cdr u))) (setq u (cdr u)))
         (rplacd u v)
         w)))

% Now the main body of the arithmetic code. the vsl kernel provides
% functions with names like iplus, itimes, igreaterp, ... that
% work with either floating point values or with integers up to 64-bits.
% Building on that this code allows a list of the form
%   (!~bignum d0 d1 d2 ...)
% to stand for a number expressed with radix 2^30 and with d0 as its
% least significant digit. A very small number of hooks within vsl
% allow reading and printing of general numbers to divert into the
% code written here.
% Implementing arithmetic in (interpreted) Lisp like this will be
% seriously inefficient, so there would be big gains from re-working
% the C code to make this stuff irrelevant!

(setq !~radix (itimes 1024 1024 1024))
(setq !~fpradix (ifloat !~radix))

% The numeric data type must now include these cases.
% The "atom" test in vsl needs to know that a bit of
% data stored as (!~bignum ...) should viewed as atomic.

(de fixp (u) (and (numberp u) (not (floatp u))))
(de numberp (u) (or (inumberp u) (bignump u)))
(de integerp (u) (and (numberp u) (not (floatp u))))

% There are two representations of numbers. The one used in the
% main parts of the code are
%    integer < 2^30
%    float
%    (!~bignum list of digits ...)
%
% but within the code that implements big arithemetic I want
% to keep things JUST as lists of digits with the "~bignum"
% marker omitted. I need functions that map between these two
% formats are here they are.

(de !~embiggen (n)
   (cond
      ((zerop n) nil)
      ((ifixp n) (list n))
      ((bignump n) (cdr n))
      (t (error "number expected but received" n))))

(de !~sizecheck (l)
   (cond
      ((null l) 0)
      ((null (cdr l)) (car l))
      (t (cons '!~bignum l))))

% Various two-argument functions will be able to use built-in
% vsl functions on floating point input but need to do more
% if they have a potentially big integer. The dispatch between
% these cases can be encapsulated within a macro...

(dm !~bignum_dispatch2 (u)
   `(cond
      ((or (floatp ,(cadr u)) (floatp ,(caddr u)))
       (,(car (cdddr u)) (float ,(cadr u)) (float ,(caddr u))))
      (t (!~sizecheck (,(cadr (cdddr u))
                      (!~embiggen ,(cadr u)) (!~embiggen ,(caddr u)))))))

% The version above converts its result back into a "number". But eg
% comparison operations do not want to do that, so here is a
% second version that does not insert calls to !~sizecheck.

(dm !~bignum_dispatch2a (u)
   `(cond
      ((or (floatp ,(cadr u)) (floatp ,(caddr u)))
       (,(car (cdddr u)) (float ,(cadr u)) (float ,(caddr u))))
      (t (,(cadr (cdddr u))
            (!~embiggen ,(cadr u)) (!~embiggen ,(caddr u))))))

% The Lisp reader in vsl will call plus2 and times2 when it reads
% in integers, so I defer defining either until all their sub-functions
% are in place.

%(de plus2 (u v)
%   (!~bignum_dispatch2 u v iplus !~bigplus2))

% The internal functions used here are all given names starting with
% "~" to reduce the prospect of clashes with user-written code.

(de !~bigplus2 (u v) (!~bigplus2carry u v 0))

% "~xdivide" is like divide on native small numbers except that
% it guarantees that the remainder it returns is non-negative.

(de !~xdivide (u v)
   (let!* ((r (idivide u v)))
      (if (iminusp (cdr r))
         (cons (isub1 (car r)) (iplus (cdr r) v))
         r)))

% "~bigcons" arranged to avoid leaving superfluous leading zeros
% as part of big-numbers.

(de !~bigcons (a b)
   (cond
      ((and (zerop a) (null b)) nil)
      ((equal b '(-1)) (if (onep a) nil (cons (idifference a !~radix) nil)))
      (t (cons a b))))

(de !~carryinto (u c)
   (cond
      ((zerop c) u)
      ((null u) (!~bigcons c nil))
      (t (let!* ((x (!~xdivide (iplus (car u) c) !~radix)))
         (!~bigcons (cdr x) (!~carryinto (cdr u) (car x)))))))

(de !~bigplus2carry (u v c)
   (cond
      ((null u) (!~carryinto v c))
      ((null v) (!~carryinto u c))
      (t (let!* ((x (!~xdivide (iplus (car u) (car v) c) !~radix)))
         (!~bigcons (cdr x) (!~bigplus2carry (cdr u) (cdr v) (car x)))))))

%(de times2 (u v) 
%   (!~bignum_dispatch2 u v itimes !~bigtimes2))


% Multiply a big-number by a simple small integer.

(de !~bigtimesn (n u c)
   (cond
      ((null u) (if (zerop c) nil (list c)))
      (t (let!* ((x (!~xdivide (iplus (itimes n (car u)) c) !~radix)))
         (!~bigcons (cdr x) (!~bigtimesn n (cdr u) (car x)))))))

(de !~bigtimes2 (u v)
   (cond
      ((or (null u) (null v)) nil)
      (t (!~bigplus2carry
         (!~bigtimesn (car u) v 0)
         (!~bigcons 0 (!~bigtimes2 (cdr u) v))
         0))))

(de logand2 (u v)
   (!~bignum_dispatch2 u v ilogand !~biglogand2))

(de logor2 (u v)
   (!~bignum_dispatch2 u v ilogor !~biglogor2))

(de logxor2 (u v)
   (!~bignum_dispatch2 u v ilogxor !~biglogxor2))

(de difference (u v)
   (!~bignum_dispatch2 u v idifference !~bigdifference))

(de divide (u v)
   (!~bigdivide (!~embiggen u) (!~embiggen v)))

% Now a patched version that will report inputs that cause trouble

(de divide (u v)
   (prog (r)
      (setq r (errorset
                 (list '!~bigdivide
                       (mkquote (!~embiggen u))
                       (mkquote (!~embiggen v))) t t))
      (when (null (atom r)) (return (car r)))
      (printc "divide failed")
      (print u)
      (print v)
      (error 99 "division messup")))

(de geq (u v)
   (not (greaterp v u)))

(de greaterp (u v)
   (cond
      ((floatp u) (igreaterp u (float v)))
      ((floatp v) (igreaterp (float u) v))
      ((or (bignump u) (bignump v))
       (!~biggreaterp (!~embiggen u) (!~embiggen v)))
      (t (igreaterp u v))))

(de leftshift (u v)
   (if (iminusp v)
       (rightshift u (iminus v))
       (times u (expt 2 v))))

(de leq (u v)
   (not (greaterp u v)))

(de lessp (u v)
   (greaterp v u)))

(de quotient (u v)
   (cond
      ((floatp u) (iquotient u (float v)))
      ((floatp v) (iquotient (float u) v))
      (t (car (divide u v)))))

(de remainder (u v)
   (cdr (divide u v)))

(de rightshift (u v)
   (if (iminusp v)
       (leftshift u (iminus v))
       (let!* ((p (expt 2 v)))
           (if (minusp u)
               (quotient (add1 (difference u p)) p)
               (quotient u p)))))

% Negative numbers give special fun for boolean operations because
% they have to be treated rather as if they had unlimited numbers of
% leading 1 bits.

% Here u will be negative but v positive. The two are about to be ANDed
% together. This delivers a version of u that has been truncated it is
% is longer than v or extended out with additional "-1" values if it
% is shorter. That can be ANDed digit by digit to yield the evenual
% result.

(de !~bigpos (u v)
   (cond
      ((null v) u)
      ((null u) (cons -1 (!~bigpos nil (cdr v))))
      (t (cons (car u) (!~bigpos (cdr u) (cdr v))))))

% Strategy for -ve numbers:
% (1) Both args +ve.   AND digit by digit
% (2) Both args -v1.   use ~(~u | ~v) knowing that the OR will be on +ve vals
% (3) Mixed.           adjust length of negetive value either by padding
%                      with extra leading -1s or by trincating it. Then
%                      treat as case (a).
% For OR work digit by digit if both args +ve otherwise use ~(~u & ~v)
% knowing that this will not be re-converted to use of OR.

(de !~biglogand2 (u v)
   (if (!~bigminusp u)
       (if (!~bigminusp v)
           (!~biglognot (!~biglogor2a (!~biglognot u) (!~biglognot v)))
           (!~biglogand2a v (!~bigpos u v)))
       (if (!~bigminusp v)
           (!~biglogand2a u (!~bigpos v u))
           (!~biglogand2a u v))))


(de !~biglogand2a (u v)
   (cond
      ((null u) nil)
      ((null v) nil)
      (t (!~bigcons (ilogand (car u) (car v))
                    (!~biglogand2a (cdr u) (cdr v))))))

(de !~biglogor2 (u v)
   (if (or (!~bigminusp u) (!~bigminusp v))
       (!~biglognot (!~biglogand2 (!~biglognot a) (!~biglognot b)))
       (!~biglogor2 u v)))

(de !~biglogor2a (u v)
   (cond
      ((null u) v)
      ((null v) u)
      (t (!~bigcons (ilogor (car u) (car v))
                    (!~biglogor2a (cdr u) (cdr v))))))


(de !~biglogxor2 (u v)
  (prog (s)
     (when (!~bigminusp u) (setq u (!~biglognot u)) (setq s t))
     (when (!~bigminusp v) (setq v (!~biglognot v)) (setq s (null s)))
     (setq u (!~biglogxor2a u v))
     (when s (setq u (!~biglognot u)))
     (return u)))

(de !~biglogxor2a (u v)
   (cond
      ((null u) v)
      ((null v) u)
      (t (!~bigcons (ilogxor (car u) (car v))
                    (!~biglogxor2 (cdr u) (cdr v))))))

(de !~bigdifference (u v)
   (!~bigplus2carry u (!~bigminus v) 0))

% Division is pretty well the messiest thing to implement
% here. The first function deals with the consequences of
% negative values, while the second ones actually does the work.

(de !~bigdivide (u v)
   (prog (su sv)
      (when (null u) (return (cons 0 0)))
      (when (null v) (error "attempt to divide by zero" u))
      (when (!~bigminusp u) (setq su t u (!~bigminus u)))
      (when (!~bigminusp v) (setq sv t v (!~bigminus v)))
      (if (null (cdr v))
         (progn
            (setq u (!~shortdivide 0 (reverse u) (car v)))
            (setq v (car u))
            (while (eqcar v 0) (setq v (cdr v)))
            (setq u (cons
               (reverse v)
               (if (zerop (cdr u)) nil (list (cdr u))))))
         (setq u (!~bigdivide1 u v)))
      (return (cons
         (!~sizecheck (if (eq su sv) (car u) (!~bigminus (car u))))
         (!~sizecheck (if su (!~bigminus (cdr u)) (cdr u)))))))

(de !~shortdivide (u1 u v)
   (cond
      ((null u) (cons nil u1))
      (t (let!* ((d (idivide (iplus (itimes !~radix u1) (car u)) v))
                 (d1 (!~shortdivide (cdr d) (cdr u) v)))
            (cons (cons (car d) (car d1)) (cdr d1))))))

(de !~bigdivide1 (u v)   % Positive arguments and v is at least 2 digits
   (prog (r d)
      (while (not (!~biggreaterp1 v u))
         (setq d (!~approx_quotient u v))
         (setq u (!~bigdifference u (!~bigtimes2 d v)))
         (if (!~bigminusp u)
            (error 99 (list "approx was overestimate, v=" v " d=" d " u=" u)))
         (setq r (!~bigplus2carry r d 0)))
      (return (cons r u))))

(setq !~big (itimes 1024 1024 1024 1024 1024 512))

(de !~approx_quotient (u v) % v has at least 2 digits and u >= v
   (prog (x xx un vn q)
      (when (null (cddr u)) % then v must also be short
         (setq un (iplus (car u) (itimes !~radix (cadr u))))
         (setq vn (iplus (car v) (itimes !~radix (cadr v))))
         (return (list (iquotient un vn))))
      (while (cddr v) (setq u (cdr u) v (cdr v)))
      (setq x 0)
      (while (cddr u) (setq u (cdr u) x (add1 x)))
      (setq un (iplus (car u) (itimes !~radix (cadr u))))
      (setq vn (iplus (car v) (itimes !~radix (cadr v))))
      (setq xx 0)
      (while (ilessp un !~big) (setq un (ileftshift un 1) xx (iadd1 xx)))
      (while (igeq vn !~radix) (setq vn (irightshift vn 1) xx (iadd1 xx)))
      (setq q (iquotient un (iadd1 vn)))
      (when (igeq xx 30) (setq x (isub1 x) xx (idifference xx 30)))
      (if (zerop xx)
          (setq un q vn 0)
          (progn
             (setq un (irightshift q xx))
             (setq vn (ileftshift (idifference q (ileftshift un xx))
                                  (idifference 30 xx)))))
      (setq q nil)
      (if (igreaterp x 0) (dotimes (i x) (setq q (cons 0 q))))
      (setq q (cons un (cons vn q)))
      (setq q (cdr (reverse q)))
      (if (equal x -1) (setq q (cdr q)))
%      (printc (list "result = " q (cons '!~bignum q)))
      (if (or (null q) (equal q '(0))) (setq q '(1)))
      (return q)))

% All the arithmetic comparisons can be expressed in terms of
% a single basic case. Here I choose to make "greaterp" the
% one that is actually coded.

(de !~biggreaterp (u v)
   (if (!~bigminusp u)
      (if (!~bigminusp v) (!~biggreaterp1 (!~bigminus v) (!~bigminus u)) nil)
      (if (!~bigminusp v) t (!~biggreaterp1 u v))))

(de !~biggreaterp1 (u v)
   (cond
      ((null u) nil)
      ((null v) t)
      ((equal (cdr u) (cdr v)) (igreaterp (car u) (car v)))
      (t (!~biggreaterp1 (cdr u) (cdr v)))))

% Now for some one-argument arithmetic functions.
% In these cases it does not seem worth having a macro
% to dispatch between the various cases.

(de add1 (u)
   (plus2 u 1))

(de ceiling (u)
   (cond
      ((floatp u) (!~bigceiling u))
      (t u)))

(de fix (u)
   (cond
      ((floatp u) (!~bigfix u))
      (t u)))

(de float (u)
   (cond
      ((floatp u) u)
      ((inumberp u) (ifloat u))
      ((bignump u) (!~bigfloat (cdr u)))
      (t (error "bad arg to float" u))))

(de floor (u)
   (cond
      ((floatp u) (!~bigfloor u))
      (t u)))

(de lognot (u)
   (cond
      ((ifixp u) (!~biglognot (list '!~bignum u)))
      ((bignump u) (!~biglognot (cdr u)))
      (t (error "bad arg to lognot" u))))

(de minus (u)
   (cond
      ((or (ifixp u) (floatp u)) (iminus u))
      ((bignump u) (!~sizecheck (!~bigminus (cdr u))))
      (t (error "bad arg to minus" u))))

(de minusp (u)
   (cond
      ((or (floatp u) (inumberp u)) (iminusp u))
      ((bignump u) (and (cdr u) (iminusp (last (cdr u)))))
      (t nil)))

(de sub1 (u)
   (plus2 u -1))

(de !~bigceiling (u)
   (if (iminusp u)
       (minus (!~bigfloor (iminus u)))
       (!~bigfixer u 1)))

(de !~bigfloor (u)
   (if (iminusp u)
       (minus (!~bigceiling (iminus u)))
       (!~bigfixer u -1)))

(de !~bigfix (u)
   (if (iminusp u)
       (minus (!~bigfix (iminus u)))
       (!~bigfixer u 0)))

(de !~bigfixer (u updown)
   (cond
      ((ilessp u !~fpradix)
         (cond
            ((zerop updown) (ifix u))
            ((onep updown) (iceiling u))
            (t (ifloor u))))
      (t (prog (w)  % Now u is definitely large!
         (setq w (fix (iquotient u !~fpradix)))
         (setq u (idifference u (itimes !~fpradix (float w))))
         (return (plus (times w !~radix) (!~bigfixer u updown)))))))
           
(de !~bigfloat (u)
   (cond
      ((null u) 0.0)
      (t (iplus (ifloat (car u))
         (itimes !~fpradix (!~bigfloat (cdr u)))))))

(de !~biglognot (u)
   (cond
      ((null u) nil)
      ((null (cdr u)) (list (ilognot (car u))))
      (t (cons (ilogxor (isub1 !~radix) (car u))
               (!~biglognot (cdr u))))))

(de !~bigminus (u)
   (cond
      ((null u) nil)
      ((zerop (car u)) (cons (car u) (!~bigminus (cdr u))))
      ((null (cdr u)) (list (iminus (car u))))
      (t (cons (ilogand (isub1 !~radix) (iminus (car u)))
               (!~biglognot (cdr u))))))

(de !~bigminusp (u)
   (and u (iminusp (last u))))

% onep and zerop are built-in, and although there is no real
% merit in anybody using a function ionep or izerop I provide
% both here just for completeness.

(de ionep (u) (onep u))

(de izerop (u) (zerop u))

% A handy macro arranges that a big-number will evaluate to itself.

(dm !~bignum (u) (list 'quote u))

% If vsl finds a big-number it calls this function to turn it
% into a string that it can then print. Again this is pretty
% inefficient! I provide a flag !*rawbig that, when set, causes
% big numbers to be displayed in terms of their internal representation
% as well as "properly" because that is sometimes useful while debugging.
% !*onlyraw is even more drastic and only shows the internal form,
% thereby avoiding division etc in this code.

(setq !*rawbig nil !*onlyraw nil)

(de !~big2str (n)
   (prog (r neg)
      (when (null n) (return "0"))
% In bad cases you may try to display a list whose first element is
% "~bignum" but which is then badly formatted.
      (setq r n)
      (while (and (not (atom r))
                  (inumberp (car r))) (setq r (cdr r)))
      (when r (return nil))
      (setq r '(!"))
      (when (or !*rawbig !*onlyraw)
         (setq r (cons '!] r))
         (dolist (c (reverse (explode n)))
            (setq r (cons c r)))
         (setq r (cons '!: (cons '![ r))))
      (when (not !*onlyraw)
         (when (!~bigminusp n) (setq n (!~bigminus n) neg t))
         (while (or (cdr n) (igreaterp (car n) 9))
% !~shortdivide is an internal function to this code with a slightly
% odd interface that involves numbers passed most significant digit
% first.
            (setq n (!~shortdivide 0 (reverse n) 10))
            (setq r (cons (car (explodec (cdr n))) r))
            (setq n (car n))
            (while (eqcar n 0) (setq n (cdr n)))
            (setq n (reverse n)))
         (setq r (cons (car (explodec (!~sizecheck n))) r))
         (when neg (setq r (cons '!- r))))
      (return (compress (cons '!" r)))))

(de list!-to!-vector (l)
   (prog (n v)
      (setq n (length l))
      (setq v (mkvect (sub1 n)))
      (setq n 0)
      (while l
         (putv v n (car l))
         (setq n (add1 n))
         (setq l (cdr l)))
      (return v)))

(setq hexdigs
  (list!-to!-vector
    '(!0 !1 !2 !3 !4 !5 !6 !7 !8 !9 !a !b !c !d !e !f)))

(de !~big2strhex (n)
   (prog (r neg)
      (when (null n) (return "0"))
      (setq r n)
      (while (and (not (atom r))
                  (ifixnum (car r))) (setq r (cdr r)))
      (when r (return nil))
      (setq r '(!"))
      (when (minusp n) (setq n (minus n) neg t))
      (while (greaterp n 15)
         (setq n (divide n 16))
         (setq r (cons (getv hexdigs (cdr n)) r))
         (setq n (car n)))
      (setq r (cons (getv hexdigs n) r))
      (when neg (setq r (cons '!- r)))
      (return (compress (cons '!" r)))))

% I want to define these two AFTER I have defined all of the rest
% of the big-number support because they can be called by the vsl
% kernel when it tries to read numbers.

(de plus2 (u v)
   (!~bignum_dispatch2 u v iplus !~bigplus2))

(de times2 (u v) 
   (!~bignum_dispatch2 u v itimes !~bigtimes2))

(de expt (a n)
   (cond
      ((zerop n) 1)
      ((onep n) a)
      ((minusp n) (expt (quotient 1.0 a) (minus n)))
      ((zerop (remainder n 2)) (expt (times a a) (quotient n 2)))
      (t (times a (expt (times a a) (quotient (sub1 n) 2))))))

% Now arithmetic is all in place.

(setq small!-modulus 3)

(de set!-small!-modulus (n)
   (let!* ((r small!-modulus))
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

% "fluid" and "global" are concepts that mainly belong with
% a compiler, but versions are provided here even if they
% are not terribly useful.

(de ensure_defined (v)
   (when (not (boundp v))
         (eval (list 'setq v nil))))

(de fluid (x)
   (remflag x 'global)
   (flag x 'fluid)
   (dolist (v x) (ensure_defined v)))

(de global (x)
   (remflag x 'fluid)
   (flag x 'global)
   (dolist (v x) (ensure_defined v)))

(de unfluid (x)
   (remflag x 'fluid))

(de unglobal (x)
   (remflag x 'global))

(de fluidp (x) (flagp x 'fluid))

(de globalp (x) (flagp x 'global))

% Now some more general-purpose small functions. Including
% cases that are alternative names for built-in ones that
% it is convenient to have for the support of some historic
% code.

(de flag (l tag)
   (dolist (v l) (put v tag t)))

(de remflag (l tag)
   (dolist (v l) (remprop v tag)))

(de flagp (v tag) (get v tag))

(de prin2 (x) (princ x))

(de explode2 (x) (explodec x))

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

% Testing for letters and digits as done here makes
% assumptions about the character-code that is in use.

(de liter (x)
   (let!* ((c (char!-code x)))
      (or (and (leq 65 c) (leq c 90))
          (and (leq 97 c) (leq c 122)))))

(de digit (x)
   (let!* ((c (char!-code x)))
      (and (leq 48 c) (leq c 57))))

(de tolower (x)
   (let!* ((c (char!-code x)))
      (if (and (leq 65 c) (leq c 90))
          (code!-char (plus c 32))
          x)))

(de char!-downcase (x) (tolower x))

(de explode2lc (x)
    (mapcar (explodec x) 'tolower))

(de intern (x)
   (if (stringp x)
       (compress (mapcan (explodec x)
                         '(lambda (c) (list '!! c))))
       x))

(setq !*raise nil)
(setq !*lower t)

(de putd (name type def)
   (cond
      ((eq type 'expr)
         (eval (cons 'de (cons name (cdr def)))))
      ((eq type 'macro)
         (eval (cons 'dm (cons name (cdr def)))))
      ((eq type 'subr)
         (error "putd/subr not supported" (list name type def)))
      (t (error "unknown type in putd" type))))

(setq !*redefmsg nil)

(dm date (x) "1 Jan 2018") % A macro so that number of args does not matter

(de set!-print!-precision (n) n)

(de constantp (x)
   (or (null x)
       (numberp x)
       (stringp x)
       (eq x t)))

(dm declare (x) nil)

% The code for ordering items that is given here is
% required by Reduce, and the exact behaviour is
% intended to support what is needed there.

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

(de max2 (a b)
   (if (greaterp a b) a b))

(de min2 (a b)
   (if (lessp a b) a b))

(de evenp (x) (zerop (remainder x 2)))

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
(de lsh (a n) (leftshift a n))
(de ilsh (a n) (leftshift a n))
(de lshift (a n) (leftshift a n))

(de ash1 (a n)
   (if (minusp a) (minus (leftshift (minus a) n)) (leftshift a n)))

(de remd (x) nil)

% The "fasl" scheme here is used when building large programs.
% Code gets put in files in a directory called "xxx.img.modules".

(de filedate (x) 0)

(de datelessp (a b) t)

(fluid '(faslinfile!* faslinstack!* fasloutfile!* faslname!*))

(de start!-module (x)
   (cond
      ((null x)
         (close fasloutfile!*)
         (setq fasloutfile!* nil)
         (princ "+++ FASLEND ")
         (printc faslname!*)
         t)
      (t
         (setq faslname!* x)
         (setq fasloutfile!* (open!-module x 'output))
         t)))

(de faslread ()
   (let!* ((s (rds faslinfile!*)))
      (prog1
         (read)
         (rds s))))

(de write!-module (x)
   (let!* ((s (wrs fasloutfile!*)))
      (prog1
         (print x)
         (wrs s))))

(fluid '(dfprint!*))

(de faslout (u)
   (prog nil
      (terpri)
      (princ "FASLOUT ")
      (prin u)
      (printc ": IN files;  or type in expressions")
      (printc "When all done, execute FASLEND;")
      (cond
         ((not (atom u)) (setq u (car u))))
      (cond ((not (start!-module u))
             (progn
                (cond ((neq (posn) 0) (terpri)))
                (printc "+++ Failed to open FASL output file")
                (return nil))))
      (setq s!:faslmod_name (cons u nil))
      (setq s!:dfprintsave dfprint!*)
      (setq dfprint!* (quote s!:fslout0))
      (setq !*defn t)))

(put (quote faslout) (quote stat) (quote rlis))

(de faslend nil
   (prog ()
      (cond
         ((null s!:faslmod_name) (return nil)))
      (princ "Completed FASL files for ")
      (print (car s!:faslmod_name))
      (start!-module nil)
      (setq dfprint!* s!:dfprintsave)
      (setq !*defn nil)
      (setq s!:faslmod_name nil)
      (return nil)))

(put (quote faslend) (quote stat) (quote endstat))
(flag '(faslend) 'eval)

(setq !*backtrace t)
(setq !*debug nil)

(de s!:fasl_supervisor nil
   (prog (u w !*echo)
      (setq !*echo !*debug)
   top
      (setq u (errorset (quote (read)) t !*backtrace))
      (cond
         ((atom u) (return nil)))
      (setq u (car u))
      (cond
         ((equal u !$eof!$) (return nil)))
      (cond ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (go top))
         ((eqcar u (quote faslend))
            (return (apply (quote faslend) nil)))
         ((eqcar u (quote rdf))
            (setq w (open (setq u (eval (cadr u))) (quote input)))
            (cond (w (progn (terpri)
                     (princ "Reading file ")
                     (prin u)
                     (terpri)
                     (setq w (rds w))
                     (s!:fasl_supervisor)
                     (princ "End of file ")
                     (prin u)
                     (terpri)
                     (close (rds w))))
                  (t (progn (princ "Failed to open file ")
                     (prin u)
                     (terpri)))))
          (t (s!:fslout0 u)))
      (go top)))

(de s!:fslout0 (u) (s!:fslout1 u nil))

(de s!:fslout1 (u loadonly)
   (prog (w)
% Note that I check for eval-when BEFORE I do any macro-expansion here
% because otherwise eval-when gets expanded away. The consequence here is
% that eval-when is only honoured at the top-level.
      (when (eqcar u 'eval!-when)
            (if (memq 'compile (cadr u)) (eval (cons 'progn (cddr u))))
            (if (memq 'load (cadr u))
                (s!:fslout1 (cons 'progn (cddr u)) loadonly))
            (return nil))
      (cond
         ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (return nil))
         ((eqcar u (quote progn))
            (prog (var1174)
               (setq var1174 (cdr u))
    lab1173    (cond
                  ((null var1174) (return nil)))
               (prog (v)
                  (setq v (car var1174))
                  (s!:fslout1 v loadonly))
               (setq var1174 (cdr var1174))
               (go lab1173))
            (return nil))
         ((eqcar u (quote eval!-when))
            (return (prog nil
               (setq w (cadr u))
               (setq u (cons (quote progn) (cddr u)))
               (cond
                  ((and (memq (quote compile) w)
                        (not loadonly))
                   (eval u)))
               (cond
                  ((memq (quote load) w) (s!:fslout1 u t)))
               (return nil))))
         ((or (flagp (car u) (quote eval))
              (and (equal (car u) (quote setq))
                   (not (atom (caddr u)))
                   (flagp (caaddr u) (quote eval))))
            (cond
               ((not loadonly) (errorset u t !*backtrace)))))
      (cond
         ((eqcar u (quote rdf))
            (prog nil
               (setq w (open (setq u (eval (cadr u))) (quote input)))
               (cond 
                  (w (princ "Reading file ")
                     (prin u)
                     (terpri)
                     (setq w (rds w))
                     (s!:fasl_supervisor)
                     (princ "End of file ")
                     (prin u)
                     (terpri)
                     (close (rds w)))
                  (t (princ "Failed to open file ")
                     (prin u)
                     (terpri)))))
          ((and (not (eqcar u (quote faslend)))
                (not (eqcar u (quote carcheck))))
             (write!-module u)))))))

(de verbos (x) nil)

(de linelength (n) (linelength!* n))

(de getenv (x) nil)

(de filep (x)
   (let!* ((h (errorset (list 'open x ''input) nil nil)))
      (if (atom h) nil
          (progn (close (car h)) t))))

(de lengthc (x) (length (explodec x)))

% Various of the functions defined here are needed by Reduce
% and simplified or dummy versions are provided here so that the
% program as a whole can be built.

(de gctime () 0)

(de eqn (a b) (equal a b))

(de threevectorp (x)
   (and (vectorp x) (equal (upbv x) 2)))

(de list!-to!-vector (l)
   (prog (n v)
      (setq n (length l))
      (setq v (mkvect (sub1 n)))
      (setq n 0)
      (while l
         (putv v n (car l))
         (setq n (add1 n))
         (setq l (cdr l)))
      (return v)))

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

(de verbos (x) nil)

(de window!-heading (x) (print x))

(de make!-special (x)
   (set x nil)
   (flag (list x) 'fluid))

(de compile!-all () nil)

(de library!-members () nil)

(de delete!-module (x) nil)

(de list!-directory (x) nil)

(de checkpoint (a b) (preserve a))

(de list!-to!-string (a)
   (prog (r)
      (setq r '(!"))
      (dolist (c a)
         (if (ifixp c) (setq c (code!-char c)))
         (if (eq c '!") (setq r (cons c r)))
         (setq r (cons c r)))
      (return (compress (reverse (cons '!" r))))))

(de list2string (a) (list!-to!-string a))

(de string2list (s)
   (setq s (mapcar (explodec s) 'char!-code))) 

(de string!-length (s) (length (explodec s)))

(de id2string (a)
   (compress (cons '!" (append (explodec a) '(!")))))

(de setpchar (x) (setpchar!* x))

(de printprompt (u) nil)

(flag '(id2string printprompt) 'lose)

(de land (a b) (logand2 a b))

(de lshift (a n) (rightshift a (iminus n)))

(de allocate!-string (n)
   (prog (i l)
      (setq i 0)
      (while (lessp i n)
         (setq l (cons 0 l))
         (setq i (iplus i 1)))
      (return (list2string l))))

(dm string!-store (x)
   `(prog (l)
       (setq l (string2list ,(cadr x)))
       (setq l (str!-store1 l ,(caddr x) ,(cadddr x)))
       (setq ,(cadr x) (list2string l))
       s))


(de str!-store1 (charlis len what)
    (if (equal len 0)
        (cons what (cdr charlis))
        (cons (car charlis) (str!-store1 (cdr charlis) (iplus len -1) what))))

(de gensym1 (x) (gensym))

(de md60 (x) 123456789)

(de error1 () (error 99 nil))

(dm eval!-when (u)
   (if (member 'eval (cadr u))
       (cons 'progn (cddr u))
       nil))

(de tmpnam () "./temporary-file.tmp")

% arithmetic left shift
(de ashift (n m)
   (cond 
      ((equal n 0) 0)
      ((equal m 0) n)
      ((greaterp m 0) (leftshift n m))
      ((greaterp n 0) (rightshift n (minus m)))
      (t % arithmetic right shift of negative number
       (minus (rightshift (minus n) (minus m))))))

(de prin1 (u) (prin u))

(de carcheck (fff) nil)

(de fp!-finite (x) t)

(de complexp (x) nil)

(dm nreverse (x) `(reversip ,(cadr x)))

(dm unwind!-protect (u)
  (list
    (list 'lambda '(!*x!*)
      (cons 'progn (append (cddr u) '(!*x!*))))
    (cadr u)))

(de widelengthc (u)
   (cond
      ((idp u) (length!-without!-followers (string2list (id2string u))))
      ((stringp u) (length!-without!-followers (string2list u)))
      (t (length (explode2 u)))))

%(de get!-lisp!-directory () ".")
(de smemql (u v)
  (cond
    ((null v) nil)
    ((smemq (car u) v) (cons (car u) (smemq (cdr u) v)))
    (t (smemql (cdr u) v))))

(dm commentoutcode (u) nil)

(de smember (u v)
  (cond
    ((eq u v) t)
    ((atom v) nil)
    (t (or (smember u (car v))
           (smember u (cdr v))))))
           
(de smemqlp (u v)
  (cond
    ((or (null v) (numberp v)) nil)
    ((atom v) (memq v u))
    ((eq (car v) 'quote) nil)
    (t (or (smemqlp u (car v)) (smemqlp u (cdr v))))))

(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))
(dm bothtimes (x) (cons 'progn (cdr x)))
(de find!-gnuplot ()
  "gnuplot")

(dm load (x)
  (terpri)
  (prin2 "++++ LOAD ")
  (prin (cdr x))
  (printc " called")
  nil)

(de posn () 0)

(de enable!-errorset (a b)
   (setq !*backtrace b))

(de prin1 (x) (prin x))

(de iequal (x y) (equal x y))

% What follow is derived from reduce/packages/rlisp/rprintf.red

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
				 ((equal c 'e) (eval a))
                                 (t (progn
                                       (p_princ "%" nil)
                                       (p_princ c nil)))) ))) ))) )
         (go whilelabel))))

(dm printf (u) (list 'printf_internal (cadr u) (cons 'list (cddr u))))

(dm bldmsg (u) (list 'bldmsg_internal (cadr u) (cons 'list (cddr u))))

(dm fprintf (u) 
    (list 'prog '(oldout) 
	  (list 'setq 'oldout (list 'wrs (cadr u)))
	  (list 'printf_internal (caddr u) (cons 'list (cdddr u)))
	  '(wrs oldout)))


(flag '(printf bldmsg fprintf) 'variadic)

% End of vsl.lsp
