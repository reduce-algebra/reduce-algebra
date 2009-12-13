%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:INUM.SL
% Description:    Interpreter entries for open-compiled integer arithmetic
% Author:         Eric Benson
% Created:        18 March 1982
% Modified:       12-Sep-84 09:26:56 (Brian Beach)
% Mode:           Lisp
% Package:        Utilities
% Status:         Experimental
% Compiletime:    PL:RLISP.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 25-Aug-1988 (Anthony C. Hearn)
%  Parseifor commented out in this module, since it doesn't belong here.
% 05-Jun-86 (H.Melenk ZIB Berlin)
%  modified IFOR to handle more than one clause in body
% 23-Aug-84 07:52:22 (Brian Beach)
%  Added definition for IFOR.  Used to just change to a WFOR.
% 06-Dec-83 16:17:09 (Brian Beach)
%   Changed mksysfor to (cons 'wfor ...)
% 05-Dec-83 17:39:55 (Nancy Kendzierski)
%   Added contents of .BUILD file.
% 02-Dec-83 18:07:14 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(off r2i)
 
(compiletime
 (progn
 
  (ds inumtwoarg (iname)
    (de iname (arg1 arg2)
      (let (result)
      (if (and (intp arg1) (intp arg2)
             (intp (setq result (iname arg1 arg2))))
        result
        (inum2error arg1 arg2 'iname)))))
 
  (ds inumtwoargbool (iname)
    (de iname (arg1 arg2)
      (if (and (intp arg1) (intp arg2))
      (iname arg1 arg2)
      (inum2error arg1 arg2 'iname))))
 
  (ds inumonearg (iname)
    (de iname (arg)
      (let (result)
      (if (and (intp arg) (intp (setq result (iname arg))))
        result
        (inum1error arg 'iname)))))
 
  (ds inumoneargbool (iname)
    (de iname (arg)
      (if (intp arg)
      (iname arg)
      (inum1error arg 'iname))))
  ))
 
(de inum2error (arg1 arg2 name)
  (continuableerror 99 "Inum out of range" (list name arg1 arg2)))
 
(de inum1error (arg name)
  (continuableerror 99 "Inum out of range" (list name arg)))
 
(inumtwoarg iplus2)
 
(inumtwoarg idifference)
 
(inumtwoarg itimes2)
 
(inumtwoarg iquotient)
 
(inumtwoarg iremainder)
 
(inumtwoargbool ilessp)
 
(inumtwoargbool igreaterp)
 
(inumtwoargbool ileq)
 
(inumtwoargbool igeq)
 
(inumtwoarg ilor)
 
(inumtwoarg iland)
 
(inumtwoarg ilxor)
 
(inumtwoarg ilsh)
 
(inumonearg iadd1)
 
(inumonearg isub1)
 
(inumonearg iminus)
 
(inumoneargbool izerop)
 
(inumoneargbool ionep)
 
(inumoneargbool iminusp)
 
(on r2i) 
 
(dm ifor (u)
  % U is of the form: (IFOR (FROM var start end step) (DO body))
 
  (let ((step (nth (second u) 5)))
    (if (fixp step)
      (constant-increment-ifor u)
      (variable-increment-ifor u)
      )))
 
(de variable-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (x         (list 'IDIFFERENCE finish var))
       (label1    (gensym))
       (label2    (gensym)))
    (unless (onep step)
      (setf x (list 'ITIMES2 step x))
      )
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((ILESSP ,x 0) (GO ,label2)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       ,label2
       )))
 
(de constant-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (comparison(if (minusp step) 'ILESSP 'IGREATERP))
       (label1    (gensym)))
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((,comparison ,var ,finish) (RETURN 0)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       )))
 
 
(commentoutcode

(compiletime (load rlisp))
 
(unless (funboundp 'begin1)
  (definerop 'ifor nil parseifor)
  (de parseifor (x)
    (prog (init stp untl action actexpr)
          (if (eq (setq op (scan)) 'setq)
            (setq init (parse0 6 t))
            (parerr "FOR missing loop VAR assignment" t))
          (cond ((eq op '!*colon!*) (setq stp 1) (setq op 'until))
                ((eq op 'step) (setq stp (parse0 6 t)))
                (t (parerr "FOR missing : or STEP clause" t)))
          (if (eq op 'until)
            (setq untl (parse0 6 t))
            (parerr "FOR missing UNTIL clause" t))
          (setq action op)
          (if (memq action '(do sum product))
            (setq actexpr (parse0 6 t))
            (parerr "FOR missing action keyword" t))
          (return (list 'ifor (list 'from x init untl stp)
                        (list action actexpr)))))
  nil)
 
)
 
