%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:os2386-ASM.SL
% Description:  Windows NT 386 specific information for LAP-TO-ASM
% Author:       
% Created:      16-Jan-1993
% Modified:
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(global '($eol$))

(Fluid '(CodeFileNameFormat* 
	 DataFileNameFormat* 
	 InitFileNameFormat* 
	 InputSymFile* 
	 OutputSymFile* 
	 CommentFormat* 
	 GlobalDataFileName* 
	 LabelFormat* 
	 ExternalDeclarationFormat* 
	 ExportedDeclarationFormat* 
	 FullWordFormat* 
	 HalfWordFormat* 
	 ReserveDataBlockFormat* 
	 ReserveZeroBlockFormat* 
	 DefinedFunctionCellFormat* 
	 UndefinedFunctionCellInstructions* 
	 MainEntryPointName* 
	 CodeOut* 
	 DataOut* 
	 *Lower 
	 ASMOpenParen* 
	 ASMCloseParen* 
	 ModuleName* 
	 NumericRegisterNames* 
	 ForeignExternList* 
	 DataProcState* 
	 PathIn*
	 printexpressionform*
	 printexpressionformpointer*
	 *declarebeforeuse))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This assembler produces two files: a code file and a data file. Both  %
% of these files are assembled to reside in the dataspace               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%FORMATS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq *DeclareBeforeUse t)

(setq CodeFileNameFormat* "%w.asm")      % The name of the code segment file
(setq DataFileNameFormat* "d%w.asm")     % postfix the "d" so that the files
					 % [20] is a reasonable guess at aU
					 % size specification

(setq InitFileNameFormat* "%w.init")     % [20] is a reasonable guess at a
					 % size specification; it may need to
					 % be changed.

(setq InputSymFile* "sun386.sym")           % default for full-kernel-build
(setq OutputSymFile* "sun386.sym")

(setq MainEntryPointName* '!m!a!i!n)     % chose a simple default
					  % main procedure name

(setq NumericRegisterNames* '[nil "eax" "ebx" "ecx" "edx" "ebp" ])

(setq LabelFormat* "%w:%n")          % Labels are in the first column
(setq dataLabelFormat* "  ALIGN 4%n%w ")
(setq CommentFormat* "; %p%n")          % Comments begin with a slash
					% will group alphabetically

(setq ExportedDeclarationFormat* " PUBLIC %w%n")
(setq ExternalDeclarationFormat* " EXTRN  %w:NEAR%n") % All in DATA space

(setq FullWordFormat* " DD %e%n")     % FullWord expects %e for parameter
(setq HalfWordFormat* " DW %e%n")     % Will EVAL formatter

(setq ReserveDataBlockFormat* " .bss %w,%e%n")
% This does *not* make zero blocks, however, the Sun manuals
% promise that a.out memory is init'ed to 0s
% Changed below to be like Vax version, so heap will be in bss. bao
(setq ReserveZeroBlockFormat* "%w  DB  %e DUP (0)%n")

(put 'MkItem 'ASMExpressionFormat "%e*08000000h+OFFSET %e" )

(setq DefinedFunctionCellFormat* " DD %w%n")   %/ Must be LONG

(setq UndefinedFunctionCellInstructions*   '(( DD UndefinedFunction)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%LISTS and CONSTANT DEFINITIONS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq ASMOpenParen* "(")
(setq ASMCloseParen* ")")

(DefList '((LAnd &) (LOr !!)) 'BinaryASMOp)

(DefList '(     (t1 "edi") (t2 "esi") (eax "eax") (al "al") (ax "ax")
		(dl "dl") (ah "ah") (bx "bx") (ebx "ebx")
		(edi "edi") (esi "esi") 
		(edx "edx") (es "es") (cs "cs") (ds "ds") (ss "ss")
		(ecx "ecx") (cl "cl") (cx "cx")
		(sp "esp") (esp "esp") (st "esp") )  % Stack Pointer
  'RegisterName)


(setq DataProcState* 'data)

%%% This put is to associate the above code with (float x) in LAP

(put 'Float 'ASMPseudoOp 'ASMPseudoPrintFloat)

(de ASMPseudoPrintFloat (x)
  (cond ((EqN (cadr x) 0.0)
	 (printf "  DD 0%n  DD 0%n")
	)
	((EqN (cadr x) 1.0)
	 (printf "  DD 0x3ff00000%n  DD 0%n")
	)
  )
)

  % dont print operand size prefix for assembler
  % (is encoded in the register name already)

(put 'OS: 'asmPseudoOp '(lambda(x) nil))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%CODE HEADERS AND TRAILERS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(de CodeFileHeader nil                  % Pure Code Segment
  (CodePrintF "        .386%n")
  (CodePrintF "DGROUP   group   _DATA, _BSS%n")
  (CodePrintF "_DATA    segment dword public 'DATA'%n")
  (CodePrintF "       include mhdr.asm %n")
  (CodePrintF "   ALIGN 4%n")
  (CodePrintF "  INCLUDE S_VA_FN.ASM%n")
  (CodePrintF "_DATA    ends%n%n")
  (CodePrintF "_BSS     segment dword public 'BSS'%n")
  (CodePrintF "_BSS     ends%n%n")
  (CodePrintF "_TEXT    segment dword public 'CODE'%n")
  (CodePrintF "         assume  CS:_TEXT%n")
  (CodePrintF "         assume  DS:DGROUP%n")
  (setq DataProcState* 'data) 
  (setq ForeignExternList* nil))
		
(de DataFileHeader nil 
  (DataPrintF "        .386%n")
  (DataPrintF "     .MODEL SMALL%n")
 )


(de DataFileTrailer nil 
    (DataPrintF "        END %n")
  nil)

(de CodeFileTrailer nil 
    (CodePrintF "_TEXT  ends%n")
    (CodePrintF "_DATA    segment dword public 'DATA'%n")
    (CodePrintF "  INCLUDE S_PR_NA.ASM%n") 
    (CodePrintF "  INCLUDE KSTRUCTS.ASM%n") 
    % (CodePrintF "  align 4%n")
    (CodePrintF "_DATA   ends%n")
    (CodePrintF "   END  %n")
   nil)

(de CheckForeignExtern (Fn) 
  (cond
   ((not (Memq Fn ForeignExternList*))
    (setq ForeignExternList* (cons Fn ForeignExternList*)))))

(de CodeBlockHeader nil nil)            %/ Chuck this?
    

(de CodeBlockTrailer nil nil)
    

(de DataAlignFullWord nil nil)
  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%`%%
% PRINT PROCEDURES%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(de PrintString (S) 
 (prog (n) 
    (cond
     ((neq (Size S) -1) 
      (progn (setq n (Size S)) 
	     (printf " DB ") 
	     (PrintExpression (Indx S 0)) 
	     (for (from i 1 n 1)
		  (do (PrintByte!, (Indx S i))))
	     (PrintByte!, 0) 
	     (cond
	      ((equal (Remainder n 2) 1)
	       (PrintByte!, 0)))
	     (Terpri)
	     nil))
     (t 
      (progn 
	(printf " DB ") 
	(PrintExpression 0) 
	(PrintByte!, 0) 
	(Terpri) nil)))))
 

(de PrintByte!, (x) 
  (progn (cond
	  ((greaterp (POSN) 40)
	   (printf "%n DB "))
	  (t (Prin2 ","))) 
	 (PrintExpression x)))
    
(de TruncateString (S n) 
  (cond
   ((leq (Size S) n)
    S)
   (t
    (SUB S 0 n))))

(de PrintByteList (L) 
    (foreach x in L do (PrintByte x)))

(de PrintByte (x) 
  (progn (printf " DB ") 
	 (PrintExpression x) 
	 (Prin2 $EOL$)))

(de PrintHalfWordList (L) 
    (foreach x in L do (PrintHalfWord x)))

(de PrintHalfWord (x) 
  (progn (printf " .word ") 
	 (PrintExpression x) 
	 (Prin2 $EOL$)))

(de PrintHalfWords (x) 
  (progn (RplacA PrintExpressionFormPointer* x) 
	 (printf HalfWordFormat* PrintExpressionForm*)))


(put 'HalfWord 'asmpseudoop 'ASMPseudoPrintHalfWords)

(de ASMPseudoPrintHalfWords (x) 
    (foreach Y in (cdr x) do (PrintHalfWord Y)))


(fluid '(*sun-mnemonic-change-table*))

%%% Print out an opcode id (derived from LAP)
%%% The Sun requires a number of transformations to the opcodes
%%% (which are based on the Motorola standard, ignored by Sun)
%%% Must change to lower case, take out the . separator, and
%%% change the names of certain mnemonics...

(de PrintOpcode (opcode)
  (let ((xform (atsoc opcode *sun-mnemonic-change-table*)))
    (if xform (setq opcode (cdr xform)))
    (prin2 (eval `(string 
	     ,@(for (in x (delete 246 (string2list (id2string opcode))))
% ausser Gefecht w.n.
		    (collect (asm-char-downcase x))
	       )
		  )
	   )
    )
  )
)

%%% Taken from PU:chars.lsp, this routine converts a character (a small
%%% number) from uppercase to lowercase.  This version is considerably
%%% simplified from the PU: one so that it works in a bare PSL (a primitive
%%% if there ever was one)

(de asm-char-downcase (c)
  (if (not (or (lessp c (char A)) (greaterp c (char Z))))
      (plus (char !a) (difference c (char !A)))
      c
  )
)

%%% Mapping table for the mnemonics that Sun decided to "improve"

(setq *sun-mnemonic-change-table*
  '(
    %(cdq     . cltd )
    %(cwde    . cwtl )
    %(cbw     . cbtw )
   )
)


(de SpecialActionForMainEntryPoint nil 
  (progn (CodePrintLabel MainEntryPointName*) 
	 (CodeDeclareExported MainEntryPointName*)))


%%% Predicate to decide whether the given id or string is a valid
%%% one to the machine's assembler (though what lap-to-asm does if
%%% this predicate fails is beyond me!)

(de ASMSymbolP (x)
  (SunSymbolP (if (idp x) (id2string x) x))
)

(de SunSymbolP (x)
  (let ((n (size x))
	(c (indx x 0))
       )
    (and (geq n 0)  % empty strings not valid
	 (or (and (geq c (char A)) (leq c (char Z)))
	     (and (geq c (char !a)) (leq c (char !z)))
	     (eqn c (char !_))
	 )
	 (for (from i 1 n)
	      (with (rslt t))
	      (while rslt)
	      (do (setq c (indx x i))
		  (setq rslt (or (and (geq c (char A)) (leq c (char Z)))
				 (and (geq c (char !a)) (leq c (char !z)))
				 (eqn c (char !_))
			     )
		  )
	      )
	      (returns rslt)
	 )
    )
  )
)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de PrintNumericOperand (x) 
  (printf "%w" x))


(de OperandPrintIndirect (x)            % (Indirect x)
  (progn (setq x (cadr x)) 
	 (if (regp x) (progn
			(prin2 (if (equal x '(reg 5))
				   "DWORD PTR ds:["
				   "DWORD PTR ["     ))
			(PrintOperand x) 
			(Prin2 "]"))
	       (prin2 "[")
	       (PrintOperand x)
	       (Prin2 "]")) 
))

(put 'Indirect 'OperandPrintFunction 'OperandPrintIndirect)

(de OperandPrintOffset (x)
    (prin2 "OFFSET " ) (printoperand (cadr x)))

(put 'offset 'OperandPrintFunction 'OperandPrintOffset)

(de OperandPrintDisplacement (x)        % (Displacement (reg x) disp)
   (progn (setq x (cdr x)) 
	  (prin2 " DWORD PTR ")
	  (PrintExpression (cadr x)) 
	  (Prin2 "[")
	  (Printoperand (car x)) 
	  (Prin2 "]")))

(put 'displacement 'OperandPrintFunction 'OperandPrintDisplacement)

% (Indexed (reg y)(displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) (displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) lab)   for jumpon
%
(de OperandPrintIndexed (x)  % (indexed (reg y) (displacement (reg x) disp))
  (if (regp (second x))
    (let ((part2 (third x)))
       (printexpression (third part2))
       (prin2 "[")
       (PrintRegister (cadr part2))
       (prin2 "][")
       (PrintRegister (cadr x))
       (prin2 "*1]")))
  (if (eqcar (second x) 'times)
   (let ((part2 (third x))
	 (part1 (second x)))
       (if (atom part2)
	   (progn  (printexpression part2))
	   (printexpression (third part2)))
       (prin2 "[")
       (when (pairp part2) (PrintRegister (cadr part2)))
       (prin2 "][")
       (PrintRegister (cadr part1))
       (prin2 "*")
       (when (not (memq (third part1) '(1 2 4 8)))
	     (error 199 "Wrong Indexed mode"))
       (prin2 (third part1))
       (prin2 "]")))
)

(put 'Indexed 'OperandPrintFunction 'OperandPrintIndexed)

(de OperandPrintImmediate (x)           % (Immediate x) % for ADDRESS
  (progn %(prin2 "#")
	 (PrintExpression (cadr x))))

(put 'Immediate 'OperandPrintFunction 'OperandPrintImmediate)


(de OperandPrintPostIncrement (x)       % (PostIncrement x)
  (progn (PrintOperand (cadr x)) 
	 (Prin2 "@+")))

(put 'PostIncrement 'OperandPrintFunction 'OperandPrintPostIncrement)

(de OperandPrintRegList (x)             % (Reglist x)
  (progn (setq x (cdr x)) 
	 (PrintOperand (car x)) 
	 (setq x (cdr x)) 
	 (While x 
		(progn (Prin2 "/") 
		       (PrintOperand (car x)) 
		       (setq x (cdr x)))) nil))


(put 'RegList 'OperandPrintFunction 'OperandPrintRegList)

(de OperandPrintPreDecrement (x)        % (PreDecrement x)
  (progn (PrintOperand (cadr x)) 
	 (Prin2 "@-")))

(put 'PreDecrement 'OperandPrintFunction 'OperandPrintPreDecrement)

(de OperandPrintAbsolute (x)            % (Absolute x)
    (PrintExpression (cadr x)))


(put 'Absolute 'OperandPrintFunction 'OperandPrintAbsolute)

(de OperandPrintForeignEntry (x)        % (ForeignEntry FcnName)
  (let ((*lower t))
       (printf "%w" (cadr x))))
  
(put 'ForeignEntry 'OperandPrintFunction 'OperandPrintForeignEntry)

(Fluid '(ResultingCode*))

(de MCPrint (x)                         % Echo of MC's
 (CodePrintF "; %p%n" x))

(de InstructionPrint (x) 
 (CodePrintF ";    %p%n" x))

(de *cerror (x) 
 (prog (i) 
    (setq i (wrs nil)) 
    (printf "%n *** CERROR: %r %n " x) 
    (wrs i) 
    (return (list (list 'cerror x)))))
 

(put 'cerror 'asmpseudoop 'printcomment)

(DefCMacro *cerror)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A HORRID patch for BRA/BRA!.W incompatibility between
% KERNEL and LAP
% In Kernel, BRA means word sized branch
% IN LAp and FASL BRA seems to mean bytes sized (?) even though
% must be coerced somewhere
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(de datareserveblock (x) nil)
%  (dataprintf " DB %w DUP (0)%n" x))

% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperitem) x))
% (dataprintf reservedatablockformat* (gensym) printexpressionform*))

(de datareservefunctioncellblock (x) nil)
%   (dataprintf " DB %w DUP (0)%n" x))    % dup(?)

% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperfunctioncell) x))
% (dataprintf reservedatablockformat* (gensym) printexpressionform*))


(de initializesymboltable ()
  (let ((maxsymbol (compiler-constant 'maxsymbols)) olddataout)
    (when (lessp maxsymbol nextidnumber*)
      (errorprintf "*** MaxSymbols %r is too small; at least %r are needed"
		   maxsymbol nextidnumber*)
      (setq maxsymbol (plus nextidnumber* 100)))
    (flag '(nil) 'nilinitialvalue)
    (put 't 'initialvalue 't)
    (setq nilnumber* (compileconstant nil))
    (setq olddataout dataout*)
    (setq dataout* (open "S_VA_FN.asm" 'output))
    (dataalignfullword)
    (initializesymval)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymfnc)
    (datareservefunctioncellblock
     (plus (difference maxsymbol nextidnumber*) 1))
    (close dataout*)
    (setq dataout* (open "S_PR_NA.asm" 'output))
    (initializesymprp)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (initializesymnam)
    (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
    (dataprintf "  DD %w DUP (?) %n" (times2 4 maxsymbol))
    (close dataout*)
    (setq dataout* olddataout)
%   (initializesymget)   % SYMGET feature
%   (datareserveblock (plus (difference maxsymbol nextidnumber*) 1))
%    (dataalignfullword)
%    (dataprintgloballabel (findgloballabel 'nextsymbol))
%    (dataprintfullword nextidnumber*)
    ))

% End of file.

