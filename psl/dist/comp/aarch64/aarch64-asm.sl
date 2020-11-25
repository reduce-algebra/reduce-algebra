%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:AARCH64-ASM.SL
% Description:  AARCH64 specific information for LAP-TO-ASM
% Author:       
% Created:      16-Jan-1982
% Modified:
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1982, University of Utah
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
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(global '($eol$))

(Fluid '(CodeFileNameFormat* 
         DataFileNameFormat*
	 RoDataFileNameFormat* 
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

(setq CodeFileNameFormat* "%w.s")        % The name of the code segment file
(setq DataFileNameFormat* "d%w.s")       % The name of the writeable data segment file
(setq RoDataFileNameFormat* "ro%w.s")    % The name of the readonly data segment file
(setq InitFileNameFormat* "%w.init")     % 

(setq InputSymFile* "armv6.sym")         % default for full-kernel-build
(setq OutputSymFile* "armv6.sym")

(setq MainEntryPointName* '!m!a!i!n)     % chose a simple default
                                         % main procedure name

(setq NumericRegisterNames* '[nil "X0" "X1" "X2" "X3" "X4" "X5", "X6", "X7"])

(setq LabelFormat* "%w:%n")             % Labels are in the first column
(setq CommentFormat* "@ %p%n")          % Comments begin with at sign
                                        % will group alphabetically

(setq ExportedDeclarationFormat* " .globl %w%n")
(setq ExternalDeclarationFormat* " .globl %w%n") % All in DATA space

(setq FullWordFormat* " .long %e%n")     % FullWord expects %e for parameter
(setq HalfWordFormat* " .hword %e%n")     % Will EVAL formatter

(setq ReserveDataBlockFormat* " .bss %w,%e%n")
% This does *not* make zero blocks, however, the Sun manuals
% promise that a.out memory is init'ed to 0s
% Changed below to be like Vax version, so heap will be in bss. 
(setq ReserveZeroBlockFormat* "%w:%n  .space %e%n")

(put 'MkItem 'ASMExpressionFormat "[[%e*0x8000000]+%e]" )

(setq DefinedFunctionCellFormat* " .long %w%n")   %/ Must be LONG

(setq UndefinedFunctionCellInstructions*   '(( !.long UndefinedFunction)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%LISTS and CONSTANT DEFINITIONS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq ASMOpenParen* "(")
(setq ASMCloseParen* ")")

(DefList '((LAnd &) 
  (LOr !!)) 'BinaryASMOp)

(DefList '(     (r0 "x0")
		(r1 "x1")
		(r2 "x2")
		(r3 "x3")
		(r4 "x4")
		(r5 "x5")
		(r6 "x6")
		(r7 "x7")
		(r8 "x8")
		(r9 "x9")
		(r10 "x10")
		(r11 "x11")
		(r12 "x12")
		(r13 "x13")
		(r14 "x14")
		(r15 "x15")
		(r16 "x16")
		(r17 "x17")
		(r18 "x18")
		(r19 "x19")
		(r20 "x20")
		(r21 "x21")
		(r22 "x22")
		(r23 "x23")
		(r24 "x24")
		(r25 "x25")
		(r26 "x26")
		(r27 "x27")
		(r28 "x28")
		(r29 "x29")
		(r30 "x30")
		(rzero "XZR")
                (t1 "x9") 
  		(t2 "x10")
		(t3 "x11")
          	(fp "X29")		% C frame pointer, X29
%		(pc "pc")
		(lr "X30")		% X30
          	(sp "sp")
          	(st "sp")		% Stack Pointer
		(heaplast "X21")
		(heaptrapbound "X22")
		(symfnc "X23")
		(symval "X24")
		(bndstkptr "X25")
		(bndstklowerbound "X26")
		(bndstkupperbound "X27")
		(nil "X28")
		)
  'RegisterName)


(setq DataProcState* 'data)

%%% This put is to associate the above code with (float x) in LAP

(put 'Float 'ASMPseudoOp 'ASMPseudoPrintFloat)

(de ASMPseudoPrintFloat (x)
  (cond ((EqN (cadr x) 0.0)
         (printf "  .long 0%n  .long 0%n")
        )
        ((EqN (cadr x) 1.0)
         (printf "  .long 0x3ff00000%n  .long 0%n")
        )
  )
)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%CODE HEADERS AND TRAILERS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(de CodeFileHeader nil                  % Pure Code Segment
  (CodePrintF "        .text%n")
  (setq DataProcState* 'data) 
  (setq ForeignExternList* nil))
                
(de DataFileHeader nil 
  (DataPrintF "        .data%n")) 

(de RoDataFileHeader nil 
  (RoDataPrintF "        .section .rodata%n")) 

(de DataFileTrailer nil
    nil)

(de RoDataFileTrailer nil 
  nil)

(de CodeFileTrailer nil 
   nil)

(de CheckForeignExtern (Fn) 
  (cond
   ((not (Memq Fn ForeignExternList*))
    (setq ForeignExternList* (cons Fn ForeignExternList*)))))

(de CodeBlockHeader nil nil)            %/ Chuck this?
    

(de CodeBlockTrailer nil nil)
    

(de DataAlignFullWord nil
    (DataPrintf " .align 4%n")
    )
  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%`%%
% PRINT PROCEDURES%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


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
	     % fill with 0 bytes to a multiple of 4 if necessary
	     (cond
	      ((greaterp (Remainder (plus n 2) 4) 0)
	       (for (from i (Remainder (plus n 2) 4) 3)
		    (do (PrintByte!, 0)))	% fill with 0 bytes to multiple of 4
	       ))
	     (Terpri)
	     nil))
     (t 
      (progn 
	(printf " .byte ") 
	(PrintExpression 0) 
	(PrintByte!, 0) 
	(Terpri) nil)))))
 

(de PrintByte!, (x) 
  (progn (cond
	  ((greaterp (POSN) 40)
	   (printf "%n .byte "))
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
  (progn (printf " .byte ") 
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
  (if (not (or (lessp c (char !A)) (greaterp c (char !Z))))
      (plus (char !a) (difference c (char !A)))
      c
  )
)

%%% Mapping table for the mnemonics that Sun decided to "improve"

(setq *sun-mnemonic-change-table*
  '(
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
  (printf "#%w" x))


(de OperandPrintRegshifted (x)
    (progn (setq x (cdr x))
	   (PrintOperand (if (eqcar (car x) 'reg) (car x) (list 'reg (car x))))
	   (prin2 ", ")
	   (prin2 (cadr x))
	   (princ '! )			% SPACE
	   (PrintOperand (caddr x)))
    )

(put 'regshifted 'OperandPrintFunction 'OperandPrintRegshifted)


(de OperandPrintIndirect (x)            % (Indirect x)
  (progn (setq x (cadr x)) 
         (if (regp x) (progn
                        (prin2 "[")
	 		(PrintOperand x) 
	 		(Prin2 "]"))
               (prin2 "*")
               (PrintOperand x)
               (Prin2 "")) 
))

(De OperandPrintDisplacement (x)        % (Displacement (reg x) disp)
   (prog (Rn arg2 rest)
     (setq x (cdr x))
     (setq Rn (car x) arg2 (cadr x) rest (cddr x))
     (Prin2 "[")
     (Printoperand (car x))
     (if (eqcar rest 'postindexed) (prin2 "]"))
     (cond ((zerop arg2))
	   ((fixp arg2) (prin2 ", #") (prin2 arg2))
	   ((regp arg2) (prin2 ", ") (PrintOperand arg2))
	   ((eqcar arg2 'regshifted) (prin2 ", ") (OperandPrintRegshifted arg2))
	   ((and (eqcar arg2 'plus) (regp (cadr arg2)))
	    (prin2 ", ") (PrintOperand (cadr arg2)))
	   ((and (eqcar arg2 'minus) (regp (cadr arg2)))
	    (prin2 ", -") (PrintOperand (cadr arg2)))
	   )
     (cond ((eqcar rest 'postindexed) nil)
	   ((eqcar rest 'preindexed) (prin2 '!]!!))
           (t (prin2 "]")))
))

(put 'displacement 'OperandPrintFunction 'OperandPrintDisplacement)

(De OperandPrintIndirect (x)        % (indirect (reg x)) == (displacement (reg x) 0)
   (prog (Rn rest)
     (setq x (cdr x))
     (setq Rn (car x) rest (cdr x))
     (Prin2 "[")
     (Printoperand (car x))
     (cond ((eqcar rest 'preindexed) (prin2 '!]!!))
           (t (prin2 "]")))
))

(put 'indirect 'OperandPrintFunction 'OperandPrintIndirect)

% (Indexed (reg y)(displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) (displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) lab)   for jumpon
%
(de OperandPrintIndexed (x)  % (indexed (reg y) (displacement (reg x) disp))
  (if (regp (second x))
    (let ((part2 (third x)))
       (prin2 "[")
       (PrintRegister (cadr part2))
       (prin2 ",")
       (printexpression (third part2))))
  (if (eqcar (second x) 'times)
   (let ((part2 (third x))
         (part1 (second x)))
       (if (atom part2)
           (progn  (printexpression part2))
           (printexpression (third part2)))
       (prin2 "[")
       (when (pairp part2) (PrintRegister (cadr part2)))
       (prin2 ",")
       (PrintRegister (cadr part1))
       (prin2 ",")
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


(de OperandPrintRegList (x)             % (Reglist x)
    (progn (setq x (cdr x))
	   (prin2 "{")
	   (PrintOperand (car x)) 
	   (setq x (cdr x)) 
	   (While x 
		  (progn (Prin2 ",") 
			 (PrintOperand (car x)) 
			 (setq x (cdr x))))
	   (princ "}")
	   nil))


(put 'RegList 'OperandPrintFunction 'OperandPrintRegList)

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
 (CodePrintF "@ %p%n" x))

(de InstructionPrint (x) 
 (CodePrintF "@    %p%n" x))

(de *cerror (x) 
 (prog (i) 
    (setq i (wrs nil)) 
    (printf "%n *** CERROR: %r %n " x) 
    (wrs i) 
    (return (list (list 'cerror x)))))
 

(put 'cerror 'asmpseudoop 'printcomment)

(DefCMacro *cerror)


(de datareserveblock (x)
  (DataPrintF "  .space %w%n" (times x (compiler-constant 'addressingunitsperitem))))

% (for (from i 1 x) (do (DataPrintF " .long 0 %n"))))
% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperitem) x))
% (DataPrintF reservedatablockformat* (gensym) printexpressionform*))

(de datareservefunctioncellblock (x)
  (DataPrintF "  .space %w%n" (times x (compiler-constant 'addressingunitsperitem))))

% (for (from i 1 x) (do (DataPrintF " .long 00 %n"))))
% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperfunctioncell) x))
% (DataPrintF reservedatablockformat* (gensym) printexpressionform*))

% End of file.

