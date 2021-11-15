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
	br	lr

