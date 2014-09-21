        .386
_DATA    segment dword public 'DATA'
       include mhdr.asm 
   ALIGN 4
  INCLUDE S_VA_FN.ASM
_DATA    ends

_BSS     segment dword public 'BSS'
_BSS     ends

_TEXT    segment dword public 'CODE'
         assume  CS:_TEXT
         assume  DS:_DATA
 DD 1
; (*entry firstkernel expr 1)
 PUBLIC firstkernel
firstkernel:
 ret 
 DD 0
; (*entry init-pointers expr 0)
 PUBLIC l0001
l0001:
 mov ds:symval+1068,0
 mov ds:symval+1072,0
 mov ds:symval+1076,0
 mov ds:symval+1080,0
 mov eax,-20000
 add eax,symval+1084
 mov ds:symval+1088,eax
 mov edi,symval+1040
 mov ds:symval+1092,edi
 mov edi,symval+1036
 mov ds:symval+1096,edi
 mov ebx,7996
 add ebx,symval+1036
 mov ds:symval+1100,ebx
 mov edi,symval+1036
 mov ds:symval+1104,edi
 mov eax,symval+1108
 mov ds:symval+1112,eax
 ret 
 DD 0
; (*entry init-fluids expr 0)
 PUBLIC l0002
l0002:
 mov eax,30*08000000h+OFFSET 128
 mov ds:symval+1120,eax
 mov ds:symval+1124,eax
 mov ds:symval+1128,eax
 mov ds:symval+1132,eax
 mov ds:symval+1136,eax
 mov ds:symval+1140,eax
 mov ds:symval+1144,eax
 mov ds:symval+1148,eax
 mov ds:symval+1152,eax
 mov ds:symval+1156,eax
 mov ds:symval+1160,eax
 mov ds:symval+1164,eax
 mov ds:symval+1168,eax
 mov ds:symval+1172,eax
 mov ds:symval+1088,eax
 mov ds:symval+1176,eax
 mov ds:symval+1180,eax
 mov ds:symval+1184,eax
 mov ds:symval+1188,eax
 mov ds:symval+1192,eax
 mov ds:symval+1196,eax
 mov ds:symval+1200,eax
 mov ds:symval+1204,eax
 mov ds:symval+1208,eax
 mov ds:symval+1212,eax
 ret 
 DD 0
; (*entry &&init-tables1 expr 0)
 PUBLIC l0003
l0003:
 mov ds:symval+1220,0
 mov edi,symval+1224
 mov ds:symval+1228,edi
 mov edi,symval+1232
 mov ds:symval+1236,edi
 mov edi,symval+1240
 mov ds:symval+1244,edi
 mov edi,symval+1248
 mov ds:symval+1252,edi
 mov edi,symval+1256
 mov ds:symval+1232,edi
 mov eax,240000
 add eax,symval+1232
 mov ds:symval+1240,eax
 add eax,240000
 mov ds:symval+1248,eax
 ret 
 DD 0
; (*entry &&init-tables2 expr 0)
 PUBLIC l0004
l0004:
 mov  DWORD PTR [esp-36],eax
 sub esp,8
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 4[esp],edi
 mov DWORD PTR [esp],edi
 mov edi,30*08000000h+OFFSET 128
 cmp edi,symval+1168
 je l0005
 mov edi,symval+1136
 mov DWORD PTR [esp],edi
 mov edi,symval+1132
 mov  DWORD PTR 4[esp],edi
 mov ebx,symval+1244
 mov eax,symval+1240
 mov edi,315
 call [symfnc+1260]
 mov ebx,symval+1236
 mov eax,symval+1232
 mov edi,315
 call [symfnc+1260]
 mov edi, DWORD PTR 4[esp]
 mov ds:symval+1132,edi
 mov edi,DWORD PTR [esp]
 mov ds:symval+1136,edi
 mov edi,316
 call [symfnc+1264]
 mov eax,30*08000000h+OFFSET 128
 jmp l0006
l0005:
 mov ebx,symval+1240
 mov eax,symval+1244
 mov edi,315
 call [symfnc+1260]
 mov ebx,symval+1232
 mov eax,symval+1236
 mov edi,315
 call [symfnc+1260]
 mov ebx,symval+1248
 mov eax,symval+1252
 add esp,8
 mov edi,315
 jmp [symfnc+1260]
l0006:
 add esp,8
 ret 
 DD 2
; (*entry &&symcopy expr 2)
 PUBLIC l0007
l0007:
 mov  DWORD PTR [esp-32],eax
 push eax
 mov ebp,ebx
 mov ebx,symval+1228
 xor eax,eax
 mov edx,eax
 mov ecx,ebx
l0008:
 cmp edx,ecx
 jle l0009
 mov eax,30*08000000h+OFFSET 128
 jmp l0010
l0009:
 mov eax,edx
 shl eax,2
 add eax,ebp
 mov ebx,edx
 shl ebx,2
 add ebx,DWORD PTR [esp]
 mov edi,DWORD PTR [ebx]
 mov DWORD PTR [eax],edi
 inc edx
 jmp l0008
l0010:
 add esp,4
 ret 
 DD 0
; (*entry _psl_main expr 0)
 PUBLIC _psl_main
_psl_main:
 push ebp
 mov edi, DWORD PTR 16[esp]
 mov ds:symval+1256,edi
 mov eax, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov ds:symval+1296,esp
 mov ds:symval+1300,eax
 mov ds:symval+1304,ebx
 push eax
 push ebx
 mov ds:symval+1140,27
 mov ds:symval+1168,30*08000000h+OFFSET 128
 mov edi,304
 call [symfnc+1216]
 pop ebx
 pop eax
 mov edi,318
 call [symfnc+1272]
 mov edi,317
 call [symfnc+1268]
 mov edi,266
 call [symfnc+1064]
 xor eax,eax
 dec eax
 mov edi,319
 call [symfnc+1276]
 mov eax, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov ds:symval+1300,eax
 mov ds:symval+1304,ebx
 mov edi,320
 call [symfnc+1280]
l0011:
 xor eax,eax
 mov edi,321
 jmp [symfnc+1284]
 pop ebp
 ret 
; (*entry exit-with-status expr 1)
 PUBLIC l0012
l0012:
 mov edi,322
 call [symfnc+1288]
 ret 
 DD 4
; (*entry _psl_call expr 4)
 PUBLIC _psl_call
_psl_call:
 push ebp
 mov eax, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov ecx, DWORD PTR 16[esp]
 mov edx, DWORD PTR 20[esp]
 mov edi,327
 call [symfnc+1308]
 pop ebp
 ret 
 DD 4
; (*entry psl_call1 expr 4)
 PUBLIC l0013
l0013:
 mov eax,30*08000000h+OFFSET 128
 ret 
 DD 1
; (*entry &time-control expr 1)
 PUBLIC l0014
l0014:
 mov eax,30*08000000h+OFFSET 128
 ret 
l0015:
 DD 21
 DB 65,98,111,117,116,32,116,111,32,108,111
 DB 97,100,32,76,79,65,68,45,80,83,76,0,0
l0016:
 DD 9
 DB 108,111,97,100,45,112,115,108,46,98,0
 DB 0
 DD 0
; (*entry pre-main expr 0)
 PUBLIC l0017
l0017:
 mov edi,329
 call [symfnc+1316]
 mov edi,330
 call [symfnc+1320]
 mov eax,4*08000000h+OFFSET l0015
 mov edi,331
 call [symfnc+1324]
 mov edi,332
 call [symfnc+1328]
 mov eax,4*08000000h+OFFSET l0016
 mov edi,333
 call [symfnc+1332]
 mov edi,334
 jmp [symfnc+1336]
 DD 1
; (*entry external_strlen expr 1)
 PUBLIC external_strlen
external_strlen:
 mov  DWORD PTR [esp-32],eax
 push 0
 push eax
l0018:
 mov ebx, DWORD PTR 4[esp]
 mov eax,DWORD PTR [esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 cmp eax,0
 jne l0019
 mov eax, DWORD PTR 4[esp]
 jmp l0020
l0019:
 inc  DWORD PTR 4[esp]
 jmp l0018
l0020:
 add esp,8
 ret 
 DD 0
; (*entry ! yield expr 0)
 PUBLIC l0021
l0021:
 mov eax,30*08000000h+OFFSET 128
 ret 
 DD 1
; (*entry console-print-string expr 1)
 PUBLIC l0022
l0022:
 and eax,134217727
 add eax,4
 mov edi,337
 jmp [symfnc+1348]
 DD 1
; (*entry console-print-number expr 1)
 PUBLIC l0023
l0023:
 mov edi,338
 jmp [symfnc+1352]
 DD 0
; (*entry console-newline expr 0)
 PUBLIC l0024
l0024:
 mov eax,10
 mov edi,340
 jmp [symfnc+1360]
l0025:
 DD 1
 DB 114,98,0,0
l0026:
 DD 34
 DB 67,111,117,108,100,110,39,116,32,111,112
 DB 101,110,32,98,105,110,97,114,121,32,102
 DB 105,108,101,32,102,111,114,32,105,110
 DB 112,117,116,0
 DD 1
; (*entry binaryopenread expr 1)
 PUBLIC binaryopenread
binaryopenread:
 mov ebx,4*08000000h+OFFSET l0025
 and ebx,134217727
 add ebx,4
 and eax,134217727
 add eax,4
 mov edi,341
 call [symfnc+1364]
 cmp eax,0
 jne l0027
 mov eax,4*08000000h+OFFSET l0026
 mov edi,342
 jmp [symfnc+1368]
l0027:
 ret 
 DD 1
; (*entry binaryread expr 1)
 PUBLIC binaryread
binaryread:
 mov edi,344
 jmp [symfnc+1376]
 DD 3
; (*entry binaryreadblock expr 3)
 PUBLIC binaryreadblock
binaryreadblock:
 mov ebp,ebx
 mov edx,eax
 mov ebx,4
 mov eax,ebp
 mov edi,346
 jmp [symfnc+1384]
 DD 1
; (*entry binaryclose expr 1)
 PUBLIC binaryclose
binaryclose:
 mov edi,348
 jmp [symfnc+1392]
 DD 0
; (*entry initialize-symbol-table expr 0)
 PUBLIC l0028
l0028:
 mov  DWORD PTR [esp-36],eax
 sub esp,8
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 4[esp],edi
 mov DWORD PTR [esp],edi
 mov ebx,60000
 mov eax,symval+1224
 mov edx,eax
 mov ecx,ebx
l0029:
 cmp edx,ecx
 jg l0030
 mov eax,edx
 shl eax,2
 add eax,symval+1404
 xor ebx,ebx
 inc ebx
 add ebx,edx
 mov DWORD PTR [eax],ebx
 inc edx
 jmp l0029
l0030:
 mov esi,symval+1404
 mov  DWORD PTR 240000[esi],0
 mov ebx,68023
 xor eax,eax
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
l0031:
 mov edi,DWORD PTR [esp]
 cmp edi, DWORD PTR 4[esp]
 jg l0032
 xor ecx,ecx
 mov ebx,DWORD PTR [esp]
 mov eax,symval+1044
 shl ebx,1
 mov 0[ebx][eax*1],cx
 inc DWORD PTR [esp]
 jmp l0031
l0032:
 mov edi,symval+1404
 mov eax, DWORD PTR 512[edi]
 mov edi,350
 call [symfnc+1400]
 mov ecx,128
 mov ebx,eax
 mov eax,symval+1044
 shl ebx,1
 mov 0[ebx][eax*1],cx
 xor ebx,ebx
 dec ebx
 add ebx,symval+1224
 mov eax,256
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
l0033:
 mov edi,DWORD PTR [esp]
 cmp edi, DWORD PTR 4[esp]
 jg l0034
 mov eax,DWORD PTR [esp]
 shl eax,2
 add eax,symval+1404
 mov eax,DWORD PTR [eax]
 mov edi,350
 call [symfnc+1400]
 mov ecx,DWORD PTR [esp]
 mov ebx,eax
 mov eax,symval+1044
 shl ebx,1
 mov 0[ebx][eax*1],cx
 inc DWORD PTR [esp]
 jmp l0033
l0034:
 mov eax,30*08000000h+OFFSET 128
 mov ds:symval+1408,eax
 add esp,8
 ret 
 DD 1
; (*entry faslin-intern expr 1)
 PUBLIC l0035
l0035:
 mov  DWORD PTR [esp-40],eax
 sub esp,12
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 8[esp],edi
 mov  DWORD PTR 4[esp],edi
 mov DWORD PTR [esp],eax
 mov ebx,eax
 xor eax,eax
 mov edi,353
 call [symfnc+1412]
 mov  DWORD PTR 4[esp],eax
 cmp eax,30*08000000h+OFFSET 128
 jne l0036
 mov eax,DWORD PTR [esp]
 add esp,12
 mov edi,354
 jmp [symfnc+1416]
l0036:
 mov eax,DWORD PTR [esp]
 and eax,134217727
 mov eax,DWORD PTR [eax]
 shl eax,5
 sar eax,5
 mov  DWORD PTR 8[esp],eax
 cmp eax, DWORD PTR 4[esp]
 jle l0037
 xor ebx,ebx
 inc ebx
 add ebx, DWORD PTR 4[esp]
 mov eax,DWORD PTR [esp]
 and eax,134217727
 add eax,4
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 cmp eax,0
 jne l0037
 inc  DWORD PTR 4[esp]
l0037:
 mov edi, DWORD PTR 4[esp]
 cmp edi, DWORD PTR 8[esp]
 jl l0038
 mov eax,DWORD PTR [esp]
 jmp l0039
l0038:
 mov ecx,DWORD PTR [esp]
 and ecx,134217727
 mov ecx,DWORD PTR [ecx]
 shl ecx,5
 sar ecx,5
 inc ecx
 xor ebx,ebx
 inc ebx
 add ebx, DWORD PTR 4[esp]
 mov eax,DWORD PTR [esp]
 mov edi,355
 call [symfnc+1420]
l0039:
 add esp,12
 mov edi,354
 jmp [symfnc+1416]
 DD 1
; (*entry intern expr 1)
 PUBLIC intern
intern:
 mov edi,357
 jmp [symfnc+1428]
l0040:
 DD 7
 DB 78,101,119,32,105,100,58,32,0,0
 DD 1
; (*entry unchecked-string-intern expr 1)
 PUBLIC l0041
l0041:
 mov  DWORD PTR [esp-52],eax
 sub esp,24
 mov DWORD PTR [esp],eax
 mov ebp,30*08000000h+OFFSET 128
 mov edx,ebp
 mov ecx,ebp
 mov ebx,eax
 and ebx,134217727
 mov ebx,DWORD PTR [ebx]
 shl ebx,5
 sar ebx,5
 and eax,134217727
 mov  DWORD PTR 4[esp],eax
 mov  DWORD PTR 8[esp],ebx
 mov  DWORD PTR 12[esp],ecx
 mov  DWORD PTR 16[esp],edx
 mov  DWORD PTR 20[esp],ebp
 cmp ebx,0
 jne l0042
 add eax,4
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 and eax,134217727
 or eax,-268435456
 jmp l0043
l0042:
 mov eax,DWORD PTR [esp]
 mov edi,350
 call [symfnc+1400]
 mov ebx,eax
 mov  DWORD PTR 12[esp],ebx
 mov eax,symval+1044
 shl ebx,1
 mov ax,0[eax][ebx*1]
 cwde 
 and eax,65535
 mov ebx,eax
 cmp eax,65535
 jl l0044
 mov eax,30*08000000h+OFFSET 128
 jmp l0045
l0044:
 mov eax,30*08000000h+OFFSET 116
l0045:
 cmp eax,30*08000000h+OFFSET 128
 je l0046
 mov eax,30*08000000h+OFFSET 116
 cmp ebx,0
 jg l0046
 add eax,12
l0046:
 cmp eax,30*08000000h+OFFSET 128
 je l0047
 mov ebx, DWORD PTR 12[esp]
 mov eax,symval+1044
 shl ebx,1
 mov ax,0[eax][ebx*1]
 cwde 
 and eax,65535
 and eax,134217727
 or eax,-268435456
 jmp l0043
l0047:
 cmp eax,symval+1408
 je l0048
 mov eax,4*08000000h+OFFSET l0040
 mov edi,331
 call [symfnc+1324]
 mov eax,DWORD PTR [esp]
 mov edi,331
 call [symfnc+1324]
 mov edi,332
 call [symfnc+1328]
l0048:
 mov edi,358
 call [symfnc+1432]
 mov  DWORD PTR 20[esp],eax
 mov ecx,eax
 mov ebx, DWORD PTR 12[esp]
 mov eax,symval+1044
 shl ebx,1
 mov 0[ebx][eax*1],cx
 mov eax, DWORD PTR 8[esp]
 mov edi,359
 call [symfnc+1436]
 mov  DWORD PTR 16[esp],eax
 mov ebx, DWORD PTR 4[esp]
 mov edi,360
 call [symfnc+1440]
 mov ebx, DWORD PTR 16[esp]
 and ebx,134217727
 or ebx,536870912
 mov eax, DWORD PTR 20[esp]
 add esp,24
 mov edi,361
 jmp [symfnc+1444]
l0043:
 add esp,24
 ret 
l0049:
 DD 18
 DB 72,97,115,104,32,116,97,98,108,101,32
 DB 111,118,101,114,102,108,111,119,0
 DD 1
; (*entry hash-into-table expr 1)
 PUBLIC l0050
l0050:
 mov  DWORD PTR [esp-44],eax
 sub esp,16
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 12[esp],edi
 mov  DWORD PTR 8[esp],edi
 mov  DWORD PTR 4[esp],edi
 mov DWORD PTR [esp],eax
 mov edi,362
 call [symfnc+1448]
 mov  DWORD PTR 4[esp],eax
 mov  DWORD PTR 8[esp],eax
 mov  DWORD PTR 12[esp],-1
l0051:
 mov ebx, DWORD PTR 8[esp]
 mov eax,symval+1044
 shl ebx,1
 mov ax,0[eax][ebx*1]
 cwde 
 and eax,65535
 cmp eax,0
 jne l0052
 cmp  DWORD PTR 12[esp],-1
 je l0053
 mov eax, DWORD PTR 12[esp]
 jmp l0054
l0053:
 mov eax, DWORD PTR 8[esp]
l0054:
 jmp l0055
l0052:
 mov ebx, DWORD PTR 8[esp]
 mov eax,symval+1044
 shl ebx,1
 mov ax,0[eax][ebx*1]
 cwde 
 mov ebx,eax
 and ebx,65535
 cmp ebx,65535
 jne l0056
 cmp  DWORD PTR 12[esp],-1
 jne l0057
 mov edi, DWORD PTR 8[esp]
 mov  DWORD PTR 12[esp],edi
 jmp l0057
l0056:
 mov ebx, DWORD PTR 8[esp]
 mov eax,symval+1044
 shl ebx,1
 mov ax,0[eax][ebx*1]
 cwde 
 mov ebx,DWORD PTR [esp]
 and eax,65535
 shl eax,2
 add eax,symval+1404
 mov eax,DWORD PTR [eax]
 mov edi,363
 call [symfnc+1452]
 cmp eax,30*08000000h+OFFSET 128
 je l0057
 mov eax, DWORD PTR 8[esp]
 jmp l0055
l0057:
 cmp  DWORD PTR 8[esp],68023
 jne l0058
 xor eax,eax
 jmp l0059
l0058:
 xor eax,eax
 inc eax
 add eax, DWORD PTR 8[esp]
l0059:
 mov  DWORD PTR 8[esp],eax
 cmp eax, DWORD PTR 4[esp]
 jne l0051
 mov eax,4*08000000h+OFFSET l0049
 mov edi,342
 call [symfnc+1368]
 jmp l0051
l0055:
 add esp,16
 ret 
 DD 2
; (*entry initialize-new-id expr 2)
 PUBLIC l0060
l0060:
 mov  DWORD PTR [esp-36],eax
 sub esp,8
 mov DWORD PTR [esp],eax
 and eax,134217727
 or eax,-268435456
 mov  DWORD PTR 4[esp],eax
 mov ecx,DWORD PTR [esp]
 shl ecx,2
 add ecx,symval+1404
 mov DWORD PTR [ecx],ebx
 mov edx,DWORD PTR [esp]
 shl edx,2
 add edx,symval+1248
 mov ebp,30*08000000h+OFFSET 128
 mov DWORD PTR [edx],ebp
 mov eax,DWORD PTR [esp]
 shl eax,2
 add eax,symval+1232
 mov ebx,DWORD PTR [esp]
 and ebx,134217727
 or ebx,-402653184
 mov DWORD PTR [eax],ebx
 mov eax,DWORD PTR [esp]
 mov edi,364
 call [symfnc+1456]
 mov eax, DWORD PTR 4[esp]
 add esp,8
 ret 
 DD 1
; (*entry hash-function expr 1)
 PUBLIC l0063
l0063:
 mov  DWORD PTR [esp-48],eax
 sub esp,20
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 12[esp],edi
 mov  DWORD PTR 4[esp],edi
 and eax,134217727
 mov  DWORD PTR 8[esp],eax
 mov eax,DWORD PTR [eax]
 shl eax,5
 sar eax,5
 mov DWORD PTR [esp],eax
 xor eax,eax
 mov  DWORD PTR 16[esp],eax
 cmp DWORD PTR [esp],24
 jle l0064
 mov DWORD PTR [esp],24
l0064:
 mov ebx,DWORD PTR [esp]
 xor eax,eax
 mov  DWORD PTR 12[esp],eax
 mov  DWORD PTR 4[esp],ebx
l0065:
 mov edi, DWORD PTR 12[esp]
 cmp edi, DWORD PTR 4[esp]
 jg l0066
 mov ebx, DWORD PTR 12[esp]
 mov eax,4
 add eax, DWORD PTR 8[esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 mov ebx,24
 sub ebx, DWORD PTR 12[esp]
 cmp ebx,0
 jge l0061
 neg ebx
 xchg ecx,ebx
 shr eax,cl
 jmp l0062
l0061:
 xchg ecx,ebx
 shl eax,cl
l0062:
 xchg ecx,ebx
 mov edi, DWORD PTR 16[esp]
 xor eax,edi
 mov  DWORD PTR 16[esp],eax
 inc  DWORD PTR 12[esp]
 jmp l0065
l0066:
 mov ebx,68023
 mov eax, DWORD PTR 16[esp]
 add esp,20
 cdq 
 idiv ebx
 mov eax,edx
 ret 
 DD 1
; (*entry faslin expr 1)
 PUBLIC faslin
faslin:
 mov  DWORD PTR [esp-72],eax
 sub esp,44
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 32[esp],edi
 mov  DWORD PTR 12[esp],edi
 mov  DWORD PTR 8[esp],edi
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 16[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 24[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 28[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 40[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 4[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 20[esp],30*08000000h+OFFSET 128
 mov  DWORD PTR 36[esp],30*08000000h+OFFSET 128
 mov edi,343
 call [symfnc+1372]
 mov  DWORD PTR 8[esp],eax
 mov edi,345
 call [symfnc+1380]
 mov  DWORD PTR 12[esp],eax
 mov ebx,65535
 and ebx,eax
 cmp ebx,399
 je l0067
 mov eax, DWORD PTR 8[esp]
 mov edi,349
 call [symfnc+1396]
 mov eax,DWORD PTR [esp]
 mov edi,365
 call [symfnc+1460]
 jmp l0068
l0067:
 mov eax, DWORD PTR 12[esp]
 shr eax,16
 mov  DWORD PTR 12[esp],eax
 mov eax, DWORD PTR 8[esp]
 mov edi,366
 call [symfnc+1464]
 mov  DWORD PTR 16[esp],eax
 mov eax, DWORD PTR 8[esp]
 mov edi,345
 call [symfnc+1380]
 mov  DWORD PTR 24[esp],eax
 mov edi,367
 call [symfnc+1468]
 mov  DWORD PTR 28[esp],eax
 xor eax,eax
 mov edi,367
 call [symfnc+1468]
 mov  DWORD PTR 36[esp],eax
 mov eax, DWORD PTR 8[esp]
 mov edi,345
 call [symfnc+1380]
 mov ebx, DWORD PTR 28[esp]
 add ebx,eax
 mov  DWORD PTR 40[esp],ebx
 mov ecx, DWORD PTR 24[esp]
 xor ebx,ebx
 add ebx, DWORD PTR 28[esp]
 mov eax, DWORD PTR 8[esp]
 mov edi,347
 call [symfnc+1388]
 mov eax, DWORD PTR 8[esp]
 mov edi,345
 call [symfnc+1380]
 mov  DWORD PTR 4[esp],eax
 mov edi,368
 call [symfnc+1472]
 mov ebx,eax
 and ebx,134217727
 or ebx,939524096
 mov  DWORD PTR 20[esp],ebx
 mov ecx, DWORD PTR 4[esp]
 and ebx,134217727
 add ebx,4
 mov eax, DWORD PTR 8[esp]
 mov edi,347
 call [symfnc+1388]
 mov eax, DWORD PTR 8[esp]
 mov edi,349
 call [symfnc+1396]
 xor eax,eax
 inc eax
 and eax, DWORD PTR 12[esp]
 cmp eax,1
 jne l0069
 mov edx, DWORD PTR 16[esp]
 mov ecx, DWORD PTR 20[esp]
 mov ebx, DWORD PTR 24[esp]
 mov eax, DWORD PTR 28[esp]
 mov edi,369
 call [symfnc+1476]
 jmp l0070
l0069:
 mov edx, DWORD PTR 16[esp]
 mov ecx, DWORD PTR 20[esp]
 mov ebx, DWORD PTR 24[esp]
 mov eax, DWORD PTR 28[esp]
 mov edi,370
 call [symfnc+1480]
l0070:
 mov eax,symval+1492
 mov  DWORD PTR 32[esp],eax
 mov edi, DWORD PTR 28[esp]
 mov ds:symval+1492,edi
 mov eax, DWORD PTR 40[esp]
 mov edi,371
 call [symfnc+1484]
 mov edi, DWORD PTR 32[esp]
 mov ds:symval+1492,edi
 mov ebx, DWORD PTR 36[esp]
 mov eax, DWORD PTR 40[esp]
 mov edi,372
 call [symfnc+1488]
l0068:
 mov eax,30*08000000h+OFFSET 128
 add esp,44
 ret 
 DD 2
; (*entry delbps expr 2)
 PUBLIC delbps
delbps:
 mov eax,30*08000000h+OFFSET 128
 ret 
 DD 4
; (*entry do-relocation expr 4)
 PUBLIC l0071
l0071:
 mov  DWORD PTR [esp-52],eax
 sub esp,24
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 16[esp],edi
 mov  DWORD PTR 12[esp],eax
 mov  DWORD PTR 4[esp],ecx
 mov  DWORD PTR 8[esp],edx
 mov eax,ebx
 shl eax,2
 xor ebx,ebx
 dec ebx
 add ebx,eax
 xor eax,eax
 mov  DWORD PTR 20[esp],eax
 mov DWORD PTR [esp],ebx
l0072:
 mov edi, DWORD PTR 20[esp]
 cmp edi,DWORD PTR [esp]
 jle l0073
 mov eax,30*08000000h+OFFSET 128
 jmp l0074
l0073:
 mov ebx, DWORD PTR 20[esp]
 mov eax, DWORD PTR 4[esp]
 and eax,134217727
 add eax,4
 mov ebp,ebx
 shr ebx,2
 mov al,0[eax][ebx*1]
 mov ebx,ebp
 and ebx,3
 add ebx,ebx
 add ebx,-6
 neg ebx
 xchg ecx,ebx
 shr eax,cl
 and eax,3
 mov ebx, DWORD PTR 12[esp]
 add ebx, DWORD PTR 20[esp]
 mov  DWORD PTR 16[esp],ebx
 cmp eax,1
 je l0075
 cmp eax,2
 je l0076
 cmp eax,3
 je l0077
 jmp l0078
l0075:
 mov ecx, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov eax, DWORD PTR 16[esp]
 mov edi,374
 call [symfnc+1496]
 jmp l0078
l0077:
 mov ecx, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov eax, DWORD PTR 16[esp]
 mov edi,375
 call [symfnc+1500]
 jmp l0078
l0076:
 mov ecx, DWORD PTR 8[esp]
 mov ebx, DWORD PTR 12[esp]
 mov eax, DWORD PTR 16[esp]
 mov edi,376
 call [symfnc+1504]
l0078:
 inc  DWORD PTR 20[esp]
 jmp l0072
l0074:
 add esp,24
 ret 
 DD 4
; (*entry do-relocation-new expr 4)
 PUBLIC l0079
l0079:
 mov  DWORD PTR [esp-52],eax
 sub esp,24
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 8[esp],edi
 mov  DWORD PTR 16[esp],eax
 mov DWORD PTR [esp],ecx
 mov  DWORD PTR 12[esp],edx
 mov ecx,30*08000000h+OFFSET 128
 mov ebx,eax
 xor eax,eax
 mov  DWORD PTR 4[esp],eax
 mov  DWORD PTR 20[esp],ebx
 mov ebp,DWORD PTR [esp]
 and ebp,134217727
 add ebp,4
 mov DWORD PTR [esp],ebp
l0080:
 mov ebx, DWORD PTR 4[esp]
 mov eax,DWORD PTR [esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 and eax,255
 mov  DWORD PTR 8[esp],eax
 cmp eax,0
 jne l0081
 mov eax,30*08000000h+OFFSET 128
 jmp l0082
l0081:
 inc  DWORD PTR 4[esp]
 mov eax,63
 and eax, DWORD PTR 8[esp]
 add eax, DWORD PTR 20[esp]
 mov  DWORD PTR 20[esp],eax
 mov ebx, DWORD PTR 8[esp]
 shr ebx,6
 mov  DWORD PTR 8[esp],ebx
 mov eax,ebx
 cmp eax,1
 je l0083
 cmp eax,2
 je l0084
 cmp eax,3
 je l0085
 jmp l0080
l0083:
 mov ecx, DWORD PTR 12[esp]
 mov ebx, DWORD PTR 16[esp]
 mov eax, DWORD PTR 20[esp]
 mov edi,374
 call [symfnc+1496]
 jmp l0080
l0085:
 mov ecx, DWORD PTR 12[esp]
 mov ebx, DWORD PTR 16[esp]
 mov eax, DWORD PTR 20[esp]
 mov edi,375
 call [symfnc+1500]
 jmp l0080
l0084:
 mov ecx, DWORD PTR 12[esp]
 mov ebx, DWORD PTR 16[esp]
 mov eax, DWORD PTR 20[esp]
 mov edi,376
 call [symfnc+1504]
 jmp l0080
l0082:
 add esp,24
 ret 
 DD 3
; (*entry relocate-word expr 3)
 PUBLIC l0086
l0086:
 mov  DWORD PTR [esp-40],eax
 sub esp,12
 mov  DWORD PTR 8[esp],eax
 mov eax,DWORD PTR [eax]
 mov DWORD PTR [esp],eax
 shr eax,30
 mov  DWORD PTR 4[esp],eax
 mov eax,DWORD PTR [esp]
 shl eax,2
 shr eax,2
 mov edx,ecx
 mov ecx,ebx
 mov ebx,eax
 mov eax, DWORD PTR 4[esp]
 mov edi,377
 call [symfnc+1508]
 mov esi, DWORD PTR 8[esp]
 mov DWORD PTR [esi],eax
 add esp,12
 ret 
 DD 3
; (*entry relocate-inf expr 3)
 PUBLIC l0087
l0087:
 mov  DWORD PTR [esp-40],eax
 sub esp,12
 mov  DWORD PTR 8[esp],eax
 mov eax,DWORD PTR [eax]
 mov DWORD PTR [esp],eax
 and eax,12582912
 shr eax,22
 mov  DWORD PTR 4[esp],eax
 mov eax,DWORD PTR [esp]
 and eax,4194303
 mov edx,ecx
 mov ecx,ebx
 mov ebx,eax
 mov eax, DWORD PTR 4[esp]
 mov edi,377
 call [symfnc+1508]
 mov esi, DWORD PTR 8[esp]
 mov edi,DWORD PTR [esi]
 and eax,134217727
 and edi,-134217728
 or edi,eax
 mov DWORD PTR [esi],edi
 add esp,12
 ret 
 DD 4
; (*entry compute-relocation expr 4)
 PUBLIC l0088
l0088:
 mov  DWORD PTR [esp-32],eax
 push ebx
 cmp eax,0
 jne l0089
 mov eax,ecx
 add eax,ebx
 jmp l0090
l0089:
 cmp eax,2
 jne l0091
 cmp ebx,8150
 jl l0092
 mov eax,-8156
 add eax,ebx
 shl eax,2
 add eax,symval+1028
 jmp l0090
l0092:
 cmp ebx,2048
 jl l0093
 mov ebx,edx
 mov eax,DWORD PTR [esp]
 mov edi,378
 call [symfnc+1512]
 cmp eax,symval+1228
 jle l0094
 shl eax,2
 add eax,symval+1232
 jmp l0090
l0094:
 shl eax,2
 add eax,symval+1236
 jmp l0090
l0093:
 mov eax,ebx
 shl eax,2
 add eax,symval+1236
 jmp l0090
l0091:
 cmp eax,3
 jne l0095
 cmp ebx,2048
 jl l0096
 mov ebx,edx
 mov eax,DWORD PTR [esp]
 mov edi,378
 call [symfnc+1512]
 mov DWORD PTR [esp],eax
l0096:
 mov eax,DWORD PTR [esp]
 shl eax,2
 add eax,symval+1240
 jmp l0090
l0095:
 cmp eax,1
 jne l0097
 cmp ebx,2048
 jl l0098
 mov ebx,edx
 mov eax,DWORD PTR [esp]
 add esp,4
 mov edi,378
 jmp [symfnc+1512]
l0098:
 mov eax,ebx
 jmp l0090
l0097:
 mov eax,30*08000000h+OFFSET 128
l0090:
 add esp,4
 ret 
 DD 3
; (*entry relocate-fast-call expr 3)
 PUBLIC l0099
l0099:
 mov eax,30*08000000h+OFFSET 128
 ret 
 DD 2
; (*entry local-to-global-id expr 2)
 PUBLIC l0100
l0100:
 add eax,-2047
 shl eax,2
 mov ecx,ebx
 and ecx,134217727
 add eax,ecx
 mov eax,DWORD PTR [eax]
 ret 
 DD 1
; (*entry read-id-table expr 1)
 PUBLIC l0101
l0101:
 mov  DWORD PTR [esp-52],eax
 sub esp,24
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 20[esp],edi
 mov  DWORD PTR 16[esp],edi
 mov  DWORD PTR 12[esp],edi
 mov  DWORD PTR 8[esp],edi
 mov  DWORD PTR 4[esp],edi
 mov DWORD PTR [esp],eax
 mov edi,345
 call [symfnc+1380]
 mov  DWORD PTR 4[esp],eax
 inc eax
 mov edi,368
 call [symfnc+1472]
 and eax,134217727
 or eax,939524096
 mov  DWORD PTR 8[esp],eax
 mov ebx, DWORD PTR 4[esp]
 xor eax,eax
 mov  DWORD PTR 12[esp],eax
 mov  DWORD PTR 16[esp],ebx
l0102:
 mov edi, DWORD PTR 12[esp]
 cmp edi, DWORD PTR 16[esp]
 jg l0103
 mov eax,DWORD PTR [esp]
 mov edi,345
 call [symfnc+1380]
 mov esi,symval+1032
 mov DWORD PTR [esi],eax
 mov ecx,5
 add ecx,eax
 mov ebx,ecx
 shr ebx,30
 add ecx,ebx
 sar ecx,2
 mov ebx,4
 add ebx,symval+1032
 mov eax,DWORD PTR [esp]
 mov edi,347
 call [symfnc+1388]
 xor eax,eax
 add eax,symval+1032
 and eax,134217727
 or eax,536870912
 mov edi,356
 call [symfnc+1424]
 mov  DWORD PTR 20[esp],eax
 xor eax,eax
 inc eax
 add eax, DWORD PTR 12[esp]
 shl eax,2
 mov ebx, DWORD PTR 8[esp]
 and ebx,134217727
 add eax,ebx
 mov ecx, DWORD PTR 20[esp]
 and ecx,134217727
 mov DWORD PTR [eax],ecx
 inc  DWORD PTR 12[esp]
 jmp l0102
l0103:
 mov eax, DWORD PTR 8[esp]
 add esp,24
 ret 
 DD 3
; (*entry putentry expr 3)
 PUBLIC putentry
putentry:
 add ecx,symval+1492
 and ecx,134217727
 or ecx,-1610612736
 mov edi,380
 jmp [symfnc+1520]
l0104:
 DD 22
 DB 70,105,108,101,32,105,115,32,110,111,116
 DB 32,70,65,83,76,32,102,111,114,109,97,116
 DB 0
 DD 1
; (*entry faslin-bad-file expr 1)
 PUBLIC l0105
l0105:
 mov eax,4*08000000h+OFFSET l0104
 mov edi,331
 call [symfnc+1324]
 mov edi,332
 jmp [symfnc+1328]
l0106:
 DD 30
 DB 82,97,110,32,111,117,116,32,111,102,32
 DB 98,105,110,97,114,121,32,112,114,111,103
 DB 114,97,109,32,115,112,97,99,101,0
 DD 1
; (*entry gtbps expr 1)
 PUBLIC gtbps
gtbps:
 mov  DWORD PTR [esp-32],eax
 sub esp,4
l0107:
 mov DWORD PTR [esp],eax
 cmp eax,30*08000000h+OFFSET 128
 jne l0108
 mov edi,382
 call [symfnc+1528]
l0108:
 cmp DWORD PTR [esp],10
 jle l0109
 mov eax,15
 and eax,symval+1172
 cmp eax,0
 je l0109
 mov ebx,symval+1172
 shr ebx,4
 shl ebx,4
 add ebx,16
 mov ds:symval+1172,ebx
l0109:
 mov eax,symval+1172
 mov ebx,DWORD PTR [esp]
 shl ebx,2
 add ebx,symval+1172
 mov ds:symval+1172,ebx
 cmp ebx,symval+1144
 jle l0110
 mov ds:symval+1172,eax
 mov eax,30*08000000h+OFFSET 383
 mov edi,384
 call [symfnc+1536]
 cmp eax,30*08000000h+OFFSET 128
 je l0111
 mov eax,DWORD PTR [esp]
 mov edi,383
 call [symfnc+1532]
 cmp eax,30*08000000h+OFFSET 128
 je l0111
 mov eax,DWORD PTR [esp]
 jmp l0107
l0111:
 mov eax,4*08000000h+OFFSET l0106
 add esp,4
 mov edi,385
 jmp [symfnc+1540]
l0110:
 add esp,4
 ret 
l0112:
 DD 21
 DB 71,84,66,80,83,32,99,97,108,108,101,100
 DB 32,119,105,116,104,32,78,73,76,46,0,0
 DD 0
; (*entry gtbps-nil-error expr 0)
 PUBLIC l0113
l0113:
 mov eax,4*08000000h+OFFSET l0112
 mov edi,385
 jmp [symfnc+1540]
 DD 1
; (*entry gtheap expr 1)
 PUBLIC gtheap
gtheap:
 cmp eax,30*08000000h+OFFSET 128
 jne l0114
 mov edi,386
 jmp [symfnc+1544]
l0114:
 mov edi,387
 jmp [symfnc+1548]
 DD 1
; (*entry real-gtheap expr 1)
 PUBLIC l0115
l0115:
 mov ecx,eax
 mov eax,symval+1128
 mov ebx,ecx
 shl ebx,2
 add ebx,symval+1128
 mov ds:symval+1128,ebx
 cmp ebx,symval+1132
 jl l0116
 mov ebx,ecx
 mov edi,389
 jmp [symfnc+1556]
l0116:
 ret 
l0117:
 DD 27
 DB 71,97,114,98,97,103,101,32,99,111,108
 DB 108,101,99,116,105,111,110,32,114,101
 DB 113,117,105,114,101,100,46,0,0
 DD 1
; (*entry get-heap-trap expr 1)
 PUBLIC l0118
l0118:
 mov eax,4*08000000h+OFFSET l0117
 mov edi,342
 jmp [symfnc+1368]
l0119:
 DD 18
 DB 82,97,110,32,111,117,116,32,111,102,32
 DB 73,68,32,115,112,97,99,101,0
 DD 0
; (*entry gtid expr 0)
 PUBLIC gtid
gtid:
 cmp symval+1224,0
 jne l0120
 mov edi,390
 call [symfnc+1560]
 cmp symval+1224,0
 jne l0120
 mov eax,4*08000000h+OFFSET l0119
 mov edi,342
 call [symfnc+1368]
l0120:
 mov eax,symval+1224
 mov ebx,eax
 shl ebx,2
 add ebx,symval+1404
 mov edi,DWORD PTR [ebx]
 mov ds:symval+1224,edi
 ret 
 DD 1
; (*entry gtwrds expr 1)
 PUBLIC gtwrds
gtwrds:
 mov  DWORD PTR [esp-32],eax
 push eax
 add eax,2
 mov edi,388
 call [symfnc+1552]
 mov ebx,DWORD PTR [esp]
 and ebx,134217727
 or ebx,-939524096
 mov DWORD PTR [eax],ebx
 add esp,4
 ret 
 DD 1
; (*entry gtconststr expr 1)
 PUBLIC gtconststr
gtconststr:
 mov  DWORD PTR [esp-36],eax
 sub esp,8
 mov DWORD PTR [esp],eax
 add eax,5
 mov ebx,eax
 shr ebx,30
 add eax,ebx
 sar eax,2
 mov  DWORD PTR 4[esp],eax
 inc eax
 mov edi,367
 call [symfnc+1468]
 mov edi,DWORD PTR [esp]
 mov DWORD PTR [eax],edi
 mov ebx, DWORD PTR 4[esp]
 shl ebx,2
 add ebx,eax
 mov DWORD PTR [ebx],0
 add esp,8
 ret 
l0121:
 DD 30
 DB 83,85,66,83,69,81,32,99,97,108,108,101
 DB 100,32,119,105,116,104,32,97,32,110,111
 DB 110,45,115,116,114,105,110,103,0
 DD 3
; (*entry subseq expr 3)
 PUBLIC subseq
subseq:
 mov  DWORD PTR [esp-60],eax
 sub esp,32
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 28[esp],edi
 mov  DWORD PTR 24[esp],edi
 mov  DWORD PTR 20[esp],edi
 mov  DWORD PTR 16[esp],edi
 mov  DWORD PTR 12[esp],edi
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
 mov  DWORD PTR 8[esp],ecx
 mov edi,eax
 shr edi,27
 cmp edi,4
 je l0122
 mov eax,4*08000000h+OFFSET l0121
 mov edi,342
 call [symfnc+1368]
l0122:
 xor eax,eax
 dec eax
 add eax, DWORD PTR 8[esp]
 sub eax, DWORD PTR 4[esp]
 mov  DWORD PTR 12[esp],eax
 mov eax,DWORD PTR [esp]
 and eax,134217727
 mov  DWORD PTR 16[esp],eax
 mov eax, DWORD PTR 12[esp]
 mov edi,391
 call [symfnc+1564]
 mov  DWORD PTR 20[esp],eax
 mov ebx, DWORD PTR 12[esp]
 xor eax,eax
 mov  DWORD PTR 24[esp],eax
 mov  DWORD PTR 28[esp],ebx
l0123:
 mov edi, DWORD PTR 24[esp]
 cmp edi, DWORD PTR 28[esp]
 jg l0124
 mov ebx, DWORD PTR 4[esp]
 add ebx, DWORD PTR 24[esp]
 mov eax,4
 add eax, DWORD PTR 16[esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 mov ecx,eax
 mov ebx, DWORD PTR 24[esp]
 mov eax,4
 add eax, DWORD PTR 20[esp]
 mov edx,0[eax][ebx*1]
 shr edx,8
 shl edx,8
 and ecx,255
 or ecx,edx
 mov 0[ebx][eax*1],ecx
 inc  DWORD PTR 24[esp]
 jmp l0123
l0124:
 mov eax, DWORD PTR 20[esp]
 and eax,134217727
 or eax,536870912
 add esp,32
 ret 
 DD 2
; (*entry search-string-for-character expr 2)
 PUBLIC l0125
l0125:
 mov  DWORD PTR [esp-44],eax
 sub esp,16
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
 and ebx,134217727
 mov ebx,DWORD PTR [ebx]
 shl ebx,5
 sar ebx,5
 xor eax,eax
 mov  DWORD PTR 8[esp],eax
 mov  DWORD PTR 12[esp],ebx
l0126:
 mov edi, DWORD PTR 8[esp]
 cmp edi, DWORD PTR 12[esp]
 jle l0127
 mov eax,30*08000000h+OFFSET 128
 jmp l0128
l0127:
 mov ebx, DWORD PTR 8[esp]
 mov eax, DWORD PTR 4[esp]
 and eax,134217727
 add eax,4
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 cmp eax,DWORD PTR [esp]
 jne l0129
 mov eax, DWORD PTR 8[esp]
 jmp l0128
l0129:
 inc  DWORD PTR 8[esp]
 jmp l0126
l0128:
 add esp,16
 ret 
 DD 2
; (*entry unchecked-string-equal expr 2)
 PUBLIC l0130
l0130:
 mov  DWORD PTR [esp-48],eax
 sub esp,20
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 16[esp],edi
 mov  DWORD PTR 12[esp],30*08000000h+OFFSET 128
 and eax,134217727
 mov DWORD PTR [esp],eax
 and ebx,134217727
 mov  DWORD PTR 4[esp],ebx
 mov ecx,DWORD PTR [eax]
 shl ecx,5
 sar ecx,5
 mov  DWORD PTR 8[esp],ecx
 mov edx,DWORD PTR [ebx]
 shl edx,5
 sar edx,5
 cmp ecx,edx
 je l0131
 mov eax,30*08000000h+OFFSET 128
 jmp l0132
l0131:
 mov  DWORD PTR 12[esp],0
l0133:
 mov edi, DWORD PTR 12[esp]
 cmp edi, DWORD PTR 8[esp]
 jle l0134
 mov eax,30*08000000h+OFFSET 116
 jmp l0132
l0134:
 mov ebx, DWORD PTR 12[esp]
 mov eax,4
 add eax,DWORD PTR [esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 mov  DWORD PTR 16[esp],eax
 mov ebx, DWORD PTR 12[esp]
 mov eax,4
 add eax, DWORD PTR 4[esp]
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 cmp eax, DWORD PTR 16[esp]
 je l0135
 mov eax,30*08000000h+OFFSET 128
 jmp l0132
l0135:
 inc  DWORD PTR 12[esp]
 jmp l0133
l0132:
 add esp,20
 ret 
 DD 2
; (*entry copystringtofrom expr 2)
 PUBLIC copystringtofrom
copystringtofrom:
 mov  DWORD PTR [esp-44],eax
 sub esp,16
 mov  DWORD PTR 12[esp],eax
 mov ecx,eax
 and ecx,134217727
 mov  DWORD PTR 4[esp],ecx
 mov edx,ebx
 and edx,134217727
 mov  DWORD PTR 8[esp],edx
 mov ebp,DWORD PTR [edx]
 shl ebp,5
 sar ebp,5
 mov DWORD PTR [esp],ebp
 mov eax,DWORD PTR [ecx]
 shl eax,5
 sar eax,5
 cmp eax,ebp
 jge l0136
 mov DWORD PTR [esp],eax
l0136:
 mov eax,5
 add eax,DWORD PTR [esp]
 mov ebx,eax
 shr ebx,30
 add eax,ebx
 sar eax,2
 mov DWORD PTR [esp],eax
 mov ebx,eax
 xor eax,eax
 mov edx,eax
 mov ecx,ebx
l0137:
 cmp edx,ecx
 jg l0138
 xor eax,eax
 inc eax
 add eax,edx
 shl eax,2
 add eax, DWORD PTR 4[esp]
 xor ebx,ebx
 inc ebx
 add ebx,edx
 shl ebx,2
 add ebx, DWORD PTR 8[esp]
 mov edi,DWORD PTR [ebx]
 mov DWORD PTR [eax],edi
 inc edx
 jmp l0137
l0138:
 mov eax, DWORD PTR 12[esp]
 add esp,16
 ret 
 DD 2
; (*entry cons expr 2)
 PUBLIC cons
cons:
 mov  DWORD PTR [esp-32],eax
 push ebx
 push eax
 mov eax,2
 mov edi,388
 call [symfnc+1552]
 mov edi,DWORD PTR [esp]
 mov DWORD PTR [eax],edi
 mov edi, DWORD PTR 4[esp]
 mov  DWORD PTR 4[eax],edi
 and eax,134217727
 or eax,1207959552
 add esp,8
 ret 
 DD 1
; (*entry interrogate expr 1)
 PUBLIC interrogate
interrogate:
 shl eax,2
 add eax,symval+1232
 mov eax,DWORD PTR [eax]
 ret 
 DD 2
; (*entry modify expr 2)
 PUBLIC modify
modify:
 shl eax,2
 add eax,symval+1232
 mov DWORD PTR [eax],ebx
 mov eax,ebx
 ret 
 DD 3
; (*entry put expr 3)
 PUBLIC put
put:
 mov edi,395
 jmp [symfnc+1580]
 DD 3
; (*entry unchecked-put expr 3)
 PUBLIC l0139
l0139:
 mov  DWORD PTR [esp-44],eax
 sub esp,16
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 12[esp],edi
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
 mov  DWORD PTR 8[esp],ecx
 mov edi,397
 call [symfnc+1588]
 mov  DWORD PTR 12[esp],eax
 mov ebx,eax
 mov eax, DWORD PTR 4[esp]
 mov edi,398
 call [symfnc+1592]
 cmp eax,30*08000000h+OFFSET 128
 je l0140
 mov edi, DWORD PTR 8[esp]
 mov  DWORD PTR [eax-1207959548],edi
 jmp l0141
l0140:
 mov ebx, DWORD PTR 8[esp]
 mov eax, DWORD PTR 4[esp]
 mov edi,392
 call [symfnc+1568]
 mov ebx, DWORD PTR 12[esp]
 mov edi,392
 call [symfnc+1568]
 mov ebx,eax
 mov eax,DWORD PTR [esp]
 mov edi,399
 call [symfnc+1596]
l0141:
 mov eax, DWORD PTR 8[esp]
 add esp,16
 ret 
 DD 2
; (*entry atsoc expr 2)
 PUBLIC atsoc
atsoc:
l0142:
 mov edi,ebx
 shr edi,27
 cmp edi,9
 je l0143
 mov eax,30*08000000h+OFFSET 128
 ret 
l0143:
 mov edi, DWORD PTR [ebx-1207959552]
 shr edi,27
 cmp edi,9
 jne l0144
 mov esi, DWORD PTR [ebx-1207959552]
 cmp eax, DWORD PTR [esi-1207959552]
 jne l0144
 mov eax, DWORD PTR [ebx-1207959552]
 ret 
l0144:
 mov ebx, DWORD PTR [ebx-1207959548]
 jmp l0142
 DD 2
; (*entry unchecked-setprop expr 2)
 PUBLIC l0145
l0145:
 and eax,134217727
 shl eax,2
 add eax,symval+1248
 mov DWORD PTR [eax],ebx
 mov eax,ebx
 ret 
 DD 1
; (*entry unchecked-prop expr 1)
 PUBLIC l0146
l0146:
 and eax,134217727
 shl eax,2
 add eax,symval+1248
 mov eax,DWORD PTR [eax]
 ret 
 DD 3
; (*entry putd expr 3)
 PUBLIC putd
putd:
 mov edi,400
 jmp [symfnc+1600]
l0147:
 DD 26
 DB 66,97,100,32,112,97,114,97,109,101,116
 DB 101,114,115,32,116,111,32,67,79,68,69
 DB 45,80,85,84,68,0
 DD 3
; (*entry code-putd expr 3)
 PUBLIC l0148
l0148:
 mov  DWORD PTR [esp-40],eax
 sub esp,12
 mov DWORD PTR [esp],eax
 mov  DWORD PTR 4[esp],ebx
 mov  DWORD PTR 8[esp],ecx
 mov edi,eax
 shr edi,27
 cmp edi,30
 jne l0149
 mov edi,ebx
 shr edi,27
 cmp edi,30
 jne l0149
 mov edi,ecx
 shr edi,27
 cmp edi,20
 je l0150
l0149:
 mov eax,4*08000000h+OFFSET l0147
 mov edi,342
 call [symfnc+1368]
l0150:
 mov ebx, DWORD PTR 8[esp]
 and ebx,134217727
 mov eax,DWORD PTR [esp]
 and eax,134217727
 mov edi,401
 call [symfnc+1604]
 mov edi, DWORD PTR 4[esp]
 cmp edi,30*08000000h+OFFSET 402
 je l0151
 mov ecx, DWORD PTR 4[esp]
 mov ebx,30*08000000h+OFFSET 403
 mov eax,DWORD PTR [esp]
 add esp,12
 mov edi,396
 jmp [symfnc+1584]
l0151:
 mov eax,30*08000000h+OFFSET 128
 add esp,12
 ret 
 DD 1
; (*entry fluid expr 1)
 PUBLIC fluid
fluid:
 mov  DWORD PTR [esp-40],eax
 sub esp,12
 mov edi,30*08000000h+OFFSET 128
 mov  DWORD PTR 8[esp],edi
 mov DWORD PTR [esp],eax
 mov eax,30*08000000h+OFFSET 128
 mov edi,DWORD PTR [esp]
 mov  DWORD PTR 4[esp],edi
 mov edi, DWORD PTR 4[esp]
 shr edi,27
 cmp edi,9
 jne l0152
 mov eax, DWORD PTR 4[esp]
 mov eax, DWORD PTR [eax-1207959552]
 jmp l0153
l0152:
 mov eax,30*08000000h+OFFSET 128
l0153:
 mov  DWORD PTR 8[esp],eax
l0154:
 mov edi, DWORD PTR 4[esp]
 shr edi,27
 cmp edi,9
 je l0155
 mov eax,30*08000000h+OFFSET 128
 jmp l0156
l0155:
 mov eax, DWORD PTR 8[esp]
 mov edi,404
 call [symfnc+1616]
 mov eax, DWORD PTR 4[esp]
 mov eax, DWORD PTR [eax-1207959548]
 mov  DWORD PTR 4[esp],eax
 mov edi,eax
 shr edi,27
 cmp edi,9
 jne l0157
 mov eax, DWORD PTR [eax-1207959552]
 jmp l0158
l0157:
 mov eax,30*08000000h+OFFSET 128
l0158:
 mov  DWORD PTR 8[esp],eax
 jmp l0154
l0156:
 add esp,12
 ret 
 DD 1
; (*entry fluid1 expr 1)
 PUBLIC l0159
l0159:
 mov ecx,30*08000000h+OFFSET 405
 mov ebx,30*08000000h+OFFSET 406
 mov edi,396
 jmp [symfnc+1584]
 DD 1
; (*entry stderror expr 1)
 PUBLIC stderror
stderror:
 mov edi,342
 jmp [symfnc+1368]
 DD 2
; (*entry *define-constant expr 2)
 PUBLIC l0160
l0160:
 mov ecx,eax
 and ecx,134217727
 shl ecx,2
 add ecx,symval+1232
 mov DWORD PTR [ecx],ebx
 mov ecx,30*08000000h+OFFSET 116
 mov ebx,30*08000000h+OFFSET 407
 mov edi,396
 jmp [symfnc+1584]
EXTRN _whatsup:NEAR
 DD 1
; (*entry whatsup expr 1)
 PUBLIC l0161
l0161:
 cmp symval+1220,0
 jge l0162
 mov edi,409
 jmp [symfnc+1636]
l0162:
 push eax
 call _whatsup
 add esp,4
 ret 
EXTRN _getpid:NEAR
 DD 0
; (*entry getpid expr 0)
 PUBLIC l0163
l0163:
 call _getpid
 add esp,0
 ret 
EXTRN _echoon:NEAR
 DD 0
; (*entry echoon expr 0)
 PUBLIC l0164
l0164:
 call _echoon
 add esp,0
 ret 
EXTRN _echooff:NEAR
 DD 0
; (*entry echooff expr 0)
 PUBLIC l0165
l0165:
 call _echooff
 add esp,0
 ret 
EXTRN _external_charsininputbuffer:NEAR
 DD 1
; (*entry external_charsininputbuffer expr 1)
 PUBLIC l0166
l0166:
 push eax
 call _external_charsininputbuffer
 add esp,4
 ret 
EXTRN _flushstdoutputbuffer:NEAR
 DD 0
; (*entry flushstdoutputbuffer expr 0)
 PUBLIC l0167
l0167:
 call _flushstdoutputbuffer
 add esp,0
 ret 
EXTRN _external_user_homedir_string:NEAR
 DD 0
; (*entry external_user_homedir_string expr 0)
 PUBLIC l0168
l0168:
 call _external_user_homedir_string
 add esp,0
 ret 
EXTRN _alterheapsize:NEAR
 DD 1
; (*entry alterheapsize expr 1)
 PUBLIC l0169
l0169:
 push eax
 call _alterheapsize
 add esp,4
 ret 
EXTRN _allocatemorebps:NEAR
 DD 1
; (*entry allocatemorebps expr 1)
 PUBLIC l0170
l0170:
 push eax
 call _allocatemorebps
 add esp,4
 ret 
EXTRN _get_file_status:NEAR
 DD 3
; (*entry get_file_status expr 3)
 PUBLIC l0171
l0171:
 push ecx
 push ebx
 push eax
 call _get_file_status
 add esp,12
 ret 
EXTRN _os_startup_hook:NEAR
 DD 2
; (*entry os_startup_hook expr 2)
 PUBLIC l0172
l0172:
 push ebx
 push eax
 call _os_startup_hook
 add esp,8
 ret 
EXTRN _os_cleanup_hook:NEAR
 DD 0
; (*entry os_cleanup_hook expr 0)
 PUBLIC l0173
l0173:
 call _os_cleanup_hook
 add esp,0
 ret 
EXTRN _external_alarm:NEAR
 DD 1
; (*entry external_alarm expr 1)
 PUBLIC l0174
l0174:
 push eax
 call _external_alarm
 add esp,4
 ret 
EXTRN _external_ualarm:NEAR
 DD 2
; (*entry external_ualarm expr 2)
 PUBLIC l0175
l0175:
 push ebx
 push eax
 call _external_ualarm
 add esp,8
 ret 
EXTRN _external_time:NEAR
 DD 1
; (*entry external_time expr 1)
 PUBLIC l0176
l0176:
 push eax
 call _external_time
 add esp,4
 ret 
EXTRN _external_timc:NEAR
 DD 1
; (*entry external_timc expr 1)
 PUBLIC l0177
l0177:
 push eax
 call _external_timc
 add esp,4
 ret 
EXTRN _external_stat:NEAR
 DD 2
; (*entry external_stat expr 2)
 PUBLIC l0178
l0178:
 push ebx
 push eax
 call _external_stat
 add esp,8
 ret 
EXTRN _external_link:NEAR
 DD 2
; (*entry external_link expr 2)
 PUBLIC l0179
l0179:
 push ebx
 push eax
 call _external_link
 add esp,8
 ret 
EXTRN _external_unlink:NEAR
 DD 1
; (*entry external_unlink expr 1)
 PUBLIC l0180
l0180:
 push eax
 call _external_unlink
 add esp,4
 ret 
EXTRN _external_setenv:NEAR
 DD 2
; (*entry external_setenv expr 2)
 PUBLIC l0181
l0181:
 push ebx
 push eax
 call _external_setenv
 add esp,8
 ret 
EXTRN _external_getenv:NEAR
 DD 1
; (*entry external_getenv expr 1)
 PUBLIC l0182
l0182:
 push eax
 call _external_getenv
 add esp,4
 ret 
EXTRN _uxfloat:NEAR
 DD 2
; (*entry uxfloat expr 2)
 PUBLIC l0183
l0183:
 push ebx
 push eax
 call _uxfloat
 add esp,8
 ret 
EXTRN _uxfix:NEAR
 DD 1
; (*entry uxfix expr 1)
 PUBLIC l0184
l0184:
 push eax
 call _uxfix
 add esp,4
 ret 
EXTRN _uxassign:NEAR
 DD 2
; (*entry uxassign expr 2)
 PUBLIC l0185
l0185:
 push ebx
 push eax
 call _uxassign
 add esp,8
 ret 
EXTRN _uxplus2:NEAR
 DD 3
; (*entry uxplus2 expr 3)
 PUBLIC l0186
l0186:
 push ecx
 push ebx
 push eax
 call _uxplus2
 add esp,12
 ret 
EXTRN _uxdifference:NEAR
 DD 3
; (*entry uxdifference expr 3)
 PUBLIC l0187
l0187:
 push ecx
 push ebx
 push eax
 call _uxdifference
 add esp,12
 ret 
EXTRN _uxtimes2:NEAR
 DD 3
; (*entry uxtimes2 expr 3)
 PUBLIC l0188
l0188:
 push ecx
 push ebx
 push eax
 call _uxtimes2
 add esp,12
 ret 
EXTRN _uxquotient:NEAR
 DD 3
; (*entry uxquotient expr 3)
 PUBLIC l0189
l0189:
 push ecx
 push ebx
 push eax
 call _uxquotient
 add esp,12
 ret 
EXTRN _uxgreaterp:NEAR
 DD 4
; (*entry uxgreaterp expr 4)
 PUBLIC l0190
l0190:
 push edx
 push ecx
 push ebx
 push eax
 call _uxgreaterp
 add esp,16
 ret 
EXTRN _uxlessp:NEAR
 DD 4
; (*entry uxlessp expr 4)
 PUBLIC l0191
l0191:
 push edx
 push ecx
 push ebx
 push eax
 call _uxlessp
 add esp,16
 ret 
EXTRN _uxwritefloat:NEAR
 DD 3
; (*entry uxwritefloat expr 3)
 PUBLIC l0192
l0192:
 push ecx
 push ebx
 push eax
 call _uxwritefloat
 add esp,12
 ret 
EXTRN _uuxdoubletofloat:NEAR
 DD 2
; (*entry uuxdoubletofloat expr 2)
 PUBLIC l0193
l0193:
 push ebx
 push eax
 call _uuxdoubletofloat
 add esp,8
 ret 
EXTRN _uuxfloattodouble:NEAR
 DD 2
; (*entry uuxfloattodouble expr 2)
 PUBLIC l0194
l0194:
 push ebx
 push eax
 call _uuxfloattodouble
 add esp,8
 ret 
EXTRN _uuxsin:NEAR
 DD 2
; (*entry uuxsin expr 2)
 PUBLIC l0195
l0195:
 push ebx
 push eax
 call _uuxsin
 add esp,8
 ret 
EXTRN _uuxcos:NEAR
 DD 2
; (*entry uuxcos expr 2)
 PUBLIC l0196
l0196:
 push ebx
 push eax
 call _uuxcos
 add esp,8
 ret 
EXTRN _uuxtan:NEAR
 DD 2
; (*entry uuxtan expr 2)
 PUBLIC l0197
l0197:
 push ebx
 push eax
 call _uuxtan
 add esp,8
 ret 
EXTRN _uuxasin:NEAR
 DD 2
; (*entry uuxasin expr 2)
 PUBLIC l0198
l0198:
 push ebx
 push eax
 call _uuxasin
 add esp,8
 ret 
EXTRN _uuxacos:NEAR
 DD 2
; (*entry uuxacos expr 2)
 PUBLIC l0199
l0199:
 push ebx
 push eax
 call _uuxacos
 add esp,8
 ret 
EXTRN _uuxatan:NEAR
 DD 2
; (*entry uuxatan expr 2)
 PUBLIC l0200
l0200:
 push ebx
 push eax
 call _uuxatan
 add esp,8
 ret 
EXTRN _uuxsqrt:NEAR
 DD 2
; (*entry uuxsqrt expr 2)
 PUBLIC l0201
l0201:
 push ebx
 push eax
 call _uuxsqrt
 add esp,8
 ret 
EXTRN _uuxexp:NEAR
 DD 2
; (*entry uuxexp expr 2)
 PUBLIC l0202
l0202:
 push ebx
 push eax
 call _uuxexp
 add esp,8
 ret 
EXTRN _uuxlog:NEAR
 DD 2
; (*entry uuxlog expr 2)
 PUBLIC l0203
l0203:
 push ebx
 push eax
 call _uuxlog
 add esp,8
 ret 
EXTRN _uuxatan2:NEAR
 DD 3
; (*entry uuxatan2 expr 3)
 PUBLIC l0204
l0204:
 push ecx
 push ebx
 push eax
 call _uuxatan2
 add esp,12
 ret 
EXTRN _get_registry_value:NEAR
 DD 4
; (*entry get_registry_value expr 4)
 PUBLIC l0205
l0205:
 push edx
 push ecx
 push ebx
 push eax
 call _get_registry_value
 add esp,16
 ret 
EXTRN _external_pwd:NEAR
 DD 0
; (*entry external_pwd expr 0)
 PUBLIC l0206
l0206:
 call _external_pwd
 add esp,0
 ret 
EXTRN _sun3_sigset:NEAR
 DD 2
; (*entry sun3_sigset expr 2)
 PUBLIC l0207
l0207:
 push ebx
 push eax
 call _sun3_sigset
 add esp,8
 ret 
EXTRN _sigrelse:NEAR
 DD 2
; (*entry sigrelse expr 2)
 PUBLIC l0208
l0208:
 push ebx
 push eax
 call _sigrelse
 add esp,8
 ret 
EXTRN _unexec:NEAR
 DD 4
; (*entry unexec expr 4)
 PUBLIC l0209
l0209:
 push edx
 push ecx
 push ebx
 push eax
 call _unexec
 add esp,16
 ret 
EXTRN _unixputc:NEAR
 DD 1
; (*entry unixputc expr 1)
 PUBLIC l0210
l0210:
 push eax
 call _unixputc
 add esp,4
 ret 
EXTRN _unixputs:NEAR
 DD 1
; (*entry unixputs expr 1)
 PUBLIC l0211
l0211:
 push eax
 call _unixputs
 add esp,4
 ret 
EXTRN _unixputn:NEAR
 DD 1
; (*entry unixputn expr 1)
 PUBLIC l0212
l0212:
 push eax
 call _unixputn
 add esp,4
 ret 
EXTRN _unixcleario:NEAR
 DD 0
; (*entry unixcleario expr 0)
 PUBLIC l0213
l0213:
 call _unixcleario
 add esp,0
 ret 
EXTRN _expand_file_name:NEAR
 DD 1
; (*entry expand_file_name expr 1)
 PUBLIC l0214
l0214:
 push eax
 call _expand_file_name
 add esp,4
 ret 
EXTRN _unixopen:NEAR
 DD 2
; (*entry unixopen expr 2)
 PUBLIC l0215
l0215:
 push ebx
 push eax
 call _unixopen
 add esp,8
 ret 
EXTRN _unixcd:NEAR
 DD 1
; (*entry unixcd expr 1)
 PUBLIC l0216
l0216:
 push eax
 call _unixcd
 add esp,4
 ret 
EXTRN _unixfread:NEAR
 DD 4
; (*entry unixfread expr 4)
 PUBLIC l0217
l0217:
 cmp symval+1220,0
 jge l0218
 mov edi,409
 jmp [symfnc+1636]
l0218:
 push edx
 push ecx
 push ebx
 push eax
 call _unixfread
 add esp,16
 ret 
EXTRN _unixfputc:NEAR
 DD 2
; (*entry unixfputc expr 2)
 PUBLIC l0219
l0219:
 cmp symval+1220,0
 jge l0220
 mov edi,409
 jmp [symfnc+1636]
l0220:
 push ebx
 push eax
 call _unixfputc
 add esp,8
 ret 
EXTRN _unixfgetc:NEAR
 DD 1
; (*entry unixfgetc expr 1)
 PUBLIC l0221
l0221:
 cmp symval+1220,0
 jge l0222
 mov edi,409
 jmp [symfnc+1636]
l0222:
 push eax
 call _unixfgetc
 add esp,4
 ret 
EXTRN _unixfgets:NEAR
 DD 3
; (*entry unixfgets expr 3)
 PUBLIC l0223
l0223:
 cmp symval+1220,0
 jge l0224
 mov edi,409
 jmp [symfnc+1636]
l0224:
 push ecx
 push ebx
 push eax
 call _unixfgets
 add esp,12
 ret 
EXTRN _unixfwrite:NEAR
 DD 4
; (*entry unixfwrite expr 4)
 PUBLIC l0225
l0225:
 cmp symval+1220,0
 jge l0226
 mov edi,409
 jmp [symfnc+1636]
l0226:
 push edx
 push ecx
 push ebx
 push eax
 call _unixfwrite
 add esp,16
 ret 
EXTRN _unixfflush:NEAR
 DD 1
; (*entry unixfflush expr 1)
 PUBLIC l0227
l0227:
 cmp symval+1220,0
 jge l0228
 mov edi,409
 jmp [symfnc+1636]
l0228:
 push eax
 call _unixfflush
 add esp,4
 ret 
EXTRN _ctime:NEAR
 DD 1
; (*entry ctime expr 1)
 PUBLIC l0229
l0229:
 push eax
 call _ctime
 add esp,4
 ret 
EXTRN _external_system:NEAR
 DD 1
; (*entry external_system expr 1)
 PUBLIC l0230
l0230:
 push eax
 call _external_system
 add esp,4
 ret 
EXTRN _external_exit:NEAR
 DD 1
; (*entry external_exit expr 1)
 PUBLIC l0231
l0231:
 push eax
 call _external_exit
 add esp,4
 ret 
EXTRN _fopen:NEAR
 DD 2
; (*entry fopen expr 2)
 PUBLIC l0232
l0232:
 push ebx
 push eax
 call _fopen
 add esp,8
 ret 
EXTRN _fclose:NEAR
 DD 1
; (*entry fclose expr 1)
 PUBLIC l0233
l0233:
 push eax
 call _fclose
 add esp,4
 ret 
EXTRN _fseek:NEAR
 DD 3
; (*entry fseek expr 3)
 PUBLIC l0234
l0234:
 push ecx
 push ebx
 push eax
 call _fseek
 add esp,12
 ret 
EXTRN _clearerr:NEAR
 DD 1
; (*entry clearerr expr 1)
 PUBLIC l0235
l0235:
 push eax
 call _clearerr
 add esp,4
 ret 
EXTRN __getw:NEAR
 DD 1
; (*entry getw expr 1)
 PUBLIC l0236
l0236:
 push eax
 call __getw
 add esp,4
 ret 
EXTRN __putw:NEAR
 DD 2
; (*entry putw expr 2)
 PUBLIC l0237
l0237:
 push ebx
 push eax
 call __putw
 add esp,8
 ret 
EXTRN _signal:NEAR
 DD 2
; (*entry signal expr 2)
 PUBLIC l0238
l0238:
 push ebx
 push eax
 call _signal
 add esp,8
 ret 
EXTRN _sleep:NEAR
 DD 1
; (*entry sleep expr 1)
 PUBLIC l0239
l0239:
 push eax
 call _sleep
 add esp,4
 ret 
EXTRN _ieee_handler:NEAR
 DD 3
; (*entry ieee_handler expr 3)
 PUBLIC l0240
l0240:
 push ecx
 push ebx
 push eax
 call _ieee_handler
 add esp,12
 ret 
EXTRN _ieee_flags:NEAR
 DD 4
; (*entry ieee_flags expr 4)
 PUBLIC l0241
l0241:
 push edx
 push ecx
 push ebx
 push eax
 call _ieee_flags
 add esp,16
 ret 
EXTRN _setlinebuf:NEAR
 DD 1
; (*entry setlinebuf expr 1)
 PUBLIC l0242
l0242:
 push eax
 call _setlinebuf
 add esp,4
 ret 
EXTRN _popen:NEAR
 DD 2
; (*entry popen expr 2)
 PUBLIC l0243
l0243:
 push ebx
 push eax
 call _popen
 add esp,8
 ret 
EXTRN _pclose:NEAR
 DD 1
; (*entry pclose expr 1)
 PUBLIC l0244
l0244:
 push eax
 call _pclose
 add esp,4
 ret 
EXTRN _profil:NEAR
 DD 4
; (*entry profil expr 4)
 PUBLIC l0245
l0245:
 push edx
 push ecx
 push ebx
 push eax
 call _profil
 add esp,16
 ret 
EXTRN _datetag:NEAR
 DD 0
; (*entry datetag expr 0)
 PUBLIC l0246
l0246:
 call _datetag
 add esp,0
 ret 
EXTRN _psll_call:NEAR
 DD 4
; (*entry psll_call expr 4)
 PUBLIC l0247
l0247:
 push edx
 push ecx
 push ebx
 push eax
 call _psll_call
 add esp,16
 ret 
 DD 4
; (*entry unix-profile expr 4)
 PUBLIC l0248
l0248:
 mov edi,479
 jmp [symfnc+1916]
 DD 4
; (*entry fread expr 4)
 PUBLIC fread
fread:
 mov edi,460
 jmp [symfnc+1840]
 DD 2
; (*entry fputc expr 2)
 PUBLIC fputc
fputc:
 mov edi,461
 jmp [symfnc+1844]
 DD 1
; (*entry fgetc expr 1)
 PUBLIC fgetc
fgetc:
 mov edi,462
 jmp [symfnc+1848]
 DD 3
; (*entry fgets expr 3)
 PUBLIC fgets
fgets:
 mov edi,463
 jmp [symfnc+1852]
 DD 4
; (*entry fwrite expr 4)
 PUBLIC fwrite
fwrite:
 mov edi,464
 jmp [symfnc+1856]
 DD 1
; (*entry fflush expr 1)
 PUBLIC fflush
fflush:
 mov edi,465
 jmp [symfnc+1860]
 DD 1
; (*entry plantunbound expr 1)
 PUBLIC plantunbound
plantunbound:
 mov  DWORD PTR [esp-32],eax
 push eax
 cmp eax,symval+1228
 jle l0249
 mov ebx,symval+1240
 add esp,4
 mov edi,488
 jmp [symfnc+1952]
l0249:
 mov ebx,symval+1240
 mov edi,488
 call [symfnc+1952]
 mov ebx,symval+1244
 mov eax,DWORD PTR [esp]
 add esp,4
 mov edi,488
 jmp [symfnc+1952]
 DD 2
; (*entry plantunbound-1 expr 2)
 PUBLIC l0250
l0250:
 add eax,eax
 mov esi,eax
 add esi,esi
 add esi,ebx
 mov edi,OFFSET l0251
 mov edi, DWORD PTR 0[edi]
 mov  DWORD PTR 0[esi],edi
 ret 
 DD 0
l0251:
 DD undefinedfunction
 DD 2
; (*entry plantcodepointer expr 2)
 PUBLIC plantcodepointer
plantcodepointer:
 mov  DWORD PTR [esp-32],eax
 push ebx
 push eax
 cmp eax,symval+1228
 jle l0252
 mov ecx,symval+1240
 add esp,8
 mov edi,489
 jmp [symfnc+1956]
l0252:
 mov ecx,symval+1240
 mov edi,489
 call [symfnc+1956]
 mov ecx,symval+1244
 mov ebx, DWORD PTR 4[esp]
 mov eax,DWORD PTR [esp]
 add esp,8
 mov edi,489
 jmp [symfnc+1956]
 DD 3
; (*entry plantcodepointer-1 expr 3)
 PUBLIC l0253
l0253:
 add eax,eax
 mov esi,eax
 add esi,esi
 add esi,ecx
 mov  DWORD PTR 0[esi],ebx
 ret 
 DD 1
; (*entry plantlambdalink expr 1)
 PUBLIC plantlambdalink
plantlambdalink:
 mov  DWORD PTR [esp-32],eax
 push eax
 cmp eax,symval+1228
 jle l0254
 mov ebx,symval+1240
 add esp,4
 mov edi,490
 jmp [symfnc+1960]
l0254:
 mov ebx,symval+1240
 mov edi,490
 call [symfnc+1960]
 mov ebx,symval+1244
 mov eax,DWORD PTR [esp]
 add esp,4
 mov edi,490
 jmp [symfnc+1960]
 DD 2
; (*entry plantlambdalink-1 expr 2)
 PUBLIC l0255
l0255:
 add eax,eax
 mov esi,eax
 add esi,esi
 add esi,ebx
 mov edi,OFFSET l0256
 mov edi, DWORD PTR 0[edi]
 mov  DWORD PTR 0[esi],edi
 ret 
 DD 0
l0256:
 DD compiledcallinginterpreted
 DD 1
; (*entry addressapply0 expr 1)
 PUBLIC l0257
l0257:
 jmp eax
 DD 2
; (*entry bittable expr 2)
 PUBLIC bittable
bittable:
 mov  DWORD PTR [esp-32],eax
 push ebx
 shr ebx,2
 mov al,0[eax][ebx*1]
 cbw 
 cwde 
 mov ebx,DWORD PTR [esp]
 and ebx,3
 add ebx,ebx
 add ebx,-6
 cmp ebx,0
 jge l0258
 neg ebx
 xchg ecx,ebx
 shr eax,cl
 jmp l0259
l0258:
 xchg ecx,ebx
 shl eax,cl
l0259:
 xchg ecx,ebx
 and eax,3
 add esp,4
 ret 
 DD 1
; (*entry undefinedfunction expr 1)
 PUBLIC undefinedfunction
undefinedfunction:
 jmp [symfnc+1976]
l0260:
 DD 26
 DB 85,110,100,101,102,105,110,101,100,32
 DB 102,117,110,99,116,105,111,110,32,99,97
 DB 108,108,101,100,58,32,0
 DD 1
; (*entry undefinedfunction-aux expr 1)
 PUBLIC l0261
l0261:
 push edi
 mov eax,4*08000000h+OFFSET l0260
 mov edi,331
 call [symfnc+1324]
 mov esi,symval+1404
 pop edi
 shl edi,2
 mov eax,0[esi][edi*1]
 mov edi,331
 call [symfnc+1324]
 xor eax,eax
 mov edi,321
 call [symfnc+1284]
 ret 
 DD 0
; (*entry compiledcallinginterpreted expr 0)
 PUBLIC compiledcallinginterpreted
compiledcallinginterpreted:
 and edi,134217727
 or edi,-268435456
 mov ds:symval+1988,edi
 mov edi,495
 jmp [symfnc+1980]
l0262:
 DD 12
 DB 70,65,84,65,76,32,69,82,82,79,82,58,32
 DB 0
 DD 1
; (*entry kernel-fatal-error expr 1)
 PUBLIC l0263
l0263:
 mov  DWORD PTR [esp-32],eax
 push eax
 mov eax,4*08000000h+OFFSET l0262
 mov edi,331
 call [symfnc+1324]
 mov eax,DWORD PTR [esp]
 mov edi,331
 call [symfnc+1324]
 mov edi,332
 call [symfnc+1328]
 xor eax,eax
 dec eax
 add esp,4
 mov edi,321
 jmp [symfnc+1284]
 DD 1
; (*entry codeaddressp expr 1)
 PUBLIC codeaddressp
codeaddressp:
 mov  DWORD PTR [esp-32],eax
 sub esp,4
 and eax,134217727
 mov DWORD PTR [esp],eax
 mov eax,30*08000000h+OFFSET 256
 mov edi,498
 call [symfnc+1992]
 and eax,134217727
 cmp eax,DWORD PTR [esp]
 jle l0264
 mov eax,30*08000000h+OFFSET 128
 jmp l0265
l0264:
 mov eax,30*08000000h+OFFSET 116
l0265:
 cmp eax,30*08000000h+OFFSET 128
 je l0266
 mov eax,30*08000000h+OFFSET 499
 mov edi,498
 call [symfnc+1992]
 and eax,134217727
 cmp eax,DWORD PTR [esp]
 jg l0267
 mov eax,30*08000000h+OFFSET 128
 jmp l0266
l0267:
 mov eax,30*08000000h+OFFSET 116
l0266:
 cmp eax,30*08000000h+OFFSET 128
 jne l0268
 mov eax,symval+1148
 and eax,134217727
 cmp eax,DWORD PTR [esp]
 jle l0269
 mov eax,30*08000000h+OFFSET 128
 jmp l0270
l0269:
 mov eax,30*08000000h+OFFSET 116
l0270:
 cmp eax,30*08000000h+OFFSET 128
 je l0268
 mov eax,symval+1172
 and eax,134217727
 cmp eax,DWORD PTR [esp]
 jg l0271
 mov eax,30*08000000h+OFFSET 128
 jmp l0268
l0271:
 mov eax,30*08000000h+OFFSET 116
l0268:
 add esp,4
 ret 
 DD 1
; (*entry lastkernel expr 1)
 PUBLIC lastkernel
lastkernel:
 ret 
 DD 0
; (*entry initcode expr 0)
 PUBLIC initcode
initcode:
 mov eax,30*08000000h+OFFSET 128
 ret 
 PUBLIC l0272
  align 4
l0272:
 DD 0
 DB 0,0
 PUBLIC l0273
  align 4
l0273:
 DD 0
 DB 1,0
 PUBLIC l0274
  align 4
l0274:
 DD 0
 DB 2,0
 PUBLIC l0275
  align 4
l0275:
 DD 0
 DB 3,0
 PUBLIC l0276
  align 4
l0276:
 DD 0
 DB 4,0
 PUBLIC l0277
  align 4
l0277:
 DD 0
 DB 5,0
 PUBLIC l0278
  align 4
l0278:
 DD 0
 DB 6,0
 PUBLIC l0279
  align 4
l0279:
 DD 0
 DB 7,0
 PUBLIC l0280
  align 4
l0280:
 DD 0
 DB 8,0
 PUBLIC l0281
  align 4
l0281:
 DD 0
 DB 9,0
 PUBLIC l0282
  align 4
l0282:
 DD 0
 DB 10,0
 PUBLIC l0283
  align 4
l0283:
 DD 0
 DB 11,0
 PUBLIC l0284
  align 4
l0284:
 DD 0
 DB 12,0
 PUBLIC l0285
  align 4
l0285:
 DD 0
 DB 13,0
 PUBLIC l0286
  align 4
l0286:
 DD 0
 DB 14,0
 PUBLIC l0287
  align 4
l0287:
 DD 0
 DB 15,0
 PUBLIC l0288
  align 4
l0288:
 DD 0
 DB 16,0
 PUBLIC l0289
  align 4
l0289:
 DD 0
 DB 17,0
 PUBLIC l0290
  align 4
l0290:
 DD 0
 DB 18,0
 PUBLIC l0291
  align 4
l0291:
 DD 0
 DB 19,0
 PUBLIC l0292
  align 4
l0292:
 DD 0
 DB 20,0
 PUBLIC l0293
  align 4
l0293:
 DD 0
 DB 21,0
 PUBLIC l0294
  align 4
l0294:
 DD 0
 DB 22,0
 PUBLIC l0295
  align 4
l0295:
 DD 0
 DB 23,0
 PUBLIC l0296
  align 4
l0296:
 DD 0
 DB 24,0
 PUBLIC l0297
  align 4
l0297:
 DD 0
 DB 25,0
 PUBLIC l0298
  align 4
l0298:
 DD 0
 DB 26,0
 PUBLIC l0299
  align 4
l0299:
 DD 0
 DB 27,0
 PUBLIC l0300
  align 4
l0300:
 DD 0
 DB 28,0
 PUBLIC l0301
  align 4
l0301:
 DD 0
 DB 29,0
 PUBLIC l0302
  align 4
l0302:
 DD 0
 DB 30,0
 PUBLIC l0303
  align 4
l0303:
 DD 0
 DB 31,0
 PUBLIC l0304
  align 4
l0304:
 DD 0
 DB 32,0
 PUBLIC l0305
  align 4
l0305:
 DD 0
 DB 33,0
 PUBLIC l0306
  align 4
l0306:
 DD 0
 DB 34,0
 PUBLIC l0307
  align 4
l0307:
 DD 0
 DB 35,0
 PUBLIC l0308
  align 4
l0308:
 DD 0
 DB 36,0
 PUBLIC l0309
  align 4
l0309:
 DD 0
 DB 37,0
 PUBLIC l0310
  align 4
l0310:
 DD 0
 DB 38,0
 PUBLIC l0311
  align 4
l0311:
 DD 0
 DB 39,0
 PUBLIC l0312
  align 4
l0312:
 DD 0
 DB 40,0
 PUBLIC l0313
  align 4
l0313:
 DD 0
 DB 41,0
 PUBLIC l0314
  align 4
l0314:
 DD 0
 DB 42,0
 PUBLIC l0315
  align 4
l0315:
 DD 0
 DB 43,0
 PUBLIC l0316
  align 4
l0316:
 DD 0
 DB 44,0
 PUBLIC l0317
  align 4
l0317:
 DD 0
 DB 45,0
 PUBLIC l0318
  align 4
l0318:
 DD 0
 DB 46,0
 PUBLIC l0319
  align 4
l0319:
 DD 0
 DB 47,0
 PUBLIC l0320
  align 4
l0320:
 DD 0
 DB 48,0
 PUBLIC l0321
  align 4
l0321:
 DD 0
 DB 49,0
 PUBLIC l0322
  align 4
l0322:
 DD 0
 DB 50,0
 PUBLIC l0323
  align 4
l0323:
 DD 0
 DB 51,0
 PUBLIC l0324
  align 4
l0324:
 DD 0
 DB 52,0
 PUBLIC l0325
  align 4
l0325:
 DD 0
 DB 53,0
 PUBLIC l0326
  align 4
l0326:
 DD 0
 DB 54,0
 PUBLIC l0327
  align 4
l0327:
 DD 0
 DB 55,0
 PUBLIC l0328
  align 4
l0328:
 DD 0
 DB 56,0
 PUBLIC l0329
  align 4
l0329:
 DD 0
 DB 57,0
 PUBLIC l0330
  align 4
l0330:
 DD 0
 DB 58,0
 PUBLIC l0331
  align 4
l0331:
 DD 0
 DB 59,0
 PUBLIC l0332
  align 4
l0332:
 DD 0
 DB 60,0
 PUBLIC l0333
  align 4
l0333:
 DD 0
 DB 61,0
 PUBLIC l0334
  align 4
l0334:
 DD 0
 DB 62,0
 PUBLIC l0335
  align 4
l0335:
 DD 0
 DB 63,0
 PUBLIC l0336
  align 4
l0336:
 DD 0
 DB 64,0
 PUBLIC l0337
  align 4
l0337:
 DD 0
 DB 65,0
 PUBLIC l0338
  align 4
l0338:
 DD 0
 DB 66,0
 PUBLIC l0339
  align 4
l0339:
 DD 0
 DB 67,0
 PUBLIC l0340
  align 4
l0340:
 DD 0
 DB 68,0
 PUBLIC l0341
  align 4
l0341:
 DD 0
 DB 69,0
 PUBLIC l0342
  align 4
l0342:
 DD 0
 DB 70,0
 PUBLIC l0343
  align 4
l0343:
 DD 0
 DB 71,0
 PUBLIC l0344
  align 4
l0344:
 DD 0
 DB 72,0
 PUBLIC l0345
  align 4
l0345:
 DD 0
 DB 73,0
 PUBLIC l0346
  align 4
l0346:
 DD 0
 DB 74,0
 PUBLIC l0347
  align 4
l0347:
 DD 0
 DB 75,0
 PUBLIC l0348
  align 4
l0348:
 DD 0
 DB 76,0
 PUBLIC l0349
  align 4
l0349:
 DD 0
 DB 77,0
 PUBLIC l0350
  align 4
l0350:
 DD 0
 DB 78,0
 PUBLIC l0351
  align 4
l0351:
 DD 0
 DB 79,0
 PUBLIC l0352
  align 4
l0352:
 DD 0
 DB 80,0
 PUBLIC l0353
  align 4
l0353:
 DD 0
 DB 81,0
 PUBLIC l0354
  align 4
l0354:
 DD 0
 DB 82,0
 PUBLIC l0355
  align 4
l0355:
 DD 0
 DB 83,0
 PUBLIC l0356
  align 4
l0356:
 DD 0
 DB 84,0
 PUBLIC l0357
  align 4
l0357:
 DD 0
 DB 85,0
 PUBLIC l0358
  align 4
l0358:
 DD 0
 DB 86,0
 PUBLIC l0359
  align 4
l0359:
 DD 0
 DB 87,0
 PUBLIC l0360
  align 4
l0360:
 DD 0
 DB 88,0
 PUBLIC l0361
  align 4
l0361:
 DD 0
 DB 89,0
 PUBLIC l0362
  align 4
l0362:
 DD 0
 DB 90,0
 PUBLIC l0363
  align 4
l0363:
 DD 0
 DB 91,0
 PUBLIC l0364
  align 4
l0364:
 DD 0
 DB 92,0
 PUBLIC l0365
  align 4
l0365:
 DD 0
 DB 93,0
 PUBLIC l0366
  align 4
l0366:
 DD 0
 DB 94,0
 PUBLIC l0367
  align 4
l0367:
 DD 0
 DB 95,0
 PUBLIC l0368
  align 4
l0368:
 DD 0
 DB 96,0
 PUBLIC l0369
  align 4
l0369:
 DD 0
 DB 97,0
 PUBLIC l0370
  align 4
l0370:
 DD 0
 DB 98,0
 PUBLIC l0371
  align 4
l0371:
 DD 0
 DB 99,0
 PUBLIC l0372
  align 4
l0372:
 DD 0
 DB 100,0
 PUBLIC l0373
  align 4
l0373:
 DD 0
 DB 101,0
 PUBLIC l0374
  align 4
l0374:
 DD 0
 DB 102,0
 PUBLIC l0375
  align 4
l0375:
 DD 0
 DB 103,0
 PUBLIC l0376
  align 4
l0376:
 DD 0
 DB 104,0
 PUBLIC l0377
  align 4
l0377:
 DD 0
 DB 105,0
 PUBLIC l0378
  align 4
l0378:
 DD 0
 DB 106,0
 PUBLIC l0379
  align 4
l0379:
 DD 0
 DB 107,0
 PUBLIC l0380
  align 4
l0380:
 DD 0
 DB 108,0
 PUBLIC l0381
  align 4
l0381:
 DD 0
 DB 109,0
 PUBLIC l0382
  align 4
l0382:
 DD 0
 DB 110,0
 PUBLIC l0383
  align 4
l0383:
 DD 0
 DB 111,0
 PUBLIC l0384
  align 4
l0384:
 DD 0
 DB 112,0
 PUBLIC l0385
  align 4
l0385:
 DD 0
 DB 113,0
 PUBLIC l0386
  align 4
l0386:
 DD 0
 DB 114,0
 PUBLIC l0387
  align 4
l0387:
 DD 0
 DB 115,0
 PUBLIC l0388
  align 4
l0388:
 DD 0
 DB 116,0
 PUBLIC l0389
  align 4
l0389:
 DD 0
 DB 117,0
 PUBLIC l0390
  align 4
l0390:
 DD 0
 DB 118,0
 PUBLIC l0391
  align 4
l0391:
 DD 0
 DB 119,0
 PUBLIC l0392
  align 4
l0392:
 DD 0
 DB 120,0
 PUBLIC l0393
  align 4
l0393:
 DD 0
 DB 121,0
 PUBLIC l0394
  align 4
l0394:
 DD 0
 DB 122,0
 PUBLIC l0395
  align 4
l0395:
 DD 0
 DB 123,0
 PUBLIC l0396
  align 4
l0396:
 DD 0
 DB 124,0
 PUBLIC l0397
  align 4
l0397:
 DD 0
 DB 125,0
 PUBLIC l0398
  align 4
l0398:
 DD 0
 DB 126,0
 PUBLIC l0399
  align 4
l0399:
 DD 0
 DB 127,0
 PUBLIC l0400
  align 4
l0400:
 DD 2
 DB 110,105,108,0
 PUBLIC l0401
  align 4
l0401:
 DD 0
 DB -127,0
 PUBLIC l0402
  align 4
l0402:
 DD 0
 DB -126,0
 PUBLIC l0403
  align 4
l0403:
 DD 0
 DB -125,0
 PUBLIC l0404
  align 4
l0404:
 DD 0
 DB -124,0
 PUBLIC l0405
  align 4
l0405:
 DD 0
 DB -123,0
 PUBLIC l0406
  align 4
l0406:
 DD 0
 DB -122,0
 PUBLIC l0407
  align 4
l0407:
 DD 0
 DB -121,0
 PUBLIC l0408
  align 4
l0408:
 DD 0
 DB -120,0
 PUBLIC l0409
  align 4
l0409:
 DD 0
 DB -119,0
 PUBLIC l0410
  align 4
l0410:
 DD 0
 DB -118,0
 PUBLIC l0411
  align 4
l0411:
 DD 0
 DB -117,0
 PUBLIC l0412
  align 4
l0412:
 DD 0
 DB -116,0
 PUBLIC l0413
  align 4
l0413:
 DD 0
 DB -115,0
 PUBLIC l0414
  align 4
l0414:
 DD 0
 DB -114,0
 PUBLIC l0415
  align 4
l0415:
 DD 0
 DB -113,0
 PUBLIC l0416
  align 4
l0416:
 DD 0
 DB -112,0
 PUBLIC l0417
  align 4
l0417:
 DD 0
 DB -111,0
 PUBLIC l0418
  align 4
l0418:
 DD 0
 DB -110,0
 PUBLIC l0419
  align 4
l0419:
 DD 0
 DB -109,0
 PUBLIC l0420
  align 4
l0420:
 DD 0
 DB -108,0
 PUBLIC l0421
  align 4
l0421:
 DD 0
 DB -107,0
 PUBLIC l0422
  align 4
l0422:
 DD 0
 DB -106,0
 PUBLIC l0423
  align 4
l0423:
 DD 0
 DB -105,0
 PUBLIC l0424
  align 4
l0424:
 DD 0
 DB -104,0
 PUBLIC l0425
  align 4
l0425:
 DD 0
 DB -103,0
 PUBLIC l0426
  align 4
l0426:
 DD 0
 DB -102,0
 PUBLIC l0427
  align 4
l0427:
 DD 0
 DB -101,0
 PUBLIC l0428
  align 4
l0428:
 DD 0
 DB -100,0
 PUBLIC l0429
  align 4
l0429:
 DD 0
 DB -99,0
 PUBLIC l0430
  align 4
l0430:
 DD 0
 DB -98,0
 PUBLIC l0431
  align 4
l0431:
 DD 0
 DB -97,0
 PUBLIC l0432
  align 4
l0432:
 DD 0
 DB -96,0
 PUBLIC l0433
  align 4
l0433:
 DD 0
 DB -95,0
 PUBLIC l0434
  align 4
l0434:
 DD 0
 DB -94,0
 PUBLIC l0435
  align 4
l0435:
 DD 0
 DB -93,0
 PUBLIC l0436
  align 4
l0436:
 DD 0
 DB -92,0
 PUBLIC l0437
  align 4
l0437:
 DD 0
 DB -91,0
 PUBLIC l0438
  align 4
l0438:
 DD 0
 DB -90,0
 PUBLIC l0439
  align 4
l0439:
 DD 0
 DB -89,0
 PUBLIC l0440
  align 4
l0440:
 DD 0
 DB -88,0
 PUBLIC l0441
  align 4
l0441:
 DD 0
 DB -87,0
 PUBLIC l0442
  align 4
l0442:
 DD 0
 DB -86,0
 PUBLIC l0443
  align 4
l0443:
 DD 0
 DB -85,0
 PUBLIC l0444
  align 4
l0444:
 DD 0
 DB -84,0
 PUBLIC l0445
  align 4
l0445:
 DD 0
 DB -83,0
 PUBLIC l0446
  align 4
l0446:
 DD 0
 DB -82,0
 PUBLIC l0447
  align 4
l0447:
 DD 0
 DB -81,0
 PUBLIC l0448
  align 4
l0448:
 DD 0
 DB -80,0
 PUBLIC l0449
  align 4
l0449:
 DD 0
 DB -79,0
 PUBLIC l0450
  align 4
l0450:
 DD 0
 DB -78,0
 PUBLIC l0451
  align 4
l0451:
 DD 0
 DB -77,0
 PUBLIC l0452
  align 4
l0452:
 DD 0
 DB -76,0
 PUBLIC l0453
  align 4
l0453:
 DD 0
 DB -75,0
 PUBLIC l0454
  align 4
l0454:
 DD 0
 DB -74,0
 PUBLIC l0455
  align 4
l0455:
 DD 0
 DB -73,0
 PUBLIC l0456
  align 4
l0456:
 DD 0
 DB -72,0
 PUBLIC l0457
  align 4
l0457:
 DD 0
 DB -71,0
 PUBLIC l0458
  align 4
l0458:
 DD 0
 DB -70,0
 PUBLIC l0459
  align 4
l0459:
 DD 0
 DB -69,0
 PUBLIC l0460
  align 4
l0460:
 DD 0
 DB -68,0
 PUBLIC l0461
  align 4
l0461:
 DD 0
 DB -67,0
 PUBLIC l0462
  align 4
l0462:
 DD 0
 DB -66,0
 PUBLIC l0463
  align 4
l0463:
 DD 0
 DB -65,0
 PUBLIC l0464
  align 4
l0464:
 DD 0
 DB -64,0
 PUBLIC l0465
  align 4
l0465:
 DD 0
 DB -63,0
 PUBLIC l0466
  align 4
l0466:
 DD 0
 DB -62,0
 PUBLIC l0467
  align 4
l0467:
 DD 0
 DB -61,0
 PUBLIC l0468
  align 4
l0468:
 DD 0
 DB -60,0
 PUBLIC l0469
  align 4
l0469:
 DD 0
 DB -59,0
 PUBLIC l0470
  align 4
l0470:
 DD 0
 DB -58,0
 PUBLIC l0471
  align 4
l0471:
 DD 0
 DB -57,0
 PUBLIC l0472
  align 4
l0472:
 DD 0
 DB -56,0
 PUBLIC l0473
  align 4
l0473:
 DD 0
 DB -55,0
 PUBLIC l0474
  align 4
l0474:
 DD 0
 DB -54,0
 PUBLIC l0475
  align 4
l0475:
 DD 0
 DB -53,0
 PUBLIC l0476
  align 4
l0476:
 DD 0
 DB -52,0
 PUBLIC l0477
  align 4
l0477:
 DD 0
 DB -51,0
 PUBLIC l0478
  align 4
l0478:
 DD 0
 DB -50,0
 PUBLIC l0479
  align 4
l0479:
 DD 0
 DB -49,0
 PUBLIC l0480
  align 4
l0480:
 DD 0
 DB -48,0
 PUBLIC l0481
  align 4
l0481:
 DD 0
 DB -47,0
 PUBLIC l0482
  align 4
l0482:
 DD 0
 DB -46,0
 PUBLIC l0483
  align 4
l0483:
 DD 0
 DB -45,0
 PUBLIC l0484
  align 4
l0484:
 DD 0
 DB -44,0
 PUBLIC l0485
  align 4
l0485:
 DD 0
 DB -43,0
 PUBLIC l0486
  align 4
l0486:
 DD 0
 DB -42,0
 PUBLIC l0487
  align 4
l0487:
 DD 0
 DB -41,0
 PUBLIC l0488
  align 4
l0488:
 DD 0
 DB -40,0
 PUBLIC l0489
  align 4
l0489:
 DD 0
 DB -39,0
 PUBLIC l0490
  align 4
l0490:
 DD 0
 DB -38,0
 PUBLIC l0491
  align 4
l0491:
 DD 0
 DB -37,0
 PUBLIC l0492
  align 4
l0492:
 DD 0
 DB -36,0
 PUBLIC l0493
  align 4
l0493:
 DD 0
 DB -35,0
 PUBLIC l0494
  align 4
l0494:
 DD 0
 DB -34,0
 PUBLIC l0495
  align 4
l0495:
 DD 0
 DB -33,0
 PUBLIC l0496
  align 4
l0496:
 DD 0
 DB -32,0
 PUBLIC l0497
  align 4
l0497:
 DD 0
 DB -31,0
 PUBLIC l0498
  align 4
l0498:
 DD 0
 DB -30,0
 PUBLIC l0499
  align 4
l0499:
 DD 0
 DB -29,0
 PUBLIC l0500
  align 4
l0500:
 DD 0
 DB -28,0
 PUBLIC l0501
  align 4
l0501:
 DD 0
 DB -27,0
 PUBLIC l0502
  align 4
l0502:
 DD 0
 DB -26,0
 PUBLIC l0503
  align 4
l0503:
 DD 0
 DB -25,0
 PUBLIC l0504
  align 4
l0504:
 DD 0
 DB -24,0
 PUBLIC l0505
  align 4
l0505:
 DD 0
 DB -23,0
 PUBLIC l0506
  align 4
l0506:
 DD 0
 DB -22,0
 PUBLIC l0507
  align 4
l0507:
 DD 0
 DB -21,0
 PUBLIC l0508
  align 4
l0508:
 DD 0
 DB -20,0
 PUBLIC l0509
  align 4
l0509:
 DD 0
 DB -19,0
 PUBLIC l0510
  align 4
l0510:
 DD 0
 DB -18,0
 PUBLIC l0511
  align 4
l0511:
 DD 0
 DB -17,0
 PUBLIC l0512
  align 4
l0512:
 DD 0
 DB -16,0
 PUBLIC l0513
  align 4
l0513:
 DD 0
 DB -15,0
 PUBLIC l0514
  align 4
l0514:
 DD 0
 DB -14,0
 PUBLIC l0515
  align 4
l0515:
 DD 0
 DB -13,0
 PUBLIC l0516
  align 4
l0516:
 DD 0
 DB -12,0
 PUBLIC l0517
  align 4
l0517:
 DD 0
 DB -11,0
 PUBLIC l0518
  align 4
l0518:
 DD 0
 DB -10,0
 PUBLIC l0519
  align 4
l0519:
 DD 0
 DB -9,0
 PUBLIC l0520
  align 4
l0520:
 DD 0
 DB -8,0
 PUBLIC l0521
  align 4
l0521:
 DD 0
 DB -7,0
 PUBLIC l0522
  align 4
l0522:
 DD 0
 DB -6,0
 PUBLIC l0523
  align 4
l0523:
 DD 0
 DB -5,0
 PUBLIC l0524
  align 4
l0524:
 DD 0
 DB -4,0
 PUBLIC l0525
  align 4
l0525:
 DD 0
 DB -3,0
 PUBLIC l0526
  align 4
l0526:
 DD 0
 DB -2,0
 PUBLIC l0527
  align 4
l0527:
 DD 0
 DB -1,0
 PUBLIC l0528
  align 4
l0528:
 DD 10
 DB 102,105,114,115,116,107,101,114,110,101
 DB 108,0
 PUBLIC l0529
  align 4
l0529:
 DD 12
 DB 97,114,103,117,109,101,110,116,98,108
 DB 111,99,107,0
 PUBLIC l0530
  align 4
l0530:
 DD 10
 DB 116,111,107,101,110,98,117,102,102,101
 DB 114,0
 PUBLIC l0531
  align 4
l0531:
 DD 5
 DB 98,110,100,115,116,107,0,0
 PUBLIC l0532
  align 4
l0532:
 DD 9
 DB 99,97,116,99,104,115,116,97,99,107,0,0
 PUBLIC l0533
  align 4
l0533:
 DD 8
 DB 104,97,115,104,116,97,98,108,101,0
 PUBLIC l0534
  align 4
l0534:
 DD 12
 DB 111,110,101,119,111,114,100,98,117,102
 DB 102,101,114,0
 PUBLIC l0535
  align 4
l0535:
 DD 7
 DB 115,97,118,101,97,114,103,99,0,0
 PUBLIC l0536
  align 4
l0536:
 DD 7
 DB 115,97,118,101,97,114,103,118,0,0
 PUBLIC l0537
  align 4
l0537:
 DD 9
 DB 100,97,116,101,98,117,102,102,101,114
 DB 0,0
 PUBLIC l0538
  align 4
l0538:
 DD 12
 DB 105,110,105,116,45,112,111,105,110,116
 DB 101,114,115,0
 PUBLIC l0539
  align 4
l0539:
 DD 12
 DB 112,115,108,95,99,97,108,108,98,97,99
 DB 107,49,0
 PUBLIC l0540
  align 4
l0540:
 DD 12
 DB 112,115,108,95,99,97,108,108,98,97,99
 DB 107,50,0
 PUBLIC l0541
  align 4
l0541:
 DD 12
 DB 112,115,108,95,99,97,108,108,98,97,99
 DB 107,51,0
 PUBLIC l0542
  align 4
l0542:
 DD 12
 DB 112,115,108,95,99,97,108,108,98,97,99
 DB 107,52,0
 PUBLIC l0543
  align 4
l0543:
 DD 4
 DB 115,116,97,99,107,0
 PUBLIC l0544
  align 4
l0544:
 DD 14
 DB 115,116,97,99,107,117,112,112,101,114
 DB 98,111,117,110,100,0
 PUBLIC l0545
  align 4
l0545:
 DD 12
 DB 99,97,116,99,104,115,116,97,99,107,112
 DB 116,114,0
 PUBLIC l0546
  align 4
l0546:
 DD 15
 DB 98,110,100,115,116,107,108,111,119,101
 DB 114,98,111,117,110,100,0,0
 PUBLIC l0547
  align 4
l0547:
 DD 15
 DB 98,110,100,115,116,107,117,112,112,101
 DB 114,98,111,117,110,100,0,0
 PUBLIC l0548
  align 4
l0548:
 DD 8
 DB 98,110,100,115,116,107,112,116,114,0
 PUBLIC l0549
  align 4
l0549:
 DD 13
 DB 104,101,97,112,108,111,119,101,114,98
 DB 111,117,110,100,0,0
 PUBLIC l0550
  align 4
l0550:
 DD 3
 DB 104,101,97,112,0,0
 PUBLIC l0551
  align 4
l0551:
 DD 10
 DB 105,110,105,116,45,102,108,117,105,100
 DB 115,0
 PUBLIC l0552
  align 4
l0552:
 DD 16
 DB 103,99,97,114,114,97,121,108,111,119,101
 DB 114,98,111,117,110,100,0
 PUBLIC l0553
  align 4
l0553:
 DD 16
 DB 103,99,97,114,114,97,121,117,112,112,101
 DB 114,98,111,117,110,100,0
 PUBLIC l0554
  align 4
l0554:
 DD 7
 DB 104,101,97,112,108,97,115,116,0,0
 PUBLIC l0555
  align 4
l0555:
 DD 12
 DB 104,101,97,112,116,114,97,112,98,111,117
 DB 110,100,0
 PUBLIC l0556
  align 4
l0556:
 DD 13
 DB 104,101,97,112,117,112,112,101,114,98
 DB 111,117,110,100,0,0
 PUBLIC l0557
  align 4
l0557:
 DD 13
 DB 95,105,110,102,98,105,116,108,101,110
 DB 103,116,104,95,0,0
 PUBLIC l0558
  align 4
l0558:
 DD 6
 DB 108,97,115,116,98,112,115,0
 PUBLIC l0559
  align 4
l0559:
 DD 12
 DB 98,112,115,108,111,119,101,114,98,111
 DB 117,110,100,0
 PUBLIC l0560
  align 4
l0560:
 DD 10
 DB 111,108,100,104,101,97,112,108,97,115
 DB 116,0
 PUBLIC l0561
  align 4
l0561:
 DD 16
 DB 111,108,100,104,101,97,112,108,111,119
 DB 101,114,98,111,117,110,100,0
 PUBLIC l0562
  align 4
l0562:
 DD 15
 DB 111,108,100,104,101,97,112,116,114,97
 DB 112,98,111,117,110,100,0,0
 PUBLIC l0563
  align 4
l0563:
 DD 16
 DB 111,108,100,104,101,97,112,117,112,112
 DB 101,114,98,111,117,110,100,0
 PUBLIC l0564
  align 4
l0564:
 DD 18
 DB 109,97,105,110,115,116,97,114,116,105
 DB 110,105,116,105,97,108,105,122,101,0
 PUBLIC l0565
  align 4
l0565:
 DD 6
 DB 110,101,120,116,98,112,115,0
 PUBLIC l0566
  align 4
l0566:
 DD 8
 DB 117,110,105,120,115,116,100,105,110,0
 PUBLIC l0567
  align 4
l0567:
 DD 9
 DB 117,110,105,120,115,116,100,111,117,116
 DB 0,0
 PUBLIC l0568
  align 4
l0568:
 DD 9
 DB 117,110,105,120,115,116,100,101,114,114
 DB 0,0
 PUBLIC l0569
  align 4
l0569:
 DD 7
 DB 117,110,105,120,110,117,108,108,0,0
 PUBLIC l0570
  align 4
l0570:
 DD 6
 DB 117,110,105,120,101,111,102,0
 PUBLIC l0571
  align 4
l0571:
 DD 6
 DB 117,110,105,120,116,116,121,0
 PUBLIC l0572
  align 4
l0572:
 DD 16
 DB 42,42,42,109,117,115,116,45,98,101,45
 DB 110,105,108,42,42,42,0
 PUBLIC l0573
  align 4
l0573:
 DD 20
 DB 42,42,42,109,117,115,116,45,98,101,45
 DB 110,105,108,45,116,111,111,42,42,42,0
 PUBLIC l0574
  align 4
l0574:
 DD 7
 DB 42,102,97,115,116,99,97,114,0,0
 PUBLIC l0575
  align 4
l0575:
 DD 8
 DB 42,42,119,105,110,100,111,119,115,0
 PUBLIC l0576
  align 4
l0576:
 DD 13
 DB 38,38,105,110,105,116,45,116,97,98,108
 DB 101,115,49,0,0
 PUBLIC l0577
  align 4
l0577:
 DD 10
 DB 98,114,117,99,104,95,98,114,117,99,104
 DB 0
 PUBLIC l0578
  align 4
l0578:
 DD 9
 DB 110,101,120,116,115,121,109,98,111,108
 DB 0,0
 PUBLIC l0579
  align 4
l0579:
 DD 16
 DB 107,101,114,110,101,108,45,109,97,120
 DB 115,121,109,98,111,108,115,0
 PUBLIC l0580
  align 4
l0580:
 DD 5
 DB 115,121,109,118,97,108,0,0
 PUBLIC l0581
  align 4
l0581:
 DD 9
 DB 111,108,100,95,115,121,109,118,97,108
 DB 0,0
 PUBLIC l0582
  align 4
l0582:
 DD 5
 DB 115,121,109,102,110,99,0,0
 PUBLIC l0583
  align 4
l0583:
 DD 9
 DB 111,108,100,95,115,121,109,102,110,99
 DB 0,0
 PUBLIC l0584
  align 4
l0584:
 DD 5
 DB 115,121,109,112,114,112,0,0
 PUBLIC l0585
  align 4
l0585:
 DD 9
 DB 111,108,100,95,115,121,109,112,114,112
 DB 0,0
 PUBLIC l0586
  align 4
l0586:
 DD 4
 DB 115,121,109,109,115,0
 PUBLIC l0587
  align 4
l0587:
 DD 8
 DB 38,38,115,121,109,99,111,112,121,0
 PUBLIC l0588
  align 4
l0588:
 DD 11
 DB 105,110,105,116,45,103,99,97,114,114,97
 DB 121,0,0
 PUBLIC l0589
  align 4
l0589:
 DD 13
 DB 38,38,105,110,105,116,45,116,97,98,108
 DB 101,115,50,0,0
 PUBLIC l0590
  align 4
l0590:
 DD 14
 DB 111,115,95,115,116,97,114,116,117,112
 DB 95,104,111,111,107,0
 PUBLIC l0591
  align 4
l0591:
 DD 12
 DB 38,116,105,109,101,45,99,111,110,116,114
 DB 111,108,0
 PUBLIC l0592
  align 4
l0592:
 DD 7
 DB 112,114,101,45,109,97,105,110,0,0
 PUBLIC l0593
  align 4
l0593:
 DD 15
 DB 101,120,105,116,45,119,105,116,104,45
 DB 115,116,97,116,117,115,0,0
 PUBLIC l0594
  align 4
l0594:
 DD 12
 DB 101,120,116,101,114,110,97,108,95,101
 DB 120,105,116,0
 PUBLIC l0595
  align 4
l0595:
 DD 8
 DB 95,112,115,108,95,109,97,105,110,0
 PUBLIC l0596
  align 4
l0596:
 DD 14
 DB 115,116,97,99,107,108,111,119,101,114
 DB 98,111,117,110,100,0
 PUBLIC l0597
  align 4
l0597:
 DD 3
 DB 97,114,103,99,0,0
 PUBLIC l0598
  align 4
l0598:
 DD 3
 DB 97,114,103,118,0,0
 PUBLIC l0599
  align 4
l0599:
 DD 8
 DB 112,115,108,95,99,97,108,108,49,0
 PUBLIC l0600
  align 4
l0600:
 DD 8
 DB 95,112,115,108,95,99,97,108,108,0
 PUBLIC l0601
  align 4
l0601:
 DD 22
 DB 105,110,105,116,105,97,108,105,122,101
 DB 45,115,121,109,98,111,108,45,116,97,98
 DB 108,101,0
 PUBLIC l0602
  align 4
l0602:
 DD 7
 DB 105,110,105,116,99,111,100,101,0,0
 PUBLIC l0603
  align 4
l0603:
 DD 19
 DB 99,111,110,115,111,108,101,45,112,114
 DB 105,110,116,45,115,116,114,105,110,103
 DB 0,0
 PUBLIC l0604
  align 4
l0604:
 DD 14
 DB 99,111,110,115,111,108,101,45,110,101
 DB 119,108,105,110,101,0
 PUBLIC l0605
  align 4
l0605:
 DD 5
 DB 102,97,115,108,105,110,0,0
 PUBLIC l0606
  align 4
l0606:
 DD 10
 DB 108,111,97,100,101,114,45,109,97,105,110
 DB 0
 PUBLIC l0607
  align 4
l0607:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,115
 DB 116,114,108,101,110,0
 PUBLIC l0608
  align 4
l0608:
 DD 5
 DB 32,121,105,101,108,100,0,0
 PUBLIC l0609
  align 4
l0609:
 DD 7
 DB 117,110,105,120,112,117,116,115,0,0
 PUBLIC l0610
  align 4
l0610:
 DD 7
 DB 117,110,105,120,112,117,116,110,0,0
 PUBLIC l0611
  align 4
l0611:
 DD 19
 DB 99,111,110,115,111,108,101,45,112,114
 DB 105,110,116,45,110,117,109,98,101,114
 DB 0,0
 PUBLIC l0612
  align 4
l0612:
 DD 7
 DB 117,110,105,120,112,117,116,99,0,0
 PUBLIC l0613
  align 4
l0613:
 DD 7
 DB 117,110,105,120,111,112,101,110,0,0
 PUBLIC l0614
  align 4
l0614:
 DD 17
 DB 107,101,114,110,101,108,45,102,97,116
 DB 97,108,45,101,114,114,111,114,0,0
 PUBLIC l0615
  align 4
l0615:
 DD 13
 DB 98,105,110,97,114,121,111,112,101,110
 DB 114,101,97,100,0,0
 PUBLIC l0616
  align 4
l0616:
 DD 3
 DB 103,101,116,119,0,0
 PUBLIC l0617
  align 4
l0617:
 DD 9
 DB 98,105,110,97,114,121,114,101,97,100,0
 DB 0
 PUBLIC l0618
  align 4
l0618:
 DD 4
 DB 102,114,101,97,100,0
 PUBLIC l0619
  align 4
l0619:
 DD 14
 DB 98,105,110,97,114,121,114,101,97,100,98
 DB 108,111,99,107,0
 PUBLIC l0620
  align 4
l0620:
 DD 5
 DB 102,99,108,111,115,101,0,0
 PUBLIC l0621
  align 4
l0621:
 DD 10
 DB 98,105,110,97,114,121,99,108,111,115,101
 DB 0
 PUBLIC l0622
  align 4
l0622:
 DD 14
 DB 104,97,115,104,45,105,110,116,111,45,116
 DB 97,98,108,101,0
 PUBLIC l0623
  align 4
l0623:
 DD 5
 DB 115,121,109,110,97,109,0,0
 PUBLIC l0624
  align 4
l0624:
 DD 11
 DB 115,104,111,119,45,110,101,119,45,105
 DB 100,115,0,0
 PUBLIC l0625
  align 4
l0625:
 DD 26
 DB 115,101,97,114,99,104,45,115,116,114,105
 DB 110,103,45,102,111,114,45,99,104,97,114
 DB 97,99,116,101,114,0
 PUBLIC l0626
  align 4
l0626:
 DD 5
 DB 105,110,116,101,114,110,0,0
 PUBLIC l0627
  align 4
l0627:
 DD 5
 DB 115,117,98,115,101,113,0,0
 PUBLIC l0628
  align 4
l0628:
 DD 12
 DB 102,97,115,108,105,110,45,105,110,116
 DB 101,114,110,0
 PUBLIC l0629
  align 4
l0629:
 DD 22
 DB 117,110,99,104,101,99,107,101,100,45,115
 DB 116,114,105,110,103,45,105,110,116,101
 DB 114,110,0
 PUBLIC l0630
  align 4
l0630:
 DD 3
 DB 103,116,105,100,0,0
 PUBLIC l0631
  align 4
l0631:
 DD 9
 DB 103,116,99,111,110,115,116,115,116,114
 DB 0,0
 PUBLIC l0632
  align 4
l0632:
 DD 15
 DB 99,111,112,121,115,116,114,105,110,103
 DB 116,111,102,114,111,109,0,0
 PUBLIC l0633
  align 4
l0633:
 DD 16
 DB 105,110,105,116,105,97,108,105,122,101
 DB 45,110,101,119,45,105,100,0
 PUBLIC l0634
  align 4
l0634:
 DD 12
 DB 104,97,115,104,45,102,117,110,99,116,105
 DB 111,110,0
 PUBLIC l0635
  align 4
l0635:
 DD 21
 DB 117,110,99,104,101,99,107,101,100,45,115
 DB 116,114,105,110,103,45,101,113,117,97
 DB 108,0,0
 PUBLIC l0636
  align 4
l0636:
 DD 11
 DB 112,108,97,110,116,117,110,98,111,117
 DB 110,100,0,0
 PUBLIC l0637
  align 4
l0637:
 DD 14
 DB 102,97,115,108,105,110,45,98,97,100,45
 DB 102,105,108,101,0
 PUBLIC l0638
  align 4
l0638:
 DD 12
 DB 114,101,97,100,45,105,100,45,116,97,98
 DB 108,101,0
 PUBLIC l0639
  align 4
l0639:
 DD 4
 DB 103,116,98,112,115,0
 PUBLIC l0640
  align 4
l0640:
 DD 5
 DB 103,116,119,114,100,115,0,0
 PUBLIC l0641
  align 4
l0641:
 DD 16
 DB 100,111,45,114,101,108,111,99,97,116,105
 DB 111,110,45,110,101,119,0
 PUBLIC l0642
  align 4
l0642:
 DD 12
 DB 100,111,45,114,101,108,111,99,97,116,105
 DB 111,110,0
 PUBLIC l0643
  align 4
l0643:
 DD 12
 DB 97,100,100,114,101,115,115,97,112,112
 DB 108,121,48,0
 PUBLIC l0644
  align 4
l0644:
 DD 5
 DB 100,101,108,98,112,115,0,0
 PUBLIC l0645
  align 4
l0645:
 DD 13
 DB 99,111,100,101,45,98,97,115,101,45,104
 DB 97,99,107,0,0
 PUBLIC l0646
  align 4
l0646:
 DD 12
 DB 114,101,108,111,99,97,116,101,45,119,111
 DB 114,100,0
 PUBLIC l0647
  align 4
l0647:
 DD 11
 DB 114,101,108,111,99,97,116,101,45,105,110
 DB 102,0,0
 PUBLIC l0648
  align 4
l0648:
 DD 18
 DB 114,101,108,111,99,97,116,101,45,114,105
 DB 103,104,116,45,104,97,108,102,0
 PUBLIC l0649
  align 4
l0649:
 DD 17
 DB 99,111,109,112,117,116,101,45,114,101
 DB 108,111,99,97,116,105,111,110,0,0
 PUBLIC l0650
  align 4
l0650:
 DD 17
 DB 108,111,99,97,108,45,116,111,45,103,108
 DB 111,98,97,108,45,105,100,0,0
 PUBLIC l0651
  align 4
l0651:
 DD 17
 DB 114,101,108,111,99,97,116,101,45,102,97
 DB 115,116,45,99,97,108,108,0,0
 PUBLIC l0652
  align 4
l0652:
 DD 3
 DB 112,117,116,100,0,0
 PUBLIC l0653
  align 4
l0653:
 DD 7
 DB 112,117,116,101,110,116,114,121,0,0
 PUBLIC l0654
  align 4
l0654:
 DD 14
 DB 103,116,98,112,115,45,110,105,108,45,101
 DB 114,114,111,114,0
 PUBLIC l0655
  align 4
l0655:
 DD 19
 DB 116,114,121,45,111,116,104,101,114,45
 DB 98,112,115,45,115,112,97,99,101,115,0
 DB 0
 PUBLIC l0656
  align 4
l0656:
 DD 3
 DB 103,101,116,100,0,0
 PUBLIC l0657
  align 4
l0657:
 DD 7
 DB 115,116,100,101,114,114,111,114,0,0
 PUBLIC l0658
  align 4
l0658:
 DD 15
 DB 107,110,111,119,110,45,102,114,101,101
 DB 45,115,112,97,99,101,0,0
 PUBLIC l0659
  align 4
l0659:
 DD 10
 DB 114,101,97,108,45,103,116,104,101,97,112
 DB 0
 PUBLIC l0660
  align 4
l0660:
 DD 5
 DB 103,116,104,101,97,112,0,0
 PUBLIC l0661
  align 4
l0661:
 DD 12
 DB 103,101,116,45,104,101,97,112,45,116,114
 DB 97,112,0
 PUBLIC l0662
  align 4
l0662:
 DD 6
 DB 114,101,99,108,97,105,109,0
 PUBLIC l0663
  align 4
l0663:
 DD 4
 DB 103,116,115,116,114,0
 PUBLIC l0664
  align 4
l0664:
 DD 3
 DB 99,111,110,115,0,0
 PUBLIC l0665
  align 4
l0665:
 DD 10
 DB 105,110,116,101,114,114,111,103,97,116
 DB 101,0
 PUBLIC l0666
  align 4
l0666:
 DD 5
 DB 109,111,100,105,102,121,0,0
 PUBLIC l0667
  align 4
l0667:
 DD 12
 DB 117,110,99,104,101,99,107,101,100,45,112
 DB 117,116,0
 PUBLIC l0668
  align 4
l0668:
 DD 2
 DB 112,117,116,0
 PUBLIC l0669
  align 4
l0669:
 DD 13
 DB 117,110,99,104,101,99,107,101,100,45,112
 DB 114,111,112,0,0
 PUBLIC l0670
  align 4
l0670:
 DD 4
 DB 97,116,115,111,99,0
 PUBLIC l0671
  align 4
l0671:
 DD 16
 DB 117,110,99,104,101,99,107,101,100,45,115
 DB 101,116,112,114,111,112,0
 PUBLIC l0672
  align 4
l0672:
 DD 8
 DB 99,111,100,101,45,112,117,116,100,0
 PUBLIC l0673
  align 4
l0673:
 DD 15
 DB 112,108,97,110,116,99,111,100,101,112
 DB 111,105,110,116,101,114,0,0
 PUBLIC l0674
  align 4
l0674:
 DD 3
 DB 101,120,112,114,0,0
 PUBLIC l0675
  align 4
l0675:
 DD 3
 DB 116,121,112,101,0,0
 PUBLIC l0676
  align 4
l0676:
 DD 5
 DB 102,108,117,105,100,49,0,0
 PUBLIC l0677
  align 4
l0677:
 DD 4
 DB 102,108,117,105,100,0
 PUBLIC l0678
  align 4
l0678:
 DD 6
 DB 118,97,114,116,121,112,101,0
 PUBLIC l0679
  align 4
l0679:
 DD 8
 DB 99,111,110,115,116,97,110,116,63,0
 PUBLIC l0680
  align 4
l0680:
 DD 15
 DB 42,100,101,102,105,110,101,45,99,111,110
 DB 115,116,97,110,116,0,0
 PUBLIC l0681
  align 4
l0681:
 DD 17
 DB 116,101,114,109,105,110,97,108,45,105
 DB 110,116,101,114,114,117,112,116,0,0
 PUBLIC l0682
  align 4
l0682:
 DD 6
 DB 119,104,97,116,115,117,112,0
 PUBLIC l0683
  align 4
l0683:
 DD 5
 DB 103,101,116,112,105,100,0,0
 PUBLIC l0684
  align 4
l0684:
 DD 5
 DB 101,99,104,111,111,110,0,0
 PUBLIC l0685
  align 4
l0685:
 DD 6
 DB 101,99,104,111,111,102,102,0
 PUBLIC l0686
  align 4
l0686:
 DD 26
 DB 101,120,116,101,114,110,97,108,95,99,104
 DB 97,114,115,105,110,105,110,112,117,116
 DB 98,117,102,102,101,114,0
 PUBLIC l0687
  align 4
l0687:
 DD 19
 DB 102,108,117,115,104,115,116,100,111,117
 DB 116,112,117,116,98,117,102,102,101,114
 DB 0,0
 PUBLIC l0688
  align 4
l0688:
 DD 27
 DB 101,120,116,101,114,110,97,108,95,117
 DB 115,101,114,95,104,111,109,101,100,105
 DB 114,95,115,116,114,105,110,103,0,0
 PUBLIC l0689
  align 4
l0689:
 DD 12
 DB 97,108,116,101,114,104,101,97,112,115
 DB 105,122,101,0
 PUBLIC l0690
  align 4
l0690:
 DD 14
 DB 97,108,108,111,99,97,116,101,109,111,114
 DB 101,98,112,115,0
 PUBLIC l0691
  align 4
l0691:
 DD 14
 DB 103,101,116,95,102,105,108,101,95,115
 DB 116,97,116,117,115,0
 PUBLIC l0692
  align 4
l0692:
 DD 14
 DB 111,115,95,99,108,101,97,110,117,112,95
 DB 104,111,111,107,0
 PUBLIC l0693
  align 4
l0693:
 DD 13
 DB 101,120,116,101,114,110,97,108,95,97,108
 DB 97,114,109,0,0
 PUBLIC l0694
  align 4
l0694:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,117
 DB 97,108,97,114,109,0
 PUBLIC l0695
  align 4
l0695:
 DD 12
 DB 101,120,116,101,114,110,97,108,95,116
 DB 105,109,101,0
 PUBLIC l0696
  align 4
l0696:
 DD 12
 DB 101,120,116,101,114,110,97,108,95,116
 DB 105,109,99,0
 PUBLIC l0697
  align 4
l0697:
 DD 12
 DB 101,120,116,101,114,110,97,108,95,115
 DB 116,97,116,0
 PUBLIC l0698
  align 4
l0698:
 DD 12
 DB 101,120,116,101,114,110,97,108,95,108
 DB 105,110,107,0
 PUBLIC l0699
  align 4
l0699:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,117
 DB 110,108,105,110,107,0
 PUBLIC l0700
  align 4
l0700:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,115
 DB 101,116,101,110,118,0
 PUBLIC l0701
  align 4
l0701:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,103
 DB 101,116,101,110,118,0
 PUBLIC l0702
  align 4
l0702:
 DD 6
 DB 117,120,102,108,111,97,116,0
 PUBLIC l0703
  align 4
l0703:
 DD 4
 DB 117,120,102,105,120,0
 PUBLIC l0704
  align 4
l0704:
 DD 7
 DB 117,120,97,115,115,105,103,110,0,0
 PUBLIC l0705
  align 4
l0705:
 DD 6
 DB 117,120,112,108,117,115,50,0
 PUBLIC l0706
  align 4
l0706:
 DD 11
 DB 117,120,100,105,102,102,101,114,101,110
 DB 99,101,0,0
 PUBLIC l0707
  align 4
l0707:
 DD 7
 DB 117,120,116,105,109,101,115,50,0,0
 PUBLIC l0708
  align 4
l0708:
 DD 9
 DB 117,120,113,117,111,116,105,101,110,116
 DB 0,0
 PUBLIC l0709
  align 4
l0709:
 DD 9
 DB 117,120,103,114,101,97,116,101,114,112
 DB 0,0
 PUBLIC l0710
  align 4
l0710:
 DD 6
 DB 117,120,108,101,115,115,112,0
 PUBLIC l0711
  align 4
l0711:
 DD 11
 DB 117,120,119,114,105,116,101,102,108,111
 DB 97,116,0,0
 PUBLIC l0712
  align 4
l0712:
 DD 15
 DB 117,117,120,100,111,117,98,108,101,116
 DB 111,102,108,111,97,116,0,0
 PUBLIC l0713
  align 4
l0713:
 DD 15
 DB 117,117,120,102,108,111,97,116,116,111
 DB 100,111,117,98,108,101,0,0
 PUBLIC l0714
  align 4
l0714:
 DD 5
 DB 117,117,120,115,105,110,0,0
 PUBLIC l0715
  align 4
l0715:
 DD 5
 DB 117,117,120,99,111,115,0,0
 PUBLIC l0716
  align 4
l0716:
 DD 5
 DB 117,117,120,116,97,110,0,0
 PUBLIC l0717
  align 4
l0717:
 DD 6
 DB 117,117,120,97,115,105,110,0
 PUBLIC l0718
  align 4
l0718:
 DD 6
 DB 117,117,120,97,99,111,115,0
 PUBLIC l0719
  align 4
l0719:
 DD 6
 DB 117,117,120,97,116,97,110,0
 PUBLIC l0720
  align 4
l0720:
 DD 6
 DB 117,117,120,115,113,114,116,0
 PUBLIC l0721
  align 4
l0721:
 DD 5
 DB 117,117,120,101,120,112,0,0
 PUBLIC l0722
  align 4
l0722:
 DD 5
 DB 117,117,120,108,111,103,0,0
 PUBLIC l0723
  align 4
l0723:
 DD 7
 DB 117,117,120,97,116,97,110,50,0,0
 PUBLIC l0724
  align 4
l0724:
 DD 17
 DB 103,101,116,95,114,101,103,105,115,116
 DB 114,121,95,118,97,108,117,101,0,0
 PUBLIC l0725
  align 4
l0725:
 DD 11
 DB 101,120,116,101,114,110,97,108,95,112
 DB 119,100,0,0
 PUBLIC l0726
  align 4
l0726:
 DD 10
 DB 115,117,110,51,95,115,105,103,115,101
 DB 116,0
 PUBLIC l0727
  align 4
l0727:
 DD 7
 DB 115,105,103,114,101,108,115,101,0,0
 PUBLIC l0728
  align 4
l0728:
 DD 5
 DB 117,110,101,120,101,99,0,0
 PUBLIC l0729
  align 4
l0729:
 DD 10
 DB 117,110,105,120,99,108,101,97,114,105
 DB 111,0
 PUBLIC l0730
  align 4
l0730:
 DD 15
 DB 101,120,112,97,110,100,95,102,105,108
 DB 101,95,110,97,109,101,0,0
 PUBLIC l0731
  align 4
l0731:
 DD 5
 DB 117,110,105,120,99,100,0,0
 PUBLIC l0732
  align 4
l0732:
 DD 8
 DB 117,110,105,120,102,114,101,97,100,0
 PUBLIC l0733
  align 4
l0733:
 DD 8
 DB 117,110,105,120,102,112,117,116,99,0
 PUBLIC l0734
  align 4
l0734:
 DD 8
 DB 117,110,105,120,102,103,101,116,99,0
 PUBLIC l0735
  align 4
l0735:
 DD 8
 DB 117,110,105,120,102,103,101,116,115,0
 PUBLIC l0736
  align 4
l0736:
 DD 9
 DB 117,110,105,120,102,119,114,105,116,101
 DB 0,0
 PUBLIC l0737
  align 4
l0737:
 DD 9
 DB 117,110,105,120,102,102,108,117,115,104
 DB 0,0
 PUBLIC l0738
  align 4
l0738:
 DD 4
 DB 99,116,105,109,101,0
 PUBLIC l0739
  align 4
l0739:
 DD 14
 DB 101,120,116,101,114,110,97,108,95,115
 DB 121,115,116,101,109,0
 PUBLIC l0740
  align 4
l0740:
 DD 4
 DB 102,111,112,101,110,0
 PUBLIC l0741
  align 4
l0741:
 DD 4
 DB 102,115,101,101,107,0
 PUBLIC l0742
  align 4
l0742:
 DD 7
 DB 99,108,101,97,114,101,114,114,0,0
 PUBLIC l0743
  align 4
l0743:
 DD 3
 DB 112,117,116,119,0,0
 PUBLIC l0744
  align 4
l0744:
 DD 5
 DB 115,105,103,110,97,108,0,0
 PUBLIC l0745
  align 4
l0745:
 DD 4
 DB 115,108,101,101,112,0
 PUBLIC l0746
  align 4
l0746:
 DD 11
 DB 105,101,101,101,95,104,97,110,100,108
 DB 101,114,0,0
 PUBLIC l0747
  align 4
l0747:
 DD 9
 DB 105,101,101,101,95,102,108,97,103,115
 DB 0,0
 PUBLIC l0748
  align 4
l0748:
 DD 9
 DB 115,101,116,108,105,110,101,98,117,102
 DB 0,0
 PUBLIC l0749
  align 4
l0749:
 DD 4
 DB 112,111,112,101,110,0
 PUBLIC l0750
  align 4
l0750:
 DD 5
 DB 112,99,108,111,115,101,0,0
 PUBLIC l0751
  align 4
l0751:
 DD 5
 DB 112,114,111,102,105,108,0,0
 PUBLIC l0752
  align 4
l0752:
 DD 6
 DB 100,97,116,101,116,97,103,0
 PUBLIC l0753
  align 4
l0753:
 DD 8
 DB 112,115,108,108,95,99,97,108,108,0
 PUBLIC l0754
  align 4
l0754:
 DD 11
 DB 117,110,105,120,45,112,114,111,102,105
 DB 108,101,0,0
 PUBLIC l0755
  align 4
l0755:
 DD 4
 DB 102,112,117,116,99,0
 PUBLIC l0756
  align 4
l0756:
 DD 4
 DB 102,103,101,116,99,0
 PUBLIC l0757
  align 4
l0757:
 DD 4
 DB 102,103,101,116,115,0
 PUBLIC l0758
  align 4
l0758:
 DD 5
 DB 102,119,114,105,116,101,0,0
 PUBLIC l0759
  align 4
l0759:
 DD 5
 DB 102,102,108,117,115,104,0,0
 PUBLIC l0760
  align 4
l0760:
 DD 13
 DB 112,108,97,110,116,117,110,98,111,117
 DB 110,100,45,49,0,0
 PUBLIC l0761
  align 4
l0761:
 DD 17
 DB 112,108,97,110,116,99,111,100,101,112
 DB 111,105,110,116,101,114,45,49,0,0
 PUBLIC l0762
  align 4
l0762:
 DD 16
 DB 112,108,97,110,116,108,97,109,98,100,97
 DB 108,105,110,107,45,49,0
 PUBLIC l0763
  align 4
l0763:
 DD 14
 DB 112,108,97,110,116,108,97,109,98,100,97
 DB 108,105,110,107,0
 PUBLIC l0764
  align 4
l0764:
 DD 7
 DB 98,105,116,116,97,98,108,101,0,0
 PUBLIC l0765
  align 4
l0765:
 DD 16
 DB 117,110,100,101,102,105,110,101,100,102
 DB 117,110,99,116,105,111,110,0
 PUBLIC l0766
  align 4
l0766:
 DD 20
 DB 117,110,100,101,102,105,110,101,100,102
 DB 117,110,99,116,105,111,110,45,97,117,120
 DB 0
 PUBLIC l0767
  align 4
l0767:
 DD 28
 DB 99,111,109,112,105,108,101,100,99,97,108
 DB 108,105,110,103,105,110,116,101,114,112
 DB 114,101,116,101,100,97,117,120,0
 PUBLIC l0768
  align 4
l0768:
 DD 25
 DB 99,111,109,112,105,108,101,100,99,97,108
 DB 108,105,110,103,105,110,116,101,114,112
 DB 114,101,116,101,100,0,0
 PUBLIC l0769
  align 4
l0769:
 DD 8
 DB 99,111,100,101,102,111,114,109,42,0
 PUBLIC l0770
  align 4
l0770:
 DD 14
 DB 103,101,116,102,99,111,100,101,112,111
 DB 105,110,116,101,114,0
 PUBLIC l0771
  align 4
l0771:
 DD 9
 DB 108,97,115,116,107,101,114,110,101,108
 DB 0,0
 PUBLIC l0772
  align 4
l0772:
 DD 11
 DB 99,111,100,101,97,100,100,114,101,115
 DB 115,112,0,0
_TEXT  ends
_DATA    segment dword public 'DATA'
  INCLUDE S_PR_NA.ASM
  INCLUDE KSTRUCTS.ASM
_DATA   ends
   END  
