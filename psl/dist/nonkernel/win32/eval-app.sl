%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EVAL-APPLY.SL 
% Title:        Function calling mechanism 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     31-May-84 10:45:42 (Brian Beach) 
% Mode:         Lisp 
% Package:      Kernel 
% Compile to:   PNKL:EVAL-APPLY.B 
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
%  15-Oct-92(Herbert Melenk)
%   386 provision for backtrace tag to be generated
%  1-Oct-88 (Tony Hearn)
%   Replaced single call of getfntype by (get fn 'type) so that putd-getd
%   module not needed to execute this module.
% 31-May-84 10:43:21 (Brian Beach)
%  Calls on IDAPPLY1 --> IDAPPLY.
% 29-Mar-84 13:50:04 (Mike Creech)
%   Added IDAPPLY for use when compiler does not optimize to opencode or when
%   interpreting.
% 01-Dec-83 14:42:43 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
  (flag '(lambdaevalapply lambdaapply) 'internalfunction))

(de lambdaevalapply (fn args)
  % Fn is Lambda, Args to be Evaled
  (if (not (and (pairp fn) (weq (car fn) 'lambda)))
    (continuableerror '1103 '"Ill-formed function expression"
		      (cons fn args))
    (prog (n result)
	  (setq n (bindeval (cadr fn) args))
	  % hand-coded, bind formals to evlis args
	  (when (weq n -1)
	    (return (continuableerror '1203 '"Argument number mismatch"
		     (cons fn args))))
	  (setq result (evprogn (cddr fn)))
	  (when (wneq n 0)
	    (unbindn n))
	  (return result))))

(de lambdaapply (fn args)
  % Fn is Lambda, unevaled Args
  (if (not (and (pairp fn) (weq (car fn) 'lambda)))
    (continuableerror '1104 '"Ill-formed function expression"
		      (cons fn (foreach x in args collect (mkquote x))))
    (prog (formals n result)
	  (setq formals (cadr fn))
	  (setq n 0)
	  (while (and (pairp formals) (pairp args))
	    (lbind1 (car formals) (car args))
	    (setq formals (cdr formals))
	    (setq args (cdr args))
	    (setq n (wplus2 n 1)))
	  (when (or (pairp formals) (pairp args))
	    (return (continuableerror '1204 '"Argument number mismatch"
		     (cons fn (foreach x in args collect (mkquote x))))))
	  (setq result (evprogn (cddr fn)))
	  (when (wneq n 0)
	    (unbindn n))
	  (return result))))

% Apply differs from the Standard Lisp Report in that functions other
% than EXPRs are allowed to be applied, the effect being the same as
% Apply(cdr GetD Fn, Args)

(de apply (fn args)
  % Indirect function call
  (cond ((idp fn)
	 (prog (stackmarkforbacktrace result)
	       (when (funboundp fn)
		 (return (continuableerror 1002
			  (bldmsg "%r is an undefined function" fn)
			  (cons fn (foreach x in args collect (mkquote x))))))
	       (setq stackmarkforbacktrace (mkbtr (inf fn)))
	       (setq result (if (fcodep fn)
		       (codeapply (getfcodepointer fn) args)
		       (lambdaapply (get fn '*lambdalink) args
			 stackmarkforbacktrace)))
	       (return result)))
	((codep fn) (codeapply fn args))
	((and (pairp fn) (equal (car fn) 'lambda)) (lambdaapply fn args))
	(t (continuableerror 1102 "Ill-formed function expression"
	    (cons fn (foreach x in args collect (mkquote x)))))))

(de idapply (fn args)

  % This is equivalent to APPLY but 'fn' must be an id.
  % Sometimes calls to this function are optimized by the compiler
  % to open code (i.e., this function is not called).

  (prog (stackmarkforbacktrace result)
    (unless
	   (idp fn)
	   % THEN We have an error.
	   (continuableerror 1102 "Ill-formed function expression"
			     (cons fn (foreach x in args collect (mkquote x)))))
    (when (funboundp fn)
      (return (continuableerror 1002
				(bldmsg "%r is an undefined function" fn)
				(cons fn (foreach x in args collect (mkquote x))))))
    (setq stackmarkforbacktrace (mkbtr (inf fn)))
    (setq result (if (fcodep fn)
		   (codeapply (getfcodepointer fn) args)
		   (lambdaapply (get fn '*lambdalink) args
		       stackmarkforbacktrace)))
    (return result)))

(de eval (u)
  % Interpret S-Expression as program
  (if (not (pairp u))
    (if (not (idp u))
      u
      (valuecell u))
    (prog (fn)
      (setq fn (car u))
      (return (cond ((idp fn) (if (funboundp fn)
				(continuableerror 1300
						  (bldmsg "%r is an undefined function" fn) u)
				(prog (fntype stackmarkforbacktrace result)
				  (setq fntype (get fn 'type))  % getfntype
				  (setq stackmarkforbacktrace
				    (mkbtr (inf fn)))
				  (setq result
				    (cond ((null fntype) % must be an EXPR
					   (if (fcodep fn)
					     (codeevalapply
					      (getfcodepointer fn) (cdr u))
					     (lambdaevalapply
					      (get fn '*lambdalink) (cdr u)
						stackmarkforbacktrace)))
					  ((equal fntype 'fexpr)
					   (idapply fn (list (cdr u))))
					  ((equal fntype 'nexpr)
					   (idapply fn (list (evlis (cdr u)))))
					  ((equal fntype 'macro)
					   (eval (idapply fn (list u))))
					  (t
					   (continuableerror 1301
							     (bldmsg
							      "Unknown function type %r"
							      fntype)
							     u))))
				  (return result))))
		    ((codep fn) (codeevalapply fn (cdr u)))
		    ((and (pairp fn) (equal (car fn) 'lambda))
		     (lambdaevalapply fn (cdr u)))
		    (t
		     (continuableerror 1302
				       (bldmsg "Ill-formed expression in Eval %r" u) u)))))))

