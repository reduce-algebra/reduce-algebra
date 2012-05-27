/* opnames.c                           Copyright (C) Codemist 1993-2008 */

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


/* Signature: 23b62659 24-May-2008 */

/*
 * table giving printable names for all 256 byte opcodes.
 */

static char *opnames[256] =
{
   "LOADLOC",                   /* 0x00 */
   "LOADLOC0",                  /* 0x01 */
   "LOADLOC1",                  /* 0x02 */
   "LOADLOC2",                  /* 0x03 */
   "LOADLOC3",                  /* 0x04 */
   "LOADLOC4",                  /* 0x05 */
   "LOADLOC5",                  /* 0x06 */
   "LOADLOC6",                  /* 0x07 */
   "LOADLOC7",                  /* 0x08 */
   "LOADLOC8",                  /* 0x09 */
   "LOADLOC9",                  /* 0x0a */
   "LOADLOC10",                 /* 0x0b */
   "LOADLOC11",                 /* 0x0c */
   "LOC0LOC1",                  /* 0x0d */
   "LOC1LOC2",                  /* 0x0e */
   "LOC2LOC3",                  /* 0x0f */
   "LOC1LOC0",                  /* 0x10 */
   "LOC2LOC1",                  /* 0x11 */
   "LOC3LOC2",                  /* 0x12 */
   "VNIL",                      /* 0x13 */
   "LOADLIT",                   /* 0x14 */
   "LOADLIT1",                  /* 0x15 */
   "LOADLIT2",                  /* 0x16 */
   "LOADLIT3",                  /* 0x17 */
   "LOADLIT4",                  /* 0x18 */
   "LOADLIT5",                  /* 0x19 */
   "LOADLIT6",                  /* 0x1a */
   "LOADLIT7",                  /* 0x1b */
   "LOADFREE",                  /* 0x1c */
   "LOADFREE1",                 /* 0x1d */
   "LOADFREE2",                 /* 0x1e */
   "LOADFREE3",                 /* 0x1f */
   "LOADFREE4",                 /* 0x20 */
   "STORELOC",                  /* 0x21 */
   "STORELOC0",                 /* 0x22 */
   "STORELOC1",                 /* 0x23 */
   "STORELOC2",                 /* 0x24 */
   "STORELOC3",                 /* 0x25 */
   "STORELOC4",                 /* 0x26 */
   "STORELOC5",                 /* 0x27 */
   "STORELOC6",                 /* 0x28 */
   "STORELOC7",                 /* 0x29 */
   "STOREFREE",                 /* 0x2a */
   "STOREFREE1",                /* 0x2b */
   "STOREFREE2",                /* 0x2c */
   "STOREFREE3",                /* 0x2d */
   "LOADLEX",                   /* 0x2e */
   "STORELEX",                  /* 0x2f */
   "CLOSURE",                   /* 0x30 */
   "CARLOC0",                   /* 0x31 */
   "CARLOC1",                   /* 0x32 */
   "CARLOC2",                   /* 0x33 */
   "CARLOC3",                   /* 0x34 */
   "CARLOC4",                   /* 0x35 */
   "CARLOC5",                   /* 0x36 */
   "CARLOC6",                   /* 0x37 */
   "CARLOC7",                   /* 0x38 */
   "CARLOC8",                   /* 0x39 */
   "CARLOC9",                   /* 0x3a */
   "CARLOC10",                  /* 0x3b */
   "CARLOC11",                  /* 0x3c */
   "CDRLOC0",                   /* 0x3d */
   "CDRLOC1",                   /* 0x3e */
   "CDRLOC2",                   /* 0x3f */
   "CDRLOC3",                   /* 0x40 */
   "CDRLOC4",                   /* 0x41 */
   "CDRLOC5",                   /* 0x42 */
   "CAARLOC0",                  /* 0x43 */
   "CAARLOC1",                  /* 0x44 */
   "CAARLOC2",                  /* 0x45 */
   "CAARLOC3",                  /* 0x46 */
   "CALL0",                     /* 0x47 */
   "CALL1",                     /* 0x48 */
   "CALL2",                     /* 0x49 */
   "CALL2R",                    /* 0x4a */
   "CALL3",                     /* 0x4b */
   "CALLN",                     /* 0x4c */
   "CALL0_0",                   /* 0x4d */
   "CALL0_1",                   /* 0x4e */
   "CALL0_2",                   /* 0x4f */
   "CALL0_3",                   /* 0x50 */
   "CALL1_0",                   /* 0x51 */
   "CALL1_1",                   /* 0x52 */
   "CALL1_2",                   /* 0x53 */
   "CALL1_3",                   /* 0x54 */
   "CALL1_4",                   /* 0x55 */
   "CALL1_5",                   /* 0x56 */
   "CALL2_0",                   /* 0x57 */
   "CALL2_1",                   /* 0x58 */
   "CALL2_2",                   /* 0x59 */
   "CALL2_3",                   /* 0x5a */
   "CALL2_4",                   /* 0x5b */
   "BUILTIN0",                  /* 0x5c */
   "BUILTIN1",                  /* 0x5d */
   "BUILTIN2",                  /* 0x5e */
   "BUILTIN2R",                 /* 0x5f */
   "BUILTIN3",                  /* 0x60 */
   "APPLY1",                    /* 0x61 */
   "APPLY2",                    /* 0x62 */
   "APPLY3",                    /* 0x63 */
   "APPLY4",                    /* 0x64 */
   "JCALL",                     /* 0x65 */
   "JCALLN",                    /* 0x66 */
   "JUMP",                      /* 0x67 */
   "JUMP_B",                    /* 0x68 */
   "JUMP_L",                    /* 0x69 */
   "JUMP_BL",                   /* 0x6a */
   "JUMPNIL",                   /* 0x6b */
   "JUMPNIL_B",                 /* 0x6c */
   "JUMPNIL_L",                 /* 0x6d */
   "JUMPNIL_BL",                /* 0x6e */
   "JUMPT",                     /* 0x6f */
   "JUMPT_B",                   /* 0x70 */
   "JUMPT_L",                   /* 0x71 */
   "JUMPT_BL",                  /* 0x72 */
   "JUMPATOM",                  /* 0x73 */
   "JUMPATOM_B",                /* 0x74 */
   "JUMPATOM_L",                /* 0x75 */
   "JUMPATOM_BL",               /* 0x76 */
   "JUMPNATOM",                 /* 0x77 */
   "JUMPNATOM_B",               /* 0x78 */
   "JUMPNATOM_L",               /* 0x79 */
   "JUMPNATOM_BL",              /* 0x7a */
   "JUMPEQ",                    /* 0x7b */
   "JUMPEQ_B",                  /* 0x7c */
   "JUMPEQ_L",                  /* 0x7d */
   "JUMPEQ_BL",                 /* 0x7e */
   "JUMPNE",                    /* 0x7f */
   "JUMPNE_B",                  /* 0x80 */
   "JUMPNE_L",                  /* 0x81 */
   "JUMPNE_BL",                 /* 0x82 */
   "JUMPEQUAL",                 /* 0x83 */
   "JUMPEQUAL_B",               /* 0x84 */
   "JUMPEQUAL_L",               /* 0x85 */
   "JUMPEQUAL_BL",              /* 0x86 */
   "JUMPNEQUAL",                /* 0x87 */
   "JUMPNEQUAL_B",              /* 0x88 */
   "JUMPNEQUAL_L",              /* 0x89 */
   "JUMPNEQUAL_BL",             /* 0x8a */
   "JUMPL0NIL",                 /* 0x8b */
   "JUMPL0T",                   /* 0x8c */
   "JUMPL1NIL",                 /* 0x8d */
   "JUMPL1T",                   /* 0x8e */
   "JUMPL2NIL",                 /* 0x8f */
   "JUMPL2T",                   /* 0x90 */
   "JUMPL3NIL",                 /* 0x91 */
   "JUMPL3T",                   /* 0x92 */
   "JUMPL4NIL",                 /* 0x93 */
   "JUMPL4T",                   /* 0x94 */
   "JUMPST0NIL",                /* 0x95 */
   "JUMPST0T",                  /* 0x96 */
   "JUMPST1NIL",                /* 0x97 */
   "JUMPST1T",                  /* 0x98 */
   "JUMPST2NIL",                /* 0x99 */
   "JUMPST2T",                  /* 0x9a */
   "JUMPL0ATOM",                /* 0x9b */
   "JUMPL0NATOM",               /* 0x9c */
   "JUMPL1ATOM",                /* 0x9d */
   "JUMPL1NATOM",               /* 0x9e */
   "JUMPL2ATOM",                /* 0x9f */
   "JUMPL2NATOM",               /* 0xa0 */
   "JUMPL3ATOM",                /* 0xa1 */
   "JUMPL3NATOM",               /* 0xa2 */
   "JUMPFREE1NIL",              /* 0xa3 */
   "JUMPFREE1T",                /* 0xa4 */
   "JUMPFREE2NIL",              /* 0xa5 */
   "JUMPFREE2T",                /* 0xa6 */
   "JUMPFREE3NIL",              /* 0xa7 */
   "JUMPFREE3T",                /* 0xa8 */
   "JUMPFREE4NIL",              /* 0xa9 */
   "JUMPFREE4T",                /* 0xaa */
   "JUMPFREENIL",               /* 0xab */
   "JUMPFREET",                 /* 0xac */
   "JUMPLIT1EQ",                /* 0xad */
   "JUMPLIT1NE",                /* 0xae */
   "JUMPLIT2EQ",                /* 0xaf */
   "JUMPLIT2NE",                /* 0xb0 */
   "JUMPLIT3EQ",                /* 0xb1 */
   "JUMPLIT3NE",                /* 0xb2 */
   "JUMPLIT4EQ",                /* 0xb3 */
   "JUMPLIT4NE",                /* 0xb4 */
   "JUMPLITEQ",                 /* 0xb5 */
   "JUMPLITNE",                 /* 0xb6 */
   "JUMPB1NIL",                 /* 0xb7 */
   "JUMPB1T",                   /* 0xb8 */
   "JUMPB2NIL",                 /* 0xb9 */
   "JUMPB2T",                   /* 0xba */
   "JUMPFLAGP",                 /* 0xbb */
   "JUMPNFLAGP",                /* 0xbc */
   "JUMPEQCAR",                 /* 0xbd */
   "JUMPNEQCAR",                /* 0xbe */
   "CATCH",                     /* 0xbf */
   "CATCH_B",                   /* 0xc0 */
   "CATCH_L",                   /* 0xc1 */
   "CATCH_BL",                  /* 0xc2 */
   "UNCATCH",                   /* 0xc3 */
   "THROW",                     /* 0xc4 */
   "PROTECT",                   /* 0xc5 */
   "UNPROTECT",                 /* 0xc6 */
   "PVBIND",                    /* 0xc7 */
   "PVRESTORE",                 /* 0xc8 */
   "FREEBIND",                  /* 0xc9 */
   "FREERSTR",                  /* 0xca */
   "EXIT",                      /* 0xcb */
   "NILEXIT",                   /* 0xcc */
   "LOC0EXIT",                  /* 0xcd */
   "LOC1EXIT",                  /* 0xce */
   "LOC2EXIT",                  /* 0xcf */
   "PUSH",                      /* 0xd0 */
   "PUSHNIL",                   /* 0xd1 */
   "PUSHNIL2",                  /* 0xd2 */
   "PUSHNIL3",                  /* 0xd3 */
   "PUSHNILS",                  /* 0xd4 */
   "POP",                       /* 0xd5 */
   "LOSE",                      /* 0xd6 */
   "LOSE2",                     /* 0xd7 */
   "LOSE3",                     /* 0xd8 */
   "LOSES",                     /* 0xd9 */
   "SWOP",                      /* 0xda */
   "EQ",                        /* 0xdb */
   "EQCAR",                     /* 0xdc */
   "EQUAL",                     /* 0xdd */
   "NUMBERP",                   /* 0xde */
   "CAR",                       /* 0xdf */
   "CDR",                       /* 0xe0 */
   "CAAR",                      /* 0xe1 */
   "CADR",                      /* 0xe2 */
   "CDAR",                      /* 0xe3 */
   "CDDR",                      /* 0xe4 */
   "CONS",                      /* 0xe5 */
   "NCONS",                     /* 0xe6 */
   "XCONS",                     /* 0xe7 */
   "ACONS",                     /* 0xe8 */
   "LENGTH",                    /* 0xe9 */
   "LIST2",                     /* 0xea */
   "LIST2STAR",                 /* 0xeb */
   "LIST3",                     /* 0xec */
   "PLUS2",                     /* 0xed */
   "ADD1",                      /* 0xee */
   "DIFFERENCE",                /* 0xef */
   "SUB1",                      /* 0xf0 */
   "TIMES2",                    /* 0xf1 */
   "GREATERP",                  /* 0xf2 */
   "LESSP",                     /* 0xf3 */
   "FLAGP",                     /* 0xf4 */
   "GET",                       /* 0xf5 */
   "LITGET",                    /* 0xf6 */
   "GETV",                      /* 0xf7 */
   "QGETV",                     /* 0xf8 */
   "QGETVN",                    /* 0xf9 */
   "BIGSTACK",                  /* 0xfa */
   "BIGCALL",                   /* 0xfb */
   "ICASE",                     /* 0xfc */
   "FASTGET",                   /* 0xfd */
   "SPARE1",                    /* 0xfe */
   "SPARE2",                    /* 0xff */
};

/* end of opnames.c */
