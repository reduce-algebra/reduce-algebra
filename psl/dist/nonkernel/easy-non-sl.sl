%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EASY-NON-SL.SL 
% Title:        Commonly used Non-Standard Lisp functions 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     25-Jul-84 09:20:18 
% Package:      Kernel 
% Status:       Open Source: BSD License
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
% 17-Dec-95 (Herbert Melenk)
%  Added function assoc* for fast search in proper a-lists.
% 17-Oct-94 (Herbert Melenk)
%  Modified SUBLA such that unchanged parts of the structure are
%  preserved (less consing). Also, a spacial variant is introduced
%  which handles the special case of one pair only - this case
%  occurs in 98 percent of all calls.
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 4 Dec 1984 1544-PST (Brian Beach)
%  Removed 20-specific FILEP.  It could only be cross-compiled.
% 25-Jul-84 09:18:47 (Jim Ambras/CRC)
%  Removed ATSOC function. It's already defined in pk:support.sl
%  in the micro-kernel.
% 10-May-84 14:37:37 (Mike Creech)
%     Rewrote ATSOC to be more efficient.
% 23-Mar-84 08:58:01 (Brian Beach)
%  Added compile time load of if-system.
%  Changed (PUTD (GETD ...)) to a function definition.
% 21-Mar-84 14:04:15 (Jim Ambras)
%  Commented out loadtime putd of spaces2 and channelspaces2 because getd
%  is not yet in the new kernel
% 01-Dec-83 14:29:32 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime (load if-system))

(compiletime
  (flag '(delqip1 deletip1 substip1 delascip1 delatqip1 dopnth
          subla1 subla2)
        'internalfunction))

(fluid '(in* out*))

% predicates
(de neq (u v)
  % not EQUAL (should be changed to not EQ)
  (not (equal u v)))

(de ne (u v)
  % not EQ
  (not (eq u v)))

(de geq (u v)
  % greater than or equal to
  (not (lessp u v)))

(de leq (u v)
  % less than or equal to
  (not (greaterp u v)))

(de eqcar (u v)
  % car U eq V
  (and (pairp u) (eq (car u) v)))

(de exprp (u)
  % Is U an EXPR?
  (or (eqcar u 'lambda) (codep u) (eqcar (getd u) 'expr)))

(de macrop (u)
  % Is U a MACRO?
  (eqcar (getd u) 'macro))

(de fexprp (u)
  % Is U an FEXPR?
  (eqcar (getd u) 'fexpr))

(de nexprp (u)
  % Is U an NEXPR?
  (eqcar (getd u) 'nexpr))

% Function definition
(de copyd (new old)
  % FunDef New := FunDef Old;
  %
  % CopyD(New:id, Old:id):id
  % -----------------------
  % Type: EVAL, SPREAD
  % The function body and type for New become the same as Old. If no
  % definition exists for Old, the error
  %
  % ***** `Old' has no definition in CopyD
  %
  % occurs.  New is returned.
  %
  (prog (olddef)
        (setq olddef (getd old))
        (if (pairp olddef)
          (putd new (car olddef) (cdr olddef))
          (stderror (bldmsg "%r has no definition in CopyD" old)))
        (return new)))

% Numerical functions
(de recip (n)
  % Floating point reciprocal
  (quotient 1.0 n))

% Commonly used constructors
(de mkquote (u)
  % Eval MkQuote U eq U
  (list 'quote u))

% Nicer names to access parts of a list
(dm first (u)
  % First element of a list
  (cons 'car (cdr u)))

(dm second (u)
  % Second element of a list
  (cons 'cadr (cdr u)))

(dm third (u)
  % Third element of a list
  (cons 'caddr (cdr u)))

(dm fourth (u)
  % Fourth element of a list
  (cons 'cadddr (cdr u)))

(dm rest (u)
  % Tail of a list
  (cons 'cdr (cdr u)))

% Destructive and EQ versions of Standard Lisp functions
(de reversip (u)
  % Destructive REVERSE (REVERSe In Place)
  (prog (x y)
        (while (pairp u)
          (setq x (cdr u))
          (setq y (rplacd u y))
          (setq u x))
        (return y)))

(de substip1 (a x l)
  % Auxiliary function for SubstIP
  (progn (cond ((equal x (car l)) (rplaca l a))
               ((pairp (car l)) (substip a x (car l))))
         (when (pairp (cdr l))
           (substip a x (cdr l)))))

(de substip (a x l)
  % Destructive version of Subst
  (cond ((null l) nil)
        ((equal x l) a)
        ((not (pairp l)) l)
        (t (substip1 a x l) l)))

(de deletip1 (u v)
  % Auxiliary function for DeletIP
  (when (pairp (cdr v))
    (if (equal u (cadr v))
      (rplacd v (cddr v))
      (deletip1 u (cdr v)))))

(de deletip (u v)
  % Destructive DELETE
  (cond ((not (pairp v)) v)
        ((equal u (car v)) (cdr v))
        (t (deletip1 u v) v)))

(de delq (u v)
  % EQ version of DELETE
  (cond ((not (pairp v)) v)
        ((eq (car v) u) (cdr v))
        (t (cons (car v) (delq u (cdr v))))))

(de del (f u v)
  % Generalized Delete, F is comparison function
  (cond ((not (pairp v)) v)
        ((apply f (list (car v) u)) (cdr v))
        (t (cons (car v) (del f u (cdr v))))))

(de delqip1 (u v)
  % Auxiliary function for DelqIP
  (when (pairp (cdr v))
    (if (eq u (cadr v))
      (rplacd v (cddr v))
      (delqip1 u (cdr v)))))

(de delqip (u v)
  % Destructive DELQ
  (cond ((not (pairp v)) v)
        ((eq u (car v)) (cdr v))
        (t (delqip1 u v) v)))

(de ass (f u v)
  % Generalized Assoc, F is comparison function
  %
  % Not to be confused with Elbow
  %
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (apply f (list u (caar v)))) (car v))
        (t (ass f u (cdr v)))))

(de mem (f u v)
  % Generalized Member, F is comparison function
  (cond ((not (pairp v)) nil)
        ((apply f (list u (car v))) v)
        (t (mem f u (cdr v)))))

(de rassoc (u v)
  % Reverse Assoc, compare with cdr of entry
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (equal u (cdar v))) (car v))
        (t (rassoc u (cdr v)))))

(de delasc (u v)
  % Remove first (U . xxx) from V
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (equal u (caar v))) (cdr v))
        (t (cons (car v) (delasc u (cdr v))))))

(de delascip1 (u v)
  % Auxiliary function for DelAscIP
  (when (pairp (cdr v))
    (if (and (pairp (cadr v)) (equal u (caadr v)))
      (rplacd v (cddr v))
      (delascip1 u (cdr v)))))

(de delascip (u v)
  % Destructive DelAsc
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (equal u (caar v))) (cdr v))
        (t (delascip1 u v) v)))

(de delatq (u v)
  % EQ version of DELASC
  (cond ((not (pairp v)) nil)
        ((eqcar (car v) u) (cdr v))
        (t (cons (car v) (delatq u (cdr v))))))

(de delatqip1 (u v)
  % Auxiliary function for DelAtQIP
  (when (pairp (cdr v))
    (if (and (pairp (cadr v)) (eq u (caadr v)))
      (rplacd v (cddr v))
      (delatqip1 u (cdr v)))))

(de delatqip (u v)
  % Destructive DelAtQ
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (eq u (caar v))) (cdr v))
        (t (delatqip1 u v) v)))

(commentoutcode

(de subla (u v)
  % EQ version of SubLis, replaces atoms only
  (let (x)
       (cond ((or (not (pairp u)) (null v)) v)
             ((atom v) (if (setq x (atsoc v u))
                (cdr x)
                v))
             (t (cons (subla u (car v)) (subla u (cdr v)))))))
)

(de subla (u v)
  % EQ version of SubLis, replaces atoms only
     (cond ((or (not (pairp u)) (null v)) v)
           ((null (cdr u)) (subla1 (caar u) (cdar u) v))
           (t (subla2 u v))))
            
(de subla1 (u w v)
  % one-pair variant of subla.
  (let (a b x y)
       (cond ((atom v) (if (eq u v) w v))
             (t (setq x (subla1 u w (setq a (car v))))
                (setq y (subla1 u w (setq b (cdr v))))
                (if (and (eq x a)(eq y b)) 
                    v 
                    (cons x y))))))

(de subla2 (u v)
  (let (a b x y)
       (cond ((null v) v)
             ((atom v) (if (setq x (atsoc v u))
                (cdr x)
                v))
             (t (setq x (subla2 u (setq a (car v))))
                (setq y (subla2 u (setq b (cdr v))))
                (if (and (eq x a)(eq y b)) 
                    v 
                    (cons x y))))))

(de rplacw (a b)
  % RePLACe Whole pair
  (if (pairp a)
    (if (pairp b)
      (rplaca (rplacd a (cdr b)) (car b))
      (nonpairerror b 'rplacw))
    (nonpairerror a 'rplacw)))

(de lastcar (x)
  % last element of list
  (if (atom x)
    x
    (car (lastpair x))))

(de lastpair (x)
  % last pair of list
  (if (or (atom x) (atom (cdr x)))
    x
    (lastpair (cdr x))))

(de copy (u)
  % copy all pairs in S-Expr
  %
  % See also TotalCopy in COPIERS.RED
  %
  (if (pairp u)
    (cons (copy (car u)) (copy (cdr u)))
    u))

% blows up if circular
(de nth (u n)
  % N-th element of list
  ((lambda (x)
           (if (pairp x)
             (car x)
             (rangeerror u n 'nth)))
   (dopnth u n)))

(de dopnth (u n)
  (if (or (equal n 1) (not (pairp u)))
    u
    (dopnth (cdr u) (difference n 1))))

(de pnth (u n)
  % Pointer to N-th element of list
  (cond ((equal n 1) u)
        ((not (pairp u)) (rangeerror u n 'pnth))
        (t (pnth (cdr u) (difference n 1)))))

(de aconc (u v)
  % destructively add element V to the tail of U
  (nconc u (list v)))

(de tconc (ptr elem)
  % AConc maintaining pointer to end
  %
  % ACONC with pointer to end of list
  % Ptr is (list . last CDR of list)
  % returns updated Ptr
  % Ptr should be initialized to (NIL . NIL) before calling the first time
  %
  (progn (setq elem (list elem))
         (cond ((not (pairp ptr)) % if PTR not initialized, return starting ptr

                (cons elem elem))
               ((null (cdr ptr)) % Nothing in the list yet

                (rplaca (rplacd ptr elem) elem))
               (t (rplacd (cdr ptr) elem) (rplacd ptr elem)))))

(de lconc (ptr lst)
  % NConc maintaining pointer to end
  %
  % NCONC with pointer to end of list
  % Ptr is (list . last CDR of list)
  % returns updated Ptr
  % Ptr should be initialized to NIL . NIL before calling the first time
  %
  (cond ((null lst) ptr)
        ((atom ptr) % if PTR not initialized, return starting ptr

         (cons lst (lastpair lst)))
        ((null (cdr ptr)) % Nothing in the list yet

         (rplaca (rplacd ptr (lastpair lst)) lst))
        (t (rplacd (cdr ptr) lst) (rplacd ptr (lastpair lst)))))

% MAP functions of 2 arguments
(de map2 (l m fn)
  % for each X, Y on L, M do Fn(X, Y);
  (progn (while (and (pairp l) (pairp m))
           (apply fn (list l m))
           (setq l (cdr l))
           (setq m (cdr m)))
         (if (or (pairp l) (pairp m))
           (stderror "Different length lists in MAP2")
           nil)))

(de mapc2 (l m fn)
  % for each X, Y in L, M do Fn(X, Y);
  (progn (while (and (pairp l) (pairp m))
           (apply fn (list (car l) (car m)))
           (setq l (cdr l))
           (setq m (cdr m)))
         (if (or (pairp l) (pairp m))
           (stderror "Different length lists in MAPC2")
           nil)))

% Printing functions
(de channelprin2t (c u)
  % Prin2 and TerPri
  (progn (channelprin2 c u)
         (channelterpri c)
         u))

(de prin2t (u)
  % Prin2 and TerPri
  (channelprin2t out* u))

(de channelspaces (c n)
  % Prin2 N spaces
  (for (from i 1 n 1) (do (channelwritechar c (char blank)))))

(de spaces (n)
  % Prin2 N spaces
  (channelspaces out* n))

(de channeltab (chn n)
  % Spaces to column N
  (prog (m)
        (setq m (channelposn chn))
        (when (lessp n m)
          (channelterpri chn)
          (setq m 0))
        (channelspaces chn (difference n m))))

(de tab (n)
  % Spaces to column N
  (channeltab out* n))

(de filep (f)
  % is F an existing file?
  %
  % This could be done more efficiently in a much more system-dependent way,
  % but efficiency probably doesn't matter too much here.
  %
  (if (pairp (setq f (errorset (list 'open (mkquote f) '(quote input)) 
			       nil
			       nil)))
    (progn (close (car f))
	   t)
    nil
    ))


% This doesn't belong anywhere and will be eliminated soon
(de putc (name ind exp)
  % Used by RLISP to define SMACROs
 (put name ind exp)
 name)

(de spaces2 (a)
  % For compatibility
  (tab a))

(de channelspaces2 (a b)
  % For compatibility
  (channeltab a b))


(off fast-integers)

% Fast assoc for proper a-lists (only pairs and terminated by nil).

(compiletime (flag '(assoc1*) 'internalfunction))

(de assoc*(x l)
  (cond ((null l) nil)
        ((idp x)(atsoc x l))
        ((and (pairp x)(idp (car x)))
              (assoc1*(car x)(cdr x) l))
        (t (assoc x l))))

(commentoutcode
(de assoc1*(a d l)
  (prog(y)
    (go check)
 next
    (setq l (cdr l))
 check
    (when (null l)(go retnil))
    (setq y (caar l))
    (when (not (pairp y))(go next))
    (when (not (eq (car y) a)) (go next))
    (when (not (equal (cdr y) d))(go next))
    (return (car l))
 retnil
    (return nil)))
 )

(lap '(
  (*entry assoc1* expr 3)
  (*alloc 3)
  (*move (reg 1) (frame 1))     % a
  (*move (reg 1) (reg 4))       % a kept in (reg 4)
  (*move (reg 2) (frame 2))     % d
 %               (frame 3)      % l
  (*jump (label check))
next
  (*move (cdr (reg 3)) (reg 3))
check
  (*jumpeq (label exitnil) (reg 3) (quote nil))
  (*move (car (car (reg 3))) (reg 1))
  (*jumpnottype (label next) (reg 1) pair-tag)
  (*jumpnoteq (label next) (reg 4) (car (reg 1)))
    % car is eq. Check cdr; now we must save l
  (*move (cdr (reg 1)) (reg 1))
  (*move (reg 3)(frame 3))
  (*link equal expr 2)
  (*jumpnoteq (label exitfound) (reg 1) (quote nil))
    % not found: restore registers for loop.
  (*move (frame 3)(reg 3))
  (*move (frame 2)(reg 2))
  (*move (frame 1)(reg 4))
  (*jump (label next))
exitfound
   (*move (car (frame 3)) (reg 1))
   (*jump (label exit))
exitnil  
   (*move (quote nil) (reg 1))
exit
   (*exit 3)
))
