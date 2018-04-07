%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:BIND-MACROS.SL 
% Description:  convenient macros for binding variables 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2056-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
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
% 6 May 1984 1640-PDT (Nancy Kendzierski)
%  Changed compiletime loads requirements to allow separate compilation of
%  USEFUL modules.
% 09-Feb-84 15:37:52 (Cris Perdue)
%  Added compiletime load useful so this can be compiled by itself.
% 19 Jan 1984 1429-PST (Brian Beach)
%   Added standard header.
% 18-Oct-82 14:31:17, Edit by BENSON
%  Reversed vars and vals after collecting them in LET, so that the order
%  of things in the LAMBDA is the same as the LET.  Not necessary,
%  but it makes it easier to follow macroexpanded things.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros))

(defmacro prog1 (first . body)
  (if (null body)
    first
    `((lambda (***PROG1-VAR***) ,@body ***PROG1-VAR***) ,first)))

(defmacro let (specs . body)
 (if (null specs)
   (cond
     ((null body) nil)
     ((and (pairp body) (null (cdr body))) (car body))
     (t `(progn ,@body)))
   (prog (vars vals)
     (foreach U in specs do
       (cond ((atom U)
	       (setq vars (cons U vars))
	       (setq vals (cons nil vals)))
	 (t
	   (setq vars (cons (car U) vars))
	   (setq vals (cons (and (cdr U) (cadr U)) vals)))))
     (return `((lambda ,(reversip vars) ,@body ) ,@(reversip vals))))))

(defmacro let* (specs . body)
 (if (null specs)
   (cond
     ((null body) nil)
     ((and (pairp body) (null (cdr body))) (car body))
     (t `(progn ,@body)))
   (let*1 specs body)))

(de let*1 (specs body)
 (let ((s (car specs))(specs (cdr specs)))
  `((lambda (,(if (atom s) s (car s)))
      ,@(if specs (list (let*1 specs body)) body))
    ,(if (and (pairp s) (cdr s)) (cadr s) nil))))

