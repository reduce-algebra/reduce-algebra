/*
x86defs.h

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#ifndef ___X86DEFS_H__
#define ___X86DEFS_H__

#include "textdefs.h"
#include "insts.h"

#define SEG_REGS_MAX (6)
#define CREGS_MAX (9)
#define DREGS_MAX (8)

// Definitions use this structure for faster copying.
// str_x86def relies on this size, copying aligned dwords.
#define DEF_TEXT_SIZE (8)
typedef struct {
	unsigned int size;
	unsigned char p[DEF_TEXT_SIZE];
} _DefText;

extern _DefText _CONDITIONS[16];
extern _DefText _CONDITIONS_PSEUDO[8];
extern _DefText _CREGS[CREGS_MAX];
extern _DefText _DREGS[DREGS_MAX];
extern _DefText _SREGS[SEG_REGS_MAX];
extern _DefText _REGS8[16];
extern _DefText _REGS8_REX[16];
extern _DefText _REGS16[16];
extern _DefText _REGS32[16];
extern _DefText _REGS64[16];
extern _DefText _REGSMMX[8];
extern _DefText _REGSSSE[16];
extern _DefText _MODS16[8];
extern _DefText _MODS32[16];
extern _DefText _MODS64[16];
extern _DefText _BASE32[16];
extern _DefText _BASE64[16];
extern _DefText _INDEX32[16];
extern _DefText _INDEX64[16];

extern _DefText _SCALE32[4];

#define FPU_STACK_TEXT ("ST")
#define ONE_CONST_TEXT ("0x1")
#define REG_RIP_TEXT ("RIP")

#define BYTE_UNDEFINED ("DB")
#define TEXT_8_BITS ("BYTE ")
#define TEXT_16_BITS ("WORD ")
#define TEXT_32_BITS ("DWORD ")
#define TEXT_64_BITS ("QWORD ")
#define TEXT_80_BITS ("TBYTE ")
#define TEXT_128_BITS ("DQWORD ")

#define PREFIX_LOCK_TEXT ("LOCK ")
#define PREFIX_REP_TEXT ("REP ")
#define PREFIX_REPNZ_TEXT ("REPNZ ")
#define PREFIX_CS_TEXT ("CS:")
#define PREFIX_SS_TEXT ("SS:")
#define PREFIX_DS_TEXT ("DS:")
#define PREFIX_ES_TEXT ("ES:")
#define PREFIX_FS_TEXT ("FS:")
#define PREFIX_GS_TEXT ("GS:")

#define SUFFIX_SIZE_BYTE ('B')
#define SUFFIX_SIZE_WORD ('W')
#define SUFFIX_SIZE_DWORD ('D')
#define SUFFIX_SIZE_QWORD ('Q')

#define OFFSET_SHORT ("SHORT ")
#define OFFSET_SMALL ("SMALL ")
#define OFFSET_LARGE ("LARGE ")

// Maximum instruction size, including prefixes
#define INST_MAXIMUM_SIZE (15)

// Maximum range of imm8 (comparison type) of special SSE instructions.
#define INST_CMP_MAX_RANGE (8)

// Wait instruction byte code
#define WAIT_INSTRUCTION_CODE (0x9b)
#define WAIT_INSTRUCTION_MNEMONIC ("WAIT")

// Minimal MODR/M value of divided instructions.
// It's 0xc0, two msb bits set, which indicates a general purpose register is used too.
#define INST_DIVIDED_MODRM (0xc0)

// This is the escape byte value used for 3DNow! instructions.
#define _3DNOW_ESCAPE_BYTE (0x0f)

#define PREFIX_LOCK (0xf0)
#define PREFIX_REPNZ (0xf2)
#define PREFIX_REP (0xf3)
#define PREFIX_CS (0x2e)
#define PREFIX_SS (0x36)
#define PREFIX_DS (0x3e)
#define PREFIX_ES (0x26)
#define PREFIX_FS (0x64)
#define PREFIX_GS (0x65)
#define PREFIX_OP_SIZE (0x66)
#define PREFIX_ADDR_SIZE (0x67)

// REX prefix value range, 64 bits mode decoding only
#define PREFIX_REX_LOW (0x40)
#define PREFIX_REX_HI (0x4f)
// In otder to use the extended GPR's we have to add 8 to the Modr/M info values.
#define REX_GPR_BASE (8)

// Mask for REX features:
// Base
#define PREFIX_REX_B (1)
// Index
#define PREFIX_REX_X (2)
// Register
#define PREFIX_REX_R (4)
// Operand Width
#define PREFIX_REX_W (8)

// The locate_inst will return on of these two instructions according to the specified decoding mode.
// ARPL or MOVSXD on 64 bits is one byte instruction at index 0x63.
#define INST_ARPL_INDEX (0x63)
extern _InstInfo II_arpl;
extern _InstInfo II_movsxd;

_INLINE_ void str_x86def(_WString* s, _DefText* d)
{
	// Copy 2 aligned dwords to speed up things.
	// _WString should have that extra space, most of the times it will simply copy null-termianting characters.
	*(long*)&s->p[s->pos] = *(long*)d->p;
	*(long*)&s->p[s->pos + sizeof(long)] = *(long*)&d->p[sizeof(long)];
	s->pos += d->size;
}

#endif // ___X86DEFS_H__
