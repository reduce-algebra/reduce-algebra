#// bytes.h                                 Copyright (C) Codemist 1993-2025


/**************************************************************************
 * Copyright (C) 2025, Codemist.                         A C Norman       *
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

// $Id$


//
//   Bytecode interpreter support.
//

#ifndef header_bytes_h
#define header_bytes_h 1

// With each opcode I put a byte where the low 4 bits give the number of
// bytes used in an instructions headed by that code and the 0x10 bit marks
// opcodes that take a pc-relative offset as their operand - is jump
// instructiuons of various sorts.

#define LIST_OF_OPCODES                   \
    X(LOADLOC,        0x02) /* 00   0 */  \
    X(LOADLOC0,       0x01) /* 01   1 */  \
    X(LOADLOC1,       0x01) /* 02   2 */  \
    X(LOADLOC2,       0x01) /* 03   3 */  \
    X(LOADLOC3,       0x01) /* 04   4 */  \
    X(LOADLOC4,       0x01) /* 05   5 */  \
    X(LOADLOC5,       0x01) /* 06   6 */  \
    X(LOADLOC6,       0x01) /* 07   7 */  \
    X(LOADLOC7,       0x01) /* 08   8 */  \
    X(LOADLOC8,       0x01) /* 09   9 */  \
    X(LOADLOC9,       0x01) /* 0a  10 */  \
    X(LOADLOC10,      0x01) /* 0b  11 */  \
    X(LOADLOC11,      0x01) /* 0c  12 */  \
    X(LOC0LOC1,       0x01) /* 0d  13 */  \
    X(LOC1LOC2,       0x01) /* 0e  14 */  \
    X(LOC2LOC3,       0x01) /* 0f  15 */  \
    X(LOC1LOC0,       0x01) /* 10  16 */  \
    X(LOC2LOC1,       0x01) /* 11  17 */  \
    X(LOC3LOC2,       0x01) /* 12  18 */  \
    X(VNIL,           0x01) /* 13  19 */  \
    X(LOADLIT,        0x02) /* 14  20 */  \
    X(LOADLIT1,       0x01) /* 15  21 */  \
    X(LOADLIT2,       0x01) /* 16  22 */  \
    X(LOADLIT3,       0x01) /* 17  23 */  \
    X(LOADLIT4,       0x01) /* 18  24 */  \
    X(LOADLIT5,       0x01) /* 19  25 */  \
    X(LOADLIT6,       0x01) /* 1a  26 */  \
    X(LOADLIT7,       0x01) /* 1b  27 */  \
    X(LOADFREE,       0x02) /* 1c  28 */  \
    X(LOADFREE1,      0x01) /* 1d  29 */  \
    X(LOADFREE2,      0x01) /* 1e  30 */  \
    X(LOADFREE3,      0x01) /* 1f  31 */  \
    X(LOADFREE4,      0x01) /* 20  32 */  \
    X(STORELOC,       0x02) /* 21  33 */  \
    X(STORELOC0,      0x01) /* 22  34 */  \
    X(STORELOC1,      0x01) /* 23  35 */  \
    X(STORELOC2,      0x01) /* 24  36 */  \
    X(STORELOC3,      0x01) /* 25  37 */  \
    X(STORELOC4,      0x01) /* 26  38 */  \
    X(STORELOC5,      0x01) /* 27  39 */  \
    X(STORELOC6,      0x01) /* 28  40 */  \
    X(STORELOC7,      0x01) /* 29  41 */  \
    X(STOREFREE,      0x02) /* 2a  42 */  \
    X(STOREFREE1,     0x01) /* 2b  43 */  \
    X(STOREFREE2,     0x01) /* 2c  44 */  \
    X(STOREFREE3,     0x01) /* 2d  45 */  \
    X(LOADLEX,        0x02) /* 2e  46 */  \
    X(STORELEX,       0x02) /* 2f  47 */  \
    X(CLOSURE,        0x02) /* 30  48 */  \
    X(CARLOC0,        0x01) /* 31  49 */  \
    X(CARLOC1,        0x01) /* 32  50 */  \
    X(CARLOC2,        0x01) /* 33  51 */  \
    X(CARLOC3,        0x01) /* 34  52 */  \
    X(CARLOC4,        0x01) /* 35  53 */  \
    X(CARLOC5,        0x01) /* 36  54 */  \
    X(CARLOC6,        0x01) /* 37  55 */  \
    X(CARLOC7,        0x01) /* 38  56 */  \
    X(CARLOC8,        0x01) /* 39  57 */  \
    X(CARLOC9,        0x01) /* 3a  58 */  \
    X(CARLOC10,       0x01) /* 3b  59 */  \
    X(CARLOC11,       0x01) /* 3c  60 */  \
    X(CDRLOC0,        0x01) /* 3d  61 */  \
    X(CDRLOC1,        0x01) /* 3e  62 */  \
    X(CDRLOC2,        0x01) /* 3f  63 */  \
    X(CDRLOC3,        0x01) /* 40  64 */  \
    X(CDRLOC4,        0x01) /* 41  65 */  \
    X(CDRLOC5,        0x01) /* 42  66 */  \
    X(CAARLOC0,       0x01) /* 43  67 */  \
    X(CAARLOC1,       0x01) /* 44  68 */  \
    X(CAARLOC2,       0x01) /* 45  69 */  \
    X(CAARLOC3,       0x01) /* 46  70 */  \
    X(CALL0,          0x02) /* 47  71 */  \
    X(CALL1,          0x02) /* 48  72 */  \
    X(CALL2,          0x02) /* 49  73 */  \
    X(CALL2R,         0x02) /* 4a  74 */  \
    X(CALL3,          0x02) /* 4b  75 */  \
    X(CALL4,          0x01) /* 4c  76 */  \
    X(CALL0_0,        0x01) /* 4d  77 */  \
    X(CALL0_1,        0x01) /* 4e  78 */  \
    X(CALL0_2,        0x01) /* 4f  79 */  \
    X(CALL0_3,        0x01) /* 50  80 */  \
    X(CALL1_0,        0x01) /* 51  81 */  \
    X(CALL1_1,        0x01) /* 52  82 */  \
    X(CALL1_2,        0x01) /* 53  83 */  \
    X(CALL1_3,        0x01) /* 54  84 */  \
    X(CALL1_4,        0x01) /* 55  85 */  \
    X(CALL1_5,        0x01) /* 56  86 */  \
    X(CALL2_0,        0x01) /* 57  87 */  \
    X(CALL2_1,        0x01) /* 58  88 */  \
    X(CALL2_2,        0x01) /* 59  89 */  \
    X(CALL2_3,        0x01) /* 5a  90 */  \
    X(CALL2_4,        0x01) /* 5b  91 */  \
    X(BUILTIN0,       0x02) /* 5c  92 */  \
    X(BUILTIN1,       0x02) /* 5d  93 */  \
    X(BUILTIN2,       0x02) /* 5e  94 */  \
    X(BUILTIN2R,      0x02) /* 5f  95 */  \
    X(BUILTIN3,       0x02) /* 60  96 */  \
    X(APPLY1,         0x01) /* 61  97 */  \
    X(APPLY2,         0x01) /* 62  98 */  \
    X(APPLY3,         0x01) /* 63  99 */  \
    X(APPLY4,         0x01) /* 64 100 */  \
    X(JCALL,          0x02) /* 65 101 */  \
    X(JUMP,           0x12) /* 66 102 */  \
    X(JUMP_B,         0x22) /* 67 103 */  \
    X(JUMP_L,         0x13) /* 68 104 */  \
    X(JUMP_BL,        0x23) /* 69 105 */  \
    X(JUMPNIL,        0x12) /* 6a 106 */  \
    X(JUMPNIL_B,      0x22) /* 6b 107 */  \
    X(JUMPNIL_L,      0x13) /* 6c 108 */  \
    X(JUMPNIL_BL,     0x23) /* 6d 109 */  \
    X(JUMPT,          0x12) /* 6e 110 */  \
    X(JUMPT_B,        0x22) /* 6f 111 */  \
    X(JUMPT_L,        0x13) /* 70 112 */  \
    X(JUMPT_BL,       0x23) /* 71 113 */  \
    X(JUMPATOM,       0x12) /* 72 114 */  \
    X(JUMPATOM_B,     0x22) /* 73 115 */  \
    X(JUMPATOM_L,     0x13) /* 74 116 */  \
    X(JUMPATOM_BL,    0x23) /* 75 117 */  \
    X(JUMPNATOM,      0x12) /* 76 118 */  \
    X(JUMPNATOM_B,    0x22) /* 77 119 */  \
    X(JUMPNATOM_L,    0x13) /* 78 120 */  \
    X(JUMPNATOM_BL,   0x23) /* 79 121 */  \
    X(JUMPEQ,         0x12) /* 7a 122 */  \
    X(JUMPEQ_B,       0x22) /* 7b 123 */  \
    X(JUMPEQ_L,       0x13) /* 7c 124 */  \
    X(JUMPEQ_BL,      0x23) /* 7d 125 */  \
    X(JUMPNE,         0x12) /* 7e 126 */  \
    X(JUMPNE_B,       0x22) /* 7f 127 */  \
    X(JUMPNE_L,       0x13) /* 80 128 */  \
    X(JUMPNE_BL,      0x23) /* 81 129 */  \
    X(JUMPEQUAL,      0x12) /* 82 130 */  \
    X(JUMPEQUAL_B,    0x22) /* 83 131 */  \
    X(JUMPEQUAL_L,    0x13) /* 84 132 */  \
    X(JUMPEQUAL_BL,   0x23) /* 85 133 */  \
    X(JUMPNEQUAL,     0x12) /* 86 134 */  \
    X(JUMPNEQUAL_B,   0x22) /* 87 135 */  \
    X(JUMPNEQUAL_L,   0x13) /* 88 136 */  \
    X(JUMPNEQUAL_BL,  0x23) /* 89 137 */  \
    X(JUMPL0NIL,      0x12) /* 8a 138 */  \
    X(JUMPL0T,        0x12) /* 8b 139 */  \
    X(JUMPL1NIL,      0x12) /* 8c 140 */  \
    X(JUMPL1T,        0x12) /* 8d 141 */  \
    X(JUMPL2NIL,      0x12) /* 8e 142 */  \
    X(JUMPL2T,        0x12) /* 8f 143 */  \
    X(JUMPL3NIL,      0x12) /* 90 144 */  \
    X(JUMPL3T,        0x12) /* 91 145 */  \
    X(JUMPL4NIL,      0x12) /* 92 146 */  \
    X(JUMPL4T,        0x12) /* 93 147 */  \
    X(JUMPST0NIL,     0x12) /* 94 148 */  \
    X(JUMPST0T,       0x12) /* 95 149 */  \
    X(JUMPST1NIL,     0x12) /* 96 150 */  \
    X(JUMPST1T,       0x12) /* 97 151 */  \
    X(JUMPST2NIL,     0x12) /* 98 152 */  \
    X(JUMPST2T,       0x12) /* 99 153 */  \
    X(JUMPL0ATOM,     0x12) /* 9a 154 */  \
    X(JUMPL0NATOM,    0x12) /* 9b 155 */  \
    X(JUMPL1ATOM,     0x12) /* 9c 156 */  \
    X(JUMPL1NATOM,    0x12) /* 9d 157 */  \
    X(JUMPL2ATOM,     0x12) /* 9e 158 */  \
    X(JUMPL2NATOM,    0x12) /* 9f 159 */  \
    X(JUMPL3ATOM,     0x12) /* a0 160 */  \
    X(JUMPL3NATOM,    0x12) /* a1 161 */  \
    X(JUMPFREE1NIL,   0x12) /* a2 162 */  \
    X(JUMPFREE1T,     0x12) /* a3 163 */  \
    X(JUMPFREE2NIL,   0x12) /* a4 164 */  \
    X(JUMPFREE2T,     0x12) /* a5 165 */  \
    X(JUMPFREE3NIL,   0x12) /* a6 166 */  \
    X(JUMPFREE3T,     0x12) /* a7 167 */  \
    X(JUMPFREE4NIL,   0x12) /* a8 168 */  \
    X(JUMPFREE4T,     0x12) /* a9 169 */  \
    X(JUMPFREENIL,    0x13) /* aa 170 */  \
    X(JUMPFREET,      0x13) /* ab 171 */  \
    X(JUMPLIT1EQ,     0x12) /* ac 172 */  \
    X(JUMPLIT1NE,     0x12) /* ad 173 */  \
    X(JUMPLIT2EQ,     0x12) /* ae 174 */  \
    X(JUMPLIT2NE,     0x12) /* af 175 */  \
    X(JUMPLIT3EQ,     0x12) /* b0 176 */  \
    X(JUMPLIT3NE,     0x12) /* b1 177 */  \
    X(JUMPLIT4EQ,     0x12) /* b2 178 */  \
    X(JUMPLIT4NE,     0x12) /* b3 179 */  \
    X(JUMPLITEQ,      0x13) /* b4 180 */  \
    X(JUMPLITNE,      0x13) /* b5 181 */  \
    X(JUMPB1NIL,      0x13) /* b6 182 */  \
    X(JUMPB1T,        0x13) /* b7 183 */  \
    X(JUMPB2NIL,      0x13) /* b8 184 */  \
    X(JUMPB2T,        0x13) /* b9 185 */  \
    X(JUMPFLAGP,      0x13) /* ba 186 */  \
    X(JUMPNFLAGP,     0x13) /* bb 187 */  \
    X(JUMPEQCAR,      0x13) /* bc 188 */  \
    X(JUMPNEQCAR,     0x13) /* bd 189 */  \
    X(CATCH,          0x12) /* be 190 */  \
    X(CATCH_B,        0x22) /* bf 191 */  \
    X(CATCH_L,        0x13) /* c0 192 */  \
    X(CATCH_BL,       0x23) /* c1 193 */  \
    X(UNCATCH,        0x01) /* c2 194 */  \
    X(THROW,          0x01) /* c3 195 */  \
    X(PROTECT,        0x01) /* c4 196 */  \
    X(UNPROTECT,      0x01) /* c5 197 */  \
    X(PVBIND,         0x01) /* c6 198 */  \
    X(PVRESTORE,      0x01) /* c7 199 */  \
    X(FREEBIND,       0x02) /* c8 200 */  \
    X(FREERSTR,       0x01) /* c9 201 */  \
    X(EXIT,           0x01) /* ca 202 */  \
    X(NILEXIT,        0x01) /* cb 203 */  \
    X(LOC0EXIT,       0x01) /* cc 204 */  \
    X(LOC1EXIT,       0x01) /* cd 205 */  \
    X(LOC2EXIT,       0x01) /* ce 206 */  \
    X(PUSH,           0x01) /* cf 207 */  \
    X(PUSHNIL,        0x01) /* d0 208 */  \
    X(PUSHNIL2,       0x01) /* d1 209 */  \
    X(PUSHNIL3,       0x01) /* d2 210 */  \
    X(PUSHNILS,       0x02) /* d3 211 */  \
    X(POP,            0x01) /* d4 212 */  \
    X(LOSE,           0x01) /* d5 213 */  \
    X(LOSE2,          0x01) /* d6 214 */  \
    X(LOSE3,          0x01) /* d7 215 */  \
    X(LOSES,          0x02) /* d8 216 */  \
    X(SWOP,           0x01) /* d9 217 */  \
    X(EQ,             0x01) /* da 218 */  \
    X(EQCAR,          0x01) /* db 219 */  \
    X(EQUAL,          0x01) /* dc 220 */  \
    X(NUMBERP,        0x01) /* dd 221 */  \
    X(CAR,            0x01) /* de 222 */  \
    X(CDR,            0x01) /* df 223 */  \
    X(CAAR,           0x01) /* e0 224 */  \
    X(CADR,           0x01) /* e1 225 */  \
    X(CDAR,           0x01) /* e2 226 */  \
    X(CDDR,           0x01) /* e3 227 */  \
    X(CONS,           0x01) /* e4 228 */  \
    X(NCONS,          0x01) /* e5 229 */  \
    X(XCONS,          0x01) /* e6 230 */  \
    X(ACONS,          0x01) /* e7 231 */  \
    X(LENGTH,         0x01) /* e8 232 */  \
    X(LIST2,          0x01) /* e9 233 */  \
    X(LIST2STAR,      0x01) /* ea 234 */  \
    X(LIST3,          0x01) /* eb 235 */  \
    X(PLUS2,          0x01) /* ec 236 */  \
    X(ADD1,           0x01) /* ed 237 */  \
    X(DIFFERENCE,     0x01) /* ee 238 */  \
    X(SUB1,           0x01) /* ef 239 */  \
    X(TIMES2,         0x01) /* f0 240 */  \
    X(GREATERP,       0x01) /* f1 241 */  \
    X(LESSP,          0x01) /* f2 242 */  \
    X(FLAGP,          0x01) /* f3 243 */  \
    X(GET,            0x01) /* f4 244 */  \
    X(LITGET,         0x02) /* f5 245 */  \
    X(GETV,           0x01) /* f6 246 */  \
    X(QGETV,          0x01) /* f7 247 */  \
    X(QGETVN,         0x02) /* f8 248 */  \
    X(BIGSTACK,       0x03) /* f9 249 */  \
    X(BIGCALL,        0x03) /* fa 250 */  \
    X(ICASE,          0x02) /* fb 251 */  \
    X(FASTGET,        0x02) /* fc 252 */  \
    X(ONEVALUE,       0x01) /* fd 253 */  \
    X(SPARE1,         0x01) /* fe 254 */  \
    X(SPARE2,         0x01) /* ff 255 */

// First I set up an enumeration defining names OP_LOADLOC and so on.

#define X(name, data) OP_ ## name,
enum
{   LIST_OF_OPCODES
    OP_end_of_table
};
#undef X

// Then a matching table of the names.

#define X(name, data) # name ,
inline const char* opnames[] =
{   LIST_OF_OPCODES
    "@end of table"
};
#undef X

// And of info about follow-on bytes

#define X(name, data) data ,
inline const uint8_t oparginfo[] =
{   LIST_OF_OPCODES
    0xff
};
#undef X

#endif // header_bytes_h

// end of bytes.h

