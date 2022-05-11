%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC:LAP-TO-ASM.SL
% Title:          LAP to assembler translator
% Author:         Eric Benson
% Created:        13 August 1981
% Modified:       15-Jan-85 11:00 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Compiler
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
% 20-Dec-86 (Leigh Stoller)
%  Wrapped printexpressionform* in a copy so that it ends up in the heap.
%  Cannot do destructive operations into bps if we want to move the
%  text/data boundry in unexec.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(semic* *comp *plap dfprint* charactersperword 
		 addressingunitsperitem addressingunitsperfunctioncell 
		 inputsymfile* outputsymfile* codeout* dataout* 
		 initout* !; codefilenameformat* datafilenameformat* 
		 initfilenameformat* modulename* uncompiledexpressions* 
		 nextidnumber* orderedidlist* nilnumber*
		 *mainfound % Main entry point found /csp
		 *main % Compiling "main" module (MAIN.RED) /csp           
		 *declarebeforeuse mainentrypointname* entrypoints* 
		 locallabels* codeexternals* codeexporteds* 
		 dataexternals* dataexporteds* 
		 externaldeclarationformat* exporteddeclarationformat* 
		 labelformat* fullwordformat* doublefloatformat* 
		 reservedatablockformat* reservezeroblockformat* 
		 undefinedfunctioncellinstructions* 
		 definedfunctioncellformat* printexpressionform* 
		 printexpressionformpointer* commentformat* 
		 numericregisternames* expressioncount* asmopenparen* 
		 asmcloseparen* tobecompiledexpressions* 
		 fasl-preeval*
		 ))

% Default values; set up if not already initialized.                       
(when (null inputsymfile*)
  (setq inputsymfile* "psl.sym"))

(when (null outputsymfile*)
  (setq outputsymfile* "psl.sym"))

(when (null initfilenameformat*)
  (setq initfilenameformat* "%w.init"))

(de dfprintasm (u)
  % Called by top-loop, dskin, dfprint to compile a single form.
  (funcall dfprint* u))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Special cases for ASMOUT:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(put 'de 'asmpreeval
     (function (lambda (u loadtime?) (fasl-define u 'expr loadtime?))))
(put 'df 'asmpreeval
     (function (lambda (u loadtime?) (fasl-define u 'fexpr loadtime?))))
(put 'dm 'asmpreeval
     (function (lambda (u loadtime?) (fasl-define u 'macro loadtime?))))
(put 'dn 'asmpreeval
     (function (lambda (u loadtime?) (fasl-define u 'nexpr loadtime?))))
(put 'loadtime 'asmpreeval
     (function (lambda (u loadtime?) (fasl-form (cadr u) T))))
(put 'startuptime 'asmpreeval
     (function (lambda (u loadtime?) (saveforcompilation (cadr u)))))
(put 'progn 'asmpreeval
     (function (lambda (u loadtime?)
		 (foreach x in (cdr u) do (fasl-form x loadtime?)))))

% do it now                                                                
(de asmpreevalsetq (u loadtime?)
  (let ((x   (second u))
	(val (third u)))
    (cond ((or (constantp val) (equal val t))
	   (findidnumber x) 
	   (put x 'initialvalue val)
	   nil)
	  ((null val)
	   (findidnumber x) 
	   (remprop x 'initialvalue) 
	   (flag (list x) 'nilinitialvalue)
	   nil)
	  ((eqcar val 'quote)
	   (findidnumber x) 
	   (setq val (cadr val))
	   (if (null val)
	     (progn (remprop x 'initialvalue)
		    (flag (list x) 'nilinitialvalue))
	     (put x 'initialvalue val))
	   nil)
	  ((or (and (idp val) (get val 'initialvalue)) 
	       (flagp val 'nilinitialvalue))
	   (if (setq val (get val 'initialvalue))
	     (put x 'initialvalue val)
	     (flag (list x) 'nilinitialvalue)))
	  (t (saveuncompiledexpression u))
	  )))

% just check simple cases, else return                                     
(put 'setq 'asmpreeval 'asmpreevalsetq)

(de asmpreevalputd (u loadtime?)
  (saveuncompiledexpression (checkforeasysharedentrypoints u)))

(de checkforeasysharedentrypoints (u)
  %                                                                        
  % looking for (PUTD (QUOTE name1) xxxx (CDR (GETD (QUOTE name2))))       
  %                                                                        
  (prog (nu nam exp)
	(setq nu (cdr u))
	(setq nam (car nu))
	(if (equal (car nam) 'quote)
	  (setq nam (cadr nam))
	  (return u))
	(setq nu (cdr nu))
	(setq exp (cadr nu))
	(unless (equal (car exp) 'cdr)
	  (return u))
	(setq exp (cadr exp))
	(unless (equal (car exp) 'getd)
	  (return u))
	(setq exp (cadr exp))
	(unless (equal (car exp) 'quote)
	  (return u))
	(setq exp (cadr exp))
	(findidnumber nam)
	(put nam 'entrypoint (findentrypoint exp))
	(unless (equal (car nu) ''expr)
	  (return (list 'put ''type (car nu))))
	(return nil)))

(put 'putd 'asmpreeval 'asmpreevalputd)

(de asmpreevalfluidandglobal (u loadtime?)
  (when (eqcar (cadr u) 'quote)
    (flag (cadr (cadr u)) 'nilinitialvalue))
  (saveuncompiledexpression u))

(put 'fluid 'asmpreeval 'asmpreevalfluidandglobal)

(put 'global 'asmpreeval 'asmpreevalfluidandglobal)

(de asmpreevallap (u loadtime?)
  (if (eqcar (cadr u) 'quote)
    (asmoutlap (cadr (cadr u)))
    (saveuncompiledexpression u)))

(put 'lap 'asmpreeval 'asmpreevallap)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ASMOUT and friends:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de saveuncompiledexpression (u)
  (when (pairp u)
    (prog (oldout)
	  (setq oldout (wrs initout*))
	  (print u)
	  (wrs oldout))))

(setq tobecompiledexpressions* (cons nil nil))

(de saveforcompilation (u)
  (cond ((or (atom u) (member u (car tobecompiledexpressions*))) nil)
	((equal (car u) 'progn) 
	 (foreach x in (cdr u) do (saveforcompilation x)))
	(t (tconc tobecompiledexpressions* u))))

(de asmout (fil)
  (prin2t "ASMOUT: IN files; or type in expressions")
  (prin2t "When all done execute ASMEND;")
  (setq modulename* fil)

  % Open the CODE output file, setting the line length large, and adding the header.

  (setq codeout* (open (bldmsg codefilenameformat* modulename*) 'output))
  (let ((oldout (wrs codeout*)))
    (linelength 1000)
    (wrs oldout)
    )
  (codefileheader)

  % Open the DATA output file, setting the line length large, and adding the header.

  (setq dataout* (open (bldmsg datafilenameformat* modulename*) 'output))
  (let ((oldout (wrs dataout*)))
    (linelength 1000)
    (wrs oldout)
    )
  (datafileheader)

  % Open the INIT output file.

  (setq initout* (open (bldmsg initfilenameformat* modulename*) 'output))

  (readsymfile)
  (setq dfprint* 'dfprintfasl)
  (remd 'oldlap)
  (copyd 'oldlap 'lap)
  (remd 'lap)
  (copyd 'lap 'asmoutlap)
  (setq *defn t)
  (setf fasl-preeval* 'asmpreeval)
  (setf *constants-for-compiler* t)
  (setq semic* '!$) % to turn echo off for IN
  (when (or (string-equal modulename* "main") *main)
    (setq *main t)
    ))

(de asmend ()
  (if *mainfound
    (progn (compileuncompiledexpressions)
	   (initializesymboltable))
    (writesymfile))
  (codefiletrailer)
  (close codeout*)
  (datafiletrailer)
  (close dataout*)
  (close initout*)
  (remd 'lap)
  (copyd 'lap 'oldlap)
  (setq dfprint* nil)
  (setq *defn nil)
  (setf *constants-for-compiler* nil)
  )

(flag '(asmend) 'ignore)

(de compileuncompiledexpressions ()
  (dfprintasm (list 'de 'initcode 'nil 
		    (cons 'progn (car tobecompiledexpressions*)))))

(de readsymfile ()
  (lapin inputsymfile*))

(de writesymfile ()
  (prog (newout oldout)
	(setq oldout (wrs (setq newout (open outputsymfile* 'output))))
	(print (list 'saveforcompilation 
		     (mkquote 
		      (cons 'progn (car tobecompiledexpressions*)))))
	(saveidlist)
	(setqprint 'nextidnumber*)
	(setqprint 'stringgensym*)
	(mapobl (function putprintentryandsym))
	(wrs oldout)
	(close newout)))

(de saveidlist ()
  (print (list 'setq 'orderedidlist* (mkquote (car orderedidlist*))))
  (print '(setq orderedidlist* 
		(cons orderedidlist* (lastpair orderedidlist*)))))

(de setqprint (u)
  (print (list 'setq u (mkquote (eval u)))))

(de putprint (x y z)
  (print (list 'put (mkquote x) (mkquote y) (mkquote z))))

% putprintentryandsym contols what is rewritten into the symbol file
% from the current propertylists.
(de putprintentryandsym (x)
  (prog (y)
	(when (setq y (get x 'entrypoint))
	  (putprint x 'entrypoint y))
	(when (setq y (get x 'symbol))
	  (putprint x 'symbol y))
	(when (setq y (get x 'idnumber))
	  (putprint x 'idnumber y))
	(when (flagp x 'internalsymbol) 
	       (print (list 'flag1 (mkquote x) ''internalsymbol)))
	(when (flagp x 'exportedsymbol) 
	       (print (list 'flag1 (mkquote x) ''exportedsymbol)))
	(when (flagp x 'externalsymbol) 
	       (print (list 'flag1 (mkquote x) ''externalsymbol)))
	(cond ((setq y (get x 'initialvalue)) (putprint x 'initialvalue y))
	      ((flagp x 'nilinitialvalue) 
	       (print (list 'flag (mkquote (list x)) ''nilinitialvalue))))
))

(de findidnumber (u)
  (prog (i)
	(return (cond ((leq (setq i (id2int u)) 128) i)
		      ((setq i (get u 'idnumber)) i)
		      (t (put u 'idnumber (setq i nextidnumber*)) 
			 (setq orderedidlist* (tconc orderedidlist* u)) 
			 (setq nextidnumber* (plus nextidnumber* 1)) i)))))

(setq orderedidlist* (cons nil nil))

(setq nextidnumber* 256)

(de initializesymboltable ()
  (let ((maxsymbol (compiler-constant 'maxsymbols)) olddataout)
    (when (lessp maxsymbol nextidnumber*)
      (errorprintf "*** MaxSymbols %r is too small; at least %r are needed"
		   maxsymbol nextidnumber*)
      (setq maxsymbol (plus nextidnumber* 100)))
    (flag '(nil) 'nilinitialvalue)
    (put 't 'initialvalue 't)
    (setq nilnumber* (compileconstant nil))
    (setq olddataout dataout*)
    (setq dataout* (open "S_VA_FN.asm" 'output))
    (dataalignfullword)
    (initializesymval)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymfnc)
    (datareservefunctioncellblock
     (plus (difference maxsymbol nextidnumber*) 1))
    (close dataout*)
    (setq dataout* (open "S_PR_NA.asm" 'output))
    (initializesymprp)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymnam)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (dataprintf "  DD %w DUP (?) %n" (times2 4 maxsymbol))
    (close dataout*)
    (setq dataout* olddataout)
%   (initializesymget)   % SYMGET feature
%   (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
%    (dataalignfullword)
%    (dataprintgloballabel (findgloballabel 'nextsymbol))
%    (dataprintfullword nextidnumber*)
    ))

(de initializesymprp ()
  % init prop lists                                                        
  (dataprintgloballabel (findgloballabel 'symprp))
  (for (from i 0 128 1) (do (initsymprp1 (int2id i))))
  (for (from i 129 255 1) (do (initsymprp1 (int2id 0))))
  (foreach x in (car orderedidlist*) do (initsymprp1 x)))

(de initsymprp1 (x) (dataprintfullword nilnumber*))

(de auxaux (i)
  (prog (j)
    (setq j (gtstr 0))
    (putstrbyt j 0 i)
    (return (mkstr j))
 ))

(de initializesymnam (maxsymbol)
  (dataprintgloballabel (findgloballabel 'symnam))
  (for (from i 0 128 1) 
       (do (dataprintfullword (compileconstant (id2string (int2id i))))))
  (for (from i 129 255 1)
       (do (dataprintfullword (compileconstant (auxaux i)))))
  (for (in idname (car orderedidlist*))
       (do  (dataprintfullword (compileconstant (id2string idname))))
       ))
 
(de initializesymget ()
  (dataprintgloballabel (findgloballabel 'symget))
  (for (from i 0 255 1) (do
			      (dataprintfullword nilnumber*)))
  (foreach x in (car orderedidlist*) do
			      (dataprintfullword nilnumber*))
  )
 
(de initializesymval ()
  (dataprintgloballabel (findgloballabel 'symval))
  (for (from i 0 128 1) (do (initsymval1 (int2id i))))
  (for (from i 129 255 1) (do
      (dataprintfullword
              (list 'mkitem (compiler-constant 'unbound-tag)  i))))
  (foreach x in (car orderedidlist*) do (initsymval1 x)))

(de initsymval1 (x)
  (prog (val)
% now decide what to plant in value cell at compiletime.
	(return (dataprintfullword 
		 (cond 
		       ((eq x 'nextsymbol) nextidnumber*)
% print the corresponding symbol for the valuecell with label, and external declaration.
		       ((flagp x 'externalsymbol)
			  (setq val (get x 'symbol))
%                         (datadeclareexternal val)
			  val)
% print the corresponding symbol for the valuecell with label, and exported declaration.
		       ((flagp x 'exportedsymbol)
			  (setq val (get x 'symbol))
			  (datadeclareexported val)
			  (dataprintlabel val)
			  (list 'mkitem (compiler-constant 'unbound-tag) 
			    (findidnumber x)))
% print internal references for symnam, symfnc, symval, symprp.
		       ((flagp x 'internalsymbol)
			  (setq val (get x 'symbol))
			  val)
% print the initial value.
		       ((setq val (get x 'initialvalue)) 
			(compileconstant val))
% print the value of nil.
		       ((flagp x 'nilinitialvalue) nilnumber*)
% print the unbound variable value.
		       (t 
			(list 'mkitem (compiler-constant 'unbound-tag) 
			 (findidnumber x))))))))

(de initializesymfnc ()
  (dataprintgloballabel (findgloballabel 'symfnc))
  (for (from i 0 255 1) (do (initsymfnc1 (int2id i))))
  (foreach x in (car orderedidlist*) do (initsymfnc1 x)))

(de initsymfnc1 (x)
  (prog (ep)
	(setq ep (get x 'entrypoint))
	(if (null ep)
	  (dataprintundefinedfunctioncell)
	  (dataprintdefinedfunctioncell ep))))

(de asmoutlap (u)
  (prog (locallabels* oldout)
	(setq u (pass1lap u))
	% Expand cmacros, quoted expressions                               
	(codeblockheader)
	(setq oldout (wrs codeout*))
	(foreach x in u do (asmoutlap1 x))
	(wrs oldout)
	(codeblocktrailer)))

(de asmoutlap1 (x)
  (prog (fn)
	(return (cond ((stringp x) (printlabel x))
		      ((atom x) (printlabel (findlocallabel x)))
		      ((setq fn (get (car x) 'asmpseudoop)) 
		       (apply fn (list x)))
		      (t
		       % instruction output form is:
      % "space" <opcode> [ "space" <operand> { "comma" <operand> } ] "newline"
									   
      (progn (prin2 '! )
	     % Space                                    
	     (when (wgreaterp (length x) 2)
		(setq x (invertsequence x)))
	     (printopcode (car x))
	     (prin2 " ")     % space
	       (when (and (eq (car x) 'mov)
			  (pairp (cadr x))
			  (memq(caadr x) '($fluid $global fluid global)))
		     (prin2 "ds:"))
	     (setq x (cdr x))
	     (unless (null x)
		     (printoperand (car x))
		     (foreach u in (cdr x) do 
			      (progn (prin2 '!,)
				     % COMMA                          
				     (printoperand u))))
	     (prin2 (int2id 13))
	     (prin2 !$eol!$)))))))

% NEWLINE                                                                  
(de invertsequence (x)
  (prog (y)
   (setq y (cons (car x) (last x)))
   (setq x (reverse (cdr (reverse (cdr x)))))
   (return (append y x))))

(put '*entry 'asmpseudoop 'asmprintentry)

(de asmprintentry (x)
  (prog (y)
	(printcomment x)
	(setq x (cadr x))
	(setq y (findentrypoint x))
	(unless (flagp x 'internalfunction)
	  (findidnumber x))
	(if (eq x mainentrypointname*)
	  (progn (setq *mainfound t)
		 (specialactionformainentrypoint))
	  (codedeclareexporteduse y))))

(de codedeclareexporteduse (y)
  (if *declarebeforeuse
    (progn (codedeclareexported y)
	   (printlabel y))
    (progn (printlabel y)
	   (codedeclareexported y))))

(de findentrypoint (x)
  (cond ((get x 'entrypoint) (get x 'entrypoint))
	((and (asmsymbolp x)
	      (not (get x 'symbol))
	      (not (flagp x 'foreignfunction)))
	 (put x 'entrypoint x) 
	 x)
	(t 
	 (let ((name (stringgensym)))
	   (put x 'entrypoint name)
	   name))
	))

(de asmpseudoprintfloat (x)
  (printf doublefloatformat* (cadr x)))

(put 'float 'asmpseudoop 'asmpseudoprintfloat)

(de asmpseudoprintfullword (x)
  (foreach y in (cdr x) do (printfullword y)))

(put 'fullword 'asmpseudoop 'asmpseudoprintfullword)

(de asmpseudoprintindword (x)
  (foreach y in (cdr x) do (printindword y)))

(put 'indword 'asmpseudoop 'asmpseudoprintindword)

(de asmpseudoprintbyte (x)
  (printbytelist (cdr x)))

(put 'byte 'asmpseudoop 'asmpseudoprintbyte)

(de asmpseudoprinthalfword (x)
  (printhalfwordlist (cdr x)))

(put 'halfword 'asmpseudoop 'asmpseudoprinthalfword)

(de asmpseudoprintstring (x)
  (printstring (cadr x)))

(put 'string 'asmpseudoop 'asmpseudoprintstring)

(de printoperand (x)
  (cond ((stringp x) (prin2 x))
	((numberp x) (printnumericoperand x))
	((idp x) (prin2 (findlabel x)))
	(t (prog (hd fn)
		 (setq hd (car x))
		 (cond ((setq fn (get hd 'operandprintfunction)) 
			(apply fn (list x)))
		       ((and (setq fn (getd hd)) (equal (car fn) 'macro)) 
			(printoperand (apply (cdr fn) (list x))))
		       ((setq fn (wconstevaluable x)) (printoperand fn))
		       (t (printexpression x)))))))

(put 'reg 'operandprintfunction 'printregister)

(de printregister (x)
  (prog (nam)
	(setq x (cadr x))
	(cond ((stringp x) (prin2 x))
	      ((numberp x) (prin2 (getv numericregisternames* x)))
	      ((setq nam (registernamep x)) (prin2 nam))
	      (t (errorprintf "***** Unknown register %r" x) (prin2 x)))))

(de registernamep (x)
  (get x 'registername))

(de asmentry (x)
  (printexpression
   (list 'plus2
	 'symfnc 
	 (list 'times2 
	       (compiler-constant 'addressingunitsperfunctioncell) 
	       (list 'idloc (cadr x))))))

(put 'entry 'operandprintfunction 'asmentry)

(put 'entry 'asmexpressionfunction 'asmentry)

(de asminternalentry (x)
  (prin2 (findentrypoint (cadr x))))

(put 'internalentry 'operandprintfunction 'asminternalentry)

(put 'internalentry 'asmexpressionfunction 'asminternalentry)

(dm extrareg (u)
  (list 'plus2 '(fluid argumentblock) 
	(times (difference (cadr u) (plus lastactualreg!& 1)) 
	       (compiler-constant 'addressingunitsperitem))))

(de asmsyslispvarsprint (x)
  (prin2 (findgloballabel (cadr x))))

(de asmprintvaluecell (x)
  (printexpression (list 'plus2 'symval 
			 (list 'times (compiler-constant 'addressingunitsperitem) 
			  (list 'idloc (cadr x))))))

(deflist '((fluid asmprintvaluecell) (!$fluid asmprintvaluecell) 
	   (global asmprintvaluecell) (!$global asmprintvaluecell))
	 'operandprintfunction)

(de lookuporaddasmsymbol (u)
  (prog (x)
	(unless (setq x (get u 'symbol))
	  (setq x (addasmsymbol u)))
	(return x)))

(de addasmsymbol (u)
  (let ((x (if (and (asmsymbolp u)
		    (not (get u 'entrypoint))
		    (not (flagp u 'foreignfunction)))
	     u
	     (stringgensym))))
    (put u 'symbol x)
    (return x)))

(de dataprintvar (name init)
  (prog (oldout)
	(dataprintlabel name)
	(setq oldout (wrs dataout*))
	(printfullword init)
	(wrs oldout)))

(de dataprintblock (name siz typ)
  (if (equal typ 'wstring)
    (setq siz 
      (list 'quotient (list 'plus2 siz (plus (compiler-constant 'charactersperword) 1)) 
	    (compiler-constant 'charactersperword)))
    (setq siz (list 'plus2 siz 1)))
  (datareservezeroblock name siz))

(de dataprintlist (nam init typ)
  (prog (oldout)
	(dataprintlabel nam)
	(setq oldout (wrs dataout*))
	(cond 
	      ((stringp init) 
	       (prog (s)
		     (setq s (size init))
		     (for (from i 0 s 1) 
		      (do (printfullword (indx init i))))))
	      (t (foreach x in init do (printfullword x))))
	(wrs oldout)))

(de dataprintgloballabel (x)
  (when *declarebeforeuse
    (datadeclareexported x))
  (dataprintlabel x)
  (unless *declarebeforeuse
    (datadeclareexported x))
%  (codedeclareexternal x))
)

(de datadeclareexternal (x)
  (unless (or (member x dataexternals*) (member x dataexporteds*))
    (setq dataexternals* (cons x dataexternals*))
    (dataprintf externaldeclarationformat* x x)))

(de codedeclareexternal (x)
  (unless (or (member x codeexternals*) (member x codeexporteds*))
    (setq codeexternals* (cons x codeexternals*))
    (codeprintf externaldeclarationformat* x x)))

(de datadeclareexported (x)
  (when (or (member x dataexternals*) (member x dataexporteds*))
    (errorprintf "***** %r multiply defined" x))
  (setq dataexporteds* (cons x dataexporteds*))
  (dataprintf exporteddeclarationformat* x x))

(de codedeclareexported (x)
  (when (or (member x codeexternals*) (member x codeexporteds*))
    (errorprintf "***** %r multiply defined" x))
  (setq codeexporteds* (cons x codeexporteds*))
  (codeprintf exporteddeclarationformat* x x))

(de printlabel (x)
  (printf labelformat* x x))

(de dataprintlabel (x)
  (dataprintf datalabelformat* x x))

(de codeprintlabel (x)
  (codeprintf labelformat* x x))

(de printcomment (x)
  (printf commentformat* x))

%% Okay to do destructive ops to save consing as long as the replaca's are
%% done on the heap, not bps. That way we can unexec over them. /LBS

%(setq printexpressionform* (list 'printexpression (mkquote nil)))
(setq printexpressionform* (totalcopy (list 'printexpression (mkquote nil))))

(setq printexpressionformpointer* (cdadr printexpressionform*))

% Save some consing                                                        
% instead of list('PrintExpression, MkQuote X), reuse the same list structure
									   
(de printfullword (x)
  (rplaca printexpressionformpointer* x)
  (printf fullwordformat* printexpressionform*))

(de printindword (x)
  (rplaca printexpressionformpointer!* x)
  (printf indwordformat!* printexpressionform!*))

(de dataprintfullword (x)
  (rplaca printexpressionformpointer* x)
  (dataprintf fullwordformat* printexpressionform*))

(de codeprintfullword (x)
  (rplaca printexpressionformpointer* x)
  (codeprintf fullwordformat* printexpressionform*))

(de datareservezeroblock (nam x)
  (rplaca printexpressionformpointer* 
	  (list 'times2 (compiler-constant 'addressingunitsperitem) x))
  (dataprintf reservezeroblockformat* nam printexpressionform*))

(de datareserveblock (x)
  (rplaca printexpressionformpointer* 
	  (list 'times2 (compiler-constant 'addressingunitsperitem) x))
  (dataprintf reservedatablockformat* printexpressionform*))

(de datareservefunctioncellblock (x)
  (rplaca printexpressionformpointer* 
	  (list 'times2 (compiler-constant 'addressingunitsperfunctioncell) x))
  (dataprintf reservedatablockformat* printexpressionform*))

(de dataprintundefinedfunctioncell ()
  (prog (oldout)
	(setq oldout (wrs dataout*))
	(foreach x in undefinedfunctioncellinstructions* do 
		 (asmoutlap1 x))
	(wrs oldout)))

(de dataprintdefinedfunctioncell (x)
  %(datadeclareexternal x)
  (dataprintf definedfunctioncellformat* x x))

% in case it's needed twice                                                
(de dataprintbytelist (x)
  (prog (oldout)
	(setq oldout (wrs dataout*))
	(printbytelist x)
	(wrs oldout)))

(de dataprintexpression (x)
  (prog (oldout)
	(setq oldout (wrs dataout*))
	(printexpression x)
	(wrs oldout)))

(de codeprintexpression (x)
  (prog (oldout)
	(setq oldout (wrs codeout*))
	(printexpression x)
	(wrs oldout)))

(setq expressioncount* -1)

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
		    (apply 'printf 
			   (cons fn 
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

(deflist '((plus2 !+) (wplus2 !+) (difference !-) (wdifference !-) 
	   (times2 *) (wtimes2 *) (quotient !/) (wquotient !/))
	 'binaryasmop)

(deflist '((minus !-) (wminus !-)) 'unaryasmop)

(de compileconstant (x)
  (setq x (buildconstant x))
  (if (null (cdr x))
    (car x)
    (progn (when *declarebeforeuse
	     (codedeclareexported (cadr x)))
	   (CODEPRINTF "  align 4%n")   % 29.9.93
	   (asmoutlap (cdr x))
%          (datadeclareexternal (cadr x))
	   (unless *declarebeforeuse
	     (codedeclareexported (cadr x)))
	   (car x))))

(de dataprintstring (x)
  (prog (oldout)
	(setq oldout (wrs dataout*))
	(printstring x)
	(wrs oldout)))

(de findlabel (x)
  (prog (y)
	(return (cond ((setq y (atsoc x locallabels*)) (cdr y))
		      ((setq y (get x 'symbol)) y)
		      (t (findlocallabel x))))))

(de findlocallabel (x)
  (prog (y)
	(return (if (setq y (atsoc x locallabels*))
		  (cdr y)
		  (progn (setq locallabels* 
			  (cons (cons x (setq y (stringgensym))) 
			   locallabels*))
			 y)))))

(de findgloballabel (x)
  (or (get x 'symbol) (errorprintf "***** Undefined symbol %r" x)))

(de codeprintf (fmt a1 a2 a3 a4)
  (prog (oldout)
	(setq oldout (wrs codeout*))
	(printf fmt a1 a2 a3 a4)
	(wrs oldout)))

(de dataprintf (fmt a1 a2 a3 a4)
  (prog (oldout)
	(setq oldout (wrs dataout*))
	(printf fmt a1 a2 a3 a4)
	(wrs oldout)))

% Kludge of the year, just to avoid having IDLOC defined during compilation
(compiletime
  (fluid '(macro)))

(setq macro 'macro)

(putd 'idloc macro (function (lambda (x)
				     (findidnumber (cadr x)))))
(put 'declare-aux-1 'asmpreeval 'eval)

(dm declare-kernel-structure (u)
  (list 'declare-aux-1 (list 'quote (cdr u))))

(df declare-aux-1 (u)
  (prog (olddataout)
  (setq olddataout dataout*)
  (setq dataout* (open "KSTRUCTS.asm" 'output))
  (foreach x in (cadar u) do 
    (declare-aux-2 (car x) (cadr x) ))
  (close dataout*)
  (setq dataout* olddataout)))

(flag '(declare-aux-1) 'ignore)

(de declare-aux-2 (name upperbound)
     (findidnumber name)             % generate an ID it doesn't exist.
     (put name 'symbol name)         % flag as a fluid variable.
     (put name 'type 'fluid)         % flag as a fluid variable.
     (flag1 name 'externalsymbol)     % flag as initial symbol value.
     (when *declarebeforeuse (datadeclareexported name))
%     (dataalignfullword)
     (setq upperbound (list 'plus2 upperbound 1))
     (dataprintf " ALIGN 4%n")
     (datareservezeroblock name upperbound)
     (unless *declarebeforeuse (datadeclareexported name))
%     (codedeclareexternal name)
)



