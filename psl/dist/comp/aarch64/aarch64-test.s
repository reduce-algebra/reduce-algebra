	LDR	X0,[X1,#16]
	LDR	X0,[X1,X2, LSL #0]
	LDR	X0,[X1,X2, LSL #3]
	LDR	X0,[X1,#12]!
	LDR	X0,[X1,X2]
	LDR	X0,[X1, #2]!
	LDR	X0,[X1],#12
	LDR	X0,[X1], #2
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	X0, [fp, #-16]
	ldr	X3, [fp, #-16]
	ldr	d7, [X3]
	fcvt	s15, d7
	fmov    x0, d0
	fmov    w1, s1
	fmov    d0, d2
	fmov    s1, s3
	fmov    d2, x3
	fmov    s3, w2
	mov	X0, X3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	mrs	x0, fpsr
	mrs	x0, fpcr
	mrs	x9, fpsr
	mrs	x9, nzcv
	msr	fpsr, x0
	msr	fpcr, x9
	msr	nzcv, x9
	sbc	X0, X2, X5
	sbc	W0, W2, W5
	sbcs	X0, X2, X5
#	subp	X0, X2, X5
#	subps	X0, X2, X5
	cneg	X0, X2, gt
	csel	X0, X2, X5, nv
	cset	X1, ge
	csetm	x2, ne
	csinc	X0, X2, X5, al
	cinc	X1, X4, le
	csinv	x1, x3, x8, eq
	cinv	X2, x6, pl
	csneg	x2, x1, x7, mi

	ccmn	x2, #5, #8, pl
	ccmn	x4, x3, #12, gt

	ccmp    W10, #3, #7, eq
	ccmp    x22, #8, #12, le
	ccmp    x22, x3, #12, le

	br	lr

