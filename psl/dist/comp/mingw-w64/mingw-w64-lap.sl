%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:386-LAP.SL
% Description:  Intel i386/i486 PSL Assembler
% Author:       H. Melenk
% Created:      1-August 1989
% Modified:
% Mode:         Lisp
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions
% 28-Apr-92 (Herbert Melenk)
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
))

(setq *lapopt t)

(fluid '(*immediatequote))
(setq *immediatequote nil)
(fluid '(*testlap))                     % diagnostic output from LAP  MK

(ds LabelP (X) (atom X))

(setq *PWrds t)                         % By default show where the code is
					% put in memory

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
	  (while (not (eq (wshift (wshift currentOffset* -3) 3) currentOffset*))
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

    (return (MkCODE LapReturnValue*)))) % How does this point at the code?
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
      (if *writingfaslfile currentoffset* (wplus2 codebase* currentoffset*))))

   % If depositing into memory
   ((not *writingfaslfile) 
    (setq entries* (cons (cons (rest x) currentoffset*) entries*)) 
    (unless lapreturnvalue* (setq lapreturnvalue*
		 (wplus2 codebase* currentoffset*))))

   % if X = ( _____ !*!*Fasl!*!*InitCode!*!* ... )
   ((equal (second x) '**fasl**initcode**) 
    (setq initoffset* currentoffset*))

   % if X is an InternalFunction
   ((flagp (second x) 'internalfunction) 
    (put (second x) 'internalentryoffset currentoffset*))

   (t (progn
       (put (second x) 'internalentryoffset currentoffset*) % MK
       (findidnumber (second x))
       (dfprintfasl (list 'putentry (mkquote (second x)) 
			  (mkquote (third x)) currentoffset*))))))
     

% DefineEntries()
% Purpose: Defines each of the procedures named in the list Entries!*
%          by putting the code pointer into the function cells

(de DefineEntries nil 
    (foreach X in Entries* do 
	(PutD (first (car X)) (second (car X))
		 (MkCODE (wplus2 CodeBase* (cdr X))))))

%(de DepositInstruction (X)
%% This actually dispatches to the procedures to assemble the instrucitons
%(prog (Y)
%    (if (eqcar x 'movq)  (progn (Depositbyte  16#48)  % REX Prefix
%				(rplaca x 'mov))
%    (when (reg64bitp x) (Depositbyte  16#48)))  % REX Prefix
%    (cond ((setq Y (get (first X) 'InstructionDepositFunction))
%	   (Apply Y (list X)))
%	  ((setq Y (get (first X) 'InstructionDepositMacro))
%	   (apply2safe y (cdr x)))
%	  (t (StdError (BldMsg "Unknown mingw-w64 instruction %p" X))))))


(de DepositLabel (x) nil)
	  
(fluid '(*testlap REX-Prefix))
(de DepositInstruction (X) 
% This actually dispatches to the procedures to assemble the instrucitons
% version with address calculation test
(prog (Y offs allowextrarexprefix REX?) 

    (when *testlap (prin2 currentoffset*) (tab 10) (print x))
    (setq allowextrarexprefix 0)
    (setq REX-Prefix 16#48)
    (when *writingfaslfile (setq offs currentoffset*))
    (cond ((eqcar x 'movq) (Depositbyte  16#48)  % REX Prefix
			  (SETQ REX? (plus codebase!* currentoffset* -1))
			  (setq allowextrarexprefix 0)
                          (rplaca x 'mov))
          ((eqcar x 'addq) (Depositbyte  16#48)  % REX Prefix
			  (SETQ REX? (plus codebase!* currentoffset* -1))
			  (setq allowextrarexprefix 0)
                          (rplaca x 'add))
          ((eqcar x 'subq) (Depositbyte  16#48)  % REX Prefix
			  (SETQ REX? (plus codebase!* currentoffset* -1))
			  (setq allowextrarexprefix 0)
                          (rplaca x 'sub))
          ((reg64bitp x) (Depositbyte  16#48)    % REX Prefix
			 (SETQ REX? (plus codebase!* currentoffset* -1))))
    (cond ((setq Y (get (first X) 'InstructionDepositFunction)) 
	   (Apply Y (list X))) 
	  ((setq Y (get (first X) 'InstructionDepositMacro))
	   (apply2safe y (cdr x))) 
	  (t (StdError (BldMsg "Unknown mingw-w64 instruction %p" X))))
    (when REX? (putbyte REX? 0 REX-Prefix)) %overwrite REX-Prefix

    (when (and (not (eq 0 allowextrarexprefix))
               offs (not (equal currentoffset*
			 (plus allowextrarexprefix offs
				 (instructionlength x)))))
	  (StdError (BldMsg "length error with instruction %p: %p"
		  x (difference (difference currentoffset* offs)
				(instructionlength x)))))
))

(de DepositLabel (x) 
    (when *testlap (prin2 currentoffset*) (tab 10) (print x))
    (when (and *writingfaslfile 
	       (not (equal currentoffset* (LabelOffset x)))) 
	  (StdError (BldMsg "wrong address for label %p: difference = %p" 
		       x    (difference currentoffset* (LabelOffset x)))))) 
	   

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
%    getting the instructions in 
  
( dskin "$pxc/mingw-w64-inst.dat")

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  additional test functions

(fluid '(sregs))
(setq sregs '(ES CS SS DS FS GS ))

(de sregp(x)
  % test for a segment register
  (and (eqcar x 'reg)
       (memq (cadr x) sregs)))

(de eaxp(x)
  (and (eqcar x 'reg)
       (setq x (cadr x))
       (or (eq x 'EAX) (eq x 1))))

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%  Instruction deposit functions
 

(de laperr(inst par)
   (StdError (BldMsg "Illegal format: (%p %p)" inst par)))

(de modR/M (op1 op2) 
% The modR/M byte is built from two operands.
% op1 is always a register (or an absolute code), op2
% a register or a memory reference 
(prog (OpFn mode base ireg n) 

    (when (regp op1) (setq op1 (lsh (reg2int op1 'REXR) 3)))
    (when (pairp op2) (setq mode (car op2)))

      % case: reg - reg
    (when (regp op2) 
	  (depositbyte (lor 2#11000000 (lor op1 (reg2int op2 'REXB))))
	  (return nil))

	  % case: reg - (indirect (reg EBP) ) % no format without offset
    (when (and (eq mode 'indirect)  
	  (regp (cadr op2))
	  (setq base (reg2int (cadr op2) 'REXB))
	  (equal base 2#101) )
	    (return (modR/M op1 (list 'displacement (cadr op2) 0))))

      % case: reg - (indirect (reg ESP) )
    (when (and (eq mode 'indirect)
	  (regp (cadr op2))
	  (setq base (reg2int (cadr op2) 'REXB))
	  (equal base 2#100) )
		  (depositbyte (lor 2#00000100 op1))
		  (depositbyte 2#00100100)  % s-i-b byte
		  (return nil))

      % case: reg - (indirect reg) non ESP/EBP
    (when (and (eq mode   'indirect) 
	       (regp (cadr op2)))
		  % no zero displacement for reg EBP:
	  (setq base (reg2int (cadr op2) 'REXB))
	  (when (or (equal base 2#100)(equal base 2#101))
		(modR/Merror op2))
	  (depositbyte (lor 2#00000000 (lor op1 base)))
	  (return nil))

      % case: reg - (displacement (reg ESP) const)
    (when (and (eq mode   'displacement)
	  (regp (cadr op2))
	  (numberp (caddr op2))
	  (setq base (reg2int (cadr op2) 'REXB))
	  (equal base 2#100) )
	(return
	  (if (bytep (caddr op2))  % 8 bit displacement
	      (progn
		  (depositbyte (lor 2#01000100 op1))
		  (depositbyte 2#00100100)  % s-i-b byte
		  (depositbyte (land 255 (caddr op2))))
	      (progn
		  (depositbyte (lor 2#10000100 op1 base))
		  (depositbyte 2#00100100)  % s-i-b byte
		  (deposit32bitword (caddr op2) )))))

      % case: reg - (displacement reg const), non ESP
    (when (and (eq mode   'displacement) 
	  (regp (cadr op2)) 
	  (numberp (caddr op2)))
	(setq base (reg2int (cadr op2) 'REXB))
	(return
	  (if (bytep (caddr op2))  % 8 bit displacement
	      (progn 
		  (depositbyte (lor 2#01000000 (lor op1 base)))
		  (depositbyte (land 255 (caddr op2))))
	      (progn  
		  (depositbyte (lor 2#10000000 (lor op1 base)))
		  (deposit32bitword (int2sys (caddr op2) ))))))
 
      % case: reg - (indexed ....) 
     (when (eq mode   'indexed)
	  (return (sibbyte-for-indexed (lor 2#00000100 op1) op2)))


      % all other cases: reg - absolute 32 bit displacement
    (depositbyte (lor 2#00000100 op1 ))
    (depositbyte 2#00100101 ) % mingw-w64 no RIP relative addressing
    (depositextension op2)))


(de sibbyte-for-indexed(modr/m op2)
   (prog(base index factor n)
       (setq base (caddr op2) index (cadr op2))
       (setq factor 1)
       (when (eqcar index 'times)
	     (setq factor (caddr index))
	     (setq index (cadr index)))
       (setq factor (atsoc factor
	   '((1 . 0)(2 . 2#01000000)(4 . 2#10000000)(8 . 2#11000000))))
       (when (null factor) (modR/Merror op2))
       (setq factor (cdr factor))
       (cond
	 ((eqcar base 'displacement)
	  (when (or (not (numberp (setq n (caddr base))))
		    (not (regp (cadr base))))   (modR/Merror op2))
	  (setq base (reg2int (cadr base) 'REXB))
	  (when (or (not (equal n 0))(eq base 2#101))
		(prin2t "****** Fall noch nicht vorgesehen")
		(modR/Merror op2))
	  (depositbyte modr/m) 
	  (depositbyte(lor factor (lor (lsh (reg2int index 'REXX) 3) base))))
	 ((labelp base)
	  (depositbyte modr/m)
	  (depositbyte(lor factor (lor (lsh (reg2int index 'REXX) 3) 2#101 )))
	  (depositextension base))
	 (t (modR/Merror op2)))))
		
(de modR/Merror(op2)
   (stderror (bldmsg "illegal 386 addressing mode %w" op2)))

(de depositextension(op2)
   % generate a relocated fullword extension
    (prog (OfFn)
      (when (atom op2) (return (depositwordexpression op2)))
    (when (setq OfFn (get (car op2) 'OperandDepositFunction))
	  (return (apply OfFn (list op2))))
    (depositwordexpression op2)))
    
(de lthmodR/M (op1 op2)
 % calculate the length of the address part by modR/M
(prog (OpFn mode base ireg n)

      % case: reg - reg
    (when (regp op2) (return 1))
    (when (pairp op2) (setq mode (car op2)))

      % case: reg - (indirect (reg ESP) ) 
    (when (and (eq mode   'indirect) 
	  (regp (cadr op2)) 
	  (setq base (reg2int (cadr op2) 'REXB)) 
	  (equal base 2#100) ) 
		  (return 2)) 

	  % case: reg - (indirect (reg EBP) ) % no format without offset 
    (when (and (eq mode   'indirect)     
	  (regp (cadr op2)) 
	  (setq base (reg2int (cadr op2) 'REXB)) 
	  (equal base 2#101) ) 
	    (return (lthmodR/M op1 (list 'displacement (cadr op2) 0)))) 

      % case: reg - (indirect reg) non ESP
    (when (and (eq mode   'indirect)
	       (regp (cadr op2)))
	  (return 1))

      % case: reg - (displacement (reg ESP) const) 
    (when (and (eq mode   'displacement)  
	  (regp (cadr op2)) 
	  (numberp (caddr op2))
	  (setq base (reg2int (cadr op2) 'REXB)) 
	  (equal base 2#100) ) 
	  (if (bytep (caddr op2) )  % 8 bit displacement
	      (return 3) 
	      (return 6)))
 
     % case: reg - (displacement reg const), non ESP
    (when (and (eq mode   'displacement)
	  (regp (cadr op2))
	  (numberp (caddr op2)))
	(return (if (bytep (caddr op2)) 2 5)))

     % case: (indexed reg (displacement reg 0)) 
     (when (eq mode   'indexed) 
	 (return (add1 (lth-sibbyte-for-indexed op2))))

      % all other cases: reg - absolute 32 bit displacement
    (return 6)))
 

(de lth-sibbyte-for-indexed(op2)
   (prog(base index factor offset)
       (setq base (caddr op2) index (cadr op2))
       (cond
	 ((eqcar base 'displacement) 
	  (setq offset (caddr base))
	  (when (or (not (equal offset 0))
		    (not (regp (cadr base))))   (modR/Merror op2))
	  (setq base (reg2int (cadr base) 'REXB)) 
	  (when (eq base 2#101)  
		(prin2t "****** Fall noch nicht vorgesehen") 
		(modR/Merror op2)) 
	  (return 1))
	 ((labelp base) (return 5))
	 (t (modR/Merror op2))))) 
	    
% Procedures to compute specific OperandRegisterNumber!*
% Each of the cases returns the Addrssing MODE
% and sets OperandRegisterNumber!* as a side effect

(fluid '(numericRegisterNames REX-Prefix))

(setq numericRegisterNames [nil EAX EBX ECX EDX EBP])

(put 'REXR 'prefixcode 2#100)
(put 'REXX 'prefixcode 2#010)
(put 'REXB 'prefixcode 2#001)

(de reg2int (u prefixbit)
   % calculate binary number for register
  (prog (r) (setq r u)
      % strip off tag 'reg
   (cond ((eqcar r 'reg)(setq r (cadr r))))
      %convert a LISP-register into a 80386 register
   (if (numberp r) (setq r (getv numericRegisterNames r)))
   (setq r (get r 'registercode))
   (when (and r (wgreaterp r 7)) (setq r (wand r 7))
			 (setq REX-Prefix
				 (wor REX-Prefix (get prefixbit 'prefixcode))))
   (if r (return r)
	 (stderror (bldmsg "unknown register %w" u)))))
 
(deflist '((EAX   0) (ECX   1) (EDX   2) (EBX   3) 
           (rAX   0) (rCX   1) (rDX   2) (rBX   3) 
	   (ESP   4) (EBP   5) (ESI   6) (EDI   7)
	   (rSP   4) (rBP   5) (rSI   6) (rDI   7)
	   (st    4)        % LISP stack register
	   (T1    7) % EDI
	   (T2    6) % ESI
%	   (T3    8) 
%	   (T4    9) 
%	   (heaplast 10) (heaptrapbound 11)
%           (bndstkptr 12) (bndstkupperbound 13)
%           (nil  15) (bndstklowerbound 14)

		% byte and word registers
	   (AL    0) (CL    1)
	   (AX    0) (CX    1)
			% segment registers
		   (ES   0) (CS    1) (SS    2) (DS   3)(FS   4)(GS   5)
	 ) 'registercode)

(de bytep(n)
    (when (and (numberp n) (lessp n 128) (greaterp n -128))
	  (land n 255)))
 
(de halfwordp(n)
    (when (and (numberp n) (lessp n 32768) (greaterp n -32768))
	  (land n 65535)))

(de unimmediate(u)
    (if (eqcar u 'immediate) (cadr u) u))

%------------------------------------------------------------------------
% (displacement (reg 5) ...) has to be prefixed in order to address
% the DS segment rther than the SS segment
(de indexed-reg-5-p(op)
    (and (pairp op) NIL % not useful in 64 bit mode
	 (or (eq (car op) 'indexed)
	     (eq (car op) 'displacement)
	     (eq (car op) 'indirect))
    (equal (cadr op) '(reg 5))) )

(de lth-reg-5-prefix(op)
   (if (indexed-reg-5-p op) 1 0))

(de reg-5-prefix(op)
   (when (indexed-reg-5-p op)
	 (depositbyte 16#3e) ))  % DS segment override prefix

%------------------------------------------------------------------------
%  special format for EAX-ibstructions

(de OP-mem-eax (code op1 op2) 
    (when (eqcar op1 'reg)(setq op1 op2))
    (depositbyte (car code))
    (depositextension (unimmediate op1)))

(de LTH-mem-eax (code op1 op2) 5)

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

%-----------------------------------------------------------------------
% immediate to EAX
(de OP-imm-EAX (code op1) 
    (depositbyte (car code)) (depositextension (unimmediate op1)))
 
(de LTH-imm-EAX (code op1) 5) 
 
%-----------------------------------------------------------------------
% INT with parameter
(de OP-INT (code op1)
    (depositbyte (car code)) (depositbyte (unimmediate op1))) 
 
(de LTH-INT (code op1) 2) 

%---------------------------------------------------------------------
% immediate to reg
% code is one byte + ModR?m byte, op1 the immediate, op2 the reg
% sometimes there is no ModR/M byte; then the reg is placed in the opcode 
%  (adc 17 (reg ABX)) 
(de OP-imm-reg (code op1 op2)
    (prog(n c1 c2)
      (when (cdr code) (depositbyte (car code))(setq code (cdr code)))
      (depositbyte (lor (car code) (reg2int op2 'REXB)))
      (depositextension (unimmediate op1))))
 
(de LTH-imm-reg (code op1 op2) (if (cdr code) 6 5))

(de OP-imm8-reg (code op1 op2)
    (prog(n c1 c2)
      (when (cdr code) (depositbyte (car code))(setq code (cdr code))) 
      (depositbyte (lor (car code) (reg2int op2 'REXB)))
      (depositbyte (bytep op1))))

(de LTH-imm8-reg (code op1 op2) (if (cdr code) 3 2))
 

%---------------------------------------------------------------------
% absolute n-byte instruction
(de OP-byte (code)
	(foreach x in code do (depositbyte x)))
(de lth-byte (code) (length code))

%---------------------------------------------------------------------
% push/pop with register: code is one byte modified with reg number
(de OP-Push-Reg(code op1) (depositbyte (lor (car code) (reg2int op1 'REXB))))
(de LTH-Push-Reg(code op1) 1)

%---------------------------------------------------------------------
% jump to absolute address
% 386 has only relative jumps
(de OP-Jump (code op1)
  (prog(n)
   (depositbyte (car code))
   (when (cdr code) (depositbyte (cadr code)))
   (setq op1 (saniere-Sprungziel op1))
   (setq n(MakeExpressionrelative op1 4)) % offset wrt next instr
   (depositliteralword n)
   (when *testlap (tab 15)(prin2 "-> ")
	 (prin2 n) (prin2 " rel = ")
	 (prin2 (plus currentoffset* n))(prin2t " abs"))))

(de lth-jump (code op1) (if (cdr code) 6 5))

%jump short (8-bit displacement)
(de OP-JUMP-SHORT (code op1)
  (prog(n a)
   (depositbyte (car code))
   (setq op1 (saniere-Sprungziel op1))
   (setq n(MakeExpressionrelative op1 1)) % offset wrt next instr
   (when (not (bytep n)) (stderror  "distance too long for short jump"))
   (depositbyte (bytep n))
   (when *testlap (tab 15)(prin2 "-> ") 
	 (prin2 n) (prin2 " rel = ")
	 (prin2 (plus currentoffset* n))(prin2t " abs"))))
(de lth-JUMP-SHORT (code op1) 2)
 
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
    (depositbyte (lor 2#11000000 (lor (cadr code) (reg2int op1 'REXB))))
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
    (foreach Y in (cdr X) do (DepositQuadWordExpression Y)))

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
	(while (not (eq 0 (remainder CurrentOffset!* 8)))
	       (depositbyte 0))))
% align to word boundary

(de DepositFloat (X)                    % this will not work in cross-assembly
(progn (setq X (FltInf (second X))) 
    (DepositWord (FloatlowOrder X)) ))

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
		      (plus2 currentoffset* offsetfromhere))))
		  (progn
		    (setq forwardinternalreferences* 
		     (cons (cons currentoffset* nam) 
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
  '((jo  . jno)  (jno  . jo)
    (jp  . jnp)  (jnp  . jp)
    (jz  . jnz)  (jnz  . jz)
    (je  . jne)  (jne  . je)
    (jb  . jae)  (jae  . jb)  (jbe  . ja)  (ja  . jbe)
    (jnb . jnae) (jnae . jnb) (jnbe . jna) (jna . jnbe)
    (jl  . jge)  (jge  . jl)  (jle  . jg)  (jg  . jle) 
    (jnl . jnge) (jnge . jnl) (jnle . jng) (jng . jnle)
))

(de reformBranches (code)
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
   (JMP JMPL) (JO JOL) (JB JBL)(JNAE JNAEL)(JNB JNBL)
   (JAE JAEL) (JE JEL) (JZ JZL)(JNE JNEL)(JNZ JNZL)
   (JBE JBEL)(JNA JNAL)(JNBE JNBEL)(JA JAL)(JS JSL)
   (JNS JNSL)(JP JPL)(JPE JPEL)(JNP JNPL)(JPO JPOL)
   (JL JLL)(JNGE JNGEL)(JNL JNLL)(JGE JGEL)(JLE JLEL)
   (JNG JNGL)(JNLE JNLEL)(JG JGL)
) 'WordBranch)

(de GeneralBranchInstructionP (i) (get i 'WordBranch))
(de LocalLabelp (l) (atom (saniere-sprungziel l)))

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

(de &make-nop(n)
   % make n bytes of nop instructions
   (cond ((wleq n 0) nil)
	 ((eq n 1)'((nop)))
	 ((eq n 2)'((nop) (nop)))
	 ((eq n 3)'((mov (reg t1)(reg t1))))
	 ((eq n 4)'((lea (displacement(reg t1)0) (reg t1))))
	 (t (append (&make-nop 3)(&make-nop (difference n 3)))) ))

(de alignCode(u)
  (if (&smember 'fastapply u) u (alignCode1 u)))

(de alignCode1(u)
   (let(rcode w (a currentoffset*) l x y z q s nops)
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
   (while (not (LabelP (car (first X)))) (setq X (cdr X))) 

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

	   ((setq Offset (Atsoc (saniere-sprungziel L) BranchAndLabelAList*)) (cdr Offset))
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
   (cond ((eqcar x 'movq) (wplus2 1 (InstructionLength1 
				 (cons 'mov (cdr x)))))
         ((eqcar x 'addq) (wplus2 1 (InstructionLength1 
				 (cons 'add (cdr x)))))
         ((eqcar x 'subq) (wplus2 1 (InstructionLength1 
				 (cons 'sub (cdr x)))))
         ((reg64bitp x) (wplus2 1 (InstructionLength1 x)))
         (t (InstructionLength1 x))))
  
(de InstructionLength1 (X) 
   (prog (Y) 
       (when (setq Y (get (car x) 'InstructionLengthFunction))
	     (return (apply2safe y (cdr x))))
       (when (setq Y (get (car x) 'INSTRUCTIONLENGTH))
	     (return (if (numberp y) y (apply y (list x)))))
       (stderror (bldmsg "*** Unknown mingw-w64 instruction:%w " x))))

(de apply2safe(y x) % ensure that plly has two parameters at least
     (cond ((null x) (apply y (list nil nil)))
	   ((null (cdr x)) (apply y (list (car x) nil)))
	   (t (apply y (list (car x)(cadr x))))))

(de InlineConstantLength (X) 
% Purpose: returns the Size_Of_Unit_In_Bytes * Number_Of_Such_Units
%   X has the form:
%          (Unit  value_1  value_2 value_3 .... )
    (Times2 (cond ((equal (first X) 'fullword) 8) (t 2)) 
 	    (length (rest X))))

(de ByteConstantLength (X) 
    (Times2 (Quotient (Plus2 (length (rest X)) 1) 2) 2))

(de LapStringLength (X)                 % must fall on word boundary
% Purpose: Calculate the number of bytes occupied by a given string
%  X has the form: (STRING "xxxxxx")
    (Times2 (Quotient (Plus2 (Size (second X)) 9) 8) 8))

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

(compiletime (put 'put_a_halfword 'opencode '(
   (mov (reg ebx) (displacement (reg eax) 0))))) %% (reg 2) (displacement (reg eax) 0)))))

(de deposit32bitword (x) %% cross
  (put_a_halfword (wplus2 codebase* currentoffset*) x)
  (updatebittable 4 0)
  (setq currentoffset* (plus currentoffset* 4)))

(de depositword (x)
  (putword (wplus2 codebase* currentoffset*) 0 x)
  (updatebittable 8 0)
  (setq currentoffset* (plus currentoffset* 8)))

(de depositliteralword (x) %% Cross
  (put_a_halfword (wplus2 codebase!* currentoffset!*) x)
  (updatebittable 4 0)
  (setq currentoffset* (plus currentoffset* 4)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (put_a_halfword (wplus2 codebase* currentoffset*)
	   (iplus2 offset (if *writingfaslfile 0 codebase*)))
  (updatebittable 4 (const reloc_word))
  (setq currentoffset* (plus currentoffset* 4)))
  
(de depositwordexpression (x)
  % Only limited expressions now handled
  (let (y)
    (cond
      ((fixp x) (deposit32bitword (int2sys x)))
      ((labelp x) (deposit-relocated-word (labeloffset x)))
      ((equal (first x) 'internalentry) 
       (let ((offset (get (second x) 'internalentryoffset)))
	 (if offset
	     (deposit-relocated-word offset)
	     (progn
	       (setq forwardinternalreferences*
		     (cons (cons currentoffset* (second x))
			   forwardinternalreferences*))
	       (deposit-relocated-word 0)))))
      ((equal (first x) 'idloc) (depositwordidnumber (second x)))
      ((equal (first x) 'entry) (depositentry x))
      (t (stderror (bldmsg "Expression too complicated %r" x))))))

(de depositquadwordexpression (x)
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
		     (cons (cons currentoffset* (second x))
			   forwardinternalreferences*))
	       (deposit-relocated-word 0)))))
      ((and (eq (car x) 'mkitem)
	    (eq (cadr x) id-tag)
	    (eqcar (setq y (caddr x)) 'idloc)
	    (wlessp (id2int(cadr y)) 129))
	(depositword (cadr y)))
      ((equal (first x) 'idloc) (depositwordidnumber (second x)))
      ((equal (first x) 'mkitem) (deposititem (second x) (third x)))
      ((equal (first x) 'entry) (depositentry x))
      ((setq y (wconstevaluable x)) (depositword (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))))

(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 128)) 
     (deposit32bitword (idinf X)))
    (t
      (put_a_halfword (wplus2 codebase* currentoffset*) 
	       (makerelocword (const reloc_id_number) (findidnumber x))) 
      (setq currentoffset* (plus currentoffset* 4)) 
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
		            (mkitem tagpart (LabelOffset InfPart))))
		     ((equal (first InfPart) 'IDLoc) 
		      (putword (wPlus2 CodeBase* CurrentOffset*) 0 
		        (MkItem TagPart 
	 		(MakeRelocInf (const RELOC_ID_NUMBER) 
	 		  (FindIDNumber (second InfPart))))))
		     (t 
		      (StdError (BldMsg "Unknown inf in MkItem %r"
				 InfPart))))
	      (setq CurrentOffset* (plus CurrentOffset* 8))
	      (UpdateBitTable 8 (const RELOC_INF))))))

(de DepositHalfWordIDNumber (X) 
    (cond ((or (not *WritingFaslFile) (LEQ (IDInf X) 128)) 
	(DepositHalfWord (IDInf X))) (t 
    
    (progn (puthalfword (wplus2 codebase* currentoffset*) 0 
		    (makerelochalfword (const reloc_id_number) (findidnumber x))) 
	(setq currentoffset* (plus currentoffset* 2)) 
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
     (setq x (remainder currentoffset* 16))
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
       (put_a_halfword 
	    (iplus2 codebase* (car (first forwardinternalreferences*))) x)
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

(fluid '(!*optimize-i486))

(setq *optimize-i486 t)

(de LapoptPeep(code)
   (when *optimize-i486 (setq code (LapoptPeep486 code)))
   code)

(de LapoptPeep486(code)
% peephole optimizer for 486 code
% interchanging instructions for dependencies.
 (let (rcode i1 i2 i3 r rb)
  (while code
   (setq i1 (pop code))
   (when (and code (cdr code))
    (setq i2(car code) i3(cadr code))
    (cond
      % case
      %   something
      %   (add 16 (reg st))
      %   (ret)
      % move (add 16 (reg st)) one step up if possible.
     ((and (equal i3 '(ret))
	   (pairp i1)
	   (pairp i2)
	   (eq (car i2) 'add)
	   (equal (caddr i2) '(reg st))
	   (not (&jumpcontrol i1))
	   (not (&smember '(reg st) i1))
	)

      (pop code r)
      (push i1 code)
      (setq i1 i2))

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
   (prin2t " 486 tauschen:")
   (mapc l 'prin2t))

(fluid '(!64bitregs))

(setq !64bitregs '((reg 1) (reg 2) (reg 3) (reg 4) (reg 5) (reg st)
                  (reg rax) (reg rbx) (reg rcx) (reg rdx)
                  (reg t3) (reg t4) (reg NIL) (reg heaplast) 
                  (reg bndstkptr) (reg bndstkupperbound) 
		  (reg bndstklowerbound)  (reg heaptrapbound) 
                  (reg t1) (reg t2) (reg esp) (reg rdi) (reg rsi)))

(de reg64bitP (i)
  (if (eq (car i) 'JMP) NIL
  (reg64bitp1 !64bitregs i)))

(de reg64bitp1 (reglist inst)
   (if (null reglist) nil
     (if (&smember (car reglist) inst) t
        (reg64bitp1 (cdr reglist) inst))))


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
