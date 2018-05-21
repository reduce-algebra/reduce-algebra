%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXC:armv6-CMAC.sl
% Title:          Patterns and predicates for ARM v 6 PSL cmacro expansion
% Author:         Winfried Neun
% Created:        Mai, 5, 2014
% Mode:           Lisp
% Status:         Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(on fast-integers)

(compiletime (load if-system))

(fluid '(AddressingUnitsPerItem CharactersPerWord StackDirection frameregs*
	*usefastframe *ImmediateQuote AddressingUnitsPerFunctionCell))

(global '(*writingasmfile))

(loadtime (off ImmediateQuote))

% The following terminal operands try to follow the same meanings as
% those outlined in the Motorola manuals.
 
(flag '(Immediate                        % #xxx
	UnImmediate                      % used for (unimmediate (immediate x))
	Indirect                         % (An)
	displacement                     % d(An)
	predecrement                     % -(An)
	postincrement                    % (An)+
	Indexed                          % d(An,Dn)
	absolute                         % absolute.long
	extrareg                         % Regs 5 .. 15
	idloc
	reglist)
	'TerminalOperand)
 

(flag '(Immediate UnImmediate Indirect deferred label extrareg Indexed
	displacement) 'TerminalOperand)

% MkItem may be used when evaluating WConst expressions.

%(de MkItem (TagPart InfPart)
%  (lor (lsh TagPart 27) (land InfPart 16#7ffffff)))

(de RegP (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '( 1  2  3  4  5
		     R0 R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 sp st pc lr
		     t1 t2 t3 fp
             nil heaplast heaptrapbound symfnc symval
%	     bndstkptr bndstklowerbound bndstkupperbound
	     ))))
 
(de short-immediate-p (X) (eq x (ashift (wshift x 16) -16)))

(de pos-short-immediate-p (x) (and (numberp x)
		                (lessp x 16#10000) (greaterp x -1)))

(de neg-short-immediate-p (x) (and (numberp x)
				(greaterp x 16#ffff0000) (minusp x)))

(de FiveP (x)  (eq x 5))

(de TwentySevenP (x)  (eq x 27))

(de SixteenP (x) (eq x 16))

(de evenp (x) (and (fixp x) (eq 0 (land x 1))))

(de DeferrableP (Expression)
  (and (PairP Expression)
       (not (memq (first Expression)
	      '(deferred $Fluid $Global Fluid Global)))))

(de RegisterDeferredP (Expression)
  (and (EqCar Expression 'Deferred) (EqCar (second Expression) 'Reg)))

(de FakeRegisterNumberP (Expression)
  (and (IntP Expression) (GreaterP Expression 5)))

% NegativeImmediateP is for numbers whose negative is a one byte operand.

(de negp (value) (and (numberp value) (lessp value 0)))

(de displacementp (x) (and (pairp x) (eq (car x) 'displacement)))

(de NegativeImmediateP (Expression)
  (and (FixP Expression) (minusp Expression) (GreaterP Expression -64)))

% expansions of addressing modes.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                       ANYREG DEFINITIONS
% These are the patterns for anyreg definitions.  They are of the form:
%
% (DefAnyreg ANYREG_NAME RESOLUTION_FUNCTION_NAME
%    ((Register_Predicate1) (Returned value))
%    ((Register_Predicate2) (returned value))
%    ...
% )
 
% The last element in the defintion has no predicate, it is a default
% case.  "Anyregs" are flagged (on their property list) with 'ANYREG.
% They have property indicators ANYREGPATTERNTABLE.  The predicate
% value list, and the function  to call - ANYREGRESOLUTIONFUNCTION.
%
% The associated function of most ANYREG's is called with 2
% arguments, a temporary REGISTER, used in the computation if needed,
% and the single SOURCE.
% The associated function usually uses (OneOperandAnyreg Register  Source
% 'Anyregname) or (ExpandOneArgumentAnyReg Register Source
% 'AnyregName). The 'AnyregName is used to find the associated pattern.
% The MEMORY anyreg has an additional argument, called ARGTWO. The
% (OneOperandAnyreg Register Source Anyregname)%
% calls the lower level ExpandOneArgumentAnyreg, after replacing Source
% by (ResolveOperand Register Source).  This function processes Source
% to see if it is. The MEMORY anyreg means that the location is the
% address of the source or destination.
%It is important that the anyregs DO NOT assign any explicit
% registers because an instruction may have two similar anyregs which
% cause the explicit register to be used twice in the same instruction.
% The future may require a scheme to allocate temporary A and D regs.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(DefAnyreg CAR
	   AnyregCAR   %Grab the source so caller can displace off it.
           (       (!*Field REGISTER SOURCE 5 27)
                   (displacement REGISTER 0))
)

(DefAnyreg CDR
           AnyregCDR     %Same as CAR, except move to next word in pair.
           (       (!*Field REGISTER SOURCE 5 27)
                   (Displacement REGISTER 4)))


(DefAnyreg MEMORY
	   AnyregMEMORY
	   ((RegP ZeroP)      (indirect SOURCE))
	   ((Anyp ZeroP)      (*MOVE SOURCE REGISTER)
			       (indirect REGISTER))
 	   ((RegP twelve-bit-p)      (Displacement SOURCE ARGTWO))
	   ((AnyP twelve-bit-p)      (*MOVE SOURCE REGISTER)
	                       (Displacement REGISTER ARGTWO))
	   ((RegP RegP)       (Indexed ARGTWO (Displacement source 0)))
	   ((RegP AnyP)       (*MOVE SOURCE REGISTER)
			       (*WPLUS2 REGISTER ARGTWO)
			       (indirect REGISTER))
	   ((AnyP DispInumP)  (!*MOVE SOURCE REGISTER)
			       (Indexed REGISTER (Displacement ARGTWO 0)))
	   (                   (!*MOVE SOURCE REGISTER)
			       (!*WPLUS2 REGISTER ARGTWO)
			       (indirect REGISTER)))


(DefAnyreg FRAME
  AnyregFRAME
	   ((zerop)  (Indirect (reg st)))
	   (         (Displacement (REG st) SOURCE)))

% The compiler will tag expressions immediate in the procedure ResolveWConst.
% Only expressions are tagged immediate, not numbers.
 
 
(De AnyRegImmediate(REGISTER SOURCE)
   (cond ((InumP  SOURCE)               SOURCE)
	 ((Eqcar SOURCE 'Unimmediate)   SOURCE)
	 (T                            (list 'immediate SOURCE) )
     ))
 
(DefAnyReg IMMEDIATE
	   AnyRegImmediate)
 
(Defanyreg QUOTE
	   AnyregQUOTE
	   ((BigIntP)  (quote SOURCE))  % more that 32 bits
	   ((IntP)  SOURCE)    %?
           ((Null) (REG NIL))
	   (       (QUOTE SOURCE)))   %? Recursivly expand??
 
(DefAnyreg WCONST
           AnyregWCONST
	   ((BigIntP)  (quote SOURCE))  % more that 32 bits
           (SOURCE))
 
(DefAnyreg REG
	   AnyregREG
	   ((FakeRegP)        (extrareg source))
	   (                  (REG SOURCE)))



%% (fluid '(*nextreg* *nextreglist*))

%% (setq *nextreg* 0        % Four registers should be sufficient
%%       *nextreglist* '((reg t2) ))

%% (de nexttempreg (x)   % ZIB  :This saves Regs , non static assignment
%%      (setq *nextreg* (wplus2 *nextreg* 1))
%%      (when (eq *nextreg* 4) (setq *nextreg* 1))
%%      (nth *nextreglist* *nextreg*))

%% (DefAnyreg Memory  ZIBanyregMemory)  % ZIB

%% (de ZIBAnyregMemory (reg source offset)
%%   (prog (aReg cadrsource)
%%    (setq source (resolveoperand reg source))
%%    (setq offset (resolveoperand reg offset))
%%    (setq aReg (if (and (displacementp source)
%%                     (member (setq cadrsource (cadr source))
%%                                  *nextreglist*))
%%                cadrsource      (nexttempreg)))
%%    (unless (eq 0 offset) (push `(*wplus2 ,aReg ,offset) Resultingcode*))
%%    (push `(*mkitem ,areg (quote 4)) Resultingcode*)
%%    (return `(displacement ,areg 0))))
  
%% (de ibmrs-register-p (r)
%%   (cond ((idp r)
%%          (cond ((get r 'RegisterName) T)
%%                ((get r '*other-name) (ibmrs-register-p (get r '*other-name)))
%%                ((get r '*register-code) t)
%%                ((get r '*f-register-code) t)
%%                ((get r '*c-register-code) t)
%%                (t nil)))
%%         ((eqcar r 'REG) t)
%%         (t nil)))


(loadtime (remflag '(fluid global $fluid $global) 'Terminaloperand))

(DefAnyreg Fluid ZIBanyregfluid)

(DefAnyreg $Fluid ZIBanyregfluid)

(de ZIBanyregFluid (reg source)
   (cond ((and (idp source) (get source 'RegisterName))
		         `(reg ,(get source 'RegisterName)))
	 (t       `($Fluid ,SOURCE))))

(DefAnyreg Global ZIBanyregglobal)

(DefAnyreg $Global ZIBanyregglobal)

(de ZIBanyregGlobal (reg source)
   (cond ((and (idp source) (get source 'RegisterName))
		         `(reg ,(get source 'RegisterName)))
	 (t       `($global ,SOURCE))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                        CMACRO DEFINITIONS
% Remember that it IS legal to use Other CMACROS in expansions%
% or to define "fake" cmacros, ie procedures, for%
% Common cases. If a new C-macro is not standard,%
% e.g (*WFOO argone argtwo), then define its table and procedure.%
% You may have to define some more "anyregs" or 'TerminalOperands%
% Or define predicates to be CAREFUL.%
% (def Cmacro *WFOO%
%      ...... )%
% (de *WFOO (Arg1 Arg2)%
%   (Expand2OperandCmacro Arg1 Arg2 '*Wfoo))%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 

(DefCMacro *Call
       ((InternallyCallableP)  (blx (InternalEntry ArgOne)))
	(         (*move (idloc argone) (reg t3))
		  (add (reg t2) (reg symfnc) (regshifted t3 LSL 2))
		  (blx (reg t2)))
)

(DefCMacro *JCall
       ((InternallyCallableP)  (b (InternalEntry ArgOne)))
	(         (*move (idloc argone) (reg t3))
		  (add (reg t2) (reg symfnc) (regshifted t3 LSL 2))
		  (BX (reg t2)))
)

(de indirectp (x)
    (eqcar x 'indirect))

(de idlocp (x) (eqcar x 'idloc))

(remprop '*move 'optfn)

(DefCMacro *Move
       (Equal)
       ((regp regp)	    	 (MOV ArgTwo ArgOne))
       ((imm8-rotatedp regp)     (mov Argtwo ArgOne))
       ((immediatep regp)        (mov Argtwo ArgOne))
       ((fixp regp)              (*LoadConstant ArgTwo (quote ArgOne)))
       ((idlocp regp)            (*LoadConstant ArgTwo ArgOne))
       ((fluid-arg-p regp)       (*LoadIdNumber LDR ArgTwo ArgOne))
       ((indirectp regp)         (LDR ArgTwo ArgOne))
       ((regp fluid-arg-p)       (*LoadIdNumber STR ArgOne ArgTwo))
       ((regp indirectp)         (STR ArgOne ArgTwo))
       ((regp anyp)              (str ArgOne ArgTwo))
       ((anyp regp)              (ldr ArgTwo ArgOne))
       (                         (*move ArgOne (reg t3))
				 (*move (reg t3) ArgTwo)))

(de *LoadConstant (dest cst)
  (setq cst (WConstEvaluable cst))
  (if (imm8-rotatedp cst)
      `( (mov ,dest ,cst))
    (progn
%      (setq cst (SaveConstant cst))
      `( (ldr ,dest (quote ,cst)))))
)

(DefCMacro *LoadConstant)

(de *LoadIdNumber (load-or-store reg nonlocal)
  (let ((idnumber
	 (WConstEvaluable `(idloc ,(cadr nonlocal)))))
    (if (and (fixp idnumber) (lessp idnumber 1024) (greaterp idnumber -1024))
	`( (,load-or-store ,reg (displacement (reg symval) ,(times 4 idnumber))) )
      `( (LDR (reg t2) (quote ,idnumber))
	 (,load-or-store ,reg (displacement (reg symval) (regshifted t2 LSL 2))) )
      )))

(DefCMacro *LoadIdNumber)

(de *ALLOC (framesize)
    (setq NAlloc!* framesize)
    (if (greaterp framesize 0)
	`( (stm (reg st) ((reg lr)) writeback)
	   (sub (reg st) (reg st) ,(times2 4 framesize)))
      `((stm (reg st) ((reg lr)) writeback))))

(DefCmacro *ALLOC)

(DefCmacro *DeAlloc
	   ((ZeroP))
	   (           (add (reg st) (reg st) ARGONE)))
	   
(de *Exit (N)
 (Expand1OperandCMacro
   (times N (compiler-constant 'AddressingUnitsPerItem)) '*Exit))

(DefCMacro *Exit     % leaf routine first
   ((ZeroP)  (ldm (reg sp) ((reg lr)) writeback)
             (bx (reg lr)))
   (         (add (reg st) (reg st) ARGONE)
	     (ldm (reg sp) ((reg lr)) writeback)
	     (bx (reg lr))))

(de displacementp (x) (and (pairp x) (eq (car x) 'displacement)))

(de deferredp (x) (eqcar x 'deferred))

(DefCMacro *Jump
       (                  (b ArgOne)))


(DefCMacro *Lbl           (ArgOne))

(DefCMacro *Push
  ( (STR ArgOne (displacement (reg st) 0 postindexed))))

(DefCMacro *Pop
  ( (LDR ArgOne (displacement (reg st) 0 postindexed))))

(de *3op (a1 a2 instruction)
  (prog (ResultingCode*)
    (return (CMacroPatternExpand
	   (list (ResolveOperand '(Reg t1) A1)
		 (ResolveOperand '(Reg t2) A2)
		  Instruction)
		 (get '*3op 'CMacroPatternTable)))))

(DefCMacro *3op
       ((regp regp) (ArgThree ArgOne ArgOne ArgTwo ))
       ((regp imm8-rotatedp)
		      (ArgThree ArgOne ArgOne ArgTwo ))
       ((regp AnyP)  (*move ArgTwo (reg T3))
		      (*3op ArgOne (reg t3) ArgThree))
       ((Anyp regp)  (*move ArgOne (reg T3))
		      (ArgThree (reg t3) ArgTwo (reg t3))
		      (*move (reg t3) ArgOne))
       ((Anyp imm8-rotatedp)
		      (*move ArgOne (reg T2))
		      (ArgThree (reg t3) (reg t2) ArgTwo)
		      (*move (reg t3) ArgOne))
       (              (*move ArgTwo (reg T3))
		      (*move ArgOne (reg T2))
		      (ArgThree (reg t3) (reg t3) (reg t2))
		      (*move (reg t3) ArgOne)))

(DefCMacro *WPlus2)

(de *wplus2 (arg1 arg2) (when (not (zerop arg2))(*wplus3 arg1 arg1 arg2)))

(de *wplus3(arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wplus3))

(DefCMacro *WPlus3
	   ((regp regp regp) (add ArgOne ArgTwo ArgThree))
	   ((regp imm8-rotatedp regp)
		                (add ArgOne Argthree ArgTwo))
	   ((regp regp imm8-rotatedp)
		                (add ArgOne ArgTwo ArgThree ))
	   ((regp imm8-rotatedp anyp)
		               (*move ArgThree (reg t3))
		               (add ArgOne (reg t3) ArgTwo))
	   ((regp anyp imm8-rotatedp)
		               (*move ArgTwo (reg t3))
		               (add ArgOne (reg t3) ArgThree))
	   ((regp regp anyp)  (*move ArgThree (reg t3))
		               (add ArgOne ArgTwo (reg t3)))
	   ((anyp regp anyp)  (*move ArgThree (reg t3))
		               (add (Reg t3) ArgTwo (reg t3))
		               (*move (reg t3) ArgOne))
	   (                   (*move ArgTwo (reg t3))
		               (*move ArgThree (reg t2))
		               (add (reg t3) (reg t2) (reg t3))
		               (*move (reg t3) ArgOne)))

(DefCMacro *WDifference
       ((*Wdifference3 ArgOne ArgOne ArgTwo)))

(de *wdifference3 (arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wdifference3))

% format ArgOne = ArgTwo - ArgThree

(DefCMacro *Wdifference3
	   ((regp regp regp) (sub ArgOne ArgTwo ArgThree))
	   ((regp regp imm8-rotatedp)
				(sub ArgOne ArgTwo ArgThree))
	   ((regp anyp regp) (*move ArgTwo (reg t3))
		               (sub ArgOne ArgThree (reg t3) ))
	   ((regp anyp anyp)  (*move ArgTwo (reg t3))
		               (*move ArgThree (reg t2))
		               (sub ArgOne (reg t2) (reg t3)))
	   ((anyp regp anyp)  (*move ArgThree (reg t3))
		               (sub (Reg t3) (reg t3) ArgTwo )
		               (*move (reg t3) ArgOne))
	   (                   (*move ArgTwo (reg t3))
		               (*move ArgThree (reg t2))
		               (sub (reg t3) (reg t2) (reg t3))
		               (*move (reg t3) ArgOne)))

(defcmacro *wtimes2)

(de *wtimes2 (arg1 arg2) (*wtimes3 arg1 arg1 arg2))

(de *wtimes3 (arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wtimes3))

% format ArgOne = ArgTwo * ArgThree

(DefCMacro *wtimes3
	   ((regp regp regp) (mul ArgOne ArgTwo ArgThree))
	   ((regp anyp regp) (*move ArgTwo (reg t1))
	                     (mul ArgOne (reg t1) Argthree))
	   ((regp regp anyp) (*move argthree (reg t1))
			     (*wtimes3 ArgOne ArgTwo (reg t1)))
	   (        (*move ArgTwo (Reg t1))
		    (*move ArgThree (reg t2))
		    (mul (reg t1) (Reg t1) (reg t2))
		    (*move (reg t1) ArgOne)))
 
(DefCMacro *wquotient)

(de *wquotient (arg1 arg2) (*wquotient3 arg1 arg1 arg2))

(de *wquotient3 (arg1 arg2 arg3)
    (Expand3OperandCmacro arg1 arg2 arg3 '*wquotient3))

% format ArgOne = ArgTwo / ArgThree

(DefCMacro *wquotient3              
	 ((anyp anyp onep)       (*move argtwo argone))
	 ((regp regp powerof2p)  (*wquotientshift ArgOne ArgTwo ArgThree))
	 ((regp regp regp)       (*sdiv ArgOne ArgTwo Argthree))
	 ((regp regp anyp)       (*move argthree (reg t1))
		                 (*wquotient3 ArgOne ArgTwo (reg t1)))
	   (        (*move ArgTwo (Reg t1))
		    (*move ArgThree (reg t2))
		    (*sdiv (reg t1) (Reg t1) (reg t2))
		    (*move (reg t1) ArgOne)))

(de *wquotientshift (arg1 arg2 arg3)
	(setq arg3 (powerof2p arg3))
	`((*asr arg1 arg2 arg3)))

(DefCMacro *wquotientshift)

(DefCMacro *wremainder
	   (       (*move ArgOne (reg t2))
	           (*move ArgTwo (reg t1))
		   (*sdiv (reg t2) (reg t2) (reg t1))
		   (mul (reg t1) (reg t1) (reg t2))
		   (*wdifference3 ArgOne ArgOne (reg t1))))
				
(DefCMacro *WAnd
       ((*3op ArgOne ArgTwo and)))

(DefCMacro *WOr
       ((*3op ArgOne ArgTwo orr)))

(DefCMacro *WXOr
       ((*3op ArgOne ArgTwo eor)))

(de fixplusp (x) (and (fixp x) (not (minusp x))))

(de *asr (Arg1 Arg2 Arg3)
  (Expand3OperandCMacro Arg1 Arg2 Arg3 '*asr))

(de *lsr (Arg1 Arg2 Arg3)
  (Expand3OperandCMacro Arg1 Arg2 Arg3 '*lsr))

(de *lsl (Arg1 Arg2 Arg3)
  (Expand3OperandCMacro Arg1 Arg2 Arg3 '*lsl))


(DefCMacro *asr
    ((mov ArgOne (regshifted ArgTwo ASR ArgThree))))

(DefCMacro *lsr
    ((mov ArgOne (regshifted ArgTwo LSR ArgThree))))

(DefCMacro *lsl
    ((mov ArgOne (regshifted ArgTwo LSL ArgThree))))

(DefCMacro *AShift
    ((AnyP ZeroP))
    ((regp negp)     (mov ArgOne (regshifted ArgOne ASR (minus ArgTwo))))
    ((regp fixplusp) (mov ArgOne (regshifted ArgOne LSL ArgTwo)))
    ((regp regp)     (cmp ArgTwo 0)
                      (bge templabel)
                      (rsb (reg t2) ArgOne 0)
                      (*asr ArgOne ArgOne (reg t2))
                      (b templabel2)
                     templabel
                      (*lsl ArgOne ArgOne ArgTwo)
                     templabel2)

    ((regp anyp)     (*move ArgTwo (reg t3))
		      (*ashift ArgOne (reg t3)))
    ((Anyp fixp)      (*move ArgOne (reg t3))
		      (*ashift (reg t3) ArgTwo)
		      (*move (reg t3) ArgOne))
    (                 (*move ArgOne (reg t1))
		      (*ashift (reg t1) ArgTwo)
		      (*move (reg t1) ArgOne))
)


(DefCMacro *WShift
    ((AnyP ZeroP))
    ((regp negp)     (*lsr ArgOne ArgOne (minus ArgTwo)))
    ((regp fixplusp) (*lsl ArgOne ArgOne ArgTwo))
    ((regp regp)     (cmp argtwo 0)
		      (bge templabel)
                      (rsb (reg r0) ArgTwo 0)
		      (*lsl ArgOne Argone (reg r0))
                      (b templabel2)
                     templabel
                      (*lsl ArgOne ArgOne ArgTwo)
                     templabel2)
    ((regp anyp)     (*move ArgTwo (reg t3))
		      (*wshift ArgOne (reg t3)))
    ((Anyp fixp)      (*move ArgOne (reg t3))
		      (*wshift (reg t3) ArgTwo)
		      (*move (reg t3) ArgOne))
    (                 (*move ArgOne (reg t1))
		      (*wshift (reg t1) ArgTwo)
		      (*move (reg t1) ArgOne)))

(DefCMacro *WNot
       ((regp regp)  (mvn ArgOne ArgTwo))
       ((regp imm8-rotatedp) (mvn ArgOne ArgTwo))
       ((regp Anyp)  (*move ArgTwo ArgOne)
		      (mvn ArgOne ArgOne))
       (	     (*move ArgTwo (reg t3))
		      (*wnot (reg t3) (reg t3))
		      (*move (reg t3) ArgOne)))

(DefCMacro *WMinus
	((regp regp)  (rsb ArgOne ArgTwo 0))
	((regp Anyp)  (*move ArgTwo ArgOne)
		      (rsb ArgOne ArgOne 0))
	(	      (*move ArgTwo (reg t3))
	        	(*wminus (reg t3) (reg t3))
			(*move (reg t3) ArgOne)))

(DefCMacro *MkItem
       ((regp fixp)	(MOV ArgOne (regshifted Argone LSL 5))
                        (ORR ArgOne ArgOne (land ArgTwo 31))
			(MOV ArgOne (regshifted ArgOne ROR 5)))
       ((regp regp)	(and (reg t3) ArgOne 31)
                        (MOV ArgOne (regshifted Argone LSL 5))
			(ORR ArgOne ArgOne (reg t3))
                        (MOV ArgOne (regshifted ArgOne ROR 5)))
       ((regp anyp)	(*move ArgTwo (reg t3))
			 (*Mkitem ArgOne (reg t3)))
       (                (*move ArgOne (reg t1))
		         (*mkitem (reg t1) ArgTwo)
		         (*move (reg t1) ArgOne)))

(DefCmacro *Tag
      ((regp regp) (MOV ArgOne (regshifted ArgTwo LSR 27)))
      ((Anyp regp) (MOV (reg t1) (regshifted ArgTwo LSR 27))
		    (*move (reg t1) ArgOne))
      ((regp anyp) (*move ArgTwo ArgOne))
		    (MOV ArgOne (regshifted ArgOne LSR 27))
      (             (*move ArgTwo (reg t1))
		    (*Tag ArgOne (reg t1))))

(de *Tag (ar1 ar2)
     (Expand2OperandCMacro ar1 ar2 '*Tag))


(de jump-immediate-offset-p (x) (offset26-p x))

(DefCMacro *JumpType
      (             (*Tag (Reg t3) ArgOne)
		    (*JumpEQ ArgThree (Reg t3) ArgTwo)))

(DefCMacro *JumpNotType
      (             (*Tag (Reg t3) ArgOne)
		    (*JumpNOTEQ ArgThree (Reg t3) ArgTwo)))

(DefCMacro *JumpInType
       ((regp Anyp) (*Tag (reg t3) ArgOne)
		     (cmp (reg t3) ArgTwo )
		     (bge  ArgThree)
		     (cmp (reg t3) 31) % negint-tag)
		     (beq ArgThree))
       (             (*move ArgOne (reg t3))
		     (*Tag (reg t2) (reg t3))
		     (cmp (reg t2) ArgTwo)
		     (bge GT ArgThree)
		     (cmp (reg t2) 31) % negint-tag
		     (beq ArgThree)))

(DefCMacro *JumpNotInType
       ((regp Anyp) (*Tag (reg t3) ArgOne)
		     (cmp (reg t3) 31) % negint-tag
		     (beq templabel)
		     (cmp (reg t3) ArgTwo)
		     (bgt ArgThree)
		    templabel)
       (             (*move ArgOne (reg t3))
		     (*Tag (reg t3) (reg t3))
		     (cmp (reg t3) 31) % negint-tag
		     (beq templabel)
		     (cmp (reg t3) ArgTwo)
		     (bgt ArgThree)
		    templabel))

%---------------------------------------------------------------------
%   General Purpose Jumper.
%   FORMAT: Operand1 Operand2 Address JumpOpCode

(DefCMacro *JumpIf
     ((regp regp)       (cmp ArgOne ArgTwo)
		         (ArgFour ArgThree))
     ((regp imm8-rotatedp) (cmp ArgOne ArgTwo)
			 (ArgFour ArgThree))
     ((regp anyp)       (*move ArgTwo (reg t3))
		         (cmp ArgOne (reg t3))
		         (ArgFour ArgThree))
     ((anyp  regp)      (*move ArgOne (reg t3))
		         (cmp (reg t3) ArgTwo )
		         (ArgFour ArgThree))
     ((anyp imm8-rotatedp) (*move ArgOne (reg t3))
		         (cmp (reg t3) ArgTwo)
		         (ArgFour ArgThree))
     (                   (*move ArgOne (reg t3))
		         (*move ArgTwo (reg t2))
		         (cmp (reg t3) (reg t2))
		         (ArgFour ArgThree)))

(de *JumpIF (ArgOne ArgTwo Label Instructions)
  (prog (ResultingCode*)
    (return (CMacroPatternExpand
	   (list (ResolveOperand '(Reg t1) ArgOne)
		 (ResolveOperand '(Reg t2) ArgTwo)
		 (ResolveOperand '(Reg Error) Label)
		 (car Instructions)
		 (cdr Instructions)
		 )
		 (get '*JumpIF 'CMacroPatternTable)))))

(DefCMacro *jumpeq)

(de *jumpeq (Lbl ArgOne ArgTwo)
       (*jumpif ArgOne ArgTwo lbl '(beq . beq)))

(DefCMacro *jumpnoteq)

(de *jumpnoteq(Lbl ArgOne ArgTwo)
	(*jumpif ArgOne ArgTwo lbl '(bne . 'bne)))

(DefCMacro *jumpwlessp)

(de *jumpwlessp (Lbl ArgOne ArgTwo)
	(*jumpif ArgOne ArgTwo lbl '(blt . bge)))

(DefCMacro *jumpwgreaterp)

(de *jumpwgreaterp (Lbl ArgOne ArgTwo)
	(*jumpif ArgOne ArgTwo lbl '(bgt . ble)))

(DefCMacro *jumpwleq)

(de  *jumpwleq(Lbl ArgOne ArgTwo)
	(*jumpif ArgOne ArgTwo lbl '(ble . bgt)))

(DefCMacro *jumpwgeq)

(de *jumpwgeq (Lbl ArgOne ArgTwo)
	(*jumpif ArgOne ArgTwo lbl '(bge . blt)))

% --------------------

(de fluid-arg-p (x)
    (and (pairp x)
     (member (car x) '(!$fluid !$global fluid global))))


(de *loc (ArgOne ArgTwo)
   (let ((resolvedarg (resolveoperand '(reg t2) ArgTwo)))
      (cond ((deferred-p resolvedarg)
	 `((*move (undeferred ,resolvedarg) ,ArgOne))) % get the address.
	 ((displacement-p resolvedarg)
	    `((ai ,ArgOne ,(cadr resolvedarg) ,(caddr resolvedarg) )))
	 ((eqcar resolvedarg 'cdr)
	    `((ai ,ArgOne ,(cadr resolvedarg) 4)))
	 (t `((*movex ,resolvedarg ,ArgOne))))))

(DefCMacro *loc)



(DefCMacro *Field

  ((regp regp Fivep TwentySevenP) (BIC ArgOne ArgTwo 16#F8000000))
  ((regp anyp Fivep TwentySevenP) (*move ArgTwo ArgOne)
                                   (BIC ArgOne ArgOne 16#F8000000))
  ((regp regp zerop fixp) (*lsr ArgOne ArgTwo (difference 32 ArgFour)))
  ((regp regp fixp fixp) (*lsl ArgOne ArgTwo ArgThree)
                         (*lsr ArgOne ArgOne (difference 32 ArgFour)))
  ((regp anyp fixp fixp) (*move ArgTwo (reg t3))
                         (*Field ArgOne (reg t3) ArgThree ArgFour))
  ((anyp regp fixp fixp) (*Field (reg t3) ArgTwo ArgThree ArgFour)
		          (*move (reg t3) ArgOne))
  (                      (*move ArgTwo (reg t2))
		          (*Field (reg t3) (reg t2) ArgThree ArgFour)
		          (*move (reg t3) ArgOne)))

(DefCMacro *SignedField

  ((regp regp zerop fixp) (*asr ArgOne ArgTwo (difference 32 ArgFour)))
  ((regp regp fixp fixp) (*lsl ArgOne ArgTwo ArgThree)
                         (*asr ArgOne ArgOne (difference 32 ArgFour)))
  ((regp anyp fixp fixp) (*move ArgTwo (reg t3))
		         (*lsl ArgOne (reg t3) ArgThree)
			 (*asr ArgOne ArgOne (difference 32 ArgFour)))
  ((anyp regp fixp fixp) (*Signedfield (reg t3) ArgTwo ArgThree ArgFour)
	 		  (*move (reg t3) ArgOne))
  (                      (*move ArgTwo (reg t2))
		          (*Signedfield (reg t3) (reg t2) ArgThree ArgFour)
		          (*move (reg t3) ArgOne)))

% following is used by garbage collector only. Not very useful to
% optimize other cases than put inf field or put tag field (with constant)

(de BitMask (StartingBit Length)
  (prog(x)
    (setq x (wshift -1 (wminus StartingBit)))
    (return (wand 16#ffffffff (wand x (wshift -1 
       (wdifference 32 (wplus2 StartingBit Length))))))))
 
(de NegMask (Length) (wshift -1 length))
 
(ds ShiftAmt (StartingBit Length)
  (wdifference 32
          (wplus2 StartingBit Length) %always positive.
          ))
 
(DefCMacro *PutField
  ((imm8-rotatedp regP Fivep TwentySevenP)
                     (AND ArgTwo ArgTwo 16#F8000000)
                     (ORR ArgTwo ArgTwo ArgOne))
	   
  ((InumP regP Fivep TwentySevenP)
                     (*Move ArgOne (reg t1))
                     (AND ArgTwo ArgTwo 16#F8000000)
                     (ORR ArgTwo ArgTwo (reg t1)))

  ((RegP regP Fivep TwentySevenP)
                     (AND ArgTwo ArgTwo 16#F8000000)
		     (BIC ArgOne ArgOne 16#F8000000)
                     (ORR ArgTwo ArgTwo ArgOne))

%  ((InumP regP ZeroP SixteenP)
%                     ( and  (LNOT (BITMASK  ARGTHREE ARGFOUR)) ARGTWO)
%                     ( or   (LAND (BITMASK  ARGTHREE ARGFOUR)
%                             (LSHIFT ARGONE (SHIFTAMT ARGTHREE ARGFOUR)))
%                   ARGTWO))

  ((InumP regP ZeroP AnyP)
                     ( *WAnd ArgTwo (LAND 16#ffffffff (LNOT (BITMASK  ARGTHREE ARGFOUR))))
                     ( *WOr ArgTwo (LAND (BITMASK  ARGTHREE ARGFOUR)
					 (LSHIFT ARGONE (SHIFTAMT ARGTHREE ARGFOUR)))
			    ))
  ((InumP regP AnyP  AnyP)
                     (*WAND   ARGTWO (LAND 16#ffffffff (LNOT (BITMASK  ARGTHREE ARGFOUR))))
                     (*WOR    ARGTWO (LAND (BITMASK  ARGTHREE ARGFOUR)
                             (LSHIFT ARGONE (SHIFTAMT ARGTHREE ARGFOUR)))))
 
  ((regP regP ZeroP AnyP)
                     (*WSHIFT ARGONE       (SHIFTAMT ARGTHREE ARGFOUR))
                     (*WAND  ARGTWO (LAND 16#ffffffff (LNOT (BITMASK  ARGTHREE ARGFOUR)) ))
                     (*Wor   ARGONE ARGTWO))
  ((regP regP AnyP AnyP)
                     (*WSHIFT ARGONE       (SHIFTAMT ARGTHREE ARGFOUR))
                     (*Wand ArgOne (BITMASK  ARGTHREE ARGFOUR))
                     (*WAND   ARGTWO (LAND 16#ffffffff (LNOT (BITMASK  ARGTHREE ARGFOUR))))
                     (*WOR    ARGTWO ARGONE))
  ((AnyP  regP AnyP AnyP)
                     (*MOVE ARGONE (reg t1))
             (*PUTFIELD    (Reg T1) ARGTWO ARGTHREE ARGFOUR))
  (                  (*MOVE ARGTWO     (reg t1))
                     (*PUTFIELD ARGONE (Reg T1) ARGTHREE ARGFOUR)
                     (*MOVE            (reg t1) ARGTWO))
 )
 

(deflist '((Byte        ((ldrsb (reg 1) (displacement (reg 2) (reg 1)))))
	   (PutByte     ((strb (reg 3) (displacement (reg 2) (reg 1)))))
	   (HalfWord    ((ldrsh (reg 1) (displacement (reg 2) (reg 1)))))
	   (PutHalfWord ((strh (reg 3) (displacement (reg 2) (reg 1))))))
  'OpenCode)

(&OneReg '(Byte PutByte HalfWord PutHalfWord))

(on fast-integers)

(commentoutcode
(for (in function '(idapply0 idapply1 idapply2 idapply3 idapply4))
     (from register 1)
     (do
      (put function 'opencode
	 `((ai (reg t1) (reg symfnccenter) -32000)
	   (rlinm (reg t2) (reg ,register) 2 5 31)
	   (lx (reg t1) (reg t1) (reg t2))
	   (*move (reg ,register) (reg t3))
	   (mtspr (reg ctr) (reg t1))
	   (bccl always 0)))
      (put function 'exitopencode
	 `((ai (reg t1) (reg symfnccenter) -32000)
	   (rlinm (reg t2) (reg ,register) 2 5 31)
	   (lx (reg t1) (reg t1) (reg t2))
	   (*move (reg ,register) (reg t3))
	   (mtspr (reg ctr) (reg t1))
	   (bcc always 0)))
))
)

(commentoutcode
(for (in function '(addressapply0 addressapply1 addressapply2
		addressapply3 addressapply4))
     (from register 1)
     (do
      (put function 'opencode
	 `((mtspr (reg ctr) (reg ,register))
	   (bccl always 0)))
      (put function 'exitopencode
	 `((mtspr (reg ctr) (reg ,register))
	   (bcc always 0)))
      ))
)

% *feq, *fgreaterp and *flessp can only occur once in a function.

(commentoutcode
 deflist '((*wfix ((ld (reg t2) (displacement (reg 1) 4))
		   (ld (reg t1) (displacement (reg 1) 0))
		   (trnc!.sd (reg 1) (reg t1))))
	   (*wfloat ((flt!.ds (reg t1) (reg 2))
		     (st (reg t2) (displacement (reg 1) 4))
		     (st (reg t1) (displacement (reg 1) 0))))
	   (*fgreaterp
		    ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16))
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (*move (quote t) (reg 1))
		     (fcmpo 0 (freg 1) (freg 2))
		     (bc true gt *donefgreaterp*)
		     (*move (reg nil) (reg 1))
		*donefgreaterp*))
	   (*flessp ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16))
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (*move (quote t) (reg 1))
		     (fcmpo 0 (freg 1) (freg 2))
		     (bc true lt *doneflessp*)
		     (*move (reg nil) (reg 1))
		*doneflessp*))
	   (*fplus2 ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16)) 
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (fa (freg 3) (freg 1) (freg 2))
		     (stfd (freg 3) (displacement (reg st) -12))
		     (l (reg t4) (displacement (reg st) -16))
		     (l (reg t3) (displacement (reg st) -12))
		     (st (reg t4) (displacement (reg 1) 4))
		     (st (reg t3) (displacement (reg 1) 0))))
	   (*fdifference
		    ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16))
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (fs (freg 3) (freg 1) (freg 2))
		     (stfd (freg 3) (displacement (reg st) -12))
		     (l (reg t4) (displacement (reg st) -16))
		     (l (reg t3) (displacement (reg st) -12))
		     (st (reg t4) (displacement (reg 1) 4))
		     (st (reg t3) (displacement (reg 1) 0))))
	   (*ftimes2 ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16))
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (fm (freg 3) (freg 1) (freg 2))
		     (stfd (freg 3) (displacement (reg st) -12))
		     (l (reg t4) (displacement (reg st) -16))
		     (l (reg t3) (displacement (reg st) -12))
		     (st (reg t4) (displacement (reg 1) 4))
		     (st (reg t3) (displacement (reg 1) 0))))
	   (*fquotient
		    ((l (reg t2) (displacement (reg 2) 4))
		     (l (reg t1) (displacement (reg 2) 0))
		     (l (reg t4) (displacement (reg 3) 4))
		     (l (reg t3) (displacement (reg 3) 0))
		     (st (reg t2) (displacement (reg st) -4))
		     (st (reg t1) (displacement (reg st) -8))
		     (st (reg t4) (displacement (reg st) -12))
		     (st (reg t3) (displacement (reg st) -16))
		     (lfd (freg 1) (displacement (reg st) -8))
		     (lfd (freg 2) (displacement (reg st) -16))
		     (fd (freg 3) (freg 1) (freg 2))
		     (stfd (freg 3) (displacement (reg st) -12))
		     (l (reg t4) (displacement (reg st) -16))
		     (l (reg t3) (displacement (reg st) -12))
		     (st (reg t4) (displacement (reg 1) 4))
		     (st (reg t3) (displacement (reg 1) 0)))))
	 'opencode)

(DefCMacro *fast-apply-load
   ( (*move ArgOne (reg t1)) ))

(put 'fast-idapply    'opencode
     '((*move (reg t1) (reg t2)) % save id number
       (*wshift (reg t2) 2)	   % times 4
       (ldr (reg t2) (displacement (reg symfnc) (reg t2)))
       (blx (reg t2))))
     
(put 'fast-idapply    'exitopencode
     '((*move (reg t1) (reg t2)) % save id number
       (*wshift (reg t2) 2)	   % times 4
       (ldr (reg t2) (displacement (reg symfnc) (reg t2)))
       (bx (reg t2))))

(put 'fast-codeapply    'opencode
     '((*field (reg t2) (reg t2) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
       (blx (reg t2))))

(put 'fast-codeapply    'exitopencode
	'((*field (reg t2) (reg t2) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
	  (bx (reg t2))))

(De *LamBind (Regs Fluids)

 % be careful, code is somewhat tricky

 (prog (n lng list cregs cfluids cadrcfluids initload freeregs genlabel)
      
      (setq genlabel (gensym))
      (setq n 0)
      (setq Regs (rest Regs))   % Remove "Registers" from the front
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Regs) 8)) % two words per BndStk entry *4

   %looking for free register to preload values of fluid s

      (setq freeregs (mapcan '((reg 1)(reg 2)(reg 3)(reg 4)(reg 5))
		   (function (lambda (x)
		                (cond ((member x regs) nil)
		                       (t (cons x nil))
      )              ) )         )  )
      (setq freeregs (nconc (list '(reg T3)) freeregs))
      (setq cfluids fluids) % copy of fluids

preload  (setq initload
       (progn (setq cadrcfluids
		(nconc cadrcfluids (cons (car freeregs) nil)))
	(nconc initload `((*move ,(car cfluids) ,(car freeregs))))
       )   )
       (setq freeregs (cdr freeregs))
       (setq cfluids (cdr cfluids))

       (cond ((and freeregs cfluids) (go preload)))

       (setq freeregs (nconc cadrcfluids cfluids)) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and not preloaded fluids if those exist

      (setq list `((*move ($fluid BndStkPtr) (Reg t1))
		   (*wplus3 (Reg t2) (Reg t1) ,lng)
		   (*move ($fluid BndstkUpperBound) (reg t1))
		   (cmp (reg t2) (reg t1))
		   (bmi ,genlabel)
		   (*call Bstackoverflow) % never come back
		  ,genlabel
		   (*move (Reg t2) ($fluid BndstkPtr))   )) %start of code

      (setq list (append initload list))

  loop
      (setq cregs (car Regs))
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	   (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 8))
      (Setq list (append list
     `((*move ,(car freeregs) (indexed (Reg t1) ,n))
       (*move (quote ,Cadrcfluids)
		   (indexed (reg t1) ,(wplus2 n -4)))
       (*move ,cregs ,cfluids)
      )          ))
      (setq fluids (cdr Fluids))
      (setq freeregs (cdr freeregs))
      (cond ((setq regs (cdr Regs)) (go loop)))
      (return list)
)    )

(DefCMacro !*lambind)

(De *ProgBind (Fluids)

 % be careful, code is somewhat tricky

 (prog (n lng list cfluids cadrcfluids genlabel initload freeregs)
      (setq genlabel (gensym))
      (setq n 0)
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Fluids) 8)) % two words per BndStk entry
		                         % * 4 addressingunits
      (setq freeregs '((reg t3)(reg T4)(reg 1)(reg 2)(reg 3)(reg 4)(reg 5)))
      (setq cfluids fluids) % copy of fluids

preload  (setq initload
       (progn (setq cadrcfluids
		(nconc cadrcfluids (cons (car freeregs) nil)))
	(nconc initload `((*move ,(car cfluids) ,(car freeregs))))
       )   )
       (setq freeregs (cdr freeregs))
       (setq cfluids (cdr cfluids))

       (cond ((and freeregs cfluids) (go preload)))

       (setq freeregs (nconc cadrcfluids cfluids)) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and not preloaded fluids if those exist


      (setq list `((*move ($fluid BndStkPtr) (Reg t1))
                   (*wplus3 (reg t2) (reg t1) ,lng)
		   (*move ($fluid BndstkUpperBound) (reg t1))
		   (cmp (reg t2) (reg t1))
		   (bmi ,genlabel)
                   (*call Bstackoverflow)  % is never come back
		   ,genlabel
		   (*move (Reg t2) ($fluid BndstkPtr))   )) %start of code

      (setq list (append initload list))

 loop
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	   (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 8))
      (Setq list (append list
	     `((*move ,(car freeregs) (indexed (Reg t1) ,n))
	       (*move (quote ,Cadrcfluids)
		           (indexed (reg t1)  ,(wplus2 n -4)))
	       (*move (quote nil) ,cfluids)
      )          ))
      (setq freeregs (cdr freeregs))
      (cond ((setq Fluids (cdr Fluids)) (go loop)))
      (return list)
)    )

(DefCMacro *progbind)

(De *FreeRstr (Fluids)

 (prog (n lng list cfluids listfluids genlabel initload freeregs)
      (setq genlabel (gensym))
      (setq n 0)
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Fluids) 2)) % two words per BndStk entry
      (setq freeregs '((reg t3)(reg t4)(reg 2)(reg 3)(reg 4)(reg 5)))
      (setq cfluids fluids) % copy of fluids
      (setq n (wtimes2 4 (wdifference 2 lng)))
      (setq lng (wtimes2 lng 4)) % * addressingunitperitem
      (setq initload (list '(*move ($fluid Bndstkptr) (reg t1))))
      (setq n 0)

preload  (setq initload
       (progn (setq listfluids
	       (if freeregs
		(nconc listfluids (cons (car freeregs) nil))
		(nconc listfluids (cons nil nil))) )
	(nconc initload
	 (if freeregs
     `((*move (displacement (reg t1) ,n) ,(car freeregs))) nil)
       )   ))
       (setq n (wplus2 n 8))
       (when freeregs (setq freeregs (cdr freeregs)))
       (setq cfluids (cdr cfluids))

       (cond (cfluids (go preload)))

       (setq freeregs listfluids ) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and nil if not enough regs available

       (setq list `((sub (reg t2) (reg t1) ,lng)
		    (*move ($fluid BndstkLowerBound) (reg t1))
		    (cmp (reg t2) (reg t1))
		    (bpl ,genlabel)
		    (*call Bstackunderflow) % never returns
		   ,genlabel
		   (*move (reg t2) (reg Bndstkptr))  )) %start of code

     (setq list (append initload list))
     (setq n 0)

 loop
      (setq cfluids (car Fluids))
      (setq n (wplus2 n 8))

  % insert reloaded register or memory reference

      (setq list (append list
	   (if (car freeregs) `((*move ,(car freeregs) ,cfluids ))
		`((*move (displacement (reg t2) ,n) ,cfluids )))

      )          )
      (setq freeregs (cdr freeregs))
      (cond ((setq Fluids (cdr Fluids)) (go loop)))
      (return list)
)    )

(DefCMacro *freerstr)

(setq *unsafebinder t)   % has to save Registers across calls

(global '(*writingasmfile))

(de !*jumpon (register lowerbound upperbound labellist)
   (if *writingasmfile
       (*xjumpon register lowerbound upperbound labellist)
     (PROG (X LL LL2)
       (setq ll  (gensym))
       (setq ll2 (stringgensym))
       (SETQ X
	(if (and (weq lowerbound 0) (weq upperbound 31))
					% jumpon on tags (most probably)
					% 4 bytes per jumptable entry
      `((b (indirect (indexed (times ,register 8) (label ,ll2))))
       ,ll2)
      `((cmp ,register ,upperbound )
	(beq ,(lastcar labellist))
	(bgt (label ,ll))
	(cmp ,register ,Lowerbound )
	(b lt (label ,ll))
        (*wdifference ,register ,lowerbound )
	(jmp (indirect (indexed (times ,register 8) (label ,ll2))))
       ,ll2) ) )
      Loop  (Setq x (nconc X `((B ,(car Labellist)))))
	    (setq Labellist (cdr Labellist))
	    (cond (Labellist (go loop)))

	    (setq x (nconc x `((*lbl (Label ,ll))) ))
	    (return x)
)  )  )

(DefCMacro !*jumpon)



% Call foreign fns (loaded by oload) by putting SymFunc cell addr in a reg,
% then doing "calls" instr indirect via the target address of the jmp
% instruction stored there.  Use old direct link for asm (kernel) compile.

(de *foreignlink (functionname functiontype numberofarguments)

    `((stm (reg st) ((reg r1) (reg r2) (reg r3) (reg r4) (reg r8) (reg r9) (reg r10) (reg r11) (reg r12)) writeback) % save caller-saved registers
%      (*move (quote t) (fluid *kernelmode))
      (blx (foreignentry ,functionname))
%      (*move (reg NIL) (fluid *kernelmode))
      (ldm (reg st) ((reg r1) (reg r2) (reg r3) (reg r4) (reg r8) (reg r9) (reg r10) (reg r11) (reg r12)) writeback))) % restore saved registers

(DefCMacro !*foreignlink)



