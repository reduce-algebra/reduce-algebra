%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXC:aarch64-CMAC.sl
% Title:          Patterns and predicates for ARM v8 PSL cmacro expansion
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
% PosShiftInumP      31 >= x >=         0          (  5 bits, unsigned) 
% NegShiftInumP       0 >  x >=       -31          (  5 bits, unsigned)

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

(de PosShiftInumP (Expression) (and (IntP Expression)
                                         (GreaterP Expression 0)
                                         (leq      Expression 31)))
 
(de NegShiftInumP (Expression) (and (IntP Expression)
                                         (minusp Expression)
                                         (geq    Expression -31)))
 
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
               '( 1  2  3  4  5  6  7  8
                     X0 X1 X2 X3 X4 X5 X6 X7 X8 X9 X10 X11 X12 X13 X14 X15
		     X16 X17 X18 X19 X20 X21 X22 X23 X24 X25 X26 X27 X28 X29 X30
                     W0 W1 W2 W3 W4 W5 W6 W7 W8 W9 W10 W11 W12 W13 W14 W15
		     W16 W17 W18 W19 W20 W21 W22 W23 W24 W25 W26 W27 W28 W29 W30
		     sp st fp lr Xzr Wzr
                     t1 t2 t3
             nil heaplast heaptrapbound symfnc symval
             bndstkptr bndstklowerbound bndstkupperbound
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

(de EightP (x)  (eq x 8))

(de TwentySevenP (x)  (eq x 27))

(de FiftySixP (x) (eq x 56))

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
           (       (!*Field REGISTER SOURCE 8 56)
                   (displacement REGISTER 0))
)

(DefAnyreg CDR
           AnyregCDR     %Same as CAR, except move to next word in pair.
           (       (!*Field REGISTER SOURCE 8 56)
                   (Displacement REGISTER 8)))


(DefAnyreg Memory
           AnyregMEMORY
           ((RegP ZeroP)      (indirect SOURCE))
	   ((fluid-arg-p ZeroP) (*Move SOURCE (reg t3))
                               (indirect (reg t3)))
           ((Anyp ZeroP)      (*Move SOURCE REGISTER)
                               (indirect REGISTER))
           ((RegP twelve-bit-p)      (Displacement SOURCE ARGTWO))
	   ((fluid-arg-p twelve-bit-p) (*Move SOURCE (reg t3))
                               (Displacement (reg t3) ARGTWO))
           ((AnyP twelve-bit-p)      (*Move SOURCE REGISTER)
                               (Displacement REGISTER ARGTWO))
           ((RegP RegP)       (Indexed ARGTWO (Displacement source 0)))
           ((RegP AnyP)       (*Move SOURCE REGISTER)
                               (*WPlus2 REGISTER ARGTWO)
                               (indirect REGISTER))
	   ((fluid-arg-p DispInumP)  (!*Move SOURCE (reg t3))
                               (Indexed (reg t3) (Displacement ARGTWO 0)))
           ((AnyP DispInumP)  (!*Move SOURCE REGISTER)
                               (Indexed REGISTER (Displacement ARGTWO 0)))
           (                   (!*Move SOURCE REGISTER)
                               (!*WPlus2 REGISTER ARGTWO)
                               (indirect REGISTER)))


(DefAnyreg FRAME
  AnyregFRAME
%           ((zerop)  (Indirect (reg st)))
           (         (Displacement (REG st) (plus2 (times2 2 8) SOURCE))))

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
%          ((Int32P)  (quote SOURCE))  % more that 32 bits
           ((INumP)  SOURCE)    %?
           ((Null) (REG NIL))
           (       (QUOTE SOURCE)))   %? Recursivly expand??
 
%(DefAnyreg WCONST
%           AnyregWCONST
%          ((Int32P)  (quote SOURCE))  % more that 32 bits
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
        (         (*Move (idloc ArgOne) (reg t3))
                  (LDR (reg t2) (indexed (reg symfnc) (regshifted t3 LSL 3)))
                  (BLR (reg t2)))
)

(DefCMacro *JCall
       ((InternallyCallableP)  (B (InternalEntry ArgOne)))
        (         (*Move (idloc ArgOne) (reg t3))
                  (LDR (reg t2) (indexed (reg symfnc) (regshifted t3 LSL 3)))
                  (BR (reg t2)))
)


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
       ((regp regp)              (MOV ArgTwo ArgOne))
       ((imm8-rotatedp regp)     (MOV Argtwo ArgOne))
       ((quotep regp)            (LDR ArgTwo ArgOne))
       ((InumP regp)             (*LoadConstant ArgTwo ArgOne))
       ((fixp regp)              (*LoadConstant ArgTwo ArgOne))
%       ((true-p regp)            (*LoadIDLoc t ArgTwo)
%                                (*MkItem ArgTwo (compiler-constant 'id-tag)))
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

%% ToDo!
(de *LoadConstant (dest cst)
    (cond ((sixteenbit-p cst)
           `( (MOV ,dest ,(land 16#ffff cst))))
          ((sixteenbit-p (lnot cst))
           `( (MOVN ,dest ,(land 16#ffff (lnot cst)))))
          ((InumP cst)
           `( (LDR ,dest (sysint ,cst))))
          (t
           `( (LDR ,dest (quote ,cst))))
          )
    )

(DefCMacro *LoadConstant)

%%% *LoadIDLoc and *LoadIdNumber need to load the internal number (id2int id) of an
%%% identifier id into (reg t3). It looks like a good idea to use (idloc id) as a
%%% constant, since it would be replaced by a relocatable id number later in
%%% Depositexpression.
%%% However, ExpandItem and friends in pass-1-lap.sl cannot easily distinguish between
%%%  (idloc id)   and    (quote (idloc id)),
%%% since the quote in the latter form is stripped before passing it on.
%%% Therefore, a special form (saveidloc id) is used.  This will be handled in
%%% ExpandItem (see the redefintion in armv6-spec.sl.

(de *LoadIDLoc (dest src)
  (let ((idnumber (WConstEvaluable src))
        (comment (if *writingasmfile `((comment ,@src)))))
    (append comment
      (cond ((and (fixp idnumber) (wlessp idnumber 257))
             (*LoadConstant dest (id2int (cadr src))))
            ((and *writingasmfile (fixp idnumber))
             `( (ldr ,dest (quote ,idnumber))))
            (t
             `( (ldr ,dest ,(SaveConstant `(saveidloc ,(cadr src))))))
    ))))


(DefCMacro *LoadIDLoc)

(de *LoadIdNumber (load-or-store reg nonlocal)
  (let ((idnumber
         (WConstEvaluable `(idloc ,(cadr nonlocal))))
        (comment (if *writingasmfile `((comment ,@nonlocal)))))
    (append comment
      (if (and idnumber (fixp idnumber) (lessp idnumber 4096) (greaterp idnumber -1))
        `( (,load-or-store ,reg (indexed (reg symval) ,(times 8 idnumber))) )
       `( (LDR (reg t3) ,(if (null idnumber) (SaveConstant `(saveidloc ,(cadr nonlocal))) `(quote ,idnumber))) 
         (,load-or-store ,reg (indexed (reg symval) (regshifted t3 LSL 3))) )
      ))))

(DefCMacro *LoadIdNumber)

(de *LoadImmediate (dest src)
    (setq src (unimmediate src))
    (print (list src (prop (unimmediate src))))
    (if (not (idp src))
        `((LDR ,dest ,(unimmediate src)))
      `((ADRL ,dest ,src)))             % two instruction load address pseudo-op
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
%% *Alloc pushes the link register and frame pointer onto the stack and allocate framesize stack frames
%% If framesize is odd, this means that the stack pointer is not 16 byte aligned.
%% In this case, write an extra value of nil onto the stack immediately below fp
%%  and increase NAlloc!* by 1.
%% Hence, for odd framesize the instructions are
%%  STP fp, lr , [sp, -#n]!   n = 8*(number of frames + 1 + 2)
%%  STR (reg nil), [sp, #(8*framesize+8)]
(de *ALLOC (framesize)
    (let (ll)
      (if (greaterp framesize 0)
	(progn
	  %% Make sure that the stack is always 16 byte aligned
	  (if (oddp framesize)
            (progn
	      (setq framesize (add1 framesize))
	      (setq ll `((STR (reg nil) (displacement (reg sp) ,(times2 (plus2 1 framesize) (compiler-constant 'AddressingUnitsPerItem))))))))
	  (setq NAlloc!* framesize)))
      `((STP (reg fp) (reg lr)
      	     (preindexed (reg sp)
			 ,(minus (times2 (plus2 2 framesize) (compiler-constant 'AddressingUnitsPerItem)))))
	(MOV (reg fp) (reg sp))
	,@ll)))

(DefCmacro *ALLOC)

(de *DeAlloc (DeAllocCount)
  (if (oddp DeAllocCount) (setq DeAllocCount (plus2 DeAllocCount 1)))
  (Expand1OperandCMacro
   %% room for fp and lr
   (times (plus 2 DeAllocCount) (compiler-constant 'AddressingUnitsPerItem))
   '*DeAlloc))

(DefCmacro *DeAlloc
           ( 
                        % pop link register
                       (LDP (reg fp) (reg lr) (postindexed (reg sp) ARGONE)))
)


% Again, make sure that the stack is always 16 byte aligned
(de *Exit (N)
  (if (oddp N) (setq N (plus2 N 1)))
 (Expand1OperandCMacro
   %% room for fp and lr
   (times (plus2 2 N) (compiler-constant 'AddressingUnitsPerItem)) '*Exit))

(DefCMacro *Exit     % leaf routine first
   (         (LDP (reg fp) (reg lr) (postindexed (reg sp) ARGONE))
             (RET)))

(de displacementp (x) (and (pairp x) (eq (car x) 'displacement)))

(de deferredp (x) (eqcar x 'deferred))

(DefCMacro *Jump
           ((indirectp)              (!*Move ArgOne (reg t1))
                                     (BR (reg t1)))
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
                (BR (reg lr))))
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
		       % check whether the opncode sequence ends with *Call
		       % and replace it with *JCall
		       (if (eqcar (lastcar OpenCodeSequence) '*Call)
			   (progn
			     (setq OpenCodeSequence (reversip OpenCodeSequence))
			     (setq OpenCodeSequence
				   (reversip
				    (cons
				     (cons '*JCall (cdr (car OpenCodeSequence)))
				     (cdr OpenCodeSequence)))))
			 (setq OpenCodeSequence
			       (Append OpenCodeSequence
				 (list '(BR (reg lr))))))
		       % check that there isn't another *Call somewhere
		       (if (atsoc '*Call OpenCodeSequence)
			   (stderror
			    (bldmsg "Cannot have *Call in opencode sequence for %w")
			    FunctionName)
			 OpenCodeSequence
			 ))
                      (t (CMacroPatternExpand (list FunctionName)
                                              (get '*JCall
                                                   'CMacroPatternTable)))))))


%(DefCMacro *Push
%  ( (!*Move ArgOne (displacement (reg st) -8 preindexed))))

%(DefCMacro *Pop
%  ( (!*Move (displacement (reg st) 8 postindexed) ArgOne)))

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
%                                      (ResolveOperand '(REG t2) Arg2)
%                                      (ResolveOperand '(REG t3) Arg3))
%                                (get CMacroName 'CMacroPatternTable)))))

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
           ((regp zerop regp) (NEG ArgOne 0))
           ((regp regp zerop) (*Move ArgOne ArgTwo))
           ((regp regp negp) (*WPlus3 ArgOne ArgTwo (minus ArgThree)))
           ((regp regp regp) (SUB ArgOne ArgTwo ArgThree))
           ((regp imm8-rotatedp regp)
	   	                (*Move ArgTwo (reg t3))
                                (SUB ArgOne (reg t3) Argthree))
           ((regp regp imm8-rotatedp)
                                (SUB ArgOne ArgTwo ArgThree))
           ((regp imm8-rotatedp anyp)
	   	   		(*Move ArgTwo (reg t2))
                                (*Move ArgThree (reg t3))
                                (SUB ArgOne (reg t2) (reg t3)))
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

(put 'wdivide 'opencode
     % returns (signed) quotient and puts remainder in *second-value*
     '( % save dividend and divisor on stack
        (*Push (reg 1))
        (*Push (reg 2))
        (*Call wquotient)
	(*Pop (reg t2))
	(*Pop (reg t1))
	% calculate remainder as t1-q*t2
	(MUL (reg 2) (reg 1) (reg t2))
	(SUB (reg 2) (reg t1) (reg 2))
        (*Move (reg 2) (fluid *second-value*))
      ))

(de *WNegate(ARG1)
 (Expand1OperandCMacro ARG1 '*WNegate))
 
(DefCMacro *WNegate
           (                  (!*WDifference3 ArgOne 0 ArgOne))
 )
 
(DefCMacro *WMinus
        ((regp regp)  (rsb ArgOne ArgTwo 0))
        ((regp Anyp)  (*Move ArgTwo ArgOne)
                      (rsb ArgOne ArgOne 0))
        (             (*Move ArgTwo (reg t2))
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


(put 'wquotient 'opencode '((SDIV (reg x0) (reg x0) (reg x1))))

(put 'wquotient-unsigned 'opencode '((UDIV (reg x0) (reg x0) (reg x1))))

(put 'wremainder 'opencode '((SDIV (reg t1) (reg x0) (reg x1))
			     (MSUB (reg x0) (reg t1) (reg x1) (reg x0))))

(put 'wremainder-unsigned 'opencode '((UDIV (reg t1) (reg x0) (reg x1))
			              (MSUB (reg x0) (reg t1) (reg x1) (reg x0))))

(put 'wdivide 'opencode '((SDIV (reg t1) (reg x0) (reg x1))
			  (MSUB (reg t1) (reg t1) (reg x1) (reg x0))
			  (*Move (reg t1) ($fluid *second-value*))))


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
                      (B!.GE templabel)
                      (NEG (reg t2) ArgOne)
                      (ASR ArgOne ArgOne (reg t2))
                      (B templabel2)
                     templabel
                      (*lsl ArgOne ArgOne ArgTwo)
                     templabel2)

    ((regp anyp)     (*Move ArgTwo (reg t2))
                      (*AShift ArgOne (reg t2)))
    ((Anyp fixp)      (*Move ArgOne (reg t1))
                      (*AShift (reg t1) ArgTwo)
                      (*Move (reg t1) ArgOne))
    (                 (*Move ArgOne (reg t1))
                      (*AShift (reg t1) ArgTwo)
                      (*Move (reg t1) ArgOne))
)


(DefCMacro *WShift
    ((AnyP ZeroP))
    ((regp negp)     (*lsr ArgOne ArgOne (minus ArgTwo)))
    ((regp fixplusp) (*lsl ArgOne ArgOne ArgTwo))
    ((regp regp)     (CMP argtwo 0)
                      (B!.GE templabel)
                      (NEG (reg t2) ArgTwo)
                      (LSR ArgOne Argone (reg t2))
                      (B templabel2)
                     templabel
                      (LSL ArgOne ArgOne ArgTwo)
                     templabel2)
    ((regp anyp)     (*Move ArgTwo (reg t2))
                      (*Wshift ArgOne (reg t2)))
    ((Anyp fixp)      (*Move ArgOne (reg t1))
                      (*Wshift (reg t1) ArgTwo)
                      (*Move (reg t1) ArgOne))
    (                 (*Move ArgOne (reg t1))
                      (*Wshift (reg t1) ArgTwo)
                      (*Move (reg t1) ArgOne)))


(de *WLshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WLshift))
 
(DefCMacro *WLShift                     %Logical shift to the left.
           ((AnyP ZeroP)           )
           ((RegP OneP)       (*WPLUS2 ARGONE ARGONE))
           ((RegP NegP)       (*Cerror "*WLshift with negative shift amount"))
           ((RegP InumP)      (*lsl ArgOne ArgOne ArgTwo))
           ((RegP regP)       (*lsl ArgOne ArgOne ArgTwo))
           ((RegP AnyP)       (*Move ARGTWO (Reg t2))
                              (*WLShift argone (reg t2)))
           (                  (*Move ARGONE (Reg t1))
                              (*WLShift (Reg t1) ARGTWO)
                              (*Move (Reg t1) ARGONE))
)
 
(de *WRshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WRshift))
 
(DefCMacro *WRShift                     %Logical shift to the right
           ((AnyP  ZeroP)           )
           ((RegP NegP)       (*Cerror "*WRshift with negative shift amount"))
           ((RegP InumP)      (*lsr ArgOne ArgOne ArgTwo))
           ((RegP regP)       (*lsr ArgOne ArgOne ArgTwo))
           ((RegP AnyP)       (*Move ARGTWO (Reg t2))
                              (*WRshift argone (reg t2)))
           (                  (*Move ARGONE (Reg t1))
                              (*WRshift (Reg t1) ARGTWO)
                              (*Move (Reg t1) ARGONE))
)


(DefCMacro *WNot
       ((regp regp)  (MVN ArgOne ArgTwo))
       ((regp imm8-rotatedp) (mvn ArgOne ArgTwo))
       ((regp Anyp)  (*Move ArgTwo ArgOne)
                      (MVN ArgOne ArgOne))
       (             (*Move ArgTwo (reg t2))
                      (*wnot (reg t2) (reg t2))
                      (*Move (reg t2) ArgOne)))

(de *WComplement(ARG1)
 (Expand1OperandCMacro ARG1 '*WComplement))
 
(DefCMacro *WComplement
           (                  (*WNot ARGONE ArgOne))
 )

(DefCMacro *MkItem
       ((regp fixp)     (MOV (reg t3) ArgTwo)
			(BFI ArgOne (reg t3) 56 8))
       ((regp regp)     (BFI ArgOne ArgTwo 56 8))
       ((regp anyp)     (*Move ArgTwo (reg t2))
                         (*Mkitem ArgOne (reg t2)))
       (                (*Move ArgOne (reg t1))
                         (*mkitem (reg t1) ArgTwo)
                         (*Move (reg t1) ArgOne)))

(DefCMacro *Tag
      ((regp regp) (UBFX ArgOne ArgTwo 56 8))
      ((Anyp regp) (UBFX (reg t1) ArgTwo 56 8)
                    (*Move (reg t1) ArgOne))
      ((regp anyp) (*Move ArgTwo ArgOne)
                    (UBFX ArgOne ArgOne 56 8))
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
                     (B!.LE  ArgThree)
                     (CMP (reg t3) 31) % negint-tag)
                     (B!.EQ ArgThree)
                     templabel)
       )

(DefCMacro *JumpNotInType
       (            (*Tag (reg t3) ArgOne)
                     (CMP (reg t3) 31) % negint-tag
                     (B!.EQ templabel)
                     (CMP (reg t3) ArgTwo)
                     (B!.GT ArgThree)
                     templabel)
       )

%---------------------------------------------------------------------
%   General Purpose Jumper.
%   FORMAT: Operand1 Operand2 Address JumpOpCode

(DefCMacro *JumpIF
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
       (*JumpIF ArgOne ArgTwo Lbl '(b!.eq . b!.eq)))

(DefCMacro *JumpNotEQ)

(de *JumpNotEQ(Lbl ArgOne ArgTwo)
        (*JumpIF ArgOne ArgTwo Lbl '(b!.ne . 'b!.ne)))

(DefCMacro *JumpWlessp)

(de *JumpWlessp (Lbl ArgOne ArgTwo)
        (*JumpIF ArgOne ArgTwo Lbl '(b!.lt . b!.ge)))

(DefCMacro *JumpWgreaterp)

(de *JumpwGreaterp (Lbl ArgOne ArgTwo)
        (*JumpIF ArgOne ArgTwo Lbl '(b!.gt . b!.le)))

(DefCMacro *JumpWleq)

(de  *JumpWleq(Lbl ArgOne ArgTwo)
        (*JumpIF ArgOne ArgTwo Lbl '(b!.le . b!.gt)))

(DefCMacro *JumpWgeq)

(de *jumpWgeq (Lbl ArgOne ArgTwo)
        (*JumpIF ArgOne ArgTwo Lbl '(b!.ge . b!.lt)))

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

  ((regp regp Eightp FiftySixP) (UBFX ArgOne ArgTwo 0 56))
  ((regp anyp Eightp FiftySixP) (*Move ArgTwo ArgOne)
                                (UBFX ArgOne ArgOne 0 56))
  ((regp regp zerop fixp) (UBFX ArgOne ArgTwo (difference 64 ArgFour) ArgFour))
  ((regp regp fixp fixp) (UBFX ArgOne ArgTwo (difference 64 (plus2 ArgThree ArgFour)) ArgFour))
  ((regp anyp fixp fixp) (*Move ArgTwo (reg t3))
                         (*Field ArgOne (reg t3) ArgThree ArgFour))
  ((anyp regp fixp fixp) (*Field (reg t1) ArgTwo ArgThree ArgFour)
                          (*Move (reg t1) ArgOne))
  (                      (*Move ArgTwo (reg t2))
                          (*Field (reg t1) (reg t2) ArgThree ArgFour)
                          (*Move (reg t1) ArgOne)))

(DefCMacro *SignedField

  ((regp regp Eightp FiftySixP) (SBFX ArgOne ArgTwo 0 56))
  ((regp anyp Eightp FiftySixP) (*Move ArgTwo ArgOne)
                                (SBFX ArgOne ArgOne 0 56))
  ((regp regp zerop fixp) (SBFX ArgOne ArgTwo (difference 64 ArgFour) ArgFour))
  ((regp regp fixp fixp) (SBFX ArgOne ArgTwo (difference 64 (plus2 ArgThree ArgFour)) ArgFour)
                         (*asr ArgOne ArgOne (difference 32 ArgFour)))
  ((regp anyp fixp fixp) (*Move ArgTwo (reg t3))
                         (*SignedField ArgOne (reg t3) ArgThree ArgFour))
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
    (return (wand x (wshift -1 
       (wdifference 64 (wplus2 StartingBit Length)))))))
 
(de NegMask (Length) (wshift -1 length))
 
(ds ShiftAmt (StartingBit Length)
  (wdifference 64
          (wplus2 StartingBit Length) %always positive.
          ))
 
(DefCMacro *PutField
  ((imm8-rotatedp regP EightP FiftySixP)
                     (AND ArgTwo ArgTwo 16#FF00000000000000)
                     (ORR ArgTwo ArgTwo ArgOne))
           
  ((InumP regP EightP FiftySixP)
                     (*Move ArgOne (reg t1))
                     (BFI ArgTwo (reg t1) 0 56))

  ((RegP regP Eightp FiftySixP)
                     (BFI ArgTwo ArgOne 0 56))

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
 

(deflist '((Byte        ((LDRSB (reg 1) (indexed (reg 1) (reg 2)))))
           (r_Byte      ((LDRSB (reg 1) (indexed (reg 1) (reg 2)))))
           (PutByte     ((STRB (reg w2) (indexed (reg 1) (reg 2)))))
           (HalfWord    ((LDRSH (reg 1) (indexed (reg 1) (reg 2)))))
           (PutHalfWord ((STRH (reg w2) (indexed (reg 1) (reg 2))))))
  'OpenCode)

(&OneReg '(Byte PutByte HalfWord PutHalfWord))

(on fast-integers)


% *feq, *fgreaterp and *flessp can only occur once in a function.

(commentoutcode
 deflist '((*wfix ((ldr (reg d0) (indirect (reg 1)))
                   (fcvtas (reg x0) (reg d0))))
           (*wfloat ((scvtf (reg d0) (reg 1))
                     (str (reg d0) (indirect (reg 1)))))
           (*fgreaterp
                    ((ldr (reg d0) (indirect (reg 1)))
                     (ldr (reg d1) (indirect (reg 2)))
                     (*Move (quote t) (reg 1))
		     (fcmp (reg d0) (reg d1))
                     (b!.gt *donefgreaterp*)
                     (*Move (reg nil) (reg 1))
                *donefgreaterp*))
           (*flessp
	            ((ldr (reg d0) (indirect (reg 1)))
                     (ldr (reg d1) (indirect (reg 2)))
                     (*Move (quote t) (reg 1))
		     (fcmp (reg d0) (reg d1))
                     (b!.lt *doneflessp*)
                     (*Move (reg nil) (reg 1))
                *doneflessp*))
           (*fplus2 ((ldr (reg d0) (indirect (reg 2)))
                     (ldr (reg d1) (indirect (reg 3)))
		     (fadd (reg d0) (reg d0) (reg d1))
                     (str (reg d0) (indirect (reg 1)))))
           (*fdifference
	            ((ldr (reg d0) (indirect (reg 2)))
                     (ldr (reg d1) (indirect (reg 3)))
		     (fsub (reg d0) (reg d0) (reg d1))
                     (str (reg d0) (indirect (reg 1)))))
           (*ftimes2
	            ((ldr (reg d0) (indirect (reg 2)))
                     (ldr (reg d1) (indirect (reg 3)))
		     (fmul (reg d0) (reg d0) (reg d1))
                     (str (reg d0) (indirect (reg 1)))))
           (*fquotient
	            ((ldr (reg d0) (indirect (reg 2)))
                     (ldr (reg d1) (indirect (reg 3)))
		     (fdiv (reg d0) (reg d0) (reg d1))
                     (str (reg d0) (indirect (reg 1))))))
         'opencode)

(DefCMacro *fast-apply-load
   ( (*Move ArgOne (reg t1)) ))

(put 'fast-idapply    'opencode
     '((!*Field (reg t3) (reg t1)  (wconst infstartingbit) (wconst infbitlength))       % remove tag
       (LDR (reg t2) (indexed (reg symfnc) (regshifted t3 LSL 3)))
       (BLR (reg t2))))
     
(put 'fast-idapply    'exitopencode
     '((!*Field (reg t3) (reg t1)  (wconst infstartingbit) (wconst infbitlength))       % remove tag
       (LDR (reg t2) (indexed(reg symfnc) (regshifted t3 LSL 3)))
       (BR (reg t2))))

%% could be:
%% (LDMIA (reg sp) ((reg lr)) writeback) % pop link register
%% (LDR (reg pc) (displacement (reg symfnc) (regshifted t3 LSL 2)))


(put 'fast-codeapply    'opencode
     '((*Field (reg t2) (reg t1) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
       (BLR (reg t2))))

(put 'fast-codeapply    'exitopencode
     '((*Field (reg t2) (reg t1) (wconst infstartingbit) (wconst infbitlength)) % extract codepointer
%       (LDMIA (reg sp) ((reg lr)) writeback) % pop link register
       (BR (reg t2))))

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
      (cond ((null (and freeregs cfluids)) (go afterpreload)))
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
                   (*Move (reg t1) (reg t2))           % (reg t1 may be reused in *move
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
      (setq lng (wtimes2 (length Fluids) 16)) % two words per BndStk entry
                                              % * 8 addressingunits
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
                   (B!.MI ,genlabel)
                   (*Call Bstackoverflow)  % is never come back
                   ,genlabel

                   (*Move (Reg t2) ($fluid BndstkPtr)) 
                   (*Move (reg t1) (reg t2))                % (reg t1 may be reused in *move
      %% (reg t2) is now the old bndstkptr (before increase)
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
                           (indexed (reg t2)  ,(wplus2 n -8)))
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
      (setq n (wtimes2 8 (wdifference 2 lng)))
      (setq lng (wtimes2 lng 8)) % * addressingunitperitem
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
       (setq n (wplus2 n 16))
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
                    (B!.PL ,genlabel)
                    (*Call Bstackunderflow) % never returns
                   ,genlabel
                   (*Move (reg t2) ($fluid Bndstkptr)) 
                   ))

     %start of code
     (setq list (append initload list))
     (setq n 0)

 loop
      (setq cfluids (car Fluids))
      (setq n (wplus2 n 16))

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
                  `((CMP ,register ,x)
                    (B!.EQ ,(pop labellist))))))


(de !*JumpOn (register lowerbound upperbound labellist)
   (if *writingasmfile
       (*xjumpon register lowerbound upperbound labellist)
     (PROG (X LL LL2)
       (setq ll  (gensym))
       (setq ll2 (stringgensym))
       (SETQ X
        (if (and (weq lowerbound 0) (weq upperbound 255))
                                        % jumpon on tags (most probably)
                                        % 8 bytes per jumptable entry
      `((ADR (reg t1) ,ll2)
        (LDR (reg t1) (indexed (reg t1) (regshifted ,(cadr register) LSL 3)))
	(BR (reg t1))
        % new value of the PC is:
        % (address of the LDR instruction) + PC + 8 + 8*(contents of register)
        % therefore we need 4 bytes (one instruction) to jump over
        (B (label ,ll))
       ,ll2)
      `((cmp ,register ,upperbound )
        (b!.eq ,(lastcar labellist))
        (b!.gt (label ,ll))
        (cmp ,register ,Lowerbound )
        (b!.lt (label ,ll))
        (*WDifference ,register ,lowerbound)
	(ADR (reg t1) ,ll2)
	(LDR (reg t1) (indexed (reg t1) (regshifted ,(cadr register) LSL 3)))
	(BR (reg t1))
        (B (label ,ll))                 % extra instruction to jump over
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

    %% stack has to be aligned on an 16byte boundary for doubles to be handled correctly.
    `((STP (reg fp) (reg lr) (preindexed (reg sp) -240))
      (MOV (reg fp) (reg sp))
      %% save caller saved registers
      (STP (reg x1) (reg x2) (displacement (reg sp) 224))
      (STP (reg x3) (reg x4) (displacement (reg sp) 208))
      (STP (reg x5) (reg x6) (displacement (reg sp) 192))
      (STP (reg x7) (reg x8) (displacement (reg sp) 176))
      (STP (reg x9) (reg x10) (displacement (reg sp) 160))
      (STP (reg x11) (reg x12) (displacement (reg sp) 144))
      (STP (reg x13) (reg x14) (displacement (reg sp) 128))
      (STP (reg x15) (reg x16) (displacement (reg sp) 112))
      (STP (reg x17) (reg x18) (displacement (reg sp) 96))
      (STP (reg x19) (reg x20) (displacement (reg sp) 80))
      (STP (reg x21) (reg x22) (displacement (reg sp) 64))
      (STP (reg x23) (reg x24) (displacement (reg sp) 48))
      (STP (reg x25) (reg x26) (displacement (reg sp) 32))
      (STP (reg x27) (reg x28) (displacement (reg sp) 16))
%%?      (!*Move (reg sp) (reg r6))
%%?      (!*Move (reg r6) (displacement (reg sp) 0))
%      (*Move (quote t) (fluid *kernelmode))
      (BL (foreignentry ,functionname))
%      (*Move (reg NIL) (fluid *kernelmode))
      %% restore registers
      (LDP (reg x27) (reg x28) (displacement (reg sp) 16))
      (LDP (reg x25) (reg x26) (displacement (reg sp) 32))
      (LDP (reg x23) (reg x24) (displacement (reg sp) 48))
      (LDP (reg x21) (reg x22) (displacement (reg sp) 64))
      (LDP (reg x19) (reg x20) (displacement (reg sp) 80))
      (LDP (reg x17) (reg x18) (displacement (reg sp) 96))
      (LDP (reg x15) (reg x16) (displacement (reg sp) 112))
      (LDP (reg x13) (reg x14) (displacement (reg sp) 128))
      (LDP (reg x11) (reg x12) (displacement (reg sp) 144))
      (LDP (reg x9) (reg x10) (displacement (reg sp) 160))
      (LDP (reg x7) (reg x8) (displacement (reg sp) 176))
      (LDP (reg x5) (reg x6) (displacement (reg sp) 192))
      (LDP (reg x3) (reg x4) (displacement (reg sp) 208))
      (LDP (reg x1) (reg x2) (displacement (reg sp) 224))
      (LDP (reg fp) (reg lr) (postindexed (reg sp) 240))
      ))

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

(put 'bstruct-tag 'compiler-constant-value 246)
(put 'hbytes-tag 'compiler-constant-value 247)
(put 'hhalfwords-tag 'compiler-constant-value 248)
(put 'hwords-tag 'compiler-constant-value 249)
(put 'hvect-tag 'compiler-constant-value 250)
(put 'forward-tag 'compiler-constant-value 251)
(put 'btr-tag 'compiler-constant-value 252)
(put 'unbound-tag 'compiler-constant-value 253)
(put 'id-tag 'compiler-constant-value 254)
(put 'negint-tag 'compiler-constant-value 255)

(put 'infbitlength 'compiler-constant 56)
