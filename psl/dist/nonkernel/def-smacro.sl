%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:DEFINE-SMACRO.SL 
% Title:        Convert SMacros to Lisp macros 
% Author:       Eric Benson 
% Created:      23 October 1981 
% Modified:     22-Mar-84 11:04:27 (Brian Beach) 
% Mode:         Lisp 
% Package:      Kernel 
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
% 22 Oct 1984 2202-PDT (Brian Beach)
%  Fixed DS so that is undertands non-proper lists as in the case
%  (DS FOO (x) (CONS x '(A . B))).  Removed internal functions.
% 26 Jan 1984 0958-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:28:47 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de instantiateinform (formals form)
  (if (atom form)
    (if (memq form formals)
      form
      (mkquote form))
    (if (null (cdr (lastpair form)))
      (cons 'list (foreach x in form collect (instantiateinform formals x)))
      (list 'cons (instantiateinform formals (car form))
	          (instantiateinform formals (cdr form)))
      )))

(de setmacroreference (u)
  (list 'setq u '(car !#arg)))

(dm ds (form)
  %. Define Smacro
  %
  % DS(FNAME:id, PARAMS:id-list, FN:any):id
  % ---------------------------------------
  % Type: MACRO
  % A convenient syntax for a simple macro definition, known as an SMACRO.
  % The syntax of DS is similar to DE, except that a MACRO is defined instead

  % of an EXPR, e.g.
  %	(DS FOO (A B) (BAR A B))
  % is equivalent to:
  %	(DM FOO (U) (LIST 'BAR (CADR U) (CADDR U))).
  % The "implicit ProgN" is allowed when using Lisp syntax.  DS is invoked
  % with Rlisp syntax as the procedure type SMACRO, e.g.
  %	SMACRO PROCEDURE FOO(A, B); BAR(A, B);
  % produces the above Lisp form.
  %
  (makeds (cadr form) (caddr form) (cdddr form)))

(de makeds (macroname formals form)
  (prog (newform i w)
        (setq newform (list 'prog))
        (setq newform (cons formals newform))
        (foreach x in formals do
                 (progn (setq newform
                         (cons '(setq !#arg (safecdr !#arg)) newform))
                        (setq newform (cons (setmacroreference x) newform))))
        (setq newform
              (cons '(cond ((pairp (cdr !#arg))
                            (stderror
                             (list "Argument mismatch in SMacro "
				  'macroname "uncovered argument(s):" 
                                  (cdr !#arg) 
			      ))))
                    newform))
        (setq newform (subst macroname 'macroname newform))

        (setq newform
              (cons (list 'return (if (null (cdr form))
                       (instantiateinform formals (car form))
                       (cons 'list
                        (cons ''progn
                         (foreach x in form collect
                          (instantiateinform formals x))))))
                    newform))
        (return (cons 'dm
                      (cons macroname
                       (cons '(!#arg) (list (reversip newform))))))))

%lisp procedure PutC(Name, Type, Body);
%    if Type eq 'SMACRO then Eval MakeDS(Name, cadr Body, cddr Body)
%    else
%    <<  put(Name, Type, Body);
%	Name >>;
