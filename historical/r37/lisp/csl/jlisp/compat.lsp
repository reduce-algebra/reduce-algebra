


% This file defines functions and variables needed to make REDUCE
% and the underlying CSL system compatible. it should
% be loaded as the first file whenever REDUCE services are required.

(setpchar "> ")

(flag '(raise lower echo comp plap pgwd pwrds savedef) 'switch)

(make!-special '!*echo)
(setq !*echo nil)
(make!-special '!*raise)
(setq !*raise nil)
(make!-special '!*lower)
(setq !*lower t)
(make!-special '!*savedef)
% I only nil out !*savedef if it is not already present because of
% some bootstrapping delicacies when this file is re-loaded.
(if (not (boundp '!*savedef)) (setq !*savedef nil))
(make!-special '!*comp)
(setq !*comp nil)
(make!-special '!*plap)
(setq !*plap nil)
(make!-special '!*pgwd)
(setq !*pgwd nil)
(make!-special '!*pwrds)
(setq !*pwrds t)

(make!-special '!!fleps1)
(setq !!fleps1 1.0e-12)

(de expand (l fn)
   (cond
      ((null (cdr l)) (car l))
      (t (list fn (car l) (expand (cdr l) fn)))))

(de mapcar (l fn)
  (prog (r)
 top (cond ((null l) (return (reversip r))))
     (setq r (cons (funcall fn (car l)) r))
     (setq l (cdr l))
     (go top)))

(de maplist (l fn)
  (prog (r)
 top (cond ((null l) (return (reversip r))))
     (setq r (cons (funcall fn l) r))
     (setq l (cdr l))
     (go top)))

(de mapcan (l fn)
  (cond ((null l) nil)
	(t (nconc (funcall fn (car l)) (mapcan (cdr l) fn)))))

(de mapcon (l fn)
  (cond ((null l) nil)
	(t (nconc (funcall fn l) (mapcon (cdr l) fn)))))

(de mapc (l fn)
  (prog ()
 top (cond ((null l) (return nil)))
     (funcall fn (car l))
     (setq l (cdr l))
     (go top)))

(de map (l fn)
  (prog ()
 top (cond ((null l) (return nil)))
     (funcall fn l)
     (setq l (cdr l))
     (go top)))

(de copy (a)
   (cond
      ((atom a) a)
      (t (cons (copy (car a)) (copy (cdr a))))))

(de sassoc (a l fn)
  (cond
     ((atom l) (funcall fn))
     ((equal a (caar l)) (car l))
     (t (sassoc a (cdr l) fn))))

(de rassoc (x l)        % Not in Standard Lisp
   (prog ()
loop  (cond ((atom l) (return nil))
	    ((equal x (cdar l)) (return (car l)))
	    (t (setq l (cdr l)) (go loop))) ))

(de lastcar (x)         % Not in Standard Lisp
   (cond
      ((null x) nil)
      ((null (cdr x)) (car x))
      (t (lastcar (cdr x)))))


(de putd (a type b)
  (progn
     (cond
	((eqcar b 'funarg) (setq b (cons 'lambda (cddr b)))))
     (cond
	((and !*redefmsg (getd a)) (progn
	   (terpri) (princ "+++ ") (prin a) (printc " redefined"))))
     (cond
	((eq type 'expr) (eval (list!* 'de a (cdr b))))
	((and (eq type 'macro) (eqcar b 'lambda))
            (eval (list!* 'dm a (cdr b))))
	(t (error "Bad type ~S in putd" type)))
     a))

(de putc (a b c)
   (put a b c))

(de traceset1 (name)
   (prog (w !*comp)
      (setq w (getd name))
      (cond ((not (and (eqcar w 'expr) (eqcar (cdr w) 'lambda)))
         (princ "+++++ ") (prin name)
         (printc " should be interpreted for traceset to work")
         (return nil)))
      (trace (list name))
      (putd name 'expr (subst 'noisy!-setq 'setq (cdr w)))))

(de untraceset1 (name)
   (prog (w !*comp)
      (setq w (getd name))
      (cond ((not (and (eqcar w 'expr) (eqcar (cdr w) 'lambda)))
         (princ "+++++ ") (prin name)
         (printc " should be interpreted for untraceset to work")
         (return nil)))
      (untrace (list name))
      (putd name 'expr (subst 'setq 'noisy!-setq (cdr w)))))

(de traceset (l)
   (mapc l (function traceset1)))

(de untraceset (l)
   (mapc l (function untraceset1)))

(de deflist (a b)
  (prog (r)
top (cond ((null a) (return (reversip r))))
    (put (caar a) b (cadar a))
    (setq r (cons (caar a) r))
    (setq a (cdr a))
    (go top)))

(de global (l)
   (prog nil
 top  (cond ((null l) (return nil)))
      (make!-global (car l))
      (cond ((not (boundp (car l))) (set (car l) nil)))
      (setq l (cdr l))
      (go top)))

(de fluid (l)
   (prog nil
 top  (cond ((null l) (return nil)))
      (make!-special (car l))
      (cond ((not (boundp (car l))) (set (car l) nil)))
      (setq l (cdr l))
      (go top)))

(de unglobal (l)
   (prog ()
 top  (cond ((null l) (return nil)))
      (unmake!-global (car l))
      (setq l (cdr l))
      (go top)))

(de unfluid (l)
   (prog ()
 top  (cond ((null l) (return nil)))
      (unmake!-special (car l))
      (setq l (cdr l))
      (go top)))

(global '(ofl!*))

(de printprompt (u) nil)

(global '(program!* ttype!* eof!*))

(global '(crbuf!*))

(global '(blank !$eol!$ tab !$eof!$ esc!*))

(fluid '(!*notailcall !*carcheckflag))

(setq !*notailcall nil)
(setq !*carcheckflag t)

(de carcheck (n)
   (prog (old)
      (cond ((zerop n) (setq n nil)))
      (setq old !*carcheckflag)
      (setq !*carcheckflag n)
      (return old)))

(progn
   (setq blank   (special!-char 0))
   (setq !$eol!$ (special!-char 1))
   (setq tab     (special!-char 3))
   (setq esc!*   (special!-char 9))
   (setq !$eof!$ (special!-char 8))
   nil)

(setq crbuf!* (list !$eol!$))    % may not be  necessary

(de symerr (u v)
  (progn (terpri)
     (print (list 'symerr u v))
     (error 'failure)))


% Now a few things not needed by Standard Lisp but maybe helpful
% when using Lisp directly.

(de s!:make!-psetq!-vars (u)
   (if (null u)
       nil
       (if (null (cdr u))
           (error "odd number of items in psetq")
           (cons (gensym) (s!:make!-psetq!-vars (cddr u))))))

(de s!:make!-psetq!-bindings (vars u)
   (if (null u)
       nil
       (cons
          (list (car vars) (cadr u))
          (s!:make!-psetq!-bindings (cdr vars) (cddr u)))))

(de s!:make!-psetq!-assignments (vars u)
   (if (null u)
       nil
       (cons
          (list 'setq (car u) (car vars))
          (s!:make!-psetq!-assignments (cdr vars) (cddr u)))))

(dm psetq (x)
   (!~let ((vars (s!:make!-psetq!-vars (cdr x))))
      `(let!* ,(s!:make!-psetq!-bindings vars (cdr x))
         ,@(s!:make!-psetq!-assignments vars (cdr x)))))

% (do ((v i s) ..)
%     (end result ...)
%     body)

(de s!:do!-bindings (u)
   (if (null u)
       nil
       (if (atom (car u))
           (cons (car u) (s!:do!-bindings (cdr u)))
           (if (null (cdar u))
               (cons (list (caar u) nil) (s!:do!-bindings (cdr u)))
               (cons (list (caar u) (cadar u)) (s!:do!-bindings (cdr u)))))))

(de s!:do!-endtest (u)
   (if (null u)
       nil
       (car u)))

(de s!:do!-result (u)
   (if (null u)
       nil
       (cdr u)))

(de s!:do!-updates (u)
   (if (null u)
       nil
       (!~let ((v (car u))
             (x (s!:do!-updates (cdr u))))
          (if (or (atom v)
                  (null (cdr v))
                  (null (cddr v)))
              x
              (cons (car v) (cons (caddr v) x))))))


(de s!:expand!-do (u letter setter)
   (let!* ((bindings (s!:do!-bindings (car u)))
           (result (s!:do!-result (cadr u)))
           (updates (s!:do!-updates (car u)))
           (body (cddr u))
           (endtest (s!:do!-endtest (cadr u)))
           (upd (if updates (list (cons setter updates)) nil))
           (res (if (null result)
                    nil
                    (if (null (cdr result))
                        (car result)
                        (cons 'progn result))))
           (x (if (null endtest) nil
                  `((if ,endtest (return ,res)))))
           (g (gensym)))
      (if bindings
         `(,letter ,bindings
               (prog nil
            ,g    ,@x
                  ,@body
                  ,@upd
                  (go ,g)))
         `(prog nil
         ,g    ,@x
               ,@body
               ,@upd
               (go ,g)))))

(dm do (u) (s!:expand!-do (cdr u) '!~let 'psetq))

(dm do!* (u) (s!:expand!-do (cdr u) 'let!* 'setq))

(de s!:expand!-dolist (vir b)
   (prog (l v var init res)
     (setq var (car vir))
     (setq init (car (setq vir (cdr vir))))
     (setq res (cdr vir))
     (setq v (gensym))
     (setq l (gensym))
     (return `(prog (,v ,var)
                (setq ,v ,init)
           ,l   (cond ((null ,v) (return (progn ,@res))))
                (setq ,var (car ,v))
                ,@b
                (setq ,v (cdr ,v))
                (go ,l)))))

(dm dolist (u) (s!:expand!-dolist (cadr u) (cddr u)))

(de s!:expand!-dotimes (vnr b)
   (prog (l v var count res)
     (setq var (car vnr))
     (setq count (car (setq vnr (cdr vnr))))
     (setq res (cdr vnr))
     (setq v (gensym))
     (setq l (gensym))
     (return `(prog (,v ,var)
                (setq ,v ,count)
                (setq ,var 0)
           ,l   (cond ((not (lessp ,var ,v)) (return (progn ,@res))))
                ,@b
                (setq ,var (add1 ,var))
                (go ,l)))))

(dm dotimes (u) (s!:expand!-dotimes (cadr u) (cddr u)))

(flag '(geq leq neq logand logor logxor leftshift princ printc
	evenp reversip seprp atsoc eqcar flagp!*!* flagpcar get!*
	prin1 prin2 apply0 apply1 apply2 apply3 smemq spaces
	subla gcdn printprompt pair) 'lose)

% end of compat.lsp


