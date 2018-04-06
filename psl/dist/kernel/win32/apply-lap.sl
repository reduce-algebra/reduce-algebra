%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:APPLY-LAP.SL 
% Description:  Portable version of APPLY-LAP 
% Author:       Eric Benson 
% Created:      29 July 1982 
% Modified:     11-Apr-84 08:55:09 (Brian Beach) 
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compiletime:  PL:SYS-MACROS.B 
% Runtime:      
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
% 22-Mar-84 08:32:58 (Brian Beach)
%  Commented out ADDRESSAPPLY0, since it is in the kernel.
% 02-Mar-84 09:29:05 (Jim Ambras/CRC)
%  Corrected file header.
% 06-Jan-84 15:34:49 (Tim Tillson)
%  Un-rlisp'ed Sam's D-register model version.  This file plus PHP:LAP.SL,
%  replaces php:apply-lap.sl.  For other machines besides HP9836 PWS, this
%  file would need an appropriate machine-dependent section (like php:lap.sl).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load sys-macros))

(compiletime
  (progn (flag '(compiledcallinginterpretedauxaux bindevalaux saveregisters)
               'internalfunction)
         (fluid '(codeptr*   % gets code pointer used by CodePrimitive
                  codeform*  % gets fn to be called from code
		  ))
         ))

(declare-warray codeargs size 15)

% ADDRESSAPPLY0 is defined in the kernel.
%
% (de addressapply0 (codeaddress)
%   (codeapply (mkcode codeaddress) nil))

(de codeevalapply (codeptr arglist)
  (codeapply codeptr (evlis arglist)))

(de bindeval (formals args)
  (bindevalaux formals args 0))

(de bindevalaux (formals args n)
  (let (f
        a)
       (cond ((pairp formals) (if (pairp args)
                (progn (setq f (first formals))
                       (setq a (eval (first args)))
                       (setq n
                        (bindevalaux (rest formals) (rest args) (iadd1 n)))
                       (if (weq n -1)
                         -1
                         (progn (lbind1 f a)
                                n)))
                -1))
             ((pairp args) -1)
             (t n))))

(de saveregisters (a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13 a14)
  (setf (wgetv codeargs 13) a14)
  (setf (wgetv codeargs 12) a13)
  (setf (wgetv codeargs 11) a12)
  (setf (wgetv codeargs 10) a11)
  (setf (wgetv codeargs 9) a10)
  (setf (wgetv codeargs 8) a9)
  (setf (wgetv codeargs 7) a8)
  (setf (wgetv codeargs 6) a7)
  (setf (wgetv codeargs 5) a6)
  (setf (wgetv codeargs 4) a5)
  (setf (wgetv codeargs 3) a4)
  (setf (wgetv codeargs 2) a3)
  (setf (wgetv codeargs 1) a2)
  (setf (wgetv codeargs 0) a1))

(de compiledcallinginterpretedaux ()
  (saveregisters)
  (compiledcallinginterpretedauxaux (get codeform* '*lambdalink)))

(de fastlambdaapply ()
  (saveregisters)
  (compiledcallinginterpretedauxaux codeform*))

(de compiledcallinginterpretedauxaux (fn)
  (if (not (and (pairp fn) (weq (car fn) 'lambda)))
    (stderror (bldmsg "Ill-formed functional expression %r for %r" fn
                      codeform*))
    (prog (formals n result)
          (setq formals (cadr fn))
          (setq n 0)
          (while (pairp formals)
            (lbind1 (car formals) (wgetv codeargs n))
            (setq formals (cdr formals))
            (setq n (iadd1 n)))
          (setq result (evprogn (cddr fn)))
          (when (wneq n 0)
            (unbindn n))
          (return result))))

