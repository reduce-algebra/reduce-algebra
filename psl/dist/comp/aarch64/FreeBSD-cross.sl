%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:openbsd-cross.sl
% Description:  FreeBSD patches for aarch64 compiler
% Author:       R. Schöpf
% Created:      January 2021
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
%
% $Id: aarch64-cross.sl 6018 2021-09-10 09:52:15Z schoepf $
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% This file contains redefinitions of compiler internals for 64/32 bit cross
% compilation.
%
% The PSL compiler running on a 64 bit architecture operates on 64 bit words
% internally. In order to generate code for a 32bit architecture, some
% operations on memory words must be modified. 
%
% In particular:
%  * shift/mask operations
%  * storing memory words 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(fluid '(nextstaticlisp))

(fluid '(bittable-entries-per-word nilnumber* dataout*))

(fluid '(staticlispbase* staticlispbittablebase* staticlispbittableoffset*))

(setq addressingunitsperitem 8)
(setq bittable-entries-per-word 32)
(setq LASTACTUALREG&   5)

(compiletime
 (load fasl-decls fast-vector)
)

(compiletime (load addr2id))

(global '(*writingasmfile))

(fluid '(*writingfaslfile
         *lower
         *quiet_faslout
         *NewMemoryModel
         dfprint*
         uncompiledexpressions*
         modulename*
         codeout*
         initoffset*
         CurrentOffset*
         faslblockend*
         maxfasloffset*
         bittableoffset*
         faslfilenameformat*
         fasl-idnumber-property*
         CodeBase*
	 GlobalStaticLispList*
	 CurrentStaticOffset*
	 Pass1SLIndexList
         ForwardInternalReferences*
         ))

(setq *NewMemoryModel t)

(compiletime
 (progn
   (put 'put_a_halfword 'opencode '((STR (reg w1) (displacement (reg x0) 0))))
   (put 'getword32 'opencode '((LDR (reg w0) (indexed (reg 1) (reg 2)) )))
 ))

(de RegP (RegName) 
    (AND (eqcar Regname 'reg)
         (MemQ (cadr RegName) 
               '( 1  2  3  4  5  6  7  8
                     X0 X1 X2 X3 X4 X5 X6 X7 X8 X9 X10 X11 X12 X13 X14 X15
                     X16 X17 X18 X19 X20 X21 X22 X23 X24 X25 X26 X27 X28 X29 X30
                     W0 W1 W2 W3 W4 W5 W6 W7 W8 W9 W10 W11 W12 W13 W14 W15
                     W16 W17 W18 W19 W20 W21 W22 W23 W24 W25 W26 W27 W28 W29 W30
                     sp st fp lr Xzr Wzr
                     t1 t2 t3 t4 t5
             nil heaplast heaptrapbound symfnc symval staticlisp
             bndstkptr bndstklowerbound bndstkupperbound
             ))))


(de DepositItem (TagPart InfPart) 
    (cond ((not *WritingFaslFile) 
           (DepositWord 
               (MkItem TagPart 
                       (cond ((LabelP InfPart) 
                              (wPlus2 CodeBase* (LabelOffset InfPart))) 
                             ((equal (first InfPart) 'IDLoc) 
                              (IDInf (second InfPart))) 
                             ((equal (first InfPart) 'SLLoc) 
                              (wPlus2 CurrentStaticOffset*
				      (SLLabelOffset (second InfPart))))
                             (t 
                                (StdError 
                                    (BldMsg "Unknown inf in MkItem %r"
                                            InfPart)))))))
          (t 
             (progn (cond 
                     ((LabelP InfPart)      % RELOC_CODE_OFFSET = 0
                      (putword (wPlus2 CodeBase* CurrentOffset*) 0 
                            (MkItem tagpart (LabelOffset InfPart))))
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

(fluid '(Pass1StaticLispList))

(de Lap (U) 
  (prog (LabelOffsets* LapReturnValue* Entries* temp) 
     (cond ((not *WritingFaslFile)
	    (setq CurrentOffset* 0)
	    (setq CurrentStaticOffset* (gtstaticlisp 0)))
	   (t (setq CurrentStaticOffset* 0)))
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
 
    (setq U (ReformBranches U))         % process conditional branches
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

% If you are depositing into memory tell the user how much space the
% code took and where it was loaded.
% ??? Why is this using the error channel ???

    (cond ((and (not *WritingFaslFile) *PWrds) 
        (ErrorPrintF "*** %p: base 16#%x, length 10#%d bytes" 
                (foreach X in Entries* collect (first (car X))) 
                                CodeBase* CodeSize*))) 

    % If writing into memory, flush the caches

    (cond ((not *WritingFaslFile)
           (clear_cache CodeBase* (wplus2 CodeBase* CodeSize*))))

    % Do not call MkCODE on LapReturnValue* if it is nil
    % LapReturnValue* is a fluid variable that got set up to hold
    % the address of the compiled function when the code was generated
    (cond
     (LapReturnValue*
      (return
	(MkCODE LapReturnValue*))))
     ))

(de Pass1Lap (InstructionList)
  (prog (Pass1CodeList
	 Pass1ConstantList
	 Pass1ConstantContentsList
	 Pass1StaticLispList
	 Pass1SLIndexList
	 EntryPoints!*
	 Pass1AddedCode)
    (setq Pass1CodeList (cons NIL NIL))	% Init a TCONC pointer.
    (setq Pass1ConstantContentsList (cons NIL NIL))
    (setq Pass1StaticLispList (cons NIL NIL))
    (setq Pass1SLIndexList (cons NIL NIL))
    (Pass1Code InstructionList)         % Expand macros.
    (Pass1Code Pass1AddedCode)
    (AppendConstants)			% Tack the constants on the end.
    (AppendStaticLisp)
    (AppendSLIndexes) 
    (return (car Pass1CodeList))))

(de SaveConstant (Expression)
  (prog (TableEntry)
	(return (cond ((setq TableEntry
			     (Ass (function equal_wo_zeroequal)
		% dont intermix 0 and 0.0
				  Expression Pass1ConstantList))
		       (cond% ((and !*NewMemoryModel (not (InumP Expression)))
			     % (get-SL-index (cdr TableEntry) (car TableEntry)))
			     (t (cdr TableEntry))))
		      (t (progn (setq TableEntry (GenerateLabel))
				(setq Pass1ConstantList
				      (cons (cons Expression
						  TableEntry)
					    Pass1ConstantList))
				(cond% ((and !*NewMemoryModel (not (InumP Expression)))
%				       (get-SL-index TableEntry Expression))
				      (t TableEntry))))
		      ))))

(de get-SL-index (TableEntry Expression)
  (prog (IndexEntry)
     (return (cond ((setq IndexEntry (assoc TableEntry Pass1SLIndexList))
%		    (list 'SLLoc (cdr IndexEntry)))
		    (cdr IndexEntry))
		   (t (progn
			(setq IndexEntry (GenerateLabel))
			(TConc Pass1SLIndexList (cons TableEntry IndexEntry))
%			(list 'SLLoc IndexEntry)))))
			IndexEntry))))
     ))

(de ExpandItem (Expression)
  (prog (LabelOfContents)
	(return (cond ((InumP Expression) Expression)
                      ((eqcar Expression 'saveidloc)
		       (list 'idloc (cadr Expression)))
		      ((IDP Expression)
		       (MakeMkItem (TagNumber Expression)
				   (list 'IDLoc Expression)))
		      ((CodeP Expression)
		       (MakeMkItem (TagNumber Expression)
			           Expression))
		      (t (progn
			   (setq LabelOfContents (SaveContents Expression))
			   (MakeMkItem
			    (TagNumber Expression)
			    (cond % (!*NewMemoryModel (list 'SLLoc LabelOfContents))
				  (t LabelOfContents)))))))))

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
				(cond% (!*NewMemoryModel (list 'SLLoc TableEntry))
				      (t TableEntry))))))))

(de asmslloc (x) (prin2 (cadr x)))    

(put 'SLLoc 'asmexpressionfunction 'asmslloc)


(de AppendOneConstant (ExpressionLabelPair)
  (cond (%(and !*NewMemoryModel (not (Inump (car ExpressionLabelPair))))
	 !*NewMemoryModel
	 (AddStaticLispLabel (cdr ExpressionLabelPair))
	 (AppendStaticItem (car ExpressionLabelPair)))
	(t
	 (AddCodeLabel (cdr ExpressionLabelPair))
         (AppendItem (car ExpressionLabelPair)))))

(de AppendStaticItem (Expression)
  (AddFullStaticWord (ExpandItem Expression)))

(de AddFullStaticWord (Expression)
  (AddStaticLisp (list 'FULLWORD Expression)))

(de AddStaticLispLabel (Label)
  (AddStaticLisp Label))

(setq GlobalStaticLispList* (cons nil nil))

(de AddStaticLisp (sl)
  (TConc GlobalStaticLispList* (cons sl (sl-itemoffset sl))))

(fluid '(staticlispcount*))

(setq staticlispcount* 0)

(de sl-itemoffset (itm)
  (if (atom itm) staticlispcount*
    (let ((countfn (get (car itm) 'SLSizeFn))
	  (offset staticlispcount*))
      (setq staticlispcount*
	    (iplus2 staticlispcount* 
		    (cond ((null countfn) 1)	   % default -- one fullword
			  ((fixp countfn) countfn) % fixed size
			  (t (apply countfn (list (cdr itm))))) % variable size
		    ))
      offset)))

(put 'FULLWORD 'SLSizeFn 'length)

(de count-sl-stringwords (str)
  (iquotient (iplus2 (size (car str)) 9) 8))

(put 'string 'SLSizeFn 'count-sl-stringwords)

(de count-sl-halfwords (hh)
  (iquotient (iplus2 (times2 (length hh) 2) 9) 8))

(put 'halfword 'SLSizeFn 'count-sl-halfwords)

(de count-sl-bytes (bb)
  (iquotient (iplus2 (length bb) 9) 8))

(put 'byte 'SLSizeFn 'count-sl-bytes)

(put 'float 'SLSizeFn '2)


(de AppendStaticLisp ()
    (if (not *writingasmfile)
	(let* ((sl-size (plus2 (cdr (cdr GlobalStaticLispList*)) nextstaticlisp))
	       (oldslbase (gtstaticlisp 0))
	       (newslbase (gtstaticlisp sl-size)))
	  (foreach sl-item in (car GlobalStaticLispList*) do
		   (DepositStaticLispItem sl-item)
		   (rplacd sl-item (plus2 (cdr sl-item) oldslbase))
		   )
	  )
	)
    )

(de DepositStaticLispItem (u)
  (let ((CodeBase* staticlispbase*)
	(CurrentOffset* CurrentStaticOffset*)
	(bittablebase* staticlispbittablebase*)
	(bittableoffset* staticlispbittableoffset*))
    (DepositInstruction u)
    (setq CurrentStaticOffset* CurrentOffset*
	  staticlispbittableoffset* bittableoffset*)))

      
(de AppendContents (ExpressionLabelPair)
  (prog (Expression UpperBound I offset)

        (when (and (FloatP (car ExpressionLabelPair)) (prop 'oddalign))
                (AddCode '(oddalign))) % odd double align floats

	(AddStaticLispLabel (cdr ExpressionLabelPair))
	(setq Expression (car ExpressionLabelPair))
	(setq offset (get-sl-offset))
	(cond ((PairP Expression)
	       (progn (AppendStaticItem (car Expression))
		      (AppendStaticItem (cdr Expression))))
	      ((StringP Expression)
	       (progn (AddFullStaticWord (Size Expression))
		      (AddStaticLisp (list 'STRING Expression))))
	      ((or (VectorP Expression) (EVectorP Expression))
	       (progn (setq UpperBound (ISizeV Expression))
		      (AddFullStaticWord UpperBound)
		      (setq I 0)
		      (while (ILEQ I UpperBound)
			     (progn (AppendStaticItem (IGetV Expression I))
				    (setq I (IAdd1 I))))))
	      ((BigP Expression)
	       (progn (setq UpperBound (ISizeV Expression))
		      (AddFullStaticWord UpperBound)
		      (AppendStaticItem (IGetV Expression 0)) % sign is an id
                      (setq I 1)
		      (while (ILEQ I UpperBound)
%		     (progn (AppendItem (IGetV Expression I))
                          (progn (AddFullStaticWord (sys2fixn (IGetV Expression I)))
				    (setq I (IAdd1 I))))))
	      ((FixP Expression)
	       (progn (AddFullStaticWord 0)	% Header of full word fixnum.
		      (AddFullStaticWord Expression)))
	      ((FloatP Expression)
	       (progn (AddFullStaticWord 1)	% Header of float.
		      (AddStaticLisp (list 'FLOAT Expression)))))
	(return (list 'staticlisp offset))
     ))

(de AppendSLIndexes ()
    (print (list 'Pass1CodeList (car Pass1CodeList)))
    (print (list 'Pass1SLIndexList (car Pass1SLIndexList)))
    (print (list 'GlobalStaticLispList* (car GlobalStaticLispList*)))
    (let ((repl (car GlobalStaticLispList*)))
%	   (foreach sl-index in (car Pass1SLIndexList) conc
%		    (let ((offset (SLLabelOffset (car sl-index))))
%		      (list
%		       (cons (list 'slloclow (cdr sl-index))
%			     (wand offset 16#ffff))
%		       (cons (list 'sllochigh (cdr sl-index) 'LSL 16)
%			     (wshift offset -16)))))))
%      (print (list 'repl repl))
      (setq Pass1CodeList (sublis repl Pass1CodeList)))
    (print (list 'Pass1CodeList (car Pass1CodeList))) )
%  (foreach sl-index in (car Pass1SLIndexList) do
%	   (AddCodeLabel (cdr sl-index))
%	   (AddFullWord (SLLabelOffset (car sl-index)))))

(de get-sl-offset nil
    (cond ((or *WritingFaslFile *WritingAsmFile) staticlispcount*)
	  (t (plus2 CurrentStaticOffset* staticlispcount*))))

(de SLLabelOffset (label)
    (let ((l (assoc label (car GlobalStaticLispList*))))
      (cond ((null l)
	     (StdError (Bldmsg "Static Label %p not found%nGlobalStaticLispList*=%p"
			       label GlobalStaticLispList*)))
	    (t (cdr l)))))

%(fluid '(nextstaticlispNumber*))

(de initialize-StaticLisp ()
  (dataprintgloballabel (findgloballabel 'staticlisp))
  (print (list 'GlobalStaticLispList* (car GlobalStaticLispList*)))  
  (foreach x in (car GlobalStaticLispList*) do (init-staticlisp-item (car x) (cdr x)))
  (dataprintgloballabel (findgloballabel 'endinitstaticlisp)))

(de init-staticlisp-item (itm offset)
  (if (atom itm)		   % label takes no room in staticlisp
      (dataprintgloballabel itm)
    (progn
      (dataprint-staticlisp itm)
      ))
)

(de dataprint-staticlisp (x)
    (prog (fn oldout)
          (return (cond ((stringp x) (dataprintgloballabel x))
                      ((atom x) (dataprintgloballabel (findlocallabel x)))
                      ((setq fn (get (car x) 'asmpseudoop))
		       (setq oldout (wrs dataout*)) 
                       (apply fn (list x))
		       (wrs oldout))
                      (t (errorprintf "***** Cannot print static lisp item %r" x)))))) 


(de DataAlignFullWord nil
    (DataPrintf " .align 4%n")
    )

(loadtime (define-constant staticlispsize 100000))

(de initializesymboltable ()
  (let ((maxsymbol (compiler-constant 'maxsymbols))
	(staticlispsize (compiler-constant 'staticlispsize)))
    (when (lessp maxsymbol nextidnumber*)
      (errorprintf "*** MaxSymbols %r is too small; at least %r are needed"
		   maxsymbol nextidnumber*)
      (setq maxsymbol (plus nextidnumber* 100)))
    (flag '(nil) 'nilinitialvalue)
    (put 't 'initialvalue 't)
%    (setq nilnumber* (compileconstant nil))
    (setq nilnumber* (compileconstant (int2id 256)))
    (dataalignfullword)
    (initializesymval)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymprp)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymnam)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymfnc)
    (datareservefunctioncellblock 
     (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymget)   % SYMGET feature
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initialize-StaticLisp)
    (datareserveblock (difference staticlispsize staticlispcount*))
    (dataprintgloballabel (findgloballabel 'laststaticlisp))
%   (dataalignfullword)
%    (dataalignfullword)
%    (dataprintgloballabel (findgloballabel 'nextsymbol))
%    (dataprintfullword nextidnumber*)
    ))

(put 'staticlisp 'registercode 20)
(put 'staticlisp 'RegisterName "X20")

(de *ForeignLink (functionname functiontype numberofarguments)
    %% stack has to be aligned on an 16 byte boundary69.
    `(
      (STP (reg fp) (reg lr) (preindexed (reg sp) -80))
%      (STP (reg fp) (reg lr) (preindexed (reg sp) -240))
      (MOV (reg fp) (reg sp))
      %% save caller saved registers
%      (STP (reg x1) (reg x2) (displacement (reg sp) 224))
%      (STP (reg x3) (reg x4) (displacement (reg sp) 208))
%      (STP (reg x5) (reg x6) (displacement (reg sp) 192))
%      (STP (reg x7) (reg x8) (displacement (reg sp) 176))
%      (STP (reg x9) (reg x10) (displacement (reg sp) 160))
%      (STP (reg x11) (reg x12) (displacement (reg sp) 144))
%      (STP (reg x13) (reg x14) (displacement (reg sp) 128))
%      (STP (reg x15) (reg x16) (displacement (reg sp) 112))
%      (STP (reg x17) (reg x18) (displacement (reg sp) 96))
      (STP (reg x19) (reg x20) (displacement (reg sp) 80))
      (STP (reg x21) (reg x22) (displacement (reg sp) 64))
      (STP (reg x23) (reg x24) (displacement (reg sp) 48))
      (STP (reg x25) (reg x26) (displacement (reg sp) 32))
      (STP (reg x27) (reg x28) (displacement (reg sp) 16))
%      (*Move (quote t) (fluid *kernelmode))
      (BL (foreignentry ,functionname))
%      (*Move (reg NIL) (fluid *kernelmode))
      %% restore registers
      (LDP (reg x27) (reg x28) (displacement (reg sp) 16))
      (LDP (reg x25) (reg x26) (displacement (reg sp) 32))
      (LDP (reg x23) (reg x24) (displacement (reg sp) 48))
      (LDP (reg x21) (reg x22) (displacement (reg sp) 64))
      (LDP (reg x19) (reg x20) (displacement (reg sp) 80))
%      (LDP (reg x17) (reg x18) (displacement (reg sp) 96))
%      (LDP (reg x15) (reg x16) (displacement (reg sp) 112))
%      (LDP (reg x13) (reg x14) (displacement (reg sp) 128))
%      (LDP (reg x11) (reg x12) (displacement (reg sp) 144))
%      (LDP (reg x9) (reg x10) (displacement (reg sp) 160))
%      (LDP (reg x7) (reg x8) (displacement (reg sp) 176))
%      (LDP (reg x5) (reg x6) (displacement (reg sp) 192))
%      (LDP (reg x3) (reg x4) (displacement (reg sp) 208))
%      (LDP (reg x1) (reg x2) (displacement (reg sp) 224))
%      (LDP (reg fp) (reg lr) (postindexed (reg sp) 240))
      (LDP (reg fp) (reg lr) (postindexed (reg sp) 80))
      ))

(fluid '(*comment))

(de asmoutlap1 (x)
  (prog (fn)
        (return (cond ((stringp x) (printlabel x))
                      ((atom x) (printlabel (findlocallabel x)))
                      ((setq fn (get (car x) 'asmpseudoop))
                       (apply fn (list x)))
                      (t
                       % instruction output form is:
      % "space" <opcode> [ "space" <operand> { "comma" <operand> } ] "newline"

      (progn (prin2 '! )
             % Space
             (PrintOpcode (car x))
             (setq x (cdr x))
             (unless (null x)
                     (prin2 '! )
                     % SPACE
                     (PrintOperand (car x))
                     (foreach u in (cdr x) do
                              (progn (prin2 '!,)
                                     % COMMA
                                     (PrintOperand u))))
	     (when *comment
	       (tab 35) (prin2 "# ") (prin2 *comment)
	       (setq *comment nil))
             (prin2 !$eol!$)))))))

(DefCMacro *Move
       (Equal)
       ((regp regp)              (MOV ArgTwo ArgOne))
       ((quotedstringp regp)     (*LoadString ArgTwo ArgOne))
       ((quotep regp)            (*LoadSLIndex (reg t3) ArgOne)
	                         (LDR ArgTwo (indexed (reg staticlisp) (regshifted t3 LSL 3))))
       ((InumP regp)             (*LoadConstant ArgTwo ArgOne))
       ((fixp regp)              (*LoadConstant ArgTwo ArgOne))
       ((idlocp regp)            (*LoadIDLoc ArgTwo ArgOne))
%       ((sllocp regp)            (*LoadSLLoc ArgTwo ArgOne))
       ((fluid-arg-p regp)       (*LoadIdNumber LDR ArgTwo ArgOne))
       ((indirectp regp)         (LDR ArgTwo ArgOne))
       ((immediatep regp)        (*LoadImmediate ArgTwo ArgOne))
       ((regp fluid-arg-p)       (*LoadIdNumber STR ArgOne ArgTwo))
       ((regp indirectp)         (STR ArgOne ArgTwo))
       ((regp extraregp)         (!*StoreIntoExtraReg ArgOne ArgTwo))
       ((regp anyp)              (STR ArgOne ArgTwo))
       ((extraregp regp)         (!*LoadExtraReg ArgOne ArgTwo))
       ((anyp regp)              (LDR ArgTwo ArgOne))
       (                         (*Move ArgOne (reg t1))
                                 (*Move (reg t1) ArgTwo)))

(de *LoadSLLoc (dest src)
  (let ((offset (SLLabelOffset src))
        (comment (if *writingasmfile `((comment ,@src)))))
    (append comment
      (cond ((and (fixp offset) (wlessp offset 257))
             (*LoadConstant dest (id2int (cadr src))))
            ((and *writingasmfile (fixp offset))
             `( (ldr ,dest (quote ,offset))))
            (t
             `( (ldr ,dest ,(SaveConstant `(saveidloc ,(cadr src))))))
    ))))


(DefCMacro *LoadSLLoc)

(de *LoadString (dest string)
%    `( (LDR (reg t3) (slloc ,(SaveContents (cadr string))))
%    `( (LDR (reg t3) (slloc ,(cadr string)))
%    `( (MOV32 (reg t3) (slloc ,(cadr string)))
%    `( (MOV32 (reg t3) ,(cadr string))
    `( (MOV32 (reg t3) ,string)
%    `( (MOV (reg t3) (slloclow ,(cadr string)))
%       (MOVK ,dest (sllochigh ,(cadr string)) LSL 16)
       (LDR ,dest (indexed (reg staticlisp) (regshifted t3 LSL 3)))
%       (*MkItem ,dest (quote 4))
       )
)

(de *LoadSLIndex (dest expr)
%    `( (LDR (reg t3) (slloc ,(SaveStaticContents (cadr expr)))))
%    `( (LDR ,dest (slloc ,(cadr expr))))
    `( (MOV32 ,dest ,expr))
%    `( (MOV ,dest (slloclow ,(cadr expr)))
%       (MOVK ,dest (sllochigh ,(cadr expr)) LSL 16))
    )

(DefCMacro *LoadSLIndex)

(de *LoadConstant (dest cst)
    (cond ((sixteenbit-p cst)
           `( (MOV ,dest ,(land 16#ffff cst))))
          ((sixteenbit-p (lnot cst))
           `( (MOVN ,dest ,(land 16#ffff (lnot cst)))))
          ((InumP cst)
%           `( (MOV64 ,dest (sysint ,cst))))
           `( (MOV64 ,dest ,cst)))
          (t
           `( (LDR ,dest (quote ,cst))))
          )
    )

(de *LoadIDLoc (dest src)
  (let ((idnumber (WConstEvaluable src))
        (comment (if *writingasmfile `((comment ,@src)))))
    (append comment
      (cond ((and (fixp idnumber) (wlessp idnumber 257))
             (*LoadConstant dest (id2int (cadr src))))
            ((and *writingasmfile (fixp idnumber))
             `( (MOV ,dest ,idnumber)))
            (t
             `( (MOV32 ,dest ,(SaveConstant `(saveidloc ,(cadr src))))))
    ))))


(de *LoadIdNumber (load-or-store reg nonlocal)
  (let ((idnumber
         (WConstEvaluable `(idloc ,(cadr nonlocal))))
        (comment (if *writingasmfile `((comment ,@nonlocal)))))
    (append comment
      (if (and idnumber (fixp idnumber) (lessp idnumber 257) (greaterp idnumber -1))
        `( (,load-or-store ,reg (displacement (reg symval) ,(times 8 idnumber))) )
       `( (MOV32 (reg t3) ,(if (null idnumber) (SaveConstant `(saveidloc ,(cadr nonlocal))) idnumber))
         (,load-or-store ,reg (indexed (reg symval) (regshifted t3 LSL 3))) )
      ))))

(de asmprintMOV32 (x)
    (prin2 '! )
    (printopcode 'movz)
    (prin2 '! )
    (printoperand (cadr x))
    (prin2 '!,)
    (printoperand (land (caddr x) 16#ffff))
    (prin2 !$eol!$)
    (if (not (eq 0 (lshift (caddr x) -16)))
	(progn
	  (prin2 '! )
	  (printopcode 'movk)
	  (prin2 '! )
	  (printoperand (cadr x))
	  (prin2 '!,)
	  (printoperand (lshift (caddr x) -16))
	  (printoperand ",lsl #16")
	  (prin2 !$eol!$)
	  )
	)
    )

(put 'mov32 'asmpseudoop 'asmprintMOV32)

(de asmprintMOV64 (x)
  (prog (part)
    (setq part (land (caddr x) 16#ffff))
    (prin2 '! )
    (printopcode 'movz)
    (prin2 '! )
    (printoperand (cadr x))
    (prin2 '!,)
    (printoperand part)
    (prin2 !$eol!$)
    (for (from sh 16 48 16)
	 (do
	  (setq part (land (lshift (caddr x) (minus sh)) 16#ffff))
	  (if (not (eq 0 part))
	      (progn
		(prin2 '! )
		(printopcode 'movk)
		(prin2 '! )
		(printoperand (cadr x))
		(prin2 '!,)
		(printoperand part)
		(printoperand (bldmsg ",lsl #%d" sh))
		(prin2 !$eol!$))
	  )))
     )
  )

(put 'mov64 'asmpseudoop 'asmprintMOV64)

(de Deposit32BitLoad (X)
    (prog (src dest)
       (print (list 'Deposit32BitLoad X))
       (setq src (caddr X) dest (cadr X)) 
       (DepositInstruction `(MOVZ ,dest (slloclow ,src)))
       (DepositInstruction `(MOVK ,dest ((sllochigh ,src) LSL 16))))
    )

(de Deposit64BitLoad (X)
    (prog (src dest)
       (print (list 'Deposit32BitLoad X))
       (setq src (caddr X) dest (cadr X)) 
       (DepositInstruction `(MOVZ ,dest (slloclow ,src)))
       (DepositInstruction `(MOVK ,dest ((sllochigh ,src) LSL 16))))
    )

(put 'MOV32 'InstructionDepositFunction 'Deposit32BitLoad)

(put 'MOV32 'InstructionLength 8)

(put 'MOV64 'InstructionDepositFunction 'Deposit64BitLoad)

(put 'MOV64 'InstructionLength 16)

(de ExpandSLLoc (Expression)
%    (list 'SLIndex (ExpandQuote1 (cadr Expression))))
    (ExpandQuote1 (cadr Expression)))

(put 'slloc 'Pass1PseudoOp 'ExpandSLLoc)

