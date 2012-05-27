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
% 08-Dec-2004 (Winfried Neun)
%  Version for AMD 64
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))

(lap '((!*entry PlantUnbound expr 1)
       (add   (reg 1)  (reg 1))              % ID*2
       (mov   (reg 1)  (reg 2))
       (add   (reg 2) (reg 2))             % ID*4
       (add   (reg 2) (reg 2))             % ID*8

       (*WPLUS2 (reg 2) (fluid SYMFNC))       
       (mov "UndefinedFunctionInstruction@GOTPCREL(%rip)" (reg t1))
       (*move (displacement (reg t1) 0) (reg t1))
       (*move (reg t1) (displacement (reg 2) 0))
       (!*EXIT 0)
       (fullword 0) 
"UndefinedFunctionInstruction"
       (fullword UndefinedFunction))
       ))


(lap '((!*entry PlantCodePointer expr 2)
       (add   (reg 1)  (reg 1))              % ID*2
       (mov   (reg 1)  (reg 3))
       (add   (reg 3) (reg 3))             % ID*4
       (add   (reg 3) (reg 3))             % ID*8

       (!*WPLUS2 (reg 3) (fluid SYMFNC))
       (*move (reg 2) (displacement (reg 3) 0))      
       (!*EXIT 0)))

(compiletime 
    (put 'CompiledCallingInterpreted 'symbol 'CompiledCallingInterpreted))
(compiletime
 (put 'CompiledCallingInterpreted 'entrypoint 'CompiledCallingInterpreted))

(lap '((!*entry PlantLambdaLink expr 1)
       (add (reg 1)  (reg 1))              % ID*2
       (mov (reg 1)  (reg 2))
       (add (reg 2) (reg 2))             % ID*4
       (add (reg 2) (reg 2))             % ID*8

       (*WPLUS2 (reg 2) (fluid SYMFNC))                        
       (mov "LambdaLinkInstruction@GOTPCREL(%rip)" (reg t1))
       (*move (displacement (reg t1) 0) (reg t1))
       (*move (reg t1) (displacement (reg 2) 0))
       (!*EXIT 0)
       (fullword 0)
    "LambdaLinkInstruction"
       (fullword CompiledCallingInterpreted)))


(lap '((*entry addressapply0 expr 1)
       (*jumphugo (reg 1))))
  
(de bittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2))
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(lap '((*entry undefinedfunction expr 1)
                  (mov "_symfnc@GOTPCREL(%rip)" (reg t3))
                  (jmp  (indirect (displacement (reg t3)
			 (entry undefinedfunction-aux))))))


   % to be redefined in nonkernel

(lap '((*entry undefinedfunction-aux expr 1)
       (*push (reg t1))
       (*move (quote "Undefined function called: ") (reg 1))
       (*call console-print-string)
       (*move (fluid symnam) (reg t2))
       (*pop (reg t1))
       (*wshift (reg t1) 3)    % * 8
       (*move (indexed (reg t1) (displacement (reg t2) 0)) (reg 1))
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
       (*move (wconst id-tag) (reg t2))
       (*MKITEM (reg t1) (reg t2))
       (*MOVE (reg t1) (Fluid CodeForm!*))
       (*JCALL CompiledCallingInterpretedAux)))

(de kernel-fatal-error (string)
  (console-print-string "FATAL ERROR: ")
  (console-print-string string)
  (console-newline)
  (exit-with-status -1)
  )

(lap '((*entry pslsignalhandler expr 0)
       (*move (quote "Interrupt") (reg 1))
       (*call stderror expr 1)))

(off fast-integers)
