/*
instructions.h

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#ifndef ___INSTRUCTIONS_H__
#define ___INSTRUCTIONS_H__

#include "decoder.h"
#include "prefix.h"

// Operand type possibilities:
// Note "_FULL" suffix indicates to decode the operand as 16 bits or 32 bits depends on DecodeType -
// actually, it depends on the decoding mode, unless there's an operand/address size prefix.
// For example, the code: 33 c0 could be decoded/executed as XOR AX, AX or XOR EAX, EAX.
typedef enum OpType{
	// No operand set
	OT_NONE = 0,

	// Read a byte(8 bits) immediate
	OT_IMM8,
	// Force a read of a word(16 bits) immediate, used by ret only
	OT_IMM16,
	// Read a word/dword immediate
	OT_IMM_FULL,
	// Read a double-word(32 bits) immediate
	OT_IMM32,

	// Special immediate for two instructions, AAM, AAD which will output the byte only if it's not 0xa (base 10)
	OT_IMM_AADM,

	// Read a signed extended byte(8 bits) immediate
	OT_SEIMM8,

	// Use a 8bit register
	OT_REG8,
	// Use a 16bit register
	OT_REG16,
	// Use a 16/32/64bit register
	OT_REG_FULL,
	// Use a 32bit register
	OT_REG32,
	// MOVSXD uses 64 bits register.
	OT_REG64,
	// If used with REX the reg size becomes 64 bits, else 32 bits.
	OT_REG32_64,
	// Extract a 32bit register from the RM field, used for instructions with register operands only
	OT_REG32_RM,
	// Used only by MOV CR/DR(n). In 64 bits decoding mode the reg size is 64 bits by default.
	OT_REG32_64_RM,

	// Use or read (indirection) a 8bit register or immediate byte
	OT_RM8,
	// Some instructions force 16 bits (mov sreg, rm16)
	OT_RM16,
	// Use or read a 16/32/64bit register or immediate word/dword/qword
	OT_RM_FULL,
	// Use or read a 32bit register or immediate dword
	OT_RM32,
	// 32 or 64 bits (with REX) operand size indirection memory operand.
	OT_RM32_64,
	// Same as OT_RMXX but POINTS to 16 bits [cannot use GENERAL-PURPOSE REG!]
	OT_FPUM16,
	// Same as OT_RMXX but POINTS to 32 bits (single precision) [cannot use GENERAL-PURPOSE REG!]
	OT_FPUM32,
	// Same as OT_RMXX but POINTS to 64 bits (double precision) [cannot use GENERAL-PURPOSE REG!]
	OT_FPUM64,
	// Same as OT_RMXX but POINTS to 80 bits (extended precision) [cannot use GENERAL-PURPOSE REG!]
	OT_FPUM80,

	// Special ModR/M for SMSW and PINSRW, which need a 16 bits memory operand or 32 bits register
	// In 16 bits decoding mode R32 becomes R16, operand size cannot affect this
	OT_R32M16,

	// Special operand type for MOV reg16/32/64/mem16, segReg 8C /r.
	// It supports all decoding modes, but if used as a memory indirection it's a 16 bit ModR/M indirection.
	OT_RFULL_M16,

	// Use a control register
	OT_CREG,
	// Use a debug register
	OT_DREG,
	// Use a segment register
	OT_SREG,
	
	// Use AL
	OT_ACC8,
	// Use AX/EAX
	OT_ACC_FULL,
	// Use AX/EAX, no REX is possible for RAX, used only with IN/OUT which don't support 64 bit registers.
	OT_ACC_FULL_NOT64,

	// Read two words(16 bits), usually indirection of SEG:OFF, JMP [1234:1234]
	OT_MEM1616,
	// Read one word(16 bits) and a double-word(32 bits), indirection
	OT_MEM1632,
	// Read two words(16 bits), usually SEG:OFF, JMP 1234:1234
	OT_PTR1616,

	// Read a byte(8 bits) immediate and calculate it relatively to the current offset of the instruction being decoded
	OT_RELCB,
	// Read a word/dword immediate and calculate it relatively to the current offset of the instruction being decoded
	OT_RELC_FULL,

	// Use general memory indirection, with varying sizes:
	OT_MEM,
	OT_MEM64,
	OT_MEM128,

	// Read an immediate as an absolute address, size is known by instruction, used by MOV (offset) only
	OT_MOFFS,
	// Use an immediate of 1, as for SHR R/M, 1
	OT_CONST1,
	// Use CL, as for SHR R/M, CL
	OT_REGCL,

	// Instruction-Block for one byte long instructions, used by INC/DEC/PUSH/POP/XCHG,
	// REG is extracted from the value of opcode
	// Use a 8bit register
	OT_IB_RB,
	// Use a 32 or 64bit (with REX) register, used by BSWAP.
	OT_IB_R_DW_QW,
	// Use a 16/32/64bit register
	OT_IB_R_FULL,

	// Use [(E)SI] as INDIRECTION, for repeatable instructions
	OT_REGI_ESI,
	// Use [(E)DI] as INDIRECTION, for repeatable instructions
	OT_REGI_EDI,
	// Use [(e)BX + AL] as INDIRECTIOM, used by XLAT only
	OT_REGI_EBXAL,
	// Use DX, as for OUTS DX, BYTE [SI]
	OT_REGDX,

	// FPU registers:
	OT_FPU_SI, // ST(i)
	OT_FPU_SSI, // ST(0), ST(i)
	OT_FPU_SIS, // ST(i), ST(0)

	// MMX registers:
	OT_MM,
	// Extract the MMX register from the RM bits this time (used when the REG bits are used for opcode extension)
	OT_MM_RM,
	// ModR/M points to 32 bits MMX variable
	OT_MM32,
	// ModR/M points to 32 bits MMX variable
	OT_MM64,

	// SSE registers:
	OT_XMM,
	// Extract the SSE register from the RM bits this time (used when the REG bits are used for opcode extension)
	OT_XMM_RM,
	// ModR/M points to 32 bits SSE variable
	OT_XMM32,
	// ModR/M points to 64 bits SSE variable
	OT_XMM64,
	// ModR/M points to 128 bits SSE variable
	OT_XMM128,

	// DUMMY for cases like CALL WORD [BX+DI], we would like to omit this "WORD". It's useless,
	// because the DWORD/WORD/BYTE mechanism is being done automatically, we need some way to disable it in such cases...
	OT_DUMMY
} _OpType;

// Indicates the size of basic opcode.
typedef enum {
	OCST_1BYTE = 0, // Single byte opcode.
	OCST_13BYTES, // Single byte + reg bits in ModR/M byte opcode.
	OCST_1dBYTES,
	OCST_2BYTES, // 2 bytes opcode.
	OCST_23BYTES, // 2 bytes + reg bits in ModR/M byte opcode.
	OCST_2dBYTES,
	OCST_3BYTES, // 3 bytes. Only for FPU as for now.
	OCST_33BYTES // 3 bytes + reg bits. Only for SSE2 as for now.
} _OpcodeSize;

// Flags for instruction:

// Empty flags indicator:
#define INST_FLAGS_NONE ((_iflags)-1)

// Explicitly define that the instruction doesn't require a ModRM byte.
// NOTE its value is 0! you can't do much with it, it is used for instructions that for sure don't use the ModR/M byte.
#define INST_EXCLUDE_MODRM (0)
// The instruction we are going to decode has a ModR/M byte.
#define INST_INCLUDE_MODRM (1)
// Special treatment for instructions which are in the divided-category but still needs the whole byte for ModR/M...
#define INST_NOT_DIVIDED (1 << 1)
// Used explicitly in repeatable instructions,
// which needs a suffix letter in their mnemonic to specify operation-size (depend on operands).
#define INST_16BITS (1 << 2)
// If the opcode is supported by 80286 and upper models (16/32 bits).
#define INST_32BITS (1 << 3)
// Prefix flags (4 types: lock/rep, seg override, addr-size, oper-size)
// There are several specific instructions that can follow LOCK prefix,
// note that they must be using a memory operand form, otherwise they generate an exception.
#define INST_PRE_LOCK (1 << 4)
// REPNZ prefix for string instructions only - means an instruction can follow it.
#define INST_PRE_REPNZ (1 << 5)
// REP prefix for string instructions only - means an instruction can follow it.
#define INST_PRE_REP (1 << 6)
// CS override prefix.
#define INST_PRE_CS (1 << 7)
// SS override prefix.
#define INST_PRE_SS (1 << 8)
// DS override prefix.
#define INST_PRE_DS (1 << 9)
// ES override prefix.
#define INST_PRE_ES (1 << 10)
// FS override prefix. Funky Segment :)
#define INST_PRE_FS (1 << 11)
// GS override prefix. Groovy Segment, of course not, duh !
#define INST_PRE_GS (1 << 12)
// Switch operand size from 32 to 16 and vice versa.
#define INST_PRE_OP_SIZE (1 << 13)
// Switch address size from 32 to 16 and vice versa.
#define INST_PRE_ADDR_SIZE (1 << 14)
// Native instructions which needs suffix letter to indicate their operation-size (and don't depend on operands).
#define INST_NATIVE (1 << 15)
// Use extended mnemonic, means it's an _InstInfoEx structure, which contains another mnemonic for 32 bits specifically.
#define INST_USE_EXMNEMONIC (1 << 16)
// Use third operand, means it's an _InstInfoOp structure, which contains another operand for special instructions.
#define INST_USE_OP3 (1 << 17)
// The instruction's mnemonic depends on the mod value of the ModR/M byte (mod=11, mod!=11).
#define INST_MODRM_BASED (1 << 18)
// The instruction uses a ModR/M byte which the MOD must be 11 (for registers operands only).
#define INST_MODRR (1 << 19)
// The way of 3DNow! instructions are built, we have to handle their locating specially. Suffix imm8 tells which instruction it is.
#define INST_3DNOW_FETCH (1 << 20)
// Indicates the instruction belongs to the MMX set.
//#define INST_MMX (1 << 21)
// Indicates the instruction belongs to the SSE set.
//#define INST_SSE (1 << 22)
// Indicates the instruction belongs to the SSE2 set.
//#define INST_SSE2 (1 << 23)
// Indicates the instruction belongs to the SSE3 set.
//#define INST_SSE3 (1 << 24)
// Indicates the instruction belongs to the 3DNow! set.
#define INST_3DNOW (1 << 25)
// The instruction needs two suffixes, one for the comparison type (imm8) and the second for its operation size indication (second mnemonic).
#define INST_PSEUDO_OPCODE (1 << 26)
// Invalid instruction at 64 bits decoding mode.
#define INST_INVALID_64BITS (1 << 27)
// Specific instruction for 64 bits.
#define INST_64BITS (1 << 28)
// Indicates the instruction is REX prefixed.
#define INST_PRE_REX (1 << 29)
// Third mnemonic is set.
#define INST_USE_EXMNEMONIC2 (1 << 24)
// Instruction is only valid in 64 bits decoding mode.
#define INST_64BITS_FETCH (1 << 23)

#define INST_PRE_REPS (INST_PRE_REPNZ | INST_PRE_REP)
#define INST_PRE_LOKREP_MASK (INST_PRE_LOCK | INST_PRE_REPNZ | INST_PRE_REP)
#define INST_PRE_SEGOVRD_MASK (INST_PRE_CS | INST_PRE_SS | INST_PRE_DS | INST_PRE_ES | INST_PRE_FS | INST_PRE_GS)

// Indicates which operand is being decoded.
// Destination (1st), Source (2nd), op3 (3rd).
// Its main purpose to help the decode-operands function know whether its the first operand (+ it's indirection + there's a lock prefix).
typedef enum {ONT_NONE = -1, ONT_1, ONT_2, ONT_3} _OperandNumberType;

#define MAX_MNEMONIC_LENGTH (32)

#ifdef _MSC_VER
 #pragma pack(push, 1)
#endif

// Info about the instruction, source/dest types, its name in text and flags.
// This structure is used to for the instructions DB and NOT for the decoded code!
// This is the BASE structure, there are extentions to this structure below.
typedef struct _PACKED_ {
	unsigned char s, d; // OpType
	char* mnemonic;
	_iflags flags;
} _InstInfo;

// There are merely few instructions which need a second mnemonic for 32 bits.
// A flag will indicate it uses another mnemonic.
// Yep, it seems like C++ could do...what the heck.
typedef struct _PACKED_ {
	unsigned char s, d; // OpType
	char* mnemonic;
	_iflags flags;
	char* mnemonic2;
	char* mnemonic3;
} _InstInfoEx;

// There are a few instructions (SHLD/SHRD/IMUL) which use third operand.
// A flag will indicate it uses a third operand.
typedef struct _PACKED_ {
	unsigned char s, d; // OpType
	char* mnemonic;
	_iflags flags;
	unsigned char op3; // OpType
} _InstInfoOp;

// Trie data structure node type:
typedef enum {
	INT_NOTEXISTS = -1, // Not exists (this is used for a return code only).
	INT_NONE, // No instruction info or list set.
	INT_INFO, // It's an instruction info.
	INT_LIST_GROUP,
	INT_LIST_FULL,
	INT_LIST_DIVIDED
} _InstNodeType;
// A node in the instructions DB;
// Can be both a node or an info, depends on type.
// I use union to decrease the node size, in any case it can't have both a list pointer and inst-info pointer.

typedef struct _PACKED_ InstNode{
	unsigned char type;
	union {
		_InstInfo* ii;
		struct InstNode* list;
	};
} _InstNode;

#ifdef _MSC_VER
 #pragma pack(pop)
#endif

// Used for letting the extract operand know the type of operands without knowing the
// instruction itself yet, because of the way those instructions work.
extern _InstInfo II_3dnow;

/*
When you add an instruction to the DB you have to specify its operands and its length.
Because instructions could be 1 or 2 bytes + using the REG bits to identify, the parameters are:

INDEX - First byte of the instruction.
MNEMONIC - The displayed text for the instruction.
MNEMONIC2 - The displayed text for the instruction (used for 32 bits, sometimes 32 bits instructions has another mnemonic, like IRET and IRETD).
OCS - Tell the DB how many bytes/bits the instructions actually consume.
INDEX2 - Second byte of the instruction.
REGINDEX - The 3 bits of the REG part in the ModR/M byte for this instruction.
d(estination) - The type of the first operand(destination).
s(ource) - The type of the second operand(source).
flags - Specifying what prefixes the instruction support, how it should be decoded(using ModR/M or not), the size of the instruction and etc...
*/

_InstInfo* locate_inst(const unsigned char** code, long* codeLen, _OffsetType* codeOffset, _WString* instructionHex, _PrefixState* ps, _DecodeType dt);
_InstInfo* locate_3dnow_inst(_CodeInfo* ci, _WString* instructionHex);

// Concatenates a text describing the size used for indirections form. (MOV *WORD* [BX], 0x12) when it's not cleared from operands.
void str_indirection_text(_WString* s, _OpType ot, _OpType ot2, _DecodeType dt, _PrefixState* ps);

#endif // ___INSTRUCTIONS_H__
