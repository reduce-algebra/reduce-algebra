%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% File:         PU:VFVECT.SL
% Description:  very fast vector access                                  
% Author:       H. Melenk
% Created:      25 January 1989
% Modified:
% Mode:         Lisp
% Package:      Utilities
% Status:       Experimental
%
% (c) Copyright 1989, Konrad-Zuse-Zentrum, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  this file is needed compiletime only
%
% This file defines a macro VFOR which has the same syntax as IFOR.
% The basic difference is that VFOR looks into the body to be executed
% and replaces all vector accesses via IgetV and IputV by references to   
% explicitly calculated addresses.                                           
(fluid '(*second-value* *variables*))
(fluid '(veccis gettis)) 

(dm vfor(u)
   (prog (vars body cvar veccis gettis by from to lvars pvars zvars let
          cvars *variables*)
          (setq from (append (assoc 'from u) '(1)))
          (setq by (caddr(cddr from)))
          (setq to (cadddr from))
          (setq cvar (cadr from))  % control variable
          (setq cvars (list cvar))
          (setq from (caddr from))
          (setq body (assoc 'do u))
          (when (null body)
                (comperr "******* do clause missing in vfor expansion"))
          (setq body (cadr body))  % strip off tag 'DO
          (setq let (assoc 'let u))
          (when let (setq let (cdr let))
                (setq cvars (cons (car let) cvars))
                (setq body (subst (cadr let) (car let) body))
                (extract-variables (cadr let))
                (setq *variables* (delete cvar *variables*)))
          (select-putv/getv body cvar)
          (setq zvars (mapcar gettis (function
               (lambda (x) (cons x (gensym))))))
          (setq pvars (cons cvar (mapcar zvars (function cdr))))
          (when let (setq pvars (cons (car let) pvars)))
                
               % case 1: from is a number
         (when (numberp from)
          (return 
          `(prog ,pvars
               (setq ,cvar ,from)
               (progn . ,(mapcar zvars
                           (function (lambda (x)
                              `(setq ,(cdr x)
                                ,(vfor-simp 
                                `(iplus2 (inf ,(caar x))
                                    (itimes2 addressingunitsperitem
                                       (iplus2 ,(subst from cvar (cdar x))
                                                1)))))))))

               ***loop***
               ,(if (greaterp by 0)
                    `(cond((igreaterp ,cvar ,to)(return NIL)))
                    `(cond((ilessp ,cvar ,to)(return NIL))))
               ,(reform-vfor body zvars)
               (progn . ,(mapcar zvars 
                           (function (lambda (x)
                              `(setq ,(cdr x)  
                               ,(vfor-simp 
                                ` (iplus2 ,(cdr x)
                                    (itimes2 addressingunitsperitem
                                       (idifference
                                          ,(subst by cvar (cdar x))
                                          ,(subst 0 cvar (cdar x))
                      )))))))))
               (setq ,cvar (iplus2 ,cvar ,by))
               (go ***loop***))))
               % case 2: from is an arbitrary expression
          (return
          `(prog ,pvars
               (setq ,cvar ,from)
               (progn . ,(mapcar zvars 
                           (function (lambda (x) 
                              `(setq ,(cdr x) 
                               ,(vfor-simp
                                `(iplus2 (inf ,(caar x)) 
                                    (itimes2 addressingunitsperitem 
                                       (iplus2 ,(subst from cvar (cdar x))
                                                1)))))))))
               ***loop***
               ,(if (greaterp by 0) 
                    `(cond((igreaterp ,cvar ,to)(return NIL))) 
                    `(cond((ilessp ,cvar ,to)(return NIL))))
               ,(reform-vfor body zvars)
               (progn . ,(mapcar zvars  
                           (function (lambda (x) 
                              `(setq ,(cdr x)   
                               ,(vfor-simp
                                `(iplus2 ,(cdr x) 
                                    (itimes2 addressingunitsperitem 
                                      (idifference 
                                          ,(subst by cvar (cdar x))
                                          ,(subst 0 cvar (cdar x)) 
                      )))))))))
               (setq ,cvar (iplus2 ,cvar ,by))
               (go ***loop***)))

))
 
(de select-putv/getv(form var)
   (cond ((atom form) nil)
         ((and (eqcar form 'iputv) (dependsof (caddr form) var))
          (setq gettis (union gettis (list (cons (cadr form) (caddr form)))))
          (select-putv/getv (cadddr form) var))
         ((and (eqcar form 'igetv) (dependsof (caddr form) var)) 
          (setq gettis (union gettis (list (cons (cadr form) (caddr form))))))
         (t (mapc form (function (lambda(x)(select-putv/getv x var)))))))
 
(de reform-vfor(form lvars)
    (cond ((atom form) form)
         ((and (eqcar form 'iputv)(assoc (cons (cadr form)(caddr form)) lvars))
          `(putmem ,(cdr (assoc (cons (cadr form)(caddr form)) lvars)) 
                   ,(reform-vfor (cadddr form) lvars)))
         ((and (eqcar form 'igetv)(assoc (cons (cadr form)(caddr form)) lvars))
          `(getmem ,(cdr (assoc (cons (cadr form)(caddr form)) lvars))))
         (t (mapcar form (function (lambda(x)(reform-vfor x lvars))))))) 


(de dependsof(form var)
   % test if the form depends only linearly from var
      (cond ((equal form var)t)
            ((numberp form) t)
            ((memq form *variables*) t)
            ((and (atom form) (get form 'constant?)(numberp (eval form))) T)
            ((atom form) nil)
            ((eqcar form 'iplus2)(and (dependsof (cadr form) var)
                                      (dependsof (caddr form) var)))
            ((eqcar form 'idifference)(and (dependsof (cadr form) var)
                                      (dependsof (caddr form) var)))
            ((eqcar form 'itimes2)
             (or (and (dependsof (cadr form) nil)
                      (dependsof (caddr form) var))
                 (and (dependsof (cadr form) nil) 
                      (dependsof (caddr form) var))))
            ((memq (car form) '(iadd1 isub1)) (dependsof (cadr form) var))
            (T nil)))

(de extract-variables(u)
   % extract the variables from an expression
      (cond ((null u) *variables*)
            ((numberp u) *variables*)
            ((pairp u) (mapc (cdr u) (function extract-variables)) *variables*)
            ((get u 'constant?) *variables*)
            (t (setq *variables* (union (cons u nil) *variables*)))))
 
(fluid '(*ioperators))
(setq *ioperators '((iplus2 . plus2)(idifference . difference)
                    (itimes2 . times2)(iquotient . quotient)
                    (isub1 . sub1)(iadd1 . add1)))

(de vfor-simp (u)
   % simplify an arithmetic expression based on i-operations
   (cond ((null u) nil)
         ((numberp u) u)
         ((get u 'constant?) (eval u))
         ((atom u) u)
         ((null (assoc (car u) *ioperators)) u)
         (T (prog (o x y h)
                (setq o (car u))
                (when (cdr u) (setq x (vfor-simp (cadr u)))
                      (when (cddr u) (setq y(vfor-simp  (caddr u)))))
                (when (and (eq o 'idifference) (numberp y))
                      (setq o 'iplus2)(setq y (minus y)))
                (when (and (numberp x)(numberp y))
                      (return (apply (cdr (assoc o *ioperators))
                                     (list x y))))
                (when (and (memq o '(itimes2 iplus2)) (numberp x))
                      (setq h x)(setq x y)(setq y h))
                (setq u(list o x y))
                (while (setq h (vfor-pat u)) (setq u (vfor-simp h)))
                (return u)))))
 
(fluid '(vfor-patterns*))
(setq vfor-patterns* '(
     ( (iadd1 *a nil)(iplus2 *a 1))
     ( (isub1 *a nil)(iplus2 *a -1))
     ( (iplus2 (iplus2 *a *n)(iplus2 *b *m))
       (iplus2 (iplus2 *a *b)(iplus2 *n *m)))
     ( (iplus2 (iplus2 *a *n) *m) (iplus2 *a (iplus2 *n *m)))
     ( (iplus2 *a 0) *a)
     ( (iplus2 *n *m)(eval (plus *n *m)))
     ( (idifference *a 0) *a)
     ( (idifference *a *a) 0)
     ( (idifference *a (iplus2 *a *n)) (iminus *n))
     ( (idifference (iplus2 *a *n) *b) (idifference *a (iplus2 *b(iminus *n))))
     ( (idifference (idifference *a *b) (idifference *a *c))
       (idifference *c *b))
     ( (idifference (iplus2 *a *b) *a)  *b)
     ( (iminus *n) (eval (minus *n)))
     
))

(de vfor-pat (u)
    (prog (p q)
         (setq p vfor-patterns*)
  loop   (when (null p)(return nil))
         (setq q(vfor-match u (caar p) (list nil)))
         (when q (setq q (subla q (cadar p)))
                 (when (eqcar q 'eval)
                       (setq q (eval (cadr q))))
                 (return q))
         (setq p (cdr p))
         (go loop)))
 
(de vfor-match(u pat a)
     (cond ((equal u pat) a)
           ((memq pat '(*a *b *c *d *n *m)) (vfor-match-variable u pat a))
           ((or (atom u) (atom pat))nil)
           ((setq a (vfor-match (car u)(car pat) a))
                    (vfor-match (cdr u)(cdr pat) a))))
 
(de  vfor-match-variable(u pat a) 
     (cond ((null (assoc pat a))  % not yet bound 
            (cond ((or (not (memq pat '(*n *m))) (numberp u))
                   (nconc a (list (cons pat u))))
                  (T nil)))
           ((equal (cdr (assoc pat a)) u) a)
           (T nil)))

