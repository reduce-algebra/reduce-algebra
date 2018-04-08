%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:DEFMACRO1.SL 
% Description:  First part of tools for destructuring and macro definition 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     7 May 1984 1059-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B 
% Runtime:      
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
% 6 May 1984 1621-PDT (Nancy Kendzierski)
%  Added compiletime loads and split into two parts to allow separate
%  compilation, without requiring itself.
% 19 Jan 1984 1431-PST (Brian Beach)
%   Added standard header.
% 03-Nov-83 16:39:02  Nancy Kendzierski
%   Removed circularity in rebuilding USEFUL by removing use of SETF in this
%   file.  Changed "setf (get '!%displaced-macro 'compfn) #'&comprogn)" to
%   "(put '!%displaced-macro 'compfn #'&comprogn)".  SETF isn't defined in the
%   module USEFUL until after defmacro.sl is processed -- setf is defined
%   in set-macros.sl, using defmacro, which is defined in this file!
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros))

(de destructure-form (target path)
 (cond ((null target) nil)
       ((idp target)
	`((setq ,target ,path)))
       ((atom target)
	 (destructure-form
	   (ContinuableError 99 (BldMsg "Can't assign to %r" target) target)
	   path))
       (t (nconc
	    (destructure-form (car target) `(car ,path))
	    (destructure-form (cdr target) `(cdr ,path))))))

(de flatten (U)
 (cond ((null U) nil)
       ((atom U) (list U))
       ((null (car U)) (cons nil (flatten (cdr U))))
       (t (append (flatten (car U)) (flatten (cdr U))))))

(fluid '(*defmacro-displaces *macro-displace))

((lambda (ub-flg)
   (fluid '(*macro-displace))
   (cond (ub-flg (setq *macro-displace t)))) % Only do if not already set
 (unboundp '*macro-displace))
	     
(de defmacro-1 (U)
% This, too, can be made more efficient if desired.  Seems unnecessary, though.
  `(dm ,(cadr U) (***DEFMACRO-ARG***)
     (prog ,(flatten (caddr U))
       ,.(destructure-form (caddr U) '(cdr ***DEFMACRO-ARG***))
       (return ,(cond
		  (*defmacro-displaces
		    `(macro-displace ***DEFMACRO-ARG*** (progn ,@(cdddr U))))
		  (t `(progn ,@(cdddr U))))))))

