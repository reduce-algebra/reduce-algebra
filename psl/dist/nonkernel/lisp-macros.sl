%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:LISP-MACROS.SL 
% Title:        Various macros to make pure Lisp more tolerable 
% Author:       Eric Benson 
% Created:      5 October 1981 
% Modified:     28-Aug-84 13:13:02 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
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
% 01-Dec-83 14:49:53 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
  (flag '(inthiscase) 'internalfunction))

% Not a macro, but it belongs with these
(df case (u)
  %U is of form (CASE <integer exp> (<case-1> <exp-1>) . . .(<case-n> <exp-n>)).

  % If <case-i> is NIL it is default,
  %   else is list of INT or (RANGE int int)
  (prog (caseexpr def caselst bod)
        (setq caseexpr (eval (car u)))
   l
        (unless (pairp (setq u (cdr u)))
          (return (eval def)))
        (setq caselst (caar u))
        (setq bod (cadar u))
        (when (or (not (pairp caselst))
                  (memq (car caselst) '(otherwise default)))
          (setq def bod)
          (go l))
        (when (inthiscase caseexpr caselst)
          (return (eval bod)))
        (go l)))

(de inthiscase (caseexpr cases)
  (cond ((not (pairp cases)) nil)
        ((and (pairp (car cases)) (eq (caar cases) 'range)
              (geq caseexpr (cadar cases)) (leq caseexpr (caddar cases)))
         t)
        ((equal caseexpr (car cases)) t)
        (t (inthiscase caseexpr (cdr cases)))))

(dm setf (u)
  %. General assignment macro
  (expandsetf (cadr u) (caddr u)))

(de expandsetf (lhs rhs)
  (let (lhsop)
       (cond ((atom lhs) (list 'setq lhs rhs))
             ((setq lhsop (get (car lhs) 'assign-op))
              (cons lhsop (append (cdr lhs) (list rhs))))
             % simple substitution case
             ((setq lhsop (get (car lhs) 'setf-expand))
              (apply lhsop (list lhs rhs)))
             % more complex transformation
             ((and (setq lhsop (getd (car lhs)))
                   (equal (car lhsop) 'macro))
              (expandsetf (apply (cdr lhsop) (list lhs)) rhs))
             (t (stderror
                 (bldmsg "%r is not a known form for assignment"
                         (list 'setf lhs rhs)))))))

(loadtime
  (deflist '((getv putv) (car rplaca) (cdr rplacd) (indx setindx)
             (sub setsub) (nth (lambda (l i x)
                                       (rplaca (pnth l i) x)
                                       x)) (eval set) (value set))
           'assign-op))

