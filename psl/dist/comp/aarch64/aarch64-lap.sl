%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:aarch64-LAP.SL
% Description:  Armv8/A64 PSL Assembler
% Author:       R. Schöpf
% Created:      21 November 2020
% Modified:     December 2020
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
	shift-ops*			% known armv6 shift operations
	comment*                        % optional comment in lap output
%	*cond*
%	*set*
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

(compiletime (load addr2id))

(compiletime
 (put 'getword32 'opencode
      '(
	(LDR (reg w0) (indexed (reg 1) (displacement (reg 2) 0)) ))))
 

% ------------------------------------------------------------
% Constant declarations:
% ------------------------------------------------------------

(DefConst  
	 RELOC_ID_NUMBER 1 
	 RELOC_HALFWORD 2 
	 RELOC_WORD 1 
	 RELOC_INF 3)

(DefConst MaximumPCRelLoadOffset 4096)

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
		 (DepositByte 0) ))
 
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
      (if *writingfaslfile CurrentOffset* (wplus2 CodeBase* CurrentOffset*))))

   % If depositing into memory
   ((not *writingfaslfile) 
    (setq entries* (cons (cons (rest x) CurrentOffset*) entries*)) 
    (unless lapreturnvalue* (setq lapreturnvalue*
		 (wplus2 CodeBase* CurrentOffset*))))

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

(commentoutcode
(de DepositInstruction (X)
% This actually dispatches to the procedures to assemble the instrucitons
(prog (Y)
    (cond ((setq Y (get (first X) 'InstructionDepositFunction))
	   (Apply Y (list X)))
	  ((setq Y (get (first X) 'InstructionDepositMacro))
	   (apply3safe y (cdr x))) 
	  (t (StdError (BldMsg "Unknown ARMv6 instruction %p" X))))))
)

(de DepositLabel (x) nil)

(commentoutcode
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
	     (apply4safe y (cdr x)))
	    (t (StdError (BldMsg "Unknown ARMv6 instruction %p" X))))
      (when (and offs (not (equal CurrentOffset* (plus offs (InstructionLength x)))))
	(StdError (BldMsg "length error with instruction %p: %p"
			  x (difference (difference CurrentOffset* offs)
					(InstructionLength x)))))
      ))

(de DepositLabel (x) 
    (when *testlap (prin2 CurrentOffset*) (tab 10) (print x))
    (when (and *writingfaslfile 
	       (not (equal CurrentOffset* (LabelOffset x)))) 
	  (StdError (BldMsg "wrong address for label %p: difference = %p" 
		       x    (difference CurrentOffset* (LabelOffset x)))))) 
	   

(CompileTime (progn 

(dm DefOpcode (U) 
%
% (DefOpcode name (parameters) pattern)
%
(prog (OpName vars pattern fname) 
    (setq U (rest U)) 
    (setq OpName (pop U))   
    (setq fname (intern (bldmsg "%w.INSTR" OpName)))
    (setq OpName (MkQuote OpName)) 
    (setq vars (pop u)) 
    (setq pattern
      (append u
	`((t (laperr ',OpName  (list .,vars))))))
    (setq pattern (cons 'cond pattern))
    % (setq u `(lambda ,vars ,pattern)) 
    % (return `(put ,OpName 'InstructionDepositMacro ',u))
    (return
      `(progn
	 (de ,fname ,vars ,pattern)
	 (put ,OpName 'InstructionDepositMacro ',fname)))
 ))

(dm DefOpLength (U)
%
% (DefOpLength name (parameters) pattern)
%
(prog (OpName vars pattern fname)
    (setq U (rest U))
    (setq OpName (pop U))   % (quote name)
    (setq fname (intern (bldmsg "%w.LTH" OpName)))
    (setq OpName (MkQuote OpName))   % (quote name)
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
%  additional test functions

(fluid '(sregs))
(setq sregs '(ES CS SS DS FS GS ))

(de RegP (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '( 1  2  3  4  5  6  7  8
                     X0 X1 X2 X3 X4 X5 X6 X7 X8 X9 X10 X11 X12 X13 X14 X15
		     X16 X17 X18 X19 X20 X21 X22 X23 X24 X25 X26 X27 X28 X29 X30
                     W0 W1 W2 W3 W4 W5 W6 W7 W8 W9 W10 W11 W12 W13 W14 W15
		     W16 W17 W18 W19 W20 W21 W22 W23 W24 W25 W26 W27 W28 W29 W30
		     fp lr Xzr Wzr
		     t1 t2 t3
             nil heaplast heaptrapbound symfnc symval
	     bndstkptr bndstklowerbound bndstkupperbound
	     ))))

(de Reg32P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    W0 W1 W2 W3 W4 W5 W6 W7 W8 W9 W10 W11 W12 W13 W14 W15
		     W16 W17 W18 W19 W20 W21 W22 W23 W24 W25 W26 W27 W28 W29 W30
		     Wzr
	     ))))

(de Regfp8P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 B10 B11 B12 B13 B14 B15
		     B16 B17 B18 B19 B20 B21 B22 B23 B24 B25 B26 B27 B28 B29 B30
		     B31
	     ))))

(de Regfp16P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    H0 H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13 H14 H15
		     H16 H17 H18 H19 H20 H21 H22 H23 H24 H25 H26 H27 H28 H29 H30
		     H31
	     ))))

(de Regfp32P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    S0 S1 S2 S3 S4 S5 S6 S7 S8 S9 S10 S11 S12 S13 S14 S15
		     S16 S17 S18 S19 S20 S21 S22 S23 S24 S25 S26 S27 S28 S29 S30
		     S31
	     ))))

(de Regfp64P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 D10 D11 D12 D13 D14 D15
		     D16 D17 D18 D19 D20 D21 D22 D23 D24 D25 D26 D27 D28 D29 D30
		     D31
	     ))))

1(de Regfp128P (RegName) 
    (AND (eqcar Regname 'reg)
	 (MemQ (cadr RegName) 
	       '(    Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 Q8 Q9 Q10 Q11 Q12 Q13 Q14 Q15
		     Q16 Q17 Q18 Q19 Q20 Q21 Q22 Q23 Q24 Q25 Q26 Q27 Q28 Q29 Q30
		     Q31
	     ))))

(de reg-zero-p (RegName)
    (eq (cadr RegName) 'XZr))

(de reg32-zero-p (RegName)
    (eq (cadr RegName) 'Wzr))

(de reg-nonzero-p (RegName)
    (and (regp RegName) (not (reg-zero-p RegName))))

(de reg32-nonzero-p (RegName)
    (and (reg32p RegName) (not (reg32-zero-p RegName))))

(de reg-zero-p (RegName)
    (eq (cadr RegName) 'XZr))

(de reg32-zero-p (RegName)
    (eq (cadr RegName) 'Wzr))

(de reg-sp-p (RegName)
    (eq (cadr RegName) 'sp))

(de reg32-sp-p (RegName)
    (eq (cadr RegName) 'Wsp))

(de reg-or-sp-p (RegName)
    (or (and (regp RegName) (not (reg-zero-p RegName)))
	(reg-sp-p RegName)))

(de reg32-or-sp-p (RegName)
    (or (and (reg32p RegName) (not (reg32-zero-p RegName)))
	(reg32-sp-p RegName)))

(de reg-indirect-p (x)
    (and (eqcar x 'indirect)
    	 (regp (cadr x))))

(de reg-or-sp-simm9-post-p (x)
    (and (eqcar x 'postindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (simm9-p (caddr x))))

(de reg-or-sp-simm9-pre-p (x)
    (and (eqcar x 'preindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (simm9-p (caddr x))))

(de reg-or-sp-simm9-p (x)
    (and (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (simm9-p (caddr x))))

(de simm9-p (displ)
    (and (fixp displ) (greaterp displ -257) (lessp displ 256)))

(de reg-or-sp-imm9-post-p (x)
    (and (eqcar x 'postindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (imm9-p (caddr x))))

(de reg-or-sp-imm9-pre-p (x)
    (and (eqcar x 'preindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (imm9-p (caddr x))))

(de reg-or-sp-imm9-p (x)
    (or (and (eqcar x 'indirect) (pairp (cdr x)) (reg-or-sp-p (cadr x)))
	(and (eqcar x 'displacement)
	     (pairp (cdr x)) (reg-or-sp-p (cadr x))
	     (pairp (cddr x)) (imm9-p (caddr x)))))

(de imm9-p (displ)
    (and (fixp displ) (greaterp displ -257) (lessp displ 253) (eq (land displ 2#11) 0)))

(de reg-or-sp-imm10-post-p (x)
    (and (eqcar x 'postindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (imm10-p (caddr x))))

(de reg-or-sp-imm10-pre-p (x)
    (and (eqcar x 'preindexed)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (imm10-p (caddr x))))

(de reg-or-sp-imm10-p (x)
    (or (and (eqcar x 'indirect) (pairp (cdr x)) (reg-or-sp-p (cadr x)))
	(and (eqcar x 'displacement)
	     (pairp (cdr x)) (reg-or-sp-p (cadr x))
	     (pairp (cddr x)) (imm10-p (caddr x)))))

(de imm10-p (displ)
    (and (fixp displ) (greaterp displ -513) (lessp displ 505) (eq (land displ 2#111) 0)))

(de reg-or-sp-pimm16-p (x)
    (and (eqcar x 'displacement)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (fixp (caddr x)) (eq 0 (land (caddr x) 15))
	 (pimm12-p (lsh (caddr x) -4))
	 ))

(de reg-or-sp-pimm15-p (x)
    (and (eqcar x 'displacement)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (fixp (caddr x)) (eq 0 (land (caddr x) 7))
	 (pimm12-p (lsh (caddr x) -3))
	 ))

(de reg-or-sp-pimm14-p (x)
    (and (eqcar x 'displacement)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (fixp (caddr x)) (eq 0 (land (caddr x) 3))
	 (pimm12-p (lsh (caddr x) -2))
	 ))

(de reg-or-sp-pimm13-p (x)
    (and (eqcar x 'displacement)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (fixp (caddr x)) (eq 0 (land (caddr x) 1))
	 (pimm12-p (lsh (caddr x) -1))
	 ))

(de reg-or-sp-pimm12-p (x)
    (and (eqcar x 'displacement)
	 (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x)) (fixp (caddr x))
	 (pimm12-p (caddr x))
	 ))

(de pimm12-p (displ)
    (and (greaterp displ -1) (lessp displ 2#1000000000000)))

(de EvenRegP (RegName)
    (and (Regp RegName) (evenp (reg2int regname))))
	 
(de reglistp (x)
    (and (pairp x) (regp (car x)) (reglistp1 (cdr x))))

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
     (imm8-rotatedp x)) 

(de imm8-rotatedp (x)
    (and (fixp x)
	 (setq x (wand 16#ffffffff x))
	 (decode-32bit-imm8-rotated x)))

(de imm12-shiftedp (x)
    (or (and (fixp x) (eq x (land x 16#fff)))
	(and (pairp x) (fixp (car x)) (eq (car x) (land (car x) 16#fff))
	     (eqcar (cdr x) 'LSL)
	     (pairp (cddr x)) (memq (caddr x) '(0 12)))))

(de imm-lg-repeated (x)
  (let ((size 64) (mask))
    (while (greaterp size 2)
      (setq size (lsh size -1))
      (setq mask (lsh -1 (minus size)))
      (if (not (eq (land mask x) (land mask (lsh x (minus size)))))
	  (return (lsh size 1)))
      (setq size (lsh size -1)))
    ))

(de imm-logical-p (x)
  (prog (size mask imm tmp zz ones immr Nimms N)
    (if (null (setq size (imm-lg-repeated x)))
        (return nil))
    (setq mask (lsh -1 (difference size 64)))
    (setq imm (land x mask))
    (setq tmp (lor (sub1 imm) imm))
    (if (and (not (eq imm 0)) (eq 0 (land (add1 tmp) tmp)))
	(progn
	  %% count trailing zeros
	  (setq zz 0 tmp imm)
	  (while (and (lessp zz 64) (eq 0 (land tmp 1)))
	    (setq tmp (lsh tmp -1)) (zz (add1 zz))
	    )
	  (if (greaterp zz 63) (return nil))
	  %% now count ones
	  (setq ones 0)
	  (while (eq 1 (land tmp 1))
	    (setq tmp (lsh tmp -1) ones (add1 ones))))
      (progn
	(setq imm (lor imm (lnot mask)))
	(if (eq 0 (lnot imm)) (return nil))
	(setq tmp (lor (sub1 (lnot imm)) (lnot imm)))
	(if (not (eq 0 (land (add1 tmp) tmp))) (return nil))
	(setq zz 64 tmp imm)
	(while (lessp tmp 0)
	  (setq tmp (lsh tmp -1)) (zz (sub1 zz)))
	(setq ones 0 tmp imm)
	(while (eq 1 (land tmp 1))
	  (setq tmp (lsh tmp -1) ones (add1 ones)))
	(setq ones (difference (plus2 (difference 64 zz) ones)
			       (diffference 64 size)))
	))
    (if (greaterp size zz) (return nil))
    (setq immr (land (difference size zz) (sub1 size)))
    (setq Nimms (lsh (lnot (sub1 size)) 1))
    (setq Nimms (lor Nimms (sub1 ones)))
    (setq N (lxor (land (lsh Nimms -6) 1) 1))
    (return (lor (lsh N 12) (lor (lsh immr 6) (land Nimms 16#3f))))
    )
  )

(de five-bit-p (x)
    (and (fixp x) (eq (wand 16#1f x) x)))

(de six-bit-p (x)
    (and (fixp x) (eq (wand 16#3f x) x)))

(de sixteenbit-p (x)
    (and (fixp x) (eq (wand 16#ffff x) x)))

(de nineteenbit-p (x)
    (and (fixp x) (eq (wand 16#7ffff x) x)))

%(de thirtytwobit-p (x)
%    (and (fixp x) (equal (wand 16#ffffffff x) x)))

% possibly shifted register (data movement), one of:
% (reg x)
% (regshifted x LSL/LSR.. amount)    amount is a number or a register
% (regshift-by-reg x LSL/LSR (reg y))

(de reg-shifter-p (x)
    (or (stringp x)
	(and (pairp x) (regp x))
	(and (eqcar x 'regshifted) (or (regp (cadr x)) (regp (list 'reg (cadr x))))
	     (memq (caddr x) '(LSL LSR ASR))
	     (or (fixp (cadddr x)) (regp (cadddr x))
		 (and (null (cadddr x)) (eq (caddr x) 'RRX))))
	)
    )

(de reg32-shifter-p (x)
    (or (stringp x)
	(and (pairp x) (reg32p x))
	(and (eqcar x 'regshifted) (or (reg32p (cadr x)) (reg32p (list 'reg (cadr x))))
	     (memq (caddr x) '(LSL LSR ASR))
	     (or (fixp (cadddr x)) (reg32p (cadddr x))
		 (and (null (cadddr x)) (eq (caddr x) 'RRX))))
	)
    )

(de reg-or-sp-shifter-p (x)
    (and (eqcar x 'indexed)
         (pairp (cdr x)) (reg-or-sp-p (cadr x))
	 (pairp (cddr x))
	 (let ((indx (caddr x)))
	   (or (regp indx)
	       (and (eqcar indx 'regshifted) (or (regp (cadr indx)) (regp (list 'reg (cadr indx)))) (eq 'LSL (caddr indx)))
	       (and (eqcar indx 'regextended) (or (reg32p (cadr indx)) (reg32p (list 'reg (cadr indx)))) (memq (caddr indx) '(SXTW UXTW)))))))

% possibly extended register (data movement), one of:
% (reg x)
% (regshifted x LSL/LSR.. amount)    amount is a number or a register
% (regshift-by-reg x LSL/LSR (reg y))

(de reg-extended-p (x)
    (or (stringp x)
	(and (pairp x) (regp x))
	(and (eqcar x 'extend) (or (regp (cadr x)) (regp (list 'reg (cadr x))))
	     (memq (caddr x) '(UXTB UXTH LSL UXTW UXTX SXTB SXTH SXTW SXTX))
	     (fixp (cadddr x)))

	)
    )

(de reg32-extended-p (x)
    (or (stringp x)
	(and (pairp x) (reg32p x))
	(and (eqcar x 'extend) (or (reg32p (cadr x)) (reg32p (list 'reg (cadr x))))
	     (memq (caddr x) '(UXTB UXTH LSL UXTW UXTX SXTB SXTH SXTW SXTX))
	     (fixp (cadddr x)))

	)
    )

(de reg-offset8-p (x)
    (cond ((stringp x) t)
	  ((atom x) nil)
	  ((eq (car x) 'indirect) (regp (cadr x)))
	  ((and (memq (car x) '(displacement indirect indexed)) (regp (cadr x)))
	   (eight-bit-p (caddr x)))
	  (t nil)))

(de reg-offset12-p (x)
    (cond ((labelp x) t)
	  ((atom x) nil)
	  ((eq (car x) 'indirect) (regp (cadr x)))
	  ((and (memq (car x) '(displacement indirect indexed)) (regp (cadr x)))
	   (twelve-bit-p (caddr x)))

%	  (or
%	    (twelve-bit-p (caddr x))
%	    (reg-shifter-p (cadr x))
%	    (and (pairp (cadr x)) (memq (caadr x) '(plus minus)) (reg-shifter-p (cadr (cadr x))))))
	  (t nil))
    )
	      
(de twelve-bit-p (x)
    (and (fixp x) (lessp x 4096) (greaterp x -4096)))

(de pos-twelve-bit-p (x)
    (and (fixp x) (lessp x 4096) (greaterp x -1)))

(de eight-bit-p (x)
    (and (fixp x) (lessp x 256) (greaterp x -256)))

(de pm-reg-shifter-p (x)
    (and (eqcar x 'displacement indexed)
	 (regp (cadr x))
	 (and (pairp (caddr x)) (memq (car (caddr x)) '(reg regshifted plus minus))))
    )

(de streg-p (x)
    (or (eq x 'cpsr) (eq x 'spsr)))

(de writeback-p (x)
    t)

(de offset19-p (x)
    (or (labelp x)
	(eqcar x 'internalentry)
	(and (or (eqcar x 'immediate) (setq x (cadr x)))
	     (fixp x)
	     (lessp x (add1 16#FFFFC))
	     (greaterp x (sub1 -1048572))
	 )
	)
    )

(de offset26-p (x)
    (or (labelp x)
	(eqcar x 'internalentry)
	(and (or (eqcar x 'immediate) (setq x (cadr x)))
	     (fixp x)
	     (lessp x (add1 16#7FFFFFC))
	     (greaterp x (sub1 -134217728))
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
      (when (atom op2) (return (DepositWordExpression op2)))
    (when (setq OfFn (get (car op2) 'OperandDepositFunction))
	  (return (apply OfFn (list op2))))
    (DepositWordExpression op2)))
    

% Procedures to compute specific OperandRegisterNumber!*
% Each of the cases returns the Addrssing MODE
% and sets OperandRegisterNumber!* as a side effect

(fluid '(numericRegisterNames))

(setq numericRegisterNames [nil X0 X1 X2 X3 X4 X5 X6 X7])

(de reg2int (u)
   % calculate binary number for register
  (prog (r) (setq r u)
      % strip off tag 'reg
   (cond ((eqcar r 'reg)(setq r (cadr r))))
      %convert a LISP-register into a Aarch64 register
   (if (numberp r) (setq r (getv numericRegisterNames r)))
   (setq r (get r 'registercode))
   (if r (return r)
	 (stderror (bldmsg "unknown register %w" u)))))

(loadtime
(deflist '((X0   0) (X1   1) (X2   2) (X3   3) 
	   (X4   4) (X5   5) (X6   6) (X7   7)
	   (X8   8) (X9   9) (X10 10) (X11 11)
	   (X12 12) (X13 13) (X14 14) (X15 15)
	   (X16 16) (X17 17) (X18 18) (X19 19)
	   (X20 20) (X21 21) (X22 22) (X23 23)
	   (X24 24) (X25 25) (X26 26) (X27 27)
	   (X28 28) (X29 29) (X30 30) (Xzr 31)
	   (W0   0) (W1   1) (W2   2) (W3   3) 
	   (W4   4) (W5   5) (W6   6) (W7   7)
	   (W8   8) (W9   9) (W10 10) (W11 11)
	   (W12 12) (W13 13) (W14 14) (W15 15)
	   (W16 16) (W17 17) (W18 18) (W19 19)
	   (W20 20) (W21 21) (W22 22) (W23 23)
	   (W24 24) (W25 25) (W26 26) (W27 27)
	   (W28 28) (W29 29) (W30 30) (Wzr 31)
	   (B0   0) (B1   1) (B2   2) (B3   3) 
	   (B4   4) (B5   5) (B6   6) (B7   7)
	   (B8   8) (B9   9) (B10 10) (B11 11)
	   (B12 12) (B13 13) (B14 14) (B15 15)
	   (B16 16) (B17 17) (B18 18) (B19 19)
	   (B20 20) (B21 21) (B22 22) (B23 23)
	   (B24 24) (B25 25) (B26 26) (B27 27)
	   (B28 28) (B29 29) (B30 30) (B31 31)
	   (H0   0) (H1   1) (H2   2) (H3   3) 
	   (H4   4) (H5   5) (H6   6) (H7   7)
	   (H8   8) (H9   9) (H10 10) (H11 11)
	   (H12 12) (H13 13) (H14 14) (H15 15)
	   (H16 16) (H17 17) (H18 18) (H19 19)
	   (H20 20) (H21 21) (H22 22) (H23 23)
	   (H24 24) (H25 25) (H26 26) (H27 27)
	   (H28 28) (H29 29) (H30 30) (H31 31)
	   (S0   0) (S1   1) (S2   2) (S3   3) 
	   (S4   4) (S5   5) (S6   6) (S7   7)
	   (S8   8) (S9   9) (S10 10) (S11 11)
	   (S12 12) (S13 13) (S14 14) (S15 15)
	   (S16 16) (S17 17) (S18 18) (S19 19)
	   (S20 20) (S21 21) (S22 22) (S23 23)
	   (S24 24) (S25 25) (S26 26) (S27 27)
	   (S28 28) (S29 29) (S30 30) (S31 31)
	   (D0   0) (D1   1) (D2   2) (D3   3) 
	   (D4   4) (D5   5) (D6   6) (D7   7)
	   (D8   8) (D9   9) (D10 10) (D11 11)
	   (D12 12) (D13 13) (D14 14) (D15 15)
	   (D16 16) (D17 17) (D18 18) (D19 19)
	   (D20 20) (D21 21) (D22 22) (D23 23)
	   (D24 24) (D25 25) (D26 26) (D27 27)
	   (D28 28) (D29 29) (D30 30) (D31 31)
	   (Q0   0) (Q1   1) (Q2   2) (Q3   3) 
	   (Q4   4) (Q5   5) (Q6   6) (Q7   7)
	   (Q8   8) (Q9   9) (Q10 10) (Q11 11)
	   (Q12 12) (Q13 13) (Q14 14) (Q15 15)
	   (Q16 16) (Q17 17) (Q18 18) (Q19 19)
	   (Q20 20) (Q21 21) (Q22 22) (Q23 23)
	   (Q24 24) (Q25 25) (Q26 26) (Q27 27)
	   (Q28 28) (Q29 29) (Q30 30) (Q31 31)
	   (T1   9) (T2  10) (T3  11)
	   (fp  29)			% frame pointer for C subroutine calls
	   (sp  31) (st  31)		% LISP stack register
	   (lr  30)			% link register
	   (heaplast 21)
	   (heaptrapbound 22)
	   (symfnc 23)
	   (symval 24)
	   (bndstkptr 25)
	   (bndstklowerbound 26)
	   (bndstkupperbound 27)
	   (nil 28)
	 ) 'registercode)
)
(de bytep(n)
    (when (and (numberp n) (lessp n 128) (greaterp n -128))
	  (wand n 255)))
 
(de halfwordp(n)
    (when (and (numberp n) (lessp n 32768) (greaterp n -32768))
	  (wand n 65535)))

(de unimmediate(u)
    (if (eqcar u 'immediate) (cadr u) u))

%------------------------------------------------------------------------
(de OP-branch-imm (code offset)
    (setq offset (MakeExpressionRelative offset 4))
    (if (not (weq (land offset 2#11) 0))
	(stderror (bldmsg "Invalid immediate branch offset %w" offset))
      (progn
	(setq offset (ashift offset -2))
	(DepositInstructionBytes
	 (lor (lsh (car code) 2) (land (lsh offset -24) 3))
	 (land 16#ff (lshift offset -16))
	 (land 16#ff (lshift offset -8))
	 (land 16#ff offset))
	))
    )

(de lth-branch-imm (code offset) 4)

(de OP-branch-imm19 (code offset)
    (setq offset (MakeExpressionRelative offset 4))
    (if (not (weq (land offset 2#11) 0))
	(stderror (bldmsg "Invalid immediate branch offset %w" offset))
      (progn
	(setq offset (ashift offset -2))
	(DepositInstructionBytes
	 (car code)
	 (land 16#ff (lshift offset -11))
	 (land 16#ff (lshift offset -3))
	 (lor (land 16#ff (lsh offset 5)) (cadr code)))
	))
    )

(de lth-branch-imm19 (code offset) 4)

(de OP-branch-reg (code regm)
    (prog (opcode)
	  (setq opcode (car code)) 
	  (DepositInstructionBytes
	   (lsh opcode -3)
	   (lor (lsh (land opcode 2#111) 5) 2#11111)
	   (lsh (reg2int regm) -3)
	   (lsh (land (reg2int regm) 2#111) 5)
	   )
	)
    )

(de lth-branch-reg (code reg) 4)


(de OP-reg-Xbfm (code regd regn lsb width)
    (prog (opcode)
	  (setq opcode (car code)) 
	  (DepositInstructionBytes
	   (lsh opcode -2)
	   (lor (lsh (land opcode 2#11) 6) lsb)
	   (lor (lsh width 2) (lsh (reg2int regn) -3))
	   (lor (lsh (land (reg2int regn) 2#111) 5) (reg2int regd))
	   )
	)
    )

(de lth-reg-Xbfm (code regd regn lsb width) 4)

(de OP-reg-Xbfx (code regd regn lsb width)
    (OP-reg-Xbfm code regd regn lsb (sub1 (plus2 lsb width)))
    )

(de lth-reg-Xbfx (code regd regn lsb width) 4)

(de OP-reg-Xbfiz (code regd regn lsb width)
    (OP-reg-Xbfm code regd regn (land (minus lsb) (if (reg32p regd) 2#11111 2#111111)) (sub1 width))
    )

(de lth-reg-Xbfiz (code regd regn lsb width) 4)

(de OP-reg-XxtX (code regd regn)
    (OP-reg-Xbfm code regd regn 0 (cadr code))
    )

(de lth-reg-XxtX (code regd regn lsb width) 4)

(de OP-reg-Xsl (code regd regn shift)
    (let ((base (if (reg32p regd) 2#11111 2#111111)))
        (OP-reg-Xbfm code regd regn (land (minus shift) base) (difference base shift))
    ))

(de lth-reg-Xsl (code regd regn lsb width) 4)

(de OP-reg-Xsr (code regd regn shift)
    (let ((base (if (reg32p regd) 2#11111 2#111111)))
        (OP-reg-Xbfm code regd regn shift base)
    ))

(de lth-reg-Xsr (code regd regn lsb width) 4)

(de OP-bfm (code regd regn immr imms)
    (prog (opcode)
	  (setq opcode (car code)) 
	  (DepositInstructionBytes
	   (lsh opcode -2)
	   (lor (lsh (land opcode 2#11) 6) immr)
	   (lor (lsh imms 2) (lsh (reg2int regn) -3))
	   (lor (lsh (land (reg2int regn) 2#111) 5) (reg2int regd))
	   )
	)
   
    )

(de lth-bfm (code regd regn immr imms) 4)

(de OP-bfc (code regd lsb width)
    (OP-bfm code regd (list 'reg (if (reg32p regd) 'Xzr 'Wzr)) (land (minus lsb) (if (reg32p regd) 2#11111 2#111111)) (sub1 width))
    )

(de lth-bfc (code regd lsb width) 4)

(de OP-bfi (code regd regn lsb width)
    (OP-bfm code regd regn (land (minus lsb) (if (reg32p regd) 2#11111 2#111111)) (sub1 width))
    )

(de lth-bfi (code regd regn lsb width) 4)

(de OP-bfxil (code regd regn lsb width)
    (OP-bfm code regd regn lsb (sub1 (plus2 lsb width)))
    )

(de lth-bfxil (code regd regn lsb width) 4)


(de saniere-Sprungziel (l)
    (cond ((atom l) l)
	  ((eqcar l 'IMMEDIATE) (saniere-Sprungziel (cadr l)))
	  ((eqcar l 'LABEL) (saniere-Sprungziel (cadr l)))
	  (T l)))

 
(de rotate-right (n m)
    (lor
     (lsh n (minus m))
     (land 16#ffffffff (lsh n (difference 32 m)))))
		    
(de rotate-left (n m)
    (wor
     (wand 16#ffffffff (wshift n m))
     (wand 16#ffffffff (wshift n (wdifference m 32)))))
		    
(de decode-32bit-imm8-rotated (n)
    (for (from i 0 15 1)
	 (do
	  (if (equal (wand n 255) n)
	      (return (cons i n))
	    (setq n (rotate-left n 2))
	    )
	  )
	 )
    )

(de DepositInstructionBytes (byte1 byte2 byte3 byte4)
%    (printf "Deposit instruction %w at %x -> %x%n"
%	    (wor (wshift byte1 24) (wor (wshift byte2 16) (wor (wshift byte3 8) byte4)))
%	    CurrentOffset* (wplus2 CodeBase* CurrentOffset*))
    (if *big-endian*
	(progn
	  (DepositByte byte1)
	  (DepositByte byte2)
	  (DepositByte byte3)
	  (DepositByte byte4))
      (progn
	(DepositByte byte4)
	(DepositByte byte3)
	(DepositByte byte2)
	(DepositByte byte1)))
%    (printf "Deposited at %x: %x >%x< %x%n"
%	    (wplus2 (wplus2 CodeBase* CurrentOffset*) -4)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -8) 0)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -4) 0)
%	    (getword32 (wplus2 CodeBase* CurrentOffset*) 0)
%	    )
    )

%% Checks
(de OP-reg3 (code reg1 reg2 reg3)
    (DepositInstructionBytes
     (lsh code -3)
     (lor (lsh (land code 7) 5) (reg2int reg3))
     (lsh (reg2int reg2 -3))
     (lor (reg2int reg1) (lsh (land (reg2int reg2) 7) 5))))

(de lth-reg3 (code reg1 reg2 reg3) 4)

%% ChecK!
(de OP-reg-imm12 (code reg1 reg2 imm12-shifted)
    (let ((imm12) (sh) (opcode (car code)))
      (if (or (and (fixp imm12-shifted) (eq imm12-shifted (wand imm12-shifted 16#fff))
		   (setq imm12 imm12-shifted))
	      (and (pairp imm12-shifted) (eq (caddr imm12-shifted) 0)
		   (setq imm12 (caddr imm12-shifted))))
	  (setq sh 0)
	(setq sh 1))
      (DepositInstructionBytes
       (lsh opcode -1)
       (lor (lsh imm12 6) (lor (lsh (land opcode 1) 7) (lsh sh 6)))
       (lor (lsh (land imm12 16#33) 2) (lsh (reg2int reg2) -3))
       (lor (reg2int reg1) (lsh (land (reg2int reg2) 7) 5))
       )))

(de lth-reg-imm12 (code reg1 reg2 imm12-rotated) 4)

%% ToDo
(de OP-reg-logical (code reg1 reg2 imm-logical)
    )

(de lth-reg-logical (code reg1 reg2 imm-logical) 4)

(de OP-reg-regsp (code reg1 reg2)
    (OP-reg-imm12 code reg1 reg2 0)
    )

(de lth-reg-regsp (code reg1 reg2) 4)

(de OP-regsp-reg (code reg1 reg2)
    (OP-reg-imm12 code reg1 reg2 0)
    )

(de lth-regsp-reg (code reg1 reg2) 4)

(de OP-reg-reg (code reg1 reg2)
    (OP-reg-shifter code reg1 (if (reg32p reg1) 'Wzr 'Xzr) reg2)
    )

(de lth-reg-reg (code reg1 reg2) 4)

%% ToDo
(de OP-reg-shifter (code reg1 reg2 reg-shifter)
    (prog (opcode2 shift-op shift-amount reg3)
	  (cond ((regp reg-shifter) (setq reg3 reg-shifter opcode2 0 shift-amount 0))
		((eqcar reg-shifter 'regshifted)
		 (setq reg3 (list 'reg (cadr reg-shifter)) shift-op (caddr reg-shifter))
		 (setq shift-amount (cadddr reg-shifter))
		 (cond ((fixp shift-amount)
			(setq opcode2 (lor (lsh (land shift-amount 1) 3) (subla '((LSL . 2#000) (LSR . 2#010) (ASR . 2#100)) shift-op))))
		       (T (stderror (bldmsg "Invalid operand %w" reg-shifter)))))
		(T (stderror (bldmsg "Invalid operand %w" reg-shifter))))
	  (DepositInstructionBytes
	   (lsh (car code) -3)
	   (lor (reg2int reg3) (lsh opcode2 5))
	   (lor (lsh (reg2int reg2) -3) (lsh shift-amount 2))
	   (lor (reg2int reg1) (lsh (land (reg2int reg2) 7) 5))))
                                                                            
    )

(de lth-reg-shifter (code reg1 reg2 reg-shifter) 4)

(de OP-reg-extended (code reg1 reg2 reg-extended)
    (prog (option reg3 shift-op shift-amount extend-bits)
	  (cond ((regp reg-extended) (setq reg3 (reg2int reg-extended)))
		((eqcar reg-extended 'regextended)
		 (setq reg3 (reg2int (list 'reg (cadr reg-extended)))
		       shift-op (caddr reg-extended))
		 (if (pairp (cdddr reg-extended))
		     (setq shift-amount (cadddr reg-extended))
		   (setq shift-amount 0))
		 (cond ((fixp shift-amount)
			(if (eq shift-op 'LSL)
			    (setq extend-bits (if (reg32p reg1) 2#010 2#011))
			  (setq extend-bits (subla '((UXTB . 2#000) (UXTH . 2#001) (UXTW . 2#010) (LSL . 2#011) (UXTX . 2#011) (SXTB . 2#100) (SXTH . 2#101) (SXTW . 2#110) (SXTX . 2#111)) shift-op)))
			(setq option (lor (lsh (land shift-amount 1) 3) extend-bits)))
		       (T (stderror (bldmsg "Invalid operand %w" reg-extended)))))
		(T (stderror (bldmsg "Invalid operand %w" reg-extended))))
	  (DepositInstructionBytes
	   (lsh code -3)
	   (lor (reg2int reg3) (lsh (land code 3) 5))
	   (lor (lor (lsh (reg2int reg2) -3) (lsh shift-amount 2)) (lsh option 5))
	   (lor (reg2int reg1) (lsh (land (reg2int reg2) 7) 5))))
                                                                            
    )

(de lth-reg-extended (code reg1 reg2 reg-extended) 4)

%% (de OP-regn-imm8 (code regn imm8-rotated)
%%     (prog (cc opcode1 imm8-decoded set-bit)
%% 	  (setq imm8-decoded (decode-32bit-imm8-rotated imm8-rotated))
%% 	  (if (null imm8-decoded)
%% 	      (stderror (bldmsg "Invalid imm8 operand %w" imm8-rotated)))
%% 	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code))
%% 	  (DepositInstructionBytes
%% 	   (lor (lsh cc 4) (lsh opcode1 -3))
%% 	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int regn))
%% 	   (car imm8-decoded)
%% 	   (cdr imm8-decoded)))
%%     )

%% (de lth-regn-imm8 (code regn imm8-rotated) 4)

%% (de OP-regn-shifter (code regn reg-shifter)
%%     (prog (cc opcode1 opcode2 set-bit reg3 reg4 shift-op shift-amount)
%% 	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) shift-amount 0)
%% 	  (cond ((regp reg-shifter) (setq reg3 (reg2int reg-shifter) reg4 0 opcode2 0))
%% 		((eqcar reg-shifter 'regshifted)
%% 		 (setq reg3 (reg2int (cadr reg-shifter)) shift-op (caddr reg-shifter))
%% 		 (if (eq shift-op 'RRX)
%% 		     (setq shift-amount 0)
%% 		   (setq shift-amount (cadddr reg-shifter)))
%% 		 (cond ((and (fixp shift-amount)
%% 			     (greaterp shift-amount -1)
%% 			     (lessp shift-amount 33))
%% 			(setq shift-amount (land 31 shift-amount))
%% 			(setq reg4 (lsh shift-amount -1)
%% 			      opcode2 (lor (lsh (land shift-amount 1) 3) (subla '((LSL . 2#000) (LSR . 2#010) (ASR . 2#100) (ROR . 2#110) (RRX . 2#110)) shift-op))))
%% 		       ((regp shift-amount)
%% 			(setq reg4 (reg2int (cadddr reg-shifter)))
%% 			(setq opcode2 (subla '((LSL . 2#0001) (LSR . 2#0011) (ASR . 2#0101) (ROR 2#0111)) shift-op))
%% 			)
%% 		       (T (stderror (bldmsg "Invalid operand %w" reg-shifter)))))
%% 		(T (stderror (bldmsg "Invalid operand %w" reg-shifter))))
%% 	  (DepositInstructionBytes
%% 	   (lor (lsh cc 4) (lsh opcode1 -3))
%% 	   (lor (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4)) (reg2int regn))
%% 	   reg4
%% 	    (lor (lsh opcode2 4) reg3)))
%%     )

%% (de lth-regn-shifter (code regn reg-shifter) 4)

%% (de OP-regd-imm8 (code regd imm8-rotated)
%%     (prog (cc opcode1 imm8-decoded set-bit)
%% 	  (setq imm8-decoded (decode-32bit-imm8-rotated imm8-rotated))
%% 	  (if (null imm8-decoded)
%% 	      (stderror (bldmsg "Invalid imm8 operand %w" imm8-rotated)))
%% 	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code))
%% 	  (DepositInstructionBytes
%% 	   (lor (lsh cc 4) (lsh opcode1 -3))
%% 	   (lor (lsh (land opcode1 2#111) 5) (lsh set-bit 4))
%% 	   (lor (lsh (reg2int regd) 4) (car imm8-decoded))
%% 	   (cdr imm8-decoded)))
%%     )

%% (de lth-regd-imm8 (code regd imm8-rotated) 4)

(de OP-regd-shifter (code regd reg-shifter)
    (OP-reg-shifter code regd '(reg R0) reg-shifter))

(de lth-regd-shifter (code reg reg-shifter) 4)

(de OP-mov-imm16 (code reg1 imm16)
    (prog (cc opcode1)
	  (setq cc (car code) opcode1 (cadr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -4))
	   (lor (lsh (land opcode1 2#1111) 4) (lsh imm16 -12))
	   (lor (lsh (reg2int reg1) 4) (land 2#1111 (lsh imm16 -8)))
	   (land 16#ff imm16)))
    )

(de lth-mov-imm16 (code reg1 imm16) 4)

(de OP-mul3 (code reg1 reg2 reg3)
    (op-mul4 (car code) reg1 reg2 reg3 (list 'reg (cadr code))))

(de lth-mul3 (code reg1 reg2 reg3) 4)
		       
(de OP-mul4 (code regd regn regm rega)
    (prog (cc opcode1)
	  (setq cc (car code) opcode1 (cadr code))
	  (DepositInstructionBytes
	   (lsh cc -3)
	   (lor (lsh (land cc 7) 5) (reg2int regm))
	   (lor (lsh opcode1 7)
		(lor (lsh (reg2int regn) -3) (lsh (reg2int rega) 2)))
	   (lor (lsh (land (reg2int regn) 7) 5) (reg2int regd)))))

(de lth-mul4 (code reg1 reg2 reg3 reg4) 4)

(de OP-clz (code regd regn)
    (prog (cc opcode1 opcode2 reg3 reg4 shift-op shift-amount set-bit)
	  (setq cc (car code) opcode1 (cadr code) opcode2 (cadddr code))
	  (DepositInstructionBytes
	   (lsh cc -3)
	   (lor opcode1 (lsh (land cc 7) 5))
	   (lor (lsh (reg2int regn) -3) (lsh opcode2 2))
	   (lor (lsh (land (reg2int regn 7) 5) (reg2int regd)))
	  )
    ))

(de lth-clz (code regd regm) 4)

%% ToDo
(de OP-streg (code regd cpsr-or-spsr)
    (prog (cc opcode1 opcode2 reg3 reg4 shift-op shift-amount set-bit r)
	  (cond ((eq cpsr-or-spsr 'cpsr) (setq r 0))
		((eq cpsr-or-spsr 'spsr) (setq r 1))
		(t (stderror (bldmsg "Invalid MRS operand: %w" cpsr-or-spsr))))
	  (setq cc (car code) opcode1 (cadr code) set-bit (caddr code) opcode2 (cadddr code))
	  (DepositInstructionBytes
	   (lor (lsh cc 4) (lsh opcode1 -3))
	   (lor (lsh r 6) 2#01111)
	   (lor (lsh (reg2int regd) 4) 2#0000)
	   (lsh opcode2 4))
	  )
    )

(de lth-streg (code regd regm) 4)


%%  Instruction                                      Lisp expression for second operand
%% LDR Rt,[Rn]                                         (indirect (reg n))
%% LDR Rt,[Rn,+/-offset12words]                        (displacement (reg n) +/-14/15bit-number)
%% LDR Rt,[Rn,Rm]                                      (displacement (reg n) (reg m))
%% LDR Rt,[Rn,Rm, shift, #shift_imm]                   (displacement (reg n) (regshifted <regno> LSL amount))
%% LDR Rt,[Rn,Rm, extend, #shift_imm]                  (displacement (reg n) (regextended <regno> UXTW/SXTW/SXTX amount))
%% LDR Rt,[Rn,+/-offset8]!                             (preindexed (reg n) +/-8bit-number)
%% LDR Rt,[Rn],+/-offset8                              (postindexed (reg n) +/-8bit-number)

(de OP-ld-st (code regt reg-offset)
    (prog (opcode1 s-bit size shift-op shift-amount regn displ offset pre-post ppbits regm byte1 byte2 byte3 lastbyte)
	  (setq opcode1 (car code) shift-amount 0)
	  (if (and
	       (not (labelp reg-offset))
	       (or (not (pairp reg-offset))
	       	   (not (memq (car reg-offset) '(displacement indirect indexed preindexed postindexed)))
		   (not (reg-or-sp-p (cadr reg-offset)))))
	      (stderror (bldmsg "Invalid 1 LDR/STR operand: %w" reg-offset)))
	  (if (labelp reg-offset)	% label --> pc-relative
	      (progn
		(setq byte1 opcode1)
		(setq displ (MakeExpressionRelative reg-offset
						    (if (eq (lsh opcode1 -6) 1) 8 4))))
	    (progn
	      (setq regn (reg2int (cadr reg-offset)))
	      (setq size (lsh opcode1 -9))
	      (setq displ (if (eqcar reg-offset 'indirect) 0 (caddr reg-offset)))
	      ))
	  (cond ((or (labelp reg-offset)
		     (not (memq (car reg-offset) '(indexed indirect displacement preindexed postindexed)))
		     )
		 nil)
		((and (memq (car reg-offset) '(preindexed postindexed))
		      (fixp displ) (lessp displ 256) (greaterp displ -257))
		 (setq pre-post (car reg-offset))
		 (setq ppbits (cadr code))
		 (setq displ (land displ 2#111111111)) % mask to nine bits
		 (setq lastbyte (lor (lsh (land 2#111 regn) 5) (reg2int regt)))
		 (setq byte3 
		       (lor (lsh regn -3)
			    (lor (lsh ppbits 2)
				 (lsh (land displ 2#1111) 4))))
		 (setq byte2
		       (lor (lsh displ -4)
			    (lsh (land opcode1 2#111) 5)))
		 (setq byte1 (lsh opcode1 -3)))
		
		((and (eq (car reg-offset) 'displacement) (fixp displ)
		      (or (and (eq (setq size (lsh opcode1 -8)) 2#10) (eq (land 2#11 displ) 0)
			       (pos-twelve-bit-p (setq displ (lsh displ -2))))
			  (and (eq size 2#11) (eq (land 2#111 displ) 0)
			       (pos-twelve-bit-p (setq displ (lsh displ -3))))))
		 (setq lastbyte (lor (lsh (land 2#111 regn) 5) (reg2int regt)))
		 (setq byte3 
		       (lor (lsh regn -3)
			    (lsh (land displ 2#111111) 2)))
		 (setq byte2
		       (lor (lsh displ -6)
			    (lsh (land opcode1 2#11) 6)))
		 (setq byte1 (lsh opcode1 -2)))
		((and (eq (car reg-offset) 'indirect) (null (cddr reg-offset)))
		 % like previous case with displacement = 0
		 (setq lastbyte (lor (lsh (land 2#111 regn) 5) (reg2int regt)))
		 (setq byte3  (lsh regn -3))
		 (setq byte2 (lsh (land opcode1 2#11) 6))
		 (setq byte1 (lsh opcode1 -2)))
		((or (not (pairp displ))
		     (not (memq (car displ) '(reg regshifted regextended))))
		 (stderror (bldmsg "Invalid 3 LDR/STR operand: %w" reg-offset)))
                % check for (scaled) register offset
		((or (and (eq (car reg-offset) 'indexed) (regp displ))
		     (and (eq (car displ) 'regshifted)
			  (eq (caddr displ) 'LSL))
		     (and (eq (car displ) 'regextended)
			  (memq (caddr displ) '(UXTW SXTW SXTX))))
		 (if (not (or (regp displ) (memq (cadddr displ) (list 0 size))))
		     (stderror (bldmsg "Invalid 4 LDR/STR operand: %w" reg-offset)))
		 (if (regp displ)
		     (progn
		       (setq regm (reg2int displ))
		       (setq shift-op 'LSL)
		       (setq S-bit 0)
		       (setq shift-amount 0))
		   (progn
		     (setq regm (reg2int (list 'reg (cadr displ))))
		     (setq shift-op (if (cddr displ) (caddr displ) 'LSL))
		     (setq S-bit (if (cddr displ) 1 0))
		     (setq shift-amount (cadddr displ))))
		 (setq lastbyte (lor (lsh (land 2#111 regn) 5) (reg2int regt)))
		 (setq byte3 
		       (lor (lsh regn -3)
			    (lor (lsh (cadr code) 2)
				 (lor (lsh S-bit 4)
				      (lsh (subla '((LSL . 2#011) (UXTW . 2#010) (SXTW . 2#110) (SXTX . 2#111)) shift-op) 5)))))
		 (setq byte2
		       (lor (lsh (land opcode1 2#111) 5) regm))
		 (setq byte1 (lsh opcode1 -3)))
		(t (stderror (bldmsg "Invalid 5 LDR/STR operand: %w" reg-offset))))
	  (DepositInstructionBytes
	   byte1
	   byte2
	   byte3
	   lastbyte)
    ))


(de lth-ld-st (code regn reg-offset12) 4)

%% (de OP-ldr-id (code regn idref)
%%     (OP-ld-st code regn idref)
%%     )

%% (de lth-ldr-id (code regn idref) 4)


%% (de OP-ld-st-misc (code regd reg-offset8)
%%     (prog (cc ld-bit opcode1 opcode2 temp shift-op shift-amount regn displ pre-post p-bit u-bit w-bit regm lastnibble)
%% 	  (setq cc (car code) opcode1 (cadr code) ld-bit (caddr code) opcode2 (cadddr code) shift-amount 0)
%% 	  (if (or (not (pairp reg-offset8))
%% 		  (not (memq (car reg-offset8) '(displacement indirect)))
%% 		  (not (regp (cadr reg-offset8))))
%% 	      (stderror (bldmsg "Invalid misc. load/store operand %w" reg-offset8)))
%% 	  (setq regn (reg2int (cadr reg-offset8)))
%% 	  (setq displ (if (eqcar reg-offset8 'indirect) 0 (caddr reg-offset8)))
%% 	  (setq u-bit 1)
%% 	  (cond ((or (eqcar reg-offset8 'indirect)
%% 		     (null (cdddr reg-offset8))) % no pre or post indexed
%% 		 (setq p-bit 1 w-bit 0))
%% 		((memq (cadddr reg-offset8) '(preindexed postindexed))
%% 		 (setq pre-post (cadddr reg-offset8))
%% 		 (setq p-bit (if (eq pre-post 'preindexed) 1 0))
%% 		 (setq w-bit (if (eq pre-post 'preindexed) 1 0)))
%% 		(t (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8))))
%% 	  (cond ((and (fixp displ) (lessp displ 256) (greaterp displ -256))
%% 		 (if (lessp displ 0)
%% 		     (progn
%% 		       (setq u-bit 0)
%% 		       (setq displ (minus displ)))
%% 		   (setq u-bit 1))
%% 		 (setq temp (lsh displ -4))
%% 		 (setq lastnibble (land displ 16#0F)))
%% 		((or (not (pairp displ))
%% 		     (not (memq (car displ) '(reg plus minus))))
%% 		 (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8)))
%% 		((or (regp displ)
%% 		     (and (memq (car displ) '(plus minus))
%% 			  (progn (if (eq (car displ) 'minus) (setq u-bit 0))
%% 				 (regp (setq displ (cadr displ))))))
%% 		 (setq temp 0)
%% 		 (setq lastnibble (reg2int displ)))
%% 		(t (stderror (bldmsg "Invalid misc. load/store operand: %w" reg-offset8))))
%% 	  (DepositInstructionBytes
%% 	   (lor (lor (lsh cc 4) (lsh opcode1 -3)) p-bit)
%% 	   (lor (lor (lsh u-bit 7) (lsh (land opcode1 2#111) 5) ) (lor (lsh w-bit 5) (lor (lsh ld-bit 4) regn)))
%% 	   (lor (lsh (reg2int regd) 4) temp)
%% 	   (lor (lshift opcode2 4) lastnibble)))
%% )

%% (de lth-ld-st-misc (code regn reg-offset8) 4)

(de OP-ldp-stp (code regt1 regt2 reg-or-sp-imm)
    (prog (opcode1 imm regn)
	  (setq opcode1 (car code))
	  (setq regn (reg2int (cadr reg-or-sp-imm)))
	  (if (eq (car reg-or-sp-imm) 'indirect)
	      (setq imm 0)
	    (setq imm (lsh (caddr reg-or-sp-imm) (if (reg32p regt1) -2 -3))))
	  (DepositInstructionBytes
	   (lsh opcode1 -2)
	   (lor (lsh (land opcode1 2#11) 6) (lsh imm -1))
           (lor (lor (lsh (land imm 1) 7) (lsh (reg2int regt2) 2)) (lsh regn -3))
           (lor (reg2int regt1) (lsh (land regn 2#111) 5)))
    ))

(de lth-ldp-stp (code regt1 regt2 reg-or-sp-imm) 4)

(de OP-fcvt (code regd regn)
    (prog (opcode1 opcode2)
	  (setq opcode1 (car code) opcode2 (cadr code))
	  (DepositInstructionBytes
	   (lsh opcode1 -3)
	   (lor (lsh (land opcode1 2#111) 5) opcode2)
	   (lsh (reg2int regn) -3)
           (lor (reg2int regd) (lsh (land (reg2int regn) 2#111) 5)))
    ))

    )

(de lth-fcvt (code regd regn) 4)


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
	       (DepositByte 0))))
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

(de AddLapComment (X)
    (setq comment* (cdr X))
    )

(put 'comment 'InstructionDepositFunction 'AddLapComment)
(put 'samelinecomment 'InstructionDepositFunction 'AddLapComment)

(de DepositLoadAddress (X)
    (prog (src dest rel)
	  (setq src (caddr X) dest (cadr X))
	  (cond ((or (not (or (idp src) (stringp src))) (not (regp dest)))
		 (stderror (bldmsg "Invalid ADRL pseudo-op: %w" X)))
		(t
		 (setq rel (MakeExpressionRelative src 8))
%		 (print (list src dest rel))
		 (cond ((lessp rel 0)
			(setq rel (minus rel))
			(cond ((imm8-rotatedp rel)
			       (DepositInstruction `(SUB ,dest (reg pc) ,rel))
			       (DepositInstruction '(MOV (reg 1) (reg 1))))
			      ((lessp rel 16#10000)
			       (DepositInstruction `(SUB ,dest (reg pc) ,(wand 16#ff rel)))
			       (DepositInstruction `(SUB ,dest ,dest ,(wand 16#ff00 rel))))
			      ((and (eq 0 (wand rel 3)) % divisible by 4
				    (imm8-rotatedp (wand rel 16#fffffc00)))
			       (DepositInstruction `(SUB ,dest (reg pc) ,(wand 16#3ff rel)))
			       (DepositInstruction `(SUB ,dest ,dest ,(wand 16#fffffc00 rel))))
			      ((and (eq 0 (wand rel 7)) % divisible by 8
				    (imm8-rotatedp (wand rel 16#fffff800)))
			       (DepositInstruction `(SUB ,dest (reg pc) ,(wand 16#7ff rel)))
			       (DepositInstruction `(SUB ,dest ,dest ,(wand 16#fffff800 rel))))
			      (t (stderror (bldmsg "ADRL load too far: %w" rel)))))
		       ((imm8-rotatedp rel)
			(DepositInstruction `(ADD ,dest (reg pc) ,rel))
			(DepositInstruction '(MOV (reg 1) (reg 1))))
		       ((lessp rel 16#10000)
			(DepositInstruction `(ADD ,dest (reg pc) ,(wand 16#ff rel)))
			(DepositInstruction `(ADD ,dest ,dest ,(wand 16#ff00 rel))))
		       ((and (eq 0 (wand rel 3)) % divisible by 4
			     (imm8-rotatedp (wand rel 16#fffffc00)))
			(DepositInstruction `(ADD ,dest (reg pc) ,(wand 16#3ff rel)))
			(DepositInstruction `(ADD ,dest ,dest ,(wand 16#fffffc00 rel))))
		       ((and (eq 0 (wand rel 7)) % divisible by 8
			     (imm8-rotatedp (wand rel 16#fffff800)))
			(DepositInstruction `(ADD ,dest (reg pc) ,(wand 16#7ff rel)))
			(DepositInstruction `(ADD ,dest ,dest ,(wand 16#fffff800 rel))))
		       (t (stderror (bldmsg "ADRL load too far: %w" rel)))))
		)))

(put 'ADRL 'InstructionDepositFunction 'DepositLoadAddress)

%(put 'ADR 'InstructionLength 4)
(put 'ADRL 'InstructionLength 8)

(de DepositFarLoadAddress (X)
    (prog (src dest)
	  (setq src (caddr X) dest (cadr X))  
	  (cond ((or (not (or (idp src) (stringp src))) (not (regp dest)))
		 (stderror (bldmsg "Invalid LDR!= pseudo-op: %p" X)))
		(t
		 (DepositLoadAddress `(ADRL ,dest ,src))
		 (DepositInstruction `(LDR ,dest (indirect ,dest)))))))

(put 'LDR!= 'InstructionDepositFunction 'DepositFarLoadAddress)

(put 'LDR!= 'InstructionLength 12)

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


(de MakeInternalentryRelative (nam offsetfromhere)
  (prog (offset)
	(setq offset (atsoc nam LabelOffsets*))
	(setq offset (if offset
		(cdr offset)
		(get nam 'internalentryoffset)))
	(return (if offset
		  (progn
		    (setq offset 
		     (difference offset 
		      (plus2 CurrentOffset* offsetfromhere))))
		  (progn
		    (setq ForwardInternalReferences* 
		     (cons (cons CurrentOffset* nam) 
		      ForwardInternalReferences*))
		    0)))))
	% will be fixed in SystemFasl...


(de LabelOffset (l)
  (let (offset)
    (cond 
     ((codep l) (if *writingfaslfile
		  (inf l)
		  (wdifference (inf l) CodeBase*)))
     ((setq offset  (atsoc l LabelOffsets*)) (cdr offset))
     (t (stderror (bldmsg "Unknown label %r" l)))
     )))



% ------------------------------------------------------------
% Branch analysis (conditional jumps)
% ------------------------------------------------------------

(fluid '(ConditionalJumps*))
(setq ConditionalJumps* 
  '((B!.EQ  . B!.NE)  (B!.NE  . B!.EQ)
    (B!.CS  . B!.CC)  (B!.CC  . B!.CS)
    (B!.MI  . B!.PL)  (B!.PL  . B!.MI)
    (B!.VS  . B!.VC)  (B!.VC  . B!.VS)
    (B!.HI  . B!.LS)  (B!.LS  . B!.HI)
    (B!.GE  . B!.LT)  (B!.LT  . B!.GE)
    (B!.GT  . B!.LE)  (B!.LE  . B!.GT)
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
		(eqcar (car code) 'B)
		(cdr code)
		(equal (cadr code) y))
	     (setq instr (cons (cdr x) (cdr (pop code)))))
	   % replace indirect conditional jumps (not avail on 386)
	(when (and
		(pairp instr)
		(atsoc (car instr) ConditionalJumps*)
		(not (atom (saniere-Sprungziel (cadr instr)))))
	     (setq x (gensym))
	     (push (cons 'B (cdr instr)) bottom)
	     (push x bottom)
	     (setq instr (list (car instr) x))   )
	(push instr rcode))
	(return (nconc (reversip rcode) bottom))))
 
%% ------------------------------------------------------------
%% Branch optimization (in favour of short jumps)
%% ------------------------------------------------------------
%
%(deflist '(
%   (BEQ BEQ) (BNE BNE) (BCS BCS)(BCC BCC)
%   (BMI BMI) (BPL BPL) (BVS BVS)(BVC BVC)
%   (BHI BHI)(BLS BLS)(BGE BGE)(BLT BLT)
%   (BGT BGT)(BLE BLE)(BAL BAL)
%   (B B) (BX BX) (BLX BLX)
%) 'WordBranch)
%
%(de GeneralBranchInstructionP (i) (get i 'WordBranch))

(de GeneralLDRInstructionP (i) (eq i 'LDR))

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
%          and look for LDR instructions where the source memory address outside
%          the $pc+/-4096 range. E.g.
%
%          (LDR (reg xy) "l0123")
%          ...
%          l0123
%          (fullword something)
%
%          where l0123 is more that 4096 away from the LDR instruction.
%
% 1. Approach:
%          Replace this by
%
%          (BL l4567)
%          ...
%          l4567
%          (LDR (reg xy) "l0123")
%          (BX (REG LR))
%          l0123
%          (fullword something)
%
%          since branches have a 26 bit offset.
%          The BL instruction stores the return address into register lr, so that
%          the BX instruction jumps back to the address immediately following.
%
%   Disadvantage: a simple load is replaced by jump-load-jump. 
%
% 2. Approach:
%          Let n be the offset between the original load instruction and the target of the
%          load. (This means that n is a multiple of 4).
%          Replace the original LDR by the LDR!= pseudo instruction:
%
%          (LDR!= (reg xy) "l0123")
%
%          which expands to
%
%          (ADRL (reg xy) "l0123")
%          (LDR (reg xy) (indirect (reg xy)))
%
%          Assuming that n>0, the ADRL pseudo instruction expands in turn
%          to the following pair of instructions:
%
%          (ADD (reg xy) (reg pc) n1)
%          (ADD (reg xy) (reg xy) n2)
%
%          with n1 = (n & 0x3ff) and n2 = (n & 0x3fc00), provided that n is an 18bit offset, i.e. +/-256kB.
%
%          For negative n, replace n by (-n) and ADD by SUB. See the definition of the ADRL
%          pseudo instruction below for more information.
%%
% Returns: a new code list

(commentoutcode
 %% 1. Approach: commented out
(de OptimizeBranches (u)
(prog (BranchAndLabelAList* InstructionChanged*) 
    (setq BranchCodeList* u)
    (BuildOffsetTable)                  % find branches, labels, and entries
    (setq InstructionChanged* nil)
    (setq InstructionChanged* (FindFarLoads))
    (while InstructionChanged*
      (setq BranchCodeList* (UpdateCodeList BranchCodeList* InstructionChanged*))
      (BuildOffsetTable)
      (setq InstructionChanged* (FindFarLoads)))
    (setq LabelOffsets* (DeleteAllButLabels BranchAndLabelAList*)) 
    (return BranchCodeList*)))

(de UpdateCodeList (codelist alist)
    %% alist contains pairs (lbl . instrlist)
    %% instrlist is to be inserted immediately before lbl
    (prog (l l1 pp)
      (printf "start: %p %p %n" (car alist) (caar alist))
      (setq l codelist)
     loop
      (setq l1 (cdr l))
      (when (null l1) (return codelist))
      (printf "Trying %p:" (first (rest l)))
      (setq pp (assoc (first (rest l)) alist))
      (cond ((null pp))			% nothing to do - advance
	    (t				% found - splice in the new code
	     (printf " --> %p" (cdr pp))
	     (nconc (cdr pp) l1)
	     (rplacd l (cdr pp))))
      (terpri)
      (setq l l1)
      (go loop)))

)

(de OptimizeBranches (u) 
(prog (BranchAndLabelAList* InstructionChanged* q w) 
    (setq BranchCodeList* u)
    (BuildOffsetTable)                  % find branches, labels, and entries
    (setq InstructionChanged* nil)
    (FindFarLoads)
    (while InstructionChanged*
         (BuildOffsetTable)    
	 (setq InstructionChanged* nil) 
	 (FindFarLoads)) 
    (setq LabelOffsets* (DeleteAllButLabels BranchAndLabelAList*)) 
    (return BranchCodeList*)))

%% (de &make-nop(n)
%%    % make n bytes of nop instructions
%%    (cond ((wleq n 0) nil)
%% 	 ((eq n 1)'((inc (reg t2))))
%% 	 ((eq n 2)'((mov (reg t1)(reg t1))))
%% 	 ((eq n 3)'((lea (displacement(reg t1)0) (reg t1))))
%% 	 (t (append (&make-nop 3)(&make-nop (difference n 3)))) ))

%% (de &make-nop(n))

%% (de alignCode(u)
%%   (if (&smember 'fastapply u) u (alignCode1 u)))

%% (de alignCode1(u)
%%    (let(rcode w (a CurrentOffset*) l x y z q s nops)
%%      (while u
%%        (setq w (pop u))
%%        (setq nops 0)
%%        (cond 

%% 	 % initial start: sync. entry point
%% 	   ((null rcode)
%% 	     (setq x a)
%% 	     (setq y u q w)
%% 	     (setq s (eqcar w '*entry))
%% 	     (while y
%% 		 (when (pairp q)(setq x (iplus2 x (instructionlength q))))
%% 		 (if (eqcar q '*entry) (setq y nil) (setq q (pop y))))
%% 	     (setq x (wand x 15))
%% 	     (when (not (eq x 0)) (setq nops (idifference 16 x)))
%% 	    )
 
%% 	% entry: executable code starts
%% 	    ((eqcar w '*entry)(setq s t))
	    
%% 	% fullword: executable code terminated
%% 	    ((eqcar w 'fullword)(setq s nil)) 

%%         % label under *align16
%% 	   ((and s (atom w) *align16)
%% 	      % next instruction should begin on cache line
%% 	     (setq x (wand a 15))   
%% 	     (when (not (eq x 0)) 
%% 		   (setq nops(wdifference 16 x))))

%% 	% label in standard mode
%% 	   ((and s (atom w) u (pairp (car u))) 
%% 	      % next instruction should not split cache lines
%% 	    (setq x (iplus2 (wand a 15) (instructionlength (car u))))
%% 	    (when (not (igreaterp x 16))
%% 		  (setq nops (idifference 16 (wand a 15))))
%% 	   )
	       
%%        % call under *align16
%% 	   ((and *align16 (eqcar w 'call))  
%% 	      % put call exactly at the end of cache line
%% 	    (setq x (wand (iplus2 a (instructionlength w)) 15))
%% 	    (when (not (eq x 0)) (setq nops (idifference 16 x)))
%% 	   )

%% 	% call 
%% 	   ((and (eqcar w 'call) u (pairp (car u)))  
%% 	      % following instruction should not split over cache line
%% 	    (setq x (wand (iplus2 a (instructionlength w)) 15))
%% 	    (when (igreaterp (iplus2 x (instructionlength (car u)))16)
%% 		  (setq nops (idifference 16 x)))
%% 	   )
%% 	 )   
%%        (when (and (igreaterp nops 0) 
%% 		  (ilessp nops 9))  % not too many
%% 	     (foreach q in (&make-nop nops) do (push q rcode))
%% 	     (setq a (iplus2 a nops)))
%%        (when (pairp w)(setq a (iplus2 a (InstructionLength w))))
%%        (push w rcode)
%%       )
%%       (while rcode
%% 	 (when (not (eq (setq w (pop rcode)) '!%temp-label))
%% 	       (push w u)))
%%     u      
%% ))

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
     %   LDR instrs        ( (opcode dest label) . CurrentOffset)
% otherwise, the CurrentOffset is advanced by the length of the instruction

(de BuildInitCodeOffsetTable (CodeList) 
(prog (AList Instr) 
    (setq CodeSize* CurrentOffset*) 
    (foreach X in CodeList do 
   (progn (cond ((LabelP X) 
	  (setq AList (cons (cons X CodeSize*) AList))) 
   ((equal (setq Instr (first X)) '*entry) 
	  (setq AList (cons (cons (second X) CodeSize*) AList))) 
   ((and (GeneralLDRInstructionP Instr) (LocalLabelp (third X)))
           (setq AList (cons (cons X CodeSize*) AList)))
		
   (t (setq CodeSize* (plus CodeSize* (InstructionLength X)))))))
    

    (setq BranchAndLabelAList* (ReversIP AList))
    (return CodeList)))


%  BuildOffsetTable();
% Purpose: generate a association list of labels, procedure entries
% The Alist has the form:
     %   labels:           ( label . CurrentOffset)
     %   procedures:       ( procedurename . CurrentOffset)
     %   branch instrs     ( (opcode label) . CurrentOffset)
     %   LDR instrs        ( (opcode dest label) . CurrentOffset)

(de BuildOffsetTable nil 
 (prog (AList Instr) 
  (setq CodeSize* CurrentOffset*) 
  (foreach X in BranchCodeList* do 
   (progn 
     (cond ((LabelP X) (setq AList (cons (cons X CodeSize*) AList))) 
	   ((equal (setq Instr (first X)) '*entry) 
	    (setq AList (cons (cons (second X) CodeSize*) AList))) 
	       % branch: enter the address of the following instruction
	   ((and (GeneralLDRInstructionP Instr) (LocalLabelp (third X))) 
	    (setq CodeSize* (plus CodeSize* (InstructionLength X))) 
	    (setq AList (cons (cons X CodeSize*) AList)))
	   (t (setq CodeSize* (plus CodeSize* (InstructionLength X)))))))
  (setq BranchAndLabelAList* (ReversIP AList)) 
  (setq InstructionChanged* BranchAndLabelAList*)
  (return BranchAndLabelAList*) ))


(commentoutcode
 %% 1. Approach: commented out

(de FindFarLoads nil
 (prog (CurrentDisplacement ResultList newcode x y)
  (foreach entry on BranchAndLabelAList* do 
    (cond ((not (LabelP (car (first entry)))) 
      (progn 
	(setq CurrentDisplacement (FindDisplacement (first entry)))
	(cond 
	 ((or (GreaterP CurrentDisplacement (const MaximumPCRelLoadOffset))
	      (Lessp CurrentDisplacement (minus (const MaximumPCRelLoadOffset))))

	  (setq newcode (MakeFarLoad (car entry) ResultList))
%	  (printf "BranchCodeList is %w%n" BranchCodeList*)
	  (cond (newcode
		 %% make sure that the label of th edata itme occurs only once
		 %% by collecting code for the same data item
		 (setq x ResultList)
		 (setq ResultList (cons newcode ResultList))
		 (while x
		   (cond ((equal (second newcode) (second (first x)))
			  %% found, collect instructions
			  (nconc (first x) (cddr newcode))
			  (printf "Appended %p to %p%n" (cddr newcode) (first x))
			  %% pop ResultList
			  (setq ResultList (cdr ResultList))
			  (setq x nil))
			 (t (setq x (cdr x))))
		 )))))))))
  %% inline version of reversip with using cdr of each element
  (while (pairp ResultList)
    (setq x (cdr ResultList))
    (rplaca ResultList (cdar ResultList))
    (setq y (rplacd ResultList y))
    (setq ResultList x))
  (return y))
  )

(de MakeFarLoad (instpair ResultList)
(prog (Instruction Result OppositeBranch n oldopcode olddest oldlabel newlabel found) 
      (setq Instruction (car instpair))
      (setq oldopcode (first Instruction))
      (setq olddest (second Instruction))
      (setq oldlabel (third Instruction))
      %% Check whether a far load for this instruction was already generated
      (setq found (assoc Instruction ResultList))
      (cond ((null found)
	     (setq newlabel (gensym)))
	    (t
	     (setq newlabel (caddr found))))
      (printf "Replacing %w " Instruction)
      (Rplaca Instruction 'BL)
      (Rplacd Instruction (list newlabel))
      (printf " by %w%n " Instruction)
      (cond (found (return nil)))
      (return `(,(list oldopcode olddest oldlabel)
		,oldlabel
		    %% These are the instructions to be inserted immediately before
		    %% the label oldlabel
		.,(list newlabel
			(list oldopcode olddest oldlabel)
			(list 'BX (list 'REG 'LR)))
		))))

)

(de FindFarLoads nil 
 (prog (CurrentDisplacement) 
  (foreach entry on BranchAndLabelAList* do 
    (cond ((not (LabelP (car (first entry)))) 
      (progn 
	(setq CurrentDisplacement (FindDisplacement (first entry))) 
	(cond 
	 ((or (GreaterP CurrentDisplacement (const MaximumPCRelLoadOffset))
	      (Lessp CurrentDisplacement (minus (const MaximumPCRelLoadOffset))))
	  %% PC-relative offset is beyond the 12 bit limit +/-4096
	  (progn (setq InstructionChanged* t) 
	      (IncreaseAllOffsets entry (MakeFarLoad entry)))))))))))

(de MakeFarLoad (AList)
    %% AList if the rest of BranchAndLabelAList*,
    %% starting with the far load to be replaced
  (prog (InstructionList Result n) 
    (setq InstructionList (car (first AList))) 
    (setq n (instructionlength InstructionList))
    (Rplaca InstructionList 'LDR!=) 	% Address load pseudo instruction
    (setq n (difference (instructionlength InstructionList) n))
    (cond ((cdr AList) (Rplacw AList (cdr AList)))
	  (t (Rplacw AList (list (cons '~DummyLabel~ 0))))) 
    (return n))) % increased length of subsequent code



(de FindDisplacement (InstructionOffsetPair) 
    (Abs (Difference (cdr InstructionOffsetPair) 
		    (FindLabelOffset (third (first InstructionOffsetPair))))))

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

(de IncreaseAllOffsets (X N) 
    (foreach Y in X do (Rplacd Y (plus (cdr Y) N))) 
    (setq CodeSize* (plus CodeSize* N)))

% ------------------------------------------------------------
% Procedures to compute instruction lengths
% ------------------------------------------------------------

(de InstructionLength (X)
   (prog (Y) 
       (when (setq Y (get (car x) 'InstructionLengthFunction))
	     (return (apply4safe y (cdr x))))
       (when (setq Y (get (car x) 'INSTRUCTIONLENGTH))
	 (return (if (numberp y) y (apply y (list x)))))
       (return 4)))
%       (stderror (bldmsg "*** Unknown Aarchv6 instruction:%w " x))))

(de apply2safe(y x) % ensure that plly has two parameters at least
     (cond ((null x) (apply y (list nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil)))
	   (t (apply y (list (car x)(cadr x))))))

(de apply3safe(y x) % ensure that plly has three parameters at least
     (cond ((null x) (apply y (list nil nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil nil)))
	   ((null (cddr x)) (apply y (list (car x) (cadr x) nil)))
	   (t (apply y (list (car x)(cadr x)(caddr x))))))

(de apply4safe(y x) % ensure that plly has four parameters at least
     (cond ((null x) (apply y (list nil nil nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil nil nil)))
	   ((null (cddr x)) (apply y (list (car x) (cadr x) nil nil)))
	   ((null (cdddr x)) (apply y (list (car x) (cadr x) (caddr x) nil)))
	   (t (apply y (list (car x)(cadr x)(caddr x)(cadddr x))))))

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
(put 'comment 'InstructionLength 0)
(put 'samelinecomment 'InstructionLength 0)

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
  (putword (wplus2 CodeBase* CurrentOffset*) 0 x)
  (updatebittable 4 0)
  (setq CurrentOffset* (plus CurrentOffset* 4)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (putword (wplus2 CodeBase* CurrentOffset*)
	   0 
	   (iplus2 offset (if *writingfaslfile 0 CodeBase*)))
  (updatebittable 4 (const reloc_word))
  (setq CurrentOffset* (plus CurrentOffset* 4)))

(de DepositWordExpression (x)
  % Only limited expressions now handled
  (let (y)
%    (printf "Deposit %w at %x -> %x%n" x CurrentOffset* (wplus2 CodeBase* CurrentOffset*))
    (cond
      ((fixp x) (depositword (int2sys x)))
      ((labelp x) (deposit-relocated-word (LabelOffset x)))
      ((equal (first x) 'internalentry) 
       (let ((offset (get (second x) 'internalentryoffset)))
	 (if offset
	     (deposit-relocated-word offset)
	     (progn
	       (setq ForwardInternalReferences*
		     (cons (cons CurrentOffset* (second x))
			   ForwardInternalReferences*))
	       (deposit-relocated-word 0)))))
      ((and (eq (car x) 'mkitem)
	    (eq (cadr x) id-tag)
	    (eqcar (setq y (caddr x)) 'idloc)
	    (wlessp (id2int (cadr y)) 257))
	(depositword (cadr y)))
      ((equal (first x) 'idloc) (depositwordidnumber (second x)))
      ((equal (first x) 'mkitem) (DepositItem (second x) (third x)))
      ((equal (first x) 'entry) (DepositEntry x))
      ((memq (first x) '(fluid global $fluid $global)) (DepositValueCellLocation (second x)))
      ((setq y (wconstevaluable x)) (DepositWord (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))
%    (printf "Deposited at %x: %x >%x< %x%n"
%	    (wplus2 (wplus2 CodeBase* CurrentOffset*) -4)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -8) 0)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -4) 0)
%	    (getword32 (wplus2 CodeBase* CurrentOffset*) 0)
%	    )
    ))

(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 256)) 
     (depositword (idinf X)))
    (t
      (putword (wplus2 CodeBase* CurrentOffset*) 0 
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
    
    (progn (puthalfword (wplus2 CodeBase* CurrentOffset*) 0 
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
  (prog (x wrd)
%     (printf "%nForwardInternalReferences: %w%n" ForwardInternalReferences*)
     % THIS VERSION ASSUMES 32 bit RELATIVE ADDESSES, HM.
     (setq x (remainder CurrentOffset* 16))
     (while (greaterp x 0) (DepositByte 0) (setq x (sub1 x)))
     (while ForwardInternalReferences*
       (setq x (get (cdr (first ForwardInternalReferences*)) 
		    'internalentryoffset))
%       (printf "Fix Forward ref at %d to %d%n" (car (first ForwardInternalReferences*)) x)
       (when (null x) 
	      (errorprintf "***** %r not defined in this module, call incorrect" 
			   (cdr (first ForwardInternalReferences*))))
       % calculate the offset
       % offset is actual offset -8
       (setq x (plus -8             % offset of PC in branch instruction
	     (difference x (car (first ForwardInternalReferences*)))))
       (setq x (wshift x -2))		% offset is in words, not bytes
       % insert the fixup into the lower 24 bits, upper 8 bits are condition bits and opcode
       (setq wrd (wgetv (iplus2 CodeBase* (car (first ForwardInternalReferences*))) 0))
       (putword (iplus2 CodeBase* (car (first ForwardInternalReferences*)))
		0
		(wor (wand wrd 16#ff000000) (wand x 16#00ffffff)))
       (setq ForwardInternalReferences* (cdr ForwardInternalReferences*)))
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
		    %    (str (reg n) (frame m))
		    %    (ldr (reg k) (frame m))
		(when (and (eq op 'STR) 
			   (regp (setq src (cadr instr)))
			   (setq dest (caddr instr))
			   (eqcar nextinstr 'LDR)
			   (equal (caddr nextinstr) dest)
			   (regp (setq x (cadr nextinstr))))
		      (pop u)
		      (push (list 'mov x src) u))
		    % pattern:
		    %    (sub (reg st) (reg st) 4)
		    %    (str (reg k) (indirect (reg st))) a.k.a. (frame 1)) 
		    % replace by (str (reg k) (displacement (reg st) -4 preindexed))
		(when (and (eq op 'SUB)
			   (equal (cadr instr) '(reg st))
			   (equal (caddr instr) '(reg st))
			   (equal (cadddr instr) '4)
			   (null (cddddr instr))
			   (eqcar nextinstr 'STR)
			   (regp (cadr nextinstr))
			   (equal (caddr nextinstr) '(indirect (reg st))))
		      (pop u)
		      (setq instr `(STR ,(cadr nextinstr) (displacement (reg st) -4 preindexed))))
		    % pattern:
		    %    (sub (reg st) (reg st) <multiple-of-4>)
		    %    (str (reg k) (displacement (reg st) n)) a.k.a. (frame ..)) 
                    % if n = <multiple-of-4>-4
		    % replace by 
                    %    (str (reg k) (displacement (reg st) -4 preindexed))
                    %    (sub (reg st) (reg st) <multiple-of-4>-4)
		(when (and (eq op 'SUB)
			   (equal (cadr instr) '(reg st))
			   (equal (caddr instr) '(reg st))
			   (fixp (cadddr instr))
			   (equal (cadddr instr) (wshift (wshift (cadddr instr) -2) 2)) % multiple of 4
			   (null (cddddr instr))
			   (eqcar nextinstr 'STR)
			   (regp (setq src (cadr nextinstr)))
			   (pairp (setq dest (caddr nextinstr)))
			   (eq (car dest) 'displacement)
			   (equal (cadr dest) '(reg st))
			   (fixp (setq x (caddr dest)))
			   (equal (difference (cadddr instr) x) 4))
%		      (print (list 'lapopt-before (car u) instr))
		      (pop u)
		      (push `(SUB (reg st) (reg st) ,x) u)
		      (setq instr `(STR ,src (displacement (reg st) -4 preindexed)))
%		      (print (list 'lapopt-after (car u) instr))
		      )
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

(fluid '(!*optimize-aarch64))

(setq *optimize-aarch64 t)

(de LapoptPeep(code)
   (when *optimize-aarch64 (setq code (LapoptPeepAarch64 code)))
   code)


%% Reminders:
%% 1) optimize (LDR (reg n) (addr)) followed by (LDR/STR (reg m) (addr))
%%    [tostringwritechar]
%%
%%(*wplus2 (memory ($fluid tokenbuffer) (wconst 0)) (wconst 1))
%%        (ldr (reg t2) (idloc tokenbuffer))
%%        (ldr (reg t1) (displacement (reg symval) (regshifted t2 lsl 2)))
%%        (ldr (reg t2) (idloc tokenbuffer))
%%        (ldr (reg t2) (displacement (reg symval) (regshifted t2 lsl 2)))
%%        (ldr (reg t3) (indirect (reg t2)))
%%        (add (reg t3) (reg t3) 1)
%%        (str (reg t3) (indirect (reg t1)))
%%
%%(*move (memory ($fluid tokenbuffer) (wconst 0)) (reg 2))
%%        (ldr (reg t2) (idloc tokenbuffer))
%%        (ldr (reg t1) (displacement (reg symval) (regshifted t2 lsl 2)))
%%        (ldr (reg 2) (indirect (reg t1)))
%%
%% 2) optimize (mov (reg n) (reg m)) (lsl (reg n) 3)
%%         --> (mov (reg n) (regshifted m LSL 3)) [from wgetv]
%% 3) optimize (add (reg n) (reg n) (reg m)) (ldr (reg k) (indirect (reg n))
%%         --> (ldr (reg k) (indexed (reg n) (reg m))) [from wgetv]

(de LapoptPeepAarch64 (code)
% peephole optimizer for aarch6 code
% interchanging instructions for dependencies.
 (let (rcode i1 i2 i3 r rb)
  (while code
   (setq i1 (pop code))
   (when code
     (setq i2 (car code) i3 (if (cdr code) (cadr code)))
    (cond
      % case
      %   (add/sub (reg n) ... ))
      %   (cmp (reg n) 0)
      % replace add/sub by adds/subs and remove cmp instruction
     ((and (eqcar i2 'cmp) (eq (caddr i2) 0)
	   (pairp i1)
	   (memq (car i1) '(add sub))
	   (equal (cadr i1) (cadr i2))
	   )
      (pop code)		% remove cmp instruction
      (setq i1 (sublis '((adc . adcs)
      	                 (add . adds)
			 (sub . subs)
			 (sbc . sbcs)
			 (neg . negs)
			 (ngc . ngcs)
			 (and . ands)
			 (bic . bics))
		       i1)))

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
	((eq (car u) 'displacement) (cadr u))
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
   (*jumpintype  . *jumpnotintype)   (*jumpnotintype  . *jumpintype)
  % no inverse jumps for
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

(dskin "aarch64-inst.dat")
