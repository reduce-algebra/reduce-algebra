%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:FOR-MACRO.SL 
% Description:  Fancy FOR loop 
% Author:       Don Morrison, Symbolic Computation Group, University of Utah 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2058-PDT (Nancy Kendzierski) 
% Package:      
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 6 May 1984 1752-PDT (Nancy Kendzierski)
%  Added compiletime loads to allow separate compilation.  Moved definition
%  of funcall and call here from misc-macros, since process-for-clause uses
%  it, and needs to know it's a macro.  Misc-macros isn't around yet, when
%  this is compiled.  The copyd of 'funcall to 'call is now bothtimes, instead
%  of compiletime loading the whole module.
% 6 Mar 1984 1730-PST (Nancy Kendzierski)
%  Added extra comments to explain numeric-operators interaction.
% 10-Jan-84 11:07:24 (Cris Perdue)
%  Fixed generation of termination testing code for the FROM
%  clause in the case where there is no termination expression and
%  a STEP that is not explicitly positive.  (Transposed 2 COND clauses.)
% Edit by Cris Perdue,  4 May 1983 1338-PDT
% Added maximal and minimal clauses: like maximize, minimize, but
%   return the element that yielded the greatest value
%   (or arbitrary function thereof).
% Edit by Cris Perdue, 22 Apr 1983 1318-PST
% Corrected test for "for" clauses being PAIRP.
% <PSL.UTIL>FOR-MACRO.SL.3,  7-Oct-82 15:46:11, Edit by BENSON
% Changed NULL tests to ATOM tests
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Fancy for loop.  Similar to MACLISP and clones' loop function, but with
% LISPier "syntax" and slightly reduced functionality and concommitant hair.

(compiletime (load backquote read-macros defmacro cond-macros
		   bind-macros set-macros iter-macros))

(fluid '(for-vars* for-outside-vars* for-tests* for-prologue* for-conditions*
         for-body* for-epilogue* for-result*))

(defmacro funcall u `(apply ,(car u) (list ,@(cdr u))))

(bothtimes (copyd 'call 'funcall))

(dm for (U) (for-build-loop (cdr U) 'do-loop 'let))

(defmacro for* U
  (for-build-loop U 'do-loop* 'let*))

(de for-build-loop (U loop-fn let-fn)
% Simply calls the function stored under the for-function property of the
% keyword at the begining of each clause, and then builds the DO form from
% the fluids below.  These are in TCONC format.  The clause specific
% functions should do their stuff by TCONC/LCONCing onto these variables.
% The clause specific functions take one argument, the list of arguments to
% the clause keyword.
 (let ((for-outside-vars* (list nil))
       (for-vars* (list nil))
       (for-tests* (list nil))
       (for-prologue* (list nil))
       (for-conditions* (list nil))
       (for-body* (list nil))
       (for-epilogue* (list nil))
       (for-result* (list nil)))
  (foreach clause in U do (process-for-clause clause))
  % "UnTCONCify" everybody
  (setf
    for-outside-vars* (car for-outside-vars*)
    for-vars* (car for-vars*)
    for-tests* (car for-tests*)
    for-prologue* (car for-prologue*)
    for-conditions* (car for-conditions*)
    for-body* (car for-body*)
    for-epilogue* (car for-epilogue*)
    for-result* (car for-result*))
  % Now, back to work...
  (if for-tests* (setf for-tests* (if (cdr for-tests*)
				    (cons 'or for-tests*)
				    (car for-tests*))))
  (when for-conditions*
   (setf for-conditions* (if (cdr for-conditions*)
			  (cons 'and for-conditions*)
			  (car for-conditions*)))
   (setf for-body* `((when ,for-conditions* ,.for-body*))))
  (if (and for-result* (cdr for-result*))
   (StdError "For loops may only return one value"))	 % msg needs improving
  % Finally build up the form to return
  (let ((form `(,loop-fn ,for-vars*
		 ,for-prologue*
		 (,for-tests* ,.for-epilogue* ,.for-result*)
		 ,.for-body*)))
    (if for-outside-vars* `(,let-fn ,for-outside-vars* ,form) form))))

(de process-for-clause (clause)
  (cond
   ((not (pairp clause))
    (process-for-clause
     (ContinuableError
      99
      (BldMsg "For clauses may not be atomic: %r." clause)
      clause))))
  (let ((op (car clause)) fn)
    (cond
     ((setf fn (get op 'for-function))
      (call fn (cdr clause)))
     (t
      (ContinuableError
       99
       (BldMsg "Unknown for clause operator: %r." op)
       op)))))

(de for-in-function (clause)
 (let ((var (car clause))
       (lst (cadr clause))
       (fn (and (cddr clause) (caddr clause)))
       (dummy (gensym)))
   (tconc for-outside-vars* dummy)
   (tconc for-vars* `(,var
		       (progn
			 (setf ,dummy ,lst)
			 (if (pairp ,dummy)
			   ,(if fn `(,fn (car ,dummy)) `(car ,dummy))
			   ()))
		       (progn
			 (setf ,dummy (cdr ,dummy))
			 (if (pairp ,dummy)
			   ,(if fn `(,fn (car ,dummy)) `(car ,dummy))
			   ()))))
   (tconc for-tests* `(atom ,dummy))))

(de for-on-function (clause)
 (let ((var (car clause))
       (lst (cadr clause)))
   (tconc for-vars* `(,var ,lst (cdr ,var)))
   (tconc for-tests* `(atom ,var))))

% Numeric-Operators assumes that for-from-function is the name used in the
% FOR clause in USEFUL.  It also assumes that for-function is the name used
% in the FOR macro.  Don't change this without understanding this interaction.
(de for-from-function (clause)
 (let* ((var (car clause))
	(var1 (if (pairp var) (car var) var))
	(clause (cdr clause))
	(init (if (pairp clause) (or (pop clause) 1) 1))
	(fin (if (pairp clause) (pop clause) nil))
	(fin-var (if (and fin (not (numberp fin))) (gensym) nil))
	(step (if (pairp clause) (car clause) 1))
	(step-var (if (and step (not (numberp step))) (gensym) nil)))
   (tconc
     for-vars*
     (list* var init (cond
		       (step-var `((plus2 ,var1 ,step-var)))
		       ((zerop step) nil)
		       ((onep step) `((add1 ,var1)))
		       ((eqn step -1) `((sub1 ,var1)))
		       (t `((plus ,var1 ,step))))))
   (if fin-var (tconc for-vars* `(,fin-var ,fin)))
   (if step-var (tconc for-vars* `(,step-var ,step)))
   (cond ((null fin))
         (step-var
	  (tconc for-tests* `(if (minusp ,step-var)
			      (lessp ,var1 ,(or fin-var fin))
			      (greaterp ,var1 ,(or fin-var fin)))))
         ((minusp step) (tconc for-tests* `(lessp ,var1 ,(or fin-var fin))))
	 (t (tconc for-tests* `(greaterp ,var1 ,(or fin-var fin)))))))

(de for-for-function (clause) (tconc for-vars* clause))

(de for-with-function (clause) 
 (lconc for-vars* (append clause nil)))			 % copy it for safety

(de for-initially-function (clause)
 (lconc for-prologue* (append clause nil)))		 % copy it for safety

(de for-finally-function (clause)
 (lconc for-epilogue* (append clause nil)))		 % copy it for safety

(de for-do-function (clause)
 (lconc for-body* (append clause nil)))			 % copy it for safety

(de for-collect-function (clause)
 (let ((tail (gensym))(reslt))
  (if (cdr clause)
    (progn
      (setf reslt (cadr clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* tail)
  (tconc for-body* `(if ,tail
		     (setf ,tail (cdr (rplacd ,tail (ncons ,(car clause)))))
		     (setf ,reslt (setf ,tail (ncons ,(car clause))))))))

(de for-conc-function (clause)
 (let ((reslt)(tail (gensym)))
  (if (cdr clause)
    (progn
      (setf reslt (cadr clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* tail)
  (tconc for-body* `(if ,tail
		     (setf ,tail (LastPair (rplacd ,tail ,(car clause))))
		     (setf ,reslt ,(car clause))
		     (setf ,tail (LastPair ,reslt))))))

(de for-join-function (clause)
 (let ((reslt)(tail (gensym)))
  (if (cdr clause)
    (progn
      (setf reslt (cadr clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* tail)
  (tconc for-body* `(if ,tail
		     (setf
		      ,tail
		      (LastPair (rplacd ,tail (append ,(car clause) nil))))
		     (setf ,reslt (append ,(car clause) nil))
		     (setf ,tail (LastPair ,reslt))))))

(defmacro-no-displace def-for-basic-return-function (name var init exp bod)
  `(de ,name (clause)
     (let ((reslt))
       (if (cdr clause)
	 (progn
	   (setf reslt (cadr clause))
	   (tconc for-prologue* `(setf ,reslt ,,init)))
	 (setf reslt (gensym))
	 (tconc for-vars* `(,reslt ,,init))
	 (tconc for-result* reslt))
       (tconc for-body* ,(subst 'reslt var (subst '(car clause) exp bod))))))

(def-for-basic-return-function for-union-function
  reslt nil exp `(setf ,reslt (union ,reslt ,exp)))

(def-for-basic-return-function for-unionq-function
  reslt nil exp `(setf ,reslt (unionq ,reslt ,exp)))

(de for-intersection-function (clause)
 (let ((reslt)(flg (gensym)))
  (if (cdr clause)
    (progn
      (setf reslt (cadr clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* flg)
  (tconc for-body* `(setf ,reslt (if ,flg
				   (intersection ,reslt ,(car clause))
				   (setf ,flg t)
				   ,(car clause))))))

(de for-intersectionq-function (clause)
 (let ((reslt)(flg (gensym)))
  (if (cdr clause)
    (progn
      (setf reslt (cadr clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* flg)
  (tconc for-body* `(setf ,reslt (if ,flg
				   (intersectionq ,reslt ,(car clause))
				   (setf ,flg t)
				   ,(car clause))))))

(def-for-basic-return-function for-adjoin-function
  reslt nil exp `(setf ,reslt (adjoin ,exp ,reslt)))

(def-for-basic-return-function for-adjoinq-function
  reslt nil exp `(setf ,reslt (adjoinq ,exp ,reslt)))

(def-for-basic-return-function for-count-function
  reslt 0 exp `(if ,exp (incr ,reslt)))

(def-for-basic-return-function for-sum-function
  reslt 0 exp `(incr ,reslt ,exp))

(def-for-basic-return-function for-product-function
  reslt 1 exp `(setf ,reslt (times ,reslt ,exp)))

(def-for-basic-return-function for-maximize-function
  reslt nil exp `(setf ,reslt (if ,reslt
				(max ,reslt ,(car clause))
				,(car clause))))

(def-for-basic-return-function for-minimize-function
  reslt nil exp `(setf ,reslt (if ,reslt
				(min ,reslt ,(car clause))
				,(car clause))))


(de for-maximal-function (clause)
 (let ((reslt) (flg (gensym)) (maxv (gensym)) (cmpv (gensym)))
  (if (and (cdr clause) (cddr clause))
    (progn
      (setf reslt (third clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* flg)
  (tconc for-vars* maxv)
  (tconc for-vars* cmpv)
  (tconc for-body* `(setf ,cmpv ,(second clause)))
  (tconc for-body* `(cond ((or (cond ((not ,flg)
				      (setf ,flg t)))
			       (greaterp ,cmpv ,maxv))
			   (setf ,maxv ,cmpv)
			   (setf ,reslt ,(first clause)))))))

(de for-minimal-function (clause)
 (let ((reslt) (flg (gensym)) (minv (gensym)) (cmpv (gensym)))
  (if (and (cdr clause) (cddr clause))
    (progn
      (setf reslt (third clause))
      (tconc for-prologue* `(setf ,reslt nil)))
    (setf reslt (gensym))
    (tconc for-vars* reslt)
    (tconc for-result* reslt))
  (tconc for-vars* flg)
  (tconc for-vars* minv)
  (tconc for-vars* cmpv)
  (tconc for-body* `(setf ,cmpv ,(second clause)))
  (tconc for-body* `(cond ((or (cond ((not ,flg)
				      (setf ,flg t)))
			       (lessp ,cmpv ,minv))
			   (setf ,minv ,cmpv)
			   (setf ,reslt ,(first clause)))))))

(de for-always-function (clause)
 (tconc for-body*
   `(if (null ,(if (cdr clause) `(and ,@clause) (car clause))) (return nil)))
 (tconc for-result* t))

(de for-never-function (clause)
 (tconc for-body*
   `(if ,(if (cdr clause) `(or ,@clause) (car clause)) (return nil)))
 (tconc for-result* t))

(de for-thereis-function (clause)
 (let ((temp (gensym)))
  (tconc for-result* nil)
  (tconc for-vars* temp)
  (tconc for-body* `(if (setf ,temp ,(car clause)) (return ,temp)))))

(de for-returns-function (clause)
 (tconc for-result* (if (cdr clause) (cons 'progn clause) (car clause))))

(de for-while-function (clause)
 (lconc for-tests* (foreach u in clause collect `(null ,u))))

(de for-until-function (clause)
 (lconc for-tests* (append clause nil)))		 % copy for safety

(de for-when-function (clause)
 (lconc for-conditions* (append clause nil)))	 % copy for safety

(de for-unless-function (clause)
 (lconc for-conditions* (foreach u in clause collect `(not ,u))))

(deflist `(
  (in ,#'for-in-function)
  (on ,#'for-on-function)
  (from ,#'for-from-function)       % See comment at function defn.
  (for ,#'for-for-function)
  (as ,#'for-for-function)
  (with ,#'for-with-function)
  (initially ,#'for-initially-function)
  (finally ,#'for-finally-function)
  (do ,#'for-do-function)
  (doing ,#'for-do-function)
  (collect ,#'for-collect-function)
  (collecting ,#'for-collect-function)
  (conc ,#'for-conc-function)
  (concing ,#'for-conc-function)
  (join ,#'for-join-function)
  (joining ,#'for-join-function)
  (count ,#'for-count-function)
  (counting ,#'for-count-function)
  (sum ,#'for-sum-function)
  (summing ,#'for-sum-function)
  (product ,#'for-product-function)
  (maximize ,#'for-maximize-function)
  (maximizing ,#'for-maximize-function)
  (minimize ,#'for-minimize-function)
  (minimizing ,#'for-minimize-function)
  (maximal ,#'for-maximal-function)
  (minimal ,#'for-minimal-function)
  (union ,#'for-union-function)
  (unionq ,#'for-unionq-function)
  (intersection ,#'for-intersection-function)
  (intersectionq ,#'for-intersectionq-function)
  (adjoin ,#'for-adjoin-function)
  (adjoinq ,#'for-adjoinq-function)  
  (always ,#'for-always-function)
  (never ,#'for-never-function)
  (thereis ,#'for-thereis-function)
  (returns ,#'for-returns-function)
  (returning ,#'for-returns-function)
  (while ,#'for-while-function)
  (until ,#'for-until-function)
  (when ,#'for-when-function)
  (unless ,#'for-unless-function)
     ) 'for-function)

% End of file.
