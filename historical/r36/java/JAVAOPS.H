/* javaops.h: Copyright (C) Codemist Ltd., 1996.                        */

/* Java operators.                                                       */
/* The operators below are taken from                                    */
/*    "The Java Virtual Machine Specification" (dated Aug 21, 1995).     */
/* They are listed in section order, rather than numerical order, but    */
/* I note there are 203 of them: 0..202 and 209 with 186 unused.         */

/* section 3.2: pushing constants onto the stack */
#define j_bipush 16
#define j_sipush 17
#define j_ldc1 18
#define j_ldc2 19
#define j_ldc2w 20
#define j_aconst_null 1
#define j_iconst_m1 2
#define j_iconst_0 3
#define j_iconst_1 4
#define j_iconst_2 5
#define j_iconst_3 6
#define j_iconst_4 7
#define j_iconst_5 8
#define j_lconst_0 9
#define j_lconst_1 10
#define j_fconst_0 11
#define j_fconst_1 12
#define j_fconst_2 13
#define j_dconst_0 14
#define j_dconst_1 15
/* section 3.3: loading locals onto the stack */
#define j_iload 21
#define j_iload_0 26
#define j_iload_1 27
#define j_iload_2 28
#define j_iload_3 29
#define j_lload 22
#define j_lload_0 30
#define j_lload_1 31
#define j_lload_2 32
#define j_lload_3 33
#define j_fload 23
#define j_fload_0 34
#define j_fload_1 35
#define j_fload_2 36
#define j_fload_3 37
#define j_dload 24
#define j_dload_0 38
#define j_dload_1 39
#define j_dload_2 40
#define j_dload_3 41
#define j_aload 25
#define j_aload_0 42
#define j_aload_1 43
#define j_aload_2 44
#define j_aload_3 45
/* section 3.4 storing stack values into locals */
#define j_istore 54
#define j_istore_0 59
#define j_istore_1 60
#define j_istore_2 61
#define j_istore_3 62
#define j_lstore 55
#define j_lstore_0 63
#define j_lstore_1 64
#define j_lstore_2 65
#define j_lstore_3 66
#define j_fstore 56
#define j_fstore_0 67
#define j_fstore_1 68
#define j_fstore_2 69
#define j_fstore_3 70
#define j_dstore 57
#define j_dstore_0 71
#define j_dstore_1 72
#define j_dstore_2 73
#define j_dstore_3 74
#define j_astore 58
#define j_astore_0 75
#define j_astore_1 76
#define j_astore_2 77
#define j_astore_3 78
#define j_iinc 132
/* section 3.5: wider index for loading etc. */
#define j_wide 196
/* section 3.6: managing arrays */
#define j_newarray 188
#define j_anewarray 189
#define j_multinewarray 197
#define j_arraylength 190
#define j_iaload 46
#define j_laload 47
#define j_faload 48
#define j_daload 49
#define j_aaload 50
#define j_baload 51
#define j_caload 52
#define j_saload 53
#define j_iastore 79
#define j_lastore 80
#define j_fastore 81
#define j_dastore 82
#define j_aastore 83
#define j_bastore 84
#define j_castore 85
#define j_sastore 86
/* 3.7 stack instructions */
#define j_nop      0
#define j_pop     87
#define j_pop2    88
#define j_dup     89
#define j_dup2    92
#define j_dup_x1  90
#define j_dup2_x1 93
#define j_dup_x2  91
#define j_dup2_x2 94
#define j_swap    95
/* 3.8 arithmetic instructions */
#define j_iadd    96
#define j_ladd    97
#define j_fadd    98
#define j_dadd    99
#define j_isub    100
#define j_lsub    101
#define j_fsub    102
#define j_dsub    103
#define j_imul    104
#define j_lmul    105
#define j_fmul    106
#define j_dmul    107
#define j_idiv    108
#define j_ldiv    109
#define j_fdiv    110
#define j_ddiv    111
#define j_irem    112
#define j_lrem    113
#define j_frem    114
#define j_drem    115
#define j_ineg    116
#define j_lneg    117
#define j_fneg    118
#define j_dneg    119
/* 3.9 logical instructions */
#define j_ishl    120
#define j_ishr    121
#define j_iushr   122
#define j_lshl    123
#define j_lshr    124
#define j_lushr   125
#define j_iand    126
#define j_land    127
#define j_ior     128
#define j_lor     129
#define j_ixor    130
#define j_lxor    131
/* 3.10 conversion instructions */
#define j_i2l     133
#define j_i2f     134
#define j_i2d     135
#define j_l2i     136
#define j_l2f     137
#define j_l2d     138
#define j_f2i     139
#define j_f2l     140
#define j_f2d     141
#define j_d2i     142
#define j_d2l     143
#define j_d2f     144
#define j_int2byte  145
#define j_int2char  146
#define j_int2short 147
/* 3.11 control transfer instructions */
#define j_ifeq    153
#define j_ifnull  198
#define j_iflt    155
#define j_ifle    158
#define j_ifne    154
#define j_ifnonnull  199
#define j_ifgt    157
#define j_ifge    156
#define j_if_icmpeq  159
#define j_if_icmpne  160
#define j_if_icmplt  161
#define j_if_icmpgt  163
#define j_if_icmple  164
#define j_if_icmpge  162
#define j_lcmp    148
#define j_fcmpl   149
#define j_fcmpg   150
#define j_dcmpl   151
#define j_dcmpg   152
#define j_if_acmpeq  165
#define j_if_acmpne  166
#define j_goto    167
#define j_goto_w  200
#define j_jsr     168
#define j_jsr_w   201
#define j_ret     169
#define j_ret_w   209
/* 3.12 function return */
#define j_ireturn 172
#define j_lreturn 173
#define j_freturn 174
#define j_dreturn 175
#define j_areturn 176
#define j_return  177
#define j_breakpoint  202
/* 3.13 table jumping */
#define j_tableswitch  170
#define j_lookupswitch 171
/* 3.14 manipulating object fields */
#define j_putfield  181
#define j_getfield  180
#define j_putstatic 179
#define j_getstatic 178
/* 3.15 method invokation */
#define j_invokevirtual    182
#define j_invokenonvirtual 183
#define j_invokestatic     184
#define j_invokeinterface  185
/* 3.16 exception handling */
#define j_athrow  191
/* 3.17 miscellaneous object operation */
#define j_new           187
#define j_checkcast     192
#define j_instanceof    193
#define j_monitorenter  194
#define j_monitorexit   195
/* Quick variants of opcodes are not currently supported. */

/* Java type codes.                                                      */
#define T_BOOLEAN 4
#define T_CHAR    5
#define T_FLOAT   6
#define T_DOUBLE  7
#define T_BYTE    8
#define T_SHORT   9
#define T_INT    10
#define T_LONG   11

/* end of javaops.h */
