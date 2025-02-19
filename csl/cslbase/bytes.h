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
    X(LOADLOC)          \
    X(LOADLOC0)         \
    X(LOADLOC1)         \
    X(LOADLOC2)         \
    X(LOADLOC3)         \
    X(LOADLOC4)         \
    X(LOADLOC5)         \
    X(LOADLOC6)         \
    X(LOADLOC7)         \
    X(LOADLOC8)         \
    X(LOADLOC9)         \
    X(LOADLOC10)        \
    X(LOADLOC11)        \
    X(LOC0LOC1)         \
    X(LOC1LOC2)         \
    X(LOC2LOC3)         \
    X(LOC1LOC0)         \
    X(LOC2LOC1)         \
    X(LOC3LOC2)         \
    X(VNIL)             \
    X(LOADLIT)          \
    X(LOADLIT1)         \
    X(LOADLIT2)         \
    X(LOADLIT3)         \
    X(LOADLIT4)         \
    X(LOADLIT5)         \
    X(LOADLIT6)         \
    X(LOADLIT7)         \
    X(LOADFREE)         \
    X(LOADFREE1)        \
    X(LOADFREE2)        \
    X(LOADFREE3)        \
    X(LOADFREE4)        \
    X(STORELOC)         \
    X(STORELOC0)        \
    X(STORELOC1)        \
    X(STORELOC2)        \
    X(STORELOC3)        \
    X(STORELOC4)        \
    X(STORELOC5)        \
    X(STORELOC6)        \
    X(STORELOC7)        \
    X(STOREFREE)        \
    X(STOREFREE1)       \
    X(STOREFREE2)       \
    X(STOREFREE3)       \
    X(LOADLEX)          \
    X(STORELEX)         \
    X(CLOSURE)          \
    X(CARLOC0)          \
    X(CARLOC1)          \
    X(CARLOC2)          \
    X(CARLOC3)          \
    X(CARLOC4)          \
    X(CARLOC5)          \
    X(CARLOC6)          \
    X(CARLOC7)          \
    X(CARLOC8)          \
    X(CARLOC9)          \
    X(CARLOC10)         \
    X(CARLOC11)         \
    X(CDRLOC0)          \
    X(CDRLOC1)          \
    X(CDRLOC2)          \
    X(CDRLOC3)          \
    X(CDRLOC4)          \
    X(CDRLOC5)          \
    X(CAARLOC0)         \
    X(CAARLOC1)         \
    X(CAARLOC2)         \
    X(CAARLOC3)         \
    X(CALL0)            \
    X(CALL1)            \
    X(CALL2)            \
    X(CALL2R)           \
    X(CALL3)            \
    X(CALL4)            \
    X(CALL0_0)          \
    X(CALL0_1)          \
    X(CALL0_2)          \
    X(CALL0_3)          \
    X(CALL1_0)          \
    X(CALL1_1)          \
    X(CALL1_2)          \
    X(CALL1_3)          \
    X(CALL1_4)          \
    X(CALL1_5)          \
    X(CALL2_0)          \
    X(CALL2_1)          \
    X(CALL2_2)          \
    X(CALL2_3)          \
    X(CALL2_4)          \
    X(BUILTIN0)         \
    X(BUILTIN1)         \
    X(BUILTIN2)         \
    X(BUILTIN2R)        \
    X(BUILTIN3)         \
    X(APPLY1)           \
    X(APPLY2)           \
    X(APPLY3)           \
    X(APPLY4)           \
    X(JCALL)            \
    X(JUMP)             \
    X(JUMP_B)           \
    X(JUMP_L)           \
    X(JUMP_BL)          \
    X(JUMPNIL)          \
    X(JUMPNIL_B)        \
    X(JUMPNIL_L)        \
    X(JUMPNIL_BL)       \
    X(JUMPT)            \
    X(JUMPT_B)          \
    X(JUMPT_L)          \
    X(JUMPT_BL)         \
    X(JUMPATOM)         \
    X(JUMPATOM_B)       \
    X(JUMPATOM_L)       \
    X(JUMPATOM_BL)      \
    X(JUMPNATOM)        \
    X(JUMPNATOM_B)      \
    X(JUMPNATOM_L)      \
    X(JUMPNATOM_BL)     \
    X(JUMPEQ)           \
    X(JUMPEQ_B)         \
    X(JUMPEQ_L)         \
    X(JUMPEQ_BL)        \
    X(JUMPNE)           \
    X(JUMPNE_B)         \
    X(JUMPNE_L)         \
    X(JUMPNE_BL)        \
    X(JUMPEQUAL)        \
    X(JUMPEQUAL_B)      \
    X(JUMPEQUAL_L)      \
    X(JUMPEQUAL_BL)     \
    X(JUMPNEQUAL)       \
    X(JUMPNEQUAL_B)     \
    X(JUMPNEQUAL_L)     \
    X(JUMPNEQUAL_BL)    \
    X(JUMPL0NIL)        \
    X(JUMPL0T)          \
    X(JUMPL1NIL)        \
    X(JUMPL1T)          \
    X(JUMPL2NIL)        \
    X(JUMPL2T)          \
    X(JUMPL3NIL)        \
    X(JUMPL3T)          \
    X(JUMPL4NIL)        \
    X(JUMPL4T)          \
    X(JUMPST0NIL)       \
    X(JUMPST0T)         \
    X(JUMPST1NIL)       \
    X(JUMPST1T)         \
    X(JUMPST2NIL)       \
    X(JUMPST2T)         \
    X(JUMPL0ATOM)       \
    X(JUMPL0NATOM)      \
    X(JUMPL1ATOM)       \
    X(JUMPL1NATOM)      \
    X(JUMPL2ATOM)       \
    X(JUMPL2NATOM)      \
    X(JUMPL3ATOM)       \
    X(JUMPL3NATOM)      \
    X(JUMPFREE1NIL)     \
    X(JUMPFREE1T)       \
    X(JUMPFREE2NIL)     \
    X(JUMPFREE2T)       \
    X(JUMPFREE3NIL)     \
    X(JUMPFREE3T)       \
    X(JUMPFREE4NIL)     \
    X(JUMPFREE4T)       \
    X(JUMPFREENIL)      \
    X(JUMPFREET)        \
    X(JUMPLIT1EQ)       \
    X(JUMPLIT1NE)       \
    X(JUMPLIT2EQ)       \
    X(JUMPLIT2NE)       \
    X(JUMPLIT3EQ)       \
    X(JUMPLIT3NE)       \
    X(JUMPLIT4EQ)       \
    X(JUMPLIT4NE)       \
    X(JUMPLITEQ)        \
    X(JUMPLITNE)        \
    X(JUMPB1NIL)        \
    X(JUMPB1T)          \
    X(JUMPB2NIL)        \
    X(JUMPB2T)          \
    X(JUMPFLAGP)        \
    X(JUMPNFLAGP)       \
    X(JUMPEQCAR)        \
    X(JUMPNEQCAR)       \
    X(CATCH)            \
    X(CATCH_B)          \
    X(CATCH_L)          \
    X(CATCH_BL)         \
    X(UNCATCH)          \
    X(THROW)            \
    X(PROTECT)          \
    X(UNPROTECT)        \
    X(PVBIND)           \
    X(PVRESTORE)        \
    X(FREEBIND)         \
    X(FREERSTR)         \
    X(EXIT)             \
    X(NILEXIT)          \
    X(LOC0EXIT)         \
    X(LOC1EXIT)         \
    X(LOC2EXIT)         \
    X(PUSH)             \
    X(PUSHNIL)          \
    X(PUSHNIL2)         \
    X(PUSHNIL3)         \
    X(PUSHNILS)         \
    X(POP)              \
    X(LOSE)             \
    X(LOSE2)            \
    X(LOSE3)            \
    X(LOSES)            \
    X(SWOP)             \
    X(EQ)               \
    X(EQCAR)            \
    X(EQUAL)            \
    X(NUMBERP)          \
    X(CAR)              \
    X(CDR)              \
    X(CAAR)             \
    X(CADR)             \
    X(CDAR)             \
    X(CDDR)             \
    X(CONS)             \
    X(NCONS)            \
    X(XCONS)            \
    X(ACONS)            \
    X(LENGTH)           \
    X(LIST2)            \
    X(LIST2STAR)        \
    X(LIST3)            \
    X(PLUS2)            \
    X(ADD1)             \
    X(DIFFERENCE)       \
    X(SUB1)             \
    X(TIMES2)           \
    X(GREATERP)         \
    X(LESSP)            \
    X(FLAGP)            \
    X(GET)              \
    X(LITGET)           \
    X(GETV)             \
    X(QGETV)            \
    X(QGETVN)           \
    X(BIGSTACK)         \
    X(BIGCALL)          \
    X(ICASE)            \
    X(FASTGET)          \
    X(ONEVALUE)         \
    X(SPARE1)           \
    X(SPARE2)

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
