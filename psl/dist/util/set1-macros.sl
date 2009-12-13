%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:SET1-MACROS.SL 
% Description:  First part of SETF macro. 
% Author:       Don Morrison, University of Utah 
% Created:      12-May-82 
% Modified:     9 May 1984 2057-PDT (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Lisp 
% Status:       Experimental (Do Not Distribute) 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
%               PL:BIND-MACROS.B 
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
% 6 May 1984 1652-PDT (Nancy Kendzierski)
%  Added compiletime loads and split into two parts to allow separate
%  compilation, without requiring itself.
% 30-Nov-83 14:14:59  Brian Beach
%   Fixed bug having to do with macro expansion.  Changed so that
%   macro expansion takes place before a decision is made about what
%   kind of structure to use (i.e. whether or not to wrap a LAMDBA 
%   around it.
% 12-Oct-82 15:53:58  Eric Benson
%  Added IGETV to SETF-SAFE list
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros bind-macros))

(defmacro setf u
  (cond
    ((atom u) nil)
    ((atom (cdr u)) (stderror "Odd number of arguments to setf."))
    ((atom (cddr u)) (setf2 (car u) (cadr u)))
    (t `(progn ,@(setf1 u)))))

(de setf1 (u)
  (cond
    ((atom u) nil)
    ((atom (cdr u)) (stderror "Odd number of arguments to setf."))
    (t (cons (setf2 (car u) (cadr u)) (setf1 (cddr u))))))

(de setf2 (lhs rhs)
  % First, perform any macro expansions necessary, and then
  % decide what sort of structure to use.

  (while (and (pairp lhs)
	      (idp (car lhs))
	      (macrop (car lhs))
	      (not (get (car lhs) 'assign-op))
	      (not (get (car lhs) 'setf-expand)))
    (setq lhs (apply (car lhs) (list lhs)))
    )
  (cond
   ((atom lhs)
    `(setq ,lhs ,rhs))
   ((and (idp (car lhs)) (flagp (car lhs) 'setf-safe))
    (expand-setf lhs rhs))
   ((atom rhs)  
    `(progn ,(expand-setf lhs rhs) ,rhs))
   (t                              
    `(let ((***SETF-VAR*** ,rhs))
       ,(expand-setf lhs '***SETF-VAR***)
       ***SETF-VAR***))
   ))

(de expand-setf (lhs rhs)
  (let ((fn (car lhs)) (op))
    (cond
      ((and (idp fn) (setq op (get fn 'assign-op)))
	`(,op ,@(cdr lhs) ,rhs))
      ((and (idp fn) (setq op (get fn 'setf-expand)))
	(apply op (list lhs rhs)))
      (t
	(expand-setf
	  (ContinuableError
	    99
	    (BldMsg "%r is not a known form for assignment" `(setf ,lhs ,rhs))
	    lhs)
	  rhs)))))

(flag '(getv indx eval value get list cons vector getd igetv) 'setf-safe)

(defmacro-no-displace car-cdr-setf (rplacfn pathfn)
  `#'(lambda (lhs rhs) `(,',rplacfn (,',pathfn ,(cadr lhs)) ,rhs)))
	       
(deflist '(
  (car rplaca)
  (cdr rplacd)
  (getv putv)
  (igetv iputv)
  (indx setindx)
  (sub setsub)
  (eval set)
  (value set)
  (get put)
  (flagp flag-setf)
  (getd getd-setf)
    ) 'assign-op)

(remprop 'nth 'assign-op) % Remove default version (which is incorrect anyway)

(deflist `(
  (caar ,(car-cdr-setf rplaca car))
  (cadr ,(car-cdr-setf rplaca cdr))
  (caaar ,(car-cdr-setf rplaca caar))
  (cadar ,(car-cdr-setf rplaca cdar))
  (caadr ,(car-cdr-setf rplaca cadr))
  (caddr ,(car-cdr-setf rplaca cddr))
  (caaaar ,(car-cdr-setf rplaca caaar))
  (cadaar ,(car-cdr-setf rplaca cdaar))
  (caadar ,(car-cdr-setf rplaca cadar))
  (caddar ,(car-cdr-setf rplaca cddar))
  (caaadr ,(car-cdr-setf rplaca caadr))
  (cadadr ,(car-cdr-setf rplaca cdadr))
  (caaddr ,(car-cdr-setf rplaca caddr))
  (cadddr ,(car-cdr-setf rplaca cdddr))
  (cdar ,(car-cdr-setf rplacd car))
  (cddr ,(car-cdr-setf rplacd cdr))
  (cdaar ,(car-cdr-setf rplacd caar))
  (cddar ,(car-cdr-setf rplacd cdar))
  (cdadr ,(car-cdr-setf rplacd cadr))
  (cdddr ,(car-cdr-setf rplacd cddr))
  (cdaaar ,(car-cdr-setf rplacd caaar))
  (cddaar ,(car-cdr-setf rplacd cdaar))
  (cdadar ,(car-cdr-setf rplacd cadar))
  (cdddar ,(car-cdr-setf rplacd cddar))
  (cdaadr ,(car-cdr-setf rplacd caadr))
  (cddadr ,(car-cdr-setf rplacd cdadr))
  (cdaddr ,(car-cdr-setf rplacd caddr))
  (cddddr ,(car-cdr-setf rplacd cdddr))
  (nth ,#'(lambda (lhs rhs) `(rplaca (pnth ,@(cdr lhs)) ,rhs)))
  (pnth ,#'expand-pnth-setf)
  (lastcar ,#'(lambda (lhs rhs) `(rplaca (lastpair ,(cadr lhs)) ,rhs)))
  (list ,#'list-setf)
  (cons ,#'cons-setf)
  (vector ,#'vector-setf)
    ) 'setf-expand)
