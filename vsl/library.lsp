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

(de not (x)
   (null x))

(de reverse_sub (a b)                  % Sub-function for reverse.
   (cond
      ((null a) b)
      (t (reverse_sub (cdr a) (cons (car a) b)))))

(de reverse (x) (reverse_sub x nil))   % Reverse a list.

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
      ((null l) (error 1 "last on emty list"))
      ((null (cdr l)) (car l))
      (t (last (cdr l)))))

(de lastcar (x)         % Not in Standard Lisp
   (cond
      ((null x) nil)
      ((null (cdr x)) (car x))
      (t (lastcar (cdr x)))))

(de member (a l)
   (cond
      ((null l) nil)
      ((equal a (car l)) l)
      (t (member a (cdr l)))))

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

(de subst (a b c)              % Substitute a for b in c
   (cond
      ((equal b c) a)
      ((atom c) c)
      (t (cons (subst a b (car c)) (subst a b (cdr c))))))

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

(dm let (x)              % (let ((v1 E1) (v2 E2) ...) body)
   (cons (cons 'lambda (cons (mapcar (cadr x) 'car) (cddr x)))
         (mapcar (cadr x) 'cadr)))

(de expand_let!* (b x)
   (cond
      ((null b) x)
      (t (list (list 'lambda (list (caar b)) (expand_let!* (cdr b) x))
               (cadar b)))))

(dm let!* (x)            % As let, but do bindings sequentially
   (expand_let!* (cadr x) (cons 'progn (cddr x))))

(dm if (x)          % (IF predicate yes no)
   `(cond
      (,(cadr x) ,(caddr x))
      (t ,(cond ((atom (cdddr x)) nil) (t (car (cdddr x)))))))

(dm when (x)        % (WHEN predicate yes yes yes ...)
   `(cond
      (,(cadr x) ,@(cddr x))))

(dm while (x)       % (WHILE predicate body body body ...)
   (let ((g (gensym)))
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
   (let ((vars (make_psetq_vars (cdr x))))
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
       (let ((v (car u))
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

(dm do (u) (expand_do (cdr u) 'let 'psetq))

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
      (let ((w u))
         (while (not (atom (cdr u))) (setq u (cdr u)))
         (rplacd u v)
         w)))

(preserve)

(stop 0)

