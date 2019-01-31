%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC/MULS32.SL
% Description:  support for BIGNUM package with double INUM operations
%               lap source for 80386 processor
% Author:       H. Melenk
% Created:      11 Sept  1989
% Modified:
% Mode:         Lisp
% Status:       Open Source: BSD License
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
       % reg1:reg2 <- reg1 * reg2 
       (UMULL (reg 1) (reg 2) (reg 1) (reg 2))
      % now we have 32 low bits in REG1, 32 high bits in REG2
       (*MOVE (reg 2) ($FLUID *second-value*))
     ))
(put 'wtimesdouble 'destroys '((reg 1)(reg 2)))


(put 'wxtimes2 'opencode % different version for $pxu/mbarith
     '((SMULL (reg 1) (reg 2) (reg 1) (reg 2))
      (*MOVE (reg 2)($FLUID *second-value*))
      ))

(put 'wquotientdouble 'opencode
      % called with a double length number in params 1 and 2
      % and a single length number in par 3.
      % Result is the single length quotient.
      % the remainder is placed in a fluid variable.
      '(  % load address of fluid variable in (reg 4)
        (LDR (reg 4) (idloc *second-value*))
	(ADD (reg 4) (reg symval) (regshifted 4 LSL 2))
        (*JCall wxquotientdouble)
      ))

% add and set carry
%
%   (a + b) -> (carry*,result)

eput 'addAndSetCarry 'opencode
       '(
         (ADDS (reg 1) (reg 2) (reg 1))
           % move cf to carry*
         (MOVCC (reg 2) 0)
         (MVNCS (reg 2) 0)
         (*Move (reg 2) ($FLUID carry*))
       ))
(put 'addAndSetCarry 'destroys '((reg 1)))


% add with carry
%
%   (a + b + carry*) -> (carry*,result)

(put 'addwithcarry 'opencode
       '(
           % move carry* to register CF
	 (*Move ($fluid carry*) (reg t1))
         (RSBS (reg t1) (wconst 0) (reg t1))
           % add with carry
         (ADCS (reg 1) (reg 2) (reg 1))
           % move cf to carry*
         (MOVCC (reg t1) 0)
         (MVNCS (reg t1) 0)
         (*Move (reg t1) ($FLUID carry*))
       ))
(put 'addWithCarry 'destroys '((reg 1)))

% add and add carry
%
%   (a + b) -> result,  (*second-value* + carry) -> *second-value*

(put 'addAndAddCarry 'opencode
       '(
         (ADDS (reg 1) (reg 2) (reg 1))
         (*move ($FLUID *second-value*) (reg 2))
         (ADC (reg 2) (reg 2) (wconst 0))
         (*move (reg 2) ($FLUID *second-value*))
       ))
(put 'addAndAddCarry 'destroys '((reg 1)(reg 2)))

% subtract with borrow
%
%  (a - (b + carry!*)) -> result, carry*=1 if borrow

(put 'subtractwithborrow 'opencode
       '(
           % move carry* to cf
	 (*Move ($fluid carry*) (reg t1))
         (RSBS (reg t1) (wconst 0) (reg t1))
           % subtract with borrow
         (SBCS (reg 1) (reg 2) (reg 1))
           % move new borrow to carry*
         (MOVHI (reg t1) 0)
         (MVNLS (reg t1) 0)
         (*Move (reg t1) ($FLUID carry*))
       ))
(put 'subtractwithborrow 'destroys '((reg 1)))


%------------------- unsigned greaterp ---------------------

% code based on integer carry; 
 
(put 'ugreaterp* 'opencode 
   % returns 1 if arg1 > arg2 unsigned.
'( (RSBS (reg 1) (reg 1) (reg 2))        % compare, setting carry if r1>r2
     % move carry to lowest bit
   (MOVHI (reg 1) 0)
   (MOVLS (reg 1) 1)
))
(ds ugreaterp(a b)(eq 1 (ugreaterp* a b)))

(commentoutcode
(put 'ugreaterp 'opencode 
   % returns 1 if arg1 > arg2 unsigned.
'( (RSBS (reg 1) (reg 1) (reg 2))        % compare, setting carry if r1>r2
     % move carry to lowest bit
   (MOVHI (reg 1) (reg nil))
   (SUBLS (reg 1) (reg nil) (wconst nil-t-diff*))
))

 )


