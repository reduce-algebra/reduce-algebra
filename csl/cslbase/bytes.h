// bytes.h                                 Copyright (C) Codemist 1993-2025



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

#define LIST_OF_OPCODES \
    X(LOADLOC)        /* 00   0 */  \
    X(LOADLOC0)       /* 01   1 */  \
    X(LOADLOC1)       /* 02   2 */  \
    X(LOADLOC2)       /* 03   3 */  \
    X(LOADLOC3)       /* 04   4 */  \
    X(LOADLOC4)       /* 05   5 */  \
    X(LOADLOC5)       /* 06   6 */  \
    X(LOADLOC6)       /* 07   7 */  \
    X(LOADLOC7)       /* 08   8 */  \
    X(LOADLOC8)       /* 09   9 */  \
    X(LOADLOC9)       /* 0a  10 */  \
    X(LOADLOC10)      /* 0b  11 */  \
    X(LOADLOC11)      /* 0c  12 */  \
    X(LOC0LOC1)       /* 0d  13 */  \
    X(LOC1LOC2)       /* 0e  14 */  \
    X(LOC2LOC3)       /* 0f  15 */  \
    X(LOC1LOC0)       /* 10  16 */  \
    X(LOC2LOC1)       /* 11  17 */  \
    X(LOC3LOC2)       /* 12  18 */  \
    X(VNIL)           /* 13  19 */  \
    X(LOADLIT)        /* 14  20 */  \
    X(LOADLIT1)       /* 15  21 */  \
    X(LOADLIT2)       /* 16  22 */  \
    X(LOADLIT3)       /* 17  23 */  \
    X(LOADLIT4)       /* 18  24 */  \
    X(LOADLIT5)       /* 19  25 */  \
    X(LOADLIT6)       /* 1a  26 */  \
    X(LOADLIT7)       /* 1b  27 */  \
    X(LOADFREE)       /* 1c  28 */  \
    X(LOADFREE1)      /* 1d  29 */  \
    X(LOADFREE2)      /* 1e  30 */  \
    X(LOADFREE3)      /* 1f  31 */  \
    X(LOADFREE4)      /* 20  32 */  \
    X(STORELOC)       /* 21  33 */  \
    X(STORELOC0)      /* 22  34 */  \
    X(STORELOC1)      /* 23  35 */  \
    X(STORELOC2)      /* 24  36 */  \
    X(STORELOC3)      /* 25  37 */  \
    X(STORELOC4)      /* 26  38 */  \
    X(STORELOC5)      /* 27  39 */  \
    X(STORELOC6)      /* 28  40 */  \
    X(STORELOC7)      /* 29  41 */  \
    X(STOREFREE)      /* 2a  42 */  \
    X(STOREFREE1)     /* 2b  43 */  \
    X(STOREFREE2)     /* 2c  44 */  \
    X(STOREFREE3)     /* 2d  45 */  \
    X(LOADLEX)        /* 2e  46 */  \
    X(STORELEX)       /* 2f  47 */  \
    X(CLOSURE)        /* 30  48 */  \
    X(CARLOC0)        /* 31  49 */  \
    X(CARLOC1)        /* 32  50 */  \
    X(CARLOC2)        /* 33  51 */  \
    X(CARLOC3)        /* 34  52 */  \
    X(CARLOC4)        /* 35  53 */  \
    X(CARLOC5)        /* 36  54 */  \
    X(CARLOC6)        /* 37  55 */  \
    X(CARLOC7)        /* 38  56 */  \
    X(CARLOC8)        /* 39  57 */  \
    X(CARLOC9)        /* 3a  58 */  \
    X(CARLOC10)       /* 3b  59 */  \
    X(CARLOC11)       /* 3c  60 */  \
    X(CDRLOC0)        /* 3d  61 */  \
    X(CDRLOC1)        /* 3e  62 */  \
    X(CDRLOC2)        /* 3f  63 */  \
    X(CDRLOC3)        /* 40  64 */  \
    X(CDRLOC4)        /* 41  65 */  \
    X(CDRLOC5)        /* 42  66 */  \
    X(CAARLOC0)       /* 43  67 */  \
    X(CAARLOC1)       /* 44  68 */  \
    X(CAARLOC2)       /* 45  69 */  \
    X(CAARLOC3)       /* 46  70 */  \
    X(CALL0)          /* 47  71 */  \
    X(CALL1)          /* 48  72 */  \
    X(CALL2)          /* 49  73 */  \
    X(CALL2R)         /* 4a  74 */  \
    X(CALL3)          /* 4b  75 */  \
    X(CALL4)          /* 4c  76 */  \
    X(CALL0_0)        /* 4d  77 */  \
    X(CALL0_1)        /* 4e  78 */  \
    X(CALL0_2)        /* 4f  79 */  \
    X(CALL0_3)        /* 50  80 */  \
    X(CALL1_0)        /* 51  81 */  \
    X(CALL1_1)        /* 52  82 */  \
    X(CALL1_2)        /* 53  83 */  \
    X(CALL1_3)        /* 54  84 */  \
    X(CALL1_4)        /* 55  85 */  \
    X(CALL1_5)        /* 56  86 */  \
    X(CALL2_0)        /* 57  87 */  \
    X(CALL2_1)        /* 58  88 */  \
    X(CALL2_2)        /* 59  89 */  \
    X(CALL2_3)        /* 5a  90 */  \
    X(CALL2_4)        /* 5b  91 */  \
    X(BUILTIN0)       /* 5c  92 */  \
    X(BUILTIN1)       /* 5d  93 */  \
    X(BUILTIN2)       /* 5e  94 */  \
    X(BUILTIN2R)      /* 5f  95 */  \
    X(BUILTIN3)       /* 60  96 */  \
    X(APPLY1)         /* 61  97 */  \
    X(APPLY2)         /* 62  98 */  \
    X(APPLY3)         /* 63  99 */  \
    X(APPLY4)         /* 64 100 */  \
    X(JCALL)          /* 65 101 */  \
    X(JUMP)           /* 66 102 */  \
    X(JUMP_B)         /* 67 103 */  \
    X(JUMP_L)         /* 68 104 */  \
    X(JUMP_BL)        /* 69 105 */  \
    X(JUMPNIL)        /* 6a 106 */  \
    X(JUMPNIL_B)      /* 6b 107 */  \
    X(JUMPNIL_L)      /* 6c 108 */  \
    X(JUMPNIL_BL)     /* 6d 109 */  \
    X(JUMPT)          /* 6e 110 */  \
    X(JUMPT_B)        /* 6f 111 */  \
    X(JUMPT_L)        /* 70 112 */  \
    X(JUMPT_BL)       /* 71 113 */  \
    X(JUMPATOM)       /* 72 114 */  \
    X(JUMPATOM_B)     /* 73 115 */  \
    X(JUMPATOM_L)     /* 74 116 */  \
    X(JUMPATOM_BL)    /* 75 117 */  \
    X(JUMPNATOM)      /* 76 118 */  \
    X(JUMPNATOM_B)    /* 77 119 */  \
    X(JUMPNATOM_L)    /* 78 120 */  \
    X(JUMPNATOM_BL)   /* 79 121 */  \
    X(JUMPEQ)         /* 7a 122 */  \
    X(JUMPEQ_B)       /* 7b 123 */  \
    X(JUMPEQ_L)       /* 7c 124 */  \
    X(JUMPEQ_BL)      /* 7d 125 */  \
    X(JUMPNE)         /* 7e 126 */  \
    X(JUMPNE_B)       /* 7f 127 */  \
    X(JUMPNE_L)       /* 80 128 */  \
    X(JUMPNE_BL)      /* 81 129 */  \
    X(JUMPEQUAL)      /* 82 130 */  \
    X(JUMPEQUAL_B)    /* 83 131 */  \
    X(JUMPEQUAL_L)    /* 84 132 */  \
    X(JUMPEQUAL_BL)   /* 85 133 */  \
    X(JUMPNEQUAL)     /* 86 134 */  \
    X(JUMPNEQUAL_B)   /* 87 135 */  \
    X(JUMPNEQUAL_L)   /* 88 136 */  \
    X(JUMPNEQUAL_BL)  /* 89 137 */  \
    X(JUMPL0NIL)      /* 8a 138 */  \
    X(JUMPL0T)        /* 8b 139 */  \
    X(JUMPL1NIL)      /* 8c 140 */  \
    X(JUMPL1T)        /* 8d 141 */  \
    X(JUMPL2NIL)      /* 8e 142 */  \
    X(JUMPL2T)        /* 8f 143 */  \
    X(JUMPL3NIL)      /* 90 144 */  \
    X(JUMPL3T)        /* 91 145 */  \
    X(JUMPL4NIL)      /* 92 146 */  \
    X(JUMPL4T)        /* 93 147 */  \
    X(JUMPST0NIL)     /* 94 148 */  \
    X(JUMPST0T)       /* 95 149 */  \
    X(JUMPST1NIL)     /* 96 150 */  \
    X(JUMPST1T)       /* 97 151 */  \
    X(JUMPST2NIL)     /* 98 152 */  \
    X(JUMPST2T)       /* 99 153 */  \
    X(JUMPL0ATOM)     /* 9a 154 */  \
    X(JUMPL0NATOM)    /* 9b 155 */  \
    X(JUMPL1ATOM)     /* 9c 156 */  \
    X(JUMPL1NATOM)    /* 9d 157 */  \
    X(JUMPL2ATOM)     /* 9e 158 */  \
    X(JUMPL2NATOM)    /* 9f 159 */  \
    X(JUMPL3ATOM)     /* a0 160 */  \
    X(JUMPL3NATOM)    /* a1 161 */  \
    X(JUMPFREE1NIL)   /* a2 162 */  \
    X(JUMPFREE1T)     /* a3 163 */  \
    X(JUMPFREE2NIL)   /* a4 164 */  \
    X(JUMPFREE2T)     /* a5 165 */  \
    X(JUMPFREE3NIL)   /* a6 166 */  \
    X(JUMPFREE3T)     /* a7 167 */  \
    X(JUMPFREE4NIL)   /* a8 168 */  \
    X(JUMPFREE4T)     /* a9 169 */  \
    X(JUMPFREENIL)    /* aa 170 */  \
    X(JUMPFREET)      /* ab 171 */  \
    X(JUMPLIT1EQ)     /* ac 172 */  \
    X(JUMPLIT1NE)     /* ad 173 */  \
    X(JUMPLIT2EQ)     /* ae 174 */  \
    X(JUMPLIT2NE)     /* af 175 */  \
    X(JUMPLIT3EQ)     /* b0 176 */  \
    X(JUMPLIT3NE)     /* b1 177 */  \
    X(JUMPLIT4EQ)     /* b2 178 */  \
    X(JUMPLIT4NE)     /* b3 179 */  \
    X(JUMPLITEQ)      /* b4 180 */  \
    X(JUMPLITNE)      /* b5 181 */  \
    X(JUMPB1NIL)      /* b6 182 */  \
    X(JUMPB1T)        /* b7 183 */  \
    X(JUMPB2NIL)      /* b8 184 */  \
    X(JUMPB2T)        /* b9 185 */  \
    X(JUMPFLAGP)      /* ba 186 */  \
    X(JUMPNFLAGP)     /* bb 187 */  \
    X(JUMPEQCAR)      /* bc 188 */  \
    X(JUMPNEQCAR)     /* bd 189 */  \
    X(CATCH)          /* be 190 */  \
    X(CATCH_B)        /* bf 191 */  \
    X(CATCH_L)        /* c0 192 */  \
    X(CATCH_BL)       /* c1 193 */  \
    X(UNCATCH)        /* c2 194 */  \
    X(THROW)          /* c3 195 */  \
    X(PROTECT)        /* c4 196 */  \
    X(UNPROTECT)      /* c5 197 */  \
    X(PVBIND)         /* c6 198 */  \
    X(PVRESTORE)      /* c7 199 */  \
    X(FREEBIND)       /* c8 200 */  \
    X(FREERSTR)       /* c9 201 */  \
    X(EXIT)           /* ca 202 */  \
    X(NILEXIT)        /* cb 203 */  \
    X(LOC0EXIT)       /* cc 204 */  \
    X(LOC1EXIT)       /* cd 205 */  \
    X(LOC2EXIT)       /* ce 206 */  \
    X(PUSH)           /* cf 207 */  \
    X(PUSHNIL)        /* d0 208 */  \
    X(PUSHNIL2)       /* d1 209 */  \
    X(PUSHNIL3)       /* d2 210 */  \
    X(PUSHNILS)       /* d3 211 */  \
    X(POP)            /* d4 212 */  \
    X(LOSE)           /* d5 213 */  \
    X(LOSE2)          /* d6 214 */  \
    X(LOSE3)          /* d7 215 */  \
    X(LOSES)          /* d8 216 */  \
    X(SWOP)           /* d9 217 */  \
    X(EQ)             /* da 218 */  \
    X(EQCAR)          /* db 219 */  \
    X(EQUAL)          /* dc 220 */  \
    X(NUMBERP)        /* dd 221 */  \
    X(CAR)            /* de 222 */  \
    X(CDR)            /* df 223 */  \
    X(CAAR)           /* e0 224 */  \
    X(CADR)           /* e1 225 */  \
    X(CDAR)           /* e2 226 */  \
    X(CDDR)           /* e3 227 */  \
    X(CONS)           /* e4 228 */  \
    X(NCONS)          /* e5 229 */  \
    X(XCONS)          /* e6 230 */  \
    X(ACONS)          /* e7 231 */  \
    X(LENGTH)         /* e8 232 */  \
    X(LIST2)          /* e9 233 */  \
    X(LIST2STAR)      /* ea 234 */  \
    X(LIST3)          /* eb 235 */  \
    X(PLUS2)          /* ec 236 */  \
    X(ADD1)           /* ed 237 */  \
    X(DIFFERENCE)     /* ee 238 */  \
    X(SUB1)           /* ef 239 */  \
    X(TIMES2)         /* f0 240 */  \
    X(GREATERP)       /* f1 241 */  \
    X(LESSP)          /* f2 242 */  \
    X(FLAGP)          /* f3 243 */  \
    X(GET)            /* f4 244 */  \
    X(LITGET)         /* f5 245 */  \
    X(GETV)           /* f6 246 */  \
    X(QGETV)          /* f7 247 */  \
    X(QGETVN)         /* f8 248 */  \
    X(BIGSTACK)       /* f9 249 */  \
    X(BIGCALL)        /* fa 250 */  \
    X(ICASE)          /* fb 251 */  \
    X(FASTGET)        /* fc 252 */  \
    X(ONEVALUE)       /* fd 253 */  \
    X(SPARE1)         /* fe 254 */  \
    X(SPARE2)         /* ff 255 */

// First I set up an enumeration defining names OP_LOADLOC and so on.

#define X(name) OP_ ## name,
enum
{   LIST_OF_OPCODES
    OP_end_of_table
};
#undef X

// Then a matching table of the names.

#define X(name) # name ,
inline const char* opnames[] =
{   LIST_OF_OPCODES
    "@end of table"
};
#undef X 

#endif // header_bytes_h

// end of bytes.h
