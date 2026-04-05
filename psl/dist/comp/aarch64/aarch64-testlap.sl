%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Status:         Open Source: BSD License
%
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
%%
%% Test cases
%%
%%   20C040F9 		LDR	X0,[X1,#16]
%%   206862F8 		LDR	X0,[X1,X2, LSL #0]
%%   207862F8 		LDR	X0,[X1,X2, LSL #3]
%%   20CC40F8 		LDR	X0,[X1,#12]!
%%   206862F8 		LDR	X0,[X1,X2]!
%%   202C40F8 		LDR	X0,[X1, #2]!
%%   20C440F8 		LDR	X0,[X1],#12
%%   202440F8 		LDR	X0,[X1], #2
%%   FDCF1FF8 		str	fp, [sp, #-4]!
%%   FD030091 		add	fp, sp, #0
%%   FF3300D1 		sub	sp, sp, #12
%%   A0031FF8 		str	X0, [fp, #-16]
%%   A3035FF8 		ldr	X3, [fp, #-16]
%%   670040FD 		ldr	d7, [X3]
%%   EF40621E 		fcvt	s15, d7
%%   0000669E 		fmov    x0, d0
%%   2100261E 		fmov    w1, s1
%%   4040601E 		fmov    d0, d2
%%   6140201E 		fmov    s1, s3
%%   6200679E 		fmov    d2, x3
%%   4300271E 		fmov    s3, w2
%%   E00303AA 		mov	X0, X3
%%   BF030091 		add	sp, fp, #0
%%   FD4740F8 		ldr	fp, [sp], #4
%%   20443BD5 		mrs	x0, fpsr
%%   00443BD5 		mrs	x0, fpcr
%%   29443BD5 		mrs	x9, fpsr
%%   09423BD5 		mrs	x9, nzcv
%%   20441BD5 		msr	fpsr, x0
%%   09441BD5 		msr	fpcr, x9
%%   09421BD5 		msr	nzcv, x9
%%   400005DA 		sbc	X0, X2, X5
%%   4000055A 		sbc	W0, W2, W5
%%   400005FA 		sbcs	X0, X2, X5
%%   40D482DA 		cneg	X0, X2, gt
%%   40F0859A 		csel	X0, X2, X5, nv
%%   E1B79F9A 		cset	X1, ge
%%   E2039FDA 		csetm	x2, ne
%%   40E4859A 		csinc	X0, X2, X5, al
%%   81C4849A 		cinc	X1, X4, le
%%   610088DA 		csinv	x1, x3, x8, eq
%%   C24086DA 		cinv	X2, x6, pl
%%   224487DA 		csneg	x2, x1, x7, mi
%%   485845BA 		ccmn	x2, #5, #8, pl
%%   8CC043BA 		ccmn	x4, x3, #12, gt
%%   4709437A 		ccmp    W10, #3, #7, eq
%%   CCDA48FA 		ccmp    x22, #8, #12, le
%%   CCD243FA 		ccmp    x22, x3, #12, le
%%   C0031FD6 		br	lr
%%

(compiletime
 (off usermode)
 (cond ((null (getd 'orig-DepositInstructionBytes))
	(copyd 'orig-DepositInstructionBytes 'DepositInstructionBytes)))
(de DepositInstructionBytes (byte1 byte2 byte3 byte4)
    (printf "%x %x %x %x%n"
	    (land byte4 16#ff)
	    (land byte3 16#ff)
	    (land byte2 16#ff)
	    (land byte1 16#ff))
    (orig-DepositInstructionBytes byte1 byte2 byte3 byte4))
)

%(tr reg-or-sp-simm9)
(lap '(
       (!*entry testaarch64 expr 0)
       (ldr (reg X0) (displacement (reg X1) 16))
       (ldr (reg X0) (indexed (reg X1) (regshifted X2 LSL 0)))
       (ldr (reg X0) (indexed (reg X1) (regshifted X2 LSL 3)))
       (ldr (reg X0) (preindexed (reg X1) 12))
       (ldr (reg X0) (indexed (reg X1) (reg X2)))
       (ldr (reg X0) (preindexed (reg X1) 2))
       (ldr (reg X0) (postindexed (reg X1) 12))
       (ldr (reg X0) (postindexed (reg X1) 2))

       (str (reg fp) (preindexed (reg sp) -4))
       (add (reg fp) (reg sp) 0)
       (sub (reg sp) (reg sp) 12)
%       (stur (reg X0) (displacement (reg fp) -16)) % not yet implemented
%       (ldur (reg X3) (displacement (reg fp) -16))
       (ldr (reg d7) (indirect (reg X3)))
       (fcvt (reg s15) (reg d7))
       (fmov (reg x0) (reg d0))
       (fmov (reg w1) (reg s1))
       (fmov (reg d0) (reg d2))
       (fmov (reg s1) (reg s3))
       (fmov (reg d2) (reg x3))
       (fmov (reg s3) (reg w2))
       (mov (reg X0) (reg X3))
       (add (reg sp) (reg fp) 0)
       (ldr (reg fp) (preindexed (reg sp) 4))

       (mrs (reg x0) (reg fpsr))
       (mrs (reg x0) (reg fpcr))
       (mrs (reg x9) (reg fpsr))
       (mrs (reg x9) (reg nzcv))
       (msr (reg fpsr) (reg x0))
       (msr (reg fpcr) (reg x9))
       (msr (reg nzcv) (reg x9))

       (sbc (reg x0) (reg x2) (reg x5))
       (sbc (reg w0) (reg w2) (reg w5))
       (sbcs (reg x0) (reg x2) (reg x5))
       (cneg (reg x0) (reg x2) GT)
       (csel (reg x0) (reg x2) (reg x5) NV)
       (cset (reg x1) ge)
       (csetm (reg x2) ne)
       (csinc (reg x0) (reg x2) (reg x5) al)
       (cinc (reg x1) (reg x4) le)
       (csinv (reg x1) (reg x3) (reg x8) eq)
       (cinv (reg x2) (reg x6) pl)
       (csneg (reg x2) (reg x1) (reg x7) mi)

       (ccmn (reg x2) (wconst 5) (wconst 8) pl)
       (ccmn (reg x4) (reg x3) (wconst 12) gt)
       (ccmp (reg w10) (wconst 3) (wconst 7) eq)
       (ccmp (reg x22) (wconst 8) (wconst 12) le)
       (ccmp (reg x22) (reg x3) (wconst 12) le)

       (br (reg lr))
))
