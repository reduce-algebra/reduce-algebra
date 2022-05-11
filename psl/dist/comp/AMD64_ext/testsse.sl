%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% testsse.sl
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(lap '((!*entry hugo expr 3)
       (movsd (indirect (reg 1))(reg xmm9))
       (movsd (indirect (reg r12)) (reg xmm1))
       (movsd (reg xmm1) (indirect (reg 2)))
       (movsd (reg xmm9) (indirect (reg r12)))
       (movsd (reg xmm12) (reg xmm1))
       (movsd (reg xmm1) (reg xmm12))
       (ucomisd (reg xmm9 ) (reg xmm8)) 
       (ucomisd (reg xmm9) (reg xmm2))
       (ucomisd (reg xmm1) (reg xmm10)) 
       (comisd (reg xmm9 ) (reg xmm8)) 
       (comisd (reg xmm9) (reg xmm2))
       (comisd (reg xmm1) (reg xmm10)) 
       (addsd (indirect (reg 1))(reg xmm9))
       (addsd (indirect (reg r12)) (reg xmm1))
       (addsd (reg xmm12) (reg xmm1))
       (addsd (reg xmm1) (reg xmm12))
       (subsd (indirect (reg 1))(reg xmm9))
       (subsd (indirect (reg 2)) (reg xmm1))
       (subsd (reg xmm12) (reg xmm1))
       (subsd (reg xmm1) (reg xmm12))
       (mulsd (indirect (reg 1))(reg xmm9))
       (mulsd (indirect (reg r12)) (reg xmm1))
       (mulsd (reg xmm12) (reg xmm1))
       (mulsd (reg xmm1) (reg xmm12))
       (divsd (indirect (reg 1))(reg xmm9))
       (divsd (indirect (reg r12)) (reg xmm1))
       (divsd (reg xmm12) (reg xmm1))
       (divsd (reg xmm1) (reg xmm12))
       (sqrtsd (indirect (reg 1))(reg xmm9))
       (sqrtsd (indirect (reg r12)) (reg xmm1))
       (sqrtsd (reg xmm12) (reg xmm1))
       (sqrtsd (reg xmm1) (reg xmm12))
       (movapd (reg xmm1) (reg xmm12))
       (movapd (reg xmm12) (reg xmm1))
       (cvtsi2sdq (indirect (reg 1))(reg xmm2))
       (cvtsi2sdq (indirect (reg r12))(reg xmm2))
       (cvtsi2sdq (indirect (reg 1))(reg xmm9))
       (cvtsi2sdq (indirect (reg r12))(reg xmm9))
       (cvttsd2si (indirect (reg 1))(reg rbx))
       (cvttsd2si (indirect (reg r12))(reg rbx))
       (cvttsd2si (indirect (reg 1))(reg r9))
       (cvttsd2si (indirect (reg r12))(reg r9))
       (movq (reg xmm12) (indirect (reg 2)))
       (movq (reg xmm1) (indirect (reg r12)))
       (movq (indirect (reg 1)) (reg xmm12))
       (movq (indirect (reg r12)) (reg xmm2))
       (movq (reg xmm1) (reg xmm12))
       (pand (indirect (reg 1)) (reg xmm9))
       (pand (indirect (reg r12)) (reg xmm1))
       (pand (reg xmm12) (reg xmm1))
       (pand (reg xmm1) (reg xmm12))
       (pandn (indirect (reg 1))(reg xmm9))
       (pandn (indirect (reg r12)) (reg xmm1))
       (pandn (reg xmm12) (reg xmm1))
       (pandn (reg xmm1) (reg xmm12))
       (por (indirect (reg 1))(reg xmm9))
       (por (indirect (reg r12)) (reg xmm1))
       (por (reg xmm12) (reg xmm1))
       (por (reg xmm1) (reg xmm12))
       (pxor (indirect (reg 1)) (reg xmm9))
       (pxor (indirect (reg r12)) (reg xmm1))
       (pxor (reg xmm12) (reg xmm1))
       (pxor (reg xmm1) (reg xmm12))
       (andpd (indirect (reg 1))(reg xmm9))
       (andpd (indirect (reg r12)) (reg xmm1))
       (andpd (reg xmm12) (reg xmm1))
       (andpd (reg xmm1) (reg xmm12))
       (andnpd (indirect (reg 1))(reg xmm9))
       (andnpd (indirect (reg r12)) (reg xmm1))
       (andnpd (reg xmm12) (reg xmm1))
       (andnpd (reg xmm1) (reg xmm12))
       (orpd (indirect (reg 1))(reg xmm9))
       (orpd (indirect (reg r12)) (reg xmm1))
       (orpd (reg xmm12) (reg xmm1))
       (orpd (reg xmm1) (reg xmm12))
       (xorpd (indirect (reg 1))(reg xmm9))
       (xorpd (indirect (reg r12)) (reg xmm1))
       (xorpd (reg xmm12) (reg xmm1))
       (xorpd (reg xmm1) (reg xmm12))
       (ldmxcsr (indirect (reg 3)) nil)
       (stmxcsr (indirect (reg 3)) nil)
       (!*exit 0)))

(lap '((!*entry *float-clear-all-except expr 0)
       (*move (wxor -1 16#3d) (reg 1))
       (*move ($fluid fpstatusloc*) (reg T1))
       (stmxcsr (indirect (reg T1)))
       (and (reg 1) (indirect (reg T1)))
       (ldmxcsr (indirect (reg T1)))
       (!*exit 0)))

%%
%% The following generates an error: the compiler doesn't know how to generate
%%  an and instruction with a 32bit immediate operand and a general address
%%
%%(lap '((!*entry *float-clear-all-except expr 0)
%%       (stmxcsr ($fluid fpstatusloc*))
%%       (and 16#ffffffc2 ($fluid fpstatusloc*))
%%       (ldmxcsr ($fluid fpstatusloc*))
%%       (!*exit 0)))
