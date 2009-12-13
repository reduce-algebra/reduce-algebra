%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC:WDECLARE.SL
% Title:          Extended WDECLARE for non-kernel
% Author:         M. L. Griss
% Created:        May 1983
% Modified:       06-Dec-83 10:00 (Brian Beach)
% Status:         Experimental
% Mode:           Lisp
% Package:        Compiler
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 7 Mar 1984 1425-PST (Nancy Kendzierski)
%  Changed warnings to StdError in NKWCONSTReform.
% 06-Dec-83 10:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% if either UpperBound or Initializer are NIL, they are considered to be
% unspecified.

(fluid '(locallabels*))
(off kernelmode)

(de registernameP (x) nil)
% In case try to access registername
 

(df wdeclare (U) 
    (foreach x in (cddr U) do (WDeclare1 (car x) (car U) (cadr U) (cadr x) (caddr x))))

(flag '(wdeclare) 'IGNORE)

(de WDeclare1 (Name Scope typ UpperBound Initializer) 
 (PROG (Base) 
   (COND ((or (get Name 'wconst) (get Name 'wvar) 
      (get Name 'wstring) (get Name 'Warray)) 
       (PROGN 
       (ErrorPrintF "*** %w declared twice, second declaration ignored.%n" 
		    Name) 
       (return nil) nil))) 
       
    (COND ((Equal typ 'wconst) 
      (return (COND ((and (Equal Scope 'external) (not (get Name 'wconst))) 
	    (ErrorPrintF "*** A value has not been defined for WConst %r" 
								Name)) (t 
	
	(PROGN (put Name 'Scope (COND ((Equal Scope 'EXPORTED) 'external) (t Scope))) 
	    (put Name 'wconst (NKWCONSTReform Initializer)))))))) 
   (COND ((registernameP Name) 
	(return (ErrorPrintF " Cant reference a register in WDECLARE %r" Name)))) 
   (COND ((Equal Scope 'external) 
    % Need some more error checking to be sure exists at this point
       (return (COND ((Numberp (get Name typ)) (put Name 'Scope 'external)) (t 
	       (ErrorPrintF " %r has no current value in WDECLARE" Name)))))) 
  % Here need to try RUN-TIME Lookup
   (put Name typ Name) 
   (put Name 'Scope (COND ((Equal Scope 'EXPORTED) 'external) (t Scope))) 
   (return (WarrayAlloc Name 
       	           typ 
	           UpperBound 
	           Initializer))))


(de WarrayAlloc (Name typ UpperBound Initializer) 
 (PROG (Base Nwrds) 
    (COND ((Equal typ 'wvar) 
    (return (PROGN (COND (UpperBound 
	       (ErrorPrintF "*** An UpperBound may not be specified for a WVar"))) 
	      (SETQ Initializer (COND (Initializer (NKWCONSTReform Initializer)) (t 0))) 
			
	(SETQ Base (GtWarray 1)) 
	(PutMem Base Initializer) 
	(put Name 'wvar Base) 
	Base)))) 
   (COND ((and UpperBound Initializer) 
	    (ErrorPrintF "*** Can't have both UpperBound and initializer")) 
	((not (or UpperBound Initializer)) 
	    (ErrorPrintF "*** Must have either UpperBound or initializer")) 
	(UpperBound 
	(return (PROGN (SETQ UpperBound (NKWCONSTReform UpperBound)) 
	         (COND ((Equal typ 'Warray) (SETQ Nwrds (Plus UpperBound 1))) (t 
	          (SETQ Nwrds (Strpack (Plus UpperBound 1))))) 
	         (SETQ Base (GtWarray Nwrds)) 
	         (put Name typ Base) 
	         (put Name 'wconst Base) 	% Seems a KLUDGE, someone converts
		 Base)))) 
	 (SETQ Initializer (COND ((StringP Initializer) (String2List Initializer)) (t 
				(NKWCONSTReformLis Initializer)))) 
	 (SETQ Nwrds (Length Initializer)) 
	 (COND ((Equal typ 'Warray) (PROGN (SETQ Base (GtWarray (Plus Nwrds 1))) 
  			       (put Name typ Base) 
		               (put Name 'wconst Base) 
			       (foreach x in Initializer do 
				 (PROGN (PutMem Base x) 
				   (SETQ Base (Plus Base AddressingUnitsPerItem)))))) (t 
         (PROGN (SETQ Base (GtWarray (Strpack (Plus Nwrds 1)))) 
			      (PutMem Base Nwrds) 	% String Length
 			      (put Name typ Base) 
		              (put Name 'wconst Base) 
			      (for (from i 0 Nwrds 1) (do 
				(PROGN (setf (strbyt Base i) (car Initializer)) 
		                  (SETQ Initializer (cdr Initializer))))))))))

	 

(de NKWCONSTReform (U) 
(PROG (x) 
    (return (COND ((or (FixP U) (StringP U)) U) 
    ((IDP U) 
	(COND ((SETQ x (get U 'Warray)) x) 
	((SETQ x (get U 'wstring)) x) 
        ((SETQ x (get U 'wvar)) (GetMem x)) 
	((SETQ x (get U 'wconst)) x) (t 
	(StdError (bldmsg "Unknown symbol %r in NKWCONSTReform" U)))))
    ((PairP U) 
	(COND ((SETQ x (get (car U) 'NKWCONSTReformPseudo)) (Apply x (list U))) 
	((SETQ x (get (car U) 'DOFN)) (cons x (NKWCONSTReformLis (cdr U)))) 
	((MacroP (car U)) (NKWCONSTReform (Apply (cdr (GetD (car U))) (list U)))) (t 
	(cons (car U) (NKWCONSTReformLis (cdr U)))))) (t 
    (StdError (bldmsg "Illegal expression %r in NKWCONSTReform" U)))))))


(de NKWCONSTReformIdent (U) 
    U)

(put 'InternalEntry 'NKWCONSTReformPseudo 'NKWCONSTReformIdent)

(de NKWCONSTReformQuote (U) 
    (CompileConstant (cadr U)))

(put 'QUOTE 'NKWCONSTReformPseudo 'NKWCONSTReformQuote)

(de NKWCONSTReformLis (U) 
    (foreach x in U collect (NKWCONSTReform x)))

(de NKWCONSTReformLoc (U)               %. To handle &Foo[23]
(PROGN (SETQ U (NKWCONSTReform (cadr U))) 
    (COND ((neq (car U) 'GetMem) 
	(ErrorPrintF "*** Illegal constant addressing expression %r" 
				(list 'Loc U))) (t 
    (cadr U)))))

(put 'Loc 'NKWCONSTReformPseudo 'NKWCONSTReformLoc)

(de NKWCONSTReformIDLoc (U) 
    (FindIDNumber (cadr U)))

(put 'IDLoc 'NKWCONSTReformPseudo 'NKWCONSTReformIDLoc)

(de LookupOrAddASMSymbol (U) 
(PROG (x) 
    (COND ((not (SETQ x (get U 'ASMSymbol))) (SETQ x (AddASMSymbol U)))) 
    (return x)))


(de AddASMSymbol (U) 
(PROG (x) 
    (SETQ x (COND ((and (ASMSymbolP U) (not (get U 'EntryPoint))) U) (t 
	 (StringGensym)))) 
    (put U 'ASMSymbol x) 
    (return x)))


(de FindLabel (x) 
(PROG (Y) 
    (return (COND ((SETQ Y (Atsoc x LocalLabels*)) (cdr Y)) 
    ((SETQ Y (get x 'ASMSymbol)) Y) 
    ((SETQ Y (get x 'wconst)) Y) (t 
    (FindLocalLabel x))))))


(de FindLocalLabel (x) 
(PROG (Y) 
    (return (COND ((SETQ Y (Atsoc x LocalLabels*)) (cdr Y)) (t 
    
    (PROGN (SETQ LocalLabels* (cons (cons x (SETQ Y (StringGensym))) LocalLabels*)) 
	Y))))))


(de FindGlobalLabel (x) 
    (or (get x 'ASMSymbol) (ErrorPrintF "***** Undefined symbol %r" x)))

% Kludge of the year, just to avoid having IDLOC defined during compilation
% Removed so that IDLOC won't screw up the compiler by evaluating too soon:

%(CompileTime (fluid '(macro)))

%(SETQ macro 'macro)

%(PutD 'IDLoc macro 
%(function (lambda (x) 
%    (FindIDNumber (cadr x)))))


