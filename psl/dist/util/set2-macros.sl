%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:SET2-MACROS.SL 
% Description:  SETF macro. 
% Author:       Don Morrison, University of Utah 
% Created:      12-May-82 
% Modified:     9 May 1984 2057-PDT (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Lisp 
% Status:       Open Source: BSD License
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
%               PL:BIND-MACROS.B PL:SET1-MACROS.B 
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
% 25-Aug-88 (Julian Padget)
% Local variable "stack" changed to "stk" to avoid binding of global variable.
% 6 May 1984 1654-PDT (Nancy Kendzierski)
%  Added compiletime loads and split into two parts to allow separate
%  compilation, without requiring itself.  Changed use of FOR in vector-setf
%  to an equivalent (although admittedly messier looking) FOREACH, because the
%  FOR macro isn't yet defined.
% 30-Nov-83 14:14:59  Brian Beach
%   Fixed bug having to do with macro expansion.  Changed so that
%   macro expansion takes place before a decision is made about what
%   kind of structure to use (i.e. whether or not to wrap a LAMDBA 
%   around it.
% 12-Oct-82 15:53:58  Eric Benson
%  Added IGETV to SETF-SAFE list
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros
		   bind-macros set1-macros))

(fluid '(*setf-debug))

(de expand-pnth-setf (lhs rhs)
  (let ((L (cadr lhs))(n (caddr lhs)))
    (cond
      ((onep n) `(setf ,L ,rhs))
      ((fixp n) `(rplacd (pnth ,L (sub1 ,n)) ,rhs))
      (t
	(let ((expnsn (errorset `(setf2 ',L ',rhs) *setf-debug *setf-debug)))
	  (if (atom expnsn)
	    `(rplacd (pnth ,L (sub1 ,n) ,rhs))
	    `(let ((***PNTH-SETF-VAR*** ,n))
	       (if (onep ***PNTH-SETF-VAR***)
		 ,(car expnsn)
		 (rplacd (pnth ,L (sub1 ***PNTH-SETF-VAR***)) ,rhs)))))))))

(de flag-setf (nam flg val)
  (cond
    (val (flag (list nam) flg) t)
    (t (remflag (list nam) flg) nil)))

(de getd-setf (trgt src)
  (cond
% not correct for the parallel case...
%   ((idp src) (copyd trgt src))
    ((or (codep src) (eqcar src 'lambda)) % is this kludge worthwhile?
      (progn (putd trgt 'expr src) (cons 'expr src)))
    ((pairp src)
      (progn (putd trgt (car src) (cdr src)) src))
    (t
      (ContinuableError
	99
	(bldmsg "%r is not a funtion spec." src)
	src))))

(de list-setf (lhs rhs)
  (if (atom rhs)
    `(progn ,.(destructure-form (cdr lhs) rhs) ,rhs)
    `(let ((***LIST-SETF-VAR*** ,rhs)) 
       ,.(destructure-form (cdr lhs) '***LIST-SETF-VAR***)
       ***LIST-SETF-VAR***)))

(de cons-setf (lhs rhs)
  (if (atom rhs)
    `(progn
       (setf ,(cadr lhs) (car ,rhs))
       (setf ,(caddr lhs) (cdr ,rhs))
       ,rhs)
    `(let ((***CONS-SETF-VAR*** ,rhs))
       (setf ,(cadr lhs) (car ***CONS-SETF-VAR***))
       (setf ,(caddr lhs) (cdr ***CONS-SETF-VAR***))
       ***CONS-SETF-VAR***)))

% Replace by definition below, because the FOR macro is not yet defined.
% (de vector-setf (lhs rhs)
%   (let ((x (if (atom rhs) rhs '***VECTOR-SETF-VAR***)))
%     (let ((L (for (in u (cdr lhs)) (from i 0)
%	        (collect `(setf ,u (getv ,x ,i))))))
%       (if (atom rhs)
%	 `(progn ,.L ,x)
%	 `(let ((***VECTOR-SETF-VAR*** ,rhs)) ,.L ,x)))))

(de vector-setf (lhs rhs)
  (let ((x (if (atom rhs) rhs '***VECTOR-SETF-VAR***)))
    (let ((L (let ((i -1))
	       (foreach u in (cdr lhs)
			collect `(setf ,u (getv ,x ,(setq i (add1 i))))))))
      (if (atom rhs)
	`(progn ,.L ,x)
	`(let ((***VECTOR-SETF-VAR*** ,rhs)) ,.L ,x)))))

% Some more useful assignment macros

(defmacro push (item stk) `(setf ,stk (cons ,item ,stk)))

(defmacro pop (stk . rst)
  (let ((x `(prog1 (car ,stk) (setf ,stk (cdr ,stk)))))
    (if rst `(setf ,(car rst) ,x) x)))

(defmacro adjoin-to (e s) `(setf ,s (adjoin ,e ,s)))

(defmacro adjoinq-to (e s) `(setf ,s (adjoinq ,e ,s)))

(defmacro incr (var . rst)
  `(setf ,var ,(if rst `(plus ,var ,@rst) `(add1 ,var))))

(defmacro decr (var . rst)
  `(setf ,var ,(if rst `(difference ,var (plus ,@rst)) `(sub1 ,var))))

(defmacro clear L
  `(setf ,.(foreach u in L conc `(,u nil))))

% Parallel assignment macros

(defmacro psetq rst
% psetq looks like a multi-arg setq but does its work in parallel.
     (cond ((null rst) nil)
           ((cddr rst)
	    `(setq ,(car rst)
		   (prog1 ,(cadr rst) (psetq . ,(cddr rst)))))
           % the last pair.  keep it simple;  no superfluous
	   % (prog1 (setq...) (psetq)).
	   ((cdr rst) `(setq . ,rst))
	   (t (StdError "psetq passed an odd number of arguments"))))

(defmacro psetf rst
% psetf looks like a multi-arg setf but does its work in parallel.
     (cond ((null rst) nil)
           ((cddr rst)
	    `(setf ,(car rst)
		   (prog1 ,(cadr rst) (psetf . ,(cddr rst)))))
	   ((cdr rst) `(setf . ,rst))
	   (t (StdError "psetf passed an odd number of arguments"))))

(defmacro defswitch (nam var . acts)
  (let ((read-act (if (pairp acts) (car acts) nil))
	(set-acts (if (pairp acts) (cdr acts) nil)))
    (when (null var)
      (setf var (newid (bldmsg "%w-SWITCH-VAR*" nam)))) 
    `(progn
       (fluid '(,var))
       (de ,nam () (let ((,nam ,var)) ,read-act) ,var)
       (setf
	 (get ',nam 'assign-op)
	 #'(lambda (,nam) ,@set-acts (setq ,var ,nam)))
       (flag '(,nam) 'setf-safe))))

