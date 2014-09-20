%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:MINGW-W64-CMAC.SL
% Description:  Patterns and predicates for 386 PSL cmacro expansion
% Author:       Winfried Neun
% Created:      10 December 2004
% Modified:
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(loadtime (progn
	(RemProp 'Wtimes2 'OpenFn)     % So need explicit code
	(RemProp 'Wtimes2 'MemModFn)   % Since no longer a cmacro
	(RemProp '*MpyMem 'UnMemMod)   %   "    "   "    "    "
 ))  %  (RemProp 'WQuotient 'OpenCode)
     %  (RemProp 'WRemainder 'OpenCode)))
 
 
(fluid '(AddressingUnitsPerItem       % Constants defined in data machine.
     *ImmediateQuote
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
 
(setf *ImmediateQuote NIL)
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                    NECESSARY FUNCTIONS
% These are useful macros for defining Cmarco pattern tables.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(compiletime (setq savebitmask 'bitmask))
(compiletime (remob 'bitmask)) % avoid loss of bitmask for field operations

(commentoutcode de BitMask (StartingBit Length)
  (prog(x)
    (setq x (wshift -1 (wminus StartingBit)))
    (return (wand x (wshift -1 
       (wdifference BitsPerWord (wplus2 StartingBit Length)))))))
 
(de NegMask (Length) (wshift -1 length))
 
(ds ShiftAmt (StartingBit Length)
  (wdifference 64 % BitsPerWord
	  (wplus2 StartingBit Length) %always positive.
	  ))
 
(de MakeTag (tag) (wshift (wand tag 16#ff) 56))
 
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
	  '( 1  2  3  4  5 st t1 t2 rax rcx rdx rbx rsp rbp rsi rdi
				eax ebx
				     al  cl ax cx es cs ss ds fs gs))))
 
(DefList '((RAX   1) (RBX   2) (RCX   3) (RDX   4) (RBP   5) )
	 'RegisterNumber)
 
(de RegisterNumber (RegSymbol)
% registers numbered according to D register model                        scs
  (cond ((NumberP RegSymbol) Regsymbol)
    ( T (OR (GET REGSYMBOL 'REGISTERNUMBER)
	(StdError (BldMsg "Unknown register %r"  RegSymbol))))
    ))
 
 
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

(de BigIntP (x) (and (intp x) (not (eq x (ashift (wshift x 32) -32)))))
 
(de TaggedLabel (X) (EqCar X 'Label))
 
 
% For powers of two we could implement (de poweroftwoP (x) (zerop (land x
%                                                           (sub1 x))))
 
(de Minus1P     (x) (equal x  -1))
(de OneP        (x) (equal x   1))
(de TwoP        (x) (equal x   2))
(de FourP       (x) (equal x   4))
(de fivep       (x) (equal x   5))
(de SixP        (x) (equal x   6))
(de EightP      (x) (equal x   8))
(de TenP        (x) (equal x  10))
(de SixteenP    (x) (equal x  16))
(de fixzerop    (x) (eq x 0))
(de TwentysevenP (x) (equal x  27))
(de fiftysixP (x)    (equal x  56))
 
 
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
 
 
%%%%%%%%%%%%%%%%%%%%% scs %%%%%%%%%%% scs %%%%%%%%%%%%%%%%% scs %%%%%%%%%%
 
(DefAnyreg CAR
           AnyregCAR   %Grab the source so caller can displace off it.
%          ((regp anyp)    (displacement source 16#c0000000))
%          ((anyp regp)    (*move SOURCE REGISTER)
%                         (displacement REGISTER 16#c0000000))
           (       (!*Field REGISTER SOURCE InfStartingBit InfBitLength)
                   (indirect REGISTER))
)

(DefAnyreg CDR
           AnyregCDR     %Same as CAR, except move to next word in pair.
%          ((regp anyp)    (displacement source 16#c0000004))
%          ((anyp regp)    (*move SOURCE REGISTER)
%                          (displacement REGISTER 16#c0000004))
           (       (!*Field REGISTER SOURCE InfStartingBit InfBitLength)
                   (Displacement REGISTER 8)))

 
% This new version is based on the old Sun 3.2 cmacro. It is designed to act
%  without the help of the memory pattern under most circumstances. Previously
%  the pattern, was doing most of work using the 14 real reg model.
%
(DefAnyreg MEMORY
	   AnyregMEMORY
	   ((RegP ZeroP)      (indirect SOURCE))
%   ((RegP ZeroP)      (*move SOURCE REGISTER)
%		      (indirect REGISTER))
	   ((Anyp  ZeroP)      (*MOVE SOURCE REGISTER)
			       (indirect REGISTER))
 	   ((RegP InumP)  (Displacement SOURCE ARGTWO))
	   ((AnyP InumP)  (*MOVE SOURCE REGISTER)
			   (Displacement REGISTER ARGTWO))
	   ((RegP RegP)    (Indexed ARGTWO (Displacement source 0)))
	   ((RegP  AnyP)       (*MOVE SOURCE REGISTER)
			       (*WPLUS2 REGISTER ARGTWO)
			       (indirect REGISTER))
	   ((AnyP DispInumP)   (!*MOVE SOURCE REGISTER)
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
	   (       (QUOTE SOURCE)))   %? Recursivly expand??
 
(DefAnyreg WCONST
           AnyregWCONST
	   ((BigIntP)  (quote SOURCE))  % more that 32 bits
           (SOURCE))
 
(DefAnyreg REG
	   AnyregREG
	   ((FakeRegP)        (extrareg source))
	   (                  (REG SOURCE)))
 
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
 
(DefCMacro *Loc                           % This needs more study    scs
	  ((regP ImmediateP)(lea (unimmediate ARGTWO) ARGONE))
	  ((RegP AnyP)      (lea              ARGTWO  ARGONE))
	  ((AnyP  ImmediateP)(*MOVE           ARGTWO  ARGONE))
	  (                  (lea              ARGTWO (Reg T2))
			     (*MOVE          (Reg T2) ARGONE)))
 
 
 
% Changed to use regs t0 and t1. Originally used regs t1 and t2, which caused
%  a register conflict in fastapply since it uses reg t2 to store the arg
%  list. The conflict occured when the number of args > maxnargs, since the
%  move from the argumentblock needed reg t2, which destroyed the argument
%  list.

(de quotep (x) (eqcar x 'quote))

(commentoutcode
(de *Move (Source Destination)            % redefined from COMMON-CMACROS
  (prog (resultingcode*)
    (return
     (CMacroPatternExpand
      (list (ResolveOperand '(REG t1) Source)
	    (ResolveOperand '(REG t2) Destination))
      (get '*Move 'CMacroPatternTable)))))
) 

%modification of *move (HM):
%   (*move (car (cdr ... )) (reg x))
%   use (reg x) as intermediate aux register in order
%   to get parallelized car/cdr loads 

(de *Move (Source Destination)            % redefined from COMMON-CMACROS
  (let (resultingcode* r)
    (CMacroPatternExpand
      (list
	 (if (and 
		 (pairp Source)
		 (memq(car Source) '(car cdr))
		 (pairp (setq r (regp Destination)))
		 (numberp (car r))
	     ) 
	    (ResolveOperand Destination Source)
	    (ResolveOperand '(REG t1) Source))
	    (ResolveOperand '(REG t2) Destination))
      (get '*Move 'CMacroPatternTable)
 )))

(DefCMacro *Move                          %  (*Move Source Destination)
   ( Equal              )                  % if source=dest then do nothing
   ((fixzerop   regp) (xor ArgTwo ArgTwo))
%%   ((onep       regp) (xor ArgTwo ArgTwo)
%%		      (inc ArgTwo))
%%   ((minus1p    regp) (xor ArgTwo ArgTwo)
%%		      (dec ArgTwo))
   ((AnyP       regP) (mov ARGONE ARGTWO))
   ((regp       anyp) (mov argone argtwo))
%   ((quotep     anyp) (movq argone argtwo))
   ((inump      anyp) (movq argone argtwo)) 
   (                  (*move argone (reg t1))
		      (*move (reg t1) argtwo))
   )
 
(DefCMacro *Pop
 (    (pop ARGONE)))
 
(DefCMacro *Push 
 (    (push ARGONE )))
 
(DefCMacro *WPlus2                %  (*WPlus2 dest source)
 ((AnyP ZeroP)         )
%% ((Anyp Onep)         (inc ArgOne))
%% ((Anyp Minus1p)      (dec ArgOne))
 ((RegP AnyP)         (add ARGTWO ARGONE))
 ((AnyP RegP)         (add ARGTWO ARGONE))
 ((Anyp Inump)        (addq ArgTwo ArgOne))
 (                    (*MOVE  ARGTWO (Reg t2))
		      (add (Reg t2) ARGONE))
)
 
(DefCMacro *WDifference                                        %  scs
	   ((AnyP  ZeroP)       )
	   (equal             (*MOVE 0 ARGONE))
%%	   ((Anyp Onep)       (dec ArgOne)) 
%%	   ((Anyp Minus1p)    (inc ArgOne))
	   ((regP AnyP )      (sub ARGTWO ARGONE))
	   ((AnyP regP )      (sub ARGTWO ARGONE))
	   ((Anyp Inump)      (subq ArgTwo Argone)) 
	   (                  (*MOVE  ARGTWO (Reg t2))
			      (sub (Reg t2) ARGONE))
)

(deflist '(
         (Byte    ((movb (indexed (reg 2) (displacement (reg 1) 0)) (reg AL))
                   (cbw)
                   (cwde) (cdqe)))
         (r_Byte  ((movb (indexed (reg 2) (displacement (reg 1) 0)) (reg AL))
                   (cbw)
                   (cwde) (cdqe)))
        (PutByte  ((movb (reg CL) (indexed (reg 1) (displacement (reg 2) 0)))))
        (HalfWord ((shl 1 (reg 2))
                    (movw (indexed (reg 2) (displacement (reg 1) 0))(reg AX))
                    (cwde)(cdqe)))
        (PutHalfWord ((shl 1 (reg 2))
                    (movw (reg CX) (indexed (reg 1)(displacement (reg 2) 0))))))
  'OpenCode)

(put 'wtimes2 'opencode '((imul (reg 2) (reg 1))))

(put 'wquotient 'opencode '(%(*move (reg 1) (reg eax))
			    (cqto)
			    (idiv (reg 2))
			    ))%%%%(*move (reg eax) (reg 1))))

(put 'wremainder 'opencode '(%(*move (reg 1) (reg eax))
			    (cqto)
			    (idiv (reg 2))
			    (*move (reg rdx) (reg 1))))

(put 'wdivide 'opencode '(%%(*move (reg 1) (reg eax))
			    (cqto)
			    (idiv (reg 2))
			   %(*move (reg eax) (reg 1))
			    (*move (reg rdx) ($fluid *second-value*))))

(de *WNegate(ARG1)
 (Expand1OperandCMacro ARG1 '*WNegate))
 
(DefCMacro *WNegate
	   (                  (neg ARGONE))
 )
 
(DefCMacro *WMinus                                               %  scs
	   ((AnyP  InumP)     (*MOVE (MINUS ARGTWO) ARGONE))
	   ( Equal            (*WNegate ARGONE))
	   ((regP AnyP)       (*MOVE ARGTWO ARGONE)
			      (neg ARGONE))
	   (                  (*WMinus ARGTWO (Reg T1))
			      (*MOVE (reg t1) ARGONE))
)
 
(de *WComplement(ARG1)
 (Expand1OperandCMacro ARG1 '*WComplement))
 
(DefCMacro *WComplement
	   (                  (not ARGONE))
 )

(de *Wcmp(arg1 arg2)
  (Expand2OperandCMacro arg1 arg2 '*Wcmp))

(DefCmacro *Wcmp
       ((Anyp Regp) (cmp argone argtwo))
       ((Regp Anyp) (cmp argtwo argone))
       (            (*Move argone (reg t1))
		    (cmp argtwo (reg t1)) ))
 
(DefCMacro *WNot
	   ((AnyP  InumP)     (*MOVE (LNOT ARGTWO) ARGONE))
	   ( Equal            (*WComplement ARGONE))
	   ((regP AnyP)       (*MOVE ARGTWO ARGONE)
			      (not ARGONE))
	   (                  (*WNot ARGTWO (Reg T1))
			      (*MOVE (reg t1) ARGONE))
 )
 
(DefCMacro *WAnd
	   ( equal                )
	   ((AnyP  Minus1P)       )
	   ((AnyP  ZeroP)       (*MOVE  0 ARGONE))
	   ((RegP AnyP)         (and ARGTWO ARGONE))
	   ((AnyP  RegP)        (and ARGTWO ARGONE))
	   ((AnyP  InumP)       (and ARGTWO ARGONE))
	   (                    (*MOVE  ARGTWO (Reg t2))
				(and  (Reg t2) ARGONE))
)
 
(DefCMacro *WOr                                               %  scs
	   ( equal                )
	   ((AnyP  ZeroP)         )
	   ((AnyP  Minus1P)     (*MOVE -1 ARGONE))
	   ((RegP AnyP)         (or ARGTWO ARGONE))
	   ((AnyP  RegP)        (or ARGTWO ARGONE))
	   ((AnyP  InumP)       (or ARGTWO ARGONE))
	   (                    (*MOVE  ARGTWO (Reg t2))
				(or (Reg t2) ARGONE))
)
 
(DefCMacro *WXOr                                                %  scs
	   ((AnyP  ZeroP)         )
	   ( equal              (*MOVE  0 ARGONE))
	   ((AnyP  Minus1P)     (*WNOT    ARGONE))
	   ((AnyP  InumP)       (xor ARGTWO ARGONE))
	   ((AnyP  RegP)        (xor ARGTWO ARGONE))
	   (                    (*MOVE  ARGTWO (Reg t1))
				(xor (Reg t1) ARGONE))
)
 
 
% ----------
% Ashift
% +index shifts left and shifts in zeroes.
% -index shifts right and sign extends.
%  ARGONE <- ARGONE shifted by ARGTWO
%------------------------------------------
 
(de reg3p (x) (equal x '(reg 3)))

(DefCMacro *AShift                                            %    scs
	   ((AnyP  ZeroP)           )
	   ((AnyP  PosInumP)  (*WShift ARGONE ARGTWO))
	   ((RegP NegInumP)   (sar (minus ARGTWO) ARGONE))
	   ((Reg3p Reg3p)     (*cerror "So Geht das nicht"))
	   ((Reg3P regP)      (xchg ArgOne ArgTwo)
			      (*Ashift ArgTwo ArgOne)
			      (xchg ArgOne ArgTwo))
	   ((RegP reg3P)      (cmp 0 ARGTWO)
			      (jge TEMPLABEL)
			      (neg ARGTWO)
			      (sar (reg cl) ARGONE)
			      (jmp TEMPLABEL2)
			 (*LBL (label TEMPLABEL))
			      (shl (Reg cl) ARGONE)
			 (*LBL (label TEMPLABEL2)))
	   ((RegP regP)       (cmp 0 ARGTWO)
			      (jge TEMPLABEL)
			      (neg ARGTWO)
			      (xchg argtwo (reg rcx))
			      (sar (reg cl) ARGONE)
			      (jmp TEMPLABEL2)
			 (*LBL (label TEMPLABEL))
			      (xchg argtwo (reg rcx))
			      (shl (Reg cl) ARGONE)
			 (*LBL (label TEMPLABEL2))
			      (xchg argtwo (reg rcx)))
	   ((RegP AnyP)        (*MOVE ARGTWO (Reg T1))
			       (*ashift argone (reg t1)))
	   (                    (*MOVE ARGONE (Reg t2))
				(*ASHIFT (Reg t2) ARGTWO)
				(*MOVE (Reg t2) ARGONE))
)
 
 
(DefCMacro *WShift                     %Logical shift. +index=left.
	   ((AnyP  ZeroP)           )
	   ((RegP  OneP)      (*WPLUS2 ARGONE ARGONE))
	   ((RegP PosInumP)   (shl ARGTWO ARGONE))
	   ((RegP NegInumP)   (shr (minus ARGTWO) ARGONE))
	   ((Reg3p Reg3p)     (*cerror "So Geht das nicht"))
	   ((Reg3P regP)      (xchg ArgOne ArgTwo)
			      (*Wshift ArgTwo ArgOne)
			      (xchg ArgOne ArgTwo))
	   ((RegP reg3P)      (cmp 0 ARGTWO)
			      (jge TEMPLABEL)
			      (neg ARGTWO)
			      (shr (reg cl) ARGONE)
			      (jmp TEMPLABEL2)
			 (*LBL (label TEMPLABEL))
			      (shl (Reg cl) ARGONE)
			 (*LBL (label TEMPLABEL2)))
	   ((RegP regP)       (cmp 0 ARGTWO)
			      (jge TEMPLABEL)
			      (neg ARGTWO)
			      (xchg argtwo (reg 3))
			      (shr (reg cl) ARGONE)
			      (jmp TEMPLABEL2)
			 (*LBL (label TEMPLABEL))
			      (xchg argtwo (reg 3))
			      (shl (Reg cl) ARGONE)
			 (*LBL (label TEMPLABEL2))
			      (xchg argtwo (reg 3)))
	   ((RegP AnyP)       (*MOVE ARGTWO (Reg T1))
			      (*wshift argone (reg t1)))
	   (                  (*MOVE ARGONE (Reg t2))
			      (*WSHIFT (Reg t2) ARGTWO)
			      (*MOVE (Reg t2) ARGONE))
)
 
 
(de *WLshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WLshift))
 
(DefCMacro *WLShift                     %Logical shift to the left.
	   ((AnyP  ZeroP)           )
	   ((RegP  OneP)      (*WPLUS2 ARGONE ARGONE))
	   ((RegP InumP)      (shl ARGTWO ARGONE))
	   ((Reg3p Reg3p)     (*cerror "So Geht das nicht"))
	   ((Reg3P regP)      (xchg ArgOne ArgTwo)
			      (*Wlshift ArgTwo ArgOne)
			      (xchg ArgOne ArgTwo))
	   ((RegP reg3P)      (shl (Reg cl) ARGONE))
	   ((RegP regP)       (xchg argtwo (reg rcx))
			      (shl (Reg cl) ARGONE)
			      (xchg argtwo (reg rcx)))
	   ((RegP AnyP)       (*MOVE ARGTWO (Reg T1))
			      (*wlshift argone (reg t1)))
	   (                  (*MOVE ARGONE (Reg t2))
			      (*WlSHIFT (Reg t2) ARGTWO)
			      (*MOVE (Reg t2) ARGONE))
)
 
(de *WRshift (ARG1 arg2)
 (Expand2OperandCMacro ARG1 ARG2 '*WRshift))
 
(DefCMacro *WRShift                     %Logical shift to the right
	   ((AnyP  ZeroP)           )
	   ((RegP InumP)      (shr ARGTWO ARGONE))
	   ((Reg3p Reg3p)     (*cerror "So Geht das nicht"))
	   ((Reg3P regP)      (xchg ArgOne ArgTwo)
			      (*WRshift ArgTwo ArgOne)
			      (xchg ArgOne ArgTwo))
	   ((RegP reg3P)      (shr (reg cl) ARGONE))
	   ((RegP regP)       (xchg argtwo (reg rcx))
			      (shr (reg cl) ARGONE)
			      (xchg argtwo (reg rcx)))
	   ((RegP AnyP)       (*MOVE ARGTWO (Reg T1))
			      (*wrshift argone (reg t1)))
	   (                  (*MOVE ARGONE (Reg t2))
			      (*WRSHIFT (Reg t2) ARGTWO)
			      (*MOVE (Reg t2) ARGONE))
)

% *JumpIfTag is an optimized form of *jumpif.It knows that we are doing word
% compares only.
 
(de *JumpIfTag (arg1 arg2 label instructions)
 (prog (resultingcode*)
       (return
	(cmacropatternexpand
	 (list (resolveoperand '(reg t1) arg1)
	       (resolveoperand '(reg t2) arg2)
	       (resolveoperand '(reg error) label)
	       (car instructions)
	       (cdr instructions))
	 (get '*JumpIfTag 'cmacropatterntable)))))
 
 
 
%  We could probably make the assumption here that we are comparing
%       a D register (16 bits only) to a constant of the form  TAGxxxxxxxxxx.
 
(DefCMacro *JumpIfTag                  %( JumpIfTag a b lbl jmp rev-jmp)
%?((INumP INumP    )   should be caught by front end constant folding
  ((INumP AnyP     ) (*JumpIfTag ARGTWO ARGONE ARGTHREE (ARGFIVE . ARGFOUR)))
  ((AnyP  ZeroP    ) (cmp 0 ARGONE)          (ARGFOUR ARGTHREE))
  ((regP AnyP     )  (cmp ARGTWO ARGONE)   (ARGFOUR ARGTHREE))
  ((AnyP  regP    )  (cmp ARGONE ARGTWO)   (ARGFIVE ARGTHREE))
  ((AnyP  InumP    ) (cmp ARGTWO ARGONE)  (ARGFOUR ARGTHREE))
  (                  (mov ARGONE (reg t1))
		     (cmp ARGTWO (reg t1)) (ARGFOUR ARGTHREE)))
 
 
(De *JumpEQTag (Lbl Arg1 Arg2)
       (*JumpIfTag Arg1 Arg2 Lbl '(je  . je )))
(DefCmacro *JumpEqTag)
 
(De *JumpNotEQTag (Lbl Arg1 Arg2)
       (*JumpIfTag Arg1 Arg2 Lbl '(jne . jne)))
(DefCmacro *JumpNotEQTag)
 
(De *JumpWGEQTag (Lbl Arg1 Arg2)
       (*JumpIfTag Arg1 Arg2 Lbl '(jge . jle)))
(DefCmacro *JumpWGEQTag)
 
(De *JumpWGreaterPTag (Lbl Arg1 Arg2)
       (*JumpIfTag Arg1 Arg2 Lbl '(jg  . jl )))
(DefCmacro *JumpWGreaterPTag)
 
(De *JumpWLessPTag (Lbl Arg1 Arg2)
       (*JumpIfTag Arg1 Arg2 Lbl '(jl  . jg )))
(DefCmacro *JumpWLesspTag)
 
(DefCMacro *JumpType
     (                    (*MOVE ARGONE (Reg T1))
			  (shr 56 (Reg T1))
			  (*JumpEQTag ARGTHREE (reg t1) ARGTWO))
     )
 
 
(DefCMacro *JumpNotType
     (                    (*MOVE ARGONE (Reg T1))
			  (shr 56 (Reg T1)) 
			  (*JumpNotEQTag ARGTHREE (reg t1) ARGTWO))
     )
 
(DefCMacro *JumpInType
     (                    (*MOVE ARGONE (Reg T1))
			  (shr 56 (reg t1))
			  (*JumpWGeqTag argthree  ARGTWO (reg t1) )
			  (*JumpeqTag   argthree  (reg t1) 255))
     )
 
(DefCMacro *JumpNotInType
     (                    (*MOVE ARGONE (Reg T1))
			  (shr 56 (reg t1))
			  (*JumpWGeqTag TEMPLABEL ArgTwo (reg t1)) 
			  (*JumpnotEQTag  ARGTHREE (reg t1) 255) 
			  (*LBL (label TEMPLABEL))) 
     )
 
 
(DE *JUMPIF (ARG1 ARG2 LABEL INSTRUCTIONS)
 
  (PROG (RESULTINGCODE*)
    (RETURN
     (CMACROPATTERNEXPAND
      (LIST (RESOLVEOPERAND '(REG T1) ARG1)
	(RESOLVEOPERAND '(REG T2) ARG2)
       (RESOLVEOPERAND '(REG ERROR) LABEL)
	       (CAR INSTRUCTIONS)
	       (CDR INSTRUCTIONS))
	 (GET '*JUMPIF 'CMACROPATTERNTABLE)))))
 
(DefCMacro *JumpIf                  %( JumpIF a b lbl jmp rev-jmp)
    ((INumP INumP    ) (!*MOVE ARGONE (reg t1))
		       (cmp ARGTWO (reg t1)) (ARGFOUR ARGTHREE))
    ((INumP AnyP     ) (*JumpIf ARGTWO ARGONE ARGTHREE (ARGFIVE . ARGFOUR)))
    ((AnyP  ZeroP    ) (cmp 0 ARGONE)          (ARGFOUR ARGTHREE))
    ((AnyP  InumP)     (cmp ArgTWO ARGONE)  (ARGFOUR ARGTHREE))
    ((regP AnyP     )  (cmp ARGTWO ARGONE)   (ARGFOUR ARGTHREE))
    ((AnyP  regP    )  (cmp ARGONE ARGTWO)   (ARGFIVE ARGTHREE))
    ((AnyP  InumP    ) (cmp ARGTWO ARGONE)  (ARGFOUR ARGTHREE))
    (                  (*MOVE ARGONE (reg t1))
		       (cmp ARGTWO (reg t1)) (ARGFOUR ARGTHREE)))
 
(De *JumpEQ (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(je  . je )))
(DefCmacro *JumpEq)
 
(De *JumpNotEQ (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(jne . jne)))
(DefCmacro *JumpNotEQ)
 
(De *JumpWGEQ (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(jge . jle)))
(DefCmacro *JumpWGEQ)
 
(De *JumpWGreaterP (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(jg . jl)))
(DefCmacro *JumpWGreaterP)
 
(De *JumpWLEQ (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(jle . jge)))
(DefCmacro *JumpWLEQ)
 
(De *JumpWLessP (Lbl Arg1 Arg2)
       (*JumpIf Arg1 Arg2 Lbl '(jl . jg)))
(DefCmacro *JumpWLessp)
 
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% An item is formed on the 386 with the first five  bits as the Tag, %
%   ----------------------------%
%   | Tag |    Info field      |%
%   ----------------------------%
%  63     56                   0%
%                                                                        %
% To create a constant ITEM, the TagPart must first be shifted 56 bits %
% to place it in the upper 8, then the InfoPart has its upper 8 bits%
% masked off.  The two are then ORed together.%
% Not really correct as the inf could end up overlapping the tag%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(DefCMacro *MkItem
     ((regp fixp)   (shl 8 Argone)
		    (shr 8 Argone)
		    (*move Argtwo (reg t1))
		    (shl 56 (reg t1))
                    (*wor argone (Reg t1)))
     ((regp regp)   (shl 8 Argone)
		    (shr 8 Argone)
		    (shl 56 Argtwo)
		    (*wor Argone Argtwo))
     ((regp anyp)   (*move Argtwo (reg t1))		
		    (*MkItem Argone (reg t1)))
     (		    (*move argone (reg t1))
		    (*mkitem (reg t1) argtwo)
		    (*move (reg t1) argone)))
%%     (              (*PUTFIELD ARGTWO ARGONE 0 8))
%% )
 
 
% Note that the arguments to *PutField are source, destination, start, size.
% This is not what the CMACRO document indicates. MkItem above has been
% modified to reflect this ordering.  This is entirely backwards to the
% majority of the CMACRO's....
 
(DefCMacro *PutField
((regp regP eightp fiftysixp) (*wshift argone 8)
			      (*wshift argone -8)
                              (*wshift argTwo -56)
			      (*wshift argtwo 56)
                              (*wor  argtwo ARGone))
 ((regp regp Zerop eightp)    (*wshift argone 56)
                              (*wshift argTwo 8)
                              (*wshift argtwo -8)
                              (*wor  argtwo ARGone))
 ((inump regp Zerop eightp)   (*move  argone (reg t2))
                              (*wshift (reg t2) 56)
                              (*wshift argTwo 8)
                              (*wshift argtwo -8)
                              (*wor  argtwo (reg t2)))
 ((inump Anyp AnyP AnyP)	(*MOVE ARGtwo (reg t1))
            			(*PUTFIELD  ARGOne (reg t1) ARGTHREE ARGFOUR)
		                (*move (reg t1) argtwo))
 ((AnyP  regP AnyP AnyP) (*MOVE ARGONE (reg t1))
			 (*PUTFIELD    (Reg T1) ARGTWO ARGTHREE ARGFOUR))
(		(mov -1  (reg t5))
	        (*move   argone (reg t4))
	        (sll     (reg t5) (difference 32 argfour) (reg t5))
	        (*wshift (reg t5) (minus argthree)) % for 0 opt
       		(sll  (reg t4) (difference 32 (plus argthree argfour)) (reg t4))
	        (and   (reg t5) (reg t4) (reg t4))
	        (*move argtwo (reg t6))
	        (andn  (reg t6) (reg t5) (reg t6))
	        (or   (reg t4) (reg t6) (reg t5))
	        (*move (reg t5) argtwo)))

 %
(DefCMacro *SignedField
  ((regp anyp anyp anyp)(*MOVE   ARGTWO ARGONE)
			 (*ASHIFT ARGONE ARGTHREE)
			 (*ASHIFT ARGONE (DIFFERENCE ARGFOUR 64)))
  (                      (*SignedField (reg t1) ARGTWO ARGTHREE ARGFOUR)
			 (*Move        (reg t1) ARGONE))
)
 
% *Field and *SignedField could be improved by using ROL/ROR.
 
(DefCMacro *Field
  ((regp anyp zerop anyp) (*MOVE   ARGTWO ARGONE)
			  (*WSHIFT ARGONE (DIFFERENCE ARGFOUR 64)))
  ((regp anyp eightp fiftysixp)
			   (*move ARGTWO ARGONE)
			   (*wshift Argone 8)
			   (*wshift Argone -8))
  ((regp anyp anyp anyp) (*MOVE   ARGTWO ARGONE)
			 (*wshift argone ARGTHREE) 
			 (*wshift argone (difference argfour 64)))
  (                      (*Field (reg t1) ARGTWO ARGTHREE ARGFOUR)
			 (*Move  (reg t1) ARGONE))
)
 
% ----------
% Alloc
% Allocates stack space upon procedure entry.
% ----------
 
(de *ALLOC (framesize)
  (progn
    (setq NAlloc!* framesize)
    (setq framesize (times2 framesize 8)) %%% addressingunitsperitem))
    (cond
      ((ZeroP framesize)
	NIL)
      (T `(  % (*move (reg 1) (displacement (reg st) ,(minus (plus framesize 28)) ))
	     % (cmp 500(reg st))
	     % (jle (indirect(entry stackoverflow)))
	     (sub ,framesize (reg st)))))))

  % a special pass in compiler will do the job

	% Otherwise, we could allocate the space and then the code to clear
	% it out.  Instead, we just push the appropriate number of NILs.

% Declare *ALLOC to be a "cmacro".
% *ALLOC function handles its expansion.
 
(defcmacro *ALLOC)
 
% FastCallableP function dont need a link register to be set

(de FastCallableP(u)
   (setq u (getd u))
   (and u
	(setq u (cdr u))
	(codep u)
	(or
	   (and nonkernelupperbound*
		(wlessp (inf u) nonkernelupperbound*)
	   )
	   (wlessp (inf u)(inf (cdr (getd 'getd))))
	)
   ))

(DefCMacro *Call
   ((InternallyCallableP) (call (InternalEntry ARGONE)))
   ((FastCallableP)       (call (indirect (entry ARGONE))))
	   (              (*move (idloc argone) (reg t1))
			  (call (indirect (entry ARGONE)))))
 
(DefCMacro *DeAlloc
   ((ZeroP))
   (                    (add ARGONE (REG st))))
 
(DefCMacro *Exit
   ((ZeroP)             (ret))
   (                    (add ARGONE (REG st))
			(ret)))
 
(DefCMacro *JCall
   ((InternallyCallableP) (jmp (InternalEntry ARGONE)))
   ((FastCallableP)       (JMP (indirect (entry ARGONE))))
	   (              (*move (idloc argone) (reg t1))
			  (JMP (indirect (entry ARGONE)))))
 
 
(DefCMacro *Jump
   ((Atom)        (jmp ARGONE))% internal labels before compile
   ((TaggedLabel) (jmp ARGONE))% compiler generated labels
   ((ImmediateP)  (jmp  (unimmediate ARGONE)))
   (              (jmp ARGONE)))
 
 
(DefCMacro *Lbl
   (              ARGONE))
 
(de *Link (FunctionName FunctionType NumberOfArguments)
  (list
   (cond ((FlagP FunctionName 'ForeignFunction)
	  (list '*ForeignLink FunctionName FunctionType NumberOfArguments))
	 (t
	  (list '*Call FunctionName)))))
 
(DefCMacro *Link)
 
 
(de *LinkE (DeAllocCount FunctionName FunctionType NumberOfArguments)
 (cons (list '*DeAlloc DeAllocCount)
       (cond ((FlagP FunctionName 'ForeignFunction)
	      (list (list '*ForeignLink FunctionName
			   FunctionType NumberOfArguments)
		    '(*Exit 0)))
	     (t
	      (list (list '*JCall FunctionName))))))
 
(DefCMacro *LinkE)
 
(De *LamBind (Regs Fluids)
 
 % be careful, code is somewhat tricky
 
 (prog (n lng list cregs cfluids cadrcfluids lab initload freeregs hugo)
      (setq lab (gensym))
      (setq hugo (gensym))
      (setq n 0)
      (setq Regs (rest Regs))   % Remove "Registers" from the front
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Regs) 16)) % two words per BndStk entry *4
 
   %looking for free register to preload values of fluid s
 
      (setq freeregs (mapcan '((reg 1)(reg 2)(reg 3)(reg 4)(reg 5))
		       (function (lambda (x)
				    (cond ((member x regs) nil)
					   (t (cons x nil))
      )              ) )         )  )
      (setq cfluids fluids) % copy of fluids
      (when (null freeregs)
	     (setq freeregs cfluids)
	     (go nopreload))
 
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
nopreload
      (setq list `((*move ($fluid BndStkPtr) (Reg t1))
		   (*move (reg t1) (reg t2))
		   (*wplus2 (Reg t2) ,lng)
		   (cmp   (reg t2) ($fluid BndstkUpperBound))
	    %  (jge   ,hugo)
		%  (*call Bstackoverflow) %(jg    (entry Bstackoverflow))
		%,hugo
	   (jle (indirect(entry Bstackoverflow)))
		   (*move (Reg t2) ($fluid BndstkPtr))  )) %start of code
 
      (setq list (append initload list))
 
  loop
      (setq cregs (car Regs))
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	       (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 16))
      (Setq list (append list
	 `((*move ,(car freeregs)(reg t2))
	   (*move (reg t2) (displacement (Reg t1) ,n))
	   (*move (quote ,Cadrcfluids) (reg t2))
	   (*move (reg t2) (displacement (reg t1) ,(wplus2 n -8)))
	   (*move ,cregs (reg t2))
	   (*move (reg t2) ,cfluids)
      )          ))
      (setq fluids (cdr Fluids))
      (setq freeregs (cdr freeregs))
      (cond ((setq regs (cdr Regs)) (go loop)))
      (return list)
)    )

(defcmacro !*lambind)

(De *ProgBind (Fluids)
 
 % be careful, code is somewhat tricky
 
 (prog (n lng list cfluids cadrcfluids lab initload freeregs kuno)
      (setq kuno (gensym))
      (setq lab (gensym))
      (setq n 0)
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Fluids) 16)) % two words per BndStk entry
					     % * 4 addressingunits
      (setq freeregs '((reg 1)(reg 2)(reg 3)(reg 4)(reg 5)))
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
		   (*move (reg t1) (reg t2))
		   (*wplus2 (Reg t2) ,lng)
		   (cmp   (reg t2) ($fluid BndstkUpperBound))
	   %   (jge  ,kuno)
	   %   (*call Bstackoverflow) %(jg    (entry Bstackoverflow))
	   %  ,kuno
	   (jle (indirect(entry Bstackoverflow)))
		   (*move (Reg t2) ($fluid BndstkPtr))  )) %start of code

     (setq list (append initload list))
 
 loop
      (setq cfluids (car Fluids))
      (setq cadrcfluids (cadr cfluids))
      (when (or (eq cadrcfluids 't) (eq cadrcfluids 'nil))
	       (stderror "T and NIL cannot be rebound"))
      (setq n (wplus2 n 16))
      (Setq list (append list
		 `((*move ,(car freeregs)(reg t2))
		   (*move (reg t2) (displacement (Reg t1) ,n))
		   (*move (quote ,Cadrcfluids) (reg t2)) 
		   (*move (reg t2) (displacement (reg t1) ,(wplus2 n -8)))
		   (*move (quote nil) (reg t2))
		   (*move (reg t2) ,cfluids)
      )          ))
      (setq freeregs (cdr freeregs))
      (cond ((setq Fluids (cdr Fluids)) (go loop)))
      (return list)
)    )
(defcmacro *progbind)
 
(De *FreeRstr (Fluids)
 
 (prog (n lng list cfluids listfluids lab initload freeregs otto)
      (setq otto (gensym))
      (setq lab (gensym))
      (setq n 0)
      (setq Fluids (rest fluids)) % Remove NONLOCALVARS
      (setq lng (wtimes2 (length Fluids) 2)) % two words per BndStk entry
      (setq freeregs '((reg 2)(reg 3)(reg 4)(reg 5)))
      (setq cfluids fluids) % copy of fluids
      (setq n (wtimes2 8 (wdifference 2 lng)))
      (setq lng (wtimes2 lng 8)) % * addressingunitperitem
      (setq initload (list '(*move ($fluid Bndstkptr) (reg t1))))
 
preload  (setq initload
	   (progn (setq listfluids
		   (if freeregs
		    (nconc listfluids (cons (car freeregs) nil))
		    (nconc listfluids (cons nil nil))) )
	    (nconc initload
	     (if freeregs
	 `((*move (displacement (reg t1) ,n) ,(car freeregs))) nil)
       )   ))
       (setq n (wplus2 n 16))
       (when freeregs (setq freeregs (cdr freeregs)))
       (setq cfluids (cdr cfluids))
 
       (cond (cfluids (go preload)))
 
       (setq freeregs listfluids ) %end of preloadcode
 
       % freeregs contains the list of preloaded regs
       % and nil if not enough regs available
 
      (setq list `((*move (reg t1) (reg t2))
		   (sub   ,lng (reg t2))
		   (cmp   (reg t2) ($fluid BndstkLowerBound))
	    %  (jle   ,otto)
		%  (*call Bstackunderflow) %(jl    (entry Bstackunderflow))
		% ,otto
	   (jg    (indirect (entry Bstackunderflow)))
		   (*move (Reg t2) ($fluid BndstkPtr))  )) %start of code
 
     (setq list (append initload list))
     (setq n 0)
 
 loop
      (setq cfluids (car Fluids))
      (setq n (wplus2 n 16))
 
  % insert reloaded register or memory reference
 
      (setq list (append list
	       (if (car freeregs) `((*move ,(car freeregs) ,cfluids ))
		    `((*move (displacement (Reg t2) ,n) ,cfluids )))

      )          )
      (setq freeregs (cdr freeregs))
      (cond ((setq Fluids (cdr Fluids)) (go loop)))
      (return list)
)    )
(defcmacro *freerstr)
 
(setq *unsafebinder t)   % has to save Registers across calls
 
(de !*jumpon (register lowerbound upperbound labellist)
      (for (from x lowerbound upperbound)
		(join
		  `((cmp ,x ,register)
		    (je ,(pop labellist))))))

(commentoutcode de !*jumpon (register lowerbound upperbound labellist)
     (PROG (X LL LL2)
       (setq ll  (gensym)) 
       (setq ll2 (gensym)) 
       (SETQ X
	(if (and (weq lowerbound 0) (weq upperbound 255) *syslisp) 
		  % jumpon on tags (most probably) 
      `(                            % 8 bytes per jumptable entry
	(jmp (indirect (indexed (times ,register 8) (label ,ll2))))
       ,ll2) 
      `((cmp ,upperbound ,register)
	(jg  (label ,ll))
	(cmp ,Lowerbound ,register)
	(jl (label ,ll))
	(*wdifference ,register ,lowerbound )
	(jmp (indirect (indexed (times ,register 8) (label ,ll2))))
       ,ll2) ) )
      Loop  (Setq x (nconc X `((FULLWORD ,(car Labellist)))) )
	    (setq Labellist (cdr Labellist)) 
	    (cond (Labellist (go loop))) 
  
	    (setq x (nconc x `((*lbl (Label ,ll))) )) 
	    (return x) 
)  )

(defcmacro !*jumpon)

(defcmacro *fast-apply-load
   (       (*move argone (reg t2)))
   )
 
(put 'fast-idapply
     'opencode
     '((*move (reg t2) (reg t1))        % save  idnumber
       (*wand (reg t2)(wconst 16#7ffffff)) % remove what's left of the tag
       (*wshift (reg t2) (wconst 3))    % 
       (*wplus2 (reg t2) ($fluid SYMFNC)) % 
       (call (indirect (reg t2)))          % jump indirect.
       ))
 
(put 'fast-idapply
     'exitopencode
     '((*move (reg t2) (reg t1))        % save  idnumber
       (*wand (reg t2)(wconst 16#7ffffff)) % remove what's left of the tag 
       (*wshift (reg t2) (wconst 3))    % double ID number (ignore tag for now)
       (*wplus2 (reg t2) ($fluid SYMFNC)) % add base address to 6 times ID.
       (jmp (indirect (reg t2)))          % jump indirect.
       ))
 
 
% Need to do tag stripping before doing the jsr. /LBS
%
(put 'fast-codeapply
     'opencode
     '((*field (reg t2) (reg t2) (wconst infstartingbit)
	   (wconst infbitlength))
       (*move ($fluid onewordbuffer)(reg t1))
       (*move (reg t2)(indirect (reg t1)))
       (call (indirect (reg t1))))
     )
 
(put 'fast-codeapply
     'exitopencode
     '((*field (reg t2) (reg t2) (wconst infstartingbit)
	   (wconst infbitlength))
       (jmp (reg t2)))
 
     )
 
(DE  !*ForeignLink (FunctionName  FunctionType NumberOfArguments)
   %%%  (codedeclareexternal FunctionName)
     (append (PNTH '((!*PUSH (REG 14)) (!*PUSH (REG 13))
	     (!*PUSH (REG 12)) (!*PUSH (REG 11))
	     (!*PUSH (REG 10)) (!*PUSH (REG  9))
	     (!*PUSH (REG  8)) (!*PUSH (REG  7))
	     (!*PUSH (REG  6)) (!*PUSH (REG  5))
	     (!*PUSH (REG  4)) (!*PUSH (REG  3))
	     (!*PUSH (REG  2)) (!*PUSH (REG  1)))
	   (difference 15  NumberOfArguments))
     (append (PNTH '(
		(!*move (displacement (reg st)104) (reg error))
		(!*move (displacement (reg st) 96) (reg error))
		(!*move (displacement (reg st) 88) (reg error))
		(!*move (displacement (reg st) 80) (reg error))
		(!*move (displacement (reg st) 72) (reg error))
		(!*move (displacement (reg st) 64) (reg error))
		(!*move (displacement (reg st) 56) (reg error))
		(!*move (displacement (reg st) 48) (reg error))
		(!*move (displacement (reg st) 40) (reg error))
		(!*move (displacement (reg st) 32) (reg error))
		(!*move (displacement (reg st) 24) (reg r9))
		(!*move (displacement (reg st) 16) (reg r8))
		(!*move (displacement (reg st) 8)  (reg rdx))
		(!*move (displacement (reg st) 0)  (reg rcx)))
	   (difference 15  NumberOfArguments))
	  (append
	   (list (list '!*move '(fluid ebxsave!*) '(reg 5))
% stack has to be aligned to 16bytes (128bit) for SSE instructions
                 '(!*move (reg st) (reg 1))
                 '(sub 64 (reg st))
                 '(!*wshift (reg st) -5)
                 '(!*wshift (reg st) 5)
                 '(!*move (reg 1) (displacement (reg st) 40))
		 (list 'call (list 'ForeignEntry FunctionName))
                 '(!*move (displacement (reg st) 40) (reg st))
		 (list '!*move '(reg 5) '(fluid ebxsave!*))
	   )
	   (cond
	((eq NumberOfArguments 0) nil)
	((lessp NumberOfArguments 3)
	 (list (list 'add (times 8 NumberOfArguments) '(reg st))))
	(t
	 (list (list 'add (times 8 NumberOfArguments) '(reg st))))
	))
	   )))
 
(DefCMacro *ForeignLink)
 
% the floating point part

% *feq, *fgreaterp and *flessp can only occur once in a function.

(deflist '((*fclex (fclex))
	   (*wfix ((fld (indirect (reg 1)))
		   (fistp (displacement (reg st)  -4))
		   (wait)
		   (mov  (displacement  (reg st) -4) (reg 1))))
	   (*wfloat ((mov (reg 2) (displacement (reg st) -4))
		     (fild (displacement (reg st) -4))
		     (fstp (indirect (reg 1)))
		     (wait)))
	   (*fgreaterp ((fld (indirect (reg 2)))
			(fcomp (indirect (reg 1)))
			(fstsw  (reg ax))
			(sahf)
			(*move (quote t) (reg 1))
			(jb *donefgreaterp*)
			(mov (quote nil) (reg 1))
			*donefgreaterp*))
	   (*flessp ((fld (indirect (reg 1)))
		     (fcomp (indirect (reg 2)))
		     (fstsw  (reg ax))
		     (sahf)
		     (*move (quote t) (reg 1))
		     (jb *doneflessp*)
		     (mov (quote nil) (reg 1))
		     *doneflessp*))
	   (*fplus2 ((fld  (indirect (reg 2)))
		     (fadd (displacement (reg 3) 0))
		     (fstp (indirect (reg 1)))
		     (wait)))
	   (*fdifference ((fld  (indirect (reg 2))) 
			  (fsub (displacement (reg 3) 0))
			  (fstp (indirect (reg 1)))
			  (wait))) 
	   (*ftimes2 ((fld  (indirect (reg 2))) 
		      (fmul (indirect (reg 3)))
		      (fstp (indirect (reg 1)))
		      (wait))) 
	   (*fquotient ((fld  (indirect (reg 2))) 
		     (fdiv (displacement (reg 3) 0))
		     (fstp (indirect (reg 1)))
		     (wait)))) 
	 'opencode)

(de &stopt (u)
  % OPTFN: Convert MOVEs + ALLOCS into PUSHES
  % U: inverse sequence of cmacros.
  % 486: instruction for stack protection should be first one.
  (cond ((atom (cdr u)) NIL)
	((and (equal (caadr u) '*alloc) (equal llngth& 1)
	      (equal (cddar u) '((frame 1))))
	 (rplacw u (append `((*push ,(cadar u))
%WN
			% (*move (reg 1) (displacement (reg st) -32))
			% (jle (indirect(entry stackoverflow)))
			% (cmp 500(reg st))
			)
			    (cddr u))))
	((and (equal (caadr u) '*move) (equal (caaddr u) '*alloc)
	      (equal llngth& 2) (equal (cddar u) '((frame 2)))
	      (equal (cddadr u) '((frame 1))))
	 (rplacw u
		 (cons (list '*push (cadadr u))
		     (cons (list '*push (cadar u)) 
		       (append  '((*move (reg 1) (reg 1))) %(*move (reg 1) (displacement (reg st) -32)))
%WN
			% '((jle (indirect(entry stackoverflow)))
			%   (cmp 500(reg st)))
		     (cdddr u)))))
)))


%------------------------- access to SS segment with DS instructions ----

(deflist
  '((*get-stack ((halfword 16#3636)   % SS segment override prefix
		 (*move (indexed (reg 1) 0) (reg 1))))
    (*put-stack ((halfword 16#3636)
		 (*move (reg 2) (indexed (reg 1) 0)))))
  'opencode)

% End of file.
