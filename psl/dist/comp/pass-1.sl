%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:PASS-1.SL 
% Description:  Pass one of the compiler. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      19-Mar-84 
% Package:      
% Status:       Experimental (Do Not Distribute) 
%
% (c) Copyright 1987, University of Utah
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
% 17-May-2002 (Winfried Neun)
%  pa1r-equal changed (equal x 0) to (eq x 0) which is different
%  from the interpreted equal for x=0.0 
% 17-Jan-92 (Winfried Neun)
%  Added pass-1-macro for minusp suggested by Arthur Norman.
% 8-Feb-90 (Winfried Neun)
%  Fix for Make-group-ops to handle NIL argument correctly.
% 27-Jun-88 (Chris Burdorf)
%  Got rid of the selectq in def-pass-1-macro list
% 25-Apr-87 (Leigh Stoller)
%  Changed load of pass-1-decls to p1-decls.
% 11-Nov-86 (Leigh Stoller)
%  Changed group function to be groupop to avoid a conflict with Alpha1 code.
% 18-Sep-86 (Leigh Stoller)
%  Added compiletime load of strings.
% 17-Jan-85 (Brian Beach)
%  Fixed bug in call to pass-1-list in the function pass-1-apply-list.
%  Fixed bug in pass-1-apply-id where CAR is called on NIL -- the result
%  of the GETD.
% 26-Dec-84 11:16:29 (Vicki O'Day)
%  Added checks to prevent (car nil) and (cdr nil) to cond.
% 3 Dec 1984 1419-PST (Brian Beach)
%  Changed bothtimes load of if-system to a compiletime load.
%  Repaired below fix for PUTFIELD (it didn't handle both cases).
% 16 Nov 1984 1049-PST (Roy D'Souza)
%  Added bothtimes load of if-system.
% 15 Nov 1984 1600-PST (Roy D'Souza)
%  Inserted p20c:patch.sl for evry system other than MC68000
% 26-Sep-84 15:19:54 (Brian Beach)
%  Fixed PASS-1-MAP-CONC.  Was collecting rather that concatenating.
% 14-Aug-84 12:53:49 (Brian Beach)
%  Fixed ASSOCOP-FLATTEN to remove infinite recursive loop.
% 13-Jun-84 15:29:08 (Jim Ambras/CRC)
%  Added load of PASS-1-DECLS.SL.
% 25-Apr-84 10:23:45 (Brian Beach)
%  Redid EQ-ABLE? and friends.
% 21-Mar-84 07:16:04 (Brian Beach)
%  Adapted from pass 1 of the PSL compiler by Griss, Benson, Peterson, and Hearn.
%  The mechanism for pass 1 functions, reform functions, and CMACROS has been 
%  changed.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% Functions used in pass 1 that are defined elsewhere in the compiler:
%
%    &COMPERROR
%    &COMPWARN
%    &GENSYM
%

%
% Common variable names used in this file:
%
%   U      - An arbitrary form to be processed
%   VBLS   - A list of variables local to the function being processed
%

(load p1-decls)

(compiletime (load if-system strings))

(de compiler-pass-1 (u)

  % Pass one of the compiler - reform body of expression for compilation

  (recursive-pass-1 u nil)
  )

(de recursive-pass-1 (u vbls)

  % Main recursive entry into PASS1.
  % Do the real pass without a reform, and then
  % reform the result if it has a reform function, and the reform function
  % returns non-NIL.

  (let ((result (pass-1-no-reform u vbls)))
    (if (and (pairp result)
	     (idp (first result))
	     (get (first result) 'pass-1-reform))
      (let ((reformed (apply (get (first result) 'pass-1-reform) (list result))))
	(if reformed
	  reformed
	  result
	  ))
      result
      )))
 
(de pass-1-no-reform (u vbls)

  % Main workhorse, without the extra reform

  (if (atom u)
    (pass-1-atom u vbls)
    (pass-1-function-call u vbls)
    ))

(de pass-1-list (u vbls)

  % Recursively process a list of forms

  (for (in x u)
       (collect (recursive-pass-1 x vbls))
       ))

(de pass-1-function-call (u vbls)

  % Check applied form to see if it is an ID or a LIST and dispatch
  % to appropriate routine.  If the resulting form is a side-effect-free
  % function applied to constant arguments, return the value of the 
  % entire expression.

  (let ((result (cond ((idp (first u))    (pass-1-apply-id u vbls))
		      ((pairp (car u))    (pass-1-apply-list u vbls))
		      (t                  (&comperror
					   (list "Ill-formed function expression" u))))))
    (if (and (pairp result)
	     (idp (first result))
	     (get (first result) 'no-side-effects?)
	     (for (in x (rest result)) (always (constant? x))))
      (list (result-tag (first u))
	    (eval-const-expr result))
      result
      )))

(de pass-1-apply-id (u vbls)

  % An ID is applied tp a list of parameters.  Pass 1 functions and macros
  % are applies.  Functions flagged with COMPFN or OPENFN are known to later
  % passes and are not processed here.  Macros are expanded.  Parameters to
  % FEXPRs and NEXPRs are listified.

  (let ((fcn   (first u))
	(args  (rest u)))
    (when (get fcn 'cmacro)
      (&compwarn (list "Function used that has a CMACRO: " fcn)))
    (cond
     ((use-fast-version? fcn)    (recursive-pass-1 (cons (get fcn 'fast-function)
							 (rest u))
						   vbls))
     ((get fcn 'pass-1-function) (apply (get fcn 'pass-1-function)
					(list u vbls)))
     ((get fcn 'pass-1-macro)    (pass-1-macro u vbls))
     ((get fcn 'compfn)          (cons fcn (pass-1-list args vbls)))
     ((get fcn 'openfn)          (cons fcn (pass-1-list args vbls)))
     ((eq (safecar (getd fcn))  
	  'macro)                (recursive-pass-1 (apply (cdr (getd fcn)) (list u)) vbls))
     ((eq (&cfntype fcn) 
	  'fexpr)                (list fcn (mkquote args)))
     ((eq (&cfntype fcn)
	  'nexpr)                (list fcn (recursive-pass-1 (cons 'list args) vbls)))
     (t                          (cons fcn (pass-1-list args vbls)))
     )))

(de use-fast-version? (fcn)
  (and (get fcn 'fast-flag)
       (eval (get fcn 'fast-flag))
       ))

(de pass-1-macro (u vbls)

  % Process a pass 1 macro call.  The macro is expanded, and if the 
  % resulting form is non-NIL, it is then processed.  If the form is NIL,
  % that indicates that the macro did not do anything, and the function
  % call is left as is, and the arguments are processed.
  
  (let* ((fcn      (get (first u) 'pass-1-macro))
	 (new-u    (apply fcn (list u))))
    (if new-u
      (recursive-pass-1 new-u vbls)
      (cons (first u) (pass-1-list (rest u) vbls))
      )))

(de pass-1-apply-list (u vbls)

  % LAMBDA expressions are the only list forms that may be used as
  % functions.  Both the LAMBDA expression and the parameters are run back
  % through pass 1.

  (if (eq (first (first u)) 'lambda)
    (pass-1-list u vbls)
    (progn
     (&comperror (list "Ill-formed function expression" u))
     '(quote nil)
     )))

(de pass-1-atom (u vbls)

  % Process an atom.  Anything other than an ID is a constant.
  % IDs are checked for non-local first, since fluid
  % variables are always accessed through the value cell.

  (cond ((not (idp u))                          (mkquote u))
	((and (constant? u)
	      (not (memq u vbls)))              (mkquote (constant-value u)))
	((non-local u)                          (list (non-local u) u))
	((memq u vbls)                          (list '$local u))
	(t                                      (make-non-local u))
	))

(de non-local (x)

  % Returns $FLUID, $GLOBAL if x is declared as a non-local.
  % Returns NIl if not.

  (cond ((fluidp x)  '$fluid)
        ((globalp x) '$global)
        (t nil)
	))

(de make-non-local (u)

  % Make an unknown symbols into a FLUID, with warning.

  (&compwarn (list u "declared fluid"))
  (fluid (list u))
  (list '$fluid u)
  )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Constant handling
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de result-tag (function)

  % Returns the proper tag for the constant result of FUNCTION.

  (if (get function 'returns-untagged-value?)
    'wconst
    'quote
    ))

(de constant? (u)
  (cond
   ((and (atom u) (not (idp u)))          t)
   ((and (idp u)
	 (or (get u 'compiler-constant?)
	     (get u 'constant?)))         t)
   ((wconst? u)                           t)
   ((and (pairp u)
	 (eq (first u) 'quote))           t)
   ))

(de constant-value (u)
  (cond
   ((and (atom u) (not (idp u)))          u)
   ((and (idp u)
	 (get u 'compiler-constant?))     (get u 'compiler-constant-value))
   ((and (idp u)
	 (get u 'constant?))              (eval u))
   ((wconst? u)                           (second u))
   ((and (pairp u)
	 (eq (first u) 'quote))           (second u))
   (t (&comperror "Compiler bug in CONSTANT-VALUE"))
   ))

(de integer-constant? (u)
  (and (constant? u)
       (fixp (constant-value u))
       ))

(de numeric-constant? (u)
  (and (constant? u)
       (numberp (constant-value u))
       ))

(de all-constant? (l)

  % Check that all expressions in list L are constants.

  (for (in item l)
       (always (constant? item)))
  )

(de eval-const-expr (u)

  % Simplify an expression whose operator has no side effects and whose parameters
  % are all constants.  If the operator has a DOFN property, that is used as the 
  % function to evaluate the expression.

  (let ((fcn  (first u))
	(args (rest u)))
    (apply (or (get fcn 'dofn) fcn)
	   (for (in x args)
		(collect (constant-value x))
		))))

(de wconst? (x)

  % Test if X is a WCONST expression:   (WCONST <integer>)

  (and (pairp x)
       (eq (first x) 'wconst)
       (fixp (second x))
       ))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Pass 1 functions, macros, and reform functions.
%
% A pass 1 function is used where explicit control is needed of the local variable
% list, or of the application of pass1 to the parameters.
%
% A pass 1 macro is used for the other (simpler) cases.
%
% A reform function is used when something needs to be done AFTER the parameters
% have been run through pass 1.
%
% The functions are placed in alphabetical order.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
 (defmacro def-pass-1-function (name args . body)
   (let ((fcn-name (intern (string-concat (id2string 'PA1F-) 
                                          (id2string name)))))
     `(progn
       (put (quote ,name) (quote pass-1-function) (quote ,fcn-name))
       (de ,fcn-name ,args ,@body)
       ))))

(compiletime
 (defmacro def-pass-1-macro (name args . body)
   (let ((fcn-name (intern (string-concat (id2string 'PA1M-) 
                                          (id2string name)))))
     `(progn
       (put (quote ,name) (quote pass-1-macro) (quote ,fcn-name))
       (defmacro ,fcn-name ,args ,@body)
       ))))

(compiletime
 (defmacro def-pass-1-reform (name args . body)
   (let ((fcn-name (intern (string-concat (id2string 'PA1R-) 
                                          (id2string name)))))
     `(progn
       (put (quote ,name) (quote pass-1-reform) (quote ,fcn-name))
       (defmacro ,fcn-name ,args ,@body)
       ))))

(def-pass-1-macro    apply (function args)
  % (apply (function xxx) (list a b ...)) => (xxx a b ...)
  (when (and (pairp function)
	     (eq (first function) 'function)
	     (pairp args)
	     (eq (first args) 'list))
    (cons (second function) (rest args))
    ))

(def-pass-1-reform   assoc (item list)
  % Try to turn ASSOC into ATSOC
  % NOTE: This function assumes that a constant list given to ASSOC is
  %       really an association list.
  (when (or (eval-eq-able? item)
	    (and (constant? list)
		 (for (in item (constant-value list))
		      (always (eq-able? (car item)))
		      )))
    `(atsoc ,item ,list)
    ))

(if_system MC68000
	   (def-pass-1-macro  byte (a b)
			      `(getbyte ,a ,b)
			      ))

(def-pass-1-macro    caar (u)
  `(car (car ,u))
  )

(def-pass-1-macro    cadr (u)
  `(car (cdr ,u))
  )

(def-pass-1-macro    cdar (u)
  `(cdr (car ,u))
  )

(def-pass-1-macro    cddr (u)
  `(cdr (cdr ,u))
  )

(def-pass-1-macro    caaar (u)
  `(car (car (car ,u)))
  )

(def-pass-1-macro    caadr (u)
  `(car (car (cdr ,u)))
  )

(def-pass-1-macro    cadar (u)
  `(car (cdr (car ,u)))
  )

(def-pass-1-macro    caddr (u)
  `(car (cdr (cdr ,u)))
  )

(def-pass-1-macro    cdaar (u)
  `(cdr (car (car ,u)))
  )

(def-pass-1-macro    cdadr (u)
  `(cdr (car (cdr ,u)))
  )

(def-pass-1-macro    cddar (u)
  `(cdr (cdr (car ,u)))
  )

(def-pass-1-macro    cdddr (u)
  `(cdr (cdr (cdr ,u)))
  )

(def-pass-1-function cond (u vbls)
     % Handle missing (T NIL) in conds, implied PROGN and
     % sepcial case where only TEST appears; its wrapped in (LAMBDA (tmp)
     % and tmp returned as value of this clause
     (prog (revu result temp)
       (when (null (cdr u))
	 (return '(quote nil)))  % (COND) == NIL
       (setq revu (reverse (cdr u)))
       (when (and (pairp (first revu)) (neq (first (first revu)) t))
	 (setq revu (cons '(t nil) revu)))
       (foreach condform in revu do (if (pairp condform)
				      (if (null (rest condform))
					(progn
					 (unless temp
					   (setq temp (&gensym))
					   (setq vbls (cons temp vbls)))
					 (setq result 
					   (cons 
					    (list 
					     (recursive-pass-1 (list 'setq temp (first condform)) vbls) 
					     (recursive-pass-1 temp vbls))
					    result)))
					(setq result 
					  (cons 
					   (list (recursive-pass-1 (first condform) vbls) 
						 (recursive-pass-1 (&mkprogn (rest condform)) vbls))
					   result)))
				      % else, condform not a pair,
				      (&comperror
				       (list "Conditional clause not a list: " condform))
				      ))
       (return (if temp
		 (list (list 'lambda (list (recursive-pass-1 temp vbls)) 
			     (cons 'cond result))
		       ''nil)
		 (cons 'cond result)))))

(def-pass-1-function case (u vbls)
  % Process CASE clauses
  (cons 'case 
        (cons (recursive-pass-1 (cadr u) vbls) 
              (for (in exp (cddr u))
		   (collect (list (pass-1-list (car exp) vbls) 
				  (recursive-pass-1 (cadr exp) vbls)))))))

(def-pass-1-macro    catch (tag . forms)

  % Look for old style CATCH, and process for open compile

  (when (and (null (cdr forms)) 
	     (or (atom (car forms)) 
		 (equal (car (car forms)) 'quote) 
		 (equal (car (car forms)) 'list)))
    (&compwarn (list "Probable obsolete use of CATCH:" (cons 'catch (cons tag forms))))
    )
  (let ((temp-var1 (&gensym))
	(temp-var2 (&gensym)))
  `((lambda (,temp-var1)
      (cond
       ((null throwsignal*)  ((lambda (,temp-var2)
			       (!%uncatch ,temp-var1)
			       ,temp-var2)
			      (progn ,@forms)))
       (t ,temp-var1)
       ))
    (catchsetup ,tag)
    )
  ))
	
(def-pass-1-macro    constantp (a)
  (let ((temp (&gensym)))
    `((lambda (,temp)
	(not (or (pairp ,temp) (idp ,temp)))
	)
      ,a)
    ))

(def-pass-1-reform   difference (a b)
  % PA1FN: convert (DIFFERENCE X 1) to (SUB1 X)
  (when (and (constant? b) (equal (constant-value b) 1))
    `(sub1 ,a)
    ))

(def-pass-1-macro    eqcar (a b)
  (let ((temp (&gensym)))
    `((lambda (,temp)
	(and (pairp ,temp) (eq (car ,temp) ,b))
	)
      ,a
      )))

(def-pass-1-reform   equal (a b)
  % PA1FN: convert EQUAL to EQ if possible
  (cond
   ((or (equal a '(quote 0)) (equal b '(quote 0))) `(eqn ,a ,b))
   ((or (eval-eq-able? a)     (eval-eq-able? b))      `(eq ,a ,b))
   ((or (numeric-constant? a) (numeric-constant? b))  `(eqn ,a ,b))
   ))

(def-pass-1-function function (u vbls)
  % FUNCTION will compile a non-atomic arg into a GENSYMed name.
  % Currently, MKFUNC = MKQUOTE
  (cond ((pairp (second u))  (&mkfunc (compd '***code**pointer*** 
					     'expr
					     (second u))))
	(t                   (&mkfunc (second u)))
	))

(def-pass-1-macro    geq (a b)
  `(not (lessp ,a ,b))
  )

(def-pass-1-macro    getbyte (a b)
  `(getunsbyte (memory ,a ,b))
  )

(def-pass-1-macro    gethalfword (a b)
  `(getsgnhword (memory ,a (wtimes2 ,b 2)))
  )

(def-pass-1-reform   getmem (addr)

  % Convert GETMEM into MEMORY expression: (MEMORY var const),
  % where var is the variable part & const is the constant part (tagged, of
  % course).  ADDR has been through pass 1, which does constant
  % folding & puts any constant term at the top level, if possible.

  (if (eqcar addr 'loc)
    (second addr) % GETMEM LOC x == x
    (cons 'memory 
	  (cond ((eqcar addr 'wplus2)
		 (if (constant? (third addr))
		   (rest addr)
		   (list (third addr) (second addr))))
		((and (eqcar addr 'wdifference) (constant? (second addr))) 
		 (list (list 'wminus (third addr)) (second addr)))
		(t (list addr '(wconst 0)))
		))))

(def-pass-1-macro    getword (a b)
  `(wgetv ,a ,b)
  )

(def-pass-1-function go (u vbls)
  u
  )

(if_system MC68000
	   (def-pass-1-macro halfword (a b)
	      `(gethalfword ,a ,b)
	      ))


(def-pass-1-macro    iadd1 (a)
  `(wplus2 ,a 1)
  )

(def-pass-1-macro    iash (a b)
  `(ashift ,a ,b)
  )

(def-pass-1-macro    idifference (a b)
  `(wdifference ,a ,b)
  )

(def-pass-1-macro    ieq (a b)
  `(eq ,a ,b)
  )

(def-pass-1-macro    igeq (a b)
  `(wgeq ,a ,b)
  )

(def-pass-1-macro    igreaterp (a b)
  `(wgreaterp ,a ,b)
  )

(def-pass-1-macro    iland (a b)
  `(wand ,a ,b)
  )

(def-pass-1-macro    ileq (a b)
  `(wleq ,a ,b)
  )

(def-pass-1-macro    ilessp (a b)
  `(wlessp ,a ,b)
  )

(def-pass-1-macro    ilnot (a)
  `(wnot ,a)
  )

(def-pass-1-macro    ilor (a b)
  `(wor ,a ,b)
  )

(def-pass-1-macro    ilsh (a b)
  `(wshift ,a ,b)
  )

(def-pass-1-macro    ilxor (a b)
  `(wxor ,a ,b)
  )

(def-pass-1-macro    iminus (a)
  `(wminus ,a)
  )

(def-pass-1-macro    iminusp (a)
  `(wlessp ,a 0)
  )

(def-pass-1-macro    ineq (a b)
  `(ne ,a ,b)
  )

(def-pass-1-reform   intern (u)
  % PA1FN: (Intern (Compress X)) == (Implode X)
  %        (Intern (Gensym)) == (InternGensym)
  (cond ((eqcar u 'compress) (cons 'implode (cdr u)))
	((eqcar u 'gensym) (cons 'interngensym (cdr u)))
        ))

(def-pass-1-macro    ionep (a)
  `(eq ,a 1)
  )

(def-pass-1-macro    iplus2 (a b)
  `(wplus2 ,a ,b)
  )

(def-pass-1-macro    iquotient (a b)
  `(wquotient ,a ,b)
  )

(def-pass-1-macro    iremainder (a b)
  `(wremainder ,a ,b)
  )

(def-pass-1-macro    isub1 (a)
  `(wdifference ,a 1)
  )

(def-pass-1-macro    itimes2 (a b)
  `(wtimes2 ,a ,b)
  )

(def-pass-1-macro    izerop (a)
  `(eq ,a 0)
  )

(def-pass-1-function lambda (u vbls)
  % Pick up new LAMBDA vars for VBLS, check implicit PROGN
  (setq vbls (append (second u) vbls))
  (cons 'lambda 
	(list (pass-1-list (second u) vbls) (recursive-pass-1 (&mkprogn (cddr u)) vbls))))

(def-pass-1-macro    leq (a b)
  `(not (greaterp ,a ,b))
  )

(def-pass-1-macro    lessp (a b)
  (when (and (constant? b) (equal (constant-value b) 0))
    `(minusp ,a)
    ))

(def-pass-1-macro    minusp (a)
   (when (eqcar a 'difference) `(lessp ,@(cdr a))))

(def-pass-1-macro list args
  % Convert NEXPR LIST into special cases NCONS, LISTn or
  % CONS sequence
  %/ Perhaps remove when True NEXPRs work?
  (let ((len (length args)))
       (cond ((eqn len 0) '(quote nil))
	     ((eqn len 1) (cons 'ncons args))
	     ((eqn len 2) (cons 'list2 args))
	     ((eqn len 3) (cons 'list3 args))
	     ((eqn len 4) (cons 'list4 args))
	     ((eqn len 5) (cons 'list5 args))
	     (t (list 'cons (first args) (cons 'list (rest args)))))))

(def-pass-1-reform   loc (u)
  % PA1FN: (LOC (memory x y)) -> (wplus2 x y)
  (when (eqcar u 'memory)
    (list 'wplus2 (third u) (second u))
    ))

(def-pass-1-macro    map (list fcn)
  % Open compile MAP as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-do list fcn nil)
  )

(def-pass-1-macro    mapc (list fcn)
  % Open compile MAPC as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-do list fcn t)
  )

(def-pass-1-macro    maplist (list fcn)
  % Open compile MAPLIST as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-collect list fcn nil)
  )

(def-pass-1-macro    mapcar (list fcn)
  % Open compile MAPCAR as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-collect list fcn t)
  )

(def-pass-1-macro    mapcon (list fcn)
  % Open compile MAPCON as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-conc list fcn nil)
  )

(def-pass-1-macro    mapcan (list fcn)
  % Open compile MAPCAN as PROG if FUNCTIONAL form is explicitly tagged FUNCTION.
  (pass-1-map-conc list fcn t)
  )

(def-pass-1-reform   member (thing lst)
  % Attempt to change MEMBER to MEMQ, if EQUAL->EQ valid
  (when (or (eval-eq-able? thing)
	    (and (constant? lst)
		 (eq-able-list? (constant-value lst))))
    `(memq ,thing ,lst)
    ))

(def-pass-1-macro    mkitem (a b)
  `(mkitemrev ,b ,a)
  )

(def-pass-1-macro    neq (a b)
  `(not (equal ,a ,b))
  )

(def-pass-1-macro    not (a)
  `(null ,a)
  )

(def-pass-1-macro    nth (list index)
  % Map NTH into CAR, CAxR sequence for 1..4
  (pass-1-nths list index '((1 . car) (2 . cadr) (3 . caddr) (4 . cadddr))))

(def-pass-1-macro    pnth (list index)
  % Map PNTH into ident, CxR sequence for 1..5
  (pass-1-nths list index  '((1 . noop) (2 . cdr) (3 . cddr) (4 . cdddr) (5 . cddddr))))

(def-pass-1-reform   null (u)
  % (NULL (tst ..)) -> (fliptst ...), else to (eq tst NIL)
  % (NULL (NULL x)) is handled since the innermost will be processed first.
  (if (and (pairp u) 
	   (get (first u) 'fliptst))
    (cons (get (first u) 'fliptst) (rest u))
    (list 'eq u '(quote nil))
    ))

% Perdue 12/3/82
% This optimization causes compiled code to behave differently
% from interpreted code.  The FLIPTST property on NE and PASS2
% handling of negation in tests (&COMTST) are enough to cause good code
% to be generated when NE is used as a test.
%PROCEDURE !&REFORMNE U;
%     IF CADR U = '(QUOTE NIL) THEN CADDR U
%     ELSE IF CADDR U = '(QUOTE NIL) THEN CADR U
%     ELSE U;

(def-pass-1-reform   plus2 (a b)
  % PA1FN:  (PLUS2 X 1) -> (ADD1 X)
  (cond ((and (constant? a)
	      (equal (constant-value a) 1)) `(add1 ,b))
        ((and (constant? b)
	      (equal (constant-value b) 1)) `(add1 ,a))
	))

(def-pass-1-function prog (u vbls)
  % Pick up PROG vars, ignore labels.
  (setq vbls (append (second u) vbls))
  (cons 'prog 
	(cons (pass-1-list (second u) vbls) 
	      (pass-1-prog-body (cddr u) vbls)
	      )))

(if_system MC68000
	   (def-pass-1-macro putbyte (a b c)
			     `(putanybyte (memory ,a ,b) ,c)
			     ))

(if_system MC68000
	   (def-pass-1-macro    putfield (a b c d)
	      `(setq ,a (putfieldrev ,d ,a ,b ,c))
	      )
	   (def-pass-1-macro    putfield (a b c d)
	      `(putfieldrev ,d ,a ,b ,c)
	      ))

(if_system MC68000
	   (def-pass-1-macro puthalfword (a b c)
	      `(putanyhword (memory ,a (wtimes2 ,b 2)) ,c)
	      ))

(def-pass-1-macro    putmem (a b)
  % PA1FN: Convert (PUTMEM a b) to (SETQ (GETMEM a) b)
  %        so can see as ALM addressing mode
  `(setq (getmem ,a) ,b)
  )

(def-pass-1-macro    putword (a b c)
  `(wputv ,a ,b ,c)
  )

(def-pass-1-function quote (u vbls)
  u
  )

(def-pass-1-function setq (u vbls)
  % PA1FN: Convert (SETQ X1 Y1 X2 Y2 ...) to (SETQ X1 Y1) (SETQ X2 Y2)
  %        in a PROGN. Also check that Xi is a MEM mode or $NAME
  (prog (var fn exp ln)
        (setq ln (length (cdr u)))
        (when (neq ln 2)
          (return (progn
                    (setq ln (divide ln 2))
                    (if (neq (cdr ln) 0)
                      (progn
                        (&comperror 
                         (list "Odd number of arguments to SETQ" u))
                        (setq u (append u (list nil)))
                        (setq ln (plus (car ln) 1)))
                      (setq ln (car ln)))
                    (setq u (cdr u))
                    (for (from i 1 ln 1) 
                         (do (progn
                            (setq exp 
                             (cons (list 'setq (car u) (cadr u)) exp))
                            (setq u (cddr u)))))
                    (recursive-pass-1 (cons 'progn (reversip exp)) vbls))))
        %/ Should CHECK that CONST's not SETQ'ed or BOUND
	(setq var (cadr u))
	(cond
	  ((and (constant? var) (not (memq var vbls)))
	   (&compwarn (list "SETQ of constant" var))))
	(cond
	  ((not (idp var)) (setq var (recursive-pass-1 var vbls)))
	  ((non-local var) (setq var (list (non-local var) var)))
	  ((memq var vbls) (setq var (list '$local var)))
	  (t (setq var (make-non-local var))))
        (setq exp (recursive-pass-1 (caddr u) vbls))
        (setq u (list '$name var))
        %  scs
        (if (or (not (setq fn (get (car exp) 'memmodfn))) 
                (not (equal (lastcar exp) var)))
          (return (list 'setq u exp))
          (return (cons fn (cons u (reversip (cdr (reversip (cdr exp))))))))))

(def-pass-1-reform   wand u
  (assocop (cons 'wand u))
  )

(def-pass-1-function wconst (u vbls)
  u
  )

(def-pass-1-reform   wdifference u
  (groupop (cons 'wdifference u))
  )

(def-pass-1-macro    weq (a b)
  `(eq ,a ,b)
  )

(def-pass-1-reform   wminus u
  (groupop (cons 'wminus u))
  )

(def-pass-1-macro    wneq (a b)
  `(ne ,a ,b)
  )

(def-pass-1-reform   wnot u
  (groupop (cons 'wnot u)))

(def-pass-1-reform   wor u
  (assocop (cons 'wor u))
  )

(def-pass-1-macro    word (a b)
  `(wgetv ,a ,b)
  )

(def-pass-1-reform   wplus2 u
  (groupop (cons 'wplus2 u))
  )

(def-pass-1-reform   wtimes2 u
  % WTIMES2: does Power of 2 to WSHIFT conversion
  (let ((form    (assocop (cons 'wtimes2 u))) )
    (if (eqcar form 'wtimes2)
      (let ((arg1    (second form))
	    (arg2    (third form)))
	(cond 
	 ((and (constant? arg1) (powerof2p (constant-value arg1))) 
	  `(wshift ,arg2 (wconst ,(powerof2p (constant-value arg1)))))
	 ((and (constant? arg2) (powerof2p (constant-value arg2)))
	  `(wshift ,arg1 (wconst ,(powerof2p (constant-value arg2)))))
	 (t form)
	 ))
      form
      )))

(def-pass-1-reform   wxor u
  (assocop (cons 'wxor u))
  )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Support for algebraic operators.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de assocop (u)

  % For abelian semi-groups & monoids 
  % given an associative, communitive operation (TIMES2, AND, ...) collect all 
  % arguments, seperate constant args, evaluate true constants, check for zero's
  % and ones (0*X = 0, 1*X = X).  All constants that can be evaluated 
  % at this time are evalutated, and the operator is applied to them 
  % to reduce them to one constant.

  (let* ((operator    (first u))  % The associative operator being dealt with
	 (args        (assocop-flatten operator (rest u)))
	 (num         nil)        % Constants which can be evaluated now, condensed
	 (vars        nil)        % Non-constant arguments.
	 (tag         (result-tag operator))
	 )
    (for (in arg args)
	 (do
	  (if (integer-constant? arg)
	    (if num
	      (setf num (apply (get operator 'dofn) (list num (constant-value arg))))
	      (setf num (constant-value arg))
	      )
	    (setf vars (nconc vars (list arg)))
	    )))
    (cond
     ((and num (eq num (get operator 'zero))) (list tag num))
     ((null vars)                             (list tag num))
     ((null num)                              (insert-op operator vars))
     (t                                       (insert-op operator 
							 (cons (list tag num)
							       vars)))
     )))

(de assocop-flatten (op args)

  % ((plus a b) (plus c d)) => (a b c d)

  (for (in arg args)
       (join (if (and (pairp arg)
		      (eq (first arg) op))
	       (assocop-flatten op (rest arg))
	       (list arg)
	       ))))


(de insert-op (op l)

  % Insert OP into a list of operands as follows: INSOP(~,'(A B C D)) =
  % (~ (~ (~ A B) C) D)
  % Algorithm: Case for lists of arguments less that 2 is simple.
  % When there are 2 or more arguments, the first two are collected into
  % one, and the function recursively applied.

  (let ((len (length l)))
    (cond
     ((zerop len)      nil)
     ((onep len)       (first l))
     (t                (insert-op op (cons (list op
						 (first l)
						 (second l))
					   (rest (rest l)))))
     )))


(de groupop (u)

  % Like ASSOCOP, except inverses exist.  All operands are collected into a list
  % and tagged with POSITIVE or NEGATIVE.  Constants are then collected into
  % one, and the expression is rebuilt.

  (let* ((operator   (first u))
	 (fns        (get operator 'groupops))
	 (args       (get-group-args fns u nil))
	 (con        nil)
	 (tag        (result-tag operator)))

    (for (in arg args)
	 (do (when (integer-constant? (second arg))
	       (setf args (delete arg args))
	       (let ((value (if (eq (first arg) 'positive)
			      (constant-value (second arg))
			      (apply (get (third fns) 'dofn)
				     (list (constant-value (second arg)))))))
		 (if con
		   (setf con (apply (get (first fns) 'dofn) (list con value)))
		   (setf con value)
		   )))))
    (if (and con (equal con (get (first fns) 'zero)))
      (list tag con)
      (progn
       (when (and con (neq con (get operator 'one)))
	 (setf args (cons (list 'positive (list tag con))
			  args))
	 )
       (make-group-exp args fns)
       ))))
     
(de get-group-args (fns exp invflag)

  % Support for GROUP.  FNS are the functions that operate on the group:
  % (add subtract inverse).  EXP is the expression to process.  INVFLG is
  % true if the entire expression is to be inverted.  
  % Example:  (PLUS (MINUS 4) (DIFFERENCE X Y))
  % Becomes:  ((NEGATIVE 4) (POSITIVE X) (NEGATIVE Y))

  (let ((op   (first exp))
	(args (rest exp)))
    (for (in arg args)
	 (from position 1)
	 (join 
	  (if (and (pairp arg) (member (first arg) fns))
	    (get-group-args fns arg (subexp-inverted? op fns position invflag))
	    (list (list (if (subexp-inverted? op fns position invflag)
			  'NEGATIVE
			  'POSITIVE)
			arg))
	    )))))

(de subexp-inverted? (op fns position invflag)

  % Returns T if the subexpression in the given POSITION of OP should
  % be inverted.

  (xor invflag
       (cond ((eq op (first fns))    nil)               % Neither arg of + is inverted
	     ((eq op (second fns))   (eq position 2))   % Second arg of - is
	     ((eq op (third fns))    t)                 % The only arg of MINUS is
	     )))

(de make-group-exp (args fns)
 (if (null args) '(wconst 0)
  (let ((first-arg (first args)))
    (if (eq (first first-arg) 'negative)
      (setf first-arg (list 'positive (list (third fns) (second first-arg))))
      )
    (if (rest args)
      (make-group-exp
       (cons (list 'positive
		   (list (if (eq (first (second args)) 'negative)
			   (second fns)
			   (first fns))
			 (second first-arg)
			 (second (second args))
			 ))
	     (rest (rest args)))
       fns)
      (second first-arg)
      ))))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Assorted support functions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &mkprogn (u)
  % Makes implied PROGN's into explicit ones (as in COND)
  (if (or (null u) (cdr u))
    (cons 'progn u)
    (car u)))

(de eq-able? (u)
  % True if U is an object for which EQ can replace EQUAL
  (or (inump u) (idp u)))

(de eq-able-list? (u)
  % True if EQ-ABLE? is true of all elements of U
  (for (in x u)
       (always (eq-able? x))
       ))

(de eval-eq-able? (u)
  % True if (EVAL U) is an object for which EQ can replace EQUAL.
  % U is assumed to have been processed by pass 1.
  (and (constant? u)
       (eq-able? (constant-value u))
       ))

(de pass-1-map-do (list fcn carflag)
  % Support for MAP and MAPC processing.
  (when (eqcar fcn 'function)
    (let* ((tmp            (&gensym))
	   (function-name  (second fcn))
	   (function-arg   (if carflag `(car ,tmp) tmp)))
      `(prog (,tmp)
	 (setq ,tmp ,list)
	 looplabel
	 (cond ((atom ,tmp) (return nil)))
	 (,function-name ,function-arg)
	 (setq ,tmp (cdr ,tmp))
	 (go looplabel)
	 )
      )))


(de pass-1-map-collect (list fcn carflag)
  % Support for MAPLIST and MAPCAR
  (when (eqcar fcn 'function)
    (let* ((tmp            (&gensym))
	   (function-name  (second fcn))
	   (function-arg   (if carflag `(car ,tmp) tmp))
	   (result         (&gensym))
	   (endptr         (&gensym)))
      `(prog (,tmp ,result ,endptr)
	 (setq ,tmp ,list)
	 (cond ((atom ,tmp) (return nil)))
	 (setq ,result (setq ,endptr (ncons (,function-name ,function-arg))))
	 looplabel
	 (setq ,tmp (cdr ,tmp))
	 (cond ((atom ,tmp) (return ,result)))
	 (rplacd ,endptr (ncons (,function-name ,function-arg)))
	 (setq ,endptr (cdr ,endptr))
	 (go looplabel)
	 )
      )))

(de pass-1-map-conc (list fcn carflag)
  % Support for MAPLIST and MAPCAR
  (when (eqcar fcn 'function)
    (let* ((tmp            (&gensym))
	   (function-name  (second fcn))
	   (function-arg   (if carflag `(car ,tmp) tmp))
	   (result         (&gensym))
	   (endptr         (&gensym)))
      `(prog (,tmp ,result ,endptr)
	 (setq ,tmp ,list)
	 startover
	 (cond ((atom ,tmp) (return nil)))
	 (setq ,result (,function-name ,function-arg))
	 (setq ,endptr (lastpair ,result))
	 (setq ,tmp (cdr ,tmp))
	 (cond ((atom ,endptr) (go startover)))
	 looplabel
	 (cond ((atom ,tmp) (return ,result)))
	 (rplacd ,endptr (,function-name ,function-arg))
	 (setq ,endptr (lastpair ,endptr))
	 (setq ,tmp (cdr ,tmp))
	 (go looplabel)
	 )
      )))
      
(de pass-1-nths (list index fntable)
  % Support for PANTH and PNTH
  (when (integer-constant? index)
    (let ((as-pair (assoc (constant-value index) fntable)))
      (when as-pair
	(if (eq (cdr as-pair) 'NOOP)
	  list
	  (list (cdr as-pair) list)
	  )))))


(de pass-1-prog-body (u vbls)
  % Support, handle PROG body
  (for (in x u)
       (collect 
	(if (atom x)
	  x
	  (recursive-pass-1 x vbls)
	  ))))
