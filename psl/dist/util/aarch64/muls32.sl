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
% Full 64 bit version : 28-December 2004 (W. Neun)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*second-value* carry*))
 

(put 'wtimesdouble 'opencode
     % Called with two parameters of maximum bbase size
     % the return value are the low order bits of the product.
     % The high order bits are placed in fluid variable.
     '(% double length unsigned mutiply; 
       % reg1:reg2 <- reg1 * reg2
       % put high 64 bits of product in reg 3, low 64 bits in reg 1
       (UMULH (reg 3) (reg 1) (reg 2))
       (MUL (reg 1) (reg 1) (reg 2))
       % now we have 64 low bits in REG1, 64 high bits in REG3
       (*MOVE (reg 3)($FLUID *second-value*))
     ))

(put 'wxtimes2 'opencode % different version for $pxu/mbarith
     '((SMULH (reg 3) (reg 1) (reg 2))
       (MUL (reg 1) (reg 1) (reg 2))
       (*MOVE (reg 3)($FLUID *second-value*))
      ))

(put 'wquotientdouble 'opencode
      % called with a double length number in params 1 and 2,
      % high word in reg1, low word in reg2
      % and a single length number in par 3.
      % Result is the single length quotient.
      % the remainder is placed in a fluid variable.
      '(
        % wxquotientdouble expects the low word in reg1 und the high word in reg
	% exchange the two registers
	(!*Move (reg 1) (reg t1))
	(!*Move (reg 2) (reg 1))
	(!*Move (reg t1) (reg 2))
	% load address of fluid variable in (reg 4)
        (*Move (idloc *second-value*) (reg 4))
        (ADD (reg 4) (reg symval) (regshifted 4 LSL 3))
        (*Call wxquotientdouble)
      ))

% add and set carry
%
%   (a + b) -> (carry*,result)

(put 'addAndSetCarry 'opencode
       '(
         (ADDS (reg 1) (reg 1) (reg 2))
         % move cf to carry*
	 (CSET (reg t1) CS)
         (*Move (reg t1) ($FLUID carry*))
))
(put 'addAndSetCarry 'destroys '((reg 1)))


% add with carry
%
%   (a + b + carry*) -> (carry*,result)

(put 'addwithcarry 'opencode
       '(
         % set CF from carry* 
	 (*Move ($fluid carry*) (reg t1))
	 (SUBS (reg t1) (reg t1) 1)
         % add with carry
         (ADCS (reg 1) (reg 1) (reg 2))
         % move cf to carry*
	 (CSET (reg t1) CS)
         (*Move (reg t1) ($FLUID carry*))
       ))
(put 'addWithCarry 'destroys '((reg 1)))

% add and add carry
%
%   (a + b) -> result,  (*second-value* + carry) -> *second-value*

(put 'addAndAddCarry 'opencode
       '(
         (ADDS (reg 1) (reg 1) (reg 2))
         (*Move ($FLUID *second-value*) (reg 2))
         (ADC (reg 2) (reg Xzr) (reg 2))
         (*Move (reg 2) ($FLUID *second-value*))
       ))
(put 'addAndAddCarry 'destroys '((reg 1)(reg 2)))

% subtract with borrow
%
%  (a - (b + carry!*)) -> result, carry*=1 if borrow

(put 'subtractwithborrow 'opencode
       '(
         % add carry* to second parameter b
	 (*Move ($fluid carry*) (reg t1))
         (SUBS (reg xzr) (reg xzr) (reg t1))
         % subtract
         (SBCS (reg 1) (reg 1) (reg 2))
	 % move new borrow (=not(CF)) to carry* 
	 (CSET (reg t1) CC)
         (*Move (reg t1) ($FLUID carry*))
       ))
(put 'subtractwithborrow 'destroys '((reg 1)))


%------------------- unsigned greaterp ---------------------

% code based on integer carry; 
 
(put 'ugreaterp* 'opencode 
   % returns 1 if arg1 > arg2 unsigned.
     '( (SUBS (reg Xzr) (reg 2) (reg 1))        % compare, setting carry if r1>r2
        (CSET (reg 1) CC)
))

(ds ugreaterp(a b)(eq 1 (ugreaterp* a b)))


