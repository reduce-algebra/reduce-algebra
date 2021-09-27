%%
%% Test cases
%%
%%   20C040F8 		LDR	X0,[X1,#12]
%%   206862F8 		LDR	X0,[X1,X2, LSL #0]
%%   207862F8 		LDR	X0,[X1,X2, LSL #3]
%%   20CC40F8 		LDR	X0,[X1,#12]!
%%   200C40F8 		LDR	X0,[X1,+X2]!
%%   202C40F8 		LDR	X0,[X1, #2]!
%%   20C440F8 		LDR	X0,[X1],#12
%%   200440F8 		LDR	X0,[X1],+X2
%%   202440F8 		LDR	X0,[X1], #2
%%   FDCF1FF8 		str	fp, [sp, #-4]!
%%   FD030091 		add	fp, sp, #0
%%   FF3300D1 		sub	sp, sp, #12
%%   A0831FF8 		str	X0, [fp, #-8]
%%   A3835FF8 		ldr	X3, [fp, #-8]
%%   670040FD 		ldr	d7, [X3]
%%   EF40621E 		fcvt	s15, d7
%%   E00303AA 		mov	X0, X3
%%   BF030091 		add	sp, fp, #0
%%   FD4740F8 		ldr	fp, [sp], #4
%%   C0031FD6 		br	lr
%%

(compiletime
(de DepositInstructionBytes (byte1 byte2 byte3 byte4)
    (printf "%x %x %x %x%n"
	    (land byte4 16#ff)
	    (land byte3 16#ff)
	    (land byte2 16#ff)
	    (land byte1 16#ff)))
)

(lap '(
       (!*entry testaarch64 expr 0)
       (ldr (reg X0) (displacement (reg X1) 12))
       (ldr (reg X0) (displacement (reg X1) (reg X2)))
       (ldr (reg X0) (displacement (reg X1) (regshifted X2 0)))
       (ldr (reg X0) (displacement (reg X1) (regshifted X2 3)))
%       (ldr (reg X0) (displacement (reg X1) (minus (reg X2))))
       (ldr (reg X0) (displacement (reg X1) 12 preindexed))
       (ldr (reg X0) (displacement (reg X1) (reg X2) preindexed))
       (ldr (reg X0) (displacement (reg X1) (plus (reg X2)) preindexed))
%       (ldr (reg X0) (displacement (reg X1) (minus (reg X2)) preindexed))
       (ldr (reg X0) (displacement (reg X1) 12 postindexed))
       (ldr (reg X0) (displacement (reg X1) (reg X2) postindexed))
       (ldr (reg X0) (displacement (reg X1) (plus (reg X2)) postindexed))
%       (ldr (reg X0) (displacement (reg X1) (minus (reg X2)) postindexed))

%       (ldm (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
%       (ldmfd (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
%       (ldmfa (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
%       (ldmed (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
%       (ldmea (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)

%       (B +132)
%       (B -144)

       (str (reg fp) (displacement (reg sp) -4 preindexed))
       (add (reg fp) (reg sp) 0)
       (sub (reg sp) (reg sp) 12)
       (str (reg X0) (displacement (reg fp) -8))
       (ldr (reg X3) (displacement (reg fp) -8))
       (ldr (reg d7) (indirect X3))
       (fcvt (reg s15) (reg d7))
       (mov (reg X0) (reg X3))
       (add (reg sp) (reg fp) 0)
       (ldr (reg fp) (displacement (reg sp) 4 preindexed))

       (br (reg lr))
))
