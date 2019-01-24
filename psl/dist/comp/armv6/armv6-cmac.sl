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

(loadtime
 (progn
   (remprop 'wtimes2 'openfn)
   (remprop 'wtimes2 'MemModFn)
   ))

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
		  displacement unindirect) 'TerminalOperand)

% MkItem may be used when evaluating WConst expressions.

%(de MkItem (TagPart InfPart)
%  (lor (lsh TagPart 27) (land InfPart 16#7ffffff)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% REGISTER HANDLING PREDICATES%
% The following predicates are for the 68000, they try to catagorize the
% constraints relating to legal operands in 68000 assembly language.
% There are a number of common predicates already available,
% they are defined the the file PC:Common-Predicates.SL
 
% The following predicates test for integers in the ranges outlined.
% All numbers are expressed in base 16.
%
% InumP        7FFFFFFF >= x >= -80000000          ( 32 bits )
% PosInumP     7FFFFFFF >= x >          0          ( 32 bits )
% NegInumP            0 >  x >= -80000000          ( 32 bits )
% Geq16P       7FFFFFFF >= x >=        10          ( 32 bits )
% LeqM16P           -10 >= x >= -80000000          ( 32 bits )
% Gt8P         7FFFFFFF >= x >          8          ( 32 bits )
% LtM8P              -8 >  x >= -80000000          ( 32 bits )
% PosHWordP       10000 >  x >          0          ( 16 bits, unsigned)
% NegHWordP           0 >  x >=    -10000          ( 16 bits, unsigned)
% DispInumP        7FFF >= x >=     -8000          ( 16 bits )
% SmallInumP         7F >= x >=       -80          (  8 bits )
% QInumP              8 >= x >=        -8          (  several bits )
% PosQInumP           8 >= x >          0          (  3 bits, unsigned)
% NegQInumP           0 >  x >=        -8          (  3 bits, unsigned)
 
(off R2I)            % This function should exist in the kernel!           scs
(de IntP(N) (IntP N))
(on  R2I)
 
(de PosInumP (Expression)  (and (InumP    Expression)
				(GreaterP Expression 0)))
 
(de NegInumP (Expression)  (and (InumP  Expression)
		(minusp Expression)))
 
(de Geq16P (Expression)    (and (InumP  Expression)
				(Geq    Expression 16)))
 
(de LeqM16P (Expression)   (and (InumP  Expression)
		(Leq    Expression -16)))
 
(de Gt8P (Expression)      (and (InumP    Expression)
				(GreaterP Expression 8)))
 
(de LtM8P (Expression)     (and (InumP    Expression)
		(LessP    Expression -8)))
 
(de PosHWordP (Expression) (and (IntP Expression)
					  (GreaterP Expression 0)
					  (lessP    Expression 16#10000)))
 
(de NegHWordP (Expression) (and (IntP Expression)
					  (minusp Expression)
					  (geq    Expression (minus 16#10000))))
 
(de DispInumP (Expression) (and (IntP Expression)
					  (leq Expression 16#7fff)
					  (geq Expression (minus 16#8000))))
 
(de SmallInumP (Expression)(and (IntP Expression)
			  (leq Expression 16#7f)
			  (geq Expression (minus 16#80))))
 
(de QInumP    (Expression) (and (IntP Expression)
			  (leq Expression  8)
			  (geq Expression -8)))
 
(de PosQInumP (Expression) (and (IntP Expression)
					  (GreaterP Expression 0)
					  (leq      Expression 8)))
 
(de NegQInumP (Expression) (and (IntP Expression)
					  (minusp Expression)
					  (geq    Expression -8)))
 
%---------------------------------------------------------
% The following set of predicates describes certain classes of
% register classes. RegP tests if the ophe operand is a valid 68000 register.%
%
% RegP  any 80386 register
% FakeRegP tests for argument register numbers greater than LastActualReg

 
(de FakeRegP (Expression) (and (PosIntP  Expression)
		   (GreaterP Expression LastActualReg&)))  % scs
 
(de RegP (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '( 1  2  3  4  5
		     R0 R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 sp st pc lr
		     t1 t2 t3 fp
             nil heaplast heaptrapbound symfnc symval
%	     bndstkptr bndstklowerbound bndstkupperbound
	     ))))
 
%-------------
%  ImmediateP tests if an item is tagged IMMEDIATE. (immediate x)
%  WConsts and WArrays are tagged immediate when they are not
%  inside MEMORY. The tagging means that the following expression
%  is to be used as an immediate value. For example, if WArray
%  SYMFNC is the base of some table, the expression
%       (*WPLUS2 (Reg 1) (immediate (WArray SYMFNC)))
%  means to add the address of SYMFNC to (Reg 1) and not the contents
%  of the SYMFNC location. Another immediate expression example would be
%  (*MOVE (postincrement (Reg st)) (immediate (plus2 (WArray ArgumentBlock) 32))'
%  which means move the popped value of the stack to the address resulting from
%  the plus computation.
%-------------
 
(de ImmediateP (x)
  (and  (EqCar x 'Immediate) (Null (fixp (cadr x)))))
 
(de TaggedLabel (X) (EqCar X 'Label))
 
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

(de fixplusp (x) (and (fixp x) (not (minusp x))))

%% 32 bit machine number?
(de Int32P (x) (and (fixp x) (lessp x 16#7fffffff) (greaterp 80000000)))

(de displacementp (x) (and (pairp x) (eq (car x) 'displacement)))

(de indirectregp (x)
    (and (pairp x)
	 (eq (car x) 'indirect)
	 (regp (cadr x))))

(de unindirect (x)
    (if (eqcar x 'indirect) (cadr x) x))

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


(DefAnyreg Memory
	   AnyregMEMORY
	   ((RegP ZeroP)      (indirect SOURCE))
	   ((Anyp ZeroP)      (*Move SOURCE REGISTER)
			       (indirect REGISTER))
 	   ((RegP twelve-bit-p)      (Displacement SOURCE ARGTWO))
	   ((AnyP twelve-bit-p)      (*Move SOURCE REGISTER)
	                       (Displacement REGISTER ARGTWO))
	   ((RegP RegP)       (Indexed ARGTWO (Displacement source 0)))
	   ((RegP AnyP)       (*Move SOURCE REGISTER)
			       (*WPlus2 REGISTER ARGTWO)
			       (indirect REGISTER))
	   ((AnyP DispInumP)  (!*Move SOURCE REGISTER)
			       (Indexed REGISTER (Displacement ARGTWO 0)))
	   (                   (!*Move SOURCE REGISTER)
			       (!*WPlus2 REGISTER ARGTWO)
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
%	   ((Int32P)  (quote SOURCE))  % more that 32 bits
	   ((INumP)  SOURCE)    %?
           ((Null) (REG NIL))
	   (       (QUOTE SOURCE)))   %? Recursivly expand??
 
%(DefAnyreg WCONST
%           AnyregWCONST
%	   ((Int32P)  (quote SOURCE))  % more that 32 bits
%           (SOURCE))
 
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
   (cond ((and (idp source) (get source 'registercode))
		         `(reg ,source))
	 (t       `($Fluid ,SOURCE))))

(DefAnyreg Global ZIBanyregglobal)

(DefAnyreg $Global ZIBanyregglobal)

(de ZIBanyregGlobal (reg source)
   (cond ((and (idp source) (get source 'registercode))
		         `(reg ,source))
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
       ((InternallyCallableP)  (BL (InternalEntry ArgOne)))
	(         (*Move (idloc argone) (reg t3))
		  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2)))
		  (BLX (reg t2)))
)

(DefCMacro *JCall
       ((InternallyCallableP)  (B (InternalEntry ArgOne)))
	(         (*Move (idloc argone) (reg t3))
		  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2)))
		  (BX (reg t2)))
)

%% could be:
%% (LDMIA (reg sp) ((reg lr)) writeback)
%% (LDR (reg pc) (displacement (reg symfnc) (regshifted t3 LSL 2)))


(de indirectp (x)
    (eqcar x 'indirect))

(de extraregp (x)
    (eqcar x 'extrareg))

(de idlocp (x) (eqcar x 'idloc))

(de smallid-p (x)
    (and (idp x)
	 (wgeq (idinf x) 0)
	 (wlessp (idinf x) 256)))

(de true-p (x) (eq x 't))

(remprop '*Move 'optfn)

(de quotep (x) (eqcar x 'quote))

%% optimize (*Move nil (fluid something))
(DefCMacro *Move
       (Equal)
       ((regp regp)	    	 (MOV ArgTwo ArgOne))
       ((imm8-rotatedp regp)     (MOV Argtwo ArgOne))
       ((quotep regp)            (LDR ArgTwo ArgOne))
       ((InumP regp)             (*LoadConstant ArgTwo ArgOne))
       ((fixp regp)              (*LoadConstant ArgTwo ArgOne))
%       ((true-p regp)            (*LoadIDLoc t ArgTwo)
%	                         (*MkItem ArgTwo (compiler-constant 'id-tag)))
       ((idlocp regp)            (*LoadIDLoc ArgTwo ArgOne))
       ((fluid-arg-p regp)       (*LoadIdNumber LDR ArgTwo ArgOne))
       ((indirectp regp)         (LDR ArgTwo ArgOne))
       ((immediatep regp)        (*LoadImmediate ArgTwo ArgOne))
       ((regp fluid-arg-p)       (*LoadIdNumber STR ArgOne ArgTwo))
       ((regp indirectp)         (STR ArgOne ArgTwo))
       ((regp extraregp)         (!*StoreIntoExtraReg ArgOne ArgTwo))
       ((regp anyp)              (STR ArgOne ArgTwo))
       ((extraregp regp)         (!*LOADExtraReg ArgOne ArgTwo))
       ((anyp regp)              (LDR ArgTwo ArgOne))
       (                         (*Move ArgOne (reg t1))
				 (*Move (reg t1) ArgTwo)))

(de *LoadConstant (dest cst)
    (cond ((imm8-rotatedp cst)
	   `( (MOV ,dest ,cst)))
	  ((imm8-rotatedp (land 16#ffffffff (lnot cst)))
	   `( (MVN ,dest  ,(land 16#ffffffff (lnot cst)))))
	  ((sixteenbit-p cst)
	   % sixteen bits: load in two steps
	   `( (MOV ,dest ,(land 16#ff cst))
	      (ADD ,dest ,dest ,(land 16#ff00 cst))))
	  ((InumP cst)
	   `( (LDR ,dest (sysint ,cst))))
	  (t
	   `( (ldr ,dest (quote ,cst))))
	  )
    )

(DefCMacro *LoadConstant)

(de *LoadIDLoc (dest src)
  (let ((idnumber (WConstEvaluable src))
	(comment (if *writingasmfile `((comment ,@src)))))
    (append comment
      (cond ((and (fixp idnumber) (wlessp idnumber 257))
	     (*LoadConstant dest (id2int (cadr src))))
	    ((and *writingasmfile (fixp idnumber))
	     `( (ldr ,dest (quote ,idnumber))))
	    (t
	     `( (ldr ,dest ,src)))
    ))))


(DefCMacro *LoadIDLoc)

(de *LoadIdNumber (load-or-store reg nonlocal)
  (let ((idnumber
	 (WConstEvaluable `(idloc ,(cadr nonlocal))))
	(comment (if *writingasmfile `((comment ,@nonlocal)))))
    (append comment
      (if (and idnumber (fixp idnumber) (lessp idnumber 257) (greaterp idnumber -1))
 	`( (,load-or-store ,reg (displacement (reg symval) ,(times 4 idnumber))) )
       `( (LDR (reg t3) ,(if (null idnumber) `(idloc ,(cadr nonlocal)) `(quote ,idnumber))) 
 	 (,load-or-store ,reg (displacement (reg symval) (regshifted t3 LSL 2))) )
      ))))

(DefCMacro *LoadIdNumber)

(de *LoadImmediate (dest src)
    (setq src (unimmediate src))
    (print (list src (prop (unimmediate src))))
    (if (not (idp src))
	`((LDR ,dest ,(unimmediate src)))
      `((ADRL ,dest ,src)))		% two instruction load address pseudo-op
    )

(DefCMacro *LoadImmediate)

(de !*LoadExtraReg (src dest)
    `( (!*Move (memory ($fluid argumentblock)
		       ,(times (difference (cadr src) (plus lastactualreg!& 1))
			       (compiler-constant 'addressingunitsperitem)))
	,dest)))

(DefCMacro !*LoadExtraReg)

(de !*StoreIntoExtraReg (src dest)
    `( (!*Move ,src (memory ($fluid argumentblock)
			 ,(times (difference (cadr dest) (plus lastactualreg!& 1))
				 (compiler-constant 'addressingunitsperitem))))))

(DefCMacro !*StoreIntoExtraReg)

%%% fill extra frame with nil!
%% *Alloc pushes the link register onto the stack and allocate framesize stack frames
%% If framesize is even, this means that the stack pointer is not 8byte aligned.
%% In this case, push an extra value of nil onto the stack immediately below lr
%%  and increase NAlloc!* by 1.
%% Hence, for odd framesize the instructions are
%%  STMDB sp!, {lr}
%%  SUB sp, sp, (4*framesize)
%% but with an extra "STR r12,[sp, #-4]!" (a.k.a. "push r12") in between for even framesize
(de *ALLOC (framesize)
    (let ((ll `((SUB (reg st) (reg st) ,(times2 4 framesize)))))
      % Make sure that the stack is always 8 byte aligned
      (if (evenp framesize)
	  (progn
	    (setq ll (cons '(*push (reg nil)) ll))
	    (setq NAlloc!* (add1  framesize)))
	(setq NAlloc!* framesize))
      (cons '(STMDB (reg st) ((reg lr)) writeback) ll)))

(DefCmacro *ALLOC)

(de *DeAlloc (DeAllocCount)
  (if (evenp DeAllocCount) (setq DeAllocCount (plus2 DeAllocCount 1)))
  (Expand1OperandCMacro 
   (times DeAllocCount (compiler-constant 'AddressingUnitsPerItem))
   '*DeAlloc))

(DefCmacro *DeAlloc
	   ((ZeroP)	      (LDMIA (reg sp) ((reg lr)) writeback))

	   (           (add (reg st) (reg st) ARGONE)
		        % pop link register
		        (LDMIA (reg sp) ((reg lr)) writeback))
)


% Again, make sure that the stack is always 8 byte aligned
(de *Exit (N)
  (if (evenp N) (setq N (plus2 N 1)))
 (Expand1OperandCMacro
   (times N (compiler-constant 'AddressingUnitsPerItem)) '*Exit))

(DefCMacro *Exit     % leaf routine first
   ((ZeroP)  (LDMIA (reg sp) ((reg lr)) writeback)
             (bx (reg lr)))
   (         (add (reg st) (reg st) ARGONE)
	     (LDMIA (reg sp) ((reg lr)) writeback)
	     (bx (reg lr))))

(de displacementp (x) (and (pairp x) (eq (car x) 'displacement)))

(de deferredp (x) (eqcar x 'deferred))

(DefCMacro *Jump
	   ((indirectp)              (!*Move ArgOne (reg t1))
	                             (bx (reg t1)))
	   (                         (b ArgOne)))


(DefCMacro *Lbl           (ArgOne))

(de *Link (FunctionName FunctionType NumberOfArguments)
  (list
   (cond ((FlagP FunctionName 'ForeignFunction)
	  (list '*ForeignLink FunctionName FunctionType NumberOfArguments))
	 (t
	  (list '*Call FunctionName)))))
 
(DefCMacro *Link)
 
 
(de *LinkE (DeAllocCount FunctionName FunctionType NumberOfArguments)
 (cons `(*DeAlloc ,DeAllocCount)
       (cond ((FlagP FunctionName 'ForeignFunction)
	      `((*ForeignLink ,FunctionName ,FunctionType ,NumberOfArguments)
		(bx (reg lr))))
	     (t
	      `((*JCall ,FunctionName))))))
 
(DefCMacro *LinkE)

(de *JCall (FunctionName)
  (prog (ResultingCode* OpenCodeSequence)
        (return (cond ((setq OpenCodeSequence
                             (get FunctionName 'ExitOpenCode))
                       OpenCodeSequence)
                      ((setq OpenCodeSequence
                             (get FunctionName 'OpenCode))
                       (Append OpenCodeSequence
			       (list '(BX (reg lr)))))
                      (t (CMacroPatternExpand (list FunctionName)
                                              (get '*JCall
                                                   'CMacroPatternTable)))))))


(DefCMacro *Push
  ( (!*Move ArgOne (displacement (reg st) -4 preindexed))))

(DefCMacro *Pop
  ( (!*Move (displacement (reg st) 4 postindexed) ArgOne)))

(de *3op (a1 a2 instruction)
  (prog (ResultingCode*)
    (return (CMacroPatternExpand
	   (list (ResolveOperand '(reg t1) a1)
		 (ResolveOperand '(reg t2) a2)
		  Instruction)
		 (get '*3op 'CMacroPatternTable)))))

(DefCMacro *3op
       ((regp regp) (ArgThree ArgOne ArgOne ArgTwo ))
       ((regp imm8-rotatedp)
		      (ArgThree ArgOne ArgOne ArgTwo ))
       ((regp INumP) (LDR (reg t2) (sysint ArgTwo))
                      (*3op ArgOne (reg t2) ArgThree))  
       ((regp AnyP)  (*Move ArgTwo (reg t2))
		      (*3op ArgOne (reg t2) ArgThree))
       ((Anyp regp)  (*Move ArgOne (reg t2))
		      (ArgThree (reg t2) ArgTwo (reg t2))
		      (*Move (reg t2) ArgOne))
       ((Anyp imm8-rotatedp)
		      (*Move ArgOne (reg t2))
		      (ArgThree (reg t2) (reg t2) ArgTwo)
		      (*Move (reg t2) ArgOne))
       (              (*Move ArgTwo (reg t2))
		      (*Move ArgOne (reg t1))
		      (ArgThree (reg t1) (reg t1) (reg t2))
		      (*Move (reg t1) ArgOne)))

(DefCMacro *WPlus2
	   ((anyp zerop))
	   ((anyp negp) (*WDifference ArgOne (minus ArgTwo)))
	   ((regp regp) (ADD ArgOne ArgOne ArgTwo))
	   ((regp imm8-rotatedp) (ADD ArgOne ArgOne ArgTwo))
	   ((regp anyp) (*Move ArgTwo (reg t3))
	                (ADD ArgOne ArgOne (reg t3)))
	   ((anyp imm8-rotatedp) (*Move ArgOne (reg t2))
	                (ADD (reg t2) (reg t2) ArgTwo)
			(*Move (reg t2) ArgOne))
	   (            (*Move ArgOne (reg t2))
			(*Move ArgTwo (reg t3))
	                (ADD (reg t2) (reg t2) (reg t3))
			(*Move (reg t2) ArgOne)))
	    

%(de *WPlus2 (arg1 arg2)
%    (when (not (or (zerop arg2) (equal arg2 '(wconst 0))))
%      (*wplus3 arg1 arg1 arg2)))

%(de Expand3OperandCMacro (Arg1 Arg2 Arg3 CMacroName)
%  (prog (ResultingCode!*)
%    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1)
%				       (ResolveOperand '(REG t2) Arg2)
%				       (ResolveOperand '(REG t3) Arg3))
%				 (get CMacroName 'CMacroPatternTable)))))

(de *WPlus3 (arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wplus3))

(DefCMacro *WPlus3
	   ((anyp zerop anyp) (*Move ArgThree ArgOne))
	   ((anyp anyp zerop) (*Move ArgTwo ArgOne))
	   ((anyp anyp negp) (*WDifference3 Argone ArgTwo (minus Argthree)))
	   ((regp regp regp) (ADD ArgOne ArgTwo ArgThree))
	   ((regp imm8-rotatedp regp)
		                (ADD ArgOne Argthree ArgTwo))
	   ((regp regp imm8-rotatedp)
		                (ADD ArgOne ArgTwo ArgThree))
	   ((regp imm8-rotatedp anyp)
		               (*Move ArgThree (reg t3))
		               (ADD ArgOne (reg t3) ArgTwo))
	   ((regp anyp imm8-rotatedp)
		               (*Move ArgTwo (reg t3))
		               (ADD ArgOne (reg t3) ArgThree))
	   ((regp regp anyp)  (*Move ArgThree (reg t3))
		               (ADD ArgOne ArgTwo (reg t3)))
	   ((regp anyp regp)  (*Move ArgTwo (reg t3))
		               (ADD ArgOne (reg t3) ArgThree))
	   ((regp anyp anyp)  (*Move ArgTwo (reg t2)) % *Move may clobber t3
		               (*Move ArgThree (reg t3))
		               (ADD ArgOne (reg t2) (reg t3)))
	   ((anyp regp imm8-rotatedp) (ADD (reg t1) ArgTwo ArgThree)
		               (*Move (reg t1) ArgOne))
	   ((anyp regp anyp)  (*Move ArgThree (reg t3))
		               (ADD (Reg t2) ArgTwo (reg t3))
		               (*Move (reg t2) ArgOne))
	   ((anyp anyp imm8-rotatedp) (*Move ArgTwo (reg t2))
		               (ADD (reg t2) (reg t2) ArgThree)
		               (*Move (reg t2) ArgOne))
	   (                   (*Move ArgTwo (reg t2))
		               (*Move ArgThree (reg t3))
		               (ADD (reg t2) (reg t2) (reg t3))
		               (*Move (reg t2) ArgOne)))

(DefCMacro *WDifference
       ((*WDifference3 ArgOne ArgOne ArgTwo)))

(de *WDifference3 (arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wdifference3))

% format ArgOne = ArgTwo - ArgThree

(DefCMacro *WDifference3
	   ((regp zerop regp) (RSB ArgOne ArgThree 0))
	   ((regp regp zerop) (*Move ArgOne ArgTwo))
	   ((regp regp negp) (*WPlus3 ArgOne ArgTwo (minus ArgThree)))
	   ((regp regp regp) (SUB ArgOne ArgTwo ArgThree))
	   ((regp imm8-rotatedp regp)
		                (RSB ArgOne Argthree ArgTwo))
	   ((regp regp imm8-rotatedp)
				(SUB ArgOne ArgTwo ArgThree))
	   ((regp imm8-rotatedp anyp)
		               (*Move ArgThree (reg t3))
		               (RSB ArgOne (reg t3) ArgTwo))
	   ((regp anyp imm8-rotatedp)
		               (*Move ArgTwo (reg t3))
		               (SUB ArgOne (reg t3) ArgThree))
	   ((regp regp anyp)  (*Move ArgThree (reg t3))
		               (SUB ArgOne ArgTwo (reg t3)))
	   ((regp anyp regp) (*Move ArgTwo (reg t3))
		               (SUB ArgOne (reg t3) ArgThree))
	   ((regp anyp anyp)  (*Move ArgTwo (reg t2))
		               (*Move ArgThree (reg t3))
		               (SUB ArgOne (reg t2) (reg t3)))
	   ((anyp regp imm8-rotatedp) (SUB (Reg t1) ArgTwo ArgThree)
		               (*Move (reg t1) ArgOne))
	   ((anyp regp anyp)  (*Move ArgThree (reg t3))
		               (SUB (Reg t2) ArgTwo (reg t3))
		               (*Move (reg t2) ArgOne))
	   ((anyp anyp imm8-rotatedp) (*Move ArgTwo (reg t2))
		               (SUB (reg t2) (reg t2) ArgThree)
		               (*Move (reg t2) ArgOne))
	   (                   (*Move ArgTwo (reg t2))
		               (*Move ArgThree (reg t3))
		               (SUB (reg t2) (reg t2) (reg t3))
		               (*Move (reg t2) ArgOne)))

(de *WNegate(ARG1)
 (Expand1OperandCMacro ARG1 '*WNegate))
 
(DefCMacro *WNegate
	   (                  (!*WDifference3 ArgOne 0 ArgOne))
 )
 
(DefCMacro *WMinus
	((regp regp)  (rsb ArgOne ArgTwo 0))
	((regp Anyp)  (*Move ArgTwo ArgOne)
		      (rsb ArgOne ArgOne 0))
	(	      (*Move ArgTwo (reg t2))
	        	(*wminus (reg t2) (reg t2))
			(*Move (reg t2) ArgOne)))

(put 'wtimes2 'opencode '((MUL (reg 1) (reg 1) (reg 2))))

(defcmacro *wtimes2)

(de *wtimes2 (arg1 arg2) (*wtimes3 arg1 arg1 arg2))

(de *wtimes3 (arg1 arg2 arg3)
    (expand3operandcmacro arg1 arg2 arg3 '*wtimes3))

% format ArgOne = ArgTwo * ArgThree

(DefCMacro *wtimes3
	   ((regp regp regp) (MUL ArgOne ArgTwo ArgThree))
	   ((regp anyp regp) (*Move ArgTwo (reg t1))
	                     (MUL ArgOne (reg t1) Argthree))
	   ((regp regp anyp) (*Move argthree (reg t1))
			     (*wtimes3 ArgOne ArgTwo (reg t1)))
	   (        (*Move ArgTwo (Reg t1))
		    (*Move ArgThree (reg t2))
		    (MUL (reg t1) (Reg t1) (reg t2))
		    (*Move (reg t1) ArgOne)))
 
(DefCMacro *wquotient)

(de *wquotient (arg1 arg2) (*wquotient3 arg1 arg1 arg2))

(de *wquotient3 (arg1 arg2 arg3)
    (Expand3OperandCmacro arg1 arg2 arg3 '*wquotient3))

% format ArgOne = ArgTwo / ArgThree

(DefCMacro *wquotient3              
	 ((anyp anyp onep)       (*Move argtwo argone))
	 ((regp regp powerof2p)  (*wquotientshift ArgOne ArgTwo ArgThree))
	 ((regp regp regp)       (*sdiv ArgOne ArgTwo Argthree))
	 ((regp regp anyp)       (*Move argthree (reg t1))
		                 (*wquotient3 ArgOne ArgTwo (reg t1)))
	   (        (*Move ArgTwo (Reg t1))
		    (*Move ArgThree (reg t2))
		    (*sdiv (reg t1) (Reg t1) (reg t2))
		    (*Move (reg t1) ArgOne)))

(de *wquotientshift (arg1 arg2 arg3)
	(setq arg3 (powerof2p arg3))
	`((*asr arg1 arg2 arg3)))

(DefCMacro *wquotientshift)

(DefCMacro *wremainder
	   (       (*Move ArgOne (reg t2))
	           (*Move ArgTwo (reg t1))
		   (*sdiv (reg t2) (reg t2) (reg t1))
		   (mul (reg t1) (reg t1) (reg t2))
		   (*wdifference3 ArgOne ArgOne (reg t1))))

(de *Wcmp(arg1 arg2)
  (Expand2OperandCMacro arg1 arg2 '*Wcmp))

(DefCmacro *Wcmp
       ((regp regp) (CMP ArgOne ArgTwo))
       ((regp imm8-rotatedp) (CMP ArgOne ArgTwo))
       ((Anyp Regp) (*Move ArgOne (reg t1))
	            (CMP (reg t1) ArgTwo))
       ((Regp Anyp) (*Move ArgTwo (reg t2))
		    (CMP ArgOne (reg t2)))
       (            (*Move ArgOne (reg t1))
                    (*Wcmp (reg t1) ArgTwo) ))
 

(DefCMacro *WAnd
       ((*3op ArgOne ArgTwo AND)))

(DefCMacro *WOr
       ((*3op ArgOne ArgTwo ORR)))

(DefCMacro *WXOr
       ((*3op ArgOne ArgTwo EOR)))

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
    ((regp negp)     (MOV ArgOne (regshifted ArgOne ASR (minus ArgTwo))))
    ((regp fixplusp) (MOV ArgOne (regshifted ArgOne LSL ArgTwo)))
    ((regp regp)     (CMP ArgTwo 0)
                      (BGE templabel)
                      (RSB (reg t2) ArgOne 0)
                      (*asr ArgOne ArgOne (reg t2))
                      (B templabel2)
                     templabel
                      (*lsl ArgOne ArgOne ArgTwo)
                     templabel2)

    ((regp anyp)     (*Move ArgTwo (reg t2))
		      (*ashift ArgOne (reg t2)))
    ((Anyp fixp)      (*Move ArgOne (reg t1))
		      (*ashift (reg t1) ArgTwo)
		      (*Move (reg t1) ArgOne))
    (                 (*Move ArgOne (reg t1))
		      (*ashift (reg t1) ArgTwo)
		      (*Move (reg t1) ArgOne))
)


(DefCMacro *WShift
    ((AnyP ZeroP))
    ((regp negp)     (*lsr ArgOne ArgOne (minus ArgTwo)))
    ((regp fixplusp) (*lsl ArgOne ArgOne ArgTwo))
    ((regp regp)     (CMP argtwo 0)
		      (BGE templabel)
                      (RSB (reg t2) ArgTwo 0)
		      (*lsr ArgOne Argone (reg t2))
                      (B templabel2)
                     templabel
                      (*lsl ArgOne ArgOne ArgTwo)
                     templabel2)
    ((regp anyp)     (*Move ArgTwo (reg t2))
		      (*wshift ArgOne (reg t2)))
    ((Anyp fixp)      (*Move ArgOne (reg t1))
		      (*wshift (reg t1) ArgTwo)
		      (*Move (reg t1) ArgOne))
    (                 (*Move ArgOne (reg t1))
		      (*wshift (reg t1) ArgTwo)
		      (*Move (reg t1) ArgOne)))


(de *WLshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WLshift))
 
(DefCMacro *WLShift                     %Logical shift to the left.
	   ((AnyP  ZeroP)           )
	   ((RegP  OneP)      (*WPLUS2 ARGONE ARGONE))
	   ((RegP NegP)       (*Cerror "*WLshift with negative shift amount"))
	   ((RegP InumP)      (*lsl ArgOne ArgOne ArgTwo))
	   ((RegP regP)       (*lsl ArgOne ArgOne ArgTwo))
	   ((RegP AnyP)       (*MOVE ARGTWO (Reg t2))
			      (*wlshift argone (reg t2)))
	   (                  (*MOVE ARGONE (Reg t1))
			      (*WlSHIFT (Reg t1) ARGTWO)
			      (*MOVE (Reg t1) ARGONE))
)
 
(de *WRshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WRshift))
 
(DefCMacro *WRShift                     %Logical shift to the right
	   ((AnyP  ZeroP)           )
	   ((RegP NegP)       (*Cerror "*WRshift with negative shift amount"))
	   ((RegP InumP)      (*lsr ArgOne ArgOne ArgTwo))
	   ((RegP regP)       (*lsr ArgOne ArgOne ArgTwo))
	   ((RegP AnyP)       (*MOVE ARGTWO (Reg t2))
			      (*wrshift argone (reg t2)))
	   (                  (*MOVE ARGONE (Reg t1))
			      (*WRSHIFT (Reg t1) ARGTWO)
			      (*MOVE (Reg t1) ARGONE))
)


(DefCMacro *WNot
       ((regp regp)  (MVN ArgOne ArgTwo))
       ((regp imm8-rotatedp) (mvn ArgOne ArgTwo))
       ((regp Anyp)  (*Move ArgTwo ArgOne)
		      (MVN ArgOne ArgOne))
       (	     (*Move ArgTwo (reg t2))
		      (*wnot (reg t2) (reg t2))
		      (*Move (reg t2) ArgOne)))

(de *WComplement(ARG1)
 (Expand1OperandCMacro ARG1 '*WComplement))
 
(DefCMacro *WComplement
	   (                  (*WNot ARGONE ArgOne))
 )

(DefCMacro *MkItem
       ((regp fixp)	(MOV ArgOne (regshifted Argone LSL 5))
                        (ORR ArgOne ArgOne (land ArgTwo 31))
			(MOV ArgOne (regshifted ArgOne ROR 5)))
       ((regp regp)	(and (reg t3) ArgTwo 31)
                        (MOV ArgOne (regshifted Argone LSL 5))
			(ORR ArgOne ArgOne (reg t3))
                        (MOV ArgOne (regshifted ArgOne ROR 5)))
       ((regp anyp)	(*Move ArgTwo (reg t2))
			 (*Mkitem ArgOne (reg t2)))
       (                (*Move ArgOne (reg t1))
		         (*mkitem (reg t1) ArgTwo)
		         (*Move (reg t1) ArgOne)))

(DefCMacro *Tag
      ((regp regp) (MOV ArgOne (regshifted ArgTwo LSR 27)))
      ((Anyp regp) (MOV (reg t1) (regshifted ArgTwo LSR 27))
		    (*Move (reg t1) ArgOne))
      ((regp anyp) (*Move ArgTwo ArgOne)
		    (MOV ArgOne (regshifted ArgOne LSR 27)))
      (             (*Move ArgTwo (reg t1))
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
       (            (*Tag (reg t3) ArgOne)
		     (CMP (reg t3) ArgTwo )
		     (BLE  ArgThree)
		     (CMP (reg t3) 31) % negint-tag)
		     (BEQ ArgThree)
		     templabel)
       )

(DefCMacro *JumpNotInType
       (            (*Tag (reg t3) ArgOne)
		     (CMP (reg t3) 31) % negint-tag
		     (BEQ templabel)
		     (CMP (reg t3) ArgTwo)
		     (BGT ArgThree)
		     templabel)
       )

%---------------------------------------------------------------------
%   General Purpose Jumper.
%   FORMAT: Operand1 Operand2 Address JumpOpCode

(DefCMacro *JumpIf
     ((regp regp)       (CMP ArgOne ArgTwo)
		         (ArgFour ArgThree))
     ((regp imm8-rotatedp) (CMP ArgOne ArgTwo)
			 (ArgFour ArgThree))
%% ((imm8-rotatedp regp (CMP ArgTwo ArgOne)
%%                       (ArgFive ArgThree))
     ((regp anyp)       (*Move ArgTwo (reg t3))
		         (CMP ArgOne (reg t3))
		         (ArgFour ArgThree))
     ((anyp regp)       (*Move ArgOne (reg t3))
		         (CMP (reg t3) ArgTwo )
		         (ArgFour ArgThree))
     ((anyp imm8-rotatedp) (*Move ArgOne (reg t3))
		         (CMP (reg t3) ArgTwo)
		         (ArgFour ArgThree))
%% ((imm8-rotatedp anyp) (*Move ArgTwo (reg t2))
%%                       (CMP (reg t2) ArgOne)
%%                       (ArgFive ArgThree))
     (                   (*Move ArgOne (reg t1))
		         (*Move ArgTwo (reg t2))
		         (CMP (reg t1) (reg t2))
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

(DefCMacro *JumpEQ)

(de *JumpEQ (Lbl ArgOne ArgTwo)
       (*JumpIF ArgOne ArgTwo Lbl '(beq . beq)))

(DefCMacro *JumpNotEQ)

(de *JumpNotEQ(Lbl ArgOne ArgTwo)
	(*JumpIF ArgOne ArgTwo Lbl '(bne . 'bne)))

(DefCMacro *JumpWlessp)

(de *JumpWlessp (Lbl ArgOne ArgTwo)
	(*JumpIF ArgOne ArgTwo Lbl '(blt . bge)))

(DefCMacro *JumpWgreaterp)

(de *JumpwGreaterp (Lbl ArgOne ArgTwo)
	(*JumpIF ArgOne ArgTwo Lbl '(bgt . ble)))

(DefCMacro *JumpWleq)

(de  *JumpWleq(Lbl ArgOne ArgTwo)
	(*JumpIF ArgOne ArgTwo Lbl '(ble . bgt)))

(DefCMacro *JumpWgeq)

(de *jumpWgeq (Lbl ArgOne ArgTwo)
	(*JumpIF ArgOne ArgTwo Lbl '(bge . blt)))

% --------------------

(de fluid-arg-p (x)
    (and (pairp x)
     (member (car x) '(!$fluid !$global fluid global))))


(DefCMacro *Loc                          % This needs more study    scs
	  ((regP smallimmediatep)(MOV ARGONE (unimmediate ARGTWO)))
	  ((regP indirectp)(*LoadAddress ARGONE ARGTWO))
	  ((regP displacementp)(*LoadAddress ARGONE ARGTWO))
	  ((RegP AnyP)      (MOV              ARGONE  ARGTWO))
	  ((AnyP smallimmediatep)(*MOVE           ARGTWO  ARGONE))
	  (                  (MOV              (Reg T2) ARGTWO)
			     (*MOVE          (Reg T2) ARGONE)))

(de *LoadAddress (dest src)
    %% dest is a register, src an indirect reference
    (cond((eqcar src 'indirect)
	  `((MOV ,dest ,(cadr src))))
	 ((and (displacementp src) (regp (cadr src)) (fixp (caddr src)))
	  `((MOV ,dest ,(cadr src))
	    (ADD ,dest ,dest ,(caddr src))))
	 (t `((MOV ,dest ,src)))))

(DefCMacro *LoadAddress)


(DefCMacro *Field

  ((regp regp Fivep TwentySevenP) (BIC ArgOne ArgTwo 16#F8000000))
  ((regp anyp Fivep TwentySevenP) (*Move ArgTwo ArgOne)
                                   (BIC ArgOne ArgOne 16#F8000000))
  ((regp regp zerop fixp) (*lsr ArgOne ArgTwo (difference 32 ArgFour)))
  ((regp regp fixp fixp) (*lsl ArgOne ArgTwo ArgThree)
                         (*lsr ArgOne ArgOne (difference 32 ArgFour)))
  ((regp anyp fixp fixp) (*Move ArgTwo (reg t3))
                         (*Field ArgOne (reg t3) ArgThree ArgFour))
  ((anyp regp fixp fixp) (*Field (reg t1) ArgTwo ArgThree ArgFour)
		          (*Move (reg t1) ArgOne))
  (                      (*Move ArgTwo (reg t2))
		          (*Field (reg t1) (reg t2) ArgThree ArgFour)
		          (*Move (reg t1) ArgOne)))

(DefCMacro *SignedField

  ((regp regp zerop fixp) (*asr ArgOne ArgTwo (difference 32 ArgFour)))
  ((regp regp fixp fixp) (*lsl ArgOne ArgTwo ArgThree)
                         (*asr ArgOne ArgOne (difference 32 ArgFour)))
  ((regp anyp fixp fixp) (*Move ArgTwo (reg t3))
		         (*lsl ArgOne (reg t3) ArgThree)
			 (*asr ArgOne ArgOne (difference 32 ArgFour)))
  ((anyp regp fixp fixp) (*Signedfield (reg t1) ArgTwo ArgThree ArgFour)
	 		  (*Move (reg t1) ArgOne))
  (                      (*Move ArgTwo (reg t2))
		          (*Signedfield (reg t1) (reg t2) ArgThree ArgFour)
		          (*Move (reg t1) ArgOne)))

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
                     (*Move ARGONE (reg t1))
             (*PUTFIELD    (Reg T1) ARGTWO ARGTHREE ARGFOUR))
  (                  (*Move ARGTWO     (reg t1))
                     (*PUTFIELD ARGONE (Reg T1) ARGTHREE ARGFOUR)
                     (*Move            (reg t1) ARGTWO))
 )
 

(deflist '((Byte        ((LDRSB (reg 1) (displacement (reg 1) (reg 2)))))
	   (r_Byte      ((LDRSB (reg 1) (displacement (reg 1) (reg 2)))))
	   (PutByte     ((STRB (reg 3) (displacement (reg 1) (reg 2)))))
	   (HalfWord    ((LDRSH (reg 1) (displacement (reg 1) (reg 2)))))
	   (PutHalfWord ((STRH (reg 3) (displacement (reg 1) (reg 2))))))
  'OpenCode)

(&OneReg '(Byte PutByte HalfWord PutHalfWord))

(on fast-integers)


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
		     (*Move (quote t) (reg 1))
		     (fcmpo 0 (freg 1) (freg 2))
		     (bc true gt *donefgreaterp*)
		     (*Move (reg nil) (reg 1))
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
		     (*Move (quote t) (reg 1))
		     (fcmpo 0 (freg 1) (freg 2))
		     (bc true lt *doneflessp*)
		     (*Move (reg nil) (reg 1))
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
   ( (*Move ArgOne (reg t1)) ))

(put 'fast-idapply    'opencode
     '((!*Field (reg t3) (reg t1)  (wconst infstartingbit) (wconst infbitlength))	% remove tag
       (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2)))
       (BLX (reg t2))))
     
(put 'fast-idapply    'exitopencode
     '((!*Field (reg t3) (reg t1)  (wconst infstartingbit) (wconst infbitlength))	% remove tag
       (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2)))
%       (LDMIA (reg sp) ((reg lr)) writeback) % pop link register
       (BX (reg t2))))

%% could be:
%% (LDMIA (reg sp) ((reg lr)) writeback) % pop link register
%% (LDR (reg pc) (displacement (reg symfnc) (regshifted t3 LSL 2)))


(put 'fast-codeapply    'opencode
     '((*Field (reg t2) (reg t1) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
       (BLX (reg t2))))

(put 'fast-codeapply    'exitopencode
     '((*Field (reg t2) (reg t1) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
%       (LDMIA (reg sp) ((reg lr)) writeback) % pop link register
       (BX (reg t2))))

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
      (setq cfluids fluids) % copy of fluids
preload 
      (cond ((null (and freeregs cfluids) (go afterpreload))))
      (setq initload
	       (progn
		 (setq cadrcfluids
		(nconc cadrcfluids (cons (car freeregs) nil)))
	(nconc initload `((*Move ,(car cfluids) ,(car freeregs))))
       )   )
       (setq freeregs (cdr freeregs))
       (setq cfluids (cdr cfluids))
       (cond ((and freeregs cfluids) (go preload)))
afterpreload
       (setq freeregs (nconc cadrcfluids cfluids)) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and not preloaded fluids if those exist

       %% careful with temp registers:
       %% (reg t3) is clobbered when loading or storing a fluid
      (setq list `((*Move ($fluid BndStkPtr) (Reg t1))
		   (*Move ($fluid BndstkUpperBound) (reg t3))
		   (*wplus3 (Reg t2) (Reg t1) ,lng)
		   (cmp (reg t2) (reg t3))
		   (bmi ,genlabel)
		   (*call Bstackoverflow) % never come back
		  ,genlabel
		   (*Move (Reg t2) ($fluid BndstkPtr))
                   (*Move (reg t1) (reg t2))	       % (reg t1 may be reused in *move
		   ))

      %start of code
      
      (setq list (append initload list))

  loop
      (setq cregs (car Regs))
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	   (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 8))
      (Setq list (append list
     `((*Move ,(car freeregs) (indexed (Reg t2) ,n))
       (*Move (quote ,Cadrcfluids)
		   (indexed (reg t2) ,(wplus2 n -4)))
       (*Move ,cregs ,cfluids)
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
      (setq freeregs '((reg 1)(reg 2)(reg 3)(reg 4)(reg 5)))
      (setq cfluids fluids) % copy of fluids

preload  (setq initload
       (progn (setq cadrcfluids
		(nconc cadrcfluids (cons (car freeregs) nil)))
	(nconc initload `((*Move ,(car cfluids) ,(car freeregs))))
       )   )
       (setq freeregs (cdr freeregs))
       (setq cfluids (cdr cfluids))

       (cond ((and freeregs cfluids) (go preload)))

       (setq freeregs (nconc cadrcfluids cfluids)) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and not preloaded fluids if those exist

       %% careful with temp registers:
       %% (reg t3) is clobbered when loading or storing a fluid
      (setq list `((*Move ($fluid BndStkPtr) (Reg t1))
		   (*Move ($fluid BndstkUpperBound) (reg t3))
                   (*wplus3 (reg t2) (reg t1) ,lng)
		   (CMP (reg t2) (reg t3))
		   (BMI ,genlabel)
                   (*Call Bstackoverflow)  % is never come back
		   ,genlabel

		   (*Move (Reg t2) ($fluid BndstkPtr)) 
                   (*Move (reg t1) (reg t2))		    % (reg t1 may be reused in *move
		   ))

      %start of code
      (setq list (append initload list))

 loop
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	   (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 8))
      (Setq list (append list
	     `((*Move ,(car freeregs) (indexed (Reg t2) ,n))
	       (*Move (quote ,Cadrcfluids)
		           (indexed (reg t2)  ,(wplus2 n -4)))
	       (*Move (quote nil) ,cfluids)
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
      (setq freeregs '((reg 2)(reg 3)(reg 4)(reg 5)))
      (setq cfluids fluids) % copy of fluids
      (setq n (wtimes2 4 (wdifference 2 lng)))
      (setq lng (wtimes2 lng 4)) % * addressingunitperitem
      (setq initload (list '(*Move ($fluid Bndstkptr) (reg t1))))

preload  (setq initload
       (progn (setq listfluids
	       (if freeregs
		(nconc listfluids (cons (car freeregs) nil))
		(nconc listfluids (cons nil nil))) )
	(nconc initload
	 (if freeregs
     `((*Move (displacement (reg t1) ,n) ,(car freeregs))) nil)
       )   ))
       (setq n (wplus2 n 8))
       (when freeregs (setq freeregs (cdr freeregs)))
       (setq cfluids (cdr cfluids))

       (cond (cfluids (go preload)))

       (setq freeregs listfluids ) %end of preloadcode

       % freeregs contains the list of preloaded regs
       % and nil if not enough regs available

       %% careful with temp registers:
       %% (reg t3) is clobbered when loading or storing a fluid
       (setq list `((*Move ($fluid BndstkLowerBound) (reg t3))
		    (SUB (reg t2) (reg t1) ,lng)
		    (CMP (reg t2) (reg t3))
		    (BPL ,genlabel)
		    (*Call Bstackunderflow) % never returns
		   ,genlabel
		   (*Move (reg t2) ($fluid Bndstkptr)) 
                   (*Move (reg t1) (reg t2))
		   ))

     %start of code
     (setq list (append initload list))
     (setq n 0)<

 loop
      (setq cfluids (car Fluids))
      (setq n (wplus2 n 8))

  % insert reloaded register or memory reference

      (setq list (append list
	   (if (car freeregs) `((*Move ,(car freeregs) ,cfluids ))
		`((*Move (displacement (reg t2) ,n) ,cfluids )))

      )          )
      (setq freeregs (cdr freeregs))
      (cond ((setq Fluids (cdr Fluids)) (go loop)))
      (return list)
)    )

(DefCMacro *freerstr)

(setq *unsafebinder t)   % has to save Registers across calls

(global '(*writingasmfile))

(de !*xjumpon (register lowerbound upperbound labellist)
      (for (from x lowerbound upperbound)
                (join
                  `((CMP ,x ,register)
                    (BEQ ,(pop labellist))))))


(de !*JumpOn (register lowerbound upperbound labellist)
   (if *writingasmfile
       (*xjumpon register lowerbound upperbound labellist)
     (PROG (X LL LL2)
       (setq ll  (gensym))
       (setq ll2 (stringgensym))
       (SETQ X
	(if (and (weq lowerbound 0) (weq upperbound 31))
					% jumpon on tags (most probably)
					% 4 bytes per jumptable entry
      `((LDR (reg pc) (displacement (reg pc) (regshifted ,(cadr register) LSL 2)))
	% new value of the PC is:
	% (address of the LDR instruction) + PC + 8 + 4*(contents of register)
	% therefore we need 4 bytes (one instruction) to jump over
	(B (label ,ll))
       ,ll2)
      `((cmp ,register ,upperbound )
	(beq ,(lastcar labellist))
	(bgt (label ,ll))
	(cmp ,register ,Lowerbound )
	(blt (label ,ll))
        (*WDifference ,register ,lowerbound)
	(LDR (reg pc) (displacement (reg pc) (regshifted ,(cadr register) LSL 2)))
	(B (label ,ll))		        % extra instruction to jump over
       ,ll2) ) )
      Loop  (Setq x (nconc X `((fullword ,(car Labellist)))))
	    (setq Labellist (cdr Labellist))
	    (cond (Labellist (go loop)))

	    (setq x (nconc x `((*lbl (Label ,ll))) ))
	    (return x)
)  )  )

(DefCMacro !*JumpOn)



% Call foreign fns (loaded by oload) by putting SymFunc cell addr in a reg,
% then doing "calls" instr indirect via the target address of the jmp
% instruction stored there.  Use old direct link for asm (kernel) compile.

(de *ForeignLink (functionname functiontype numberofarguments)

    %% stack has to be aligned on an 8byte boundary for doubles to be handled correctly.
    `((STMDB (reg st) ((reg r1) (reg r2) (reg r3) (reg r4) (reg r8) (reg r9) (reg r10) (reg r11) (reg r12) (reg lr)) writeback) % save caller-saved registers
      (!*Move (reg sp) (reg r6))
      (MVN (reg r7) (wconst 7))
      (SUB (reg sp) (reg sp) 8)
      (AND (reg sp) (reg sp) (reg r7))
      (!*Move (reg r6) (displacement (reg sp) 0))
%      (*Move (quote t) (fluid *kernelmode))
      (BLX (foreignentry ,functionname))
%      (*Move (reg NIL) (fluid *kernelmode))
      (!*Move (displacement (reg sp) 0) (reg sp))
      (LDMIA (reg st) ((reg r1) (reg r2) (reg r3) (reg r4) (reg r8) (reg r9) (reg r10) (reg r11) (reg r12) (reg lr)) writeback))) % restore saved registers

(DefCMacro !*foreignlink)

(put 'bstruct-tag 'compiler-constant? t)
(put 'hbytes-tag 'compiler-constant? t)
(put 'hhalfwords-tag 'compiler-constant? t)
(put 'hwords-tag 'compiler-constant? t)
(put 'hvect-tag 'compiler-constant? t)
(put 'forward-tag 'compiler-constant? t)
(put 'btr-tag 'compiler-constant? t)
(put 'unbound-tag 'compiler-constant? t)
(put 'id-tag 'compiler-constant? t)
(put 'negint-tag 'compiler-constant? t)

(put 'bstruct-tag 'compiler-constant-value 22)
(put 'hbytes-tag 'compiler-constant-value 23)
(put 'hhalfwords-tag 'compiler-constant-value 24)
(put 'hwords-tag 'compiler-constant-value 25)
(put 'hvect-tag 'compiler-constant-value 26)
(put 'forward-tag 'compiler-constant-value 27)
(put 'btr-tag 'compiler-constant-value 28)
(put 'unbound-tag 'compiler-constant-value 29)
(put 'id-tag 'compiler-constant-value 30)
(put 'negint-tag 'compiler-constant-value 31)

(put 'infbitlength 'compiler-constant 27)
