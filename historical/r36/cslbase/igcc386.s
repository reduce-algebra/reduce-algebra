
	.file	"igcc386.s"

gcc2_compiled.:
___gnu_compiled_c:
.text
	.align 2
.globl _Imultiply
_Imultiply:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	mull	12(%ebp)
	movl	8(%ebp), %ecx
	addl	20(%ebp), %eax
	adcl	$0, %edx
        addl    %eax, %eax
        adcl    %edx, %edx
        shrl	$1, %eax
	movl	%eax, 0(%ecx)
	movl	%edx, %eax
	leave
	ret
	.align 2
.globl _Idiv10_9
_Idiv10_9:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	shll	$1, %eax
	shrl	$1, %edx
	rcrl	$1, %eax
	movl	$1000000000, %ecx
	divl	%ecx
	movl	8(%ebp), %ecx
	movl	%eax, 0(%ecx)
	movl	%edx, %eax
	leave
	ret
	.align 2
.globl _Idivide
_Idivide:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	shll	$1, %eax
	shrl	$1, %edx
	rcrl	$1, %eax
	movl	20(%ebp), %ecx
	divl	%ecx
	movl	8(%ebp), %ecx
	movl	%eax, 0(%ecx)
	movl	%edx, %eax
	leave
	ret
	.align 2
