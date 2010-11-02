.globl _hugo
	.data
	.align 2
_hugo:
	.space 4
.globl _klaus
	.align 5
_klaus:
	.long	1
	.space 36
	.text
.globl _iimain
_iimain:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	L_Tk_Main$stub
	movl	$0, %eax
	leave
	ret
.comm _otto,48
	.section __IMPORT,__jump_table,symbol_stubs,self_modifying_code+pure_instructions,5
L_Tk_Main$stub:
	.indirect_symbol _Tk_Main
	hlt ; hlt ; hlt ; hlt ; hlt
	.subsections_via_symbols
