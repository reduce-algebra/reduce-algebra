%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:MACROEXPAND.SL 
% Description:  tools for expanding macros in forms 
% Author:       Don Morrison 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2058-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
%               PL:BIND-MACROS.B PL:SET-MACROS.B PL:ITER-MACROS.B 
%               PL:FOR-MACRO.B 
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
% 6 May 1984 1836-PDT (Nancy Kendzierski)
%  Added compiletime loads to allow separate compilation.
% 24 Apr 1984 1348-PST (Brian Beach)
%  Changed CAR to SAFECAR in MACROEXPAND-FUNCTION-CALL, since not all functions
%  will have definitions.
% 13-Feb-84 09:51:37 (Alan Snyder)
%  Fixed missing second argument to macroexpand2-list in macroexpand-cond.
% 07-Feb-84 14:22:26 (Brian Beach)
%  Repaired bug expanding lambdas.  In expanding a DE, the parameter list was
%  being handled as a function call.  Fixed this by making the handling of
%  lambdas more general, so that they are allowed to occur.  Rather than add
%  handling of FUNCTION as an fexpr, I have simply handled LAMBDA as a special
%  case, since this is the way HPSL will define it.
% 19 Jan 1984 1443-PST (Brian Beach)
%   Added standard header.
% 8 Jul 1983 1804-PDT, Cris Perdue
%   Added coverage for CATCH and CASE, which means every FEXPR
%   except DEFSTRUCT and perhaps WDECLARE is now handled.
% 17-June-83 Alan Snyder
%   Taught it about the LIST Fexpr (needed to make Objects work).
%  <PSL.UTIL>MACROEXPAND.SL.15,  2-Sep-82 10:32:10, Edit by BENSON
%   Fixed multiple argument SETQ macro expansion
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros
		   bind-macros set-macros iter-macros for-macro))

(defmacro macroexpand (form . macros)
 `(macroexpand1 ,form (list ,@macros)))

(fluid '(*macroexpand-signal*))

(de macroexpand1 (form macros-to-expand)
  (let ((*macroexpand-signal*  t)
	(*macro-displace       nil))
    (while *macroexpand-signal*
      (setq *macroexpand-signal* nil)
      (setq form (macroexpand2 form macros-to-expand))))
  form)
    
(de macroexpand2 (form macros-to-expand)
  (cond
    ((or (atom form) 
	 (constantp (car form)))            form)
    ((eqcar (car form) 'lambda)             (macroexpand2-list form macros-to-expand))
    ((not (idp (car form)))                 form)
    (t                                      (macroexpand-function-call 
					     form macros-to-expand))
    ))

(de macroexpand-function-call (form macros-to-expand)
  (let ((special-fn (get (first form) 'macroexpand-func))
	(fcn-type   (safecar (getd (first form)))))
    (cond
     (special-fn            (apply special-fn (list form macros-to-expand)))
     ((eq fcn-type 'fexpr)  form)
     ((eq fcn-type 'macro)  (macroexpand-macro form macros-to-expand))
     (t                     (cons (first form)
				  (macroexpand2-list (rest form) macros-to-expand)))
     )))

(de macroexpand-macro (form macros-to-expand)
  (if (or (null macros-to-expand)
	  (memq (car form) macros-to-expand))
    (progn
     (setq *macroexpand-signal* t)
     (apply (cdr (getd (car form))) (list form))
     )
    (cons
     (car form)
     (macroexpand2-list (rest form) macros-to-expand)
     )))

(de macroexpand2-list (forms macros-to-expand)
  (for (in form forms)
       (collect (macroexpand2 form macros-to-expand))
       ))

(de macroexpand-skip-second (form macros-to-expand)

  % FORM is (ID XXX REST) where ID is a functions whose second parameter
  % is not to be expanded.

  `(,(first form) ,(second form) ,@(macroexpand2-list (rest (rest form)) 
						     macros-to-expand)))

			     
(de macroexpand-cond (U L)
  (cons 'cond 
	(for (in V (rest U))
	     (collect (macroexpand2-list V L))
	     )))

(de macroexpand-case (u l)
  `(case ,(macroexpand2 (second u) l)
	 ,.(foreach v in (cddr u) collect
		    (cons (first v)
			  (foreach w in (rest v) collect
				   (macroexpand2 w l))))))


(de macroexpand-normal (U L)
  (cons (car U) (foreach V in (cdr U) collect (macroexpand2 V L))))

% Should probably add a bunch more of these...
(put 'lambda   'macroexpand-func  'macroexpand-skip-second)
(put 'prog     'macroexpand-func  'macroexpand-skip-second)
(put 'progn    'macroexpand-func  'macroexpand-normal)
(put 'cond     'macroexpand-func  'macroexpand-cond)
(put 'and      'macroexpand-func  'macroexpand-normal)
(put 'or       'macroexpand-func  'macroexpand-normal)
(put 'setq     'macroexpand-func  'macroexpand-normal)
(put 'function 'macroexpand-func  'macroexpand-normal)
(put 'list     'macroexpand-func  'macroexpand-normal)
(put 'catch    'macroexpand-func  'macroexpand-skip-second)
(put 'case     'macroexpand-func  'macroexpand-case)

(de macroexpand-loop ()
  (catch 'macroexpand-loop
    `(toploop
       ',(and toploopread* #'read)
       ',#'prettyprint
       ',#'(lambda (u) (if (atom u) (throw 'macroexpand-loop) (macroexpand u)))
       "expand"
       ',(bldmsg
	   "Entering macroexpand loop (atomic input forces exit) %w..."
	   (if (and
		 toploopread*
		 (idp toploopread*)
		 (not (eq toploopread* 'read)))
	     (bldmsg "[reading with %w]" toploopread*)
	     ""))))
    (printf "... Leaving macroexpand loop."))
