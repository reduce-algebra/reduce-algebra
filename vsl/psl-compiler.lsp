% This tries to build a PSL comopiler...

% For VSL the treatment of file-names written as "$xxx/..." is that a Lisp
% variable called "@xxx" is inspected to find the actual path required.

(setq @psl  "../psl/dist")

(setq @psys "../psl/dist/bin/AMD64_ext")

(setq @pl   "../psl/dist/lap/AMD64_ext")

(setq @pk   "../psl/dist/kernel")
(setq @pxk  "../psl/dist/kernel/AMD64_ext")

(setq @pnk  "../psl/dist/nonkernel")
(setq @pxnk "../psl/dist/nonkernel/AMD64_ext")
(setq @pnkl "../psl/dist/nonkernel/AMD64_ext/lap")

(setq @pc   "../psl/dist/comp")
(setq @pxc  "../psl/dist/comp/AMD64_ext")

(setq @pu   "../psl/dist/util")
(setq @pxu  "../psl/dist/util/AMD64_ext")

(setq @pdist   "../psl/dist/distrib")
(setq @pxdist  "../psl/dist/distrib/AMD64_ext")


(de stderror (msg)
  (error 99 msg))

(de exitlisp () (stop 0))

% copyd is invoked (botimes ..) within the for-macro.sl source file,
% but easy-non-sl.sl uses some macros defined in for-macro. To break the
% circularity I define copyd here.

(de copyd (new old)
  (prog (olddef)
        (setq olddef (getd old))
	(print olddef)
        (if (pairp olddef)
          (putd new (car olddef) (cdr olddef))
          (stderror (bldmsg "%r has no definition in CopyD" old)))
        (return new)))

(dm defun (u) (cons 'de (cdr u)))

(de codep (u) nil)

(de ncons (u) (cons u nil))

(de posintp (n) (and (fixp n) (geq n 0)))

(dm errorprintf (u)
  (list 'errorprintf1 (cadr u) (cons 'list (cddr u))))

(de errorprintf1 (fmt args)
  (terpri)
  (princ "+++ errorprintf ")
  (printf_internal fmt args)
  nil) 

(de remob (u)
  (terpri)
  (princ "+++ REMOB not performed on ")
  (print u)
  u)

% This definition of totalcopy is probably insufficient...
(de totalcopy (x)
  (copy x))

% This definition is from nonkernel/loop-macros.sl, but that file contains
% a definition of FOR that clashes with the version that I seem to need (which
% is in util/for-macro.sl).

(dm foreach (u)
  %. Macro for MAP functions
  %
  % From RLISP
  %
  % Possible forms are:
  % (foreach x in u do (foo x))	   --> (mapc u (function (lambda (x) (foo x))))

  % (foreach x in u collect (foo x)) --> (mapcar u ...)
  % (foreach x in u conc (foo x))	   --> (mapcan u ...)
  % (foreach x in u join (foo x))	   --> (mapcan u ...)
  % (foreach x on u do (foo x))	   --> (map u ...)
  % (foreach x on u collect (foo u)) --> (maplist u ...)
  % (foreach x on u conc (foo x))	   --> (mapcon u ...)
  % (foreach x on u join (foo x))	   --> (mapcon u ...)
  %
  (prog (action body fn lst mod var)
        (setq var (cadr u))
        (setq u (cddr u))
        (setq mod (car u))
        (setq u (cdr u))
        (setq lst (car u))
        (setq u (cdr u))
        (setq action (car u))
        (setq body (cdr u))
        (setq fn
              (cond ((eq action 'do) (if (eq mod 'in)
                       'mapc
                       'map))
                    ((or (eq action 'conc) (eq action 'join)) (if (eq mod
                                                                   'in)
                       'mapcan
                       'mapcon))
                    ((eq action 'collect) (if (eq mod 'in)
                       'mapcar
                       'maplist))
                    (t (stderror
                        (bldmsg "%r is an illegal action in ForEach"
                         action)))))
        (return (list fn lst
                      (list 'function
                       (cons 'lambda (cons (list var) body)))))))


(dm repeat (u)
  %
  % From RLISP
  % Form is (repeat exp1 ... expN bool)
  % Repeat until bool is true, similar to Pascal, etc.
  %
  (cons 'prog
        (cons 'nil
              (cons '$loop$
                    (foreach x on (cdr u) collect (if (null (cdr x))
                       (list 'cond (list (list 'not (car x)) '(go $loop$)))
                       (car x)))))))


% I will also want IFOR, but the other things defined in util/inum.sl would
% potentially clobber VSL versions of iplus etc.. so I lift the definition
% out to here.

(dm ifor (u)
  % U is of the form: (IFOR (FROM var start end step) (DO body))

  (let ((step (nth (second u) 5)))
    (if (fixp step)
      (constant-increment-ifor u)
      (variable-increment-ifor u)
      )))

(de variable-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (x         (list 'IDIFFERENCE finish var))
       (label1    (gensym))
       (label2    (gensym)))
    (unless (onep step)
      (setf x (list 'ITIMES2 step x))
      )
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((ILESSP ,x 0) (GO ,label2)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       ,label2
       )))

(de constant-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (comparison(if (minusp step) 'ILESSP 'IGREATERP))
       (label1    (gensym)))
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((,comparison ,var ,finish) (RETURN 0)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       )))


(de onoff* (u val)
  (foreach x in u do 
    (cond ((idp x) (set (intern (list2string (cons '!* (explode2 x)))) val)))))

(dm on (u)
   (terpri)
   (princ "+++ ON ")
   (print (cdr u))
   (list 'onoff* (mkquote (cdr u)) t))

(dm off (u)
   (terpri)
   (princ "+++ OFF ")
   (print (cdr u))
   (list 'onoff* (mkquote (cdr u)) nil))

(flag '(on off) 'ignore)

(de lap (u)
   (terpri)
   (princ "+++ LAP ")
   (print u)
   nil)

(dm imports (u)
   (terpri)
   (princ "+++ IMPORTS ")
   (print (cdr u))
   (evload u))

(dm putmem (u)
   (terpri)
   (princ "+++ PUTMEM ")
   (print (cdr u))
   nil)

(dm putbyte (u)
   (terpri)
   (princ "+++ PUTBYTE ")
   (print (cdr u))
   nil)

(dm put_a_halfword (u)
   (terpri)
   (princ "+++ PUT_A_HALFWORD ")
   (print (cdr u))
   nil)

(dm depositfunctioncelllocation (u)
   (terpri)
   (princ "+++ DEPOSITFUNCTIONCELLLOCATION")
   (print (cdr u))
   nil)

(dm int2id (u)
   (terpri)
   (princ "+++ INT2ID")
   (print (cdr u))
   (list 'int2id-internal (cadr u)))

(de int2id-internal (u)
  (cond ((equal u **nil-id-value**) nil)
        ((and (greaterp u -1) (lessp u 256)) (code-char u))
        (t 'unknown)))

(dm load (x)
  (terpri)
  (prin2 "++++ LOAD ")
  (prin (cdr x))
  (printc " called")
  (list 'evload (mkquote (cdr x))))

(de evload (x)
  (foreach u in x do (load1 u)))

(setq modules-loaded* nil)

(de load1 (u)
  (print u)
  (cond ((memq u modules-loaded*) nil)
        ((memq u '(fasl-decls hash-decls)) (dskin (string-concat "$pxk/" (string-concat (id2string u) ".sl"))))
%        ((memq u '(fast-vector)) (dskin (string-concat "$pu/" (string-concat (id2string u) ".sl"))))
  )
  (setq modules-loaded* (cons u modules-loaded*)))

(de unboundp (u) (not (boundp u)))

(de fboundp (u) (not (null (getd u))))

(de funboundp (u) (null (getd u)))

(de dskin (u) (rdf u))

(flag '(dskin) 'ignore)

(de pp (x) (prettyprint x))

(de string-concat (a b)
  (setq a (explode a))
  (setq b (explode b))
  (compress (append
    (reverse (cdr (reverse a)))
    (cdr b))))

%%%% This doesn't work,  as gtbps must return the address of the vector
%(de gtbps (n) (mkvect n))
(de gtbps (n) 47114711)

(de string-equal (x y) (equal x y))

(de channelprin2 (ch x)
   (let!* ((s (wrs ch)))
      (prog1
         (prin2 x)
         (wrs s))))

(de channelterpri (ch)
   (let!* ((s (wrs ch)))
      (prog1
         (terpri)
         (wrs s))))

(setq stringgensymcounter* 0)
(de stringgensym ()
  (let ((x (explode2 (setq stringgensymcounter* (plus2 stringgensymcounter* 1)))))
    (while (lessp (length x) 4)
      (setq x (cons '!0 x)))
    (compress (cons 'L x))))

(dm errset (u)
    (list 'errorset (list 'quote (cadr u))
	  (if (null (cddr u)) t (caddr u))
	  nil))

(de id2int (x) (print (list "ID2INT called on" x)) 4711)
(de id2int (x)
  (cond ((null x) **nil-id-value**)
        ((equal (length (explode2 x)) 1) (char-code (car (explode2 x))))
        (t 4711)))

(dm idloc (x)
  (cond ((null (cadr x)) **nil-id-value**)
        (t (findidnumber (cadr x))))) 

% converts a binary integer in a machine word into a lisp integer
(de int2sys (x) x)

(de sys2fixn (x) x)

% Functions that operate on machine words
% use integer functions for now
(de wshift (x y) (lshift x y))
(de wplus2 (x y) (plus2 x y))
(de wtimes2 (x y) (times2 x y))
(de wdifference (x y) (difference x y))
(de wgreaterp (x y) (greaterp x y))
(de wand (x y) (logand x y))
(de wor (x y) (logor x y))

(dm land (u) (cons 'logand (cdr u)))
(dm lor (u) (cons 'logor (cdr u)))

(dm string (u) (list 'list2string (cons 'list (cdr u))))

(dm putword (u)
    (cons 'wputv (cdr u)))

(de evectorp (x) nil)

(de bigp (u) (bignump u))
 
(de isizev (u) (size u))
(de igetv (a b) (indx a b))

(rdf "$pnk/lisp-macros.sl")

(rdf "$pu/defmacro1.sl")
(rdf "$pu/defmacro2.sl")
(rdf "$pu/set1-macros.sl")
(rdf "$pu/set2-macros.sl")
(rdf "$pu/iter-macros.sl")
(rdf "$pu/for-macro.sl")
(rdf "$pu/cond-macros.sl")

(rdf "$pnk/easy-non-sl.sl")
(rdf "$pnk/sets.sl")
%(rdf "$pnk/type-error.sl")

% $pu/if.sl defines an IF macro that uses symbols as keywords THEN, ELIF
% and ELSE. It is coded using the NEXT macro from $pnk/loop-macros.sl, but
% if I load that file then it gives a version of FOR that conflicts with
% $pu/for-macro.sl. So I will provide BEXT manually here - not that I think
% that use of it was a good idea!

(dm next (u)  % Continue Loop
  '(go $loop$))

(rdf "$pu/if.sl")

(rdf "$pu/if-system.sl")

% At least for bootstrapping I need to restore MY version of SPACES
(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

(de intp (x) (and (fixp x) (not (bignump x))))
(flag '(intp) 'lose)

(de flag1 (x y) (flag (list x) y))

(de remflag1 (x y) (remflag (list x) y))

(dm control (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))
(dm cntrl (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))

(de continuableerror (errnum message errorform*)
  (progn (errorprintf "***** %l" message)))

(de main ())

% The paths used here suppose that the current directory is the VSL
% one. This is a bit unsatisfactory at present.

(rdf "$pnk/carcdr.sl")
(rdf "$pnk/def-smacro.sl")
(rdf "$pnk/defconst.sl")
(rdf "$pnk/constants.sl")

(rdf "$pnk/eval-when.sl")

(dm bothtimes (x) (cons 'progn (cdr x)))
(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))

(rdf "$pc/datamachine.sl")
(rdf "$pc/pass-1.sl")
(rdf "$pc/pass-2-3.sl")
(rdf "$pc/pass-1-lap.sl")


(rdf "$pc/anyreg-cmac.sl")
(rdf "$pc/cmacros.sl")
(rdf "$pc/bare-psl.sym")
(rdf "$pc/big-faslend.sl")
(rdf "$pc/comasm.sl")
(rdf "$pc/p1-decls.sl")
(rdf "$pc/p-lambind.sl")
(rdf "$pc/predicates.sl")
(rdf "$pc/pslcomp.sl")
(rdf "$pc/putprint.sl")


(rdf "$pxc/compat.sl")
(rdf "$pxc/sys-consts.sl")
(rdf "$pxc/sys-dm.sl")
(rdf "$pxc/tags.sl")
(rdf "$pxc/AMD64-lap.sl")
(rdf "$pxc/AMD64-cmac.sl")
(rdf "$pxc/AMD64-comp.sl")
(rdf "$pc/faslout.sl")
(rdf "$pxc/AMD64-spec.sl")
%         (rdf "$pxc/carcdrnil.sl")
(rdf "$pxc/comp-decls.sl")
(rdf "$pxc/compiler.sl")
(rdf "$pxc/nbittab.sl")
(rdf "$pxc/neweq.sl")

% redefine as macros since VSL doesn't support functiosn with a variable number of arguments
(dm codeprintf (x) (cons 'fprintf (cons 'codeout* (cdr x))))
(dm dataprintf (x) (cons 'fprintf (cons 'dataout* (cdr x))))


(rdf "$pxc/unixAMD64-lap-to-asm.sl")
(rdf "$pxc/unixAMD64-asm.sl")

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

(preserve)

