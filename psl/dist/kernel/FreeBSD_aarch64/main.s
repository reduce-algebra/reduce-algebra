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
 .globl l0001
l0001:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($fluid heaplast)
 movz X11,#268
 str X21,[X24, X11, lsl #3]
// ($fluid heaptrapbound)
 movz X11,#269
 str X22,[X24, X11, lsl #3]
// ($fluid bndstkptr)
 movz X11,#270
 str X25,[X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 movz X11,#271
 str X26,[X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 movz X11,#272
 str X27,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 0
// (*entry init-pointers expr 0)
 .globl l0002
l0002:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global catchstack)
 movz X11,#262
 ldr X9,[X24, X11, lsl #3]
// ($global catchstackptr)
 movz X11,#274
 str X9,[X24, X11, lsl #3]
// ($global bndstk)
 movz X11,#261
 ldr X9,[X24, X11, lsl #3]
// ($global bndstklowerbound)
 movz X11,#271
 str X9,[X24, X11, lsl #3]
 movz X0,#28920
 movk X0,#2,lsl #16
// ($global bndstk)
 movz X11,#261
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
// ($global bndstkupperbound)
 movz X11,#272
 str X0,[X24, X11, lsl #3]
// ($global bndstk)
 movz X11,#261
 ldr X9,[X24, X11, lsl #3]
// ($global bndstkptr)
 movz X11,#270
 str X9,[X24, X11, lsl #3]
// ($global heaplowerbound)
 movz X11,#275
 ldr X0,[X24, X11, lsl #3]
// ($global heap)
 movz X11,#276
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 0
// (*entry init-fluids expr 0)
 .globl l0003
l0003:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
// ($global gcarraylowerbound)
 movz X11,#278
 str X0,[X24, X11, lsl #3]
// ($global gcarrayupperbound)
 movz X11,#279
 str X0,[X24, X11, lsl #3]
// ($global heaplast)
 movz X11,#268
 str X0,[X24, X11, lsl #3]
// ($global oldheaplast)
 movz X11,#280
 str X0,[X24, X11, lsl #3]
// ($global heaptrapbound)
 movz X11,#269
 str X0,[X24, X11, lsl #3]
// ($global oldheaptrapbound)
 movz X11,#281
 str X0,[X24, X11, lsl #3]
// ($global heapupperbound)
 movz X11,#282
 str X0,[X24, X11, lsl #3]
// ($global _infbitlength_)
 movz X11,#283
 str X0,[X24, X11, lsl #3]
// ($global lastbps)
 movz X11,#284
 str X0,[X24, X11, lsl #3]
// ($global bpslowerbound)
 movz X11,#285
 str X0,[X24, X11, lsl #3]
// ($global mainstartinitialize)
 movz X11,#286
 str X0,[X24, X11, lsl #3]
// ($global nextbps)
 movz X11,#287
 str X0,[X24, X11, lsl #3]
// ($global nextbpsw)
 movz X11,#288
 str X0,[X24, X11, lsl #3]
// ($global bpsbaserw)
 movz X11,#289
 str X0,[X24, X11, lsl #3]
// ($global bpsbaserx)
 movz X11,#290
 str X0,[X24, X11, lsl #3]
// ($global bpsoffset)
 movz X11,#291
 str X0,[X24, X11, lsl #3]
// ($global staticlisp)
 movz X11,#292
 str X0,[X24, X11, lsl #3]
// ($global laststaticlisp)
 movz X11,#293
 str X0,[X24, X11, lsl #3]
// ($global nextstaticlisp)
 movz X11,#294
 str X0,[X24, X11, lsl #3]
// ($global oldheapupperbound)
 movz X11,#295
 str X0,[X24, X11, lsl #3]
// ($global oldheaplowerbound)
 movz X11,#296
 str X0,[X24, X11, lsl #3]
// ($global stackupperbound)
 movz X11,#297
 str X0,[X24, X11, lsl #3]
// ($global unixstdin)
 movz X11,#298
 str X0,[X24, X11, lsl #3]
// ($global unixstdout)
 movz X11,#299
 str X0,[X24, X11, lsl #3]
// ($global unixstderr)
 movz X11,#300
 str X0,[X24, X11, lsl #3]
// ($global unixnull)
 movz X11,#301
 str X0,[X24, X11, lsl #3]
// ($global unixeof)
 movz X11,#302
 str X0,[X24, X11, lsl #3]
// ($global unixtty)
 movz X11,#303
 str X0,[X24, X11, lsl #3]
// ($global ***must-be-nil***)
 movz X11,#304
 str X0,[X24, X11, lsl #3]
// ($global ***must-be-nil-too***)
 movz X11,#305
 str X0,[X24, X11, lsl #3]
// ($global *fastcar)
 movz X11,#306
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
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
 movz X11,#308
 str X24,[X24, X11, lsl #3]
// ($global symfnc)
 movz X11,#309
 ldr X23,[X24, X11, lsl #3]
 mov X28,#256
 mov X11,#254
 bfi X28,X11,#56,#8
 mov X9,#56
// (fluid _infbitlength_)
 movz X11,#283
 str X9,[X24, X11, lsl #3]
// (idloc os_startup_hook)
 mov X11,#310
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #16]
// (fluid argc)
 movz X11,#311
 str X9,[X24, X11, lsl #3]
 ldr X9,[sp, #24]
// (fluid argv)
 movz X11,#312
 str X9,[X24, X11, lsl #3]
 ldr X9,[sp, #32]
// (fluid ebxsave*)
 movz X11,#313
 str X9,[X24, X11, lsl #3]
// (idloc init-pointers)
 mov X11,#277
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X3,sp
 lsr X3,X3,#5
// (fluid stacklowerbound)
 movz X11,#314
 str X3,[X24, X11, lsl #3]
// ($global staticlisp)
 movz X11,#292
 ldr X20,[X24, X11, lsl #3]
// ($fluid heaplast)
 movz X11,#268
 ldr X21,[X24, X11, lsl #3]
// ($fluid heaptrapbound)
 movz X11,#269
 ldr X22,[X24, X11, lsl #3]
// ($fluid bndstkptr)
 movz X11,#270
 ldr X25,[X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 movz X11,#271
 ldr X26,[X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 movz X11,#272
 ldr X27,[X24, X11, lsl #3]
// (idloc init-gcarray)
 mov X11,#315
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc pre-main)
 mov X11,#316
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0004:
 mov X0,#0
 ldp X29,X30,[sp], #48
// (idloc exit-with-status)
 mov X11,#317
 ldr X10,[X23, X11, lsl #3]
 br X10
// (*entry exit-with-status expr 1)
 .globl l0005
l0005:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc os_cleanup_hook)
 mov X11,#318
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #32
// (idloc external_exit)
 mov X11,#319
 ldr X10,[X23, X11, lsl #3]
 br X10
 ldp X29,X30,[sp], #16
 ret
 nop
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
 mov X11,#321
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X1,[sp, #16]
 ldr X0,[sp, #24]
// (idloc stringopen)
 mov X11,#321
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
 ldr X0,[sp, #32]
// (idloc rds)
 mov X11,#322
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc wrs)
 mov X11,#323
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc begin1)
 mov X11,#324
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
// (idloc rds)
 mov X11,#322
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
// (idloc wrs)
 mov X11,#323
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #32]
// (idloc close)
 mov X11,#325
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc close)
 mov X11,#325
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,X28
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 0
// (*entry init-gcarray expr 0)
 .globl l0006
l0006:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 0
// (*entry pre-main expr 0)
 .globl l0011
l0011:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// (idloc unixcleario)
 mov X11,#327
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc initialize-symbol-table)
 mov X11,#328
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc initcode)
 mov X11,#329
 ldr X10,[X23, X11, lsl #3]
 blr X10
 movz X11,#1
 ldr X0,[X20, X11, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 mov X11,#331
 ldr X10,[X23, X11, lsl #3]
 blr X10
 movz X11,#0
 ldr X0,[X20, X11, lsl #3]
// (idloc faslin)
 mov X11,#332
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #16
// (idloc loader-main)
 mov X11,#333
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry console-print-string expr 1)
 .globl l0012
l0012:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 add X0,X0,#8
 ldp X29,X30,[sp], #16
// (idloc unixputs)
 mov X11,#334
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry console-print-number expr 1)
 .globl l0013
l0013:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc unixputn)
 mov X11,#335
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 0
// (*entry console-newline expr 0)
 .globl l0014
l0014:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X0,#10
 ldp X29,X30,[sp], #16
// (idloc unixputc)
 mov X11,#337
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 movz X11,#10
 ldr X1,[X20, X11, lsl #3]
 ubfx X1,X1,#0,#56
 add X1,X1,#8
 ubfx X0,X0,#0,#56
 add X0,X0,#8
// (idloc unixopen)
 mov X11,#338
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cbnz X0,l0019
 movz X11,#9
 ldr X0,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #16
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 br X10
l0019:
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
 mov X11,#341
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
 mov X11,#343
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
 mov X11,#345
 ldr X10,[X23, X11, lsl #3]
 br X10
l0020:
// (*entry initialize-symbol-table expr 0)
 .globl l0021
l0021:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X28,[sp, #16]
 movz X1,#37856
 movk X1,#4,lsl #16
// ($global nextsymbol)
 movz X11,#347
 ldr X0,[X24, X11, lsl #3]
 mov X3,X0
 mov X2,X1
l0022:
 cmp X3,X2
 b.gt l0023
 mov X0,X3
 lsl X0,X0,#3
// ($global symnam)
 movz X11,#348
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 mov X1,#1
 add X1,X1,X3
 str X1,[X0]
 add X3,X3,#1
 b l0022
l0023:
// ($global symnam)
 movz X11,#348
 ldr X10,[X24, X11, lsl #3]
 movz X13,#40704
 movk X13,#36,lsl #16
 add X10,X10,X13
 mov X9,#0
 str X9,[X10]
 movz X1,#25
 movk X1,#6,lsl #16
 mov X0,#0
 str X0,[sp, #16]
 str X1,[sp, #24]
l0024:
 ldr X9,[sp, #16]
 ldr X10,[sp, #24]
 cmp X9,X10
 b.gt l0025
 mov X2,#0
 ldr X1,[sp, #16]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X12,[sp, #16]
 add X12,X12,#1
 str X12,[sp, #16]
 b l0024
l0025:
// ($global symnam)
 movz X11,#348
 ldr X0,[X24, X11, lsl #3]
 ldr X0,[X0, #2048]
// (idloc hash-into-table)
 mov X11,#349
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X2,#256
 mov X1,X0
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 movn X1,#0
// ($global nextsymbol)
 movz X11,#347
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 mov X0,#256
 str X0,[sp, #16]
 str X1,[sp, #24]
l0026:
 ldr X9,[sp, #16]
 ldr X10,[sp, #24]
 cmp X9,X10
 b.gt l0027
 ldr X0,[sp, #16]
 lsl X0,X0,#3
// ($global symnam)
 movz X11,#348
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
// (idloc hash-into-table)
 mov X11,#349
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #16]
 mov X1,X0
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X12,[sp, #16]
 add X12,X12,#1
 str X12,[sp, #16]
 b l0026
l0027:
 mov X0,X28
// ($global show-new-ids)
 movz X11,#350
 str X0,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry faslin-intern expr 1)
 .globl l0028
l0028:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
 mov X1,X0
 mov X0,#0
// (idloc search-string-for-character)
 mov X11,#351
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 cmp X0,X28
 b.ne l0029
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #48
// (idloc intern)
 mov X11,#352
 ldr X10,[X23, X11, lsl #3]
 br X10
l0029:
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 sbfx X0,X0,#0,#56
 str X0,[sp, #32]
 ldr X11,[sp, #24]
 cmp X0,X11
 b.le l0030
 mov X1,#1
 ldr X13,[sp, #24]
 add X1,X1,X13
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 cbnz X0,l0030
 ldr X12,[sp, #24]
 add X12,X12,#1
 str X12,[sp, #24]
l0030:
 ldr X9,[sp, #24]
 ldr X10,[sp, #32]
 cmp X9,X10
 b.lt l0031
 ldr X0,[sp, #16]
 b l0032
l0031:
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
 mov X11,#353
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0032:
 ldp X29,X30,[sp], #48
// (idloc intern)
 mov X11,#352
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
 mov X11,#355
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry unchecked-string-intern expr 1)
 .globl l0036
l0036:
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
 cbnz X1,l0037
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 and X0,X0,#255
 mov X11,#254
 bfi X0,X11,#56,#8
 b l0038
l0037:
 ldr X0,[sp, #16]
// (idloc hash-into-table)
 mov X11,#349
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X1,X0
 str X1,[sp, #40]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 mov X1,X0
 movz X11,#65535
 movk X11,#65535,lsl #16
 cmp X0,X11
 b.lt l0039
 mov X0,X28
 b l0040
l0039:
 movz X11,#20
 ldr X0,[X20, X11, lsl #3]
l0040:
 cmp X0,X28
 b.eq l0041
 movz X11,#20
 ldr X0,[X20, X11, lsl #3]
 cmp X1,#0
 b.gt l0041
 add X0,X0,#140
l0041:
 cmp X0,X28
 b.eq l0042
 ldr X1,[sp, #40]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 mov X11,#254
 bfi X0,X11,#56,#8
 b l0038
l0042:
// ($global show-new-ids)
 movz X11,#350
 ldr X11,[X24, X11, lsl #3]
 cmp X0,X11
 b.eq l0043
 movz X11,#19
 ldr X0,[X20, X11, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 mov X11,#331
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0043:
// (idloc gtid)
 mov X11,#356
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 mov X2,X0
 ldr X1,[sp, #40]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 str W2,[X0, X1, lsl #2]
 ldr X0,[sp, #32]
// (idloc gtconststr)
 mov X11,#357
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #48]
 ldr X1,[sp, #24]
// (idloc copystringtofrom)
 mov X11,#358
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #48]
 mov X11,#4
 bfi X1,X11,#56,#8
 ldr X0,[sp, #56]
 ldp X29,X30,[sp], #64
// (idloc initialize-new-id)
 mov X11,#359
 ldr X10,[X23, X11, lsl #3]
 br X10
l0038:
 ldp X29,X30,[sp], #64
 ret
 nop
 .quad 1
// (*entry hash-into-table expr 1)
 .globl l0046
l0046:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc hash-function)
 mov X11,#360
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 str X0,[sp, #32]
 movn X9,#0
 str X9,[sp, #40]
l0047:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 cbnz X0,l0048
 ldr X11,[sp, #40]
 cmn X11,#1
 b.eq l0049
 ldr X0,[sp, #40]
 b l0050
l0049:
 ldr X0,[sp, #32]
l0050:
 b l0051
l0048:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 movz X11,#65535
 movk X11,#65535,lsl #16
 cmp X0,X11
 b.ne l0052
 ldr X11,[sp, #40]
 cmn X11,#1
 b.ne l0053
 ldr X9,[sp, #32]
 str X9,[sp, #40]
 b l0053
l0052:
 ldr X1,[sp, #32]
// ($fluid hashtable)
 movz X11,#263
 ldr X0,[X24, X11, lsl #3]
 ldr W0,[X0, X1, lsl #2]
 ldr X1,[sp, #16]
 lsl X0,X0,#3
// ($global symnam)
 movz X11,#348
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
// (idloc unchecked-string-equal)
 mov X11,#361
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0053
 ldr X0,[sp, #32]
 b l0051
l0053:
 ldr X9,[sp, #32]
 movz X10,#25
 movk X10,#6,lsl #16
 cmp X9,X10
 b.ne l0054
 mov X0,#0
 b l0055
l0054:
 mov X0,#1
 ldr X13,[sp, #32]
 add X0,X0,X13
l0055:
 str X0,[sp, #32]
 ldr X11,[sp, #24]
 cmp X0,X11
 b.ne l0047
 movz X11,#24
 ldr X0,[X20, X11, lsl #3]
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0047
l0051:
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 2
// (*entry initialize-new-id expr 2)
 .globl l0056
l0056:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X0,[sp, #16]
 mov X11,#254
 bfi X0,X11,#56,#8
 str X0,[sp, #24]
 ldr X2,[sp, #16]
 lsl X2,X2,#3
// ($global symnam)
 movz X11,#348
 ldr X13,[X24, X11, lsl #3]
 add X2,X2,X13
 str X1,[X2]
 ldr X3,[sp, #16]
 lsl X3,X3,#3
// ($global symprp)
 movz X11,#362
 ldr X13,[X24, X11, lsl #3]
 add X3,X3,X13
 mov X4,X28
 str X4,[X3]
 ldr X0,[sp, #16]
 lsl X0,X0,#3
// ($global symget)
 movz X11,#363
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
 mov X11,#364
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #24]
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry hash-function expr 1)
 .globl l0059
l0059:
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
 b.le l0060
 mov X9,#20
 str X9,[sp, #16]
l0060:
 ldr X1,[sp, #16]
 mov X0,#0
 mov X4,X0
 mov X3,X1
l0061:
 cmp X4,X3
 b.gt l0062
 mov X1,X4
 mov X0,#8
 ldr X13,[sp, #24]
 add X0,X0,X13
 ldrsb X0,[X0, X1]
 mov X2,#56
 subs X2,X2,X1
 b.ge l0057
 neg X10,X2
 lsr X0,X0,X10
 b l0058
l0057:
 lsl X0,X0,X2
l0058:
 ldr X12,[sp, #32]
 eor X0,X0,X12
 str X0,[sp, #32]
 add X4,X4,#1
 b l0061
l0062:
 movz X1,#25
 movk X1,#6,lsl #16
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 udiv X9,X0,X1
 msub X0,X9,X1,X0
 ret
 nop
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
 mov X11,#340
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #48]
 mov X1,#65535
 and X1,X1,X0
 cmp X1,#399
 b.eq l0063
 ldr X0,[sp, #40]
// (idloc binaryclose)
 mov X11,#346
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc faslin-bad-file)
 mov X11,#365
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0064
l0063:
 ldr X0,[sp, #48]
 lsr X0,X0,#16
 str X0,[sp, #48]
 ldr X0,[sp, #40]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc read-id-table)
 mov X11,#366
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X0,[sp, #24]
// (idloc gtstaticlisp)
 mov X11,#367
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #24]
 mov X1,#0
 add X1,X1,X0
 ldr X0,[sp, #40]
// (idloc binaryreadblock)
 mov X11,#344
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #72]
// (idloc gtbps)
 mov X11,#368
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #80]
 mov X0,#0
// (idloc gtbps)
 mov X11,#368
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #96]
 ldr X0,[sp, #40]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #80]
 add X1,X1,X0
 str X1,[sp, #104]
 ldr X0,[sp, #80]
// (idloc bpsaddr-to-bpsaddr-rw)
 mov X11,#369
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X2,[sp, #72]
 mov X1,#0
 add X1,X1,X0
 ldr X0,[sp, #40]
// (idloc binaryreadblock)
 mov X11,#344
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
// (idloc gtwrds)
 mov X11,#370
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
 mov X11,#344
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #40]
// (idloc binaryclose)
 mov X11,#346
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#1
 ldr X12,[sp, #48]
 and X0,X0,X12
 cmp X0,#1
 b.ne l0065
 ldr X3,[sp, #56]
 ldr X2,[sp, #64]
 ldr X1,[sp, #72]
 ldr X0,[sp, #80]
// (idloc do-relocation-new)
 mov X11,#371
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0066
l0065:
 ldr X3,[sp, #56]
 ldr X2,[sp, #64]
 ldr X1,[sp, #72]
 ldr X0,[sp, #80]
// (idloc do-relocation)
 mov X11,#372
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0066:
 ldr X1,[sp, #72]
 lsl X1,X1,#3
 ldr X13,[sp, #80]
 add X1,X1,X13
 ldr X0,[sp, #80]
// (idloc clear_cache)
 mov X11,#373
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid code-base-hack)
 movz X11,#374
 ldr X0,[X24, X11, lsl #3]
 str X0,[sp, #88]
 ldr X9,[sp, #80]
// ($fluid code-base-hack)
 movz X11,#374
 str X9,[X24, X11, lsl #3]
 ldr X0,[sp, #104]
// (idloc addressapply0)
 mov X11,#375
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #88]
// ($fluid code-base-hack)
 movz X11,#374
 str X9,[X24, X11, lsl #3]
 ldr X1,[sp, #96]
 ldr X0,[sp, #104]
// (idloc delbps)
 mov X11,#376
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0064:
 mov X0,X28
 ldp X29,X30,[sp], #112
 ret
 nop
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
 .globl l0067
l0067:
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
l0068:
 ldr X9,[sp, #56]
 ldr X10,[sp, #16]
 cmp X9,X10
 b.le l0069
 mov X0,X28
 b l0070
l0069:
 ldr X1,[sp, #56]
 ldr X0,[sp, #24]
 mov X11,#1
 bfi X0,X11,#56,#8
 add X0,X0,#4
// (idloc bittable)
 mov X11,#377
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X1,[sp, #40]
 ldr X13,[sp, #56]
 add X1,X1,X13
 str X1,[sp, #48]
 cmp X0,#1
 b.eq l0071
 cmp X0,#2
 b.eq l0072
 cmp X0,#3
 b.eq l0073
 b l0074
l0071:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-word)
 mov X11,#378
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0074
l0073:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-inf)
 mov X11,#379
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0074
l0072:
 ldr X2,[sp, #32]
 ldr X1,[sp, #40]
 ldr X0,[sp, #48]
// (idloc relocate-right-half)
 mov X11,#380
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0074:
 ldr X12,[sp, #56]
 add X12,X12,#1
 str X12,[sp, #56]
 b l0068
l0070:
 ldp X29,X30,[sp], #64
 ret
 .quad 4
// (*entry do-relocation-new expr 4)
 .globl l0075
l0075:
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
l0076:
 ldr X1,[sp, #24]
 ldr X0,[sp, #16]
 ldrsb X0,[X0, X1]
 and X0,X0,#255
 str X0,[sp, #32]
 cbnz X0,l0077
 mov X0,X28
 b l0078
l0077:
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
 b.eq l0079
 cmp X0,#2
 b.eq l0080
 cmp X0,#3
 b.eq l0081
 b l0076
l0079:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-word)
 mov X11,#378
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0076
l0081:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-inf)
 mov X11,#379
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0076
l0080:
 ldr X2,[sp, #40]
 ldr X1,[sp, #48]
 ldr X0,[sp, #56]
// (idloc relocate-right-half)
 mov X11,#380
 ldr X10,[X23, X11, lsl #3]
 blr X10
 b l0076
l0078:
 ldp X29,X30,[sp], #64
 ret
 .quad 3
// (*entry relocate-word expr 3)
 .globl l0082
l0082:
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
 mov X11,#369
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X3,[sp, #32]
 ldr X2,[sp, #24]
 ldr X1,[sp, #48]
 ldr X0,[sp, #40]
// (idloc compute-relocation)
 mov X11,#381
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X10,[sp, #56]
 str X0,[X10]
 ldp X29,X30,[sp], #64
 ret
 .quad 3
// (*entry relocate-inf expr 3)
 .globl l0083
l0083:
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
 mov X11,#381
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X0,[sp, #24]
// (idloc bpsaddr-to-bpsaddr-rw)
 mov X11,#369
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
 .globl l0084
l0084:
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
 mov X11,#381
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #32]
 ldr X0,[sp, #24]
// (idloc bpsaddr-to-bpsaddr-rw)
 mov X11,#369
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
 .globl l0085
l0085:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X1,[sp, #16]
 cbnz X0,l0086
 mov X0,X2
 add X0,X0,X1
 b l0087
l0086:
 cmp X0,#2
 b.ne l0088
 mov X11,#65510
 cmp X1,X11
 b.lt l0089
 movn X0,#65518
 add X0,X0,X1
 lsl X0,X0,#3
// ($fluid argumentblock)
 movz X11,#259
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 b l0087
l0089:
 cmp X1,#2048
 b.lt l0090
 mov X1,X3
 ldr X0,[sp, #16]
// (idloc local-to-global-id)
 mov X11,#382
 ldr X10,[X23, X11, lsl #3]
 blr X10
 lsl X0,X0,#3
 add X0,X0,X24
 b l0087
l0090:
 mov X0,X1
 lsl X0,X0,#3
 add X0,X0,X24
 b l0087
l0088:
 cmp X0,#3
 b.ne l0091
 cmp X1,#2048
 b.lt l0092
 mov X1,X3
 ldr X0,[sp, #16]
// (idloc local-to-global-id)
 mov X11,#382
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #16]
l0092:
 ldr X0,[sp, #16]
 lsl X0,X0,#3
 add X0,X0,X23
 b l0087
l0091:
 cmp X0,#1
 b.ne l0093
 cmp X1,#2048
 b.lt l0094
 mov X1,X3
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #32
// (idloc local-to-global-id)
 mov X11,#382
 ldr X10,[X23, X11, lsl #3]
 br X10
l0094:
 mov X0,X1
 b l0087
l0093:
 mov X0,X28
l0087:
 ldp X29,X30,[sp], #32
 ret
 .quad 2
// (*entry local-to-global-id expr 2)
 .globl l0095
l0095:
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
 .globl l0096
l0096:
 stp X29,X30,[sp, #-64]!
 mov X29,sp
 str X28,[sp, #56]
 str X28,[sp, #48]
 str X28,[sp, #40]
 str X28,[sp, #32]
 str X28,[sp, #24]
 str X0,[sp, #16]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #24]
 add X0,X0,#1
// (idloc gtwrds)
 mov X11,#370
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X11,#7
 bfi X0,X11,#56,#8
 str X0,[sp, #32]
 ldr X1,[sp, #24]
 mov X0,#0
 str X0,[sp, #40]
 str X1,[sp, #48]
l0097:
 ldr X9,[sp, #40]
 ldr X10,[sp, #48]
 cmp X9,X10
 b.gt l0098
 ldr X0,[sp, #16]
// (idloc binaryread)
 mov X11,#342
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid tokenbuffer)
 movz X11,#260
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
 movz X11,#260
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 ldr X0,[sp, #16]
// (idloc binaryreadblock)
 mov X11,#344
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#0
// ($fluid tokenbuffer)
 movz X11,#260
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 mov X11,#4
 bfi X0,X11,#56,#8
// (idloc faslin-intern)
 mov X11,#354
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
 b l0097
l0098:
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #64
 ret
 .quad 3
// (*entry putentry expr 3)
 .globl putentry
putentry:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($fluid code-base-hack)
 movz X11,#374
 ldr X13,[X24, X11, lsl #3]
 add X2,X2,X13
 mov X11,#20
 bfi X2,X11,#56,#8
 ldp X29,X30,[sp], #16
// (idloc putd)
 mov X11,#383
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry faslin-bad-file expr 1)
 .globl l0101
l0101:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 movz X11,#29
 ldr X0,[X20, X11, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #16
// (idloc console-newline)
 mov X11,#331
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
l0105:
 str X0,[sp, #16]
 cmp X0,X28
 b.ne l0106
// (idloc gtbps-nil-error)
 mov X11,#385
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0106:
 ldr X11,[sp, #16]
 cmp X11,#10
 b.le l0107
 mov X0,#15
// ($global nextbps)
 movz X11,#287
 ldr X12,[X24, X11, lsl #3]
 and X0,X0,X12
 cbz X0,l0107
// ($global nextbps)
 movz X11,#287
 ldr X1,[X24, X11, lsl #3]
 lsr X1,X1,#4
 lsl X1,X1,#4
 add X1,X1,#16
// ($global nextbps)
 movz X11,#287
 str X1,[X24, X11, lsl #3]
l0107:
// ($global nextbps)
 movz X11,#287
 ldr X0,[X24, X11, lsl #3]
 ldr X1,[sp, #16]
 lsl X1,X1,#3
// ($global nextbps)
 movz X11,#287
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
// ($global nextbps)
 movz X11,#287
 str X1,[X24, X11, lsl #3]
// ($global lastbps)
 movz X11,#284
 ldr X11,[X24, X11, lsl #3]
 cmp X1,X11
 b.le l0108
// ($global nextbps)
 movz X11,#287
 str X0,[X24, X11, lsl #3]
 movz X11,#35
 ldr X0,[X20, X11, lsl #3]
// (idloc getd)
 mov X11,#386
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0109
 ldr X0,[sp, #16]
// (idloc try-other-bps-spaces)
 mov X11,#387
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0109
 ldr X0,[sp, #16]
 b l0105
l0109:
 movz X11,#34
 ldr X0,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #32
// (idloc stderror)
 mov X11,#388
 ldr X10,[X23, X11, lsl #3]
 br X10
l0108:
 ldp X29,X30,[sp], #32
 ret
 .quad 1
// (*entry gtbps-nil-error expr 1)
 .globl l0112
l0112:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 movz X11,#41
 ldr X0,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #16
// (idloc stderror)
 mov X11,#388
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry bpsaddr-to-bpsaddr-rw expr 1)
 .globl l0113
l0113:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global bpsbaserw)
 movz X11,#289
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
// ($global bpsbaserx)
 movz X11,#290
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
l0119:
 str X0,[sp, #16]
 cmp X0,X28
 b.ne l0120
 movz X11,#48
 ldr X0,[X20, X11, lsl #3]
// (idloc stderror)
 mov X11,#388
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0120:
// ($global nextstaticlisp)
 movz X11,#294
 ldr X0,[X24, X11, lsl #3]
 ldr X1,[sp, #16]
 lsl X1,X1,#3
// ($global nextstaticlisp)
 movz X11,#294
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
// ($global nextstaticlisp)
 movz X11,#294
 str X1,[X24, X11, lsl #3]
// ($global laststaticlisp)
 movz X11,#293
 ldr X11,[X24, X11, lsl #3]
 cmp X1,X11
 b.le l0121
// ($global nextstaticlisp)
 movz X11,#294
 str X0,[X24, X11, lsl #3]
 movz X11,#47
 ldr X0,[X20, X11, lsl #3]
// (idloc getd)
 mov X11,#386
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0122
 ldr X0,[sp, #16]
// (idloc try-other-staticlisp-spaces)
 mov X11,#389
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0122
 ldr X0,[sp, #16]
 b l0119
l0122:
 movz X11,#46
 ldr X0,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #32
// (idloc stderror)
 mov X11,#388
 ldr X10,[X23, X11, lsl #3]
 br X10
l0121:
 ldp X29,X30,[sp], #32
 ret
 nop
 .quad 1
// (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 cmp X0,X28
 b.ne l0123
 ldp X29,X30,[sp], #16
// (idloc known-free-space)
 mov X11,#390
 ldr X10,[X23, X11, lsl #3]
 br X10
l0123:
 ldp X29,X30,[sp], #16
// (idloc real-gtheap)
 mov X11,#391
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry real-gtheap expr 1)
 .globl l0124
l0124:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 mov X2,X0
 mov X0,X21
 mov X1,X2
 lsl X1,X1,#3
 add X1,X1,X21
 mov X21,X1
 cmp X1,X22
 b.lt l0125
 mov X1,X2
 ldp X29,X30,[sp], #16
// (idloc get-heap-trap)
 mov X11,#393
 ldr X10,[X23, X11, lsl #3]
 br X10
l0125:
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 2
// (*entry get-heap-trap expr 2)
 .globl l0128
l0128:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 movz X11,#59
 ldr X0,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #16
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
l0131:
// (*entry gtid expr 0)
 .globl gtid
gtid:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
// ($global nextsymbol)
 movz X11,#347
 ldr X11,[X24, X11, lsl #3]
 cbnz X11,l0132
// (idloc reclaim)
 mov X11,#394
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($global nextsymbol)
 movz X11,#347
 ldr X11,[X24, X11, lsl #3]
 cbnz X11,l0132
 movz X11,#65
 ldr X0,[X20, X11, lsl #3]
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0132:
// ($global nextsymbol)
 movz X11,#347
 ldr X0,[X24, X11, lsl #3]
 mov X1,X0
 lsl X1,X1,#3
// ($global symnam)
 movz X11,#348
 ldr X13,[X24, X11, lsl #3]
 add X1,X1,X13
 ldr X9,[X1]
// ($global nextsymbol)
 movz X11,#347
 str X9,[X24, X11, lsl #3]
 ldp X29,X30,[sp], #16
 ret
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
 mov X11,#392
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
 mov X11,#367
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
 b.eq l0135
 movz X11,#70
 ldr X0,[X20, X11, lsl #3]
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0135:
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
 mov X11,#395
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #56]
 ldr X1,[sp, #40]
 mov X0,#0
 mov X4,X0
 mov X3,X1
l0136:
 cmp X4,X3
 b.gt l0137
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
 b l0136
l0137:
 ldr X0,[sp, #56]
 mov X11,#4
 bfi X0,X11,#56,#8
 ldp X29,X30,[sp], #64
 ret
 .quad 2
// (*entry search-string-for-character expr 2)
 .globl l0138
l0138:
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
l0139:
 cmp X3,X2
 b.le l0140
 mov X0,X28
 b l0141
l0140:
 mov X1,X3
 ubfx X0,X4,#0,#56
 add X0,X0,#8
 ldrsb X0,[X0, X1]
 ldr X11,[sp, #16]
 cmp X11,X0
 b.ne l0142
 mov X0,X1
 b l0141
l0142:
 add X3,X3,#1
 b l0139
l0141:
 ldp X29,X30,[sp], #32
 ret
 .quad 2
// (*entry unchecked-string-equal expr 2)
 .globl l0144
l0144:
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
 b.eq l0145
 mov X0,X28
 b l0146
l0145:
 mov X9,#0
 str X9,[sp, #32]
l0147:
 ldr X11,[sp, #32]
 cmp X11,X4
 b.le l0148
 movz X11,#76
 ldr X0,[X20, X11, lsl #3]
 b l0146
l0148:
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
 b.eq l0149
 mov X0,X28
 b l0146
l0149:
 ldr X12,[sp, #32]
 add X12,X12,#1
 str X12,[sp, #32]
 b l0147
l0146:
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
 b.ge l0150
 str X0,[sp, #16]
l0150:
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
l0151:
 cmp X3,X2
 b.gt l0152
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
 b l0151
l0152:
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
 mov X11,#392
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
 mov X11,#399
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 3
// (*entry unchecked-put expr 3)
 .globl l0153
l0153:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
// (idloc unchecked-prop)
 mov X11,#401
 ldr X10,[X23, X11, lsl #3]
 blr X10
 str X0,[sp, #40]
 mov X1,X0
 ldr X0,[sp, #24]
// (idloc atsoc)
 mov X11,#402
 ldr X10,[X23, X11, lsl #3]
 blr X10
 cmp X0,X28
 b.eq l0154
 ubfx X10,X0,#0,#56
 ldr X9,[sp, #32]
 str X9,[X10, #8]
 b l0155
l0154:
 ldr X1,[sp, #32]
 ldr X0,[sp, #24]
 str X0,[X21]
 mov X0,#9
 orr X0,X21,X0, lsl #56
 str X1,[X21, #8]
 add X21,X21,#16
 cmp X21,X22
 b.lt l0156
 stp X0,X1,[sp, #-16]!
// (idloc !%reclaim)
 mov X11,#403
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X0,X1,[sp], #16
l0156:
 ldr X1,[sp, #40]
 str X0,[X21]
 mov X0,#9
 orr X0,X21,X0, lsl #56
 str X1,[X21, #8]
 add X21,X21,#16
 cmp X21,X22
 b.lt l0157
 stp X0,X1,[sp, #-16]!
// (idloc !%reclaim)
 mov X11,#403
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X0,X1,[sp], #16
l0157:
 mov X1,X0
 ldr X0,[sp, #16]
// (idloc unchecked-setprop)
 mov X11,#404
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0155:
 ldr X0,[sp, #32]
 ldp X29,X30,[sp], #48
 ret
 .quad 2
// (*entry atsoc expr 2)
 .globl atsoc
atsoc:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
l0158:
 ubfx X11,X1,#56,#8
 cmp X11,#9
 b.eq l0159
 mov X0,X28
 ldp X29,X30,[sp], #16
 ret
l0159:
 ubfx X9,X1,#0,#56
 ldr X11,[X9]
 ubfx X11,X11,#56,#8
 cmp X11,#9
 b.ne l0160
 ubfx X10,X1,#0,#56
 ldr X10,[X10]
 ubfx X10,X10,#0,#56
 ldr X11,[X10]
 cmp X0,X11
 b.ne l0160
 ubfx X0,X1,#0,#56
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
l0160:
 ubfx X1,X1,#0,#56
 ldr X1,[X1, #8]
 b l0158
 .quad 2
// (*entry unchecked-setprop expr 2)
 .globl l0161
l0161:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 lsl X0,X0,#3
// ($global symprp)
 movz X11,#362
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 str X1,[X0]
 mov X0,X1
 ldp X29,X30,[sp], #16
 ret
 .quad 1
// (*entry unchecked-prop expr 1)
 .globl l0162
l0162:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X0,X0,#0,#56
 lsl X0,X0,#3
// ($global symprp)
 movz X11,#362
 ldr X13,[X24, X11, lsl #3]
 add X0,X0,X13
 ldr X0,[X0]
 ldp X29,X30,[sp], #16
 ret
 nop
 .quad 3
// (*entry putd expr 3)
 .globl putd
putd:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldp X29,X30,[sp], #16
// (idloc code-putd)
 mov X11,#405
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 3
// (*entry code-putd expr 3)
 .globl l0167
l0167:
 stp X29,X30,[sp, #-48]!
 mov X29,sp
 str X28,[sp, #40]
 str X0,[sp, #16]
 str X1,[sp, #24]
 str X2,[sp, #32]
 ubfx X11,X0,#56,#8
 cmp X11,#254
 b.ne l0168
 ubfx X11,X1,#56,#8
 cmp X11,#254
 b.ne l0168
 ubfx X11,X2,#56,#8
 cmp X11,#20
 b.eq l0169
l0168:
 movz X11,#79
 ldr X0,[X20, X11, lsl #3]
// (idloc kernel-fatal-error)
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 blr X10
l0169:
 ldr X1,[sp, #32]
 ubfx X1,X1,#0,#56
 ldr X0,[sp, #16]
 ubfx X0,X0,#0,#56
// (idloc plantcodepointer)
 mov X11,#406
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X9,[sp, #24]
 movz X11,#78
 ldr X10,[X20, X11, lsl #3]
 cmp X9,X10
 b.eq l0170
 ldr X2,[sp, #24]
 movz X11,#77
 ldr X1,[X20, X11, lsl #3]
 ldr X0,[sp, #16]
 ldp X29,X30,[sp], #48
// (idloc put)
 mov X11,#400
 ldr X10,[X23, X11, lsl #3]
 br X10
l0170:
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
 b.ne l0171
 ldr X0,[sp, #24]
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 b l0172
l0171:
 mov X0,X28
l0172:
 str X0,[sp, #32]
l0173:
 ldr X11,[sp, #24]
 ubfx X11,X11,#56,#8
 cmp X11,#9
 b.eq l0174
 mov X0,X28
 b l0175
l0174:
 ldr X0,[sp, #32]
// (idloc fluid1)
 mov X11,#407
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #24]
 ubfx X0,X0,#0,#56
 ldr X0,[X0, #8]
 str X0,[sp, #24]
 ubfx X11,X0,#56,#8
 cmp X11,#9
 b.ne l0176
 ubfx X0,X0,#0,#56
 ldr X0,[X0]
 b l0177
l0176:
 mov X0,X28
l0177:
 str X0,[sp, #32]
 b l0173
l0175:
 ldp X29,X30,[sp], #48
 ret
 nop
 .quad 1
// (*entry fluid1 expr 1)
 .globl l0180
l0180:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 movz X11,#86
 ldr X2,[X20, X11, lsl #3]
 movz X11,#85
 ldr X1,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #16
// (idloc put)
 mov X11,#400
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
 mov X11,#339
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 2
// (*entry *define-constant expr 2)
 .globl l0183
l0183:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ubfx X2,X0,#0,#56
 lsl X2,X2,#3
 add X2,X2,X24
 str X1,[X2]
 movz X11,#88
 ldr X2,[X20, X11, lsl #3]
 movz X11,#87
 ldr X1,[X20, X11, lsl #3]
 ldp X29,X30,[sp], #16
// (idloc put)
 mov X11,#400
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 stp X29,X30,[sp, #-16]!
 mov X29,sp
 ldr X9,l0184
 str X9,[X23, X0, lsl #3]
 ldp X29,X30,[sp], #16
 ret
l0185:
l0184:
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
 ldr X9,l0186
 str X9,[X23, X0, lsl #3]
 ldp X29,X30,[sp], #16
 ret
l0187:
l0186:
 .quad compiledcallinginterpreted
 .quad 1
// (*entry addressapply0 expr 1)
 .globl l0188
l0188:
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
 b.ge l0189
 neg X10,X2
 lsr X0,X0,X10
 b l0190
l0189:
 lsl X0,X0,X2
l0190:
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
 mov X11,#411
 ldr X10,[X23, X11, lsl #3]
 br X10
 .quad 1
// (*entry undefinedfunction-aux expr 1)
 .globl l0193
l0193:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X9,[sp, #16]
 movz X11,#89
 ldr X0,[X20, X11, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
// ($fluid symnam)
 movz X11,#348
 ldr X10,[X24, X11, lsl #3]
 ldr X9,[sp, #16]
 ldr X0,[X10, X9, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 mov X11,#331
 ldr X10,[X23, X11, lsl #3]
 blr X10
 mov X0,#0
// (idloc exit-with-status)
 mov X11,#317
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldp X29,X30,[sp], #32
 ret
 nop
l0194:
// (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 mov X9,X11
 mov X11,#254
 bfi X9,X11,#56,#8
// ($fluid codeform*)
 movz X11,#413
 str X9,[X24, X11, lsl #3]
// (idloc compiledcallinginterpretedaux)
 mov X11,#414
 ldr X10,[X23, X11, lsl #3]
 br X10
 nop
 .quad 1
// (*entry kernel-fatal-error expr 1)
 .globl l0197
l0197:
 stp X29,X30,[sp, #-32]!
 mov X29,sp
 str X28,[sp, #24]
 str X0,[sp, #16]
 movz X11,#95
 ldr X0,[X20, X11, lsl #3]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ldr X0,[sp, #16]
// (idloc console-print-string)
 mov X11,#330
 ldr X10,[X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 mov X11,#331
 ldr X10,[X23, X11, lsl #3]
 blr X10
 movn X0,#0
 ldp X29,X30,[sp], #32
// (idloc exit-with-status)
 mov X11,#317
 ldr X10,[X23, X11, lsl #3]
 br X10
l0198:
// (*entry echooff expr 0)
 .globl l0199
l0199:
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
l0200:
// (*entry echoon expr 0)
 .globl l0201
l0201:
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
 .globl l0202
l0202:
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
l0203:
// (*entry flushstdoutputbuffer expr 0)
 .globl l0204
l0204:
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
l0205:
// (*entry external_user_homedir_string expr 0)
 .globl l0206
l0206:
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
 .globl l0207
l0207:
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
l0208:
// (*entry unexec expr 0)
 .globl l0209
l0209:
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
 .globl l0210
l0210:
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
 .globl l0211
l0211:
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
l0212:
// (*entry get_imagefilepath expr 0)
 .globl l0213
l0213:
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
 .globl l0214
l0214:
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
 .globl l0215
l0215:
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
l0216:
// (*entry os_cleanup_hook expr 0)
 .globl l0217
l0217:
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
l0218:
// (*entry get_execfilepath expr 0)
 .globl l0219
l0219:
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
 .globl l0220
l0220:
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
 .globl l0221
l0221:
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
 .globl l0222
l0222:
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
 .globl l0223
l0223:
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
 .globl l0224
l0224:
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
l0225:
// (*entry external_timc expr 0)
 .globl l0226
l0226:
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
 .globl l0227
l0227:
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
 .globl l0228
l0228:
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
 .globl l0229
l0229:
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
 .globl l0230
l0230:
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
 .globl l0231
l0231:
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
 .globl l0232
l0232:
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
 .globl l0233
l0233:
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
 .globl l0234
l0234:
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
 .globl l0235
l0235:
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
 .globl l0236
l0236:
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
 .globl l0237
l0237:
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
 .globl l0238
l0238:
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
 .globl l0239
l0239:
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
 .globl l0240
l0240:
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
 .globl l0241
l0241:
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
 .globl l0242
l0242:
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
 .globl l0243
l0243:
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
 .globl l0244
l0244:
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
 .globl l0245
l0245:
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
 .globl l0246
l0246:
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
 .globl l0247
l0247:
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
 .globl l0248
l0248:
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
 .globl l0249
l0249:
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
 .globl l0250
l0250:
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
 .globl l0251
l0251:
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
 .globl l0252
l0252:
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
 .globl l0253
l0253:
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
 .globl l0254
l0254:
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
 .globl l0255
l0255:
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
 .globl l0256
l0256:
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
 .globl l0257
l0257:
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
 .globl l0258
l0258:
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
 .globl l0259
l0259:
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
 .globl l0260
l0260:
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
 .globl l0261
l0261:
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
 .globl l0262
l0262:
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
 .globl l0263
l0263:
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
 .globl l0264
l0264:
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
 .globl l0265
l0265:
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
 .globl l0266
l0266:
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
 .globl l0267
l0267:
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
 .globl l0268
l0268:
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
 .globl l0269
l0269:
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
 .globl l0270
l0270:
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
l0271:
// (*entry external_pwd expr 0)
 .globl l0272
l0272:
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
 .globl l0273
l0273:
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
 .globl l0274
l0274:
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
 .globl l0275
l0275:
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
 .globl l0276
l0276:
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
 .globl l0277
l0277:
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
 .globl l0278
l0278:
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
l0279:
// (*entry unixcleario expr 0)
 .globl l0280
l0280:
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
 .globl l0281
l0281:
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
 .globl l0282
l0282:
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
 .globl l0283
l0283:
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
 .globl l0284
l0284:
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
 .globl l0285
l0285:
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
 .globl l0286
l0286:
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
 .globl l0287
l0287:
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
 .globl l0288
l0288:
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
 .globl l0289
l0289:
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
 .globl l0290
l0290:
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
 .globl l0291
l0291:
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
 .globl l0292
l0292:
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
 .globl l0293
l0293:
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
 .globl l0294
l0294:
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
 .globl l0295
l0295:
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
 .globl l0296
l0296:
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
 .globl l0297
l0297:
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
 .globl l0298
l0298:
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
 .globl l0299
l0299:
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
 .globl l0300
l0300:
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
 .globl l0301
l0301:
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
 .globl l0302
l0302:
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
 .globl l0303
l0303:
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
l0304:
// (*entry getpid expr 0)
 .globl l0305
l0305:
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
l0306:
// (*entry gethostid expr 0)
 .globl l0307
l0307:
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
 .globl l0308
l0308:
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
 .globl l0309
l0309:
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
 .globl l0310
l0310:
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
 .globl l0311
l0311:
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
l0312:
// (*entry fork expr 0)
 .globl l0313
l0313:
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
 .globl l0314
l0314:
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
 .globl l0315
l0315:
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
 .globl l0316
l0316:
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
 .globl l0317
l0317:
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
 .globl l0318
l0318:
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
 .globl l0319
l0319:
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
 .globl l0320
l0320:
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
 .globl l0321
l0321:
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
 .globl l0322
l0322:
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
 .globl l0323
l0323:
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
 .globl l0324
l0324:
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
 .globl l0325
l0325:
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
 .globl l0326
l0326:
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
 .globl l0327
l0327:
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
 .globl l0328
l0328:
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
 movz X11,#101
 ldr X0,[X20, X11, lsl #3]
// (idloc getfcodepointer)
 mov X11,#522
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X0,X11
 b.le l0332
 mov X0,X28
 b l0333
l0332:
 movz X11,#100
 ldr X0,[X20, X11, lsl #3]
l0333:
 cmp X0,X28
 b.eq l0334
 movz X11,#99
 ldr X0,[X20, X11, lsl #3]
// (idloc getfcodepointer)
 mov X11,#522
 ldr X10,[X23, X11, lsl #3]
 blr X10
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X11,X0
 b.lt l0335
 mov X0,X28
 b l0334
l0335:
 movz X11,#100
 ldr X0,[X20, X11, lsl #3]
l0334:
 cmp X0,X28
 b.ne l0336
// ($global bpslowerbound)
 movz X11,#285
 ldr X0,[X24, X11, lsl #3]
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X0,X11
 b.le l0337
 mov X0,X28
 b l0338
l0337:
 movz X11,#100
 ldr X0,[X20, X11, lsl #3]
l0338:
 cmp X0,X28
 b.eq l0336
// ($global nextbps)
 movz X11,#287
 ldr X0,[X24, X11, lsl #3]
 ubfx X0,X0,#0,#56
 ldr X11,[sp, #16]
 cmp X11,X0
 b.lt l0339
 mov X0,X28
 b l0336
l0339:
 movz X11,#100
 ldr X0,[X20, X11, lsl #3]
l0336:
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
l0340:
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
 .globl l0035
 .globl l0044
 .globl l0045
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
 .globl l0133
 .globl l0134
 .globl l0143
 .globl l0165
 .globl l0164
 .globl l0163
 .globl l0166
 .globl l0179
 .globl l0178
 .globl l0182
 .globl l0181
 .globl l0191
 .globl l0192
 .globl l0195
 .globl l0196
 .globl l0331
 .globl l0330
 .globl l0329
 .globl l0341
 .globl l0342
 .globl l0343
 .globl l0344
 .globl l0345
 .globl l0346
 .globl l0347
 .globl l0348
 .globl l0349
 .globl l0350
 .globl l0351
 .globl l0352
 .globl l0353
 .globl l0354
 .globl l0355
 .globl l0356
 .globl l0357
 .globl l0358
 .globl l0359
 .globl l0360
 .globl l0361
 .globl l0362
 .globl l0363
 .globl l0364
 .globl l0365
 .globl l0366
 .globl l0367
 .globl l0368
 .globl l0369
 .globl l0370
 .globl l0371
 .globl l0372
 .globl l0373
 .globl l0374
 .globl l0375
 .globl l0376
 .globl l0377
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
 .globl endinitstaticlisp
 .globl laststaticlisp
