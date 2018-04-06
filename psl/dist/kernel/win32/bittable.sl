%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:BITTABLE.SL
% Package:      
% Status:       Open Source: BSD License
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


(put 'bittable 'opencode        
     '(
		 % (*PUSH (REG 2))
	(mov (REG 2) (reg 5))
		 % (*WSHIFT (REG 2) (QUOTE -2))
	(SHR (MINUS -2) (REG 2))
		 % (*LINK BYTE EXPR 2)
	(MOV (INDEXED (REG 2) (DISPLACEMENT (REG 1) 0)) (REG AL))
		 %     (CBW)
		 %     (CWDE)
		 % (*FIELD (REG 2) (reg 5) (QUOTE 30) (QUOTE 2))
	(MOV (reg 5) (REG 2))
	(AND (BITMASK 30 2) (REG 2))
		 % (*WSHIFT (REG 2) (WCONST 1))
	(ADD (REG 2) (REG 2))
		 % (*WPLUS2 (REG 2) (WCONST -6))
	(ADD -6 (REG 2))
		 % (*WSHIFT (REG 1) (REG 2))
		 %   (CMP 0 (REG 2))
		 %   (JGE "L0001")
	(NEG (REG 2))
	(XCHG (REG 2) (REG ECX))
	(SHR (REG CL) (REG 1))
		 %   (JMP "L0002")
		 %   (XCHG (REG 2) (REG ECX))
		 %   (SHL (REG CL) (REG 1))
		 %   (XCHG (REG 2) (REG ECX))
		 % (*FIELD (REG 1) (REG 1) (QUOTE 30) (QUOTE 2))
	(AND (BITMASK 30 2) (REG 1))
))
