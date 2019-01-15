        .text
 .long 1
@ (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 0
@ (*entry move-regs-to-mem expr 0)
 .globl l0003
l0003:
 stmdb sp!, {lr}
 sub sp, sp, #4
@ ($fluid heaplast)
 ldr r7, l0001
 str r8, [r11, r7, lsl #2]
@ ($fluid heaptrapbound)
 ldr r7, l0002
 str r9, [r11, r7, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
l0002:
 .long 269
l0001:
 .long 268
 .long 0
@ (*entry init-pointers expr 0)
 .globl l0013
l0013:
 stmdb sp!, {lr}
 sub sp, sp, #4
@ ($global catchstack)
 ldr r7, l0004
 ldr r5, [r11, r7, lsl #2]
@ ($global catchstackptr)
 ldr r7, l0005
 str r5, [r11, r7, lsl #2]
@ ($global bndstk)
 ldr r7, l0006
 ldr r5, [r11, r7, lsl #2]
@ ($global bndstklowerbound)
 ldr r7, l0007
 str r5, [r11, r7, lsl #2]
 ldr r0, l0008
@ ($global bndstk)
 ldr r7, l0006
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
@ ($global bndstkupperbound)
 ldr r7, l0009
 str r0, [r11, r7, lsl #2]
@ ($global bndstk)
 ldr r7, l0006
 ldr r5, [r11, r7, lsl #2]
@ ($global bndstkptr)
 ldr r7, l0010
 str r5, [r11, r7, lsl #2]
@ ($global heaplowerbound)
 ldr r7, l0011
 ldr r0, [r11, r7, lsl #2]
@ ($global heap)
 ldr r7, l0012
 str r0, [r11, r7, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
l0012:
 .long 276
l0011:
 .long 275
l0010:
 .long 274
l0009:
 .long 273
l0008:
 .long 79996
l0007:
 .long 272
l0006:
 .long 261
l0005:
 .long 271
l0004:
 .long 262
 .long 0
@ (*entry init-fluids expr 0)
 .globl l0038
l0038:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r12
@ ($global gcarraylowerbound)
 ldr r7, l0014
 str r0, [r11, r7, lsl #2]
@ ($global gcarrayupperbound)
 ldr r7, l0015
 str r0, [r11, r7, lsl #2]
@ ($global heaplast)
 ldr r7, l0016
 str r0, [r11, r7, lsl #2]
@ ($global oldheaplast)
 ldr r7, l0017
 str r0, [r11, r7, lsl #2]
@ ($global heaptrapbound)
 ldr r7, l0018
 str r0, [r11, r7, lsl #2]
@ ($global oldheaptrapbound)
 ldr r7, l0019
 str r0, [r11, r7, lsl #2]
@ ($global heapupperbound)
 ldr r7, l0020
 str r0, [r11, r7, lsl #2]
@ ($global _infbitlength_)
 ldr r7, l0021
 str r0, [r11, r7, lsl #2]
@ ($global lastbps)
 ldr r7, l0022
 str r0, [r11, r7, lsl #2]
@ ($global bpslowerbound)
 ldr r7, l0023
 str r0, [r11, r7, lsl #2]
@ ($global mainstartinitialize)
 ldr r7, l0024
 str r0, [r11, r7, lsl #2]
@ ($global nextbps)
 ldr r7, l0025
 str r0, [r11, r7, lsl #2]
@ ($global oldheapupperbound)
 ldr r7, l0026
 str r0, [r11, r7, lsl #2]
@ ($global oldheaplowerbound)
 ldr r7, l0027
 str r0, [r11, r7, lsl #2]
@ ($global stackupperbound)
 ldr r7, l0028
 str r0, [r11, r7, lsl #2]
@ ($global unixstdin)
 ldr r7, l0029
 str r0, [r11, r7, lsl #2]
@ ($global unixstdout)
 ldr r7, l0030
 str r0, [r11, r7, lsl #2]
@ ($global unixstderr)
 ldr r7, l0031
 str r0, [r11, r7, lsl #2]
@ ($global unixnull)
 ldr r7, l0032
 str r0, [r11, r7, lsl #2]
@ ($global unixeof)
 ldr r7, l0033
 str r0, [r11, r7, lsl #2]
@ ($global unixtty)
 ldr r7, l0034
 str r0, [r11, r7, lsl #2]
@ ($global ***must-be-nil***)
 ldr r7, l0035
 str r0, [r11, r7, lsl #2]
@ ($global ***must-be-nil-too***)
 ldr r7, l0036
 str r0, [r11, r7, lsl #2]
@ ($global *fastcar)
 ldr r7, l0037
 str r0, [r11, r7, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
l0037:
 .long 299
l0036:
 .long 298
l0035:
 .long 297
l0034:
 .long 296
l0033:
 .long 295
l0032:
 .long 294
l0031:
 .long 293
l0030:
 .long 292
l0029:
 .long 291
l0028:
 .long 290
l0027:
 .long 289
l0026:
 .long 288
l0025:
 .long 287
l0024:
 .long 286
l0023:
 .long 285
l0022:
 .long 284
l0021:
 .long 283
l0020:
 .long 282
l0019:
 .long 281
l0018:
 .long 269
l0017:
 .long 280
l0016:
 .long 268
l0015:
 .long 279
l0014:
 .long 278
 .long 0
@ (*entry _psl_main expr 0)
_psl_main:
 .globl _psl_main
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 str fp, [sp, #8]
 mov r11, r2
@ ($global symval)
 ldr r7, l0039
 str r11, [r11, r7, lsl #2]
@ ($global symfnc)
 ldr r7, l0040
 ldr r10, [r11, r7, lsl #2]
 mov r12, #256
 mov r12, r12, lsl #5
 orr r12, r12, #30
 mov r12, r12, ror #5
 mov r5, #27
@ (fluid _infbitlength_)
 ldr r7, l0041
 str r5, [r11, r7, lsl #2]
@ (idloc os_startup_hook)
 ldr r7, l0042
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r5, [sp]
@ (fluid argc)
 ldr r7, l0043
 str r5, [r11, r7, lsl #2]
 ldr r5, [sp, #4]
@ (fluid argv)
 ldr r7, l0044
 str r5, [r11, r7, lsl #2]
 ldr r5, [sp, #8]
@ (fluid ebxsave*)
 ldr r7, l0045
 str r5, [r11, r7, lsl #2]
@ (idloc init-pointers)
 ldr r7, l0046
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r3, sp
 mov r3, r3, lsr #5
@ (fluid stacklowerbound)
 ldr r7, l0047
 str r3, [r11, r7, lsl #2]
@ ($fluid heaplast)
 ldr r7, l0048
 ldr r8, [r11, r7, lsl #2]
@ ($fluid heaptrapbound)
 ldr r7, l0049
 ldr r9, [r11, r7, lsl #2]
@ (idloc init-gcarray)
 ldr r7, l0050
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc pre-main)
 ldr r7, l0051
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0055:
 mov r0, #0
 add sp, sp, #12
 ldmia sp!, {lr}
@ (idloc exit-with-status)
 ldr r7, l0052
 ldr r6, [r10, r7, lsl #2]
 bx r6
 add sp, sp, #12
 ldmia sp!, {pc}
@ (*entry exit-with-status expr 1)
 .globl l0056
l0056:
 str r0, [sp, #-4]!
@ (idloc os_cleanup_hook)
 ldr r7, l0053
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp], #4
@ (idloc external_exit)
 ldr r7, l0054
 ldr r6, [r10, r7, lsl #2]
 blx r6
 add sp, sp, #4
 ldmia sp!, {pc}
l0054:
 .long 312
l0053:
 .long 311
l0052:
 .long 310
l0051:
 .long 309
l0050:
 .long 308
l0049:
 .long 269
l0048:
 .long 268
l0047:
 .long 307
l0046:
 .long 277
l0045:
 .long 306
l0044:
 .long 305
l0043:
 .long 304
l0042:
 .long 303
l0041:
 .long 283
l0040:
 .long 302
l0039:
 .long 301
 .long 0
@ (*entry _reduceup expr 0)
 .globl _reduceup
_reduceup:
 ldr r0, [sp, #4]
 ldr r1, [sp, #8]
 ldr r2, [sp, #12]
 ldr r3, [sp, #16]
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc reduceup)
 ldr r7, l0057
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0057:
 .long 314
 .long 4
@ (*entry reduceup expr 4)
 .globl reduceup
reduceup:
 stmdb sp!, {lr}
 sub sp, sp, #20
 str r12, [sp, #12]
 str r12, [sp, #8]
 str r1, [sp, #4]
 str r3, [sp]
 mov r1, r2
@ (idloc stringopen)
 ldr r7, l0058
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #8]
 ldr r1, [sp]
 ldr r0, [sp, #4]
@ (idloc stringopen)
 ldr r7, l0058
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #12]
 ldr r5, l0059
@ ($fluid *lisp_hook)
 ldr r7, l0060
 str r5, [r11, r7, lsl #2]
 ldr r0, [sp, #8]
@ (idloc rds)
 ldr r7, l0061
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #12]
@ (idloc wrs)
 ldr r7, l0062
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc begin1)
 ldr r7, l0063
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r12
@ (idloc rds)
 ldr r7, l0061
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r12
@ (idloc wrs)
 ldr r7, l0062
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #8]
@ (idloc close)
 ldr r7, l0064
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #12]
@ (idloc close)
 ldr r7, l0064
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r12
 add sp, sp, #20
 ldmia sp!, {pc}
l0064:
 .long 321
l0063:
 .long 320
l0062:
 .long 319
l0061:
 .long 318
l0060:
 .long 317
l0059:
 .long [[30*0x8000000]+116]
l0058:
 .long 316
 .long 0
@ (*entry init-gcarray expr 0)
 .globl l0065
l0065:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r12
 add sp, sp, #4
 ldmia sp!, {pc}
l0075:
 .long 9
 .byte 108,111,97,100,45,112,115,108,46,98
 .byte 0,0
l0076:
 .long 21
 .byte 65,98,111,117,116,32,116,111,32,108
 .byte 111,97,100,32,76,79,65,68,45,80,83
 .byte 76,0,0
 .long 0
@ (*entry pre-main expr 0)
 .globl l0077
l0077:
 stmdb sp!, {lr}
 sub sp, sp, #4
@ (idloc unixcleario)
 ldr r7, l0066
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc initialize-symbol-table)
 ldr r7, l0067
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc initcode)
 ldr r7, l0068
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, l0069
@ (idloc console-print-string)
 ldr r7, l0070
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc console-newline)
 ldr r7, l0071
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, l0072
@ (idloc faslin)
 ldr r7, l0073
 ldr r6, [r10, r7, lsl #2]
 blx r6
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc loader-main)
 ldr r7, l0074
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0074:
 .long 328
l0073:
 .long 327
l0072:
 .long [[4*0x8000000]+l0075]
l0071:
 .long 326
l0070:
 .long 325
l0069:
 .long [[4*0x8000000]+l0076]
l0068:
 .long 324
l0067:
 .long 323
l0066:
 .long 322
 .long 1
@ (*entry console-print-string expr 1)
 .globl l0079
l0079:
 stmdb sp!, {lr}
 sub sp, sp, #4
 bic r0, r0, #4160749568
 add r0, r0, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc unixputs)
 ldr r7, l0078
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0078:
 .long 329
 .long 1
@ (*entry console-print-number expr 1)
 .globl l0081
l0081:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc unixputn)
 ldr r7, l0080
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0080:
 .long 330
 .long 0
@ (*entry console-newline expr 0)
 .globl l0083
l0083:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, #10
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc unixputc)
 ldr r7, l0082
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0082:
 .long 332
l0088:
 .long 34
 .byte 67,111,117,108,100,110,39,116,32,111
 .byte 112,101,110,32,98,105,110,97,114,121
 .byte 32,102,105,108,101,32,102,111,114,32
 .byte 105,110,112,117,116,0
l0089:
 .long 0
 .byte 114,0,0,0
 .long 1
@ (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r1, l0084
 bic r1, r1, #4160749568
 add r1, r1, #4
 bic r0, r0, #4160749568
 add r0, r0, #4
@ (idloc unixopen)
 ldr r7, l0085
 ldr r6, [r10, r7, lsl #2]
 blx r6
 cmp r0, #0
 bne l0090
 ldr r0, l0086
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc kernel-fatal-error)
 ldr r7, l0087
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0090:
 add sp, sp, #4
 ldmia sp!, {pc}
l0087:
 .long 334
l0086:
 .long [[4*0x8000000]+l0088]
l0085:
 .long 333
l0084:
 .long [[4*0x8000000]+l0089]
 .long 1
@ (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc getw)
 ldr r7, l0091
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0091:
 .long 336
 .long 3
@ (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r4, r1
 mov r3, r0
 mov r1, #4
 mov r0, r4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc fread)
 ldr r7, l0092
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0092:
 .long 338
 .long 1
@ (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc fclose)
 ldr r7, l0093
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0093:
 .long 340
 .long 0
@ (*entry initialize-symbol-table expr 0)
 .globl l0102
l0102:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r12, [sp, #4]
 str r12, [sp]
 ldr r1, l0094
@ ($global nextsymbol)
 ldr r7, l0095
 ldr r0, [r11, r7, lsl #2]
 mov r3, r0
 mov r2, r1
l0103:
 cmp r3, r2
 bgt l0104
 mov r0, r3
 mov r0, r0, lsl #2
@ ($global symnam)
 ldr r7, l0096
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 mov r1, #1
 add r1, r1, r3
 str r1, [r0]
 add r3, r3, #1
 b l0103
l0104:
@ ($global symnam)
 ldr r7, l0096
 ldr r6, [r11, r7, lsl #2]
 ldr r7, l0097
 add r6, r6, r7
 mov r5, #0
 str r5, [r6]
 ldr r1, l0098
 mov r0, #0
 mov r3, r0
 mov r2, r1
l0105:
 cmp r3, r2
 bgt l0106
 mov r0, r3
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0099
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 mov r5, #0
 str r5, [r0]
 add r3, r3, #1
 b l0105
l0106:
@ ($global symnam)
 ldr r7, l0096
 ldr r5, [r11, r7, lsl #2]
 ldr r0, [r5, #1024]
@ (idloc hash-into-table)
 ldr r7, l0100
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0099
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 mov r5, #256
 str r5, [r0]
 mvn r1, #0
@ ($global nextsymbol)
 ldr r7, l0095
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
 mov r0, #256
 str r0, [sp]
 str r1, [sp, #4]
l0107:
 ldr r5, [sp]
 ldr r6, [sp, #4]
 cmp r5, r6
 bgt l0108
 ldr r0, [sp]
 mov r0, r0, lsl #2
@ ($global symnam)
 ldr r7, l0096
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
@ (idloc hash-into-table)
 ldr r7, l0100
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0099
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r5, [sp]
 str r5, [r0]
 ldr r6, [sp]
 add r6, r6, #1
 str r6, [sp]
 b l0107
l0108:
 mov r0, r12
@ ($global show-new-ids)
 ldr r7, l0101
 str r0, [r11, r7, lsl #2]
 add sp, sp, #12
 ldmia sp!, {pc}
l0101:
 .long 345
l0100:
 .long 344
l0099:
 .long 263
l0098:
 .long 393241
l0097:
 .long 1200000
l0096:
 .long 343
l0095:
 .long 342
l0094:
 .long 300000
 .long 1
@ (*entry faslin-intern expr 1)
 .globl l0112
l0112:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r12, [sp, #8]
 str r12, [sp, #4]
 str r0, [sp]
 mov r1, r0
 mov r0, #0
@ (idloc search-string-for-character)
 ldr r7, l0109
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #4]
 cmp r0, r12
 bne l0113
 ldr r0, [sp]
 add sp, sp, #12
 ldmia sp!, {lr}
@ (idloc intern)
 ldr r7, l0110
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0113:
 ldr r0, [sp]
 bic r0, r0, #4160749568
 ldr r7, [r0]
 mov r0, r7, lsl #5
 mov r0, r0, asr #5
 str r0, [sp, #8]
 ldr r7, [sp, #4]
 cmp r0, r7
 ble l0114
 mov r1, #1
 ldr r7, [sp, #4]
 add r1, r1, r7
 ldr r0, [sp]
 bic r0, r0, #4160749568
 add r0, r0, #4
 ldrsb r0, [r0, r1]
 cmp r0, #0
 bne l0114
 ldr r6, [sp, #4]
 add r6, r6, #1
 str r6, [sp, #4]
l0114:
 ldr r5, [sp, #4]
 ldr r6, [sp, #8]
 cmp r5, r6
 blt l0115
 ldr r0, [sp]
 b l0116
l0115:
 ldr r2, [sp]
 bic r2, r2, #4160749568
 ldr r7, [r2]
 mov r2, r7, lsl #5
 mov r2, r2, asr #5
 add r2, r2, #1
 mov r1, #1
 ldr r7, [sp, #4]
 add r1, r1, r7
 ldr r0, [sp]
@ (idloc subseq)
 ldr r7, l0111
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0116:
 add sp, sp, #12
 ldmia sp!, {lr}
@ (idloc intern)
 ldr r7, l0110
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0111:
 .long 348
l0110:
 .long 347
l0109:
 .long 346
 .long 1
@ (*entry intern expr 1)
 .globl intern
intern:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc unchecked-string-intern)
 ldr r7, l0117
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0117:
 .long 350
l0130:
 .long 7
 .byte 78,101,119,32,105,100,58,32,0,0,0,0
l0131:
 .long 0
 .long 2147483647
 .long 1
@ (*entry unchecked-string-intern expr 1)
 .globl l0132
l0132:
 stmdb sp!, {lr}
 sub sp, sp, #28
 str r0, [sp]
 mov r4, r12
 mov r3, r4
 mov r2, r4
 bic r1, r0, #4160749568
 ldr r7, [r1]
 mov r1, r7, lsl #5
 mov r1, r1, asr #5
 bic r0, r0, #4160749568
 str r0, [sp, #4]
 str r1, [sp, #8]
 str r2, [sp, #12]
 str r3, [sp, #16]
 str r4, [sp, #20]
 cmp r1, #0
 bne l0133
 add r0, r0, #4
 ldrsb r0, [r0, r1]
 mov r0, r0, lsl #5
 orr r0, r0, #30
 mov r0, r0, ror #5
 b l0134
l0133:
 ldr r0, [sp]
@ (idloc hash-into-table)
 ldr r7, l0118
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #12]
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0119
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
 mov r1, r0
 ldr r7, l0120
 cmp r0, r7
 ble l0135
 mov r0, r12
 b l0136
l0135:
 ldr r0, l0121
l0136:
 cmp r0, r12
 beq l0137
 ldr r0, l0121
 cmp r1, #0
 bgt l0137
 add r0, r0, #140
l0137:
 cmp r0, r12
 beq l0138
 ldr r0, [sp, #12]
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0119
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
 mov r0, r0, lsl #5
 orr r0, r0, #30
 mov r0, r0, ror #5
 b l0134
l0138:
@ ($global show-new-ids)
 ldr r7, l0122
 ldr r7, [r11, r7, lsl #2]
 cmp r0, r7
 beq l0139
 ldr r0, l0123
@ (idloc console-print-string)
 ldr r7, l0124
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp]
@ (idloc console-print-string)
 ldr r7, l0124
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc console-newline)
 ldr r7, l0125
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0139:
@ (idloc gtid)
 ldr r7, l0126
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #20]
 ldr r1, [sp, #12]
 mov r1, r1, lsl #2
@ ($fluid hashtable)
 ldr r7, l0119
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
 str r0, [r1]
 ldr r0, [sp, #8]
@ (idloc gtconststr)
 ldr r7, l0127
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #16]
 ldr r1, [sp, #4]
@ (idloc copystringtofrom)
 ldr r7, l0128
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r1, [sp, #16]
 mov r1, r1, lsl #5
 orr r1, r1, #4
 mov r1, r1, ror #5
 ldr r0, [sp, #20]
 add sp, sp, #28
 ldmia sp!, {lr}
@ (idloc initialize-new-id)
 ldr r7, l0129
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0134:
 add sp, sp, #28
 ldmia sp!, {pc}
l0129:
 .long 354
l0128:
 .long 353
l0127:
 .long 352
l0126:
 .long 351
l0125:
 .long 326
l0124:
 .long 325
l0123:
 .long [[4*0x8000000]+l0130]
l0122:
 .long 345
l0121:
 .long [[30*0x8000000]+116]
l0120:
 .long [[1*0x8000000]+l0131]
l0119:
 .long 263
l0118:
 .long 344
l0148:
 .long 18
 .byte 72,97,115,104,32,116,97,98,108,101
 .byte 32,111,118,101,114,102,108,111,119
 .byte 0
l0149:
 .long 0
 .long 4294967295
 .long 1
@ (*entry hash-into-table expr 1)
 .globl l0150
l0150:
 stmdb sp!, {lr}
 sub sp, sp, #20
 str r12, [sp, #12]
 str r12, [sp, #8]
 str r12, [sp, #4]
 str r0, [sp]
@ (idloc hash-function)
 ldr r7, l0140
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #4]
 str r0, [sp, #8]
 mvn r5, #0
 str r5, [sp, #12]
l0151:
 ldr r0, [sp, #8]
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0141
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 mov r5, #0
 ldr r6, [r0]
 cmp r5, r6
 bne l0152
 ldr r5, [sp, #12]
 mvn r6, #0
 cmp r5, r6
 beq l0153
 ldr r0, [sp, #12]
 b l0154
l0153:
 ldr r0, [sp, #8]
l0154:
 b l0155
l0152:
 ldr r1, [sp, #8]
 mov r1, r1, lsl #2
@ ($fluid hashtable)
 ldr r7, l0141
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
 ldr r5, l0142
 ldr r6, [r1]
 cmp r5, r6
 bne l0156
 ldr r5, [sp, #12]
 mvn r6, #0
 cmp r5, r6
 bne l0157
 ldr r5, [sp, #8]
 str r5, [sp, #12]
 b l0157
l0156:
 ldr r1, [sp]
 ldr r0, [sp, #8]
 mov r0, r0, lsl #2
@ ($fluid hashtable)
 ldr r7, l0141
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
 mov r0, r0, lsl #2
@ ($global symnam)
 ldr r7, l0143
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
@ (idloc unchecked-string-equal)
 ldr r7, l0144
 ldr r6, [r10, r7, lsl #2]
 blx r6
 cmp r0, r12
 beq l0157
 ldr r0, [sp, #8]
 b l0155
l0157:
 ldr r5, [sp, #8]
 ldr r6, l0145
 cmp r5, r6
 bne l0158
 mov r0, #0
 b l0159
l0158:
 mov r0, #1
 ldr r7, [sp, #8]
 add r0, r0, r7
l0159:
 str r0, [sp, #8]
 ldr r7, [sp, #4]
 cmp r0, r7
 bne l0151
 ldr r0, l0146
@ (idloc kernel-fatal-error)
 ldr r7, l0147
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0151
l0155:
 add sp, sp, #20
 ldmia sp!, {pc}
l0147:
 .long 334
l0146:
 .long [[4*0x8000000]+l0148]
l0145:
 .long 393241
l0144:
 .long 356
l0143:
 .long 343
l0142:
 .long [[1*0x8000000]+l0149]
l0141:
 .long 263
l0140:
 .long 355
 .long 2
@ (*entry initialize-new-id expr 2)
 .globl l0165
l0165:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 mov r0, r0, lsl #5
 orr r0, r0, #30
 mov r0, r0, ror #5
 str r0, [sp, #4]
 ldr r2, [sp]
 mov r2, r2, lsl #2
@ ($global symnam)
 ldr r7, l0160
 ldr r7, [r11, r7, lsl #2]
 add r2, r2, r7
 str r1, [r2]
 ldr r3, [sp]
 mov r3, r3, lsl #2
@ ($global symprp)
 ldr r7, l0161
 ldr r7, [r11, r7, lsl #2]
 add r3, r3, r7
 mov r4, r12
 str r4, [r3]
 ldr r0, [sp]
 mov r0, r0, lsl #2
@ ($global symget)
 ldr r7, l0162
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 str r4, [r0]
 ldr r0, [sp]
 mov r0, r0, lsl #2
 add r0, r0, r11
 ldr r1, [sp]
 mov r1, r1, lsl #5
 orr r1, r1, #29
 mov r1, r1, ror #5
 str r1, [r0]
 ldr r0, [sp]
@ (idloc plantunbound)
 ldr r7, l0164
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #4]
 add sp, sp, #12
 ldmia sp!, {pc}
l0164:
 .long 359
l0163:
 .long [[30*0x8000000]+360]
l0162:
 .long 358
l0161:
 .long 357
l0160:
 .long 343
 .long 1
@ (*entry hash-function expr 1)
 .globl l0170
l0170:
 stmdb sp!, {lr}
 sub sp, sp, #12
 bic r0, r0, #4160749568
 str r0, [sp, #4]
 ldr r7, [r0]
 mov r0, r7, lsl #5
 mov r0, r0, asr #5
 str r0, [sp]
 mov r0, #0
 str r0, [sp, #8]
 ldr r7, [sp]
 cmp r7, #24
 ble l0171
 mov r5, #24
 str r5, [sp]
l0171:
 ldr r1, [sp]
 mov r0, #0
 mov r4, r0
 mov r3, r1
l0172:
 cmp r4, r3
 bgt l0173
 mov r1, r4
 mov r0, #4
 ldr r7, [sp, #4]
 add r0, r0, r7
 ldrsb r0, [r0, r1]
 mov r2, #24
 sub r2, r2, r1
 cmp r2, #0
 bge l0166
 rsb r6, r2, #0
 mov r0, r0, lsr r6
 b l0167
l0166:
 mov r0, r0, lsl r2
l0167:
 ldr r6, [sp, #8]
 eor r0, r0, r6
 str r0, [sp, #8]
 add r4, r4, #1
 b l0172
l0173:
 ldr r1, l0168
 ldr r0, [sp, #8]
 add sp, sp, #12
 ldmia sp!, {lr}
@ (idloc wremainder)
 ldr r7, l0169
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0169:
 .long 361
l0168:
 .long 393241
 .long 1
@ (*entry faslin expr 1)
 .globl faslin
faslin:
 stmdb sp!, {lr}
 sub sp, sp, #44
 str r12, [sp, #32]
 str r12, [sp, #12]
 str r12, [sp, #8]
 str r0, [sp]
 str r12, [sp, #16]
 str r12, [sp, #24]
 str r12, [sp, #28]
 str r12, [sp, #40]
 str r12, [sp, #4]
 str r12, [sp, #20]
 str r12, [sp, #36]
@ (idloc binaryopenread)
 ldr r7, l0174
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #8]
@ (idloc binaryread)
 ldr r7, l0175
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #12]
 mov r1, #255
 add r1, r1, #65280
 and r1, r1, r0
 mov r7, #143
 add r7, r7, #256
 cmp r1, r7
 beq l0187
 ldr r0, [sp, #8]
@ (idloc binaryclose)
 ldr r7, l0176
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp]
@ (idloc faslin-bad-file)
 ldr r7, l0177
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0188
l0187:
 ldr r0, [sp, #12]
 mov r0, r0, lsr #16
 str r0, [sp, #12]
 ldr r0, [sp, #8]
@ (idloc read-id-table)
 ldr r7, l0178
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #16]
 ldr r0, [sp, #8]
@ (idloc binaryread)
 ldr r7, l0175
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #24]
@ (idloc gtbps)
 ldr r7, l0179
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #28]
 mov r0, #0
@ (idloc gtbps)
 ldr r7, l0179
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #36]
 ldr r0, [sp, #8]
@ (idloc binaryread)
 ldr r7, l0175
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r1, [sp, #28]
 add r1, r1, r0
 str r1, [sp, #40]
 ldr r2, [sp, #24]
 mov r1, #0
 ldr r7, [sp, #28]
 add r1, r1, r7
 ldr r0, [sp, #8]
@ (idloc binaryreadblock)
 ldr r7, l0180
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #8]
@ (idloc binaryread)
 ldr r7, l0175
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #4]
@ (idloc gtwrds)
 ldr r7, l0181
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r1, r0
 mov r1, r1, lsl #5
 orr r1, r1, #7
 mov r1, r1, ror #5
 str r1, [sp, #20]
 ldr r2, [sp, #4]
 bic r1, r1, #4160749568
 add r1, r1, #4
 ldr r0, [sp, #8]
@ (idloc binaryreadblock)
 ldr r7, l0180
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #8]
@ (idloc binaryclose)
 ldr r7, l0176
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, #1
 ldr r6, [sp, #12]
 and r0, r0, r6
 cmp r0, #1
 bne l0189
 ldr r3, [sp, #16]
 ldr r2, [sp, #20]
 ldr r1, [sp, #24]
 ldr r0, [sp, #28]
@ (idloc do-relocation-new)
 ldr r7, l0182
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0190
l0189:
 ldr r3, [sp, #16]
 ldr r2, [sp, #20]
 ldr r1, [sp, #24]
 ldr r0, [sp, #28]
@ (idloc do-relocation)
 ldr r7, l0183
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0190:
@ ($fluid code-base-hack)
 ldr r7, l0184
 ldr r0, [r11, r7, lsl #2]
 str r0, [sp, #32]
 ldr r5, [sp, #28]
@ ($fluid code-base-hack)
 ldr r7, l0184
 str r5, [r11, r7, lsl #2]
 ldr r0, [sp, #40]
@ (idloc addressapply0)
 ldr r7, l0185
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r5, [sp, #32]
@ ($fluid code-base-hack)
 ldr r7, l0184
 str r5, [r11, r7, lsl #2]
 ldr r1, [sp, #36]
 ldr r0, [sp, #40]
@ (idloc delbps)
 ldr r7, l0186
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0188:
 mov r0, r12
 add sp, sp, #44
 ldmia sp!, {pc}
l0186:
 .long 370
l0185:
 .long 369
l0184:
 .long 368
l0183:
 .long 367
l0182:
 .long 366
l0181:
 .long 365
l0180:
 .long 339
l0179:
 .long 364
l0178:
 .long 363
l0177:
 .long 362
l0176:
 .long 341
l0175:
 .long 337
l0174:
 .long 335
 .long 2
@ (*entry delbps expr 2)
 .globl delbps
delbps:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r12
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 4
@ (*entry do-relocation expr 4)
 .globl l0195
l0195:
 stmdb sp!, {lr}
 sub sp, sp, #28
 str r12, [sp, #16]
 str r0, [sp, #12]
 str r2, [sp, #4]
 str r3, [sp, #8]
 mov r0, r1
 mov r0, r0, lsl #2
 mvn r1, #0
 add r1, r1, r0
 mov r0, #0
 str r0, [sp, #20]
 str r1, [sp]
l0196:
 ldr r5, [sp, #20]
 ldr r6, [sp]
 cmp r5, r6
 ble l0197
 mov r0, r12
 b l0198
l0197:
 ldr r1, [sp, #20]
 ldr r0, [sp, #4]
 mov r0, r0, lsl #5
 orr r0, r0, #1
 mov r0, r0, ror #5
 add r0, r0, #4
@ (idloc bittable)
 ldr r7, l0191
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r1, [sp, #12]
 ldr r7, [sp, #20]
 add r1, r1, r7
 str r1, [sp, #16]
 cmp r0, #1
 beq l0199
 cmp r0, #2
 beq l0200
 cmp r0, #3
 beq l0201
 b l0202
l0199:
 ldr r2, [sp, #8]
 ldr r1, [sp, #12]
 ldr r0, [sp, #16]
@ (idloc relocate-word)
 ldr r7, l0192
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0202
l0201:
 ldr r2, [sp, #8]
 ldr r1, [sp, #12]
 ldr r0, [sp, #16]
@ (idloc relocate-inf)
 ldr r7, l0193
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0202
l0200:
 ldr r2, [sp, #8]
 ldr r1, [sp, #12]
 ldr r0, [sp, #16]
@ (idloc relocate-right-half)
 ldr r7, l0194
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0202:
 ldr r6, [sp, #20]
 add r6, r6, #1
 str r6, [sp, #20]
 b l0196
l0198:
 add sp, sp, #28
 ldmia sp!, {pc}
l0194:
 .long 374
l0193:
 .long 373
l0192:
 .long 372
l0191:
 .long 371
 .long 4
@ (*entry do-relocation-new expr 4)
 .globl l0206
l0206:
 stmdb sp!, {lr}
 sub sp, sp, #28
 str r12, [sp, #8]
 str r0, [sp, #16]
 str r2, [sp]
 str r3, [sp, #12]
 mov r2, r12
 mov r1, r0
 mov r0, #0
 str r0, [sp, #4]
 str r1, [sp, #20]
 ldr r4, [sp]
 bic r4, r4, #4160749568
 add r4, r4, #4
 str r4, [sp]
l0207:
 ldr r1, [sp, #4]
 ldr r0, [sp]
 ldrsb r0, [r0, r1]
 and r0, r0, #255
 str r0, [sp, #8]
 cmp r0, #0
 bne l0208
 mov r0, r12
 b l0209
l0208:
 ldr r6, [sp, #4]
 add r6, r6, #1
 str r6, [sp, #4]
 mov r0, #63
 ldr r6, [sp, #8]
 and r0, r0, r6
 ldr r7, [sp, #20]
 add r0, r0, r7
 str r0, [sp, #20]
 ldr r1, [sp, #8]
 mov r1, r1, lsr #6
 str r1, [sp, #8]
 mov r0, r1
 cmp r0, #1
 beq l0210
 cmp r0, #2
 beq l0211
 cmp r0, #3
 beq l0212
 b l0207
l0210:
 ldr r2, [sp, #12]
 ldr r1, [sp, #16]
 ldr r0, [sp, #20]
@ (idloc relocate-word)
 ldr r7, l0203
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0207
l0212:
 ldr r2, [sp, #12]
 ldr r1, [sp, #16]
 ldr r0, [sp, #20]
@ (idloc relocate-inf)
 ldr r7, l0204
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0207
l0211:
 ldr r2, [sp, #12]
 ldr r1, [sp, #16]
 ldr r0, [sp, #20]
@ (idloc relocate-right-half)
 ldr r7, l0205
 ldr r6, [r10, r7, lsl #2]
 blx r6
 b l0207
l0209:
 add sp, sp, #28
 ldmia sp!, {pc}
l0205:
 .long 374
l0204:
 .long 373
l0203:
 .long 372
 .long 3
@ (*entry relocate-word expr 3)
 .globl l0214
l0214:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 ldr r7, [r0]
 mov r1, r7, lsl #2
 mov r1, r1, lsr #2
 ldr r7, [r0]
 mov r0, r7, lsr #30
 mov r3, r2
 ldr r2, [sp, #4]
@ (idloc compute-relocation)
 ldr r7, l0213
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r6, [sp]
 str r0, [r6]
 add sp, sp, #12
 ldmia sp!, {pc}
l0213:
 .long 375
 .long 3
@ (*entry relocate-inf expr 3)
 .globl l0216
l0216:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 ldr r7, [r0]
 mov r1, r7, lsl #10
 mov r1, r1, lsr #10
 ldr r7, [r0]
 mov r0, r7, lsl #8
 mov r0, r0, lsr #30
 mov r3, r2
 ldr r2, [sp, #4]
@ (idloc compute-relocation)
 ldr r7, l0215
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r6, [sp]
 ldr r5, [r6]
 and r5, r5, #4160749568
 bic r0, r0, #4160749568
 orr r5, r5, r0
 str r5, [r6]
 add sp, sp, #12
 ldmia sp!, {pc}
l0215:
 .long 375
 .long 3
@ (*entry relocate-right-half expr 3)
 .globl l0219
l0219:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 ldr r7, [r0]
 mov r1, r7, lsl #2
 mov r1, r1, lsr #18
 ldr r7, [r0]
 mov r0, r7, lsr #30
 mov r3, r2
 ldr r2, [sp, #4]
@ (idloc compute-relocation)
 ldr r7, l0217
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r6, [sp]
 ldr r5, [r6]
 mov r0, r0, lsl #16
 ldr r6, l0218
 and r5, r5, r6
 orr r0, r0, r5
 str r5, [r6]
 add sp, sp, #12
 ldmia sp!, {pc}
l0218:
 .long 65535
l0217:
 .long 375
 .long 4
@ (*entry compute-relocation expr 4)
 .globl l0224
l0224:
 stmdb sp!, {lr}
 str r1, [sp, #-4]!
 cmp r0, #0
 bne l0225
 mov r0, r2
 add r0, r0, r1
 b l0226
l0225:
 cmp r0, #2
 bne l0227
 mov r7, #214
 add r7, r7, #7936
 cmp r1, r7
 blt l0228
 ldr r0, l0220
 add r0, r0, r1
 mov r0, r0, lsl #2
@ ($fluid argumentblock)
 ldr r7, l0221
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 b l0226
l0228:
 cmp r1, #2048
 blt l0229
 mov r1, r3
 ldr r0, [sp]
@ (idloc local-to-global-id)
 ldr r7, l0222
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r0, lsl #2
 add r0, r0, r11
 b l0226
l0229:
 mov r0, r1
 mov r0, r0, lsl #2
 add r0, r0, r11
 b l0226
l0227:
 cmp r0, #3
 bne l0230
 cmp r1, #2048
 blt l0231
 mov r1, r3
 ldr r0, [sp]
@ (idloc local-to-global-id)
 ldr r7, l0222
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp]
l0231:
 ldr r0, [sp]
 mov r0, r0, lsl #2
 add r0, r0, r10
 b l0226
l0230:
 cmp r0, #1
 bne l0232
 cmp r1, #2048
 blt l0233
 mov r1, r3
 ldr r0, [sp]
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc local-to-global-id)
 ldr r7, l0222
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0233:
 mov r0, r1
 b l0226
l0232:
 mov r0, r12
l0226:
 add sp, sp, #4
 ldmia sp!, {pc}
l0223:
 .long [[30*0x8000000]+360]
l0222:
 .long 376
l0221:
 .long 259
l0220:
 .long -8156
 .long 2
@ (*entry local-to-global-id expr 2)
 .globl l0234
l0234:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r7, #255
 add r7, r7, #1792
 sub r0, r0, r7
 mov r0, r0, lsl #2
 bic r2, r1, #4160749568
 add r0, r0, r2
 ldr r0, [r0]
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 1
@ (*entry read-id-table expr 1)
 .globl l0240
l0240:
 stmdb sp!, {lr}
 sub sp, sp, #28
 str r12, [sp, #20]
 str r12, [sp, #16]
 str r12, [sp, #12]
 str r12, [sp, #8]
 str r12, [sp, #4]
 str r0, [sp]
@ (idloc binaryread)
 ldr r7, l0235
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #4]
 add r0, r0, #1
@ (idloc gtwrds)
 ldr r7, l0236
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, r0, lsl #5
 orr r0, r0, #7
 mov r0, r0, ror #5
 str r0, [sp, #8]
 ldr r1, [sp, #4]
 mov r0, #0
 str r0, [sp, #12]
 str r1, [sp, #16]
l0241:
 ldr r5, [sp, #12]
 ldr r6, [sp, #16]
 cmp r5, r6
 bgt l0242
 ldr r0, [sp]
@ (idloc binaryread)
 ldr r7, l0235
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ ($fluid tokenbuffer)
 ldr r7, l0237
 ldr r6, [r11, r7, lsl #2]
 str r0, [r6]
 mov r2, #5
 add r2, r2, r0
 mov r1, r2
 mov r1, r1, lsr #30
 add r2, r2, r1
 mov r2, r2, asr #2
 mov r1, #4
@ ($fluid tokenbuffer)
 ldr r7, l0237
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
 ldr r0, [sp]
@ (idloc binaryreadblock)
 ldr r7, l0238
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, #0
@ ($fluid tokenbuffer)
 ldr r7, l0237
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 mov r0, r0, lsl #5
 orr r0, r0, #4
 mov r0, r0, ror #5
@ (idloc faslin-intern)
 ldr r7, l0239
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #20]
 mov r0, #1
 ldr r7, [sp, #12]
 add r0, r0, r7
 mov r0, r0, lsl #2
 ldr r1, [sp, #8]
 bic r1, r1, #4160749568
 add r0, r0, r1
 ldr r2, [sp, #20]
 bic r2, r2, #4160749568
 str r2, [r0]
 ldr r6, [sp, #12]
 add r6, r6, #1
 str r6, [sp, #12]
 b l0241
l0242:
 ldr r0, [sp, #8]
 add sp, sp, #28
 ldmia sp!, {pc}
l0239:
 .long 349
l0238:
 .long 339
l0237:
 .long 260
l0236:
 .long 365
l0235:
 .long 337
 .long 3
@ (*entry putentry expr 3)
 .globl putentry
putentry:
 stmdb sp!, {lr}
 sub sp, sp, #4
@ ($fluid code-base-hack)
 ldr r7, l0243
 ldr r7, [r11, r7, lsl #2]
 add r2, r2, r7
 mov r2, r2, lsl #5
 orr r2, r2, #20
 mov r2, r2, ror #5
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc putd)
 ldr r7, l0244
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0244:
 .long 377
l0243:
 .long 368
l0248:
 .long 22
 .byte 70,105,108,101,32,105,115,32,110,111
 .byte 116,32,70,65,83,76,32,102,111,114,109
 .byte 97,116,0
 .long 1
@ (*entry faslin-bad-file expr 1)
 .globl l0249
l0249:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r0, l0245
@ (idloc console-print-string)
 ldr r7, l0246
 ldr r6, [r10, r7, lsl #2]
 blx r6
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc console-newline)
 ldr r7, l0247
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0247:
 .long 326
l0246:
 .long 325
l0245:
 .long [[4*0x8000000]+l0248]
l0258:
 .long 30
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,98,105,110,97,114,121,32,112,114
 .byte 111,103,114,97,109,32,115,112,97,99
 .byte 101,0
 .long 1
@ (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 stmdb sp!, {lr}
 sub sp, sp, #4
l0259:
 str r0, [sp]
 cmp r0, r12
 bne l0260
@ (idloc gtbps-nil-error)
 ldr r7, l0250
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0260:
 ldr r7, [sp]
 cmp r7, #10
 ble l0261
 mov r0, #15
@ ($global nextbps)
 ldr r7, l0251
 ldr r6, [r11, r7, lsl #2]
 and r0, r0, r6
 cmp r0, #0
 beq l0261
@ ($global nextbps)
 ldr r7, l0251
 ldr r1, [r11, r7, lsl #2]
 mov r1, r1, lsr #4
 mov r1, r1, lsl #4
 add r1, r1, #16
@ ($global nextbps)
 ldr r7, l0251
 str r1, [r11, r7, lsl #2]
l0261:
@ ($global nextbps)
 ldr r7, l0251
 ldr r0, [r11, r7, lsl #2]
 ldr r1, [sp]
 mov r1, r1, lsl #2
@ ($global nextbps)
 ldr r7, l0251
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
@ ($global nextbps)
 ldr r7, l0251
 str r1, [r11, r7, lsl #2]
@ ($global lastbps)
 ldr r7, l0252
 ldr r7, [r11, r7, lsl #2]
 cmp r1, r7
 ble l0262
@ ($global nextbps)
 ldr r7, l0251
 str r0, [r11, r7, lsl #2]
 ldr r0, l0253
@ (idloc getd)
 ldr r7, l0254
 ldr r6, [r10, r7, lsl #2]
 blx r6
 cmp r0, r12
 beq l0263
 ldr r0, [sp]
@ (idloc try-other-bps-spaces)
 ldr r7, l0255
 ldr r6, [r10, r7, lsl #2]
 blx r6
 cmp r0, r12
 beq l0263
 ldr r0, [sp]
 b l0259
l0263:
 ldr r0, l0256
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc stderror)
 ldr r7, l0257
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0262:
 add sp, sp, #4
 ldmia sp!, {pc}
l0257:
 .long 382
l0256:
 .long [[4*0x8000000]+l0258]
l0255:
 .long 381
l0254:
 .long 380
l0253:
 .long [[30*0x8000000]+381]
l0252:
 .long 284
l0251:
 .long 287
l0250:
 .long 379
l0266:
 .long 21
 .byte 71,84,66,80,83,32,99,97,108,108,101
 .byte 100,32,119,105,116,104,32,78,73,76
 .byte 46,0,0
 .long 1
@ (*entry gtbps-nil-error expr 1)
 .globl l0267
l0267:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r0, l0264
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc stderror)
 ldr r7, l0265
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0265:
 .long 382
l0264:
 .long [[4*0x8000000]+l0266]
 .long 1
@ (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 stmdb sp!, {lr}
 sub sp, sp, #4
 cmp r0, r12
 bne l0270
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc known-free-space)
 ldr r7, l0268
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0270:
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc real-gtheap)
 ldr r7, l0269
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0269:
 .long 384
l0268:
 .long 383
 .long 1
@ (*entry real-gtheap expr 1)
 .globl l0273
l0273:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r2, r0
 mov r0, r8
 mov r1, r2
 mov r1, r1, lsl #2
 add r1, r1, r8
 mov r8, r1
 cmp r1, r9
 blt l0274
 mov r1, r2
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc get-heap-trap)
 ldr r7, l0272
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0274:
 add sp, sp, #4
 ldmia sp!, {pc}
l0272:
 .long 386
l0271:
 .long [[30*0x8000000]+360]
l0277:
 .long 27
 .byte 71,97,114,98,97,103,101,32,99,111,108
 .byte 108,101,99,116,105,111,110,32,114,101
 .byte 113,117,105,114,101,100,46,0,0,0,0
 .long 1
@ (*entry get-heap-trap expr 1)
 .globl l0278
l0278:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r0, l0275
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc kernel-fatal-error)
 ldr r7, l0276
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0276:
 .long 334
l0275:
 .long [[4*0x8000000]+l0277]
l0284:
 .long 18
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,73,68,32,115,112,97,99,101,0
 .long 0
@ (*entry gtid expr 0)
 .globl gtid
gtid:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r5, #0
@ ($global nextsymbol)
 ldr r7, l0279
 ldr r6, [r11, r7, lsl #2]
 cmp r5, r6
 bne l0285
@ (idloc reclaim)
 ldr r7, l0280
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r5, #0
@ ($global nextsymbol)
 ldr r7, l0279
 ldr r6, [r11, r7, lsl #2]
 cmp r5, r6
 bne l0285
 ldr r0, l0281
@ (idloc kernel-fatal-error)
 ldr r7, l0282
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0285:
@ ($global nextsymbol)
 ldr r7, l0279
 ldr r0, [r11, r7, lsl #2]
 mov r1, r0
 mov r1, r1, lsl #2
@ ($global symnam)
 ldr r7, l0283
 ldr r7, [r11, r7, lsl #2]
 add r1, r1, r7
 ldr r5, [r1]
@ ($global nextsymbol)
 ldr r7, l0279
 str r5, [r11, r7, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
l0283:
 .long 343
l0282:
 .long 334
l0281:
 .long [[4*0x8000000]+l0284]
l0280:
 .long 387
l0279:
 .long 342
 .long 1
@ (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 stmdb sp!, {lr}
 str r0, [sp, #-4]!
 add r0, r0, #2
@ (idloc gtheap)
 ldr r7, l0286
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r1, [sp]
 mov r1, r1, lsl #5
 orr r1, r1, #25
 mov r1, r1, ror #5
 str r1, [r0]
 add sp, sp, #4
 ldmia sp!, {pc}
l0286:
 .long 385
 .long 1
@ (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 add r0, r0, #5
 mov r1, r0
 mov r1, r1, lsr #30
 add r0, r0, r1
 mov r0, r0, asr #2
 str r0, [sp, #4]
 add r0, r0, #1
@ (idloc gtbps)
 ldr r7, l0287
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r5, [sp]
 str r5, [r0]
 ldr r1, [sp, #4]
 mov r1, r1, lsl #2
 add r1, r1, r0
 mov r5, #0
 str r5, [r1]
 add sp, sp, #12
 ldmia sp!, {pc}
l0287:
 .long 364
l0291:
 .long 30
 .byte 83,85,66,83,69,81,32,99,97,108,108
 .byte 101,100,32,119,105,116,104,32,97,32
 .byte 110,111,110,45,115,116,114,105,110
 .byte 103,0
 .long 3
@ (*entry subseq expr 3)
 .globl subseq
subseq:
 stmdb sp!, {lr}
 sub sp, sp, #28
 str r12, [sp, #20]
 str r12, [sp, #16]
 str r12, [sp, #12]
 str r0, [sp]
 str r1, [sp, #4]
 str r2, [sp, #8]
 mov r7, r0, lsr #27
 cmp r7, #4
 beq l0292
 ldr r0, l0288
@ (idloc kernel-fatal-error)
 ldr r7, l0289
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0292:
 mvn r0, #0
 ldr r7, [sp, #8]
 add r0, r0, r7
 ldr r7, [sp, #4]
 sub r0, r0, r7
 str r0, [sp, #12]
 ldr r0, [sp]
 bic r0, r0, #4160749568
 str r0, [sp, #16]
 ldr r0, [sp, #12]
@ (idloc gtstr)
 ldr r7, l0290
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #20]
 ldr r1, [sp, #12]
 mov r0, #0
 mov r4, r0
 mov r3, r1
l0293:
 cmp r4, r3
 bgt l0294
 ldr r1, [sp, #4]
 add r1, r1, r4
 mov r0, #4
 ldr r7, [sp, #16]
 add r0, r0, r7
 ldrsb r0, [r0, r1]
 mov r2, r0
 mov r1, r4
 mov r0, #4
 ldr r7, [sp, #20]
 add r0, r0, r7
 strb r2, [r0, r1]
 add r4, r4, #1
 b l0293
l0294:
 ldr r0, [sp, #20]
 mov r0, r0, lsl #5
 orr r0, r0, #4
 mov r0, r0, ror #5
 add sp, sp, #28
 ldmia sp!, {pc}
l0290:
 .long 388
l0289:
 .long 334
l0288:
 .long [[4*0x8000000]+l0291]
 .long 2
@ (*entry search-string-for-character expr 2)
 .globl l0295
l0295:
 stmdb sp!, {lr}
 str r0, [sp, #-4]!
 mov r4, r1
 bic r1, r1, #4160749568
 ldr r7, [r1]
 mov r1, r7, lsl #5
 mov r1, r1, asr #5
 mov r0, #0
 mov r3, r0
 mov r2, r1
l0296:
 cmp r3, r2
 ble l0297
 mov r0, r12
 b l0298
l0297:
 mov r1, r3
 bic r0, r4, #4160749568
 add r0, r0, #4
 ldrsb r0, [r0, r1]
 ldr r7, [sp]
 cmp r7, r0
 bne l0299
 mov r0, r1
 b l0298
l0299:
 add r3, r3, #1
 b l0296
l0298:
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 2
@ (*entry unchecked-string-equal expr 2)
 .globl l0301
l0301:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r12, [sp, #8]
 bic r0, r0, #4160749568
 str r0, [sp]
 bic r1, r1, #4160749568
 str r1, [sp, #4]
 ldr r7, [r0]
 mov r2, r7, lsl #5
 mov r2, r2, asr #5
 mov r4, r2
 ldr r7, [r1]
 mov r3, r7, lsl #5
 mov r3, r3, asr #5
 cmp r2, r3
 beq l0302
 mov r0, r12
 b l0303
l0302:
 mov r5, #0
 str r5, [sp, #8]
l0304:
 ldr r7, [sp, #8]
 cmp r7, r4
 ble l0305
 ldr r0, l0300
 b l0303
l0305:
 ldr r1, [sp, #8]
 mov r0, #4
 ldr r7, [sp]
 add r0, r0, r7
 ldrsb r0, [r0, r1]
 mov r2, r0
 mov r0, #4
 ldr r7, [sp, #4]
 add r0, r0, r7
 ldrsb r0, [r0, r1]
 cmp r2, r0
 beq l0306
 mov r0, r12
 b l0303
l0306:
 ldr r6, [sp, #8]
 add r6, r6, #1
 str r6, [sp, #8]
 b l0304
l0303:
 add sp, sp, #12
 ldmia sp!, {pc}
l0300:
 .long [[30*0x8000000]+116]
 .long 2
@ (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 stmdb sp!, {lr}
 sub sp, sp, #20
 str r0, [sp, #12]
 bic r2, r0, #4160749568
 str r2, [sp, #4]
 bic r3, r1, #4160749568
 str r3, [sp, #8]
 ldr r7, [r3]
 mov r4, r7, lsl #5
 mov r4, r4, asr #5
 str r4, [sp]
 ldr r7, [r2]
 mov r0, r7, lsl #5
 mov r0, r0, asr #5
 cmp r0, r4
 bge l0307
 str r0, [sp]
l0307:
 mov r0, #5
 ldr r7, [sp]
 add r0, r0, r7
 mov r1, r0
 mov r1, r1, lsr #30
 add r0, r0, r1
 mov r0, r0, asr #2
 sub r0, r0, #1
 str r0, [sp]
 mov r1, r0
 mov r0, #0
 mov r3, r0
 mov r2, r1
l0308:
 cmp r3, r2
 bgt l0309
 mov r0, #1
 add r0, r0, r3
 mov r0, r0, lsl #2
 ldr r7, [sp, #4]
 add r0, r0, r7
 mov r1, #1
 add r1, r1, r3
 mov r1, r1, lsl #2
 ldr r7, [sp, #8]
 add r1, r1, r7
 ldr r5, [r1]
 str r5, [r0]
 add r3, r3, #1
 b l0308
l0309:
 ldr r0, [sp, #12]
 add sp, sp, #20
 ldmia sp!, {pc}
 .long 2
@ (*entry cons expr 2)
 .globl cons
cons:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 mov r0, #2
@ (idloc gtheap)
 ldr r7, l0310
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r5, [sp]
 str r5, [r0]
 ldr r5, [sp, #4]
 str r5, [r0, #4]
 mov r0, r0, lsl #5
 orr r0, r0, #9
 mov r0, r0, ror #5
 add sp, sp, #12
 ldmia sp!, {pc}
l0310:
 .long 385
 .long 1
@ (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r0, lsl #2
 add r0, r0, r11
 ldr r0, [r0]
 add sp, sp, #4
 ldmia sp!, {pc}
l0311:
 .long [[30*0x8000000]+360]
 .long 2
@ (*entry modify expr 2)
 .globl modify
modify:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r0, lsl #2
 add r0, r0, r11
 str r1, [r0]
 mov r0, r1
 add sp, sp, #4
 ldmia sp!, {pc}
l0312:
 .long [[30*0x8000000]+360]
 .long 3
@ (*entry put expr 3)
 .globl put
put:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc unchecked-put)
 ldr r7, l0313
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0313:
 .long 392
 .long 3
@ (*entry unchecked-put expr 3)
 .globl l0318
l0318:
 stmdb sp!, {lr}
 sub sp, sp, #20
 str r12, [sp, #12]
 str r0, [sp]
 str r1, [sp, #4]
 str r2, [sp, #8]
@ (idloc unchecked-prop)
 ldr r7, l0314
 ldr r6, [r10, r7, lsl #2]
 blx r6
 str r0, [sp, #12]
 mov r1, r0
 ldr r0, [sp, #4]
@ (idloc atsoc)
 ldr r7, l0315
 ldr r6, [r10, r7, lsl #2]
 blx r6
 cmp r0, r12
 beq l0319
 bic r6, r0, #4160749568
 ldr r5, [sp, #8]
 str r5, [r6, #4]
 b l0320
l0319:
 ldr r1, [sp, #8]
 ldr r0, [sp, #4]
 str r0, [r8]
 mov r0, r8
 orr r0, r0, #1207959552
 str r1, [r8, #4]
 add r8, r8, #8
 cmp r8, r9
 blt l0321
 str r0, [sp, #-4]!
@ (idloc !%reclaim)
 ldr r7, l0316
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp], #4
l0321:
 ldr r1, [sp, #12]
 str r0, [r8]
 mov r0, r8
 orr r0, r0, #1207959552
 str r1, [r8, #4]
 add r8, r8, #8
 cmp r8, r9
 blt l0322
 str r0, [sp, #-4]!
@ (idloc !%reclaim)
 ldr r7, l0316
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp], #4
l0322:
 mov r1, r0
 ldr r0, [sp]
@ (idloc unchecked-setprop)
 ldr r7, l0317
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0320:
 ldr r0, [sp, #8]
 add sp, sp, #20
 ldmia sp!, {pc}
l0317:
 .long 397
l0316:
 .long 396
l0315:
 .long 395
l0314:
 .long 394
 .long 2
@ (*entry atsoc expr 2)
 .globl atsoc
atsoc:
 stmdb sp!, {lr}
 sub sp, sp, #4
l0323:
 mov r7, r1, lsr #27
 cmp r7, #9
 beq l0324
 mov r0, r12
 add sp, sp, #4
 ldmia sp!, {pc}
l0324:
 bic r5, r1, #4160749568
 ldr r7, [r5]
 mov r7, r7, lsr #27
 cmp r7, #9
 bne l0325
 bic r6, r1, #4160749568
 ldr r6, [r6]
 bic r6, r6, #4160749568
 ldr r7, [r6]
 cmp r0, r7
 bne l0325
 bic r0, r1, #4160749568
 ldr r0, [r0]
 add sp, sp, #4
 ldmia sp!, {pc}
l0325:
 bic r1, r1, #4160749568
 ldr r1, [r1, #4]
 b l0323
 .long 2
@ (*entry unchecked-setprop expr 2)
 .globl l0327
l0327:
 stmdb sp!, {lr}
 sub sp, sp, #4
 bic r0, r0, #4160749568
 mov r0, r0, lsl #2
@ ($global symprp)
 ldr r7, l0326
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 str r1, [r0]
 mov r0, r1
 add sp, sp, #4
 ldmia sp!, {pc}
l0326:
 .long 357
 .long 1
@ (*entry unchecked-prop expr 1)
 .globl l0329
l0329:
 stmdb sp!, {lr}
 sub sp, sp, #4
 bic r0, r0, #4160749568
 mov r0, r0, lsl #2
@ ($global symprp)
 ldr r7, l0328
 ldr r7, [r11, r7, lsl #2]
 add r0, r0, r7
 ldr r0, [r0]
 add sp, sp, #4
 ldmia sp!, {pc}
l0328:
 .long 357
 .long 3
@ (*entry putd expr 3)
 .globl putd
putd:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc code-putd)
 ldr r7, l0330
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0330:
 .long 398
l0337:
 .long 26
 .byte 66,97,100,32,112,97,114,97,109,101
 .byte 116,101,114,115,32,116,111,32,67,79
 .byte 68,69,45,80,85,84,68,0
 .long 3
@ (*entry code-putd expr 3)
 .globl l0338
l0338:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r0, [sp]
 str r1, [sp, #4]
 str r2, [sp, #8]
 mov r7, r0, lsr #27
 cmp r7, #30
 bne l0339
 mov r7, r1, lsr #27
 cmp r7, #30
 bne l0339
 mov r7, r2, lsr #27
 cmp r7, #20
 beq l0340
l0339:
 ldr r0, l0331
@ (idloc kernel-fatal-error)
 ldr r7, l0332
 ldr r6, [r10, r7, lsl #2]
 blx r6
l0340:
 ldr r1, [sp, #8]
 bic r1, r1, #4160749568
 ldr r0, [sp]
 bic r0, r0, #4160749568
@ (idloc plantcodepointer)
 ldr r7, l0333
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r5, [sp, #4]
 ldr r6, l0334
 cmp r5, r6
 beq l0341
 ldr r2, [sp, #4]
 ldr r1, l0335
 ldr r0, [sp]
 add sp, sp, #12
 ldmia sp!, {lr}
@ (idloc put)
 ldr r7, l0336
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0341:
 mov r0, r12
 add sp, sp, #12
 ldmia sp!, {pc}
l0336:
 .long 393
l0335:
 .long [[30*0x8000000]+400]
l0334:
 .long [[30*0x8000000]+401]
l0333:
 .long 399
l0332:
 .long 334
l0331:
 .long [[4*0x8000000]+l0337]
 .long 1
@ (*entry fluid expr 1)
 .globl fluid
fluid:
 stmdb sp!, {lr}
 sub sp, sp, #12
 str r12, [sp, #8]
 str r0, [sp]
 mov r0, r12
 ldr r5, [sp]
 str r5, [sp, #4]
 mov r7, r5
 mov r7, r7, lsr #27
 cmp r7, #9
 bne l0343
 ldr r0, [sp, #4]
 bic r0, r0, #4160749568
 ldr r0, [r0]
 b l0344
l0343:
 mov r0, r12
l0344:
 str r0, [sp, #8]
l0345:
 ldr r7, [sp, #4]
 mov r7, r7, lsr #27
 cmp r7, #9
 beq l0346
 mov r0, r12
 b l0347
l0346:
 ldr r0, [sp, #8]
@ (idloc fluid1)
 ldr r7, l0342
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp, #4]
 bic r0, r0, #4160749568
 ldr r0, [r0, #4]
 str r0, [sp, #4]
 mov r7, r0, lsr #27
 cmp r7, #9
 bne l0348
 bic r0, r0, #4160749568
 ldr r0, [r0]
 b l0349
l0348:
 mov r0, r12
l0349:
 str r0, [sp, #8]
 b l0345
l0347:
 add sp, sp, #12
 ldmia sp!, {pc}
l0342:
 .long 402
 .long 1
@ (*entry fluid1 expr 1)
 .globl l0353
l0353:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r2, l0350
 ldr r1, l0351
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc put)
 ldr r7, l0352
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0352:
 .long 393
l0351:
 .long [[30*0x8000000]+404]
l0350:
 .long [[30*0x8000000]+403]
 .long 1
@ (*entry stderror expr 1)
 .globl stderror
stderror:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc kernel-fatal-error)
 ldr r7, l0354
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0354:
 .long 334
 .long 2
@ (*entry *define-constant expr 2)
 .globl l0359
l0359:
 stmdb sp!, {lr}
 sub sp, sp, #4
 bic r2, r0, #4160749568
 mov r2, r2, lsl #2
 add r2, r2, r11
 str r1, [r2]
 ldr r2, l0356
 ldr r1, l0357
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc put)
 ldr r7, l0358
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0358:
 .long 393
l0357:
 .long [[30*0x8000000]+406]
l0356:
 .long [[30*0x8000000]+116]
l0355:
 .long [[30*0x8000000]+360]
 .long 1
@ (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r5, l0360
 str r5, [r10, r0, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 0
l0360:
 .long undefinedfunction
 .long 2
@ (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 stmdb sp!, {lr}
 sub sp, sp, #4
 str r1, [r10, r0, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 1
@ (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 stmdb sp!, {lr}
 sub sp, sp, #4
 ldr r5, l0361
 str r5, [r10, r0, lsl #2]
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 0
l0361:
 .long compiledcallinginterpreted
 .long 1
@ (*entry addressapply0 expr 1)
 .globl l0362
l0362:
 bx r0
 .long 2
@ (*entry bittable expr 2)
 .globl bittable
bittable:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r3, r1
 mov r1, r1, lsr #2
 ldrsb r0, [r0, r1]
 mov r2, r3, lsl #30
 mov r2, r2, lsr #30
 mov r2, r2, lsl #1
 sub r2, r2, #6
 cmp r2, #0
 bge l0363
 rsb r6, r2, #0
 mov r0, r0, lsr r6
 b l0364
l0363:
 mov r0, r0, lsl r2
l0364:
 mov r0, r0, lsl #30
 mov r0, r0, lsr #30
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 1
@ (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r5, r7
@ (idloc undefinedfunction-aux)
 ldr r7, l0365
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0365:
 .long 408
l0371:
 .long 26
 .byte 85,110,100,101,102,105,110,101,100
 .byte 32,102,117,110,99,116,105,111,110,32
 .byte 99,97,108,108,101,100,58,32,0
 .long 1
@ (*entry undefinedfunction-aux expr 1)
 .globl l0372
l0372:
 stmdb sp!, {lr}
 sub sp, sp, #4
 str r5, [sp, #-4]!
 ldr r0, l0366
@ (idloc console-print-string)
 ldr r7, l0367
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ ($fluid symnam)
 ldr r7, l0368
 ldr r6, [r11, r7, lsl #2]
 ldr r5, [sp], #4
 ldr r0, [r6, r5, lsl #2]
@ (idloc console-print-string)
 ldr r7, l0367
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc console-newline)
 ldr r7, l0369
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mov r0, #0
@ (idloc exit-with-status)
 ldr r7, l0370
 ldr r6, [r10, r7, lsl #2]
 blx r6
 add sp, sp, #4
 ldmia sp!, {pc}
l0370:
 .long 310
l0369:
 .long 326
l0368:
 .long 343
l0367:
 .long 325
l0366:
 .long [[4*0x8000000]+l0371]
 .long 0
@ (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 stmdb sp!, {lr}
 sub sp, sp, #4
@ (idloc *tehcalledid*)
 ldr r5, l0373
@ ($fluid codeform*)
 ldr r7, l0374
 str r5, [r11, r7, lsl #2]
@ (idloc compiledcallinginterpretedaux)
 ldr r7, l0375
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0375:
 .long 412
l0374:
 .long 411
l0373:
 .long 410
l0380:
 .long 12
 .byte 70,65,84,65,76,32,69,82,82,79,82,58
 .byte 32,0,0,0
 .long 1
@ (*entry kernel-fatal-error expr 1)
 .globl l0381
l0381:
 stmdb sp!, {lr}
 str r0, [sp, #-4]!
 ldr r0, l0376
@ (idloc console-print-string)
 ldr r7, l0377
 ldr r6, [r10, r7, lsl #2]
 blx r6
 ldr r0, [sp]
@ (idloc console-print-string)
 ldr r7, l0377
 ldr r6, [r10, r7, lsl #2]
 blx r6
@ (idloc console-newline)
 ldr r7, l0378
 ldr r6, [r10, r7, lsl #2]
 blx r6
 mvn r0, #0
 add sp, sp, #4
 ldmia sp!, {lr}
@ (idloc exit-with-status)
 ldr r7, l0379
 ldr r6, [r10, r7, lsl #2]
 bx r6
l0379:
 .long 310
l0378:
 .long 326
l0377:
 .long 325
l0376:
 .long [[4*0x8000000]+l0380]
 .long 0
@ (*entry echoon expr 0)
 .globl l0382
l0382:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx echoon
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry echooff expr 0)
 .globl l0383
l0383:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx echooff
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_charsininputbuffer expr 1)
 .globl l0384
l0384:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_charsininputbuffer
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry flushstdoutputbuffer expr 0)
 .globl l0385
l0385:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx flushstdoutputbuffer
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry external_user_homedir_string expr 0)
 .globl l0386
l0386:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_user_homedir_string
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_anyuser_homedir_string expr 1)
 .globl l0387
l0387:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_anyuser_homedir_string
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry alterheapsize expr 1)
 .globl l0388
l0388:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx alterheapsize
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry allocatemorebps expr 1)
 .globl l0389
l0389:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx allocatemorebps
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry get_imagefilepath expr 0)
 .globl l0390
l0390:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx get_imagefilepath
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry get_file_status expr 3)
 .globl l0391
l0391:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx get_file_status
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry os_startup_hook expr 2)
 .globl l0392
l0392:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx os_startup_hook
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry os_cleanup_hook expr 0)
 .globl l0393
l0393:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx os_cleanup_hook
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry get_execfilepath expr 0)
 .globl l0394
l0394:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx get_execfilepath
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry wquotient expr 2)
 .globl l0395
l0395:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx wquotient
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry wremainder expr 2)
 .globl l0396
l0396:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx wremainder
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_alarm expr 1)
 .globl l0397
l0397:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_alarm
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry external_ualarm expr 2)
 .globl l0398
l0398:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_ualarm
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_time expr 1)
 .globl l0399
l0399:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_time
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_timc expr 1)
 .globl l0400
l0400:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_timc
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry external_stat expr 2)
 .globl l0401
l0401:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_stat
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry external_link expr 2)
 .globl l0402
l0402:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_link
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_unlink expr 1)
 .globl l0403
l0403:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_unlink
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_rmdir expr 1)
 .globl l0404
l0404:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_rmdir
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry external_mkdir expr 2)
 .globl l0405
l0405:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_mkdir
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_strlen expr 1)
 .globl l0406
l0406:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_strlen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry external_setenv expr 2)
 .globl l0407
l0407:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_setenv
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_getenv expr 1)
 .globl l0408
l0408:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_getenv
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uxfloat expr 2)
 .globl l0409
l0409:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxfloat
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry uxfix expr 1)
 .globl l0410
l0410:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxfix
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uxassign expr 2)
 .globl l0411
l0411:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxassign
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uxminus expr 2)
 .globl l0412
l0412:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxminus
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uxplus2 expr 3)
 .globl l0413
l0413:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxplus2
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uxdifference expr 3)
 .globl l0414
l0414:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxdifference
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uxtimes2 expr 3)
 .globl l0415
l0415:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxtimes2
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uxquotient expr 3)
 .globl l0416
l0416:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxquotient
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry uxgreaterp expr 4)
 .globl l0417
l0417:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxgreaterp
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry uxlessp expr 4)
 .globl l0418
l0418:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxlessp
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uxwritefloat expr 3)
 .globl l0419
l0419:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uxwritefloat
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxdoubletofloat expr 2)
 .globl l0420
l0420:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxdoubletofloat
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxfloattodouble expr 2)
 .globl l0421
l0421:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxfloattodouble
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxsin expr 2)
 .globl l0422
l0422:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxsin
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxcos expr 2)
 .globl l0423
l0423:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxcos
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxtan expr 2)
 .globl l0424
l0424:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxtan
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxasin expr 2)
 .globl l0425
l0425:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxasin
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxacos expr 2)
 .globl l0426
l0426:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxacos
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxatan expr 2)
 .globl l0427
l0427:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxatan
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxsqrt expr 2)
 .globl l0428
l0428:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxsqrt
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxexp expr 2)
 .globl l0429
l0429:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxexp
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry uuxlog expr 2)
 .globl l0430
l0430:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxlog
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry uuxatan2 expr 3)
 .globl l0431
l0431:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx uuxatan2
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry external_pwd expr 0)
 .globl l0432
l0432:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_pwd
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry sun3_sigset expr 2)
 .globl l0433
l0433:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx sun3_sigset
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry sun3_sigrelse expr 2)
 .globl l0434
l0434:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx sun3_sigrelse
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry sigrelse expr 2)
 .globl sigrelse
sigrelse:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx sun3_sigrelse
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry mask_signal expr 2)
 .globl l0435
l0435:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx mask_signal
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry unexec expr 4)
 .globl l0436
l0436:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unexec
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry unixputc expr 1)
 .globl l0437
l0437:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixputc
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry unixputs expr 1)
 .globl l0438
l0438:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixputs
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry unixputn expr 1)
 .globl l0439
l0439:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixputn
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry unixcleario expr 0)
 .globl l0440
l0440:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixcleario
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry expand_file_name expr 1)
 .globl l0441
l0441:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx expand_file_name
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry unixopen expr 2)
 .globl l0442
l0442:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixopen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry unixcd expr 1)
 .globl l0443
l0443:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixcd
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry ctime expr 1)
 .globl l0444
l0444:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx ctime
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_system expr 1)
 .globl l0445
l0445:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_system
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_fullpath expr 1)
 .globl l0446
l0446:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_fullpath
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry external_exit expr 1)
 .globl l0447
l0447:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx external_exit
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry fopen expr 2)
 .globl l0448
l0448:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fopen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry fclose expr 1)
 .globl l0449
l0449:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fclose
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry fread expr 4)
 .globl l0450
l0450:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fread
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry fputc expr 2)
 .globl l0451
l0451:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fputc
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry fgetc expr 1)
 .globl l0452
l0452:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fgetc
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry fgets expr 3)
 .globl l0453
l0453:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fgets
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry fwrite expr 4)
 .globl l0454
l0454:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fwrite
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry fflush expr 1)
 .globl l0455
l0455:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fflush
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry fseek expr 3)
 .globl l0456
l0456:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fseek
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry clearerr expr 1)
 .globl l0457
l0457:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx clearerr
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry getw expr 1)
 .globl l0458
l0458:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx getw
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry putw expr 2)
 .globl l0459
l0459:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx putw
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry signal expr 2)
 .globl l0460
l0460:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx signal
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry sleep expr 1)
 .globl l0461
l0461:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx sleep
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry ieee_handler expr 3)
 .globl l0462
l0462:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx ieee_handler
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry ieee_flags expr 4)
 .globl l0463
l0463:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx ieee_flags
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry setlinebuf expr 1)
 .globl l0464
l0464:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx setlinebuf
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry getpid expr 0)
 .globl l0465
l0465:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx getpid
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry gethostid expr 0)
 .globl l0466
l0466:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx gethostid
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry unixsocketopen expr 2)
 .globl l0467
l0467:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixsocketopen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry getsocket expr 3)
 .globl l0468
l0468:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx getsocket
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry writesocket expr 3)
 .globl l0469
l0469:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx writesocket
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry unixclosesocket expr 1)
 .globl l0470
l0470:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx unixclosesocket
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 0
@ (*entry fork expr 0)
 .globl l0471
l0471:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx fork
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry wait expr 1)
 .globl l0472
l0472:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx wait
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry popen expr 2)
 .globl l0473
l0473:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx popen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry pclose expr 1)
 .globl l0474
l0474:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx pclose
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry shmctl expr 3)
 .globl l0475
l0475:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx shmctl
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry shmget expr 3)
 .globl l0476
l0476:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx shmget
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry shmat expr 3)
 .globl l0477
l0477:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx shmat
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry shmdt expr 1)
 .globl l0478
l0478:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx shmdt
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry semctl expr 4)
 .globl l0479
l0479:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx semctl
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry semget expr 3)
 .globl l0480
l0480:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx semget
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 3
@ (*entry semop expr 3)
 .globl l0481
l0481:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx semop
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry dlopen expr 2)
 .globl l0482
l0482:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx dlopen
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry dlerror expr 1)
 .globl l0483
l0483:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx dlerror
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 2
@ (*entry dlsym expr 2)
 .globl l0484
l0484:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx dlsym
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry dlclose expr 1)
 .globl l0485
l0485:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx dlclose
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 4
@ (*entry unix-profile expr 4)
 .globl l0486
l0486:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {lr}
 stmdb sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 mov r6, sp
 mvn r7, #7
 sub sp, sp, #8
 and sp, sp, r7
 str r6, [sp]
 blx profil
 ldr sp, [sp]
 ldmia sp!, {r1,r2,r3,r4,r8,r9,r10,r11,r12,lr}
 bx lr
 .long 1
@ (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 stmdb sp!, {lr}
 sub sp, sp, #4
 bic r0, r0, #4160749568
 str r0, [sp]
 ldr r0, l0487
@ (idloc getfcodepointer)
 ldr r7, l0488
 ldr r6, [r10, r7, lsl #2]
 blx r6
 bic r0, r0, #4160749568
 ldr r7, [sp]
 cmp r0, r7
 ble l0493
 mov r0, r12
 b l0494
l0493:
 ldr r0, l0489
l0494:
 cmp r0, r12
 beq l0495
 ldr r0, l0490
@ (idloc getfcodepointer)
 ldr r7, l0488
 ldr r6, [r10, r7, lsl #2]
 blx r6
 bic r0, r0, #4160749568
 ldr r7, [sp]
 cmp r7, r0
 blt l0496
 mov r0, r12
 b l0495
l0496:
 ldr r0, l0489
l0495:
 cmp r0, r12
 bne l0497
@ ($global bpslowerbound)
 ldr r7, l0491
 ldr r0, [r11, r7, lsl #2]
 bic r0, r0, #4160749568
 ldr r7, [sp]
 cmp r0, r7
 ble l0498
 mov r0, r12
 b l0499
l0498:
 ldr r0, l0489
l0499:
 cmp r0, r12
 beq l0497
@ ($global nextbps)
 ldr r7, l0492
 ldr r0, [r11, r7, lsl #2]
 bic r0, r0, #4160749568
 ldr r7, [sp]
 cmp r7, r0
 blt l0500
 mov r0, r12
 b l0497
l0500:
 ldr r0, l0489
l0497:
 add sp, sp, #4
 ldmia sp!, {pc}
l0492:
 .long 287
l0491:
 .long 285
l0490:
 .long [[30*0x8000000]+510]
l0489:
 .long [[30*0x8000000]+116]
l0488:
 .long 508
l0487:
 .long [[30*0x8000000]+257]
 .long 1
@ (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 stmdb sp!, {lr}
 sub sp, sp, #4
 add sp, sp, #4
 ldmia sp!, {pc}
 .long 0
@ (*entry initcode expr 0)
 .globl initcode
initcode:
 stmdb sp!, {lr}
 sub sp, sp, #4
 mov r0, r12
 add sp, sp, #4
 ldmia sp!, {pc}
 .globl symval
 .globl symprp
 .globl symnam
 .globl l0501
l0501:
 .long 0
 .byte 0,0,0,0
 .globl l0502
l0502:
 .long 0
 .byte 1,0,0,0
 .globl l0503
l0503:
 .long 0
 .byte 2,0,0,0
 .globl l0504
l0504:
 .long 0
 .byte 3,0,0,0
 .globl l0505
l0505:
 .long 0
 .byte 4,0,0,0
 .globl l0506
l0506:
 .long 0
 .byte 5,0,0,0
 .globl l0507
l0507:
 .long 0
 .byte 6,0,0,0
 .globl l0508
l0508:
 .long 0
 .byte 7,0,0,0
 .globl l0509
l0509:
 .long 0
 .byte 8,0,0,0
 .globl l0510
l0510:
 .long 0
 .byte 9,0,0,0
 .globl l0511
l0511:
 .long 0
 .byte 10,0,0,0
 .globl l0512
l0512:
 .long 0
 .byte 11,0,0,0
 .globl l0513
l0513:
 .long 0
 .byte 12,0,0,0
 .globl l0514
l0514:
 .long 0
 .byte 13,0,0,0
 .globl l0515
l0515:
 .long 0
 .byte 14,0,0,0
 .globl l0516
l0516:
 .long 0
 .byte 15,0,0,0
 .globl l0517
l0517:
 .long 0
 .byte 16,0,0,0
 .globl l0518
l0518:
 .long 0
 .byte 17,0,0,0
 .globl l0519
l0519:
 .long 0
 .byte 18,0,0,0
 .globl l0520
l0520:
 .long 0
 .byte 19,0,0,0
 .globl l0521
l0521:
 .long 0
 .byte 20,0,0,0
 .globl l0522
l0522:
 .long 0
 .byte 21,0,0,0
 .globl l0523
l0523:
 .long 0
 .byte 22,0,0,0
 .globl l0524
l0524:
 .long 0
 .byte 23,0,0,0
 .globl l0525
l0525:
 .long 0
 .byte 24,0,0,0
 .globl l0526
l0526:
 .long 0
 .byte 25,0,0,0
 .globl l0527
l0527:
 .long 0
 .byte 26,0,0,0
 .globl l0528
l0528:
 .long 0
 .byte 27,0,0,0
 .globl l0529
l0529:
 .long 0
 .byte 28,0,0,0
 .globl l0530
l0530:
 .long 0
 .byte 29,0,0,0
 .globl l0531
l0531:
 .long 0
 .byte 30,0,0,0
 .globl l0532
l0532:
 .long 0
 .byte 31,0,0,0
 .globl l0533
l0533:
 .long 0
 .byte 32,0,0,0
 .globl l0534
l0534:
 .long 0
 .byte 33,0,0,0
 .globl l0535
l0535:
 .long 0
 .byte 34,0,0,0
 .globl l0536
l0536:
 .long 0
 .byte 35,0,0,0
 .globl l0537
l0537:
 .long 0
 .byte 36,0,0,0
 .globl l0538
l0538:
 .long 0
 .byte 37,0,0,0
 .globl l0539
l0539:
 .long 0
 .byte 38,0,0,0
 .globl l0540
l0540:
 .long 0
 .byte 39,0,0,0
 .globl l0541
l0541:
 .long 0
 .byte 40,0,0,0
 .globl l0542
l0542:
 .long 0
 .byte 41,0,0,0
 .globl l0543
l0543:
 .long 0
 .byte 42,0,0,0
 .globl l0544
l0544:
 .long 0
 .byte 43,0,0,0
 .globl l0545
l0545:
 .long 0
 .byte 44,0,0,0
 .globl l0546
l0546:
 .long 0
 .byte 45,0,0,0
 .globl l0547
l0547:
 .long 0
 .byte 46,0,0,0
 .globl l0548
l0548:
 .long 0
 .byte 47,0,0,0
 .globl l0549
l0549:
 .long 0
 .byte 48,0,0,0
 .globl l0550
l0550:
 .long 0
 .byte 49,0,0,0
 .globl l0551
l0551:
 .long 0
 .byte 50,0,0,0
 .globl l0552
l0552:
 .long 0
 .byte 51,0,0,0
 .globl l0553
l0553:
 .long 0
 .byte 52,0,0,0
 .globl l0554
l0554:
 .long 0
 .byte 53,0,0,0
 .globl l0555
l0555:
 .long 0
 .byte 54,0,0,0
 .globl l0556
l0556:
 .long 0
 .byte 55,0,0,0
 .globl l0557
l0557:
 .long 0
 .byte 56,0,0,0
 .globl l0558
l0558:
 .long 0
 .byte 57,0,0,0
 .globl l0559
l0559:
 .long 0
 .byte 58,0,0,0
 .globl l0560
l0560:
 .long 0
 .byte 59,0,0,0
 .globl l0561
l0561:
 .long 0
 .byte 60,0,0,0
 .globl l0562
l0562:
 .long 0
 .byte 61,0,0,0
 .globl l0563
l0563:
 .long 0
 .byte 62,0,0,0
 .globl l0564
l0564:
 .long 0
 .byte 63,0,0,0
 .globl l0565
l0565:
 .long 0
 .byte 64,0,0,0
 .globl l0566
l0566:
 .long 0
 .byte 65,0,0,0
 .globl l0567
l0567:
 .long 0
 .byte 66,0,0,0
 .globl l0568
l0568:
 .long 0
 .byte 67,0,0,0
 .globl l0569
l0569:
 .long 0
 .byte 68,0,0,0
 .globl l0570
l0570:
 .long 0
 .byte 69,0,0,0
 .globl l0571
l0571:
 .long 0
 .byte 70,0,0,0
 .globl l0572
l0572:
 .long 0
 .byte 71,0,0,0
 .globl l0573
l0573:
 .long 0
 .byte 72,0,0,0
 .globl l0574
l0574:
 .long 0
 .byte 73,0,0,0
 .globl l0575
l0575:
 .long 0
 .byte 74,0,0,0
 .globl l0576
l0576:
 .long 0
 .byte 75,0,0,0
 .globl l0577
l0577:
 .long 0
 .byte 76,0,0,0
 .globl l0578
l0578:
 .long 0
 .byte 77,0,0,0
 .globl l0579
l0579:
 .long 0
 .byte 78,0,0,0
 .globl l0580
l0580:
 .long 0
 .byte 79,0,0,0
 .globl l0581
l0581:
 .long 0
 .byte 80,0,0,0
 .globl l0582
l0582:
 .long 0
 .byte 81,0,0,0
 .globl l0583
l0583:
 .long 0
 .byte 82,0,0,0
 .globl l0584
l0584:
 .long 0
 .byte 83,0,0,0
 .globl l0585
l0585:
 .long 0
 .byte 84,0,0,0
 .globl l0586
l0586:
 .long 0
 .byte 85,0,0,0
 .globl l0587
l0587:
 .long 0
 .byte 86,0,0,0
 .globl l0588
l0588:
 .long 0
 .byte 87,0,0,0
 .globl l0589
l0589:
 .long 0
 .byte 88,0,0,0
 .globl l0590
l0590:
 .long 0
 .byte 89,0,0,0
 .globl l0591
l0591:
 .long 0
 .byte 90,0,0,0
 .globl l0592
l0592:
 .long 0
 .byte 91,0,0,0
 .globl l0593
l0593:
 .long 0
 .byte 92,0,0,0
 .globl l0594
l0594:
 .long 0
 .byte 93,0,0,0
 .globl l0595
l0595:
 .long 0
 .byte 94,0,0,0
 .globl l0596
l0596:
 .long 0
 .byte 95,0,0,0
 .globl l0597
l0597:
 .long 0
 .byte 96,0,0,0
 .globl l0598
l0598:
 .long 0
 .byte 97,0,0,0
 .globl l0599
l0599:
 .long 0
 .byte 98,0,0,0
 .globl l0600
l0600:
 .long 0
 .byte 99,0,0,0
 .globl l0601
l0601:
 .long 0
 .byte 100,0,0,0
 .globl l0602
l0602:
 .long 0
 .byte 101,0,0,0
 .globl l0603
l0603:
 .long 0
 .byte 102,0,0,0
 .globl l0604
l0604:
 .long 0
 .byte 103,0,0,0
 .globl l0605
l0605:
 .long 0
 .byte 104,0,0,0
 .globl l0606
l0606:
 .long 0
 .byte 105,0,0,0
 .globl l0607
l0607:
 .long 0
 .byte 106,0,0,0
 .globl l0608
l0608:
 .long 0
 .byte 107,0,0,0
 .globl l0609
l0609:
 .long 0
 .byte 108,0,0,0
 .globl l0610
l0610:
 .long 0
 .byte 109,0,0,0
 .globl l0611
l0611:
 .long 0
 .byte 110,0,0,0
 .globl l0612
l0612:
 .long 0
 .byte 111,0,0,0
 .globl l0613
l0613:
 .long 0
 .byte 112,0,0,0
 .globl l0614
l0614:
 .long 0
 .byte 113,0,0,0
 .globl l0615
l0615:
 .long 0
 .byte 114,0,0,0
 .globl l0616
l0616:
 .long 0
 .byte 115,0,0,0
 .globl l0617
l0617:
 .long 0
 .byte 116,0,0,0
 .globl l0618
l0618:
 .long 0
 .byte 117,0,0,0
 .globl l0619
l0619:
 .long 0
 .byte 118,0,0,0
 .globl l0620
l0620:
 .long 0
 .byte 119,0,0,0
 .globl l0621
l0621:
 .long 0
 .byte 120,0,0,0
 .globl l0622
l0622:
 .long 0
 .byte 121,0,0,0
 .globl l0623
l0623:
 .long 0
 .byte 122,0,0,0
 .globl l0624
l0624:
 .long 0
 .byte 123,0,0,0
 .globl l0625
l0625:
 .long 0
 .byte 124,0,0,0
 .globl l0626
l0626:
 .long 0
 .byte 125,0,0,0
 .globl l0627
l0627:
 .long 0
 .byte 126,0,0,0
 .globl l0628
l0628:
 .long 0
 .byte 127,0,0,0
 .globl l0629
l0629:
 .long 0
 .byte -128,0,0,0
 .globl l0630
l0630:
 .long 0
 .byte -127,0,0,0
 .globl l0631
l0631:
 .long 0
 .byte -126,0,0,0
 .globl l0632
l0632:
 .long 0
 .byte -125,0,0,0
 .globl l0633
l0633:
 .long 0
 .byte -124,0,0,0
 .globl l0634
l0634:
 .long 0
 .byte -123,0,0,0
 .globl l0635
l0635:
 .long 0
 .byte -122,0,0,0
 .globl l0636
l0636:
 .long 0
 .byte -121,0,0,0
 .globl l0637
l0637:
 .long 0
 .byte -120,0,0,0
 .globl l0638
l0638:
 .long 0
 .byte -119,0,0,0
 .globl l0639
l0639:
 .long 0
 .byte -118,0,0,0
 .globl l0640
l0640:
 .long 0
 .byte -117,0,0,0
 .globl l0641
l0641:
 .long 0
 .byte -116,0,0,0
 .globl l0642
l0642:
 .long 0
 .byte -115,0,0,0
 .globl l0643
l0643:
 .long 0
 .byte -114,0,0,0
 .globl l0644
l0644:
 .long 0
 .byte -113,0,0,0
 .globl l0645
l0645:
 .long 0
 .byte -112,0,0,0
 .globl l0646
l0646:
 .long 0
 .byte -111,0,0,0
 .globl l0647
l0647:
 .long 0
 .byte -110,0,0,0
 .globl l0648
l0648:
 .long 0
 .byte -109,0,0,0
 .globl l0649
l0649:
 .long 0
 .byte -108,0,0,0
 .globl l0650
l0650:
 .long 0
 .byte -107,0,0,0
 .globl l0651
l0651:
 .long 0
 .byte -106,0,0,0
 .globl l0652
l0652:
 .long 0
 .byte -105,0,0,0
 .globl l0653
l0653:
 .long 0
 .byte -104,0,0,0
 .globl l0654
l0654:
 .long 0
 .byte -103,0,0,0
 .globl l0655
l0655:
 .long 0
 .byte -102,0,0,0
 .globl l0656
l0656:
 .long 0
 .byte -101,0,0,0
 .globl l0657
l0657:
 .long 0
 .byte -100,0,0,0
 .globl l0658
l0658:
 .long 0
 .byte -99,0,0,0
 .globl l0659
l0659:
 .long 0
 .byte -98,0,0,0
 .globl l0660
l0660:
 .long 0
 .byte -97,0,0,0
 .globl l0661
l0661:
 .long 0
 .byte -96,0,0,0
 .globl l0662
l0662:
 .long 0
 .byte -95,0,0,0
 .globl l0663
l0663:
 .long 0
 .byte -94,0,0,0
 .globl l0664
l0664:
 .long 0
 .byte -93,0,0,0
 .globl l0665
l0665:
 .long 0
 .byte -92,0,0,0
 .globl l0666
l0666:
 .long 0
 .byte -91,0,0,0
 .globl l0667
l0667:
 .long 0
 .byte -90,0,0,0
 .globl l0668
l0668:
 .long 0
 .byte -89,0,0,0
 .globl l0669
l0669:
 .long 0
 .byte -88,0,0,0
 .globl l0670
l0670:
 .long 0
 .byte -87,0,0,0
 .globl l0671
l0671:
 .long 0
 .byte -86,0,0,0
 .globl l0672
l0672:
 .long 0
 .byte -85,0,0,0
 .globl l0673
l0673:
 .long 0
 .byte -84,0,0,0
 .globl l0674
l0674:
 .long 0
 .byte -83,0,0,0
 .globl l0675
l0675:
 .long 0
 .byte -82,0,0,0
 .globl l0676
l0676:
 .long 0
 .byte -81,0,0,0
 .globl l0677
l0677:
 .long 0
 .byte -80,0,0,0
 .globl l0678
l0678:
 .long 0
 .byte -79,0,0,0
 .globl l0679
l0679:
 .long 0
 .byte -78,0,0,0
 .globl l0680
l0680:
 .long 0
 .byte -77,0,0,0
 .globl l0681
l0681:
 .long 0
 .byte -76,0,0,0
 .globl l0682
l0682:
 .long 0
 .byte -75,0,0,0
 .globl l0683
l0683:
 .long 0
 .byte -74,0,0,0
 .globl l0684
l0684:
 .long 0
 .byte -73,0,0,0
 .globl l0685
l0685:
 .long 0
 .byte -72,0,0,0
 .globl l0686
l0686:
 .long 0
 .byte -71,0,0,0
 .globl l0687
l0687:
 .long 0
 .byte -70,0,0,0
 .globl l0688
l0688:
 .long 0
 .byte -69,0,0,0
 .globl l0689
l0689:
 .long 0
 .byte -68,0,0,0
 .globl l0690
l0690:
 .long 0
 .byte -67,0,0,0
 .globl l0691
l0691:
 .long 0
 .byte -66,0,0,0
 .globl l0692
l0692:
 .long 0
 .byte -65,0,0,0
 .globl l0693
l0693:
 .long 0
 .byte -64,0,0,0
 .globl l0694
l0694:
 .long 0
 .byte -63,0,0,0
 .globl l0695
l0695:
 .long 0
 .byte -62,0,0,0
 .globl l0696
l0696:
 .long 0
 .byte -61,0,0,0
 .globl l0697
l0697:
 .long 0
 .byte -60,0,0,0
 .globl l0698
l0698:
 .long 0
 .byte -59,0,0,0
 .globl l0699
l0699:
 .long 0
 .byte -58,0,0,0
 .globl l0700
l0700:
 .long 0
 .byte -57,0,0,0
 .globl l0701
l0701:
 .long 0
 .byte -56,0,0,0
 .globl l0702
l0702:
 .long 0
 .byte -55,0,0,0
 .globl l0703
l0703:
 .long 0
 .byte -54,0,0,0
 .globl l0704
l0704:
 .long 0
 .byte -53,0,0,0
 .globl l0705
l0705:
 .long 0
 .byte -52,0,0,0
 .globl l0706
l0706:
 .long 0
 .byte -51,0,0,0
 .globl l0707
l0707:
 .long 0
 .byte -50,0,0,0
 .globl l0708
l0708:
 .long 0
 .byte -49,0,0,0
 .globl l0709
l0709:
 .long 0
 .byte -48,0,0,0
 .globl l0710
l0710:
 .long 0
 .byte -47,0,0,0
 .globl l0711
l0711:
 .long 0
 .byte -46,0,0,0
 .globl l0712
l0712:
 .long 0
 .byte -45,0,0,0
 .globl l0713
l0713:
 .long 0
 .byte -44,0,0,0
 .globl l0714
l0714:
 .long 0
 .byte -43,0,0,0
 .globl l0715
l0715:
 .long 0
 .byte -42,0,0,0
 .globl l0716
l0716:
 .long 0
 .byte -41,0,0,0
 .globl l0717
l0717:
 .long 0
 .byte -40,0,0,0
 .globl l0718
l0718:
 .long 0
 .byte -39,0,0,0
 .globl l0719
l0719:
 .long 0
 .byte -38,0,0,0
 .globl l0720
l0720:
 .long 0
 .byte -37,0,0,0
 .globl l0721
l0721:
 .long 0
 .byte -36,0,0,0
 .globl l0722
l0722:
 .long 0
 .byte -35,0,0,0
 .globl l0723
l0723:
 .long 0
 .byte -34,0,0,0
 .globl l0724
l0724:
 .long 0
 .byte -33,0,0,0
 .globl l0725
l0725:
 .long 0
 .byte -32,0,0,0
 .globl l0726
l0726:
 .long 0
 .byte -31,0,0,0
 .globl l0727
l0727:
 .long 0
 .byte -30,0,0,0
 .globl l0728
l0728:
 .long 0
 .byte -29,0,0,0
 .globl l0729
l0729:
 .long 0
 .byte -28,0,0,0
 .globl l0730
l0730:
 .long 0
 .byte -27,0,0,0
 .globl l0731
l0731:
 .long 0
 .byte -26,0,0,0
 .globl l0732
l0732:
 .long 0
 .byte -25,0,0,0
 .globl l0733
l0733:
 .long 0
 .byte -24,0,0,0
 .globl l0734
l0734:
 .long 0
 .byte -23,0,0,0
 .globl l0735
l0735:
 .long 0
 .byte -22,0,0,0
 .globl l0736
l0736:
 .long 0
 .byte -21,0,0,0
 .globl l0737
l0737:
 .long 0
 .byte -20,0,0,0
 .globl l0738
l0738:
 .long 0
 .byte -19,0,0,0
 .globl l0739
l0739:
 .long 0
 .byte -18,0,0,0
 .globl l0740
l0740:
 .long 0
 .byte -17,0,0,0
 .globl l0741
l0741:
 .long 0
 .byte -16,0,0,0
 .globl l0742
l0742:
 .long 0
 .byte -15,0,0,0
 .globl l0743
l0743:
 .long 0
 .byte -14,0,0,0
 .globl l0744
l0744:
 .long 0
 .byte -13,0,0,0
 .globl l0745
l0745:
 .long 0
 .byte -12,0,0,0
 .globl l0746
l0746:
 .long 0
 .byte -11,0,0,0
 .globl l0747
l0747:
 .long 0
 .byte -10,0,0,0
 .globl l0748
l0748:
 .long 0
 .byte -9,0,0,0
 .globl l0749
l0749:
 .long 0
 .byte -8,0,0,0
 .globl l0750
l0750:
 .long 0
 .byte -7,0,0,0
 .globl l0751
l0751:
 .long 0
 .byte -6,0,0,0
 .globl l0752
l0752:
 .long 0
 .byte -5,0,0,0
 .globl l0753
l0753:
 .long 0
 .byte -4,0,0,0
 .globl l0754
l0754:
 .long 0
 .byte -3,0,0,0
 .globl l0755
l0755:
 .long 0
 .byte -2,0,0,0
 .globl l0756
l0756:
 .long 0
 .byte -1,0,0,0
 .globl l0757
l0757:
 .long 2
 .byte 110,105,108,0
 .globl l0758
l0758:
 .long 10
 .byte 102,105,114,115,116,107,101,114,110
 .byte 101,108,0
 .globl l0759
l0759:
 .long 4
 .byte 115,116,97,99,107,0,0,0
 .globl l0760
l0760:
 .long 12
 .byte 97,114,103,117,109,101,110,116,98,108
 .byte 111,99,107,0,0,0
 .globl l0761
l0761:
 .long 10
 .byte 116,111,107,101,110,98,117,102,102
 .byte 101,114,0
 .globl l0762
l0762:
 .long 5
 .byte 98,110,100,115,116,107,0,0
 .globl l0763
l0763:
 .long 9
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 0,0
 .globl l0764
l0764:
 .long 8
 .byte 104,97,115,104,116,97,98,108,101,0
 .byte 0,0
 .globl l0765
l0765:
 .long 12
 .byte 111,110,101,119,111,114,100,98,117
 .byte 102,102,101,114,0,0,0
 .globl l0766
l0766:
 .long 7
 .byte 115,97,118,101,97,114,103,99,0,0,0
 .byte 0
 .globl l0767
l0767:
 .long 7
 .byte 115,97,118,101,97,114,103,118,0,0,0
 .byte 0
 .globl l0768
l0768:
 .long 9
 .byte 100,97,116,101,98,117,102,102,101,114
 .byte 0,0
 .globl l0769
l0769:
 .long 7
 .byte 104,101,97,112,108,97,115,116,0,0,0
 .byte 0
 .globl l0770
l0770:
 .long 12
 .byte 104,101,97,112,116,114,97,112,98,111
 .byte 117,110,100,0,0,0
 .globl l0771
l0771:
 .long 15
 .byte 109,111,118,101,45,114,101,103,115
 .byte 45,116,111,45,109,101,109,0,0,0,0
 .globl l0772
l0772:
 .long 12
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 112,116,114,0,0,0
 .globl l0773
l0773:
 .long 15
 .byte 98,110,100,115,116,107,108,111,119
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .globl l0774
l0774:
 .long 15
 .byte 98,110,100,115,116,107,117,112,112
 .byte 101,114,98,111,117,110,100,0,0,0,0
 .globl l0775
l0775:
 .long 8
 .byte 98,110,100,115,116,107,112,116,114
 .byte 0,0,0
 .globl l0776
l0776:
 .long 13
 .byte 104,101,97,112,108,111,119,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0777
l0777:
 .long 3
 .byte 104,101,97,112,0,0,0,0
 .globl l0778
l0778:
 .long 12
 .byte 105,110,105,116,45,112,111,105,110
 .byte 116,101,114,115,0,0,0
 .globl l0779
l0779:
 .long 16
 .byte 103,99,97,114,114,97,121,108,111,119
 .byte 101,114,98,111,117,110,100,0,0,0
 .globl l0780
l0780:
 .long 16
 .byte 103,99,97,114,114,97,121,117,112,112
 .byte 101,114,98,111,117,110,100,0,0,0
 .globl l0781
l0781:
 .long 10
 .byte 111,108,100,104,101,97,112,108,97,115
 .byte 116,0
 .globl l0782
l0782:
 .long 15
 .byte 111,108,100,104,101,97,112,116,114
 .byte 97,112,98,111,117,110,100,0,0,0,0
 .globl l0783
l0783:
 .long 13
 .byte 104,101,97,112,117,112,112,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0784
l0784:
 .long 13
 .byte 95,105,110,102,98,105,116,108,101,110
 .byte 103,116,104,95,0,0
 .globl l0785
l0785:
 .long 6
 .byte 108,97,115,116,98,112,115,0
 .globl l0786
l0786:
 .long 12
 .byte 98,112,115,108,111,119,101,114,98,111
 .byte 117,110,100,0,0,0
 .globl l0787
l0787:
 .long 18
 .byte 109,97,105,110,115,116,97,114,116,105
 .byte 110,105,116,105,97,108,105,122,101
 .byte 0
 .globl l0788
l0788:
 .long 6
 .byte 110,101,120,116,98,112,115,0
 .globl l0789
l0789:
 .long 16
 .byte 111,108,100,104,101,97,112,117,112
 .byte 112,101,114,98,111,117,110,100,0,0
 .byte 0
 .globl l0790
l0790:
 .long 16
 .byte 111,108,100,104,101,97,112,108,111
 .byte 119,101,114,98,111,117,110,100,0,0
 .byte 0
 .globl l0791
l0791:
 .long 14
 .byte 115,116,97,99,107,117,112,112,101,114
 .byte 98,111,117,110,100,0
 .globl l0792
l0792:
 .long 8
 .byte 117,110,105,120,115,116,100,105,110
 .byte 0,0,0
 .globl l0793
l0793:
 .long 9
 .byte 117,110,105,120,115,116,100,111,117
 .byte 116,0,0
 .globl l0794
l0794:
 .long 9
 .byte 117,110,105,120,115,116,100,101,114
 .byte 114,0,0
 .globl l0795
l0795:
 .long 7
 .byte 117,110,105,120,110,117,108,108,0,0
 .byte 0,0
 .globl l0796
l0796:
 .long 6
 .byte 117,110,105,120,101,111,102,0
 .globl l0797
l0797:
 .long 6
 .byte 117,110,105,120,116,116,121,0
 .globl l0798
l0798:
 .long 16
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,42,42,42,0,0,0
 .globl l0799
l0799:
 .long 20
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,45,116,111,111,42,42
 .byte 42,0,0,0
 .globl l0800
l0800:
 .long 7
 .byte 42,102,97,115,116,99,97,114,0,0,0,0
 .globl l0801
l0801:
 .long 10
 .byte 105,110,105,116,45,102,108,117,105
 .byte 100,115,0
 .globl l0802
l0802:
 .long 5
 .byte 115,121,109,118,97,108,0,0
 .globl l0803
l0803:
 .long 5
 .byte 115,121,109,102,110,99,0,0
 .globl l0804
l0804:
 .long 14
 .byte 111,115,95,115,116,97,114,116,117,112
 .byte 95,104,111,111,107,0
 .globl l0805
l0805:
 .long 3
 .byte 97,114,103,99,0,0,0,0
 .globl l0806
l0806:
 .long 3
 .byte 97,114,103,118,0,0,0,0
 .globl l0807
l0807:
 .long 7
 .byte 101,98,120,115,97,118,101,42,0,0,0
 .byte 0
 .globl l0808
l0808:
 .long 14
 .byte 115,116,97,99,107,108,111,119,101,114
 .byte 98,111,117,110,100,0
 .globl l0809
l0809:
 .long 11
 .byte 105,110,105,116,45,103,99,97,114,114
 .byte 97,121,0,0,0,0
 .globl l0810
l0810:
 .long 7
 .byte 112,114,101,45,109,97,105,110,0,0,0
 .byte 0
 .globl l0811
l0811:
 .long 15
 .byte 101,120,105,116,45,119,105,116,104
 .byte 45,115,116,97,116,117,115,0,0,0,0
 .globl l0812
l0812:
 .long 14
 .byte 111,115,95,99,108,101,97,110,117,112
 .byte 95,104,111,111,107,0
 .globl l0813
l0813:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,101
 .byte 120,105,116,0,0,0
 .globl l0814
l0814:
 .long 8
 .byte 95,112,115,108,95,109,97,105,110,0
 .byte 0,0
 .globl l0815
l0815:
 .long 7
 .byte 114,101,100,117,99,101,117,112,0,0
 .byte 0,0
 .globl l0816
l0816:
 .long 8
 .byte 95,114,101,100,117,99,101,117,112,0
 .byte 0,0
 .globl l0817
l0817:
 .long 9
 .byte 115,116,114,105,110,103,111,112,101
 .byte 110,0,0
 .globl l0818
l0818:
 .long 9
 .byte 42,108,105,115,112,95,104,111,111,107
 .byte 0,0
 .globl l0819
l0819:
 .long 2
 .byte 114,100,115,0
 .globl l0820
l0820:
 .long 2
 .byte 119,114,115,0
 .globl l0821
l0821:
 .long 5
 .byte 98,101,103,105,110,49,0,0
 .globl l0822
l0822:
 .long 4
 .byte 99,108,111,115,101,0,0,0
 .globl l0823
l0823:
 .long 10
 .byte 117,110,105,120,99,108,101,97,114,105
 .byte 111,0
 .globl l0824
l0824:
 .long 22
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,115,121,109,98,111,108,45,116
 .byte 97,98,108,101,0
 .globl l0825
l0825:
 .long 7
 .byte 105,110,105,116,99,111,100,101,0,0
 .byte 0,0
 .globl l0826
l0826:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,115,116,114,105,110
 .byte 103,0,0,0,0
 .globl l0827
l0827:
 .long 14
 .byte 99,111,110,115,111,108,101,45,110,101
 .byte 119,108,105,110,101,0
 .globl l0828
l0828:
 .long 5
 .byte 102,97,115,108,105,110,0,0
 .globl l0829
l0829:
 .long 10
 .byte 108,111,97,100,101,114,45,109,97,105
 .byte 110,0
 .globl l0830
l0830:
 .long 7
 .byte 117,110,105,120,112,117,116,115,0,0
 .byte 0,0
 .globl l0831
l0831:
 .long 7
 .byte 117,110,105,120,112,117,116,110,0,0
 .byte 0,0
 .globl l0832
l0832:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,110,117,109,98,101,114
 .byte 0,0,0,0
 .globl l0833
l0833:
 .long 7
 .byte 117,110,105,120,112,117,116,99,0,0
 .byte 0,0
 .globl l0834
l0834:
 .long 7
 .byte 117,110,105,120,111,112,101,110,0,0
 .byte 0,0
 .globl l0835
l0835:
 .long 17
 .byte 107,101,114,110,101,108,45,102,97,116
 .byte 97,108,45,101,114,114,111,114,0,0
 .globl l0836
l0836:
 .long 13
 .byte 98,105,110,97,114,121,111,112,101,110
 .byte 114,101,97,100,0,0
 .globl l0837
l0837:
 .long 3
 .byte 103,101,116,119,0,0,0,0
 .globl l0838
l0838:
 .long 9
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 0,0
 .globl l0839
l0839:
 .long 4
 .byte 102,114,101,97,100,0,0,0
 .globl l0840
l0840:
 .long 14
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 98,108,111,99,107,0
 .globl l0841
l0841:
 .long 5
 .byte 102,99,108,111,115,101,0,0
 .globl l0842
l0842:
 .long 10
 .byte 98,105,110,97,114,121,99,108,111,115
 .byte 101,0
 .globl l0843
l0843:
 .long 9
 .byte 110,101,120,116,115,121,109,98,111
 .byte 108,0,0
 .globl l0844
l0844:
 .long 5
 .byte 115,121,109,110,97,109,0,0
 .globl l0845
l0845:
 .long 14
 .byte 104,97,115,104,45,105,110,116,111,45
 .byte 116,97,98,108,101,0
 .globl l0846
l0846:
 .long 11
 .byte 115,104,111,119,45,110,101,119,45,105
 .byte 100,115,0,0,0,0
 .globl l0847
l0847:
 .long 26
 .byte 115,101,97,114,99,104,45,115,116,114
 .byte 105,110,103,45,102,111,114,45,99,104
 .byte 97,114,97,99,116,101,114,0
 .globl l0848
l0848:
 .long 5
 .byte 105,110,116,101,114,110,0,0
 .globl l0849
l0849:
 .long 5
 .byte 115,117,98,115,101,113,0,0
 .globl l0850
l0850:
 .long 12
 .byte 102,97,115,108,105,110,45,105,110,116
 .byte 101,114,110,0,0,0
 .globl l0851
l0851:
 .long 22
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,105,110
 .byte 116,101,114,110,0
 .globl l0852
l0852:
 .long 3
 .byte 103,116,105,100,0,0,0,0
 .globl l0853
l0853:
 .long 9
 .byte 103,116,99,111,110,115,116,115,116
 .byte 114,0,0
 .globl l0854
l0854:
 .long 15
 .byte 99,111,112,121,115,116,114,105,110
 .byte 103,116,111,102,114,111,109,0,0,0,0
 .globl l0855
l0855:
 .long 16
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,110,101,119,45,105,100,0,0,0
 .globl l0856
l0856:
 .long 12
 .byte 104,97,115,104,45,102,117,110,99,116
 .byte 105,111,110,0,0,0
 .globl l0857
l0857:
 .long 21
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,101,113
 .byte 117,97,108,0,0
 .globl l0858
l0858:
 .long 5
 .byte 115,121,109,112,114,112,0,0
 .globl l0859
l0859:
 .long 5
 .byte 115,121,109,103,101,116,0,0
 .globl l0860
l0860:
 .long 11
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,0,0,0,0
 .globl l0861
l0861:
 .long 11
 .byte 114,101,103,105,115,116,101,114,99
 .byte 111,100,101,0,0,0,0
 .globl l0862
l0862:
 .long 9
 .byte 119,114,101,109,97,105,110,100,101
 .byte 114,0,0
 .globl l0863
l0863:
 .long 14
 .byte 102,97,115,108,105,110,45,98,97,100
 .byte 45,102,105,108,101,0
 .globl l0864
l0864:
 .long 12
 .byte 114,101,97,100,45,105,100,45,116,97
 .byte 98,108,101,0,0,0
 .globl l0865
l0865:
 .long 4
 .byte 103,116,98,112,115,0,0,0
 .globl l0866
l0866:
 .long 5
 .byte 103,116,119,114,100,115,0,0
 .globl l0867
l0867:
 .long 16
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,45,110,101,119,0,0,0
 .globl l0868
l0868:
 .long 12
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,0,0,0
 .globl l0869
l0869:
 .long 13
 .byte 99,111,100,101,45,98,97,115,101,45
 .byte 104,97,99,107,0,0
 .globl l0870
l0870:
 .long 12
 .byte 97,100,100,114,101,115,115,97,112,112
 .byte 108,121,48,0,0,0
 .globl l0871
l0871:
 .long 5
 .byte 100,101,108,98,112,115,0,0
 .globl l0872
l0872:
 .long 7
 .byte 98,105,116,116,97,98,108,101,0,0,0
 .byte 0
 .globl l0873
l0873:
 .long 12
 .byte 114,101,108,111,99,97,116,101,45,119
 .byte 111,114,100,0,0,0
 .globl l0874
l0874:
 .long 11
 .byte 114,101,108,111,99,97,116,101,45,105
 .byte 110,102,0,0,0,0
 .globl l0875
l0875:
 .long 18
 .byte 114,101,108,111,99,97,116,101,45,114
 .byte 105,103,104,116,45,104,97,108,102,0
 .globl l0876
l0876:
 .long 17
 .byte 99,111,109,112,117,116,101,45,114,101
 .byte 108,111,99,97,116,105,111,110,0,0
 .globl l0877
l0877:
 .long 17
 .byte 108,111,99,97,108,45,116,111,45,103
 .byte 108,111,98,97,108,45,105,100,0,0
 .globl l0878
l0878:
 .long 3
 .byte 112,117,116,100,0,0,0,0
 .globl l0879
l0879:
 .long 7
 .byte 112,117,116,101,110,116,114,121,0,0
 .byte 0,0
 .globl l0880
l0880:
 .long 14
 .byte 103,116,98,112,115,45,110,105,108,45
 .byte 101,114,114,111,114,0
 .globl l0881
l0881:
 .long 3
 .byte 103,101,116,100,0,0,0,0
 .globl l0882
l0882:
 .long 19
 .byte 116,114,121,45,111,116,104,101,114
 .byte 45,98,112,115,45,115,112,97,99,101
 .byte 115,0,0,0,0
 .globl l0883
l0883:
 .long 7
 .byte 115,116,100,101,114,114,111,114,0,0
 .byte 0,0
 .globl l0884
l0884:
 .long 15
 .byte 107,110,111,119,110,45,102,114,101
 .byte 101,45,115,112,97,99,101,0,0,0,0
 .globl l0885
l0885:
 .long 10
 .byte 114,101,97,108,45,103,116,104,101,97
 .byte 112,0
 .globl l0886
l0886:
 .long 5
 .byte 103,116,104,101,97,112,0,0
 .globl l0887
l0887:
 .long 12
 .byte 103,101,116,45,104,101,97,112,45,116
 .byte 114,97,112,0,0,0
 .globl l0888
l0888:
 .long 6
 .byte 114,101,99,108,97,105,109,0
 .globl l0889
l0889:
 .long 4
 .byte 103,116,115,116,114,0,0,0
 .globl l0890
l0890:
 .long 3
 .byte 99,111,110,115,0,0,0,0
 .globl l0891
l0891:
 .long 10
 .byte 105,110,116,101,114,114,111,103,97
 .byte 116,101,0
 .globl l0892
l0892:
 .long 5
 .byte 109,111,100,105,102,121,0,0
 .globl l0893
l0893:
 .long 12
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,117,116,0,0,0
 .globl l0894
l0894:
 .long 2
 .byte 112,117,116,0
 .globl l0895
l0895:
 .long 13
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,114,111,112,0,0
 .globl l0896
l0896:
 .long 4
 .byte 97,116,115,111,99,0,0,0
 .globl l0897
l0897:
 .long 7
 .byte 37,114,101,99,108,97,105,109,0,0,0
 .byte 0
 .globl l0898
l0898:
 .long 16
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,101,116,112,114,111,112,0,0,0
 .globl l0899
l0899:
 .long 8
 .byte 99,111,100,101,45,112,117,116,100,0
 .byte 0,0
 .globl l0900
l0900:
 .long 15
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,0,0,0,0
 .globl l0901
l0901:
 .long 3
 .byte 116,121,112,101,0,0,0,0
 .globl l0902
l0902:
 .long 3
 .byte 101,120,112,114,0,0,0,0
 .globl l0903
l0903:
 .long 5
 .byte 102,108,117,105,100,49,0,0
 .globl l0904
l0904:
 .long 4
 .byte 102,108,117,105,100,0,0,0
 .globl l0905
l0905:
 .long 6
 .byte 118,97,114,116,121,112,101,0
 .globl l0906
l0906:
 .long 15
 .byte 42,100,101,102,105,110,101,45,99,111
 .byte 110,115,116,97,110,116,0,0,0,0
 .globl l0907
l0907:
 .long 8
 .byte 99,111,110,115,116,97,110,116,63,0
 .byte 0,0
 .globl l0908
l0908:
 .long 14
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,0
 .globl l0909
l0909:
 .long 20
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,45,97
 .byte 117,120,0,0,0
 .globl l0910
l0910:
 .long 16
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,0,0
 .byte 0
 .globl l0911
l0911:
 .long 12
 .byte 42,116,101,104,99,97,108,108,101,100
 .byte 105,100,42,0,0,0
 .globl l0912
l0912:
 .long 8
 .byte 99,111,100,101,102,111,114,109,42,0
 .byte 0,0
 .globl l0913
l0913:
 .long 28
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,97,117
 .byte 120,0,0,0
 .globl l0914
l0914:
 .long 25
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,0,0
 .globl l0915
l0915:
 .long 5
 .byte 101,99,104,111,111,110,0,0
 .globl l0916
l0916:
 .long 6
 .byte 101,99,104,111,111,102,102,0
 .globl l0917
l0917:
 .long 26
 .byte 101,120,116,101,114,110,97,108,95,99
 .byte 104,97,114,115,105,110,105,110,112
 .byte 117,116,98,117,102,102,101,114,0
 .globl l0918
l0918:
 .long 19
 .byte 102,108,117,115,104,115,116,100,111
 .byte 117,116,112,117,116,98,117,102,102
 .byte 101,114,0,0,0,0
 .globl l0919
l0919:
 .long 27
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 115,101,114,95,104,111,109,101,100
 .byte 105,114,95,115,116,114,105,110,103
 .byte 0,0,0,0
 .globl l0920
l0920:
 .long 30
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 110,121,117,115,101,114,95,104,111
 .byte 109,101,100,105,114,95,115,116,114
 .byte 105,110,103,0
 .globl l0921
l0921:
 .long 12
 .byte 97,108,116,101,114,104,101,97,112,115
 .byte 105,122,101,0,0,0
 .globl l0922
l0922:
 .long 14
 .byte 97,108,108,111,99,97,116,101,109,111
 .byte 114,101,98,112,115,0
 .globl l0923
l0923:
 .long 16
 .byte 103,101,116,95,105,109,97,103,101,102
 .byte 105,108,101,112,97,116,104,0,0,0
 .globl l0924
l0924:
 .long 14
 .byte 103,101,116,95,102,105,108,101,95,115
 .byte 116,97,116,117,115,0
 .globl l0925
l0925:
 .long 15
 .byte 103,101,116,95,101,120,101,99,102,105
 .byte 108,101,112,97,116,104,0,0,0,0
 .globl l0926
l0926:
 .long 8
 .byte 119,113,117,111,116,105,101,110,116
 .byte 0,0,0
 .globl l0927
l0927:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 108,97,114,109,0,0
 .globl l0928
l0928:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 97,108,97,114,109,0
 .globl l0929
l0929:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,101,0,0,0
 .globl l0930
l0930:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,99,0,0,0
 .globl l0931
l0931:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,97,116,0,0,0
 .globl l0932
l0932:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,108
 .byte 105,110,107,0,0,0
 .globl l0933
l0933:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 110,108,105,110,107,0
 .globl l0934
l0934:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,114
 .byte 109,100,105,114,0,0
 .globl l0935
l0935:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,109
 .byte 107,100,105,114,0,0
 .globl l0936
l0936:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,114,108,101,110,0
 .globl l0937
l0937:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 101,116,101,110,118,0
 .globl l0938
l0938:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,103
 .byte 101,116,101,110,118,0
 .globl l0939
l0939:
 .long 6
 .byte 117,120,102,108,111,97,116,0
 .globl l0940
l0940:
 .long 4
 .byte 117,120,102,105,120,0,0,0
 .globl l0941
l0941:
 .long 7
 .byte 117,120,97,115,115,105,103,110,0,0
 .byte 0,0
 .globl l0942
l0942:
 .long 6
 .byte 117,120,109,105,110,117,115,0
 .globl l0943
l0943:
 .long 6
 .byte 117,120,112,108,117,115,50,0
 .globl l0944
l0944:
 .long 11
 .byte 117,120,100,105,102,102,101,114,101
 .byte 110,99,101,0,0,0,0
 .globl l0945
l0945:
 .long 7
 .byte 117,120,116,105,109,101,115,50,0,0
 .byte 0,0
 .globl l0946
l0946:
 .long 9
 .byte 117,120,113,117,111,116,105,101,110
 .byte 116,0,0
 .globl l0947
l0947:
 .long 9
 .byte 117,120,103,114,101,97,116,101,114
 .byte 112,0,0
 .globl l0948
l0948:
 .long 6
 .byte 117,120,108,101,115,115,112,0
 .globl l0949
l0949:
 .long 11
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,0,0,0,0
 .globl l0950
l0950:
 .long 15
 .byte 117,117,120,100,111,117,98,108,101
 .byte 116,111,102,108,111,97,116,0,0,0,0
 .globl l0951
l0951:
 .long 15
 .byte 117,117,120,102,108,111,97,116,116
 .byte 111,100,111,117,98,108,101,0,0,0,0
 .globl l0952
l0952:
 .long 5
 .byte 117,117,120,115,105,110,0,0
 .globl l0953
l0953:
 .long 5
 .byte 117,117,120,99,111,115,0,0
 .globl l0954
l0954:
 .long 5
 .byte 117,117,120,116,97,110,0,0
 .globl l0955
l0955:
 .long 6
 .byte 117,117,120,97,115,105,110,0
 .globl l0956
l0956:
 .long 6
 .byte 117,117,120,97,99,111,115,0
 .globl l0957
l0957:
 .long 6
 .byte 117,117,120,97,116,97,110,0
 .globl l0958
l0958:
 .long 6
 .byte 117,117,120,115,113,114,116,0
 .globl l0959
l0959:
 .long 5
 .byte 117,117,120,101,120,112,0,0
 .globl l0960
l0960:
 .long 5
 .byte 117,117,120,108,111,103,0,0
 .globl l0961
l0961:
 .long 7
 .byte 117,117,120,97,116,97,110,50,0,0,0
 .byte 0
 .globl l0962
l0962:
 .long 11
 .byte 101,120,116,101,114,110,97,108,95,112
 .byte 119,100,0,0,0,0
 .globl l0963
l0963:
 .long 10
 .byte 115,117,110,51,95,115,105,103,115,101
 .byte 116,0
 .globl l0964
l0964:
 .long 12
 .byte 115,117,110,51,95,115,105,103,114,101
 .byte 108,115,101,0,0,0
 .globl l0965
l0965:
 .long 7
 .byte 115,105,103,114,101,108,115,101,0,0
 .byte 0,0
 .globl l0966
l0966:
 .long 10
 .byte 109,97,115,107,95,115,105,103,110,97
 .byte 108,0
 .globl l0967
l0967:
 .long 5
 .byte 117,110,101,120,101,99,0,0
 .globl l0968
l0968:
 .long 15
 .byte 101,120,112,97,110,100,95,102,105,108
 .byte 101,95,110,97,109,101,0,0,0,0
 .globl l0969
l0969:
 .long 5
 .byte 117,110,105,120,99,100,0,0
 .globl l0970
l0970:
 .long 4
 .byte 99,116,105,109,101,0,0,0
 .globl l0971
l0971:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 121,115,116,101,109,0
 .globl l0972
l0972:
 .long 16
 .byte 101,120,116,101,114,110,97,108,95,102
 .byte 117,108,108,112,97,116,104,0,0,0
 .globl l0973
l0973:
 .long 4
 .byte 102,111,112,101,110,0,0,0
 .globl l0974
l0974:
 .long 4
 .byte 102,112,117,116,99,0,0,0
 .globl l0975
l0975:
 .long 4
 .byte 102,103,101,116,99,0,0,0
 .globl l0976
l0976:
 .long 4
 .byte 102,103,101,116,115,0,0,0
 .globl l0977
l0977:
 .long 5
 .byte 102,119,114,105,116,101,0,0
 .globl l0978
l0978:
 .long 5
 .byte 102,102,108,117,115,104,0,0
 .globl l0979
l0979:
 .long 4
 .byte 102,115,101,101,107,0,0,0
 .globl l0980
l0980:
 .long 7
 .byte 99,108,101,97,114,101,114,114,0,0,0
 .byte 0
 .globl l0981
l0981:
 .long 3
 .byte 112,117,116,119,0,0,0,0
 .globl l0982
l0982:
 .long 5
 .byte 115,105,103,110,97,108,0,0
 .globl l0983
l0983:
 .long 4
 .byte 115,108,101,101,112,0,0,0
 .globl l0984
l0984:
 .long 11
 .byte 105,101,101,101,95,104,97,110,100,108
 .byte 101,114,0,0,0,0
 .globl l0985
l0985:
 .long 9
 .byte 105,101,101,101,95,102,108,97,103,115
 .byte 0,0
 .globl l0986
l0986:
 .long 9
 .byte 115,101,116,108,105,110,101,98,117
 .byte 102,0,0
 .globl l0987
l0987:
 .long 5
 .byte 103,101,116,112,105,100,0,0
 .globl l0988
l0988:
 .long 8
 .byte 103,101,116,104,111,115,116,105,100
 .byte 0,0,0
 .globl l0989
l0989:
 .long 13
 .byte 117,110,105,120,115,111,99,107,101
 .byte 116,111,112,101,110,0,0
 .globl l0990
l0990:
 .long 8
 .byte 103,101,116,115,111,99,107,101,116
 .byte 0,0,0
 .globl l0991
l0991:
 .long 10
 .byte 119,114,105,116,101,115,111,99,107
 .byte 101,116,0
 .globl l0992
l0992:
 .long 14
 .byte 117,110,105,120,99,108,111,115,101
 .byte 115,111,99,107,101,116,0
 .globl l0993
l0993:
 .long 3
 .byte 102,111,114,107,0,0,0,0
 .globl l0994
l0994:
 .long 3
 .byte 119,97,105,116,0,0,0,0
 .globl l0995
l0995:
 .long 4
 .byte 112,111,112,101,110,0,0,0
 .globl l0996
l0996:
 .long 5
 .byte 112,99,108,111,115,101,0,0
 .globl l0997
l0997:
 .long 5
 .byte 115,104,109,99,116,108,0,0
 .globl l0998
l0998:
 .long 5
 .byte 115,104,109,103,101,116,0,0
 .globl l0999
l0999:
 .long 4
 .byte 115,104,109,97,116,0,0,0
 .globl l1000
l1000:
 .long 4
 .byte 115,104,109,100,116,0,0,0
 .globl l1001
l1001:
 .long 5
 .byte 115,101,109,99,116,108,0,0
 .globl l1002
l1002:
 .long 5
 .byte 115,101,109,103,101,116,0,0
 .globl l1003
l1003:
 .long 4
 .byte 115,101,109,111,112,0,0,0
 .globl l1004
l1004:
 .long 5
 .byte 100,108,111,112,101,110,0,0
 .globl l1005
l1005:
 .long 6
 .byte 100,108,101,114,114,111,114,0
 .globl l1006
l1006:
 .long 4
 .byte 100,108,115,121,109,0,0,0
 .globl l1007
l1007:
 .long 6
 .byte 100,108,99,108,111,115,101,0
 .globl l1008
l1008:
 .long 11
 .byte 117,110,105,120,45,112,114,111,102
 .byte 105,108,101,0,0,0,0
 .globl l1009
l1009:
 .long 14
 .byte 103,101,116,102,99,111,100,101,112
 .byte 111,105,110,116,101,114,0
 .globl l1010
l1010:
 .long 11
 .byte 99,111,100,101,97,100,100,114,101,115
 .byte 115,112,0,0,0,0
 .globl l1011
l1011:
 .long 9
 .byte 108,97,115,116,107,101,114,110,101
 .byte 108,0,0
 .globl symfnc
 .globl symget
