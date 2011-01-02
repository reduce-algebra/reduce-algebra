        .text
 .quad 1
/ (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 ret
 .quad 0
/ (*entry init-pointers expr 0)
 .globl l0001
l0001:
 mov symval+2088,%rdi
 mov %rdi,symval+2144
 mov symval+2080,%rdi
 mov %rdi,symval+2152
 mov $15992,%rax
 add symval+2080,%rax
 mov %rax,symval+2160
 mov symval+2080,%rdi
 mov %rdi,symval+2168
 mov symval+2176,%rax
 mov %rax,symval+2184
 ret
 .quad 0
/ (*entry init-fluids expr 0)
 .globl l0003
l0003:
 mov l0002,%rax
 mov %rax,symval+2200
 mov %rax,symval+2208
 mov %rax,symval+2216
 mov %rax,symval+2224
 mov %rax,symval+2232
 mov %rax,symval+2240
 mov %rax,symval+2248
 mov %rax,symval+2256
 mov %rax,symval+2264
 mov %rax,symval+2272
 mov %rax,symval+2280
 mov %rax,symval+2288
 mov %rax,symval+2296
 mov %rax,symval+2304
 mov %rax,symval+2312
 mov %rax,symval+2320
 mov %rax,symval+2328
 mov %rax,symval+2336
 mov %rax,symval+2344
 mov %rax,symval+2352
 mov %rax,symval+2360
 mov %rax,symval+2368
 mov %rax,symval+2376
 mov %rax,symval+2384
 ret
l0002:
 .quad [[254<<56]+128]
 .quad 0
/ (*entry psl_main expr 0)
psl_main:
 .globl psl_main
 mov %rcx,%rax
 mov %rdx,%rbx
 sub $24,%rsp
 mov l0004,%rdi
 mov %rdi,16(%rsp)
 mov %rdi,8(%rsp)
 mov %rdi,(%rsp)
 call *symfnc+2400
 mov (%rsp),%rdi
 mov %rdi,symval+2408
 mov 8(%rsp),%rdi
 mov %rdi,symval+2416
 mov 16(%rsp),%rdi
 mov %rdi,symval+2424
 call *symfnc+2136
 mov %rsp,%rdx
 shr $5,%rdx
 mov %rdx,symval+2432
 call *symfnc+2440
 call *symfnc+2448
l0005:
 xor %rax,%rax
 add $24,%rsp
 jmp *symfnc+2456
 add $24,%rsp
 ret
/ (*entry exit-with-status expr 1)
 .globl l0006
l0006:
 push %rax
 call *symfnc+2464
 pop %rax
 call *symfnc+2472
 add $24,%rsp
 ret
l0004:
 .quad [[254<<56]+128]
 .quad 0
/ (*entry init-gcarray expr 0)
 .globl l0008
l0008:
 mov l0007,%rax
 ret
l0007:
 .quad [[254<<56]+128]
l0011:
 .quad 9
 .byte 108,111,97,100,45,112,115,108,46,98
 .byte 0,0
l0012:
 .quad 21
 .byte 65,98,111,117,116,32,116,111,32,108
 .byte 111,97,100,32,76,79,65,68,45,80,83
 .byte 76,0,0
 .quad 0
/ (*entry pre-main expr 0)
 .globl l0013
l0013:
 call *symfnc+2480
 call *symfnc+2488
 call *symfnc+2496
 mov l0009,%rax
 call *symfnc+2504
 call *symfnc+2512
 mov l0010,%rax
 call *symfnc+2520
 jmp *symfnc+2528
l0010:
 .quad [[4<<56]+l0011]
l0009:
 .quad [[4<<56]+l0012]
 .quad 1
/ (*entry console-print-string expr 1)
 .globl l0014
l0014:
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 jmp *symfnc+2536
 .quad 1
/ (*entry console-print-number expr 1)
 .globl l0015
l0015:
 jmp *symfnc+2552
 .quad 0
/ (*entry console-newline expr 0)
 .globl l0016
l0016:
 mov $10,%rax
 jmp *symfnc+2560
l0019:
 .quad 34
 .byte 67,111,117,108,100,110,39,116,32,111
 .byte 112,101,110,32,98,105,110,97,114,121
 .byte 32,102,105,108,101,32,102,111,114,32
 .byte 105,110,112,117,116,0
l0020:
 .quad 1
 .byte 114,98,0,0
 .quad 1
/ (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 mov l0017,%rbx
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 call *symfnc+2576
 cmp $0,%rax
 jne l0021
 mov l0018,%rax
 jmp *symfnc+2584
l0021:
 ret
l0018:
 .quad [[4<<56]+l0019]
l0017:
 .quad [[4<<56]+l0020]
 .quad 1
/ (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 jmp *symfnc+2600
 .quad 3
/ (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 mov %rbx,%rbp
 mov %rax,%rdx
 mov $8,%rbx
 mov %rbp,%rax
 jmp *symfnc+2616
 .quad 1
/ (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 jmp *symfnc+2632
 .quad 0
/ (*entry initialize-symbol-table expr 0)
 .globl l0023
l0023:
 sub $16,%rsp
 mov l0022,%rdi
 mov %rdi,8(%rsp)
 mov %rdi,(%rsp)
 mov $65000,%rbx
 mov symval+2640,%rax
 mov %rax,%rdx
 mov %rbx,%rcx
l0024:
 cmp %rcx,%rdx
 jg l0025
 mov %rdx,%rax
 shl $3,%rax
 add symval+2648,%rax
 mov $1,%rbx
 add %rdx,%rbx
 mov %rbx,(%rax)
 add $1,%rdx
 jmp l0024
l0025:
 mov symval+2648,%rsi
 movq $0,520000(%rsi)
 mov $68023,%rbx
 xor %rax,%rax
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
l0026:
 mov (%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0027
 xor %rcx,%rcx
 mov (%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw %cx,0(%rbx,%rax,1)
 addq $1,(%rsp)
 jmp l0026
l0027:
 mov symval+2648,%rdi
 mov 1024(%rdi),%rax
 call *symfnc+2656
 mov $128,%rcx
 mov %rax,%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw %cx,0(%rbx,%rax,1)
 mov $-1,%rbx
 add symval+2640,%rbx
 mov $256,%rax
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
l0028:
 mov (%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0029
 mov (%rsp),%rax
 shl $3,%rax
 add symval+2648,%rax
 mov (%rax),%rax
 call *symfnc+2656
 mov (%rsp),%rcx
 mov %rax,%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw %cx,0(%rbx,%rax,1)
 addq $1,(%rsp)
 jmp l0028
l0029:
 mov l0022,%rax
 mov %rax,symval+2664
 add $16,%rsp
 ret
l0022:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry faslin-intern expr 1)
 .globl l0031
l0031:
 sub $24,%rsp
 mov l0030,%rdi
 mov %rdi,16(%rsp)
 mov %rdi,8(%rsp)
 mov %rax,(%rsp)
 mov %rax,%rbx
 xor %rax,%rax
 call *symfnc+2680
 mov %rax,8(%rsp)
 cmp l0030,%rax
 jne l0032
 mov (%rsp),%rax
 add $24,%rsp
 jmp *symfnc+2688
l0032:
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 shl $8,%rax
 sar $8,%rax
 mov %rax,16(%rsp)
 cmp 8(%rsp),%rax
 jle l0033
 mov $1,%rbx
 add 8(%rsp),%rbx
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cmp $0,%rax
 jne l0033
 addq $1,8(%rsp)
l0033:
 mov 8(%rsp),%rdi
 cmp 16(%rsp),%rdi
 jl l0034
 mov (%rsp),%rax
 jmp l0035
l0034:
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
 call *symfnc+2696
l0035:
 add $24,%rsp
 jmp *symfnc+2688
l0030:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry intern expr 1)
 .globl intern
intern:
 jmp *symfnc+2704
l0039:
 .quad 7
 .byte 78,101,119,32,105,100,58,32,0,0
 .quad 1
/ (*entry unchecked-string-intern expr 1)
 .globl l0040
l0040:
 sub $48,%rsp
 mov %rax,(%rsp)
 mov l0036,%rbp
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
 jne l0041
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 shl $8,%rax
 shr $8,%rax
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%rax
 jmp l0042
l0041:
 mov (%rsp),%rax
 call *symfnc+2656
 mov %rax,%rbx
 mov %rbx,24(%rsp)
 mov symval+2096,%rax
 shl $1,%rbx
 movw 0(%rax,%rbx,1),%ax
 cwtl
 shl $48,%rax
 shr $48,%rax
 mov %rax,%rbx
 cmp $65535,%rax
 jl l0043
 mov l0036,%rax
 jmp l0044
l0043:
 mov l0037,%rax
l0044:
 cmp l0036,%rax
 je l0045
 mov l0037,%rax
 cmp $0,%rbx
 jg l0045
 add $12,%rax
l0045:
 cmp l0036,%rax
 je l0046
 mov 24(%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw 0(%rax,%rbx,1),%ax
 cwtl
 shl $48,%rax
 shr $48,%rax
 shl $8,%rax
 shr $8,%rax
 mov $254,%rdi
 shl $56,%rdi
 or %rdi,%rax
 jmp l0042
l0046:
 cmp symval+2664,%rax
 je l0047
 mov l0038,%rax
 call *symfnc+2504
 mov (%rsp),%rax
 call *symfnc+2504
 call *symfnc+2512
l0047:
 call *symfnc+2712
 mov %rax,40(%rsp)
 mov %rax,%rcx
 mov 24(%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw %cx,0(%rbx,%rax,1)
 mov 16(%rsp),%rax
 call *symfnc+2720
 mov %rax,32(%rsp)
 mov 8(%rsp),%rbx
 call *symfnc+2728
 mov 32(%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov 40(%rsp),%rax
 add $48,%rsp
 jmp *symfnc+2736
l0042:
 add $48,%rsp
 ret
l0038:
 .quad [[4<<56]+l0039]
l0037:
 .quad [[254<<56]+116]
l0036:
 .quad [[254<<56]+128]
l0050:
 .quad 18
 .byte 72,97,115,104,32,116,97,98,108,101
 .byte 32,111,118,101,114,102,108,111,119
 .byte 0
 .quad 1
/ (*entry hash-into-table expr 1)
 .globl l0051
l0051:
 sub $32,%rsp
 mov l0048,%rdi
 mov %rdi,24(%rsp)
 mov %rdi,16(%rsp)
 mov %rdi,8(%rsp)
 mov %rax,(%rsp)
 call *symfnc+2744
 mov %rax,8(%rsp)
 mov %rax,16(%rsp)
 movq $-1,24(%rsp)
l0052:
 mov 16(%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw 0(%rax,%rbx,1),%ax
 cwtl
 shl $48,%rax
 shr $48,%rax
 cmp $0,%rax
 jne l0053
 cmp $-1,24(%rsp)
 je l0054
 mov 24(%rsp),%rax
 jmp l0055
l0054:
 mov 16(%rsp),%rax
l0055:
 jmp l0056
l0053:
 mov 16(%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw 0(%rax,%rbx,1),%ax
 cwtl
 mov %rax,%rbx
 shl $48,%rbx
 shr $48,%rbx
 cmp $65535,%rbx
 jne l0057
 cmp $-1,24(%rsp)
 jne l0058
 mov 16(%rsp),%rdi
 mov %rdi,24(%rsp)
 jmp l0058
l0057:
 mov 16(%rsp),%rbx
 mov symval+2096,%rax
 shl $1,%rbx
 movw 0(%rax,%rbx,1),%ax
 cwtl
 mov (%rsp),%rbx
 shl $48,%rax
 shr $48,%rax
 shl $3,%rax
 add symval+2648,%rax
 mov (%rax),%rax
 call *symfnc+2752
 cmp l0048,%rax
 je l0058
 mov 16(%rsp),%rax
 jmp l0056
l0058:
 cmpq $68023,16(%rsp)
 jne l0059
 xor %rax,%rax
 jmp l0060
l0059:
 mov $1,%rax
 add 16(%rsp),%rax
l0060:
 mov %rax,16(%rsp)
 cmp 8(%rsp),%rax
 jne l0052
 mov l0049,%rax
 call *symfnc+2584
 jmp l0052
l0056:
 add $32,%rsp
 ret
l0049:
 .quad [[4<<56]+l0050]
l0048:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry initialize-new-id expr 2)
 .globl l0062
l0062:
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
 add symval+2648,%rcx
 mov %rbx,(%rcx)
 mov (%rsp),%rdx
 shl $3,%rdx
 add symval+2760,%rdx
 mov l0061,%rbp
 mov %rbp,(%rdx)
 mov (%rsp),%rax
 shl $3,%rax
 add symval+2768,%rax
 mov %rbp,(%rax)
 mov (%rsp),%rax
 shl $3,%rax
 add symval+2776,%rax
 mov (%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $253,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov %rbx,(%rax)
 mov (%rsp),%rax
 call *symfnc+2784
 mov 8(%rsp),%rax
 add $16,%rsp
 ret
l0061:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry hash-function expr 1)
 .globl l0066
l0066:
 sub $40,%rsp
 mov l0063,%rdi
 mov %rdi,24(%rsp)
 mov %rdi,8(%rsp)
 shl $8,%rax
 shr $8,%rax
 mov %rax,16(%rsp)
 mov (%rax),%rax
 shl $8,%rax
 sar $8,%rax
 mov %rax,(%rsp)
 xor %rax,%rax
 mov %rax,32(%rsp)
 cmp $20,(%rsp)
 jle l0067
 movq $20,(%rsp)
l0067:
 mov (%rsp),%rbx
 xor %rax,%rax
 mov %rax,24(%rsp)
 mov %rbx,8(%rsp)
l0068:
 mov 24(%rsp),%rdi
 cmp 8(%rsp),%rdi
 jg l0069
 mov 24(%rsp),%rbx
 mov $8,%rax
 add 16(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 mov $56,%rbx
 sub 24(%rsp),%rbx
 cmp $0,%rbx
 jge l0064
 neg %rbx
 xchg %rbx,%rcx
 shr %cl,%rax
 jmp l0065
l0064:
 xchg %rbx,%rcx
 shl %cl,%rax
l0065:
 xchg %rbx,%rcx
 mov 32(%rsp),%rdi
 xor %rdi,%rax
 mov %rax,32(%rsp)
 addq $1,24(%rsp)
 jmp l0068
l0069:
 mov $68023,%rbx
 mov 32(%rsp),%rax
 add $40,%rsp
 cqto
 idiv %rbx
 mov %rdx,%rax
 ret
l0063:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry faslin expr 1)
 .globl faslin
faslin:
 sub $88,%rsp
 mov l0070,%rdi
 mov %rdi,64(%rsp)
 mov %rdi,24(%rsp)
 mov %rdi,16(%rsp)
 mov %rax,(%rsp)
 mov l0070,%rdi
 mov %rdi,32(%rsp)
 mov l0070,%rdi
 mov %rdi,48(%rsp)
 mov l0070,%rdi
 mov %rdi,56(%rsp)
 mov l0070,%rdi
 mov %rdi,80(%rsp)
 mov l0070,%rdi
 mov %rdi,8(%rsp)
 mov l0070,%rdi
 mov %rdi,40(%rsp)
 mov l0070,%rdi
 mov %rdi,72(%rsp)
 call *symfnc+2568
 mov %rax,16(%rsp)
 call *symfnc+2592
 mov %rax,24(%rsp)
 mov $65535,%rbx
 and %rax,%rbx
 cmp $399,%rbx
 je l0071
 mov 16(%rsp),%rax
 call *symfnc+2624
 mov (%rsp),%rax
 call *symfnc+2792
 jmp l0072
l0071:
 mov 24(%rsp),%rax
 shr $16,%rax
 mov %rax,24(%rsp)
 mov 16(%rsp),%rax
 call *symfnc+2800
 mov %rax,32(%rsp)
 mov 16(%rsp),%rax
 call *symfnc+2592
 mov %rax,48(%rsp)
 call *symfnc+2808
 mov %rax,56(%rsp)
 xor %rax,%rax
 call *symfnc+2808
 mov %rax,72(%rsp)
 mov 16(%rsp),%rax
 call *symfnc+2592
 mov 56(%rsp),%rbx
 add %rax,%rbx
 mov %rbx,80(%rsp)
 mov 48(%rsp),%rcx
 xor %rbx,%rbx
 add 56(%rsp),%rbx
 mov 16(%rsp),%rax
 call *symfnc+2608
 mov 16(%rsp),%rax
 call *symfnc+2592
 mov %rax,8(%rsp)
 call *symfnc+2816
 mov %rax,%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov $7,%rdi
 shl $56,%rdi
 or %rdi,%rbx
 mov %rbx,40(%rsp)
 mov 8(%rsp),%rcx
 shl $8,%rbx
 shr $8,%rbx
 add $8,%rbx
 mov 16(%rsp),%rax
 call *symfnc+2608
 mov 16(%rsp),%rax
 call *symfnc+2624
 mov $1,%rax
 and 24(%rsp),%rax
 cmp $1,%rax
 jne l0073
 mov 32(%rsp),%rdx
 mov 40(%rsp),%rcx
 mov 48(%rsp),%rbx
 mov 56(%rsp),%rax
 call *symfnc+2824
 jmp l0074
l0073:
 mov 32(%rsp),%rdx
 mov 40(%rsp),%rcx
 mov 48(%rsp),%rbx
 mov 56(%rsp),%rax
 call *symfnc+2832
l0074:
 mov symval+2840,%rax
 mov %rax,64(%rsp)
 mov 56(%rsp),%rdi
 mov %rdi,symval+2840
 mov 80(%rsp),%rax
 call *symfnc+2848
 mov 64(%rsp),%rdi
 mov %rdi,symval+2840
 mov 72(%rsp),%rbx
 mov 80(%rsp),%rax
 call *symfnc+2856
l0072:
 mov l0070,%rax
 add $88,%rsp
 ret
l0070:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry delbps expr 2)
 .globl delbps
delbps:
 mov l0075,%rax
 ret
l0075:
 .quad [[254<<56]+128]
 .quad 4
/ (*entry do-relocation expr 4)
 .globl l0077
l0077:
 sub $48,%rsp
 mov l0076,%rdi
 mov %rdi,32(%rsp)
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
l0078:
 mov 40(%rsp),%rdi
 cmp (%rsp),%rdi
 jle l0079
 mov l0076,%rax
 jmp l0080
l0079:
 mov 40(%rsp),%rbx
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 mov $358,%rdi
 call *symfnc+2864
 mov 24(%rsp),%rbx
 add 40(%rsp),%rbx
 mov %rbx,32(%rsp)
 cmp $1,%rax
 je l0081
 cmp $2,%rax
 je l0082
 cmp $3,%rax
 je l0083
 jmp l0084
l0081:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 call *symfnc+2880
 jmp l0084
l0083:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 call *symfnc+2888
 jmp l0084
l0082:
 mov 16(%rsp),%rcx
 mov 24(%rsp),%rbx
 mov 32(%rsp),%rax
 mov $359,%rdi
 call *symfnc+2872
l0084:
 addq $1,40(%rsp)
 jmp l0078
l0080:
 add $48,%rsp
 ret
l0076:
 .quad [[254<<56]+128]
 .quad 4
/ (*entry do-relocation-new expr 4)
 .globl l0086
l0086:
 sub $48,%rsp
 mov l0085,%rdi
 mov %rdi,16(%rsp)
 mov %rax,32(%rsp)
 mov %rcx,(%rsp)
 mov %rdx,24(%rsp)
 mov l0085,%rcx
 mov %rax,%rbx
 xor %rax,%rax
 mov %rax,8(%rsp)
 mov %rbx,40(%rsp)
 mov (%rsp),%rbp
 shl $8,%rbp
 shr $8,%rbp
 add $8,%rbp
 mov %rbp,(%rsp)
l0087:
 mov 8(%rsp),%rbx
 mov (%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 and $255,%rax
 mov %rax,16(%rsp)
 cmp $0,%rax
 jne l0088
 mov l0085,%rax
 jmp l0089
l0088:
 addq $1,8(%rsp)
 mov $63,%rax
 and 16(%rsp),%rax
 add 40(%rsp),%rax
 mov %rax,40(%rsp)
 mov 16(%rsp),%rbx
 shr $6,%rbx
 mov %rbx,16(%rsp)
 mov %rbx,%rax
 cmp $1,%rax
 je l0090
 cmp $2,%rax
 je l0091
 cmp $3,%rax
 je l0092
 jmp l0087
l0090:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 call *symfnc+2880
 jmp l0087
l0092:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 call *symfnc+2888
 jmp l0087
l0091:
 mov 24(%rsp),%rcx
 mov 32(%rsp),%rbx
 mov 40(%rsp),%rax
 mov $359,%rdi
 call *symfnc+2872
 jmp l0087
l0089:
 add $48,%rsp
 ret
l0085:
 .quad [[254<<56]+128]
 .quad 3
/ (*entry relocate-word expr 3)
 .globl l0094
l0094:
 sub $32,%rsp
 mov l0093,%rdi
 mov %rdi,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov 0(%rax),%rax
 mov %rax,24(%rsp)
 mov (%rsp),%rax
 mov 0(%rax),%rax
 mov %rax,%rbx
 shl $34,%rbx
 shr $34,%rbx
 mov 24(%rsp),%rax
 shl $32,%rax
 shr $62,%rax
 mov 16(%rsp),%rdx
 mov 8(%rsp),%rcx
 call *symfnc+2896
 mov %rax,%rbx
 mov (%rsp),%rax
 add $32,%rsp
 mov %ebx,0(%eax)
 ret
l0093:
 .quad [[254<<56]+128]
 .quad 3
/ (*entry relocate-inf expr 3)
 .globl l0096
l0096:
 sub $24,%rsp
 mov l0095,%rdi
 mov %rdi,8(%rsp)
 mov %rax,16(%rsp)
 mov %rbx,(%rsp)
 mov (%rax),%rbx
 shl $42,%rbx
 shr $42,%rbx
 mov (%rax),%rax
 shr $54,%rax
 and $3,%rax
 mov %rcx,%rdx
 mov (%rsp),%rcx
 call *symfnc+2896
 mov %rax,8(%rsp)
 mov 16(%rsp),%rsi
 mov (%rsi),%rax
 shr $56,%rax
 shl $56,%rax
 or 8(%rsp),%rax
 mov 16(%rsp),%rsi
 mov %rax,(%rsi)
 add $24,%rsp
 ret
l0095:
 .quad [[254<<56]+128]
 .quad 4
/ (*entry compute-relocation expr 4)
 .globl l0098
l0098:
 push %rbx
 cmp $0,%rax
 jne l0099
 mov %rcx,%rax
 add %rbx,%rax
 jmp l0100
l0099:
 cmp $2,%rax
 jne l0101
 cmp $8150,%rbx
 jl l0102
 mov $-8156,%rax
 add %rbx,%rax
 shl $3,%rax
 add symval+2064,%rax
 jmp l0100
l0102:
 cmp $2048,%rbx
 jl l0103
 mov %rdx,%rbx
 mov (%rsp),%rax
 call *symfnc+2904
 shl $3,%rax
 add symval+2776,%rax
 jmp l0100
l0103:
 mov %rbx,%rax
 shl $3,%rax
 add symval+2776,%rax
 jmp l0100
l0101:
 cmp $3,%rax
 jne l0104
 cmp $2048,%rbx
 jl l0105
 mov %rdx,%rbx
 mov (%rsp),%rax
 call *symfnc+2904
 mov %rax,(%rsp)
l0105:
 mov (%rsp),%rax
 shl $3,%rax
 add symval+2912,%rax
 jmp l0100
l0104:
 cmp $1,%rax
 jne l0106
 cmp $2048,%rbx
 jl l0107
 mov %rdx,%rbx
 mov (%rsp),%rax
 add $8,%rsp
 jmp *symfnc+2904
l0107:
 mov %rbx,%rax
 jmp l0100
l0106:
 mov l0097,%rax
l0100:
 add $8,%rsp
 ret
l0097:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry local-to-global-id expr 2)
 .globl l0108
l0108:
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
 .globl l0110
l0110:
 sub $48,%rsp
 mov l0109,%rdi
 mov %rdi,40(%rsp)
 mov %rdi,32(%rsp)
 mov %rdi,24(%rsp)
 mov %rdi,16(%rsp)
 mov %rdi,8(%rsp)
 mov %rax,(%rsp)
 call *symfnc+2592
 mov %rax,8(%rsp)
 add $1,%rax
 call *symfnc+2816
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
l0111:
 mov 24(%rsp),%rdi
 cmp 32(%rsp),%rdi
 jg l0112
 mov (%rsp),%rax
 call *symfnc+2592
 mov symval+2072,%rsi
 mov %rax,(%rsi)
 mov $9,%rcx
 add %rax,%rcx
 mov %rcx,%rbx
 shr $61,%rbx
 add %rbx,%rcx
 sar $3,%rcx
 mov $8,%rbx
 add symval+2072,%rbx
 mov (%rsp),%rax
 call *symfnc+2608
 xor %rax,%rax
 add symval+2072,%rax
 shl $8,%rax
 shr $8,%rax
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rax
 call *symfnc+2672
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
 jmp l0111
l0112:
 mov 16(%rsp),%rax
 add $48,%rsp
 ret
l0109:
 .quad [[254<<56]+128]
 .quad 3
/ (*entry putentry expr 3)
 .globl putentry
putentry:
 add symval+2840,%rcx
 shl $8,%rcx
 shr $8,%rcx
 mov $20,%rdi
 shl $56,%rdi
 or %rdi,%rcx
 mov $365,%rdi
 jmp *symfnc+2920
l0114:
 .quad 22
 .byte 70,105,108,101,32,105,115,32,110,111
 .byte 116,32,70,65,83,76,32,102,111,114,109
 .byte 97,116,0
 .quad 1
/ (*entry faslin-bad-file expr 1)
 .globl l0115
l0115:
 mov l0113,%rax
 call *symfnc+2504
 jmp *symfnc+2512
l0113:
 .quad [[4<<56]+l0114]
l0119:
 .quad 30
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,98,105,110,97,114,121,32,112,114
 .byte 111,103,114,97,109,32,115,112,97,99
 .byte 101,0
 .quad 1
/ (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 sub $8,%rsp
l0120:
 mov %rax,(%rsp)
 cmp l0116,%rax
 jne l0121
 call *symfnc+2936
l0121:
 cmp $10,(%rsp)
 jle l0122
 mov $15,%rax
 and symval+2288,%rax
 cmp $0,%rax
 je l0122
 mov symval+2288,%rbx
 shr $4,%rbx
 shl $4,%rbx
 add $16,%rbx
 mov %rbx,symval+2288
l0122:
 mov symval+2288,%rax
 mov (%rsp),%rbx
 shl $3,%rbx
 add symval+2288,%rbx
 mov %rbx,symval+2288
 cmp symval+2264,%rbx
 jle l0123
 mov %rax,symval+2288
 mov l0117,%rax
 call *symfnc+2944
 cmp l0116,%rax
 je l0124
 mov (%rsp),%rax
 call *symfnc+2952
 cmp l0116,%rax
 je l0124
 mov (%rsp),%rax
 jmp l0120
l0124:
 mov l0118,%rax
 add $8,%rsp
 jmp *symfnc+2960
l0123:
 add $8,%rsp
 ret
l0118:
 .quad [[4<<56]+l0119]
l0117:
 .quad [[254<<56]+369]
l0116:
 .quad [[254<<56]+128]
l0126:
 .quad 21
 .byte 71,84,66,80,83,32,99,97,108,108,101
 .byte 100,32,119,105,116,104,32,78,73,76
 .byte 46,0,0
 .quad 0
/ (*entry gtbps-nil-error expr 0)
 .globl l0127
l0127:
 mov l0125,%rax
 jmp *symfnc+2960
l0125:
 .quad [[4<<56]+l0126]
 .quad 1
/ (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 cmp l0128,%rax
 jne l0129
 jmp *symfnc+2976
l0129:
 jmp *symfnc+2984
l0128:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry real-gtheap expr 1)
 .globl l0130
l0130:
 mov %rax,%rcx
 mov symval+2216,%rax
 mov %rcx,%rbx
 shl $3,%rbx
 add symval+2216,%rbx
 mov %rbx,symval+2216
 cmp symval+2232,%rbx
 jl l0131
 mov %rcx,%rbx
 jmp *symfnc+2992
l0131:
 ret
l0133:
 .quad 27
 .byte 71,97,114,98,97,103,101,32,99,111,108
 .byte 108,101,99,116,105,111,110,32,114,101
 .byte 113,117,105,114,101,100,46,0,0
 .quad 1
/ (*entry get-heap-trap expr 1)
 .globl l0134
l0134:
 mov l0132,%rax
 jmp *symfnc+2584
l0132:
 .quad [[4<<56]+l0133]
l0136:
 .quad 18
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,73,68,32,115,112,97,99,101,0
 .quad 0
/ (*entry gtid expr 0)
 .globl gtid
gtid:
 cmp $0,symval+2640
 jne l0137
 call *symfnc+3000
 cmp $0,symval+2640
 jne l0137
 mov l0135,%rax
 call *symfnc+2584
l0137:
 mov symval+2640,%rax
 mov %rax,%rbx
 shl $3,%rbx
 add symval+2648,%rbx
 mov (%rbx),%rdi
 mov %rdi,symval+2640
 ret
l0135:
 .quad [[4<<56]+l0136]
 .quad 1
/ (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 push %rax
 add $2,%rax
 call *symfnc+2968
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
 call *symfnc+2808
 mov (%rsp),%rdi
 mov %rdi,(%rax)
 mov 8(%rsp),%rbx
 shl $3,%rbx
 add %rax,%rbx
 movq $0,(%rbx)
 add $16,%rsp
 ret
l0140:
 .quad 30
 .byte 83,85,66,83,69,81,32,99,97,108,108
 .byte 101,100,32,119,105,116,104,32,97,32
 .byte 110,111,110,45,115,116,114,105,110
 .byte 103,0
 .quad 3
/ (*entry subseq expr 3)
 .globl subseq
subseq:
 sub $64,%rsp
 mov l0138,%rdi
 mov %rdi,56(%rsp)
 mov %rdi,48(%rsp)
 mov %rdi,40(%rsp)
 mov %rdi,32(%rsp)
 mov %rdi,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $4,%rdi
 je l0141
 mov l0139,%rax
 call *symfnc+2584
l0141:
 mov $-1,%rax
 add 16(%rsp),%rax
 sub 8(%rsp),%rax
 mov %rax,24(%rsp)
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov %rax,32(%rsp)
 mov 24(%rsp),%rax
 call *symfnc+3008
 mov %rax,40(%rsp)
 mov 24(%rsp),%rbx
 xor %rax,%rax
 mov %rax,48(%rsp)
 mov %rbx,56(%rsp)
l0142:
 mov 48(%rsp),%rdi
 cmp 56(%rsp),%rdi
 jg l0143
 mov 8(%rsp),%rbx
 add 48(%rsp),%rbx
 mov $8,%rax
 add 32(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 mov %rax,%rcx
 mov 48(%rsp),%rbx
 mov $8,%rax
 add 40(%rsp),%rax
 movb %cl,0(%rbx,%rax,1)
 addq $1,48(%rsp)
 jmp l0142
l0143:
 mov 40(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov $4,%rdi
 shl $56,%rdi
 or %rdi,%rax
 add $64,%rsp
 ret
l0139:
 .quad [[4<<56]+l0140]
l0138:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry search-string-for-character expr 2)
 .globl l0145
l0145:
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
l0146:
 mov 16(%rsp),%rdi
 cmp 24(%rsp),%rdi
 jle l0147
 mov l0144,%rax
 jmp l0148
l0147:
 mov 16(%rsp),%rbx
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 add $8,%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cmp (%rsp),%rax
 jne l0149
 mov 16(%rsp),%rax
 jmp l0148
l0149:
 addq $1,16(%rsp)
 jmp l0146
l0148:
 add $32,%rsp
 ret
l0144:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry unchecked-string-equal expr 2)
 .globl l0152
l0152:
 sub $40,%rsp
 mov l0150,%rdi
 mov %rdi,32(%rsp)
 mov l0150,%rdi
 mov %rdi,24(%rsp)
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
 je l0153
 mov l0150,%rax
 jmp l0154
l0153:
 movq $0,24(%rsp)
l0155:
 mov 24(%rsp),%rdi
 cmp 16(%rsp),%rdi
 jle l0156
 mov l0151,%rax
 jmp l0154
l0156:
 mov 24(%rsp),%rbx
 mov $8,%rax
 add (%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 mov %rax,32(%rsp)
 mov 24(%rsp),%rbx
 mov $8,%rax
 add 8(%rsp),%rax
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 cmp 32(%rsp),%rax
 je l0157
 mov l0150,%rax
 jmp l0154
l0157:
 addq $1,24(%rsp)
 jmp l0155
l0154:
 add $40,%rsp
 ret
l0151:
 .quad [[254<<56]+116]
l0150:
 .quad [[254<<56]+128]
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
 jge l0158
 mov %rax,(%rsp)
l0158:
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
l0159:
 cmp %rcx,%rdx
 jg l0160
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
 jmp l0159
l0160:
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
 call *symfnc+2968
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
 add symval+2776,%rax
 mov (%rax),%rax
 ret
 .quad 2
/ (*entry modify expr 2)
 .globl modify
modify:
 shl $3,%rax
 add symval+2776,%rax
 mov %rbx,(%rax)
 mov %rbx,%rax
 ret
 .quad 3
/ (*entry put expr 3)
 .globl put
put:
 jmp *symfnc+3048
 .quad 3
/ (*entry unchecked-put expr 3)
 .globl l0162
l0162:
 sub $32,%rsp
 mov l0161,%rdi
 mov %rdi,24(%rsp)
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 call *symfnc+3056
 mov %rax,24(%rsp)
 mov %rax,%rbx
 mov 8(%rsp),%rax
 call *symfnc+3064
 cmp l0161,%rax
 je l0163
 mov %rax,%rsi
 shl $8,%rsi
 shr $8,%rsi
 mov 16(%rsp),%rdi
 mov %rdi,8(%rsi)
 jmp l0164
l0163:
 mov 16(%rsp),%rbx
 mov 8(%rsp),%rax
 call *symfnc+3016
 mov 24(%rsp),%rbx
 call *symfnc+3016
 mov %rax,%rbx
 mov (%rsp),%rax
 call *symfnc+3072
l0164:
 mov 16(%rsp),%rax
 add $32,%rsp
 ret
l0161:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry atsoc expr 2)
 .globl atsoc
atsoc:
l0166:
 mov %rbx,%rdi
 shr $56,%rdi
 cmp $9,%rdi
 je l0167
 mov l0165,%rax
 ret
l0167:
 mov %rbx,%rdi
 shl $8,%rdi
 shr $8,%rdi
 mov (%rdi),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0168
 mov %rbx,%rsi
 shl $8,%rsi
 shr $8,%rsi
 mov (%rsi),%rsi
 shl $8,%rsi
 shr $8,%rsi
 cmp (%rsi),%rax
 jne l0168
 mov %rbx,%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 ret
l0168:
 shl $8,%rbx
 shr $8,%rbx
 mov 8(%rbx),%rbx
 jmp l0166
l0165:
 .quad [[254<<56]+128]
 .quad 2
/ (*entry unchecked-setprop expr 2)
 .globl l0169
l0169:
 shl $8,%rax
 shr $8,%rax
 shl $3,%rax
 add symval+2760,%rax
 mov %rbx,(%rax)
 mov %rbx,%rax
 ret
 .quad 1
/ (*entry unchecked-prop expr 1)
 .globl l0170
l0170:
 shl $8,%rax
 shr $8,%rax
 shl $3,%rax
 add symval+2760,%rax
 mov (%rax),%rax
 ret
 .quad 3
/ (*entry putd expr 3)
 .globl putd
putd:
 jmp *symfnc+3080
l0175:
 .quad 26
 .byte 66,97,100,32,112,97,114,97,109,101
 .byte 116,101,114,115,32,116,111,32,67,79
 .byte 68,69,45,80,85,84,68,0
 .quad 3
/ (*entry code-putd expr 3)
 .globl l0176
l0176:
 sub $24,%rsp
 mov %rax,(%rsp)
 mov %rbx,8(%rsp)
 mov %rcx,16(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $254,%rdi
 jne l0177
 mov %rbx,%rdi
 shr $56,%rdi
 cmp $254,%rdi
 jne l0177
 mov %rcx,%rdi
 shr $56,%rdi
 cmp $20,%rdi
 je l0178
l0177:
 mov l0171,%rax
 call *symfnc+2584
l0178:
 mov 16(%rsp),%rbx
 shl $8,%rbx
 shr $8,%rbx
 mov (%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 call *symfnc+3088
 mov 8(%rsp),%rdi
 cmp l0172,%rdi
 je l0179
 mov 8(%rsp),%rcx
 mov l0173,%rbx
 mov (%rsp),%rax
 add $24,%rsp
 jmp *symfnc+3040
l0179:
 mov l0174,%rax
 add $24,%rsp
 ret
l0174:
 .quad [[254<<56]+128]
l0173:
 .quad [[254<<56]+387]
l0172:
 .quad [[254<<56]+388]
l0171:
 .quad [[4<<56]+l0175]
 .quad 1
/ (*entry fluid expr 1)
 .globl fluid
fluid:
 sub $24,%rsp
 mov l0180,%rdi
 mov %rdi,16(%rsp)
 mov %rax,(%rsp)
 mov l0180,%rax
 mov (%rsp),%rdi
 mov %rdi,8(%rsp)
 mov 8(%rsp),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0181
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 jmp l0182
l0181:
 mov l0180,%rax
l0182:
 mov %rax,16(%rsp)
l0183:
 mov 8(%rsp),%rdi
 shr $56,%rdi
 cmp $9,%rdi
 je l0184
 mov l0180,%rax
 jmp l0185
l0184:
 mov 16(%rsp),%rax
 call *symfnc+3120
 mov 8(%rsp),%rax
 shl $8,%rax
 shr $8,%rax
 mov 8(%rax),%rax
 mov %rax,8(%rsp)
 mov %rax,%rdi
 shr $56,%rdi
 cmp $9,%rdi
 jne l0186
 shl $8,%rax
 shr $8,%rax
 mov (%rax),%rax
 jmp l0187
l0186:
 mov l0180,%rax
l0187:
 mov %rax,16(%rsp)
 jmp l0183
l0185:
 add $24,%rsp
 ret
l0180:
 .quad [[254<<56]+128]
 .quad 1
/ (*entry fluid1 expr 1)
 .globl l0190
l0190:
 mov l0188,%rcx
 mov l0189,%rbx
 jmp *symfnc+3040
l0189:
 .quad [[254<<56]+391]
l0188:
 .quad [[254<<56]+389]
 .quad 1
/ (*entry stderror expr 1)
 .globl stderror
stderror:
 jmp *symfnc+2584
 .quad 2
/ (*entry *define-constant expr 2)
 .globl l0193
l0193:
 mov %rax,%rcx
 shl $8,%rcx
 shr $8,%rcx
 shl $3,%rcx
 add symval+2776,%rcx
 mov %rbx,(%rcx)
 mov l0191,%rcx
 mov l0192,%rbx
 jmp *symfnc+3040
l0192:
 .quad [[254<<56]+393]
l0191:
 .quad [[254<<56]+116]
 .quad 1
/ (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 add %rax,%rax
 mov %rax,%rsi
 add %rsi,%rsi
 add %rsi,%rsi
 add symval+2912,%rsi
 mov l0194,%rdi
 mov %rdi,0(%rsi)
 ret
 .quad 0
l0194:
 .quad undefinedfunction
 .quad 2
/ (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 add %rax,%rax
 mov %rax,%rsi
 add %rsi,%rsi
 add %rsi,%rsi
 add symval+2912,%rsi
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
 add symval+2912,%rsi
 mov l0195,%rdi
 mov %rdi,0(%rsi)
 ret
 .quad 0
l0195:
 .quad compiledcallinginterpreted
 .quad 1
/ (*entry addressapply0 expr 1)
 .globl l0196
l0196:
 jmp  *%rax
 .quad 2
/ (*entry bittable expr 2)
 .globl bittable
bittable:
 push %rbx
 shr $2,%rbx
 movb 0(%rax,%rbx,1),%al
 cbtw
 cwtl
 mov (%rsp),%rbx
 shl $30,%rbx
 shr $62,%rbx
 add %rbx,%rbx
 add $-6,%rbx
 cmp $0,%rbx
 jge l0197
 neg %rbx
 xchg %rbx,%rcx
 shr %cl,%rax
 jmp l0198
l0197:
 xchg %rbx,%rcx
 shl %cl,%rax
l0198:
 xchg %rbx,%rcx
 shl $30,%rax
 shr $62,%rax
 add $8,%rsp
 ret
 .quad 1
/ (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 jmp *symfnc+3168
l0200:
 .quad 26
 .byte 85,110,100,101,102,105,110,101,100
 .byte 32,102,117,110,99,116,105,111,110,32
 .byte 99,97,108,108,101,100,58,32,0
 .quad 1
/ (*entry undefinedfunction-aux expr 1)
 .globl l0201
l0201:
 push %rdi
 mov l0199,%rax
 call *symfnc+2504
 mov symval+2648,%rsi
 pop %rdi
 shl $3,%rdi
 mov 0(%rsi,%rdi,1),%rax
 call *symfnc+2504
 xor %rax,%rax
 call *symfnc+2456
 ret
l0199:
 .quad [[4<<56]+l0200]
 .quad 0
/ (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 mov $254,%rsi
 shl $8,%rdi
 shr $8,%rdi
 shl $56,%rsi
 or %rsi,%rdi
 mov %rdi,symval+3184
 jmp *symfnc+3192
l0203:
 .quad 12
 .byte 70,65,84,65,76,32,69,82,82,79,82,58
 .byte 32,0
 .quad 1
/ (*entry kernel-fatal-error expr 1)
 .globl l0204
l0204:
 push %rax
 mov l0202,%rax
 call *symfnc+2504
 mov (%rsp),%rax
 call *symfnc+2504
 call *symfnc+2512
 mov $-1,%rax
 add $8,%rsp
 jmp *symfnc+2456
l0202:
 .quad [[4<<56]+l0203]
l0206:
 .quad 8
 .byte 73,110,116,101,114,114,117,112,116
 .byte 0
 .quad 0
/ (*entry pslsignalhandler expr 0)
 .globl pslsignalhandler
pslsignalhandler:
 mov l0205,%rax
 call *symfnc+2960
l0205:
 .quad [[4<<56]+l0206]
 .quad 0
/ (*entry echoon expr 0)
 .globl l0207
l0207:
 call echoon
 ret
 .quad 0
/ (*entry echooff expr 0)
 .globl l0208
l0208:
 call echooff
 ret
 .quad 1
/ (*entry external_charsininputbuffer expr 1)
 .globl l0209
l0209:
 push %rax
 mov 0(%rsp),%rcx
 call external_charsininputbuffer
 add $8,%rsp
 ret
 .quad 0
/ (*entry flushstdoutputbuffer expr 0)
 .globl l0210
l0210:
 call flushstdoutputbuffer
 ret
 .quad 0
/ (*entry external_user_homedir_string expr 0)
 .globl l0211
l0211:
 call external_user_homedir_string
 ret
 .quad 1
/ (*entry external_anyuser_homedir_string expr 1)
 .globl l0212
l0212:
 push %rax
 mov 0(%rsp),%rcx
 call external_anyuser_homedir_string
 add $8,%rsp
 ret
 .quad 1
/ (*entry alterheapsize expr 1)
 .globl l0213
l0213:
 push %rax
 mov 0(%rsp),%rcx
 call alterheapsize
 add $8,%rsp
 ret
 .quad 1
/ (*entry allocatemorebps expr 1)
 .globl l0214
l0214:
 push %rax
 mov 0(%rsp),%rcx
 call allocatemorebps
 add $8,%rsp
 ret
 .quad 3
/ (*entry get_file_status expr 3)
 .globl l0215
l0215:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call get_file_status
 add $24,%rsp
 ret
 .quad 2
/ (*entry os_startup_hook expr 2)
 .globl l0216
l0216:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call os_startup_hook
 add $16,%rsp
 ret
 .quad 0
/ (*entry os_cleanup_hook expr 0)
 .globl l0217
l0217:
 call os_cleanup_hook
 ret
 .quad 1
/ (*entry external_alarm expr 1)
 .globl l0218
l0218:
 push %rax
 mov 0(%rsp),%rcx
 call external_alarm
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_ualarm expr 2)
 .globl l0219
l0219:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call external_ualarm
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_time expr 1)
 .globl l0220
l0220:
 push %rax
 mov 0(%rsp),%rcx
 call external_time
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_timc expr 1)
 .globl l0221
l0221:
 push %rax
 mov 0(%rsp),%rcx
 call external_timc
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_stat expr 2)
 .globl l0222
l0222:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call external_stat
 add $16,%rsp
 ret
 .quad 2
/ (*entry external_link expr 2)
 .globl l0223
l0223:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call external_link
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_unlink expr 1)
 .globl l0224
l0224:
 push %rax
 mov 0(%rsp),%rcx
 call external_unlink
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_strlen expr 1)
 .globl l0225
l0225:
 push %rax
 mov 0(%rsp),%rcx
 call external_strlen
 add $8,%rsp
 ret
 .quad 2
/ (*entry external_setenv expr 2)
 .globl l0226
l0226:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call external_setenv
 add $16,%rsp
 ret
 .quad 1
/ (*entry external_getenv expr 1)
 .globl l0227
l0227:
 push %rax
 mov 0(%rsp),%rcx
 call external_getenv
 add $8,%rsp
 ret
 .quad 2
/ (*entry uxfloat expr 2)
 .globl l0228
l0228:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxfloat
 add $16,%rsp
 ret
 .quad 1
/ (*entry uxfix expr 1)
 .globl l0229
l0229:
 push %rax
 mov 0(%rsp),%rcx
 call uxfix
 add $8,%rsp
 ret
 .quad 2
/ (*entry uxassign expr 2)
 .globl l0230
l0230:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxassign
 add $16,%rsp
 ret
 .quad 3
/ (*entry uxplus2 expr 3)
 .globl l0231
l0231:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxplus2
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxdifference expr 3)
 .globl l0232
l0232:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxdifference
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxtimes2 expr 3)
 .globl l0233
l0233:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxtimes2
 add $24,%rsp
 ret
 .quad 3
/ (*entry uxquotient expr 3)
 .globl l0234
l0234:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxquotient
 add $24,%rsp
 ret
 .quad 4
/ (*entry uxgreaterp expr 4)
 .globl l0235
l0235:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxgreaterp
 add $32,%rsp
 ret
 .quad 4
/ (*entry uxlessp expr 4)
 .globl l0236
l0236:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxlessp
 add $32,%rsp
 ret
 .quad 3
/ (*entry uxwritefloat expr 3)
 .globl l0237
l0237:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxwritefloat
 add $24,%rsp
 ret
 .quad 4
/ (*entry uxwritefloat8 expr 4)
 .globl l0238
l0238:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxwritefloat8
 add $32,%rsp
 ret
 .quad 2
/ (*entry uxdoubletofloat expr 2)
 .globl l0239
l0239:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxdoubletofloat
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxfloattodouble expr 2)
 .globl l0240
l0240:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxfloattodouble
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxsin expr 2)
 .globl l0241
l0241:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxsin
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxcos expr 2)
 .globl l0242
l0242:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxcos
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxtan expr 2)
 .globl l0243
l0243:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxtan
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxasin expr 2)
 .globl l0244
l0244:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxasin
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxacos expr 2)
 .globl l0245
l0245:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxacos
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxatan expr 2)
 .globl l0246
l0246:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxatan
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxsqrt expr 2)
 .globl l0247
l0247:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxsqrt
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxexp expr 2)
 .globl l0248
l0248:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxexp
 add $16,%rsp
 ret
 .quad 2
/ (*entry uxlog expr 2)
 .globl l0249
l0249:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxlog
 add $16,%rsp
 ret
 .quad 3
/ (*entry uxatan2 expr 3)
 .globl l0250
l0250:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call uxatan2
 add $24,%rsp
 ret
 .quad 0
/ (*entry external_pwd expr 0)
 .globl l0251
l0251:
 call external_pwd
 ret
 .quad 2
/ (*entry sun3_sigset expr 2)
 .globl l0252
l0252:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call sun3_sigset
 add $16,%rsp
 ret
 .quad 1
/ (*entry sigrelse expr 1)
 .globl l0253
l0253:
 push %rax
 mov 0(%rsp),%rcx
 call sigrelse
 add $8,%rsp
 ret
 .quad 4
/ (*entry unexec expr 4)
 .globl l0254
l0254:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unexec
 add $32,%rsp
 ret
 .quad 1
/ (*entry unixputc expr 1)
 .globl l0255
l0255:
 push %rax
 mov 0(%rsp),%rcx
 call unixputc
 add $8,%rsp
 ret
 .quad 1
/ (*entry unixputs expr 1)
 .globl l0256
l0256:
 push %rax
 mov 0(%rsp),%rcx
 call unixputs
 add $8,%rsp
 ret
 .quad 1
/ (*entry unixputn expr 1)
 .globl l0257
l0257:
 push %rax
 mov 0(%rsp),%rcx
 call unixputn
 add $8,%rsp
 ret
 .quad 0
/ (*entry unixcleario expr 0)
 .globl l0258
l0258:
 call unixcleario
 ret
 .quad 1
/ (*entry expand_file_name expr 1)
 .globl l0259
l0259:
 push %rax
 mov 0(%rsp),%rcx
 call expand_file_name
 add $8,%rsp
 ret
 .quad 2
/ (*entry unixopen expr 2)
 .globl l0260
l0260:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixopen
 add $16,%rsp
 ret
 .quad 1
/ (*entry unixcd expr 1)
 .globl l0261
l0261:
 push %rax
 mov 0(%rsp),%rcx
 call unixcd
 add $8,%rsp
 ret
 .quad 1
/ (*entry ctime expr 1)
 .globl l0262
l0262:
 push %rax
 mov 0(%rsp),%rcx
 call ctime
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_system expr 1)
 .globl l0263
l0263:
 push %rax
 mov 0(%rsp),%rcx
 call external_system
 add $8,%rsp
 ret
 .quad 1
/ (*entry external_exit expr 1)
 .globl l0264
l0264:
 push %rax
 mov 0(%rsp),%rcx
 call external_exit
 add $8,%rsp
 ret
 .quad 2
/ (*entry fopen expr 2)
 .globl l0265
l0265:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixopen
 add $16,%rsp
 ret
 .quad 1
/ (*entry fclose expr 1)
 .globl l0266
l0266:
 push %rax
 mov 0(%rsp),%rcx
 call unixfclose
 add $8,%rsp
 ret
 .quad 4
/ (*entry fread expr 4)
 .globl l0267
l0267:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixfread
 add $32,%rsp
 ret
 .quad 2
/ (*entry fputc expr 2)
 .globl l0268
l0268:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixfputc
 add $16,%rsp
 ret
 .quad 1
/ (*entry fgetc expr 1)
 .globl l0269
l0269:
 push %rax
 mov 0(%rsp),%rcx
 call unixfgetc
 add $8,%rsp
 ret
 .quad 3
/ (*entry fgets expr 3)
 .globl l0270
l0270:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixfgets
 add $24,%rsp
 ret
 .quad 4
/ (*entry fwrite expr 4)
 .globl l0271
l0271:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixfwrite
 add $32,%rsp
 ret
 .quad 1
/ (*entry fflush expr 1)
 .globl l0272
l0272:
 push %rax
 mov 0(%rsp),%rcx
 call unixfflush
 add $8,%rsp
 ret
 .quad 3
/ (*entry fseek expr 3)
 .globl l0273
l0273:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixfseek
 add $24,%rsp
 ret
 .quad 1
/ (*entry clearerr expr 1)
 .globl l0274
l0274:
 push %rax
 mov 0(%rsp),%rcx
 call unixclearerr
 add $8,%rsp
 ret
 .quad 1
/ (*entry xgetw expr 1)
 .globl l0275
l0275:
 push %rax
 mov 0(%rsp),%rcx
 call xgetw
 add $8,%rsp
 ret
 .quad 2
/ (*entry putw expr 2)
 .globl l0276
l0276:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixputw
 add $16,%rsp
 ret
 .quad 2
/ (*entry signal expr 2)
 .globl l0277
l0277:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call signal
 add $16,%rsp
 ret
 .quad 1
/ (*entry sleep expr 1)
 .globl l0278
l0278:
 push %rax
 mov 0(%rsp),%rcx
 call sleep
 add $8,%rsp
 ret
 .quad 3
/ (*entry ieee_handler expr 3)
 .globl l0279
l0279:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call ieee_handler
 add $24,%rsp
 ret
 .quad 4
/ (*entry ieee_flags expr 4)
 .globl l0280
l0280:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call ieee_flags
 add $32,%rsp
 ret
 .quad 1
/ (*entry setlinebuf expr 1)
 .globl l0281
l0281:
 push %rax
 mov 0(%rsp),%rcx
 call setlinebuf
 add $8,%rsp
 ret
 .quad 0
/ (*entry getpid expr 0)
 .globl l0282
l0282:
 call getpid
 ret
 .quad 0
/ (*entry gethostid expr 0)
 .globl l0283
l0283:
 call gethostid
 ret
 .quad 2
/ (*entry unixsocketopen expr 2)
 .globl l0284
l0284:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call unixsocketopen
 add $16,%rsp
 ret
 .quad 3
/ (*entry getsocket expr 3)
 .globl l0285
l0285:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call getsocket
 add $24,%rsp
 ret
 .quad 3
/ (*entry writesocket expr 3)
 .globl l0286
l0286:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call writesocket
 add $24,%rsp
 ret
 .quad 1
/ (*entry unixclosesocket expr 1)
 .globl l0287
l0287:
 push %rax
 mov 0(%rsp),%rcx
 call unixclosesocket
 add $8,%rsp
 ret
 .quad 0
/ (*entry fork expr 0)
 .globl l0288
l0288:
 call fork
 ret
 .quad 1
/ (*entry wait expr 1)
 .globl l0289
l0289:
 push %rax
 mov 0(%rsp),%rcx
 call wait
 add $8,%rsp
 ret
 .quad 2
/ (*entry popen expr 2)
 .globl l0290
l0290:
 push %rbx
 push %rax
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call popen
 add $16,%rsp
 ret
 .quad 1
/ (*entry pclose expr 1)
 .globl l0291
l0291:
 push %rax
 mov 0(%rsp),%rcx
 call pclose
 add $8,%rsp
 ret
 .quad 3
/ (*entry shmctl expr 3)
 .globl l0292
l0292:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call shmctl
 add $24,%rsp
 ret
 .quad 3
/ (*entry shmget expr 3)
 .globl l0293
l0293:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call shmget
 add $24,%rsp
 ret
 .quad 3
/ (*entry shmat expr 3)
 .globl l0294
l0294:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call shmat
 add $24,%rsp
 ret
 .quad 1
/ (*entry shmdt expr 1)
 .globl l0295
l0295:
 push %rax
 mov 0(%rsp),%rcx
 call shmdt
 add $8,%rsp
 ret
 .quad 4
/ (*entry semctl expr 4)
 .globl l0296
l0296:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call semctl
 add $32,%rsp
 ret
 .quad 3
/ (*entry semget expr 3)
 .globl l0297
l0297:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call semget
 add $24,%rsp
 ret
 .quad 3
/ (*entry semop expr 3)
 .globl l0298
l0298:
 push %rcx
 push %rbx
 push %rax
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call semop
 add $24,%rsp
 ret
 .quad 4
/ (*entry unix-profile expr 4)
 .globl l0299
l0299:
 push %rdx
 push %rcx
 push %rbx
 push %rax
 mov 24(%rsp),%rdi
 mov %rdi,%r9
 mov 16(%rsp),%rdi
 mov %rdi,%r8
 mov 8(%rsp),%rdx
 mov 0(%rsp),%rcx
 call profil
 add $32,%rsp
 ret
 .quad 1
/ (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 sub $8,%rsp
 shl $8,%rax
 shr $8,%rax
 mov %rax,(%rsp)
 mov l0300,%rax
 call *symfnc+3872
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jle l0304
 mov l0301,%rax
 jmp l0305
l0304:
 mov l0302,%rax
l0305:
 cmp l0301,%rax
 je l0306
 mov l0303,%rax
 call *symfnc+3872
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jg l0307
 mov l0301,%rax
 jmp l0306
l0307:
 mov l0302,%rax
l0306:
 cmp l0301,%rax
 jne l0308
 mov symval+2272,%rax
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jle l0309
 mov l0301,%rax
 jmp l0310
l0309:
 mov l0302,%rax
l0310:
 cmp l0301,%rax
 je l0308
 mov symval+2288,%rax
 shl $8,%rax
 shr $8,%rax
 cmp (%rsp),%rax
 jg l0311
 mov l0301,%rax
 jmp l0308
l0311:
 mov l0302,%rax
l0308:
 add $8,%rsp
 ret
l0303:
 .quad [[254<<56]+485]
l0302:
 .quad [[254<<56]+116]
l0301:
 .quad [[254<<56]+128]
l0300:
 .quad [[254<<56]+256]
 .quad 1
/ (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 ret
 .quad 0
/ (*entry initcode expr 0)
 .globl initcode
initcode:
 mov l0312,%rax
 ret
l0312:
 .quad [[254<<56]+128]
 .globl symval
 .globl symprp
 .globl symnam
 .globl l0313
l0313:
 .quad 0
 .byte 0,0
 .globl l0314
l0314:
 .quad 0
 .byte 1,0
 .globl l0315
l0315:
 .quad 0
 .byte 2,0
 .globl l0316
l0316:
 .quad 0
 .byte 3,0
 .globl l0317
l0317:
 .quad 0
 .byte 4,0
 .globl l0318
l0318:
 .quad 0
 .byte 5,0
 .globl l0319
l0319:
 .quad 0
 .byte 6,0
 .globl l0320
l0320:
 .quad 0
 .byte 7,0
 .globl l0321
l0321:
 .quad 0
 .byte 8,0
 .globl l0322
l0322:
 .quad 0
 .byte 9,0
 .globl l0323
l0323:
 .quad 0
 .byte 10,0
 .globl l0324
l0324:
 .quad 0
 .byte 11,0
 .globl l0325
l0325:
 .quad 0
 .byte 12,0
 .globl l0326
l0326:
 .quad 0
 .byte 13,0
 .globl l0327
l0327:
 .quad 0
 .byte 14,0
 .globl l0328
l0328:
 .quad 0
 .byte 15,0
 .globl l0329
l0329:
 .quad 0
 .byte 16,0
 .globl l0330
l0330:
 .quad 0
 .byte 17,0
 .globl l0331
l0331:
 .quad 0
 .byte 18,0
 .globl l0332
l0332:
 .quad 0
 .byte 19,0
 .globl l0333
l0333:
 .quad 0
 .byte 20,0
 .globl l0334
l0334:
 .quad 0
 .byte 21,0
 .globl l0335
l0335:
 .quad 0
 .byte 22,0
 .globl l0336
l0336:
 .quad 0
 .byte 23,0
 .globl l0337
l0337:
 .quad 0
 .byte 24,0
 .globl l0338
l0338:
 .quad 0
 .byte 25,0
 .globl l0339
l0339:
 .quad 0
 .byte 26,0
 .globl l0340
l0340:
 .quad 0
 .byte 27,0
 .globl l0341
l0341:
 .quad 0
 .byte 28,0
 .globl l0342
l0342:
 .quad 0
 .byte 29,0
 .globl l0343
l0343:
 .quad 0
 .byte 30,0
 .globl l0344
l0344:
 .quad 0
 .byte 31,0
 .globl l0345
l0345:
 .quad 0
 .byte 32,0
 .globl l0346
l0346:
 .quad 0
 .byte 33,0
 .globl l0347
l0347:
 .quad 0
 .byte 34,0
 .globl l0348
l0348:
 .quad 0
 .byte 35,0
 .globl l0349
l0349:
 .quad 0
 .byte 36,0
 .globl l0350
l0350:
 .quad 0
 .byte 37,0
 .globl l0351
l0351:
 .quad 0
 .byte 38,0
 .globl l0352
l0352:
 .quad 0
 .byte 39,0
 .globl l0353
l0353:
 .quad 0
 .byte 40,0
 .globl l0354
l0354:
 .quad 0
 .byte 41,0
 .globl l0355
l0355:
 .quad 0
 .byte 42,0
 .globl l0356
l0356:
 .quad 0
 .byte 43,0
 .globl l0357
l0357:
 .quad 0
 .byte 44,0
 .globl l0358
l0358:
 .quad 0
 .byte 45,0
 .globl l0359
l0359:
 .quad 0
 .byte 46,0
 .globl l0360
l0360:
 .quad 0
 .byte 47,0
 .globl l0361
l0361:
 .quad 0
 .byte 48,0
 .globl l0362
l0362:
 .quad 0
 .byte 49,0
 .globl l0363
l0363:
 .quad 0
 .byte 50,0
 .globl l0364
l0364:
 .quad 0
 .byte 51,0
 .globl l0365
l0365:
 .quad 0
 .byte 52,0
 .globl l0366
l0366:
 .quad 0
 .byte 53,0
 .globl l0367
l0367:
 .quad 0
 .byte 54,0
 .globl l0368
l0368:
 .quad 0
 .byte 55,0
 .globl l0369
l0369:
 .quad 0
 .byte 56,0
 .globl l0370
l0370:
 .quad 0
 .byte 57,0
 .globl l0371
l0371:
 .quad 0
 .byte 58,0
 .globl l0372
l0372:
 .quad 0
 .byte 59,0
 .globl l0373
l0373:
 .quad 0
 .byte 60,0
 .globl l0374
l0374:
 .quad 0
 .byte 61,0
 .globl l0375
l0375:
 .quad 0
 .byte 62,0
 .globl l0376
l0376:
 .quad 0
 .byte 63,0
 .globl l0377
l0377:
 .quad 0
 .byte 64,0
 .globl l0378
l0378:
 .quad 0
 .byte 65,0
 .globl l0379
l0379:
 .quad 0
 .byte 66,0
 .globl l0380
l0380:
 .quad 0
 .byte 67,0
 .globl l0381
l0381:
 .quad 0
 .byte 68,0
 .globl l0382
l0382:
 .quad 0
 .byte 69,0
 .globl l0383
l0383:
 .quad 0
 .byte 70,0
 .globl l0384
l0384:
 .quad 0
 .byte 71,0
 .globl l0385
l0385:
 .quad 0
 .byte 72,0
 .globl l0386
l0386:
 .quad 0
 .byte 73,0
 .globl l0387
l0387:
 .quad 0
 .byte 74,0
 .globl l0388
l0388:
 .quad 0
 .byte 75,0
 .globl l0389
l0389:
 .quad 0
 .byte 76,0
 .globl l0390
l0390:
 .quad 0
 .byte 77,0
 .globl l0391
l0391:
 .quad 0
 .byte 78,0
 .globl l0392
l0392:
 .quad 0
 .byte 79,0
 .globl l0393
l0393:
 .quad 0
 .byte 80,0
 .globl l0394
l0394:
 .quad 0
 .byte 81,0
 .globl l0395
l0395:
 .quad 0
 .byte 82,0
 .globl l0396
l0396:
 .quad 0
 .byte 83,0
 .globl l0397
l0397:
 .quad 0
 .byte 84,0
 .globl l0398
l0398:
 .quad 0
 .byte 85,0
 .globl l0399
l0399:
 .quad 0
 .byte 86,0
 .globl l0400
l0400:
 .quad 0
 .byte 87,0
 .globl l0401
l0401:
 .quad 0
 .byte 88,0
 .globl l0402
l0402:
 .quad 0
 .byte 89,0
 .globl l0403
l0403:
 .quad 0
 .byte 90,0
 .globl l0404
l0404:
 .quad 0
 .byte 91,0
 .globl l0405
l0405:
 .quad 0
 .byte 92,0
 .globl l0406
l0406:
 .quad 0
 .byte 93,0
 .globl l0407
l0407:
 .quad 0
 .byte 94,0
 .globl l0408
l0408:
 .quad 0
 .byte 95,0
 .globl l0409
l0409:
 .quad 0
 .byte 96,0
 .globl l0410
l0410:
 .quad 0
 .byte 97,0
 .globl l0411
l0411:
 .quad 0
 .byte 98,0
 .globl l0412
l0412:
 .quad 0
 .byte 99,0
 .globl l0413
l0413:
 .quad 0
 .byte 100,0
 .globl l0414
l0414:
 .quad 0
 .byte 101,0
 .globl l0415
l0415:
 .quad 0
 .byte 102,0
 .globl l0416
l0416:
 .quad 0
 .byte 103,0
 .globl l0417
l0417:
 .quad 0
 .byte 104,0
 .globl l0418
l0418:
 .quad 0
 .byte 105,0
 .globl l0419
l0419:
 .quad 0
 .byte 106,0
 .globl l0420
l0420:
 .quad 0
 .byte 107,0
 .globl l0421
l0421:
 .quad 0
 .byte 108,0
 .globl l0422
l0422:
 .quad 0
 .byte 109,0
 .globl l0423
l0423:
 .quad 0
 .byte 110,0
 .globl l0424
l0424:
 .quad 0
 .byte 111,0
 .globl l0425
l0425:
 .quad 0
 .byte 112,0
 .globl l0426
l0426:
 .quad 0
 .byte 113,0
 .globl l0427
l0427:
 .quad 0
 .byte 114,0
 .globl l0428
l0428:
 .quad 0
 .byte 115,0
 .globl l0429
l0429:
 .quad 0
 .byte 116,0
 .globl l0430
l0430:
 .quad 0
 .byte 117,0
 .globl l0431
l0431:
 .quad 0
 .byte 118,0
 .globl l0432
l0432:
 .quad 0
 .byte 119,0
 .globl l0433
l0433:
 .quad 0
 .byte 120,0
 .globl l0434
l0434:
 .quad 0
 .byte 121,0
 .globl l0435
l0435:
 .quad 0
 .byte 122,0
 .globl l0436
l0436:
 .quad 0
 .byte 123,0
 .globl l0437
l0437:
 .quad 0
 .byte 124,0
 .globl l0438
l0438:
 .quad 0
 .byte 125,0
 .globl l0439
l0439:
 .quad 0
 .byte 126,0
 .globl l0440
l0440:
 .quad 0
 .byte 127,0
 .globl l0441
l0441:
 .quad 2
 .byte 110,105,108,0
 .globl l0442
l0442:
 .quad 0
 .byte -127,0
 .globl l0443
l0443:
 .quad 0
 .byte -126,0
 .globl l0444
l0444:
 .quad 0
 .byte -125,0
 .globl l0445
l0445:
 .quad 0
 .byte -124,0
 .globl l0446
l0446:
 .quad 0
 .byte -123,0
 .globl l0447
l0447:
 .quad 0
 .byte -122,0
 .globl l0448
l0448:
 .quad 0
 .byte -121,0
 .globl l0449
l0449:
 .quad 0
 .byte -120,0
 .globl l0450
l0450:
 .quad 0
 .byte -119,0
 .globl l0451
l0451:
 .quad 0
 .byte -118,0
 .globl l0452
l0452:
 .quad 0
 .byte -117,0
 .globl l0453
l0453:
 .quad 0
 .byte -116,0
 .globl l0454
l0454:
 .quad 0
 .byte -115,0
 .globl l0455
l0455:
 .quad 0
 .byte -114,0
 .globl l0456
l0456:
 .quad 0
 .byte -113,0
 .globl l0457
l0457:
 .quad 0
 .byte -112,0
 .globl l0458
l0458:
 .quad 0
 .byte -111,0
 .globl l0459
l0459:
 .quad 0
 .byte -110,0
 .globl l0460
l0460:
 .quad 0
 .byte -109,0
 .globl l0461
l0461:
 .quad 0
 .byte -108,0
 .globl l0462
l0462:
 .quad 0
 .byte -107,0
 .globl l0463
l0463:
 .quad 0
 .byte -106,0
 .globl l0464
l0464:
 .quad 0
 .byte -105,0
 .globl l0465
l0465:
 .quad 0
 .byte -104,0
 .globl l0466
l0466:
 .quad 0
 .byte -103,0
 .globl l0467
l0467:
 .quad 0
 .byte -102,0
 .globl l0468
l0468:
 .quad 0
 .byte -101,0
 .globl l0469
l0469:
 .quad 0
 .byte -100,0
 .globl l0470
l0470:
 .quad 0
 .byte -99,0
 .globl l0471
l0471:
 .quad 0
 .byte -98,0
 .globl l0472
l0472:
 .quad 0
 .byte -97,0
 .globl l0473
l0473:
 .quad 0
 .byte -96,0
 .globl l0474
l0474:
 .quad 0
 .byte -95,0
 .globl l0475
l0475:
 .quad 0
 .byte -94,0
 .globl l0476
l0476:
 .quad 0
 .byte -93,0
 .globl l0477
l0477:
 .quad 0
 .byte -92,0
 .globl l0478
l0478:
 .quad 0
 .byte -91,0
 .globl l0479
l0479:
 .quad 0
 .byte -90,0
 .globl l0480
l0480:
 .quad 0
 .byte -89,0
 .globl l0481
l0481:
 .quad 0
 .byte -88,0
 .globl l0482
l0482:
 .quad 0
 .byte -87,0
 .globl l0483
l0483:
 .quad 0
 .byte -86,0
 .globl l0484
l0484:
 .quad 0
 .byte -85,0
 .globl l0485
l0485:
 .quad 0
 .byte -84,0
 .globl l0486
l0486:
 .quad 0
 .byte -83,0
 .globl l0487
l0487:
 .quad 0
 .byte -82,0
 .globl l0488
l0488:
 .quad 0
 .byte -81,0
 .globl l0489
l0489:
 .quad 0
 .byte -80,0
 .globl l0490
l0490:
 .quad 0
 .byte -79,0
 .globl l0491
l0491:
 .quad 0
 .byte -78,0
 .globl l0492
l0492:
 .quad 0
 .byte -77,0
 .globl l0493
l0493:
 .quad 0
 .byte -76,0
 .globl l0494
l0494:
 .quad 0
 .byte -75,0
 .globl l0495
l0495:
 .quad 0
 .byte -74,0
 .globl l0496
l0496:
 .quad 0
 .byte -73,0
 .globl l0497
l0497:
 .quad 0
 .byte -72,0
 .globl l0498
l0498:
 .quad 0
 .byte -71,0
 .globl l0499
l0499:
 .quad 0
 .byte -70,0
 .globl l0500
l0500:
 .quad 0
 .byte -69,0
 .globl l0501
l0501:
 .quad 0
 .byte -68,0
 .globl l0502
l0502:
 .quad 0
 .byte -67,0
 .globl l0503
l0503:
 .quad 0
 .byte -66,0
 .globl l0504
l0504:
 .quad 0
 .byte -65,0
 .globl l0505
l0505:
 .quad 0
 .byte -64,0
 .globl l0506
l0506:
 .quad 0
 .byte -63,0
 .globl l0507
l0507:
 .quad 0
 .byte -62,0
 .globl l0508
l0508:
 .quad 0
 .byte -61,0
 .globl l0509
l0509:
 .quad 0
 .byte -60,0
 .globl l0510
l0510:
 .quad 0
 .byte -59,0
 .globl l0511
l0511:
 .quad 0
 .byte -58,0
 .globl l0512
l0512:
 .quad 0
 .byte -57,0
 .globl l0513
l0513:
 .quad 0
 .byte -56,0
 .globl l0514
l0514:
 .quad 0
 .byte -55,0
 .globl l0515
l0515:
 .quad 0
 .byte -54,0
 .globl l0516
l0516:
 .quad 0
 .byte -53,0
 .globl l0517
l0517:
 .quad 0
 .byte -52,0
 .globl l0518
l0518:
 .quad 0
 .byte -51,0
 .globl l0519
l0519:
 .quad 0
 .byte -50,0
 .globl l0520
l0520:
 .quad 0
 .byte -49,0
 .globl l0521
l0521:
 .quad 0
 .byte -48,0
 .globl l0522
l0522:
 .quad 0
 .byte -47,0
 .globl l0523
l0523:
 .quad 0
 .byte -46,0
 .globl l0524
l0524:
 .quad 0
 .byte -45,0
 .globl l0525
l0525:
 .quad 0
 .byte -44,0
 .globl l0526
l0526:
 .quad 0
 .byte -43,0
 .globl l0527
l0527:
 .quad 0
 .byte -42,0
 .globl l0528
l0528:
 .quad 0
 .byte -41,0
 .globl l0529
l0529:
 .quad 0
 .byte -40,0
 .globl l0530
l0530:
 .quad 0
 .byte -39,0
 .globl l0531
l0531:
 .quad 0
 .byte -38,0
 .globl l0532
l0532:
 .quad 0
 .byte -37,0
 .globl l0533
l0533:
 .quad 0
 .byte -36,0
 .globl l0534
l0534:
 .quad 0
 .byte -35,0
 .globl l0535
l0535:
 .quad 0
 .byte -34,0
 .globl l0536
l0536:
 .quad 0
 .byte -33,0
 .globl l0537
l0537:
 .quad 0
 .byte -32,0
 .globl l0538
l0538:
 .quad 0
 .byte -31,0
 .globl l0539
l0539:
 .quad 0
 .byte -30,0
 .globl l0540
l0540:
 .quad 0
 .byte -29,0
 .globl l0541
l0541:
 .quad 0
 .byte -28,0
 .globl l0542
l0542:
 .quad 0
 .byte -27,0
 .globl l0543
l0543:
 .quad 0
 .byte -26,0
 .globl l0544
l0544:
 .quad 0
 .byte -25,0
 .globl l0545
l0545:
 .quad 0
 .byte -24,0
 .globl l0546
l0546:
 .quad 0
 .byte -23,0
 .globl l0547
l0547:
 .quad 0
 .byte -22,0
 .globl l0548
l0548:
 .quad 0
 .byte -21,0
 .globl l0549
l0549:
 .quad 0
 .byte -20,0
 .globl l0550
l0550:
 .quad 0
 .byte -19,0
 .globl l0551
l0551:
 .quad 0
 .byte -18,0
 .globl l0552
l0552:
 .quad 0
 .byte -17,0
 .globl l0553
l0553:
 .quad 0
 .byte -16,0
 .globl l0554
l0554:
 .quad 0
 .byte -15,0
 .globl l0555
l0555:
 .quad 0
 .byte -14,0
 .globl l0556
l0556:
 .quad 0
 .byte -13,0
 .globl l0557
l0557:
 .quad 0
 .byte -12,0
 .globl l0558
l0558:
 .quad 0
 .byte -11,0
 .globl l0559
l0559:
 .quad 0
 .byte -10,0
 .globl l0560
l0560:
 .quad 0
 .byte -9,0
 .globl l0561
l0561:
 .quad 0
 .byte -8,0
 .globl l0562
l0562:
 .quad 0
 .byte -7,0
 .globl l0563
l0563:
 .quad 0
 .byte -6,0
 .globl l0564
l0564:
 .quad 0
 .byte -5,0
 .globl l0565
l0565:
 .quad 0
 .byte -4,0
 .globl l0566
l0566:
 .quad 0
 .byte -3,0
 .globl l0567
l0567:
 .quad 0
 .byte -2,0
 .globl l0568
l0568:
 .quad 0
 .byte -1,0
 .globl l0569
l0569:
 .quad 10
 .byte 102,105,114,115,116,107,101,114,110
 .byte 101,108,0
 .globl l0570
l0570:
 .quad 4
 .byte 115,116,97,99,107,0
 .globl l0571
l0571:
 .quad 12
 .byte 97,114,103,117,109,101,110,116,98,108
 .byte 111,99,107,0
 .globl l0572
l0572:
 .quad 10
 .byte 116,111,107,101,110,98,117,102,102
 .byte 101,114,0
 .globl l0573
l0573:
 .quad 5
 .byte 98,110,100,115,116,107,0,0
 .globl l0574
l0574:
 .quad 9
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 0,0
 .globl l0575
l0575:
 .quad 8
 .byte 104,97,115,104,116,97,98,108,101,0
 .globl l0576
l0576:
 .quad 12
 .byte 111,110,101,119,111,114,100,98,117
 .byte 102,102,101,114,0
 .globl l0577
l0577:
 .quad 7
 .byte 115,97,118,101,97,114,103,99,0,0
 .globl l0578
l0578:
 .quad 7
 .byte 115,97,118,101,97,114,103,118,0,0
 .globl l0579
l0579:
 .quad 9
 .byte 100,97,116,101,98,117,102,102,101,114
 .byte 0,0
 .globl l0580
l0580:
 .quad 12
 .byte 105,110,105,116,45,112,111,105,110
 .byte 116,101,114,115,0
 .globl l0581
l0581:
 .quad 12
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 112,116,114,0
 .globl l0582
l0582:
 .quad 15
 .byte 98,110,100,115,116,107,108,111,119
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0583
l0583:
 .quad 15
 .byte 98,110,100,115,116,107,117,112,112
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0584
l0584:
 .quad 8
 .byte 98,110,100,115,116,107,112,116,114
 .byte 0
 .globl l0585
l0585:
 .quad 13
 .byte 104,101,97,112,108,111,119,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0586
l0586:
 .quad 3
 .byte 104,101,97,112,0,0
 .globl l0587
l0587:
 .quad 10
 .byte 105,110,105,116,45,102,108,117,105
 .byte 100,115,0
 .globl l0588
l0588:
 .quad 16
 .byte 103,99,97,114,114,97,121,108,111,119
 .byte 101,114,98,111,117,110,100,0
 .globl l0589
l0589:
 .quad 16
 .byte 103,99,97,114,114,97,121,117,112,112
 .byte 101,114,98,111,117,110,100,0
 .globl l0590
l0590:
 .quad 7
 .byte 104,101,97,112,108,97,115,116,0,0
 .globl l0591
l0591:
 .quad 10
 .byte 111,108,100,104,101,97,112,108,97,115
 .byte 116,0
 .globl l0592
l0592:
 .quad 12
 .byte 104,101,97,112,116,114,97,112,98,111
 .byte 117,110,100,0
 .globl l0593
l0593:
 .quad 15
 .byte 111,108,100,104,101,97,112,116,114
 .byte 97,112,98,111,117,110,100,0,0
 .globl l0594
l0594:
 .quad 13
 .byte 104,101,97,112,117,112,112,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0595
l0595:
 .quad 13
 .byte 95,105,110,102,98,105,116,108,101,110
 .byte 103,116,104,95,0,0
 .globl l0596
l0596:
 .quad 6
 .byte 108,97,115,116,98,112,115,0
 .globl l0597
l0597:
 .quad 12
 .byte 98,112,115,108,111,119,101,114,98,111
 .byte 117,110,100,0
 .globl l0598
l0598:
 .quad 18
 .byte 109,97,105,110,115,116,97,114,116,105
 .byte 110,105,116,105,97,108,105,122,101
 .byte 0
 .globl l0599
l0599:
 .quad 6
 .byte 110,101,120,116,98,112,115,0
 .globl l0600
l0600:
 .quad 16
 .byte 111,108,100,104,101,97,112,117,112
 .byte 112,101,114,98,111,117,110,100,0
 .globl l0601
l0601:
 .quad 16
 .byte 111,108,100,104,101,97,112,108,111
 .byte 119,101,114,98,111,117,110,100,0
 .globl l0602
l0602:
 .quad 14
 .byte 115,116,97,99,107,117,112,112,101,114
 .byte 98,111,117,110,100,0
 .globl l0603
l0603:
 .quad 8
 .byte 117,110,105,120,115,116,100,105,110
 .byte 0
 .globl l0604
l0604:
 .quad 9
 .byte 117,110,105,120,115,116,100,111,117
 .byte 116,0,0
 .globl l0605
l0605:
 .quad 9
 .byte 117,110,105,120,115,116,100,101,114
 .byte 114,0,0
 .globl l0606
l0606:
 .quad 7
 .byte 117,110,105,120,110,117,108,108,0,0
 .globl l0607
l0607:
 .quad 6
 .byte 117,110,105,120,101,111,102,0
 .globl l0608
l0608:
 .quad 6
 .byte 117,110,105,120,116,116,121,0
 .globl l0609
l0609:
 .quad 16
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,42,42,42,0
 .globl l0610
l0610:
 .quad 20
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,45,116,111,111,42,42
 .byte 42,0
 .globl l0611
l0611:
 .quad 7
 .byte 42,102,97,115,116,99,97,114,0,0
 .globl l0612
l0612:
 .quad 3
 .byte 109,97,105,110,0,0
 .globl l0613
l0613:
 .quad 14
 .byte 111,115,95,115,116,97,114,116,117,112
 .byte 95,104,111,111,107,0
 .globl l0614
l0614:
 .quad 3
 .byte 97,114,103,99,0,0
 .globl l0615
l0615:
 .quad 3
 .byte 97,114,103,118,0,0
 .globl l0616
l0616:
 .quad 7
 .byte 101,98,120,115,97,118,101,42,0,0
 .globl l0617
l0617:
 .quad 14
 .byte 115,116,97,99,107,108,111,119,101,114
 .byte 98,111,117,110,100,0
 .globl l0618
l0618:
 .quad 11
 .byte 105,110,105,116,45,103,99,97,114,114
 .byte 97,121,0,0
 .globl l0619
l0619:
 .quad 7
 .byte 112,114,101,45,109,97,105,110,0,0
 .globl l0620
l0620:
 .quad 15
 .byte 101,120,105,116,45,119,105,116,104
 .byte 45,115,116,97,116,117,115,0,0
 .globl l0621
l0621:
 .quad 14
 .byte 111,115,95,99,108,101,97,110,117,112
 .byte 95,104,111,111,107,0
 .globl l0622
l0622:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,101
 .byte 120,105,116,0
 .globl l0623
l0623:
 .quad 10
 .byte 117,110,105,120,99,108,101,97,114,105
 .byte 111,0
 .globl l0624
l0624:
 .quad 22
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,115,121,109,98,111,108,45,116
 .byte 97,98,108,101,0
 .globl l0625
l0625:
 .quad 7
 .byte 105,110,105,116,99,111,100,101,0,0
 .globl l0626
l0626:
 .quad 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,115,116,114,105,110
 .byte 103,0,0
 .globl l0627
l0627:
 .quad 14
 .byte 99,111,110,115,111,108,101,45,110,101
 .byte 119,108,105,110,101,0
 .globl l0628
l0628:
 .quad 5
 .byte 102,97,115,108,105,110,0,0
 .globl l0629
l0629:
 .quad 10
 .byte 108,111,97,100,101,114,45,109,97,105
 .byte 110,0
 .globl l0630
l0630:
 .quad 7
 .byte 117,110,105,120,112,117,116,115,0,0
 .globl l0631
l0631:
 .quad 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,110,117,109,98,101,114
 .byte 0,0
 .globl l0632
l0632:
 .quad 7
 .byte 117,110,105,120,112,117,116,110,0,0
 .globl l0633
l0633:
 .quad 7
 .byte 117,110,105,120,112,117,116,99,0,0
 .globl l0634
l0634:
 .quad 13
 .byte 98,105,110,97,114,121,111,112,101,110
 .byte 114,101,97,100,0,0
 .globl l0635
l0635:
 .quad 7
 .byte 117,110,105,120,111,112,101,110,0,0
 .globl l0636
l0636:
 .quad 17
 .byte 107,101,114,110,101,108,45,102,97,116
 .byte 97,108,45,101,114,114,111,114,0,0
 .globl l0637
l0637:
 .quad 9
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 0,0
 .globl l0638
l0638:
 .quad 4
 .byte 120,103,101,116,119,0
 .globl l0639
l0639:
 .quad 14
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 98,108,111,99,107,0
 .globl l0640
l0640:
 .quad 4
 .byte 102,114,101,97,100,0
 .globl l0641
l0641:
 .quad 10
 .byte 98,105,110,97,114,121,99,108,111,115
 .byte 101,0
 .globl l0642
l0642:
 .quad 5
 .byte 102,99,108,111,115,101,0,0
 .globl l0643
l0643:
 .quad 9
 .byte 110,101,120,116,115,121,109,98,111
 .byte 108,0,0
 .globl l0644
l0644:
 .quad 5
 .byte 115,121,109,110,97,109,0,0
 .globl l0645
l0645:
 .quad 14
 .byte 104,97,115,104,45,105,110,116,111,45
 .byte 116,97,98,108,101,0
 .globl l0646
l0646:
 .quad 11
 .byte 115,104,111,119,45,110,101,119,45,105
 .byte 100,115,0,0
 .globl l0647
l0647:
 .quad 12
 .byte 102,97,115,108,105,110,45,105,110,116
 .byte 101,114,110,0
 .globl l0648
l0648:
 .quad 26
 .byte 115,101,97,114,99,104,45,115,116,114
 .byte 105,110,103,45,102,111,114,45,99,104
 .byte 97,114,97,99,116,101,114,0
 .globl l0649
l0649:
 .quad 5
 .byte 105,110,116,101,114,110,0,0
 .globl l0650
l0650:
 .quad 5
 .byte 115,117,98,115,101,113,0,0
 .globl l0651
l0651:
 .quad 22
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,105,110
 .byte 116,101,114,110,0
 .globl l0652
l0652:
 .quad 3
 .byte 103,116,105,100,0,0
 .globl l0653
l0653:
 .quad 9
 .byte 103,116,99,111,110,115,116,115,116
 .byte 114,0,0
 .globl l0654
l0654:
 .quad 15
 .byte 99,111,112,121,115,116,114,105,110
 .byte 103,116,111,102,114,111,109,0,0
 .globl l0655
l0655:
 .quad 16
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,110,101,119,45,105,100,0
 .globl l0656
l0656:
 .quad 12
 .byte 104,97,115,104,45,102,117,110,99,116
 .byte 105,111,110,0
 .globl l0657
l0657:
 .quad 21
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,101,113
 .byte 117,97,108,0,0
 .globl l0658
l0658:
 .quad 5
 .byte 115,121,109,112,114,112,0,0
 .globl l0659
l0659:
 .quad 5
 .byte 115,121,109,103,101,116,0,0
 .globl l0660
l0660:
 .quad 5
 .byte 115,121,109,118,97,108,0,0
 .globl l0661
l0661:
 .quad 11
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,0,0
 .globl l0662
l0662:
 .quad 14
 .byte 102,97,115,108,105,110,45,98,97,100
 .byte 45,102,105,108,101,0
 .globl l0663
l0663:
 .quad 12
 .byte 114,101,97,100,45,105,100,45,116,97
 .byte 98,108,101,0
 .globl l0664
l0664:
 .quad 4
 .byte 103,116,98,112,115,0
 .globl l0665
l0665:
 .quad 5
 .byte 103,116,119,114,100,115,0,0
 .globl l0666
l0666:
 .quad 16
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,45,110,101,119,0
 .globl l0667
l0667:
 .quad 12
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,0
 .globl l0668
l0668:
 .quad 13
 .byte 99,111,100,101,45,98,97,115,101,45
 .byte 104,97,99,107,0,0
 .globl l0669
l0669:
 .quad 12
 .byte 97,100,100,114,101,115,115,97,112,112
 .byte 108,121,48,0
 .globl l0670
l0670:
 .quad 5
 .byte 100,101,108,98,112,115,0,0
 .globl l0671
l0671:
 .quad 7
 .byte 98,105,116,116,97,98,108,101,0,0
 .globl l0672
l0672:
 .quad 18
 .byte 114,101,108,111,99,97,116,101,45,114
 .byte 105,103,104,116,45,104,97,108,102,0
 .globl l0673
l0673:
 .quad 12
 .byte 114,101,108,111,99,97,116,101,45,119
 .byte 111,114,100,0
 .globl l0674
l0674:
 .quad 11
 .byte 114,101,108,111,99,97,116,101,45,105
 .byte 110,102,0,0
 .globl l0675
l0675:
 .quad 17
 .byte 99,111,109,112,117,116,101,45,114,101
 .byte 108,111,99,97,116,105,111,110,0,0
 .globl l0676
l0676:
 .quad 17
 .byte 108,111,99,97,108,45,116,111,45,103
 .byte 108,111,98,97,108,45,105,100,0,0
 .globl l0677
l0677:
 .quad 5
 .byte 115,121,109,102,110,99,0,0
 .globl l0678
l0678:
 .quad 3
 .byte 112,117,116,100,0,0
 .globl l0679
l0679:
 .quad 7
 .byte 112,117,116,101,110,116,114,121,0,0
 .globl l0680
l0680:
 .quad 14
 .byte 103,116,98,112,115,45,110,105,108,45
 .byte 101,114,114,111,114,0
 .globl l0681
l0681:
 .quad 3
 .byte 103,101,116,100,0,0
 .globl l0682
l0682:
 .quad 19
 .byte 116,114,121,45,111,116,104,101,114
 .byte 45,98,112,115,45,115,112,97,99,101
 .byte 115,0,0
 .globl l0683
l0683:
 .quad 7
 .byte 115,116,100,101,114,114,111,114,0,0
 .globl l0684
l0684:
 .quad 5
 .byte 103,116,104,101,97,112,0,0
 .globl l0685
l0685:
 .quad 15
 .byte 107,110,111,119,110,45,102,114,101
 .byte 101,45,115,112,97,99,101,0,0
 .globl l0686
l0686:
 .quad 10
 .byte 114,101,97,108,45,103,116,104,101,97
 .byte 112,0
 .globl l0687
l0687:
 .quad 12
 .byte 103,101,116,45,104,101,97,112,45,116
 .byte 114,97,112,0
 .globl l0688
l0688:
 .quad 6
 .byte 114,101,99,108,97,105,109,0
 .globl l0689
l0689:
 .quad 4
 .byte 103,116,115,116,114,0
 .globl l0690
l0690:
 .quad 3
 .byte 99,111,110,115,0,0
 .globl l0691
l0691:
 .quad 10
 .byte 105,110,116,101,114,114,111,103,97
 .byte 116,101,0
 .globl l0692
l0692:
 .quad 5
 .byte 109,111,100,105,102,121,0,0
 .globl l0693
l0693:
 .quad 2
 .byte 112,117,116,0
 .globl l0694
l0694:
 .quad 12
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,117,116,0
 .globl l0695
l0695:
 .quad 13
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,114,111,112,0,0
 .globl l0696
l0696:
 .quad 4
 .byte 97,116,115,111,99,0
 .globl l0697
l0697:
 .quad 16
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,101,116,112,114,111,112,0
 .globl l0698
l0698:
 .quad 8
 .byte 99,111,100,101,45,112,117,116,100,0
 .globl l0699
l0699:
 .quad 15
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,0,0
 .globl l0700
l0700:
 .quad 3
 .byte 116,121,112,101,0,0
 .globl l0701
l0701:
 .quad 3
 .byte 101,120,112,114,0,0
 .globl l0702
l0702:
 .quad 4
 .byte 102,108,117,105,100,0
 .globl l0703
l0703:
 .quad 5
 .byte 102,108,117,105,100,49,0,0
 .globl l0704
l0704:
 .quad 6
 .byte 118,97,114,116,121,112,101,0
 .globl l0705
l0705:
 .quad 15
 .byte 42,100,101,102,105,110,101,45,99,111
 .byte 110,115,116,97,110,116,0,0
 .globl l0706
l0706:
 .quad 8
 .byte 99,111,110,115,116,97,110,116,63,0
 .globl l0707
l0707:
 .quad 14
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,0
 .globl l0708
l0708:
 .quad 16
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,0
 .globl l0709
l0709:
 .quad 20
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,45,97
 .byte 117,120,0
 .globl l0710
l0710:
 .quad 25
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,0,0
 .globl l0711
l0711:
 .quad 8
 .byte 99,111,100,101,102,111,114,109,42,0
 .globl l0712
l0712:
 .quad 28
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,97,117
 .byte 120,0
 .globl l0713
l0713:
 .quad 15
 .byte 112,115,108,115,105,103,110,97,108
 .byte 104,97,110,100,108,101,114,0,0
 .globl l0714
l0714:
 .quad 5
 .byte 101,99,104,111,111,110,0,0
 .globl l0715
l0715:
 .quad 6
 .byte 101,99,104,111,111,102,102,0
 .globl l0716
l0716:
 .quad 26
 .byte 101,120,116,101,114,110,97,108,95,99
 .byte 104,97,114,115,105,110,105,110,112
 .byte 117,116,98,117,102,102,101,114,0
 .globl l0717
l0717:
 .quad 19
 .byte 102,108,117,115,104,115,116,100,111
 .byte 117,116,112,117,116,98,117,102,102
 .byte 101,114,0,0
 .globl l0718
l0718:
 .quad 27
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 115,101,114,95,104,111,109,101,100
 .byte 105,114,95,115,116,114,105,110,103
 .byte 0,0
 .globl l0719
l0719:
 .quad 30
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 110,121,117,115,101,114,95,104,111
 .byte 109,101,100,105,114,95,115,116,114
 .byte 105,110,103,0
 .globl l0720
l0720:
 .quad 12
 .byte 97,108,116,101,114,104,101,97,112,115
 .byte 105,122,101,0
 .globl l0721
l0721:
 .quad 14
 .byte 97,108,108,111,99,97,116,101,109,111
 .byte 114,101,98,112,115,0
 .globl l0722
l0722:
 .quad 14
 .byte 103,101,116,95,102,105,108,101,95,115
 .byte 116,97,116,117,115,0
 .globl l0723
l0723:
 .quad 13
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 108,97,114,109,0,0
 .globl l0724
l0724:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 97,108,97,114,109,0
 .globl l0725
l0725:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,101,0
 .globl l0726
l0726:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,99,0
 .globl l0727
l0727:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,97,116,0
 .globl l0728
l0728:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,108
 .byte 105,110,107,0
 .globl l0729
l0729:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 110,108,105,110,107,0
 .globl l0730
l0730:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,114,108,101,110,0
 .globl l0731
l0731:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 101,116,101,110,118,0
 .globl l0732
l0732:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,103
 .byte 101,116,101,110,118,0
 .globl l0733
l0733:
 .quad 6
 .byte 117,120,102,108,111,97,116,0
 .globl l0734
l0734:
 .quad 4
 .byte 117,120,102,105,120,0
 .globl l0735
l0735:
 .quad 7
 .byte 117,120,97,115,115,105,103,110,0,0
 .globl l0736
l0736:
 .quad 6
 .byte 117,120,112,108,117,115,50,0
 .globl l0737
l0737:
 .quad 11
 .byte 117,120,100,105,102,102,101,114,101
 .byte 110,99,101,0,0
 .globl l0738
l0738:
 .quad 7
 .byte 117,120,116,105,109,101,115,50,0,0
 .globl l0739
l0739:
 .quad 9
 .byte 117,120,113,117,111,116,105,101,110
 .byte 116,0,0
 .globl l0740
l0740:
 .quad 9
 .byte 117,120,103,114,101,97,116,101,114
 .byte 112,0,0
 .globl l0741
l0741:
 .quad 6
 .byte 117,120,108,101,115,115,112,0
 .globl l0742
l0742:
 .quad 11
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,0,0
 .globl l0743
l0743:
 .quad 12
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,56,0
 .globl l0744
l0744:
 .quad 14
 .byte 117,120,100,111,117,98,108,101,116
 .byte 111,102,108,111,97,116,0
 .globl l0745
l0745:
 .quad 14
 .byte 117,120,102,108,111,97,116,116,111
 .byte 100,111,117,98,108,101,0
 .globl l0746
l0746:
 .quad 4
 .byte 117,120,115,105,110,0
 .globl l0747
l0747:
 .quad 4
 .byte 117,120,99,111,115,0
 .globl l0748
l0748:
 .quad 4
 .byte 117,120,116,97,110,0
 .globl l0749
l0749:
 .quad 5
 .byte 117,120,97,115,105,110,0,0
 .globl l0750
l0750:
 .quad 5
 .byte 117,120,97,99,111,115,0,0
 .globl l0751
l0751:
 .quad 5
 .byte 117,120,97,116,97,110,0,0
 .globl l0752
l0752:
 .quad 5
 .byte 117,120,115,113,114,116,0,0
 .globl l0753
l0753:
 .quad 4
 .byte 117,120,101,120,112,0
 .globl l0754
l0754:
 .quad 4
 .byte 117,120,108,111,103,0
 .globl l0755
l0755:
 .quad 6
 .byte 117,120,97,116,97,110,50,0
 .globl l0756
l0756:
 .quad 11
 .byte 101,120,116,101,114,110,97,108,95,112
 .byte 119,100,0,0
 .globl l0757
l0757:
 .quad 10
 .byte 115,117,110,51,95,115,105,103,115,101
 .byte 116,0
 .globl l0758
l0758:
 .quad 7
 .byte 115,105,103,114,101,108,115,101,0,0
 .globl l0759
l0759:
 .quad 5
 .byte 117,110,101,120,101,99,0,0
 .globl l0760
l0760:
 .quad 15
 .byte 101,120,112,97,110,100,95,102,105,108
 .byte 101,95,110,97,109,101,0,0
 .globl l0761
l0761:
 .quad 5
 .byte 117,110,105,120,99,100,0,0
 .globl l0762
l0762:
 .quad 4
 .byte 99,116,105,109,101,0
 .globl l0763
l0763:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 121,115,116,101,109,0
 .globl l0764
l0764:
 .quad 4
 .byte 102,111,112,101,110,0
 .globl l0765
l0765:
 .quad 4
 .byte 102,112,117,116,99,0
 .globl l0766
l0766:
 .quad 4
 .byte 102,103,101,116,99,0
 .globl l0767
l0767:
 .quad 4
 .byte 102,103,101,116,115,0
 .globl l0768
l0768:
 .quad 5
 .byte 102,119,114,105,116,101,0,0
 .globl l0769
l0769:
 .quad 5
 .byte 102,102,108,117,115,104,0,0
 .globl l0770
l0770:
 .quad 4
 .byte 102,115,101,101,107,0
 .globl l0771
l0771:
 .quad 7
 .byte 99,108,101,97,114,101,114,114,0,0
 .globl l0772
l0772:
 .quad 3
 .byte 112,117,116,119,0,0
 .globl l0773
l0773:
 .quad 5
 .byte 115,105,103,110,97,108,0,0
 .globl l0774
l0774:
 .quad 4
 .byte 115,108,101,101,112,0
 .globl l0775
l0775:
 .quad 11
 .byte 105,101,101,101,95,104,97,110,100,108
 .byte 101,114,0,0
 .globl l0776
l0776:
 .quad 9
 .byte 105,101,101,101,95,102,108,97,103,115
 .byte 0,0
 .globl l0777
l0777:
 .quad 9
 .byte 115,101,116,108,105,110,101,98,117
 .byte 102,0,0
 .globl l0778
l0778:
 .quad 5
 .byte 103,101,116,112,105,100,0,0
 .globl l0779
l0779:
 .quad 8
 .byte 103,101,116,104,111,115,116,105,100
 .byte 0
 .globl l0780
l0780:
 .quad 13
 .byte 117,110,105,120,115,111,99,107,101
 .byte 116,111,112,101,110,0,0
 .globl l0781
l0781:
 .quad 8
 .byte 103,101,116,115,111,99,107,101,116
 .byte 0
 .globl l0782
l0782:
 .quad 10
 .byte 119,114,105,116,101,115,111,99,107
 .byte 101,116,0
 .globl l0783
l0783:
 .quad 14
 .byte 117,110,105,120,99,108,111,115,101
 .byte 115,111,99,107,101,116,0
 .globl l0784
l0784:
 .quad 3
 .byte 102,111,114,107,0,0
 .globl l0785
l0785:
 .quad 3
 .byte 119,97,105,116,0,0
 .globl l0786
l0786:
 .quad 4
 .byte 112,111,112,101,110,0
 .globl l0787
l0787:
 .quad 5
 .byte 112,99,108,111,115,101,0,0
 .globl l0788
l0788:
 .quad 5
 .byte 115,104,109,99,116,108,0,0
 .globl l0789
l0789:
 .quad 5
 .byte 115,104,109,103,101,116,0,0
 .globl l0790
l0790:
 .quad 4
 .byte 115,104,109,97,116,0
 .globl l0791
l0791:
 .quad 4
 .byte 115,104,109,100,116,0
 .globl l0792
l0792:
 .quad 5
 .byte 115,101,109,99,116,108,0,0
 .globl l0793
l0793:
 .quad 5
 .byte 115,101,109,103,101,116,0,0
 .globl l0794
l0794:
 .quad 4
 .byte 115,101,109,111,112,0
 .globl l0795
l0795:
 .quad 11
 .byte 117,110,105,120,45,112,114,111,102
 .byte 105,108,101,0,0
 .globl l0796
l0796:
 .quad 11
 .byte 99,111,100,101,97,100,100,114,101,115
 .byte 115,112,0,0
 .globl l0797
l0797:
 .quad 14
 .byte 103,101,116,102,99,111,100,101,112
 .byte 111,105,110,116,101,114,0
 .globl l0798
l0798:
 .quad 9
 .byte 108,97,115,116,107,101,114,110,101
 .byte 108,0,0
 .globl symfnc
 .globl symget
