%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:DEFMACRO2.SL 
% Description:  Second part of tools for destructuring and macro definition 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     7 May 1984 1058-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO1.B 
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

(compiletime (load backquote read-macros def1macro))

(de macro-displace (u v)
  (cond
    (*macro-displace
      (rplacw u `(!%displaced-macro
		   ',(cons (car u) (cdr u))
		   ,(macroexpand v))))
    (t v)))
  
(dm defmacro (u) (defmacro-1 u))
 
(dm defmacro-displace (u)
  ((lambda (*defmacro-displaces) (defmacro-1 u)) t))

(dm defmacro-no-displace (u)
  ((lambda (*defmacro-displaces) (defmacro-1 u)) nil))

(copyd '!%displaced-macro 'prog2)

(put '!%displaced-macro 'compfn #'&comprogn)

(defmacro desetq (U V)
% a destructuring setq - should be made more efficient and robust
 `((lambda (***DESETQ-VAR***)
       ,.(destructure-form U '***DESETQ-VAR***)
       ***DESETQ-VAR***)
   ,V))

(fluid '(*macro-debug))

(defmacro-no-displace deflambda (nam vars . bod)
  (if *macro-debug % T => deflambdas are functions and can be traced, etc.
    `(de ,nam ,vars ,@bod)
    `(defmacro ,nam ,vars
       `((lambda ,',vars ,.',bod) ,.(list ,@vars)))))
