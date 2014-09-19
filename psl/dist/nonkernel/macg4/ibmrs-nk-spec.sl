%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         ibmrs-nk-spec.sl
% Title:        misc functions for IBM RS 6000 nonkernel
% Author:       Winfried Neun
% Created:      27 February 1989
% Status:       Experimental
% Mode:         Lisp
% Package:      Kernel
%
% (c) Copyright 1989, Konrad-Zuse-Zentrum Berlin, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
  (flag '(halfwordsequal vectorequal wordsequal intern-equal
          bothzero floateqn pairequal fast-wordsequal )
                   'internalfunction))

(remd 'eqn)

(de eqn (u v)
  % Eq or numeric equality.
      (case (tag u)
        ((posint-tag)   (or (weq u v) (and (eq 0 u) (bothzero u v))))
        ((negint-tag)   (weq u v))
        ((floatnum-tag) (floateqn u v))
        ((fixnum-tag)
                (and (fixnp v) (weq (fixval (fixinf u)) (fixval (fixinf v)))))
        ((bignum-tag)   (and (bigp v) (wordsequal u v)))
        (nil nil)))

(de floateqn (u v)
      (or (and (floatp v)
               (weq (floathighorder (fltinf u)) (floathighorder (fltinf v)))
               (weq (floatloworder (fltinf u))  (floatloworder (fltinf v))))
          (bothzero u v)))

(de bothzero (u v) (and (zerop u) (zerop v)))

(remd 'equal)

(de equal (u v)
  % Structural equality
      (case (tag u)
        ((posint-tag)    (or (weq u v) (and (eq u 0) (eqn u v))))
        ((negint-tag code-tag id-tag unbound-tag forward-tag 16 17 18 19)
                         (weq u v))  % to fool &comcase
        ((evector-tag)   (or (weq u v) (evectorequal u v)))
        ((vector-tag)    (and (vectorp v) (vectorequal u v)))
        ((string-tag)    (and (stringp v) (stringequal u v)))
        ((bytes-tag)     (and (bytesp v)  (stringequal u v)))
        ((pair-tag)      (and (pairp v)   (pairequal u v)))
        ((floatnum-tag)  (eqn u v))
        ((fixnum-tag)    (eqn u v))
        ((bignum-tag)    (and (bigp v)    (wordsequal u v)))
        ((words-tag)     (and (wrdsp v)   (wordsequal u v)))
        ((halfwords-tag) (and (halfwordsp v) (halfwordsequal u v)))
        ((hbytes-tag hhalfwords-tag hwords-tag hvect-tag sgd-tag)
          (weq u v)) %just to fool &comcase
        (nil nil)))

(de intern-equal (u v)
  % Structural equality
      (case (tag u)
        ((posint-tag)    (or (weq u v) (and (eq u 0) (eqn u v))))
        ((negint-tag code-tag id-tag unbound-tag forward-tag 16 17 18 19)
                         (weq u v))  % to fool &comcase
        ((evector-tag)   (or (weq u v) (evectorequal u v)))
        ((vector-tag)    (and (vectorp v) (vectorequal u v)))
        ((string-tag)    (and (stringp v) (stringequal u v)))
        ((bytes-tag)     (and (bytesp v)  (stringequal u v)))
        ((pair-tag)      (and (pairp v)   (pairequal u v)))
        ((floatnum-tag)  (eqn u v))
        ((fixnum-tag)    (eqn u v))
        ((bignum-tag)    (and (bigp v)    (wordsequal u v)))
        ((words-tag)     (and (wrdsp v)   (wordsequal u v)))
        ((halfwords-tag) (and (halfwordsp v) (halfwordsequal u v)))
        ((hbytes-tag hhalfwords-tag hwords-tag hvect-tag sgd-tag)
          (weq u v)) %just to fool &comcase
        (nil nil)))


(de pairequal (u v)
     (cond ((eq u v) t)
           ((intern-equal (car u) (car v)) (intern-equal (cdr u) (cdr v)))
           (T nil)))
 
(remd 'wordsequal)

(de wordsequal (u v)
  (prog (s1 i)
        (setq u (wrdinf u))
        (setq v (wrdinf v))
        (unless (weq (setq s1 (wrdlen u)) (wrdlen v)) (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i s1)    (return t))
        (unless (weq (wrditm u i) (wrditm v i))  (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(remd 'halfwordsequal)

(de halfwordsequal (u v)
  (prog (s1 i)
        (setq u (halfwordinf u))
        (setq v (halfwordinf v))
        (unless (wgreaterp (setq s1 (halfwordlen u)) (halfwordlen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i s1)        (return t))
        (unless (weq (halfworditm u i) (halfworditm v i)) (return nil))
        (setq i (wplus2 i 1))
        (go loop)))


(remd 'vectorequal)

(de vectorequal (u v)
  % Vector equality without type check
  (prog (len i)
        (setq u (vecinf u))
        (setq v (vecinf v))
        (setq len (veclen u))
        (when (wneq len (veclen v))  (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i len)      (return t))
        (unless (equal (vecitm u i) (vecitm v i))       (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(remd 'evlis)

(de evlis(u)
      (prog (result pointer)
           (when (not (pairp u)) (return nil))
           (setq pointer (setq result (cons (eval (car u)) nil)))
       loop
           (setq u (cdr u))
           (when (not (pairp u)) (return result))
           (rplacd pointer (cons (eval (car u)) nil))
           (setq pointer (cdr pointer))
           (go loop)))

(copyd 'eval-aux 'eval)

% a simple case (alloc free) dispatch for eval

(remd 'eval)

(de eval (u)
   (prog (v)
     (case (tag u)
        ((id-tag) (if (or (null u)
			(not (eq unbound-tag (tag (setq v (symval (inf u)))))))
                             (return v)
                             (return (eval-aux u))))
        ((pair-tag) (return (eval-aux u)))
        ((0 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23
          24 25 26 27 28 29 31)   (return u))  % not id or atom
) ))
(de > (x y) (greaterp x y))
(de fast-plus (x y) (wplus2 x y))
 (lap '((*entry !*!*hu!*!* expr 0) (*move 16#74 (reg r0))
(*mkitem (reg r0) 30) (*exit 0)))
(!*!*hu!*!*)

(compiletime 
(put 'pputlr 'opencode '((!*move (reg 1) (displacement (reg 2) 8))))
(put 'putlr 'opencode '((!*move (displacement (reg r1) 0) (reg 2));
                       (!*move (reg 1) (displacement (reg 2) 8))))
(put 'getlr 'opencode '((!*move (displacement (reg r1) 0) (reg 1))
                       (!*move (displacement (reg 1) 8) (reg 1))))
(put 'getst 'opencode '((!*move (reg r1) (reg 1))))
)

(remd 'errorset)

(fluid '(save_lr))

% A safety variant which restores the link register
% which happens to be overwritten in stack

(de errorset (form !*emsgp !*inner!*backtrace)
(prog (sta save_lr resu)
(setq save_lr (getlr))
(setq sta (getst))
 %  unixputn getst();
 % console!-print!-string " der stack ";
 %  unixputn getlr();
 %  console!-print!-string " das linkreg ";
 % console!-newline();
(setq resu (catch '!$error!$ (ncons (eval form))))
 % unixputn getst();
 %console!-print!-string " der neue stack ";
 % console!-newline();
 %   unixputn getlr();
 %  console!-print!-string " das neue linkreg ";
 %console!-newline();

(putlr save_lr sta)
 %  console!-print!-string " Geputtet ";
 % console!-newline();
(return resu)
))
