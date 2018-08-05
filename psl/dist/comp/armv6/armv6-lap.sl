<%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:armv6-LAP.SL
% Description:  Armv6 PSL Assembler
% Author:       H. Melenk
% Created:      1-August 1989
% Modified:
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions
% 28-Apr-92 (herbert Melenk)
% no relocation for quoted small ID's
%
% 3-Apr-90 (Winfried Neun)
% added support for new car and cdr scheme in modr/m
 

% ------------------------------------------------------------
% Fluid declarations:
% ------------------------------------------------------------

(fluid '(LabelOffsets*                  % just the label entries from
					% BranchAndLabelAList!*
					% Has the form ( (Label.Offset) ... )
	BranchCodeList*                 % Used in Branch optimization
	BranchAndLabelAList*            % Used in Branch optimization
	CurrentOffset*                  % the global value of the current
					% byte displacement from the starting
					% point of the code
	CodeSize*                       % Current number of bytes generated
	CodeBase*                       % Starting address of the module
	Entries*                        % list of procedure entries of the
					% form
					% ((ProcedureName
					%   ProcedureType
					%   NumberOfArguments) .
					%   CurrentOffset!* )
	InstructionChanged*             % Boolean - indicates if any
					% instructions have changed due to
					% branch optimization
	InstructionSize*                % Contains the size constant Byte
					% Word or Long during length compute
					% and assembly of individual instr.
	ForwardInternalReferences*      % a-list of offsets of references to
					% internal functions, to be patched
					% by SystemFaslFixup
	LapReturnValue*                 % set by SaveEntry to the pointer
					% to be returned by LAP
	OperandRegisterNumber*          % see EffectiveAddress
	*WritingFaslFile                % FLAG: if true, then we are writing
					% the resulting code to a file,
					% otherwise we are depositing it into
					% memory directly
	InitOffset*                     % The offset from the module to the
					% Initialiization code which is to be
					% run when the module is loaded
	*PGWD                           % FLAG: if true, then mnemonics and
					% assembled instructions are printed
	*PWrds                          % FLAG: if true, then base address
					% and size of each compiled
					% procedure are printed as they are
					% deposited into memory
	*align16                        % align lables to 16 byte
					% boundaries        
	*lapopt
	*trlapopt
	*big-endian*    		% True if big-endian version
	shift-ops*			% known shift operations
	*cond*
	*set*
	*OpNameList*
	!*LDM-adressing-modes
	!*condition-codes*

))

(setq *lapopt t)

(fluid '(*immediatequote))
(setq *immediatequote nil)
(fluid '(*testlap))                     % diagnostic output from LAP  MK

(ds LabelP (X) (atom X))

(setq *PWrds t)                         % By default show where the code is
					% put in memory

(setq shift-ops* '(LSL LSR ASR ROR RRX))

% ------------------------------------------------------------
% Constant declarations:
% ------------------------------------------------------------

(DefConst  
	 RELOC_ID_NUMBER 1 
	 RELOC_HALFWORD 2 
	 RELOC_WORD 1 
	 RELOC_INF 3)

(DefConst MaximumShortBranch 127)

% ------------------------------------------------------------
% Start of actual code
% ------------------------------------------------------------

(de Lap (U) 
(prog (LabelOffsets* LapReturnValue* Entries* temp) 
    (cond ((not *WritingFaslFile) (setq CurrentOffset* 0))) 
    (setq U (&fillframeholes u))
    
%%%    (setq u (lapopt1 u))                % optimize macros

    (setq U (Pass1Lap U))               % Pass1lap
					% expand all the LAP macros
					% Note that this is defined in
					% PC:PASS-1-LAP.SL

    (setq U (LapoptFrame u))            % optimize frame-register transports
    (setq U (LapoptPeep u))             % peephole optimizer for 486 code

    (when *WritingFaslFile       % round off to fullword address
	  (while (not (eq (wshift (wshift currentOffset* -2) 2) currentOffset*))
		 (depositbyte 0) ))
 
    (SETQ U (ReformBranches U))         % process conditional branches
    (setq U (OptimizeBranches U))       % optimize branches and
					% calculate offsets and total length
    
    (when (not *WritingFaslFile)       
	  (setq CodeBase* (GTBPS (Quotient (Plus2 CodeSize* 3) 4))))


% Print the machine specific assembly code
% if the object is an atom then it is a LABEL
% otherwise it is an instruction

    (cond (*PGWD (foreach X in U do 
	(cond ((LabelP X) (Prin2 X)) (t (PrintF "          %p%n" X)))))) 

    (foreach Instruction_or_Label in U do 
	(cond
	    ((LabelP Instruction_or_Label) (DepositLabel Instruction_or_Label))
	    ((equal (first Instruction_or_Label) '*entry) 
		      (SaveEntry Instruction_or_Label)) 
	    (t (DepositInstruction Instruction_or_Label) )))

    (DefineEntries)                     % define entries to whom?

% If you are depositing it into memory the tell the user how much space the
% code took and where it was loaded.
% ??? Why is this using the error channel ???

    (cond ((and (not *WritingFaslFile) *PWrds) 
	(ErrorPrintF "*** %p: base 16#%x, length 10#%d bytes" 
		(foreach X in Entries* collect (first (car X))) 
				CodeBase* CodeSize*))) 

    (return (and LapReturnValue*	  % return nil if LapReturnValue* is not set
	     (MkCODE LapReturnValue*))))) % How does this point at the code?
					  % It is a fluid variable that got
					  % set up when the code was generated.


% CheckForInitCode will scan the Codelist for the first !*Entry
% testing for !*!*FASL!*!*Initcode!*!*.

(de CheckForInitCode (CodeList) 
     (foreach Instruction in CodeList do 
       (progn (cond ((PairP Instruction) 
	   (cond ((equal (car Instruction) '*entry) 
	     (cond ((equal (second Instruction) '**Fasl**InitCode**) 
		(return t))))))))))

% SaveEntry( '(!*entry ProcedureName ProcedureType NumberOfArguments) )
% Purpose: To associate with a procedure its location (so other routines can
%          access it

(de saveentry (x)
  (cond  
   % if X = ( _____ !*!*!*Code!*!*Pointer!*!*!* ... )
   ((equal (second x) '***code**pointer***) 
    (setq lapreturnvalue* 
      (if *writingfaslfile CurrentOffset* (wplus2 codebase* CurrentOffset*))))

   % If depositing into memory
   ((not *writingfaslfile) 
    (setq entries* (cons (cons (rest x) CurrentOffset*) entries*)) 
    (unless lapreturnvalue* (setq lapreturnvalue*
		 (wplus2 codebase* CurrentOffset*))))

   % if X = ( _____ !*!*Fasl!*!*InitCode!*!* ... )
   ((equal (second x) '**fasl**initcode**) 
    (setq initoffset* CurrentOffset*))

   % if X is an InternalFunction
   ((flagp (second x) 'internalfunction) 
    (put (second x) 'internalentryoffset CurrentOffset*))

   (t (progn
       (put (second x) 'internalentryoffset CurrentOffset*) % MK
       (findidnumber (second x))
       (dfprintfasl (list 'putentry (mkquote (second x)) 
			  (mkquote (third x)) CurrentOffset*))))))
     

% DefineEntries()
% Purpose: Defines each of the procedures named in the list Entries!*
%          by putting the code pointer into the function cells

(de DefineEntries nil 
    (foreach X in Entries* do 
	(PutD (first (car X)) (second (car X))
		 (MkCODE (wplus2 CodeBase* (cdr X))))))

(de DepositInstruction (X)
% This actually dispatches to the procedures to assemble the instrucitons
(prog (Y)
    (cond ((setq Y (get (first X) 'InstructionDepositFunction))
	   (Apply Y (list X)))
	  ((setq Y (get (first X) 'InstructionDepositMacro))
	   (apply3safe y (cdr x))) 
	  (t (StdError (BldMsg "Unknown ARMv6 instruction %p" X))))))


(de DepositLabel (x) nil)

(de string-begins-with (s opname)
    (if (lessp (size s) (size opname))
	nil
      (equal (subseq s 0 (add1 (size opname))) opname)))

(de lookup-mnemonic (s)
    %% find opcode in *OpNameList* by comparing the first characters of x
    (prog (x)
	  (setq s (string s))
	  (setq x *OpNameList*)
	  lbl
	  (if (string-begins-with s (car x))
	      (return (car x)))
	  (setq x (cdr x))
	  (go lbl)))


(de get-instruction-deposit-function (mnemonic)
%%
%% first tries with mnemonic,
%%  then with trailing S stripped, then with condition codes stripped
%%
    (setq mnemonic (string mnemonic))
    (prog (generic-opname rest set!? conds fn variants z len size size1 substr )
	  (setq generic-opname (lookup-mnemonic mnemonic))
	  (setq rest (subseq mnemonic (add1 (size generic-opname)) (add1 (size mnemonic))))
	  (setq generic-opname (intern generic-opname))
	  (setq fn (get generic-opname 'InstructionDepositMacro))
	  (setq variants (get generic-opname 'OpCodeVariants))
	  (setq len (add1 (size rest)))
	  (foreach x in
		   (list (list '*set* '(s) 0)
			 (list '*ldm-addr* !*LDM-adressing-modes 'IA)
			 (list '*cond* !*condition-codes!* 'AL))
		   do
		   (if (memq (car x) variants)
		       (progn
			 (setq size1 (add1 (size (car (cddr x)))))
			 (setq substr (subseq rest (difference size size1) size))
			 (if (memq (intern substr) (cadr x)) % found
			     (push (cons (car x) (intern substr)) z)
			   (push (cons (car x) (caddr x)) z))
			 ))
		   )

	  (if fn (return (list fn (cons generic-opname z))))

	  )
    )

(fluid '(*testlap))
(de DepositInstruction (X) 
% This actually dispatches to the procedures to assemble the instrucitons
% version with address calculation test
(prog (Y l offs) 
      (when *testlap (prin2 CurrentOffset*) (tab 10) (print x))
      (when *writingfaslfile (setq offs CurrentOffset*))
      (cond ((setq Y (get (first X) 'InstructionDepositFunction)) 
	     (Apply Y (list X)))
	    ((setq Y (get (first X) 'InstructionDepositMacro))
	     (apply3safe y (cdr x)))
	    (t (StdError (BldMsg "Unknown ARMv6 instruction %p" X))))
      (when (and offs (not (equal CurrentOffset* (plus offs (instructionlength x)))))
	(StdError (BldMsg "length error with instruction %p: %p"
			  x (difference (difference CurrentOffset* offs)
					(instructionlength x)))))
      ))

(de DepositLabel (x) 
    (when *testlap (prin2 CurrentOffset*) (tab 10) (print x))
    (when (and *writingfaslfile 
	       (not (equal CurrentOffset* (LabelOffset x)))) 
	  (StdError (BldMsg "wrong address for label %p: difference = %p" 
		       x    (difference CurrentOffset* (LabelOffset x)))))) 
	   

%
% Conditions bits 31:28 in ARMv6 opcodes
%

(deflist '((EQ 2#0000) (NE 2#0001) (CS 2#0010) (HS 2#0010) (CC 2#0011) (LO 2#0011)
	   (MI 2#0100) (PL 2#0101) (VS 2#0110) (VC 2#0111)
	   (HI 2#1000) (LS 2#1001) (GE 2#1010) (LT 2#1011)
	   (GT 2#1100) (LE 2#1101) (AL 2#1110))
  'condition-bits)

(setq !*condition-codes!* '(EQ NE CS HS CC LO MI PL VS VC HI LS GE LT GT LE AL))

(deflist '((IA 2#01) (IB 2#11) (DA 2#00) (DB 2#10))
  'ldm-addressing-modes)

(setq !*LDM-adressing-modes '(IA IB DA DB))


(CompileTime (progn 

(dm DefOpcode (U) 
%
% (DefOpcode name (parameters) pattern)
%
(prog (OpName variants vars pattern fname condbits set!? opname-string) 
    (setq U (rest U)) 
    (setq OpName (pop U))
    (setq opname-string (string OpName))
    (setq fname (intern (bldmsg "%w.INSTR" OpName)))
    (setq OpName (MkQuote OpName))
%    (setq variants (pop u))
    (setq vars (pop u))
    (setq pattern
      (append u
	`((t (laperr ',OpName  (list .,vars))))))
    (setq pattern (cons 'cond pattern))
    %% (setq pattern
    %% 	  `((lambda (*condbits* *set* *ldm-addr*) ,pattern)
    %% 	    (get (or ,(car variants) 'AL) 'condition-bits)
    %% 	    ,(if (cdr variants)
    %% 		 `(if ,(cadr variants) 1 0)
    %% 	       )
    %% 	    ,(if (and (cdr variants) (cddr variants))
    %% 		 `(get (or ,(caddr variants) 'IA) 'ldm-addressing-modes))
    %% 	    ))
    % (setq u `(lambda ,vars ,pattern)) 
    % (return `(put ,OpName 'InstructionDepositMacro ',u))
    (push opname-string *OpNameList*)
    (return
      `(progn
	 (de ,fname ,vars ,pattern)
%	 (put ,OpName 'variants ',variants)
	 (put ,OpName 'InstructionDepositMacro ',fname)))
    ))



(dm DefOpLength (U)
%
% (DefOpLength name (parameters) pattern)
%
(prog (OpName variants vars pattern fname)
    (setq U (rest U))
    (setq OpName (pop U))   % (quote name)
    (setq fname (intern (bldmsg "%w.LTH" OpName)))
    (setq OpName (MkQuote OpName))   % (quote name)
%    (setq variants (pop u)) 
    (setq vars (pop u)) 
    (setq pattern
      (append u 
	`((t (laperr ',OpName  (list .,vars))))))  
    (setq pattern (cons 'cond pattern)) 
    % (setq u `(lambda ,vars ,pattern))
    % (return `(put ,OpName 'InstructionLengthFunction ',u))
    (return 
      `(progn
	 (de ,fname ,vars ,pattern) 
	 (put ,OpName 'InstructionLengthFunction ',fname))) 
)) 
 
 
 
))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%
%    getting the instructions in 
  
( dskin "armv6-inst.dat")

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  additional test functions

(fluid '(sregs))
(setq sregs '(ES CS SS DS FS GS ))

(de RegP (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '( 1  2  3  4  5
		     R0 R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 sp st pc lr
		     t1 t2 t3 fp
             nil heaplast heaptrapbound symfnc symval
%%	     bndstkptr bndstklowerbound bndstkupperbound
	     ))))

(de EvenRegP (RegName)
    (and (Regp RegName) (evenp (reg2int regname))))
	 
(de reglistp (x)
    (and (pairp x) (eqcar (car x) 'reg) (pairp (cdr x)) (reglistp1 (cdr x))))

(de reglistp1 (x)
    (or (null x)
	(and (pairp x) (regp (car x))
	     (reglistp1 (cdr x)))))


(de memoryp(x) 
  % supports reference to explicit addresses
   (if (atom x) nil
       (progn
	 (setq x (car x))
	 (or
	   (eq x 'label) 
	   (eq x '$FLUID)
	   (eq x '$GLOBAL)
   )))) 
 
(de effap(x)
  % supports most general memory and register references
   (or (stringp x) (idp x) (regp x)
      (and (pairp x)
       (memq (car x)
	     '(indirect displacement indexed $fluid $global 
	       fluid global extrareg) ))))

(de stdimmediatep(x)
  % full size immediate
  (or (numberp x)(eqcar x 'immediate)(eqcar x 'idloc)))

(de shortlabelp (x)(or (labelp x) (eqcar x 'IMMEDIATE)))

(de adrp (x) (or (atom x)
		 (memq (car x)'(label entry internalentry foreignentry))
		 (and (eqcar x 'IMMEDIATE) (adrp (cadr x)))))
  
(de indirectadrp (x) (and (eqcar x 'INDIRECT) 
			  (or (adrp (cadr x)) (effap (cadr x))(regp (cadr x)))))

(de smallimmediatep (x)
     (when (eqcar x 'IMMEDIATE) (setq x (unimmediate x)))
     (bytep x)) 

(de imm8-rotatedp (x)
    (setq x (wand 16#ffffffff x))
    (and (fixp x) (decode-32bit-imm8-rotated x)))

% possibly shifted register (data movement), one of:
% (reg x)
% (regshifted x LSL/LSR.. amount)    amount is a number or a register
% (regshift-by-reg x LSL/LSR (reg y))

(de reg-shifter-p (x)
    (or (and (pairp x) (regp x))
	(and (eqcar x 'regshifted) (or (regp (cadr x)) (regp (list 'reg (cadr x))))
	     (memq (caddr x) shift-ops*)
	     (or (fixp (cadddr x)) (regp (cadddr x))
		 (and (null (cadddr x)) (eq (caddr x) 'RRX))))
	)
    )

(de reg-offset8-p (x)
    (cond ((stringp x) t)
	  ((atom x) nil)
	  ((eq (car x) 'indirect) (regp (cadr x)))
	  ((and (memq (car x) '(displacement indirect)) (regp (cadr x)))
	   (eight-bit-p (caddr x)))
	  (t nil)))

(de reg-offset12-p (x)
    (cond ((stringp x) t)
	  ((atom x) nil)
	  ((eq (car x) 'indirect) (regp (cadr x)))
	  ((and (memq (car x) '(displacement indirect)) (regp (cadr x)))
	   (twelve-bit-p (caddr x)))

%	  (or
%	    (twelve-bit-p (caddr x))
%	    (reg-shifter-p (cadr x))
%	    (and (pairp (cadr x)) (memq (caadr x) '(plus minus)) (reg-shifter-p (cadr (cadr x))))))
	  (t nil))
    )
	      
(de twelve-bit-p (x)
    (and (fixp x) (lessp x 4096) (greaterp x -4096)))

(de eight-bit-p (x)
    (and (fixp x) (lessp x 256) (greaterp x -256)))

(de pm-reg-shifter-p (x)
    (and (eqcar x 'displacement)
	 (regp (cadr x))
	 (and (pairp (caddr x)) (memq (car (caddr x)) '(reg regshifted plus minus))))

    )

(de streg-p (x)
    (eq x 'cpsr))

(de writeback-p (x)
    t)

(de offset26-p (x)
    (or (labelp x)
	(and (eqcar x 'immediate) (setq x (cadr x))
	     (fixp x)
	     (lessp x (add1 16#1FFFFFC))
	     (greaterp x (sub1 -33554432))
	 )
	)
    )


    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%  Instruction deposit functions
 

(de laperr(inst par)
   (StdError (BldMsg "Illegal format: (%p %p)" inst par)))


(de depositextension(op2)
   % generate a relocated fullword extension
    (prog (OfFn)
      (when (atom op2) (return (depositwordexpression op2)))
    (when (setq OfFn (get (car op2) 'OperandDepositFunction))
	  (return (apply OfFn (list op2))))
    (depositwordexpression op2)))
    

% Procedures to compute specific OperandRegisterNumber!*
% Each of the cases returns the Addrssing MODE
% and sets OperandRegisterNumber!* as a side effect

(fluid '(numericRegisterNames))

(setq numericRegisterNames [nil R0 R1 R2 R3 R4])

(de reg2int (u)
   % calculate binary number for register
  (prog (r) (setq r u)
      % strip off tag 'reg
   (cond ((eqcar r 'reg)(setq r (cadr r))))
      %convert a LISP-register into a ARMv6 register
   (if (numberp r) (setq r (getv numericRegisterNames r)))
   (setq r (get r 'registercode))
   (if r (return r)
	 (stderror (bldmsg "unknown register %w" u)))))

(loadtime
(deflist '((R0   0) (R1   1) (R2   2) (R3   3) 
	   (R4   4) (R5   5) (R6   6) (R7   7)
	   (R8   8) (R9   9) (R10 10) (R11 11)
	   (R12 12) (R13 13) (R14 14) (R15 15)
	   (T1   5) (T2   6) (T3   7)
	   (fp  11)			% frame pointer for C subroutine calls
	   (sp  13) (st  13)		% LISP stack register
	   (lr  14)			% link register
	   (pc  15)			% program counter
	   (heaplast 8)
	   (heapupperbound 9)
	   (symfnc 10)
	   (symval 11)
	   (nil 12)
	 ) 'registercode)
)
(de bytep(n)
    (when (and (numberp n) (lessp n 128) (greaterp n -128))
	  (land n 255)))
 
(de halfwordp(n)
    (when (and (numberp n) (lessp n 32768) (greaterp n -32768))
	  (land n 65535)))

(de unimmediate(u)
    (if (eqcar u 'immediate) (cadr u) u))

%------------------------------------------------------------------------
% code is one byte, op1 is a register, op2 is an effective address
(de OP-reg-effa (code op1 op2)
    (reg-5-prefix op2)
    (depositbyte (car code))
    (modR/M op1 op2))

(de LTH-reg-effa (code op1 op2) 
   (plus 1 (lth-reg-5-prefix op2) (lthmodR/M op1 op2)))
 
%------------------------------------------------------------------------
% op1 is an immediate, op2 is an effective address which patches into
% the second byte of the code
(de OP-imm-effa (code op1 op2)
    (reg-5-prefix op2)
    (depositbyte (car code))
    (modR/M (cadr code) op2)
    (depositextension (unimmediate op1)))

(de lth-imm-effa (code op1 op2)
   (plus 5 (lth-reg-5-prefix op2) (lthmodR/M (cadr code) op2)))

(de OP-imm8-effa (code op1 op2)
    (reg-5-prefix op2)
    (depositbyte (car code))
    (modR/M (cadr code) op2)
    (depositbyte (unimmediate op1)))
(de lth-imm8-effa (code op1 op2)
   (plus 2 (lth-reg-5-prefix op2) (lthmodR/M (cadr code) op2)))

%------------------------------------------------------------------------
% code is two bytes, op1 is a register, op2 is an effective address
(de OP-reg-effa-2 (code op1 op2)
    (reg-5-prefix op2)
    (depositbyte (car code))
    (depositbyte (cadr code))
    (modR/M op1 op2))

(de LTH-reg-effa-2 (code op1 op2)
   (plus 2 (lth-reg-5-prefix op2) (lthmodR/M op1 op2)))


%-----------------------------------------------------------------------
% format: fixed modV/M byte
(de OP-EFFA (code op1) (OP-reg-effa code (cadr code) op1))
(de lth-EFFA (code op1) (LTH-reg-effa code (cadr code) op1))

(de OP2-effa(code op1)
    (depositbyte (car code))
    (op-EFFA (cdr code) op1))

(de lth2-EFFA(code op1) (add1 (lth-effa(cdr code) op1)))

%---------------------------------------------------------------------
% immediate to reg
% code is one byte + ModR?m byte, op1 the immediate, op2 the reg
% sometimes there is no ModR/M byte; then the reg is placed in the opcode 
%  (adc 17 (reg ABX)) 
(de OP-imm-reg (code op1 op2)
    (prog(n c1 c2)
      (when (cdr code) (depositbyte (car code))(setq code (cdr code)))
      (depositbyte (lor (car code) (reg2int op2)))
      (depositextension (unimmediate op1))))
 
(de LTH-imm-reg (code op1 op2) (if (cdr code) 6 5))

(de OP-imm8-reg (code op1 op2)
    (prog(n c1 c2)
      (when (cdr code) (depositbyte (car code))(setq code (cdr code))) 
      (depositbyte (lor (car code) (reg2int op2)))
      (depositbyte (bytep op1))))

(de LTH-imm8-reg (code op1 op2) (if (cdr code) 3 2))

(de OP-branch-imm (code offset)
    (setq offset (MakeExpressionRelative offset 8))
    (if (not (weq (land offset 2#11) 0))
	(stderror (bldmsg "Invalid immediate branch offset %w" offset))
      (progn
	(setq offset (ashift offset -2))
	(DepositInstructionBytes
	 (lor (lsh (car code) 4) (cadr code))
	 (land 16#ff (lshift offset -16))
	 (land 16#ff (lshift offset -8))
	 (land 16#ff offset))
	))
    )

(de lth-branch-imm (code offset) 4)

(de OP-branch-reg (code regm)
    (prog (cc opcode1 opcode2 set-bit)
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) opcode2 (cadddr code)) 
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) 2#1111)
	   16#ff 
	   (lor (lsh opcode2 4) (reg2int regm)))
	)
    )

(de lth-branch-reg (code reg) 4)

%---------------------------------------------------------------------
% absolute n-byte instruction
(de OP-byte (code)
	(foreach x in code do (depositbyte x)))
(de lth-byte (code) (length code))

%% %---------------------------------------------------------------------
%% % jump to absolute address
%% % 386 has only relative jumps
%% (de OP-Jump (code op1)
%%   (prog(n)
%%    (depositbyte (car code))
%%    (when (cdr code) (depositbyte (cadr code)))
%%    (setq op1 (saniere-Sprungziel op1))
%%    (setq n(MakeExpressionrelative op1 8)) % offset wrt next instr
%%    (depositword n)
%%    (when *testlap (tab 15)(prin2 "-> ")
%% 	 (prin2 n) (prin2 " rel = ")
%% 	 (prin2 (plus CurrentOffset* n))(prin2t " abs"))))
%% (de lth-jump (code op1) (if (cdr code) 6 5))


%% %jump short (8-bit displacement)
%% (de OP-JUMP-SHORT (code op1)
%%   (prog(n a)
%%    (depositbyte (car code))
%%    (setq op1 (saniere-Sprungziel op1))
%%    (setq n(MakeExpressionrelative op1 1)) % offset wrt next instr
%%    (when (not (bytep n)) (stderror  "distance too long for short jump"))
%%    (depositbyte (bytep n))
%%    (when *testlap (tab 15)(prin2 "-> ") 
%% 	 (prin2 n) (prin2 " rel = ")
%% 	 (prin2 (plus CurrentOffset* n))(prin2t " abs"))))
%% (de lth-JUMP-SHORT (code op1) 2)
 
% indirect jump to effective address
(de OP-JUMP-EFFA (code op1)
	      % a tag "inirect" contained already in the operation if not
	      % explicit reg reference
	   (when (and (eqcar op1 'indirect) (not (regp (cadr op1))))
		 (setq op1 (cadr op1)))
	   (op-reg-effa code (cadr code) op1))
(de LTH-JUMP-EFFA (code op1) 
	   (when (and (eqcar op1 'indirect) (not (regp (cadr op1))))
		 (setq op1 (cadr op1)))
	   (lth-reg-effa code (cadr code) op1))
 

(commentoutcode
%jump full size (32 bit displacement)
(de OP-JUMP-LONG(code op1)
    (depositbyte (car code))
    (setq op1 (saniere-Sprungziel op1))
    (when (cdr code) (depositbyte (cadr code))) %conditional jumps
    (depositExtension op1))
(de lth-JUMP-LONG(code op1) (if (cdr code) 6 5))
)

(de saniere-Sprungziel(l)
    (cond ((atom l) l)
	  ((eqcar l 'IMMEDIATE) (saniere-Sprungziel (cadr l)))
	  ((eqcar l 'LABEL) (saniere-Sprungziel (cadr l)))
	  (T l)))
% RET n
(de OP-RET-n (code op1) 
   (depositbyte (car code)) 
   (deposithalfword (halfwordp (unimmediate op1))))
(de lth-RET-n (code op1) 3) 
  
%-------------------------------------------------------------
%enter 
(de OP-enter (code op1) 
   (depositbyte (car code)) 
   (deposithalfword (unimmediate op1))
   (depositbyte 0))  % support for level 0 only
(de lth-enter (code op1) 4)

%-------------------------------------------------------------
% PUSH imm32
(de OP-imm   (code op1)
   (depositbyte (car code))
   (depositextension (unimmediate op1)))
(de lth-imm   (code op1) 5)
 

%-------------------------------------------------------------
% shift with one parameter
(de op-shift (code dummy op1)
    (depositbyte (car code))
    (modr/m (cadr code) op1))
(de lth-shift (code op1) (add1 (lthmodR/M (cadr code) op1)))
 
%shift with immediate amount
(de op-shiftimm(code op2 op1)
    (depositbyte (car code)) 
    (depositbyte (lor 2#11000000 (lor (cadr code) (reg2int op1))))
    (depositbyte (bytep (unimmediate op2))))
(de lth-shiftimm(code op1 op2) 3)
 
% double shifts
(de op-dshift (code dummy op1) 
    (depositbyte (cadr code)) 
    (modR/M op1 0)) 
(de lth-dshift (code op1) (plus 2 (lthmodR/M op1 0)))
 
(de op-dshiftimm (code op2 op1)  
    (depositbyte (cadr code))  
    (modR/M op1 0)  
    (depositbyte (bytep (unimmediate op2))))
(de lth-dshiftimm (code op1) (plus 3 (lthmodR/M op1 0)))

%-------------------------------------------------------------
% MUL and DIV
(de OP-MUL (code op1) (op-reg-effa code (cadr code) op1))
(de lth-mul (code op1) (lth-reg-effa code (cadr code) op1))

% special: IMUL
(de OP-IMUL (code op1 op2)
    (depositbyte (car code))
    (depositbyte (cadr code))
    (modR/M op1 op2))
(de lth-imul (code op1 op2) 3)

(de rotate-right (n m)
    (lor
     (lsh n (minus m))
     (land 16#ffffffff (lsh n (difference 32 m)))))
		    
(de decode-32bit-imm8-rotated (n)
    (for (from i 0 15 1)
	 (do
	  (if (lessp n 256)
	      (return (cons i n))
	    (setq n (rotate-right n 2))
	    )
	  )
	 )
    )

(de DepositInstructionBytes (byte1 byte2 byte3 byte4)
    (if *big-endian*
	(progn
	  (depositbyte byte1)
	  (depositbyte byte2)
	  (depositbyte byte3)
	  (depositbyte byte4))
      (progn
	(depositbyte byte4)
	(depositbyte byte3)
	(depositbyte byte2)
	(depositbyte byte1))))
	  
    
(de OP-reg-imm8 (code reg1 reg2 imm8-rotated)
    (prog (cc opcode1 opcode2 imm8-decoded set-bit)
	  (setq imm8-decoded (decode-32bit-imm8-rotated imm8-rotated))
	  (if (null imm8-decoded)
	      (stderror (bldmsg "Invalid imm8 operand %w" imm8-rotated)))
	  (setq cc (car code) set-bit (caddr code) opcode1 (cadr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int reg2))
	   (lor (lsh (reg2int reg1) 4) (car imm8-decoded))
	   (cdr imm8-decoded)))
    )

(de lth-reg-imm8 (code reg1 reg2 imm8-rotated) 4)

(de OP-reg-shifter (code reg1 reg2 reg-shifter)
    (prog (cc opcode1 opcode2 reg3 reg4 shift-op shift-amount set-bit)
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) shift-amount 0)
	  (cond ((regp reg-shifter) (setq reg3 (reg2int reg-shifter) reg4 0 opcode2 0))
		((eqcar reg-shifter 'regshifted)
		 (setq reg3 (reg2int (cadr reg-shifter)) shift-op (caddr reg-shifter))
		 (if (eq shift-op 'RRX)
		     (setq shift-amount 0)
		   (setq shift-amount (cadddr reg-shifter)))
		 (cond ((fixp shift-amount)
			(setq reg4 (lsh shift-amount -1)
			      opcode2 (lor (lsh (land shift-amount 1) 3) (subla '((LSL . 2#000) (LSR . 2#010) (ASR . 2#100) (ROR . 2#110) (RRX . 2#110)) shift-op))))
		       ((regp shift-amount)
			(setq reg4 (reg2int (cadddr reg-shifter)))
			(setq opcode2 (subla '((LSL . 2#0001) (LSR . 2#0011) (ASR . 2#0101) (ROR 2#0111)) shift-op))
			)
		       (T (stderr (bldmsg "Invalid operand %w" reg-shifter)))))
		(T (stderr (bldmsg "Invalid operand %w" reg-shifter))))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int reg2))
	   (lor (lsh (reg2int reg1) 4) reg4)
	   (lor (lsh opcode2 4) reg3)))
                                                                            
    )

(de lth-reg-shifter (code reg1 reg2 reg-shifter) 4)

(de OP-regn-imm8 (code regn imm8-rotated)
    (prog (cc opcode1 imm8-decoded set-bit)
	  (setq imm8-decoded (decode-32bit-imm8-rotated imm8-rotated))
	  (if (null imm8-decoded)
	      (stderror (bldmsg "Invalid imm8 operand %w" imm8-rotated)))
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int regn))
	   (car imm8-decoded)
	   (cdr imm8-decoded)))
    )

(de lth-regn-imm8 (code regn imm8-rotated) 4)

(de OP-regn-shifter (code regn reg-shifter)
    (prog (cc opcode1 opcode2 set-bit reg3 reg4 shift-op shift-amount)
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) shift-amount 0)
	  (cond ((regp reg-shifter) (setq reg3 (reg2int reg-shifter) reg4 0 opcode2 0))
		((eqcar reg-shifter 'regshifted)
		 (setq reg3 (reg2int (cadr reg-shifter)) shift-op (caddr reg-shifter))
		 (if (eq shift-op 'RRX)
		     (setq shift-amount 0)
		   (setq shift-amount (cadddr reg-shifter)))
		 (cond ((fixp shift-amount)
			(setq reg4 (lsh shift-amount -1)
			      opcode2 (lor (lsh (land shift-amount 1) 3) (subla '((LSL . 2#000) (LSR . 2#010) (ASR . 2#100) (ROR . 2#110) (RRX . 2#110)) shift-op))))
		       ((regp shift-amount)
			(setq reg4 (reg2int (cadddr reg-shifter)))
			(setq opcode2 (subla '((LSL . 2#0001) (LSR . 2#0011) (ASR . 2#0101) (ROR 2#0111)) shift-op))
			)
		       (T (stderr (bldmsg "Invalid operand %w" reg-shifter)))))
		(T (stderr (bldmsg "Invalid operand %w" reg-shifter))))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int regn))
	   reg4
	    (lor (lsh opcode2 4) reg3)))
    )

(de lth-regn-shifter (code regn reg-shifter) 4)

(de OP-regd-imm8 (code regd imm8-rotated)
    (prog (cc opcode1 imm8-decoded set-bit)
	  (setq imm8-decoded (decode-32bit-imm8-rotated imm8-rotated))
	  (if (null imm8-decoded)
	      (stderror (bldmsg "Invalid imm8 operand %w" imm8-rotated)))
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4))
	   (lor (lsh (reg2int regd) 4) (car imm8-decoded))
	   (cdr imm8-decoded)))
    )

(de lth-regd-imm8 (code regd imm8-rotated) 4)

(de OP-regd-shifter (code regd reg-shifter)
    (OP-reg-shifter code regd '(reg R0) reg-shifter))

(de lth-regd-shifter (code reg reg-shifter) 4)


(de OP-mul3 (code reg1 reg2 reg3)
    (prog (cc opcode1 opcode2 set-bit rest)
	  (setq cc (car code)
		opcode1 (cadr code)
		set-bit (caddr code)
		opcode2 (cadddr code)
		rest (car (cddddr code)))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4))  (reg2int reg1))
	   (lor (lsh rest 4) (reg2int reg3))
	   (lor (lsh opcode2 4) (reg2int reg2)))))

(de lth-mul3 (code reg1 reg2 reg3) 4)
		       
(de OP-mul4 (code reg1 reg2 reg3 reg4)
    (prog (cc opcode1 opcode2 set-bit)
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) opcode2 (cadddr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -4))
	   (lor (land opcode1 2#1111) (reg2int reg1))
	   (lor (lsh (reg2int reg4) 4) (reg2int reg3))
	   (lor (lsh opcode2 4) (reg2int reg2)))))

(de lth-mul4 (code reg1 reg2 reg3 reg4) 4)

(de OP-clz (code regd regm)
    (prog (cc opcode1 opcode2 reg3 reg4 shift-op shift-amount set-bit)
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) opcode2 (cadddr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lsh (land opcode1 2#111) 5) 2#01111)
	   (lor (lsh (reg2int regd) 4) 2#1111)
	   (lor (lsh opcode2 4) (reg2int regm)))
	  )
    )

(de lth-clz (code regd regm) 4)


%%  Instruction                                      Lisp expression for second operand
%% LDR Rd,[Rn]                                         (indirect (reg n))
%% LDR Rd,[Rn,+/-offset12]                             (displacement (reg n) +/-12bit-number)
%% LDR Rd,[Rn,Rm]                                      (displacement (reg n) (reg m))
%% LDR Rd,[Rn,+/-Rm]                                   (displacement (reg n) (plus|minus (reg m)))
%% LDR Rd,[Rn,Rm, shift, #shift_imm]                   (displacement (reg n) (regshifted <regno> LSL/LSR.. amount))
%% LDR Rd,[Rn,+/-Rm, shift, #shift_imm]                (displacement (reg n) (plus|minus (regshifted <regno> LSL/LSR.. amount)))
%% LDR Rd,[Rn,+/-offset12]!                            (displacement (reg n) +/-12bit-number preindexed)
%% LDR Rd,[Rn,Rm]!                                     (displacement (reg n) (reg m) preindexed)
%% LDR Rd,[Rn,+/-Rm]!                                  (displacement (reg n) (plus|minus (reg m)) preindexed)
%% LDR Rd,[Rn,+Rm, shift, #shift_imm]!                 (displacement (reg n) (regshifted <regno> LSL/LSR.. amount) preindexed)
%% LDR Rd,[Rn,+/-Rm, shift, #shift_imm]!               (displacement (reg n) (plus|minus (regshifted <regno> LSL/LSR.. amount)) preindexed)
%% LDR Rd,[Rn],+/-offset12                             (displacement (reg n) +/-12bit-number postindexed)
%% LDR Rd,[Rn],Rm                                      (displacement (reg n) (reg m) postindexed)
%% LDR Rd,[Rn],+/-Rm                                   (displacement (reg n) (plus|minus (reg m)) postindexed)  
%% LDR Rd,[Rn],Rm, shift, #shift_imm                   (displacement (reg n) (regshifted <regno> LSL/LSR.. amount) postindexed)
%% LDR Rd,[Rn],+/-Rm, shift, #shift_imm                (displacement (reg n) (plus|minus (regshifted <regno> LSL/LSR.. amount)) postindexed)  

(de OP-ld-st (code regd reg-offset12)
    (prog (cc ld-bit opcode1 temp shift-op shift-amount regn displ pre-post p-bit u-bit w-bit regm lastbyte)
	  (setq cc (car code) opcode1 (cadr code) ld-bit (caddr code) shift-amount 0)
	  (if (and
	       (not (stringp reg-offset12))
	       (or (not (pairp reg-offset12)) (not (memq (car reg-offset12) '(displacement indirect))) (not (regp (cadr reg-offset12)))))
	      (stderror (bldmsg "Invalid LDR/STR operand: %w" reg-offset12)))
	  (if (labelp reg-offset12)	% label --> pc-relative
	      (progn
		(setq regn 15)
		(setq displ (MakeExpressionRelative reg-offset12 8)))
	    (progn
	      (setq regn (reg2int (cadr reg-offset12)))
	      (setq displ (if (eqcar reg-offset12 'indirect) 0 (caddr reg-offset12)))))
	  (setq u-bit 1)
	  (cond ((or (labelp reg-offset12) (null (cddr reg-offset12)) (null (cdddr reg-offset12))) % no pre or post indexed
		 (setq p-bit 1 w-bit 0))
		((memq (cadddr reg-offset12) '(preindexed postindexed))
		 (setq pre-post (cadddr reg-offset12))
		 (setq p-bit (if (eq pre-post 'preindexed) 1 0))
		 (setq w-bit (if (eq pre-post 'preindexed) 1 0)))
		(t (stderror (bldmsg "Invalid LDR/STR operand: %w" reg-offset12))))
	  (cond ((and (fixp displ) (lessp displ 4096) (greaterp displ -4096))
		 (if (lessp displ 0)
		     (progn
		       (setq u-bit 0)
		       (setq displ (minus displ)))
		   (setq u-bit 1))
		 (setq temp (lsh displ -8))
		 (setq lastbyte (land displ 16#FF)))
		((or (not (pairp displ))
		     (not (memq (car displ) '(reg regshifted plus minus))))
		 (stderror (bldmsg "Invalid LDR/STR operand: %w" reg-offset12)))
                % check for register offset
		((or (regp displ)
		     (and (memq (car displ) '(plus minus))
			  (progn (if (eq (car displ) 'minus) (setq u-bit 0))
				 (regp (setq displ (cadr displ))))))
		 (setq temp 0)
%                 (setq opcode1 (lor opcode1 16#10))
		 (setq lastbyte (reg2int displ)))
                % check for scaled register offset
		((or (eq (car displ) 'regshifted)
		     (and (memq (car displ) '(plus minus))
			  (progn (if (eq (car displ) 'minus) (setq u-bit 0))
				 (eq (car (setq displ (cadr displ))) 'regshifted))))
		 (setq regm (reg2int (cadr displ)) shift-op (caddr displ))
%                 (setq opcode1 (lor opcode1 16#10))
		 (if (eq shift-op 'RRX)
		     (setq shift-amount 0)
		   (setq shift-amount (cadddr displ)))
		 (setq temp (lsh shift-amount -1)
		       lastbyte (lor (lsh (land shift-amount 1) 7)
				     (lor (subla '((LSL . 2#0000000) (LSR . 2#0100000) (ASR . 2#1000000) (ROR . 2#1100000) (RRX . 2#1100000)) shift-op)
					  regm))))
		(t (stderror (bldmsg "Invalid LDR/STR operand: %w" reg-offset12))))
	  (DepositInstructionBytes
	   (lor (lor (lsh cc 4) (lsh opcode1 -3)) p-bit)
	   (lor (lor (lsh u-bit 7) (lsh (land opcode1 2#111) 5) ) (lor (lsh w-bit 5) (lor (lsh ld-bit 4) regn)))
	   (lor (lsh (reg2int regd) 4) temp)
	   lastbyte))
    )

(de lth-ld-st (code regn reg-offset12) 4)

%%  Instruction                                      Lisp expression for second operand
%% LDRD Rd,[Rn,+/-offset8]                              (displacement (reg n) +/-8bit-number)
%% LDRD Rd,[Rn,Rm]                                      (displacement (reg n) (reg m))
%% LDRD Rd,[Rn,+/-Rm]                                   (displacement (reg n) (plus|minus (reg m)))
%% LDRD Rd,[Rn,+/-offset8]!                             (displacement (reg n) +/-8bit-number preindexed)
%% LDRD Rd,[Rn,Rm]!                                     (displacement (reg n) (reg m) preindexed)
%% LDRD Rd,[Rn,+/-Rm]!                                  (displacement (reg n) (plus|minus (reg m)) preindexed)
%% LDRD Rd,[Rn],+/-offset8                              (displacement (reg n) +/-8bit-number postindexed)
%% LDRD Rd,[Rn],Rm                                      (displacement (reg n) (reg m) postindexed)
%% LDRD Rd,[Rn],+/-Rm                                   (displacement (reg n) (plus|minus (reg m)) postindexed)  

(de OP-ld-st-misc (code regd reg-offset8)
    (prog (cc ld-bit opcode1 opcode2 temp shift-op shift-amount regn displ pre-post p-bit u-bit w-bit regm lastnibble)
	  (setq cc (car code) opcode1 (cadr code) ld-bit (caddr code) opcode2 (cadddr code) shift-amount 0)
	  (if (or (not (pairp reg-offset8))
		  (not (memq (car reg-offset8) '(displacement indirect)))
		  (not (regp (cadr reg-offset8))))
	      (stderror (bldmsg "Invalid misc. load/store operand %w" reg-offset8)))
	  (setq regn (reg2int (cadr reg-offset8)))
	  (setq displ (if (eqcar reg-offset8 'indirect) 0 (caddr reg-offset8)))
	  (setq u-bit 1)
	  (cond ((or (eqcar reg-offset8 'indirect)
		     (null (cdddr reg-offset8))) % no pre or post indexed
		 (setq p-bit 1 w-bit 0))
		((memq (cadddr reg-offset8) '(preindexed postindexed))
		 (setq pre-post (cadddr reg-offset8))
		 (setq p-bit (if (eq pre-post 'preindexed) 1 0))
		 (setq w-bit (if (eq pre-post 'preindexed) 1 0)))
		(t (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8))))
	  (cond ((and (fixp displ) (lessp displ 256) (greaterp displ -256))
		 (if (lessp displ 0)
		     (progn
		       (setq u-bit 0)
		       (setq displ (minus displ)))
		   (setq u-bit 1))
		 (setq temp (lsh displ -4))
		 (setq lastnibble (land displ 16#0F)))
		((or (not (pairp displ))
		     (not (memq (car displ) '(reg plus minus))))
		 (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8)))
		((or (regp displ)
		     (and (memq (car displ) '(plus minus))
			  (progn (if (eq (car displ) 'minus) (setq u-bit 0))
				 (regp (setq displ (cadr displ))))))
		 (setq temp 0)
		 (setq lastnibble (reg2int displ)))
		(t (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8))))
	  (DepositInstructionBytes
	   (lor (lor (lsh cc 4) (lsh opcode1 -3)) p-bit)
	   (lor (lor (lsh u-bit 7) (lsh (land opcode1 2#111) 5) ) (lor (lsh w-bit 5) (lor (lsh ld-bit 4) regn)))
	   (lor (lsh (reg2int regd) 4) temp)
	   (lor (lshift opcode2 4) lastnibble)))
    )

(de lth-ld-st-misc (code regn reg-offset8) 4)

(de OP-ldm-stm (code regn reglist writeback?)
    (prog (cc opcode1 regbits ld-bit w-bit)
	  (setq cc (car code) opcode1 (cadr code) ld-bit (caddr code) regbits 0)
	  (setq w-bit (if writeback? 1 0))
	  (foreach reg in reglist do
		   (setq regbits (lor regbits (lsh 1 (reg2int reg)))))
	   (DepositInstructionBytes
	    (lor (lsh cc 4) (lsh opcode1 -3))
	    (lor (lor (lsh (land opcode1 2#111) 5) (lsh w-bit 5)) (lor (lsh ld-bit 4) (reg2int regn)))
	    (lsh regbits -8)
	    (land regbits 16#ff)))
    )

(de lth-ldm-stm (code regn reg-offset12) 4)



% ------------------------------------------------------------
% standard operand tags
% ------------------------------------------------------------



(de DepositFluid (X)
    (DepositValueCellLocation (second X)))      % Defined in System-Faslin.Red

(de DepositExtraReg (X)
    (DepositExtraRegLocation (second X)))       % Defined in System-Faslin.Red

(de DepositEntry (X)
    (DepositFunctionCellLocation (second X)))   % Defined in System-Faslin.Red

(de depositforeignentry (x)
  (depositfunctioncelllocation (second x)))

(put 'fluid 'OperandDepositFunction (function DepositFluid))
(put '$fluid 'OperandDepositFunction (function DepositFluid))
(put 'global 'OperandDepositFunction (function DepositFluid))
(put '$global 'OperandDepositFunction (function DepositFluid))
(put 'ExtraReg 'OperandDepositFunction (function DepositExtraReg))
(put 'entry 'OperandDepositFunction (function DepositEntry))
(put 'foreignentry 'operanddepositfunction (function depositforeignentry))
 


% ------------------------------------------------------------
% Deposit instructions for Pseudo ops
% ------------------------------------------------------------

(de DepositWordBlock (X)                % (FULLWORD xxx xxx ... xxx)
    (foreach Y in (cdr X) do (DepositWordExpression Y)))

(de DepositHalfWordBlock (X)            % (HALFWORD xxx xxx ... xxx)
    (foreach Y in (cdr X) do (DepositHalfWordExpression Y)))

(de DepositByteBlock (X)                % (BYTE     xxx xxx ... xxx)
(prog (Z) 
    (setq Z 0) 
    (foreach Y in (cdr X) do 
    (progn (DepositByte Y) 
	(setq Z (LXOR Z 1))))           % toggle Z
    (cond ((not (equal Z 0)) (DepositByte 0)))))        % go to halfword boundary


% Deposit a string with a trailing ZERO byte

(de DepositString (X)                   % (STRING "xxxxxx")
  (prog nil 
    (setq X (second X)) 
    (for (from I 0 (Size X) 1) (do (DepositByte (Indx X I)))) 
    (DepositByte 0) 
	(while (not (eq 0 (remainder CurrentOffset!* 4)))
	       (depositbyte 0))))
% align to word boundary

(de DepositFloat (X)                    % this will not work in cross-assembly
(progn (setq X (FltInf (second X))) 
    (DepositWord (FloatlowOrder X)) 
    (DepositWord (FloathighOrder X))))

(put 'fullword 'InstructionDepositFunction 'DepositWordBlock)
(put 'halfword 'InstructionDepositFunction 'DepositHalfWordBlock)
(put 'byte 'InstructionDepositFunction 'DepositByteBlock)
(put 'string 'InstructionDepositFunction 'DepositString)
(put 'float 'InstructionDepositFunction 'DepositFloat)

% Auxiliary functions for computing instruction bit patterns

(de MakeExpressionRelative (Exp OffsetFromHere) 
(prog (X Y Z) 
    (cond ((EqCar Exp 'InternalEntry) 
      (return (MakeInternalEntryRelative (second Exp) OffsetFromHere)))) 

    (cond ((not (LabelP Exp))
	   (return (StdError "Only labels can be relative")))) 

    (setq X (plus CurrentOffset* OffsetFromHere)) 
    (setq Y (LabelOffset Exp))
    (return (Difference Y X))))


(de makeinternalentryrelative (nam offsetfromhere)
  (prog (offset)
	(setq offset (atsoc nam labeloffsets*))
	(setq offset (if offset
		(cdr offset)
		(get nam 'internalentryoffset)))
	(return (if offset
		  (progn
		    (setq offset 
		     (difference offset 
		      (plus2 CurrentOffset* offsetfromhere))))
		  (progn
		    (setq forwardinternalreferences* 
		     (cons (cons CurrentOffset* nam) 
		      forwardinternalreferences*))
		    0)))))
	% will be fixed in SystemFasl...


(de labeloffset (l)
  (let (offset)
    (cond 
     ((codep l) (if *writingfaslfile
		  (inf l)
		  (wdifference (inf l) codebase*)))
     ((setq offset  (atsoc l labeloffsets*)) (cdr offset))
     (t (stderror (bldmsg "Unknown label %r" l)))
     )))



% ------------------------------------------------------------
% Branch analysis (conditional jumps)
% ------------------------------------------------------------

(fluid '(ConditionalJumps*))
(setq ConditionalJumps* 
  '((beq  . bne)  (bne  . beq)
    (bcs  . bcc)  (bcc  . bcs)
    (bmi  . bpl)  (bpl  . bmi)
    (bvs  . bvc)  (bvc  . bvs)
    (bhi  . bls)  (bls  . bhi)
    (bge  . blt)  (blt  . bge)
    (bgt  . ble)  (ble  . bgt)
))

(de ReformBranches (code)
  (prog (rcode instr bottom x y z)
    (while code
       (setq instr (pop code))
	   % replace simple negation jumps
	   % case: (jne lab)(j anywhere) lab
	   %  ->   (je anywhere)
       (when (and 
		(pairp instr)
		(setq x (atsoc (car instr) ConditionalJumps*))
		(setq y (saniere-Sprungziel (cadr instr)))
		(eqcar (car code) 'JMP)
		(cdr code)
		(equal (cadr code) y))
	     (setq instr (cons (cdr x) (cdr (pop code)))))
	   % replace indirect conditional jumps (not avail on 386)
	(when (and
		(pairp instr)
		(atsoc (car instr) ConditionalJumps*)
		(not (atom (saniere-Sprungziel (cadr instr)))))
	     (setq x (gensym))
	     (push (cons 'JMP (cdr instr)) bottom)
	     (push x bottom)
	     (setq instr (list (car instr) x))   )
	(push instr rcode))
	(return (nconc (reversip rcode) bottom))))
 
% ------------------------------------------------------------
% Branch optimization (in favour of short jumps)
% ------------------------------------------------------------

(deflist '(
   (BEQ BEQ) (BNE BNE) (BCS BCS)(BCC BCC)
   (BMI BMI) (BPL BPL) (BVS BVS)(BVC BVC)
   (BHI BHI)(BLS BLS)(BGE BGE)(BLT BLT)
   (BGT BGT)(BLE BLE)(BAL BAL)
   (B B) (BX BX) (BLX BLX)
) 'WordBranch)

(de GeneralBranchInstructionP (i) (get i 'WordBranch))
(de LocalLabelp (l) (atom (saniere-Sprungziel l)))

% ProcessInitCode CodeList
% Purpose: Take a code list which has already been expanded by Pass1Lap
%          and replaces all generic branches with word mode branches.
% Returns: a new code list

(de ProcessInitCode (CodeList) 
(prog (BranchAndLabelAList*)            % find branches, labels, and entries
    (setq CodeList (BuildInitCodeOffsetTable CodeList)) 
    (setq LabelOffsets* (DeleteAllButLabels BranchAndLabelAList*)) 
    (return CodeList)))


% OptimizeBranches BranchCodeList!*;
% Purpose: Take a code list which has already been expanded by Pass1Lap
%          and try to optimize the branches
% Returns: a new code list

(de OptimizeBranches (u) (OptimizeBranches0 u *WritingFaslFile))

(de OptimizeBranches0 (u m) 
(prog (BranchAndLabelAList* InstructionChanged* q w) 
    (setq BranchCodeList* (if m (alignCode u) u))
    (BuildOffsetTable)                  % find branches, labels, and entries
    (setq InstructionChanged* nil)
    (FindLongBranches)
    (when (and m InstructionChanged*)   
	      % give up aligned code 
	  (return (OptimizeBranches0 u nil)))
    (while InstructionChanged* 
	 (setq InstructionChanged* nil) 
	 (FindLongBranches)) 
    (setq LabelOffsets* (DeleteAllButLabels BranchAndLabelAList*)) 
    (return BranchCodeList*)))

%% (de &make-nop(n)
%%    % make n bytes of nop instructions
%%    (cond ((wleq n 0) nil)
%% 	 ((eq n 1)'((inc (reg t2))))
%% 	 ((eq n 2)'((mov (reg t1)(reg t1))))
%% 	 ((eq n 3)'((lea (displacement(reg t1)0) (reg t1))))
%% 	 (t (append (&make-nop 3)(&make-nop (difference n 3)))) ))

(de &make-nop(n))

(de alignCode(u)
  (if (&smember 'fastapply u) u (alignCode1 u)))

(de alignCode1(u)
   (let(rcode w (a CurrentOffset*) l x y z q s nops)
     (while u
       (setq w (pop u))
       (setq nops 0)
       (cond 

	 % initial start: sync. entry point
	   ((null rcode)
	     (setq x a)
	     (setq y u q w)
	     (setq s (eqcar w '*entry))
	     (while y
		 (when (pairp q)(setq x (iplus2 x (instructionlength q))))
		 (if (eqcar q '*entry) (setq y nil) (setq q (pop y))))
	     (setq x (wand x 15))
	     (when (not (eq x 0)) (setq nops (idifference 16 x)))
	    )
 
	% entry: executable code starts
	    ((eqcar w '*entry)(setq s t))
	    
	% fullword: executable code terminated
	    ((eqcar w 'fullword)(setq s nil)) 

        % label under *align16
	   ((and s (atom w) *align16)
	      % next instruction should begin on cache line
	     (setq x (wand a 15))   
	     (when (not (eq x 0)) 
		   (setq nops(wdifference 16 x))))

	% label in standard mode
	   ((and s (atom w) u (pairp (car u))) 
	      % next instruction should not split cache lines
	    (setq x (iplus2 (wand a 15) (instructionlength (car u))))
	    (when (not (igreaterp x 16))
		  (setq nops (idifference 16 (wand a 15))))
	   )
	       
       % call under *align16
	   ((and *align16 (eqcar w 'call))  
	      % put call exactly at the end of cache line
	    (setq x (wand (iplus2 a (instructionlength w)) 15))
	    (when (not (eq x 0)) (setq nops (idifference 16 x)))
	   )

	% call 
	   ((and (eqcar w 'call) u (pairp (car u)))  
	      % following instruction should not split over cache line
	    (setq x (wand (iplus2 a (instructionlength w)) 15))
	    (when (igreaterp (iplus2 x (instructionlength (car u)))16)
		  (setq nops (idifference 16 x)))
	   )
	 )   
       (when (and (igreaterp nops 0) 
		  (ilessp nops 9))  % not too many
	     (foreach q in (&make-nop nops) do (push q rcode))
	     (setq a (iplus2 a nops)))
       (when (pairp w)(setq a (iplus2 a (InstructionLength w))))
       (push w rcode)
      )
      (while rcode
	 (when (not (eq (setq w (pop rcode)) '!%temp-label))
	       (push w u)))
    u      
))

(de DeleteAllButLabels (X) 
(prog (Y) 
   (while (and X (not (LabelP (car (first X))))) (setq X (cdr X))) 

   (cond ((null X) (return nil))) 
    (setq Y X) 
    (while (cdr Y) 
	(cond ((LabelP (car (second Y))) 
	    (setq Y (cdr Y))) (t 
	
	    (Rplacd Y (cddr Y))))) 
    (return X)))


% BuildInitCodeOffsetTable CodeList;
% Purpose: generate a association list of labels, procedure entries
% Input is:
     %   labels:             label
     %   instructions:     ( opcode [operands]* )
     %   entry points:     ( !*entry procedurename proceduretype numberofargs)
% The Alist has the form:
     %   labels:           ( label . CurrentOffset)
     %   procedures:       ( procedurename . CurrentOffset)
     %   branch instrs     ( (opcode label) . CurrentOffset)
% otherwise, the CurrentOffset is advanced by the length of the instruction

(de BuildInitCodeOffsetTable (CodeList) 
(prog (AList Instr) 
    (setq CodeSize* CurrentOffset*) 
    (foreach X in CodeList do 
   (progn (cond ((LabelP X) 
	  (setq AList (cons (cons X CodeSize*) AList))) 
   ((equal (setq Instr (first X)) '*entry) 
	  (setq AList (cons (cons (second X) CodeSize*) AList))) 
   ((and (GeneralBranchInstructionP Instr)(locallabelp (second X))) 
	  (progn (Rplaca X (get Instr 'WordBranch)) 

		    (setq CodeSize* (plus CodeSize* (InstructionLength X))) 
		    (setq AList (cons (cons X CodeSize*) AList)))) (t 
		
   (setq CodeSize* (plus CodeSize* (InstructionLength X))))))) 
    

    (setq BranchAndLabelAList* (ReversIP AList)) 
    (return CodeList)))


%  BuildOffsetTable();
% Purpose: generate a association list of labels, procedure entries
% The Alist has the form:
     %   labels:           ( label . CurrentOffset)
     %   procedures:       ( procedurename . CurrentOffset)
     %   branch instrs     ( (opcode label) . CurrentOffset)

(de BuildOffsetTable nil 
 (prog (AList Instr) 
  (setq CodeSize* CurrentOffset*) 
  (foreach X in BranchCodeList* do 
   (progn 
     (cond ((LabelP X) (setq AList (cons (cons X CodeSize*) AList))) 
	   ((equal (setq Instr (first X)) '*entry) 
	    (setq AList (cons (cons (second X) CodeSize*) AList))) 
	       % branch: enter the address of the following instruction
	   ((and (GeneralBranchInstructionP Instr) (locallabelp (second X))) 
	    (setq CodeSize* (plus CodeSize* (InstructionLength X))) 
	    (setq AList (cons (cons X CodeSize*) AList))) 
	   (t (setq CodeSize* (plus CodeSize* (InstructionLength X)))))))
  (setq BranchAndLabelAList* (ReversIP AList)) 
  (setq InstructionChanged* BranchAndLabelAList*)
  (return BranchAndLabelAList*) ))


(de FindLongBranches nil 
 (prog (CurrentDisplacement) 
  (foreach entry on BranchAndLabelAList* do 
    (cond ((not (LabelP (car (first entry)))) 
      (progn 
	(setq CurrentDisplacement (FindDisplacement (first entry))) 
	(cond 
	   ((or (GreaterP CurrentDisplacement (const MaximumShortBranch)) 
		(ZeroP CurrentDisplacement))    % Must have long brahch.
	  
	  (progn (setq InstructionChanged* t) 
	      (IncreaseAllOffsets entry (MakeLongBranch entry)))))))))))
      


(de FindDisplacement (InstructionOffsetPair) 
    (Abs (Difference (cdr InstructionOffsetPair) 
		    (FindLabelOffset (second (first InstructionOffsetPair))))))

%  FindLabelOffset(Label)
% Purpose: looks up the location of Label in BranchAndLabelAList!*
% Returns: the offset of said Label

(de FindLabelOffset (L) 
(prog (Offset) 
    (return 
     (cond ((EqCar L 'InternalEntry) (FindEntryOffset (second L))) 

	   ((setq Offset (Atsoc (saniere-Sprungziel L) BranchAndLabelAList*)) (cdr Offset))
	   (t (StdError (BldMsg "Unknown label %r" L)))))))


%  FindEntryOffset(ProcedureName);
% Purpose: looks up the location of ProcedureName in BranchAndLabelAList!*
% Returns: the offset of said ProcedureName
%          if an entry point is not known for this procedure it returns a
%          dummy value of -2000

(de FindEntryOffset (L) 
    (cond ((setq L (Atsoc L BranchAndLabelAList*)) (cdr L)) (t -2000)))

(de MakeLongBranch (AList) 
(prog (InstructionList Result OppositeBranch n) 
    (setq InstructionList (car (first AList))) 
    (setq n (instructionlength InstructionList))
    (Rplaca InstructionList (get (first InstructionList) 'WordBranch)) 
    (setq n (difference (instructionlength InstructionList) n))
    (cond ((cdr AList) (Rplacw AList (cdr AList)))
	  (t (Rplacw AList (list (cons '~DummyLabel~ 0))))) 
    (return n))) % increased length of subsequent code


(de IncreaseAllOffsets (X N) 
    (foreach Y in X do (Rplacd Y (plus (cdr Y) N))) 
    (setq CodeSize* (plus CodeSize* N)))

% ------------------------------------------------------------
% Procedures to compute instruction lengths
% ------------------------------------------------------------

(de InstructionLength (X)
   (prog (Y) 
       (when (setq Y (get (car x) 'InstructionLengthFunction))
	     (return (apply3safe y (cdr x))))
       (when (setq Y (get (car x) 'INSTRUCTIONLENGTH))
	 (return (if (numberp y) y (apply y (list x)))))
       (return 4)))
%       (stderror (bldmsg "*** Unknown ARMv6 instruction:%w " x))))

(de apply2safe(y x) % ensure that plly has two parameters at least
     (cond ((null x) (apply y (list nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil)))
	   (t (apply y (list (car x)(cadr x))))))

(de apply3safe(y x) % ensure that plly has two parameters at least
     (cond ((null x) (apply y (list nil nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil nil)))
	   ((null (cddr x)) (apply y (list (car x) (cadr x) nil)))
	   (t (apply y (list (car x)(cadr x)(caddr x))))))

(de InlineConstantLength (X) 
% Purpose: returns the Size_Of_Unit_In_Bytes * Number_Of_Such_Units
%   X has the form:
%          (Unit  value_1  value_2 value_3 .... )
    (Times2 (cond ((equal (first X) 'fullword) 4) (t 2)) 
	     
	     
	   (length (rest X))))

(de ByteConstantLength (X) 
    (Times2 (Quotient (Plus2 (length (rest X)) 1) 2) 2))

(de LapStringLength (X)                 % must fall on word boundary
% Purpose: Calculate the number of bytes occupied by a given string
%  X has the form: (STRING "xxxxxx")
    (Times2 (Quotient (Plus2 (Size (second X)) 5) 4) 4))

(DefList '((fullword InlineConstantLength) 
	  (halfword InlineConstantLength) 
	  (byte ByteConstantLength) 
	  (float 8) 
	  (string LapStringLength)) 'InstructionLength)


(put '*entry 'InstructionLength 0)

% ------------------------------------------------------------
% Depositing Operations
% ------------------------------------------------------------

(de DepositByte (X) 
(progn (putbyte (wPlus2 CodeBase* CurrentOffset*) 0 X) 
    (UpdateBitTable 1 0) 
    (setq CurrentOffset* (plus CurrentOffset* 1))))

(de DepositHalfWord (X) 
(progn (puthalfword (wPlus2 CodeBase* CurrentOffset*) 0 X) 
    (UpdateBitTable 2 0) 
    (setq CurrentOffset* (plus CurrentOffset* 2))))

(de DepositWord (x)
  (putword (wplus2 codebase* CurrentOffset*) 0 x)
  (updatebittable 4 0)
  (setq CurrentOffset* (plus CurrentOffset* 4)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (putword (wplus2 codebase* CurrentOffset*)
	   0 
	   (iplus2 offset (if *writingfaslfile 0 codebase*)))
  (updatebittable 4 (const reloc_word))
  (setq CurrentOffset* (plus CurrentOffset* 4)))
  
(de DepositWordExpression (x)
  % Only limited expressions now handled
  (let (y)
    (cond
      ((fixp x) (depositword (int2sys x)))
      ((labelp x) (deposit-relocated-word (labeloffset x)))
      ((equal (first x) 'internalentry) 
       (let ((offset (get (second x) 'internalentryoffset)))
	 (if offset
	     (deposit-relocated-word offset)
	     (progn
	       (setq forwardinternalreferences*
		     (cons (cons CurrentOffset* (second x))
			   forwardinternalreferences*))
	       (deposit-relocated-word 0)))))
      ((and (eq (car x) 'mkitem)
	    (eq (cadr x) id-tag)
	    (eqcar (setq y (caddr x)) 'idloc)
	    (wlessp (id2int (cadr y)) 257))
	(depositword (cadr y)))
      ((equal (first x) 'idloc) (depositwordidnumber (second x)))
      ((equal (first x) 'mkitem) (deposititem (second x) (third x)))
      ((equal (first x) 'entry) (depositentry x))
      ((setq y (wconstevaluable x)) (DepositWord (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))))

(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 128)) 
     (depositword (idinf X)))
    (t
      (putword (wplus2 codebase* CurrentOffset*) 0 
	       (makerelocword (const reloc_id_number) (findidnumber x))) 
      (setq CurrentOffset* (plus CurrentOffset* 4)) 
      (updatebittable 4 (const reloc_word)))))

(de DepositHalfWordExpression (X) 
(prog (Y) 
    (return (cond ((FixP X) (DepositHalfWord X)) 
    ((LabelP X) 
    (progn (puthalfword (wPlus2 CodeBase* CurrentOffset*) 0 
		    (IPlus2 (LabelOffset X) 
			   (cond (*WritingFaslFile 0) (t CodeBase*)))) 
	(UpdateBitTable 2 (const RELOC_HALFWORD)) 
	(setq CurrentOffset* (plus CurrentOffset* 2)))) 
    
	    ((and (equal (first X) 'Difference) (LabelP (second X)) 
	    (LabelP (third X))) 
	   (DepositHalfWord (Difference (LabelOffset (second X)) 
					   (LabelOffset (third X))))) 
    ((equal (first X) 'IDLoc) 
	   (DepositHalfWordIDNumber (second X))) 
    ((setq Y (WConstEvaluable X)) 
	   (DepositHalfWord Y)) (t 
    (StdError (BldMsg "Halfword expression too complicated %r" X)))))))


(de DepositItem (TagPart InfPart) 
    (cond ((not *WritingFaslFile) 
	   (DepositWord 
	       (MkItem TagPart 
		       (cond ((LabelP InfPart) 
			      (wPlus2 CodeBase* (LabelOffset InfPart))) 
			     ((equal (first InfPart) 'IDLoc) 
			      (IDInf (second InfPart))) 
			     (t 
				(StdError 
				    (BldMsg "Unknown inf in MkItem %r"
					    InfPart)))))))
	  (t 
	     (progn (cond 
		     ((LabelP InfPart)      % RELOC_CODE_OFFSET = 0
		      (putword (wPlus2 CodeBase* CurrentOffset*) 0 
		       (MkItem TagPart (LabelOffset InfPart)))) 
		     ((equal (first InfPart) 'IDLoc) 
		      (putword (wPlus2 CodeBase* CurrentOffset*) 0 
		       (MkItem TagPart 
			(MakeRelocInf (const RELOC_ID_NUMBER) 
			  (FindIDNumber (second InfPart))))))
		     (t 
		      (StdError (BldMsg "Unknown inf in MkItem %r"
				 InfPart))))
	      (setq CurrentOffset* (plus CurrentOffset* 4))
	      (UpdateBitTable 4 (const RELOC_INF))))))

(de DepositHalfWordIDNumber (X) 
    (cond ((or (not *WritingFaslFile) (LEQ (IDInf X) 128)) 
	(DepositHalfWord (IDInf X))) (t 
    
    (progn (puthalfword (wplus2 codebase* CurrentOffset*) 0 
		    (makerelochalfword (const reloc_id_number) (findidnumber x))) 
	(setq CurrentOffset* (plus CurrentOffset* 2)) 
	(updatebittable 2 (const reloc_halfword))))))

% ------------------------------------------------------------
% this procedure was "inserted" to eliminate the problem with the compiler
% not generating the code for:
% function lambda y;remprop(y, 'internalentryoffset);
% who knows why it didn't generate anything reasonable - it generated nil.
(de remove-ieo-property (y) 
  (remprop y 'internalentryoffset))
% ------------------------------------------------------------

(de systemfaslfixup ()
  (prog (x)
     % THIS VERSION ASSUMES 32 bit RELATIVE ADDESSES, HM.
     (setq x (remainder CurrentOffset* 16))
     (while (greaterp x 0) (depositbyte 0) (setq x (sub1 x)))
     (while forwardinternalreferences*
       (setq x (get (cdr (first forwardinternalreferences*)) 
		    'internalentryoffset))
       (when (null x) 
	      (errorprintf "***** %r not defined in this module, call incorrect" 
			   (cdr (first forwardinternalreferences*))))
	       % calculate the offset
       (setq x (plus -4             % offset to next word
	     (difference x (car (first forwardinternalreferences*)))))
			 % insert the fixup
       (putword (iplus2 codebase* (car (first forwardinternalreferences*))) 0 x)
       (setq forwardinternalreferences* (cdr forwardinternalreferences*)))
	      % Now remove the InternalEntry offsets from everyone
   (mapobl 'remove-ieo-property)))

%-----------------------------------------------------------------
%
% Optimize:
%   1.  (prog (a b c d e) :
%    (mov (quote nil) (reg t1)) (mov (reg t1)(frame 1))
%    (mov (quote nil) (reg t1)  (mov (reg t1)(frame 2))
%        ......
%
%   2. (setq a b)(xxx   ... b )
%    (mov (reg 1) (frame 1)) (mov (frame 1) (reg 2))
 
(de LapoptFrame(u)
    (prog (rcode instr op nextinstr src dest x)
       (while u
	(setq instr (pop u))
	(when (and (pairp instr) u)
		(setq op (car instr))
		(setq nextinstr (car u))
		    % pattern:
		    %    (mov (reg n) (frame m))
		    %    (mov (frame m) (reg k))
		(when (and (eq op 'MOV) 
			   (regp (setq src (cadr instr)))
			   (not (sregp src))  % not for segment registers
			   (setq dest (caddr instr))
			   (eqcar nextinstr 'MOV)
			   (equal (cadr nextinstr)dest)
			   (regp (setq x (caddr nextinstr))))
		      (pop u)
		      (push (list 'mov src x) u))
		    % pattern:
		    %      (mov (quote nil) (frame 1))  
		    %      (mov (quote nil) (frame 2)) ...
		(when (and
			(eq op 'mov)
			(immediatep (setq src (cadr instr)))
			(not (regp (caddr instr)))
			(eqcar nextinstr 'mov)
			(equal (cadr nextinstr) src))   % at 2 of that type
		      (setq u (LapoptFrame1 src (push instr u)))
		      (setq instr (list 'mov src '(reg t1))))
		    % pattern: 
		    %      (push (quote nil) )   
		    %      (push (quote nil) ) ... 
		(when (and
			(eq op 'push) 
			(immediatep (setq src (cadr instr))) 
			(or (and 
			       (eqcar nextinstr 'mov) 
			       (equal (cadr nextinstr) src))
			    (and
			       (eqcar nextinstr 'push)
			       (equal (cadr nextinstr) src)))) 
		      (setq u (LapoptFrame1 src (push instr u))) 
		      (setq instr (list 'mov src '(reg t1))))

	)
	(push instr rcode))
       (return (reversip rcode))))
 
(de LapoptFrame1 (src u)
     % here subsequent instructions are modified for source T1
   (cond ((or (null u) (atom (car u))) u)
	 ((and (eq (caar u) 'PUSH) (equal (cadr (car u)) src))
		(cons '(PUSH (reg t1)) (LapoptFrame1 src (cdr u))))
	 ((not (and (eq(caar u) 'MOV) % nor more such instr.
		    (equal (cadar u) src)))
	  u)
	 ((equal (caddr (car u)) '(reg t1))
		(LapoptFrame1 src (cdr u)))
	 (t  (cons
		(list 'mov '(reg t1) (caddr (car u)))
		(LapoptFrame1 src (cdr u))))))

(fluid '(!*optimize-armv6))

(setq *optimize-armv6 t)

(de LapoptPeep(code)
   (when *optimize-armv6 (setq code (LapoptPeepArmv6 code)))
   code)

(de LapoptPeepArmv6(code)
% peephole optimizer for armv6 code
% interchanging instructions for dependencies.
 (let (rcode i1 i2 i3 r rb)
  (while code
   (setq i1 (pop code))
   (when code
     (setq i2 (car code) i3 (if (cdr code) (cadr code)))
    (cond
      % case
      %   (ldm (reg sp) (reglist ... (reg lr)))
      %   (bx (reg lr)) 
      % replace (reg lr) in ldm by (reg pc) and remove bx instruction
     ((and (equal i2 '(bx (reg lr)))
	   (pairp i1)
	   (eq (car i1) 'ldm)
	   (equal (cadr i1) '(reg sp))
	   (member '(reg lr) (caddr i1))
	   )
      (pop code)		% remove bx instruction
      (setq i1 (subst '(reg pc) '(reg lr) i1)))

      % case
      %   something
      %   (mov (reg x) ...)
      %   (yyy ... (displacement (reg x))
      % move (mov (reg x) ...)  one step up if independent
     ((and
       (pairp i1)
       (eqcar i2 'mov)
       (eqcar (setq r (caddr i2)) 'reg)
       (equal r (&indirectbase i3))
       (not (&jumpcontrol i1))
	    % test independence (target i2) and i1
       (not (&smember r i1))
	    % test independence (source i2) and (target i1)
       (setq rb (&regbase (cadr i2)))
       (or (and (eqcar i1 'mov) (not (&smember rb (caddr i1))) )
	   (not (&smember rb i1))
       )
      )

      (pop code)
      (push i1 code)
      (setq i1 i2)
     )) % cond
    )% when
    (push i1 rcode)
   )% while
   (reversip rcode)
)) % let,de

(de &smember(a l)
  (cond ((equal a l) t)
	((atom l) nil)
	((&smember a (car l)) t)
	(t (&smember a (cdr l))) ))

(de &indirectbase(u)
  (cond ((atom u) nil)
	((atom (cdr u)) nil)
	((eq (car u) 'displacement)(cadr u))
	((eq (car u) 'indirect) (cadr u))
	(t (or (&indirectbase (car u))(&indirectbase (cdr u)))) ))

(de &regbase(u)
  % u is an operand of *MOVE. Extract the source base. 
     (cond((or (atom u)(eq (car u) 'quote)) t) 
	  ((eq (car u) 'reg) u)
	  ((or (eq (car u) 'indirect) (eq(car u)'displacement))
	   (cadr u))
	  (t t)))

(de &jumpcontrol(u)
    (or (atom u)
	 (LocalLabelp u)
	(GeneralBranchInstructionP (setq u (car u)))
	(eq u 'call)
	(eq u 'ret)
	(eq u '*entry)  
   ))

(de lapoptprint(l)
   (terpri)
   (prin2t " armv6 tauschen:")
   (mapc l 'prin2t))

%---------------------------------------------------------------------
%  cmacro optimizer
%---------------------------------------------------------------------

(de lapopt1 (u)
    (prog()
	(when (not *lapopt) (return u))
	(setq u (lapopt-move-special-cases u))
	(return u)))

%  Move bodies of if-then-elseif ... sequences  such that at runtime as few
%  jumps as possible are taken.

(fluid '(&cond-cm&))

(setq &cond-cm& 
 '((*jumpeq      . *jumpnoteq)       (*jumpnoteq      . *jumpeq)
   (*jumpwgeq    . *jumpwlessp)      (*jumpwlessp     . *jumpwgeq)
   (*jumpwleq    . *jumpwgreaterp)   (*jumpwgreaterp  . *jumpwleq)
   (*jumptype    . *jumpnottype)     (*jumpnottype    . *jumptype)
   (*jumpintype  . *jumpnotintype)   (*jumpnotintypte . *jumpintype)
   (*jumpeqtag   . *jumpnoteqtag)    (*jumpnoteqtag   . *jumpeqtag)
   (*jumpwgeqtag . *jumpwlessptag)   (*jumpwlessptag  . *jumpwgeqtag)
  % no inverse jumps for
   (*jumpwgreaterptag)
   (*jumpon)
   
))

(de lapopt-move-special-cases(code)
  (let (rcode bcode inst u w lbl lab)
   (while (not (lapopt-bottom code))
    (setq inst (pop code))
     (when 
      (and
       (pairp inst)
       (setq u (atsoc (car inst) &cond-cm&))
       (setq u (cdr u))
       (setq lbl (cadr inst))
       (or (memq lbl code)(member (setq lbl (list '*lbl lbl)) code))
       (setq w (lapopt-move-special-cases1 code lbl))
      )
      (setq lab (list 'label (gensym)))
      (setq bcode (nconc bcode (cons (list '*lbl lab) (car w))))
      (push (cons u (cons lab (cddr inst))) rcode)
      (setq inst nil)
      (setq code (cdr w))
     )
     (when inst (push inst rcode))
    )
  (setq code (nconc (reversip rcode) (nconc bcode code)))
  (when *trlapopt 
	 (prin2t "=== move special cases:")
	 (MAPCAR code 'PRINT))
  code    
)) 

(de lapopt-bottom(u)
 (or (null u) 
     (eqcar (car u) 'fullword)))

(de lapopt-move-special-cases1 (code lbl)
  % Find basic block until lbl which ends by an unconditional jump.
  % Return nil or pair of bblock and rest of code.
  (let (rcode fcode inst op)
   (while code
     (setq inst (pop code))
     (push inst rcode)
     (cond ((or (atom inst) (equal inst lbl)) (setq code nil))
	   ((and (memq (setq op (car inst)) 
		      '(*jump *linke *exit))
		 (cdr code)
		 (equal (car code) lbl)
	    )
	    (setq fcode code) (setq code nil))
	   ((or (eq op '*lbl) (atsoc op &cond-cm&))
	    (setq code nil)
	   )
   ))
   (when fcode (cons (reversip rcode) fcode))
))
