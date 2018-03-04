% Redefine a couple of functions that do not work out of the box

(de printexpression (x)
  ((lambda (expressioncount*)
     (prog (hd tl fn)
	   (setq x (resolvewconstexpression x))
 	   (cond ((or (numberp x) (stringp x)) (prin2 x))
		 ((idp x) (prin2 (findlabel x)))
		 ((atom x) 
		  (errorprintf "***** Oddity in expression %r" x) 
		  (prin2 x))
		 (t
		  (setq hd (car x)) (setq tl (cdr x)) 
		  (cond
		   ((setq fn (get hd 'binaryasmop))
		    (when (greaterp expressioncount* 0)
			  (prin2 asmopenparen*))
		    (printexpression (car tl)) (prin2 fn) 
		    (printexpression (cadr tl))
		    (when (greaterp expressioncount* 0)
			  (prin2 asmcloseparen*)))
		   ((setq fn (get hd 'unaryasmop)) (prin2 fn) 
		    (printexpression (car tl)))
		   ((setq fn (get hd 'asmexpressionformat)) 
		    (apply 'printf_internal
			   (list fn 
				 (foreach y in tl collect 
					  (list 'printexpression
						(mkquote y))))))
		   ((and (setq fn (getd hd)) 
			 (equal (car fn) 'macro))
		    (printexpression (apply (cdr fn) (list x))))
		   ((setq fn (get hd 'asmexpressionfunction)) 
		    (apply fn (list x)))
		   (t 
		    (errorprintf "***** Unknown expression %r" 
				 x)
		    (printf "*** Expression error %r ***" x)))))))
   (plus expressioncount* 1)))

(de size (x) 
  (cond ((stringp x) (difference (length (explodec x)) 1))
        ((vectorp x) (upbv x))
        ((bignump x) (difference (length (cdr x)) 1))
        (t nil)))

(de indx (s n)
  (cond ((stringp s) (char-code (nth (explodec s) (plus2 n 1))))
        (t nil)))

(de intp (x) (and (fixp x) (not (bignump x))))

(de sunsymbolp (x)
   (setq x (explodec x))
   (prog nil
     lbl
     (cond ((null x) (return t))
           ((not (or (liter (car x)) (eq (car x) '!_))) (return nil)))
     (setq x (cdr x))
     (go lbl)))

(de asm-char-downcase (c)
    (if (and (leq 65 c) (leq c 90))
	(plus c 32)
      x)))

(de auxaux (i)
  (list2string (list (code-char i))))

(dm codeprintf (x) (cons 'fprintf (cons 'codeout* (cdr x))))
(dm dataprintf (x) (cons 'fprintf (cons 'dataout* (cdr x))))

(def-pass-1-macro Char (u)
%. PSL Character constant macro
  (DoChar U))

% Table driven char macro expander
(de DoChar (u)
  (cond
    ((idp u) (or
               (get u 'charvalue) 
               ((lambda (n) (cond ((lessp n 128) n))) (id2int u))
               (CharError u)))
    ((pairp u) % Here's the real change -- let users add "functions"
      ((lambda (fn)
         (cond 
           (fn (apply fn (list (dochar (cadr u)))))
           (t (CharError u))))
       (cond ((idp (car u)) (get (car u) 'char-prefix-function)))))
    ((and (fixp u) (geq u 0) (leq u 9)) (plus u 48))  % 48 = (char 0)
    (t (CharError u))))

(de CharError (u)
  (ErrorPrintF "*** Unknown character constant: %r" u)
  0)


% This is needed for ASM generation, see $pxk/main-start.sl
(put 'symnam 'symbol 'symnam)
(put 'symfnc 'symbol 'symfnc)
(put 'symget 'symbol 'symget)
(put 'symval 'symbol 'symval)
(put 'symprp 'symbol 'symprp)

(setq toploopeval* 'eval)
 
(setq **nil-id-value** 128)

(dm idloc (x)
  (cond ((null (cadr x)) **nil-id-value**)
        (t (findidnumber (cadr x)))))

%(de idloc (x)
%  (if (null x) **nil-id-value**
%    (errorprintf "idloc called with %w%n" x)))

% For utterly cross building I may fudge some things...
%(de mkitem (tag data) (list 'list ''tagged tag data))

%(de OperandPrintIndirect (x)            % (Indirect x)
%  (progn (setq x (cadr x)) 
%         (if (regp x) (progn
%                        (prin2 "(")
%                        (PrintOperand x) 
%                        (Prin2 ")"))
%               (prin2 "*")
%               (PrintOperand x)
%               (prin2 "         / ")
%	       (prin1 x)
%               (Prin2 "")) 
%))
%
%
%(de asmprintvaluecell (x)
%  (printexpression (list 'plus2 'symval 
%                         (list 'times (compiler-constant 'addressingunitsperitem) 
%                          (list 'idloc (cadr x)))))
%  (princ "     / ")
%  (prin1 x))

(flag '(evload) 'ignore)
