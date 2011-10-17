;   "asmarm.s"          Copyright (C) Codemist Ltd, 1992
;
;

r0      RN      0       ; r0-r3 are used as workspace here
r1      RN      1
r2      RN      2
r3      RN      3

r12     RN      12      ; points at profile_record
sp      RN      13      ; stack provided by the operating system for me
lr      RN      14      ; return address
pc      RN      15

        AREA |C$$code|, CODE, READONLY

        IMPORT  |__main|
        B       |__main|


        EXPORT  |__RO_Base|
        EXPORT  |__RO_Limit|
        IMPORT  |Image$$RO$$Base|
        IMPORT  |Image$$RO$$Limit|

|__RO_Base|
        &       |Image$$RO$$Base|
|__RO_Limit|
        &       |Image$$RO$$Limit|

        EXPORT  wimp_tick
        IMPORT  C_nil
        IMPORT  tick_pending
        IMPORT  polltick_pending
        IMPORT  already_in_gc
        IMPORT  tick_on_gc_exit
        IMPORT  saveheaplimit
        IMPORT  savevheaplimit
        IMPORT  savecodelimit
        IMPORT  savestacklimit
        IMPORT  stackbase

tick_count
        &       0

wimp_tick
        LDR     r2, tick_count
        SUBS    r2, r2, #1          ; decrement tick_count
        MOVMI   r2, #20             ; set back to 1/5 second delay on wrap
        STR     r2, tick_count
        MOVPLS  pc, lr              ; not ready yet
        LDR     r2, =polltick_pending
        STR     r2, [r2, #0]        ; set polltick_pending
        LDR     r2, =tick_pending
        LDR     r0, [r2, #0]
        CMPS    r0, #0
        MOVNES  pc, lr              ; tick already signalled
        LDR     r0, =already_in_gc
        LDR     r1, [r0, #0]
        CMPS    r1, #0
        BEQ     not_in_gc
        LDR     r2, =tick_on_gc_exit
        STR     r1, [r2, #0]        ; special case if garbage collecting
        MOVS    pc, lr
not_in_gc
        LDR     r0, =C_nil          ; use NIL as base-register
        LDR     r0, [r0, #0]
        BIC     r0, r0, #&80000000  ; clean up potential mark bit
        MOV     r1, r0
        MOV     r3, #1
        STR     r3, [r2, #0]
        LDR     r3, [r1, #76]
        LDR     r2, =saveheaplimit
        STR     r3, [r2, #0]
        LDR     r2, [r1, #72]
        STR     r2, [r1, #76]
        LDR     r1, [r0, #80]
        LDR     r2, =savevheaplimit
        STR     r1, [r2, #0]
        LDR     r1, [r0, #84]
        STR     r1, [r0, #80]
        LDR     r2, [r0, #56]
        LDR     r1, =savecodelimit
        STR     r2, [r1, #0]
        LDR     r1, [r0, #52]
        STR     r1, [r0, #56]
        LDR     r2, [r0, #60]
        LDR     r1, =savestacklimit
        STR     r2, [r1, #0]
        LDR     r1, =stackbase
        LDR     r1, [r1, #0]
        STR     r1, [r0, #60]
        MOVS    pc, lr

        END


