        .text
 .quad 1
/ (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 ret
 .quad 0
/ (*entry move-regs-to-mem expr 0)
 .globl l0001
l0001:
 mov %r10,2144(%r13)
 mov %r11,2152(%r13)
 mov %r12,2160(%r13)
 ret
 .quad 0
/ (*entry init-pointers expr 0)
 .globl l0002
l0002:
 mov 2088(%r13),%rdi
 mov %rdi,2176(%r13)
 mov 2080(%r13),%rdi
 mov %rdi,2184(%r13)
 mov $159992,%rax
 add 2080(%r13),%rax
 mov %rax,2192(%r13)
 mov 2080(%r13),%rdi
 mov %rdi,2160(%r13)
 mov 2200(%r13),%rax
 mov %rax,2208(%r13)
 ret
 .quad 0
/ (*entry init-fluids expr 0)
 .globl l0003
l0003:
 mov %r15,%rax
 mov %rax,2224(%r13)
 mov %rax,2232(%r13)
 mov %rax,2144(%r13)
 mov %rax,2240(%r13)
 mov %rax,2152(%r13)
 mov %rax,2248(%r13)
 mov %rax,2256(%r13)
 mov %rax,2264(%r13)
 mov %rax,2272(%r13)
 mov %rax,2280(%r13)
 mov %rax,2288(%r13)
 mov %rax,2296(%r13)
 mov %rax,2304(%r13)
 mov %rax,2312(%r13)
 mov %rax,2320(%r13)
 mov %rax,2328(%r13)
 mov %rax,2336(%r13)
 mov %rax,2344(%r13)
 mov %rax,2352(%r13)
 mov %rax,2360(%r13)
 mov %rax,2368(%r13)
 mov %rax,2376(%r13)
 mov %rax,2384(%r13)
 mov %rax,2392(%r13)
 mov %rax,2400(%r13)
 mov %rax,2408(%r13)
 mov %rax,2416(%r13)
 mov %rax,2424(%r13)
 mov %rax,2432(%r13)
 mov %rax,2440(%r13)
 ret
 .quad 0
/ (*entry psl_main expr 0)
psl_main:
 .globl psl_main
 sub $24,%rsp
 mov %r15,16(%rsp)
 mov %rdi,%rax
 mov %rsi,%rbx
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rdx,%r13
 mov %r13,2456(%r13)
 mov 2464(%r13),%r14
 call *2472(%r14)
 mov 2328(%r13),%r9
 mov 2144(%r13),%r10
 mov 2152(%r13),%r11
 mov 2160(%r13),%r12
 mov $256,%r15
 shl $8,%r15
 shr $8,%r15
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%r15
 mov (%rsp),%rdi
 mov %rdi,2480(%r13)
 mov 8(%rsp),%rdi
 mov %rdi,2488(%r13)
 mov 16(%rsp),%rdi
 mov %rdi,2496(%r13)
 call *2168(%r14)
 mov %rsp,%rdx
 shr $5,%rdx
 mov %rdx,2504(%r13)
 call *2512(%r14)
l0004:
 xor %rax,%rax
 add $24,%rsp
 jmp *2520(%r14)
 add $24,%rsp
 ret
/ (*entry exit-with-status expr 1)
 .globl l0005
l0005:
 push %rax
 call *2528(%r14)
 pop %rdi
 call *2536(%r14)
 ret
 .quad 0
/ (*entry init-gcarray expr 0)
 .globl l0006
l0006:
 mov %r15,%rax
 ret
 .quad 0
/ (*entry pre-main expr 0)
 .globl l0011
l0011:
 call *2552(%r14)
 call *2560(%r14)
 call *2568(%r14)
 mov l0007,%rax
 call *2576(%r14)
 call *2584(%r14)
 mov l0008,%rax
 call *2592(%r14)
 jmp *2600(%r14)
 .quad 1
/ (*entry console-print-string expr 1)
 .globl l0012
l0012:
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 jmp *2608(%r14)
 .quad 1
/ (*entry console-print-number expr 1)
 .globl l0013
l0013:
 jmp *2624(%r14)
 .quad 0
/ (*entry console-newline expr 0)
 .globl l0014
l0014:
 mov $10,%rax
 jmp *2632(%r14)
 .quad 1
/ (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 mov l0015,%rbx
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 call *2648(%r14)
 cmp $0,%rax
 jne l0019
 mov l0016,%rax
 jmp *2656(%r14)
l0019:
 ret
 .quad 1
/ (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 jmp *2672(%r14)
 .quad 3
/ (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 mov %rbx,%rbp
 mov %rax,%rdx
 mov $8,%rbx
 mov %rbp,%rax
 jmp *2688(%r14)
 .quad 1
/ (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 jmp *2704(%r14)
 .quad 0
/ (*entry initialize-symbol-table expr 0)
 .globl l0020
l0020:
 sub $16,%rsp
 mov %r15,8(%rsp)
 mov %r15,(%rsp)
 mov $300000,%rbx
 mov 2712(%r13),%rax
 mov %rax,%rdx
 mov %rbx,%rcx
l0021:
 cmp %rcx,%rdx
 jg l0022
 mov %rdx,%rax
 shl $3,%rax
 add 2720(%r13),%rax
 mov $1,%rbx
 add %rdx,%rbx
 mov %rbx,(%rax)
 add $1,%rdx
 jmp l0021
l0022:
 mov 2720(%r13),%rsi
 movq $0,2400000(%rsi)
 mov $393241,%rbx
 xor %rax,%rax
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
l0023:
 mov (%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0024
 xor %rcx,%rcx
 mov (%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl %ecx,0(%rbx,%rax,1)
 addq $1,(%rsp)
 jmp l0023
l0024:
 mov 2720(%r13),%rdi
 mov 2048(%rdi),%rax
 call *2728(%r14)
 mov $256,%rcx
 mov %rax,%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl %ecx,0(%rbx,%rax,1)
 mov $-1,%rbx
 add 2712(%r13),%rbx
 mov $256,%rax
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
l0025:
 mov (%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0026
 mov (%rsp),%rax
 shl $3,%rax
 add 2720(%r13),%rax
 mov (%rax),%rax
 call *2728(%r14)
 mov (%rsp),%rcx
 mov %rax,%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl %ecx,0(%rbx,%rax,1)
 addq $1,(%rsp)
 jmp l0025
l0026:
 mov %r15,%rax
 mov %rax,2736(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry faslin-intern expr 1)
 .globl l0027
l0027:
 sub $24,%rsp
 mov %r15,16(%rsp)
 mov %r15,8(%rsp)
 mov %rax,(%rsp)
 mov %rax,%rbx
 xor %rax,%rax
 call *2752(%r14)
 mov %rax,8(%rsp)
 cmp %r15,%rax
 jne l0028
 mov (%rsp),%rax
 add $24,%rsp
 jmp *2760(%r14)
l0028:
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 shl $8,%rax
 sar $8,%rax
 mov %rax,16(%rsp)
 cmp 8(%rsp),%rax
 jle l0029
 mov $1,%rbx
 add 8(%rsp),%rbx
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 cmp $0,%rax
 jne l0029
 addq $1,8(%rsp)
l0029:
 mov 8(%rsp),%rdi
 cmp 16(%rsp),%rdi
 jl l0030
 mov (%rsp),%rax
 jmp l0031
l0030:
 mov (%rsp),%rcx
 shl $8,%rcx
 shr $8,%rcx
 mov (%rcx),%rcx
 shl $8,%rcx
 sar $8,%rcx
 add $1,%rcx
 mov $1,%rbx
 add 8(%rsp),%rbx
 mov (%rsp),%rax
 call *2768(%r14)
l0031:
 add $24,%rsp
 jmp *2760(%r14)
 .quad 1
/ (*entry intern expr 1)
 .globl intern
intern:
 jmp *2776(%r14)
 .quad 1
/ (*entry unchecked-string-intern expr 1)
 .globl l0036
l0036:
 sub $48,%rsp
 mov %rax,(%rsp)
 mov %r15,%rbp
 mov %rbp,%rdx
 mov %rbp,%rcx
 mov %rax,%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov (%rbx),%rbx
 shl $8,%rbx
 sar $8,%rbx
 shl $8,%rax
 shr $8,%rax
 mov %rax,8(%rsp)
 mov %rbx,16(%rsp)
 mov %rcx,24(%rsp)
 mov %rdx,32(%rsp)
 mov %rbp,40(%rsp)
 cmp $0,%rbx
 jne l0037
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 and $255,%rax
 shl $8,%rax
 shr $8,%rax
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%rax
 jmp l0038
l0037:
 mov (%rsp),%rax
 call *2728(%r14)
 mov %rax,%rbx
 mov %rbx,24(%rsp)
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl 0(%rbx,%rax,1),%eax
 shl $32,%rax
 shr $32,%rax
 mov %rax,%rbx
 cmp l0032,%rax
 jl l0039
 mov %r15,%rax
 jmp l0040
l0039:
 mov l0033,%rax
l0040:
 cmp %r15,%rax
 je l0041
 mov l0033(%rip),%rax
 cmp $0,%rbx
 jg l0041
 add $140,%rax
l0041:
 cmp %r15,%rax
 je l0042
 mov 24(%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl 0(%rbx,%rax,1),%eax
 shl $32,%rax
 shr $32,%rax
 shl $8,%rax
 shr $8,%rax
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%rax
 jmp l0038
l0042:
 cmp 2736(%r13),%rax
 je l0043
 mov l0034,%rax
 call *2576(%r14)
 mov (%rsp),%rax
 call *2576(%r14)
 call *2584(%r14)
l0043:
 call *2784(%r14)
 mov %rax,40(%rsp)
 mov %rax,%rcx
 mov 24(%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl %ecx,0(%rbx,%rax,1)
 mov 16(%rsp),%rax
 call *2792(%r14)
 mov %rax,32(%rsp)
 mov 8(%rsp),%rbx
 call *2800(%r14)
 mov 32(%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov 40(%rsp),%rax
 add $48,%rsp
 jmp *2808(%r14)
l0038:
 add $48,%rsp
 ret
 .quad 1
/ (*entry hash-into-table expr 1)
 .globl l0047
l0047:
 sub $32,%rsp
 mov %r15,24(%rsp)
 mov %r15,16(%rsp)
 mov %r15,8(%rsp)
 mov %rax,(%rsp)
 call *2816(%r14)
 mov %rax,8(%rsp)
 mov %rax,16(%rsp)
 movq $-1,24(%rsp)
l0048:
 mov 16(%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl 0(%rbx,%rax,1),%eax
 shl $32,%rax
 shr $32,%rax
 cmp $0,%rax
 jne l0049
 cmpq $-1,24(%rsp)
 je l0050
 mov 24(%rsp),%rax
 jmp l0051
l0050:
 mov 16(%rsp),%rax
l0051:
 jmp l0052
l0049:
 mov 16(%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl 0(%rbx,%rax,1),%eax
 mov %rax,%rbx
 shl $32,%rbx
 shr $32,%rbx
 cmp l0044,%rbx
 jne l0053
 cmpq $-1,24(%rsp)
 jne l0054
 mov 16(%rsp),%rdi
 mov %rdi,24(%rsp)
 jmp l0054
l0053:
 mov 16(%rsp),%rbx
 mov 2096(%r13),%rax
 shl $2,%rbx
 movl 0(%rbx,%rax,1),%eax
 mov (%rsp),%rbx
 shl $32,%rax
 shr $32,%rax
 shl $3,%rax
 add 2720(%r13),%rax
 mov (%rax),%rax
 call *2824(%r14)
 cmp %r15,%rax
 je l0054
 mov 16(%rsp),%rax
 jmp l0052
l0054:
 cmpq $393241,16(%rsp)
 jne l0055
 xor %rax,%rax
 jmp l0056
l0055:
 mov $1,%rax
 add 16(%rsp),%rax
l0056:
 mov %rax,16(%rsp)
 cmp 8(%rsp),%rax
 jne l0048
 mov l0045,%rax
 call *2656(%r14)
 jmp l0048
l0052:
 add $32,%rsp
 ret
 .quad 2
/ (*entry initialize-new-id expr 2)
 .globl l0057
l0057:
 sub $16,%rsp
 mov %rax,(%rsp)
 shl $8,%rax
 shr $8,%rax
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%rax
 mov %rax,8(%rsp)
 mov (%rsp),%rcx
 shl $3,%rcx
 add 2720(%r13),%rcx
 mov %rbx,(%rcx)
 mov (%rsp),%rdx
 shl $3,%rdx
 add 2832(%r13),%rdx
 mov %r15,%rbp
 mov %rbp,(%rdx)
 mov (%rsp),%rax
 shl $3,%rax
 add 2840(%r13),%rax
 mov %rbp,(%rax)
 mov (%rsp),%rax
 shl $3,%rax
 add %r13,%rax
 mov (%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $253,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov %rbx,(%rax)
 mov (%rsp),%rax
 call *2848(%r14)
 mov 8(%rsp),%rax
 add $16,%rsp
 ret
 .quad 1
/ (*entry hash-function expr 1)
 .globl l0060
l0060:
 sub $40,%rsp
 mov %r15,24(%rsp)
 mov %r15,8(%rsp)
 shl $8,%rax
 shr $8,%rax
 mov %rax,16(%rsp)
 mov (%rax),%rax
 shl $8,%rax
 sar $8,%rax
 mov %rax,(%rsp)
 xor %rax,%rax
 mov %rax,32(%rsp)
 cmpq $20,(%rsp)
 jle l0061
 movq $20,(%rsp)
l0061:
 mov (%rsp),%rbx
 xor %rax,%rax
 mov %rax,24(%rsp)
 mov %rbx,8(%rsp)
l0062:
 mov 24(%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0063
 mov 24(%rsp),%rbx
 mov $8,%rax
 add 16(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 mov $56,%rbx
 sub 24(%rsp),%rbx
 cmp $0,%rbx
 jge l0058
 neg %rbx
 xchg %rbx,%rcx
 shr %cl,%rax
 jmp l0059
l0058:
 xchg %rbx,%rcx
 shl %cl,%rax
l0059:
 xchg %rbx,%rcx
 mov 32(%rsp),%rdi
 xor %rdi,%rax
 mov %rax,32(%rsp)
 addq $1,24(%rsp)
 jmp l0062
l0063:
 mov $393241,%rbx
 mov 32(%rsp),%rax
 add $40,%rsp
 xor %rdx,%rdx
 idiv %rbx
 mov %rdx,%rax
 ret
 .quad 1
/ (*entry faslin expr 1)
 .globl faslin
faslin:
 sub $96,%rsp
 mov %r15,72(%rsp)
 mov %r15,32(%rsp)
 mov %r15,24(%rsp)
 mov %rax,(%rsp)
 mov %r15,40(%rsp)
 mov %r15,8(%rsp)
 mov %r15,56(%rsp)
 mov %r15,64(%rsp)
 mov %r15,88(%rsp)
 mov %r15,16(%rsp)
 mov %r15,48(%rsp)
 mov %r15,80(%rsp)
 call *2640(%r14)
 mov %rax,24(%rsp)
 call *2664(%r14)
 mov %rax,32(%rsp)
 mov $65535,%rbx
 and %rax,%rbx
 cmpq $399,%rbx
 je l0064
 mov 24(%rsp),%rax
 call *2696(%r14)
 mov (%rsp),%rax
 call *2872(%r14)
 jmp l0065
l0064:
 mov 32(%rsp),%rax
 shr $16,%rax
 mov %rax,32(%rsp)
 mov 24(%rsp),%rax
 call *2664(%r14)
 mov 24(%rsp),%rax
 call *2880(%r14)
 mov %rax,40(%rsp)
 mov 8(%rsp),%rax
 mov $357,%rdi
 call *2856(%r14)
 mov 8(%rsp),%rcx
 xor %rbx,%rbx
 add %rax,%rbx
 mov 24(%rsp),%rax
 call *2680(%r14)
 mov 24(%rsp),%rax
 call *2664(%r14)
 mov %rax,56(%rsp)
 call *2888(%r14)
 mov %rax,64(%rsp)
 xor %rax,%rax
 call *2888(%r14)
 mov %rax,80(%rsp)
 mov 24(%rsp),%rax
 call *2664(%r14)
 mov 64(%rsp),%rbx
 add %rax,%rbx
 mov %rbx,88(%rsp)
 mov 64(%rsp),%rax
 mov $358,%rdi
 call *2864(%r14)
 mov 56(%rsp),%rcx
 xor %rbx,%rbx
 add %rax,%rbx
 mov 24(%rsp),%rax
 call *2680(%r14)
 mov 24(%rsp),%rax
 call *2664(%r14)
 mov %rax,16(%rsp)
 call *2896(%r14)
 mov %rax,%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $7,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov %rbx,48(%rsp)
 mov 16(%rsp),%rcx
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 mov 24(%rsp),%rax
 call *2680(%r14)
 mov 24(%rsp),%rax
 call *2696(%r14)
 mov $1,%rax
 and 32(%rsp),%rax
 cmpq $1,%rax
 jne l0066
 mov 40(%rsp),%rdx
 mov 48(%rsp),%rcx
 mov 56(%rsp),%rbx
 mov 64(%rsp),%rax
 call *2904(%r14)
 jmp l0067
l0066:
 mov 40(%rsp),%rdx
 mov 48(%rsp),%rcx
 mov 56(%rsp),%rbx
 mov 64(%rsp),%rax
 call *2912(%r14)
l0067:
 mov 2920(%r13),%rax
 mov %rax,72(%rsp)
 mov 64(%rsp),%rdi
 mov %rdi,2920(%r13)
 mov 88(%rsp),%rax
 call *2928(%r14)
 mov 72(%rsp),%rdi
 mov %rdi,2920(%r13)
 mov 80(%rsp),%rbx
 mov 88(%rsp),%rax
 call *2936(%r14)
l0065:
 mov %r15,%rax
 add $96,%rsp
 ret
 .quad 2
/ (*entry delbps expr 2)
 .globl delbps
delbps:
 mov %r15,%rax
 ret
 .quad 4
/ (*entry do-relocation expr 4)
 .globl l0068
l0068:
 sub $48,%rsp
 mov %r15,32(%rsp)
 mov %rax,24(%rsp)
 mov %rcx,8(%rsp)
 mov %rdx,16(%rsp)
 mov %rbx,%rax
 shl $3,%rax
 mov $-1,%rbx
 add %rax,%rbx
 xor %rax,%rax
 mov %rax,40(%rsp)
 mov %rbx,(%rsp)
l0069:
 mov 40(%rsp),%rdi
 cmp (%rsp),%rdi
 jle l0070
 mov %r15,%rax
 jmp l0071
l0070:
 mov 40(%rsp),%rbx
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 mov $368,%rdi
 call *2944(%r14)
 mov 24(%rsp),%rbx
 add 40(%rsp),%rbx
 mov %rbx,32(%rsp)
 cmpq $1,%rax
 je l0072
 cmpq $2,%rax
 je l0073
 cmpq $3,%rax
 je l0074
 jmp l0075
l0072:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 call *2960(%r14)
 jmp l0075
l0074:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 call *2968(%r14)
 jmp l0075
l0073:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 mov $369,%rdi
 call *2952(%r14)
l0075:
 addq $1,40(%rsp)
 jmp l0069
l0071:
 add $48,%rsp
 ret
 .quad 4
/ (*entry do-relocation-new expr 4)
 .globl l0076
l0076:
 sub $48,%rsp
 mov %r15,16(%rsp)
 mov %rax,32(%rsp)
 mov %rcx,(%rsp)
 mov %rdx,24(%rsp)
 mov %r15,%rcx
 mov %rax,%rbx
 xor %rax,%rax
 mov %rax,8(%rsp)
 mov %rbx,40(%rsp)
 mov (%rsp),%rbp
 shl $8,%rbp
 shr $8,%rbp
 add $8,%rbp
 mov %rbp,(%rsp)
l0077:
 mov 8(%rsp),%rbx
 mov (%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 and $255,%rax
 mov %rax,16(%rsp)
 cmp $0,%rax
 jne l0078
 mov %r15,%rax
 jmp l0079
l0078:
 addq $1,8(%rsp)
 mov $63,%rax
 and 16(%rsp),%rax
 add 40(%rsp),%rax
 mov %rax,40(%rsp)
 mov 16(%rsp),%rbx
 shr $6,%rbx
 mov %rbx,16(%rsp)
 mov %rbx,%rax
 cmpq $1,%rax
 je l0080
 cmpq $2,%rax
 je l0081
 cmpq $3,%rax
 je l0082
 jmp l0077
l0080:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 call *2960(%r14)
 jmp l0077
l0082:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 call *2968(%r14)
 jmp l0077
l0081:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 mov $369,%rdi
 call *2952(%r14)
 jmp l0077
l0079:
 add $48,%rsp
 ret
 .quad 3
/ (*entry relocate-word expr 3)
 .globl l0083
l0083:
 sub $48,%rsp
 mov %r15,40(%rsp)
 mov %r15,32(%rsp)
 mov %r15,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov 0(%rax),%eax
 mov %rax,24(%rsp)
 mov (%rsp),%rax
 mov 0(%rax),%eax
 mov %rax,%rbx
 shl $34,%rbx
 shr $34,%rbx
 mov 24(%rsp),%rax
 shl $32,%rax
 shr $62,%rax
 mov %rax,24(%rsp)
 mov %rbx,32(%rsp)
 mov (%rsp),%rax
 mov $358,%rdi
 call *2864(%r14)
 mov %rax,40(%rsp)
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 24(%rsp),%rax
 call *2976(%r14)
 mov %rax,%rbx
 mov 40(%rsp),%rax
 add $48,%rsp
 mov %ebx,0(%rax)
 ret
 .quad 3
/ (*entry relocate-inf expr 3)
 .globl l0084
l0084:
 sub $56,%rsp
 mov %r15,48(%rsp)
 mov %r15,40(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov (%rax),%rbx
 shl $42,%rbx
 shr $42,%rbx
 mov (%rax),%rax
 shr $54,%rax
 and $3,%rax
 mov %rax,24(%rsp)
 mov %rbx,32(%rsp)
 mov (%rsp),%rax
 mov $358,%rdi
 call *2864(%r14)
 mov %rax,40(%rsp)
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 24(%rsp),%rax
 call *2976(%r14)
 mov %rax,48(%rsp)
 mov (%rsp),%rsi
 mov (%rsi),%rax
 shr $56,%rax
 shl $56,%rax
 or 48(%rsp),%rax
 mov 40(%rsp),%rsi
 mov %rax,(%rsi)
 add $56,%rsp
 ret
 .quad 4
/ (*entry compute-relocation expr 4)
 .globl l0085
l0085:
 push %rbx
 cmp $0,%rax
 jne l0086
 mov %rcx,%rax
 add %rbx,%rax
 jmp l0087
l0086:
 cmpq $2,%rax
 jne l0088
 cmpq $8150,%rbx
 jl l0089
 mov $-8156,%rax
 add %rbx,%rax
 shl $3,%rax
 add 2064(%r13),%rax
 jmp l0087
l0089:
 cmpq $2048,%rbx
 jl l0090
 mov %rdx,%rbx
 mov (%rsp),%rax
 call *2984(%r14)
 shl $3,%rax
 jmp l0087
l0090:
 mov %rbx,%rax
 shl $3,%rax
 jmp l0087
l0088:
 cmpq $3,%rax
 jne l0091
 cmpq $2048,%rbx
 jl l0092
 mov %rdx,%rbx
 mov (%rsp),%rax
 call *2984(%r14)
 mov %rax,(%rsp)
l0092:
 mov (%rsp),%rax
 shl $3,%rax
 add %r14,%rax
 jmp l0087
l0091:
 cmpq $1,%rax
 jne l0093
 cmpq $2048,%rbx
 jl l0094
 mov %rdx,%rbx
 mov (%rsp),%rax
 add $8,%rsp
 jmp *2984(%r14)
l0094:
 mov %rbx,%rax
 jmp l0087
l0093:
 mov %r15,%rax
l0087:
 add $8,%rsp
 ret
 .quad 2
/ (*entry local-to-global-id expr 2)
 .globl l0095
l0095:
 add $-2047,%rax
 shl $3,%rax
 mov %rbx,%rcx
 shl $8,%rcx
 shr $8,%rcx
 add %rcx,%rax
 mov (%rax),%rax
 ret
 .quad 1
/ (*entry read-id-table expr 1)
 .globl l0096
l0096:
 sub $48,%rsp
 mov %r15,40(%rsp)
 mov %r15,32(%rsp)
 mov %r15,24(%rsp)
 mov %r15,16(%rsp)
 mov %r15,8(%rsp)
 mov %rax,(%rsp)
 call *2664(%r14)
 mov %rax,8(%rsp)
 add $1,%rax
 call *2896(%r14)
 shl $8,%rax
 shr $8,%rax
 mov $7,%rdi
 shl $56,%rdi
 or %rdi,%rax
 mov %rax,16(%rsp)
 mov 8(%rsp),%rbx
 xor %rax,%rax
 mov %rax,24(%rsp)
 mov %rbx,32(%rsp)
l0097:
 mov 24(%rsp),%rdi
 cmp 32(%rsp),%rdi
 jg l0098
 mov (%rsp),%rax
 call *2664(%r14)
 mov 2072(%r13),%rsi
 mov %rax,(%rsi)
 mov $9,%rcx
 add %rax,%rcx
 mov %rcx,%rbx
 shr $61,%rbx
 add %rbx,%rcx
 sar $3,%rcx
 mov $8,%rbx
 add 2072(%r13),%rbx
 mov (%rsp),%rax
 call *2680(%r14)
 xor %rax,%rax
 add 2072(%r13),%rax
 shl $8,%rax
 shr $8,%rax
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rax
 call *2744(%r14)
 mov %rax,40(%rsp)
 mov $1,%rax
 add 24(%rsp),%rax
 shl $3,%rax
 mov 16(%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 add %rbx,%rax
 mov 40(%rsp),%rcx
 shl $8,%rcx
 shr $8,%rcx
 mov %rcx,(%rax)
 addq $1,24(%rsp)
 jmp l0097
l0098:
 mov 16(%rsp),%rax
 add $48,%rsp
 ret
 .quad 3
/ (*entry putentry expr 3)
 .globl putentry
putentry:
 add 2920(%r13),%rcx
 shl $8,%rcx
 shr $8,%rcx
 mov $20,%rdi
 shl $56,%rdi
 or %rdi,%rcx
 mov $374,%rdi
 jmp *2992(%r14)
 .quad 1
/ (*entry faslin-bad-file expr 1)
 .globl l0101
l0101:
 mov l0099,%rax
 call *2576(%r14)
 jmp *2584(%r14)
 .quad 1
/ (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 sub $8,%rsp
l0105:
 mov %rax,(%rsp)
 cmp %r15,%rax
 jne l0106
 call *3008(%r14)
l0106:
 cmpq $10,(%rsp)
 jle l0107
 mov $15,%rax
 and 2296(%r13),%rax
 cmp $0,%rax
 je l0107
 mov 2296(%r13),%rbx
 shr $4,%rbx
 shl $4,%rbx
 add $16,%rbx
 mov %rbx,2296(%r13)
l0107:
 mov 2296(%r13),%rax
 mov (%rsp),%rbx
 shl $3,%rbx
 add 2296(%r13),%rbx
 mov %rbx,2296(%r13)
 cmp 2272(%r13),%rbx
 jle l0108
 mov %rax,2296(%r13)
 mov l0102,%rax
 call *3016(%r14)
 cmp %r15,%rax
 je l0109
 mov (%rsp),%rax
 call *3024(%r14)
 cmp %r15,%rax
 je l0109
 mov (%rsp),%rax
 jmp l0105
l0109:
 mov l0103,%rax
 add $8,%rsp
 jmp *3032(%r14)
l0108:
 add $8,%rsp
 ret
 .quad 0
/ (*entry gtbps-nil-error expr 0)
 .globl l0112
l0112:
 mov l0110,%rax
 jmp *3032(%r14)
 .quad 1
/ (*entry bpsaddr-to-bpsaddr-rw expr 1)
 .globl l0113
l0113:
 add 2304(%r13),%rax
 sub 2312(%r13),%rax
 ret
 .quad 1
/ (*entry gtstaticlisp expr 1)
 .globl gtstaticlisp
gtstaticlisp:
 sub $8,%rsp
l0119:
 mov %rax,(%rsp)
 cmp %r15,%rax
 jne l0120
 mov l0114,%rax
 call *3032(%r14)
l0120:
 mov 2344(%r13),%rax
 mov (%rsp),%rbx
 shl $3,%rbx
 add 2344(%r13),%rbx
 mov %rbx,2344(%r13)
 cmp 2336(%r13),%rbx
 jle l0121
 mov %rax,2344(%r13)
 mov l0115,%rax
 call *3016(%r14)
 cmp %r15,%rax
 je l0122
 mov (%rsp),%rax
 mov $380,%rdi
 call *3040(%r14)
 cmp %r15,%rax
 je l0122
 mov (%rsp),%rax
 jmp l0119
l0122:
 mov l0116,%rax
 add $8,%rsp
 jmp *3032(%r14)
l0121:
 add $8,%rsp
 ret
 .quad 1
/ (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 cmp %r15,%rax
 jne l0123
 jmp *3056(%r14)
l0123:
 jmp *3064(%r14)
 .quad 1
/ (*entry real-gtheap expr 1)
 .globl l0124
l0124:
 mov %rax,%rcx
 mov %r10,%rax
 mov %rcx,%rbx
 shl $3,%rbx
 add %r10,%rbx
 mov %rbx,%r10
 cmp %r11,%rbx
 jl l0125
 mov %rcx,%rbx
 jmp *3072(%r14)
l0125:
 ret
 .quad 1
/ (*entry get-heap-trap expr 1)
 .globl l0128
l0128:
 mov l0126,%rax
 jmp *2656(%r14)
 .quad 0
/ (*entry gtid expr 0)
 .globl gtid
gtid:
 cmp $0,2712(%r13)
 jne l0131
 call *3080(%r14)
 cmp $0,2712(%r13)
 jne l0131
 mov l0129,%rax
 call *2656(%r14)
l0131:
 mov 2712(%r13),%rax
 mov %rax,%rbx
 shl $3,%rbx
 add 2720(%r13),%rbx
 mov (%rbx),%rdi
 mov %rdi,2712(%r13)
 ret
 .quad 1
/ (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 push %rax
 add $2,%rax
 call *3048(%r14)
 mov (%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $249,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov %rbx,(%rax)
 add $8,%rsp
 ret
 .quad 1
/ (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 sub $16,%rsp
 mov %rax,(%rsp)
 add $9,%rax
 mov %rax,%rbx
 shr $61,%rbx
 add %rbx,%rax
 sar $3,%rax
 mov %rax,8(%rsp)
 add $1,%rax
 mov $357,%rdi
 call *2856(%r14)
 mov (%rsp),%rdi
 mov %rdi,(%rax)
 mov 8(%rsp),%rbx
 shl $3,%rbx
 add %rax,%rbx
 movq $0,(%rbx)
 add $16,%rsp
 ret
 .quad 3
/ (*entry subseq expr 3)
 .globl subseq
subseq:
 sub $64,%rsp
 mov %r15,56(%rsp)
 mov %r15,48(%rsp)
 mov %r15,40(%rsp)
 mov %r15,32(%rsp)
 mov %r15,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $4,%rdi
 je l0134
 mov l0132,%rax
 call *2656(%r14)
l0134:
 mov $-1,%rax
 add 16(%rsp),%rax
 sub 8(%rsp),%rax
 mov %rax,24(%rsp)
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov %rax,32(%rsp)
 mov 24(%rsp),%rax
 call *3088(%r14)
 mov %rax,40(%rsp)
 mov 24(%rsp),%rbx
 xor %rax,%rax
 mov %rax,48(%rsp)
 mov %rbx,56(%rsp)
l0135:
 mov 48(%rsp),%rdi
 cmp 56(%rsp),%rdi
 jg l0136
 mov 8(%rsp),%rbx
 add 48(%rsp),%rbx
 mov $8,%rax
 add 32(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 mov %rax,%rcx
 mov 48(%rsp),%rbx
 mov $8,%rax
 add 40(%rsp),%rax
 movb %cl,0(%rbx,%rax,1)
 addq $1,48(%rsp)
 jmp l0135
l0136:
 mov 40(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rax
 add $64,%rsp
 ret
 .quad 2
/ (*entry search-string-for-character expr 2)
 .globl l0137
l0137:
 sub $32,%rsp
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 shl $8,%rbx
 shr $8,%rbx
 mov (%rbx),%rbx
 shl $8,%rbx
 sar $8,%rbx
 xor %rax,%rax
 mov %rax,16(%rsp)
 mov %rbx,24(%rsp)
l0138:
 mov 16(%rsp),%rdi
 cmp 24(%rsp),%rdi
 jle l0139
 mov %r15,%rax
 jmp l0140
l0139:
 mov 16(%rsp),%rbx
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 cmp (%rsp),%rax
 jne l0141
 mov 16(%rsp),%rax
 jmp l0140
l0141:
 addq $1,16(%rsp)
 jmp l0138
l0140:
 add $32,%rsp
 ret
 .quad 2
/ (*entry unchecked-string-equal expr 2)
 .globl l0143
l0143:
 sub $40,%rsp
 mov %r15,32(%rsp)
 mov %r15,24(%rsp)
 shl $8,%rax
 shr $8,%rax
 mov %rax,(%rsp)
 shl $8,%rbx
 shr $8,%rbx
 mov %rbx,8(%rsp)
 mov (%rax),%rcx
 shl $8,%rcx
 sar $8,%rcx
 mov %rcx,16(%rsp)
 mov (%rbx),%rdx
 shl $8,%rdx
 sar $8,%rdx
 cmp %rdx,%rcx
 je l0144
 mov %r15,%rax
 jmp l0145
l0144:
 movq $0,24(%rsp)
l0146:
 mov 24(%rsp),%rdi
 cmp 16(%rsp),%rdi
 jle l0147
 mov l0142,%rax
 jmp l0145
l0147:
 mov 24(%rsp),%rbx
 mov $8,%rax
 add (%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 mov %rax,32(%rsp)
 mov 24(%rsp),%rbx
 mov $8,%rax
 add 8(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 cmp 32(%rsp),%rax
 je l0148
 mov %r15,%rax
 jmp l0145
l0148:
 addq $1,24(%rsp)
 jmp l0146
l0145:
 add $40,%rsp
 ret
 .quad 2
/ (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 sub $32,%rsp
 mov %rax,24(%rsp)
 mov %rax,%rcx
 shl $8,%rcx
 shr $8,%rcx
 mov %rcx,8(%rsp)
 mov %rbx,%rdx
 shl $8,%rdx
 shr $8,%rdx
 mov %rdx,16(%rsp)
 mov (%rdx),%rbp
 shl $8,%rbp
 sar $8,%rbp
 mov %rbp,(%rsp)
 mov (%rcx),%rax
 shl $8,%rax
 sar $8,%rax
 cmp %rbp,%rax
 jge l0149
 mov %rax,(%rsp)
l0149:
 mov $9,%rax
 add (%rsp),%rax
 mov %rax,%rbx
 shr $61,%rbx
 add %rbx,%rax
 sar $3,%rax
 add $-1,%rax
 mov %rax,(%rsp)
 mov %rax,%rbx
 xor %rax,%rax
 mov %rax,%rdx
 mov %rbx,%rcx
l0150:
 cmp %rcx,%rdx
 jg l0151
 mov $1,%rax
 add %rdx,%rax
 shl $3,%rax
 add 8(%rsp),%rax
 mov $1,%rbx
 add %rdx,%rbx
 shl $3,%rbx
 add 16(%rsp),%rbx
 mov (%rbx),%rdi
 mov %rdi,(%rax)
 add $1,%rdx
 jmp l0150
l0151:
 mov 24(%rsp),%rax
 add $32,%rsp
 ret
 .quad 2
/ (*entry cons expr 2)
 .globl cons
cons:
 push %rbx
 push %rax
 mov $2,%rax
 call *3048(%r14)
 mov (%rsp),%rdi
 mov %rdi,(%rax)
 mov 8(%rsp),%rdi
 mov %rdi,8(%rax)
 shl $8,%rax
 shr $8,%rax
 mov $9,%rdi
 shl $56,%rdi
 or %rdi,%rax
 add $16,%rsp
 ret
 .quad 1
/ (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 shl $3,%rax
 add %r13,%rax
 mov (%rax),%rax
 ret
 .quad 2
/ (*entry modify expr 2)
 .globl modify
modify:
 shl $3,%rax
 add %r13,%rax
 mov %rbx,(%rax)
 mov %rbx,%rax
 ret
 .quad 3
/ (*entry put expr 3)
 .globl put
put:
 jmp *3128(%r14)
 .quad 3
/ (*entry unchecked-put expr 3)
 .globl l0152
l0152:
 sub $32,%rsp
 mov %r15,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 call *3136(%r14)
 mov %rax,24(%rsp)
 mov %rax,%rbx
 mov 8(%rsp),%rax
 call *3144(%r14)
 cmp %r15,%rax
 je l0153
 mov %rax,%rsi
 shl $8,%rsi
 shr $8,%rsi
 mov 16(%rsp),%rdi
 mov %rdi,8(%rsi)
 jmp l0154
l0153:
 mov 16(%rsp),%rbx
 mov 8(%rsp),%rax
 mov %rax,0(%r10)
 mov $9,%rax
 shl $56,%rax
 add %r10,%rax
 mov %rbx,8(%r10)
 add $16,%r10
 cmp %r11,%r10
 jl l0155
 push %rax
 call *3152(%r14)
 pop %rax
l0155:
 mov 24(%rsp),%rbx
 mov %rax,0(%r10)
 mov $9,%rax
 shl $56,%rax
 add %r10,%rax
 mov %rbx,8(%r10)
 add $16,%r10
 cmp %r11,%r10
 jl l0156
 push %rax
 call *3152(%r14)
 pop %rax
l0156:
 mov %rax,%rbx
 mov (%rsp),%rax
 call *3160(%r14)
l0154:
 mov 16(%rsp),%rax
 add $32,%rsp
 ret
 .quad 2
/ (*entry atsoc expr 2)
 .globl atsoc
atsoc:
l0157:
 mov %rbx,%rdi
 shr $56,%rdi
 cmp $9,%rdi
 je l0158
 mov %r15,%rax
 ret
l0158:
 mov %rbx,%rdi
 shl $8,%rdi
 shr $8,%rdi
 mov (%rdi),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0159
 mov %rbx,%rsi
 shl $8,%rsi
 shr $8,%rsi
 mov (%rsi),%rsi
 shl $8,%rsi
 shr $8,%rsi
 cmp (%rsi),%rax
 jne l0159
 mov %rbx,%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 ret
l0159:
 shl $8,%rbx
 shr $8,%rbx
 mov 8(%rbx),%rbx
 jmp l0157
 .quad 2
/ (*entry unchecked-setprop expr 2)
 .globl l0160
l0160:
 shl $8,%rax
 shr $8,%rax
 shl $3,%rax
 add 2832(%r13),%rax
 mov %rbx,(%rax)
 mov %rbx,%rax
 ret
 .quad 1
/ (*entry unchecked-prop expr 1)
 .globl l0161
l0161:
 shl $8,%rax
 shr $8,%rax
 shl $3,%rax
 add 2832(%r13),%rax
 mov (%rax),%rax
 ret
 .quad 3
/ (*entry putd expr 3)
 .globl putd
putd:
 jmp *3168(%r14)
 .quad 3
/ (*entry code-putd expr 3)
 .globl l0166
l0166:
 sub $24,%rsp
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $254,%rdi
 jne l0167
 mov %rbx,%rdi
 shr $56,%rdi
 cmp $254,%rdi
 jne l0167
 mov %rcx,%rdi
 shr $56,%rdi
 cmp $20,%rdi
 je l0168
l0167:
 mov l0162,%rax
 call *2656(%r14)
l0168:
 mov 16(%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 call *3176(%r14)
 mov 8(%rsp),%rdi
 cmp l0163,%rdi
 je l0169
 mov 8(%rsp),%rcx
 mov l0164,%rbx
 mov (%rsp),%rax
 add $24,%rsp
 jmp *3120(%r14)
l0169:
 mov %r15,%rax
 add $24,%rsp
 ret
 .quad 1
/ (*entry fluid expr 1)
 .globl fluid
fluid:
 sub $24,%rsp
 mov %r15,16(%rsp)
 mov %rax,(%rsp)
 mov %r15,%rax
 mov (%rsp),%rdi
 mov %rdi,8(%rsp)
 mov 8(%rsp),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0170
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 jmp l0171
l0170:
 mov %r15,%rax
l0171:
 mov %rax,16(%rsp)
l0172:
 mov 8(%rsp),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 je l0173
 mov %r15,%rax
 jmp l0174
l0173:
 mov 16(%rsp),%rax
 call *3192(%r14)
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov 8(%rax),%rax
 mov %rax,8(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0175
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 jmp l0176
l0175:
 mov %r15,%rax
l0176:
 mov %rax,16(%rsp)
 jmp l0172
l0174:
 add $24,%rsp
 ret
 .quad 1
/ (*entry fluid1 expr 1)
 .globl l0179
l0179:
 mov l0177,%rcx
 mov l0178,%rbx
 jmp *3120(%r14)
 .quad 1
/ (*entry stderror expr 1)
 .globl stderror
stderror:
 jmp *2656(%r14)
 .quad 2
/ (*entry *define-constant expr 2)
 .globl l0182
l0182:
 mov %rax,%rcx
 shl $8,%rcx
 shr $8,%rcx
 shl $3,%rcx
 add %r13,%rcx
 mov %rbx,(%rcx)
 mov l0180,%rcx
 mov l0181,%rbx
 jmp *3120(%r14)
 .quad 1
/ (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 add %rax,%rax
 mov %rax,%rsi
 add %rsi,%rsi
 add %rsi,%rsi
 add %r14,%rsi
 mov l0183(%rip),%rdi
 mov %rdi,0(%rsi)
 ret
 .quad 0
l0183:
 .quad undefinedfunction
 .quad 2
/ (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 add %rax,%rax
 mov %rax,%rsi
 add %rsi,%rsi
 add %rsi,%rsi
 add %r14,%rsi
 mov %rbx,0(%rsi)
 ret
 .quad 1
/ (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 add %rax,%rax
 mov %rax,%rsi
 add %rsi,%rsi
 add %rsi,%rsi
 add %r14,%rsi
 mov l0184(%rip),%rdi
 mov %rdi,0(%rsi)
 ret
 .quad 0
l0184:
 .quad compiledcallinginterpreted
 .quad 1
/ (*entry addressapply0 expr 1)
 .globl l0185
l0185:
 jmp *%rax
 .quad 1
/ (*entry addressapplyx expr 1)
 .globl addressapplyx
addressapplyx:
 call *%rax
 ret
 .quad 2
/ (*entry bittable expr 2)
 .globl bittable
bittable:
 push %rbx
 shr $2,%rbx
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cdqe
 mov (%rsp),%rbx
 shl $30,%rbx
 shr $62,%rbx
 add %rbx,%rbx
 add $-6,%rbx
 cmp $0,%rbx
 jge l0186
 neg %rbx
 xchg %rbx,%rcx
 shr %cl,%rax
 jmp l0187
l0186:
 xchg %rbx,%rcx
 shl %cl,%rax
l0187:
 xchg %rbx,%rcx
 shl $30,%rax
 shr $62,%rax
 add $8,%rsp
 ret
 .quad 1
/ (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 jmp *3232(%r14)
 .quad 1
/ (*entry undefinedfunction-aux expr 1)
 .globl l0190
l0190:
 push %rdi
 mov l0188,%rax
 call *2576(%r14)
 mov 2720(%r13),%rsi
 pop %rdi
 shl $3,%rdi
 mov 0(%rsi,%rdi,1),%rax
 call *2576(%r14)
 xor %rax,%rax
 call *2520(%r14)
 ret
 .quad 0
/ (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 mov $254,%rsi
 shl $8,%rdi
 shr $8,%rdi
 shl $56,%rsi
 or %rsi,%rdi
 mov %rdi,3248(%r13)
 jmp *3256(%r14)
 .quad 1
/ (*entry kernel-fatal-error expr 1)
 .globl l0193
l0193:
 push %rax
 mov l0191,%rax
 call *2576(%r14)
 mov (%rsp),%rax
 call *2576(%r14)
 call *2584(%r14)
 mov $-1,%rax
 add $8,%rsp
 jmp *2520(%r14)
 .quad 0
/ (*entry pslsignalhandler expr 0)
 .globl pslsignalhandler
pslsignalhandler:
 mov l0194,%rax
 call *3032(%r14)
 .quad 0
/ (*entry echoon expr 0)
 .globl l0196
l0196:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call echoon
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 0
/ (*entry echooff expr 0)
 .globl l0197
l0197:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call echooff
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 1
/ (*entry external_charsininputbuffer expr 1)
 .globl l0198
l0198:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_charsininputbuffer
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry flushstdoutputbuffer expr 0)
 .globl l0199
l0199:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call flushstdoutputbuffer
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 0
/ (*entry external_user_homedir_string expr 0)
 .globl l0200
l0200:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_user_homedir_string
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 1
/ (*entry external_anyuser_homedir_string expr 1)
 .globl l0201
l0201:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_anyuser_homedir_string
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry alterheapsize expr 1)
 .globl l0202
l0202:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call alterheapsize
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry allocatemorebps expr 1)
 .globl l0203
l0203:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call allocatemorebps
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry get_imagefilepath expr 0)
 .globl l0204
l0204:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call get_imagefilepath
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 3
/ (*entry get_file_status expr 3)
 .globl l0205
l0205:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call get_file_status
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 2
/ (*entry os_startup_hook expr 2)
 .globl l0206
l0206:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call os_startup_hook
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 0
/ (*entry os_cleanup_hook expr 0)
 .globl l0207
l0207:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call os_cleanup_hook
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 0
/ (*entry get_execfilepath expr 0)
 .globl l0208
l0208:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call get_execfilepath
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 1
/ (*entry external_alarm expr 1)
 .globl l0209
l0209:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_alarm
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_ualarm expr 2)
 .globl l0210
l0210:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_ualarm
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_time expr 1)
 .globl l0211
l0211:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_time
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_timc expr 1)
 .globl l0212
l0212:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_timc
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_stat expr 2)
 .globl l0213
l0213:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_stat
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry external_link expr 2)
 .globl l0214
l0214:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_link
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_strlen expr 1)
 .globl l0215
l0215:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_strlen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_unlink expr 1)
 .globl l0216
l0216:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_unlink
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_setenv expr 2)
 .globl l0217
l0217:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_setenv
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_rmdir expr 1)
 .globl l0218
l0218:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_rmdir
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_mkdir expr 2)
 .globl l0219
l0219:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_mkdir
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_getenv expr 1)
 .globl l0220
l0220:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_getenv
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry uxfloat expr 2)
 .globl l0221
l0221:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxfloat
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry uxfix expr 1)
 .globl l0222
l0222:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxfix
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry uxassign expr 2)
 .globl l0223
l0223:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxassign
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry uxplus2 expr 3)
 .globl l0224
l0224:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxplus2
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxdifference expr 3)
 .globl l0225
l0225:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxdifference
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxtimes2 expr 3)
 .globl l0226
l0226:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxtimes2
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxquotient expr 3)
 .globl l0227
l0227:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxquotient
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 2
/ (*entry uxminus expr 2)
 .globl l0228
l0228:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxminus
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 4
/ (*entry uxgreaterp expr 4)
 .globl l0229
l0229:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxgreaterp
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 4
/ (*entry uxlessp expr 4)
 .globl l0230
l0230:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxlessp
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 3
/ (*entry uxwritefloat expr 3)
 .globl l0231
l0231:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxwritefloat
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 4
/ (*entry uxwritefloat8 expr 4)
 .globl l0232
l0232:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxwritefloat8
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 2
/ (*entry uxdoubletofloat expr 2)
 .globl l0233
l0233:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxdoubletofloat
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxfloattodouble expr 2)
 .globl l0234
l0234:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxfloattodouble
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxsin expr 2)
 .globl l0235
l0235:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxsin
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxcos expr 2)
 .globl l0236
l0236:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxcos
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxtan expr 2)
 .globl l0237
l0237:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxtan
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxasin expr 2)
 .globl l0238
l0238:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxasin
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxacos expr 2)
 .globl l0239
l0239:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxacos
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxatan expr 2)
 .globl l0240
l0240:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxatan
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxsqrt expr 2)
 .globl l0241
l0241:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxsqrt
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxexp expr 2)
 .globl l0242
l0242:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxexp
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxlog expr 2)
 .globl l0243
l0243:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxlog
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry uxatan2 expr 3)
 .globl l0244
l0244:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call uxatan2
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 0
/ (*entry external_pwd expr 0)
 .globl l0245
l0245:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_pwd
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 2
/ (*entry sun3_sigset expr 2)
 .globl l0246
l0246:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call sun3_sigset
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry mask_signal expr 2)
 .globl l0247
l0247:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call mask_signal
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 4
/ (*entry unexec expr 4)
 .globl l0248
l0248:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unexec
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry unixputc expr 1)
 .globl l0249
l0249:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixputc
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry unixputs expr 1)
 .globl l0250
l0250:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixputs
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry unixputn expr 1)
 .globl l0251
l0251:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixputn
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry unixcleario expr 0)
 .globl l0252
l0252:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixcleario
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 1
/ (*entry expand_file_name expr 1)
 .globl l0253
l0253:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call expand_file_name
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry unixopen expr 2)
 .globl l0254
l0254:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixopen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry unixcd expr 1)
 .globl l0255
l0255:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixcd
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry ctime expr 1)
 .globl l0256
l0256:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call ctime
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_system expr 1)
 .globl l0257
l0257:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_system
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_fullpath expr 1)
 .globl l0258
l0258:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_fullpath
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_exit expr 1)
 .globl l0259
l0259:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call external_exit
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry fopen expr 2)
 .globl l0260
l0260:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fopen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry fclose expr 1)
 .globl l0261
l0261:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fclose
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 4
/ (*entry fread expr 4)
 .globl l0262
l0262:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fread
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 2
/ (*entry fputc expr 2)
 .globl l0263
l0263:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fputc
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry fgetc expr 1)
 .globl l0264
l0264:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fgetc
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 3
/ (*entry fgets expr 3)
 .globl l0265
l0265:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fgets
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 4
/ (*entry fwrite expr 4)
 .globl l0266
l0266:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fwrite
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry fflush expr 1)
 .globl l0267
l0267:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fflush
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 3
/ (*entry fseek expr 3)
 .globl l0268
l0268:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fseek
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry clearerr expr 1)
 .globl l0269
l0269:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call clearerr
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry xgetw expr 1)
 .globl l0270
l0270:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call xgetw
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry putw expr 2)
 .globl l0271
l0271:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call putw
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry signal expr 2)
 .globl l0272
l0272:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call signal
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry sleep expr 1)
 .globl l0273
l0273:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call sleep
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 3
/ (*entry ieee_handler expr 3)
 .globl l0274
l0274:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call ieee_handler
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 4
/ (*entry ieee_flags expr 4)
 .globl l0275
l0275:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call ieee_flags
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry setlinebuf expr 1)
 .globl l0276
l0276:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call setlinebuf
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry getpid expr 0)
 .globl l0277
l0277:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call getpid
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 0
/ (*entry gethostid expr 0)
 .globl l0278
l0278:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call gethostid
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 2
/ (*entry unixsocketopen expr 2)
 .globl l0279
l0279:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixsocketopen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry getsocket expr 3)
 .globl l0280
l0280:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call getsocket
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry writesocket expr 3)
 .globl l0281
l0281:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call writesocket
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry unixclosesocket expr 1)
 .globl l0282
l0282:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call unixclosesocket
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry fork expr 0)
 .globl l0283
l0283:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call fork
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 1
/ (*entry wait expr 1)
 .globl l0284
l0284:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call wait
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry popen expr 2)
 .globl l0285
l0285:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call popen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pclose expr 1)
 .globl l0286
l0286:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pclose
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 3
/ (*entry shmctl expr 3)
 .globl l0287
l0287:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call shmctl
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry shmget expr 3)
 .globl l0288
l0288:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call shmget
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry shmat expr 3)
 .globl l0289
l0289:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call shmat
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry shmdt expr 1)
 .globl l0290
l0290:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call shmdt
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 4
/ (*entry semctl expr 4)
 .globl l0291
l0291:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call semctl
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 3
/ (*entry semget expr 3)
 .globl l0292
l0292:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call semget
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry semop expr 3)
 .globl l0293
l0293:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call semop
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 2
/ (*entry dlopen expr 2)
 .globl l0294
l0294:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call dlopen
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry dlerror expr 1)
 .globl l0295
l0295:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call dlerror
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry dlsym expr 2)
 .globl l0296
l0296:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call dlsym
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry dlclose expr 1)
 .globl l0297
l0297:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call dlclose
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 4
/ (*entry unix-profile expr 4)
 .globl l0298
l0298:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call profil
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 4
/ (*entry pthread_create expr 4)
 .globl l0299
l0299:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_create
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry pthread_exit expr 1)
 .globl l0300
l0300:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_exit
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_join expr 2)
 .globl l0301
l0301:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_join
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pthread_detach expr 1)
 .globl l0302
l0302:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_detach
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 0
/ (*entry pthread_self expr 0)
 .globl l0303
l0303:
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_self
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 ret
 .quad 2
/ (*entry pthread_equal expr 2)
 .globl l0304
l0304:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_equal
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pthread_attr_init expr 1)
 .globl l0305
l0305:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_attr_destroy expr 1)
 .globl l0306
l0306:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setdetachstate expr 2)
 .globl l0307
l0307:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setdetachstate
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getguardsize expr 2)
 .globl l0308
l0308:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getguardsize
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setguardsize expr 2)
 .globl l0309
l0309:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setguardsize
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getschedparam expr 2)
 .globl l0310
l0310:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getschedparam
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setschedparam expr 2)
 .globl l0311
l0311:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setschedparam
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getschedpolicy expr 2)
 .globl l0312
l0312:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getschedpolicy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setschedpolicy expr 2)
 .globl l0313
l0313:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setschedpolicy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getinheritsched expr 2)
 .globl l0314
l0314:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getinheritsched
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setinheritsched expr 2)
 .globl l0315
l0315:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setinheritsched
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getscope expr 2)
 .globl l0316
l0316:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getscope
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setscope expr 2)
 .globl l0317
l0317:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setscope
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry pthread_attr_getstack expr 3)
 .globl l0318
l0318:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getstack
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry pthread_attr_setstack expr 3)
 .globl l0319
l0319:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setstack
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_getstacksize expr 2)
 .globl l0320
l0320:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_getstacksize
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_attr_setstacksize expr 2)
 .globl l0321
l0321:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_attr_setstacksize
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry pthread_setschedparam expr 3)
 .globl l0322
l0322:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_setschedparam
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 3
/ (*entry pthread_getschedparam expr 3)
 .globl l0323
l0323:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_getschedparam
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry pthread_getconcurrency expr 1)
 .globl l0324
l0324:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_getconcurrency
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_yield expr 1)
 .globl l0325
l0325:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_yield
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_once expr 2)
 .globl l0326
l0326:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_once
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_setcancelstate expr 2)
 .globl l0327
l0327:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_setcancelstate
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_setcanceltype expr 2)
 .globl l0328
l0328:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_setcanceltype
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pthread_cancel expr 1)
 .globl l0329
l0329:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cancel
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_testcancel expr 1)
 .globl l0330
l0330:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_testcancel
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_mutex_init expr 2)
 .globl l0331
l0331:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutex_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pthread_mutex_destroy expr 1)
 .globl l0332
l0332:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutex_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_mutex_trylock expr 1)
 .globl l0333
l0333:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutex_trylock
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_mutex_lock expr 1)
 .globl l0334
l0334:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutex_lock
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_mutex_unlock expr 1)
 .globl l0335
l0335:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutex_unlock
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_mutexattr_init expr 1)
 .globl l0336
l0336:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutexattr_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_mutexattr_destroy expr 1)
 .globl l0337
l0337:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_mutexattr_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_rwlock_unlock expr 1)
 .globl l0338
l0338:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_rwlock_unlock
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_rwlockattr_init expr 1)
 .globl l0339
l0339:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_rwlockattr_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_rwlockattr_destroy expr 1)
 .globl l0340
l0340:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_rwlockattr_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_rwlockattr_getpshared expr 2)
 .globl l0341
l0341:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_rwlockattr_getpshared
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 2
/ (*entry pthread_rwlockattr_setpshared expr 2)
 .globl l0342
l0342:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_rwlockattr_setpshared
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry pthread_cond_init expr 3)
 .globl l0343
l0343:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry pthread_cond_destroy expr 1)
 .globl l0344
l0344:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_cond_signal expr 1)
 .globl l0345
l0345:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_signal
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_cond_broadcast expr 1)
 .globl l0346
l0346:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_broadcast
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_cond_wait expr 2)
 .globl l0347
l0347:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_wait
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry pthread_cond_timedwait expr 3)
 .globl l0348
l0348:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_cond_timedwait
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 1
/ (*entry pthread_condattr_init expr 1)
 .globl l0349
l0349:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_condattr_init
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_condattr_destroy expr 1)
 .globl l0350
l0350:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_condattr_destroy
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_key_create expr 2)
 .globl l0351
l0351:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_key_create
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 1
/ (*entry pthread_key_delete expr 1)
 .globl l0352
l0352:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_key_delete
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 1
/ (*entry pthread_getspecific expr 1)
 .globl l0353
l0353:
 push %rax
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_getspecific
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $8,%rsp
 ret
 .quad 2
/ (*entry pthread_setspecific expr 2)
 .globl l0354
l0354:
 push %rbx
 push %rax
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_setspecific
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $16,%rsp
 ret
 .quad 3
/ (*entry pthread_atfork expr 3)
 .globl l0355
l0355:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r13
 push %r14
 push %r9
 mov %rsp,%rax
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rax,40(%rsp)
 call pthread_atfork
 mov 40(%rsp),%rsp
 pop %r9
 pop %r14
 pop %r13
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $24,%rsp
 ret
 .quad 2
/ (*entry psl-dlopen expr 2)
 .globl l0358
l0358:
 sub $16,%rsp
 mov %r15,8(%rsp)
 mov %rax,(%rsp)
 mov $1,%rbx
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 call *3968(%r14)
 mov %rax,8(%rsp)
 cmp $0,%rax
 jne l0359
 mov (%rsp),%rbx
 mov l0356,%rax
 add $16,%rsp
 jmp *4472(%r14)
l0359:
 mov 8(%rsp),%rax
 add $16,%rsp
 ret
 .quad 0
/ (*entry psl-dlerror expr 0)
 .globl l0362
l0362:
 mov $1,%rax
 call *4488(%r14)
 mov l0360,%rdi
 mov %rdi,(%rax)
 ret
 .quad 2
/ (*entry psl-dlsym expr 2)
 .globl l0363
l0363:
 push %r15
 push %rax
 mov %rbx,%rdi
 shr $56,%rdi
 cmp $254,%rdi
 jne l0364
 mov %rbx,%rax
 call *4504(%r14)
 mov %rax,%rbx
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 mov (%rsp),%rax
 call *3984(%r14)
 mov %rax,8(%rsp)
 jmp l0365
l0364:
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 call *3984(%r14)
 mov %rax,8(%rsp)
l0365:
 mov 8(%rsp),%rax
 add $16,%rsp
 ret
 .quad 1
/ (*entry dynloadhelper expr 1)
 .globl dynloadhelper
dynloadhelper:
 push %rbp
 push %rdx
 push %rcx
 push %rbx
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r14
 push %r13
 mov %rsp,%rbx
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rbx,40(%rsp)
 call *%rax
 mov 40(%rsp),%rsp
 pop %r13
 pop %r14
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry dynloadhelper_float_float expr 1)
 .globl dynloadhelper_float_float
dynloadhelper_float_float:
 push %rbp
 push %rdx
 push %rcx
 push %rbx
 mov 24(%rsp),%rcx
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rsi
 mov 0(%rsp),%rdi
 mov 2496(%r13),%rbx
 push %r15
 push %r10
 push %r11
 push %r12
 push %r14
 push %r13
 mov %rsp,%rbx
 sub $64,%rsp
 shr $5,%rsp
 shl $5,%rsp
 mov %rbx,40(%rsp)
 movsd (%rdi),%xmm0
 call *%rax
 movq %xmm0,%rax
 mov 40(%rsp),%rsp
 pop %r13
 pop %r14
 pop %r12
 pop %r11
 pop %r10
 pop %r15
 mov %rbx,2496(%r13)
 add $32,%rsp
 ret
 .quad 1
/ (*entry psl-dlclose expr 1)
 .globl l0366
l0366:
 jmp *3992(%r14)
 .quad 1
/ (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 sub $8,%rsp
 shl $8,%rax
 shr $8,%rax
 mov %rax,(%rsp)
 mov l0367,%rax
 call *4544(%r14)
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jle l0370
 mov %r15,%rax
 jmp l0371
l0370:
 mov l0368,%rax
l0371:
 cmp %r15,%rax
 je l0372
 mov l0369,%rax
 call *4544(%r14)
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jg l0373
 mov %r15,%rax
 jmp l0372
l0373:
 mov l0368(%rip),%rax
l0372:
 cmp %r15,%rax
 jne l0374
 mov 2280(%r13),%rax
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jle l0375
 mov %r15,%rax
 jmp l0376
l0375:
 mov l0368(%rip),%rax
l0376:
 cmp %r15,%rax
 je l0374
 mov 2296(%r13),%rax
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jg l0377
 mov %r15,%rax
 jmp l0374
l0377:
 mov l0368(%rip),%rax
l0374:
 add $8,%rsp
 ret
 .quad 1
/ (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 ret
 .quad 0
/ (*entry initcode expr 0)
 .globl initcode
initcode:
 mov %r15,%rax
 ret
 .globl symval
 .globl symprp
 .globl symnam
 .globl symfnc
 .globl symget
 .globl staticlisp
 .globl l0008
 .globl l0007
 .globl l0009
 .globl l0010
 .globl l0016
 .globl l0015
 .globl l0017
 .globl l0018
 .globl l0034
 .globl l0033
 .globl l0032
 .globl l0035
 .globl l0045
 .globl l0044
 .globl l0046
 .globl l0099
 .globl l0100
 .globl l0103
 .globl l0102
 .globl l0104
 .globl l0110
 .globl l0111
 .globl l0116
 .globl l0115
 .globl l0114
 .globl l0117
 .globl l0118
 .globl l0126
 .globl l0127
 .globl l0129
 .globl l0130
 .globl l0132
 .globl l0133
 .globl l0142
 .globl l0164
 .globl l0163
 .globl l0162
 .globl l0165
 .globl l0178
 .globl l0177
 .globl l0181
 .globl l0180
 .globl l0188
 .globl l0189
 .globl l0191
 .globl l0192
 .globl l0194
 .globl l0195
 .globl l0356
 .globl l0357
 .globl l0360
 .globl l0361
 .globl l0369
 .globl l0368
 .globl l0367
 .globl l0378
 .globl l0379
 .globl l0380
 .globl l0381
 .globl l0382
 .globl l0383
 .globl l0384
 .globl l0385
 .globl l0386
 .globl l0387
 .globl l0388
 .globl l0389
 .globl l0390
 .globl l0391
 .globl l0392
 .globl l0393
 .globl l0394
 .globl l0395
 .globl l0396
 .globl l0397
 .globl l0398
 .globl l0399
 .globl l0400
 .globl l0401
 .globl l0402
 .globl l0403
 .globl l0404
 .globl l0405
 .globl l0406
 .globl l0407
 .globl l0408
 .globl l0409
 .globl l0410
 .globl l0411
 .globl l0412
 .globl l0413
 .globl l0414
 .globl l0415
 .globl l0416
 .globl l0417
 .globl l0418
 .globl l0419
 .globl l0420
 .globl l0421
 .globl l0422
 .globl l0423
 .globl l0424
 .globl l0425
 .globl l0426
 .globl l0427
 .globl l0428
 .globl l0429
 .globl l0430
 .globl l0431
 .globl l0432
 .globl l0433
 .globl l0434
 .globl l0435
 .globl l0436
 .globl l0437
 .globl l0438
 .globl l0439
 .globl l0440
 .globl l0441
 .globl l0442
 .globl l0443
 .globl l0444
 .globl l0445
 .globl l0446
 .globl l0447
 .globl l0448
 .globl l0449
 .globl l0450
 .globl l0451
 .globl l0452
 .globl l0453
 .globl l0454
 .globl l0455
 .globl l0456
 .globl l0457
 .globl l0458
 .globl l0459
 .globl l0460
 .globl l0461
 .globl l0462
 .globl l0463
 .globl l0464
 .globl l0465
 .globl l0466
 .globl l0467
 .globl l0468
 .globl l0469
 .globl l0470
 .globl l0471
 .globl l0472
 .globl l0473
 .globl l0474
 .globl l0475
 .globl l0476
 .globl l0477
 .globl l0478
 .globl l0479
 .globl l0480
 .globl l0481
 .globl l0482
 .globl l0483
 .globl l0484
 .globl l0485
 .globl l0486
 .globl l0487
 .globl l0488
 .globl l0489
 .globl l0490
 .globl l0491
 .globl l0492
 .globl l0493
 .globl l0494
 .globl l0495
 .globl l0496
 .globl l0497
 .globl l0498
 .globl l0499
 .globl l0500
 .globl l0501
 .globl l0502
 .globl l0503
 .globl l0504
 .globl l0505
 .globl l0506
 .globl l0507
 .globl l0508
 .globl l0509
 .globl l0510
 .globl l0511
 .globl l0512
 .globl l0513
 .globl l0514
 .globl l0515
 .globl l0516
 .globl l0517
 .globl l0518
 .globl l0519
 .globl l0520
 .globl l0521
 .globl l0522
 .globl l0523
 .globl l0524
 .globl l0525
 .globl l0526
 .globl l0527
 .globl l0528
 .globl l0529
 .globl l0530
 .globl l0531
 .globl l0532
 .globl l0533
 .globl l0534
 .globl l0535
 .globl l0536
 .globl l0537
 .globl l0538
 .globl l0539
 .globl l0540
 .globl l0541
 .globl l0542
 .globl l0543
 .globl l0544
 .globl l0545
 .globl l0546
 .globl l0547
 .globl l0548
 .globl l0549
 .globl l0550
 .globl l0551
 .globl l0552
 .globl l0553
 .globl l0554
 .globl l0555
 .globl l0556
 .globl l0557
 .globl l0558
 .globl l0559
 .globl l0560
 .globl l0561
 .globl l0562
 .globl l0563
 .globl l0564
 .globl l0565
 .globl l0566
 .globl l0567
 .globl l0568
 .globl l0569
 .globl l0570
 .globl l0571
 .globl l0572
 .globl l0573
 .globl l0574
 .globl l0575
 .globl l0576
 .globl l0577
 .globl l0578
 .globl l0579
 .globl l0580
 .globl l0581
 .globl l0582
 .globl l0583
 .globl l0584
 .globl l0585
 .globl l0586
 .globl l0587
 .globl l0588
 .globl l0589
 .globl l0590
 .globl l0591
 .globl l0592
 .globl l0593
 .globl l0594
 .globl l0595
 .globl l0596
 .globl l0597
 .globl l0598
 .globl l0599
 .globl l0600
 .globl l0601
 .globl l0602
 .globl l0603
 .globl l0604
 .globl l0605
 .globl l0606
 .globl l0607
 .globl l0608
 .globl l0609
 .globl l0610
 .globl l0611
 .globl l0612
 .globl l0613
 .globl l0614
 .globl l0615
 .globl l0616
 .globl l0617
 .globl l0618
 .globl l0619
 .globl l0620
 .globl l0621
 .globl l0622
 .globl l0623
 .globl l0624
 .globl l0625
 .globl l0626
 .globl l0627
 .globl l0628
 .globl l0629
 .globl l0630
 .globl l0631
 .globl l0632
 .globl l0633
 .globl l0634
 .globl l0635
 .globl l0636
 .globl l0637
 .globl l0638
 .globl l0639
 .globl l0640
 .globl l0641
 .globl l0642
 .globl l0643
 .globl l0644
 .globl l0645
 .globl l0646
 .globl l0647
 .globl l0648
 .globl l0649
 .globl l0650
 .globl l0651
 .globl l0652
 .globl l0653
 .globl l0654
 .globl l0655
 .globl l0656
 .globl l0657
 .globl l0658
 .globl l0659
 .globl l0660
 .globl l0661
 .globl l0662
 .globl l0663
 .globl l0664
 .globl l0665
 .globl l0666
 .globl l0667
 .globl l0668
 .globl l0669
 .globl l0670
 .globl l0671
 .globl l0672
 .globl l0673
 .globl l0674
 .globl l0675
 .globl l0676
 .globl l0677
 .globl l0678
 .globl l0679
 .globl l0680
 .globl l0681
 .globl l0682
 .globl l0683
 .globl l0684
 .globl l0685
 .globl l0686
 .globl l0687
 .globl l0688
 .globl l0689
 .globl l0690
 .globl l0691
 .globl l0692
 .globl l0693
 .globl l0694
 .globl l0695
 .globl l0696
 .globl l0697
 .globl l0698
 .globl l0699
 .globl l0700
 .globl l0701
 .globl l0702
 .globl l0703
 .globl l0704
 .globl l0705
 .globl l0706
 .globl l0707
 .globl l0708
 .globl l0709
 .globl l0710
 .globl l0711
 .globl l0712
 .globl l0713
 .globl l0714
 .globl l0715
 .globl l0716
 .globl l0717
 .globl l0718
 .globl l0719
 .globl l0720
 .globl l0721
 .globl l0722
 .globl l0723
 .globl l0724
 .globl l0725
 .globl l0726
 .globl l0727
 .globl l0728
 .globl l0729
 .globl l0730
 .globl l0731
 .globl l0732
 .globl l0733
 .globl l0734
 .globl l0735
 .globl l0736
 .globl l0737
 .globl l0738
 .globl l0739
 .globl l0740
 .globl l0741
 .globl l0742
 .globl l0743
 .globl l0744
 .globl l0745
 .globl l0746
 .globl l0747
 .globl l0748
 .globl l0749
 .globl l0750
 .globl l0751
 .globl l0752
 .globl l0753
 .globl l0754
 .globl l0755
 .globl l0756
 .globl l0757
 .globl l0758
 .globl l0759
 .globl l0760
 .globl l0761
 .globl l0762
 .globl l0763
 .globl l0764
 .globl l0765
 .globl l0766
 .globl l0767
 .globl l0768
 .globl l0769
 .globl l0770
 .globl l0771
 .globl l0772
 .globl l0773
 .globl l0774
 .globl l0775
 .globl l0776
 .globl l0777
 .globl l0778
 .globl l0779
 .globl l0780
 .globl l0781
 .globl l0782
 .globl l0783
 .globl l0784
 .globl l0785
 .globl l0786
 .globl l0787
 .globl l0788
 .globl l0789
 .globl l0790
 .globl l0791
 .globl l0792
 .globl l0793
 .globl l0794
 .globl l0795
 .globl l0796
 .globl l0797
 .globl l0798
 .globl l0799
 .globl l0800
 .globl l0801
 .globl l0802
 .globl l0803
 .globl l0804
 .globl l0805
 .globl l0806
 .globl l0807
 .globl l0808
 .globl l0809
 .globl l0810
 .globl l0811
 .globl l0812
 .globl l0813
 .globl l0814
 .globl l0815
 .globl l0816
 .globl l0817
 .globl l0818
 .globl l0819
 .globl l0820
 .globl l0821
 .globl l0822
 .globl l0823
 .globl l0824
 .globl l0825
 .globl l0826
 .globl l0827
 .globl l0828
 .globl l0829
 .globl l0830
 .globl l0831
 .globl l0832
 .globl l0833
 .globl l0834
 .globl l0835
 .globl l0836
 .globl l0837
 .globl l0838
 .globl l0839
 .globl l0840
 .globl l0841
 .globl l0842
 .globl l0843
 .globl l0844
 .globl l0845
 .globl l0846
 .globl l0847
 .globl l0848
 .globl l0849
 .globl l0850
 .globl l0851
 .globl l0852
 .globl l0853
 .globl l0854
 .globl l0855
 .globl l0856
 .globl l0857
 .globl l0858
 .globl l0859
 .globl l0860
 .globl l0861
 .globl l0862
 .globl l0863
 .globl l0864
 .globl l0865
 .globl l0866
 .globl l0867
 .globl l0868
 .globl l0869
 .globl l0870
 .globl l0871
 .globl l0872
 .globl l0873
 .globl l0874
 .globl l0875
 .globl l0876
 .globl l0877
 .globl l0878
 .globl l0879
 .globl l0880
 .globl l0881
 .globl l0882
 .globl l0883
 .globl l0884
 .globl l0885
 .globl l0886
 .globl l0887
 .globl l0888
 .globl l0889
 .globl l0890
 .globl l0891
 .globl l0892
 .globl l0893
 .globl l0894
 .globl l0895
 .globl l0896
 .globl l0897
 .globl l0898
 .globl l0899
 .globl l0900
 .globl l0901
 .globl l0902
 .globl l0903
 .globl l0904
 .globl l0905
 .globl l0906
 .globl l0907
 .globl l0908
 .globl l0909
 .globl l0910
 .globl l0911
 .globl l0912
 .globl l0913
 .globl l0914
 .globl l0915
 .globl l0916
 .globl l0917
 .globl l0918
 .globl l0919
 .globl l0920
 .globl l0921
 .globl l0922
 .globl l0923
 .globl l0924
 .globl l0925
 .globl l0926
 .globl l0927
 .globl l0928
 .globl l0929
 .globl l0930
 .globl l0931
 .globl l0932
 .globl l0933
 .globl l0934
 .globl l0935
 .globl l0936
 .globl l0937
 .globl l0938
 .globl l0939
 .globl l0940
 .globl l0941
 .globl l0942
 .globl l0943
 .globl l0944
 .globl l0945
 .globl l0946
 .globl l0947
 .globl endinitstaticlisp
 .globl laststaticlisp
