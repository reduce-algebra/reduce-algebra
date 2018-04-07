%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:SYSLISP-SYN.SL
% Title:          SMacros and redefinition of arithmetic operators
% Author:         Eric Benson and M. L. griss
% Created:        11 July 1981
% Modified:       11-Jan-84 15:21:21
% Package:        Syslisp
% Status:         Open Source: BSD License
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
% 11-Jan-84 15:21:01 (Jim Ambras)
%  Added compile-time load of rlisp.
% 05-Dec-83 14:23:28 (Brian Beach)
%   Translated from Rlisp to Lisp.  Got rid for FOR redefinition kludge, 
%   replaced with WFOR.  (definition of WFOR is in SYS-MACROS.SL)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  <PSL.COMP>SYSLISP-SYNTAX.RED.2, 30-Mar-83 11:05:36, Edit by KENDZIERSKI
%  Included the text from syslisp-syntax.build at the beginning of this file.
%  The file names w/extensions were too large for the VAX to deal with.
%  <PSL.COMP>SYSLISP-SYNTAX.RED.3,  5-May-82 11:33:48, Edit by BENSON
%  Wrapped if GetD 'BEGIN1 around parser calls

(compiletime
 (load rlisp)
 (off usermode)
 )

(fluid '(!*syslisp))

%% Comment this out for Alpha1.
(commentoutcode
% New WDECLARE constructs
% Modify ***** [] vector syntax for PREFIX and INFIX forms
% At lower prec
(de parselvec (vname vexpr)
  (if (eq op '!*rvec!*)
    (progn
      (setq op (scan))
      (list 'indx vname vexpr))
    (parerr "Missing ] in index expression ")))
)

% Use normal parsing, then CLEAN
(de parsewdec0 (fn dmodes dlist)
  (prog (plist)
        (if (eqcar dlist '!*comma!*)
          (setq dlist (reverse (cdr dlist)))
          (setq dlist (list dlist)))
        (setq plist (foreach dec in dlist collect (parsewdec1 fn dec)))
        (return (cons 'wdeclare (cons dmodes (cons fn (reverse plist)))))))

(de parsewdec1 (fn dec)
  % Process each WDEC to check legal modes
  (if (eqcar dec 'equal)
    (aconc (parsewdec2 fn (cadr dec)) (parsewdec3 fn (caddr dec)))
    (aconc (parsewdec2 fn dec) nil)))

(de parsewdec2 (fn x)
  % Remove INDXs from LHS of =
  (cond ((idp x) (list x nil))
        ((eqcar x 'indx) (list (cadr x) (caddr x)))
        (t (parerr "Only [] allowed on LHS of WDECLARATION"))))

(de parsewdec3 (fn x)
  % Remove INDX's from RHS of =
  (cond ((idp x) x)
        ((eqcar x 'indx) (if (eq (cadr x) '!*prefixvect!*)
           (remcom (caddr x))
           (parerr "Only [...] is legal INIT in WDECLARE")))
        (t x)))

(unless (funboundp 'begin1)
  % kludge #+Rlisp
  (definebop '!*lvec!* 121 5 parselvec)
  (definerop '!*lvec!* 5 (parselvec '!*prefixvect!* x))
  (definebop '!*rvec!* 4 5)
  (definerop 'wconst 1 (parsewdec0 'wconst 'default x))
  (definerop 'wvar 1 (parsewdec0 'wvar 'default x))
  (definerop 'warray 1 (parsewdec0 'warray 'default x))
  (definerop 'wstring 1 (parsewdec0 'wstring 'default x))
  (definebop 'wconst 1 1 (parsewdec0 'wconst x y))
  (definebop 'wvar 1 1 (parsewdec0 'wvar x y))
  (definebop 'warray 1 1 (parsewdec0 'warray x y))
  (definebop 'wstring 1 1 (parsewdec0 'wstring x y))
  % Operators @ for GetMem, & for Loc
  (put '!@ 'newnam 'getmem)
  (put '!& 'newnam 'loc)
  nil)

% SysName hooks for REFORM
(remflag '(reform) 'lose)

(de reform (u)
  (cond ((or (atom u) (memq (car u) ''wconst)) u)
        ((eq (car u) 'cond) (cons 'cond (reform (cdr u))))
        ((eq (car u) 'prog) (rplcdx (cdr u) (reformlis (cddr u))) u)
        ((eq (car u) 'lambda) (rplaca (cddr u) (reform (caddr u))) u)
        ((and (eq (car u) 'function) (atom (cadr u))) 
         (prog (x)
               (cond ((and (null !*cref) (setq x (get (cadr u) 'smacro))) 
                      (return (list 'function x)))
                     ((or (get (cadr u) 'nmacro) (macrop (cadr u))) 
                      (rederr "MACRO USED AS FUNCTION"))
                     (t (return u)))))
        %    ELSE IF CAR U EQ 'MAT THEN RPLCDX(U,MAPC2(CDR U,FUNCTION REFORM))
        ((atom (car u)) 
         (prog (x y fn)
               (setq fn (car u))
               (when (and (setq y (getd fn)) (eq (car y) 'macro) 
                      (expandq fn))
                 (return (reform (apply (cdr y) (list u)))))
               (setq x (reformlis (cdr u)))
               (when (null (idp fn))
                 (return (cons fn x)))
               (when (and !*syslisp (setq y (get fn 'sysname)))
                 (setq fn y)
                 (setq u (cons fn (cdr u))))
               (cond ((and (or (null !*cref) (expandq fn)) 
                       (setq y (get fn 'nmacro)))
                      (return 
                       (apply y (if (flagp fn 'nospread)
                          (list x)
                          x))))
                     ((and (or (null !*cref) (expandq fn)) 
                       (setq y (get fn 'smacro)))
                      (return (sublis (pair (cadr y) x) (caddr y))))
                     (t %we could use an atom SUBLIS here (eg, SUBLA);
                        (return (progn
                           (rplcdx u x)
                           u))))))
        (t (cons (reform (car u)) (reformlis (cdr u))))))

(remflag '(plus times) 'nary)

(deflist '((plus wplus2) (plus2 wplus2) (minus wminus) 
           (difference wdifference) (times wtimes2) (times2 wtimes2) 
           (quotient wquotient) (remainder wremainder) (mod wremainder) 
           (land wand) (lor wor) (lxor wxor) (lnot wnot) (lshift wshift) 
           (lsh wshift))
         'sysname)

(deflist '((neq wneq) (equal weq) (eqn weq) (eq weq) (greaterp wgreaterp) 
           (lessp wlessp) (geq wgeq) (leq wleq) (getv wgetv) (indx wgetv) 
           (putv wputv) (setindx wputv) (for wfor))
         'sysname)

% End of file.

