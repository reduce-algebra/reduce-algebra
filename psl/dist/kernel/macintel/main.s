        .text
 .long 1
// (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 ret
 .long 0
// (*entry move-regs-to-mem expr 0)
 .globl l0001
l0001:
 movl r10,%edi
 movl %edi,symval+1072
 movl r11,%edi
 movl %edi,symval+1076
 movl bndstkptr,%edi
 movl %edi,symval+1080
 movl bndstklowerbound,%edi
 movl %edi,symval+1084
 movl bndstkupperbound,%edi
 movl %edi,symval+1088
 ret
 .long 0
// (*entry init-pointers expr 0)
 .globl l0002
l0002:
 movl symval+1044,%edi
 movl %edi,symval+1096
 movl symval+1040,%edi
 movl %edi,symval+1084
 movl $7996,%eax
 add symval+1040,%eax
 movl %eax,symval+1088
 movl symval+1040,%edi
 movl %edi,symval+1080
 movl symval+1100,%eax
 movl %eax,symval+1104
 ret
 .long 0
// (*entry init-fluids expr 0)
 .globl l0003
l0003:
 movl $((30*0x8000000)+128),%eax
 movl %eax,symval+1112
 movl %eax,symval+1116
 movl %eax,symval+1072
 movl %eax,symval+1120
 movl %eax,symval+1076
 movl %eax,symval+1124
 movl %eax,symval+1128
 movl %eax,symval+1132
 movl %eax,symval+1136
 movl %eax,symval+1140
 movl %eax,symval+1144
 movl %eax,symval+1148
 movl %eax,symval+1152
 movl %eax,symval+1156
 movl %eax,symval+1160
 movl %eax,symval+1164
 movl %eax,symval+1168
 movl %eax,symval+1172
 movl %eax,symval+1176
 movl %eax,symval+1180
 movl %eax,symval+1184
 movl %eax,symval+1188
 movl %eax,symval+1192
 movl %eax,symval+1196
 ret
 .long 0
// (*entry _psl_main expr 0)
_psl_main:
 .globl _psl_main
 movl rdi,%eax
 movl rsi,%ebx
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,8(%esp)
 movl %edi,4(%esp)
 movl %edi,(%esp)
 call *symfnc+1204
 movl (%esp),%edi
 movl %edi,symval+1208
 movl 4(%esp),%edi
 movl %edi,symval+1212
 movl 8(%esp),%edi
 movl %edi,symval+1216
 call *symfnc+1092
 movl %esp,%edx
 shr $5,%edx
 movl %edx,symval+1220
 movl symval+1072,%edi
 movl %edi,r10
 movl symval+1076,%edi
 movl %edi,r11
 movl symval+1080,%edi
 movl %edi,bndstkptr
 movl symval+1084,%edi
 movl %edi,bndstklowerbound
 movl symval+1088,%edi
 movl %edi,bndstkupperbound
 movl $128,nil
 movl nil,%edi
 and $134217727,%edi
 or $-268435456,%edi
 movl %edi,nil
 call *symfnc+1224
l0004:
 xor %eax,%eax
 add $12,%esp
 jmp *symfnc+1228
 add $12,%esp
 ret
// (*entry exit-with-status expr 1)
 .globl l0005
l0005:
 push %eax
 call *symfnc+1232
 pop %eax
 call *symfnc+1236
 add $12,%esp
 ret
 .long 0
// (*entry init-gcarray expr 0)
 .globl l0006
l0006:
 movl $((30*0x8000000)+128),%eax
 ret
l0007:
 .long 21
 .byte 65,98,111,117,116,32,116,111,32,108
 .byte 111,97,100,32,76,79,65,68,45,80,83
 .byte 76,0,0
l0008:
 .long 9
 .byte 108,111,97,100,45,112,115,108,46,98
 .byte 0,0
 .long 0
// (*entry pre-_psl_main expr 0)
 .globl l0009
l0009:
 call *symfnc+1244
 call *symfnc+1248
 call *symfnc+1252
 movl $((4*0x8000000)+l0007),%eax
 call *symfnc+1256
 call *symfnc+1260
 movl $((4*0x8000000)+l0008),%eax
 call *symfnc+1264
 jmp *symfnc+1268
 .long 1
// (*entry console-print-string expr 1)
 .globl l0010
l0010:
 and $134217727,%eax
 add $4,%eax
 jmp *symfnc+1272
 .long 1
// (*entry console-print-number expr 1)
 .globl l0011
l0011:
 jmp *symfnc+1280
 .long 0
// (*entry console-newline expr 0)
 .globl l0012
l0012:
 movl $10,%eax
 jmp *symfnc+1284
l0013:
 .long 0
 .byte 114,0
l0014:
 .long 34
 .byte 67,111,117,108,100,110,39,116,32,111
 .byte 112,101,110,32,98,105,110,97,114,121
 .byte 32,102,105,108,101,32,102,111,114,32
 .byte 105,110,112,117,116,0
 .long 1
// (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 movl $((4*0x8000000)+l0013),%ebx
 and $134217727,%ebx
 add $4,%ebx
 and $134217727,%eax
 add $4,%eax
 call *symfnc+1292
 cmpl $0,%eax
 jne l0015
 movl $((4*0x8000000)+l0014),%eax
 jmp *symfnc+1296
l0015:
 ret
 .long 1
// (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 movl $325,%edi
 jmp *symfnc+1300
 .long 3
// (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 movl %ebx,%ebp
 movl %eax,%edx
 movl $8,%ebx
 movl %ebp,%eax
 jmp *symfnc+1312
 .long 1
// (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 jmp *symfnc+1320
 .long 0
// (*entry initialize-symbol-table expr 0)
 .globl l0016
l0016:
 sub $8,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,4(%esp)
 movl %edi,(%esp)
 movl $15000,%ebx
 movl *** Expression error `($global nextsymbol)' ***,%eax
 movl %eax,%edx
 movl %ebx,%ecx
l0017:
 cmpl %ecx,%edx
 jg l0018
 movl %edx,%eax
 shl $2,%eax
 add *** Expression error `($global symnam)' ***,%eax
 xor %ebx,%ebx
 incl %ebx
 add %edx,%ebx
 movl %ebx,(%eax)
 incl %edx
 jmp l0017
l0018:
 movl *** Expression error `($global symnam)' ***,%esi
 movl $0,60000(%esi)
 movl $18013,%ebx
 xor %eax,%eax
 movl %eax,(%esp)
 movl %ebx,4(%esp)
l0019:
 movl (%esp),%edi
 cmpl 4(%esp),%edi
 jg l0020
 xor %ecx,%ecx
 movl (%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw %cx,0(%ebx,%eax,1)
 incl (%esp)
 jmp l0019
l0020:
 movl *** Expression error `($global symnam)' ***,%edi
 movl 512(%edi),%eax
 call *symfnc+1324
 movl $128,%ecx
 movl %eax,%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw %cx,0(%ebx,%eax,1)
 xor %ebx,%ebx
 dec %ebx
 add *** Expression error `($global nextsymbol)' ***,%ebx
 movl $256,%eax
 movl %eax,(%esp)
 movl %ebx,4(%esp)
l0021:
 movl (%esp),%edi
 cmpl 4(%esp),%edi
 jg l0022
 movl (%esp),%eax
 shl $2,%eax
 add *** Expression error `($global symnam)' ***,%eax
 movl (%eax),%eax
 call *symfnc+1324
 movl (%esp),%ecx
 movl %eax,%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw %cx,0(%ebx,%eax,1)
 incl (%esp)
 jmp l0021
l0022:
 movl $((30*0x8000000)+128),%eax
 movl %eax,*** Expression error `($global show-new-ids)' ***
 add $8,%esp
 ret
 .long 1
// (*entry faslin-intern expr 1)
 .globl l0023
l0023:
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,8(%esp)
 movl %edi,4(%esp)
 movl %eax,(%esp)
 movl %eax,%ebx
 xor %eax,%eax
 call *symfnc+1332
 movl %eax,4(%esp)
 cmpl $((30*0x8000000)+128),%eax
 jne l0024
 movl (%esp),%eax
 add $12,%esp
 jmp *symfnc+1336
l0024:
 movl (%esp),%eax
 and $134217727,%eax
 movl (%eax),%eax
 shl $5,%eax
 sar $5,%eax
 movl %eax,8(%esp)
 cmpl 4(%esp),%eax
 jle l0025
 xor %ebx,%ebx
 incl %ebx
 add 4(%esp),%ebx
 movl (%esp),%eax
 and $134217727,%eax
 add $4,%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 cmpl $0,%eax
 jne l0025
 incl 4(%esp)
l0025:
 movl 4(%esp),%edi
 cmpl 8(%esp),%edi
 jl l0026
 movl (%esp),%eax
 jmp l0027
l0026:
 movl (%esp),%ecx
 and $134217727,%ecx
 movl (%ecx),%ecx
 shl $5,%ecx
 sar $5,%ecx
 incl %ecx
 xor %ebx,%ebx
 incl %ebx
 add 4(%esp),%ebx
 movl (%esp),%eax
 call *symfnc+1340
l0027:
 add $12,%esp
 jmp *symfnc+1336
 .long 1
// (*entry intern expr 1)
 .globl intern
intern:
 jmp *symfnc+1344
l0028:
 .long 7
 .byte 78,101,119,32,105,100,58,32,0,0
 .long 1
// (*entry unchecked-string-intern expr 1)
 .globl l0029
l0029:
 sub $24,%esp
 movl %eax,(%esp)
 movl $((30*0x8000000)+128),%ebp
 movl %ebp,%edx
 movl %ebp,%ecx
 movl %eax,%ebx
 and $134217727,%ebx
 movl (%ebx),%ebx
 shl $5,%ebx
 sar $5,%ebx
 and $134217727,%eax
 movl %eax,4(%esp)
 movl %ebx,8(%esp)
 movl %ecx,12(%esp)
 movl %edx,16(%esp)
 movl %ebp,20(%esp)
 cmpl $0,%ebx
 jne l0030
 add $4,%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 and $134217727,%eax
 or $-268435456,%eax
 jmp l0031
l0030:
 movl (%esp),%eax
 call *symfnc+1324
 movl %eax,%ebx
 movl %ebx,12(%esp)
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw 0(%eax,%ebx,1),%ax
 cwtl
 shl $16,%eax
 sar $16,%eax
 cmpl $0,%eax
 jle l0032
 movl 12(%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw 0(%eax,%ebx,1),%ax
 cwtl
 shl $16,%eax
 sar $16,%eax
 and $134217727,%eax
 or $-268435456,%eax
 jmp l0031
l0032:
 movl $((30*0x8000000)+128),%edi
 cmpl *** Expression error `($global show-new-ids)' ***,%edi
 je l0033
 movl $((4*0x8000000)+l0028),%eax
 call *symfnc+1256
 movl (%esp),%eax
 call *symfnc+1256
 call *symfnc+1260
l0033:
 call *symfnc+1348
 movl %eax,20(%esp)
 movl %eax,%ecx
 movl 12(%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw %cx,0(%ebx,%eax,1)
 movl 8(%esp),%eax
 call *symfnc+1352
 movl %eax,16(%esp)
 movl 4(%esp),%ebx
 call *symfnc+1356
 movl 16(%esp),%ebx
 and $134217727,%ebx
 or $536870912,%ebx
 movl 20(%esp),%eax
 add $24,%esp
 jmp *symfnc+1360
l0031:
 add $24,%esp
 ret
l0034:
 .long 18
 .byte 72,97,115,104,32,116,97,98,108,101
 .byte 32,111,118,101,114,102,108,111,119
 .byte 0
 .long 1
// (*entry hash-into-table expr 1)
 .globl l0035
l0035:
 sub $16,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,12(%esp)
 movl %edi,8(%esp)
 movl %edi,4(%esp)
 movl %eax,(%esp)
 call *symfnc+1364
 movl %eax,4(%esp)
 movl %eax,8(%esp)
 movl $-1,12(%esp)
l0036:
 movl 8(%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw 0(%eax,%ebx,1),%ax
 cwtl
 shl $16,%eax
 sar $16,%eax
 cmpl $0,%eax
 jne l0037
 cmpl $-1,12(%esp)
 je l0038
 movl 12(%esp),%eax
 jmp l0039
l0038:
 movl 8(%esp),%eax
l0039:
 jmp l0040
l0037:
 movl 8(%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw 0(%eax,%ebx,1),%ax
 cwtl
 movl %eax,%ebx
 shl $16,%ebx
 sar $16,%ebx
 cmpl $-1,%ebx
 jne l0041
 cmpl $-1,12(%esp)
 jne l0042
 movl 8(%esp),%edi
 movl %edi,12(%esp)
 jmp l0042
l0041:
 movl 8(%esp),%ebx
 movl *** Expression error `($fluid hashtable)' ***,%eax
 shl $1,%ebx
 movw 0(%eax,%ebx,1),%ax
 cwtl
 movl (%esp),%ebx
 shl $16,%eax
 sar $16,%eax
 shl $2,%eax
 add *** Expression error `($global symnam)' ***,%eax
 movl (%eax),%eax
 call *symfnc+1368
 cmpl $((30*0x8000000)+128),%eax
 je l0042
 movl 8(%esp),%eax
 jmp l0040
l0042:
 cmpl $18013,8(%esp)
 jne l0043
 xor %eax,%eax
 jmp l0044
l0043:
 xor %eax,%eax
 incl %eax
 add 8(%esp),%eax
l0044:
 movl %eax,8(%esp)
 cmpl 4(%esp),%eax
 jne l0036
 movl $((4*0x8000000)+l0034),%eax
 call *symfnc+1296
 jmp l0036
l0040:
 add $16,%esp
 ret
 .long 2
// (*entry initialize-new-id expr 2)
 .globl l0045
l0045:
 sub $8,%esp
 movl %eax,(%esp)
 and $134217727,%eax
 or $-268435456,%eax
 movl %eax,4(%esp)
 movl (%esp),%ecx
 shl $2,%ecx
 add *** Expression error `($global symnam)' ***,%ecx
 movl %ebx,(%ecx)
 movl (%esp),%edx
 shl $2,%edx
 add *** Expression error `($global symprp)' ***,%edx
 movl $((30*0x8000000)+128),%ebp
 movl %ebp,(%edx)
 movl (%esp),%eax
 shl $2,%eax
 add *** Expression error `($global symget)' ***,%eax
 movl %ebp,(%eax)
 movl (%esp),%eax
 shl $2,%eax
 add *** Expression error `($global symval)' ***,%eax
 movl (%esp),%ebx
 and $134217727,%ebx
 or $-402653184,%ebx
 movl %ebx,(%eax)
 movl (%esp),%eax
 call *symfnc+1372
 movl 4(%esp),%eax
 add $8,%esp
 ret
 .long 1
// (*entry hash-function expr 1)
 .globl l0048
l0048:
 sub $20,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,12(%esp)
 movl %edi,4(%esp)
 and $134217727,%eax
 movl %eax,8(%esp)
 movl (%eax),%eax
 shl $5,%eax
 sar $5,%eax
 movl %eax,(%esp)
 xor %eax,%eax
 movl %eax,16(%esp)
 cmpl $20,(%esp)
 jle l0049
 movl $20,(%esp)
l0049:
 movl (%esp),%ebx
 xor %eax,%eax
 movl %eax,12(%esp)
 movl %ebx,4(%esp)
l0050:
 movl 12(%esp),%edi
 cmpl 4(%esp),%edi
 jg l0051
 movl 12(%esp),%ebx
 movl $4,%eax
 add 8(%esp),%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 movl $24,%ebx
 sub 12(%esp),%ebx
 cmpl $0,%ebx
 jge l0046
 neg %ebx
 xchg %ebx,%ecx
 shr %cl,%eax
 jmp l0047
l0046:
 xchg %ebx,%ecx
 shl %cl,%eax
l0047:
 xchg %ebx,%ecx
 movl 16(%esp),%edi
 xor %edi,%eax
 movl %eax,16(%esp)
 incl 12(%esp)
 jmp l0050
l0051:
 movl $18013,%ebx
 movl 16(%esp),%eax
 add $20,%esp
 cltd
 idiv %ebx
 movl %edx,%eax
 ret
 .long 1
// (*entry faslin expr 1)
 .globl faslin
faslin:
 sub $44,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,32(%esp)
 movl %edi,12(%esp)
 movl %edi,8(%esp)
 movl %eax,(%esp)
 movl $((30*0x8000000)+128),16(%esp)
 movl $((30*0x8000000)+128),24(%esp)
 movl $((30*0x8000000)+128),28(%esp)
 movl $((30*0x8000000)+128),40(%esp)
 movl $((30*0x8000000)+128),4(%esp)
 movl $((30*0x8000000)+128),20(%esp)
 movl $((30*0x8000000)+128),36(%esp)
 call *symfnc+1288
 movl %eax,8(%esp)
 call *symfnc+1304
 movl %eax,12(%esp)
 movl $65535,%ebx
 and %eax,%ebx
 cmpl $399,%ebx
 je l0052
 movl 8(%esp),%eax
 call *symfnc+1316
 movl (%esp),%eax
 call *symfnc+1376
 jmp l0053
l0052:
 movl 12(%esp),%eax
 shr $16,%eax
 movl %eax,12(%esp)
 movl 8(%esp),%eax
 call *symfnc+1380
 movl %eax,16(%esp)
 movl 8(%esp),%eax
 call *symfnc+1304
 movl %eax,24(%esp)
 call *symfnc+1384
 movl %eax,28(%esp)
 xor %eax,%eax
 call *symfnc+1384
 movl %eax,36(%esp)
 movl 8(%esp),%eax
 call *symfnc+1304
 movl 28(%esp),%ebx
 add %eax,%ebx
 movl %ebx,40(%esp)
 movl 24(%esp),%ecx
 xor %ebx,%ebx
 add 28(%esp),%ebx
 movl 8(%esp),%eax
 call *symfnc+1308
 movl 8(%esp),%eax
 call *symfnc+1304
 movl %eax,4(%esp)
 call *symfnc+1388
 movl %eax,%ebx
 and $134217727,%ebx
 or $939524096,%ebx
 movl %ebx,20(%esp)
 movl 4(%esp),%ecx
 and $134217727,%ebx
 add $4,%ebx
 movl 8(%esp),%eax
 call *symfnc+1308
 movl 8(%esp),%eax
 call *symfnc+1316
 xor %eax,%eax
 incl %eax
 and 12(%esp),%eax
 cmpl $1,%eax
 jne l0054
 movl 16(%esp),%edx
 movl 20(%esp),%ecx
 movl 24(%esp),%ebx
 movl 28(%esp),%eax
 call *symfnc+1392
 jmp l0055
l0054:
 movl 16(%esp),%edx
 movl 20(%esp),%ecx
 movl 24(%esp),%ebx
 movl 28(%esp),%eax
 call *symfnc+1396
l0055:
 movl *** Expression error `($fluid code-base-hack)' ***,%eax
 movl %eax,32(%esp)
 movl 28(%esp),%edi
 movl %edi,*** Expression error `($fluid code-base-hack)' ***
 movl 40(%esp),%eax
 call *symfnc+1400
 movl 32(%esp),%edi
 movl %edi,*** Expression error `($fluid code-base-hack)' ***
 movl 36(%esp),%ebx
 movl 40(%esp),%eax
 call *symfnc+1404
l0053:
 movl $((30*0x8000000)+128),%eax
 add $44,%esp
 ret
 .long 2
// (*entry delbps expr 2)
 .globl delbps
delbps:
 movl $((30*0x8000000)+128),%eax
 ret
 .long 4
// (*entry do-relocation expr 4)
 .globl l0056
l0056:
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,16(%esp)
 movl %eax,12(%esp)
 movl %ecx,4(%esp)
 movl %edx,8(%esp)
 movl %ebx,%eax
 shl $2,%eax
 xor %ebx,%ebx
 dec %ebx
 add %eax,%ebx
 xor %eax,%eax
 movl %eax,20(%esp)
 movl %ebx,(%esp)
l0057:
 movl 20(%esp),%edi
 cmpl (%esp),%edi
 jle l0058
 movl $((30*0x8000000)+128),%eax
 jmp l0059
l0058:
 movl 20(%esp),%ebx
 movl 4(%esp),%eax
 and $134217727,%eax
 add $4,%eax
 movl $352,%edi
 call *symfnc+1408
 movl 12(%esp),%ebx
 add 20(%esp),%ebx
 movl %ebx,16(%esp)
 cmpl $1,%eax
 je l0060
 cmpl $2,%eax
 je l0061
 cmpl $3,%eax
 je l0062
 jmp l0063
l0060:
 movl 8(%esp),%ecx
 movl 12(%esp),%ebx
 movl 16(%esp),%eax
 call *symfnc+1412
 jmp l0063
l0062:
 movl 8(%esp),%ecx
 movl 12(%esp),%ebx
 movl 16(%esp),%eax
 call *symfnc+1416
 jmp l0063
l0061:
 movl 8(%esp),%ecx
 movl 12(%esp),%ebx
 movl 16(%esp),%eax
 call *symfnc+1420
l0063:
 incl 20(%esp)
 jmp l0057
l0059:
 add $24,%esp
 ret
 .long 4
// (*entry do-relocation-new expr 4)
 .globl l0064
l0064:
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,8(%esp)
 movl %eax,16(%esp)
 movl %ecx,(%esp)
 movl %edx,12(%esp)
 movl $((30*0x8000000)+128),%ecx
 movl %eax,%ebx
 xor %eax,%eax
 movl %eax,4(%esp)
 movl %ebx,20(%esp)
 movl (%esp),%ebp
 and $134217727,%ebp
 add $4,%ebp
 movl %ebp,(%esp)
l0065:
 movl 4(%esp),%ebx
 movl (%esp),%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 and $255,%eax
 movl %eax,8(%esp)
 cmpl $0,%eax
 jne l0066
 movl $((30*0x8000000)+128),%eax
 jmp l0067
l0066:
 incl 4(%esp)
 movl $63,%eax
 and 8(%esp),%eax
 add 20(%esp),%eax
 movl %eax,20(%esp)
 movl 8(%esp),%ebx
 shr $6,%ebx
 movl %ebx,8(%esp)
 movl %ebx,%eax
 cmpl $1,%eax
 je l0068
 cmpl $2,%eax
 je l0069
 cmpl $3,%eax
 je l0070
 jmp l0065
l0068:
 movl 12(%esp),%ecx
 movl 16(%esp),%ebx
 movl 20(%esp),%eax
 call *symfnc+1412
 jmp l0065
l0070:
 movl 12(%esp),%ecx
 movl 16(%esp),%ebx
 movl 20(%esp),%eax
 call *symfnc+1416
 jmp l0065
l0069:
 movl 12(%esp),%ecx
 movl 16(%esp),%ebx
 movl 20(%esp),%eax
 call *symfnc+1420
 jmp l0065
l0067:
 add $24,%esp
 ret
 .long 3
// (*entry relocate-word expr 3)
 .globl l0071
l0071:
 sub $16,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,12(%esp)
 movl %eax,(%esp)
 movl %ebx,4(%esp)
 movl %ecx,8(%esp)
 movl 0(%eax),%eax
 movl %eax,12(%esp)
 movl (%esp),%eax
 movl 0(%eax),%eax
 movl %eax,%ebx
 shl $34,%ebx
 shr $34,%ebx
 movl 12(%esp),%eax
 shl $32,%eax
 shr $62,%eax
 movl %eax,12(%esp)
 movl 8(%esp),%edx
 movl 4(%esp),%ecx
 call *symfnc+1424
 movl %eax,*** Expression error `($fluid tempo)' ***
 cmpl $2,12(%esp)
 je l0072
 cmpl $0,12(%esp)
 je l0072
 cmpl $3,12(%esp)
 jne l0073
l0072:
 add $-4,%eax
 sub (%esp),%eax
l0073:
 movl %eax,%ebx
 movl (%esp),%eax
 add $16,%esp
 movl %ebx,0(%rax)
 ret
 .long 3
// (*entry relocate-inf expr 3)
 .globl l0074
l0074:
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,4(%esp)
 movl %eax,8(%esp)
 movl %ebx,(%esp)
 movl (%eax),%ebx
 and $4194303,%ebx
 movl (%eax),%eax
 shr $54,%eax
 and $3,%eax
 movl %ecx,%edx
 movl (%esp),%ecx
 call *symfnc+1424
 movl %eax,*** Expression error `($fluid tempo)' ***
 movl %eax,4(%esp)
 movl 8(%esp),%esi
 movl (%esi),%eax
 shr $27,%eax
 shl $56,%eax
 or 4(%esp),%eax
 movl 8(%esp),%esi
 movl %eax,(%esi)
 add $12,%esp
 ret
 .long 4
// (*entry compute-relocation expr 4)
 .globl l0075
l0075:
 push %ebx
 cmpl $0,%eax
 jne l0076
 movl %ecx,%eax
 add %ebx,%eax
 jmp l0077
l0076:
 cmpl $2,%eax
 jne l0078
 cmpl $8150,%ebx
 jl l0079
 movl $-8156,%eax
 add %ebx,%eax
 shl $2,%eax
 add *** Expression error `($fluid argumentblock)' ***,%eax
 jmp l0077
l0079:
 cmpl $2048,%ebx
 jl l0080
 movl %edx,%ebx
 movl (%esp),%eax
 call *symfnc+1428
 shl $2,%eax
 add *** Expression error `($global symval)' ***,%eax
 jmp l0077
l0080:
 movl %ebx,%eax
 shl $2,%eax
 add *** Expression error `($global symval)' ***,%eax
 jmp l0077
l0078:
 cmpl $3,%eax
 jne l0081
 cmpl $2048,%ebx
 jl l0082
 movl %edx,%ebx
 movl (%esp),%eax
 call *symfnc+1428
 movl %eax,(%esp)
l0082:
 movl (%esp),%eax
 shl $2,%eax
 add *** Expression error `($global symfnc)' ***,%eax
 jmp l0077
l0081:
 cmpl $1,%eax
 jne l0083
 cmpl $2048,%ebx
 jl l0084
 movl %edx,%ebx
 movl (%esp),%eax
 add $4,%esp
 jmp *symfnc+1428
l0084:
 movl %ebx,%eax
 jmp l0077
l0083:
 movl $((30*0x8000000)+128),%eax
l0077:
 add $4,%esp
 ret
 .long 2
// (*entry local-to-global-id expr 2)
 .globl l0085
l0085:
 add $-2047,%eax
 shl $2,%eax
 movl %ebx,%ecx
 and $134217727,%ecx
 add %ecx,%eax
 movl (%eax),%eax
 ret
 .long 1
// (*entry read-id-table expr 1)
 .globl l0086
l0086:
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,20(%esp)
 movl %edi,16(%esp)
 movl %edi,12(%esp)
 movl %edi,8(%esp)
 movl %edi,4(%esp)
 movl %eax,(%esp)
 call *symfnc+1304
 movl %eax,4(%esp)
 incl %eax
 call *symfnc+1388
 and $134217727,%eax
 or $939524096,%eax
 movl %eax,8(%esp)
 movl 4(%esp),%ebx
 xor %eax,%eax
 movl %eax,12(%esp)
 movl %ebx,16(%esp)
l0087:
 movl 12(%esp),%edi
 cmpl 16(%esp),%edi
 jg l0088
 movl (%esp),%eax
 call *symfnc+1304
 movl *** Expression error `($fluid tokenbuffer)' ***,%esi
 movl %eax,(%esi)
 movl $5,%ecx
 add %eax,%ecx
 movl %ecx,%ebx
 shr $30,%ebx
 add %ebx,%ecx
 sar $2,%ecx
 movl $4,%ebx
 add *** Expression error `($fluid tokenbuffer)' ***,%ebx
 movl (%esp),%eax
 call *symfnc+1308
 xor %eax,%eax
 add *** Expression error `($fluid tokenbuffer)' ***,%eax
 and $134217727,%eax
 or $536870912,%eax
 call *symfnc+1328
 movl %eax,20(%esp)
 xor %eax,%eax
 incl %eax
 add 12(%esp),%eax
 shl $2,%eax
 movl 8(%esp),%ebx
 and $134217727,%ebx
 add %ebx,%eax
 movl 20(%esp),%ecx
 and $134217727,%ecx
 movl %ecx,(%eax)
 incl 12(%esp)
 jmp l0087
l0088:
 movl 8(%esp),%eax
 add $24,%esp
 ret
 .long 3
// (*entry putentry expr 3)
 .globl putentry
putentry:
 add *** Expression error `($fluid code-base-hack)' ***,%ecx
 and $134217727,%ecx
 or $-1610612736,%ecx
 movl $358,%edi
 jmp *symfnc+1432
l0089:
 .long 22
 .byte 70,105,108,101,32,105,115,32,110,111
 .byte 116,32,70,65,83,76,32,102,111,114,109
 .byte 97,116,0
 .long 1
// (*entry faslin-bad-file expr 1)
 .globl l0090
l0090:
 movl $((4*0x8000000)+l0089),%eax
 call *symfnc+1256
 jmp *symfnc+1260
l0091:
 .long 30
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,98,105,110,97,114,121,32,112,114
 .byte 111,103,114,97,109,32,115,112,97,99
 .byte 101,0
 .long 1
// (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 sub $4,%esp
l0092:
 movl %eax,(%esp)
 cmpl $((30*0x8000000)+128),%eax
 jne l0093
 call *symfnc+1444
l0093:
 cmpl $10,(%esp)
 jle l0094
 movl $15,%eax
 and *** Expression error `($global nextbps)' ***,%eax
 cmpl $0,%eax
 je l0094
 movl *** Expression error `($global nextbps)' ***,%ebx
 shr $4,%ebx
 shl $4,%ebx
 add $16,%ebx
 movl %ebx,*** Expression error `($global nextbps)' ***
l0094:
 movl *** Expression error `($global nextbps)' ***,%eax
 movl (%esp),%ebx
 shl $2,%ebx
 add *** Expression error `($global nextbps)' ***,%ebx
 movl %ebx,*** Expression error `($global nextbps)' ***
 cmpl *** Expression error `($global lastbps)' ***,%ebx
 jle l0095
 movl %eax,*** Expression error `($global nextbps)' ***
 movl $((30*0x8000000)+360),%eax
 call *symfnc+1448
 cmpl $((30*0x8000000)+128),%eax
 je l0096
 movl (%esp),%eax
 call *symfnc+1440
 cmpl $((30*0x8000000)+128),%eax
 je l0096
 movl (%esp),%eax
 jmp l0092
l0096:
 movl $((4*0x8000000)+l0091),%eax
 add $4,%esp
 jmp *symfnc+1452
l0095:
 add $4,%esp
 ret
l0097:
 .long 21
 .byte 71,84,66,80,83,32,99,97,108,108,101
 .byte 100,32,119,105,116,104,32,78,73,76
 .byte 46,0,0
 .long 0
// (*entry gtbps-nil-error expr 0)
 .globl l0098
l0098:
 movl $((4*0x8000000)+l0097),%eax
 jmp *symfnc+1452
 .long 1
// (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 cmpl $((30*0x8000000)+128),%eax
 jne l0099
 jmp *symfnc+1460
l0099:
 jmp *symfnc+1464
 .long 1
// (*entry real-gtheap expr 1)
 .globl l0100
l0100:
 movl %eax,%ecx
 movl *** Expression error `($global heaplast)' ***,%eax
 movl %ecx,%ebx
 shl $2,%ebx
 add *** Expression error `($global heaplast)' ***,%ebx
 movl %ebx,*** Expression error `($global heaplast)' ***
 cmpl *** Expression error `($global heaptrapbound)' ***,%ebx
 jl l0101
 movl %ecx,%ebx
 jmp *symfnc+1468
l0101:
 ret
l0102:
 .long 27
 .byte 71,97,114,98,97,103,101,32,99,111,108
 .byte 108,101,99,116,105,111,110,32,114,101
 .byte 113,117,105,114,101,100,46,0,0
 .long 1
// (*entry get-heap-trap expr 1)
 .globl l0103
l0103:
 movl $((4*0x8000000)+l0102),%eax
 jmp *symfnc+1296
l0104:
 .long 18
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,73,68,32,115,112,97,99,101,0
 .long 0
// (*entry gtid expr 0)
 .globl gtid
gtid:
 cmpl $0,*** Expression error `($global nextsymbol)' ***
 jne l0105
 call *symfnc+1472
 cmpl $0,*** Expression error `($global nextsymbol)' ***
 jne l0105
 movl $((4*0x8000000)+l0104),%eax
 call *symfnc+1296
l0105:
 movl *** Expression error `($global nextsymbol)' ***,%eax
 movl %eax,%ebx
 shl $2,%ebx
 add *** Expression error `($global symnam)' ***,%ebx
 movl (%ebx),%edi
 movl %edi,*** Expression error `($global nextsymbol)' ***
 ret
 .long 1
// (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 push %eax
 add $2,%eax
 call *symfnc+1456
 movl (%esp),%ebx
 and $134217727,%ebx
 or $-939524096,%ebx
 movl %ebx,(%eax)
 add $4,%esp
 ret
 .long 1
// (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 sub $8,%esp
 movl %eax,(%esp)
 add $5,%eax
 movl %eax,%ebx
 shr $30,%ebx
 add %ebx,%eax
 sar $2,%eax
 movl %eax,4(%esp)
 incl %eax
 call *symfnc+1384
 movl (%esp),%edi
 movl %edi,(%eax)
 movl 4(%esp),%ebx
 shl $2,%ebx
 add %eax,%ebx
 movl $0,(%ebx)
 add $8,%esp
 ret
l0106:
 .long 30
 .byte 83,85,66,83,69,81,32,99,97,108,108
 .byte 101,100,32,119,105,116,104,32,97,32
 .byte 110,111,110,45,115,116,114,105,110
 .byte 103,0
 .long 3
// (*entry subseq expr 3)
 .globl subseq
subseq:
 sub $32,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,28(%esp)
 movl %edi,24(%esp)
 movl %edi,20(%esp)
 movl %edi,16(%esp)
 movl %edi,12(%esp)
 movl %eax,(%esp)
 movl %ebx,4(%esp)
 movl %ecx,8(%esp)
 movl %eax,%edi
 shr $27,%edi
 cmpl $4,%edi
 je l0107
 movl $((4*0x8000000)+l0106),%eax
 call *symfnc+1296
l0107:
 xor %eax,%eax
 dec %eax
 add 8(%esp),%eax
 sub 4(%esp),%eax
 movl %eax,12(%esp)
 movl (%esp),%eax
 and $134217727,%eax
 movl %eax,16(%esp)
 movl 12(%esp),%eax
 call *symfnc+1476
 movl %eax,20(%esp)
 movl 12(%esp),%ebx
 xor %eax,%eax
 movl %eax,24(%esp)
 movl %ebx,28(%esp)
l0108:
 movl 24(%esp),%edi
 cmpl 28(%esp),%edi
 jg l0109
 movl 4(%esp),%ebx
 add 24(%esp),%ebx
 movl $4,%eax
 add 16(%esp),%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 movl %eax,%ecx
 movl 24(%esp),%ebx
 movl $4,%eax
 add 20(%esp),%eax
 movb %cl,0(%ebx,%eax,1)
 incl 24(%esp)
 jmp l0108
l0109:
 movl 20(%esp),%eax
 and $134217727,%eax
 or $536870912,%eax
 add $32,%esp
 ret
 .long 2
// (*entry search-string-for-character expr 2)
 .globl l0110
l0110:
 sub $16,%esp
 movl %eax,(%esp)
 movl %ebx,4(%esp)
 and $134217727,%ebx
 movl (%ebx),%ebx
 shl $5,%ebx
 sar $5,%ebx
 xor %eax,%eax
 movl %eax,8(%esp)
 movl %ebx,12(%esp)
l0111:
 movl 8(%esp),%edi
 cmpl 12(%esp),%edi
 jle l0112
 movl $((30*0x8000000)+128),%eax
 jmp l0113
l0112:
 movl 8(%esp),%ebx
 movl 4(%esp),%eax
 and $134217727,%eax
 add $4,%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 cmpl (%esp),%eax
 jne l0114
 movl 8(%esp),%eax
 jmp l0113
l0114:
 incl 8(%esp)
 jmp l0111
l0113:
 add $16,%esp
 ret
 .long 2
// (*entry unchecked-string-equal expr 2)
 .globl l0115
l0115:
 sub $20,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,16(%esp)
 movl $((30*0x8000000)+128),12(%esp)
 and $134217727,%eax
 movl %eax,(%esp)
 and $134217727,%ebx
 movl %ebx,4(%esp)
 movl (%eax),%ecx
 shl $5,%ecx
 sar $5,%ecx
 movl %ecx,8(%esp)
 movl (%ebx),%edx
 shl $5,%edx
 sar $5,%edx
 cmpl %edx,%ecx
 je l0116
 movl $((30*0x8000000)+128),%eax
 jmp l0117
l0116:
 movl $0,12(%esp)
l0118:
 movl 12(%esp),%edi
 cmpl 8(%esp),%edi
 jle l0119
 movl $((30*0x8000000)+116),%eax
 jmp l0117
l0119:
 movl 12(%esp),%ebx
 movl $4,%eax
 add (%esp),%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 movl %eax,16(%esp)
 movl 12(%esp),%ebx
 movl $4,%eax
 add 4(%esp),%eax
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 cmpl 16(%esp),%eax
 je l0120
 movl $((30*0x8000000)+128),%eax
 jmp l0117
l0120:
 incl 12(%esp)
 jmp l0118
l0117:
 add $20,%esp
 ret
 .long 2
// (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 sub $16,%esp
 movl %eax,12(%esp)
 movl %eax,%ecx
 and $134217727,%ecx
 movl %ecx,4(%esp)
 movl %ebx,%edx
 and $134217727,%edx
 movl %edx,8(%esp)
 movl (%edx),%ebp
 shl $5,%ebp
 sar $5,%ebp
 movl %ebp,(%esp)
 movl (%ecx),%eax
 shl $5,%eax
 sar $5,%eax
 cmpl %ebp,%eax
 jge l0121
 movl %eax,(%esp)
l0121:
 movl $5,%eax
 add (%esp),%eax
 movl %eax,%ebx
 shr $30,%ebx
 add %ebx,%eax
 sar $2,%eax
 dec %eax
 movl %eax,(%esp)
 movl %eax,%ebx
 xor %eax,%eax
 movl %eax,%edx
 movl %ebx,%ecx
l0122:
 cmpl %ecx,%edx
 jg l0123
 xor %eax,%eax
 incl %eax
 add %edx,%eax
 shl $2,%eax
 add 4(%esp),%eax
 xor %ebx,%ebx
 incl %ebx
 add %edx,%ebx
 shl $2,%ebx
 add 8(%esp),%ebx
 movl (%ebx),%edi
 movl %edi,(%eax)
 incl %edx
 jmp l0122
l0123:
 movl 12(%esp),%eax
 add $16,%esp
 ret
 .long 2
// (*entry cons expr 2)
 .globl cons
cons:
 push %ebx
 push %eax
 movl $2,%eax
 call *symfnc+1456
 movl (%esp),%edi
 movl %edi,(%eax)
 movl 4(%esp),%edi
 movl %edi,4(%eax)
 and $134217727,%eax
 or $1207959552,%eax
 add $8,%esp
 ret
 .long 1
// (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 shl $2,%eax
 add *** Expression error `($global symval)' ***,%eax
 movl (%eax),%eax
 ret
 .long 2
// (*entry modify expr 2)
 .globl modify
modify:
 shl $2,%eax
 add *** Expression error `($global symval)' ***,%eax
 movl %ebx,(%eax)
 movl %ebx,%eax
 ret
 .long 3
// (*entry put expr 3)
 .globl put
put:
 jmp *symfnc+1496
 .long 3
// (*entry unchecked-put expr 3)
 .globl l0124
l0124:
 sub $16,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,12(%esp)
 movl %eax,(%esp)
 movl %ebx,4(%esp)
 movl %ecx,8(%esp)
 call *symfnc+1500
 movl %eax,12(%esp)
 movl %eax,%ebx
 movl 4(%esp),%eax
 call *symfnc+1504
 cmpl $((30*0x8000000)+128),%eax
 je l0125
 movl 8(%esp),%edi
 movl %edi,-1207959548(%eax)
 jmp l0126
l0125:
 movl 8(%esp),%ebx
 movl 4(%esp),%eax
 call *symfnc+1480
 movl 12(%esp),%ebx
 call *symfnc+1480
 movl %eax,%ebx
 movl (%esp),%eax
 call *symfnc+1508
l0126:
 movl 8(%esp),%eax
 add $16,%esp
 ret
 .long 2
// (*entry atsoc expr 2)
 .globl atsoc
atsoc:
l0127:
 movl %ebx,%edi
 shr $27,%edi
 cmpl $9,%edi
 je l0128
 movl $((30*0x8000000)+128),%eax
 ret
l0128:
 movl -1207959552(%ebx),%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0129
 movl -1207959552(%ebx),%esi
 cmpl -1207959552(%esi),%eax
 jne l0129
 movl -1207959552(%ebx),%eax
 ret
l0129:
 movl -1207959548(%ebx),%ebx
 jmp l0127
 .long 2
// (*entry unchecked-setprop expr 2)
 .globl l0130
l0130:
 and $134217727,%eax
 shl $2,%eax
 add *** Expression error `($global symprp)' ***,%eax
 movl %ebx,(%eax)
 movl %ebx,%eax
 ret
 .long 1
// (*entry unchecked-prop expr 1)
 .globl l0131
l0131:
 and $134217727,%eax
 shl $2,%eax
 add *** Expression error `($global symprp)' ***,%eax
 movl (%eax),%eax
 ret
 .long 3
// (*entry putd expr 3)
 .globl putd
putd:
 jmp *symfnc+1512
l0132:
 .long 26
 .byte 66,97,100,32,112,97,114,97,109,101
 .byte 116,101,114,115,32,116,111,32,67,79
 .byte 68,69,45,80,85,84,68,0
 .long 3
// (*entry code-putd expr 3)
 .globl l0133
l0133:
 sub $12,%esp
 movl %eax,(%esp)
 movl %ebx,4(%esp)
 movl %ecx,8(%esp)
 movl %eax,%edi
 shr $27,%edi
 cmpl $30,%edi
 jne l0134
 movl %ebx,%edi
 shr $27,%edi
 cmpl $30,%edi
 jne l0134
 movl %ecx,%edi
 shr $27,%edi
 cmpl $20,%edi
 je l0135
l0134:
 movl $((4*0x8000000)+l0132),%eax
 call *symfnc+1296
l0135:
 movl 8(%esp),%ebx
 and $134217727,%ebx
 movl (%esp),%eax
 and $134217727,%eax
 call *symfnc+1524
 movl 4(%esp),%edi
 cmpl $((30*0x8000000)+379),%edi
 je l0136
 movl 4(%esp),%ecx
 movl $((30*0x8000000)+380),%ebx
 movl (%esp),%eax
 add $12,%esp
 jmp *symfnc+1492
l0136:
 movl $((30*0x8000000)+128),%eax
 add $12,%esp
 ret
 .long 1
// (*entry fluid expr 1)
 .globl fluid
fluid:
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 movl %edi,8(%esp)
 movl %eax,(%esp)
 movl $((30*0x8000000)+128),%eax
 movl (%esp),%edi
 movl %edi,4(%esp)
 movl 4(%esp),%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0137
 movl 4(%esp),%eax
 movl -1207959552(%eax),%eax
 jmp l0138
l0137:
 movl $((30*0x8000000)+128),%eax
l0138:
 movl %eax,8(%esp)
l0139:
 movl 4(%esp),%edi
 shr $27,%edi
 cmpl $9,%edi
 je l0140
 movl $((30*0x8000000)+128),%eax
 jmp l0141
l0140:
 movl 8(%esp),%eax
 call *symfnc+1532
 movl 4(%esp),%eax
 movl -1207959548(%eax),%eax
 movl %eax,4(%esp)
 movl %eax,%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0142
 movl -1207959552(%eax),%eax
 jmp l0143
l0142:
 movl $((30*0x8000000)+128),%eax
l0143:
 movl %eax,8(%esp)
 jmp l0139
l0141:
 add $12,%esp
 ret
 .long 1
// (*entry fluid1 expr 1)
 .globl l0144
l0144:
 movl $((30*0x8000000)+382),%ecx
 movl $((30*0x8000000)+384),%ebx
 jmp *symfnc+1492
 .long 1
// (*entry stderror expr 1)
 .globl stderror
stderror:
 jmp *symfnc+1296
 .long 2
// (*entry *define-constant expr 2)
 .globl l0145
l0145:
 movl %eax,%ecx
 and $134217727,%ecx
 shl $2,%ecx
 add *** Expression error `($global symval)' ***,%ecx
 movl %ebx,(%ecx)
 movl $((30*0x8000000)+116),%ecx
 movl $((30*0x8000000)+385),%ebx
 jmp *symfnc+1492
 .long 1
// (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 add %eax,%eax
 movl %eax,%ebx
 add %ebx,%ebx
 add %ebx,%ebx
 add *** Expression error `(fluid symfnc)' ***,%ebx
 movl UndefinedFunctionInstruction@GOTPCREL(%rip),%edi
 movl 0(%edi),%edi
 movl %edi,0(%ebx)
 ret
 .long 0
UndefinedFunctionInstruction:
 .long undefinedfunction
 .long 2
// (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 add %eax,%eax
 movl %eax,%ecx
 add %ecx,%ecx
 add %ecx,%ecx
 add *** Expression error `(fluid symfnc)' ***,%ecx
 movl %ebx,0(%ecx)
 ret
 .long 1
// (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 add %eax,%eax
 movl %eax,%ebx
 add %ebx,%ebx
 add %ebx,%ebx
 add *** Expression error `(fluid symfnc)' ***,%ebx
 movl LambdaLinkInstruction@GOTPCREL(%rip),%edi
 movl 0(%edi),%edi
 movl %edi,0(%ebx)
 ret
 .long 0
LambdaLinkInstruction:
 .long compiledcallinginterpreted
 .long 1
// (*entry addressapply0 expr 1)
 .globl l0146
l0146:
 jmp  *%eax
 .long 2
// (*entry bittable expr 2)
 .globl bittable
bittable:
 push %ebx
 shr $2,%ebx
 movb 0(%eax,%ebx,1),%al
 cbtw
 cwtl
 movl (%esp),%ebx
 and $3,%ebx
 add %ebx,%ebx
 add $-6,%ebx
 cmpl $0,%ebx
 jge l0147
 neg %ebx
 xchg %ebx,%ecx
 shr %cl,%eax
 jmp l0148
l0147:
 xchg %ebx,%ecx
 shl %cl,%eax
l0148:
 xchg %ebx,%ecx
 and $3,%eax
 add $4,%esp
 ret
 .long 1
// (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 movl _symfnc@GOTPCREL(%rip),t3
 jmp *(symfnc+1556)(t3)
l0149:
 .long 26
 .byte 85,110,100,101,102,105,110,101,100
 .byte 32,102,117,110,99,116,105,111,110,32
 .byte 99,97,108,108,101,100,58,32,0
 .long 1
// (*entry undefinedfunction-aux expr 1)
 .globl l0150
l0150:
 push %edi
 movl $((4*0x8000000)+l0149),%eax
 call *symfnc+1256
 movl *** Expression error `(fluid symnam)' ***,%esi
 pop %edi
 shl $3,%edi
 movl 0(%esi,%edi,1),%eax
 call *symfnc+1256
 xor %eax,%eax
 call *symfnc+1228
 ret
 .long 0
// (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 movl $30,%esi
 shl $27,%esi
 and $134217727,%edi
 or %esi,%edi
 movl %edi,*** Expression error `(fluid codeform*)' ***
 jmp *symfnc+1564
l0151:
 .long 12
 .byte 70,65,84,65,76,32,69,82,82,79,82,58
 .byte 32,0
 .long 1
// (*entry kernel-fatal-error expr 1)
 .globl l0152
l0152:
 push %eax
 movl $((4*0x8000000)+l0151),%eax
 call *symfnc+1256
 movl (%esp),%eax
 call *symfnc+1256
 call *symfnc+1260
 xor %eax,%eax
 dec %eax
 add $4,%esp
 jmp *symfnc+1228
l0153:
 .long 8
 .byte 73,110,116,101,114,114,117,112,116
 .byte 0
 .long 0
// (*entry pslsignalhandler expr 0)
 .globl pslsignalhandler
pslsignalhandler:
 movl $((4*0x8000000)+l0153),%eax
 call *symfnc+1452
 .globl echoon
 .long 0
// (*entry echoon expr 0)
 .globl l0154
l0154:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _echoon
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl echooff
 .long 0
// (*entry echooff expr 0)
 .globl l0155
l0155:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _echooff
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl external_charsininputbuffer
 .long 1
// (*entry external_charsininputbuffer expr 1)
 .globl l0156
l0156:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_charsininputbuffer
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl flushstdoutputbuffer
 .long 0
// (*entry flushstdoutputbuffer expr 0)
 .globl l0157
l0157:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _flushstdoutputbuffer
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl external_user_homedir_string
 .long 0
// (*entry external_user_homedir_string expr 0)
 .globl l0158
l0158:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_user_homedir_string
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl external_anyuser_homedir_string
 .long 1
// (*entry external_anyuser_homedir_string expr 1)
 .globl l0159
l0159:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_anyuser_homedir_string
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl alterheapsize
 .long 1
// (*entry alterheapsize expr 1)
 .globl l0160
l0160:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _alterheapsize
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl allocatemorebps
 .long 1
// (*entry allocatemorebps expr 1)
 .globl l0161
l0161:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _allocatemorebps
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl get_file_status
 .long 3
// (*entry get_file_status expr 3)
 .globl l0162
l0162:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _get_file_status
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl os_startup_hook
 .long 2
// (*entry os_startup_hook expr 2)
 .globl l0163
l0163:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _os_startup_hook
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl os_cleanup_hook
 .long 0
// (*entry os_cleanup_hook expr 0)
 .globl l0164
l0164:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _os_cleanup_hook
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl external_alarm
 .long 1
// (*entry external_alarm expr 1)
 .globl l0165
l0165:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_alarm
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_ualarm
 .long 2
// (*entry external_ualarm expr 2)
 .globl l0166
l0166:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_ualarm
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl external_time
 .long 1
// (*entry external_time expr 1)
 .globl l0167
l0167:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_time
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_timc
 .long 1
// (*entry external_timc expr 1)
 .globl l0168
l0168:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_timc
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_stat
 .long 2
// (*entry external_stat expr 2)
 .globl l0169
l0169:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_stat
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl external_link
 .long 2
// (*entry external_link expr 2)
 .globl l0170
l0170:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_link
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl external_unlink
 .long 1
// (*entry external_unlink expr 1)
 .globl l0171
l0171:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_unlink
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_strlen
 .long 1
// (*entry external_strlen expr 1)
 .globl l0172
l0172:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_strlen
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_setenv
 .long 2
// (*entry external_setenv expr 2)
 .globl l0173
l0173:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_setenv
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl external_getenv
 .long 1
// (*entry external_getenv expr 1)
 .globl l0174
l0174:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_getenv
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl uxfloat
 .long 2
// (*entry uxfloat expr 2)
 .globl l0175
l0175:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxfloat
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxfix
 .long 1
// (*entry uxfix expr 1)
 .globl l0176
l0176:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxfix
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl uxassign
 .long 2
// (*entry uxassign expr 2)
 .globl l0177
l0177:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxassign
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxplus2
 .long 3
// (*entry uxplus2 expr 3)
 .globl l0178
l0178:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxplus2
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl uxdifference
 .long 3
// (*entry uxdifference expr 3)
 .globl l0179
l0179:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxdifference
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl uxtimes2
 .long 3
// (*entry uxtimes2 expr 3)
 .globl l0180
l0180:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxtimes2
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl uxquotient
 .long 3
// (*entry uxquotient expr 3)
 .globl l0181
l0181:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxquotient
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl uxgreaterp
 .long 4
// (*entry uxgreaterp expr 4)
 .globl l0182
l0182:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxgreaterp
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl uxlessp
 .long 4
// (*entry uxlessp expr 4)
 .globl l0183
l0183:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxlessp
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl uxwritefloat
 .long 3
// (*entry uxwritefloat expr 3)
 .globl l0184
l0184:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxwritefloat
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl uxwritefloat8
 .long 4
// (*entry uxwritefloat8 expr 4)
 .globl l0185
l0185:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxwritefloat8
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl uxdoubletofloat
 .long 2
// (*entry uxdoubletofloat expr 2)
 .globl l0186
l0186:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxdoubletofloat
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxfloattodouble
 .long 2
// (*entry uxfloattodouble expr 2)
 .globl l0187
l0187:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxfloattodouble
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxsin
 .long 2
// (*entry uxsin expr 2)
 .globl l0188
l0188:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxsin
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxcos
 .long 2
// (*entry uxcos expr 2)
 .globl l0189
l0189:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxcos
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxtan
 .long 2
// (*entry uxtan expr 2)
 .globl l0190
l0190:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxtan
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxasin
 .long 2
// (*entry uxasin expr 2)
 .globl l0191
l0191:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxasin
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxacos
 .long 2
// (*entry uxacos expr 2)
 .globl l0192
l0192:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxacos
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxatan
 .long 2
// (*entry uxatan expr 2)
 .globl l0193
l0193:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxatan
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxsqrt
 .long 2
// (*entry uxsqrt expr 2)
 .globl l0194
l0194:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxsqrt
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxexp
 .long 2
// (*entry uxexp expr 2)
 .globl l0195
l0195:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxexp
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxlog
 .long 2
// (*entry uxlog expr 2)
 .globl l0196
l0196:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxlog
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl uxatan2
 .long 3
// (*entry uxatan2 expr 3)
 .globl l0197
l0197:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _uxatan2
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl external_pwd
 .long 0
// (*entry external_pwd expr 0)
 .globl l0198
l0198:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_pwd
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl sun3_sigset
 .long 2
// (*entry sun3_sigset expr 2)
 .globl l0199
l0199:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _sun3_sigset
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl sigrelse
 .long 1
// (*entry sigrelse expr 1)
 .globl l0200
l0200:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _sigrelse
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl unexec
 .long 4
// (*entry unexec expr 4)
 .globl l0201
l0201:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unexec
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl unixputc
 .long 1
// (*entry unixputc expr 1)
 .globl l0202
l0202:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixputc
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl unixputs
 .long 1
// (*entry unixputs expr 1)
 .globl l0203
l0203:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixputs
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl unixputn
 .long 1
// (*entry unixputn expr 1)
 .globl l0204
l0204:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixputn
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl unixcleario
 .long 0
// (*entry unixcleario expr 0)
 .globl l0205
l0205:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixcleario
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl expand_file_name
 .long 1
// (*entry expand_file_name expr 1)
 .globl l0206
l0206:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _expand_file_name
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl unixopen
 .long 2
// (*entry unixopen expr 2)
 .globl l0207
l0207:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixopen
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl unixcd
 .long 1
// (*entry unixcd expr 1)
 .globl l0208
l0208:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixcd
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl ctime
 .long 1
// (*entry ctime expr 1)
 .globl l0209
l0209:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _ctime
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_system
 .long 1
// (*entry external_system expr 1)
 .globl l0210
l0210:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_system
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl external_exit
 .long 1
// (*entry external_exit expr 1)
 .globl l0211
l0211:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _external_exit
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl fopen
 .long 2
// (*entry fopen expr 2)
 .globl l0212
l0212:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fopen
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl fclose
 .long 1
// (*entry fclose expr 1)
 .globl l0213
l0213:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fclose
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl fread
 .long 4
// (*entry fread expr 4)
 .globl l0214
l0214:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fread
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl fputc
 .long 2
// (*entry fputc expr 2)
 .globl l0215
l0215:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fputc
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl fgetc
 .long 1
// (*entry fgetc expr 1)
 .globl l0216
l0216:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fgetc
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl fgets
 .long 3
// (*entry fgets expr 3)
 .globl l0217
l0217:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fgets
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl fwrite
 .long 4
// (*entry fwrite expr 4)
 .globl l0218
l0218:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fwrite
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl fflush
 .long 1
// (*entry fflush expr 1)
 .globl l0219
l0219:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fflush
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl fseek
 .long 3
// (*entry fseek expr 3)
 .globl l0220
l0220:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fseek
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl clearerr
 .long 1
// (*entry clearerr expr 1)
 .globl l0221
l0221:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _clearerr
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl xgetw
 .long 1
// (*entry xgetw expr 1)
 .globl l0222
l0222:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _xgetw
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl putw
 .long 2
// (*entry putw expr 2)
 .globl l0223
l0223:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _putw
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl signal
 .long 2
// (*entry signal expr 2)
 .globl l0224
l0224:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _signal
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl sleep
 .long 1
// (*entry sleep expr 1)
 .globl l0225
l0225:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _sleep
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl ieee_handler
 .long 3
// (*entry ieee_handler expr 3)
 .globl l0226
l0226:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _ieee_handler
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl ieee_flags
 .long 4
// (*entry ieee_flags expr 4)
 .globl l0227
l0227:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _ieee_flags
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl setlinebuf
 .long 1
// (*entry setlinebuf expr 1)
 .globl l0228
l0228:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _setlinebuf
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl getpid
 .long 0
// (*entry getpid expr 0)
 .globl l0229
l0229:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _getpid
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl gethostid
 .long 0
// (*entry gethostid expr 0)
 .globl l0230
l0230:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _gethostid
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl unixsocketopen
 .long 2
// (*entry unixsocketopen expr 2)
 .globl l0231
l0231:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixsocketopen
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl getsocket
 .long 3
// (*entry getsocket expr 3)
 .globl l0232
l0232:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _getsocket
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl writesocket
 .long 3
// (*entry writesocket expr 3)
 .globl l0233
l0233:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _writesocket
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl unixclosesocket
 .long 1
// (*entry unixclosesocket expr 1)
 .globl l0234
l0234:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _unixclosesocket
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl fork
 .long 0
// (*entry fork expr 0)
 .globl l0235
l0235:
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _fork
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 ret
 .globl wait
 .long 1
// (*entry wait expr 1)
 .globl l0236
l0236:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _wait
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl popen
 .long 2
// (*entry popen expr 2)
 .globl l0237
l0237:
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _popen
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $8,%esp
 ret
 .globl pclose
 .long 1
// (*entry pclose expr 1)
 .globl l0238
l0238:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _pclose
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl shmctl
 .long 3
// (*entry shmctl expr 3)
 .globl l0239
l0239:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _shmctl
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl shmget
 .long 3
// (*entry shmget expr 3)
 .globl l0240
l0240:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _shmget
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl shmat
 .long 3
// (*entry shmat expr 3)
 .globl l0241
l0241:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _shmat
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl shmdt
 .long 1
// (*entry shmdt expr 1)
 .globl l0242
l0242:
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _shmdt
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $4,%esp
 ret
 .globl semctl
 .long 4
// (*entry semctl expr 4)
 .globl l0243
l0243:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _semctl
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .globl semget
 .long 3
// (*entry semget expr 3)
 .globl l0244
l0244:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _semget
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl semop
 .long 3
// (*entry semop expr 3)
 .globl l0245
l0245:
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _semop
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $12,%esp
 ret
 .globl profil
 .long 4
// (*entry unix-profile expr 4)
 .globl l0246
l0246:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl *** Expression error `(fluid ebxsave*)' ***,%ebx
 call _profil
 movl %ebx,*** Expression error `(fluid ebxsave*)' ***
 add $16,%esp
 ret
 .long 1
// (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 sub $4,%esp
 and $134217727,%eax
 movl %eax,(%esp)
 movl $((30*0x8000000)+256),%eax
 call *symfnc+1908
 and $134217727,%eax
 cmpl (%esp),%eax
 jle l0247
 movl $((30*0x8000000)+128),%eax
 jmp l0248
l0247:
 movl $((30*0x8000000)+116),%eax
l0248:
 cmpl $((30*0x8000000)+128),%eax
 je l0249
 movl $((30*0x8000000)+475),%eax
 call *symfnc+1908
 and $134217727,%eax
 cmpl (%esp),%eax
 jg l0250
 movl $((30*0x8000000)+128),%eax
 jmp l0249
l0250:
 movl $((30*0x8000000)+116),%eax
l0249:
 cmpl $((30*0x8000000)+128),%eax
 jne l0251
 movl *** Expression error `($global bpslowerbound)' ***,%eax
 and $134217727,%eax
 cmpl (%esp),%eax
 jle l0252
 movl $((30*0x8000000)+128),%eax
 jmp l0253
l0252:
 movl $((30*0x8000000)+116),%eax
l0253:
 cmpl $((30*0x8000000)+128),%eax
 je l0251
 movl *** Expression error `($global nextbps)' ***,%eax
 and $134217727,%eax
 cmpl (%esp),%eax
 jg l0254
 movl $((30*0x8000000)+128),%eax
 jmp l0251
l0254:
 movl $((30*0x8000000)+116),%eax
l0251:
 add $4,%esp
 ret
 .long 1
// (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 ret
 .long 0
// (*entry initcode expr 0)
 .globl initcode
initcode:
 movl $((30*0x8000000)+128),%eax
 ret
 .globl symval
 .globl symprp
 .globl symnam
 .globl l0255
l0255:
 .long 0
 .byte 0,0
 .globl l0256
l0256:
 .long 0
 .byte 1,0
 .globl l0257
l0257:
 .long 0
 .byte 2,0
 .globl l0258
l0258:
 .long 0
 .byte 3,0
 .globl l0259
l0259:
 .long 0
 .byte 4,0
 .globl l0260
l0260:
 .long 0
 .byte 5,0
 .globl l0261
l0261:
 .long 0
 .byte 6,0
 .globl l0262
l0262:
 .long 0
 .byte 7,0
 .globl l0263
l0263:
 .long 0
 .byte 8,0
 .globl l0264
l0264:
 .long 0
 .byte 9,0
 .globl l0265
l0265:
 .long 0
 .byte 10,0
 .globl l0266
l0266:
 .long 0
 .byte 11,0
 .globl l0267
l0267:
 .long 0
 .byte 12,0
 .globl l0268
l0268:
 .long 0
 .byte 13,0
 .globl l0269
l0269:
 .long 0
 .byte 14,0
 .globl l0270
l0270:
 .long 0
 .byte 15,0
 .globl l0271
l0271:
 .long 0
 .byte 16,0
 .globl l0272
l0272:
 .long 0
 .byte 17,0
 .globl l0273
l0273:
 .long 0
 .byte 18,0
 .globl l0274
l0274:
 .long 0
 .byte 19,0
 .globl l0275
l0275:
 .long 0
 .byte 20,0
 .globl l0276
l0276:
 .long 0
 .byte 21,0
 .globl l0277
l0277:
 .long 0
 .byte 22,0
 .globl l0278
l0278:
 .long 0
 .byte 23,0
 .globl l0279
l0279:
 .long 0
 .byte 24,0
 .globl l0280
l0280:
 .long 0
 .byte 25,0
 .globl l0281
l0281:
 .long 0
 .byte 26,0
 .globl l0282
l0282:
 .long 0
 .byte 27,0
 .globl l0283
l0283:
 .long 0
 .byte 28,0
 .globl l0284
l0284:
 .long 0
 .byte 29,0
 .globl l0285
l0285:
 .long 0
 .byte 30,0
 .globl l0286
l0286:
 .long 0
 .byte 31,0
 .globl l0287
l0287:
 .long 0
 .byte 32,0
 .globl l0288
l0288:
 .long 0
 .byte 33,0
 .globl l0289
l0289:
 .long 0
 .byte 34,0
 .globl l0290
l0290:
 .long 0
 .byte 35,0
 .globl l0291
l0291:
 .long 0
 .byte 36,0
 .globl l0292
l0292:
 .long 0
 .byte 37,0
 .globl l0293
l0293:
 .long 0
 .byte 38,0
 .globl l0294
l0294:
 .long 0
 .byte 39,0
 .globl l0295
l0295:
 .long 0
 .byte 40,0
 .globl l0296
l0296:
 .long 0
 .byte 41,0
 .globl l0297
l0297:
 .long 0
 .byte 42,0
 .globl l0298
l0298:
 .long 0
 .byte 43,0
 .globl l0299
l0299:
 .long 0
 .byte 44,0
 .globl l0300
l0300:
 .long 0
 .byte 45,0
 .globl l0301
l0301:
 .long 0
 .byte 46,0
 .globl l0302
l0302:
 .long 0
 .byte 47,0
 .globl l0303
l0303:
 .long 0
 .byte 48,0
 .globl l0304
l0304:
 .long 0
 .byte 49,0
 .globl l0305
l0305:
 .long 0
 .byte 50,0
 .globl l0306
l0306:
 .long 0
 .byte 51,0
 .globl l0307
l0307:
 .long 0
 .byte 52,0
 .globl l0308
l0308:
 .long 0
 .byte 53,0
 .globl l0309
l0309:
 .long 0
 .byte 54,0
 .globl l0310
l0310:
 .long 0
 .byte 55,0
 .globl l0311
l0311:
 .long 0
 .byte 56,0
 .globl l0312
l0312:
 .long 0
 .byte 57,0
 .globl l0313
l0313:
 .long 0
 .byte 58,0
 .globl l0314
l0314:
 .long 0
 .byte 59,0
 .globl l0315
l0315:
 .long 0
 .byte 60,0
 .globl l0316
l0316:
 .long 0
 .byte 61,0
 .globl l0317
l0317:
 .long 0
 .byte 62,0
 .globl l0318
l0318:
 .long 0
 .byte 63,0
 .globl l0319
l0319:
 .long 0
 .byte 64,0
 .globl l0320
l0320:
 .long 0
 .byte 65,0
 .globl l0321
l0321:
 .long 0
 .byte 66,0
 .globl l0322
l0322:
 .long 0
 .byte 67,0
 .globl l0323
l0323:
 .long 0
 .byte 68,0
 .globl l0324
l0324:
 .long 0
 .byte 69,0
 .globl l0325
l0325:
 .long 0
 .byte 70,0
 .globl l0326
l0326:
 .long 0
 .byte 71,0
 .globl l0327
l0327:
 .long 0
 .byte 72,0
 .globl l0328
l0328:
 .long 0
 .byte 73,0
 .globl l0329
l0329:
 .long 0
 .byte 74,0
 .globl l0330
l0330:
 .long 0
 .byte 75,0
 .globl l0331
l0331:
 .long 0
 .byte 76,0
 .globl l0332
l0332:
 .long 0
 .byte 77,0
 .globl l0333
l0333:
 .long 0
 .byte 78,0
 .globl l0334
l0334:
 .long 0
 .byte 79,0
 .globl l0335
l0335:
 .long 0
 .byte 80,0
 .globl l0336
l0336:
 .long 0
 .byte 81,0
 .globl l0337
l0337:
 .long 0
 .byte 82,0
 .globl l0338
l0338:
 .long 0
 .byte 83,0
 .globl l0339
l0339:
 .long 0
 .byte 84,0
 .globl l0340
l0340:
 .long 0
 .byte 85,0
 .globl l0341
l0341:
 .long 0
 .byte 86,0
 .globl l0342
l0342:
 .long 0
 .byte 87,0
 .globl l0343
l0343:
 .long 0
 .byte 88,0
 .globl l0344
l0344:
 .long 0
 .byte 89,0
 .globl l0345
l0345:
 .long 0
 .byte 90,0
 .globl l0346
l0346:
 .long 0
 .byte 91,0
 .globl l0347
l0347:
 .long 0
 .byte 92,0
 .globl l0348
l0348:
 .long 0
 .byte 93,0
 .globl l0349
l0349:
 .long 0
 .byte 94,0
 .globl l0350
l0350:
 .long 0
 .byte 95,0
 .globl l0351
l0351:
 .long 0
 .byte 96,0
 .globl l0352
l0352:
 .long 0
 .byte 97,0
 .globl l0353
l0353:
 .long 0
 .byte 98,0
 .globl l0354
l0354:
 .long 0
 .byte 99,0
 .globl l0355
l0355:
 .long 0
 .byte 100,0
 .globl l0356
l0356:
 .long 0
 .byte 101,0
 .globl l0357
l0357:
 .long 0
 .byte 102,0
 .globl l0358
l0358:
 .long 0
 .byte 103,0
 .globl l0359
l0359:
 .long 0
 .byte 104,0
 .globl l0360
l0360:
 .long 0
 .byte 105,0
 .globl l0361
l0361:
 .long 0
 .byte 106,0
 .globl l0362
l0362:
 .long 0
 .byte 107,0
 .globl l0363
l0363:
 .long 0
 .byte 108,0
 .globl l0364
l0364:
 .long 0
 .byte 109,0
 .globl l0365
l0365:
 .long 0
 .byte 110,0
 .globl l0366
l0366:
 .long 0
 .byte 111,0
 .globl l0367
l0367:
 .long 0
 .byte 112,0
 .globl l0368
l0368:
 .long 0
 .byte 113,0
 .globl l0369
l0369:
 .long 0
 .byte 114,0
 .globl l0370
l0370:
 .long 0
 .byte 115,0
 .globl l0371
l0371:
 .long 0
 .byte 116,0
 .globl l0372
l0372:
 .long 0
 .byte 117,0
 .globl l0373
l0373:
 .long 0
 .byte 118,0
 .globl l0374
l0374:
 .long 0
 .byte 119,0
 .globl l0375
l0375:
 .long 0
 .byte 120,0
 .globl l0376
l0376:
 .long 0
 .byte 121,0
 .globl l0377
l0377:
 .long 0
 .byte 122,0
 .globl l0378
l0378:
 .long 0
 .byte 123,0
 .globl l0379
l0379:
 .long 0
 .byte 124,0
 .globl l0380
l0380:
 .long 0
 .byte 125,0
 .globl l0381
l0381:
 .long 0
 .byte 126,0
 .globl l0382
l0382:
 .long 0
 .byte 127,0
 .globl l0383
l0383:
 .long 2
 .byte 110,105,108,0
 .globl l0384
l0384:
 .long 0
 .byte -127,0
 .globl l0385
l0385:
 .long 0
 .byte -126,0
 .globl l0386
l0386:
 .long 0
 .byte -125,0
 .globl l0387
l0387:
 .long 0
 .byte -124,0
 .globl l0388
l0388:
 .long 0
 .byte -123,0
 .globl l0389
l0389:
 .long 0
 .byte -122,0
 .globl l0390
l0390:
 .long 0
 .byte -121,0
 .globl l0391
l0391:
 .long 0
 .byte -120,0
 .globl l0392
l0392:
 .long 0
 .byte -119,0
 .globl l0393
l0393:
 .long 0
 .byte -118,0
 .globl l0394
l0394:
 .long 0
 .byte -117,0
 .globl l0395
l0395:
 .long 0
 .byte -116,0
 .globl l0396
l0396:
 .long 0
 .byte -115,0
 .globl l0397
l0397:
 .long 0
 .byte -114,0
 .globl l0398
l0398:
 .long 0
 .byte -113,0
 .globl l0399
l0399:
 .long 0
 .byte -112,0
 .globl l0400
l0400:
 .long 0
 .byte -111,0
 .globl l0401
l0401:
 .long 0
 .byte -110,0
 .globl l0402
l0402:
 .long 0
 .byte -109,0
 .globl l0403
l0403:
 .long 0
 .byte -108,0
 .globl l0404
l0404:
 .long 0
 .byte -107,0
 .globl l0405
l0405:
 .long 0
 .byte -106,0
 .globl l0406
l0406:
 .long 0
 .byte -105,0
 .globl l0407
l0407:
 .long 0
 .byte -104,0
 .globl l0408
l0408:
 .long 0
 .byte -103,0
 .globl l0409
l0409:
 .long 0
 .byte -102,0
 .globl l0410
l0410:
 .long 0
 .byte -101,0
 .globl l0411
l0411:
 .long 0
 .byte -100,0
 .globl l0412
l0412:
 .long 0
 .byte -99,0
 .globl l0413
l0413:
 .long 0
 .byte -98,0
 .globl l0414
l0414:
 .long 0
 .byte -97,0
 .globl l0415
l0415:
 .long 0
 .byte -96,0
 .globl l0416
l0416:
 .long 0
 .byte -95,0
 .globl l0417
l0417:
 .long 0
 .byte -94,0
 .globl l0418
l0418:
 .long 0
 .byte -93,0
 .globl l0419
l0419:
 .long 0
 .byte -92,0
 .globl l0420
l0420:
 .long 0
 .byte -91,0
 .globl l0421
l0421:
 .long 0
 .byte -90,0
 .globl l0422
l0422:
 .long 0
 .byte -89,0
 .globl l0423
l0423:
 .long 0
 .byte -88,0
 .globl l0424
l0424:
 .long 0
 .byte -87,0
 .globl l0425
l0425:
 .long 0
 .byte -86,0
 .globl l0426
l0426:
 .long 0
 .byte -85,0
 .globl l0427
l0427:
 .long 0
 .byte -84,0
 .globl l0428
l0428:
 .long 0
 .byte -83,0
 .globl l0429
l0429:
 .long 0
 .byte -82,0
 .globl l0430
l0430:
 .long 0
 .byte -81,0
 .globl l0431
l0431:
 .long 0
 .byte -80,0
 .globl l0432
l0432:
 .long 0
 .byte -79,0
 .globl l0433
l0433:
 .long 0
 .byte -78,0
 .globl l0434
l0434:
 .long 0
 .byte -77,0
 .globl l0435
l0435:
 .long 0
 .byte -76,0
 .globl l0436
l0436:
 .long 0
 .byte -75,0
 .globl l0437
l0437:
 .long 0
 .byte -74,0
 .globl l0438
l0438:
 .long 0
 .byte -73,0
 .globl l0439
l0439:
 .long 0
 .byte -72,0
 .globl l0440
l0440:
 .long 0
 .byte -71,0
 .globl l0441
l0441:
 .long 0
 .byte -70,0
 .globl l0442
l0442:
 .long 0
 .byte -69,0
 .globl l0443
l0443:
 .long 0
 .byte -68,0
 .globl l0444
l0444:
 .long 0
 .byte -67,0
 .globl l0445
l0445:
 .long 0
 .byte -66,0
 .globl l0446
l0446:
 .long 0
 .byte -65,0
 .globl l0447
l0447:
 .long 0
 .byte -64,0
 .globl l0448
l0448:
 .long 0
 .byte -63,0
 .globl l0449
l0449:
 .long 0
 .byte -62,0
 .globl l0450
l0450:
 .long 0
 .byte -61,0
 .globl l0451
l0451:
 .long 0
 .byte -60,0
 .globl l0452
l0452:
 .long 0
 .byte -59,0
 .globl l0453
l0453:
 .long 0
 .byte -58,0
 .globl l0454
l0454:
 .long 0
 .byte -57,0
 .globl l0455
l0455:
 .long 0
 .byte -56,0
 .globl l0456
l0456:
 .long 0
 .byte -55,0
 .globl l0457
l0457:
 .long 0
 .byte -54,0
 .globl l0458
l0458:
 .long 0
 .byte -53,0
 .globl l0459
l0459:
 .long 0
 .byte -52,0
 .globl l0460
l0460:
 .long 0
 .byte -51,0
 .globl l0461
l0461:
 .long 0
 .byte -50,0
 .globl l0462
l0462:
 .long 0
 .byte -49,0
 .globl l0463
l0463:
 .long 0
 .byte -48,0
 .globl l0464
l0464:
 .long 0
 .byte -47,0
 .globl l0465
l0465:
 .long 0
 .byte -46,0
 .globl l0466
l0466:
 .long 0
 .byte -45,0
 .globl l0467
l0467:
 .long 0
 .byte -44,0
 .globl l0468
l0468:
 .long 0
 .byte -43,0
 .globl l0469
l0469:
 .long 0
 .byte -42,0
 .globl l0470
l0470:
 .long 0
 .byte -41,0
 .globl l0471
l0471:
 .long 0
 .byte -40,0
 .globl l0472
l0472:
 .long 0
 .byte -39,0
 .globl l0473
l0473:
 .long 0
 .byte -38,0
 .globl l0474
l0474:
 .long 0
 .byte -37,0
 .globl l0475
l0475:
 .long 0
 .byte -36,0
 .globl l0476
l0476:
 .long 0
 .byte -35,0
 .globl l0477
l0477:
 .long 0
 .byte -34,0
 .globl l0478
l0478:
 .long 0
 .byte -33,0
 .globl l0479
l0479:
 .long 0
 .byte -32,0
 .globl l0480
l0480:
 .long 0
 .byte -31,0
 .globl l0481
l0481:
 .long 0
 .byte -30,0
 .globl l0482
l0482:
 .long 0
 .byte -29,0
 .globl l0483
l0483:
 .long 0
 .byte -28,0
 .globl l0484
l0484:
 .long 0
 .byte -27,0
 .globl l0485
l0485:
 .long 0
 .byte -26,0
 .globl l0486
l0486:
 .long 0
 .byte -25,0
 .globl l0487
l0487:
 .long 0
 .byte -24,0
 .globl l0488
l0488:
 .long 0
 .byte -23,0
 .globl l0489
l0489:
 .long 0
 .byte -22,0
 .globl l0490
l0490:
 .long 0
 .byte -21,0
 .globl l0491
l0491:
 .long 0
 .byte -20,0
 .globl l0492
l0492:
 .long 0
 .byte -19,0
 .globl l0493
l0493:
 .long 0
 .byte -18,0
 .globl l0494
l0494:
 .long 0
 .byte -17,0
 .globl l0495
l0495:
 .long 0
 .byte -16,0
 .globl l0496
l0496:
 .long 0
 .byte -15,0
 .globl l0497
l0497:
 .long 0
 .byte -14,0
 .globl l0498
l0498:
 .long 0
 .byte -13,0
 .globl l0499
l0499:
 .long 0
 .byte -12,0
 .globl l0500
l0500:
 .long 0
 .byte -11,0
 .globl l0501
l0501:
 .long 0
 .byte -10,0
 .globl l0502
l0502:
 .long 0
 .byte -9,0
 .globl l0503
l0503:
 .long 0
 .byte -8,0
 .globl l0504
l0504:
 .long 0
 .byte -7,0
 .globl l0505
l0505:
 .long 0
 .byte -6,0
 .globl l0506
l0506:
 .long 0
 .byte -5,0
 .globl l0507
l0507:
 .long 0
 .byte -4,0
 .globl l0508
l0508:
 .long 0
 .byte -3,0
 .globl l0509
l0509:
 .long 0
 .byte -2,0
 .globl l0510
l0510:
 .long 0
 .byte -1,0
 .globl l0511
l0511:
 .long 10
 .byte 102,105,114,115,116,107,101,114,110
 .byte 101,108,0
 .globl l0512
l0512:
 .long 4
 .byte 115,116,97,99,107,0
 .globl l0513
l0513:
 .long 12
 .byte 97,114,103,117,109,101,110,116,98,108
 .byte 111,99,107,0
 .globl l0514
l0514:
 .long 10
 .byte 116,111,107,101,110,98,117,102,102
 .byte 101,114,0
 .globl l0515
l0515:
 .long 5
 .byte 98,110,100,115,116,107,0,0
 .globl l0516
l0516:
 .long 9
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 0,0
 .globl l0517
l0517:
 .long 8
 .byte 104,97,115,104,116,97,98,108,101,0
 .globl l0518
l0518:
 .long 12
 .byte 111,110,101,119,111,114,100,98,117
 .byte 102,102,101,114,0
 .globl l0519
l0519:
 .long 7
 .byte 115,97,118,101,97,114,103,99,0,0
 .globl l0520
l0520:
 .long 7
 .byte 115,97,118,101,97,114,103,118,0,0
 .globl l0521
l0521:
 .long 9
 .byte 100,97,116,101,98,117,102,102,101,114
 .byte 0,0
 .globl l0522
l0522:
 .long 15
 .byte 109,111,118,101,45,114,101,103,115
 .byte 45,116,111,45,109,101,109,0,0
 .globl l0523
l0523:
 .long 7
 .byte 104,101,97,112,108,97,115,116,0,0
 .globl l0524
l0524:
 .long 12
 .byte 104,101,97,112,116,114,97,112,98,111
 .byte 117,110,100,0
 .globl l0525
l0525:
 .long 8
 .byte 98,110,100,115,116,107,112,116,114
 .byte 0
 .globl l0526
l0526:
 .long 15
 .byte 98,110,100,115,116,107,108,111,119
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0527
l0527:
 .long 15
 .byte 98,110,100,115,116,107,117,112,112
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0528
l0528:
 .long 12
 .byte 105,110,105,116,45,112,111,105,110
 .byte 116,101,114,115,0
 .globl l0529
l0529:
 .long 12
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 112,116,114,0
 .globl l0530
l0530:
 .long 13
 .byte 104,101,97,112,108,111,119,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0531
l0531:
 .long 3
 .byte 104,101,97,112,0,0
 .globl l0532
l0532:
 .long 10
 .byte 105,110,105,116,45,102,108,117,105
 .byte 100,115,0
 .globl l0533
l0533:
 .long 16
 .byte 103,99,97,114,114,97,121,108,111,119
 .byte 101,114,98,111,117,110,100,0
 .globl l0534
l0534:
 .long 16
 .byte 103,99,97,114,114,97,121,117,112,112
 .byte 101,114,98,111,117,110,100,0
 .globl l0535
l0535:
 .long 10
 .byte 111,108,100,104,101,97,112,108,97,115
 .byte 116,0
 .globl l0536
l0536:
 .long 15
 .byte 111,108,100,104,101,97,112,116,114
 .byte 97,112,98,111,117,110,100,0,0
 .globl l0537
l0537:
 .long 13
 .byte 104,101,97,112,117,112,112,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0538
l0538:
 .long 13
 .byte 95,105,110,102,98,105,116,108,101,110
 .byte 103,116,104,95,0,0
 .globl l0539
l0539:
 .long 6
 .byte 108,97,115,116,98,112,115,0
 .globl l0540
l0540:
 .long 12
 .byte 98,112,115,108,111,119,101,114,98,111
 .byte 117,110,100,0
 .globl l0541
l0541:
 .long 18
 .byte 109,97,105,110,115,116,97,114,116,105
 .byte 110,105,116,105,97,108,105,122,101
 .byte 0
 .globl l0542
l0542:
 .long 6
 .byte 110,101,120,116,98,112,115,0
 .globl l0543
l0543:
 .long 16
 .byte 111,108,100,104,101,97,112,117,112
 .byte 112,101,114,98,111,117,110,100,0
 .globl l0544
l0544:
 .long 16
 .byte 111,108,100,104,101,97,112,108,111
 .byte 119,101,114,98,111,117,110,100,0
 .globl l0545
l0545:
 .long 14
 .byte 115,116,97,99,107,117,112,112,101,114
 .byte 98,111,117,110,100,0
 .globl l0546
l0546:
 .long 8
 .byte 117,110,105,120,115,116,100,105,110
 .byte 0
 .globl l0547
l0547:
 .long 9
 .byte 117,110,105,120,115,116,100,111,117
 .byte 116,0,0
 .globl l0548
l0548:
 .long 9
 .byte 117,110,105,120,115,116,100,101,114
 .byte 114,0,0
 .globl l0549
l0549:
 .long 7
 .byte 117,110,105,120,110,117,108,108,0,0
 .globl l0550
l0550:
 .long 6
 .byte 117,110,105,120,101,111,102,0
 .globl l0551
l0551:
 .long 6
 .byte 117,110,105,120,116,116,121,0
 .globl l0552
l0552:
 .long 16
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,42,42,42,0
 .globl l0553
l0553:
 .long 20
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,45,116,111,111,42,42
 .byte 42,0
 .globl l0554
l0554:
 .long 7
 .byte 42,102,97,115,116,99,97,114,0,0
 .globl l0555
l0555:
 .long 3
 .byte 109,97,105,110,0,0
 .globl l0556
l0556:
 .long 14
 .byte 111,115,95,115,116,97,114,116,117,112
 .byte 95,104,111,111,107,0
 .globl l0557
l0557:
 .long 3
 .byte 97,114,103,99,0,0
 .globl l0558
l0558:
 .long 3
 .byte 97,114,103,118,0,0
 .globl l0559
l0559:
 .long 7
 .byte 101,98,120,115,97,118,101,42,0,0
 .globl l0560
l0560:
 .long 14
 .byte 115,116,97,99,107,108,111,119,101,114
 .byte 98,111,117,110,100,0
 .globl l0561
l0561:
 .long 7
 .byte 112,114,101,45,109,97,105,110,0,0
 .globl l0562
l0562:
 .long 15
 .byte 101,120,105,116,45,119,105,116,104
 .byte 45,115,116,97,116,117,115,0,0
 .globl l0563
l0563:
 .long 14
 .byte 111,115,95,99,108,101,97,110,117,112
 .byte 95,104,111,111,107,0
 .globl l0564
l0564:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,101
 .byte 120,105,116,0
 .globl l0565
l0565:
 .long 11
 .byte 105,110,105,116,45,103,99,97,114,114
 .byte 97,121,0,0
 .globl l0566
l0566:
 .long 10
 .byte 117,110,105,120,99,108,101,97,114,105
 .byte 111,0
 .globl l0567
l0567:
 .long 22
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,115,121,109,98,111,108,45,116
 .byte 97,98,108,101,0
 .globl l0568
l0568:
 .long 7
 .byte 105,110,105,116,99,111,100,101,0,0
 .globl l0569
l0569:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,115,116,114,105,110
 .byte 103,0,0
 .globl l0570
l0570:
 .long 14
 .byte 99,111,110,115,111,108,101,45,110,101
 .byte 119,108,105,110,101,0
 .globl l0571
l0571:
 .long 5
 .byte 102,97,115,108,105,110,0,0
 .globl l0572
l0572:
 .long 10
 .byte 108,111,97,100,101,114,45,109,97,105
 .byte 110,0
 .globl l0573
l0573:
 .long 7
 .byte 117,110,105,120,112,117,116,115,0,0
 .globl l0574
l0574:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,110,117,109,98,101,114
 .byte 0,0
 .globl l0575
l0575:
 .long 7
 .byte 117,110,105,120,112,117,116,110,0,0
 .globl l0576
l0576:
 .long 7
 .byte 117,110,105,120,112,117,116,99,0,0
 .globl l0577
l0577:
 .long 13
 .byte 98,105,110,97,114,121,111,112,101,110
 .byte 114,101,97,100,0,0
 .globl l0578
l0578:
 .long 7
 .byte 117,110,105,120,111,112,101,110,0,0
 .globl l0579
l0579:
 .long 17
 .byte 107,101,114,110,101,108,45,102,97,116
 .byte 97,108,45,101,114,114,111,114,0,0
 .globl l0580
l0580:
 .long 4
 .byte 120,103,101,116,119,0
 .globl l0581
l0581:
 .long 9
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 0,0
 .globl l0582
l0582:
 .long 14
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 98,108,111,99,107,0
 .globl l0583
l0583:
 .long 4
 .byte 102,114,101,97,100,0
 .globl l0584
l0584:
 .long 10
 .byte 98,105,110,97,114,121,99,108,111,115
 .byte 101,0
 .globl l0585
l0585:
 .long 5
 .byte 102,99,108,111,115,101,0,0
 .globl l0586
l0586:
 .long 14
 .byte 104,97,115,104,45,105,110,116,111,45
 .byte 116,97,98,108,101,0
 .globl l0587
l0587:
 .long 12
 .byte 102,97,115,108,105,110,45,105,110,116
 .byte 101,114,110,0
 .globl l0588
l0588:
 .long 26
 .byte 115,101,97,114,99,104,45,115,116,114
 .byte 105,110,103,45,102,111,114,45,99,104
 .byte 97,114,97,99,116,101,114,0
 .globl l0589
l0589:
 .long 5
 .byte 105,110,116,101,114,110,0,0
 .globl l0590
l0590:
 .long 5
 .byte 115,117,98,115,101,113,0,0
 .globl l0591
l0591:
 .long 22
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,105,110
 .byte 116,101,114,110,0
 .globl l0592
l0592:
 .long 3
 .byte 103,116,105,100,0,0
 .globl l0593
l0593:
 .long 9
 .byte 103,116,99,111,110,115,116,115,116
 .byte 114,0,0
 .globl l0594
l0594:
 .long 15
 .byte 99,111,112,121,115,116,114,105,110
 .byte 103,116,111,102,114,111,109,0,0
 .globl l0595
l0595:
 .long 16
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,110,101,119,45,105,100,0
 .globl l0596
l0596:
 .long 12
 .byte 104,97,115,104,45,102,117,110,99,116
 .byte 105,111,110,0
 .globl l0597
l0597:
 .long 21
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,101,113
 .byte 117,97,108,0,0
 .globl l0598
l0598:
 .long 11
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,0,0
 .globl l0599
l0599:
 .long 14
 .byte 102,97,115,108,105,110,45,98,97,100
 .byte 45,102,105,108,101,0
 .globl l0600
l0600:
 .long 12
 .byte 114,101,97,100,45,105,100,45,116,97
 .byte 98,108,101,0
 .globl l0601
l0601:
 .long 4
 .byte 103,116,98,112,115,0
 .globl l0602
l0602:
 .long 5
 .byte 103,116,119,114,100,115,0,0
 .globl l0603
l0603:
 .long 16
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,45,110,101,119,0
 .globl l0604
l0604:
 .long 12
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,0
 .globl l0605
l0605:
 .long 12
 .byte 97,100,100,114,101,115,115,97,112,112
 .byte 108,121,48,0
 .globl l0606
l0606:
 .long 5
 .byte 100,101,108,98,112,115,0,0
 .globl l0607
l0607:
 .long 7
 .byte 98,105,116,116,97,98,108,101,0,0
 .globl l0608
l0608:
 .long 12
 .byte 114,101,108,111,99,97,116,101,45,119
 .byte 111,114,100,0
 .globl l0609
l0609:
 .long 11
 .byte 114,101,108,111,99,97,116,101,45,105
 .byte 110,102,0,0
 .globl l0610
l0610:
 .long 18
 .byte 114,101,108,111,99,97,116,101,45,114
 .byte 105,103,104,116,45,104,97,108,102,0
 .globl l0611
l0611:
 .long 17
 .byte 99,111,109,112,117,116,101,45,114,101
 .byte 108,111,99,97,116,105,111,110,0,0
 .globl l0612
l0612:
 .long 17
 .byte 108,111,99,97,108,45,116,111,45,103
 .byte 108,111,98,97,108,45,105,100,0,0
 .globl l0613
l0613:
 .long 3
 .byte 112,117,116,100,0,0
 .globl l0614
l0614:
 .long 7
 .byte 112,117,116,101,110,116,114,121,0,0
 .globl l0615
l0615:
 .long 19
 .byte 116,114,121,45,111,116,104,101,114
 .byte 45,98,112,115,45,115,112,97,99,101
 .byte 115,0,0
 .globl l0616
l0616:
 .long 14
 .byte 103,116,98,112,115,45,110,105,108,45
 .byte 101,114,114,111,114,0
 .globl l0617
l0617:
 .long 3
 .byte 103,101,116,100,0,0
 .globl l0618
l0618:
 .long 7
 .byte 115,116,100,101,114,114,111,114,0,0
 .globl l0619
l0619:
 .long 5
 .byte 103,116,104,101,97,112,0,0
 .globl l0620
l0620:
 .long 15
 .byte 107,110,111,119,110,45,102,114,101
 .byte 101,45,115,112,97,99,101,0,0
 .globl l0621
l0621:
 .long 10
 .byte 114,101,97,108,45,103,116,104,101,97
 .byte 112,0
 .globl l0622
l0622:
 .long 12
 .byte 103,101,116,45,104,101,97,112,45,116
 .byte 114,97,112,0
 .globl l0623
l0623:
 .long 6
 .byte 114,101,99,108,97,105,109,0
 .globl l0624
l0624:
 .long 4
 .byte 103,116,115,116,114,0
 .globl l0625
l0625:
 .long 3
 .byte 99,111,110,115,0,0
 .globl l0626
l0626:
 .long 10
 .byte 105,110,116,101,114,114,111,103,97
 .byte 116,101,0
 .globl l0627
l0627:
 .long 5
 .byte 109,111,100,105,102,121,0,0
 .globl l0628
l0628:
 .long 2
 .byte 112,117,116,0
 .globl l0629
l0629:
 .long 12
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,117,116,0
 .globl l0630
l0630:
 .long 13
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,114,111,112,0,0
 .globl l0631
l0631:
 .long 4
 .byte 97,116,115,111,99,0
 .globl l0632
l0632:
 .long 16
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,101,116,112,114,111,112,0
 .globl l0633
l0633:
 .long 8
 .byte 99,111,100,101,45,112,117,116,100,0
 .globl l0634
l0634:
 .long 3
 .byte 101,120,112,114,0,0
 .globl l0635
l0635:
 .long 3
 .byte 116,121,112,101,0,0
 .globl l0636
l0636:
 .long 15
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,0,0
 .globl l0637
l0637:
 .long 4
 .byte 102,108,117,105,100,0
 .globl l0638
l0638:
 .long 5
 .byte 102,108,117,105,100,49,0,0
 .globl l0639
l0639:
 .long 6
 .byte 118,97,114,116,121,112,101,0
 .globl l0640
l0640:
 .long 8
 .byte 99,111,110,115,116,97,110,116,63,0
 .globl l0641
l0641:
 .long 15
 .byte 42,100,101,102,105,110,101,45,99,111
 .byte 110,115,116,97,110,116,0,0
 .globl l0642
l0642:
 .long 14
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,0
 .globl l0643
l0643:
 .long 16
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,0
 .globl l0644
l0644:
 .long 20
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,45,97
 .byte 117,120,0
 .globl l0645
l0645:
 .long 25
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,0,0
 .globl l0646
l0646:
 .long 28
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,97,117
 .byte 120,0
 .globl l0647
l0647:
 .long 15
 .byte 112,115,108,115,105,103,110,97,108
 .byte 104,97,110,100,108,101,114,0,0
 .globl l0648
l0648:
 .long 5
 .byte 101,99,104,111,111,110,0,0
 .globl l0649
l0649:
 .long 6
 .byte 101,99,104,111,111,102,102,0
 .globl l0650
l0650:
 .long 26
 .byte 101,120,116,101,114,110,97,108,95,99
 .byte 104,97,114,115,105,110,105,110,112
 .byte 117,116,98,117,102,102,101,114,0
 .globl l0651
l0651:
 .long 19
 .byte 102,108,117,115,104,115,116,100,111
 .byte 117,116,112,117,116,98,117,102,102
 .byte 101,114,0,0
 .globl l0652
l0652:
 .long 27
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 115,101,114,95,104,111,109,101,100
 .byte 105,114,95,115,116,114,105,110,103
 .byte 0,0
 .globl l0653
l0653:
 .long 30
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 110,121,117,115,101,114,95,104,111
 .byte 109,101,100,105,114,95,115,116,114
 .byte 105,110,103,0
 .globl l0654
l0654:
 .long 12
 .byte 97,108,116,101,114,104,101,97,112,115
 .byte 105,122,101,0
 .globl l0655
l0655:
 .long 14
 .byte 97,108,108,111,99,97,116,101,109,111
 .byte 114,101,98,112,115,0
 .globl l0656
l0656:
 .long 14
 .byte 103,101,116,95,102,105,108,101,95,115
 .byte 116,97,116,117,115,0
 .globl l0657
l0657:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 108,97,114,109,0,0
 .globl l0658
l0658:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 97,108,97,114,109,0
 .globl l0659
l0659:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,101,0
 .globl l0660
l0660:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,99,0
 .globl l0661
l0661:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,97,116,0
 .globl l0662
l0662:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,108
 .byte 105,110,107,0
 .globl l0663
l0663:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 110,108,105,110,107,0
 .globl l0664
l0664:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,114,108,101,110,0
 .globl l0665
l0665:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 101,116,101,110,118,0
 .globl l0666
l0666:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,103
 .byte 101,116,101,110,118,0
 .globl l0667
l0667:
 .long 6
 .byte 117,120,102,108,111,97,116,0
 .globl l0668
l0668:
 .long 4
 .byte 117,120,102,105,120,0
 .globl l0669
l0669:
 .long 7
 .byte 117,120,97,115,115,105,103,110,0,0
 .globl l0670
l0670:
 .long 6
 .byte 117,120,112,108,117,115,50,0
 .globl l0671
l0671:
 .long 11
 .byte 117,120,100,105,102,102,101,114,101
 .byte 110,99,101,0,0
 .globl l0672
l0672:
 .long 7
 .byte 117,120,116,105,109,101,115,50,0,0
 .globl l0673
l0673:
 .long 9
 .byte 117,120,113,117,111,116,105,101,110
 .byte 116,0,0
 .globl l0674
l0674:
 .long 9
 .byte 117,120,103,114,101,97,116,101,114
 .byte 112,0,0
 .globl l0675
l0675:
 .long 6
 .byte 117,120,108,101,115,115,112,0
 .globl l0676
l0676:
 .long 11
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,0,0
 .globl l0677
l0677:
 .long 12
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,56,0
 .globl l0678
l0678:
 .long 14
 .byte 117,120,100,111,117,98,108,101,116
 .byte 111,102,108,111,97,116,0
 .globl l0679
l0679:
 .long 14
 .byte 117,120,102,108,111,97,116,116,111
 .byte 100,111,117,98,108,101,0
 .globl l0680
l0680:
 .long 4
 .byte 117,120,115,105,110,0
 .globl l0681
l0681:
 .long 4
 .byte 117,120,99,111,115,0
 .globl l0682
l0682:
 .long 4
 .byte 117,120,116,97,110,0
 .globl l0683
l0683:
 .long 5
 .byte 117,120,97,115,105,110,0,0
 .globl l0684
l0684:
 .long 5
 .byte 117,120,97,99,111,115,0,0
 .globl l0685
l0685:
 .long 5
 .byte 117,120,97,116,97,110,0,0
 .globl l0686
l0686:
 .long 5
 .byte 117,120,115,113,114,116,0,0
 .globl l0687
l0687:
 .long 4
 .byte 117,120,101,120,112,0
 .globl l0688
l0688:
 .long 4
 .byte 117,120,108,111,103,0
 .globl l0689
l0689:
 .long 6
 .byte 117,120,97,116,97,110,50,0
 .globl l0690
l0690:
 .long 11
 .byte 101,120,116,101,114,110,97,108,95,112
 .byte 119,100,0,0
 .globl l0691
l0691:
 .long 10
 .byte 115,117,110,51,95,115,105,103,115,101
 .byte 116,0
 .globl l0692
l0692:
 .long 7
 .byte 115,105,103,114,101,108,115,101,0,0
 .globl l0693
l0693:
 .long 5
 .byte 117,110,101,120,101,99,0,0
 .globl l0694
l0694:
 .long 15
 .byte 101,120,112,97,110,100,95,102,105,108
 .byte 101,95,110,97,109,101,0,0
 .globl l0695
l0695:
 .long 5
 .byte 117,110,105,120,99,100,0,0
 .globl l0696
l0696:
 .long 4
 .byte 99,116,105,109,101,0
 .globl l0697
l0697:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 121,115,116,101,109,0
 .globl l0698
l0698:
 .long 4
 .byte 102,111,112,101,110,0
 .globl l0699
l0699:
 .long 4
 .byte 102,112,117,116,99,0
 .globl l0700
l0700:
 .long 4
 .byte 102,103,101,116,99,0
 .globl l0701
l0701:
 .long 4
 .byte 102,103,101,116,115,0
 .globl l0702
l0702:
 .long 5
 .byte 102,119,114,105,116,101,0,0
 .globl l0703
l0703:
 .long 5
 .byte 102,102,108,117,115,104,0,0
 .globl l0704
l0704:
 .long 4
 .byte 102,115,101,101,107,0
 .globl l0705
l0705:
 .long 7
 .byte 99,108,101,97,114,101,114,114,0,0
 .globl l0706
l0706:
 .long 3
 .byte 112,117,116,119,0,0
 .globl l0707
l0707:
 .long 5
 .byte 115,105,103,110,97,108,0,0
 .globl l0708
l0708:
 .long 4
 .byte 115,108,101,101,112,0
 .globl l0709
l0709:
 .long 11
 .byte 105,101,101,101,95,104,97,110,100,108
 .byte 101,114,0,0
 .globl l0710
l0710:
 .long 9
 .byte 105,101,101,101,95,102,108,97,103,115
 .byte 0,0
 .globl l0711
l0711:
 .long 9
 .byte 115,101,116,108,105,110,101,98,117
 .byte 102,0,0
 .globl l0712
l0712:
 .long 5
 .byte 103,101,116,112,105,100,0,0
 .globl l0713
l0713:
 .long 8
 .byte 103,101,116,104,111,115,116,105,100
 .byte 0
 .globl l0714
l0714:
 .long 13
 .byte 117,110,105,120,115,111,99,107,101
 .byte 116,111,112,101,110,0,0
 .globl l0715
l0715:
 .long 8
 .byte 103,101,116,115,111,99,107,101,116
 .byte 0
 .globl l0716
l0716:
 .long 10
 .byte 119,114,105,116,101,115,111,99,107
 .byte 101,116,0
 .globl l0717
l0717:
 .long 14
 .byte 117,110,105,120,99,108,111,115,101
 .byte 115,111,99,107,101,116,0
 .globl l0718
l0718:
 .long 3
 .byte 102,111,114,107,0,0
 .globl l0719
l0719:
 .long 3
 .byte 119,97,105,116,0,0
 .globl l0720
l0720:
 .long 4
 .byte 112,111,112,101,110,0
 .globl l0721
l0721:
 .long 5
 .byte 112,99,108,111,115,101,0,0
 .globl l0722
l0722:
 .long 5
 .byte 115,104,109,99,116,108,0,0
 .globl l0723
l0723:
 .long 5
 .byte 115,104,109,103,101,116,0,0
 .globl l0724
l0724:
 .long 4
 .byte 115,104,109,97,116,0
 .globl l0725
l0725:
 .long 4
 .byte 115,104,109,100,116,0
 .globl l0726
l0726:
 .long 5
 .byte 115,101,109,99,116,108,0,0
 .globl l0727
l0727:
 .long 5
 .byte 115,101,109,103,101,116,0,0
 .globl l0728
l0728:
 .long 4
 .byte 115,101,109,111,112,0
 .globl l0729
l0729:
 .long 11
 .byte 117,110,105,120,45,112,114,111,102
 .byte 105,108,101,0,0
 .globl l0730
l0730:
 .long 9
 .byte 108,97,115,116,107,101,114,110,101
 .byte 108,0,0
 .globl l0731
l0731:
 .long 11
 .byte 99,111,100,101,97,100,100,114,101,115
 .byte 115,112,0,0
 .globl l0732
l0732:
 .long 14
 .byte 103,101,116,102,99,111,100,101,112
 .byte 111,105,110,116,101,114,0
 .globl symfnc
 .globl symget
