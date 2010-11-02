 .long 2
// (*entry fopen expr 2)
 .globl l0210
l0210:
 push %ebx
 push %eax
 movl symval+1212,%ebx
 // call _fopen
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 1
// (*entry fclose expr 1)
 .globl l0211
l0211:
 push %eax
 movl symval+1212,%ebx
 // call _fclose
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 4
// (*entry fread expr 4)
 .globl l0212
l0212:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call fread$stub
 movl %ebx,symval+1212
 add $16,%esp
 ret
 .long 2
// (*entry fputc expr 2)
 .globl l0213
l0213:
 push %ebx
 push %eax
 movl symval+1212,%ebx
 // call _fputc
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 1
// (*entry fgetc expr 1)
 .globl l0214
l0214:
 push %eax
 movl symval+1212,%ebx
 //call _fgetc
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 3
// (*entry fgets expr 3)
 .globl l0215
l0215:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _fgets
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 4
// (*entry fwrite expr 4)
 .globl l0216
l0216:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call fwrite$stub
 movl %ebx,symval+1212
 add $16,%esp
 ret
 .long 1
// (*entry fflush expr 1)
 .globl l0217
l0217:
 push %eax
 movl symval+1212,%ebx
 //call _fflush
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 3
// (*entry fseek expr 3)
 .globl l0218
l0218:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 // call _fseek
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 1
// (*entry clearerr expr 1)
 .globl l0219
l0219:
 push %eax
 movl symval+1212,%ebx
// call _clearerr
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 1
// (*entry getw expr 1)
 .globl l0220
l0220:
 sub $8,%esp
 push %eax
 movl symval+1212,%ebx
 call getw$stub
 movl %ebx,symval+1212
 add $12,%esp
 ret
.section __IMPORT,__jump_table,symbol_stubs,self_modifying_code+pure_instructions,5
L_putw$stub:
        .indirect_symbol _putw
        hlt ; hlt ; hlt ; hlt ; hlt
getw$stub:
        .indirect_symbol _getw
        hlt ; hlt ; hlt ; hlt ; hlt
fwrite$stub:
        .indirect_symbol _fwrite
        hlt ; hlt ; hlt ; hlt ; hlt
fread$stub:
        .indirect_symbol _fread
        hlt ; hlt ; hlt ; hlt ; hlt

  .text
 .long 2
// (*entry putw expr 2)
 .globl l0221
l0221:
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call L_putw$stub
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 2
// (*entry signal expr 2)
 .globl l0222
l0222:
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _signal
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 1
// (*entry sleep expr 1)
 .globl l0223
l0223:
 push %eax
 movl symval+1212,%ebx
//  call _sleep
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 3
// (*entry ieee_handler expr 3)
 .globl l0224
l0224:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call _ieee_handler
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 4
// (*entry ieee_flags expr 4)
 .globl l0225
l0225:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call _ieee_flags
 movl %ebx,symval+1212
 add $16,%esp
 ret
 .long 1
// (*entry setlinebuf expr 1)
 .globl l0226
l0226:
 push %eax
 movl symval+1212,%ebx
// call _setlinebuf
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 0
// (*entry getpid expr 0)
 .globl l0227
l0227:
 movl symval+1212,%ebx
// call _getpid
 movl %ebx,symval+1212
 ret
 .long 0
// (*entry gethostid expr 0)
 .globl l0228
l0228:
 movl symval+1212,%ebx
// call _gethostid
 movl %ebx,symval+1212
 ret
 .long 2
// (*entry unixsocketopen expr 2)
 .globl l0229
l0229:
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call _unixsocketopen
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 3
// (*entry getsocket expr 3)
 .globl l0230
l0230:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call _getsocket
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 3
// (*entry writesocket expr 3)
 .globl l0231
l0231:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 call _writesocket
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 1
// (*entry unixclosesocket expr 1)
 .globl l0232
l0232:
 push %eax
 movl symval+1212,%ebx
 call _unixclosesocket
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 0
// (*entry fork expr 0)
 .globl l0233
l0233:
 movl symval+1212,%ebx
// call _fork
 movl %ebx,symval+1212
 ret
 .long 1
// (*entry wait expr 1)
 .globl l0234
l0234:
 push %eax
 movl symval+1212,%ebx
//  call _wait
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 2
// (*entry popen expr 2)
 .globl l0235
l0235:
 push %ebx
 push %eax
 movl symval+1212,%ebx
 // call _popen
 movl %ebx,symval+1212
 add $8,%esp
 ret
 .long 1
// (*entry pclose expr 1)
 .globl l0236
l0236:
 push %eax
 movl symval+1212,%ebx
// call _pclose
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 3
// (*entry shmctl expr 3)
 .globl l0237
l0237:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _shmctl
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 3
// (*entry shmget expr 3)
 .globl l0238
l0238:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _shmget
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 3
// (*entry shmat expr 3)
 .globl l0239
l0239:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _shmat
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 1
// (*entry shmdt expr 1)
 .globl l0240
l0240:
 push %eax
 movl symval+1212,%ebx
// call _shmdt
 movl %ebx,symval+1212
 add $4,%esp
 ret
 .long 4
// (*entry semctl expr 4)
 .globl l0241
l0241:
 push %edx
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
 // call _semctl
 movl %ebx,symval+1212
 add $16,%esp
 ret
 .long 3
// (*entry semget expr 3)
 .globl l0242
l0242:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _semget
 movl %ebx,symval+1212
 add $12,%esp
 ret
 .long 3
// (*entry semop expr 3)
 .globl l0243
l0243:
 push %ecx
 push %ebx
 push %eax
 movl symval+1212,%ebx
// call _semop
 movl %ebx,symval+1212
 add $12,%esp
 ret
