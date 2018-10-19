%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:unixAMD64-ASM.SL
% Description:  AMD64 specific information for LAP-TO-ASM
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
(setq DataFileNameFormat* "d%w.s")       % postfix the "d" so that the files
                                         % [20] is a reasonable guess at aU
                                         % size specification

(setq InitFileNameFormat* "%w.init")     % [20] is a reasonable guess at a
                                         % size specification; it may need to
                                         % be changed.

(setq InputSymFile* "sun386.sym")           % default for full-kernel-build
(setq OutputSymFile* "sun386.sym")

(setq MainEntryPointName* '!m!a!i!n)     % chose a simple default
                                          % main procedure name

(setq NumericRegisterNames* '[nil "%rax" "%rbx" "%rcx" "%rdx" "%rbp" ])

(setq LabelFormat* "%w:%n")             % Labels are in the first column
(setq CommentFormat* "/ %p%n")          % Comments begin with a slash
                                        % will group alphabetically

(setq ExportedDeclarationFormat* " .globl %w%n")
(setq ExternalDeclarationFormat* " .globl %w%n") % All in DATA space

(setq FullWordFormat* " .quad %e%n")     % FullWord expects %e for parameter
(setq HalfWordFormat* " .word %e%n")     % Will EVAL formatter

(setq ReserveDataBlockFormat* " .bss %w,%e%n")
% This does *not* make zero blocks, however, the Sun manuals
% promise that a.out memory is init'ed to 0s
% Changed below to be like Vax version, so heap will be in bss. bao
(setq ReserveZeroBlockFormat* "  .comm %w,%e%n")

(put 'MkItem 'ASMExpressionFormat "[[%e<<56]+%e]" )

(setq DefinedFunctionCellFormat* " .quad %w%n")   %/ Must be LONG

(setq UndefinedFunctionCellInstructions*   '(( !.quad UndefinedFunction)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%LISTS and CONSTANT DEFINITIONS%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq ASMOpenParen* "(")
(setq ASMCloseParen* ")")

(DefList '((LAnd &) 
  (LOr !!)) 'BinaryASMOp)

(DefList '(     (t1 "%rdi") (t2 "%rsi") 
		(t3  "%r8") (t4 "%r9")
                (rax "%rax") (al "%al") (ax "%ax")
                (rbx "%rbx") (rcx "%rcx")
                (rdx "%rdx") (rdi "%rdi") (rsi "%rsi")
                (ecx "%ecx") (edx "%edx") (ebx "%ebx") (eax "%eax")
                (r8  "%r8") ( r9 "%r9") (r10 "%r10")
                (r11 "%r11") ( r12 "%r12") (r13 "%r13")
                (r14 "%r14") ( r15 "%r15") 
		(heaplast "%r10") (heaptrapbound "%r11")
		(bndstkptr "%r12") (bndstkupperbound "%r13")
		(nil  "%r15") (bndstklowerbound "%r14")
                (rcx "%rcx") (cl "%cl") (cx "%cx")
                (xmm0 "%xmm0") (xmm1 "%xmm1")
                (xmm2 "%xmm2") (xmm3 "%xmm3")
                (xmm4 "%xmm4") (xmm5 "%xmm5")
                (xmm6 "%xmm6") (xmm7 "%xmm7")
                (xmm8 "%xmm8") (xmm9 "%xmm9")
                (xmm10 "%xmm10") (xmm11 "%xmm11")
                (xmm12 "%xmm12") (xmm13 "%xmm13")
                (xmm14 "%xmm14") (xmm15 "%xmm15")
          	(sp "%rsp") (rip "%rip") 
          	(st "%rsp") )                      % Stack Pointer
  'RegisterName)

(put 'NIL 'RegisterName "%r15")

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

(de DataFileTrailer nil 
  nil)

(de CodeFileTrailer nil 
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
	     (printf " .byte ") 
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
    (cdq     . cltd )
    (cwde    . cwtl )
    (cbw     . cbtw )
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
  (printf "$%w" x))


(de OperandPrintIndirect (x)            % (Indirect x)
  (progn (setq x (cadr x)) 
         (if (regp x) (progn
                        (prin2 "(")
	 		(PrintOperand x) 
	 		(Prin2 ")"))
               (prin2 "*")
               (PrintOperand x)
               (Prin2 "")) 
))

(put 'Indirect 'OperandPrintFunction 'OperandPrintIndirect)

(de OperandPrintDisplacement (x)        % (Displacement (reg x) disp)
   (progn (setq x (cdr x)) 
	  (PrintExpression (cadr x)) 
	  (Prin2 "(")
	  (Printoperand (car x)) 
	  (Prin2 ")")))

(put 'displacement 'OperandPrintFunction 'OperandPrintDisplacement)

% (Indexed (reg y)(displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) (displacement (reg x) disp))
% or       (times (reg y) 1/2/4/8) lab)   for jumpon
%
(de OperandPrintIndexed (x)  % (indexed (reg y) (displacement (reg x) disp))
  (if (regp (second x))
    (let ((part2 (third x)))
       (printexpression (third part2))
       (prin2 "(")
       (PrintRegister (cadr part2))
       (prin2 ",")
       (PrintRegister (cadr x))
       (prin2 ",1)")))
  (if (eqcar (second x) 'times)
   (let ((part2 (third x))
         (part1 (second x)))
       (if (atom part2)
           (progn  (printexpression part2))
           (printexpression (third part2)))
       (prin2 "(")
       (when (pairp part2) (PrintRegister (cadr part2)))
       (prin2 ",")
       (PrintRegister (cadr part1))
       (prin2 ",")
       (when (not (memq (third part1) '(1 2 4 8)))
             (error 199 "Wrong Indexed mode"))
       (prin2 (third part1))
       (prin2 ")")))
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
 (CodePrintF "/ %p%n" x))

(de InstructionPrint (x) 
 (CodePrintF "/    %p%n" x))

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


(de datareserveblock (x)
  (dataprintf "  .space %w%n" (times x 8)))%ddressingunitsperitem)))

% (for (from i 1 x) (do (dataprintf " .long 0 %n"))))
% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperitem) x))
% (dataprintf reservedatablockformat* (gensym) printexpressionform*))

(de datareservefunctioncellblock (x)
  (dataprintf "  .space %w%n" (times x 8))) % addressingunitsperitem)))

% (for (from i 1 x) (do (dataprintf " .long 00 %n"))))
% (rplaca printexpressionformpointer*
%         (list 'times2 (compiler-constant 'addressingunitsperfunctioncell) x))
% (dataprintf reservedatablockformat* (gensym) printexpressionform*))

% End of file.

