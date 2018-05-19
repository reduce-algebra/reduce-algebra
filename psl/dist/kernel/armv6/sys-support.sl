%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PX:SYS-SUPPORT.SL
% Description:  System specific kernel support functions.
% Author:       Brian Beach, Hewlett-Packard`CRC
% Created:      22-Feb-84
% Modified:     29-Jun-84 13:56:27 (RAM)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 08-Sep-89 (Winfried Neun)
%  Version for SUN386
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))

(lap '((!*entry PlantUnbound expr 1)
       (LDR (reg t1) UndefinedFunctionInstruction)
       (STR (reg t1) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (!*EXIT 0)
       (fullword 0) 
    UndefinedFunctionInstruction
       (fullword UndefinedFunction))
       )


(lap '((!*entry PlantCodePointer expr 2)
       (*wor (reg 2) 16#8000000)
       (STR (reg 2) (displacement (reg SYMFNC) (regshifted 2 LSL 2)))
       (!*EXIT 0)))

(compiletime 
    (put 'CompiledCallingInterpreted 'symbol 'CompiledCallingInterpreted))
(compiletime
 (put 'CompiledCallingInterpreted 'entrypoint 'CompiledCallingInterpreted))

(lap '((!*entry PlantLambdaLink expr 1)
       (LDR (reg t1) LambdaLinkInstruction)
       (STR (reg t1) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (!*EXIT 0)
       (fullword 0)
    LambdaLinkInstruction
       (fullword CompiledCallingInterpreted)))


(lap '((*entry addressapply0 expr 1)
       (BLX (reg 1))))
  
(de bittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2))
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(lap '((*entry undefinedfunction expr 1)
       (*JCall undefinedfunction-aux)))

   % to be redefined in nonkernel

(lap '((*entry undefinedfunction-aux expr 1)
       (*move (reg t1) (displacement (reg st) 0 postindexed))
       (*move (quote "Undefined function called: ") (reg 1))
       (*call console-print-string)
       (*move (fluid symnam) (reg t2))
       (*move (displacement (reg st) 0 postindexed) (reg t1))
       (LDR (reg 1) (displacement (reg t2) (regshifted t1 LSL 2)))
       (*call console-print-string)
       (*move 0 (reg 1))
       (*call Exit-with-status)
       (*exit 0)
       ))

(lap '((*entry CompiledCallingInterpreted expr 0)      %. link for lambda
       %
       % Called by JMP in the function cell. Stores the ID of the interpreted
       % function in CodeForm!* without disturbing its argument registers
       %
       (*MKITEM (reg t1) (wconst id-tag))
       (*MOVE (reg t1) (Fluid CodeForm!*))
       (*JCALL CompiledCallingInterpretedAux)))

(de kernel-fatal-error (string)
  (console-print-string "FATAL ERROR: ")
  (console-print-string string)
  (console-newline)
  (exit-with-status -1)
  )


(off fast-integers)
