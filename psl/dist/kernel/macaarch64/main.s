        .text
 .align 3
 .quad 1
// (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 ret
 .quad 0
// (*entry move-regs-to-mem expr 0)
 .globl l0006
l0006:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ($fluid heaplast)
 ldr X11, l0001
 str X21, [X24, X11, lsl #3]
// ($fluid heaptrapbound)
 ldr X11, l0002
 str X22, [X24, X11, lsl #3]
// ($fluid bndstkptr)
 ldr X11, l0003
 str X25, [X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 ldr X11, l0004
 str X26, [X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 ldr X11, l0005
 str X27, [X24, X11, lsl #3]
 ldp X29, X30, [sp], #16
 ret
l0005:
 .quad 272
l0004:
 .quad 271
l0003:
 .quad 270
l0002:
 .quad 269
l0001:
 .quad 268
 .quad 0
// (*entry init-pointers expr 0)
 .globl l0016
l0016:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ($global catchstack)
 ldr X11, l0007
 ldr X9, [X24, X11, lsl #3]
// ($global catchstackptr)
 ldr X11, l0008
 str X9, [X24, X11, lsl #3]
// ($global bndstk)
 ldr X11, l0009
 ldr X9, [X24, X11, lsl #3]
// ($global bndstklowerbound)
 ldr X11, l0010
 str X9, [X24, X11, lsl #3]
 ldr X0, l0011
// ($global bndstk)
 ldr X11, l0009
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
// ($global bndstkupperbound)
 ldr X11, l0012
 str X0, [X24, X11, lsl #3]
// ($global bndstk)
 ldr X11, l0009
 ldr X9, [X24, X11, lsl #3]
// ($global bndstkptr)
 ldr X11, l0013
 str X9, [X24, X11, lsl #3]
// ($global heaplowerbound)
 ldr X11, l0014
 ldr X0, [X24, X11, lsl #3]
// ($global heap)
 ldr X11, l0015
 str X0, [X24, X11, lsl #3]
 ldp X29, X30, [sp], #16
 ret
l0015:
 .quad 276
l0014:
 .quad 275
l0013:
 .quad 270
l0012:
 .quad 272
l0011:
 .quad 159992
l0010:
 .quad 271
l0009:
 .quad 261
l0008:
 .quad 274
l0007:
 .quad 262
 .quad 0
// (*entry init-fluids expr 0)
 .globl l0041
l0041:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X0, X28
// ($global gcarraylowerbound)
 ldr X11, l0017
 str X0, [X24, X11, lsl #3]
// ($global gcarrayupperbound)
 ldr X11, l0018
 str X0, [X24, X11, lsl #3]
// ($global heaplast)
 ldr X11, l0019
 str X0, [X24, X11, lsl #3]
// ($global oldheaplast)
 ldr X11, l0020
 str X0, [X24, X11, lsl #3]
// ($global heaptrapbound)
 ldr X11, l0021
 str X0, [X24, X11, lsl #3]
// ($global oldheaptrapbound)
 ldr X11, l0022
 str X0, [X24, X11, lsl #3]
// ($global heapupperbound)
 ldr X11, l0023
 str X0, [X24, X11, lsl #3]
// ($global _infbitlength_)
 ldr X11, l0024
 str X0, [X24, X11, lsl #3]
// ($global lastbps)
 ldr X11, l0025
 str X0, [X24, X11, lsl #3]
// ($global bpslowerbound)
 ldr X11, l0026
 str X0, [X24, X11, lsl #3]
// ($global mainstartinitialize)
 ldr X11, l0027
 str X0, [X24, X11, lsl #3]
// ($global nextbps)
 ldr X11, l0028
 str X0, [X24, X11, lsl #3]
// ($global oldheapupperbound)
 ldr X11, l0029
 str X0, [X24, X11, lsl #3]
// ($global oldheaplowerbound)
 ldr X11, l0030
 str X0, [X24, X11, lsl #3]
// ($global stackupperbound)
 ldr X11, l0031
 str X0, [X24, X11, lsl #3]
// ($global unixstdin)
 ldr X11, l0032
 str X0, [X24, X11, lsl #3]
// ($global unixstdout)
 ldr X11, l0033
 str X0, [X24, X11, lsl #3]
// ($global unixstderr)
 ldr X11, l0034
 str X0, [X24, X11, lsl #3]
// ($global unixnull)
 ldr X11, l0035
 str X0, [X24, X11, lsl #3]
// ($global unixeof)
 ldr X11, l0036
 str X0, [X24, X11, lsl #3]
// ($global unixtty)
 ldr X11, l0037
 str X0, [X24, X11, lsl #3]
// ($global ***must-be-nil***)
 ldr X11, l0038
 str X0, [X24, X11, lsl #3]
// ($global ***must-be-nil-too***)
 ldr X11, l0039
 str X0, [X24, X11, lsl #3]
// ($global *fastcar)
 ldr X11, l0040
 str X0, [X24, X11, lsl #3]
 ldp X29, X30, [sp], #16
 ret
 nop
l0040:
 .quad 299
l0039:
 .quad 298
l0038:
 .quad 297
l0037:
 .quad 296
l0036:
 .quad 295
l0035:
 .quad 294
l0034:
 .quad 293
l0033:
 .quad 292
l0032:
 .quad 291
l0031:
 .quad 290
l0030:
 .quad 289
l0029:
 .quad 288
l0028:
 .quad 287
l0027:
 .quad 286
l0026:
 .quad 285
l0025:
 .quad 284
l0024:
 .quad 283
l0023:
 .quad 282
l0022:
 .quad 281
l0021:
 .quad 269
l0020:
 .quad 280
l0019:
 .quad 268
l0018:
 .quad 279
l0017:
 .quad 278
 .quad 0
// (*entry _psl_main expr 0)
_psl_main:
 .globl _psl_main
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X0, [sp, #16]
 str X1, [sp, #24]
 str X29, [sp, #32]
 mov X24, X2
// ($global symval)
 ldr X11, l0042
 str X24, [X24, X11, lsl #3]
// ($global symfnc)
 ldr X11, l0043
 ldr X23, [X24, X11, lsl #3]
 mov X28, #256
 mov X11, #254
 bfi X28, X11, #56, #8
 mov X9, #56
// (fluid _infbitlength_)
 ldr X11, l0044
 str X9, [X24, X11, lsl #3]
// (idloc os_startup_hook)
 ldr X11, l0045
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X9, [sp, #16]
// (fluid argc)
 ldr X11, l0046
 str X9, [X24, X11, lsl #3]
 ldr X9, [sp, #24]
// (fluid argv)
 ldr X11, l0047
 str X9, [X24, X11, lsl #3]
 ldr X9, [sp, #32]
// (fluid ebxsave*)
 ldr X11, l0048
 str X9, [X24, X11, lsl #3]
// (idloc init-pointers)
 ldr X11, l0049
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X3, sp
 lsr X3, X3, #5
// (fluid stacklowerbound)
 ldr X11, l0050
 str X3, [X24, X11, lsl #3]
// ($fluid heaplast)
 ldr X11, l0051
 ldr X21, [X24, X11, lsl #3]
// ($fluid heaptrapbound)
 ldr X11, l0052
 ldr X22, [X24, X11, lsl #3]
// ($fluid bndstkptr)
 ldr X11, l0053
 ldr X25, [X24, X11, lsl #3]
// ($fluid bndstklowerbound)
 ldr X11, l0054
 ldr X26, [X24, X11, lsl #3]
// ($fluid bndstkupperbound)
 ldr X11, l0055
 ldr X27, [X24, X11, lsl #3]
// (idloc init-gcarray)
 ldr X11, l0056
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc pre-main)
 ldr X11, l0057
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0061:
 mov X0, #0
 ldp X29, X30, [sp], #48
// (idloc exit-with-status)
 ldr X11, l0058
 ldr X10, [X23, X11, lsl #3]
 br X10
// (*entry exit-with-status expr 1)
 .globl l0062
l0062:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X0, [sp, #16]
// (idloc os_cleanup_hook)
 ldr X11, l0059
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #16]
 ldp X29, X30, [sp], #32
// (idloc external_exit)
 ldr X11, l0060
 ldr X10, [X23, X11, lsl #3]
 br X10
 ldp X29, X30, [sp], #16
 ret
 nop
l0060:
 .quad 312
l0059:
 .quad 311
l0058:
 .quad 310
l0057:
 .quad 309
l0056:
 .quad 308
l0055:
 .quad 272
l0054:
 .quad 271
l0053:
 .quad 270
l0052:
 .quad 269
l0051:
 .quad 268
l0050:
 .quad 307
l0049:
 .quad 277
l0048:
 .quad 306
l0047:
 .quad 305
l0046:
 .quad 304
l0045:
 .quad 303
l0044:
 .quad 283
l0043:
 .quad 302
l0042:
 .quad 301
 .quad 0
// (*entry _reduceup expr 0)
 .globl _reduceup
_reduceup:
 ldr X0, [sp, #16]
 ldr X1, [sp, #24]
 ldr X2, [sp, #32]
 ldr X3, [sp, #40]
 ldp X29, X30, [sp], #16
// (idloc reduceup)
 ldr X11, l0063
 ldr X10, [X23, X11, lsl #3]
 br X10
l0063:
 .quad 314
 .quad 4
// (*entry reduceup expr 4)
 .globl reduceup
reduceup:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X1, [sp, #24]
 str X3, [sp, #16]
 mov X1, X2
// (idloc stringopen)
 ldr X11, l0064
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #32]
 ldr X1, [sp, #16]
 ldr X0, [sp, #24]
// (idloc stringopen)
 ldr X11, l0064
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #40]
 ldr X9, l0065
// ($fluid *lisp_hook)
 ldr X11, l0066
 str X9, [X24, X11, lsl #3]
 ldr X0, [sp, #32]
// (idloc rds)
 ldr X11, l0067
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #40]
// (idloc wrs)
 ldr X11, l0068
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc begin1)
 ldr X11, l0069
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, X28
// (idloc rds)
 ldr X11, l0067
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, X28
// (idloc wrs)
 ldr X11, l0068
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #32]
// (idloc close)
 ldr X11, l0070
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #40]
// (idloc close)
 ldr X11, l0070
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, X28
 ldp X29, X30, [sp], #48
 ret
l0070:
 .quad 321
l0069:
 .quad 320
l0068:
 .quad 319
l0067:
 .quad 318
l0066:
 .quad 317
l0065:
 .quad ((254<<56)+116)
l0064:
 .quad 316
 .quad 0
// (*entry init-gcarray expr 0)
 .globl l0071
l0071:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X0, X28
 ldp X29, X30, [sp], #16
 ret
 nop
l0081:
 .quad 9
 .byte 108,111,97,100,45,112,115,108,46,98
 .byte 0,0,0,0,0,0
l0082:
 .quad 21
 .byte 65,98,111,117,116,32,116,111,32,108
 .byte 111,97,100,32,76,79,65,68,45,80,83
 .byte 76,0,0
 .quad 0
// (*entry pre-main expr 0)
 .globl l0083
l0083:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// (idloc unixcleario)
 ldr X11, l0072
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc initialize-symbol-table)
 ldr X11, l0073
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc initcode)
 ldr X11, l0074
 ldr X10, [X23, X11, lsl #3]
 blr X10
// ldr X0, l0075
 adr X0,l0082
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc console-print-string)
 ldr X11, l0076
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11, l0077
 ldr X10, [X23, X11, lsl #3]
 blr X10
 adr X0, l0081
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc faslin)
 ldr X11, l0079
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldp X29, X30, [sp], #16
// (idloc loader-main)
 ldr X11, l0080
 ldr X10, [X23, X11, lsl #3]
 br X10
l0080:
 .quad 328
l0079:
 .quad 327
// l0078:
//  .quad ((4<<56)+l0081)
l0077:
 .quad 326
l0076:
 .quad 325
// l0075:
//  .quad ((4<<56)+l0082)
l0074:
 .quad 324
l0073:
 .quad 323
l0072:
 .quad 322
 .quad 1
// (*entry console-print-string expr 1)
 .globl l0085
l0085:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ubfx X0, X0, #0, #56
 add X0, X0, #8
 ldp X29, X30, [sp], #16
// (idloc unixputs)
 ldr X11, l0084
 ldr X10, [X23, X11, lsl #3]
 br X10
l0084:
 .quad 329
 .quad 1
// (*entry console-print-number expr 1)
 .globl l0087
l0087:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc unixputn)
 ldr X11, l0086
 ldr X10, [X23, X11, lsl #3]
 br X10
l0086:
 .quad 330
 .quad 0
// (*entry console-newline expr 0)
 .globl l0089
l0089:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X0, #10
 ldp X29, X30, [sp], #16
// (idloc unixputc)
 ldr X11, l0088
 ldr X10, [X23, X11, lsl #3]
 br X10
 nop
l0088:
 .quad 332
l0094:
 .quad 34
 .byte 67,111,117,108,100,110,39,116,32,111
 .byte 112,101,110,32,98,105,110,97,114,121
 .byte 32,102,105,108,101,32,102,111,114,32
 .byte 105,110,112,117,116,0,0,0,0,0
l0095:
 .quad 0
 .byte 114,0,0,0,0,0,0,0
 .quad 1
// (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ldr X1, l0090
 adr X0,l0095
 mov X11, #4
 bfi X0, X11, #56, #8
 ubfx X1, X1, #0, #56
 add X1, X1, #8
 ubfx X0, X0, #0, #56
 add X0, X0, #8
// (idloc unixopen)
 ldr X11, l0091
 ldr X10, [X23, X11, lsl #3]
 blr X10
 cbnz X0, l0096
// ldr X0, l0092
 adr X0,l0094
 mov X11, #4
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #16
// (idloc kernel-fatal-error)
 ldr X11, l0093
 ldr X10, [X23, X11, lsl #3]
 br X10
l0096:
 ldp X29, X30, [sp], #16
 ret
l0093:
 .quad 334
// l0092:
//  .quad ((4<<56)+l0094)
l0091:
 .quad 333
// l0090:
// .quad ((4<<56)+l0095)
 .quad 1
// (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc xgetw)
 ldr X11, l0097
 ldr X10, [X23, X11, lsl #3]
 br X10
l0097:
 .quad 336
 .quad 3
// (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X4, X1
 mov X3, X0
 mov X1, #8
 mov X0, X4
 ldp X29, X30, [sp], #16
// (idloc fread)
 ldr X11, l0098
 ldr X10, [X23, X11, lsl #3]
 br X10
l0098:
 .quad 338
 .quad 1
// (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc fclose)
 ldr X11, l0099
 ldr X10, [X23, X11, lsl #3]
 br X10
l0099:
 .quad 340
 .quad 0
// (*entry initialize-symbol-table expr 0)
 .globl l0108
l0108:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X28, [sp, #16]
 ldr X1, l0100
// ($global nextsymbol)
 ldr X11, l0101
 ldr X0, [X24, X11, lsl #3]
 mov X3, X0
 mov X2, X1
l0109:
 cmp X3, X2
 b.gt l0110
 mov X0, X3
 lsl X0, X0, #3
// ($global symnam)
 ldr X11, l0102
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 mov X1, #1
 add X1, X1, X3
 str X1, [X0]
 add X3, X3, #1
 b l0109
l0110:
// ($global symnam)
 ldr X11, l0102
 ldr X10, [X24, X11, lsl #3]
 ldr X11, l0103
 add X10, X10, X11
 mov X9, #0
 str X9, [X10]
 ldr X1, l0104
 mov X0, #0
 str X0, [sp, #16]
 str X1, [sp, #24]
l0111:
 ldr X9, [sp, #16]
 ldr X10, [sp, #24]
 cmp X9, X10
 b.gt l0112
 mov X2, #0
 ldr X1, [sp, #16]
// ($fluid hashtable)
 ldr X11, l0105
 ldr X0, [X24, X11, lsl #3]
 str W2, [X0, X1, lsl #2]
 ldr X10, [sp, #16]
 add X10, X10, #1
 str X10, [sp, #16]
 b l0111
l0112:
// ($global symnam)
 ldr X11, l0102
 ldr X11, [X24, X11, lsl #3]
 ldr X0, [X11, #2048]
// (idloc hash-into-table)
 ldr X11, l0106
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X2, #256
 mov X1, X0
// ($fluid hashtable)
 ldr X11, l0105
 ldr X0, [X24, X11, lsl #3]
 str W2, [X0, X1, lsl #2]
 movn X1, #0
// ($global nextsymbol)
 ldr X11, l0101
 ldr X11, [X24, X11, lsl #3]
 add X1, X1, X11
 mov X0, #256
 str X0, [sp, #16]
 str X1, [sp, #24]
l0113:
 ldr X9, [sp, #16]
 ldr X10, [sp, #24]
 cmp X9, X10
 b.gt l0114
 ldr X0, [sp, #16]
 lsl X0, X0, #3
// ($global symnam)
 ldr X11, l0102
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 ldr X0, [X0]
// (idloc hash-into-table)
 ldr X11, l0106
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X2, [sp, #16]
 mov X1, X0
// ($fluid hashtable)
 ldr X11, l0105
 ldr X0, [X24, X11, lsl #3]
 str W2, [X0, X1, lsl #2]
 ldr X10, [sp, #16]
 add X10, X10, #1
 str X10, [sp, #16]
 b l0113
l0114:
 mov X0, X28
// ($global show-new-ids)
 ldr X11, l0107
 str X0, [X24, X11, lsl #3]
 ldp X29, X30, [sp], #32
 ret
 nop
l0107:
 .quad 345
l0106:
 .quad 344
l0105:
 .quad 263
l0104:
 .quad 393241
l0103:
 .quad 2400000
l0102:
 .quad 343
l0101:
 .quad 342
l0100:
 .quad 300000
 .quad 1
// (*entry faslin-intern expr 1)
 .globl l0118
l0118:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X28, [sp, #24]
 str X0, [sp, #16]
 mov X1, X0
 mov X0, #0
// (idloc search-string-for-character)
 ldr X11, l0115
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #24]
 cmp X0, X28
 b.ne l0119
 ldr X0, [sp, #16]
 ldp X29, X30, [sp], #48
// (idloc intern)
 ldr X11, l0116
 ldr X10, [X23, X11, lsl #3]
 br X10
l0119:
 ldr X0, [sp, #16]
 ubfx X0, X0, #0, #56
 ldr X0, [X0]
 sbfx X0, X0, #0, #56
 str X0, [sp, #32]
 ldr X11, [sp, #24]
 cmp X0, X11
 b.le l0120
 mov X1, #1
 ldr X11, [sp, #24]
 add X1, X1, X11
 ldr X0, [sp, #16]
 ubfx X0, X0, #0, #56
 add X0, X0, #8
 ldrsb X0, [X0, X1]
 cbnz X0, l0120
 ldr X10, [sp, #24]
 add X10, X10, #1
 str X10, [sp, #24]
l0120:
 ldr X9, [sp, #24]
 ldr X10, [sp, #32]
 cmp X9, X10
 b.lt l0121
 ldr X0, [sp, #16]
 b l0122
l0121:
 ldr X2, [sp, #16]
 ubfx X2, X2, #0, #56
 ldr X2, [X2]
 sbfx X2, X2, #0, #56
 add X2, X2, #1
 mov X1, #1
 ldr X11, [sp, #24]
 add X1, X1, X11
 ldr X0, [sp, #16]
// (idloc subseq)
 ldr X11, l0117
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0122:
 ldp X29, X30, [sp], #48
// (idloc intern)
 ldr X11, l0116
 ldr X10, [X23, X11, lsl #3]
 br X10
l0117:
 .quad 348
l0116:
 .quad 347
l0115:
 .quad 346
 .quad 1
// (*entry intern expr 1)
 .globl intern
intern:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc unchecked-string-intern)
 ldr X11, l0123
 ldr X10, [X23, X11, lsl #3]
 br X10
l0123:
 .quad 350
l0136:
 .quad 7
 .byte 78,101,119,32,105,100,58,32,0,0,0,0
 .byte 0,0,0,0
 .quad 1
// (*entry unchecked-string-intern expr 1)
 .globl l0137
l0137:
 stp X29, X30, [sp, #-64]!
 mov X29, sp
 str X0, [sp, #16]
 mov X4, X28
 mov X3, X4
 mov X2, X4
 ubfx X1, X0, #0, #56
 ldr X1, [X1]
 sbfx X1, X1, #0, #56
 ubfx X0, X0, #0, #56
 str X0, [sp, #24]
 str X1, [sp, #32]
 str X2, [sp, #40]
 str X3, [sp, #48]
 str X4, [sp, #56]
 cbnz X1, l0138
 add X0, X0, #8
 ldrsb X0, [X0, X1]
 and X0, X0, #255
 mov X11, #254
 bfi X0, X11, #56, #8
 b l0139
l0138:
 ldr X0, [sp, #16]
// (idloc hash-into-table)
 ldr X11, l0124
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X1, X0
 str X1, [sp, #40]
// ($fluid hashtable)
 ldr X11, l0125
 ldr X0, [X24, X11, lsl #3]
 ldr W0, [X0, X1, lsl #2]
 mov X1, X0
 ldr X11, l0126
 cmp X0, X11
 b.lt l0140
 mov X0, X28
 b l0141
l0140:
 ldr X0, l0127
l0141:
 cmp X0, X28
 b.eq l0142
 ldr X0, l0127
 cmp X1, #0
 b.gt l0142
 add X0, X0, #140
l0142:
 cmp X0, X28
 b.eq l0143
 ldr X1, [sp, #40]
// ($fluid hashtable)
 ldr X11, l0125
 ldr X0, [X24, X11, lsl #3]
 ldr W0, [X0, X1, lsl #2]
 mov X11, #254
 bfi X0, X11, #56, #8
 b l0139
l0143:
// ($global show-new-ids)
 ldr X11, l0128
 ldr X11, [X24, X11, lsl #3]
 cmp X0, X11
 b.eq l0144
// ldr X0, l0129
 adr X0,l0136
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc console-print-string)
 ldr X11, l0130
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #16]
// (idloc console-print-string)
 ldr X11, l0130
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11, l0131
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0144:
// (idloc gtid)
 ldr X11, l0132
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #56]
 mov X2, X0
 ldr X1, [sp, #40]
// ($fluid hashtable)
 ldr X11, l0125
 ldr X0, [X24, X11, lsl #3]
 str W2, [X0, X1, lsl #2]
 ldr X0, [sp, #32]
// (idloc gtconststr)
 ldr X11, l0133
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #48]
 ldr X1, [sp, #24]
// (idloc copystringtofrom)
 ldr X11, l0134
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X1, [sp, #48]
 mov X11, #4
 bfi X1, X11, #56, #8
 ldr X0, [sp, #56]
 ldp X29, X30, [sp], #64
// (idloc initialize-new-id)
 ldr X11, l0135
 ldr X10, [X23, X11, lsl #3]
 br X10
l0139:
 ldp X29, X30, [sp], #64
 ret
l0135:
 .quad 354
l0134:
 .quad 353
l0133:
 .quad 352
l0132:
 .quad 351
l0131:
 .quad 326
l0130:
 .quad 325
// l0129:
//  .quad ((4<<56)+l0136)
l0128:
 .quad 345
l0127:
 .quad ((254<<56)+116)
l0126:
 .quad 4294967295
l0125:
 .quad 263
l0124:
 .quad 344
l0153:
 .quad 18
 .byte 72,97,115,104,32,116,97,98,108,101
 .byte 32,111,118,101,114,102,108,111,119
 .byte 0,0,0,0,0
 .quad 1
// (*entry hash-into-table expr 1)
 .globl l0154
l0154:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X28, [sp, #24]
 str X0, [sp, #16]
// (idloc hash-function)
 ldr X11, l0145
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #24]
 str X0, [sp, #32]
 movn X9, #0
 str X9, [sp, #40]
l0155:
 ldr X1, [sp, #32]
// ($fluid hashtable)
 ldr X11, l0146
 ldr X0, [X24, X11, lsl #3]
 ldr W0, [X0, X1, lsl #2]
 cbnz X0, l0156
 ldr X9, [sp, #40]
 movn X10, #0
 cmp X9, X10
 b.eq l0157
 ldr X0, [sp, #40]
 b l0158
l0157:
 ldr X0, [sp, #32]
l0158:
 b l0159
l0156:
 ldr X1, [sp, #32]
// ($fluid hashtable)
 ldr X11, l0146
 ldr X0, [X24, X11, lsl #3]
 ldr W0, [X0, X1, lsl #2]
 ldr X11, l0147
 cmp X0, X11
 b.ne l0160
 ldr X9, [sp, #40]
 movn X10, #0
 cmp X9, X10
 b.ne l0161
 ldr X9, [sp, #32]
 str X9, [sp, #40]
 b l0161
l0160:
 ldr X1, [sp, #32]
// ($fluid hashtable)
 ldr X11, l0146
 ldr X0, [X24, X11, lsl #3]
 ldr W0, [X0, X1, lsl #2]
 ldr X1, [sp, #16]
 lsl X0, X0, #3
// ($global symnam)
 ldr X11, l0148
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 ldr X0, [X0]
// (idloc unchecked-string-equal)
 ldr X11, l0149
 ldr X10, [X23, X11, lsl #3]
 blr X10
 cmp X0, X28
 b.eq l0161
 ldr X0, [sp, #32]
 b l0159
l0161:
 ldr X9, [sp, #32]
 ldr X10, l0150
 cmp X9, X10
 b.ne l0162
 mov X0, #0
 b l0163
l0162:
 mov X0, #1
 ldr X11, [sp, #32]
 add X0, X0, X11
l0163:
 str X0, [sp, #32]
 ldr X11, [sp, #24]
 cmp X0, X11
 b.ne l0155
// ldr X0, l0151
 adr X0,l0153
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc kernel-fatal-error)
 ldr X11, l0152
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0155
l0159:
 ldp X29, X30, [sp], #48
 ret
 nop
l0152:
 .quad 334
// l0151:
// .quad ((4<<56)+l0153)
l0150:
 .quad 393241
l0149:
 .quad 356
l0148:
 .quad 343
l0147:
 .quad 4294967295
l0146:
 .quad 263
l0145:
 .quad 355
 .quad 2
// (*entry initialize-new-id expr 2)
 .globl l0168
l0168:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 mov X11, #254
 bfi X0, X11, #56, #8
 str X0, [sp, #24]
 ldr X2, [sp, #16]
 lsl X2, X2, #3
// ($global symnam)
 ldr X11, l0164
 ldr X11, [X24, X11, lsl #3]
 add X2, X2, X11
 str X1, [X2]
 ldr X3, [sp, #16]
 lsl X3, X3, #3
// ($global symprp)
 ldr X11, l0165
 ldr X11, [X24, X11, lsl #3]
 add X3, X3, X11
 mov X4, X28
 str X4, [X3]
 ldr X0, [sp, #16]
 lsl X0, X0, #3
// ($global symget)
 ldr X11, l0166
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 str X4, [X0]
 ldr X0, [sp, #16]
 lsl X0, X0, #3
 add X0, X0, X24
 ldr X1, [sp, #16]
 mov X11, #253
 bfi X1, X11, #56, #8
 str X1, [X0]
 ldr X0, [sp, #16]
// (idloc plantunbound)
 ldr X11, l0167
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #24]
 ldp X29, X30, [sp], #32
 ret
 nop
l0167:
 .quad 359
l0166:
 .quad 358
l0165:
 .quad 357
l0164:
 .quad 343
 .quad 1
// (*entry hash-function expr 1)
 .globl l0172
l0172:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 ubfx X0, X0, #0, #56
 str X0, [sp, #24]
 ldr X0, [X0]
 sbfx X0, X0, #0, #56
 str X0, [sp, #16]
 mov X0, #0
 str X0, [sp, #32]
 ldr X11, [sp, #16]
 cmp X11, #20
 b.le l0173
 mov X9, #20
 str X9, [sp, #16]
l0173:
 ldr X1, [sp, #16]
 mov X0, #0
 mov X4, X0
 mov X3, X1
l0174:
 cmp X4, X3
 b.gt l0175
 mov X1, X4
 mov X0, #8
 ldr X11, [sp, #24]
 add X0, X0, X11
 ldrsb X0, [X0, X1]
 mov X2, #56
 subs X2, X2, X1
 b.ge l0169
 neg X10, X2
 lsr X0, X0, X10
 b l0170
l0169:
 lsl X0, X0, X2
l0170:
 ldr X10, [sp, #32]
 eor X0, X0, X10
 str X0, [sp, #32]
 add X4, X4, #1
 b l0174
l0175:
 ldr X1, l0171
 ldr X0, [sp, #32]
 ldp X29, X30, [sp], #48
 udiv X9, X0, X1
 msub X0, X9, X1, X0
 ret
l0171:
 .quad 393241
 .quad 1
// (*entry faslin expr 1)
 .globl faslin
faslin:
 stp X29, X30, [sp, #-112]!
 mov X29, sp
 str X28, [sp, #104]
 str X28, [sp, #80]
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X0, [sp, #16]
 str X28, [sp, #48]
 str X28, [sp, #64]
 str X28, [sp, #72]
 str X28, [sp, #96]
 str X28, [sp, #24]
 str X28, [sp, #56]
 str X28, [sp, #88]
// (idloc binaryopenread)
 ldr X11, l0176
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #32]
// (idloc binaryread)
 ldr X11, l0177
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #40]
 mov X1, #65535
 and X1, X1, X0
 mov X11, #399
 cmp X1, X11
 b.eq l0190
 ldr X0, [sp, #32]
// (idloc binaryclose)
 ldr X11, l0178
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #16]
// (idloc faslin-bad-file)
 ldr X11, l0179
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0191
l0190:
 ldr X0, [sp, #40]
 lsr X0, X0, #16
 str X0, [sp, #40]
 ldr X0, [sp, #32]
// (idloc read-id-table)
 ldr X11, l0180
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #48]
 ldr X0, [sp, #32]
// (idloc binaryread)
 ldr X11, l0177
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #64]
// (idloc gtbps)
 ldr X11, l0181
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #72]
 mov X0, #0
// (idloc gtbps)
 ldr X11, l0181
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #88]
 ldr X0, [sp, #32]
// (idloc binaryread)
 ldr X11, l0177
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X1, [sp, #72]
 add X1, X1, X0
 str X1, [sp, #96]
 ldr X2, [sp, #64]
 mov X1, #0
 ldr X11, [sp, #72]
 add X1, X1, X11
 ldr X0, [sp, #32]
// (idloc binaryreadblock)
 ldr X11, l0182
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #32]
// (idloc binaryread)
 ldr X11, l0177
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #24]
// (idloc gtwrds)
 ldr X11, l0183
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X1, X0
 mov X11, #7
 bfi X1, X11, #56, #8
 str X1, [sp, #56]
 ldr X2, [sp, #24]
 ubfx X1, X1, #0, #56
 add X1, X1, #8
 ldr X0, [sp, #32]
// (idloc binaryreadblock)
 ldr X11, l0182
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #32]
// (idloc binaryclose)
 ldr X11, l0178
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, #1
 ldr X10, [sp, #40]
 and X0, X0, X10
 cmp X0, #1
 b.ne l0192
 ldr X3, [sp, #48]
 ldr X2, [sp, #56]
 ldr X1, [sp, #64]
 ldr X0, [sp, #72]
// (idloc do-relocation-new)
 ldr X11, l0184
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0193
l0192:
 ldr X3, [sp, #48]
 ldr X2, [sp, #56]
 ldr X1, [sp, #64]
 ldr X0, [sp, #72]
// (idloc do-relocation)
 ldr X11, l0185
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0193:
 ldr X1, [sp, #64]
 lsl X1, X1, #3
 ldr X11, [sp, #72]
 add X1, X1, X11
 ldr X0, [sp, #72]
// (idloc clear_cache)
 ldr X11, l0186
 ldr X10, [X23, X11, lsl #3]
 blr X10
// ($fluid code-base-hack)
 ldr X11, l0187
 ldr X0, [X24, X11, lsl #3]
 str X0, [sp, #80]
 ldr X9, [sp, #72]
// ($fluid code-base-hack)
 ldr X11, l0187
 str X9, [X24, X11, lsl #3]
 ldr X0, [sp, #96]
// (idloc addressapply0)
 ldr X11, l0188
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X9, [sp, #80]
// ($fluid code-base-hack)
 ldr X11, l0187
 str X9, [X24, X11, lsl #3]
 ldr X1, [sp, #88]
 ldr X0, [sp, #96]
// (idloc delbps)
 ldr X11, l0189
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0191:
 mov X0, X28
 ldp X29, X30, [sp], #112
 ret
 nop
l0189:
 .quad 369
l0188:
 .quad 368
l0187:
 .quad 367
l0186:
 .quad 366
l0185:
 .quad 365
l0184:
 .quad 364
l0183:
 .quad 363
l0182:
 .quad 339
l0181:
 .quad 362
l0180:
 .quad 361
l0179:
 .quad 360
l0178:
 .quad 341
l0177:
 .quad 337
l0176:
 .quad 335
 .quad 2
// (*entry delbps expr 2)
 .globl delbps
delbps:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X0, X28
 ldp X29, X30, [sp], #16
 ret
 nop
 .quad 4
// (*entry do-relocation expr 4)
 .globl l0198
l0198:
 stp X29, X30, [sp, #-64]!
 mov X29, sp
 str X28, [sp, #48]
 str X0, [sp, #40]
 str X2, [sp, #24]
 str X3, [sp, #32]
 mov X0, X1
 lsl X0, X0, #3
 movn X1, #0
 add X1, X1, X0
 mov X0, #0
 str X0, [sp, #56]
 str X1, [sp, #16]
l0199:
 ldr X9, [sp, #56]
 ldr X10, [sp, #16]
 cmp X9, X10
 b.le l0200
 mov X0, X28
 b l0201
l0200:
 ldr X1, [sp, #56]
 ldr X0, [sp, #24]
 mov X11, #1
 bfi X0, X11, #56, #8
 add X0, X0, #4
// (idloc bittable)
 ldr X11, l0194
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X1, [sp, #40]
 ldr X11, [sp, #56]
 add X1, X1, X11
 str X1, [sp, #48]
 cmp X0, #1
 b.eq l0202
 cmp X0, #2
 b.eq l0203
 cmp X0, #3
 b.eq l0204
 b l0205
l0202:
 ldr X2, [sp, #32]
 ldr X1, [sp, #40]
 ldr X0, [sp, #48]
// (idloc relocate-word)
 ldr X11, l0195
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0205
l0204:
 ldr X2, [sp, #32]
 ldr X1, [sp, #40]
 ldr X0, [sp, #48]
// (idloc relocate-inf)
 ldr X11, l0196
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0205
l0203:
 ldr X2, [sp, #32]
 ldr X1, [sp, #40]
 ldr X0, [sp, #48]
// (idloc relocate-right-half)
 ldr X11, l0197
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0205:
 ldr X10, [sp, #56]
 add X10, X10, #1
 str X10, [sp, #56]
 b l0199
l0201:
 ldp X29, X30, [sp], #64
 ret
l0197:
 .quad 373
l0196:
 .quad 372
l0195:
 .quad 371
l0194:
 .quad 370
 .quad 4
// (*entry do-relocation-new expr 4)
 .globl l0209
l0209:
 stp X29, X30, [sp, #-64]!
 mov X29, sp
 str X28, [sp, #32]
 str X0, [sp, #48]
 str X2, [sp, #16]
 str X3, [sp, #40]
 mov X2, X28
 mov X1, X0
 mov X0, #0
 str X0, [sp, #24]
 str X1, [sp, #56]
 ldr X4, [sp, #16]
 ubfx X4, X4, #0, #56
 add X4, X4, #8
 str X4, [sp, #16]
l0210:
 ldr X1, [sp, #24]
 ldr X0, [sp, #16]
 ldrsb X0, [X0, X1]
 and X0, X0, #255
 str X0, [sp, #32]
 cbnz X0, l0211
 mov X0, X28
 b l0212
l0211:
 ldr X10, [sp, #24]
 add X10, X10, #1
 str X10, [sp, #24]
 mov X0, #63
 ldr X10, [sp, #32]
 and X0, X0, X10
 ldr X11, [sp, #56]
 add X0, X0, X11
 str X0, [sp, #56]
 ldr X1, [sp, #32]
 lsr X1, X1, #6
 str X1, [sp, #32]
 mov X0, X1
 cmp X0, #1
 b.eq l0213
 cmp X0, #2
 b.eq l0214
 cmp X0, #3
 b.eq l0215
 b l0210
l0213:
 ldr X2, [sp, #40]
 ldr X1, [sp, #48]
 ldr X0, [sp, #56]
// (idloc relocate-word)
 ldr X11, l0206
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0210
l0215:
 ldr X2, [sp, #40]
 ldr X1, [sp, #48]
 ldr X0, [sp, #56]
// (idloc relocate-inf)
 ldr X11, l0207
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0210
l0214:
 ldr X2, [sp, #40]
 ldr X1, [sp, #48]
 ldr X0, [sp, #56]
// (idloc relocate-right-half)
 ldr X11, l0208
 ldr X10, [X23, X11, lsl #3]
 blr X10
 b l0210
l0212:
 ldp X29, X30, [sp], #64
 ret
l0208:
 .quad 373
l0207:
 .quad 372
l0206:
 .quad 371
 .quad 3
// (*entry relocate-word expr 3)
 .globl l0217
l0217:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 str X1, [sp, #24]
 ldr X11, [X0]
 ubfx X1, X11, #0, #62
 ldr X11, [X0]
 ubfx X0, X11, #62, #2
 mov X3, X2
 ldr X2, [sp, #24]
// (idloc compute-relocation)
 ldr X11, l0216
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X10, [sp, #16]
 str X0, [X10]
 ldp X29, X30, [sp], #32
 ret
 nop
l0216:
 .quad 374
 .quad 3
// (*entry relocate-inf expr 3)
 .globl l0219
l0219:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 str X1, [sp, #24]
 ldr X11, [X0]
 ubfx X1, X11, #0, #22
 ldr X11, [X0]
 ubfx X0, X11, #54, #2
 mov X3, X2
 ldr X2, [sp, #24]
// (idloc compute-relocation)
 ldr X11, l0218
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X10, [sp, #16]
 ldr X12, [X10]
 bfi X12, X0, #0, #56
 str X12, [X10]
 ldp X29, X30, [sp], #32
 ret
 nop
l0218:
 .quad 374
 .quad 3
// (*entry relocate-right-half expr 3)
 .globl l0221
l0221:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 str X1, [sp, #24]
 ldr X11, [X0]
 ubfx X1, X11, #48, #14
 ldr X11, [X0]
 ubfx X0, X11, #62, #2
 mov X3, X2
 ldr X2, [sp, #24]
// (idloc compute-relocation)
 ldr X11, l0220
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X10, [sp, #16]
 ldr X12, [X10]
 bfi X12, X0, #48, #16
 str X12, [X10]
 ldp X29, X30, [sp], #32
 ret
 nop
l0220:
 .quad 374
 .quad 4
// (*entry compute-relocation expr 4)
 .globl l0224
l0224:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X1, [sp, #16]
 cbnz X0, l0225
 mov X0, X2
 add X0, X0, X1
 b l0226
l0225:
 cmp X0, #2
 b.ne l0227
 mov X11, #65510
 cmp X1, X11
 b.lt l0228
 movn X0, #65515
 add X0, X0, X1
 lsl X0, X0, #3
// ($fluid argumentblock)
 ldr X11, l0222
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 b l0226
l0228:
 cmp X1, #2048
 b.lt l0229
 mov X1, X3
 ldr X0, [sp, #16]
// (idloc local-to-global-id)
 ldr X11, l0223
 ldr X10, [X23, X11, lsl #3]
 blr X10
 lsl X0, X0, #3
 add X0, X0, X24
 b l0226
l0229:
 mov X0, X1
 lsl X0, X0, #3
 add X0, X0, X24
 b l0226
l0227:
 cmp X0, #3
 b.ne l0230
 cmp X1, #2048
 b.lt l0231
 mov X1, X3
 ldr X0, [sp, #16]
// (idloc local-to-global-id)
 ldr X11, l0223
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #16]
l0231:
 ldr X0, [sp, #16]
 lsl X0, X0, #3
 add X0, X0, X23
 b l0226
l0230:
 cmp X0, #1
 b.ne l0232
 cmp X1, #2048
 b.lt l0233
 mov X1, X3
 ldr X0, [sp, #16]
 ldp X29, X30, [sp], #32
// (idloc local-to-global-id)
 ldr X11, l0223
 ldr X10, [X23, X11, lsl #3]
 br X10
l0233:
 mov X0, X1
 b l0226
l0232:
 mov X0, X28
l0226:
 ldp X29, X30, [sp], #32
 ret
 nop
l0223:
 .quad 375
l0222:
 .quad 259
 .quad 2
// (*entry local-to-global-id expr 2)
 .globl l0234
l0234:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X11, #2047
 sub X0, X0, X11
 lsl X0, X0, #3
 ubfx X2, X1, #0, #56
 add X0, X0, X2
 ldr X0, [X0]
 ldp X29, X30, [sp], #16
 ret
 .quad 1
// (*entry read-id-table expr 1)
 .globl l0240
l0240:
 stp X29, X30, [sp, #-64]!
 mov X29, sp
 str X28, [sp, #56]
 str X28, [sp, #48]
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X28, [sp, #24]
 str X0, [sp, #16]
// (idloc binaryread)
 ldr X11, l0235
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #24]
 add X0, X0, #1
// (idloc gtwrds)
 ldr X11, l0236
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X11, #7
 bfi X0, X11, #56, #8
 str X0, [sp, #32]
 ldr X1, [sp, #24]
 mov X0, #0
 str X0, [sp, #40]
 str X1, [sp, #48]
l0241:
 ldr X9, [sp, #40]
 ldr X10, [sp, #48]
 cmp X9, X10
 b.gt l0242
 ldr X0, [sp, #16]
// (idloc binaryread)
 ldr X11, l0235
 ldr X10, [X23, X11, lsl #3]
 blr X10
// ($fluid tokenbuffer)
 ldr X11, l0237
 ldr X11, [X24, X11, lsl #3]
 str X0, [X11]
 mov X2, #9
 add X2, X2, X0
 mov X1, X2
 lsr X1, X1, #61
 add X2, X2, X1
 asr X2, X2, #3
 mov X1, #8
// ($fluid tokenbuffer)
 ldr X11, l0237
 ldr X11, [X24, X11, lsl #3]
 add X1, X1, X11
 ldr X0, [sp, #16]
// (idloc binaryreadblock)
 ldr X11, l0238
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, #0
// ($fluid tokenbuffer)
 ldr X11, l0237
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc faslin-intern)
 ldr X11, l0239
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #56]
 mov X0, #1
 ldr X11, [sp, #40]
 add X0, X0, X11
 lsl X0, X0, #3
 ldr X1, [sp, #32]
 ubfx X1, X1, #0, #56
 add X0, X0, X1
 ldr X2, [sp, #56]
 ubfx X2, X2, #0, #56
 str X2, [X0]
 ldr X10, [sp, #40]
 add X10, X10, #1
 str X10, [sp, #40]
 b l0241
l0242:
 ldr X0, [sp, #32]
 ldp X29, X30, [sp], #64
 ret
 nop
l0239:
 .quad 349
l0238:
 .quad 339
l0237:
 .quad 260
l0236:
 .quad 363
l0235:
 .quad 337
 .quad 3
// (*entry putentry expr 3)
 .globl putentry
putentry:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ($fluid code-base-hack)
 ldr X11, l0243
 ldr X11, [X24, X11, lsl #3]
 add X2, X2, X11
 mov X11, #20
 bfi X2, X11, #56, #8
 ldp X29, X30, [sp], #16
// (idloc putd)
 ldr X11, l0244
 ldr X10, [X23, X11, lsl #3]
 br X10
 nop
l0244:
 .quad 376
l0243:
 .quad 367
l0248:
 .quad 22
 .byte 70,105,108,101,32,105,115,32,110,111
 .byte 116,32,70,65,83,76,32,102,111,114,109
 .byte 97,116,0
 .quad 1
// (*entry faslin-bad-file expr 1)
 .globl l0249
l0249:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ldr X0, l0245
 adr X0,l0248
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc console-print-string)
 ldr X11, l0246
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldp X29, X30, [sp], #16
// (idloc console-newline)
 ldr X11, l0247
 ldr X10, [X23, X11, lsl #3]
 br X10
l0247:
 .quad 326
l0246:
 .quad 325
// l0245:
//  .quad ((4<<56)+l0248)
l0258:
 .quad 30
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,98,105,110,97,114,121,32,112,114
 .byte 111,103,114,97,109,32,115,112,97,99
 .byte 101,0
 .quad 1
// (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
l0259:
 str X0, [sp, #16]
 cmp X0, X28
 b.ne l0260
// (idloc gtbps-nil-error)
 ldr X11, l0250
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0260:
 ldr X11, [sp, #16]
 cmp X11, #10
 b.le l0261
 mov X0, #15
// ($global nextbps)
 ldr X11, l0251
 ldr X10, [X24, X11, lsl #3]
 and X0, X0, X10
 cbz X0, l0261
// ($global nextbps)
 ldr X11, l0251
 ldr X1, [X24, X11, lsl #3]
 lsr X1, X1, #4
 lsl X1, X1, #4
 add X1, X1, #16
// ($global nextbps)
 ldr X11, l0251
 str X1, [X24, X11, lsl #3]
l0261:
// ($global nextbps)
 ldr X11, l0251
 ldr X0, [X24, X11, lsl #3]
 ldr X1, [sp, #16]
 lsl X1, X1, #3
// ($global nextbps)
 ldr X11, l0251
 ldr X11, [X24, X11, lsl #3]
 add X1, X1, X11
// ($global nextbps)
 ldr X11, l0251
 str X1, [X24, X11, lsl #3]
// ($global lastbps)
 ldr X11, l0252
 ldr X11, [X24, X11, lsl #3]
 cmp X1, X11
 b.le l0262
// ($global nextbps)
 ldr X11, l0251
 str X0, [X24, X11, lsl #3]
 ldr X0, l0253
// (idloc getd)
 ldr X11, l0254
 ldr X10, [X23, X11, lsl #3]
 blr X10
 cmp X0, X28
 b.eq l0263
 ldr X0, [sp, #16]
// (idloc try-other-bps-spaces)
 ldr X11, l0255
 ldr X10, [X23, X11, lsl #3]
 blr X10
 cmp X0, X28
 b.eq l0263
 ldr X0, [sp, #16]
 b l0259
l0263:
// ldr X0, l0256
 adr X0,l0258
 mov X11, #4
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #32
// (idloc stderror)
 ldr X11, l0257
 ldr X10, [X23, X11, lsl #3]
 br X10
l0262:
 ldp X29, X30, [sp], #32
 ret
l0257:
 .quad 381
// l0256:
//  .quad ((4<<56)+l0258)
l0255:
 .quad 380
l0254:
 .quad 379
l0253:
 .quad ((254<<56)+380)
l0252:
 .quad 284
l0251:
 .quad 287
l0250:
 .quad 378
l0266:
 .quad 21
 .byte 71,84,66,80,83,32,99,97,108,108,101
 .byte 100,32,119,105,116,104,32,78,73,76
 .byte 46,0,0
 .quad 1
// (*entry gtbps-nil-error expr 1)
 .globl l0267
l0267:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ldr X0, l0264
 adr X0,l0266
 mov X11, #4
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #16
// (idloc stderror)
 ldr X11, l0265
 ldr X10, [X23, X11, lsl #3]
 br X10
 nop
l0265:
 .quad 381
// l0264:
//  .quad ((4<<56)+l0266)
 .quad 1
// (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 cmp X0, X28
 b.ne l0270
 ldp X29, X30, [sp], #16
// (idloc known-free-space)
 ldr X11, l0268
 ldr X10, [X23, X11, lsl #3]
 br X10
l0270:
 ldp X29, X30, [sp], #16
// (idloc real-gtheap)
 ldr X11, l0269
 ldr X10, [X23, X11, lsl #3]
 br X10
l0269:
 .quad 383
l0268:
 .quad 382
 .quad 1
// (*entry real-gtheap expr 1)
 .globl l0272
l0272:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X2, X0
 mov X0, X21
 mov X1, X2
 lsl X1, X1, #3
 add X1, X1, X21
 mov X21, X1
 cmp X1, X22
 b.lt l0273
 mov X1, X2
 ldp X29, X30, [sp], #16
// (idloc get-heap-trap)
 ldr X11, l0271
 ldr X10, [X23, X11, lsl #3]
 br X10
l0273:
 ldp X29, X30, [sp], #16
 ret
 nop
l0271:
 .quad 385
l0276:
 .quad 27
 .byte 71,97,114,98,97,103,101,32,99,111,108
 .byte 108,101,99,116,105,111,110,32,114,101
 .byte 113,117,105,114,101,100,46,0,0,0,0
 .quad 2
// (*entry get-heap-trap expr 2)
 .globl l0277
l0277:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
// ldr X0, l0274
 adr X0,l0276
 mov X11, #4
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #16
// (idloc kernel-fatal-error)
 ldr X11, l0275
 ldr X10, [X23, X11, lsl #3]
 br X10
 nop
l0275:
 .quad 334
// l0274:
//  .quad ((4<<56)+l0276)
l0283:
 .quad 18
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,73,68,32,115,112,97,99,101,0,0,0
 .byte 0,0
 .quad 0
// (*entry gtid expr 0)
 .globl gtid
gtid:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X9, #0
// ($global nextsymbol)
 ldr X11, l0278
 ldr X10, [X24, X11, lsl #3]
 cmp X9, X10
 b.ne l0284
// (idloc reclaim)
 ldr X11, l0279
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X9, #0
// ($global nextsymbol)
 ldr X11, l0278
 ldr X10, [X24, X11, lsl #3]
 cmp X9, X10
 b.ne l0284
// ldr X0, l0280
 adr X0,l0283
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc kernel-fatal-error)
 ldr X11, l0281
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0284:
// ($global nextsymbol)
 ldr X11, l0278
 ldr X0, [X24, X11, lsl #3]
 mov X1, X0
 lsl X1, X1, #3
// ($global symnam)
 ldr X11, l0282
 ldr X11, [X24, X11, lsl #3]
 add X1, X1, X11
 ldr X9, [X1]
// ($global nextsymbol)
 ldr X11, l0278
 str X9, [X24, X11, lsl #3]
 ldp X29, X30, [sp], #16
 ret
 nop
l0282:
 .quad 343
l0281:
 .quad 334
// l0280:
//  .quad ((4<<56)+l0283)
l0279:
 .quad 386
l0278:
 .quad 342
 .quad 1
// (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X0, [sp, #16]
 add X0, X0, #2
// (idloc gtheap)
 ldr X11, l0285
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X1, [sp, #16]
 mov X11, #249
 bfi X1, X11, #56, #8
 str X1, [X0]
 ldp X29, X30, [sp], #32
 ret
l0285:
 .quad 384
 .quad 1
// (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 add X0, X0, #9
 mov X1, X0
 lsr X1, X1, #61
 add X0, X0, X1
 asr X0, X0, #3
 str X0, [sp, #24]
 add X0, X0, #1
// (idloc gtbps)
 ldr X11, l0286
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X9, [sp, #16]
 str X9, [X0]
 ldr X1, [sp, #24]
 lsl X1, X1, #3
 add X1, X1, X0
 mov X9, #0
 str X9, [X1]
 ldp X29, X30, [sp], #32
 ret
l0286:
 .quad 362
l0290:
 .quad 30
 .byte 83,85,66,83,69,81,32,99,97,108,108
 .byte 101,100,32,119,105,116,104,32,97,32
 .byte 110,111,110,45,115,116,114,105,110
 .byte 103,0
 .quad 3
// (*entry subseq expr 3)
 .globl subseq
subseq:
 stp X29, X30, [sp, #-64]!
 mov X29, sp
 str X28, [sp, #56]
 str X28, [sp, #48]
 str X28, [sp, #40]
 str X0, [sp, #16]
 str X1, [sp, #24]
 str X2, [sp, #32]
 ubfx X11, X0, #56, #8
 cmp X11, #4
 b.eq l0291
// ldr X0, l0287
 adr X0,l0290
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc kernel-fatal-error)
 ldr X11, l0288
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0291:
 movn X0, #0
 ldr X11, [sp, #32]
 add X0, X0, X11
 ldr X11, [sp, #24]
 sub X0, X0, X11
 str X0, [sp, #40]
 ldr X0, [sp, #16]
 ubfx X0, X0, #0, #56
 str X0, [sp, #48]
 ldr X0, [sp, #40]
// (idloc gtstr)
 ldr X11, l0289
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #56]
 ldr X1, [sp, #40]
 mov X0, #0
 mov X4, X0
 mov X3, X1
l0292:
 cmp X4, X3
 b.gt l0293
 ldr X1, [sp, #24]
 add X1, X1, X4
 mov X0, #8
 ldr X11, [sp, #48]
 add X0, X0, X11
 ldrsb X0, [X0, X1]
 mov X2, X0
 mov X1, X4
 mov X0, #8
 ldr X11, [sp, #56]
 add X0, X0, X11
 strb W2, [X0, X1]
 add X4, X4, #1
 b l0292
l0293:
 ldr X0, [sp, #56]
 mov X11, #4
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #64
 ret
l0289:
 .quad 387
l0288:
 .quad 334
// l0287:
//  .quad ((4<<56)+l0290)
 .quad 2
// (*entry search-string-for-character expr 2)
 .globl l0294
l0294:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X0, [sp, #16]
 mov X4, X1
 ubfx X1, X1, #0, #56
 ldr X1, [X1]
 sbfx X1, X1, #0, #56
 mov X0, #0
 mov X3, X0
 mov X2, X1
l0295:
 cmp X3, X2
 b.le l0296
 mov X0, X28
 b l0297
l0296:
 mov X1, X3
 ubfx X0, X4, #0, #56
 add X0, X0, #8
 ldrsb X0, [X0, X1]
 ldr X11, [sp, #16]
 cmp X11, X0
 b.ne l0298
 mov X0, X1
 b l0297
l0298:
 add X3, X3, #1
 b l0295
l0297:
 ldp X29, X30, [sp], #32
 ret
 .quad 2
// (*entry unchecked-string-equal expr 2)
 .globl l0300
l0300:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X28, [sp, #32]
 ubfx X0, X0, #0, #56
 str X0, [sp, #16]
 ubfx X1, X1, #0, #56
 str X1, [sp, #24]
 ldr X2, [X0]
 sbfx X2, X2, #0, #56
 mov X4, X2
 ldr X3, [X1]
 sbfx X3, X3, #0, #56
 cmp X2, X3
 b.eq l0301
 mov X0, X28
 b l0302
l0301:
 mov X9, #0
 str X9, [sp, #32]
l0303:
 ldr X11, [sp, #32]
 cmp X11, X4
 b.le l0304
 ldr X0, l0299
 b l0302
l0304:
 ldr X1, [sp, #32]
 mov X0, #8
 ldr X11, [sp, #16]
 add X0, X0, X11
 ldrsb X0, [X0, X1]
 mov X2, X0
 mov X0, #8
 ldr X11, [sp, #24]
 add X0, X0, X11
 ldrsb X0, [X0, X1]
 cmp X2, X0
 b.eq l0305
 mov X0, X28
 b l0302
l0305:
 ldr X10, [sp, #32]
 add X10, X10, #1
 str X10, [sp, #32]
 b l0303
l0302:
 ldp X29, X30, [sp], #48
 ret
l0299:
 .quad ((254<<56)+116)
 .quad 2
// (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X0, [sp, #40]
 ubfx X2, X0, #0, #56
 str X2, [sp, #24]
 ubfx X3, X1, #0, #56
 str X3, [sp, #32]
 ldr X4, [X3]
 sbfx X4, X4, #0, #56
 str X4, [sp, #16]
 ldr X0, [X2]
 sbfx X0, X0, #0, #56
 cmp X0, X4
 b.ge l0306
 str X0, [sp, #16]
l0306:
 mov X0, #9
 ldr X11, [sp, #16]
 add X0, X0, X11
 mov X1, X0
 lsr X1, X1, #61
 add X0, X0, X1
 asr X0, X0, #3
 sub X0, X0, #1
 str X0, [sp, #16]
 mov X1, X0
 mov X0, #0
 mov X3, X0
 mov X2, X1
l0307:
 cmp X3, X2
 b.gt l0308
 mov X0, #1
 add X0, X0, X3
 lsl X0, X0, #3
 ldr X11, [sp, #24]
 add X0, X0, X11
 mov X1, #1
 add X1, X1, X3
 lsl X1, X1, #3
 ldr X11, [sp, #32]
 add X1, X1, X11
 ldr X9, [X1]
 str X9, [X0]
 add X3, X3, #1
 b l0307
l0308:
 ldr X0, [sp, #40]
 ldp X29, X30, [sp], #48
 ret
 nop
 .quad 2
// (*entry cons expr 2)
 .globl cons
cons:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X0, [sp, #16]
 str X1, [sp, #24]
 mov X0, #2
// (idloc gtheap)
 ldr X11, l0309
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X9, [sp, #16]
 str X9, [X0]
 ldr X9, [sp, #24]
 str X9, [X0, #8]
 mov X11, #9
 bfi X0, X11, #56, #8
 ldp X29, X30, [sp], #32
 ret
l0309:
 .quad 384
 .quad 1
// (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 lsl X0, X0, #3
 add X0, X0, X24
 ldr X0, [X0]
 ldp X29, X30, [sp], #16
 ret
 nop
 .quad 2
// (*entry modify expr 2)
 .globl modify
modify:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 lsl X0, X0, #3
 add X0, X0, X24
 str X1, [X0]
 mov X0, X1
 ldp X29, X30, [sp], #16
 ret
 .quad 3
// (*entry put expr 3)
 .globl put
put:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc unchecked-put)
 ldr X11, l0310
 ldr X10, [X23, X11, lsl #3]
 br X10
l0310:
 .quad 391
 .quad 3
// (*entry unchecked-put expr 3)
 .globl l0315
l0315:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X0, [sp, #16]
 str X1, [sp, #24]
 str X2, [sp, #32]
// (idloc unchecked-prop)
 ldr X11, l0311
 ldr X10, [X23, X11, lsl #3]
 blr X10
 str X0, [sp, #40]
 mov X1, X0
 ldr X0, [sp, #24]
// (idloc atsoc)
 ldr X11, l0312
 ldr X10, [X23, X11, lsl #3]
 blr X10
 cmp X0, X28
 b.eq l0316
 ubfx X10, X0, #0, #56
 ldr X9, [sp, #32]
 str X9, [X10, #8]
 b l0317
l0316:
 ldr X1, [sp, #32]
 ldr X0, [sp, #24]
 str X0, [X21]
 mov X0, #9
 lsl X0, X0, #56
 add X0, X0, X21
 str X1, [X21, #8]
 add X21, X21, #16
 cmp X21, X22
 b.lt l0318
 stp X0, X1, [sp, #16]!
// (idloc !%reclaim)
 ldr X11, l0313
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldp X0, X1, [sp], #16
l0318:
 ldr X1, [sp, #40]
 str X0, [X21]
 mov X0, #9
 lsl X0, X0, #56
 add X0, X0, X21
 str X1, [X21, #8]
 add X21, X21, #16
 cmp X21, X22
 b.lt l0319
 stp X0, X1, [sp, #16]!
// (idloc !%reclaim)
 ldr X11, l0313
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldp X0, X1, [sp], #16
l0319:
 mov X1, X0
 ldr X0, [sp, #16]
// (idloc unchecked-setprop)
 ldr X11, l0314
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0317:
 ldr X0, [sp, #32]
 ldp X29, X30, [sp], #48
 ret
l0314:
 .quad 396
l0313:
 .quad 395
l0312:
 .quad 394
l0311:
 .quad 393
 .quad 2
// (*entry atsoc expr 2)
 .globl atsoc
atsoc:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
l0320:
 ubfx X11, X1, #56, #8
 cmp X11, #9
 b.eq l0321
 mov X0, X28
 ldp X29, X30, [sp], #16
 ret
l0321:
 ubfx X9, X1, #0, #56
 ldr X11, [X9]
 ubfx X11, X11, #56, #8
 cmp X11, #9
 b.ne l0322
 ubfx X10, X1, #0, #56
 ldr X10, [X10]
 ubfx X10, X10, #0, #56
 ldr X11, [X10]
 cmp X0, X11
 b.ne l0322
 ubfx X0, X1, #0, #56
 ldr X0, [X0]
 ldp X29, X30, [sp], #16
 ret
l0322:
 ubfx X1, X1, #0, #56
 ldr X1, [X1, #8]
 b l0320
 .quad 2
// (*entry unchecked-setprop expr 2)
 .globl l0324
l0324:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ubfx X0, X0, #0, #56
 lsl X0, X0, #3
// ($global symprp)
 ldr X11, l0323
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 str X1, [X0]
 mov X0, X1
 ldp X29, X30, [sp], #16
 ret
 nop
l0323:
 .quad 357
 .quad 1
// (*entry unchecked-prop expr 1)
 .globl l0326
l0326:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ubfx X0, X0, #0, #56
 lsl X0, X0, #3
// ($global symprp)
 ldr X11, l0325
 ldr X11, [X24, X11, lsl #3]
 add X0, X0, X11
 ldr X0, [X0]
 ldp X29, X30, [sp], #16
 ret
l0325:
 .quad 357
 .quad 3
// (*entry putd expr 3)
 .globl putd
putd:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc code-putd)
 ldr X11, l0327
 ldr X10, [X23, X11, lsl #3]
 br X10
l0327:
 .quad 397
l0334:
 .quad 26
 .byte 66,97,100,32,112,97,114,97,109,101
 .byte 116,101,114,115,32,116,111,32,67,79
 .byte 68,69,45,80,85,84,68,0,0,0,0,0
 .quad 3
// (*entry code-putd expr 3)
 .globl l0335
l0335:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X0, [sp, #16]
 str X1, [sp, #24]
 str X2, [sp, #32]
 ubfx X11, X0, #56, #8
 cmp X11, #254
 b.ne l0336
 ubfx X11, X1, #56, #8
 cmp X11, #254
 b.ne l0336
 ubfx X11, X2, #56, #8
 cmp X11, #20
 b.eq l0337
l0336:
// ldr X0, l0328
 adr X0,l0334
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc kernel-fatal-error)
 ldr X11, l0329
 ldr X10, [X23, X11, lsl #3]
 blr X10
l0337:
 ldr X1, [sp, #32]
 ubfx X1, X1, #0, #56
 ldr X0, [sp, #16]
 ubfx X0, X0, #0, #56
// (idloc plantcodepointer)
 ldr X11, l0330
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X9, [sp, #24]
 ldr X10, l0331
 cmp X9, X10
 b.eq l0338
 ldr X2, [sp, #24]
 ldr X1, l0332
 ldr X0, [sp, #16]
 ldp X29, X30, [sp], #48
// (idloc put)
 ldr X11, l0333
 ldr X10, [X23, X11, lsl #3]
 br X10
l0338:
 mov X0, X28
 ldp X29, X30, [sp], #48
 ret
l0333:
 .quad 392
l0332:
 .quad ((254<<56)+399)
l0331:
 .quad ((254<<56)+400)
l0330:
 .quad 398
l0329:
 .quad 334
// l0328:
//  .quad ((4<<56)+l0334)
 .quad 1
// (*entry fluid expr 1)
 .globl fluid
fluid:
 stp X29, X30, [sp, #-48]!
 mov X29, sp
 str X28, [sp, #40]
 str X28, [sp, #32]
 str X0, [sp, #16]
 mov X0, X28
 ldr X9, [sp, #16]
 str X9, [sp, #24]
 mov X11, X9
 ubfx X11, X11, #56, #8
 cmp X11, #9
 b.ne l0340
 ldr X0, [sp, #24]
 ubfx X0, X0, #0, #56
 ldr X0, [X0]
 b l0341
l0340:
 mov X0, X28
l0341:
 str X0, [sp, #32]
l0342:
 ldr X11, [sp, #24]
 ubfx X11, X11, #56, #8
 cmp X11, #9
 b.eq l0343
 mov X0, X28
 b l0344
l0343:
 ldr X0, [sp, #32]
// (idloc fluid1)
 ldr X11, l0339
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #24]
 ubfx X0, X0, #0, #56
 ldr X0, [X0, #8]
 str X0, [sp, #24]
 ubfx X11, X0, #56, #8
 cmp X11, #9
 b.ne l0345
 ubfx X0, X0, #0, #56
 ldr X0, [X0]
 b l0346
l0345:
 mov X0, X28
l0346:
 str X0, [sp, #32]
 b l0342
l0344:
 ldp X29, X30, [sp], #48
 ret
 nop
l0339:
 .quad 401
 .quad 1
// (*entry fluid1 expr 1)
 .globl l0350
l0350:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldr X2, l0347
 ldr X1, l0348
 ldp X29, X30, [sp], #16
// (idloc put)
 ldr X11, l0349
 ldr X10, [X23, X11, lsl #3]
 br X10
l0349:
 .quad 392
l0348:
 .quad ((254<<56)+403)
l0347:
 .quad ((254<<56)+402)
 .quad 1
// (*entry stderror expr 1)
 .globl stderror
stderror:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
// (idloc kernel-fatal-error)
 ldr X11, l0351
 ldr X10, [X23, X11, lsl #3]
 br X10
l0351:
 .quad 334
 .quad 2
// (*entry *define-constant expr 2)
 .globl l0355
l0355:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ubfx X2, X0, #0, #56
 lsl X2, X2, #3
 add X2, X2, X24
 str X1, [X2]
 ldr X2, l0352
 ldr X1, l0353
 ldp X29, X30, [sp], #16
// (idloc put)
 ldr X11, l0354
 ldr X10, [X23, X11, lsl #3]
 br X10
l0354:
 .quad 392
l0353:
 .quad ((254<<56)+405)
l0352:
 .quad ((254<<56)+116)
 .quad 1
// (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 adr X9, undefinedfunction
 str X9, [X23, X0, lsl #3]
 ldp X29, X30, [sp], #16
 ret
 .quad 0
 .quad 2
// (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 str X1, [X23, X0, lsl #3]
 ldp X29, X30, [sp], #16
 ret
 nop
 .quad 1
// (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 adr X9, compiledcallinginterpreted
 str X9, [X23, X0, lsl #3]
 ldp X29, X30, [sp], #16
 ret
 .quad 0
 .quad 1
// (*entry addressapply0 expr 1)
 .globl l0358
l0358:
 br X0
 nop
 .quad 2
// (*entry bittable expr 2)
 .globl bittable
bittable:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X3, X1
 lsr X1, X1, #2
 ldrsb X0, [X0, X1]
 ubfx X2, X3, #32, #2
 lsl X2, X2, #1
 subs X2, X2, #6
 b.ge l0359
 neg X10, X2
 lsr X0, X0, X10
 b l0360
l0359:
 lsl X0, X0, X2
l0360:
 ubfx X0, X0, #32, #2
 ldp X29, X30, [sp], #16
 ret
 .quad 1
// (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X9, X11
// (idloc undefinedfunction-aux)
 ldr X11, l0361
 ldr X10, [X23, X11, lsl #3]
 br X10
l0361:
 .quad 407
l0367:
 .quad 26
 .byte 85,110,100,101,102,105,110,101,100
 .byte 32,102,117,110,99,116,105,111,110,32
 .byte 99,97,108,108,101,100,58,32,0,0,0,0
 .byte 0
 .quad 1
// (*entry undefinedfunction-aux expr 1)
 .globl l0368
l0368:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X9, [sp, #16]
// ldr X0, l0362
 adr X0,l0367
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc console-print-string)
 ldr X11, l0363
 ldr X10, [X23, X11, lsl #3]
 blr X10
// ($fluid symnam)
 ldr X11, l0364
 ldr X10, [X24, X11, lsl #3]
 ldr X9, [sp, #16]
 ldr X0, [X10, X9, lsl #3]
// (idloc console-print-string)
 ldr X11, l0363
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11, l0365
 ldr X10, [X23, X11, lsl #3]
 blr X10
 mov X0, #0
// (idloc exit-with-status)
 ldr X11, l0366
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldp X29, X30, [sp], #32
 ret
l0366:
 .quad 310
l0365:
 .quad 326
l0364:
 .quad 343
l0363:
 .quad 325
// l0362:
//  .quad ((4<<56)+l0367)
 .quad 0
// (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 mov X9, X11
 mov X11, #254
 bfi X9, X11, #56, #8
// ($fluid codeform*)
 ldr X11, l0369
 str X9, [X24, X11, lsl #3]
// (idloc compiledcallinginterpretedaux)
 ldr X11, l0370
 ldr X10, [X23, X11, lsl #3]
 br X10
l0370:
 .quad 410
l0369:
 .quad 409
l0375:
 .quad 12
 .byte 70,65,84,65,76,32,69,82,82,79,82,58
 .byte 32,0,0,0
 .quad 1
// (*entry kernel-fatal-error expr 1)
 .globl l0376
l0376:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 str X0, [sp, #16]
// ldr X0, l0371
 adr X0,l0375
 mov X11, #4
 bfi X0, X11, #56, #8
// (idloc console-print-string)
 ldr X11, l0372
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ldr X0, [sp, #16]
// (idloc console-print-string)
 ldr X11, l0372
 ldr X10, [X23, X11, lsl #3]
 blr X10
// (idloc console-newline)
 ldr X11, l0373
 ldr X10, [X23, X11, lsl #3]
 blr X10
 movn X0, #0
 ldp X29, X30, [sp], #32
// (idloc exit-with-status)
 ldr X11, l0374
 ldr X10, [X23, X11, lsl #3]
 br X10
l0374:
 .quad 310
l0373:
 .quad 326
l0372:
 .quad 325
// l0371:
//  .quad ((4<<56)+l0375)
 .quad 0
// (*entry echoon expr 0)
 .globl l0377
l0377:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _echoon
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry echooff expr 0)
 .globl l0378
l0378:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _echooff
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_charsininputbuffer expr 1)
 .globl l0379
l0379:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_charsininputbuffer
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry flushstdoutputbuffer expr 0)
 .globl l0380
l0380:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _flushstdoutputbuffer
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry external_user_homedir_string expr 0)
 .globl l0381
l0381:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_user_homedir_string
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_anyuser_homedir_string expr 1)
 .globl l0382
l0382:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_anyuser_homedir_string
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry alterheapsize expr 1)
 .globl l0383
l0383:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _alterheapsize
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry allocatemorebps expr 1)
 .globl l0384
l0384:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _allocatemorebps
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry get_imagefilepath expr 0)
 .globl l0385
l0385:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _get_imagefilepath
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry get_file_status expr 3)
 .globl l0386
l0386:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _get_file_status
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry os_startup_hook expr 2)
 .globl l0387
l0387:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _os_startup_hook
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry os_cleanup_hook expr 0)
 .globl l0388
l0388:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _os_cleanup_hook
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry get_execfilepath expr 0)
 .globl l0389
l0389:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _get_execfilepath
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry clear_cache expr 2)
 .globl l0390
l0390:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _clear_cache
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry wxquotientdouble expr 4)
 .globl l0394
l0394:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _wxquotientdouble
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_alarm expr 1)
 .globl l0395
l0395:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_alarm
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry external_ualarm expr 2)
 .globl l0396
l0396:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_ualarm
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_time expr 1)
 .globl l0397
l0397:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_time
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_timc expr 1)
 .globl l0398
l0398:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_timc
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry external_stat expr 2)
 .globl l0399
l0399:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_stat
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry external_link expr 2)
 .globl l0400
l0400:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_link
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_unlink expr 1)
 .globl l0401
l0401:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_unlink
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_rmdir expr 1)
 .globl l0402
l0402:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_rmdir
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry external_mkdir expr 2)
 .globl l0403
l0403:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_mkdir
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_strlen expr 1)
 .globl l0404
l0404:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_strlen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry external_setenv expr 2)
 .globl l0405
l0405:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_setenv
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_getenv expr 1)
 .globl l0406
l0406:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_getenv
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxfloat expr 2)
 .globl l0407
l0407:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxfloat
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry uxfix expr 1)
 .globl l0408
l0408:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxfix
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxassign expr 2)
 .globl l0409
l0409:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxassign
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxminus expr 2)
 .globl l0410
l0410:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxminus
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxplus2 expr 3)
 .globl l0411
l0411:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxplus2
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxdifference expr 3)
 .globl l0412
l0412:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxdifference
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxtimes2 expr 3)
 .globl l0413
l0413:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxtimes2
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxquotient expr 3)
 .globl l0414
l0414:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxquotient
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry uxgreaterp expr 4)
 .globl l0415
l0415:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxgreaterp
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry uxlessp expr 4)
 .globl l0416
l0416:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxlessp
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxwritefloat expr 3)
 .globl l0417
l0417:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxwritefloat
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxdoubletofloat expr 2)
 .globl l0418
l0418:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxdoubletofloat
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxfloattodouble expr 2)
 .globl l0419
l0419:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxfloattodouble
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxsin expr 2)
 .globl l0420
l0420:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxsin
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxcos expr 2)
 .globl l0421
l0421:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxcos
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxtan expr 2)
 .globl l0422
l0422:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxtan
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxasin expr 2)
 .globl l0423
l0423:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxasin
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxacos expr 2)
 .globl l0424
l0424:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxacos
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxatan expr 2)
 .globl l0425
l0425:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxatan
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxsqrt expr 2)
 .globl l0426
l0426:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxsqrt
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxexp expr 2)
 .globl l0427
l0427:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxexp
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry uxlog expr 2)
 .globl l0428
l0428:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxlog
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry uxatan2 expr 3)
 .globl l0429
l0429:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _uxatan2
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry external_pwd expr 0)
 .globl l0430
l0430:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_pwd
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry sun3_sigset expr 2)
 .globl l0431
l0431:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _sun3_sigset
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry sun3_sigrelse expr 2)
 .globl l0432
l0432:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _sun3_sigrelse
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry sigrelse expr 2)
 .globl sigrelse
sigrelse:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _sun3_sigrelse
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry mask_signal expr 2)
 .globl l0433
l0433:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _mask_signal
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry unexec expr 4)
 .globl l0434
l0434:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unexec
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry unixputc expr 1)
 .globl l0435
l0435:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixputc
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry unixputs expr 1)
 .globl l0436
l0436:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixputs
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry unixputn expr 1)
 .globl l0437
l0437:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixputn
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry unixcleario expr 0)
 .globl l0438
l0438:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixcleario
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry expand_file_name expr 1)
 .globl l0439
l0439:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _expand_file_name
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry unixopen expr 2)
 .globl l0440
l0440:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixopen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry unixcd expr 1)
 .globl l0441
l0441:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixcd
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry ctime expr 1)
 .globl l0442
l0442:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _ctime
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_system expr 1)
 .globl l0443
l0443:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_system
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_fullpath expr 1)
 .globl l0444
l0444:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_fullpath
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry external_exit expr 1)
 .globl l0445
l0445:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _external_exit
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry fopen expr 2)
 .globl l0446
l0446:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fopen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry fclose expr 1)
 .globl l0447
l0447:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fclose
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry fread expr 4)
 .globl l0448
l0448:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fread
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry fputc expr 2)
 .globl l0449
l0449:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fputc
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry fgetc expr 1)
 .globl l0450
l0450:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fgetc
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry fgets expr 3)
 .globl l0451
l0451:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fgets
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry fwrite expr 4)
 .globl l0452
l0452:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fwrite
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry fflush expr 1)
 .globl l0453
l0453:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fflush
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry fseek expr 3)
 .globl l0454
l0454:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fseek
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry clearerr expr 1)
 .globl l0455
l0455:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _clearerr
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry xgetw expr 1)
 .globl l0456
l0456:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _xgetw
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry putw expr 2)
 .globl l0457
l0457:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _putw
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry signal expr 2)
 .globl l0458
l0458:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _signal
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry sleep expr 1)
 .globl l0459
l0459:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _sleep
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry ieee_handler expr 3)
 .globl l0460
l0460:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _ieee_handler
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry ieee_flags expr 4)
 .globl l0461
l0461:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _ieee_flags
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry setlinebuf expr 1)
 .globl l0462
l0462:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _setlinebuf
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry getpid expr 0)
 .globl l0463
l0463:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _getpid
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry gethostid expr 0)
 .globl l0464
l0464:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _gethostid
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry unixsocketopen expr 2)
 .globl l0465
l0465:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixsocketopen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry getsocket expr 3)
 .globl l0466
l0466:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _getsocket
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry writesocket expr 3)
 .globl l0467
l0467:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _writesocket
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry unixclosesocket expr 1)
 .globl l0468
l0468:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _unixclosesocket
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 0
// (*entry fork expr 0)
 .globl l0469
l0469:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _fork
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry wait expr 1)
 .globl l0470
l0470:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _wait
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry popen expr 2)
 .globl l0471
l0471:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _popen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry pclose expr 1)
 .globl l0472
l0472:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _pclose
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry shmctl expr 3)
 .globl l0473
l0473:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _shmctl
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry shmget expr 3)
 .globl l0474
l0474:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _shmget
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry shmat expr 3)
 .globl l0475
l0475:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _shmat
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry shmdt expr 1)
 .globl l0476
l0476:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _shmdt
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry semctl expr 4)
 .globl l0477
l0477:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _semctl
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry semget expr 3)
 .globl l0478
l0478:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _semget
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 3
// (*entry semop expr 3)
 .globl l0479
l0479:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _semop
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry dlopen expr 2)
 .globl l0480
l0480:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _dlopen
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry dlerror expr 1)
 .globl l0481
l0481:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _dlerror
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 2
// (*entry dlsym expr 2)
 .globl l0482
l0482:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _dlsym
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry dlclose expr 1)
 .globl l0483
l0483:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _dlclose
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 4
// (*entry unix-profile expr 4)
 .globl l0484
l0484:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 stp X29, X30, [sp, #-80]!
 mov X29, sp
 stp X21, X22, [sp, #64]
 stp X23, X24, [sp, #48]
 stp X25, X26, [sp, #32]
 stp X27, X28, [sp, #16]
 bl _profil
 ldp X27, X28, [sp, #16]
 ldp X25, X26, [sp, #32]
 ldp X23, X24, [sp, #48]
 ldp X21, X22, [sp, #64]
 ldp X29, X30, [sp], #80
 ret
 .quad 1
// (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 stp X29, X30, [sp, #-32]!
 mov X29, sp
 str X28, [sp, #24]
 ubfx X0, X0, #0, #56
 str X0, [sp, #16]
 ldr X0, l0485
// (idloc getfcodepointer)
 ldr X11, l0486
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ubfx X0, X0, #0, #56
 ldr X11, [sp, #16]
 cmp X0, X11
 b.le l0491
 mov X0, X28
 b l0492
l0491:
 ldr X0, l0487
l0492:
 cmp X0, X28
 b.eq l0493
 ldr X0, l0488
// (idloc getfcodepointer)
 ldr X11, l0486
 ldr X10, [X23, X11, lsl #3]
 blr X10
 ubfx X0, X0, #0, #56
 ldr X11, [sp, #16]
 cmp X11, X0
 b.lt l0494
 mov X0, X28
 b l0493
l0494:
 ldr X0, l0487
l0493:
 cmp X0, X28
 b.ne l0495
// ($global bpslowerbound)
 ldr X11, l0489
 ldr X0, [X24, X11, lsl #3]
 ubfx X0, X0, #0, #56
 ldr X11, [sp, #16]
 cmp X0, X11
 b.le l0496
 mov X0, X28
 b l0497
l0496:
 ldr X0, l0487
l0497:
 cmp X0, X28
 b.eq l0495
// ($global nextbps)
 ldr X11, l0490
 ldr X0, [X24, X11, lsl #3]
 ubfx X0, X0, #0, #56
 ldr X11, [sp, #16]
 cmp X11, X0
 b.lt l0498
 mov X0, X28
 b l0495
l0498:
 ldr X0, l0487
l0495:
 ldp X29, X30, [sp], #32
 ret
 nop
l0490:
 .quad 287
l0489:
 .quad 285
l0488:
 .quad ((254<<56)+511)
l0487:
 .quad ((254<<56)+116)
l0486:
 .quad 509
l0485:
 .quad ((254<<56)+257)
 .quad 1
// (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 ldp X29, X30, [sp], #16
 ret
 .quad 0
// (*entry initcode expr 0)
 .globl initcode
initcode:
 stp X29, X30, [sp, #-16]!
 mov X29, sp
 mov X0, X28
 ldp X29, X30, [sp], #16
 ret
 nop
 .globl symval
 .globl symprp
 .globl symnam
 .globl l0499
l0499:
 .quad 0
 .byte 0,0,0,0,0,0,0,0
 .globl l0500
l0500:
 .quad 0
 .byte 1,0,0,0,0,0,0,0
 .globl l0501
l0501:
 .quad 0
 .byte 2,0,0,0,0,0,0,0
 .globl l0502
l0502:
 .quad 0
 .byte 3,0,0,0,0,0,0,0
 .globl l0503
l0503:
 .quad 0
 .byte 4,0,0,0,0,0,0,0
 .globl l0504
l0504:
 .quad 0
 .byte 5,0,0,0,0,0,0,0
 .globl l0505
l0505:
 .quad 0
 .byte 6,0,0,0,0,0,0,0
 .globl l0506
l0506:
 .quad 0
 .byte 7,0,0,0,0,0,0,0
 .globl l0507
l0507:
 .quad 0
 .byte 8,0,0,0,0,0,0,0
 .globl l0508
l0508:
 .quad 0
 .byte 9,0,0,0,0,0,0,0
 .globl l0509
l0509:
 .quad 0
 .byte 10,0,0,0,0,0,0,0
 .globl l0510
l0510:
 .quad 0
 .byte 11,0,0,0,0,0,0,0
 .globl l0511
l0511:
 .quad 0
 .byte 12,0,0,0,0,0,0,0
 .globl l0512
l0512:
 .quad 0
 .byte 13,0,0,0,0,0,0,0
 .globl l0513
l0513:
 .quad 0
 .byte 14,0,0,0,0,0,0,0
 .globl l0514
l0514:
 .quad 0
 .byte 15,0,0,0,0,0,0,0
 .globl l0515
l0515:
 .quad 0
 .byte 16,0,0,0,0,0,0,0
 .globl l0516
l0516:
 .quad 0
 .byte 17,0,0,0,0,0,0,0
 .globl l0517
l0517:
 .quad 0
 .byte 18,0,0,0,0,0,0,0
 .globl l0518
l0518:
 .quad 0
 .byte 19,0,0,0,0,0,0,0
 .globl l0519
l0519:
 .quad 0
 .byte 20,0,0,0,0,0,0,0
 .globl l0520
l0520:
 .quad 0
 .byte 21,0,0,0,0,0,0,0
 .globl l0521
l0521:
 .quad 0
 .byte 22,0,0,0,0,0,0,0
 .globl l0522
l0522:
 .quad 0
 .byte 23,0,0,0,0,0,0,0
 .globl l0523
l0523:
 .quad 0
 .byte 24,0,0,0,0,0,0,0
 .globl l0524
l0524:
 .quad 0
 .byte 25,0,0,0,0,0,0,0
 .globl l0525
l0525:
 .quad 0
 .byte 26,0,0,0,0,0,0,0
 .globl l0526
l0526:
 .quad 0
 .byte 27,0,0,0,0,0,0,0
 .globl l0527
l0527:
 .quad 0
 .byte 28,0,0,0,0,0,0,0
 .globl l0528
l0528:
 .quad 0
 .byte 29,0,0,0,0,0,0,0
 .globl l0529
l0529:
 .quad 0
 .byte 30,0,0,0,0,0,0,0
 .globl l0530
l0530:
 .quad 0
 .byte 31,0,0,0,0,0,0,0
 .globl l0531
l0531:
 .quad 0
 .byte 32,0,0,0,0,0,0,0
 .globl l0532
l0532:
 .quad 0
 .byte 33,0,0,0,0,0,0,0
 .globl l0533
l0533:
 .quad 0
 .byte 34,0,0,0,0,0,0,0
 .globl l0534
l0534:
 .quad 0
 .byte 35,0,0,0,0,0,0,0
 .globl l0535
l0535:
 .quad 0
 .byte 36,0,0,0,0,0,0,0
 .globl l0536
l0536:
 .quad 0
 .byte 37,0,0,0,0,0,0,0
 .globl l0537
l0537:
 .quad 0
 .byte 38,0,0,0,0,0,0,0
 .globl l0538
l0538:
 .quad 0
 .byte 39,0,0,0,0,0,0,0
 .globl l0539
l0539:
 .quad 0
 .byte 40,0,0,0,0,0,0,0
 .globl l0540
l0540:
 .quad 0
 .byte 41,0,0,0,0,0,0,0
 .globl l0541
l0541:
 .quad 0
 .byte 42,0,0,0,0,0,0,0
 .globl l0542
l0542:
 .quad 0
 .byte 43,0,0,0,0,0,0,0
 .globl l0543
l0543:
 .quad 0
 .byte 44,0,0,0,0,0,0,0
 .globl l0544
l0544:
 .quad 0
 .byte 45,0,0,0,0,0,0,0
 .globl l0545
l0545:
 .quad 0
 .byte 46,0,0,0,0,0,0,0
 .globl l0546
l0546:
 .quad 0
 .byte 47,0,0,0,0,0,0,0
 .globl l0547
l0547:
 .quad 0
 .byte 48,0,0,0,0,0,0,0
 .globl l0548
l0548:
 .quad 0
 .byte 49,0,0,0,0,0,0,0
 .globl l0549
l0549:
 .quad 0
 .byte 50,0,0,0,0,0,0,0
 .globl l0550
l0550:
 .quad 0
 .byte 51,0,0,0,0,0,0,0
 .globl l0551
l0551:
 .quad 0
 .byte 52,0,0,0,0,0,0,0
 .globl l0552
l0552:
 .quad 0
 .byte 53,0,0,0,0,0,0,0
 .globl l0553
l0553:
 .quad 0
 .byte 54,0,0,0,0,0,0,0
 .globl l0554
l0554:
 .quad 0
 .byte 55,0,0,0,0,0,0,0
 .globl l0555
l0555:
 .quad 0
 .byte 56,0,0,0,0,0,0,0
 .globl l0556
l0556:
 .quad 0
 .byte 57,0,0,0,0,0,0,0
 .globl l0557
l0557:
 .quad 0
 .byte 58,0,0,0,0,0,0,0
 .globl l0558
l0558:
 .quad 0
 .byte 59,0,0,0,0,0,0,0
 .globl l0559
l0559:
 .quad 0
 .byte 60,0,0,0,0,0,0,0
 .globl l0560
l0560:
 .quad 0
 .byte 61,0,0,0,0,0,0,0
 .globl l0561
l0561:
 .quad 0
 .byte 62,0,0,0,0,0,0,0
 .globl l0562
l0562:
 .quad 0
 .byte 63,0,0,0,0,0,0,0
 .globl l0563
l0563:
 .quad 0
 .byte 64,0,0,0,0,0,0,0
 .globl l0564
l0564:
 .quad 0
 .byte 65,0,0,0,0,0,0,0
 .globl l0565
l0565:
 .quad 0
 .byte 66,0,0,0,0,0,0,0
 .globl l0566
l0566:
 .quad 0
 .byte 67,0,0,0,0,0,0,0
 .globl l0567
l0567:
 .quad 0
 .byte 68,0,0,0,0,0,0,0
 .globl l0568
l0568:
 .quad 0
 .byte 69,0,0,0,0,0,0,0
 .globl l0569
l0569:
 .quad 0
 .byte 70,0,0,0,0,0,0,0
 .globl l0570
l0570:
 .quad 0
 .byte 71,0,0,0,0,0,0,0
 .globl l0571
l0571:
 .quad 0
 .byte 72,0,0,0,0,0,0,0
 .globl l0572
l0572:
 .quad 0
 .byte 73,0,0,0,0,0,0,0
 .globl l0573
l0573:
 .quad 0
 .byte 74,0,0,0,0,0,0,0
 .globl l0574
l0574:
 .quad 0
 .byte 75,0,0,0,0,0,0,0
 .globl l0575
l0575:
 .quad 0
 .byte 76,0,0,0,0,0,0,0
 .globl l0576
l0576:
 .quad 0
 .byte 77,0,0,0,0,0,0,0
 .globl l0577
l0577:
 .quad 0
 .byte 78,0,0,0,0,0,0,0
 .globl l0578
l0578:
 .quad 0
 .byte 79,0,0,0,0,0,0,0
 .globl l0579
l0579:
 .quad 0
 .byte 80,0,0,0,0,0,0,0
 .globl l0580
l0580:
 .quad 0
 .byte 81,0,0,0,0,0,0,0
 .globl l0581
l0581:
 .quad 0
 .byte 82,0,0,0,0,0,0,0
 .globl l0582
l0582:
 .quad 0
 .byte 83,0,0,0,0,0,0,0
 .globl l0583
l0583:
 .quad 0
 .byte 84,0,0,0,0,0,0,0
 .globl l0584
l0584:
 .quad 0
 .byte 85,0,0,0,0,0,0,0
 .globl l0585
l0585:
 .quad 0
 .byte 86,0,0,0,0,0,0,0
 .globl l0586
l0586:
 .quad 0
 .byte 87,0,0,0,0,0,0,0
 .globl l0587
l0587:
 .quad 0
 .byte 88,0,0,0,0,0,0,0
 .globl l0588
l0588:
 .quad 0
 .byte 89,0,0,0,0,0,0,0
 .globl l0589
l0589:
 .quad 0
 .byte 90,0,0,0,0,0,0,0
 .globl l0590
l0590:
 .quad 0
 .byte 91,0,0,0,0,0,0,0
 .globl l0591
l0591:
 .quad 0
 .byte 92,0,0,0,0,0,0,0
 .globl l0592
l0592:
 .quad 0
 .byte 93,0,0,0,0,0,0,0
 .globl l0593
l0593:
 .quad 0
 .byte 94,0,0,0,0,0,0,0
 .globl l0594
l0594:
 .quad 0
 .byte 95,0,0,0,0,0,0,0
 .globl l0595
l0595:
 .quad 0
 .byte 96,0,0,0,0,0,0,0
 .globl l0596
l0596:
 .quad 0
 .byte 97,0,0,0,0,0,0,0
 .globl l0597
l0597:
 .quad 0
 .byte 98,0,0,0,0,0,0,0
 .globl l0598
l0598:
 .quad 0
 .byte 99,0,0,0,0,0,0,0
 .globl l0599
l0599:
 .quad 0
 .byte 100,0,0,0,0,0,0,0
 .globl l0600
l0600:
 .quad 0
 .byte 101,0,0,0,0,0,0,0
 .globl l0601
l0601:
 .quad 0
 .byte 102,0,0,0,0,0,0,0
 .globl l0602
l0602:
 .quad 0
 .byte 103,0,0,0,0,0,0,0
 .globl l0603
l0603:
 .quad 0
 .byte 104,0,0,0,0,0,0,0
 .globl l0604
l0604:
 .quad 0
 .byte 105,0,0,0,0,0,0,0
 .globl l0605
l0605:
 .quad 0
 .byte 106,0,0,0,0,0,0,0
 .globl l0606
l0606:
 .quad 0
 .byte 107,0,0,0,0,0,0,0
 .globl l0607
l0607:
 .quad 0
 .byte 108,0,0,0,0,0,0,0
 .globl l0608
l0608:
 .quad 0
 .byte 109,0,0,0,0,0,0,0
 .globl l0609
l0609:
 .quad 0
 .byte 110,0,0,0,0,0,0,0
 .globl l0610
l0610:
 .quad 0
 .byte 111,0,0,0,0,0,0,0
 .globl l0611
l0611:
 .quad 0
 .byte 112,0,0,0,0,0,0,0
 .globl l0612
l0612:
 .quad 0
 .byte 113,0,0,0,0,0,0,0
 .globl l0613
l0613:
 .quad 0
 .byte 114,0,0,0,0,0,0,0
 .globl l0614
l0614:
 .quad 0
 .byte 115,0,0,0,0,0,0,0
 .globl l0615
l0615:
 .quad 0
 .byte 116,0,0,0,0,0,0,0
 .globl l0616
l0616:
 .quad 0
 .byte 117,0,0,0,0,0,0,0
 .globl l0617
l0617:
 .quad 0
 .byte 118,0,0,0,0,0,0,0
 .globl l0618
l0618:
 .quad 0
 .byte 119,0,0,0,0,0,0,0
 .globl l0619
l0619:
 .quad 0
 .byte 120,0,0,0,0,0,0,0
 .globl l0620
l0620:
 .quad 0
 .byte 121,0,0,0,0,0,0,0
 .globl l0621
l0621:
 .quad 0
 .byte 122,0,0,0,0,0,0,0
 .globl l0622
l0622:
 .quad 0
 .byte 123,0,0,0,0,0,0,0
 .globl l0623
l0623:
 .quad 0
 .byte 124,0,0,0,0,0,0,0
 .globl l0624
l0624:
 .quad 0
 .byte 125,0,0,0,0,0,0,0
 .globl l0625
l0625:
 .quad 0
 .byte 126,0,0,0,0,0,0,0
 .globl l0626
l0626:
 .quad 0
 .byte 127,0,0,0,0,0,0,0
 .globl l0627
l0627:
 .quad 0
 .byte -128,0,0,0,0,0,0,0
 .globl l0628
l0628:
 .quad 0
 .byte -127,0,0,0,0,0,0,0
 .globl l0629
l0629:
 .quad 0
 .byte -126,0,0,0,0,0,0,0
 .globl l0630
l0630:
 .quad 0
 .byte -125,0,0,0,0,0,0,0
 .globl l0631
l0631:
 .quad 0
 .byte -124,0,0,0,0,0,0,0
 .globl l0632
l0632:
 .quad 0
 .byte -123,0,0,0,0,0,0,0
 .globl l0633
l0633:
 .quad 0
 .byte -122,0,0,0,0,0,0,0
 .globl l0634
l0634:
 .quad 0
 .byte -121,0,0,0,0,0,0,0
 .globl l0635
l0635:
 .quad 0
 .byte -120,0,0,0,0,0,0,0
 .globl l0636
l0636:
 .quad 0
 .byte -119,0,0,0,0,0,0,0
 .globl l0637
l0637:
 .quad 0
 .byte -118,0,0,0,0,0,0,0
 .globl l0638
l0638:
 .quad 0
 .byte -117,0,0,0,0,0,0,0
 .globl l0639
l0639:
 .quad 0
 .byte -116,0,0,0,0,0,0,0
 .globl l0640
l0640:
 .quad 0
 .byte -115,0,0,0,0,0,0,0
 .globl l0641
l0641:
 .quad 0
 .byte -114,0,0,0,0,0,0,0
 .globl l0642
l0642:
 .quad 0
 .byte -113,0,0,0,0,0,0,0
 .globl l0643
l0643:
 .quad 0
 .byte -112,0,0,0,0,0,0,0
 .globl l0644
l0644:
 .quad 0
 .byte -111,0,0,0,0,0,0,0
 .globl l0645
l0645:
 .quad 0
 .byte -110,0,0,0,0,0,0,0
 .globl l0646
l0646:
 .quad 0
 .byte -109,0,0,0,0,0,0,0
 .globl l0647
l0647:
 .quad 0
 .byte -108,0,0,0,0,0,0,0
 .globl l0648
l0648:
 .quad 0
 .byte -107,0,0,0,0,0,0,0
 .globl l0649
l0649:
 .quad 0
 .byte -106,0,0,0,0,0,0,0
 .globl l0650
l0650:
 .quad 0
 .byte -105,0,0,0,0,0,0,0
 .globl l0651
l0651:
 .quad 0
 .byte -104,0,0,0,0,0,0,0
 .globl l0652
l0652:
 .quad 0
 .byte -103,0,0,0,0,0,0,0
 .globl l0653
l0653:
 .quad 0
 .byte -102,0,0,0,0,0,0,0
 .globl l0654
l0654:
 .quad 0
 .byte -101,0,0,0,0,0,0,0
 .globl l0655
l0655:
 .quad 0
 .byte -100,0,0,0,0,0,0,0
 .globl l0656
l0656:
 .quad 0
 .byte -99,0,0,0,0,0,0,0
 .globl l0657
l0657:
 .quad 0
 .byte -98,0,0,0,0,0,0,0
 .globl l0658
l0658:
 .quad 0
 .byte -97,0,0,0,0,0,0,0
 .globl l0659
l0659:
 .quad 0
 .byte -96,0,0,0,0,0,0,0
 .globl l0660
l0660:
 .quad 0
 .byte -95,0,0,0,0,0,0,0
 .globl l0661
l0661:
 .quad 0
 .byte -94,0,0,0,0,0,0,0
 .globl l0662
l0662:
 .quad 0
 .byte -93,0,0,0,0,0,0,0
 .globl l0663
l0663:
 .quad 0
 .byte -92,0,0,0,0,0,0,0
 .globl l0664
l0664:
 .quad 0
 .byte -91,0,0,0,0,0,0,0
 .globl l0665
l0665:
 .quad 0
 .byte -90,0,0,0,0,0,0,0
 .globl l0666
l0666:
 .quad 0
 .byte -89,0,0,0,0,0,0,0
 .globl l0667
l0667:
 .quad 0
 .byte -88,0,0,0,0,0,0,0
 .globl l0668
l0668:
 .quad 0
 .byte -87,0,0,0,0,0,0,0
 .globl l0669
l0669:
 .quad 0
 .byte -86,0,0,0,0,0,0,0
 .globl l0670
l0670:
 .quad 0
 .byte -85,0,0,0,0,0,0,0
 .globl l0671
l0671:
 .quad 0
 .byte -84,0,0,0,0,0,0,0
 .globl l0672
l0672:
 .quad 0
 .byte -83,0,0,0,0,0,0,0
 .globl l0673
l0673:
 .quad 0
 .byte -82,0,0,0,0,0,0,0
 .globl l0674
l0674:
 .quad 0
 .byte -81,0,0,0,0,0,0,0
 .globl l0675
l0675:
 .quad 0
 .byte -80,0,0,0,0,0,0,0
 .globl l0676
l0676:
 .quad 0
 .byte -79,0,0,0,0,0,0,0
 .globl l0677
l0677:
 .quad 0
 .byte -78,0,0,0,0,0,0,0
 .globl l0678
l0678:
 .quad 0
 .byte -77,0,0,0,0,0,0,0
 .globl l0679
l0679:
 .quad 0
 .byte -76,0,0,0,0,0,0,0
 .globl l0680
l0680:
 .quad 0
 .byte -75,0,0,0,0,0,0,0
 .globl l0681
l0681:
 .quad 0
 .byte -74,0,0,0,0,0,0,0
 .globl l0682
l0682:
 .quad 0
 .byte -73,0,0,0,0,0,0,0
 .globl l0683
l0683:
 .quad 0
 .byte -72,0,0,0,0,0,0,0
 .globl l0684
l0684:
 .quad 0
 .byte -71,0,0,0,0,0,0,0
 .globl l0685
l0685:
 .quad 0
 .byte -70,0,0,0,0,0,0,0
 .globl l0686
l0686:
 .quad 0
 .byte -69,0,0,0,0,0,0,0
 .globl l0687
l0687:
 .quad 0
 .byte -68,0,0,0,0,0,0,0
 .globl l0688
l0688:
 .quad 0
 .byte -67,0,0,0,0,0,0,0
 .globl l0689
l0689:
 .quad 0
 .byte -66,0,0,0,0,0,0,0
 .globl l0690
l0690:
 .quad 0
 .byte -65,0,0,0,0,0,0,0
 .globl l0691
l0691:
 .quad 0
 .byte -64,0,0,0,0,0,0,0
 .globl l0692
l0692:
 .quad 0
 .byte -63,0,0,0,0,0,0,0
 .globl l0693
l0693:
 .quad 0
 .byte -62,0,0,0,0,0,0,0
 .globl l0694
l0694:
 .quad 0
 .byte -61,0,0,0,0,0,0,0
 .globl l0695
l0695:
 .quad 0
 .byte -60,0,0,0,0,0,0,0
 .globl l0696
l0696:
 .quad 0
 .byte -59,0,0,0,0,0,0,0
 .globl l0697
l0697:
 .quad 0
 .byte -58,0,0,0,0,0,0,0
 .globl l0698
l0698:
 .quad 0
 .byte -57,0,0,0,0,0,0,0
 .globl l0699
l0699:
 .quad 0
 .byte -56,0,0,0,0,0,0,0
 .globl l0700
l0700:
 .quad 0
 .byte -55,0,0,0,0,0,0,0
 .globl l0701
l0701:
 .quad 0
 .byte -54,0,0,0,0,0,0,0
 .globl l0702
l0702:
 .quad 0
 .byte -53,0,0,0,0,0,0,0
 .globl l0703
l0703:
 .quad 0
 .byte -52,0,0,0,0,0,0,0
 .globl l0704
l0704:
 .quad 0
 .byte -51,0,0,0,0,0,0,0
 .globl l0705
l0705:
 .quad 0
 .byte -50,0,0,0,0,0,0,0
 .globl l0706
l0706:
 .quad 0
 .byte -49,0,0,0,0,0,0,0
 .globl l0707
l0707:
 .quad 0
 .byte -48,0,0,0,0,0,0,0
 .globl l0708
l0708:
 .quad 0
 .byte -47,0,0,0,0,0,0,0
 .globl l0709
l0709:
 .quad 0
 .byte -46,0,0,0,0,0,0,0
 .globl l0710
l0710:
 .quad 0
 .byte -45,0,0,0,0,0,0,0
 .globl l0711
l0711:
 .quad 0
 .byte -44,0,0,0,0,0,0,0
 .globl l0712
l0712:
 .quad 0
 .byte -43,0,0,0,0,0,0,0
 .globl l0713
l0713:
 .quad 0
 .byte -42,0,0,0,0,0,0,0
 .globl l0714
l0714:
 .quad 0
 .byte -41,0,0,0,0,0,0,0
 .globl l0715
l0715:
 .quad 0
 .byte -40,0,0,0,0,0,0,0
 .globl l0716
l0716:
 .quad 0
 .byte -39,0,0,0,0,0,0,0
 .globl l0717
l0717:
 .quad 0
 .byte -38,0,0,0,0,0,0,0
 .globl l0718
l0718:
 .quad 0
 .byte -37,0,0,0,0,0,0,0
 .globl l0719
l0719:
 .quad 0
 .byte -36,0,0,0,0,0,0,0
 .globl l0720
l0720:
 .quad 0
 .byte -35,0,0,0,0,0,0,0
 .globl l0721
l0721:
 .quad 0
 .byte -34,0,0,0,0,0,0,0
 .globl l0722
l0722:
 .quad 0
 .byte -33,0,0,0,0,0,0,0
 .globl l0723
l0723:
 .quad 0
 .byte -32,0,0,0,0,0,0,0
 .globl l0724
l0724:
 .quad 0
 .byte -31,0,0,0,0,0,0,0
 .globl l0725
l0725:
 .quad 0
 .byte -30,0,0,0,0,0,0,0
 .globl l0726
l0726:
 .quad 0
 .byte -29,0,0,0,0,0,0,0
 .globl l0727
l0727:
 .quad 0
 .byte -28,0,0,0,0,0,0,0
 .globl l0728
l0728:
 .quad 0
 .byte -27,0,0,0,0,0,0,0
 .globl l0729
l0729:
 .quad 0
 .byte -26,0,0,0,0,0,0,0
 .globl l0730
l0730:
 .quad 0
 .byte -25,0,0,0,0,0,0,0
 .globl l0731
l0731:
 .quad 0
 .byte -24,0,0,0,0,0,0,0
 .globl l0732
l0732:
 .quad 0
 .byte -23,0,0,0,0,0,0,0
 .globl l0733
l0733:
 .quad 0
 .byte -22,0,0,0,0,0,0,0
 .globl l0734
l0734:
 .quad 0
 .byte -21,0,0,0,0,0,0,0
 .globl l0735
l0735:
 .quad 0
 .byte -20,0,0,0,0,0,0,0
 .globl l0736
l0736:
 .quad 0
 .byte -19,0,0,0,0,0,0,0
 .globl l0737
l0737:
 .quad 0
 .byte -18,0,0,0,0,0,0,0
 .globl l0738
l0738:
 .quad 0
 .byte -17,0,0,0,0,0,0,0
 .globl l0739
l0739:
 .quad 0
 .byte -16,0,0,0,0,0,0,0
 .globl l0740
l0740:
 .quad 0
 .byte -15,0,0,0,0,0,0,0
 .globl l0741
l0741:
 .quad 0
 .byte -14,0,0,0,0,0,0,0
 .globl l0742
l0742:
 .quad 0
 .byte -13,0,0,0,0,0,0,0
 .globl l0743
l0743:
 .quad 0
 .byte -12,0,0,0,0,0,0,0
 .globl l0744
l0744:
 .quad 0
 .byte -11,0,0,0,0,0,0,0
 .globl l0745
l0745:
 .quad 0
 .byte -10,0,0,0,0,0,0,0
 .globl l0746
l0746:
 .quad 0
 .byte -9,0,0,0,0,0,0,0
 .globl l0747
l0747:
 .quad 0
 .byte -8,0,0,0,0,0,0,0
 .globl l0748
l0748:
 .quad 0
 .byte -7,0,0,0,0,0,0,0
 .globl l0749
l0749:
 .quad 0
 .byte -6,0,0,0,0,0,0,0
 .globl l0750
l0750:
 .quad 0
 .byte -5,0,0,0,0,0,0,0
 .globl l0751
l0751:
 .quad 0
 .byte -4,0,0,0,0,0,0,0
 .globl l0752
l0752:
 .quad 0
 .byte -3,0,0,0,0,0,0,0
 .globl l0753
l0753:
 .quad 0
 .byte -2,0,0,0,0,0,0,0
 .globl l0754
l0754:
 .quad 0
 .byte -1,0,0,0,0,0,0,0
 .globl l0755
l0755:
 .quad 2
 .byte 110,105,108,0,0,0,0,0
 .globl l0756
l0756:
 .quad 10
 .byte 102,105,114,115,116,107,101,114,110
 .byte 101,108,0,0,0,0,0
 .globl l0757
l0757:
 .quad 4
 .byte 115,116,97,99,107,0,0,0
 .globl l0758
l0758:
 .quad 12
 .byte 97,114,103,117,109,101,110,116,98,108
 .byte 111,99,107,0,0,0
 .globl l0759
l0759:
 .quad 10
 .byte 116,111,107,101,110,98,117,102,102
 .byte 101,114,0,0,0,0,0
 .globl l0760
l0760:
 .quad 5
 .byte 98,110,100,115,116,107,0,0
 .globl l0761
l0761:
 .quad 9
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 0,0,0,0,0,0
 .globl l0762
l0762:
 .quad 8
 .byte 104,97,115,104,116,97,98,108,101,0
 .byte 0,0,0,0,0,0
 .globl l0763
l0763:
 .quad 12
 .byte 111,110,101,119,111,114,100,98,117
 .byte 102,102,101,114,0,0,0
 .globl l0764
l0764:
 .quad 7
 .byte 115,97,118,101,97,114,103,99,0,0,0
 .byte 0,0,0,0,0
 .globl l0765
l0765:
 .quad 7
 .byte 115,97,118,101,97,114,103,118,0,0,0
 .byte 0,0,0,0,0
 .globl l0766
l0766:
 .quad 9
 .byte 100,97,116,101,98,117,102,102,101,114
 .byte 0,0,0,0,0,0
 .globl l0767
l0767:
 .quad 7
 .byte 104,101,97,112,108,97,115,116,0,0,0
 .byte 0,0,0,0,0
 .globl l0768
l0768:
 .quad 12
 .byte 104,101,97,112,116,114,97,112,98,111
 .byte 117,110,100,0,0,0
 .globl l0769
l0769:
 .quad 8
 .byte 98,110,100,115,116,107,112,116,114
 .byte 0,0,0,0,0,0,0
 .globl l0770
l0770:
 .quad 15
 .byte 98,110,100,115,116,107,108,111,119
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .byte 0,0,0,0
 .globl l0771
l0771:
 .quad 15
 .byte 98,110,100,115,116,107,117,112,112
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .byte 0,0,0,0
 .globl l0772
l0772:
 .quad 15
 .byte 109,111,118,101,45,114,101,103,115
 .byte 45,116,111,45,109,101,109,0,0,0,0,0
 .byte 0,0,0
 .globl l0773
l0773:
 .quad 12
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 112,116,114,0,0,0
 .globl l0774
l0774:
 .quad 13
 .byte 104,101,97,112,108,111,119,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0775
l0775:
 .quad 3
 .byte 104,101,97,112,0,0,0,0
 .globl l0776
l0776:
 .quad 12
 .byte 105,110,105,116,45,112,111,105,110
 .byte 116,101,114,115,0,0,0
 .globl l0777
l0777:
 .quad 16
 .byte 103,99,97,114,114,97,121,108,111,119
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .byte 0,0,0
 .globl l0778
l0778:
 .quad 16
 .byte 103,99,97,114,114,97,121,117,112,112
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .byte 0,0,0
 .globl l0779
l0779:
 .quad 10
 .byte 111,108,100,104,101,97,112,108,97,115
 .byte 116,0,0,0,0,0
 .globl l0780
l0780:
 .quad 15
 .byte 111,108,100,104,101,97,112,116,114
 .byte 97,112,98,111,117,110,100,0,0,0,0,0
 .byte 0,0,0
 .globl l0781
l0781:
 .quad 13
 .byte 104,101,97,112,117,112,112,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0782
l0782:
 .quad 13
 .byte 95,105,110,102,98,105,116,108,101,110
 .byte 103,116,104,95,0,0
 .globl l0783
l0783:
 .quad 6
 .byte 108,97,115,116,98,112,115,0
 .globl l0784
l0784:
 .quad 12
 .byte 98,112,115,108,111,119,101,114,98,111
 .byte 117,110,100,0,0,0
 .globl l0785
l0785:
 .quad 18
 .byte 109,97,105,110,115,116,97,114,116,105
 .byte 110,105,116,105,97,108,105,122,101
 .byte 0,0,0,0,0
 .globl l0786
l0786:
 .quad 6
 .byte 110,101,120,116,98,112,115,0
 .globl l0787
l0787:
 .quad 16
 .byte 111,108,100,104,101,97,112,117,112
 .byte 112,101,114,98,111,117,110,100,0,0
 .byte 0,0,0,0,0
 .globl l0788
l0788:
 .quad 16
 .byte 111,108,100,104,101,97,112,108,111
 .byte 119,101,114,98,111,117,110,100,0,0
 .byte 0,0,0,0,0
 .globl l0789
l0789:
 .quad 14
 .byte 115,116,97,99,107,117,112,112,101,114
 .byte 98,111,117,110,100,0
 .globl l0790
l0790:
 .quad 8
 .byte 117,110,105,120,115,116,100,105,110
 .byte 0,0,0,0,0,0,0
 .globl l0791
l0791:
 .quad 9
 .byte 117,110,105,120,115,116,100,111,117
 .byte 116,0,0,0,0,0,0
 .globl l0792
l0792:
 .quad 9
 .byte 117,110,105,120,115,116,100,101,114
 .byte 114,0,0,0,0,0,0
 .globl l0793
l0793:
 .quad 7
 .byte 117,110,105,120,110,117,108,108,0,0
 .byte 0,0,0,0,0,0
 .globl l0794
l0794:
 .quad 6
 .byte 117,110,105,120,101,111,102,0
 .globl l0795
l0795:
 .quad 6
 .byte 117,110,105,120,116,116,121,0
 .globl l0796
l0796:
 .quad 16
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,42,42,42,0,0,0,0,0,0
 .byte 0
 .globl l0797
l0797:
 .quad 20
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,45,116,111,111,42,42
 .byte 42,0,0,0
 .globl l0798
l0798:
 .quad 7
 .byte 42,102,97,115,116,99,97,114,0,0,0,0
 .byte 0,0,0,0
 .globl l0799
l0799:
 .quad 10
 .byte 105,110,105,116,45,102,108,117,105
 .byte 100,115,0,0,0,0,0
 .globl l0800
l0800:
 .quad 5
 .byte 115,121,109,118,97,108,0,0
 .globl l0801
l0801:
 .quad 5
 .byte 115,121,109,102,110,99,0,0
 .globl l0802
l0802:
 .quad 14
 .byte 111,115,95,115,116,97,114,116,117,112
 .byte 95,104,111,111,107,0
 .globl l0803
l0803:
 .quad 3
 .byte 97,114,103,99,0,0,0,0
 .globl l0804
l0804:
 .quad 3
 .byte 97,114,103,118,0,0,0,0
 .globl l0805
l0805:
 .quad 7
 .byte 101,98,120,115,97,118,101,42,0,0,0
 .byte 0,0,0,0,0
 .globl l0806
l0806:
 .quad 14
 .byte 115,116,97,99,107,108,111,119,101,114
 .byte 98,111,117,110,100,0
 .globl l0807
l0807:
 .quad 11
 .byte 105,110,105,116,45,103,99,97,114,114
 .byte 97,121,0,0,0,0
 .globl l0808
l0808:
 .quad 7
 .byte 112,114,101,45,109,97,105,110,0,0,0
 .byte 0,0,0,0,0
 .globl l0809
l0809:
 .quad 15
 .byte 101,120,105,116,45,119,105,116,104
 .byte 45,115,116,97,116,117,115,0,0,0,0,0
 .byte 0,0,0
 .globl l0810
l0810:
 .quad 14
 .byte 111,115,95,99,108,101,97,110,117,112
 .byte 95,104,111,111,107,0
 .globl l0811
l0811:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,101
 .byte 120,105,116,0,0,0
 .globl l0812
l0812:
 .quad 8
 .byte 95,112,115,108,95,109,97,105,110,0
 .byte 0,0,0,0,0,0
 .globl l0813
l0813:
 .quad 7
 .byte 114,101,100,117,99,101,117,112,0,0
 .byte 0,0,0,0,0,0
 .globl l0814
l0814:
 .quad 8
 .byte 95,114,101,100,117,99,101,117,112,0
 .byte 0,0,0,0,0,0
 .globl l0815
l0815:
 .quad 9
 .byte 115,116,114,105,110,103,111,112,101
 .byte 110,0,0,0,0,0,0
 .globl l0816
l0816:
 .quad 9
 .byte 42,108,105,115,112,95,104,111,111,107
 .byte 0,0,0,0,0,0
 .globl l0817
l0817:
 .quad 2
 .byte 114,100,115,0,0,0,0,0
 .globl l0818
l0818:
 .quad 2
 .byte 119,114,115,0,0,0,0,0
 .globl l0819
l0819:
 .quad 5
 .byte 98,101,103,105,110,49,0,0
 .globl l0820
l0820:
 .quad 4
 .byte 99,108,111,115,101,0,0,0
 .globl l0821
l0821:
 .quad 10
 .byte 117,110,105,120,99,108,101,97,114,105
 .byte 111,0,0,0,0,0
 .globl l0822
l0822:
 .quad 22
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,115,121,109,98,111,108,45,116
 .byte 97,98,108,101,0
 .globl l0823
l0823:
 .quad 7
 .byte 105,110,105,116,99,111,100,101,0,0
 .byte 0,0,0,0,0,0
 .globl l0824
l0824:
 .quad 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,115,116,114,105,110
 .byte 103,0,0,0,0
 .globl l0825
l0825:
 .quad 14
 .byte 99,111,110,115,111,108,101,45,110,101
 .byte 119,108,105,110,101,0
 .globl l0826
l0826:
 .quad 5
 .byte 102,97,115,108,105,110,0,0
 .globl l0827
l0827:
 .quad 10
 .byte 108,111,97,100,101,114,45,109,97,105
 .byte 110,0,0,0,0,0
 .globl l0828
l0828:
 .quad 7
 .byte 117,110,105,120,112,117,116,115,0,0
 .byte 0,0,0,0,0,0
 .globl l0829
l0829:
 .quad 7
 .byte 117,110,105,120,112,117,116,110,0,0
 .byte 0,0,0,0,0,0
 .globl l0830
l0830:
 .quad 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,110,117,109,98,101,114
 .byte 0,0,0,0
 .globl l0831
l0831:
 .quad 7
 .byte 117,110,105,120,112,117,116,99,0,0
 .byte 0,0,0,0,0,0
 .globl l0832
l0832:
 .quad 7
 .byte 117,110,105,120,111,112,101,110,0,0
 .byte 0,0,0,0,0,0
 .globl l0833
l0833:
 .quad 17
 .byte 107,101,114,110,101,108,45,102,97,116
 .byte 97,108,45,101,114,114,111,114,0,0,0
 .byte 0,0,0
 .globl l0834
l0834:
 .quad 13
 .byte 98,105,110,97,114,121,111,112,101,110
 .byte 114,101,97,100,0,0
 .globl l0835
l0835:
 .quad 4
 .byte 120,103,101,116,119,0,0,0
 .globl l0836
l0836:
 .quad 9
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 0,0,0,0,0,0
 .globl l0837
l0837:
 .quad 4
 .byte 102,114,101,97,100,0,0,0
 .globl l0838
l0838:
 .quad 14
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 98,108,111,99,107,0
 .globl l0839
l0839:
 .quad 5
 .byte 102,99,108,111,115,101,0,0
 .globl l0840
l0840:
 .quad 10
 .byte 98,105,110,97,114,121,99,108,111,115
 .byte 101,0,0,0,0,0
 .globl l0841
l0841:
 .quad 9
 .byte 110,101,120,116,115,121,109,98,111
 .byte 108,0,0,0,0,0,0
 .globl l0842
l0842:
 .quad 5
 .byte 115,121,109,110,97,109,0,0
 .globl l0843
l0843:
 .quad 14
 .byte 104,97,115,104,45,105,110,116,111,45
 .byte 116,97,98,108,101,0
 .globl l0844
l0844:
 .quad 11
 .byte 115,104,111,119,45,110,101,119,45,105
 .byte 100,115,0,0,0,0
 .globl l0845
l0845:
 .quad 26
 .byte 115,101,97,114,99,104,45,115,116,114
 .byte 105,110,103,45,102,111,114,45,99,104
 .byte 97,114,97,99,116,101,114,0,0,0,0,0
 .globl l0846
l0846:
 .quad 5
 .byte 105,110,116,101,114,110,0,0
 .globl l0847
l0847:
 .quad 5
 .byte 115,117,98,115,101,113,0,0
 .globl l0848
l0848:
 .quad 12
 .byte 102,97,115,108,105,110,45,105,110,116
 .byte 101,114,110,0,0,0
 .globl l0849
l0849:
 .quad 22
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,105,110
 .byte 116,101,114,110,0
 .globl l0850
l0850:
 .quad 3
 .byte 103,116,105,100,0,0,0,0
 .globl l0851
l0851:
 .quad 9
 .byte 103,116,99,111,110,115,116,115,116
 .byte 114,0,0,0,0,0,0
 .globl l0852
l0852:
 .quad 15
 .byte 99,111,112,121,115,116,114,105,110
 .byte 103,116,111,102,114,111,109,0,0,0,0
 .byte 0,0,0,0
 .globl l0853
l0853:
 .quad 16
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,110,101,119,45,105,100,0,0,0
 .byte 0,0,0,0
 .globl l0854
l0854:
 .quad 12
 .byte 104,97,115,104,45,102,117,110,99,116
 .byte 105,111,110,0,0,0
 .globl l0855
l0855:
 .quad 21
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,101,113
 .byte 117,97,108,0,0
 .globl l0856
l0856:
 .quad 5
 .byte 115,121,109,112,114,112,0,0
 .globl l0857
l0857:
 .quad 5
 .byte 115,121,109,103,101,116,0,0
 .globl l0858
l0858:
 .quad 11
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,0,0,0,0
 .globl l0859
l0859:
 .quad 14
 .byte 102,97,115,108,105,110,45,98,97,100
 .byte 45,102,105,108,101,0
 .globl l0860
l0860:
 .quad 12
 .byte 114,101,97,100,45,105,100,45,116,97
 .byte 98,108,101,0,0,0
 .globl l0861
l0861:
 .quad 4
 .byte 103,116,98,112,115,0,0,0
 .globl l0862
l0862:
 .quad 5
 .byte 103,116,119,114,100,115,0,0
 .globl l0863
l0863:
 .quad 16
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,45,110,101,119,0,0,0,0
 .byte 0,0,0
 .globl l0864
l0864:
 .quad 12
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,0,0,0
 .globl l0865
l0865:
 .quad 10
 .byte 99,108,101,97,114,95,99,97,99,104,101
 .byte 0,0,0,0,0
 .globl l0866
l0866:
 .quad 13
 .byte 99,111,100,101,45,98,97,115,101,45
 .byte 104,97,99,107,0,0
 .globl l0867
l0867:
 .quad 12
 .byte 97,100,100,114,101,115,115,97,112,112
 .byte 108,121,48,0,0,0
 .globl l0868
l0868:
 .quad 5
 .byte 100,101,108,98,112,115,0,0
 .globl l0869
l0869:
 .quad 7
 .byte 98,105,116,116,97,98,108,101,0,0,0
 .byte 0,0,0,0,0
 .globl l0870
l0870:
 .quad 12
 .byte 114,101,108,111,99,97,116,101,45,119
 .byte 111,114,100,0,0,0
 .globl l0871
l0871:
 .quad 11
 .byte 114,101,108,111,99,97,116,101,45,105
 .byte 110,102,0,0,0,0
 .globl l0872
l0872:
 .quad 18
 .byte 114,101,108,111,99,97,116,101,45,114
 .byte 105,103,104,116,45,104,97,108,102,0
 .byte 0,0,0,0
 .globl l0873
l0873:
 .quad 17
 .byte 99,111,109,112,117,116,101,45,114,101
 .byte 108,111,99,97,116,105,111,110,0,0,0
 .byte 0,0,0
 .globl l0874
l0874:
 .quad 17
 .byte 108,111,99,97,108,45,116,111,45,103
 .byte 108,111,98,97,108,45,105,100,0,0,0
 .byte 0,0,0
 .globl l0875
l0875:
 .quad 3
 .byte 112,117,116,100,0,0,0,0
 .globl l0876
l0876:
 .quad 7
 .byte 112,117,116,101,110,116,114,121,0,0
 .byte 0,0,0,0,0,0
 .globl l0877
l0877:
 .quad 14
 .byte 103,116,98,112,115,45,110,105,108,45
 .byte 101,114,114,111,114,0
 .globl l0878
l0878:
 .quad 3
 .byte 103,101,116,100,0,0,0,0
 .globl l0879
l0879:
 .quad 19
 .byte 116,114,121,45,111,116,104,101,114
 .byte 45,98,112,115,45,115,112,97,99,101
 .byte 115,0,0,0,0
 .globl l0880
l0880:
 .quad 7
 .byte 115,116,100,101,114,114,111,114,0,0
 .byte 0,0,0,0,0,0
 .globl l0881
l0881:
 .quad 15
 .byte 107,110,111,119,110,45,102,114,101
 .byte 101,45,115,112,97,99,101,0,0,0,0,0
 .byte 0,0,0
 .globl l0882
l0882:
 .quad 10
 .byte 114,101,97,108,45,103,116,104,101,97
 .byte 112,0,0,0,0,0
 .globl l0883
l0883:
 .quad 5
 .byte 103,116,104,101,97,112,0,0
 .globl l0884
l0884:
 .quad 12
 .byte 103,101,116,45,104,101,97,112,45,116
 .byte 114,97,112,0,0,0
 .globl l0885
l0885:
 .quad 6
 .byte 114,101,99,108,97,105,109,0
 .globl l0886
l0886:
 .quad 4
 .byte 103,116,115,116,114,0,0,0
 .globl l0887
l0887:
 .quad 3
 .byte 99,111,110,115,0,0,0,0
 .globl l0888
l0888:
 .quad 10
 .byte 105,110,116,101,114,114,111,103,97
 .byte 116,101,0,0,0,0,0
 .globl l0889
l0889:
 .quad 5
 .byte 109,111,100,105,102,121,0,0
 .globl l0890
l0890:
 .quad 12
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,117,116,0,0,0
 .globl l0891
l0891:
 .quad 2
 .byte 112,117,116,0,0,0,0,0
 .globl l0892
l0892:
 .quad 13
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,114,111,112,0,0
 .globl l0893
l0893:
 .quad 4
 .byte 97,116,115,111,99,0,0,0
 .globl l0894
l0894:
 .quad 7
 .byte 37,114,101,99,108,97,105,109,0,0,0
 .byte 0,0,0,0,0
 .globl l0895
l0895:
 .quad 16
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,101,116,112,114,111,112,0,0,0,0
 .byte 0,0,0
 .globl l0896
l0896:
 .quad 8
 .byte 99,111,100,101,45,112,117,116,100,0
 .byte 0,0,0,0,0,0
 .globl l0897
l0897:
 .quad 15
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,0,0,0,0,0,0
 .byte 0,0
 .globl l0898
l0898:
 .quad 3
 .byte 116,121,112,101,0,0,0,0
 .globl l0899
l0899:
 .quad 3
 .byte 101,120,112,114,0,0,0,0
 .globl l0900
l0900:
 .quad 5
 .byte 102,108,117,105,100,49,0,0
 .globl l0901
l0901:
 .quad 4
 .byte 102,108,117,105,100,0,0,0
 .globl l0902
l0902:
 .quad 6
 .byte 118,97,114,116,121,112,101,0
 .globl l0903
l0903:
 .quad 15
 .byte 42,100,101,102,105,110,101,45,99,111
 .byte 110,115,116,97,110,116,0,0,0,0,0,0
 .byte 0,0
 .globl l0904
l0904:
 .quad 8
 .byte 99,111,110,115,116,97,110,116,63,0
 .byte 0,0,0,0,0,0
 .globl l0905
l0905:
 .quad 14
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,0
 .globl l0906
l0906:
 .quad 20
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,45,97
 .byte 117,120,0,0,0
 .globl l0907
l0907:
 .quad 16
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,0,0
 .byte 0,0,0,0,0
 .globl l0908
l0908:
 .quad 8
 .byte 99,111,100,101,102,111,114,109,42,0
 .byte 0,0,0,0,0,0
 .globl l0909
l0909:
 .quad 28
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,97,117
 .byte 120,0,0,0
 .globl l0910
l0910:
 .quad 25
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,0,0,0,0
 .byte 0,0
 .globl l0911
l0911:
 .quad 5
 .byte 101,99,104,111,111,110,0,0
 .globl l0912
l0912:
 .quad 6
 .byte 101,99,104,111,111,102,102,0
 .globl l0913
l0913:
 .quad 26
 .byte 101,120,116,101,114,110,97,108,95,99
 .byte 104,97,114,115,105,110,105,110,112
 .byte 117,116,98,117,102,102,101,114,0,0
 .byte 0,0,0
 .globl l0914
l0914:
 .quad 19
 .byte 102,108,117,115,104,115,116,100,111
 .byte 117,116,112,117,116,98,117,102,102
 .byte 101,114,0,0,0,0
 .globl l0915
l0915:
 .quad 27
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 115,101,114,95,104,111,109,101,100
 .byte 105,114,95,115,116,114,105,110,103
 .byte 0,0,0,0
 .globl l0916
l0916:
 .quad 30
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 110,121,117,115,101,114,95,104,111
 .byte 109,101,100,105,114,95,115,116,114
 .byte 105,110,103,0
 .globl l0917
l0917:
 .quad 12
 .byte 97,108,116,101,114,104,101,97,112,115
 .byte 105,122,101,0,0,0
 .globl l0918
l0918:
 .quad 14
 .byte 97,108,108,111,99,97,116,101,109,111
 .byte 114,101,98,112,115,0
 .globl l0919
l0919:
 .quad 16
 .byte 103,101,116,95,105,109,97,103,101,102
 .byte 105,108,101,112,97,116,104,0,0,0,0
 .byte 0,0,0
 .globl l0920
l0920:
 .quad 14
 .byte 103,101,116,95,102,105,108,101,95,115
 .byte 116,97,116,117,115,0
 .globl l0921
l0921:
 .quad 15
 .byte 103,101,116,95,101,120,101,99,102,105
 .byte 108,101,112,97,116,104,0,0,0,0,0,0
 .byte 0,0
 .globl l0922
l0922:
 .quad 8
 .byte 119,113,117,111,116,105,101,110,116
 .byte 0,0,0,0,0,0,0
 .globl l0923
l0923:
 .quad 9
 .byte 119,114,101,109,97,105,110,100,101
 .byte 114,0,0,0,0,0,0
 .globl l0924
l0924:
 .quad 7
 .byte 119,120,100,105,118,105,100,101,0,0
 .byte 0,0,0,0,0,0
 .globl l0925
l0925:
 .quad 15
 .byte 119,120,113,117,111,116,105,101,110
 .byte 116,100,111,117,98,108,101,0,0,0,0
 .byte 0,0,0,0
 .globl l0926
l0926:
 .quad 13
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 108,97,114,109,0,0
 .globl l0927
l0927:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 97,108,97,114,109,0
 .globl l0928
l0928:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,101,0,0,0
 .globl l0929
l0929:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,99,0,0,0
 .globl l0930
l0930:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,97,116,0,0,0
 .globl l0931
l0931:
 .quad 12
 .byte 101,120,116,101,114,110,97,108,95,108
 .byte 105,110,107,0,0,0
 .globl l0932
l0932:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 110,108,105,110,107,0
 .globl l0933
l0933:
 .quad 13
 .byte 101,120,116,101,114,110,97,108,95,114
 .byte 109,100,105,114,0,0
 .globl l0934
l0934:
 .quad 13
 .byte 101,120,116,101,114,110,97,108,95,109
 .byte 107,100,105,114,0,0
 .globl l0935
l0935:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,114,108,101,110,0
 .globl l0936
l0936:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 101,116,101,110,118,0
 .globl l0937
l0937:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,103
 .byte 101,116,101,110,118,0
 .globl l0938
l0938:
 .quad 6
 .byte 117,120,102,108,111,97,116,0
 .globl l0939
l0939:
 .quad 4
 .byte 117,120,102,105,120,0,0,0
 .globl l0940
l0940:
 .quad 7
 .byte 117,120,97,115,115,105,103,110,0,0
 .byte 0,0,0,0,0,0
 .globl l0941
l0941:
 .quad 6
 .byte 117,120,109,105,110,117,115,0
 .globl l0942
l0942:
 .quad 6
 .byte 117,120,112,108,117,115,50,0
 .globl l0943
l0943:
 .quad 11
 .byte 117,120,100,105,102,102,101,114,101
 .byte 110,99,101,0,0,0,0
 .globl l0944
l0944:
 .quad 7
 .byte 117,120,116,105,109,101,115,50,0,0
 .byte 0,0,0,0,0,0
 .globl l0945
l0945:
 .quad 9
 .byte 117,120,113,117,111,116,105,101,110
 .byte 116,0,0,0,0,0,0
 .globl l0946
l0946:
 .quad 9
 .byte 117,120,103,114,101,97,116,101,114
 .byte 112,0,0,0,0,0,0
 .globl l0947
l0947:
 .quad 6
 .byte 117,120,108,101,115,115,112,0
 .globl l0948
l0948:
 .quad 11
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,0,0,0,0
 .globl l0949
l0949:
 .quad 14
 .byte 117,120,100,111,117,98,108,101,116
 .byte 111,102,108,111,97,116,0
 .globl l0950
l0950:
 .quad 14
 .byte 117,120,102,108,111,97,116,116,111
 .byte 100,111,117,98,108,101,0
 .globl l0951
l0951:
 .quad 4
 .byte 117,120,115,105,110,0,0,0
 .globl l0952
l0952:
 .quad 4
 .byte 117,120,99,111,115,0,0,0
 .globl l0953
l0953:
 .quad 4
 .byte 117,120,116,97,110,0,0,0
 .globl l0954
l0954:
 .quad 5
 .byte 117,120,97,115,105,110,0,0
 .globl l0955
l0955:
 .quad 5
 .byte 117,120,97,99,111,115,0,0
 .globl l0956
l0956:
 .quad 5
 .byte 117,120,97,116,97,110,0,0
 .globl l0957
l0957:
 .quad 5
 .byte 117,120,115,113,114,116,0,0
 .globl l0958
l0958:
 .quad 4
 .byte 117,120,101,120,112,0,0,0
 .globl l0959
l0959:
 .quad 4
 .byte 117,120,108,111,103,0,0,0
 .globl l0960
l0960:
 .quad 6
 .byte 117,120,97,116,97,110,50,0
 .globl l0961
l0961:
 .quad 11
 .byte 101,120,116,101,114,110,97,108,95,112
 .byte 119,100,0,0,0,0
 .globl l0962
l0962:
 .quad 10
 .byte 115,117,110,51,95,115,105,103,115,101
 .byte 116,0,0,0,0,0
 .globl l0963
l0963:
 .quad 12
 .byte 115,117,110,51,95,115,105,103,114,101
 .byte 108,115,101,0,0,0
 .globl l0964
l0964:
 .quad 7
 .byte 115,105,103,114,101,108,115,101,0,0
 .byte 0,0,0,0,0,0
 .globl l0965
l0965:
 .quad 10
 .byte 109,97,115,107,95,115,105,103,110,97
 .byte 108,0,0,0,0,0
 .globl l0966
l0966:
 .quad 5
 .byte 117,110,101,120,101,99,0,0
 .globl l0967
l0967:
 .quad 15
 .byte 101,120,112,97,110,100,95,102,105,108
 .byte 101,95,110,97,109,101,0,0,0,0,0,0,0
 .byte 0
 .globl l0968
l0968:
 .quad 5
 .byte 117,110,105,120,99,100,0,0
 .globl l0969
l0969:
 .quad 4
 .byte 99,116,105,109,101,0,0,0
 .globl l0970
l0970:
 .quad 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 121,115,116,101,109,0
 .globl l0971
l0971:
 .quad 16
 .byte 101,120,116,101,114,110,97,108,95,102
 .byte 117,108,108,112,97,116,104,0,0,0,0
 .byte 0,0,0
 .globl l0972
l0972:
 .quad 4
 .byte 102,111,112,101,110,0,0,0
 .globl l0973
l0973:
 .quad 4
 .byte 102,112,117,116,99,0,0,0
 .globl l0974
l0974:
 .quad 4
 .byte 102,103,101,116,99,0,0,0
 .globl l0975
l0975:
 .quad 4
 .byte 102,103,101,116,115,0,0,0
 .globl l0976
l0976:
 .quad 5
 .byte 102,119,114,105,116,101,0,0
 .globl l0977
l0977:
 .quad 5
 .byte 102,102,108,117,115,104,0,0
 .globl l0978
l0978:
 .quad 4
 .byte 102,115,101,101,107,0,0,0
 .globl l0979
l0979:
 .quad 7
 .byte 99,108,101,97,114,101,114,114,0,0,0
 .byte 0,0,0,0,0
 .globl l0980
l0980:
 .quad 3
 .byte 112,117,116,119,0,0,0,0
 .globl l0981
l0981:
 .quad 5
 .byte 115,105,103,110,97,108,0,0
 .globl l0982
l0982:
 .quad 4
 .byte 115,108,101,101,112,0,0,0
 .globl l0983
l0983:
 .quad 11
 .byte 105,101,101,101,95,104,97,110,100,108
 .byte 101,114,0,0,0,0
 .globl l0984
l0984:
 .quad 9
 .byte 105,101,101,101,95,102,108,97,103,115
 .byte 0,0,0,0,0,0
 .globl l0985
l0985:
 .quad 9
 .byte 115,101,116,108,105,110,101,98,117
 .byte 102,0,0,0,0,0,0
 .globl l0986
l0986:
 .quad 5
 .byte 103,101,116,112,105,100,0,0
 .globl l0987
l0987:
 .quad 8
 .byte 103,101,116,104,111,115,116,105,100
 .byte 0,0,0,0,0,0,0
 .globl l0988
l0988:
 .quad 13
 .byte 117,110,105,120,115,111,99,107,101
 .byte 116,111,112,101,110,0,0
 .globl l0989
l0989:
 .quad 8
 .byte 103,101,116,115,111,99,107,101,116
 .byte 0,0,0,0,0,0,0
 .globl l0990
l0990:
 .quad 10
 .byte 119,114,105,116,101,115,111,99,107
 .byte 101,116,0,0,0,0,0
 .globl l0991
l0991:
 .quad 14
 .byte 117,110,105,120,99,108,111,115,101
 .byte 115,111,99,107,101,116,0
 .globl l0992
l0992:
 .quad 3
 .byte 102,111,114,107,0,0,0,0
 .globl l0993
l0993:
 .quad 3
 .byte 119,97,105,116,0,0,0,0
 .globl l0994
l0994:
 .quad 4
 .byte 112,111,112,101,110,0,0,0
 .globl l0995
l0995:
 .quad 5
 .byte 112,99,108,111,115,101,0,0
 .globl l0996
l0996:
 .quad 5
 .byte 115,104,109,99,116,108,0,0
 .globl l0997
l0997:
 .quad 5
 .byte 115,104,109,103,101,116,0,0
 .globl l0998
l0998:
 .quad 4
 .byte 115,104,109,97,116,0,0,0
 .globl l0999
l0999:
 .quad 4
 .byte 115,104,109,100,116,0,0,0
 .globl l1000
l1000:
 .quad 5
 .byte 115,101,109,99,116,108,0,0
 .globl l1001
l1001:
 .quad 5
 .byte 115,101,109,103,101,116,0,0
 .globl l1002
l1002:
 .quad 4
 .byte 115,101,109,111,112,0,0,0
 .globl l1003
l1003:
 .quad 5
 .byte 100,108,111,112,101,110,0,0
 .globl l1004
l1004:
 .quad 6
 .byte 100,108,101,114,114,111,114,0
 .globl l1005
l1005:
 .quad 4
 .byte 100,108,115,121,109,0,0,0
 .globl l1006
l1006:
 .quad 6
 .byte 100,108,99,108,111,115,101,0
 .globl l1007
l1007:
 .quad 11
 .byte 117,110,105,120,45,112,114,111,102
 .byte 105,108,101,0,0,0,0
 .globl l1008
l1008:
 .quad 14
 .byte 103,101,116,102,99,111,100,101,112
 .byte 111,105,110,116,101,114,0
 .globl l1009
l1009:
 .quad 11
 .byte 99,111,100,101,97,100,100,114,101,115
 .byte 115,112,0,0,0,0
 .globl l1010
l1010:
 .quad 9
 .byte 108,97,115,116,107,101,114,110,101
 .byte 108,0,0,0,0,0,0
 .globl symfnc
 .globl symget
