%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:ITER-MACROS.SL 
% Description:  macros for generalized iteration 
% Author:       Don Morrison 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2057-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
%               PL:BIND-MACROS.B PL:SET-MACROS.B 
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
% 6 May 1984 1748-PDT (Nancy Kendzierski)
%  Added compiletime loads to allow separate compilation.
% 19 Jan 1984 1442-PST (Brian Beach)
%   Added standard header.
% 15-Sep-82 17:06:49, (Eric Benson)
%   Fixed typo, ((null (cdr result) nil)) ==> ((null (cdr result)) nil)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros
		   bind-macros set-macros))

(defmacro do (iterators result . body)
  (let (vars steps)
    (setq vars
      (foreach U in iterators collect
	(if (and (pairp U) (cdr U) (cddr U))
	  (progn
	    (setq steps (cons
			  (if (atom (car U)) (car U) (caar U))
			  (cons (caddr U) steps)))
	    (list (car U) (cadr U)))
	  U)))
    (let ((form `(prog ()
		   ***DO-LABEL***
		   (cond
		     (,(car result)
		       (return ,(cond
				  ((null (cdr result)) nil)
				  ((and
				     (pairp (cdr result))
				     (null (cddr result)))
				    (cadr result))
				  (t `(progn ,@(cdr result)))))))
		   ,@body
		   (psetq ,.steps)
		   (go ***DO-LABEL***))))
      (if vars `(let ,vars ,form) form))))

(defmacro do* (iterators result . body)
  (let (vars steps)
    (setq vars
      (foreach U in iterators collect
	(if (and (pairp U) (cdr U) (cddr U))
	  (progn
	    (push
	      `(setq ,(if (atom (car U)) (car U) (caar U)) ,(caddr U))
	      steps)
	    (list (car U) (cadr U)))
	  U)))
    (let ((form `(prog ()
		   ***DO-LABEL***
		   (cond
		     (,(car result)
		       (return ,(cond
				  ((null (cdr result)) nil)
				  ((and
				     (pairp (cdr result))
				     (null (cddr result)))
				    (cadr result))
				  (t `(progn ,@(cdr result)))))))
		   ,@body
		   ,.(reversip steps)
		   (go ***DO-LABEL***))))
      (if vars `(let* ,vars ,form) form))))

(defmacro do-loop (iterators prologue result . body)
  (let (vars steps)
    (setq vars
      (foreach U in iterators collect
	(if (and (pairp U) (cdr U) (cddr U))
	  (progn
	    (setq steps (cons
			  (if (atom (car U)) (car U) (caar U))
			  (cons (caddr U) steps)))
	    (list (car U) (cadr U)))
	  U)))
    (let ((form `(prog ()
		   ,@prologue
		   ***DO-LABEL***
		   (cond
		     (,(car result)
		       (return ,(cond
				  ((null (cdr result)) nil)
				  ((and
				     (pairp (cdr result))
				     (null (cddr result)))
				    (cadr result))
				  (t `(progn ,@(cdr result)))))))
		   ,@body
		   (psetq ,.steps)
		   (go ***DO-LABEL***))))
      (if vars `(let ,vars ,form) form))))

(defmacro do-loop* (iterators prologue result . body)
  (let (vars steps)
    (setq vars
      (foreach U in iterators collect
	(if (and (pairp U) (cdr U) (cddr U))
	  (progn
	    (push
	      `(setq ,(if (atom (car U)) (car U) (caar U)) ,(caddr U))
	      steps)
	    (list (car U) (cadr U)))
	  U)))
    (let ((form `(prog ()
		   ,@prologue
		   ***DO-LABEL***
		   (cond
		     (,(car result)
		       (return ,(cond
				  ((null (cdr result)) nil)
				  ((and
				     (pairp (cdr result))
				     (null (cddr result)))
				    (cadr result))
				  (t `(progn ,@(cdr result)))))))
		   ,@body
		   ,.(reversip steps)
		   (go ***DO-LABEL***))))
      (if vars `(let* ,vars ,form) form))))

