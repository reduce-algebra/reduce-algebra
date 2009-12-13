%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:COMMON-CMACROS.SL
% Description:  C-macros and Anyregs common to all implementations
% Author:       Eric Benson
% Created:      17 December 1981
% Modified:     11-Sep-84 08:24:29 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
% Compile to:   none
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
% 27-May-1992 (Winfried Neun)
%  Made file usable for newer versions which do not have fluid as TERMINALOPERAND
% 27-Mar-84 08:29:43 (Brian Beach)
%  Added fast-apply-load function.
% 14 Feb 1984 1142-PST (Cris Perdue)
%  Added standard header.
% 10 Jan 1984 0909-PST (Brian Beach)
%  Removed string that was continued over end of line.
% 20-NOV-83 Mark R. Swanson
%  Added function defs. for new cmacros *MKBPTR and *MKBPTR1
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(fluid '(NAlloc* ResultingCode*))

(de *Link (FunctionName FunctionType NumberOfArguments)
  (list (cond ((FlagP FunctionName 'ForeignFunction)
	       (list '*ForeignLink
		     FunctionName
		     FunctionType
		     NumberOfArguments))
	      (t  (list '*Call FunctionName)))))

(DefCMacro *Link)

(de *Call (FunctionName)
  (prog (ResultingCode* OpenCodeSequence)
	(return (cond ((setq OpenCodeSequence
			     (get FunctionName 'OpenCode))
		       OpenCodeSequence)
		      (t (CMacroPatternExpand (list FunctionName)
					      (get '*Call
						   'CMacroPatternTable)))))))

(de *LinkE (DeAllocCount FunctionName FunctionType NumberOfArguments)
  (cons (list '*DeAlloc DeAllocCount)
	(cond ((FlagP FunctionName 'ForeignFunction)
	       (list (list '*ForeignLink
			   FunctionName
			   FunctionType
			   NumberOfArguments)
		     '(*Exit 0)))
	      (t  (list (list '*JCall FunctionName))))))

(DefCMacro *LinkE)

(de *JCall (FunctionName)
  (prog (ResultingCode* OpenCodeSequence)
	(return (cond ((setq OpenCodeSequence
			     (get FunctionName 'ExitOpenCode))
		       OpenCodeSequence)
		      ((setq OpenCodeSequence
			     (get FunctionName 'OpenCode))
		       (Append OpenCodeSequence (list '(*Exit 0))))
		      (t (CMacroPatternExpand (list FunctionName)
					      (get '*JCall
						   'CMacroPatternTable)))))))
  

(de *DeAlloc (DeAllocCount)
  (Expand1OperandCMacro 
   (times DeAllocCount (compiler-constant 'AddressingUnitsPerItem))
   '*DeAlloc))

(de *Alloc (N)
  (setq NAlloc* N)
  (Expand1OperandCMacro
   (times N (compiler-constant 'AddressingUnitsPerItem)) 
   '*Alloc))

(de *Exit (N)
  (Expand1OperandCMacro
   (times N (compiler-constant 'AddressingUnitsPerItem)) '*Exit))

(de *JumpWithin (Label LowerBound UpperBound)
  (prog (ExitLabel)
	(setq ExitLabel (list 'Label (GenSym)))
	(return (list (list '*JumpWLessP ExitLabel '(Reg 1) LowerBound)
		      (list '*JumpWLeq Label '(Reg 1) UpperBound)
		      (list '*Lbl ExitLabel)))))

(DefCMacro *JumpWithin)

(de *ProgBind (FluidsList)
  (*LamBind '(Registers) FluidsList))

(DefCMacro *ProgBind)

(de *FreeRstr (FluidsList)
  (Expand1OperandCMacro (length (cdr FluidsList)) '*FreeRstr))

(de *Jump (Arg1)
  (Expand1OperandCMacro Arg1 '*Jump))

(de *Lbl (Arg1)
  (cdr Arg1))

(de *Push (Arg1)
  (Expand1OperandCMacro Arg1 '*Push))

(de *Pop (Arg1)
  (Expand1OperandCMacro Arg1 '*Pop))

(de *Move (Source Destination)
  (prog (ResultingCode* ResolvedDestination)
    (setq ResolvedDestination (ResolveOperand '(REG t2) Destination))
    (return
      (CMacroPatternExpand
	(list (ResolveOperand (cond ((RegisterP ResolvedDestination)
				     ResolvedDestination)
				    (t '(REG t1)))
			      Source)
	      ResolvedDestination)
	(get '*Move 'CMacroPatternTable)))))

(de *JumpEQ (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpEQ))

(de *JumpNotEQ (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpNotEQ))

(de *JumpWLessP (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpWLessP))

(de *JumpWGreaterP (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpWGreaterP))

(de *JumpWLEQ (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpWLEQ))

(de *JumpWGEQ (Label Arg1 Arg2)
  (Expand2OperandAndLabelCMacro Arg1 Arg2 Label '*JumpWGEQ))

(de *MkBPtr (Arg1 Arg2 Arg3)
  (Expand3OperandCMacro Arg1 Arg2 Arg3 '*MkBPtr))

(de *MkBPtr1 (Arg1 Arg2 Arg3)
  (Expand3OperandCMacro Arg1 Arg2 Arg3 '*MkBPtr1))

(de *JumpType (Label Arg TypeTag)
  (Expand2OperandAndLabelCMacro Arg
				(list 'WConst (compiler-constant TypeTag))
				Label
				'*JumpType))

(de *JumpNotType (Label Arg TypeTag)
  (Expand2OperandAndLabelCMacro Arg
				(list 'WConst (compiler-constant TypeTag))
				Label
				'*JumpNotType))

(de *JumpInType (Label Arg TypeTag)
  (Expand2OperandAndLabelCMacro Arg
				(list 'WConst (compiler-constant TypeTag))
				Label
				'*JumpInType))

(de *JumpNotInType (Label Arg TypeTag)
  (Expand2OperandAndLabelCMacro Arg
				(list 'WConst (compiler-constant TypeTag))
				Label
				'*JumpNotInType))

(de *MkItem (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*MkItem))

(de *WPlus2 (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WPlus2))

(de *WDifference (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WDifference))

(de *WTimes2 (Arg1 Arg2)
  (prog (P)
	(return (cond ((and (or (EqCar Arg2 'Quote)
				(EqCar Arg2 'WConst))
			    (setq P (PowerOf2P (cadr Arg2))))
		       (*AShift Arg1 (list (car Arg2) P)))
		      (t (Expand2OperandCMacro Arg1 Arg2 '*WTimes2))))))

(de PowerOf2P (X)
  % If X is a positive power of 2, log base 2 of X is returned.  Otherwise
  % NIL is returned.
  (prog (N)
	(return (cond ((or (not (FixP X)) (MinusP X) (equal X 0)) NIL)
		      (t (progn (setq N 0)
				(while (not (equal (lor x 1) x))
				       (progn (setq N (add1 N))
					      (setq X (lsh X -1))))
				(cond ((equal X 1) N) (T NIL))))))))

(de *AShift (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*AShift))

(de *WShift (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WShift))

(de *WAnd (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WAnd))

(de *WOr (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WOr))

(de *WXOr (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WXOr))

(de *WMinus (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WMinus))

(de *WNot (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*WNot))

(de *Loc (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*Loc))

(de *Field (Arg1 Arg2 Arg3 Arg4)
  (Expand4OperandCMacro Arg1 Arg2 Arg3 Arg4 '*Field))

(de *SignedField (Arg1 Arg2 Arg3 Arg4)
  (Expand4OperandCMacro Arg1 Arg2 Arg3 Arg4 '*SignedField))

(de *PutField (Arg1 Arg2 Arg3 Arg4)
  (Expand4OperandCMacro Arg1 Arg2 Arg3 Arg4 '*PutField))

(de *fast-apply-load (Arg1)
  (Expand1OperandCMacro Arg1 '*fast-apply-load))

(de AnyregCAR (Register Source)
  (OneOperandAnyreg Register Source 'car))

(de AnyregCDR (Register Source)
  (OneOperandAnyreg Register Source 'cdr))

(de AnyregQUOTE (Register Source)
  (ExpandOneArgumentAnyreg Register Source 'quote))

(de AnyregWVAR (Register Source)
  (ExpandOneArgumentAnyreg Register Source 'WVar))

(de AnyregREG (Register Source)
  (ExpandOneArgumentAnyreg Register Source 'REG))

(de AnyregWCONST (Register Source)
  (OneOperandAnyreg Register Source 'WConst))

(DefAnyreg WCONST
	   AnyregWCONST
	   (SOURCE))

(de AnyregFRAME (Register Source)
  (ExpandOneArgumentAnyreg Register
			   (times (compiler-constant 'StackDirection)
				  (compiler-constant 'AddressingUnitsPerItem)
				  (difference 1 Source))
			   'Frame))

(de AnyregFRAMESIZE (Register)
  (times NAlloc* (compiler-constant 'AddressingUnitsPerItem)))

(DefAnyreg FrameSize
	   AnyregFRAMESIZE)

(de AnyregMEMORY (Register Source ArgTwo)
  (TwoOperandAnyreg Register Source ArgTwo 'MEMORY))

(loadtime (flag '(FLUID !$FLUID GLOBAL !$GLOBAL ExtraReg Label) 'TerminalOperand))


(fluid '(labelgen*))		% a-list of tags and labels

% (labelgen tag) and (labelref tag) can be used as either ANYREG or CMACRO.
% (labelgen tag) creates and returns a unique label, (labelref tag) returns
% the same one.  Useful for 'OpenCode lists.

(de anyreglabelgen (reg name)
  ((lambda (lb al)
	   (cond ((null al)
		  (setq labelgen* (cons (cons name lb) labelgen*)))
		 (t (rplacd al lb)))
	   lb)
   (gensym)
   (assoc name labelgen*)))

(defanyreg labelgen anyreglabelgen)

(de labelgen (name)
  (list (anyreglabelgen nil name)))

(defcmacro labelgen)


(de anyreglabelref (reg name) (cdr (assoc name labelgen*)))

(defanyreg labelref anyreglabelref)

(de labelref (name)
  (list (anyreglabelref nil name)))

(defcmacro labelref)
