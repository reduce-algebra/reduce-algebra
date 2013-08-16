%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PX:SYS-SUPPORT.SL
% Description:  System specific kernel support functions.
% Author:       Winfried Neun, Konrad-Zuse-Zentrum
% Created:      08-Sep-89
% Modified:     
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 
%
% Revisions:
%
% 08-Sep-89 (Winfried Neun)
%  Version for SUN386
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))

(fluid '(kernel-maxsymbols))

(de PlantUnbound (idnum)
   (if (wgreaterp idnum kernel-maxsymbols)
        (PlantUnbound-1 idnum symfnc)
     (PlantUnbound-1 idnum symfnc)
     (PlantUnbound-1 idnum old_symfnc)))

(lap '((!*entry PlantUnbound-1 expr 2)
       (add   (reg 1)  (reg 1))              % ID*2
       (mov   (reg 1)  (reg t2))
       (add   (reg t2) (reg t2))             % ID*4

       (*WPLUS2 (reg t2) (reg 2))       
       (mov (offset UndefinedFunctionInstruction) (reg t1))
       (*move (displacement (reg t1) 0) (reg t1))
       (*move (reg t1) (displacement (reg t2) 0))
       (!*EXIT 0)
       (fullword 0) 
    UndefinedFunctionInstruction
       (fullword UndefinedFunction))
       ))

(de PlantCodePointer (idnum fn) 
   (if (wgreaterp idnum kernel-maxsymbols) 
        (PlantCodePointer-1 idnum FN symfnc) 
     (PlantCodePointer-1 idnum fn symfnc) 
     (PlantCodePointer-1 idnum fn old_symfnc)))

(lap '((!*entry PlantCodePointer-1 expr 3)
       (add   (reg 1)  (reg 1))              % ID*2
       (mov   (reg 1)  (reg t2))
       (add   (reg t2) (reg t2))             % ID*4

       (!*WPLUS2 (reg t2) (reg 3))
       (*move (reg 2) (displacement (reg t2) 0))      
       (!*EXIT 0)))

(compiletime 
    (put 'CompiledCallingInterpreted 'symbol 'CompiledCallingInterpreted))
(compiletime
 (put 'CompiledCallingInterpreted 'entrypoint 'CompiledCallingInterpreted))

(de PlantLambdaLink (idnum)
   (if (wgreaterp idnum kernel-maxsymbols)
        (PlantLambdaLink-1 idnum symfnc)
     (PlantLambdaLink-1 idnum symfnc)
     (PlantLambdaLink-1 idnum old_symfnc)))

(lap '((!*entry PlantLambdaLink-1 expr 2)
       (add (reg 1)  (reg 1))              % ID*2
       (mov (reg 1)  (reg t2))
       (add (reg t2) (reg t2))             % ID*4

       (*WPLUS2 (reg t2) (reg 2))                        
       (mov  (offset LambdaLinkInstruction) (reg t1))
       (*move (displacement (reg t1) 0) (reg t1))
       (*move (reg t1) (displacement (reg t2) 0))
       (!*EXIT 0)
       (fullword 0)
    LambdaLinkInstruction
       (fullword CompiledCallingInterpreted)))


(lap '((*entry addressapply0 expr 1)
       (jmp (reg 1))))
  
(de bittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2))
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(lap '((*entry undefinedfunction expr 1)
       (jmp (indirect (entry undefinedfunction-aux)))))

   % to be redefined in nonkernel

(lap '((*entry undefinedfunction-aux expr 1)
       (*push (reg t1))
       (*move (quote "Undefined function called: ") (reg 1))
       (*call console-print-string)
       (*move (fluid symnam) (reg t2))
       (*pop (reg t1))
       (*wshift (reg t1) 2)    % * 4
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
