%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EASY-SL.SL 
% Title:        Standard Lisp functions with easy Standard Lisp definitions 
% Author:       Eric Benson 
% Created:      17 August 1981 
% Modified:     31-May-84 10:42:18 (Brian Beach) 
% Package:      Kernel 
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22-Mar-88 (James Davenport)
%  Added the Milne/Galway fixed expt function (faster)
% 03-Aug-87 (Leigh Stoller)
%  Added Tony Hearn's fixed expt function.
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 31-May-84 10:31:44 (Brian Beach)
%  Fixed EXPT as per fixes by Nancy Kendzierski and Cris Perdue.
% 02-Mar-84 09:29:30 (Jim Ambras/CRC)
%  Corrected file header.
% 23-Jan-84 11:48:54 (Cris Perdue)
%  Provided error checking and message for error of odd number
%  of args to SETQ.
% 18-Jan-84 17:51:54 (Cris Perdue)
%  Fixed definitions of some of the mapping functions.  They
%  were written requiring actual runtime recursion and with
%  dependence on left-to-right evaluation of arguments in
%  compiled code.  Now compiletime loads USEFUL.
% 01-Dec-83 14:30:06 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime
  (load useful))

(compiletime
  (flag '(evand1) 'internalfunction))

(fluid '(in* out*))

% Section 3.1 -- Elementary predicates
(de atom (u)
  %. is U a non pair?
  (not (pairp u)))

(de constantp (u)
  %. is Eval U eq U by definition?
  (and (not (pairp u)) (not (idp u))))

(de null (u)
  %. is U eq NIL?
  (eq u nil))

(de numberp (u)
  %. is U a number of any kind?
  (or (fixp u) (floatp u)))

% New version of expt without extra squaring.  Thanks to Philip
% Milne (psm) for noticing this and providing the first version of
% this code.  Also modified to use iminusp and iminus, instead of
% "slower" versions. (This could be a mistake.)
% When raising x^n, x a fairly big bignum, the new
% version appears to be 2 to 4 times faster than the previous
% version, depending on n.  Perhaps 30% faster when x is a smallish
% bignum. 
% (JHD) Above note written by Will Galway. Here are his timings:
% x^n      |   Iterations   |   Old   |   New
% --------------------------------------------------------------
% 2^12     |        1000    |    688  |    600
% 2^30     |        1000    |   2300  |   1600
% 11^199   |         100    |  11200  |   6000
% m^2      |         100    |  65300  |  14500


(de expt-rec (x n a)
    % Tail recursive heart of expt.  a is the running product for
    % finding x^n.
    (cond
     ((izerop n)
      a)
     ((ionep n)
      (times x a))
     (t
      (let ((tmp (divide n 2)))
	(cond
	 ((izerop (cdr tmp))
	  (expt-rec (times x x) (car tmp) a))
	 (t
	  (expt-rec (times x x) (car tmp) (times x a))))))))

(de expt (x n)
  (cond
    ((not (fixp n)) (nonintegererror n 'expt))
    ((izerop n) 1)
    ((ionep n) x)
    ((iminusp n)
     (expt-rec (quotient 1.0 x) (iminus n) 1))
    (t
     (expt-rec x n 1))))

% Old version
% (de expt (x n)
%   (cond
%     ((not (fixp n)) (nonintegererror n 'expt))
%     ((izerop n) 1)
%     ((ionep n) x)
%     ((minusp n)
%      (cond
%        ((eqn n -1) (quotient 1.0 x))
%        (t (let ((a 1.0))
%          (while (not (izerop n))
%            (let ((tmp (divide n 2)))
%              (cond
%                ((ionep (iminus (cdr tmp))) (setq a (quotient a x))))
%              (setq x (times x x))
%              (setq n (car tmp))))
%          a))))
%     (t (let ((a 1))
%       (while (not (izerop n))
%         (let ((tmp (divide n 2)))
%           (cond ((ionep (cdr tmp)) (setq a (times a x))))
%           (setq x (times x x))
%           (setq n (car tmp))))
%       a))))

% MinusP, OneP and ZeroP are in ARITHMETIC.RED
% FixP is defined in OTHERS-SL.RED
% Section 3.2 -- Functions on Dotted-Pairs
% composites of CAR and CDR are found in CARCDR.RED
(df list (u)
  %. construct list of arguments
  (evlis u))

% section 3.5 -- Function definition
(dm de (u)
  %. Terse syntax for PutD call for EXPR
  (list 'putd (mkquote (cadr u)) ''expr
        (list 'function (cons 'lambda (cddr u)))))

(dm df (u)
  %. Terse syntax for PutD call for FEXPR
  (list 'putd (mkquote (cadr u)) ''fexpr
        (list 'function (cons 'lambda (cddr u)))))

(dm dm (u)
  %. Terse syntax for PutD call for MACRO
  (list 'putd (mkquote (cadr u)) ''macro
        (list 'function (cons 'lambda (cddr u)))))

(dm dn (u)
  %. Terse syntax for PutD call for NEXPR
  (list 'putd (mkquote (cadr u)) ''nexpr
        (list 'function (cons 'lambda (cddr u)))))

% Section 3.6 -- Variables and bindings
(df setq (u)
  %. Standard named variable assignment
  %
  % Extended from SL Report to be Common Lisp compatible
  % (setq foo 1 bar 2 ...) is permitted
  %
  (prog (v w)
        (while u
          (setq w (cdr u))
          (if (null w)
            (continuableerror 99
             (bldmsg "SETQ %p lacks an expression for the new value."
                     (car u))
             (list 'setq (car u))))
          (set (car u) (setq v (eval (car w))))
          (setq u (cdr w)))
        (return v)))

% Section 3.7 -- Program feature functions
(de prog2 (u v)
  %. Return second argument
  v)

(df progn (u)
  %. Sequential evaluation, return last
  (evprogn u))

%% (startuptime (put 'progn 'type 'fexpr)) %% not needed any more /bwb

(de evprogn (u)
  %. EXPR support for ProgN, Eval, Cond
  (if (pairp u)
    (progn (while (pairp (cdr u))
             (eval (car u))
             (setq u (cdr u)))
           (eval (car u)))
    nil))

% Section 3.10 -- Boolean functions and conditionals
(df and (u)
  %. Sequentially evaluate until NIL
  (evand u))

(de evand (u)
  %. EXPR support for And
  (if (not (pairp u))
    t
    (evand1 u)))

(de evand1 (u)
  % Auxiliary function for EvAnd
  (cond ((not (pairp (cdr u))) (eval (car u)))
        ((not (eval (car u))) nil)
        (t (evand1 (cdr u)))))

(df or (u)
  %. sequentially evaluate until non-NIL
  (evor u))

(de evor (u)
  %. EXPR support for Or
  (and (pairp u) (or (eval (car u)) (evor (cdr u)))))

(df cond (u)
  %. Conditional evaluation construct
  (evcond u))

(de evcond (u)
  %. EXPR support for Cond
  %
  % Extended from Standard Lisp definition to allow no consequent (antecedent is

  % returned), or multiple consequent (implicit progn).
  %
  (let (condform
        antecedent
        result)
       (if (not (pairp u))
         nil
         (progn (setq condform (car u))
                (setq u (cdr u))
                (setq antecedent (if (pairp condform)
                        (car condform)
                        condform))
                (cond ((not (setq result (eval antecedent))) (evcond u))
                      ((or (not (pairp condform))
                        (not (pairp (cdr condform))))
                       result)
                      (t (evprogn (cdr condform))))))))

(de not (u)
  %. Equivalent to NULL
  (null u))

% Section 3.11 -- Arithmetic functions
(de abs (u)
  %. Absolute value of number
  (if (minusp u)
    (minus u)
    u))

(de divide (u v)
  %. dotted pair remainder and quotient
  (if (zerop v)
    (conterror 99 "Attempt to divide by 0 in DIVIDE" (divide u v))
    (cons (quotient u v) (remainder u v))))

(dm max (u)
  %. numeric maximum of several arguments
  (robustexpand (cdr u) 'max2 0))

% should probably be -infinity
(de max2 (u v)
  %. maximum of 2 arguments
  (if (lessp u v)
    v
    u))

(dm min (u)
  %. numeric minimum of several arguments
  (robustexpand (cdr u) 'min2 0))

% should probably be +infinity
(de min2 (u v)
  %. minimum of 2 arguments
  (if (greaterp u v)
    v
    u))

(dm plus (u)
  %. addition of several arguments
  (robustexpand (cdr u) 'plus2 0))

(dm times (u)
  %. multiplication of several arguments
  (robustexpand (cdr u) 'times2 1))

% Section 3.12 -- MAP Composite functions
(de map (l fn)
  %. for each X on L do Fn(X);
  (while (pairp l)
    (apply fn (list l))
    (setq l (cdr l))))

(de mapc (l fn)
  %. for each X in L do Fn(X);
  (while (pairp l)
    (apply fn (list (car l)))
    (setq l (cdr l))))

(de mapcan (l fn)
  %. for each X in L conc Fn(X);
  (for (in i l) (conc (funcall fn i))))

(de mapcon (l fn)
  %. for each X on L conc Fn(X);
  (for (on i l) (conc (funcall fn i))))

(de mapcar (l fn)
  %. for each X in L collect Fn(X);
  (for (in i l) (collect (funcall fn i))))

(de maplist (l fn)
  %. for each X on L collect Fn(X);
  (for (on i l) (collect (funcall fn i))))

% Section 3.13 -- Composite functions
(de append (u v)
  %. Combine 2 lists
  (if (not (pairp u))
    v
    (prog (u1 u2)
          (setq u1 (setq u2 (cons (car u) nil)))
          (setq u (cdr u))
          (while (pairp u)
            (rplacd u2 (cons (car u) nil))
            (setq u (cdr u))
            (setq u2 (cdr u2)))
          (rplacd u2 v)
          (return u1))))

%
% These A-list functions differ from the Standard Lisp Report in that
% poorly formed A-lists (non-pair entries) are not signalled as an error,
% rather the entries are ignored.  This is because some data structures
% (such as property lists) use atom entries for other purposes.
%
(de assoc (u v)
  %. Return first (U . xxx) in V, or NIL
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (equal u (caar v))) (car v))
        (t (assoc u (cdr v)))))

(de sassoc (u v fn)
  %. Return first (U . xxx) in V, or Fn()
  (cond ((not (pairp v)) (apply fn nil))
        ((and (pairp (car v)) (equal u (caar v))) (car v))
        (t (sassoc u (cdr v) fn))))

(de pair (u v)
  %. For each X,Y in U,V collect (X . Y)
  (cond ((and (pairp u) (pairp v))
         (cons (cons (car u) (car v)) (pair (cdr u) (cdr v))))
        ((or (pairp u) (pairp v))
         (stderror "Different length lists in PAIR"))
        (t nil)))

(de sublis (x y)
  %. Substitution in Y by A-list X
  (if (not (pairp x))
    y
    (prog (u)
          (setq u (assoc y x))
          (return (cond ((pairp u) (cdr u))
                        ((not (pairp y)) y)
                        (t (cons (sublis x (car y)) (sublis x (cdr y)))))))))

(de deflist (dlist indicator)
  %. PUT many IDs, same indicator
  (if (not (pairp dlist))
    nil
    (cons (progn (put (caar dlist) indicator (cadar dlist))
                 (caar dlist)) (deflist (cdr dlist) indicator))))

(de delete (u v)
  %. Remove first top-level U in V
  (cond ((not (pairp v)) v)
        ((equal (car v) u) (cdr v))
        (t (cons (car v) (delete u (cdr v))))))

%  DIGIT, LENGTH and LITER are optimized, don't use SL Report version
(de member (u v)
  %. Find U in V
  (cond ((not (pairp v)) nil)
        ((equal u (car v)) v)
        (t (member u (cdr v)))))

(de memq (u v)
  % EQ version of Member
  (cond ((not (pairp v)) nil)
        ((eq u (car v)) v)
        (t (memq u (cdr v)))))

(de nconc (u v)
  %. Destructive version of Append
  (prog (w)
        (unless (pairp u)
          (return v))
        (setq w u)
        (while (pairp (cdr w))
          (setq w (cdr w)))
        (rplacd w v)
        (return u)))

(de reverse (u)
  %. Top-level reverse of list
  (prog (v)
        (while (pairp u)
          (setq v (cons (car u) v))
          (setq u (cdr u)))
        (return v)))

(de subst (a x l)
  %. Replace every X in L with A
  (cond ((null l) nil)
        ((equal x l) a)
        ((null (pairp l)) l)
        (t (cons (subst a x (car l)) (subst a x (cdr l))))))

(de evlis (u)
  %. For each X in U collect Eval X
  (if (not (pairp u))
    nil
    (cons (eval (car u)) (evlis (cdr u)))))

(de robustexpand (l fn emptycase)
  %. Expand + arg for empty list
  (if (null l)
    emptycase
    (expand l fn)))

(de expand (l fn)
  %. L = (a b c) --> (Fn a (Fn b c))
  (cond ((not (pairp l)) l)
        ((not (pairp (cdr l))) (car l))
        (t (list fn (car l) (expand (cdr l) fn)))))

(df quote (u)
  %. Return unevaluated argument
  (car u))

%% (startuptime (put 'quote 'type 'fexpr)) not needed any more /bwb

% needed to run from scratch
(df function (u)
  %. Same as Quote in this version
  (car u))

% Section 3.15 -- Input and Output
(de channelprint (c u)
  %. Display U and terminate line
  (progn (channelprin1 c u)
         (channelterpri c)
         u))

(de print (u)
  %. Display U and terminate line
  (channelprint out* u))

(off fast-integers)
