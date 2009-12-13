%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:NUMERIC-OPS.SL
% Description:    Definitions of Numeric Operators with "Fast" Option
% Author:         Alan Snyder, Hewlett-Packard CRC
% Created:        7 January 1983 (based on the earlier Fast-Int module)
% Modified:       02-Oct-84 17:44:38 (Cris Perdue)
% Status:         Experimental (Do Not Distribute)
% Mode:           Lisp
% Package:        Utilities
% Runtime:        PL:USEFUL.B
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
% 02-Sep-87 (Leigh Stoller for Russ Fish)
%  Use IntLShift instead of WShift for right shift on the VAX.
% 02-Oct-84 16:40:22 (Cris Perdue)
%  Added fix to numeric-for-from-function like one already made
%  in pu:for-macro.sl so case where expression giving
%  termination value is NIL and the step is not a literal number
%  can work correctly.
% 1 May 1984 0945-PDT (Cris Perdue)
%  Added a non-open-coded definition for /=, which had been
%  omitted up to now.
% 6 Mar 1984 1731-PST (Nancy Kendzierski)
%  Changed "fast" interaction by renaming for-from-function to 
%  numeric-for-from-function and changing the property list of 'from
%  as fast-integers are enabled and disabled.
% 21-Mar-84 16:21:40 (Brian Beach)
%  Updated for new compiler model.  CMACRO properties changes to FAST-FUNCTION
%  properties.
% 19 Jan 1984 1445-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Edit by Cris Perdue, 19 Apr 1983 1417-PST
% Disable-fast-numeric-operators now remprops fast-plus and fast-times
%  as it should.
% Edit by Cris Perdue,  7 Mar 1983 1131-PST
% Redefined + and * to take any number of arguments.
% This involved defining exprs fast-plus and fast-times.
% Added an error check to - and /

% WARNING: + and * are no longer exprs.  Code using this module and COMPILED
% with the fast-integers switch set to NIL will not work until it is
% recompiled. /csp

% Note: This must be LOAD, not IMPORTS. /csp
(load useful)

% This file defines a set of C-like numeric operators that are a superset of the
% numeric operators defined by the Common Lisp compatibility package.

% The operators are:
%
%	=	Numeric Equal
%	/=	Numeric Not Equal (common lisp)
%	~=	Numeric Not Equal (CLU)
%	<	Numeric Less Than
%	>	Numeric Greater Than
%	<=	Numeric Less Than or Equal
%	>=	Numeric Greater Than or Equal
%	+	Numeric Addition
%	-	Numeric Minus or Subtraction
%	*	Numeric Multiplication
%	/	Numeric Division
%	//	Numeric Remainder
%	~	Integer Bitwise Logical Not
%	&	Integer Bitwise Logical And
%	|	Integer Bitwise Logical Or
%	^	Integer Bitwise Logical Xor
%	<<	Integer Bitwise Logical Left Shift
%	>>	Integer Bitwise Logical Right Shift

% +, -, *, and / are defined as in Common LISP, but when compiled they
% do open-coded arithmetic only, just like all the other operators.
% The arithmetic relational operators all take exactly 2 arguments,
% unlike the genuine Common LISP versions.

% The switch FAST-INTEGERS controls an option that provides for an efficient
% compiled implementation of these operators using Syslisp arithmetic.  When the
% switch is on, uses of these operators will compile into the corresponding
% Syslisp arithmetic operators, which generally are open-compiled and fast.
% However, the Syslisp operators perform machine arithmetic on untagged
% integers: they will work only if their inputs are untagged integers, and they
% produce untagged integer outputs.  The (undocumented) functions Int2Sys and
% Sys2Int can be used to convert between tagged Lisp integers and Syslisp
% integers; however, no conversion is needed to convert between INUMs and
% Syslisp integers within the valid range of INUMs.

% This module modifies the FOR macro to use the numeric operators to implement
% the FROM clause; thus, the FOR statement will use Syslisp arithmetic when the
% FAST-INTEGERS switch is on.

%
% The following functions are defined in the COMMON package:
%   =, <, >, <=, >=, +, -, *, /
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The Implementation:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(fluid '(*fast-integers))

% Macros for n-ary functions:

(de expand-operator-tree (op args)
  (if (equal (length args) 1)
    (first args)
    (expand-operator-tree
     op
     (cons (list op (first args) (second args))
	   (rest (rest args))
	   ))))

(defmacro + args
  (if (null args)
    0
    (expand-operator-tree 'fast-plus args)
    ))

(defmacro * args
  (if (null args)
    1
    (expand-operator-tree 'fast-times args)
    ))

(defmacro - args
  (cond
   ((null args)         (stderror "No args supplied to ""-"""))
   ((null (rest args))  `(fast-minus ,@args))
   (t                   (expand-operator-tree 'fast-difference args))
   ))

(defmacro / args
  (cond
   ((null args)         (stderror "No args supplied to ""/"""))
   ((null (rest args))  `(recip ,@args))
   (t                   (expand-operator-tree 'fast-quotient args))
   ))

% Function definitions for running interpretively:

(de = (a b) (eqn a b))
(de < (a b) (lessp a b))
(de > (a b) (greaterp a b))
(de <= (a b) (leq a b))
(de >= (a b) (geq a b))
(de ~= (a b) (not (eqn a b)))
(de /= (a b) (not (eqn a b)))
(de fast-plus (a b) (plus a b))
(de fast-times (a b) (times a b))
(de fast-minus (a) (minus a))
(de fast-difference (a b) (difference a b))
(de fast-quotient (a b) (quotient a b))
(de // (a b) (remainder a b))
(de ~ (a) (lnot a))
(de & (a b) (land a b))
(de | (a b) (lor a b))
(de ^ (a b) (lxor a b))
(de << (a b) (lshift a b))
(de >> (a b) (if_system VAX
			(intlshift a (minus b))
			(lshift a (minus b))))

% Compiler declarations for fast functions:

(put '=               'fast-function 'weq)
(put '/=              'fast-function 'wneq)
(put '~=              'fast-function 'wneq)
(put '<               'fast-function 'wlessp)
(put '>               'fast-function 'wgreaterp)
(put '<=              'fast-function 'wleq)
(put '>=              'fast-function 'wgeq)
(put 'fast-plus       'fast-function 'wplus2)
(put 'fast-difference 'fast-function 'wdifference)
(put 'fast-minus      'fast-function 'wminus)
(put 'fast-times      'fast-function 'wtimes2)
(put 'fast-quotient   'fast-function 'wquotient)
(put '//              'fast-function 'wremainder)
(put '~               'fast-function 'wnot)
(put '&               'fast-function 'wand)
(put '|               'fast-function 'wor)
(put '^               'fast-function 'wxor)
(put '<<              'fast-function 'wshift)
(put '>>              'fast-function 'wshift-right)

(put '=               'fast-flag  '*fast-integers)
(put '/=              'fast-flag  '*fast-integers)
(put '~=              'fast-flag  '*fast-integers)
(put '<               'fast-flag  '*fast-integers)
(put '>               'fast-flag  '*fast-integers)
(put '<=              'fast-flag  '*fast-integers)
(put '>=              'fast-flag  '*fast-integers)
(put 'fast-plus       'fast-flag  '*fast-integers)
(put 'fast-difference 'fast-flag  '*fast-integers)
(put 'fast-minus      'fast-flag  '*fast-integers)
(put 'fast-times      'fast-flag  '*fast-integers)
(put 'fast-quotient   'fast-flag  '*fast-integers)
(put '//              'fast-flag  '*fast-integers)
(put '~               'fast-flag  '*fast-integers)
(put '&               'fast-flag  '*fast-integers)
(put '|               'fast-flag  '*fast-integers)
(put '^               'fast-flag  '*fast-integers)
(put '<<              'fast-flag  '*fast-integers)
(put '>>              'fast-flag  '*fast-integers)

(defmacro wshift-right (num shift)
  `(wshift ,num (wminus ,shift))
  )
   

(put 'fast-integers 'simpfg '((T   (enable-fast-numeric-operators))
			      (NIL (disable-fast-numeric-operators))
			      ))

(de enable-fast-numeric-operators ()
  (put 'from 'for-function 'numeric-for-from-function)
  )

(de disable-fast-numeric-operators ()
  (put 'from 'for-function 'for-from-function)
  )

% Here we redefine the FROM clause of FOR statements:

(fluid '(for-vars* for-outside-vars* for-tests* for-prologue* for-conditions*
		   for-body* for-epilogue* for-result*))

(de numeric-for-from-function (clause)
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
		      (step-var `((+ ,var1 ,step-var)))
		      ((zerop step) nil)
		      ((onep step) `((+ ,var1 1)))
		      ((eqn step -1) `((- ,var1 1)))
		      (t `((+ ,var1 ,step))))))
    (if fin-var (tconc for-vars* `(,fin-var ,fin)))
    (if step-var (tconc for-vars* `(,step-var ,step)))
    (cond ((null fin))
	  (step-var
	   (tconc for-tests* `(if (< ,step-var 0)
				(< ,var1 ,(or fin-var fin))
				(> ,var1 ,(or fin-var fin)))))
	  ((minusp step) (tconc for-tests* `(< ,var1 ,(or fin-var fin))))
	  (t (tconc for-tests* `(> ,var1 ,(or fin-var fin)))))))

% End of file.
