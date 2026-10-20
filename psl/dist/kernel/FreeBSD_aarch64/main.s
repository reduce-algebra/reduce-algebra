        .text
 .align 3
 .quad 1
// (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 ret
 .quad 0
// (*entry move-regs-to-mem expr 0)
 .globl l0006
l0006:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($fluid heaplast)
 ldr X11,l0001
 str X21,[X24, X11, lsl #3]
// ($fluid heaptrapbound)
 ldr X11,l0002
 str X22,[X24, X11, lsl #3]
// ($fluid bndstkptr)
 ldr X11,l0003
 str X25,[X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 ldr X11,l0004
 str X26,[X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 ldr X11,l0005
 str X27,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 .quad 0
// (*entry init-pointers expr 0)
 .globl l0016
l0016:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global catchstack)
 ldr X11,l0007
 ldr X9,[X24, X11, lsl #3]
// ($global catchstackptr)
 ldr X11,l0008
 str X9,[X24, X11, lsl #3]
// ($global bndstk)
 ldr X11,l0009
 ldr X9,[X24, X11, lsl #3]
// ($global bndstklowerbound)
 ldr X11,l0010
 str X9,[X24, X11, lsl #3]
 ldr X0,l0011
// ($global bndstk)
 ldr X11,l0009
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
// ($global bndstkupperbound)
 ldr X11,l0012
 str X0,[X24, X11, lsl #3]
// ($global bndstk)
 ldr X11,l0009
 ldr X9,[X24, X11, lsl #3]
// ($global bndstkptr)
 ldr X11,l0013
 str X9,[X24, X11, lsl #3]
// ($global heaplowerbound)
 ldr X11,l0014
 ldr X0,[X24, X11, lsl #3]
// ($global heap)
 ldr X11,l0015
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 .quad 0
// (*entry init-fluids expr 0)
 .globl l0048
l0048:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
// ($global gcarraylowerbound)
 ldr X11,l0017
 str X0,[X24, X11, lsl #3]
// ($global gcarrayupperbound)
 ldr X11,l0018
 str X0,[X24, X11, lsl #3]
// ($global heaplast)
 ldr X11,l0019
 str X0,[X24, X11, lsl #3]
// ($global oldheaplast)
 ldr X11,l0020
 str X0,[X24, X11, lsl #3]
// ($global heaptrapbound)
 ldr X11,l0021
 str X0,[X24, X11, lsl #3]
// ($global oldheaptrapbound)
 ldr X11,l0022
 str X0,[X24, X11, lsl #3]
// ($global heapupperbound)
 ldr X11,l0023
 str X0,[X24, X11, lsl #3]
// ($global _infbitlength_)
 ldr X11,l0024
 str X0,[X24, X11, lsl #3]
// ($global lastbps)
 ldr X11,l0025
 str X0,[X24, X11, lsl #3]
// ($global bpslowerbound)
 ldr X11,l0026
 str X0,[X24, X11, lsl #3]
// ($global mainstartinitialize)
 ldr X11,l0027
 str X0,[X24, X11, lsl #3]
// ($global nextbps)
 ldr X11,l0028
 str X0,[X24, X11, lsl #3]
// ($global nextbpsw)
 ldr X11,l0029
 str X0,[X24, X11, lsl #3]
// ($global bpsbaserw)
 ldr X11,l0030
 str X0,[X24, X11, lsl #3]
// ($global bpsbaserx)
 ldr X11,l0031
 str X0,[X24, X11, lsl #3]
// ($global bpsoffset)
 ldr X11,l0032
 str X0,[X24, X11, lsl #3]
// ($global staticlisp)
 ldr X11,l0033
 str X0,[X24, X11, lsl #3]
// ($global laststaticlisp)
 ldr X11,l0034
 str X0,[X24, X11, lsl #3]
// ($global nextstaticlisp)
 ldr X11,l0035
 str X0,[X24, X11, lsl #3]
// ($global oldheapupperbound)
 ldr X11,l0036
 str X0,[X24, X11, lsl #3]
// ($global oldheaplowerbound)
 ldr X11,l0037
 str X0,[X24, X11, lsl #3]
// ($global stackupperbound)
 ldr X11,l0038
 str X0,[X24, X11, lsl #3]
// ($global unixstdin)
 ldr X11,l0039
 str X0,[X24, X11, lsl #3]
// ($global unixstdout)
 ldr X11,l0040
 str X0,[X24, X11, lsl #3]
// ($global unixstderr)
 ldr X11,l0041
 str X0,[X24, X11, lsl #3]
// ($global unixnull)
 ldr X11,l0042
 str X0,[X24, X11, lsl #3]
// ($global unixeof)
 ldr X11,l0043
 str X0,[X24, X11, lsl #3]
// ($global unixtty)
 ldr X11,l0044
 str X0,[X24, X11, lsl #3]
// ($global ***must-be-nil***)
 ldr X11,l0045
 str X0,[X24, X11, lsl #3]
// ($global ***must-be-nil-too***)
 ldr X11,l0046
 str X0,[X24, X11, lsl #3]
// ($global *fastcar)
 ldr X11,l0047
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 0
// (*entry _psl_main expr 0)
_psl_main:
 .globl _psl_main
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X29,[sp, #32]
 mov X24,X2
 mov X20,X3
// ($global symval)
 ldr X11,l0049
 str X24,[X24, X11, lsl #3]
// ($global symfnc)
 ldr X11,l0050
 ldr X23,[X24, X11, lsl #3]
 mov X28,#256
 mov X11,#254
 bfi X28,X11,#56,#8
 mov X9,#56
// (fluid _infbitlength_)
 ldr X11,l0051
 str X9,[X24, X11, lsl #3]
// (idloc os_startup_hook)
 ldr X11,l0052
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #16]
// (fluid argc)
 ldr X11,l0053
 str X9,[X24, X11, lsl #3]
 ldr X9,[sp, #24]
// (fluid argv)
 ldr X11,l0054
 str X9,[X24, X11, lsl #3]
 ldr X9,[sp, #32]
// (fluid ebxsave*)
 ldr X11,l0055
 str X9,[X24, X11, lsl #3]
// (idloc init-pointers)
 ldr X11,l0056
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X3,sp
 lsr X3,X3,#5
// (fluid stacklowerbound)
 ldr X11,l0057
 str X3,[X24, X11, lsl #3]
// ($global staticlisp)
 ldr X11,l0058
 ldr X20,[X24, X11, lsl #3]
// ($fluid heaplast)
 ldr X11,l0059
 ldr X21,[X24, X11, lsl #3]
// ($fluid heaptrapbound)
 ldr X11,l0060
 ldr X22,[X24, X11, lsl #3]
// ($fluid bndstkptr)
 ldr X11,l0061
 ldr X25,[X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 ldr X11,l0062
 ldr X26,[X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 ldr X11,l0063
 ldr X27,[X24, X11, lsl #3]
// (idloc init-gcarray)
 ldr X11,l0064
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc pre-main)
 ldr X11,l0065
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0069:
 mov X0,#0
 ldp X29,X30,[sp], #48
// (idloc exit-with-status)
 ldr X11,l0066
 ldr X10,[X23, X11, lsl #3]
 br X10
// (*entry exit-with-status expr 1)
 .globl l0070
l0070:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc os_cleanup_hook)
 ldr X11,l0067
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #32
// (idloc external_exit)
 ldr X11,l0068
 ldr X10,[X23, X11, lsl #3]
 br X10
 ldp X29,X30,[sp], #16
 ret
 .quad 4
// (*entry _reduceup expr 4)
 .globl _reduceup
_reduceup:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X1,[sp, #24]
 str X3,[sp, #16]
 mov X1,X2
// (idloc stringopen)
 ldr X11,l0071
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X1,[sp, #16]
 ldr X0,[sp, #24]
// (idloc stringopen)
 ldr X11,l0071
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
 ldr X0,[sp, #32]
// (idloc rds)
 ldr X11,l0072
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc wrs)
 ldr X11,l0073
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc begin1)
 ldr X11,l0074
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
// (idloc rds)
 ldr X11,l0072
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
// (idloc wrs)
 ldr X11,l0073
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #32]
// (idloc close)
 ldr X11,l0075
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc close)
 ldr X11,l0075
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 0
// (*entry init-gcarray expr 0)
 .globl l0076
l0076:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 0
// (*entry pre-main expr 0)
 .globl l0086
l0086:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// (idloc unixcleario)
 ldr X11,l0077
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc initialize-symbol-table)
 ldr X11,l0078
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc initcode)
 ldr X11,l0079
 ldr X10,[X23, X11, lsl #3]
 blr X10
 adr X0,l0080
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc console-print-string)
 ldr X11,l0081
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11,l0082
 ldr X10,[X23, X11, lsl #3]
 blr X10
 adr X0,l0083
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc faslin)
 ldr X11,l0084
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #16
// (idloc loader-main)
 ldr X11,l0085
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry console-print-string expr 1)
 .globl l0088
l0088:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 add X0,X0,#8
 ldp X29,X30,[sp], #16
// (idloc unixputs)
 ldr X11,l0087
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry console-print-number expr 1)
 .globl l0090
l0090:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc unixputn)
 ldr X11,l0089
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 0
// (*entry console-newline expr 0)
 .globl l0092
l0092:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,#10
 ldp X29,X30,[sp], #16
// (idloc unixputc)
 ldr X11,l0091
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 adr X1,l0093
 mov X11,#4
 bfi X1,X11,#56,#8
 ubfx X1,X1,#0,#56
 add X1,X1,#8
 ubfx X0,X0,#0,#56
 add X0,X0,#8
// (idloc unixopen)
 ldr X11,l0094
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cbnz X0,l0097
 adr X0,l0095
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #16
// (idloc kernel-fatal-error)
 ldr X11,l0096
 ldr X10,[X23, X11, lsl #3]
 br X10
l0097:
 ldp X29,X30,[sp], #16
 ret
 .quad 1
// (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc xgetw)
 ldr X11,l0098
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 3
// (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X4,X1
 mov X3,X0
 mov X1,#8
 mov X0,X4
 ldp X29,X30,[sp], #16
// (idloc fread)
 ldr X11,l0099
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc fclose)
 ldr X11,l0100
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 0
// (*entry initialize-symbol-table expr 0)
 .globl l0109
l0109:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X28,[sp, #16]
 ldr X1,l0101
// ($global nextsymbol)
 ldr X11,l0102
 ldr X0,[X24, X11, lsl #3]
 mov X3,X0
 mov X2,X1
l0110:
 cmp X3,X2
 b.gt l0111
 mov X0,X3
 lsl X0,X0,#3
// ($global symnam)
 ldr X11,l0103
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 mov X1,#1
 add X1,X1,X3
 str X1,[X0]
 add X3,X3,#1
 b l0110
l0111:
// ($global symnam)
 ldr X11,l0103
 ldr X10,[X24, X11, lsl #3]
 ldr X13,l0104
 add X10,X10,X13
 mov X9,#0
 str X9,[X10]
 ldr X1,l0105
 mov X0,#0
 str X0,[sp, #16]
 str X1,[sp, #24]
l0112:
 ldr X9,[sp, #16]
 ldr X10,[sp, #24]
 cmp X9,X10
 b.gt l0113
 mov X2,#0
 ldr X1,[sp, #16]
// ($fluid hashtable)
 ldr X11,l0106
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X12,[sp, #16]
 add X12,X12,#1
 str X12,[sp, #16]
 b l0112
l0113:
// ($global symnam)
 ldr X11,l0103
 ldr X0,[X24, X11, lsl #3]
 ldr X0,[X0, #2048]
// (idloc hash-into-table)
 ldr X11,l0107
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X2,#256
 mov X1,X0
// ($fluid hashtable)
 ldr X11,l0106
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 movn X1,#0
// ($global nextsymbol)
 ldr X11,l0102
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 mov X0,#256
 str X0,[sp, #16]
 str X1,[sp, #24]
l0114:
 ldr X9,[sp, #16]
 ldr X10,[sp, #24]
 cmp X9,X10
 b.gt l0115
 ldr X0,[sp, #16]
 lsl X0,X0,#3
// ($global symnam)
 ldr X11,l0103
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
// (idloc hash-into-table)
 ldr X11,l0107
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #16]
 mov X1,X0
// ($fluid hashtable)
 ldr X11,l0106
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X12,[sp, #16]
 add X12,X12,#1
 str X12,[sp, #16]
 b l0114
l0115:
 mov X0,X28
// ($global show-new-ids)
 ldr X11,l0108
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #32
 ret
 nop
 .quad 1
// (*entry faslin-intern expr 1)
 .globl l0119
l0119:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
 mov X1,X0
 mov X0,#0
// (idloc search-string-for-character)
 ldr X11,l0116
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 cmp X0,X28
 b.ne l0120
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #48
// (idloc intern)
 ldr X11,l0117
 ldr X10,[X23, X11, lsl #3]
 br X10
l0120:
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 sbfx X0,X0,#0,#56
 str X0,[sp, #32]
 ldr X11,[sp, #24]
 cmp X0,X11
 b.le l0121
 mov X1,#1
 ldr X13,[sp, #24]
 add X1,X1,X13
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 cbnz X0,l0121
 ldr X12,[sp, #24]
 add X12,X12,#1
 str X12,[sp, #24]
l0121:
 ldr X9,[sp, #24]
 ldr X10,[sp, #32]
 cmp X9,X10
 b.lt l0122
 ldr X0,[sp, #16]
 b l0123
l0122:
 ldr X2,[sp, #16]
 ubfx X2,X2,#0,#56
 ldr X2,[X2]
 sbfx X2,X2,#0,#56
 add X2,X2,#1
 mov X1,#1
 ldr X13,[sp, #24]
 add X1,X1,X13
 ldr X0,[sp, #16]
// (idloc subseq)
 ldr X11,l0118
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0123:
 ldp X29,X30,[sp], #48
// (idloc intern)
 ldr X11,l0117
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry intern expr 1)
 .globl intern
intern:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc unchecked-string-intern)
 ldr X11,l0124
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry unchecked-string-intern expr 1)
 .globl l0137
l0137:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X0,[sp, #16]
 mov X4,X28
 mov X3,X4
 mov X2,X4
 ubfx X1,X0,#0,#56
 ldr X1,[X1]
 sbfx X1,X1,#0,#56
 ubfx X0,X0,#0,#56
 str X0,[sp, #24]
 str X1,[sp, #32]
 str X2,[sp, #40]
 str X3,[sp, #48]
 str X4,[sp, #56]
 cbnz X1,l0138
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 and X0,X0,#255
 mov X11,#254
 bfi X0,X11,#56,#8
 b l0139
l0138:
 ldr X0,[sp, #16]
// (idloc hash-into-table)
 ldr X11,l0125
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X1,X0
 str X1,[sp, #40]
// ($fluid hashtable)
 ldr X11,l0126
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 mov X1,X0
 ldr X11,l0127
 cmp X0,X11
 b.lt l0140
 mov X0,X28
 b l0141
l0140:
 ldr X0,l0128
l0141:
 cmp X0,X28
 b.eq l0142
 ldr X0,l0128
 cmp X1,#0
 b.gt l0142
 add X0,X0,#140
l0142:
 cmp X0,X28
 b.eq l0143
 ldr X1,[sp, #40]
// ($fluid hashtable)
 ldr X11,l0126
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 mov X11,#254
 bfi X0,X11,#56,#8
 b l0139
l0143:
// ($global show-new-ids)
 ldr X11,l0129
 ldr X11,[X24, X11, lsl #3]
 cmp X0,X11
 b.eq l0144
 adr X0,l0130
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc console-print-string)
 ldr X11,l0131
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc console-print-string)
 ldr X11,l0131
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11,l0132
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0144:
// (idloc gtid)
 ldr X11,l0133
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 mov X2,X0
 ldr X1,[sp, #40]
// ($fluid hashtable)
 ldr X11,l0126
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X0,[sp, #32]
// (idloc gtconststr)
 ldr X11,l0134
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #48]
 ldr X1,[sp, #24]
// (idloc copystringtofrom)
 ldr X11,l0135
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #48]
 mov X11,#4
 bfi X1,X11,#56,#8
 ldr X0,[sp, #56]
 ldp X29,X30,[sp], #64
// (idloc initialize-new-id)
 ldr X11,l0136
 ldr X10,[X23, X11, lsl #3]
 br X10
l0139:
 ldp X29,X30,[sp], #64
 ret
 .quad 1
// (*entry hash-into-table expr 1)
 .globl l0153
l0153:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc hash-function)
 ldr X11,l0145
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 str X0,[sp, #32]
 movn X9,#0
 str X9,[sp, #40]
l0154:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 ldr X11,l0146
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 cbnz X0,l0155
 ldr X11,[sp, #40]
 cmn X11,#1
 b.eq l0156
 ldr X0,[sp, #40]
 b l0157
l0156:
 ldr X0,[sp, #32]
l0157:
 b l0158
l0155:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 ldr X11,l0146
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 ldr X11,l0147
 cmp X0,X11
 b.ne l0159
 ldr X11,[sp, #40]
 cmn X11,#1
 b.ne l0160
 ldr X9,[sp, #32]
 str X9,[sp, #40]
 b l0160
l0159:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 ldr X11,l0146
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 ldr X1,[sp, #16]
 lsl X0,X0,#3
// ($global symnam)
 ldr X11,l0148
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
// (idloc unchecked-string-equal)
 ldr X11,l0149
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0160
 ldr X0,[sp, #32]
 b l0158
l0160:
 ldr X9,[sp, #32]
 ldr X10,l0150
 cmp X9,X10
 b.ne l0161
 mov X0,#0
 b l0162
l0161:
 mov X0,#1
 ldr X13,[sp, #32]
 add X0,X0,X13
l0162:
 str X0,[sp, #32]
 ldr X11,[sp, #24]
 cmp X0,X11
 b.ne l0154
 adr X0,l0151
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc kernel-fatal-error)
 ldr X11,l0152
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0154
l0158:
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 2
// (*entry initialize-new-id expr 2)
 .globl l0167
l0167:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X0,[sp, #16]
 mov X11,#254
 bfi X0,X11,#56,#8
 str X0,[sp, #24]
 ldr X2,[sp, #16]
 lsl X2,X2,#3
// ($global symnam)
 ldr X11,l0163
 ldr X13,[X24, X11, lsl #3]
 add X2,X2,X13
 str X1,[X2]
 ldr X3,[sp, #16]
 lsl X3,X3,#3
// ($global symprp)
 ldr X11,l0164
 ldr X13,[X24, X11, lsl #3]
 add X3,X3,X13
 mov X4,X28
 str X4,[X3]
 ldr X0,[sp, #16]
 lsl X0,X0,#3
// ($global symget)
 ldr X11,l0165
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 str X4,[X0]
 ldr X0,[sp, #16]
 lsl X0,X0,#3
 add X0,X0,X24
 ldr X1,[sp, #16]
 mov X11,#253
 bfi X1,X11,#56,#8
 str X1,[X0]
 ldr X0,[sp, #16]
// (idloc plantunbound)
 ldr X11,l0166
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #24]
 ldp X29,X30,[sp], #32
 ret
 nop
 .quad 1
// (*entry hash-function expr 1)
 .globl l0171
l0171:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 ubfx X0,X0,#0,#56
 str X0,[sp, #24]
 ldr X0,[X0]
 sbfx X0,X0,#0,#56
 str X0,[sp, #16]
 mov X0,#0
 str X0,[sp, #32]
 ldr X11,[sp, #16]
 cmp X11,#20
 b.le l0172
 mov X9,#20
 str X9,[sp, #16]
l0172:
 ldr X1,[sp, #16]
 mov X0,#0
 mov X4,X0
 mov X3,X1
l0173:
 cmp X4,X3
 b.gt l0174
 mov X1,X4
 mov X0,#8
 ldr X13,[sp, #24]
 add X0,X0,X13
 ldrsb X0,[X0, X1]
 mov X2,#56
 subs X2,X2,X1
 b.ge l0168
 neg X10,X2
 lsr X0,X0,X10
 b l0169
l0168:
 lsl X0,X0,X2
l0169:
 ldr X12,[sp, #32]
 eor X0,X0,X12
 str X0,[sp, #32]
 add X4,X4,#1
 b l0173
l0174:
 ldr X1,l0170
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 udiv X9,X0,X1
 msub X0,X9,X1,X0
 ret
 .quad 1
// (*entry faslin expr 1)
 .globl faslin
faslin:
 stp X29,X30,[sp, #-112]!
 mov X29,sp
 str X28,[sp, #88]
 str X28,[sp, #48]
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X28,[sp, #56]
 str X28,[sp, #24]
 str X28,[sp, #72]
 str X28,[sp, #80]
 str X28,[sp, #104]
 str X28,[sp, #32]
 str X28,[sp, #64]
 str X28,[sp, #96]
// (idloc binaryopenread)
 ldr X11,l0175
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
// (idloc binaryread)
 ldr X11,l0176
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #48]
 mov X1,#65535
 and X1,X1,X0
 cmp X1,#399
 b.eq l0191
 ldr X0,[sp, #40]
// (idloc binaryclose)
 ldr X11,l0177
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc faslin-bad-file)
 ldr X11,l0178
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0192
l0191:
 ldr X0,[sp, #48]
 lsr X0,X0,#16
 str X0,[sp, #48]
 ldr X0,[sp, #40]
// (idloc binaryread)
 ldr X11,l0176
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc read-id-table)
 ldr X11,l0179
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X0,[sp, #24]
// (idloc gtstaticlisp)
 ldr X11,l0180
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #24]
 mov X1,#0
 add X1,X1,X0
 ldr X0,[sp, #40]
// (idloc binaryreadblock)
 ldr X11,l0181
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryread)
 ldr X11,l0176
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #72]
// (idloc gtbps)
 ldr X11,l0182
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #80]
 mov X0,#0
// (idloc gtbps)
 ldr X11,l0182
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #96]
 ldr X0,[sp, #40]
// (idloc binaryread)
 ldr X11,l0176
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #80]
 add X1,X1,X0
 str X1,[sp, #104]
 ldr X0,[sp, #80]
// (idloc bpsaddr-to-bpsaddr-rw)
 ldr X11,l0183
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #72]
 mov X1,#0
 add X1,X1,X0
 ldr X0,[sp, #40]
// (idloc binaryreadblock)
 ldr X11,l0181
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryread)
 ldr X11,l0176
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
// (idloc gtwrds)
 ldr X11,l0184
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X1,X0
 mov X11,#7
 bfi X1,X11,#56,#8
 str X1,[sp, #64]
 ldr X2,[sp, #32]
 ubfx X1,X1,#0,#56
 add X1,X1,#8
 ldr X0,[sp, #40]
// (idloc binaryreadblock)
 ldr X11,l0181
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryclose)
 ldr X11,l0177
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#1
 ldr X12,[sp, #48]
 and X0,X0,X12
 cmp X0,#1
 b.ne l0193
 ldr X3,[sp, #56]
 ldr X2,[sp, #64]
 ldr X1,[sp, #72]
 ldr X0,[sp, #80]
// (idloc do-relocation-new)
 ldr X11,l0185
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0194
l0193:
 ldr X3,[sp, #56]
 ldr X2,[sp, #64]
 ldr X1,[sp, #72]
 ldr X0,[sp, #80]
// (idloc do-relocation)
 ldr X11,l0186
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0194:
 ldr X1,[sp, #72]
 lsl X1,X1,#3
 ldr X13,[sp, #80]
 add X1,X1,X13
 ldr X0,[sp, #80]
// (idloc clear_cache)
 ldr X11,l0187
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid code-base-hack)
 ldr X11,l0188
 ldr X0,[X24, X11, lsl #3]
 str X0,[sp, #88]
 ldr X9,[sp, #80]
// ($fluid code-base-hack)
 ldr X11,l0188
 str X9,[X24, X11, lsl #3]
 ldr X0,[sp, #104]
// (idloc addressapply0)
 ldr X11,l0189
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #88]
// ($fluid code-base-hack)
 ldr X11,l0188
 str X9,[X24, X11, lsl #3]
 ldr X1,[sp, #96]
 ldr X0,[sp, #104]
// (idloc delbps)
 ldr X11,l0190
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0192:
 mov X0,X28
 ldp X29,X30,[sp], #112
 ret
 .quad 2
// (*entry delbps expr 2)
 .globl delbps
delbps:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 4
// (*entry do-relocation expr 4)
 .globl l0199
l0199:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #48]
 str X0,[sp, #40]
 str X2,[sp, #24]
 str X3,[sp, #32]
 mov X0,X1
 lsl X0,X0,#3
 movn X1,#0
 add X1,X1,X0
 mov X0,#0
 str X0,[sp, #56]
 str X1,[sp, #16]
l0200:
 ldr X9,[sp, #56]
 ldr X10,[sp, #16]
 cmp X9,X10
 b.le l0201
 mov X0,X28
 b l0202
l0201:
 ldr X1,[sp, #56]
 ldr X0,[sp, #24]
 mov X11,#1
 bfi X0,X11,#56,#8
 add X0,X0,#4
// (idloc bittable)
 ldr X11,l0195
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #40]
 ldr X13,[sp, #56]
 add X1,X1,X13
 str X1,[sp, #48]
 cmp X0,#1
 b.eq l0203
 cmp X0,#2
 b.eq l0204
 cmp X0,#3
 b.eq l0205
 b l0206
l0203:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-word)
 ldr X11,l0196
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0206
l0205:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-inf)
 ldr X11,l0197
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0206
l0204:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-right-half)
 ldr X11,l0198
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0206:
 ldr X12,[sp, #56]
 add X12,X12,#1
 str X12,[sp, #56]
 b l0200
l0202:
 ldp X29,X30,[sp], #64
 ret
 .quad 4
// (*entry do-relocation-new expr 4)
 .globl l0210
l0210:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #32]
 str X0,[sp, #48]
 str X2,[sp, #16]
 str X3,[sp, #40]
 mov X2,X28
 mov X1,X0
 mov X0,#0
 str X0,[sp, #24]
 str X1,[sp, #56]
 ldr X4,[sp, #16]
 ubfx X4,X4,#0,#56
 add X4,X4,#8
 str X4,[sp, #16]
l0211:
 ldr X1,[sp, #24]
 ldr X0,[sp, #16]
 ldrsb X0,[X0, X1]
 and X0,X0,#255
 str X0,[sp, #32]
 cbnz X0,l0212
 mov X0,X28
 b l0213
l0212:
 ldr X12,[sp, #24]
 add X12,X12,#1
 str X12,[sp, #24]
 mov X0,#63
 ldr X12,[sp, #32]
 and X0,X0,X12
 ldr X13,[sp, #56]
 add X0,X0,X13
 str X0,[sp, #56]
 ldr X1,[sp, #32]
 lsr X1,X1,#6
 str X1,[sp, #32]
 mov X0,X1
 cmp X0,#1
 b.eq l0214
 cmp X0,#2
 b.eq l0215
 cmp X0,#3
 b.eq l0216
 b l0211
l0214:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-word)
 ldr X11,l0207
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0211
l0216:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-inf)
 ldr X11,l0208
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0211
l0215:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-right-half)
 ldr X11,l0209
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0211
l0213:
 ldp X29,X30,[sp], #64
 ret
 .quad 3
// (*entry relocate-word expr 3)
 .globl l0219
l0219:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #56]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
 ldr X11,[X0]
 ubfx X1,X11,#0,#62
 ldr X11,[X0]
 ubfx X0,X11,#62,#2
 str X0,[sp, #40]
 str X1,[sp, #48]
 ldr X0,[sp, #16]
// (idloc bpsaddr-to-bpsaddr-rw)
 ldr X11,l0217
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X3,[sp, #32]
 ldr X2,[sp, #24]
 ldr X1,[sp, #48]
 ldr X0,[sp, #40]
// (idloc compute-relocation)
 ldr X11,l0218
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X10,[sp, #56]
 str X0,[X10]
 ldp X29,X30,[sp], #64
 ret
 .quad 3
// (*entry relocate-inf expr 3)
 .globl l0222
l0222:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X0,[sp, #24]
 str X1,[sp, #16]
 ldr X11,[X0]
 ubfx X1,X11,#0,#22
 ldr X11,[X0]
 ubfx X0,X11,#54,#2
 mov X3,X2
 ldr X2,[sp, #16]
// (idloc compute-relocation)
 ldr X11,l0220
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X0,[sp, #24]
// (idloc bpsaddr-to-bpsaddr-rw)
 ldr X11,l0221
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X12,[X0]
 ldr X9,[sp, #32]
 bfi X12,X9,#0,#56
 str X12,[X0]
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 3
// (*entry relocate-right-half expr 3)
 .globl l0225
l0225:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X0,[sp, #24]
 str X1,[sp, #16]
 ldr X11,[X0]
 ubfx X1,X11,#48,#14
 ldr X11,[X0]
 ubfx X0,X11,#62,#2
 mov X3,X2
 ldr X2,[sp, #16]
// (idloc compute-relocation)
 ldr X11,l0223
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X0,[sp, #24]
// (idloc bpsaddr-to-bpsaddr-rw)
 ldr X11,l0224
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X12,[X0]
 ldr X9,[sp, #32]
 bfi X12,X9,#48,#16
 str X12,[X0]
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 4
// (*entry compute-relocation expr 4)
 .globl l0228
l0228:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X1,[sp, #16]
 cbnz X0,l0229
 mov X0,X2
 add X0,X0,X1
 b l0230
l0229:
 cmp X0,#2
 b.ne l0231
 mov X11,#65510
 cmp X1,X11
 b.lt l0232
 movn X0,#65518
 add X0,X0,X1
 lsl X0,X0,#3
// ($fluid argumentblock)
 ldr X11,l0226
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 b l0230
l0232:
 cmp X1,#2048
 b.lt l0233
 mov X1,X3
 ldr X0,[sp, #16]
// (idloc local-to-global-id)
 ldr X11,l0227
 ldr X10,[X23, X11, lsl #3]
 blr X10
 lsl X0,X0,#3
 add X0,X0,X24
 b l0230
l0233:
 mov X0,X1
 lsl X0,X0,#3
 add X0,X0,X24
 b l0230
l0231:
 cmp X0,#3
 b.ne l0234
 cmp X1,#2048
 b.lt l0235
 mov X1,X3
 ldr X0,[sp, #16]
// (idloc local-to-global-id)
 ldr X11,l0227
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #16]
l0235:
 ldr X0,[sp, #16]
 lsl X0,X0,#3
 add X0,X0,X23
 b l0230
l0234:
 cmp X0,#1
 b.ne l0236
 cmp X1,#2048
 b.lt l0237
 mov X1,X3
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #32
// (idloc local-to-global-id)
 ldr X11,l0227
 ldr X10,[X23, X11, lsl #3]
 br X10
l0237:
 mov X0,X1
 b l0230
l0236:
 mov X0,X28
l0230:
 ldp X29,X30,[sp], #32
 ret
 nop
 .quad 2
// (*entry local-to-global-id expr 2)
 .globl l0238
l0238:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 sub X0,X0,#2047
 lsl X0,X0,#3
 ubfx X2,X1,#0,#56
 add X0,X0,X2
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 1
// (*entry read-id-table expr 1)
 .globl l0244
l0244:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #56]
 str X28,[sp, #48]
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc binaryread)
 ldr X11,l0239
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 add X0,X0,#1
// (idloc gtwrds)
 ldr X11,l0240
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X11,#7
 bfi X0,X11,#56,#8
 str X0,[sp, #32]
 ldr X1,[sp, #24]
 mov X0,#0
 str X0,[sp, #40]
 str X1,[sp, #48]
l0245:
 ldr X9,[sp, #40]
 ldr X10,[sp, #48]
 cmp X9,X10
 b.gt l0246
 ldr X0,[sp, #16]
// (idloc binaryread)
 ldr X11,l0239
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid tokenbuffer)
 ldr X11,l0241
 ldr X10,[X24, X11, lsl #3]
 str X0,[X10]
 mov X2,#9
 add X2,X2,X0
 mov X1,X2
 lsr X1,X1,#61
 add X2,X2,X1
 asr X2,X2,#3
 mov X1,#8
// ($fluid tokenbuffer)
 ldr X11,l0241
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 ldr X0,[sp, #16]
// (idloc binaryreadblock)
 ldr X11,l0242
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#0
// ($fluid tokenbuffer)
 ldr X11,l0241
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc faslin-intern)
 ldr X11,l0243
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 mov X0,#1
 ldr X13,[sp, #40]
 add X0,X0,X13
 lsl X0,X0,#3
 ldr X1,[sp, #32]
 ubfx X1,X1,#0,#56
 add X0,X0,X1
 ldr X2,[sp, #56]
 ubfx X2,X2,#0,#56
 str X2,[X0]
 ldr X12,[sp, #40]
 add X12,X12,#1
 str X12,[sp, #40]
 b l0245
l0246:
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #64
 ret
 nop
 .quad 3
// (*entry putentry expr 3)
 .globl putentry
putentry:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($fluid code-base-hack)
 ldr X11,l0247
 ldr X13,[X24, X11, lsl #3]
 add X2,X2,X13
 mov X11,#20
 bfi X2,X11,#56,#8
 ldp X29,X30,[sp], #16
// (idloc putd)
 ldr X11,l0248
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry faslin-bad-file expr 1)
 .globl l0252
l0252:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 adr X0,l0249
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc console-print-string)
 ldr X11,l0250
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #16
// (idloc console-newline)
 ldr X11,l0251
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
l0261:
 str X0,[sp, #16]
 cmp X0,X28
 b.ne l0262
// (idloc gtbps-nil-error)
 ldr X11,l0253
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0262:
 ldr X11,[sp, #16]
 cmp X11,#10
 b.le l0263
 mov X0,#15
// ($global nextbps)
 ldr X11,l0254
 ldr X12,[X24, X11, lsl #3]
 and X0,X0,X12
 cbz X0,l0263
// ($global nextbps)
 ldr X11,l0254
 ldr X1,[X24, X11, lsl #3]
 lsr X1,X1,#4
 lsl X1,X1,#4
 add X1,X1,#16
// ($global nextbps)
 ldr X11,l0254
 str X1,[X24, X11, lsl #3]
l0263:
// ($global nextbps)
 ldr X11,l0254
 ldr X0,[X24, X11, lsl #3]
 ldr X1,[sp, #16]
 lsl X1,X1,#3
// ($global nextbps)
 ldr X11,l0254
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
// ($global nextbps)
 ldr X11,l0254
 str X1,[X24, X11, lsl #3]
// ($global lastbps)
 ldr X11,l0255
 ldr X11,[X24, X11, lsl #3]
 cmp X1,X11
 b.le l0264
// ($global nextbps)
 ldr X11,l0254
 str X0,[X24, X11, lsl #3]
 ldr X0,l0256
// (idloc getd)
 ldr X11,l0257
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0265
 ldr X0,[sp, #16]
// (idloc try-other-bps-spaces)
 ldr X11,l0258
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0265
 ldr X0,[sp, #16]
 b l0261
l0265:
 adr X0,l0259
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #32
// (idloc stderror)
 ldr X11,l0260
 ldr X10,[X23, X11, lsl #3]
 br X10
l0264:
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry gtbps-nil-error expr 1)
 .globl l0268
l0268:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 adr X0,l0266
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #16
// (idloc stderror)
 ldr X11,l0267
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry bpsaddr-to-bpsaddr-rw expr 1)
 .globl l0271
l0271:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global bpsbaserw)
 ldr X11,l0269
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
// ($global bpsbaserx)
 ldr X11,l0270
 ldr X11,[X24, X11, lsl #3]
 sub X0,X0,X11
 ldp X29,X30,[sp], #16
 ret
 .quad 1
// (*entry gtstaticlisp expr 1)
 .globl gtstaticlisp
gtstaticlisp:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
l0280:
 str X0,[sp, #16]
 cmp X0,X28
 b.ne l0281
 adr X0,l0272
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc stderror)
 ldr X11,l0273
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0281:
// ($global nextstaticlisp)
 ldr X11,l0274
 ldr X0,[X24, X11, lsl #3]
 ldr X1,[sp, #16]
 lsl X1,X1,#3
// ($global nextstaticlisp)
 ldr X11,l0274
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
// ($global nextstaticlisp)
 ldr X11,l0274
 str X1,[X24, X11, lsl #3]
// ($global laststaticlisp)
 ldr X11,l0275
 ldr X11,[X24, X11, lsl #3]
 cmp X1,X11
 b.le l0282
// ($global nextstaticlisp)
 ldr X11,l0274
 str X0,[X24, X11, lsl #3]
 ldr X0,l0276
// (idloc getd)
 ldr X11,l0277
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0283
 ldr X0,[sp, #16]
// (idloc try-other-staticlisp-spaces)
 ldr X11,l0278
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0283
 ldr X0,[sp, #16]
 b l0280
l0283:
 adr X0,l0279
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #32
// (idloc stderror)
 ldr X11,l0273
 ldr X10,[X23, X11, lsl #3]
 br X10
l0282:
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 cmp X0,X28
 b.ne l0286
 ldp X29,X30,[sp], #16
// (idloc known-free-space)
 ldr X11,l0284
 ldr X10,[X23, X11, lsl #3]
 br X10
l0286:
 ldp X29,X30,[sp], #16
// (idloc real-gtheap)
 ldr X11,l0285
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry real-gtheap expr 1)
 .globl l0288
l0288:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X2,X0
 mov X0,X21
 mov X1,X2
 lsl X1,X1,#3
 add X1,X1,X21
 mov X21,X1
 cmp X1,X22
 b.lt l0289
 mov X1,X2
 ldp X29,X30,[sp], #16
// (idloc get-heap-trap)
 ldr X11,l0287
 ldr X10,[X23, X11, lsl #3]
 br X10
l0289:
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 2
// (*entry get-heap-trap expr 2)
 .globl l0292
l0292:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 adr X0,l0290
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #16
// (idloc kernel-fatal-error)
 ldr X11,l0291
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 0
// (*entry gtid expr 0)
 .globl gtid
gtid:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global nextsymbol)
 ldr X11,l0293
 ldr X11,[X24, X11, lsl #3]
 cbnz X11,l0298
// (idloc reclaim)
 ldr X11,l0294
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($global nextsymbol)
 ldr X11,l0293
 ldr X11,[X24, X11, lsl #3]
 cbnz X11,l0298
 adr X0,l0295
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc kernel-fatal-error)
 ldr X11,l0296
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0298:
// ($global nextsymbol)
 ldr X11,l0293
 ldr X0,[X24, X11, lsl #3]
 mov X1,X0
 lsl X1,X1,#3
// ($global symnam)
 ldr X11,l0297
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 ldr X9,[X1]
// ($global nextsymbol)
 ldr X11,l0293
 str X9,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 1
// (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
 add X0,X0,#2
// (idloc gtheap)
 ldr X11,l0299
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #16]
 mov X11,#249
 bfi X1,X11,#56,#8
 str X1,[X0]
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X0,[sp, #16]
 add X0,X0,#9
 mov X1,X0
 lsr X1,X1,#61
 add X0,X0,X1
 asr X0,X0,#3
 str X0,[sp, #24]
 add X0,X0,#1
// (idloc gtstaticlisp)
 ldr X11,l0300
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #16]
 str X9,[X0]
 ldr X1,[sp, #24]
 lsl X1,X1,#3
 add X1,X1,X0
 mov X9,#0
 str X9,[X1]
 ldp X29,X30,[sp], #32
 ret
 .quad 3
// (*entry subseq expr 3)
 .globl subseq
subseq:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #56]
 str X28,[sp, #48]
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
 ubfx X11,X0,#56,#8
 cmp X11,#4
 b.eq l0304
 adr X0,l0301
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc kernel-fatal-error)
 ldr X11,l0302
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0304:
 movn X0,#0
 ldr X13,[sp, #32]
 add X0,X0,X13
 ldr X11,[sp, #24]
 sub X0,X0,X11
 str X0,[sp, #40]
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
 str X0,[sp, #48]
 ldr X0,[sp, #40]
// (idloc gtstr)
 ldr X11,l0303
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X1,[sp, #40]
 mov X0,#0
 mov X4,X0
 mov X3,X1
l0305:
 cmp X4,X3
 b.gt l0306
 ldr X1,[sp, #24]
 add X1,X1,X4
 mov X0,#8
 ldr X13,[sp, #48]
 add X0,X0,X13
 ldrsb X0,[X0, X1]
 mov X2,X0
 mov X1,X4
 mov X0,#8
 ldr X13,[sp, #56]
 add X0,X0,X13
 strb W2,[X0, X1]
 add X4,X4,#1
 b l0305
l0306:
 ldr X0,[sp, #56]
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #64
 ret
 .quad 2
// (*entry search-string-for-character expr 2)
 .globl l0307
l0307:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
 mov X4,X1
 ubfx X1,X1,#0,#56
 ldr X1,[X1]
 sbfx X1,X1,#0,#56
 mov X0,#0
 mov X3,X0
 mov X2,X1
l0308:
 cmp X3,X2
 b.le l0309
 mov X0,X28
 b l0310
l0309:
 mov X1,X3
 ubfx X0,X4,#0,#56
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 ldr X11,[sp, #16]
 cmp X11,X0
 b.ne l0311
 mov X0,X1
 b l0310
l0311:
 add X3,X3,#1
 b l0308
l0310:
 ldp X29,X30,[sp], #32
 ret
 .quad 2
// (*entry unchecked-string-equal expr 2)
 .globl l0313
l0313:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 ubfx X0,X0,#0,#56
 str X0,[sp, #16]
 ubfx X1,X1,#0,#56
 str X1,[sp, #24]
 ldr X2,[X0]
 sbfx X2,X2,#0,#56
 mov X4,X2
 ldr X3,[X1]
 sbfx X3,X3,#0,#56
 cmp X2,X3
 b.eq l0314
 mov X0,X28
 b l0315
l0314:
 mov X9,#0
 str X9,[sp, #32]
l0316:
 ldr X11,[sp, #32]
 cmp X11,X4
 b.le l0317
 ldr X0,l0312
 b l0315
l0317:
 ldr X1,[sp, #32]
 mov X0,#8
 ldr X13,[sp, #16]
 add X0,X0,X13
 ldrsb X0,[X0, X1]
 mov X2,X0
 mov X0,#8
 ldr X13,[sp, #24]
 add X0,X0,X13
 ldrsb X0,[X0, X1]
 cmp X2,X0
 b.eq l0318
 mov X0,X28
 b l0315
l0318:
 ldr X12,[sp, #32]
 add X12,X12,#1
 str X12,[sp, #32]
 b l0316
l0315:
 ldp X29,X30,[sp], #48
 ret
 .quad 2
// (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X0,[sp, #40]
 ubfx X2,X0,#0,#56
 str X2,[sp, #24]
 ubfx X3,X1,#0,#56
 str X3,[sp, #32]
 ldr X4,[X3]
 sbfx X4,X4,#0,#56
 str X4,[sp, #16]
 ldr X0,[X2]
 sbfx X0,X0,#0,#56
 cmp X0,X4
 b.ge l0319
 str X0,[sp, #16]
l0319:
 mov X0,#9
 ldr X13,[sp, #16]
 add X0,X0,X13
 mov X1,X0
 lsr X1,X1,#61
 add X0,X0,X1
 asr X0,X0,#3
 sub X0,X0,#1
 str X0,[sp, #16]
 mov X1,X0
 mov X0,#0
 mov X3,X0
 mov X2,X1
l0320:
 cmp X3,X2
 b.gt l0321
 mov X0,#1
 add X0,X0,X3
 lsl X0,X0,#3
 ldr X13,[sp, #24]
 add X0,X0,X13
 mov X1,#1
 add X1,X1,X3
 lsl X1,X1,#3
 ldr X13,[sp, #32]
 add X1,X1,X13
 ldr X9,[X1]
 str X9,[X0]
 add X3,X3,#1
 b l0320
l0321:
 ldr X0,[sp, #40]
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 2
// (*entry cons expr 2)
 .globl cons
cons:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X0,[sp, #16]
 str X1,[sp, #24]
 mov X0,#2
// (idloc gtheap)
 ldr X11,l0322
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #16]
 str X9,[X0]
 ldr X9,[sp, #24]
 str X9,[X0, #8]
 mov X11,#9
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 lsl X0,X0,#3
 add X0,X0,X24
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 2
// (*entry modify expr 2)
 .globl modify
modify:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 lsl X0,X0,#3
 add X0,X0,X24
 str X1,[X0]
 mov X0,X1
 ldp X29,X30,[sp], #16
 ret
 .quad 3
// (*entry put expr 3)
 .globl put
put:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc unchecked-put)
 ldr X11,l0323
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 3
// (*entry unchecked-put expr 3)
 .globl l0328
l0328:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
// (idloc unchecked-prop)
 ldr X11,l0324
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
 mov X1,X0
 ldr X0,[sp, #24]
// (idloc atsoc)
 ldr X11,l0325
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0329
 ubfx X10,X0,#0,#56
 ldr X9,[sp, #32]
 str X9,[X10, #8]
 b l0330
l0329:
 ldr X1,[sp, #32]
 ldr X0,[sp, #24]
 str X0,[X21]
 mov X0,#9
 orr X0,X21,X0, lsl #56
 str X1,[X21, #8]
 add X21,X21,#16
 cmp X21,X22
 b.lt l0331
 stp X0,X1,[sp, #-16]!
// (idloc !%reclaim)
 ldr X11,l0326
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X0,X1,[sp], #16
l0331:
 ldr X1,[sp, #40]
 str X0,[X21]
 mov X0,#9
 orr X0,X21,X0, lsl #56
 str X1,[X21, #8]
 add X21,X21,#16
 cmp X21,X22
 b.lt l0332
 stp X0,X1,[sp, #-16]!
// (idloc !%reclaim)
 ldr X11,l0326
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X0,X1,[sp], #16
l0332:
 mov X1,X0
 ldr X0,[sp, #16]
// (idloc unchecked-setprop)
 ldr X11,l0327
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0330:
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 ret
 .quad 2
// (*entry atsoc expr 2)
 .globl atsoc
atsoc:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
l0333:
 ubfx X11,X1,#56,#8
 cmp X11,#9
 b.eq l0334
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
l0334:
 ubfx X9,X1,#0,#56
 ldr X11,[X9]
 ubfx X11,X11,#56,#8
 cmp X11,#9
 b.ne l0335
 ubfx X10,X1,#0,#56
 ldr X10,[X10]
 ubfx X10,X10,#0,#56
 ldr X11,[X10]
 cmp X0,X11
 b.ne l0335
 ubfx X0,X1,#0,#56
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
l0335:
 ubfx X1,X1,#0,#56
 ldr X1,[X1, #8]
 b l0333
 .quad 2
// (*entry unchecked-setprop expr 2)
 .globl l0337
l0337:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 lsl X0,X0,#3
// ($global symprp)
 ldr X11,l0336
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 str X1,[X0]
 mov X0,X1
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 1
// (*entry unchecked-prop expr 1)
 .globl l0339
l0339:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 lsl X0,X0,#3
// ($global symprp)
 ldr X11,l0338
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
 .quad 3
// (*entry putd expr 3)
 .globl putd
putd:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc code-putd)
 ldr X11,l0340
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 3
// (*entry code-putd expr 3)
 .globl l0347
l0347:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
 ubfx X11,X0,#56,#8
 cmp X11,#254
 b.ne l0348
 ubfx X11,X1,#56,#8
 cmp X11,#254
 b.ne l0348
 ubfx X11,X2,#56,#8
 cmp X11,#20
 b.eq l0349
l0348:
 adr X0,l0341
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc kernel-fatal-error)
 ldr X11,l0342
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0349:
 ldr X1,[sp, #32]
 ubfx X1,X1,#0,#56
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
// (idloc plantcodepointer)
 ldr X11,l0343
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #24]
 ldr X10,l0344
 cmp X9,X10
 b.eq l0350
 ldr X2,[sp, #24]
 ldr X1,l0345
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #48
// (idloc put)
 ldr X11,l0346
 ldr X10,[X23, X11, lsl #3]
 br X10
l0350:
 mov X0,X28
 ldp X29,X30,[sp], #48
 ret
 .quad 1
// (*entry fluid expr 1)
 .globl fluid
fluid:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X0,[sp, #16]
 mov X0,X28
 ldr X9,[sp, #16]
 str X9,[sp, #24]
 mov X11,X9
 ubfx X11,X11,#56,#8
 cmp X11,#9
 b.ne l0352
 ldr X0,[sp, #24]
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 b l0353
l0352:
 mov X0,X28
l0353:
 str X0,[sp, #32]
l0354:
 ldr X11,[sp, #24]
 ubfx X11,X11,#56,#8
 cmp X11,#9
 b.eq l0355
 mov X0,X28
 b l0356
l0355:
 ldr X0,[sp, #32]
// (idloc fluid1)
 ldr X11,l0351
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #24]
 ubfx X0,X0,#0,#56
 ldr X0,[X0, #8]
 str X0,[sp, #24]
 ubfx X11,X0,#56,#8
 cmp X11,#9
 b.ne l0357
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 b l0358
l0357:
 mov X0,X28
l0358:
 str X0,[sp, #32]
 b l0354
l0356:
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 1
// (*entry fluid1 expr 1)
 .globl l0362
l0362:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldr X2,l0359
 ldr X1,l0360
 ldp X29,X30,[sp], #16
// (idloc put)
 ldr X11,l0361
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry stderror expr 1)
 .globl stderror
stderror:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc kernel-fatal-error)
 ldr X11,l0363
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 2
// (*entry *define-constant expr 2)
 .globl l0367
l0367:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X2,X0,#0,#56
 lsl X2,X2,#3
 add X2,X2,X24
 str X1,[X2]
 ldr X2,l0364
 ldr X1,l0365
 ldp X29,X30,[sp], #16
// (idloc put)
 ldr X11,l0366
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldr X9,l0368
 str X9,[X23, X0, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 .quad 0
l0368:
 .quad undefinedfunction
 .quad 2
// (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 str X1,[X23, X0, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 1
// (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldr X9,l0369
 str X9,[X23, X0, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 .quad 0
l0369:
 .quad compiledcallinginterpreted
 .quad 1
// (*entry addressapply0 expr 1)
 .globl l0370
l0370:
 br X0
 nop
 .quad 2
// (*entry bittable expr 2)
 .globl bittable
bittable:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X3,X1
 lsr X1,X1,#2
 ldrsb X0,[X0, X1]
 ubfx X2,X3,#32,#2
 lsl X2,X2,#1
 subs X2,X2,#6
 b.ge l0371
 neg X10,X2
 lsr X0,X0,X10
 b l0372
l0371:
 lsl X0,X0,X2
l0372:
 ubfx X0,X0,#32,#2
 ldp X29,X30,[sp], #16
 ret
 .quad 1
// (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X9,X11
// (idloc undefinedfunction-aux)
 ldr X11,l0373
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry undefinedfunction-aux expr 1)
 .globl l0379
l0379:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X9,[sp, #16]
 adr X0,l0374
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc console-print-string)
 ldr X11,l0375
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid symnam)
 ldr X11,l0376
 ldr X10,[X24, X11, lsl #3]
 ldr X9,[sp, #16]
 ldr X0,[X10, X9, lsl #3]
// (idloc console-print-string)
 ldr X11,l0375
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11,l0377
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#0
// (idloc exit-with-status)
 ldr X11,l0378
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #32
 ret
 .quad 0
// (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 mov X9,X11
 mov X11,#254
 bfi X9,X11,#56,#8
// ($fluid codeform*)
 ldr X11,l0380
 str X9,[X24, X11, lsl #3]
// (idloc compiledcallinginterpretedaux)
 ldr X11,l0381
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry kernel-fatal-error expr 1)
 .globl l0386
l0386:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
 adr X0,l0382
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc console-print-string)
 ldr X11,l0383
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc console-print-string)
 ldr X11,l0383
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11,l0384
 ldr X10,[X23, X11, lsl #3]
 blr X10
 movn X0,#0
 ldp X29,X30,[sp], #32
// (idloc exit-with-status)
 ldr X11,l0385
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 0
// (*entry echooff expr 0)
 .globl l0387
l0387:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl echooff
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry echoon expr 0)
 .globl l0388
l0388:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl echoon
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_charsininputbuffer expr 1)
 .globl l0389
l0389:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_charsininputbuffer
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry flushstdoutputbuffer expr 0)
 .globl l0390
l0390:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl flushstdoutputbuffer
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry external_user_homedir_string expr 0)
 .globl l0391
l0391:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_user_homedir_string
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_anyuser_homedir_string expr 1)
 .globl l0392
l0392:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_anyuser_homedir_string
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry unexec expr 0)
 .globl l0393
l0393:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unexec
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry alterheapsize expr 1)
 .globl l0394
l0394:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl alterheapsize
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry allocatemorebps expr 1)
 .globl l0395
l0395:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl allocatemorebps
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry get_imagefilepath expr 0)
 .globl l0396
l0396:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl get_imagefilepath
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry get_file_status expr 3)
 .globl l0397
l0397:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl get_file_status
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry os_startup_hook expr 2)
 .globl l0398
l0398:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl os_startup_hook
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry os_cleanup_hook expr 0)
 .globl l0399
l0399:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl os_cleanup_hook
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry get_execfilepath expr 0)
 .globl l0400
l0400:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl get_execfilepath
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry clear_cache expr 2)
 .globl l0401
l0401:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl clear_cache
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry wxquotientdouble expr 4)
 .globl l0402
l0402:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl wxquotientdouble
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_alarm expr 1)
 .globl l0403
l0403:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_alarm
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_ualarm expr 2)
 .globl l0404
l0404:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_ualarm
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_time expr 1)
 .globl l0405
l0405:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_time
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry external_timc expr 0)
 .globl l0406
l0406:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_timc
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_stat expr 2)
 .globl l0407
l0407:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_stat
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_mkdir expr 2)
 .globl l0408
l0408:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_mkdir
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_rmdir expr 1)
 .globl l0409
l0409:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_rmdir
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_link expr 2)
 .globl l0410
l0410:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_link
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_unlink expr 1)
 .globl l0411
l0411:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_unlink
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_strlen expr 1)
 .globl l0412
l0412:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_strlen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_getenv expr 1)
 .globl l0413
l0413:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_getenv
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_setenv expr 2)
 .globl l0414
l0414:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_setenv
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_mkfifo expr 2)
 .globl l0415
l0415:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_mkfifo
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry external_flock expr 2)
 .globl l0416
l0416:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_flock
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry external_fcntl expr 3)
 .globl l0417
l0417:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_fcntl
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry external_read expr 3)
 .globl l0418
l0418:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_read
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry external_write expr 3)
 .globl l0419
l0419:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_write
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry external_lseek expr 3)
 .globl l0420
l0420:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_lseek
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry external_open expr 3)
 .globl l0421
l0421:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_open
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_close expr 1)
 .globl l0422
l0422:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_close
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxfloat expr 2)
 .globl l0423
l0423:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxfloat
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry uxfix expr 1)
 .globl l0424
l0424:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxfix
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxassign expr 2)
 .globl l0425
l0425:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxassign
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxplus2 expr 3)
 .globl l0426
l0426:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxplus2
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxdifference expr 3)
 .globl l0427
l0427:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxdifference
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxtimes2 expr 3)
 .globl l0428
l0428:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxtimes2
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxquotient expr 3)
 .globl l0429
l0429:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxquotient
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxminus expr 2)
 .globl l0430
l0430:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxminus
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry uxgreaterp expr 4)
 .globl l0431
l0431:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxgreaterp
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry uxlessp expr 4)
 .globl l0432
l0432:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxlessp
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxwritefloat expr 3)
 .globl l0433
l0433:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxwritefloat
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxdoubletofloat expr 2)
 .globl l0434
l0434:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxdoubletofloat
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxfloattodouble expr 2)
 .globl l0435
l0435:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxfloattodouble
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxsin expr 2)
 .globl l0436
l0436:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxsin
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxcos expr 2)
 .globl l0437
l0437:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxcos
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxtan expr 2)
 .globl l0438
l0438:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxtan
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxasin expr 2)
 .globl l0439
l0439:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxasin
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxacos expr 2)
 .globl l0440
l0440:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxacos
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxatan expr 2)
 .globl l0441
l0441:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxatan
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxsqrt expr 2)
 .globl l0442
l0442:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxsqrt
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxexp expr 2)
 .globl l0443
l0443:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxexp
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxlog expr 2)
 .globl l0444
l0444:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxlog
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxatan2 expr 3)
 .globl l0445
l0445:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxatan2
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxsinh expr 2)
 .globl l0446
l0446:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxsinh
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxcosh expr 2)
 .globl l0447
l0447:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxcosh
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry uxtanh expr 2)
 .globl l0448
l0448:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxtanh
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxhypot expr 3)
 .globl l0449
l0449:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxhypot
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry uxpow expr 3)
 .globl l0450
l0450:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl uxpow
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry external_pwd expr 0)
 .globl l0451
l0451:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_pwd
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry sun3_sigset expr 2)
 .globl l0452
l0452:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl sun3_sigset
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry sun3_sigrelse expr 2)
 .globl l0453
l0453:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl sun3_sigrelse
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry sigrelse expr 2)
 .globl sigrelse
sigrelse:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl sun3_sigrelse
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry mask_signal expr 2)
 .globl l0454
l0454:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl mask_signal
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry unixputc expr 1)
 .globl l0455
l0455:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixputc
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry unixputs expr 1)
 .globl l0456
l0456:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixputs
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry unixputn expr 1)
 .globl l0457
l0457:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixputn
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry unixcleario expr 0)
 .globl l0458
l0458:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixcleario
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry expand_file_name expr 1)
 .globl l0459
l0459:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl expand_file_name
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry unixopen expr 2)
 .globl l0460
l0460:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixopen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry unixcd expr 1)
 .globl l0461
l0461:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixcd
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry ctime expr 1)
 .globl l0462
l0462:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl ctime
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_system expr 1)
 .globl l0463
l0463:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_system
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_fullpath expr 1)
 .globl l0464
l0464:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_fullpath
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry external_exit expr 1)
 .globl l0465
l0465:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl external_exit
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry fopen expr 2)
 .globl l0466
l0466:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fopen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry fclose expr 1)
 .globl l0467
l0467:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fclose
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry fread expr 4)
 .globl l0468
l0468:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fread
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry fputc expr 2)
 .globl l0469
l0469:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fputc
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry fgetc expr 1)
 .globl l0470
l0470:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fgetc
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry fgets expr 3)
 .globl l0471
l0471:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fgets
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry fwrite expr 4)
 .globl l0472
l0472:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fwrite
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry fflush expr 1)
 .globl l0473
l0473:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fflush
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry fseek expr 3)
 .globl l0474
l0474:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fseek
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry clearerr expr 1)
 .globl l0475
l0475:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl clearerr
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry xgetw expr 1)
 .globl l0476
l0476:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl xgetw
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry putw expr 2)
 .globl l0477
l0477:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl putw
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry signal expr 2)
 .globl l0478
l0478:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl signal
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry sleep expr 1)
 .globl l0479
l0479:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl sleep
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry ieee_flags expr 4)
 .globl l0480
l0480:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl ieee_flags
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry setlinebuf expr 1)
 .globl l0481
l0481:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl setlinebuf
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry getpid expr 0)
 .globl l0482
l0482:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl getpid
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry gethostid expr 0)
 .globl l0483
l0483:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl gethostid
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry unixsocketopen expr 2)
 .globl l0484
l0484:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixsocketopen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry getsocket expr 3)
 .globl l0485
l0485:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl getsocket
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry writesocket expr 3)
 .globl l0486
l0486:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl writesocket
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry unixclosesocket expr 1)
 .globl l0487
l0487:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl unixclosesocket
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 0
// (*entry fork expr 0)
 .globl l0488
l0488:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl fork
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry wait expr 1)
 .globl l0489
l0489:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl wait
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry popen expr 2)
 .globl l0490
l0490:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl popen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry pclose expr 1)
 .globl l0491
l0491:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl pclose
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry shmctl expr 3)
 .globl l0492
l0492:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl shmctl
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry shmget expr 3)
 .globl l0493
l0493:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl shmget
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry shmat expr 3)
 .globl l0494
l0494:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl shmat
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry shmdt expr 1)
 .globl l0495
l0495:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl shmdt
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry semctl expr 4)
 .globl l0496
l0496:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl semctl
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry semget expr 3)
 .globl l0497
l0497:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl semget
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 3
// (*entry semop expr 3)
 .globl l0498
l0498:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl semop
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry dlopen expr 2)
 .globl l0499
l0499:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl dlopen
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry dlerror expr 1)
 .globl l0500
l0500:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl dlerror
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 2
// (*entry dlsym expr 2)
 .globl l0501
l0501:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl dlsym
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry dlclose expr 1)
 .globl l0502
l0502:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl dlclose
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 4
// (*entry unix-profile expr 4)
 .globl l0503
l0503:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 stp X29,X30,[sp, #-80]!
 mov X29,sp
 stp X19,X20,[sp, #80]
 stp X21,X22,[sp, #64]
 stp X23,X24,[sp, #48]
 stp X25,X26,[sp, #32]
 stp X27,X28,[sp, #16]
 bl profil
 ldp X27,X28,[sp, #16]
 ldp X25,X26,[sp, #32]
 ldp X23,X24,[sp, #48]
 ldp X21,X22,[sp, #64]
 ldp X19,X20,[sp, #80]
 ldp X29,X30,[sp], #80
 ret
 .quad 1
// (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 ubfx X0,X0,#0,#56
 str X0,[sp, #16]
 ldr X0,l0504
// (idloc getfcodepointer)
 ldr X11,l0505
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X0,X11
 b.le l0510
 mov X0,X28
 b l0511
l0510:
 ldr X0,l0506
l0511:
 cmp X0,X28
 b.eq l0512
 ldr X0,l0507
// (idloc getfcodepointer)
 ldr X11,l0505
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X11,X0
 b.lt l0513
 mov X0,X28
 b l0512
l0513:
 ldr X0,l0506
l0512:
 cmp X0,X28
 b.ne l0514
// ($global bpslowerbound)
 ldr X11,l0508
 ldr X0,[X24, X11, lsl #3]
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X0,X11
 b.le l0515
 mov X0,X28
 b l0516
l0515:
 ldr X0,l0506
l0516:
 cmp X0,X28
 b.eq l0514
// ($global nextbps)
 ldr X11,l0509
 ldr X0,[X24, X11, lsl #3]
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X11,X0
 b.lt l0517
 mov X0,X28
 b l0514
l0517:
 ldr X0,l0506
l0514:
 ldp X29,X30,[sp], #32
 ret
 nop
 .quad 1
// (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
 ret
 .quad 0
// (*entry initcode expr 0)
 .globl initcode
initcode:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
 nop
 .globl symval
 .globl symprp
 .globl symnam
 .globl symfnc
 .globl symget
 .globl staticlisp
 .globl l0005
 .globl l0004
 .globl l0003
 .globl l0002
 .globl l0001
 .globl l0015
 .globl l0014
 .globl l0013
 .globl l0012
 .globl l0011
 .globl l0010
 .globl l0009
 .globl l0008
 .globl l0007
 .globl l0047
 .globl l0046
 .globl l0045
 .globl l0044
 .globl l0043
 .globl l0042
 .globl l0041
 .globl l0040
 .globl l0039
 .globl l0038
 .globl l0037
 .globl l0036
 .globl l0035
 .globl l0034
 .globl l0033
 .globl l0032
 .globl l0031
 .globl l0030
 .globl l0029
 .globl l0028
 .globl l0027
 .globl l0026
 .globl l0025
 .globl l0024
 .globl l0023
 .globl l0022
 .globl l0021
 .globl l0020
 .globl l0019
 .globl l0018
 .globl l0017
 .globl l0068
 .globl l0067
 .globl l0066
 .globl l0065
 .globl l0064
 .globl l0063
 .globl l0062
 .globl l0061
 .globl l0060
 .globl l0059
 .globl l0058
 .globl l0057
 .globl l0056
 .globl l0055
 .globl l0054
 .globl l0053
 .globl l0052
 .globl l0051
 .globl l0050
 .globl l0049
 .globl l0075
 .globl l0074
 .globl l0073
 .globl l0072
 .globl l0071
 .globl l0085
 .globl l0084
 .globl l0082
 .globl l0081
 .globl l0079
 .globl l0078
 .globl l0077
 .globl l0080
 .globl l0083
 .globl l0087
 .globl l0089
 .globl l0091
 .globl l0096
 .globl l0094
 .globl l0093
 .globl l0095
 .globl l0098
 .globl l0099
 .globl l0100
 .globl l0108
 .globl l0107
 .globl l0106
 .globl l0105
 .globl l0104
 .globl l0103
 .globl l0102
 .globl l0101
 .globl l0118
 .globl l0117
 .globl l0116
 .globl l0124
 .globl l0136
 .globl l0135
 .globl l0134
 .globl l0133
 .globl l0132
 .globl l0131
 .globl l0129
 .globl l0128
 .globl l0127
 .globl l0126
 .globl l0125
 .globl l0130
 .globl l0152
 .globl l0150
 .globl l0149
 .globl l0148
 .globl l0147
 .globl l0146
 .globl l0145
 .globl l0151
 .globl l0166
 .globl l0165
 .globl l0164
 .globl l0163
 .globl l0170
 .globl l0190
 .globl l0189
 .globl l0188
 .globl l0187
 .globl l0186
 .globl l0185
 .globl l0184
 .globl l0183
 .globl l0182
 .globl l0181
 .globl l0180
 .globl l0179
 .globl l0178
 .globl l0177
 .globl l0176
 .globl l0175
 .globl l0198
 .globl l0197
 .globl l0196
 .globl l0195
 .globl l0209
 .globl l0208
 .globl l0207
 .globl l0218
 .globl l0217
 .globl l0221
 .globl l0220
 .globl l0224
 .globl l0223
 .globl l0227
 .globl l0226
 .globl l0243
 .globl l0242
 .globl l0241
 .globl l0240
 .globl l0239
 .globl l0248
 .globl l0247
 .globl l0251
 .globl l0250
 .globl l0249
 .globl l0260
 .globl l0258
 .globl l0257
 .globl l0256
 .globl l0255
 .globl l0254
 .globl l0253
 .globl l0259
 .globl l0267
 .globl l0266
 .globl l0270
 .globl l0269
 .globl l0278
 .globl l0277
 .globl l0276
 .globl l0275
 .globl l0274
 .globl l0273
 .globl l0272
 .globl l0279
 .globl l0285
 .globl l0284
 .globl l0287
 .globl l0291
 .globl l0290
 .globl l0297
 .globl l0296
 .globl l0294
 .globl l0293
 .globl l0295
 .globl l0299
 .globl l0300
 .globl l0303
 .globl l0302
 .globl l0301
 .globl l0312
 .globl l0322
 .globl l0323
 .globl l0327
 .globl l0326
 .globl l0325
 .globl l0324
 .globl l0336
 .globl l0338
 .globl l0340
 .globl l0346
 .globl l0345
 .globl l0344
 .globl l0343
 .globl l0342
 .globl l0341
 .globl l0351
 .globl l0361
 .globl l0360
 .globl l0359
 .globl l0363
 .globl l0366
 .globl l0365
 .globl l0364
 .globl l0373
 .globl l0378
 .globl l0377
 .globl l0376
 .globl l0375
 .globl l0374
 .globl l0381
 .globl l0380
 .globl l0385
 .globl l0384
 .globl l0383
 .globl l0382
 .globl l0509
 .globl l0508
 .globl l0507
 .globl l0506
 .globl l0505
 .globl l0504
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
 .globl l0948
 .globl l0949
 .globl l0950
 .globl l0951
 .globl l0952
 .globl l0953
 .globl l0954
 .globl l0955
 .globl l0956
 .globl l0957
 .globl l0958
 .globl l0959
 .globl l0960
 .globl l0961
 .globl l0962
 .globl l0963
 .globl l0964
 .globl l0965
 .globl l0966
 .globl l0967
 .globl l0968
 .globl l0969
 .globl l0970
 .globl l0971
 .globl l0972
 .globl l0973
 .globl l0974
 .globl l0975
 .globl l0976
 .globl l0977
 .globl l0978
 .globl l0979
 .globl l0980
 .globl l0981
 .globl l0982
 .globl l0983
 .globl l0984
 .globl l0985
 .globl l0986
 .globl l0987
 .globl l0988
 .globl l0989
 .globl l0990
 .globl l0991
 .globl l0992
 .globl l0993
 .globl l0994
 .globl l0995
 .globl l0996
 .globl l0997
 .globl l0998
 .globl l0999
 .globl l1000
 .globl l1001
 .globl l1002
 .globl l1003
 .globl l1004
 .globl l1005
 .globl l1006
 .globl l1007
 .globl l1008
 .globl l1009
 .globl l1010
 .globl l1011
 .globl l1012
 .globl l1013
 .globl l1014
 .globl l1015
 .globl l1016
 .globl l1017
 .globl l1018
 .globl l1019
 .globl l1020
 .globl l1021
 .globl l1022
 .globl l1023
 .globl l1024
 .globl l1025
 .globl l1026
 .globl l1027
 .globl l1028
 .globl l1029
 .globl l1030
 .globl l1031
 .globl l1032
 .globl l1033
 .globl l1034
 .globl l1035
 .globl l1036
 .globl l1037
 .globl l1038
 .globl l1039
 .globl l1040
 .globl l1041
 .globl l1042
 .globl endinitstaticlisp
 .globl laststaticlisp
