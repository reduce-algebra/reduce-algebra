	LDR	X0,[X1,#12]
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
	str	X0, [fp, #-8]
	ldr	X3, [fp, #-8]
	ldr	d7, [X3]
	fcvt	s15, d7
	mov	X0, X3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	br	lr

