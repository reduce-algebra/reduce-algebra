        .text
 .long 1
/ (*entry firstkernel expr 1)
 .globl firstkernel
firstkernel:
 ret
 .long 0
/ (*entry init-pointers expr 0)
 .globl l0001
l0001:
 movl $0,symval+1068
 movl $0,symval+1072
 movl $0,symval+1076
 movl $0,symval+1080
 movl $-20000,%eax
 add symval+1084,%eax
 mov %eax,symval+1088
 mov symval+1040,%edi
 mov %edi,symval+1092
 mov symval+1036,%edi
 mov %edi,symval+1096
 movl $7996,%ebx
 add symval+1036,%ebx
 mov %ebx,symval+1100
 mov symval+1036,%edi
 mov %edi,symval+1104
 mov symval+1108,%eax
 mov %eax,symval+1112
 ret
 .long 0
/ (*entry init-fluids expr 0)
 .globl l0002
l0002:
 movl $((30*0x8000000)+128),%eax
 mov %eax,symval+1120
 mov %eax,symval+1124
 mov %eax,symval+1128
 mov %eax,symval+1132
 mov %eax,symval+1136
 mov %eax,symval+1140
 mov %eax,symval+1144
 mov %eax,symval+1148
 mov %eax,symval+1152
 mov %eax,symval+1156
 mov %eax,symval+1160
 mov %eax,symval+1164
 mov %eax,symval+1168
 mov %eax,symval+1172
 mov %eax,symval+1088
 mov %eax,symval+1176
 mov %eax,symval+1180
 mov %eax,symval+1184
 mov %eax,symval+1188
 mov %eax,symval+1192
 mov %eax,symval+1196
 mov %eax,symval+1200
 mov %eax,symval+1204
 mov %eax,symval+1208
 mov %eax,symval+1212
 ret
 .long 0
/ (*entry &&init-tables1 expr 0)
 .globl l0003
l0003:
 movl $0,symval+1220
 mov symval+1224,%edi
 mov %edi,symval+1228
 mov symval+1232,%edi
 mov %edi,symval+1236
 mov symval+1240,%edi
 mov %edi,symval+1244
 mov symval+1248,%edi
 mov %edi,symval+1252
 mov symval+1256,%edi
 mov %edi,symval+1260
 mov symval+1264,%edi
 mov %edi,symval+1232
 movl $240000,%eax
 add symval+1232,%eax
 mov %eax,symval+1240
 add $240000,%eax
 mov %eax,symval+1248
 ret
 .long 0
/ (*entry &&init-tables2 expr 0)
 .globl l0004
l0004:
 mov %eax,-36(%esp)
 sub $8,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,4(%esp)
 mov %edi,(%esp)
 movl $((30*0x8000000)+128),%edi
 cmp symval+1168,%edi
 je l0005
 mov symval+1136,%edi
 mov %edi,(%esp)
 mov symval+1132,%edi
 mov %edi,4(%esp)
 mov symval+1244,%ebx
 mov symval+1240,%eax
 movl $317,%edi
 call *symfnc+1268
 mov symval+1236,%ebx
 mov symval+1232,%eax
 movl $317,%edi
 call *symfnc+1268
 mov 4(%esp),%edi
 mov %edi,symval+1132
 mov (%esp),%edi
 mov %edi,symval+1136
 movl $318,%edi
 call *symfnc+1272
 movl $((30*0x8000000)+128),%eax
 jmp l0006
l0005:
 mov symval+1240,%ebx
 mov symval+1244,%eax
 movl $317,%edi
 call *symfnc+1268
 mov symval+1232,%ebx
 mov symval+1236,%eax
 movl $317,%edi
 call *symfnc+1268
 mov symval+1248,%ebx
 mov symval+1252,%eax
 add $8,%esp
 movl $317,%edi
 jmp *symfnc+1268
l0006:
 add $8,%esp
 ret
 .long 2
/ (*entry &&symcopy expr 2)
 .globl l0007
l0007:
 mov %eax,-32(%esp)
 push %eax
 mov %ebx,%ebp
 mov symval+1228,%ebx
 xor %eax,%eax
 mov %eax,%edx
 mov %ebx,%ecx
l0008:
 cmp %ecx,%edx
 jle l0009
 movl $((30*0x8000000)+128),%eax
 jmp l0010
l0009:
 mov %edx,%eax
 shl $2,%eax
 add %ebp,%eax
 mov %edx,%ebx
 shl $2,%ebx
 add (%esp),%ebx
 mov (%ebx),%edi
 mov %edi,(%eax)
 incl %edx
 jmp l0008
l0010:
 add $4,%esp
 ret
 .long 0
/ (*entry _psl_main expr 0)
 .globl _psl_main
_psl_main:
 push %ebp
 mov 16(%esp),%edi
 mov %edi,symval+1264
 mov 8(%esp),%eax
 mov 12(%esp),%ebx
 mov %esp,symval+1304
 mov %eax,symval+1308
 mov %ebx,symval+1312
 push %eax
 push %ebx
 movl $27,symval+1140
 movl $((30*0x8000000)+128),symval+1168
 movl $304,%edi
 call *symfnc+1216
 pop %ebx
 pop %eax
 movl $320,%edi
 call *symfnc+1280
 movl $319,%edi
 call *symfnc+1276
 movl $266,%edi
 call *symfnc+1064
 xor %eax,%eax
 dec %eax
 movl $321,%edi
 call *symfnc+1284
 mov 8(%esp),%eax
 mov 12(%esp),%ebx
 mov %eax,symval+1308
 mov %ebx,symval+1312
 movl $322,%edi
 call *symfnc+1288
l0011:
 xor %eax,%eax
 movl $323,%edi
 jmp *symfnc+1292
 pop %ebp
 ret
/ (*entry exit-with-status expr 1)
 .globl l0012
l0012:
 movl $324,%edi
 call *symfnc+1296
 ret
 .long 4
/ (*entry _psl_call expr 4)
 .globl _psl_call
_psl_call:
 push %ebp
 mov 8(%esp),%eax
 mov 12(%esp),%ebx
 mov 16(%esp),%ecx
 mov 20(%esp),%edx
 movl $329,%edi
 call *symfnc+1316
 pop %ebp
 ret
 .long 4
/ (*entry psl_call1 expr 4)
 .globl l0013
l0013:
 movl $((30*0x8000000)+128),%eax
 ret
 .long 1
/ (*entry &time-control expr 1)
 .globl l0014
l0014:
 movl $((30*0x8000000)+128),%eax
 ret
l0015:
 .long 6
 .byte 66,80,83,58,32,32,32,0
l0016:
 .long 0
 .byte 45,0
l0017:
 .long 6
 .byte 72,69,65,80,58,32,32,0
l0018:
 .long 6
 .byte 83,84,65,67,75,58,32,0
l0019:
 .long 7
 .byte 83,89,77,86,65,76,58,32,0,0
l0020:
 .long 8
 .byte 32,83,89,77,70,78,67,58,32,0
l0021:
 .long 8
 .byte 32,83,89,77,80,82,80,58,32,0
l0022:
 .long 8
 .byte 32,83,89,77,78,65,77,58,32,0
l0023:
 .long 8
 .byte 32,83,89,77,71,69,84,58,32,0
l0024:
 .long 21
 .byte 65,98,111,117,116,32,116,111,32,108
 .byte 111,97,100,32,76,79,65,68,45,80,83
 .byte 76,0,0
l0025:
 .long 9
 .byte 108,111,97,100,45,112,115,108,46,98
 .byte 0,0
 .long 0
/ (*entry pre-main expr 0)
 .globl l0026
l0026:
 movl $331,%edi
 call *symfnc+1324
 movl $((4*0x8000000)+l0015),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1172,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0016),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1144,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $334,%edi
 call *symfnc+1336
 movl $((4*0x8000000)+l0017),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1128,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0016),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1136,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $334,%edi
 call *symfnc+1336
 movl $((4*0x8000000)+l0018),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1304,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0016),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1088,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $334,%edi
 call *symfnc+1336
 movl $((4*0x8000000)+l0019),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1232,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0020),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1240,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0021),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1248,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0022),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1356,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $((4*0x8000000)+l0023),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1256,%eax
 movl $333,%edi
 call *symfnc+1332
 movl $334,%edi
 call *symfnc+1336
 movl $335,%edi
 call *symfnc+1340
 movl $336,%edi
 call *symfnc+1344
 movl $((4*0x8000000)+l0024),%eax
 movl $332,%edi
 call *symfnc+1328
 movl $334,%edi
 call *symfnc+1336
 movl $((4*0x8000000)+l0025),%eax
 movl $337,%edi
 call *symfnc+1348
 movl $338,%edi
 jmp *symfnc+1352
 .long 1
/ (*entry external_strlen expr 1)
 .globl external_strlen
external_strlen:
 mov %eax,-32(%esp)
 push $0
 push %eax
l0027:
 mov 4(%esp),%ebx
 mov (%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 cmpl $0,%eax
 jne l0028
 mov 4(%esp),%eax
 jmp l0029
l0028:
 incl 4(%esp)
 jmp l0027
l0029:
 add $8,%esp
 ret
 .long 0
/ (*entry ! yield expr 0)
 .globl l0030
l0030:
 movl $((30*0x8000000)+128),%eax
 ret
 .long 1
/ (*entry console-print-string expr 1)
 .globl l0031
l0031:
 and $134217727,%eax
 add $4,%eax
 movl $342,%edi
 jmp *symfnc+1368
 .long 1
/ (*entry console-print-number expr 1)
 .globl l0032
l0032:
 movl $333,%edi
 jmp *symfnc+1332
 .long 0
/ (*entry console-newline expr 0)
 .globl l0033
l0033:
 movl $10,%eax
 movl $344,%edi
 jmp *symfnc+1376
l0034:
 .long 1
 .byte 114,98,0,0
l0035:
 .long 34
 .byte 67,111,117,108,100,110,39,116,32,111
 .byte 112,101,110,32,98,105,110,97,114,121
 .byte 32,102,105,108,101,32,102,111,114,32
 .byte 105,110,112,117,116,0
 .long 1
/ (*entry binaryopenread expr 1)
 .globl binaryopenread
binaryopenread:
 movl $((4*0x8000000)+l0034),%ebx
 and $134217727,%ebx
 add $4,%ebx
 and $134217727,%eax
 add $4,%eax
 movl $345,%edi
 call *symfnc+1380
 cmpl $0,%eax
 jne l0036
 movl $((4*0x8000000)+l0035),%eax
 movl $346,%edi
 jmp *symfnc+1384
l0036:
 ret
 .long 1
/ (*entry binaryread expr 1)
 .globl binaryread
binaryread:
 movl $348,%edi
 jmp *symfnc+1392
 .long 3
/ (*entry binaryreadblock expr 3)
 .globl binaryreadblock
binaryreadblock:
 mov %ebx,%ebp
 mov %eax,%edx
 movl $4,%ebx
 mov %ebp,%eax
 movl $350,%edi
 jmp *symfnc+1400
 .long 1
/ (*entry binaryclose expr 1)
 .globl binaryclose
binaryclose:
 movl $352,%edi
 jmp *symfnc+1408
 .long 0
/ (*entry initialize-symbol-table expr 0)
 .globl l0037
l0037:
 mov %eax,-36(%esp)
 sub $8,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,4(%esp)
 mov %edi,(%esp)
 movl $60000,%ebx
 mov symval+1224,%eax
 mov %eax,%edx
 mov %ebx,%ecx
l0038:
 cmp %ecx,%edx
 jg l0039
 mov %edx,%eax
 shl $2,%eax
 add symval+1356,%eax
 xor %ebx,%ebx
 incl %ebx
 add %edx,%ebx
 mov %ebx,(%eax)
 incl %edx
 jmp l0038
l0039:
 mov symval+1356,%esi
 movl $0,240000(%esi)
 movl $68023,%ebx
 xor %eax,%eax
 mov %eax,(%esp)
 mov %ebx,4(%esp)
l0040:
 mov (%esp),%edi
 cmp 4(%esp),%edi
 jg l0041
 xor %ecx,%ecx
 mov (%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 
 mov %cx,0(%ebx,%eax,1)
 incl (%esp)
 jmp l0040
l0041:
 mov symval+1356,%edi
 mov 512(%edi),%eax
 movl $354,%edi
 call *symfnc+1416
 movl $128,%ecx
 mov %eax,%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 
 mov %cx,0(%ebx,%eax,1)
 xor %ebx,%ebx
 dec %ebx
 add symval+1224,%ebx
 movl $256,%eax
 mov %eax,(%esp)
 mov %ebx,4(%esp)
l0042:
 mov (%esp),%edi
 cmp 4(%esp),%edi
 jg l0043
 mov (%esp),%eax
 shl $2,%eax
 add symval+1356,%eax
 mov (%eax),%eax
 movl $354,%edi
 call *symfnc+1416
 mov (%esp),%ecx
 mov %eax,%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 
 mov %cx,0(%ebx,%eax,1)
 incl (%esp)
 jmp l0042
l0043:
 movl $((30*0x8000000)+128),%eax
 mov %eax,symval+1420
 add $8,%esp
 ret
 .long 1
/ (*entry faslin-intern expr 1)
 .globl l0044
l0044:
 mov %eax,-40(%esp)
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,8(%esp)
 mov %edi,4(%esp)
 mov %eax,(%esp)
 mov %eax,%ebx
 xor %eax,%eax
 movl $356,%edi
 call *symfnc+1424
 mov %eax,4(%esp)
 cmpl $((30*0x8000000)+128),%eax
 jne l0045
 mov (%esp),%eax
 add $12,%esp
 movl $357,%edi
 jmp *symfnc+1428
l0045:
 mov (%esp),%eax
 and $134217727,%eax
 mov (%eax),%eax
 shl $5,%eax
 sar $5,%eax
 mov %eax,8(%esp)
 cmp 4(%esp),%eax
 jle l0046
 xor %ebx,%ebx
 incl %ebx
 add 4(%esp),%ebx
 mov (%esp),%eax
 and $134217727,%eax
 add $4,%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 cmpl $0,%eax
 jne l0046
 incl 4(%esp)
l0046:
 mov 4(%esp),%edi
 cmp 8(%esp),%edi
 jl l0047
 mov (%esp),%eax
 jmp l0048
l0047:
 mov (%esp),%ecx
 and $134217727,%ecx
 mov (%ecx),%ecx
 shl $5,%ecx
 sar $5,%ecx
 incl %ecx
 xor %ebx,%ebx
 incl %ebx
 add 4(%esp),%ebx
 mov (%esp),%eax
 movl $358,%edi
 call *symfnc+1432
l0048:
 add $12,%esp
 movl $357,%edi
 jmp *symfnc+1428
 .long 1
/ (*entry intern expr 1)
 .globl intern
intern:
 movl $360,%edi
 jmp *symfnc+1440
l0049:
 .long 7
 .byte 78,101,119,32,105,100,58,32,0,0
 .long 1
/ (*entry unchecked-string-intern expr 1)
 .globl l0050
l0050:
 mov %eax,-52(%esp)
 sub $24,%esp
 mov %eax,(%esp)
 movl $((30*0x8000000)+128),%ebp
 mov %ebp,%edx
 mov %ebp,%ecx
 mov %eax,%ebx
 and $134217727,%ebx
 mov (%ebx),%ebx
 shl $5,%ebx
 sar $5,%ebx
 and $134217727,%eax
 mov %eax,4(%esp)
 mov %ebx,8(%esp)
 mov %ecx,12(%esp)
 mov %edx,16(%esp)
 mov %ebp,20(%esp)
 cmpl $0,%ebx
 jne l0051
 add $4,%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 and $255,%eax
 and $134217727,%eax
 or $-268435456,%eax
 jmp l0052
l0051:
 mov (%esp),%eax
 movl $354,%edi
 call *symfnc+1416
 mov %eax,%ebx
 mov %ebx,12(%esp)
 mov symval+1044,%eax
 shl $1,%ebx
 mov 0(%eax,%ebx,1),%ax
 cwde
 and $65535,%eax
 mov %eax,%ebx
 cmpl $65535,%eax
 jl l0053
 movl $((30*0x8000000)+128),%eax
 jmp l0054
l0053:
 movl $((30*0x8000000)+116),%eax
l0054:
 cmpl $((30*0x8000000)+128),%eax
 je l0055
 movl $((30*0x8000000)+116),%eax
 cmpl $0,%ebx
 jg l0055
 add $12,%eax
l0055:
 cmpl $((30*0x8000000)+128),%eax
 je l0056
 mov 12(%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 mov 0(%eax,%ebx,1),%ax
 cwde
 and $65535,%eax
 and $134217727,%eax
 or $-268435456,%eax
 jmp l0052
l0056:
 cmp symval+1420,%eax
 je l0057
 movl $((4*0x8000000)+l0049),%eax
 movl $332,%edi
 call *symfnc+1328
 mov (%esp),%eax
 movl $332,%edi
 call *symfnc+1328
 movl $334,%edi
 call *symfnc+1336
l0057:
 movl $361,%edi
 call *symfnc+1444
 mov %eax,20(%esp)
 mov %eax,%ecx
 mov 12(%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 
 mov %cx,0(%ebx,%eax,1)
 mov 8(%esp),%eax
 movl $362,%edi
 call *symfnc+1448
 mov %eax,16(%esp)
 mov 4(%esp),%ebx
 movl $363,%edi
 call *symfnc+1452
 mov 16(%esp),%ebx
 and $134217727,%ebx
 or $536870912,%ebx
 mov 20(%esp),%eax
 add $24,%esp
 movl $364,%edi
 jmp *symfnc+1456
l0052:
 add $24,%esp
 ret
l0058:
 .long 18
 .byte 72,97,115,104,32,116,97,98,108,101
 .byte 32,111,118,101,114,102,108,111,119
 .byte 0
 .long 1
/ (*entry hash-into-table expr 1)
 .globl l0059
l0059:
 mov %eax,-44(%esp)
 sub $16,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,12(%esp)
 mov %edi,8(%esp)
 mov %edi,4(%esp)
 mov %eax,(%esp)
 movl $365,%edi
 call *symfnc+1460
 mov %eax,4(%esp)
 mov %eax,8(%esp)
 movl $-1,12(%esp)
l0060:
 mov 8(%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 mov 0(%eax,%ebx,1),%ax
 cwde
 and $65535,%eax
 cmpl $0,%eax
 jne l0061
 cmpl $-1,12(%esp)
 je l0062
 mov 12(%esp),%eax
 jmp l0063
l0062:
 mov 8(%esp),%eax
l0063:
 jmp l0064
l0061:
 mov 8(%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 mov 0(%eax,%ebx,1),%ax
 cwde
 mov %eax,%ebx
 and $65535,%ebx
 cmpl $65535,%ebx
 jne l0065
 cmpl $-1,12(%esp)
 jne l0066
 mov 8(%esp),%edi
 mov %edi,12(%esp)
 jmp l0066
l0065:
 mov 8(%esp),%ebx
 mov symval+1044,%eax
 shl $1,%ebx
 mov 0(%eax,%ebx,1),%ax
 cwde
 mov (%esp),%ebx
 and $65535,%eax
 shl $2,%eax
 add symval+1356,%eax
 mov (%eax),%eax
 movl $366,%edi
 call *symfnc+1464
 cmpl $((30*0x8000000)+128),%eax
 je l0066
 mov 8(%esp),%eax
 jmp l0064
l0066:
 cmpl $68023,8(%esp)
 jne l0067
 xor %eax,%eax
 jmp l0068
l0067:
 xor %eax,%eax
 incl %eax
 add 8(%esp),%eax
l0068:
 mov %eax,8(%esp)
 cmp 4(%esp),%eax
 jne l0060
 movl $((4*0x8000000)+l0058),%eax
 movl $346,%edi
 call *symfnc+1384
 jmp l0060
l0064:
 add $16,%esp
 ret
 .long 2
/ (*entry initialize-new-id expr 2)
 .globl l0069
l0069:
 mov %eax,-36(%esp)
 sub $8,%esp
 mov %eax,(%esp)
 and $134217727,%eax
 or $-268435456,%eax
 mov %eax,4(%esp)
 mov (%esp),%ecx
 shl $2,%ecx
 add symval+1356,%ecx
 mov %ebx,(%ecx)
 mov (%esp),%edx
 shl $2,%edx
 add symval+1248,%edx
 movl $((30*0x8000000)+128),%ebp
 mov %ebp,(%edx)
 mov (%esp),%eax
 shl $2,%eax
 add symval+1256,%eax
 mov %ebp,(%eax)
 mov (%esp),%eax
 shl $2,%eax
 add symval+1232,%eax
 mov (%esp),%ebx
 and $134217727,%ebx
 or $-402653184,%ebx
 mov %ebx,(%eax)
 mov (%esp),%eax
 movl $367,%edi
 call *symfnc+1468
 mov 4(%esp),%eax
 add $8,%esp
 ret
 .long 1
/ (*entry hash-function expr 1)
 .globl l0072
l0072:
 mov %eax,-48(%esp)
 sub $20,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,12(%esp)
 mov %edi,4(%esp)
 and $134217727,%eax
 mov %eax,8(%esp)
 mov (%eax),%eax
 shl $5,%eax
 sar $5,%eax
 mov %eax,(%esp)
 xor %eax,%eax
 mov %eax,16(%esp)
 cmpl $24,(%esp)
 jle l0073
 movl $24,(%esp)
l0073:
 mov (%esp),%ebx
 xor %eax,%eax
 mov %eax,12(%esp)
 mov %ebx,4(%esp)
l0074:
 mov 12(%esp),%edi
 cmp 4(%esp),%edi
 jg l0075
 mov 12(%esp),%ebx
 movl $4,%eax
 add 8(%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 movl $24,%ebx
 sub 12(%esp),%ebx
 cmpl $0,%ebx
 jge l0070
 neg %ebx
 xchg %ebx,%ecx
 shr %cl,%eax
 jmp l0071
l0070:
 xchg %ebx,%ecx
 shl %cl,%eax
l0071:
 xchg %ebx,%ecx
 mov 16(%esp),%edi
 xor %edi,%eax
 mov %eax,16(%esp)
 incl 12(%esp)
 jmp l0074
l0075:
 movl $68023,%ebx
 mov 16(%esp),%eax
 add $20,%esp
 xor %edx,%edx
 idiv %ebx
 mov %edx,%eax
 ret
 .long 1
/ (*entry faslin expr 1)
 .globl faslin
faslin:
 mov %eax,-72(%esp)
 sub $44,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,32(%esp)
 mov %edi,12(%esp)
 mov %edi,8(%esp)
 mov %eax,(%esp)
 movl $((30*0x8000000)+128),16(%esp)
 movl $((30*0x8000000)+128),24(%esp)
 movl $((30*0x8000000)+128),28(%esp)
 movl $((30*0x8000000)+128),40(%esp)
 movl $((30*0x8000000)+128),4(%esp)
 movl $((30*0x8000000)+128),20(%esp)
 movl $((30*0x8000000)+128),36(%esp)
 movl $347,%edi
 call *symfnc+1388
 mov %eax,8(%esp)
 movl $349,%edi
 call *symfnc+1396
 mov %eax,12(%esp)
 movl $65535,%ebx
 and %eax,%ebx
 cmpl $399,%ebx
 je l0076
 mov 8(%esp),%eax
 movl $353,%edi
 call *symfnc+1412
 mov (%esp),%eax
 movl $368,%edi
 call *symfnc+1472
 jmp l0077
l0076:
 mov 12(%esp),%eax
 shr $16,%eax
 mov %eax,12(%esp)
 mov 8(%esp),%eax
 movl $369,%edi
 call *symfnc+1476
 mov %eax,16(%esp)
 mov 8(%esp),%eax
 movl $349,%edi
 call *symfnc+1396
 mov %eax,24(%esp)
 movl $370,%edi
 call *symfnc+1480
 mov %eax,28(%esp)
 xor %eax,%eax
 movl $370,%edi
 call *symfnc+1480
 mov %eax,36(%esp)
 mov 8(%esp),%eax
 movl $349,%edi
 call *symfnc+1396
 mov 28(%esp),%ebx
 add %eax,%ebx
 mov %ebx,40(%esp)
 mov 24(%esp),%ecx
 xor %ebx,%ebx
 add 28(%esp),%ebx
 mov 8(%esp),%eax
 movl $351,%edi
 call *symfnc+1404
 mov 8(%esp),%eax
 movl $349,%edi
 call *symfnc+1396
 mov %eax,4(%esp)
 movl $371,%edi
 call *symfnc+1484
 mov %eax,%ebx
 and $134217727,%ebx
 or $939524096,%ebx
 mov %ebx,20(%esp)
 mov 4(%esp),%ecx
 and $134217727,%ebx
 add $4,%ebx
 mov 8(%esp),%eax
 movl $351,%edi
 call *symfnc+1404
 mov 8(%esp),%eax
 movl $353,%edi
 call *symfnc+1412
 xor %eax,%eax
 incl %eax
 and 12(%esp),%eax
 cmpl $1,%eax
 jne l0078
 mov 16(%esp),%edx
 mov 20(%esp),%ecx
 mov 24(%esp),%ebx
 mov 28(%esp),%eax
 movl $372,%edi
 call *symfnc+1488
 jmp l0079
l0078:
 mov 16(%esp),%edx
 mov 20(%esp),%ecx
 mov 24(%esp),%ebx
 mov 28(%esp),%eax
 movl $373,%edi
 call *symfnc+1492
l0079:
 mov symval+1504,%eax
 mov %eax,32(%esp)
 mov 28(%esp),%edi
 mov %edi,symval+1504
 mov 40(%esp),%eax
 movl $374,%edi
 call *symfnc+1496
 mov 32(%esp),%edi
 mov %edi,symval+1504
 mov 36(%esp),%ebx
 mov 40(%esp),%eax
 movl $375,%edi
 call *symfnc+1500
l0077:
 movl $((30*0x8000000)+128),%eax
 add $44,%esp
 ret
 .long 2
/ (*entry delbps expr 2)
 .globl delbps
delbps:
 movl $((30*0x8000000)+128),%eax
 ret
 .long 4
/ (*entry do-relocation expr 4)
 .globl l0080
l0080:
 mov %eax,-52(%esp)
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,16(%esp)
 mov %eax,12(%esp)
 mov %ecx,4(%esp)
 mov %edx,8(%esp)
 mov %ebx,%eax
 shl $2,%eax
 xor %ebx,%ebx
 dec %ebx
 add %eax,%ebx
 xor %eax,%eax
 mov %eax,20(%esp)
 mov %ebx,(%esp)
l0081:
 mov 20(%esp),%edi
 cmp (%esp),%edi
 jle l0082
 movl $((30*0x8000000)+128),%eax
 jmp l0083
l0082:
 mov 20(%esp),%ebx
 mov 4(%esp),%eax
 and $134217727,%eax
 add $4,%eax
 mov %ebx,%ebp
 shr $2,%ebx
 mov 0(%eax,%ebx,1),%al
 mov %ebp,%ebx
 and $3,%ebx
 add %ebx,%ebx
 add $-6,%ebx
 neg %ebx
 xchg %ebx,%ecx
 shr %cl,%eax
 and $3,%eax
 mov 12(%esp),%ebx
 add 20(%esp),%ebx
 mov %ebx,16(%esp)
 cmpl $1,%eax
 je l0084
 cmpl $2,%eax
 je l0085
 cmpl $3,%eax
 je l0086
 jmp l0087
l0084:
 mov 8(%esp),%ecx
 mov 12(%esp),%ebx
 mov 16(%esp),%eax
 movl $377,%edi
 call *symfnc+1508
 jmp l0087
l0086:
 mov 8(%esp),%ecx
 mov 12(%esp),%ebx
 mov 16(%esp),%eax
 movl $378,%edi
 call *symfnc+1512
 jmp l0087
l0085:
 mov 8(%esp),%ecx
 mov 12(%esp),%ebx
 mov 16(%esp),%eax
 movl $379,%edi
 call *symfnc+1516
l0087:
 incl 20(%esp)
 jmp l0081
l0083:
 add $24,%esp
 ret
 .long 4
/ (*entry do-relocation-new expr 4)
 .globl l0088
l0088:
 mov %eax,-52(%esp)
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,8(%esp)
 mov %eax,16(%esp)
 mov %ecx,(%esp)
 mov %edx,12(%esp)
 movl $((30*0x8000000)+128),%ecx
 mov %eax,%ebx
 xor %eax,%eax
 mov %eax,4(%esp)
 mov %ebx,20(%esp)
 mov (%esp),%ebp
 and $134217727,%ebp
 add $4,%ebp
 mov %ebp,(%esp)
l0089:
 mov 4(%esp),%ebx
 mov (%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 and $255,%eax
 mov %eax,8(%esp)
 cmpl $0,%eax
 jne l0090
 movl $((30*0x8000000)+128),%eax
 jmp l0091
l0090:
 incl 4(%esp)
 movl $63,%eax
 and 8(%esp),%eax
 add 20(%esp),%eax
 mov %eax,20(%esp)
 mov 8(%esp),%ebx
 shr $6,%ebx
 mov %ebx,8(%esp)
 mov %ebx,%eax
 cmpl $1,%eax
 je l0092
 cmpl $2,%eax
 je l0093
 cmpl $3,%eax
 je l0094
 jmp l0089
l0092:
 mov 12(%esp),%ecx
 mov 16(%esp),%ebx
 mov 20(%esp),%eax
 movl $377,%edi
 call *symfnc+1508
 jmp l0089
l0094:
 mov 12(%esp),%ecx
 mov 16(%esp),%ebx
 mov 20(%esp),%eax
 movl $378,%edi
 call *symfnc+1512
 jmp l0089
l0093:
 mov 12(%esp),%ecx
 mov 16(%esp),%ebx
 mov 20(%esp),%eax
 movl $379,%edi
 call *symfnc+1516
 jmp l0089
l0091:
 add $24,%esp
 ret
 .long 3
/ (*entry relocate-word expr 3)
 .globl l0095
l0095:
 mov %eax,-40(%esp)
 sub $12,%esp
 mov %eax,8(%esp)
 mov (%eax),%eax
 mov %eax,(%esp)
 shr $30,%eax
 mov %eax,4(%esp)
 mov (%esp),%eax
 shl $2,%eax
 shr $2,%eax
 mov %ecx,%edx
 mov %ebx,%ecx
 mov %eax,%ebx
 mov 4(%esp),%eax
 movl $380,%edi
 call *symfnc+1520
 mov 8(%esp),%esi
 mov %eax,(%esi)
 add $12,%esp
 ret
 .long 3
/ (*entry relocate-inf expr 3)
 .globl l0096
l0096:
 mov %eax,-40(%esp)
 sub $12,%esp
 mov %eax,8(%esp)
 mov (%eax),%eax
 mov %eax,(%esp)
 and $12582912,%eax
 shr $22,%eax
 mov %eax,4(%esp)
 mov (%esp),%eax
 and $4194303,%eax
 mov %ecx,%edx
 mov %ebx,%ecx
 mov %eax,%ebx
 mov 4(%esp),%eax
 movl $380,%edi
 call *symfnc+1520
 mov 8(%esp),%esi
 mov (%esi),%edi
 and $134217727,%eax
 and $-134217728,%edi
 or %eax,%edi
 mov %edi,(%esi)
 add $12,%esp
 ret
 .long 4
/ (*entry compute-relocation expr 4)
 .globl l0097
l0097:
 mov %eax,-32(%esp)
 push %ebx
 cmpl $0,%eax
 jne l0098
 mov %ecx,%eax
 add %ebx,%eax
 jmp l0099
l0098:
 cmpl $2,%eax
 jne l0100
 cmpl $8150,%ebx
 jl l0101
 movl $-8156,%eax
 add %ebx,%eax
 shl $2,%eax
 add symval+1028,%eax
 jmp l0099
l0101:
 cmpl $2048,%ebx
 jl l0102
 mov %edx,%ebx
 mov (%esp),%eax
 movl $381,%edi
 call *symfnc+1524
 cmp symval+1228,%eax
 jle l0103
 shl $2,%eax
 add symval+1232,%eax
 jmp l0099
l0103:
 shl $2,%eax
 add symval+1236,%eax
 jmp l0099
l0102:
 mov %ebx,%eax
 shl $2,%eax
 add symval+1236,%eax
 jmp l0099
l0100:
 cmpl $3,%eax
 jne l0104
 cmpl $2048,%ebx
 jl l0105
 mov %edx,%ebx
 mov (%esp),%eax
 movl $381,%edi
 call *symfnc+1524
 mov %eax,(%esp)
l0105:
 mov (%esp),%eax
 shl $2,%eax
 add symval+1240,%eax
 jmp l0099
l0104:
 cmpl $1,%eax
 jne l0106
 cmpl $2048,%ebx
 jl l0107
 mov %edx,%ebx
 mov (%esp),%eax
 add $4,%esp
 movl $381,%edi
 jmp *symfnc+1524
l0107:
 mov %ebx,%eax
 jmp l0099
l0106:
 movl $((30*0x8000000)+128),%eax
l0099:
 add $4,%esp
 ret
 .long 3
/ (*entry relocate-fast-call expr 3)
 .globl l0108
l0108:
 movl $((30*0x8000000)+128),%eax
 ret
 .long 2
/ (*entry local-to-global-id expr 2)
 .globl l0109
l0109:
 add $-2047,%eax
 shl $2,%eax
 mov %ebx,%ecx
 and $134217727,%ecx
 add %ecx,%eax
 mov (%eax),%eax
 ret
 .long 1
/ (*entry read-id-table expr 1)
 .globl l0110
l0110:
 mov %eax,-52(%esp)
 sub $24,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,20(%esp)
 mov %edi,16(%esp)
 mov %edi,12(%esp)
 mov %edi,8(%esp)
 mov %edi,4(%esp)
 mov %eax,(%esp)
 movl $349,%edi
 call *symfnc+1396
 mov %eax,4(%esp)
 incl %eax
 movl $371,%edi
 call *symfnc+1484
 and $134217727,%eax
 or $939524096,%eax
 mov %eax,8(%esp)
 mov 4(%esp),%ebx
 xor %eax,%eax
 mov %eax,12(%esp)
 mov %ebx,16(%esp)
l0111:
 mov 12(%esp),%edi
 cmp 16(%esp),%edi
 jg l0112
 mov (%esp),%eax
 movl $349,%edi
 call *symfnc+1396
 mov symval+1032,%esi
 mov %eax,(%esi)
 movl $5,%ecx
 add %eax,%ecx
 mov %ecx,%ebx
 shr $30,%ebx
 add %ebx,%ecx
 sar $2,%ecx
 movl $4,%ebx
 add symval+1032,%ebx
 mov (%esp),%eax
 movl $351,%edi
 call *symfnc+1404
 xor %eax,%eax
 add symval+1032,%eax
 and $134217727,%eax
 or $536870912,%eax
 movl $359,%edi
 call *symfnc+1436
 mov %eax,20(%esp)
 xor %eax,%eax
 incl %eax
 add 12(%esp),%eax
 shl $2,%eax
 mov 8(%esp),%ebx
 and $134217727,%ebx
 add %ebx,%eax
 mov 20(%esp),%ecx
 and $134217727,%ecx
 mov %ecx,(%eax)
 incl 12(%esp)
 jmp l0111
l0112:
 mov 8(%esp),%eax
 add $24,%esp
 ret
 .long 3
/ (*entry putentry expr 3)
 .globl putentry
putentry:
 add symval+1504,%ecx
 and $134217727,%ecx
 or $-1610612736,%ecx
 movl $383,%edi
 jmp *symfnc+1532
l0113:
 .long 22
 .byte 70,105,108,101,32,105,115,32,110,111
 .byte 116,32,70,65,83,76,32,102,111,114,109
 .byte 97,116,0
 .long 1
/ (*entry faslin-bad-file expr 1)
 .globl l0114
l0114:
 movl $((4*0x8000000)+l0113),%eax
 movl $332,%edi
 call *symfnc+1328
 movl $334,%edi
 jmp *symfnc+1336
l0115:
 .long 30
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,98,105,110,97,114,121,32,112,114
 .byte 111,103,114,97,109,32,115,112,97,99
 .byte 101,0
 .long 1
/ (*entry gtbps expr 1)
 .globl gtbps
gtbps:
 mov %eax,-32(%esp)
 sub $4,%esp
l0116:
 mov %eax,(%esp)
 cmpl $((30*0x8000000)+128),%eax
 jne l0117
 movl $385,%edi
 call *symfnc+1540
l0117:
 cmpl $10,(%esp)
 jle l0118
 movl $15,%eax
 and symval+1172,%eax
 cmpl $0,%eax
 je l0118
 mov symval+1172,%ebx
 shr $4,%ebx
 shl $4,%ebx
 add $16,%ebx
 mov %ebx,symval+1172
l0118:
 mov symval+1172,%eax
 mov (%esp),%ebx
 shl $2,%ebx
 add symval+1172,%ebx
 mov %ebx,symval+1172
 cmp symval+1144,%ebx
 jle l0119
 mov %eax,symval+1172
 movl $((30*0x8000000)+386),%eax
 movl $387,%edi
 call *symfnc+1548
 cmpl $((30*0x8000000)+128),%eax
 je l0120
 mov (%esp),%eax
 movl $386,%edi
 call *symfnc+1544
 cmpl $((30*0x8000000)+128),%eax
 je l0120
 mov (%esp),%eax
 jmp l0116
l0120:
 movl $((4*0x8000000)+l0115),%eax
 add $4,%esp
 movl $388,%edi
 jmp *symfnc+1552
l0119:
 add $4,%esp
 ret
l0121:
 .long 21
 .byte 71,84,66,80,83,32,99,97,108,108,101
 .byte 100,32,119,105,116,104,32,78,73,76
 .byte 46,0,0
 .long 0
/ (*entry gtbps-nil-error expr 0)
 .globl l0122
l0122:
 movl $((4*0x8000000)+l0121),%eax
 movl $388,%edi
 jmp *symfnc+1552
 .long 1
/ (*entry gtheap expr 1)
 .globl gtheap
gtheap:
 cmpl $((30*0x8000000)+128),%eax
 jne l0123
 movl $389,%edi
 jmp *symfnc+1556
l0123:
 movl $390,%edi
 jmp *symfnc+1560
 .long 1
/ (*entry real-gtheap expr 1)
 .globl l0124
l0124:
 mov %eax,%ecx
 mov symval+1128,%eax
 mov %ecx,%ebx
 shl $2,%ebx
 add symval+1128,%ebx
 mov %ebx,symval+1128
 cmp symval+1132,%ebx
 jl l0125
 mov %ecx,%ebx
 movl $392,%edi
 jmp *symfnc+1568
l0125:
 ret
l0126:
 .long 27
 .byte 71,97,114,98,97,103,101,32,99,111,108
 .byte 108,101,99,116,105,111,110,32,114,101
 .byte 113,117,105,114,101,100,46,0,0
 .long 1
/ (*entry get-heap-trap expr 1)
 .globl l0127
l0127:
 movl $((4*0x8000000)+l0126),%eax
 movl $346,%edi
 jmp *symfnc+1384
l0128:
 .long 18
 .byte 82,97,110,32,111,117,116,32,111,102
 .byte 32,73,68,32,115,112,97,99,101,0
 .long 0
/ (*entry gtid expr 0)
 .globl gtid
gtid:
 cmpl $0,symval+1224
 jne l0129
 movl $393,%edi
 call *symfnc+1572
 cmpl $0,symval+1224
 jne l0129
 movl $((4*0x8000000)+l0128),%eax
 movl $346,%edi
 call *symfnc+1384
l0129:
 mov symval+1224,%eax
 mov %eax,%ebx
 shl $2,%ebx
 add symval+1356,%ebx
 mov (%ebx),%edi
 mov %edi,symval+1224
 ret
 .long 1
/ (*entry gtwrds expr 1)
 .globl gtwrds
gtwrds:
 mov %eax,-32(%esp)
 push %eax
 add $2,%eax
 movl $391,%edi
 call *symfnc+1564
 mov (%esp),%ebx
 and $134217727,%ebx
 or $-939524096,%ebx
 mov %ebx,(%eax)
 add $4,%esp
 ret
 .long 1
/ (*entry gtconststr expr 1)
 .globl gtconststr
gtconststr:
 mov %eax,-36(%esp)
 sub $8,%esp
 mov %eax,(%esp)
 add $5,%eax
 mov %eax,%ebx
 shr $30,%ebx
 add %ebx,%eax
 sar $2,%eax
 mov %eax,4(%esp)
 incl %eax
 movl $370,%edi
 call *symfnc+1480
 mov (%esp),%edi
 mov %edi,(%eax)
 mov 4(%esp),%ebx
 shl $2,%ebx
 add %eax,%ebx
 movl $0,(%ebx)
 add $8,%esp
 ret
l0130:
 .long 30
 .byte 83,85,66,83,69,81,32,99,97,108,108
 .byte 101,100,32,119,105,116,104,32,97,32
 .byte 110,111,110,45,115,116,114,105,110
 .byte 103,0
 .long 3
/ (*entry subseq expr 3)
 .globl subseq
subseq:
 mov %eax,-60(%esp)
 sub $32,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,28(%esp)
 mov %edi,24(%esp)
 mov %edi,20(%esp)
 mov %edi,16(%esp)
 mov %edi,12(%esp)
 mov %eax,(%esp)
 mov %ebx,4(%esp)
 mov %ecx,8(%esp)
 mov %eax,%edi
 shr $27,%edi
 cmpl $4,%edi
 je l0131
 movl $((4*0x8000000)+l0130),%eax
 movl $346,%edi
 call *symfnc+1384
l0131:
 xor %eax,%eax
 dec %eax
 add 8(%esp),%eax
 sub 4(%esp),%eax
 mov %eax,12(%esp)
 mov (%esp),%eax
 and $134217727,%eax
 mov %eax,16(%esp)
 mov 12(%esp),%eax
 movl $394,%edi
 call *symfnc+1576
 mov %eax,20(%esp)
 mov 12(%esp),%ebx
 xor %eax,%eax
 mov %eax,24(%esp)
 mov %ebx,28(%esp)
l0132:
 mov 24(%esp),%edi
 cmp 28(%esp),%edi
 jg l0133
 mov 4(%esp),%ebx
 add 24(%esp),%ebx
 movl $4,%eax
 add 16(%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 mov %eax,%ecx
 mov 24(%esp),%ebx
 movl $4,%eax
 add 20(%esp),%eax
 mov 0(%eax,%ebx,1),%edx
 shr $8,%edx
 shl $8,%edx
 and $255,%ecx
 or %edx,%ecx
 mov %ecx,0(%ebx,%eax,1)
 incl 24(%esp)
 jmp l0132
l0133:
 mov 20(%esp),%eax
 and $134217727,%eax
 or $536870912,%eax
 add $32,%esp
 ret
 .long 2
/ (*entry search-string-for-character expr 2)
 .globl l0134
l0134:
 mov %eax,-44(%esp)
 sub $16,%esp
 mov %eax,(%esp)
 mov %ebx,4(%esp)
 and $134217727,%ebx
 mov (%ebx),%ebx
 shl $5,%ebx
 sar $5,%ebx
 xor %eax,%eax
 mov %eax,8(%esp)
 mov %ebx,12(%esp)
l0135:
 mov 8(%esp),%edi
 cmp 12(%esp),%edi
 jle l0136
 movl $((30*0x8000000)+128),%eax
 jmp l0137
l0136:
 mov 8(%esp),%ebx
 mov 4(%esp),%eax
 and $134217727,%eax
 add $4,%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 cmp (%esp),%eax
 jne l0138
 mov 8(%esp),%eax
 jmp l0137
l0138:
 incl 8(%esp)
 jmp l0135
l0137:
 add $16,%esp
 ret
 .long 2
/ (*entry unchecked-string-equal expr 2)
 .globl l0139
l0139:
 mov %eax,-48(%esp)
 sub $20,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,16(%esp)
 movl $((30*0x8000000)+128),12(%esp)
 and $134217727,%eax
 mov %eax,(%esp)
 and $134217727,%ebx
 mov %ebx,4(%esp)
 mov (%eax),%ecx
 shl $5,%ecx
 sar $5,%ecx
 mov %ecx,8(%esp)
 mov (%ebx),%edx
 shl $5,%edx
 sar $5,%edx
 cmp %edx,%ecx
 je l0140
 movl $((30*0x8000000)+128),%eax
 jmp l0141
l0140:
 movl $0,12(%esp)
l0142:
 mov 12(%esp),%edi
 cmp 8(%esp),%edi
 jle l0143
 movl $((30*0x8000000)+116),%eax
 jmp l0141
l0143:
 mov 12(%esp),%ebx
 movl $4,%eax
 add (%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 mov %eax,16(%esp)
 mov 12(%esp),%ebx
 movl $4,%eax
 add 4(%esp),%eax
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 cmp 16(%esp),%eax
 je l0144
 movl $((30*0x8000000)+128),%eax
 jmp l0141
l0144:
 incl 12(%esp)
 jmp l0142
l0141:
 add $20,%esp
 ret
 .long 2
/ (*entry copystringtofrom expr 2)
 .globl copystringtofrom
copystringtofrom:
 mov %eax,-44(%esp)
 sub $16,%esp
 mov %eax,12(%esp)
 mov %eax,%ecx
 and $134217727,%ecx
 mov %ecx,4(%esp)
 mov %ebx,%edx
 and $134217727,%edx
 mov %edx,8(%esp)
 mov (%edx),%ebp
 shl $5,%ebp
 sar $5,%ebp
 mov %ebp,(%esp)
 mov (%ecx),%eax
 shl $5,%eax
 sar $5,%eax
 cmp %ebp,%eax
 jge l0145
 mov %eax,(%esp)
l0145:
 movl $5,%eax
 add (%esp),%eax
 mov %eax,%ebx
 shr $30,%ebx
 add %ebx,%eax
 sar $2,%eax
 mov %eax,(%esp)
 mov %eax,%ebx
 xor %eax,%eax
 mov %eax,%edx
 mov %ebx,%ecx
l0146:
 cmp %ecx,%edx
 jg l0147
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
 mov (%ebx),%edi
 mov %edi,(%eax)
 incl %edx
 jmp l0146
l0147:
 mov 12(%esp),%eax
 add $16,%esp
 ret
 .long 2
/ (*entry cons expr 2)
 .globl cons
cons:
 mov %eax,-32(%esp)
 push %ebx
 push %eax
 movl $2,%eax
 movl $391,%edi
 call *symfnc+1564
 mov (%esp),%edi
 mov %edi,(%eax)
 mov 4(%esp),%edi
 mov %edi,4(%eax)
 and $134217727,%eax
 or $1207959552,%eax
 add $8,%esp
 ret
 .long 1
/ (*entry interrogate expr 1)
 .globl interrogate
interrogate:
 shl $2,%eax
 add symval+1232,%eax
 mov (%eax),%eax
 ret
 .long 2
/ (*entry modify expr 2)
 .globl modify
modify:
 shl $2,%eax
 add symval+1232,%eax
 mov %ebx,(%eax)
 mov %ebx,%eax
 ret
 .long 3
/ (*entry put expr 3)
 .globl put
put:
 movl $398,%edi
 jmp *symfnc+1592
 .long 3
/ (*entry unchecked-put expr 3)
 .globl l0148
l0148:
 mov %eax,-44(%esp)
 sub $16,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,12(%esp)
 mov %eax,(%esp)
 mov %ebx,4(%esp)
 mov %ecx,8(%esp)
 movl $400,%edi
 call *symfnc+1600
 mov %eax,12(%esp)
 mov %eax,%ebx
 mov 4(%esp),%eax
 movl $401,%edi
 call *symfnc+1604
 cmpl $((30*0x8000000)+128),%eax
 je l0149
 mov 8(%esp),%edi
 mov %edi,-1207959548(%eax)
 jmp l0150
l0149:
 mov 8(%esp),%ebx
 mov 4(%esp),%eax
 movl $395,%edi
 call *symfnc+1580
 mov 12(%esp),%ebx
 movl $395,%edi
 call *symfnc+1580
 mov %eax,%ebx
 mov (%esp),%eax
 movl $402,%edi
 call *symfnc+1608
l0150:
 mov 8(%esp),%eax
 add $16,%esp
 ret
 .long 2
/ (*entry atsoc expr 2)
 .globl atsoc
atsoc:
l0151:
 mov %ebx,%edi
 shr $27,%edi
 cmpl $9,%edi
 je l0152
 movl $((30*0x8000000)+128),%eax
 ret
l0152:
 mov -1207959552(%ebx),%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0153
 mov -1207959552(%ebx),%esi
 cmp -1207959552(%esi),%eax
 jne l0153
 mov -1207959552(%ebx),%eax
 ret
l0153:
 mov -1207959548(%ebx),%ebx
 jmp l0151
 .long 2
/ (*entry unchecked-setprop expr 2)
 .globl l0154
l0154:
 and $134217727,%eax
 shl $2,%eax
 add symval+1248,%eax
 mov %ebx,(%eax)
 mov %ebx,%eax
 ret
 .long 1
/ (*entry unchecked-prop expr 1)
 .globl l0155
l0155:
 and $134217727,%eax
 shl $2,%eax
 add symval+1248,%eax
 mov (%eax),%eax
 ret
 .long 3
/ (*entry putd expr 3)
 .globl putd
putd:
 movl $403,%edi
 jmp *symfnc+1612
l0156:
 .long 26
 .byte 66,97,100,32,112,97,114,97,109,101
 .byte 116,101,114,115,32,116,111,32,67,79
 .byte 68,69,45,80,85,84,68,0
 .long 3
/ (*entry code-putd expr 3)
 .globl l0157
l0157:
 mov %eax,-40(%esp)
 sub $12,%esp
 mov %eax,(%esp)
 mov %ebx,4(%esp)
 mov %ecx,8(%esp)
 mov %eax,%edi
 shr $27,%edi
 cmpl $30,%edi
 jne l0158
 mov %ebx,%edi
 shr $27,%edi
 cmpl $30,%edi
 jne l0158
 mov %ecx,%edi
 shr $27,%edi
 cmpl $20,%edi
 je l0159
l0158:
 movl $((4*0x8000000)+l0156),%eax
 movl $346,%edi
 call *symfnc+1384
l0159:
 mov 8(%esp),%ebx
 and $134217727,%ebx
 mov (%esp),%eax
 and $134217727,%eax
 movl $404,%edi
 call *symfnc+1616
 mov 4(%esp),%edi
 cmpl $((30*0x8000000)+405),%edi
 je l0160
 mov 4(%esp),%ecx
 movl $((30*0x8000000)+406),%ebx
 mov (%esp),%eax
 add $12,%esp
 movl $399,%edi
 jmp *symfnc+1596
l0160:
 movl $((30*0x8000000)+128),%eax
 add $12,%esp
 ret
 .long 1
/ (*entry fluid expr 1)
 .globl fluid
fluid:
 mov %eax,-40(%esp)
 sub $12,%esp
 movl $((30*0x8000000)+128),%edi
 mov %edi,8(%esp)
 mov %eax,(%esp)
 movl $((30*0x8000000)+128),%eax
 mov (%esp),%edi
 mov %edi,4(%esp)
 mov 4(%esp),%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0161
 mov 4(%esp),%eax
 mov -1207959552(%eax),%eax
 jmp l0162
l0161:
 movl $((30*0x8000000)+128),%eax
l0162:
 mov %eax,8(%esp)
l0163:
 mov 4(%esp),%edi
 shr $27,%edi
 cmpl $9,%edi
 je l0164
 movl $((30*0x8000000)+128),%eax
 jmp l0165
l0164:
 mov 8(%esp),%eax
 movl $407,%edi
 call *symfnc+1628
 mov 4(%esp),%eax
 mov -1207959548(%eax),%eax
 mov %eax,4(%esp)
 mov %eax,%edi
 shr $27,%edi
 cmpl $9,%edi
 jne l0166
 mov -1207959552(%eax),%eax
 jmp l0167
l0166:
 movl $((30*0x8000000)+128),%eax
l0167:
 mov %eax,8(%esp)
 jmp l0163
l0165:
 add $12,%esp
 ret
 .long 1
/ (*entry fluid1 expr 1)
 .globl l0168
l0168:
 movl $((30*0x8000000)+408),%ecx
 movl $((30*0x8000000)+409),%ebx
 movl $399,%edi
 jmp *symfnc+1596
 .long 1
/ (*entry stderror expr 1)
 .globl stderror
stderror:
 movl $346,%edi
 jmp *symfnc+1384
 .long 2
/ (*entry *define-constant expr 2)
 .globl l0169
l0169:
 mov %eax,%ecx
 and $134217727,%ecx
 shl $2,%ecx
 add symval+1232,%ecx
 mov %ebx,(%ecx)
 movl $((30*0x8000000)+116),%ecx
 movl $((30*0x8000000)+410),%ebx
 movl $399,%edi
 jmp *symfnc+1596
 .globl _whatsup
 .long 1
/ (*entry whatsup expr 1)
 .globl l0170
l0170:
 cmpl $0,symval+1220
 jge l0171
 movl $412,%edi
 jmp *symfnc+1648
l0171:
 push %eax
 call _whatsup
 add $4,%esp
 ret
 .globl _getpid
 .long 0
/ (*entry getpid expr 0)
 .globl l0172
l0172:
 call _getpid
 add $0,%esp
 ret
 .globl _echoon
 .long 0
/ (*entry echoon expr 0)
 .globl l0173
l0173:
 call _echoon
 add $0,%esp
 ret
 .globl _echooff
 .long 0
/ (*entry echooff expr 0)
 .globl l0174
l0174:
 call _echooff
 add $0,%esp
 ret
 .globl _external_charsininputbuffer
 .long 1
/ (*entry external_charsininputbuffer expr 1)
 .globl l0175
l0175:
 push %eax
 call _external_charsininputbuffer
 add $4,%esp
 ret
 .globl _flushstdoutputbuffer
 .long 0
/ (*entry flushstdoutputbuffer expr 0)
 .globl l0176
l0176:
 call _flushstdoutputbuffer
 add $0,%esp
 ret
 .globl _external_user_homedir_string
 .long 0
/ (*entry external_user_homedir_string expr 0)
 .globl l0177
l0177:
 call _external_user_homedir_string
 add $0,%esp
 ret
 .globl _alterheapsize
 .long 1
/ (*entry alterheapsize expr 1)
 .globl l0178
l0178:
 push %eax
 call _alterheapsize
 add $4,%esp
 ret
 .globl _allocatemorebps
 .long 1
/ (*entry allocatemorebps expr 1)
 .globl l0179
l0179:
 push %eax
 call _allocatemorebps
 add $4,%esp
 ret
 .globl _get_imagefilepath
 .long 0
/ (*entry get_imagefilepath expr 0)
 .globl l0180
l0180:
 call _get_imagefilepath
 add $0,%esp
 ret
 .globl _get_file_status
 .long 3
/ (*entry get_file_status expr 3)
 .globl l0181
l0181:
 push %ecx
 push %ebx
 push %eax
 call _get_file_status
 add $12,%esp
 ret
 .globl _os_startup_hook
 .long 2
/ (*entry os_startup_hook expr 2)
 .globl l0182
l0182:
 push %ebx
 push %eax
 call _os_startup_hook
 add $8,%esp
 ret
 .globl _os_cleanup_hook
 .long 0
/ (*entry os_cleanup_hook expr 0)
 .globl l0183
l0183:
 call _os_cleanup_hook
 add $0,%esp
 ret
 .globl _get_execfilepath
 .long 0
/ (*entry get_execfilepath expr 0)
 .globl l0184
l0184:
 call _get_execfilepath
 add $0,%esp
 ret
 .globl _external_alarm
 .long 1
/ (*entry external_alarm expr 1)
 .globl l0185
l0185:
 push %eax
 call _external_alarm
 add $4,%esp
 ret
 .globl _external_ualarm
 .long 2
/ (*entry external_ualarm expr 2)
 .globl l0186
l0186:
 push %ebx
 push %eax
 call _external_ualarm
 add $8,%esp
 ret
 .globl _external_time
 .long 1
/ (*entry external_time expr 1)
 .globl l0187
l0187:
 push %eax
 call _external_time
 add $4,%esp
 ret
 .globl _external_timc
 .long 1
/ (*entry external_timc expr 1)
 .globl l0188
l0188:
 push %eax
 call _external_timc
 add $4,%esp
 ret
 .globl _external_stat
 .long 2
/ (*entry external_stat expr 2)
 .globl l0189
l0189:
 push %ebx
 push %eax
 call _external_stat
 add $8,%esp
 ret
 .globl _external_mkdir
 .long 2
/ (*entry external_mkdir expr 2)
 .globl l0190
l0190:
 push %ebx
 push %eax
 call _external_mkdir
 add $8,%esp
 ret
 .globl _external_rmdir
 .long 1
/ (*entry external_rmdir expr 1)
 .globl l0191
l0191:
 push %eax
 call _external_rmdir
 add $4,%esp
 ret
 .globl _external_link
 .long 2
/ (*entry external_link expr 2)
 .globl l0192
l0192:
 push %ebx
 push %eax
 call _external_link
 add $8,%esp
 ret
 .globl _external_unlink
 .long 1
/ (*entry external_unlink expr 1)
 .globl l0193
l0193:
 push %eax
 call _external_unlink
 add $4,%esp
 ret
 .globl _external_setenv
 .long 2
/ (*entry external_setenv expr 2)
 .globl l0194
l0194:
 push %ebx
 push %eax
 call _external_setenv
 add $8,%esp
 ret
 .globl _external_getenv
 .long 1
/ (*entry external_getenv expr 1)
 .globl l0195
l0195:
 push %eax
 call _external_getenv
 add $4,%esp
 ret
 .globl _uxfloat
 .long 2
/ (*entry uxfloat expr 2)
 .globl l0196
l0196:
 push %ebx
 push %eax
 call _uxfloat
 add $8,%esp
 ret
 .globl _uxfix
 .long 1
/ (*entry uxfix expr 1)
 .globl l0197
l0197:
 push %eax
 call _uxfix
 add $4,%esp
 ret
 .globl _uxassign
 .long 2
/ (*entry uxassign expr 2)
 .globl l0198
l0198:
 push %ebx
 push %eax
 call _uxassign
 add $8,%esp
 ret
 .globl _uxplus2
 .long 3
/ (*entry uxplus2 expr 3)
 .globl l0199
l0199:
 push %ecx
 push %ebx
 push %eax
 call _uxplus2
 add $12,%esp
 ret
 .globl _uxdifference
 .long 3
/ (*entry uxdifference expr 3)
 .globl l0200
l0200:
 push %ecx
 push %ebx
 push %eax
 call _uxdifference
 add $12,%esp
 ret
 .globl _uxtimes2
 .long 3
/ (*entry uxtimes2 expr 3)
 .globl l0201
l0201:
 push %ecx
 push %ebx
 push %eax
 call _uxtimes2
 add $12,%esp
 ret
 .globl _uxquotient
 .long 3
/ (*entry uxquotient expr 3)
 .globl l0202
l0202:
 push %ecx
 push %ebx
 push %eax
 call _uxquotient
 add $12,%esp
 ret
 .globl _uxgreaterp
 .long 4
/ (*entry uxgreaterp expr 4)
 .globl l0203
l0203:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _uxgreaterp
 add $16,%esp
 ret
 .globl _uxlessp
 .long 4
/ (*entry uxlessp expr 4)
 .globl l0204
l0204:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _uxlessp
 add $16,%esp
 ret
 .globl _uxwritefloat
 .long 3
/ (*entry uxwritefloat expr 3)
 .globl l0205
l0205:
 push %ecx
 push %ebx
 push %eax
 call _uxwritefloat
 add $12,%esp
 ret
 .globl _uuxdoubletofloat
 .long 2
/ (*entry uuxdoubletofloat expr 2)
 .globl l0206
l0206:
 push %ebx
 push %eax
 call _uuxdoubletofloat
 add $8,%esp
 ret
 .globl _uuxfloattodouble
 .long 2
/ (*entry uuxfloattodouble expr 2)
 .globl l0207
l0207:
 push %ebx
 push %eax
 call _uuxfloattodouble
 add $8,%esp
 ret
 .globl _uuxsin
 .long 2
/ (*entry uuxsin expr 2)
 .globl l0208
l0208:
 push %ebx
 push %eax
 call _uuxsin
 add $8,%esp
 ret
 .globl _uuxcos
 .long 2
/ (*entry uuxcos expr 2)
 .globl l0209
l0209:
 push %ebx
 push %eax
 call _uuxcos
 add $8,%esp
 ret
 .globl _uuxtan
 .long 2
/ (*entry uuxtan expr 2)
 .globl l0210
l0210:
 push %ebx
 push %eax
 call _uuxtan
 add $8,%esp
 ret
 .globl _uuxasin
 .long 2
/ (*entry uuxasin expr 2)
 .globl l0211
l0211:
 push %ebx
 push %eax
 call _uuxasin
 add $8,%esp
 ret
 .globl _uuxacos
 .long 2
/ (*entry uuxacos expr 2)
 .globl l0212
l0212:
 push %ebx
 push %eax
 call _uuxacos
 add $8,%esp
 ret
 .globl _uuxatan
 .long 2
/ (*entry uuxatan expr 2)
 .globl l0213
l0213:
 push %ebx
 push %eax
 call _uuxatan
 add $8,%esp
 ret
 .globl _uuxsqrt
 .long 2
/ (*entry uuxsqrt expr 2)
 .globl l0214
l0214:
 push %ebx
 push %eax
 call _uuxsqrt
 add $8,%esp
 ret
 .globl _uuxexp
 .long 2
/ (*entry uuxexp expr 2)
 .globl l0215
l0215:
 push %ebx
 push %eax
 call _uuxexp
 add $8,%esp
 ret
 .globl _uuxlog
 .long 2
/ (*entry uuxlog expr 2)
 .globl l0216
l0216:
 push %ebx
 push %eax
 call _uuxlog
 add $8,%esp
 ret
 .globl _uuxatan2
 .long 3
/ (*entry uuxatan2 expr 3)
 .globl l0217
l0217:
 push %ecx
 push %ebx
 push %eax
 call _uuxatan2
 add $12,%esp
 ret
 .globl _get_registry_value
 .long 4
/ (*entry get_registry_value expr 4)
 .globl l0218
l0218:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _get_registry_value
 add $16,%esp
 ret
 .globl _external_pwd
 .long 0
/ (*entry external_pwd expr 0)
 .globl l0219
l0219:
 call _external_pwd
 add $0,%esp
 ret
 .globl _sun3_sigset
 .long 2
/ (*entry sun3_sigset expr 2)
 .globl l0220
l0220:
 push %ebx
 push %eax
 call _sun3_sigset
 add $8,%esp
 ret
 .globl _sigrelse
 .long 2
/ (*entry sigrelse expr 2)
 .globl l0221
l0221:
 push %ebx
 push %eax
 call _sigrelse
 add $8,%esp
 ret
 .globl _unexec
 .long 4
/ (*entry unexec expr 4)
 .globl l0222
l0222:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _unexec
 add $16,%esp
 ret
 .globl _unixputc
 .long 1
/ (*entry unixputc expr 1)
 .globl l0223
l0223:
 push %eax
 call _unixputc
 add $4,%esp
 ret
 .globl _unixputs
 .long 1
/ (*entry unixputs expr 1)
 .globl l0224
l0224:
 push %eax
 call _unixputs
 add $4,%esp
 ret
 .globl _unixputn
 .long 1
/ (*entry unixputn expr 1)
 .globl l0225
l0225:
 push %eax
 call _unixputn
 add $4,%esp
 ret
 .globl _unixcleario
 .long 0
/ (*entry unixcleario expr 0)
 .globl l0226
l0226:
 call _unixcleario
 add $0,%esp
 ret
 .globl _expand_file_name
 .long 1
/ (*entry expand_file_name expr 1)
 .globl l0227
l0227:
 push %eax
 call _expand_file_name
 add $4,%esp
 ret
 .globl _unixopen
 .long 2
/ (*entry unixopen expr 2)
 .globl l0228
l0228:
 push %ebx
 push %eax
 call _unixopen
 add $8,%esp
 ret
 .globl _unixcd
 .long 1
/ (*entry unixcd expr 1)
 .globl l0229
l0229:
 push %eax
 call _unixcd
 add $4,%esp
 ret
 .globl _unixfread
 .long 4
/ (*entry unixfread expr 4)
 .globl l0230
l0230:
 cmpl $0,symval+1220
 jge l0231
 movl $412,%edi
 jmp *symfnc+1648
l0231:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _unixfread
 add $16,%esp
 ret
 .globl _unixfputc
 .long 2
/ (*entry unixfputc expr 2)
 .globl l0232
l0232:
 cmpl $0,symval+1220
 jge l0233
 movl $412,%edi
 jmp *symfnc+1648
l0233:
 push %ebx
 push %eax
 call _unixfputc
 add $8,%esp
 ret
 .globl _unixfgetc
 .long 1
/ (*entry unixfgetc expr 1)
 .globl l0234
l0234:
 cmpl $0,symval+1220
 jge l0235
 movl $412,%edi
 jmp *symfnc+1648
l0235:
 push %eax
 call _unixfgetc
 add $4,%esp
 ret
 .globl _unixfgets
 .long 3
/ (*entry unixfgets expr 3)
 .globl l0236
l0236:
 cmpl $0,symval+1220
 jge l0237
 movl $412,%edi
 jmp *symfnc+1648
l0237:
 push %ecx
 push %ebx
 push %eax
 call _unixfgets
 add $12,%esp
 ret
 .globl _unixfwrite
 .long 4
/ (*entry unixfwrite expr 4)
 .globl l0238
l0238:
 cmpl $0,symval+1220
 jge l0239
 movl $412,%edi
 jmp *symfnc+1648
l0239:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _unixfwrite
 add $16,%esp
 ret
 .globl _unixfflush
 .long 1
/ (*entry unixfflush expr 1)
 .globl l0240
l0240:
 cmpl $0,symval+1220
 jge l0241
 movl $412,%edi
 jmp *symfnc+1648
l0241:
 push %eax
 call _unixfflush
 add $4,%esp
 ret
 .globl _ctime
 .long 1
/ (*entry ctime expr 1)
 .globl l0242
l0242:
 push %eax
 call _ctime
 add $4,%esp
 ret
 .globl _external_system
 .long 1
/ (*entry external_system expr 1)
 .globl l0243
l0243:
 push %eax
 call _external_system
 add $4,%esp
 ret
 .globl _external_fullpath
 .long 1
/ (*entry external_fullpath expr 1)
 .globl l0244
l0244:
 push %eax
 call _external_fullpath
 add $4,%esp
 ret
 .globl _external_exit
 .long 1
/ (*entry external_exit expr 1)
 .globl l0245
l0245:
 push %eax
 call _external_exit
 add $4,%esp
 ret
 .globl _fopen
 .long 2
/ (*entry fopen expr 2)
 .globl l0246
l0246:
 push %ebx
 push %eax
 call _fopen
 add $8,%esp
 ret
 .globl _fclose
 .long 1
/ (*entry fclose expr 1)
 .globl l0247
l0247:
 push %eax
 call _fclose
 add $4,%esp
 ret
 .globl _fseek
 .long 3
/ (*entry fseek expr 3)
 .globl l0248
l0248:
 push %ecx
 push %ebx
 push %eax
 call _fseek
 add $12,%esp
 ret
 .globl _clearerr
 .long 1
/ (*entry clearerr expr 1)
 .globl l0249
l0249:
 push %eax
 call _clearerr
 add $4,%esp
 ret
 .globl __getw
 .long 1
/ (*entry getw expr 1)
 .globl l0250
l0250:
 push %eax
 call __getw
 add $4,%esp
 ret
 .globl __putw
 .long 2
/ (*entry putw expr 2)
 .globl l0251
l0251:
 push %ebx
 push %eax
 call __putw
 add $8,%esp
 ret
 .globl _signal
 .long 2
/ (*entry signal expr 2)
 .globl l0252
l0252:
 push %ebx
 push %eax
 call _signal
 add $8,%esp
 ret
 .globl _sleep
 .long 1
/ (*entry sleep expr 1)
 .globl l0253
l0253:
 push %eax
 call _sleep
 add $4,%esp
 ret
 .globl _ieee_handler
 .long 3
/ (*entry ieee_handler expr 3)
 .globl l0254
l0254:
 push %ecx
 push %ebx
 push %eax
 call _ieee_handler
 add $12,%esp
 ret
 .globl _ieee_flags
 .long 4
/ (*entry ieee_flags expr 4)
 .globl l0255
l0255:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _ieee_flags
 add $16,%esp
 ret
 .globl _setlinebuf
 .long 1
/ (*entry setlinebuf expr 1)
 .globl l0256
l0256:
 push %eax
 call _setlinebuf
 add $4,%esp
 ret
 .globl _popen
 .long 2
/ (*entry popen expr 2)
 .globl l0257
l0257:
 push %ebx
 push %eax
 call _popen
 add $8,%esp
 ret
 .globl _pclose
 .long 1
/ (*entry pclose expr 1)
 .globl l0258
l0258:
 push %eax
 call _pclose
 add $4,%esp
 ret
 .globl _profil
 .long 4
/ (*entry profil expr 4)
 .globl l0259
l0259:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _profil
 add $16,%esp
 ret
 .globl _datetag
 .long 0
/ (*entry datetag expr 0)
 .globl l0260
l0260:
 call _datetag
 add $0,%esp
 ret
 .globl _psll_call
 .long 4
/ (*entry psll_call expr 4)
 .globl l0261
l0261:
 push %edx
 push %ecx
 push %ebx
 push %eax
 call _psll_call
 add $16,%esp
 ret
 .long 4
/ (*entry unix-profile expr 4)
 .globl l0262
l0262:
 movl $486,%edi
 jmp *symfnc+1944
 .long 4
/ (*entry fread expr 4)
 .globl fread
fread:
 movl $466,%edi
 jmp *symfnc+1864
 .long 2
/ (*entry fputc expr 2)
 .globl fputc
fputc:
 movl $467,%edi
 jmp *symfnc+1868
 .long 1
/ (*entry fgetc expr 1)
 .globl fgetc
fgetc:
 movl $468,%edi
 jmp *symfnc+1872
 .long 3
/ (*entry fgets expr 3)
 .globl fgets
fgets:
 movl $469,%edi
 jmp *symfnc+1876
 .long 4
/ (*entry fwrite expr 4)
 .globl fwrite
fwrite:
 movl $470,%edi
 jmp *symfnc+1880
 .long 1
/ (*entry fflush expr 1)
 .globl fflush
fflush:
 movl $471,%edi
 jmp *symfnc+1884
 .long 1
/ (*entry plantunbound expr 1)
 .globl plantunbound
plantunbound:
 mov %eax,-32(%esp)
 push %eax
 cmp symval+1228,%eax
 jle l0263
 mov symval+1240,%ebx
 add $4,%esp
 movl $495,%edi
 jmp *symfnc+1980
l0263:
 mov symval+1240,%ebx
 movl $495,%edi
 call *symfnc+1980
 mov symval+1244,%ebx
 mov (%esp),%eax
 add $4,%esp
 movl $495,%edi
 jmp *symfnc+1980
 .long 2
/ (*entry plantunbound-1 expr 2)
 .globl l0264
l0264:
 add %eax,%eax
 mov %eax,%esi
 add %esi,%esi
 add %ebx,%esi
 mov l0265,%edi
 mov %edi,0(%esi)
 ret
 .long 0
l0265:
 .long undefinedfunction
 .long 2
/ (*entry plantcodepointer expr 2)
 .globl plantcodepointer
plantcodepointer:
 mov %eax,-32(%esp)
 push %ebx
 push %eax
 cmp symval+1228,%eax
 jle l0266
 mov symval+1240,%ecx
 add $8,%esp
 movl $496,%edi
 jmp *symfnc+1984
l0266:
 mov symval+1240,%ecx
 movl $496,%edi
 call *symfnc+1984
 mov symval+1244,%ecx
 mov 4(%esp),%ebx
 mov (%esp),%eax
 add $8,%esp
 movl $496,%edi
 jmp *symfnc+1984
 .long 3
/ (*entry plantcodepointer-1 expr 3)
 .globl l0267
l0267:
 add %eax,%eax
 mov %eax,%esi
 add %esi,%esi
 add %ecx,%esi
 mov %ebx,0(%esi)
 ret
 .long 1
/ (*entry plantlambdalink expr 1)
 .globl plantlambdalink
plantlambdalink:
 mov %eax,-32(%esp)
 push %eax
 cmp symval+1228,%eax
 jle l0268
 mov symval+1240,%ebx
 add $4,%esp
 movl $497,%edi
 jmp *symfnc+1988
l0268:
 mov symval+1240,%ebx
 movl $497,%edi
 call *symfnc+1988
 mov symval+1244,%ebx
 mov (%esp),%eax
 add $4,%esp
 movl $497,%edi
 jmp *symfnc+1988
 .long 2
/ (*entry plantlambdalink-1 expr 2)
 .globl l0269
l0269:
 add %eax,%eax
 mov %eax,%esi
 add %esi,%esi
 add %ebx,%esi
 mov l0270,%edi
 mov %edi,0(%esi)
 ret
 .long 0
l0270:
 .long compiledcallinginterpreted
 .long 1
/ (*entry addressapply0 expr 1)
 .globl l0271
l0271:
 jmp *%eax
 .long 2
/ (*entry bittable expr 2)
 .globl bittable
bittable:
 mov %eax,-32(%esp)
 push %ebx
 shr $2,%ebx
 mov 0(%eax,%ebx,1),%al
 cbw
 cwde
 mov (%esp),%ebx
 and $3,%ebx
 add %ebx,%ebx
 add $-6,%ebx
 cmpl $0,%ebx
 jge l0272
 neg %ebx
 xchg %ebx,%ecx
 shr %cl,%eax
 jmp l0273
l0272:
 xchg %ebx,%ecx
 shl %cl,%eax
l0273:
 xchg %ebx,%ecx
 and $3,%eax
 add $4,%esp
 ret
 .long 1
/ (*entry undefinedfunction expr 1)
 .globl undefinedfunction
undefinedfunction:
 jmp *symfnc+2004
l0274:
 .long 26
 .byte 85,110,100,101,102,105,110,101,100
 .byte 32,102,117,110,99,116,105,111,110,32
 .byte 99,97,108,108,101,100,58,32,0
 .long 1
/ (*entry undefinedfunction-aux expr 1)
 .globl l0275
l0275:
 push %edi
 movl $((4*0x8000000)+l0274),%eax
 movl $332,%edi
 call *symfnc+1328
 mov symval+1356,%esi
 pop %edi
 shl $2,%edi
 mov 0(%esi,%edi,1),%eax
 movl $332,%edi
 call *symfnc+1328
 xor %eax,%eax
 movl $323,%edi
 call *symfnc+1292
 ret
 .long 0
/ (*entry compiledcallinginterpreted expr 0)
 .globl compiledcallinginterpreted
compiledcallinginterpreted:
 and $134217727,%edi
 or $-268435456,%edi
 mov %edi,symval+2016
 movl $502,%edi
 jmp *symfnc+2008
l0276:
 .long 12
 .byte 70,65,84,65,76,32,69,82,82,79,82,58
 .byte 32,0
 .long 1
/ (*entry kernel-fatal-error expr 1)
 .globl l0277
l0277:
 mov %eax,-32(%esp)
 push %eax
 movl $((4*0x8000000)+l0276),%eax
 movl $332,%edi
 call *symfnc+1328
 mov (%esp),%eax
 movl $332,%edi
 call *symfnc+1328
 movl $334,%edi
 call *symfnc+1336
 xor %eax,%eax
 dec %eax
 add $4,%esp
 movl $323,%edi
 jmp *symfnc+1292
 .long 1
/ (*entry codeaddressp expr 1)
 .globl codeaddressp
codeaddressp:
 mov %eax,-32(%esp)
 sub $4,%esp
 and $134217727,%eax
 mov %eax,(%esp)
 movl $((30*0x8000000)+256),%eax
 movl $505,%edi
 call *symfnc+2020
 and $134217727,%eax
 cmp (%esp),%eax
 jle l0278
 movl $((30*0x8000000)+128),%eax
 jmp l0279
l0278:
 movl $((30*0x8000000)+116),%eax
l0279:
 cmpl $((30*0x8000000)+128),%eax
 je l0280
 movl $((30*0x8000000)+506),%eax
 movl $505,%edi
 call *symfnc+2020
 and $134217727,%eax
 cmp (%esp),%eax
 jg l0281
 movl $((30*0x8000000)+128),%eax
 jmp l0280
l0281:
 movl $((30*0x8000000)+116),%eax
l0280:
 cmpl $((30*0x8000000)+128),%eax
 jne l0282
 mov symval+1148,%eax
 and $134217727,%eax
 cmp (%esp),%eax
 jle l0283
 movl $((30*0x8000000)+128),%eax
 jmp l0284
l0283:
 movl $((30*0x8000000)+116),%eax
l0284:
 cmpl $((30*0x8000000)+128),%eax
 je l0282
 mov symval+1172,%eax
 and $134217727,%eax
 cmp (%esp),%eax
 jg l0285
 movl $((30*0x8000000)+128),%eax
 jmp l0282
l0285:
 movl $((30*0x8000000)+116),%eax
l0282:
 add $4,%esp
 ret
 .long 1
/ (*entry lastkernel expr 1)
 .globl lastkernel
lastkernel:
 ret
 .long 0
/ (*entry initcode expr 0)
 .globl initcode
initcode:
 movl $((30*0x8000000)+128),%eax
 ret
 .globl l0286
l0286:
 .long 0
 .byte 0,0
 .globl l0287
l0287:
 .long 0
 .byte 1,0
 .globl l0288
l0288:
 .long 0
 .byte 2,0
 .globl l0289
l0289:
 .long 0
 .byte 3,0
 .globl l0290
l0290:
 .long 0
 .byte 4,0
 .globl l0291
l0291:
 .long 0
 .byte 5,0
 .globl l0292
l0292:
 .long 0
 .byte 6,0
 .globl l0293
l0293:
 .long 0
 .byte 7,0
 .globl l0294
l0294:
 .long 0
 .byte 8,0
 .globl l0295
l0295:
 .long 0
 .byte 9,0
 .globl l0296
l0296:
 .long 0
 .byte 10,0
 .globl l0297
l0297:
 .long 0
 .byte 11,0
 .globl l0298
l0298:
 .long 0
 .byte 12,0
 .globl l0299
l0299:
 .long 0
 .byte 13,0
 .globl l0300
l0300:
 .long 0
 .byte 14,0
 .globl l0301
l0301:
 .long 0
 .byte 15,0
 .globl l0302
l0302:
 .long 0
 .byte 16,0
 .globl l0303
l0303:
 .long 0
 .byte 17,0
 .globl l0304
l0304:
 .long 0
 .byte 18,0
 .globl l0305
l0305:
 .long 0
 .byte 19,0
 .globl l0306
l0306:
 .long 0
 .byte 20,0
 .globl l0307
l0307:
 .long 0
 .byte 21,0
 .globl l0308
l0308:
 .long 0
 .byte 22,0
 .globl l0309
l0309:
 .long 0
 .byte 23,0
 .globl l0310
l0310:
 .long 0
 .byte 24,0
 .globl l0311
l0311:
 .long 0
 .byte 25,0
 .globl l0312
l0312:
 .long 0
 .byte 26,0
 .globl l0313
l0313:
 .long 0
 .byte 27,0
 .globl l0314
l0314:
 .long 0
 .byte 28,0
 .globl l0315
l0315:
 .long 0
 .byte 29,0
 .globl l0316
l0316:
 .long 0
 .byte 30,0
 .globl l0317
l0317:
 .long 0
 .byte 31,0
 .globl l0318
l0318:
 .long 0
 .byte 32,0
 .globl l0319
l0319:
 .long 0
 .byte 33,0
 .globl l0320
l0320:
 .long 0
 .byte 34,0
 .globl l0321
l0321:
 .long 0
 .byte 35,0
 .globl l0322
l0322:
 .long 0
 .byte 36,0
 .globl l0323
l0323:
 .long 0
 .byte 37,0
 .globl l0324
l0324:
 .long 0
 .byte 38,0
 .globl l0325
l0325:
 .long 0
 .byte 39,0
 .globl l0326
l0326:
 .long 0
 .byte 40,0
 .globl l0327
l0327:
 .long 0
 .byte 41,0
 .globl l0328
l0328:
 .long 0
 .byte 42,0
 .globl l0329
l0329:
 .long 0
 .byte 43,0
 .globl l0330
l0330:
 .long 0
 .byte 44,0
 .globl l0331
l0331:
 .long 0
 .byte 45,0
 .globl l0332
l0332:
 .long 0
 .byte 46,0
 .globl l0333
l0333:
 .long 0
 .byte 47,0
 .globl l0334
l0334:
 .long 0
 .byte 48,0
 .globl l0335
l0335:
 .long 0
 .byte 49,0
 .globl l0336
l0336:
 .long 0
 .byte 50,0
 .globl l0337
l0337:
 .long 0
 .byte 51,0
 .globl l0338
l0338:
 .long 0
 .byte 52,0
 .globl l0339
l0339:
 .long 0
 .byte 53,0
 .globl l0340
l0340:
 .long 0
 .byte 54,0
 .globl l0341
l0341:
 .long 0
 .byte 55,0
 .globl l0342
l0342:
 .long 0
 .byte 56,0
 .globl l0343
l0343:
 .long 0
 .byte 57,0
 .globl l0344
l0344:
 .long 0
 .byte 58,0
 .globl l0345
l0345:
 .long 0
 .byte 59,0
 .globl l0346
l0346:
 .long 0
 .byte 60,0
 .globl l0347
l0347:
 .long 0
 .byte 61,0
 .globl l0348
l0348:
 .long 0
 .byte 62,0
 .globl l0349
l0349:
 .long 0
 .byte 63,0
 .globl l0350
l0350:
 .long 0
 .byte 64,0
 .globl l0351
l0351:
 .long 0
 .byte 65,0
 .globl l0352
l0352:
 .long 0
 .byte 66,0
 .globl l0353
l0353:
 .long 0
 .byte 67,0
 .globl l0354
l0354:
 .long 0
 .byte 68,0
 .globl l0355
l0355:
 .long 0
 .byte 69,0
 .globl l0356
l0356:
 .long 0
 .byte 70,0
 .globl l0357
l0357:
 .long 0
 .byte 71,0
 .globl l0358
l0358:
 .long 0
 .byte 72,0
 .globl l0359
l0359:
 .long 0
 .byte 73,0
 .globl l0360
l0360:
 .long 0
 .byte 74,0
 .globl l0361
l0361:
 .long 0
 .byte 75,0
 .globl l0362
l0362:
 .long 0
 .byte 76,0
 .globl l0363
l0363:
 .long 0
 .byte 77,0
 .globl l0364
l0364:
 .long 0
 .byte 78,0
 .globl l0365
l0365:
 .long 0
 .byte 79,0
 .globl l0366
l0366:
 .long 0
 .byte 80,0
 .globl l0367
l0367:
 .long 0
 .byte 81,0
 .globl l0368
l0368:
 .long 0
 .byte 82,0
 .globl l0369
l0369:
 .long 0
 .byte 83,0
 .globl l0370
l0370:
 .long 0
 .byte 84,0
 .globl l0371
l0371:
 .long 0
 .byte 85,0
 .globl l0372
l0372:
 .long 0
 .byte 86,0
 .globl l0373
l0373:
 .long 0
 .byte 87,0
 .globl l0374
l0374:
 .long 0
 .byte 88,0
 .globl l0375
l0375:
 .long 0
 .byte 89,0
 .globl l0376
l0376:
 .long 0
 .byte 90,0
 .globl l0377
l0377:
 .long 0
 .byte 91,0
 .globl l0378
l0378:
 .long 0
 .byte 92,0
 .globl l0379
l0379:
 .long 0
 .byte 93,0
 .globl l0380
l0380:
 .long 0
 .byte 94,0
 .globl l0381
l0381:
 .long 0
 .byte 95,0
 .globl l0382
l0382:
 .long 0
 .byte 96,0
 .globl l0383
l0383:
 .long 0
 .byte 97,0
 .globl l0384
l0384:
 .long 0
 .byte 98,0
 .globl l0385
l0385:
 .long 0
 .byte 99,0
 .globl l0386
l0386:
 .long 0
 .byte 100,0
 .globl l0387
l0387:
 .long 0
 .byte 101,0
 .globl l0388
l0388:
 .long 0
 .byte 102,0
 .globl l0389
l0389:
 .long 0
 .byte 103,0
 .globl l0390
l0390:
 .long 0
 .byte 104,0
 .globl l0391
l0391:
 .long 0
 .byte 105,0
 .globl l0392
l0392:
 .long 0
 .byte 106,0
 .globl l0393
l0393:
 .long 0
 .byte 107,0
 .globl l0394
l0394:
 .long 0
 .byte 108,0
 .globl l0395
l0395:
 .long 0
 .byte 109,0
 .globl l0396
l0396:
 .long 0
 .byte 110,0
 .globl l0397
l0397:
 .long 0
 .byte 111,0
 .globl l0398
l0398:
 .long 0
 .byte 112,0
 .globl l0399
l0399:
 .long 0
 .byte 113,0
 .globl l0400
l0400:
 .long 0
 .byte 114,0
 .globl l0401
l0401:
 .long 0
 .byte 115,0
 .globl l0402
l0402:
 .long 0
 .byte 116,0
 .globl l0403
l0403:
 .long 0
 .byte 117,0
 .globl l0404
l0404:
 .long 0
 .byte 118,0
 .globl l0405
l0405:
 .long 0
 .byte 119,0
 .globl l0406
l0406:
 .long 0
 .byte 120,0
 .globl l0407
l0407:
 .long 0
 .byte 121,0
 .globl l0408
l0408:
 .long 0
 .byte 122,0
 .globl l0409
l0409:
 .long 0
 .byte 123,0
 .globl l0410
l0410:
 .long 0
 .byte 124,0
 .globl l0411
l0411:
 .long 0
 .byte 125,0
 .globl l0412
l0412:
 .long 0
 .byte 126,0
 .globl l0413
l0413:
 .long 0
 .byte 127,0
 .globl l0414
l0414:
 .long 2
 .byte 110,105,108,0
 .globl l0415
l0415:
 .long 0
 .byte -127,0
 .globl l0416
l0416:
 .long 0
 .byte -126,0
 .globl l0417
l0417:
 .long 0
 .byte -125,0
 .globl l0418
l0418:
 .long 0
 .byte -124,0
 .globl l0419
l0419:
 .long 0
 .byte -123,0
 .globl l0420
l0420:
 .long 0
 .byte -122,0
 .globl l0421
l0421:
 .long 0
 .byte -121,0
 .globl l0422
l0422:
 .long 0
 .byte -120,0
 .globl l0423
l0423:
 .long 0
 .byte -119,0
 .globl l0424
l0424:
 .long 0
 .byte -118,0
 .globl l0425
l0425:
 .long 0
 .byte -117,0
 .globl l0426
l0426:
 .long 0
 .byte -116,0
 .globl l0427
l0427:
 .long 0
 .byte -115,0
 .globl l0428
l0428:
 .long 0
 .byte -114,0
 .globl l0429
l0429:
 .long 0
 .byte -113,0
 .globl l0430
l0430:
 .long 0
 .byte -112,0
 .globl l0431
l0431:
 .long 0
 .byte -111,0
 .globl l0432
l0432:
 .long 0
 .byte -110,0
 .globl l0433
l0433:
 .long 0
 .byte -109,0
 .globl l0434
l0434:
 .long 0
 .byte -108,0
 .globl l0435
l0435:
 .long 0
 .byte -107,0
 .globl l0436
l0436:
 .long 0
 .byte -106,0
 .globl l0437
l0437:
 .long 0
 .byte -105,0
 .globl l0438
l0438:
 .long 0
 .byte -104,0
 .globl l0439
l0439:
 .long 0
 .byte -103,0
 .globl l0440
l0440:
 .long 0
 .byte -102,0
 .globl l0441
l0441:
 .long 0
 .byte -101,0
 .globl l0442
l0442:
 .long 0
 .byte -100,0
 .globl l0443
l0443:
 .long 0
 .byte -99,0
 .globl l0444
l0444:
 .long 0
 .byte -98,0
 .globl l0445
l0445:
 .long 0
 .byte -97,0
 .globl l0446
l0446:
 .long 0
 .byte -96,0
 .globl l0447
l0447:
 .long 0
 .byte -95,0
 .globl l0448
l0448:
 .long 0
 .byte -94,0
 .globl l0449
l0449:
 .long 0
 .byte -93,0
 .globl l0450
l0450:
 .long 0
 .byte -92,0
 .globl l0451
l0451:
 .long 0
 .byte -91,0
 .globl l0452
l0452:
 .long 0
 .byte -90,0
 .globl l0453
l0453:
 .long 0
 .byte -89,0
 .globl l0454
l0454:
 .long 0
 .byte -88,0
 .globl l0455
l0455:
 .long 0
 .byte -87,0
 .globl l0456
l0456:
 .long 0
 .byte -86,0
 .globl l0457
l0457:
 .long 0
 .byte -85,0
 .globl l0458
l0458:
 .long 0
 .byte -84,0
 .globl l0459
l0459:
 .long 0
 .byte -83,0
 .globl l0460
l0460:
 .long 0
 .byte -82,0
 .globl l0461
l0461:
 .long 0
 .byte -81,0
 .globl l0462
l0462:
 .long 0
 .byte -80,0
 .globl l0463
l0463:
 .long 0
 .byte -79,0
 .globl l0464
l0464:
 .long 0
 .byte -78,0
 .globl l0465
l0465:
 .long 0
 .byte -77,0
 .globl l0466
l0466:
 .long 0
 .byte -76,0
 .globl l0467
l0467:
 .long 0
 .byte -75,0
 .globl l0468
l0468:
 .long 0
 .byte -74,0
 .globl l0469
l0469:
 .long 0
 .byte -73,0
 .globl l0470
l0470:
 .long 0
 .byte -72,0
 .globl l0471
l0471:
 .long 0
 .byte -71,0
 .globl l0472
l0472:
 .long 0
 .byte -70,0
 .globl l0473
l0473:
 .long 0
 .byte -69,0
 .globl l0474
l0474:
 .long 0
 .byte -68,0
 .globl l0475
l0475:
 .long 0
 .byte -67,0
 .globl l0476
l0476:
 .long 0
 .byte -66,0
 .globl l0477
l0477:
 .long 0
 .byte -65,0
 .globl l0478
l0478:
 .long 0
 .byte -64,0
 .globl l0479
l0479:
 .long 0
 .byte -63,0
 .globl l0480
l0480:
 .long 0
 .byte -62,0
 .globl l0481
l0481:
 .long 0
 .byte -61,0
 .globl l0482
l0482:
 .long 0
 .byte -60,0
 .globl l0483
l0483:
 .long 0
 .byte -59,0
 .globl l0484
l0484:
 .long 0
 .byte -58,0
 .globl l0485
l0485:
 .long 0
 .byte -57,0
 .globl l0486
l0486:
 .long 0
 .byte -56,0
 .globl l0487
l0487:
 .long 0
 .byte -55,0
 .globl l0488
l0488:
 .long 0
 .byte -54,0
 .globl l0489
l0489:
 .long 0
 .byte -53,0
 .globl l0490
l0490:
 .long 0
 .byte -52,0
 .globl l0491
l0491:
 .long 0
 .byte -51,0
 .globl l0492
l0492:
 .long 0
 .byte -50,0
 .globl l0493
l0493:
 .long 0
 .byte -49,0
 .globl l0494
l0494:
 .long 0
 .byte -48,0
 .globl l0495
l0495:
 .long 0
 .byte -47,0
 .globl l0496
l0496:
 .long 0
 .byte -46,0
 .globl l0497
l0497:
 .long 0
 .byte -45,0
 .globl l0498
l0498:
 .long 0
 .byte -44,0
 .globl l0499
l0499:
 .long 0
 .byte -43,0
 .globl l0500
l0500:
 .long 0
 .byte -42,0
 .globl l0501
l0501:
 .long 0
 .byte -41,0
 .globl l0502
l0502:
 .long 0
 .byte -40,0
 .globl l0503
l0503:
 .long 0
 .byte -39,0
 .globl l0504
l0504:
 .long 0
 .byte -38,0
 .globl l0505
l0505:
 .long 0
 .byte -37,0
 .globl l0506
l0506:
 .long 0
 .byte -36,0
 .globl l0507
l0507:
 .long 0
 .byte -35,0
 .globl l0508
l0508:
 .long 0
 .byte -34,0
 .globl l0509
l0509:
 .long 0
 .byte -33,0
 .globl l0510
l0510:
 .long 0
 .byte -32,0
 .globl l0511
l0511:
 .long 0
 .byte -31,0
 .globl l0512
l0512:
 .long 0
 .byte -30,0
 .globl l0513
l0513:
 .long 0
 .byte -29,0
 .globl l0514
l0514:
 .long 0
 .byte -28,0
 .globl l0515
l0515:
 .long 0
 .byte -27,0
 .globl l0516
l0516:
 .long 0
 .byte -26,0
 .globl l0517
l0517:
 .long 0
 .byte -25,0
 .globl l0518
l0518:
 .long 0
 .byte -24,0
 .globl l0519
l0519:
 .long 0
 .byte -23,0
 .globl l0520
l0520:
 .long 0
 .byte -22,0
 .globl l0521
l0521:
 .long 0
 .byte -21,0
 .globl l0522
l0522:
 .long 0
 .byte -20,0
 .globl l0523
l0523:
 .long 0
 .byte -19,0
 .globl l0524
l0524:
 .long 0
 .byte -18,0
 .globl l0525
l0525:
 .long 0
 .byte -17,0
 .globl l0526
l0526:
 .long 0
 .byte -16,0
 .globl l0527
l0527:
 .long 0
 .byte -15,0
 .globl l0528
l0528:
 .long 0
 .byte -14,0
 .globl l0529
l0529:
 .long 0
 .byte -13,0
 .globl l0530
l0530:
 .long 0
 .byte -12,0
 .globl l0531
l0531:
 .long 0
 .byte -11,0
 .globl l0532
l0532:
 .long 0
 .byte -10,0
 .globl l0533
l0533:
 .long 0
 .byte -9,0
 .globl l0534
l0534:
 .long 0
 .byte -8,0
 .globl l0535
l0535:
 .long 0
 .byte -7,0
 .globl l0536
l0536:
 .long 0
 .byte -6,0
 .globl l0537
l0537:
 .long 0
 .byte -5,0
 .globl l0538
l0538:
 .long 0
 .byte -4,0
 .globl l0539
l0539:
 .long 0
 .byte -3,0
 .globl l0540
l0540:
 .long 0
 .byte -2,0
 .globl l0541
l0541:
 .long 0
 .byte -1,0
 .globl l0542
l0542:
 .long 10
 .byte 102,105,114,115,116,107,101,114,110
 .byte 101,108,0
 .globl l0543
l0543:
 .long 12
 .byte 97,114,103,117,109,101,110,116,98,108
 .byte 111,99,107,0
 .globl l0544
l0544:
 .long 10
 .byte 116,111,107,101,110,98,117,102,102
 .byte 101,114,0
 .globl l0545
l0545:
 .long 5
 .byte 98,110,100,115,116,107,0,0
 .globl l0546
l0546:
 .long 9
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 0,0
 .globl l0547
l0547:
 .long 8
 .byte 104,97,115,104,116,97,98,108,101,0
 .globl l0548
l0548:
 .long 12
 .byte 111,110,101,119,111,114,100,98,117
 .byte 102,102,101,114,0
 .globl l0549
l0549:
 .long 7
 .byte 115,97,118,101,97,114,103,99,0,0
 .globl l0550
l0550:
 .long 7
 .byte 115,97,118,101,97,114,103,118,0,0
 .globl l0551
l0551:
 .long 9
 .byte 100,97,116,101,98,117,102,102,101,114
 .byte 0,0
 .globl l0552
l0552:
 .long 12
 .byte 105,110,105,116,45,112,111,105,110
 .byte 116,101,114,115,0
 .globl l0553
l0553:
 .long 12
 .byte 112,115,108,95,99,97,108,108,98,97
 .byte 99,107,49,0
 .globl l0554
l0554:
 .long 12
 .byte 112,115,108,95,99,97,108,108,98,97
 .byte 99,107,50,0
 .globl l0555
l0555:
 .long 12
 .byte 112,115,108,95,99,97,108,108,98,97
 .byte 99,107,51,0
 .globl l0556
l0556:
 .long 12
 .byte 112,115,108,95,99,97,108,108,98,97
 .byte 99,107,52,0
 .globl l0557
l0557:
 .long 4
 .byte 115,116,97,99,107,0
 .globl l0558
l0558:
 .long 14
 .byte 115,116,97,99,107,117,112,112,101,114
 .byte 98,111,117,110,100,0
 .globl l0559
l0559:
 .long 12
 .byte 99,97,116,99,104,115,116,97,99,107
 .byte 112,116,114,0
 .globl l0560
l0560:
 .long 15
 .byte 98,110,100,115,116,107,108,111,119
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0561
l0561:
 .long 15
 .byte 98,110,100,115,116,107,117,112,112
 .byte 101,114,98,111,117,110,100,0,0
 .globl l0562
l0562:
 .long 8
 .byte 98,110,100,115,116,107,112,116,114
 .byte 0
 .globl l0563
l0563:
 .long 13
 .byte 104,101,97,112,108,111,119,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0564
l0564:
 .long 3
 .byte 104,101,97,112,0,0
 .globl l0565
l0565:
 .long 10
 .byte 105,110,105,116,45,102,108,117,105
 .byte 100,115,0
 .globl l0566
l0566:
 .long 16
 .byte 103,99,97,114,114,97,121,108,111,119
 .byte 101,114,98,111,117,110,100,0
 .globl l0567
l0567:
 .long 16
 .byte 103,99,97,114,114,97,121,117,112,112
 .byte 101,114,98,111,117,110,100,0
 .globl l0568
l0568:
 .long 7
 .byte 104,101,97,112,108,97,115,116,0,0
 .globl l0569
l0569:
 .long 12
 .byte 104,101,97,112,116,114,97,112,98,111
 .byte 117,110,100,0
 .globl l0570
l0570:
 .long 13
 .byte 104,101,97,112,117,112,112,101,114
 .byte 98,111,117,110,100,0,0
 .globl l0571
l0571:
 .long 13
 .byte 95,105,110,102,98,105,116,108,101,110
 .byte 103,116,104,95,0,0
 .globl l0572
l0572:
 .long 6
 .byte 108,97,115,116,98,112,115,0
 .globl l0573
l0573:
 .long 12
 .byte 98,112,115,108,111,119,101,114,98,111
 .byte 117,110,100,0
 .globl l0574
l0574:
 .long 10
 .byte 111,108,100,104,101,97,112,108,97,115
 .byte 116,0
 .globl l0575
l0575:
 .long 16
 .byte 111,108,100,104,101,97,112,108,111
 .byte 119,101,114,98,111,117,110,100,0
 .globl l0576
l0576:
 .long 15
 .byte 111,108,100,104,101,97,112,116,114
 .byte 97,112,98,111,117,110,100,0,0
 .globl l0577
l0577:
 .long 16
 .byte 111,108,100,104,101,97,112,117,112
 .byte 112,101,114,98,111,117,110,100,0
 .globl l0578
l0578:
 .long 18
 .byte 109,97,105,110,115,116,97,114,116,105
 .byte 110,105,116,105,97,108,105,122,101
 .byte 0
 .globl l0579
l0579:
 .long 6
 .byte 110,101,120,116,98,112,115,0
 .globl l0580
l0580:
 .long 8
 .byte 117,110,105,120,115,116,100,105,110
 .byte 0
 .globl l0581
l0581:
 .long 9
 .byte 117,110,105,120,115,116,100,111,117
 .byte 116,0,0
 .globl l0582
l0582:
 .long 9
 .byte 117,110,105,120,115,116,100,101,114
 .byte 114,0,0
 .globl l0583
l0583:
 .long 7
 .byte 117,110,105,120,110,117,108,108,0,0
 .globl l0584
l0584:
 .long 6
 .byte 117,110,105,120,101,111,102,0
 .globl l0585
l0585:
 .long 6
 .byte 117,110,105,120,116,116,121,0
 .globl l0586
l0586:
 .long 16
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,42,42,42,0
 .globl l0587
l0587:
 .long 20
 .byte 42,42,42,109,117,115,116,45,98,101
 .byte 45,110,105,108,45,116,111,111,42,42
 .byte 42,0
 .globl l0588
l0588:
 .long 7
 .byte 42,102,97,115,116,99,97,114,0,0
 .globl l0589
l0589:
 .long 8
 .byte 42,42,119,105,110,100,111,119,115,0
 .globl l0590
l0590:
 .long 13
 .byte 38,38,105,110,105,116,45,116,97,98
 .byte 108,101,115,49,0,0
 .globl l0591
l0591:
 .long 10
 .byte 98,114,117,99,104,95,98,114,117,99
 .byte 104,0
 .globl l0592
l0592:
 .long 9
 .byte 110,101,120,116,115,121,109,98,111
 .byte 108,0,0
 .globl l0593
l0593:
 .long 16
 .byte 107,101,114,110,101,108,45,109,97,120
 .byte 115,121,109,98,111,108,115,0
 .globl l0594
l0594:
 .long 5
 .byte 115,121,109,118,97,108,0,0
 .globl l0595
l0595:
 .long 9
 .byte 111,108,100,95,115,121,109,118,97,108
 .byte 0,0
 .globl l0596
l0596:
 .long 5
 .byte 115,121,109,102,110,99,0,0
 .globl l0597
l0597:
 .long 9
 .byte 111,108,100,95,115,121,109,102,110
 .byte 99,0,0
 .globl l0598
l0598:
 .long 5
 .byte 115,121,109,112,114,112,0,0
 .globl l0599
l0599:
 .long 9
 .byte 111,108,100,95,115,121,109,112,114
 .byte 112,0,0
 .globl l0600
l0600:
 .long 5
 .byte 115,121,109,103,101,116,0,0
 .globl l0601
l0601:
 .long 9
 .byte 111,108,100,95,115,121,109,103,101
 .byte 116,0,0
 .globl l0602
l0602:
 .long 4
 .byte 115,121,109,109,115,0
 .globl l0603
l0603:
 .long 8
 .byte 38,38,115,121,109,99,111,112,121,0
 .globl l0604
l0604:
 .long 11
 .byte 105,110,105,116,45,103,99,97,114,114
 .byte 97,121,0,0
 .globl l0605
l0605:
 .long 13
 .byte 38,38,105,110,105,116,45,116,97,98
 .byte 108,101,115,50,0,0
 .globl l0606
l0606:
 .long 14
 .byte 111,115,95,115,116,97,114,116,117,112
 .byte 95,104,111,111,107,0
 .globl l0607
l0607:
 .long 12
 .byte 38,116,105,109,101,45,99,111,110,116
 .byte 114,111,108,0
 .globl l0608
l0608:
 .long 7
 .byte 112,114,101,45,109,97,105,110,0,0
 .globl l0609
l0609:
 .long 15
 .byte 101,120,105,116,45,119,105,116,104
 .byte 45,115,116,97,116,117,115,0,0
 .globl l0610
l0610:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,101
 .byte 120,105,116,0
 .globl l0611
l0611:
 .long 8
 .byte 95,112,115,108,95,109,97,105,110,0
 .globl l0612
l0612:
 .long 14
 .byte 115,116,97,99,107,108,111,119,101,114
 .byte 98,111,117,110,100,0
 .globl l0613
l0613:
 .long 3
 .byte 97,114,103,99,0,0
 .globl l0614
l0614:
 .long 3
 .byte 97,114,103,118,0,0
 .globl l0615
l0615:
 .long 8
 .byte 112,115,108,95,99,97,108,108,49,0
 .globl l0616
l0616:
 .long 8
 .byte 95,112,115,108,95,99,97,108,108,0
 .globl l0617
l0617:
 .long 10
 .byte 117,110,105,120,99,108,101,97,114,105
 .byte 111,0
 .globl l0618
l0618:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,115,116,114,105,110
 .byte 103,0,0
 .globl l0619
l0619:
 .long 7
 .byte 117,110,105,120,112,117,116,110,0,0
 .globl l0620
l0620:
 .long 14
 .byte 99,111,110,115,111,108,101,45,110,101
 .byte 119,108,105,110,101,0
 .globl l0621
l0621:
 .long 22
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,115,121,109,98,111,108,45,116
 .byte 97,98,108,101,0
 .globl l0622
l0622:
 .long 7
 .byte 105,110,105,116,99,111,100,101,0,0
 .globl l0623
l0623:
 .long 5
 .byte 102,97,115,108,105,110,0,0
 .globl l0624
l0624:
 .long 10
 .byte 108,111,97,100,101,114,45,109,97,105
 .byte 110,0
 .globl l0625
l0625:
 .long 5
 .byte 115,121,109,110,97,109,0,0
 .globl l0626
l0626:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,114,108,101,110,0
 .globl l0627
l0627:
 .long 5
 .byte 32,121,105,101,108,100,0,0
 .globl l0628
l0628:
 .long 7
 .byte 117,110,105,120,112,117,116,115,0,0
 .globl l0629
l0629:
 .long 19
 .byte 99,111,110,115,111,108,101,45,112,114
 .byte 105,110,116,45,110,117,109,98,101,114
 .byte 0,0
 .globl l0630
l0630:
 .long 7
 .byte 117,110,105,120,112,117,116,99,0,0
 .globl l0631
l0631:
 .long 7
 .byte 117,110,105,120,111,112,101,110,0,0
 .globl l0632
l0632:
 .long 17
 .byte 107,101,114,110,101,108,45,102,97,116
 .byte 97,108,45,101,114,114,111,114,0,0
 .globl l0633
l0633:
 .long 13
 .byte 98,105,110,97,114,121,111,112,101,110
 .byte 114,101,97,100,0,0
 .globl l0634
l0634:
 .long 3
 .byte 103,101,116,119,0,0
 .globl l0635
l0635:
 .long 9
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 0,0
 .globl l0636
l0636:
 .long 4
 .byte 102,114,101,97,100,0
 .globl l0637
l0637:
 .long 14
 .byte 98,105,110,97,114,121,114,101,97,100
 .byte 98,108,111,99,107,0
 .globl l0638
l0638:
 .long 5
 .byte 102,99,108,111,115,101,0,0
 .globl l0639
l0639:
 .long 10
 .byte 98,105,110,97,114,121,99,108,111,115
 .byte 101,0
 .globl l0640
l0640:
 .long 14
 .byte 104,97,115,104,45,105,110,116,111,45
 .byte 116,97,98,108,101,0
 .globl l0641
l0641:
 .long 11
 .byte 115,104,111,119,45,110,101,119,45,105
 .byte 100,115,0,0
 .globl l0642
l0642:
 .long 26
 .byte 115,101,97,114,99,104,45,115,116,114
 .byte 105,110,103,45,102,111,114,45,99,104
 .byte 97,114,97,99,116,101,114,0
 .globl l0643
l0643:
 .long 5
 .byte 105,110,116,101,114,110,0,0
 .globl l0644
l0644:
 .long 5
 .byte 115,117,98,115,101,113,0,0
 .globl l0645
l0645:
 .long 12
 .byte 102,97,115,108,105,110,45,105,110,116
 .byte 101,114,110,0
 .globl l0646
l0646:
 .long 22
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,105,110
 .byte 116,101,114,110,0
 .globl l0647
l0647:
 .long 3
 .byte 103,116,105,100,0,0
 .globl l0648
l0648:
 .long 9
 .byte 103,116,99,111,110,115,116,115,116
 .byte 114,0,0
 .globl l0649
l0649:
 .long 15
 .byte 99,111,112,121,115,116,114,105,110
 .byte 103,116,111,102,114,111,109,0,0
 .globl l0650
l0650:
 .long 16
 .byte 105,110,105,116,105,97,108,105,122
 .byte 101,45,110,101,119,45,105,100,0
 .globl l0651
l0651:
 .long 12
 .byte 104,97,115,104,45,102,117,110,99,116
 .byte 105,111,110,0
 .globl l0652
l0652:
 .long 21
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,116,114,105,110,103,45,101,113
 .byte 117,97,108,0,0
 .globl l0653
l0653:
 .long 11
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,0,0
 .globl l0654
l0654:
 .long 14
 .byte 102,97,115,108,105,110,45,98,97,100
 .byte 45,102,105,108,101,0
 .globl l0655
l0655:
 .long 12
 .byte 114,101,97,100,45,105,100,45,116,97
 .byte 98,108,101,0
 .globl l0656
l0656:
 .long 4
 .byte 103,116,98,112,115,0
 .globl l0657
l0657:
 .long 5
 .byte 103,116,119,114,100,115,0,0
 .globl l0658
l0658:
 .long 16
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,45,110,101,119,0
 .globl l0659
l0659:
 .long 12
 .byte 100,111,45,114,101,108,111,99,97,116
 .byte 105,111,110,0
 .globl l0660
l0660:
 .long 12
 .byte 97,100,100,114,101,115,115,97,112,112
 .byte 108,121,48,0
 .globl l0661
l0661:
 .long 5
 .byte 100,101,108,98,112,115,0,0
 .globl l0662
l0662:
 .long 13
 .byte 99,111,100,101,45,98,97,115,101,45
 .byte 104,97,99,107,0,0
 .globl l0663
l0663:
 .long 12
 .byte 114,101,108,111,99,97,116,101,45,119
 .byte 111,114,100,0
 .globl l0664
l0664:
 .long 11
 .byte 114,101,108,111,99,97,116,101,45,105
 .byte 110,102,0,0
 .globl l0665
l0665:
 .long 18
 .byte 114,101,108,111,99,97,116,101,45,114
 .byte 105,103,104,116,45,104,97,108,102,0
 .globl l0666
l0666:
 .long 17
 .byte 99,111,109,112,117,116,101,45,114,101
 .byte 108,111,99,97,116,105,111,110,0,0
 .globl l0667
l0667:
 .long 17
 .byte 108,111,99,97,108,45,116,111,45,103
 .byte 108,111,98,97,108,45,105,100,0,0
 .globl l0668
l0668:
 .long 17
 .byte 114,101,108,111,99,97,116,101,45,102
 .byte 97,115,116,45,99,97,108,108,0,0
 .globl l0669
l0669:
 .long 3
 .byte 112,117,116,100,0,0
 .globl l0670
l0670:
 .long 7
 .byte 112,117,116,101,110,116,114,121,0,0
 .globl l0671
l0671:
 .long 14
 .byte 103,116,98,112,115,45,110,105,108,45
 .byte 101,114,114,111,114,0
 .globl l0672
l0672:
 .long 19
 .byte 116,114,121,45,111,116,104,101,114
 .byte 45,98,112,115,45,115,112,97,99,101
 .byte 115,0,0
 .globl l0673
l0673:
 .long 3
 .byte 103,101,116,100,0,0
 .globl l0674
l0674:
 .long 7
 .byte 115,116,100,101,114,114,111,114,0,0
 .globl l0675
l0675:
 .long 15
 .byte 107,110,111,119,110,45,102,114,101
 .byte 101,45,115,112,97,99,101,0,0
 .globl l0676
l0676:
 .long 10
 .byte 114,101,97,108,45,103,116,104,101,97
 .byte 112,0
 .globl l0677
l0677:
 .long 5
 .byte 103,116,104,101,97,112,0,0
 .globl l0678
l0678:
 .long 12
 .byte 103,101,116,45,104,101,97,112,45,116
 .byte 114,97,112,0
 .globl l0679
l0679:
 .long 6
 .byte 114,101,99,108,97,105,109,0
 .globl l0680
l0680:
 .long 4
 .byte 103,116,115,116,114,0
 .globl l0681
l0681:
 .long 3
 .byte 99,111,110,115,0,0
 .globl l0682
l0682:
 .long 10
 .byte 105,110,116,101,114,114,111,103,97
 .byte 116,101,0
 .globl l0683
l0683:
 .long 5
 .byte 109,111,100,105,102,121,0,0
 .globl l0684
l0684:
 .long 12
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,117,116,0
 .globl l0685
l0685:
 .long 2
 .byte 112,117,116,0
 .globl l0686
l0686:
 .long 13
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 112,114,111,112,0,0
 .globl l0687
l0687:
 .long 4
 .byte 97,116,115,111,99,0
 .globl l0688
l0688:
 .long 16
 .byte 117,110,99,104,101,99,107,101,100,45
 .byte 115,101,116,112,114,111,112,0
 .globl l0689
l0689:
 .long 8
 .byte 99,111,100,101,45,112,117,116,100,0
 .globl l0690
l0690:
 .long 15
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,0,0
 .globl l0691
l0691:
 .long 3
 .byte 101,120,112,114,0,0
 .globl l0692
l0692:
 .long 3
 .byte 116,121,112,101,0,0
 .globl l0693
l0693:
 .long 5
 .byte 102,108,117,105,100,49,0,0
 .globl l0694
l0694:
 .long 4
 .byte 102,108,117,105,100,0
 .globl l0695
l0695:
 .long 6
 .byte 118,97,114,116,121,112,101,0
 .globl l0696
l0696:
 .long 8
 .byte 99,111,110,115,116,97,110,116,63,0
 .globl l0697
l0697:
 .long 15
 .byte 42,100,101,102,105,110,101,45,99,111
 .byte 110,115,116,97,110,116,0,0
 .globl l0698
l0698:
 .long 17
 .byte 116,101,114,109,105,110,97,108,45,105
 .byte 110,116,101,114,114,117,112,116,0,0
 .globl l0699
l0699:
 .long 6
 .byte 119,104,97,116,115,117,112,0
 .globl l0700
l0700:
 .long 5
 .byte 103,101,116,112,105,100,0,0
 .globl l0701
l0701:
 .long 5
 .byte 101,99,104,111,111,110,0,0
 .globl l0702
l0702:
 .long 6
 .byte 101,99,104,111,111,102,102,0
 .globl l0703
l0703:
 .long 26
 .byte 101,120,116,101,114,110,97,108,95,99
 .byte 104,97,114,115,105,110,105,110,112
 .byte 117,116,98,117,102,102,101,114,0
 .globl l0704
l0704:
 .long 19
 .byte 102,108,117,115,104,115,116,100,111
 .byte 117,116,112,117,116,98,117,102,102
 .byte 101,114,0,0
 .globl l0705
l0705:
 .long 27
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 115,101,114,95,104,111,109,101,100
 .byte 105,114,95,115,116,114,105,110,103
 .byte 0,0
 .globl l0706
l0706:
 .long 12
 .byte 97,108,116,101,114,104,101,97,112,115
 .byte 105,122,101,0
 .globl l0707
l0707:
 .long 14
 .byte 97,108,108,111,99,97,116,101,109,111
 .byte 114,101,98,112,115,0
 .globl l0708
l0708:
 .long 16
 .byte 103,101,116,95,105,109,97,103,101,102
 .byte 105,108,101,112,97,116,104,0
 .globl l0709
l0709:
 .long 14
 .byte 103,101,116,95,102,105,108,101,95,115
 .byte 116,97,116,117,115,0
 .globl l0710
l0710:
 .long 14
 .byte 111,115,95,99,108,101,97,110,117,112
 .byte 95,104,111,111,107,0
 .globl l0711
l0711:
 .long 15
 .byte 103,101,116,95,101,120,101,99,102,105
 .byte 108,101,112,97,116,104,0,0
 .globl l0712
l0712:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,97
 .byte 108,97,114,109,0,0
 .globl l0713
l0713:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 97,108,97,114,109,0
 .globl l0714
l0714:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,101,0
 .globl l0715
l0715:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,116
 .byte 105,109,99,0
 .globl l0716
l0716:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 116,97,116,0
 .globl l0717
l0717:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,109
 .byte 107,100,105,114,0,0
 .globl l0718
l0718:
 .long 13
 .byte 101,120,116,101,114,110,97,108,95,114
 .byte 109,100,105,114,0,0
 .globl l0719
l0719:
 .long 12
 .byte 101,120,116,101,114,110,97,108,95,108
 .byte 105,110,107,0
 .globl l0720
l0720:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,117
 .byte 110,108,105,110,107,0
 .globl l0721
l0721:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 101,116,101,110,118,0
 .globl l0722
l0722:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,103
 .byte 101,116,101,110,118,0
 .globl l0723
l0723:
 .long 6
 .byte 117,120,102,108,111,97,116,0
 .globl l0724
l0724:
 .long 4
 .byte 117,120,102,105,120,0
 .globl l0725
l0725:
 .long 7
 .byte 117,120,97,115,115,105,103,110,0,0
 .globl l0726
l0726:
 .long 6
 .byte 117,120,112,108,117,115,50,0
 .globl l0727
l0727:
 .long 11
 .byte 117,120,100,105,102,102,101,114,101
 .byte 110,99,101,0,0
 .globl l0728
l0728:
 .long 7
 .byte 117,120,116,105,109,101,115,50,0,0
 .globl l0729
l0729:
 .long 9
 .byte 117,120,113,117,111,116,105,101,110
 .byte 116,0,0
 .globl l0730
l0730:
 .long 9
 .byte 117,120,103,114,101,97,116,101,114
 .byte 112,0,0
 .globl l0731
l0731:
 .long 6
 .byte 117,120,108,101,115,115,112,0
 .globl l0732
l0732:
 .long 11
 .byte 117,120,119,114,105,116,101,102,108
 .byte 111,97,116,0,0
 .globl l0733
l0733:
 .long 15
 .byte 117,117,120,100,111,117,98,108,101
 .byte 116,111,102,108,111,97,116,0,0
 .globl l0734
l0734:
 .long 15
 .byte 117,117,120,102,108,111,97,116,116
 .byte 111,100,111,117,98,108,101,0,0
 .globl l0735
l0735:
 .long 5
 .byte 117,117,120,115,105,110,0,0
 .globl l0736
l0736:
 .long 5
 .byte 117,117,120,99,111,115,0,0
 .globl l0737
l0737:
 .long 5
 .byte 117,117,120,116,97,110,0,0
 .globl l0738
l0738:
 .long 6
 .byte 117,117,120,97,115,105,110,0
 .globl l0739
l0739:
 .long 6
 .byte 117,117,120,97,99,111,115,0
 .globl l0740
l0740:
 .long 6
 .byte 117,117,120,97,116,97,110,0
 .globl l0741
l0741:
 .long 6
 .byte 117,117,120,115,113,114,116,0
 .globl l0742
l0742:
 .long 5
 .byte 117,117,120,101,120,112,0,0
 .globl l0743
l0743:
 .long 5
 .byte 117,117,120,108,111,103,0,0
 .globl l0744
l0744:
 .long 7
 .byte 117,117,120,97,116,97,110,50,0,0
 .globl l0745
l0745:
 .long 17
 .byte 103,101,116,95,114,101,103,105,115
 .byte 116,114,121,95,118,97,108,117,101,0
 .byte 0
 .globl l0746
l0746:
 .long 11
 .byte 101,120,116,101,114,110,97,108,95,112
 .byte 119,100,0,0
 .globl l0747
l0747:
 .long 10
 .byte 115,117,110,51,95,115,105,103,115,101
 .byte 116,0
 .globl l0748
l0748:
 .long 7
 .byte 115,105,103,114,101,108,115,101,0,0
 .globl l0749
l0749:
 .long 5
 .byte 117,110,101,120,101,99,0,0
 .globl l0750
l0750:
 .long 15
 .byte 101,120,112,97,110,100,95,102,105,108
 .byte 101,95,110,97,109,101,0,0
 .globl l0751
l0751:
 .long 5
 .byte 117,110,105,120,99,100,0,0
 .globl l0752
l0752:
 .long 8
 .byte 117,110,105,120,102,114,101,97,100
 .byte 0
 .globl l0753
l0753:
 .long 8
 .byte 117,110,105,120,102,112,117,116,99
 .byte 0
 .globl l0754
l0754:
 .long 8
 .byte 117,110,105,120,102,103,101,116,99
 .byte 0
 .globl l0755
l0755:
 .long 8
 .byte 117,110,105,120,102,103,101,116,115
 .byte 0
 .globl l0756
l0756:
 .long 9
 .byte 117,110,105,120,102,119,114,105,116
 .byte 101,0,0
 .globl l0757
l0757:
 .long 9
 .byte 117,110,105,120,102,102,108,117,115
 .byte 104,0,0
 .globl l0758
l0758:
 .long 4
 .byte 99,116,105,109,101,0
 .globl l0759
l0759:
 .long 14
 .byte 101,120,116,101,114,110,97,108,95,115
 .byte 121,115,116,101,109,0
 .globl l0760
l0760:
 .long 16
 .byte 101,120,116,101,114,110,97,108,95,102
 .byte 117,108,108,112,97,116,104,0
 .globl l0761
l0761:
 .long 4
 .byte 102,111,112,101,110,0
 .globl l0762
l0762:
 .long 4
 .byte 102,115,101,101,107,0
 .globl l0763
l0763:
 .long 7
 .byte 99,108,101,97,114,101,114,114,0,0
 .globl l0764
l0764:
 .long 3
 .byte 112,117,116,119,0,0
 .globl l0765
l0765:
 .long 5
 .byte 115,105,103,110,97,108,0,0
 .globl l0766
l0766:
 .long 4
 .byte 115,108,101,101,112,0
 .globl l0767
l0767:
 .long 11
 .byte 105,101,101,101,95,104,97,110,100,108
 .byte 101,114,0,0
 .globl l0768
l0768:
 .long 9
 .byte 105,101,101,101,95,102,108,97,103,115
 .byte 0,0
 .globl l0769
l0769:
 .long 9
 .byte 115,101,116,108,105,110,101,98,117
 .byte 102,0,0
 .globl l0770
l0770:
 .long 4
 .byte 112,111,112,101,110,0
 .globl l0771
l0771:
 .long 5
 .byte 112,99,108,111,115,101,0,0
 .globl l0772
l0772:
 .long 5
 .byte 112,114,111,102,105,108,0,0
 .globl l0773
l0773:
 .long 6
 .byte 100,97,116,101,116,97,103,0
 .globl l0774
l0774:
 .long 8
 .byte 112,115,108,108,95,99,97,108,108,0
 .globl l0775
l0775:
 .long 11
 .byte 117,110,105,120,45,112,114,111,102
 .byte 105,108,101,0,0
 .globl l0776
l0776:
 .long 4
 .byte 102,112,117,116,99,0
 .globl l0777
l0777:
 .long 4
 .byte 102,103,101,116,99,0
 .globl l0778
l0778:
 .long 4
 .byte 102,103,101,116,115,0
 .globl l0779
l0779:
 .long 5
 .byte 102,119,114,105,116,101,0,0
 .globl l0780
l0780:
 .long 5
 .byte 102,102,108,117,115,104,0,0
 .globl l0781
l0781:
 .long 13
 .byte 112,108,97,110,116,117,110,98,111,117
 .byte 110,100,45,49,0,0
 .globl l0782
l0782:
 .long 17
 .byte 112,108,97,110,116,99,111,100,101,112
 .byte 111,105,110,116,101,114,45,49,0,0
 .globl l0783
l0783:
 .long 16
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,45,49,0
 .globl l0784
l0784:
 .long 14
 .byte 112,108,97,110,116,108,97,109,98,100
 .byte 97,108,105,110,107,0
 .globl l0785
l0785:
 .long 7
 .byte 98,105,116,116,97,98,108,101,0,0
 .globl l0786
l0786:
 .long 16
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,0
 .globl l0787
l0787:
 .long 20
 .byte 117,110,100,101,102,105,110,101,100
 .byte 102,117,110,99,116,105,111,110,45,97
 .byte 117,120,0
 .globl l0788
l0788:
 .long 28
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,97,117
 .byte 120,0
 .globl l0789
l0789:
 .long 25
 .byte 99,111,109,112,105,108,101,100,99,97
 .byte 108,108,105,110,103,105,110,116,101
 .byte 114,112,114,101,116,101,100,0,0
 .globl l0790
l0790:
 .long 8
 .byte 99,111,100,101,102,111,114,109,42,0
 .globl l0791
l0791:
 .long 14
 .byte 103,101,116,102,99,111,100,101,112
 .byte 111,105,110,116,101,114,0
 .globl l0792
l0792:
 .long 9
 .byte 108,97,115,116,107,101,114,110,101
 .byte 108,0,0
 .globl l0793
l0793:
 .long 11
 .byte 99,111,100,101,97,100,100,114,101,115
 .byte 115,112,0,0
