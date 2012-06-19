	.file	"os-hooks.c"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$32, %rsp
.LCFI2:
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, %eax
	call	clear_iob
	movl	$0, %eax
	call	clear_dtabsize
	movl	$8192, %ecx
	movl	$1, %edx
	movl	$0, %esi
	movq	stdout(%rip), %rdi
	call	setvbuf
	movl	$mainenv, %edi
	call	_setjmp
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L2
	movq	-16(%rbp), %rsi
	movl	-4(%rbp), %edi
	movl	$0, %eax
	call	copy_argv
	movl	%eax, %esi
	movl	-4(%rbp), %edi
	movl	$0, %eax
	call	psl_main
.L2:
	movl	$0, %edi
	call	exit
.LFE2:
	.size	main, .-main
.globl os_startup_hook
	.type	os_startup_hook, @function
os_startup_hook:
.LFB3:
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$16, %rsp
.LCFI5:
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movl	-4(%rbp), %edi
	movl	$0, %eax
	call	setupbpsandheap
	leave
	ret
.LFE3:
	.size	os_startup_hook, .-os_startup_hook
.globl os_cleanup_hook
	.type	os_cleanup_hook, @function
os_cleanup_hook:
.LFB4:
	pushq	%rbp
.LCFI6:
	movq	%rsp, %rbp
.LCFI7:
	movl	$1, %esi
	movl	$mainenv, %edi
	call	longjmp
.LFE4:
	.size	os_cleanup_hook, .-os_cleanup_hook
.globl clear_iob
	.type	clear_iob, @function
clear_iob:
.LFB5:
	pushq	%rbp
.LCFI8:
	movq	%rsp, %rbp
.LCFI9:
	leave
	ret
.LFE5:
	.size	clear_iob, .-clear_iob
.globl clear_dtabsize
	.type	clear_dtabsize, @function
clear_dtabsize:
.LFB6:
	pushq	%rbp
.LCFI10:
	movq	%rsp, %rbp
.LCFI11:
	leave
	ret
.LFE6:
	.size	clear_dtabsize, .-clear_dtabsize
	.comm	mainenv,200,32
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	""
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.byte	0x4
	.long	.LCFI3-.LFB3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.byte	0x4
	.long	.LCFI6-.LFB4
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.byte	0x4
	.long	.LCFI8-.LFB5
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI9-.LCFI8
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.byte	0x4
	.long	.LCFI10-.LFB6
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI11-.LCFI10
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE9:
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.2 20041017 (Red Hat 3.4.2-6.fc3)"
