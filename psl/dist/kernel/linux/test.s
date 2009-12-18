	.file	"test.c"
	.version	"01.01"
gcc2_compiled.:
.globl hugo
.data
	.align 4
	.type	 hugo,@object
	.size	 hugo,4
hugo:
	.long 0
.globl klaus
	.align 32
	.type	 klaus,@object
	.size	 klaus,40
klaus:
	.long 1
	.zero	36
.text
	.align 16
.globl iimain
	.type	 iimain,@function
iimain:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 16(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	call Tk_Main
	addl $16,%esp
	xorl %eax,%eax
	jmp .L2
	.p2align 4,,7
.L2:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe1:
	.size	 iimain,.Lfe1-iimain
	.comm	otto,40,32
	.ident	"GCC: (GNU) 2.95.2 19991024 (release)"
