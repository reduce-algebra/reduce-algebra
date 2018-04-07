%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% File:         PU:NBIG30a.SL
% Description:  Vector based BIGNUM package with INUM operations
% Author:       M. L. Griss & B Morrison
% Created:      25 June 1982
% Modified:
% Mode:         Lisp
% Package:      Utilities
% Status:       Open Source: BSD License
%
% (c) Copyright 1993, Konrad-Zuse-Zentrum
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

%----------------------------------------------------------
%
%  ASM syntax (only inside compiled function):
%
%  (asm
%     (init reg exp) 
%     (init reg exp2) 
%     instr1
%     instr2
%      ...
%
%
%   init: lisp forms which are evaluted before entering
%         the instruction sequence for initializing
%         (reg 1), (reg 2) ...
%        optional
%
%   instr1, instr2, ...
%        LAP instructions (cmacros, assembler instructions).
%
%   references to local variables are permitted but
%   only if these are used outside of the asm-code too.
%
%   final result: content of register (reg 1).

(dm asm(u)
  % separate arguments and quote asm code.
   (prog(args name)
     (pop u)
     (while (and (pairp u) (eqcar (car u) 'init))
        (push (car u) args)
        (pop u))
      (return `(asm** ',u . ,args))))

(put 'asm** 'compfn '&comasm)

(de &comasm (exp status&) 
   (prog (u args name pl n)  
     (setq name (gensym))
     (setq u (reform-asm* (cadr (cadr exp))))
     (setq args (cddr exp))
     (foreach a in args do
       (progn
         (setq a (cdr a))  % pop "init"
         (when (not (registerp (car a)))
               (error 99 "illegal init form in asm call "))
         (setq n (cadr (car a)))
         (setq n (cadr n)) % unquote
         (when (not (numberp n))
               (error 99 "illegal init form in asm call "))
         (while (lessp (length pl) n)
                (setq pl (append pl (list ''0))))
         (rplaca (pnth pl n) (cadr a))))
     (&comload pl)
     (foreach m in u do (&attach 
         (if (pairp m) m `(*lbl (label ,m)))))  % emit code
))

(de reform-asm*(u)
  % substitute local variables by their frames
  (cond ((and (idp u) u) (reform-asm1 u stomap&))
        ((atom u) u)
        ((memq (car u) '(reg $fluid $global quote)) u)
        (t (mapcar u(function reform-asm*)))
))

(de reform-asm1(u stomap)
  (cond ((eq u 'reg) u)
        ((get u 'cmacropatterntable) u)
        ((null stomap) u)
        ((eq (cadr (caar stomap)) u)
         (&refstore (caar stomap))  % reference to local variable position
         (cadr (car stomap)))       % return frame position
        (t (reform-asm1 u (cdr stomap))) ))

