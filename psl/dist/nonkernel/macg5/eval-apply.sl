%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EVAL-APPLY.SL 
% Title:        Function calling mechanism 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     31-May-84 10:45:42 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compile to:   PNKL:EVAL-APPLY.B 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
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
  (flag '(lambdaevalapply lambdaapply eval-aux) 'internalfunction))

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
			(lambdaapply (get fn '*lambdalink) args)))
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
			(bldmsg "%r is an uundefined function" fn)
			(cons fn (foreach x in args collect (mkquote x))))))
    (setq stackmarkforbacktrace (mkbtr (inf fn)))
    (setq result (if (fcodep fn)
			(codeapply (getfcodepointer fn) args)
			(lambdaapply (get fn '*lambdalink) args)))
    (return result)))

(commentoutcode de eval (u)
   (prog (v)
     (case (tag u)
        ((id-tag) (if (or (null u)
                      (not (eq unbound-tag (tag (setq v (symval (inf u)))))))
                             (return v)
                             (return (valuecell u))))
        ((pair-tag) (return (eval-aux u)))
        ((0 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23
          24 25 26 27 28 29 31)   (return u))  % not id or atom
) ))

(lap '((*ENTRY EVAL EXPR 1) 
	(SRL (REG 1) 27 (REG 5)) 
	(SLL (REG 5) 3 (REG T5)) 
	(MOVE-RELOCATABLE-OBJECT "L0010" (REG T1)) 
	(JMPL (DISPLACEMENT (REG T1) (REG T5)) (REG 0)) 
	(MOV (REG 1) (REG 3))
     "L0010" 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(BA (INTERNALENTRY EVAL-AUX)) (NOP)
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
	(BA G0145) (SUBCC (REG 3) (REG NIL) (REG G0)) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP) 
      G0145 
	(BE!,A G0147) (MOV (REG 3) (REG 1)) 
	(ANDN (REG 3) (REG I5) (REG 1)) 
	(LD (INDEXED (REG G7) -116) (REG T5))
	(SLL (REG 1) 2 (REG 1)) 
	(LD (DISPLACEMENT (REG 1) (REG T5)) (REG 2)) 
	(SRL (REG 2) 27 (REG 1)) 
	(SUBCC (REG 1) 29 (REG G0)) 
	(BE!,A (ENTRY VALUECELL)) (MOV (REG 3) (REG 1)) 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (MOV (REG 2) (REG 1)) 
      G0147 
	(JMPL (DISPLACEMENT (REG 15) 8) (REG 0)) (NOP)))

(fluid '(symget lambda-link-address undefined-function-address))

(de eval-aux (u)
  % Interpret S-Expression as program
    (prog (fn)
      (setq fn (car u))
      (return
	 (cond ((idp fn)   % (funboundp fn)
		(if (eq (symfnc (idinf fn)) undefined-function-address)
			(continuableerror 1300
			  (bldmsg "%r is an uuundefined function" fn) u)
			(prog (fntype stackmarkforbacktrace result)
			%  (setq fntype (get fn 'type))  % getfntype
			  (setq fntype (wgetv symget (idinf fn)))
			  (when fntype
			    (setq fntype (wgetv (inf fntype) 1)))
			% TYPE is put into element 0 of the SYMGET slot
			% vector (if any)
			  (setq stackmarkforbacktrace (mkbtr (inf fn)))
			  (setq result
			    (cond ((null fntype) % must be an EXPR
				%   (if (fcodep fn)
				   (if (and
					(not (eq (symfnc (idinf fn)) 
						undefined-function-address))
					(not (eq (symfnc (idinf fn))
						lambda-link-address)))
				     (codeevalapply
					(mkcode (wplus2 symfnc 
						  (wtimes2 (idinf fn)
					    addressingunitsperfunctioncell)))
						%(getfcodepointer fn) 
					(cdr u))
				     (lambdaevalapply
				      (get fn '*lambdalink) (cdr u))))
				  ((equal fntype 'fexpr)
				   (idapply fn (list (cdr u))))
				  ((equal fntype 'nexpr)
				   (idapply fn (list (evlis (cdr u)))))
				  ((equal fntype 'macro)
				   (eval (idapply fn (list u))))
				  (t
				   (continuableerror 1301
				     (bldmsg "Unknown function type %r"
						      fntype)
						     u))))
			  (return result))))
	    ((codep fn) (codeevalapply fn (cdr u)))
	    ((and (pairp fn) (equal (car fn) 'lambda))
	     (lambdaevalapply fn (cdr u)))
	    (t
	     (continuableerror 1302
		 (bldmsg "Ill-formed expression in Eval %r" u) u))))))

