%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PX:SYS-SUPPORT.SL
% Description:  System specific kernel support functions.
% Author:       Brian Beach, Hewlett-Packard`CRC
% Created:      22-Feb-84
% Modified:     29-Jun-84 13:56:27 (RAM)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 08-Sep-89 (Winfried Neun)
%  Version for SUN386
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))

(lap '((!*entry PlantUnbound expr 1)
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (LDR (reg t1) UndefinedFunctionInstruction)
       (STR (reg t1) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (!*EXIT 0)
       (fullword 0) 
    UndefinedFunctionInstruction
       (fullword UndefinedFunction))
       )


(lap '((!*entry PlantCodePointer expr 2)
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (STR (reg 2) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (!*EXIT 0)))

(compiletime 
    (put 'CompiledCallingInterpreted 'symbol 'CompiledCallingInterpreted))
(compiletime
 (put 'CompiledCallingInterpreted 'entrypoint 'CompiledCallingInterpreted))

(lap '((!*entry PlantLambdaLink expr 1)
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (LDR (reg t1) LambdaLinkInstruction)
       (STR (reg t1) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (!*EXIT 0)
       (fullword 0)
    LambdaLinkInstruction
       (fullword CompiledCallingInterpreted)))


(lap '((*entry addressapply0 expr 1)
       (BX (reg 1))))
  
(de bittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2))
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

(lap '((*entry undefinedfunction expr 1)
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (*move (reg t3) (reg t1))
       (*JCall undefinedfunction-aux)))

   % to be redefined in nonkernel

(lap '((*entry undefinedfunction-aux expr 1)
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (*push (reg t1))
       (*move (quote "Undefined function called: ") (reg 1))
       (*call console-print-string)
       (*move (fluid symnam) (reg t2))
       (*pop (reg t1))
       (LDR (reg 1) (displacement (reg t2) (regshifted t1 LSL 2)))
       (*call console-print-string)
       (*call console-newline)
       (*move 0 (reg 1))
       (*call Exit-with-status)
       (*exit 0)
       ))

(lap '((*entry CompiledCallingInterpreted expr 0)      %. link for lambda
       %
       % Called by JMP in the function cell. Stores the ID of the interpreted
       % function in CodeForm!* without disturbing its argument registers
       %
       (*Move (reg t3) (reg t1))
       (*MKITEM (reg t1) (wconst id-tag))
       (*MOVE (reg t1) (Fluid CodeForm!*))
%       (*MOVE (idloc *tehcalledid*) (Fluid CodeForm!*))
       (*JCALL CompiledCallingInterpretedAux)))

(de kernel-fatal-error (string)
  (console-print-string "FATAL ERROR: ")
  (console-print-string string)
  (console-newline)
  (exit-with-status -1)
  )


(off fast-integers)
