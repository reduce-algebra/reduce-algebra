# Code to support tracing from assembly code

 .text

# Usage:
#    call acn
#    .asciz "message\n"

 .globl acn
 .globl _acn
acn:
_acn:        # return address at 128
 push %rax   # 120
 push %rbx   # 112
 push %rcx   # 104
 push %rdx   # 96
 push %rbp   # 88
 push %rsp   # 80
 push %rsi   # 72
 push %rdi   # 64
 push %r8    # 56
 push %r9    # 48
 push %r10   # 40
 push %r11   # 32
 push %r12   # 24
 push %r13   # 16
 push %r14   # 8
 push %r15   # 0

# For calling C I want to put arguments in
#  Linux:   rdi, rsi, rdx, rcx, r8, r9
#  Windows: rcx, rdx, r8, r9, stack, stack
.ifdef __WIN64__
 mov 128(%rsp), %rcx
 mov 120(%rsp), %rdx
 mov 112(%rsp), %r8
 mov 104(%rsp), %r9
.else
.ifdef __CYGWIN__
.else
 mov 128(%rsp), %rcx
 mov 120(%rsp), %rdx
 mov 112(%rsp), %r8
 mov 104(%rsp), %r9
.endif
.endif
# There must be space for 4 registers above the stack pointer, and
# the stack should be aligned at a multiple of 16 just before any CALL.
# Or possibly a multiple of 32, which is what I impose here.
 mov %rsp, %rax
 sub $64, %rsp
 shr $5, %rsp
 shl $5, %rsp
 mov %rax, 40(%rsp)
 call _acn1    # This function must return the real return address!
 mov 40(%rsp), %rsp
 mov %rax, 128(%rsp)

 pop %r15
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r9
 pop %r8
 pop %rdi
 pop %rsi
 pop %rsp
 pop %rbp
 pop %rdx
 pop %rcx
 pop %rbx
 pop %rax
 ret

# end of acn.s

