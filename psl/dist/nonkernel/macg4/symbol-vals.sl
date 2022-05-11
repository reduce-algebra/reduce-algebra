%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:SYMBOL-VALS.SL
% Title:          ValueCell, UnboundP, MakeUnbound and Set
% Author:         Eric Benson
% Created:        20 August 1981
% Modified:       29-Aug-84 11:02:05 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% Copyright (c) 1981 Eric Benson
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
% 29-April-89 (Winfried Neun)
%  added correct handling for viv-fluids (pseudo registers)
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:02:42 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
 (progn

(fluid '(collectedregs* fluid-reg-vector max-vivnum))

(setq max-vivnum 0)

(de collectregs-read (x)
     (when (get x 'VIV-number)
	(when (greaterp (id2int x) max-vivnum) (setq max-vivnum (id2int x)))
        (setq collectedregs*
         (cons `((eq u (quote ,x)) ,x) collectedregs*))))

(dm idtoreg-conversion-read ()
       (setq collectedregs* nil)
       (mapobl (function collectregs-read))
       (cons 'cond (nconc collectedregs* `((t u))  )))

(de collectregs-write (x)
     (when (get x 'VIV-number)
	(when (greaterp (id2int x) max-vivnum) (setq max-vivnum (id2int x)))
        (setq collectedregs*
         (cons `((eq exp (quote ,x)) (setq ,x val)) collectedregs*))))

(dm idtoreg-conversion-write ()
       (setq collectedregs* nil)
       (mapobl (function collectregs-write))
       (append `(cond ((wgreaterp (idinf exp) ,max-vivnum)
                                (setf (symval (idinf exp)) val)))
		(nconc collectedregs*
                          `((t (setf (symval (idinf exp)) val))) )))

(dm build-fluid-reg-vector ()
       (setq collectedregs* nil)
       (mapobl (function (lambda (x)
                  (when (get x 'VIV-number)
                   (setq collectedregs* (cons x collectedregs*))))))
       (list 'quote collectedregs*))

(dm build-lng-fluid-reg-vector ()
       (setq collectedregs* 0)
       (mapobl (function (lambda (x)
                  (when (get x 'VIV-number)
                   (cond ((fluidp x) nil)
                         ((globalp x) nil)
                         (T (fluid1 x)))
                   (setq collectedregs* (plus2 collectedregs* 1))))))
       collectedregs*)

(define-constant lng-of-fluid-reg-vector (build-lng-fluid-reg-vector))
)) %end compiletime

(setq fluid-reg-vector (build-fluid-reg-vector))

(de unboundp (u)
  % Does U not have a value?
  (if (idp u)
    (if (weq (tag (symval (idinf u))) unbound-tag)
       (progn  (if (memq u fluid-reg-vector)
                   (eq (tag (idtoreg-conversion-read)) unbound-tag)
                   t))
      nil)
    (noniderror u 'unboundp)))

(de makeunbound (u)
  % Make U an unbound ID
  (if (idp u)
    (setf (symval (idinf u)) (mkitem unbound-tag (idinf u)))
    (noniderror u 'makeunbound)))

(de valuecell (u)
  % Safe access to SymVal entry
  (prog (v)
        % This guy is called from Eval
        (return (if (idp u)
                  (progn (setq v (symval (idinf u)))
                         (if (weq (tag v) unbound-tag)
                          (if (memq u fluid-reg-vector)
                           (setq v (idtoreg-conversion-read))
                           (continuableerror '99
                            (bldmsg '"%r is an unbound ID" u) u))
                           v))
                  (noniderror u 'valuecell)))))

% This version of SET differs from the Standard Lisp report in that Exp is
% not declared fluid, in order to maintain compatibility between compiled
% and interpreted code.
(de set (exp val)
  % Assign Val to ID Exp
  (if (idp exp)
    (if (not (or (null exp) (weq exp 't)))
      (progn (idtoreg-conversion-write)
             val)
      (stderror '"T and NIL cannot be SET"))
    (noniderror exp 'set)))
