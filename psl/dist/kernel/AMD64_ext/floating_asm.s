	.file	"floating_asm.c"
	.text
	.globl	fegetexceptflag
	.type	fegetexceptflag, @function
fegetexceptflag:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
#APP
# 11 "floating_asm.c" 1
	fnstsw -6(%rbp)
stmxcsr -4(%rbp)
# 0 "" 2
#NO_APP
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	movzwl	-6(%rbp), %eax
	orl	%eax, %edx
	movl	-28(%rbp), %eax
	andl	%edx, %eax
	andl	$61, %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movw	%dx, (%rax)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fegetexceptflag, .-fegetexceptflag
	.globl	feclearexcept
	.type	feclearexcept, @function
feclearexcept:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -52(%rbp)
	andl	$61, -52(%rbp)
#APP
# 31 "floating_asm.c" 1
	fnstenv -32(%rbp)
# 0 "" 2
#NO_APP
	movzwl	-28(%rbp), %eax
	movl	-52(%rbp), %edx
	xorl	$61, %edx
	andl	%edx, %eax
	movw	%ax, -28(%rbp)
#APP
# 37 "floating_asm.c" 1
	fldenv -32(%rbp)
# 0 "" 2
# 40 "floating_asm.c" 1
	stmxcsr -36(%rbp)
# 0 "" 2
#NO_APP
	movl	-52(%rbp), %eax
	notl	%eax
	movl	%eax, %edx
	movl	-36(%rbp), %eax
	andl	%edx, %eax
	movl	%eax, -36(%rbp)
#APP
# 46 "floating_asm.c" 1
	ldmxcsr -36(%rbp)
# 0 "" 2
#NO_APP
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	feclearexcept, .-feclearexcept
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
