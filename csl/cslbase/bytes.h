/* bytes.h                             Copyright (C) Codemist 1993-2008 */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 3d0fca5b 24-May-2008 */


/*
 *   Bytecode interpreter support.
 */

#ifndef header_bytes_h
#define header_bytes_h 1

#define JUMP_BACK               0x01 /* select direction of jump  */
#define JUMP_LONG               0x02 /* select 16 vs 8 bit offset */

#define OP_LOADLOC              0x00
#define OP_LOADLOC0             0x01
#define OP_LOADLOC1             0x02
#define OP_LOADLOC2             0x03
#define OP_LOADLOC3             0x04
#define OP_LOADLOC4             0x05
#define OP_LOADLOC5             0x06
#define OP_LOADLOC6             0x07
#define OP_LOADLOC7             0x08
#define OP_LOADLOC8             0x09
#define OP_LOADLOC9             0x0a
#define OP_LOADLOC10            0x0b
#define OP_LOADLOC11            0x0c
#define OP_LOC0LOC1             0x0d
#define OP_LOC1LOC2             0x0e
#define OP_LOC2LOC3             0x0f
#define OP_LOC1LOC0             0x10
#define OP_LOC2LOC1             0x11
#define OP_LOC3LOC2             0x12
#define OP_VNIL                 0x13
#define OP_LOADLIT              0x14
#define OP_LOADLIT1             0x15
#define OP_LOADLIT2             0x16
#define OP_LOADLIT3             0x17
#define OP_LOADLIT4             0x18
#define OP_LOADLIT5             0x19
#define OP_LOADLIT6             0x1a
#define OP_LOADLIT7             0x1b
#define OP_LOADFREE             0x1c
#define OP_LOADFREE1            0x1d
#define OP_LOADFREE2            0x1e
#define OP_LOADFREE3            0x1f
#define OP_LOADFREE4            0x20
#define OP_STORELOC             0x21
#define OP_STORELOC0            0x22
#define OP_STORELOC1            0x23
#define OP_STORELOC2            0x24
#define OP_STORELOC3            0x25
#define OP_STORELOC4            0x26
#define OP_STORELOC5            0x27
#define OP_STORELOC6            0x28
#define OP_STORELOC7            0x29
#define OP_STOREFREE            0x2a
#define OP_STOREFREE1           0x2b
#define OP_STOREFREE2           0x2c
#define OP_STOREFREE3           0x2d
#define OP_LOADLEX              0x2e
#define OP_STORELEX             0x2f
#define OP_CLOSURE              0x30
#define OP_CARLOC0              0x31
#define OP_CARLOC1              0x32
#define OP_CARLOC2              0x33
#define OP_CARLOC3              0x34
#define OP_CARLOC4              0x35
#define OP_CARLOC5              0x36
#define OP_CARLOC6              0x37
#define OP_CARLOC7              0x38
#define OP_CARLOC8              0x39
#define OP_CARLOC9              0x3a
#define OP_CARLOC10             0x3b
#define OP_CARLOC11             0x3c
#define OP_CDRLOC0              0x3d
#define OP_CDRLOC1              0x3e
#define OP_CDRLOC2              0x3f
#define OP_CDRLOC3              0x40
#define OP_CDRLOC4              0x41
#define OP_CDRLOC5              0x42
#define OP_CAARLOC0             0x43
#define OP_CAARLOC1             0x44
#define OP_CAARLOC2             0x45
#define OP_CAARLOC3             0x46
#define OP_CALL0                0x47
#define OP_CALL1                0x48
#define OP_CALL2                0x49
#define OP_CALL2R               0x4a
#define OP_CALL3                0x4b
#define OP_CALLN                0x4c
#define OP_CALL0_0              0x4d
#define OP_CALL0_1              0x4e
#define OP_CALL0_2              0x4f
#define OP_CALL0_3              0x50
#define OP_CALL1_0              0x51
#define OP_CALL1_1              0x52
#define OP_CALL1_2              0x53
#define OP_CALL1_3              0x54
#define OP_CALL1_4              0x55
#define OP_CALL1_5              0x56
#define OP_CALL2_0              0x57
#define OP_CALL2_1              0x58
#define OP_CALL2_2              0x59
#define OP_CALL2_3              0x5a
#define OP_CALL2_4              0x5b
#define OP_BUILTIN0             0x5c
#define OP_BUILTIN1             0x5d
#define OP_BUILTIN2             0x5e
#define OP_BUILTIN2R            0x5f
#define OP_BUILTIN3             0x60
#define OP_APPLY1               0x61
#define OP_APPLY2               0x62
#define OP_APPLY3               0x63
#define OP_APPLY4               0x64
#define OP_JCALL                0x65
#define OP_JCALLN               0x66
#define OP_JUMP                 0x67
#define OP_JUMP_B               0x68
#define OP_JUMP_L               0x69
#define OP_JUMP_BL              0x6a
#define OP_JUMPNIL              0x6b
#define OP_JUMPNIL_B            0x6c
#define OP_JUMPNIL_L            0x6d
#define OP_JUMPNIL_BL           0x6e
#define OP_JUMPT                0x6f
#define OP_JUMPT_B              0x70
#define OP_JUMPT_L              0x71
#define OP_JUMPT_BL             0x72
#define OP_JUMPATOM             0x73
#define OP_JUMPATOM_B           0x74
#define OP_JUMPATOM_L           0x75
#define OP_JUMPATOM_BL          0x76
#define OP_JUMPNATOM            0x77
#define OP_JUMPNATOM_B          0x78
#define OP_JUMPNATOM_L          0x79
#define OP_JUMPNATOM_BL         0x7a
#define OP_JUMPEQ               0x7b
#define OP_JUMPEQ_B             0x7c
#define OP_JUMPEQ_L             0x7d
#define OP_JUMPEQ_BL            0x7e
#define OP_JUMPNE               0x7f
#define OP_JUMPNE_B             0x80
#define OP_JUMPNE_L             0x81
#define OP_JUMPNE_BL            0x82
#define OP_JUMPEQUAL            0x83
#define OP_JUMPEQUAL_B          0x84
#define OP_JUMPEQUAL_L          0x85
#define OP_JUMPEQUAL_BL         0x86
#define OP_JUMPNEQUAL           0x87
#define OP_JUMPNEQUAL_B         0x88
#define OP_JUMPNEQUAL_L         0x89
#define OP_JUMPNEQUAL_BL        0x8a
#define OP_JUMPL0NIL            0x8b
#define OP_JUMPL0T              0x8c
#define OP_JUMPL1NIL            0x8d
#define OP_JUMPL1T              0x8e
#define OP_JUMPL2NIL            0x8f
#define OP_JUMPL2T              0x90
#define OP_JUMPL3NIL            0x91
#define OP_JUMPL3T              0x92
#define OP_JUMPL4NIL            0x93
#define OP_JUMPL4T              0x94
#define OP_JUMPST0NIL           0x95
#define OP_JUMPST0T             0x96
#define OP_JUMPST1NIL           0x97
#define OP_JUMPST1T             0x98
#define OP_JUMPST2NIL           0x99
#define OP_JUMPST2T             0x9a
#define OP_JUMPL0ATOM           0x9b
#define OP_JUMPL0NATOM          0x9c
#define OP_JUMPL1ATOM           0x9d
#define OP_JUMPL1NATOM          0x9e
#define OP_JUMPL2ATOM           0x9f
#define OP_JUMPL2NATOM          0xa0
#define OP_JUMPL3ATOM           0xa1
#define OP_JUMPL3NATOM          0xa2
#define OP_JUMPFREE1NIL         0xa3
#define OP_JUMPFREE1T           0xa4
#define OP_JUMPFREE2NIL         0xa5
#define OP_JUMPFREE2T           0xa6
#define OP_JUMPFREE3NIL         0xa7
#define OP_JUMPFREE3T           0xa8
#define OP_JUMPFREE4NIL         0xa9
#define OP_JUMPFREE4T           0xaa
#define OP_JUMPFREENIL          0xab
#define OP_JUMPFREET            0xac
#define OP_JUMPLIT1EQ           0xad
#define OP_JUMPLIT1NE           0xae
#define OP_JUMPLIT2EQ           0xaf
#define OP_JUMPLIT2NE           0xb0
#define OP_JUMPLIT3EQ           0xb1
#define OP_JUMPLIT3NE           0xb2
#define OP_JUMPLIT4EQ           0xb3
#define OP_JUMPLIT4NE           0xb4
#define OP_JUMPLITEQ            0xb5
#define OP_JUMPLITNE            0xb6
#define OP_JUMPB1NIL            0xb7
#define OP_JUMPB1T              0xb8
#define OP_JUMPB2NIL            0xb9
#define OP_JUMPB2T              0xba
#define OP_JUMPFLAGP            0xbb
#define OP_JUMPNFLAGP           0xbc
#define OP_JUMPEQCAR            0xbd
#define OP_JUMPNEQCAR           0xbe
#define OP_CATCH                0xbf
#define OP_CATCH_B              0xc0
#define OP_CATCH_L              0xc1
#define OP_CATCH_BL             0xc2
#define OP_UNCATCH              0xc3
#define OP_THROW                0xc4
#define OP_PROTECT              0xc5
#define OP_UNPROTECT            0xc6
#define OP_PVBIND               0xc7
#define OP_PVRESTORE            0xc8
#define OP_FREEBIND             0xc9
#define OP_FREERSTR             0xca
#define OP_EXIT                 0xcb
#define OP_NILEXIT              0xcc
#define OP_LOC0EXIT             0xcd
#define OP_LOC1EXIT             0xce
#define OP_LOC2EXIT             0xcf
#define OP_PUSH                 0xd0
#define OP_PUSHNIL              0xd1
#define OP_PUSHNIL2             0xd2
#define OP_PUSHNIL3             0xd3
#define OP_PUSHNILS             0xd4
#define OP_POP                  0xd5
#define OP_LOSE                 0xd6
#define OP_LOSE2                0xd7
#define OP_LOSE3                0xd8
#define OP_LOSES                0xd9
#define OP_SWOP                 0xda
#define OP_EQ                   0xdb
#define OP_EQCAR                0xdc
#define OP_EQUAL                0xdd
#define OP_NUMBERP              0xde
#define OP_CAR                  0xdf
#define OP_CDR                  0xe0
#define OP_CAAR                 0xe1
#define OP_CADR                 0xe2
#define OP_CDAR                 0xe3
#define OP_CDDR                 0xe4
#define OP_CONS                 0xe5
#define OP_NCONS                0xe6
#define OP_XCONS                0xe7
#define OP_ACONS                0xe8
#define OP_LENGTH               0xe9
#define OP_LIST2                0xea
#define OP_LIST2STAR            0xeb
#define OP_LIST3                0xec
#define OP_PLUS2                0xed
#define OP_ADD1                 0xee
#define OP_DIFFERENCE           0xef
#define OP_SUB1                 0xf0
#define OP_TIMES2               0xf1
#define OP_GREATERP             0xf2
#define OP_LESSP                0xf3
#define OP_FLAGP                0xf4
#define OP_GET                  0xf5
#define OP_LITGET               0xf6
#define OP_GETV                 0xf7
#define OP_QGETV                0xf8
#define OP_QGETVN               0xf9
#define OP_BIGSTACK             0xfa
#define OP_BIGCALL              0xfb
#define OP_ICASE                0xfc
#define OP_FASTGET              0xfd
#define OP_SPARE1               0xfe
#define OP_SPARE2               0xff

#endif /* header_bytes_h */

/* end of bytes.h */

