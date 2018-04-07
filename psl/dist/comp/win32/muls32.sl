%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC/MULS32.SL
% Description:  support for BIGNUM package with double INUM operations
%               lap source for 80386 processor
% Author:       H. Melenk
% Created:      11 Sept  1989
% Modified:
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
%
% Full 32 bit version : 28-June 1993 (H. Melenk)

(fluid '(*second-value* carry*))
 

(put 'wtimesdouble 'opencode
     % Called with two parameters of maximum bbase size
     % the return value are the low order bits of the product.
     % The high order bits are placed in fluid variable.
     '(% double length unsigned mutiply; 
       % EDX:EAX <- EAX * reg 
       (MUL (reg 2))
      % now we have 32 low bits in REG1, 32 high bits in REG4(=EDX)
       (*MOVE (reg EDX) ($FLUID *second-value*))
     ))

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
        (*MOVE (reg 1) (reg edx)) % high word
        (*MOVE (reg 2) (reg eax)) % low word
        (DIV (reg 3))
        (*MOVE (reg EDX) ($FLUID *second-value*))
      ))

% add and set carry
%
%   (a + b) -> (carry*,result)

(put 'addAndSetCarry 'opencode
       '(
         (ADD (reg 2)(reg 1))
           % move cf to carry*
         (SETC ($FLUID carry*))
       ))

% add with carry
%
%   (a + b + carry*) -> (carry*,result)

(put 'addwithcarry 'opencode
       '(
           % move carry* to register CF
         (*MOVE (wconst 0)(reg 3))
         (SUB ($fluid carry*)(reg 3))         
           % add with carry
         (ADC (reg 2)(reg 1))
           % move cf to carry*
         (SETC ($FLUID carry*))
       ))

% add and add carry
%
%   (a + b) -> result,  (*second-value* + carry) -> *second-value*

(put 'addAndAddCarry 'opencode
       '(
         (*move ($FLUID *second-value*) (reg 3))
         (*move 0 (reg 4))
           % add (reg 2) to (reg 1)
         (ADD (reg 2)(reg 1))
           % add carry to reg 3
         (ADC (reg 4)(reg 3))
         (*move (reg 3) ($FLUID *second-value*))
       ))

% subtract with borrow
%
%  (a - (b + carry!*)) -> result, carry*=1 if borrow

(put 'subtractwithborrow 'opencode
       '(
           % move carry* to cf
         (*MOVE (wconst 0)(reg 3))
         (SUB ($fluid carry*)(reg 3))    
           % subtract with borrow
         (sbb (reg 2)(reg 1))
           % move new borrow to carry*
         (SETC ($FLUID carry*))
       ))


%------------------- unsigned greaterp ---------------------

(commentoutcode

   % machine independent version

(put 'ugreaterp 'opencode '(
    (*move (reg 1)(reg 3))
    (*move (reg 2)(reg 4))
    (*wshift (reg 1) -1)
    (*wshift (reg 2) -1)
    (*jumpnoteq (label ugne)(reg 1)(reg 2))
    (*move (reg 3)(reg 1))
    (*move (reg 4)(reg 2))
    (*wand (reg 1) (wconst 1))
    (*wand (reg 2) (wconst 1))
ugne
    (*jumpwgreaterp ugt (reg 1)(reg 2))
    (*move (quote nil)(reg 1))
    (*jump ugret)
ugt (*move (quote T) (reg 1))
ugret
))
)

% code based on integer carry; 
 
(put 'ugreaterp* 'opencode 
   % returns 1 if arg1 > arg2 unsigned.
'( (sub (reg 1)(reg 2))        % compare, setting carry if r1>r2
   (setc (reg 1))              % move carry to low byte
   (*wand (reg 1) (wconst 1))  % clear leading bits
))

(ds ugreaterp(a b)(eq 1 (ugreaterp* a b)))

%--------------------- BIT operations --------------------------

(put 'wtz 'opencode 
'( (byte 2#00001111)   % Instruction (BSF (reg 1)(reg 1))
   (byte 2#10111100)
   (byte 2#11000000) ))
