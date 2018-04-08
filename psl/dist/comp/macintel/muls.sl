%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC/MULS.SL
% Description:  support for BIGNUM package with double INUM operations
%               lap source for 80386 processor
% Author:       H. Melenk
% Created:      11 Sept  1989
% Modified:
% Mode:         Lisp
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Double length multiply and divide for the  processor.
% These are the open codes which embed the extended arithmetic 
% operations such that they are accessible from compiled LISP top level.
% They map the 2*30 bit operations needed by BIG to the 2*32 bit operations
% of the processor by shifting etc.
(fluid '(*second-value*))
 

(put 'wtimesdouble 'opencode
     % Called with two parameters of maximum bbase size
     % the return value are the low order bits of the product.
     % The high order bits are placed in fluid variable.
     '(% double length unsigned mutiply; 
       % EDX:EAX <- EAX * reg 
       (MUL (reg 2))
      % now we have 32 low bits in REG1, 32 high bits in REG4(=EDX)
       (*MOVE (reg EDX) (reg 3))
       (*WSHIFT (reg 3) 2)
       (*MOVE (reg 1) (reg 2))
       (*WSHIFT (reg 2) -30)
       (*WOR (reg 3)(reg 2))
       (*MOVE (reg 3)($FLUID *second-value*))
       (*WSHIFT (reg 1) 2)
       (*WSHIFT (reg 1) -2) ))

(put 'wxtimes2 'opencode % different version for $pxu/mbarith
     '((IMUL (reg 2))
      (*MOVE (reg 4)($FLUID *second-value*))
      ))

(put 'wquotientdouble 'opencode
      % called with a double length number in params 1 and 2
      % and a single length number in par 3.
      % Result is the single length quotient.
      % the remainder is placed in a fluid variable.
      '(  % adjusting the words first
        (*MOVE (reg 1) (reg 4))
        (*WSHIFT (reg 1) -2)
        (*WSHIFT (reg 4) 30)
        (*WOR (reg 2) (reg 4))
          % EDX:EAX / reg, EAX=Quo, EDX=Rem 
        (*MOVE (reg 1) (reg EDX)) % EDX
        (*MOVE (reg 2) (reg EAX)) % EAX
        (DIV (reg 3))
        (*MOVE (reg EDX) ($FLUID *second-value*))
        (*MOVE (reg EAX) (reg 1))))

(put 'addcarry 'opencode
       '(
         (*MOVE ($FLUID carry*) (reg 2))
         (*WPLUS2 (reg 1)(reg 2))
         (*MOVE (reg 1)(reg 3))
         (*WSHIFT (reg 3) -30)
         (*MOVE (reg 3) ($FLUID carry*))
         (*WSHIFT (reg 1) 2)
         (*WSHIFT (reg 1) -2)))

(put 'subcarry 'opencode
       '(
         (*MOVE ($FLUID carry*) (reg 2))
         (*WDIFFERENCE (reg 1)(reg 2))
         (*MOVE (reg 1) (reg 2))
         (*WSHIFT (reg 2) -31)
         (*MOVE (reg 2) ($FLUID carry*))
         (*WSHIFT (reg 2) 30)
         (*WPLUS2 (reg 1) (reg 2))
       ))
         


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   functions supporting word arithmetic with bbase*
%   bbase* is too large to be stored in a fluid cell;
%   so we perform operations with bbase* by shift and mask
%   instructions.
 
%   get the value for bbase* into a register
(put 'bbase** 'opencode
      '((*MOVE 1 (reg 1))
        (*WSHIFT (reg 1) 30)))
 
%   get the value for logicalbits* into a register     
(put 'logicalbits** 'opencode
      '((*MOVE -1 (reg 1))
        (*WSHIFT (reg 1) -2)))

%   calculate (remainder x bbase*)
(put 'remainder-bbase 'opencode
      '((*WSHIFT (reg 1) 2)
        (*WSHIFT (reg 1) -2)))

%   calculate (quotient x bbase*)
(put 'quotient-bbase 'opencode
      '((*WSHIFT (reg 1) -30)))

(put 'bbase** 'destroys '((reg 1))) 
(put 'logicalbits** 'destroys '((reg 1)))  
(put 'remainder-bbase 'destroys '((reg 1)))  
(put 'quotient-bbase 'destroys '((reg 1)))  


