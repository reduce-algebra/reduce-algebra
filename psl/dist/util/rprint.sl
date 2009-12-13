%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: RPRINT.SL 
% Description:  
% Author:       
% Created:      
% Modified:     02-Dec-83 19:07:49 (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Experimental 
% Notes:        
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 02-Dec-83 19:07:49 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 30-Nov-83 17:20:58  Nancy Kendzierski                                   
%   Changed COMMENT to %COMMENT so un-rlisp wouldn't throw away the comment.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Module RPRINT;                                                    
% The Standard Lisp to Reduce pretty printer;                       
% These guys are set by the old parser and do not normally exist in PSL;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
(put 'expt 'op '((19 19)))

(put 'times 'op '((17 17)))

(put '!*semicol!* 'op '((-1 0)))

(put 'or 'op '((3 3)))

(put 'geq 'op '((11 11)))

(put 'not 'op '(nil 5))

(put 'recip 'op '(nil 18))

(put 'quotient 'op '((18 18)))

(put 'memq 'op '((7 7)))

(put 'minus 'op '(nil 16))

(put 'setq 'op '((2 2)))

(put 'greaterp 'op '((12 12)))

(put 'member 'op '((6 6)))

(put 'and 'op '((4 4)))

(put 'cons 'op '((20 20)))

(put 'plus 'op '((15 15)))

(put 'equal 'op '((8 8)))

(put 'leq 'op '((13 13)))

(put 'difference 'op '((16 16)))

(put 'neq 'op '((9 9)))

(put 'lessp 'op '((14 14)))

(put '!*comma!* 'op '((5 6)))

(put 'eq 'op '((10 10)))

(fluid '(pretop pretoprinf))

(setq pretop 'op)

(setq pretoprinf 'oprinf)

(fluid '(combuff))

(fluid '(curmark buffp rmar !*n))

(de rprint (u)
  (prog (buff buffp curmark rmar x !*n)
        (setq curmark 0)
        (setq buff (setq buffp (list (list 0 0))))
        (setq rmar (linelength nil))
        (setq x (get '!*semicol!* pretop))
        (setq !*n 0)
        (mprino1 u (list (caar x) (cadar x)))
        (prin2ox ";")
        (omarko curmark)
        (prinos buff)))

(de rprin1 (u)
  (prog (buff buffp curmark x)
        (setq curmark 0)
        (setq buff (setq buffp (list (list 0 0))))
        (setq x (get '!*semicol!* pretop))
        (mprino1 u (list (caar x) (cadar x)))
        (omarko curmark)
        (prinos buff)))

(de mprino (u)
  (mprino1 u (list 0 0)))

(de mprino1 (u v)
  (prog (x)
        (when (setq x (atsoc u combuff))
          (foreach y in (cdr x) do (comprox y))
          (setq combuff (delete x combuff)))
        (cond ((and (numberp u) (lessp u 0) 
                    (setq x (get 'difference pretop)))
               (return (prog (p)
                             (setq x (car x))
                             (setq p 
                              (or (not (greaterp (car x) (cadr v))) 
                               (not (greaterp (cadr x) (car v)))))
                             (when p
                               (prin2ox "("))
                             (prinox u)
                             (when p
                               (prinox ")")))))
              ((atom u) (return (prinox u)))
              ((not (atom (car u))) (setq curmark (plus curmark 1)) 
               (prin2ox "(") (mprino (car u)) (prin2ox ")") 
               (omark (list curmark 3)) 
               (setq curmark (difference curmark 1)))
              ((setq x (get (car u) pretoprinf)) 
               (return (prog (p)
                             (setq p 
                              (and (greaterp (car v) 0) 
                               (not (memq (car u) '(block . 
                                                   (prog quote
                                                    string))))))
                             (when p
                               (prin2ox "("))
                             (apply x (list (cdr u)))
                             (when p
                               (prin2ox ")")))))
              ((setq x (get (car u) pretop)) 
               (return (cond ((car x) (inprinox u (car x) v))
                             ((cddr u) (rederr "SYNTAX ERROR"))
                             ((null (cadr x)) (inprinox u (list 100 1) v))
                             (t (inprinox u (list 100 (cadr x)) v)))))
              (t (prinox (car u))))
        (when (rlistatp (car u))
          (return (rlpri (cdr u) v)))
        (setq u (cdr u))
        (if (null u)
          (prin2ox "()")
          (mprargs u v))))

(de mprargs (u v)
  (if (null (cdr u))
    (progn (prin2ox " ")
           (mprino1 (car u) (list 100 100)))
    (inprinox (cons '!*comma!* u) (list 0 0) v)))

(de inprinox (u x v)
  (prog (p)
        (setq p 
              (or (not (greaterp (car x) (cadr v))) 
                  (not (greaterp (cadr x) (car v)))))
        (when p
          (prin2ox "("))
        (omark '(m u))
        (inprino (car u) x (cdr u))
        (when p
          (prin2ox ")"))
        (omark '(m d))))

(de inprino (opr v l)
  (prog (flg x)
        (setq curmark (plus curmark 2))
        (setq x (get opr pretop))
        (when (and x (car x))
          (mprino1 (car l) (list (car v) 0))
          (setq l (cdr l))
          (setq flg t))
        (while l
          (cond ((eq opr '!*comma!*) (prin2ox ",") (omarko curmark))
                ((eq opr 'setq) (prin2ox " := ") (omark (list curmark 1)))
                ((or (atom (car l)) (not (eq opr (get!* (caar l) 'alt)))) 
                 (omark (list curmark 1)) (oprino opr flg) (setq flg t)))
          (mprino1 (car l) 
                   (list (if (null (cdr l))
                           0
                           (car v)) (if (null flg)
                           0
                           (cadr v))))
          (setq l (cdr l)))
        (setq curmark (difference curmark 2))))

(de oprino (opr b)
  ((lambda (x)
           (if (null x)
             (progn (when b
                      (prin2ox " "))
                    (prinox opr)
                    (prin2ox " "))
             (prin2ox (car x))))
   (get opr 'prtch)))

(de prin2ox (u)
  (rplacd buffp (explode2 u))
  (while (cdr buffp)
    (setq buffp (cdr buffp))))

(de prinox (u)
  (rplacd buffp (explode u))
  (while (cdr buffp)
    (setq buffp (cdr buffp))))

(de get!* (u v)
  (if (numberp u)
    nil
    (get u v)))

(de omark (u)
  (rplacd buffp (list u))
  (setq buffp (cdr buffp)))

(de omarko (u)
  (omark (list u 0)))

(de comprox (u)
  (prog (x)
        (when (equal (car buffp) '(0 0))
          (return (progn (foreach j in u do (prin2ox j))
                         (omark '(0 0)))))
        (setq x (car buffp))
        (rplaca buffp (list (plus curmark 1) 3))
        (foreach j in u do (prin2ox j))
        (omark x)))

(de rlistatp (u)
  (member (get u 'stat) '(endstat rlis rlis2)))

(de rlpri (u v)
  (cond ((null u) nil)
        ((or (not (eq (caar u) 'list)) (cdr u)) 
         (rederr "RPRINT FORMAT ERROR"))
        (t (prog nil
                 (prin2ox " ")
                 (omark '(m u))
                 (inprino '!*comma!* (list 0 0) (rlpri1 (cdar u)))
                 (omark '(m d))))))

(de rlpri1 (u)
  (cond ((null u) nil)
        ((eqcar (car u) 'quote) (cons (cadar u) (rlpri1 (cdr u))))
        ((stringp (car u)) (cons (car u) (rlpri1 (cdr u))))
        (t (rederr "RPRINT FORMAT ERROR"))))

(de condox (u)
  (prog (x)
        (omark '(m u))
        (setq curmark (plus curmark 2))
        (while u
          (prin2ox "IF ")
          (mprino (caar u))
          (omark (list curmark 1))
          (prin2ox " THEN ")
          (when (and (cdr u) (eqcar (cadar u) 'cond) 
                     (not (eqcar (car (reverse (cadar u))) 't)))
            (setq x t)
            (prin2ox "("))
          (mprino (cadar u))
          (when x
            (prin2ox ")"))
          (setq u (cdr u))
          (when u
            (omarko (difference curmark 1))
            (prin2ox " ELSE "))
          (when (and u (null (cdr u)) (eq (caar u) 't))
            (mprino (cadar u))
            (setq u nil)))
        (setq curmark (difference curmark 2))
        (omark '(m d))))

(put 'cond pretoprinf 'condox)

(de blockox (u)
  (prog nil
        (omark '(m u))
        (setq curmark (plus curmark 2))
        (prin2ox "BEGIN ")
        (when (car u)
          (varprx (car u)))
        (setq u (cdr u))
        (omark (list curmark (if (eqcar (car u) '!*label)
                       1
                       3)))
        (while u
          (mprino (car u))
          (when (and (not (eqcar (car u) '!*label)) (cdr u))
            (prin2ox "; "))
          (setq u (cdr u))
          (when u
            (omark (list curmark (if (eqcar (car u) '!*label)
                           1
                           3)))))
        (omark (list (difference curmark 1) -1))
        (prin2ox " END")
        (setq curmark (difference curmark 2))
        (omark '(m d))))

(de retox (u)
  (prog nil
        (omark '(m u))
        (setq curmark (plus curmark 2))
        (prin2ox "RETURN ")
        (omark '(m u))
        (mprino (car u))
        (setq curmark (difference curmark 2))
        (omark '(m d))
        (omark '(m d))))

(put 'return pretoprinf 'retox)

%SYMBOLIC PROCEDURE VARPRX U;                                              
%      MAPC(CDR U,FUNCTION (LAMBDA J;                                      
%			<<PRIN2OX CAR J;                                   
%			PRIN2OX " ";                                       
%			INPRINO('!*COMMA!*,LIST(0,0),CDR J);               
%			PRIN2OX "; ";                                      
%			OMARK LIST(CURMARK,6)>>));                         
%COMMENT a version for the old parser;                                     
(de varprx (u)
  (prog (typ)
        (setq u (reverse u))
        (while u
          (if (eq (cdar u) typ)
            (progn (prin2ox ",")
                   (omarko (plus curmark 1))
                   (prinox (caar u)))
            (progn (when typ
                     (prin2ox "; ")
                     (omark '(m d)))
                   (prinox (setq typ (cdar u)))
                   (prin2ox " ")
                   (omark '(m u))
                   (prinox (caar u))))
          (setq u (cdr u)))
        (prin2ox "; ")
        (omark '(m d))))

(put 'block pretoprinf 'blockox)

(de progox (u)
  (blockox (cons (mapcar (reverse (car u)) 
                         (function (lambda (j)
                                           (cons j 'scalar))))
                 (labchk (cdr u)))))

(de labchk (u)
  (prog (x)
        (foreach z in u do (if (atom z)
                   (setq x (cons (list '!*label z) x))
                   (setq x (cons z x))))
        (return (reversip x))))

(put 'prog pretoprinf 'progox)

(de gox (u)
  (prin2ox "GO TO ")
  (prinox (car u)))

(put 'go pretoprinf 'gox)

(de labox (u)
  (prinox (car u))
  (prin2ox ": "))

(put '!*label pretoprinf 'labox)

(de quotox (u)
  (if (stringp u)
    (prinox u)
    (progn (prin2ox "'")
           (prinsox (car u)))))

(de prinsox (u)
  (if (atom u)
    (prinox u)
    (progn (prin2ox "(")
           (omark '(m u))
           (setq curmark (plus curmark 1))
           (while u
             (prinsox (car u))
             (setq u (cdr u))
             (when u
               (omark (list curmark -1))
               (if (atom u)
                 (progn (prin2ox " . ")
                        (prinsox u)
                        (setq u nil))
                 (prin2ox " "))))
           (setq curmark (difference curmark 1))
           (omark '(m d))
           (prin2ox ")"))))

(put 'quote pretoprinf 'quotox)

(de prognox (u)
  (prog nil
        (setq curmark (plus curmark 1))
        (prin2ox "<<")
        (omark '(m u))
        (while u
          (mprino (car u))
          (setq u (cdr u))
          (when u
            (prin2ox "; ")
            (omarko curmark)))
        (omark '(m d))
        (prin2ox ">>")
        (setq curmark (difference curmark 1))))

(put 'prog2 pretoprinf 'prognox)

(put 'progn pretoprinf 'prognox)

(de repeatox (u)
  (prog nil
        (setq curmark (plus curmark 1))
        (omark '(m u))
        (prin2ox "REPEAT ")
        (mprino (car u))
        (prin2ox " UNTIL ")
        (omark (list curmark 3))
        (mprino (cadr u))
        (omark '(m d))
        (setq curmark (difference curmark 1))))

(put 'repeat pretoprinf 'repeatox)

(de whileox (u)
  (prog nil
        (setq curmark (plus curmark 1))
        (omark '(m u))
        (prin2ox "WHILE ")
        (mprino (car u))
        (prin2ox " DO ")
        (omark (list curmark 3))
        (mprino (cadr u))
        (omark '(m d))
        (setq curmark (difference curmark 1))))

(put 'while pretoprinf 'whileox)

(de procox (u)
  (prog nil
        (omark '(m u))
        (setq curmark (plus curmark 1))
        (when (cadddr (cdr u))
          (mprino (cadddr (cdr u)))
          (prin2ox " "))
        (prin2ox "PROCEDURE ")
        (procox1 (car u) (cadr u) (caddr u))))

(de procox1 (u v w)
  (prog nil
        (prinox u)
        (when v
          (mprargs v (list 0 0)))
        (prin2ox "; ")
        (omark (list curmark 3))
        (mprino w)
        (setq curmark (difference curmark 1))
        (omark '(m d))))

(put 'proc pretoprinf 'procox)

(de proceox (u)
  (prog nil
        (omark '(m u))
        (setq curmark (plus curmark 1))
        (mprino (cadr u))
        (prin2ox " ")
        (unless (eq (caddr u) 'expr)
          (mprino (caddr u))
          (prin2ox " "))
        (prin2ox "PROCEDURE ")
        (proceox1 (car u) (cadddr u) (car (cddddr u)))))

(de proceox1 (u v w)
  (prog nil
        (prinox u)
        (when v
          (mprargs (mapcar v (function car)) (list 0 0)))
        %we need to check here for non-default type;                       
        (prin2ox "; ")
        (omark (list curmark 3))
        (mprino w)
        (setq curmark (difference curmark 1))
        (omark '(m d))))

(put 'procedure pretoprinf 'proceox)

(de proceox0 (u v w x)
  (proceox (list u 'symbolic v 
                 (mapcar w (function (lambda (j)
                                             (cons j 'symbolic)))) x)))

(de deox (u)
  (proceox0 (car u) 'expr (cadr u) (caddr u)))

(put 'de pretoprinf 'deox)

(de dfox (u)
  (proceox0 (car u) 'fexpr (cadr u) (caddr u)))

(put 'df pretoprinf 'dfox)

(de dmox (u)
  (proceox0 (car u) 'macro (cadr u) (caddr u)))

(put 'dm pretoprinf 'dmox)

(de lambdox (u)
  (prog nil
        (omark '(m u))
        (setq curmark (plus curmark 1))
        (procox1 'lambda (car u) (cadr u))))

(put 'lambda pretoprinf 'lambdox)

(de eachox (u)
  (prin2ox "FOR EACH ")
  (while (cdr u)
    (mprino (car u))
    (prin2ox " ")
    (setq u (cdr u)))
  (mprino (car u)))

(put 'foreach pretoprinf 'eachox)

%COMMENT Declarations needed by old parser;                                
(when (null (get '!*semicol!* 'op))
  (put '!*semicol!* 'op '((-1 0)))
  (put '!*comma!* 'op '((5 6))))

%COMMENT RPRINT MODULE, Page 2;                                            
(fluid '(orig curpos))

(de prinos (u)
  (prog (orig curpos)
        (setq orig (list (posn)))
        (setq curpos (car orig))
        (prinoy u 0)
        (terpri0x)))

(de prinoy (u n)
  (prog (x)
        (cond ((car (setq x (spaceleft u n))) (return (prinom u n)))
              ((null (cdr x)) 
               (return (if (lessp (car orig) 10)
                         (prinom u n)
                         (progn (setq orig (cons 9 (cdr orig)))
                                (terpri0x)
                                (rpspaces2 
                                 (setq curpos (plus 9 (cadar u))))
                                (prinoy u n)))))
              (t (prog nil
                  a
                       (setq u (prinoy u (plus n 1)))
                       (when (or (null (cdr u)) (leq (caar u) n))
                         (return nil))
                       (terpri0x)
                       (rpspaces2 
                        (setq curpos (plus (car orig) (cadar u))))
                       (go a))))
        (return u)))

(de spaceleft (u mark)
  %U is an expanded buffer of characters delimited by non-atom marks       
  %of the form: '(M ...) or '(INT INT))                                    
  %MARK is an integer;                                                     
  (prog (flg mflg n)
        (setq n (difference rmar curpos))
        (setq u (cdr u))
        %move over the first mark;                                         
        (while (and u (not flg) (geq n 0))
          (cond ((atom (car u)) (setq n (difference n 1)))
                ((eq (caar u) 'm) nil)
                ((geq mark (caar u)) (setq flg t) (setq u (cons nil u)))
                (t (setq mflg t)))
          (setq u (cdr u)))
        (return (cons (geq n 0) mflg))))

(de prinom (u mark)
  (prog (flg x n)
        (setq n curpos)
        (setq u (cdr u))
        (while (and u (not flg))
          (cond ((atom (car u)) (setq x (prin20x (car u))) 
                 (setq n (plus n 1)))
                ((eq (caar u) 'm) (if (eq (cadar u) 'u)
                   (setq orig (cons n orig))
                   (setq orig (cdr orig))))
                ((and (geq mark (caar u)) 
                      (not 
                       (and (equal x '!,) 
                        (greaterp (difference (difference rmar n) 6) 
                         (charspace u x mark)))))
                 (setq flg t) (setq u (cons nil u))))
          (setq u (cdr u)))
        (setq curpos n)
        (when (and (equal mark 0) (cdr u))
          (terpri0x)
          (terpri0x)
          (setq orig (list 0))
          (setq curpos 0)
          (prinoy u mark))
        %must be a top level constant;                                     
        (return u)))

(de charspace (u chr mark)
  %determines if there is space until the next character CHR;              
  (prog (n)
        (setq n 0)
        (while u
          (cond ((equal (car u) chr) (setq u (list nil)))
                ((atom (car u)) (setq n (plus n 1)))
                ((equal (car u) '(m u)) (setq n 1000) (setq u (list nil)))
                ((and (numberp (caar u)) (lessp (caar u) mark)) 
                 (setq u (list nil))))
          (setq u (cdr u)))
        (return n)))

(de rpspaces2 (n)
  %FOR I := 1:N DO PRIN20X '! ;                                            
  (while (greaterp n 0)
    (prin20x '! )
    (setq n (difference n 1))))

(de prin2rox (u)
  (prog (x y m n)
        (setq m (difference rmar 12))
        (setq n (difference rmar 1))
        (while u
          (cond ((eq (car u) '!") (if (not 
                                       (stringspace (cdr u) 
                                        (difference n !*n)))
                   (progn (terpri0x)
                          (setq !*n 0))
                   nil)
                 (prin20x '!") (setq u (cdr u)) (while (not 
                                                        (eq (car u) '!"))
                   (prin20x (car u))
                   (setq u (cdr u))
                   (setq !*n (plus !*n 1)))
                 (prin20x '!") (setq u (cdr u)) (setq !*n (plus !*n 2)) 
                 (setq x (setq y nil)))
                ((and (atom (car u)) 
                      (not 
                       (and (eq (car u) '! ) 
                        (or (equal !*n 0) (null x) 
                         (and (cdr u) (breakp (cadr u))) 
                         (and (breakp x) (not (eq y '!!)))))))
                 (setq y x) (prin20x (setq x (car u))) 
                 (setq !*n (plus !*n 1)) (setq u (cdr u)) (if (or 
                                                               (equal !*n 
                                                                n)
                                                               (and 
                                                                (greaterp 
                                                                 !*n m)
                                                                (not 
                                                                 (breakp 
                                                                  (car u)))
                                                                (nospace u 
                                                                 (difference
                                                                  n !*n))))
                   (progn (terpri0x)
                          (setq x (setq y nil)))
                   nil))
                (t (setq u (cdr u)))))))

(de nospace (u n)
  (cond ((lessp n 1) t)
        ((null u) nil)
        ((not (atom (car u))) (nospace (cdr u) n))
        ((and (not (eq (car u) '!!)) 
              (or (eq (cadr u) '! ) (breakp (cadr u))))
         nil)
        (t (nospace (cdr u) (difference n 1)))))

(de breakp (u)
  (member u '(!< !> !; !: != !) !+ !- !, !' !")))

(de stringspace (u n)
  (cond ((lessp n 1) nil)
        ((eq (car u) '!") t)
        (t (stringspace (cdr u) (difference n 1)))))

%COMMENT Some interfaces needed;                                           
(put 'cons 'prtch '(! !.!  !.))

(global '(rprifn!* rterfn!*))

%COMMENT RPRIFN!* allows output from RPRINT to be handled differently,     
%	 RTERFN!* allows end of lines to be handled differently;           
(de prin20x (u)
  (if rprifn!*
    (apply rprifn!* (list u))
    (prin2 u)))

(de terpri0x ()
  (if rterfn!*
    (apply rterfn!* nil)
    (terpri)))

