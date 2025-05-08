%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:openbsd-cross.sl
% Description:  Aarch64 patches for 64bit cross compiler
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

(fluid '(bittable-entries-per-word nilnumber* dataout*))

(setq addressingunitsperitem 8)
(setq bittable-entries-per-word 32)
(setq LASTACTUALREG&   5)

(compiletime
 (load fasl-decls fast-vector)
)

(compiletime (load addr2id))

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
         ForwardInternalReferences*
         ))

(setq *NewMemoryModel t)

%% (de codefiletrailer ()
%%   (prog (s)
%%         (systemfaslfixup)
%%         (binarywrite codeout* (idifference (isub1 nextidnumber*) 
%%                                            first-local-id-number))
%%         % Number of local IDs
%%         (foreach x in (car orderedidlist*) do
%%                  (progn (remprop x fasl-idnumber-property*)
%%                         (setq x (strinf (faslid2string x)))
%%                         (setq s (strlen x))
%%                         (binarywrite codeout* s)
%%                         (binarywriteblock codeout* (strbase x)
%%                                           (strpack s))))
%%         (binarywrite codeout* % S is size in words
%%                      (setq s
%%                       (iquotient
%%                        (iplus2 CurrentOffset*
%%                         (isub1 addressingunitsperitem))
%%                        addressingunitsperitem)))
%%         (binarywrite codeout* initoffset*)
%%         (binarywriteblock codeout* CodeBase* s)
%% 	(if *compact-bittable
%%          (let((b (compact-bittable bittablebase* bittableoffset*))
%%               (bpw (quotient bitsperword 8)))
%%            (binarywrite codeout*
%%             (setq s (iquotient
%%                        (iplus2 (car b)
%%                         (isub1 bpw))
%%                        bpw)))
%%            (binarywriteblock codeout* (strbase (strinf (cdr b))) s)
%%          )
%%          (progn
%%           (binarywrite codeout*
%%                      (setq s
%%                       (iquotient
%%                        (iplus2 bittableoffset*
%%                         (isub1 bittable-entries-per-word))
%%                        bittable-entries-per-word)))
%%           (binarywriteblock codeout* bittablebase* s)
%%         ))
%%         (deallocatefaslspaces)))

(compiletime
 (if_system x86_64
   (progn
     (put 'put_a_halfword 'opencode '((movl (reg ebx) (displacement (reg rax) 0))))
     (put 'getword32 'opencode '((movl (indexed (reg 1) (displacement (reg 2) 0)) (reg EAX)))))
   (progn
     (put 'put_a_halfword 'opencode '((STR (reg w1) (displacement (reg x0) 0))))
     (put 'getword32 'opencode '((LDR (reg w0) (indexed (reg 1) (reg 2)) ))))
   ))

%% (de deposit32bitword (x) %% cross
%%   (put_a_halfword (wplus2 codebase* currentoffset*) x)
%%   (updatebittable 4 0)
%%   (setq currentoffset* (plus currentoffset* 4)))

%% (de deposit-relocated-word (offset)
%%   % Given an OFFSET from CODEBASE*, deposit a word containing the
%%   % absolute address of that offset.
%%   (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	   (iplus2 offset (if *writingfaslfile 0 CodeBase*)))
%%   (updatebittable 4 (const reloc_word))
%%   (setq CurrentOffset* (plus CurrentOffset* 4)))

%% (de depositwordidnumber (x) 
%%   (cond
%%     ((or (not *writingfaslfile) (leq (idinf x) 256)) 
%%      (deposit32bitword (idinf X)))
%%     (t
%%       (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	       (makerelocword (const reloc_id_number) (findidnumber x))) 
%%       (setq CurrentOffset* (plus CurrentOffset* 4)) 
%%       (updatebittable 4 (const reloc_word)))))

%% Changed for special handling of id numbers 0-256 instead of 0-128
(de DepositQuadWordExpression (x)
  % Only limited expressions now handled
  (let (y)
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
	(depositword (if (null (cadr y)) (int2id 256) (cadr y))))
      ((equal (first x) 'idloc) (depositquadwordidnumber (second x)))
      ((equal (first x) 'mkitem) (DepositItem (second x) (third x)))
      ((equal (first x) 'entry) (DepositEntry x))
      ((memq (first x) '(fluid global $fluid $global)) (DepositValueCellLocation (second x)))
      ((setq y (wconstevaluable x)) (DepositWord (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))
    ))

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

%% (de depositwordidnumber (x) 
%%   (cond
%%     ((or (not *writingfaslfile) (leq (idinf x) 256)) 
%%      (deposit32bitword (idinf X)))
%%     (t
%%       (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	       (makerelocword (const reloc_id_number) (findidnumber x))) 
%%       (setq CurrentOffset* (plus CurrentOffset* 4)) 
%%       (updatebittable 4 (const reloc_word)))))


%% (de findidnumber (u)
%%   (prog (i)
%%         (return (cond ((null u) 256)
%% 		      ((ileq (setq i (idinf u)) 256) i)
%%                       ((setq i (get u fasl-idnumber-property*)) i)
%% 		      ((extraargumentp nextidnumber*)
%% 		       (stderror "Too many identifiers in fasl file"))
%%                       (t (put u 'idnumber (setq i nextidnumber*))
%% 			 (setq orderedidlist* (tconc orderedidlist* u))
%% 			 (setq nextidnumber* (iadd1 nextidnumber*)) i)))))


%%
%% We have a little problem here with the id numbers of nil and findidnumber:
%%
%%                             cross compiler            target system
%% id number of nil                 128                      256
%% id number of firstkernel  
%% (int2id 256)                  firstkernel                 nil
%% (id2int nil)                     128                      256
%% (id2int 'firstkernel)            256                      257
%%
%% When the initial values in the symbol table are written to the assembler file,
%% initsymval1 is called for every symbol. For these two cases we have
%%    (initsymval1 (int2id 256))
%% followed by
%%    (initsymval1 'firstkernel)
%% i.e., twice with the same value
%% To get around this I introduce a global variable **nil-seen** that is nil at
%% the beginning, and set to t as seen as (initsymval1 (int2id 256)) is called.
%%

(global '(**nil-seen**))

(de initsymval1 (x)
  (prog (val)
% now decide what to plant in value cell at compiletime.
        (return (dataprintfullword 
                 (cond 
                       ((eq x 'nextsymbol) nextidnumber*)
% print the corresponding symbol for the valuecell with label, and external declaration.
                       ((flagp x 'externalsymbol)
                          (setq val (get x 'symbol))
                          (datadeclareexternal val)
                          val)
% print the corresponding symbol for the valuecell with label, and exported declaration.
                       ((flagp x 'exportedsymbol)
                          (setq val (get x 'symbol))
                          (datadeclareexported val)
                          (dataprintlabel val)
                          (list 'mkitem (compiler-constant 'unbound-tag) 
                            (findidnumber x)))
% print internal references for symnam, symfnc, symval, symprp.
                       ((flagp x 'internalsymbol)
                          (setq val (get x 'symbol))
                          val)
% print the initial value.
                       ((setq val (get x 'initialvalue))
                        (compileconstant val))
% print the value of nil. Make sure that this case applies to nil only, not to
% the symbol firstkernel (which happens to have id number 256 in the cross compiler
% because nil has still id number 128)
		       ((and (eq (id2int x) 256) (not **nil-seen**))
			(setq **nil-seen** t)
			(list 'mkitem (compiler-constant 'id-tag) 256))
% print the value of cross compiler nil
                       ((eq (id2int x) 128)
			(list 'mkitem (compiler-constant 'unbound-tag) 128))
                       ((and (flagp x 'nilinitialvalue) (not (eq x 'firstkernel)))
			nilnumber*)
% print the unbound variable value.
                       (t 
                        (list 'mkitem (compiler-constant 'unbound-tag) 
                         (findidnumber x))))))))

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

    % Do not call MkCODE on LapReturnValue* if it is nil
    % LapReturnValue* is a fluid variable that got set up to hold
    % the address of the compiled function when the code was generated
    (cond
     (LapReturnValue*
      (return
       (MkCODE LapReturnValue*))))))

(de Pass1Lap (InstructionList)
  (prog (Pass1CodeList
	 Pass1ConstantList
	 Pass1ConstantContentsList
	 Pass1StaticLispList
	 EntryPoints!*
	 Pass1AddedCode)
    (setq Pass1CodeList (cons NIL NIL))	% Init a TCONC pointer.
    (setq Pass1ConstantContentsList (cons NIL NIL))
    (setq Pass1StaticLispList (cons NIL NIL))
    (Pass1Code InstructionList)         % Expand macros.
    (Pass1Code Pass1AddedCode)
    (AppendConstants)			% Tack the constants on the end.
    (AppendStaticLisp)
    (return (car Pass1CodeList))))

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
				(cond (!*NewMemoryModel (list 'SLLoc TableEntry))
				      (t TableEntry))
				))))))

(de ExpandItem (Expression)
  (prog (LabelOfContents)
	(return (cond ((InumP Expression) Expression)
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
			    (cond (!*NewMemoryModel (list 'SLLoc LabelOfContents))
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
				(cond (!*NewMemoryModel (list 'SLLoc TableEntry))
				      (t TableEntry))))))))

(de asmslloc (x) (prin2 (cadr x)))

(put 'SLLoc 'asmexpressionfunction 'asmslloc)


(de AppendOneConstant (ExpressionLabelPair)
    (prog (offset)
	  (setq offset (get-sl-offset))
	  (AddStaticLispLabel (cdr ExpressionLabelPair))
          (return (AppendStaticItem (car ExpressionLabelPair)))))

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
			  (t (apply countfn (cdr itm)))) % variable size
		    ))
      offset)))

(de count-stringwords (str)
  (iquotient (iplus2 (size str) 9) 8))

(put 'string 'SLSizeFn 'count-stringwords)
(put 'float 'SLSizeFn '2)

(put 'FULLWORD 'StaticLispSize 1)


(de AppendStaticLisp ()
    (let* ((sl-size (plus2 (cdr (cdr GlobalStaticLispList*)) nextstaticlisp))
	   (oldslbase (gtstaticlisp 0))
	   (newslbase (gtstaticlisp sl-size)))
      (foreach sl-item in (car GlobalStaticLispList*) do
	(DepositInstruction sl-item)
	(rplacd sl-item (plus2 (cdr sl-item) oldslbase))
	)
      )
    )

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

(de get-sl-offset nil
    (cond (WritingFaslFile staticlispcount*)
	  (t (plus2 CurrentStaticOffset* staticlispcount*))))

(de SLLabelOffset (label)
    (let ((l (assoc label GlobalStaticLispList*)))
      (cond ((null l) (StdError (Bldmsg "Static Label %w not found" label)))
	    (t (times2 addressingunitperitem (cdr l))))))

%(fluid '(nextstaticlispNumber*))

(de initialize-StaticLisp ()
  (dataprintgloballabel (findgloballabel 'staticlisp))
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

(de PrintString (S) 
 (prog (n) 
    (cond
     ((neq (Size S) -1) 
      (progn (setq n (Size S)) 
	     (printf " .byte ") 
	     (PrintExpression (Indx S 0)) 
	     (for (from i 1 n 1)
		  (do (PrintByte!, (Indx S i))))
	     (PrintByte!, 0)
	     % at this point (n+2) bytes (including final 0 byte) have been printed
	     % fill with 0 bytes to a multiple of 8 if necessary
	     (cond
	      ((greaterp (Remainder (plus n 2) 8) 0)
	       (for (from i (Remainder (plus n 2) 8) 7)
		    (do (PrintByte!, 0)))	% fill with 0 bytes to multiple of 8
	       ))
	     (Terpri)
	     nil))
     (t 
      (progn 
	(printf " .byte ") 
	(PrintExpression 0) 
	(PrintByte!, 0) 
	(Terpri) nil)))))

(remprop 'T4 'registercode)
(put 'staticlisp 'registercode 9)
(put 'staticlisp 'RegisterName "%r9")

(remprop 'bndstklowerbound 'registercode)
(remprop 'bndstkupperbound 'registercode)
(put 'symval 'registercode 13)
(put 'symfnc 'registercode 14)
(put 'symval 'RegisterName "%r13")
(put 'symfnc 'RegisterName "%r14")

(de RegP (RegName)
    (AND (eqcar Regname 'reg)
         (MemQ (cadr RegName)
          '( 1  2  3  4  5 st t1 t2 rax rcx rdx rbx rsp rbp rsi rdi
             eax ebx ecx edx esi edi r8 r9 r10 r11 r12 r13 r14 r15
             nil heaplast heaptrapbound
             bndstkptr symval symfnc staticlisp t3
             al cl ax cx es cs ss ds fs gs))))

(setq !64bitregs '((reg 1) (reg 2) (reg 3) (reg 4) (reg 5) (reg st)
                  (reg rax) (reg rbx) (reg rcx) (reg rdx)
                  (reg t3) (reg NIL) (reg heaplast) 
                  (reg bndstkptr) (reg symval) (reg staticlisp)
                  (reg symfnc)  (reg heaptrapbound) 
                  (reg t1) (reg t2) (reg esp) (reg rdi) (reg rsi)
                  (reg r8) (reg r9) (reg r10) (reg r11)
                  (reg r12) (reg r13)(reg r14) (reg r15)
                  ))

(setq upper64bitregs '(
                  (reg t3) (reg NIL) (reg heaplast) 
                  (reg bndstkptr) (reg symval) (reg staticlisp) 
                  (reg symfnc)  (reg heaptrapbound)
                  (reg r8) (reg r9) (reg r10) (reg r11)
                  (reg r12) (reg r13)(reg r14) (reg r15)
                  (reg xmm8) (reg xmm9) (reg xmm10) (reg xmm11)
                  (reg xmm12) (reg xmm13) (reg xmm15) (reg xmm15)
                  ))


(DefCMacro *Move                          %  (*Move Source Destination)
   ( Equal              )                  % if source=dest then do nothing
   ((fixzerop   regp) (xor ArgTwo ArgTwo))
   ((Fluidp     regp) (movq (displacement (reg symval) ArgOne) ArgTwo))
   ((AnyP       regP) (mov ARGONE ARGTWO))
   ((regp     Fluidp) (movq ArgOne (displacement (reg symval) ArgTwo)))
   ((regp       anyp) (mov argone argtwo))
%   ((quotep     anyp) (movq argone argtwo))
   ((inump      anyp) (movq argone argtwo))
   (                  (*move argone (reg t1))
                      (*move (reg t1) argtwo))
   )
 

%% (DefCMacro *Call
%%    ((RegP)                (CALL ARGONE))
%%    ((InternallyCallableP) (call (InternalEntry ARGONE)))
%%    ((FastCallableP)       (call (indirect (entry ARGONE))))
%%    (                      (*move (idloc argone) (reg t1))
%%                           (call (indirect (displacement (reg symfnc) (entry ARGONE))))))

%% (DefCMacro *JCall
%%    ((RegP)                (JMP ARGONE))
%%    ((InternallyCallableP) (jmp (InternalEntry ARGONE)))
%%    ((FastCallableP)       (JMP (indirect (entry ARGONE))))
%%    (                      (*move (idloc argone) (reg t1))
%%1                          (call (indirect (displacement (reg symfnc) (entry ARGONE))))))

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
		(!*move (displacement (reg st) 88) (reg error))
		(!*move (displacement (reg st) 88) (reg error))
		(!*move (displacement (reg st) 88) (reg error))
		(!*move (displacement (reg st) 80) (reg r14))
		(!*move (displacement (reg st) 72) (reg r13))
		(!*move (displacement (reg st) 64) (reg r12))
		(!*move (displacement (reg st) 56) (reg r11))
		(!*move (displacement (reg st) 48) (reg r10))
		(!*move (displacement (reg st) 40) (reg r9))
		(!*move (displacement (reg st) 32) (reg r8))
		(!*move (displacement (reg st) 24) (reg rcx))
		(!*move (displacement (reg st) 16) (reg rdx))
		(!*move (displacement (reg st) 8) (reg rsi))
		(!*move (displacement (reg st) 0) (reg rdi)))
	   (difference 15  NumberOfArguments))
	  (append
	   (list (list '!*move '(fluid ebxsave!*) '(reg 2))
		 '(*push (reg nil)) '(*push (reg heaplast)) 
		 '(*push (reg heaptrapbound)) '(*push (reg bndstkptr)) 
		 '(*push (reg symval)) '(*push (reg symfnc))
		 '(*push (reg staticlisp))
% stack has to be aligned for SSE instructions in dyn. linking in C
                 '(!*move  (reg st) (reg 1))
                 '(sub 64 (reg st))
		 '(!*WShift (reg st) -5)
                 '(!*WShift (reg st) 5)
                 '(!*move  (reg 1) (displacement (reg st) 40))
                %% '(!*move  (displacement (reg rdi) 0) (reg rdi))
		 (list 'call (list 'ForeignEntry FunctionName))
                 '(!*move  (displacement (reg st) 40) (reg st))
                 '(*pop (reg staticlisp))
		 '(*pop (reg symfnc))'(!*pop (reg symval))
		 '(*pop (reg  bndstkptr)) '(*pop (reg heaptrapbound)) 
		 '(*pop (reg heaplast)) '(*pop (reg nil)) 
		 (list '!*move '(reg 2) '(fluid ebxsave!*)))
	   (cond
	((eq NumberOfArguments 0) nil)
	((lessp NumberOfArguments 3)
	 (list (list 'add (times 8 NumberOfArguments) '(reg st))))
	(t
	 (list (list 'add (times 8 NumberOfArguments) '(reg st))))
	))
	   )))

(de modR/M (op1 op2) 
% The modR/M byte is built from two operands.
% op1 is always a register (or an absolute code), op2
% a register or a memory reference 
(prog (OpFn mode base ireg n) 

    (when (or (regp op1) (xmmregp op1)) (setq op1 (lsh (reg2int op1 'REXR) 3)))
    (when (pairp op2) (setq mode (car op2)))

    % case: reg - reg
    (when (or (regp op2) (xmmregp op2))
         (depositbyte (lor 2#11000000 (lor op1 (reg2int op2 'REXB))))
         (return nil))
 
    % case: reg - (indirect (reg EBP/R13) ) % no format without offset
    (when (and (eq mode 'indirect)  
         (regp (cadr op2)) 
         (setq base (reg2int (cadr op2) 'REXB))
         (equal base 2#101) )
            (return (modR/M op1 (list 'displacement (cadr op2) 0))))

    % case: reg - (indirect (reg ESP/R12) )
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
          (when (or (and (equal base 2#100) (not (upperreg64p (cadr op2)))) (equal base 2#101))
            (modR/Merror op2))
          (depositbyte (lor 2#00000000 (lor op1 base)))
          (return nil))

    % case: reg - (displacement (reg ESP/R12) const)
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


    % all other cases: reg - RIP relative 32 bit displacement
    (depositbyte (lor 2#00000101 op1 ))
    (depositextension op2)))

(de lthmodR/M (op1 op2)
    % calculate the length of the address part by modR/M
    (prog (OpFn mode base ireg n)

          % case: reg - reg
          (when (regp op2) (return 1))
          (when (pairp op2) (setq mode (car op2)))

          % case: reg - (indirect (reg ESP/R12) ) 
          (when (and (eq mode   'indirect) 
                     (regp (cadr op2)) 
                     (setq base (reg2int (cadr op2) 'REXB)) 
                     (equal base 2#100) ) 
            (return 2)) 

          % case: reg - (indirect (reg EBP/R13) ) % no format without offset 
          (when (and (eq mode   'indirect)     
                     (regp (cadr op2)) 
                     (setq base (reg2int (cadr op2) 'REXB)) 
                     (equal base 2#101) ) 
            (return (lthmodR/M op1 (list 'displacement (cadr op2) 0)))) 

          % case: reg - (indirect reg) non ESP/EBP
          (when (and (eq mode   'indirect)
                     (regp (cadr op2)))
            (return 1))

          % case: reg - (displacement (reg ESP/R12) const) 
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

	  % all other cases: reg - RIP relative 32 bit displacement
	  (return 5)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (put_a_halfword (wplus2 codebase* currentoffset*)
          (if *WritingFaslFile  offset
               (wdifference offset (wplus2 currentoffset* 4)))) 
  (updatebittable 4 (const reloc_word))
  (setq currentoffset* (plus currentoffset* 4)))

(fluid '(*asmprintids))
(setq *asmprintids t)

(de asmprintvaluecell (x)
  (printexpression (list 'times (compiler-constant 'addressingunitsperitem) 
                         (list 'idloc (cadr x))))
  (prin2 "(%r13)")
%  (when *asmprintids (setq *comment (cadr x)))
  )

(de asmentry (x)
  (printexpression
   (list 'times2 
         (compiler-constant 'addressingunitsperfunctioncell) 
         (list 'idloc (cadr x))))
  (prin2 "(%r14)")
%  (when *asmprintids (setq *comment (cadr x)))
  )

(remprop 'nil-t-diff* 'constant?)
(setq nil-t-diff* 140)
(put 'nil-t-diff* 'constant? t)
