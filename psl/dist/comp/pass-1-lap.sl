%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC:PASS-1-LAP.SL
% Title:          Expand c-macros and allocate quoted expressions
% Author:         Eric Benson
% Created:        14 December 1981
% Modified:       11-Sep-84 08:23:14 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Compiler
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 15-Dec-92 (Winfried Neun)
%  Faslout for evectors (!)
% 27-Oct-92 (Winfried Neun)
%  Fixed a bug noted by Rainer Schoepf which caused intermix of (0) and (0.0)
% 27-May-92 (Winfried Neun)
%  'Unified' again with the specific versions (allocation of bignums in fasl)
% 5 -February 1991 (Winfried Neun)
% Added code for (odd-) alignment of floats
% 22-Jun-87 (Leigh Stoller)
%  Removed internal function flags.
% 22-Jun-84 10:36:12 (Brian Fromme)
%  Added Bugnums to the list of types in TAGNUMBER.
% 28 Feb 1984 1705-PST (Cris Perdue)
%  Redefined inump and tagnumber to use "compiler constants".
%  Should now be valid for both self- and cross-compilation.
% 12-Mar-84 13:31:01 (Brian Beach)
%  Removed fluid declaration for ADDRESSINGUNITSPERITEM.
% 15-Feb-84 10:46:00 (Steve Lowder)
%  Removed all references to Wvar, WString, Wconst, and Warray.
% 26-Jan-84 21:45:20 (Nancy Kendzierski)
%  Moved dskins of common-cmacros and common-predicates after body of
%  pass-1-lap source, since that's how it was in the build file.
% 30 Dec 1983 1058-PST (Brian Beach)
%  Added stuff from build file.  Changed big comment from "(comment...)"
%  to "%...".  Removed (ON EOLINSTRINGOK).
% 06-Dec-83 10:00 (Brian Beach)
%   New header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Added MCprint and InstructionPrint - MLG

% <PSL.COMP>PASS-1-LAP.SL.17,  4-Aug-82 00:35:54, Edit by BENSON
% Added bignum constants; won't work for cross-compilation, though

%

% Pass1Lap takes a list of c-macros and instructions, and attempts to simplify
% them whenever possible.  C-macros are expanded by APPLY(CAR X, CDR X), which
% will return another instruction list to be processed recursively by Pass1Lap.
% Quoted expressions are allocated at the end of the code, in the following way:
% 
% In an instruction or c-macro
% (.... (QUOTE (A B C)) ...)
% 
% the following is tacked onto the end of the constructed code list:
% 
% L2
% (MKITEM ID A)
% (MKITEM PAIR L3)
% L3
% (MKITEM ID B)
% (MKITEM PAIR L4)
% L4
% (MKITEM ID C)
% (MKITEM ID NIL)
% 
% If *ImmediateQuote is NIL, the quoted reference becomes:
% 
% (... L1 ...)
% ...
% L1
% (fullword (MKITEM PAIR L2))
% 
% Otherwise, it becomes:
% 
% (... (immediate (MKITEM PAIR L2)) ...)

(dskin "$pc/anyreg-cmac.sl")
(dskin "$pc/cmacros.sl")
(dskin "$pc/predicates.sl")

(fluid '(!*ImmediateQuote
	 !*PCMAC
	 !*PrintedOneCMacro
	 Pass1CodeList
	 Pass1ConstantList
	 Pass1ConstantContentsList
	 Pass1AddedCode
	 EntryPoints!*
	 LastActualReg!&))

(CompileTime (load fast-vector))

(de Pass1Lap (InstructionList)
  (prog (Pass1CodeList
	 Pass1ConstantList
	 Pass1ConstantContentsList
	 EntryPoints!*
	 Pass1AddedCode)
    (setq Pass1CodeList (cons NIL NIL))	% Init a TCONC pointer.
    (setq Pass1ConstantContentsList (cons NIL NIL))
    (Pass1Code InstructionList)         % Expand macros.
    (Pass1Code Pass1AddedCode)
    (AppendConstants)			% Tack the constants on the end.
    (return (car Pass1CodeList))))

% BuildConstant takes an S-expression and returns the LAP version of it.

% The car is the expanded item, cdr is the contents.

(de BuildConstant (Expression)
  (prog (Pass1CodeList
	 Pass1ConstantList
	 Pass1ConstantContentsList
	 ExpandedExpression)
    (setq Pass1CodeList (cons NIL NIL))	% Init a TCONC pointer.
    (setq Pass1ConstantContentsList (cons NIL NIL))
    (setq ExpandedExpression (ExpandItem Expression)) % Expand the item.
    (AppendConstants)			% Tack the contents on the end.
    (return (cons ExpandedExpression (car Pass1CodeList)))))

(de Pass1Code (InstructionList)
    (ForEach Instruction in InstructionList do (OneLapPass1 Instruction)))

(de OneLapPass1 (Instruction)
  (cond ((atom Instruction) (AddCodeLabel Instruction))
	((eq (car Instruction) '!*ENTRY)
	 (progn % ENTRY directives are passed unchanged.
	        (cond ((and (not (or (FlagP (second Instruction)
					    'InternalFunction)
				     (equal (second Instruction)
					    '**fasl**initcode**)))
			    (null (car Pass1CodeList)))
		       % Header word says how many arguments to expect.
		       (AddCode (list 'FULLWORD (fourth Instruction)))))
		(setq EntryPoints!*
		      (cons (second Instruction) EntryPoints!*))
		(cond (!*PCMAC (MCPrint Instruction)))
		(AddCode Instruction)))
	((FlagP (car Instruction) 'MC)
	 (progn (cond ((and !*PCMAC (not !*PrintedOneCMacro))
		       (MCPrint Instruction)))
		((lambda (!*PrintedOneCMacro)
			 (Pass1Code (Apply (car Instruction)
					   (cdr Instruction))))
		 T)))
	(t (progn (cond (!*PCMAC (InstructionPrint Instruction)))
		  (AddInstruction Instruction)))))

(de MCPrint(x) (print x))
(de InstructionPrint(x) (PrintF "	%p%n" x))

(de AddInstruction (Instruction)
  (AddCode (ExpandPseudoOps Instruction)))

(de ExpandPseudoOps (X)
  (cond ((atom X) X)
	(t (cons (ExpandOnePseudoOp (car X))
		 (ExpandPseudoOps (cdr X))))))

(de ExpandOnePseudoOp (X)
  (prog (PseudoOpFunction)
	(return (cond ((atom X) X)
		      ((setq PseudoOpFunction
			     (get (car X) 'Pass1PseudoOp))
		       (ExpandOnePseudoOp (Apply PseudoOpFunction
						 (list X))))
		      ((setq PseudoOpFunction (WConstEvaluable X))
		       PseudoOpFunction)
		      (t (cons (car X) (ExpandPseudoOps (cdr X))))))))


(de PassOneUnImmediate (X)
  (progn (setq X (cadr X))
	 (cond ((EqCar X 'Immediate) (cadr X))
	   (t X))))

(put 'UnImmediate 'Pass1PseudoOp 'PassOneUnImmediate)

(de PassOneLabel (U)
  (cadr U))

(put 'Label 'Pass1PseudoOp 'PassOneLabel)

(de PassOneUnDeferred (X)
  (progn (setq X (cadr X))
	 (cond ((EqCar X 'Deferred) (cadr X))
	   (t X))))

(put 'UnDeferred 'Pass1PseudoOp 'PassOneUnDeferred)

(de GenerateCodeLabel ()
  (prog (NewLabel)
	(setq NewLabel (GenerateLabel))
	(AddCodeLabel NewLabel)
	(return NewLabel)))

(de GenerateLabel ()
  (StringGenSym))

(de AddCodeLabel (Label)
  (AddCode Label))

(de AddCode (C)
  (TConc Pass1CodeList C))

(de ExpandLit (U)
  (prog (L)
    (cond ((setq L (FindPreviousLit (cdr U))) (return L)))
    (setq L (GenerateLabel))
    (setq Pass1AddedCode (NConc Pass1AddedCode
			   (cons L (ForEach X in (cdr U) collect X))))
    (return L)))

(de FindPreviousLit (U)
  (cond ((not (null (rest U))) NIL)
    (t (prog (L)
	 (setq L Pass1AddedCode)
	 (cond ((null L) (return NIL)))
	 (setq U (first U))
        loop
	 (cond ((null (rest L)) (return NIL)))
	 (cond ((equal U (second L))
		(return (cond ((atom (first L)) (first L))
			  (t (prog (B)
			       (setq L (rest L))
			       (rplacd L (cons (first L) (rest L)))
			       (rplaca L (setq B (GenerateLabel)))
			       (return B)))))))
	 (setq L (rest L))
	 (go loop)))))

(put 'lit 'Pass1PseudoOp 'ExpandLit)
(flag '(lit) 'TerminalOperand)

(de ExpandQuote (QuotedExpression)
  (ExpandQuote1 (cadr QuotedExpression)))

(put 'Quote 'Pass1PseudoOp 'ExpandQuote)

(de ExpandQuote1 (Expression)
  (cond (!*ImmediateQuote (ExpandImmediateQuote Expression))
        (t (ExpandNonImmediateQuote Expression))))

(de ExpandImmediateQuote (Expression)
  (list 'IMMEDIATE (ExpandItem Expression)))

(de ExpandItem (Expression)
  (prog (LabelOfContents)
	(return (cond ((InumP Expression) Expression)
		      ((IDP Expression)
		       (MakeMkItem (TagNumber Expression)
				   (list 'IDLoc Expression)))
		      ((CodeP Expression)
		       (MakeMkItem (TagNumber Expression)
			           Expression))
		      (t (progn (setq LabelOfContents
				      (SaveContents Expression))
				(MakeMkItem (TagNumber Expression)
					    LabelOfContents)))))))

(de ExpandNonImmediateQuote (Expression)
  (SaveConstant Expression))

(de equal_wo_zeroequal (x y)
   (or (eq x y)
	(cond ((pairp x) (and (pairp y)
			(equal_wo_zeroequal (car x) (car y))
	 		(equal_wo_zeroequal (cdr x) (cdr y))))
	      ((and (atom x) (zerop x)) (eq x y))
	      (t (equal x y)))))


(de SaveConstant (Expression)
  (prog (TableEntry)
	(return (cond ((setq TableEntry
			     (Ass (function equal_wo_zeroequal)
		% dont intermix 0 and 0.0
				 Expression Pass1ConstantList))
		       (cdr TableEntry))
		      (t (progn (setq TableEntry (GenerateLabel))
				(setq Pass1ConstantList
				      (cons (cons Expression
						  TableEntry)
					    Pass1ConstantList))
				TableEntry))))))


(de SaveContents (Expression)
  (prog (TableEntry)
	(return (cond ((setq TableEntry
			     (Ass (function equal_wo_zeroequal)
                % dont intermix 0 and 0.0
				 Expression (car Pass1ConstantContentsList)))
		       (cdr TableEntry))
		      (t (progn (setq TableEntry (GenerateLabel))
				(TConc Pass1ConstantContentsList
				       (cons Expression TableEntry))
				TableEntry))))))


(de AppendConstants ()
  (prog (TempCodeList)
	(cond ((not !*ImmediateQuote)
	       (ForEach TableEntry in Pass1ConstantList do
			(AppendOneConstant TableEntry))))
	(setq TempCodeList Pass1CodeList)
	(setq Pass1CodeList (cons NIL NIL))
	(ForEach TableEntry in (car Pass1ConstantContentsList) do
		 (AppendContents TableEntry))
	% The contents go on the begininning of the list.
	(LConc Pass1CodeList (car TempCodeList))))

(de AppendOneConstant (ExpressionLabelPair)
  (progn (AddCodeLabel (cdr ExpressionLabelPair))
         (AppendItem (car ExpressionLabelPair))))

(de AppendItem (Expression)
  (AddFullWord (ExpandItem Expression)))

(de AddFullWord (Expression)
  (AddCode (list 'FULLWORD Expression)))

(de AppendContents (ExpressionLabelPair)
  (prog (Expression UpperBound I)

        (when (and (FloatP (car ExpressionLabelPair)) (prop 'oddalign))
                (AddCode '(oddalign))) % odd double align floats

	(AddCodeLabel (cdr ExpressionLabelPair))
	(setq Expression (car ExpressionLabelPair))
	(cond ((PairP Expression)
	       (progn (AppendItem (car Expression))
		      (AppendItem (cdr Expression))))
	      ((StringP Expression)
	       (progn (AddFullWord (Size Expression))
		      (AddCode (list 'STRING Expression))))
	      ((or (VectorP Expression) (EVectorP Expression))
	       (progn (setq UpperBound (ISizeV Expression))
		      (AddFullWord UpperBound)
		      (setq I 0)
		      (while (ILEQ I UpperBound)
			     (progn (AppendItem (IGetV Expression I))
				    (setq I (IAdd1 I))))))
	      ((BigP Expression)
	       (progn (setq UpperBound (ISizeV Expression))
		      (AddFullWord UpperBound)
		      (AppendItem (IGetV Expression 0)) % sign is an id
                      (setq I 1)
		      (while (ILEQ I UpperBound)
%		     (progn (AppendItem (IGetV Expression I))
                          (progn (AddFullWord (sys2fixn (IGetV Expression I)))
				    (setq I (IAdd1 I))))))
	      ((FixP Expression)
	       (progn (AddFullWord 0)	% Header of full word fixnum.
		      (AddFullWord Expression)))
	      ((FloatP Expression)
	       (progn (AddFullWord 1)	% Header of float.
		      (AddCode (list 'FLOAT Expression)))))))

(de MakeMkItem (TagPart InfPart)
  (list 'MKITEM TagPart InfPart))

(de InumP (Expression)
  (and (fixp expression)
       (lessp expression (lshift 1  (compiler-constant 'infbitlength)))
       (geq   expression (lshift -1 (compiler-constant 'infbitlength)))))

(de TagNumber (X)
  (cond ((IDP X)     (compiler-constant 'id-tag))
	((PairP X)   (compiler-constant 'pair-tag))
	((StringP X) (compiler-constant 'string-tag))
	((InumP X)   (if (MinusP X)
		       (compiler-constant 'negint-tag)
		       (compiler-constant 'posint-tag)))
	((CodeP X)   (compiler-constant 'code-tag))
	((FloatP X)  (compiler-constant 'floatnum-tag))
	((VectorP X) (compiler-constant 'vector-tag))
	((EVectorP X) (compiler-constant 'evector-tag))
	((BigP X)    (compiler-constant 'bignum-tag))
	((FixP X)    (compiler-constant 'fixnum-tag))))

% End of file.
