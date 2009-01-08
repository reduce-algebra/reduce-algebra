/*
operands.c

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#include "diconfig.h"

#include "operands.h"
#include "x86defs.h"

#include <stdlib.h>

/*
 SIB decoding is the most confusing part when decoding IA-32 instructions.
 This explanation should clear up some stuff.

 ! When base == 5, use EBP as the base register !
 if (rm == 4) {
	if mod == 01, decode SIB byte and ALSO read a 8 bits displacement.
	if mod == 10, decode SIB byte and ALSO read a 32 bits displacement.
	if mod == 11 <-- EXCEPTION, this is a general-purpose register and mustn't lead to SIB decoding!
	; So far so good, now the confusing part comes in with mod == 0 and base=5, but no worry.
	if (mod == 00) {
	 decode SIB byte WITHOUT any displacement.
	 EXCEPTION!!! when base == 5, read a 32 bits displacement, but this time DO NOT use (EBP) BASE at all!
	}

	NOTE: base could be specify None (no base register) if base==5 and mod==5, but then you also need DISP32.
 }
*/
int extract_sib(const unsigned char** code, long* codeLen, _OffsetType* codeOffset,
                _WString* instructionHex, _WString* operandText, _OpType type,
                _OpType op2, unsigned char sib, _PrefixState* ps, _DecodeType dt, int mod)
{
	int scale, index, base;

	const unsigned char* code0 = *code;
	_iflags totalPrefixes = ps->totalPrefixes;

	unsigned char rex = 0;

	/*
	SIB bits:
	|7---6-5----3-2---0|
	|SCALE| INDEX| BASE|
	|------------------|
	*/

	scale = (sib >> 6) & 3;
	index = (sib >> 3) & 7;
	base = sib & 7;

	if (ps->isREXPrefixValid) rex = *ps->rexpos;

	// format= <size ptr> seg: [base + index * scale + disp8/32]
	// whereas base/index/scale/disp8/32 are ALL optional by specific rules!

	str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
	str_seg_text(operandText, ps, dt);
	chrcat_WS(operandText, OPEN_CHR);

	if (base != 5) {
		if (rex & PREFIX_REX_B) ps->usedPrefixes |= INST_PRE_REX;
		if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits) str_x86def(operandText, &_BASE64[base + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
		else str_x86def(operandText, &_BASE32[base + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
	} else if (mod != 0) {
		/*
		if base == 5 then you have to decode according to MOD.
		mod(00) - disp32.
		mod(01) - disp8 + rBP
		mod(10) - disp32 + rBP
		mod(11) - not possible, it's a general-purpose register.
		*/
		if (rex & PREFIX_REX_B) ps->usedPrefixes |= INST_PRE_REX;
		if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits) str_x86def(operandText, &_BASE64[5 + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
		else str_x86def(operandText, &_BASE32[5 + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
	}

	// In 64 bits the REX prefix might affect the index of the SIB byte.
	if (rex & PREFIX_REX_X) {
		ps->usedPrefixes |= INST_PRE_REX;
		index += REX_GPR_BASE;
	}
	if (index != 4) { // In 64 bits decoding mode, if index == R12, it's valid!
		// Concat '+' only if we have a base or index.
		if ((mod != 0) || (base != 5)) chrcat_WS(operandText, PLUS_DISP_CHR);
		if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits) str_x86def(operandText, &_INDEX64[index]);
		else str_x86def(operandText, &_INDEX32[index]);
		str_x86def(operandText, &_SCALE32[scale]);
	}

	// Read the displacement if required, according to MOD.
	switch (mod)
	{
		case 0:
			// It might be there's only disp32 left in this case,
			// so we have to check for index existance(!=4), because otherwise we would have a spare '+'.

			// When mod=0 there's no force for disp32, unless base=5.
			if (base == 5) {
				/* disp32 */
				*codeLen -= sizeof(long);
				if (*codeLen < 0) return 0;
				str_hex_sp_dw(instructionHex, *(unsigned long*)code0);

				if (index != 4) {
					// If an index was used make it signed relative address:
					chrcat_WS(operandText, (*(long*)code0 >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
					str_code_hdw(operandText, abs(*(long*)code0));
				} else { // Otherwise it's a disp32 only, so make it absolute.
					str_code_hdw(operandText, *(unsigned long*)code0);
				}

				*code += sizeof(long);
				*codeOffset += sizeof(long);
			}
		break;
		case 1:
			/* disp8 */
			*codeLen -= sizeof(char);
			if (*codeLen < 0) return 0;
			str_hex_sp_b(instructionHex, *code0);

			chrcat_WS(operandText, (*(char*)code0 >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
			str_code_hb(operandText, abs(*(char*)code0));

			*code += sizeof(char);
			*codeOffset += sizeof(char);
		break;
		case 2:
			/* disp32 */
			*codeLen -= sizeof(long);
			if (*codeLen < 0) return 0;
			str_hex_sp_dw(instructionHex, *(unsigned long*)code0);

			// Signed relative address:
			chrcat_WS(operandText, (*(long*)code0 >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
			str_code_hdw(operandText, abs(*(long*)code0));
			//chrcat_WS(operandText, PLUS_DISP_CHR);
			//str_code_hdw(operandText, *(unsigned long*)code0);

			*code += sizeof(long);
			*codeOffset += sizeof(long);
		break;
			// case 3: break; --> It's a general-purpose register. // 3rd time -ice cream?!
	}

	chrcat_WS(operandText, CLOSE_CHR);
	return 1;
}

/*
This seems to be the hardest part in decoding the operands.
If you take a look carefully at Table 2-2. 32-Bit Addressing Forms with the ModR/M Byte,
you will understand it's easy to decode the operands.

First we check the DT, so we can decide according to which Table in the documentation we are supposed to decode.
Then we follow the specific table whether it's 16 bits or 32 bits.

Don't forget that Operand Size AND Address Size prefixes may change the decoding!

Some instructions force the use of RM16, so take it into account.
*/
int extract_modrm(_CodeInfo* ci,
                  _WString* instructionHex, _WString* operandText, _OpType type, _OpType op2,
                  _OperandNumberType opNum, _PrefixState* ps,
                  _DecodeType dt, int* lockableInstruction, int mod, int rm, _iflags instFlags)
{
	unsigned char sib = 0, rex = 0;

	const unsigned char* code = ci->code;
	long codeLen = ci->codeLen;
	_OffsetType codeOffset = ci->codeOffset;

	_iflags totalPrefixes = ps->totalPrefixes;

	if (ps->isREXPrefixValid) rex = *ps->rexpos;

	if (mod == 3)	{ // General-purpose register is handled the same way in 16/32/64 bits decoding modes.
		switch(type)
		{
			case OT_RFULL_M16:
			case OT_RM_FULL:
				switch (OP_SIZE_AFFECT(dt, totalPrefixes, rex))
				{
					case Decode16Bits:
						ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
						if (rex & PREFIX_REX_B) {
							ps->usedPrefixes |= INST_PRE_REX;
							rm += REX_GPR_BASE;
						}
						str_x86def(operandText, &_REGS16[rm]);
					break;
					case Decode32Bits:
						ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
						if (rex & PREFIX_REX_B) {
							ps->usedPrefixes |= INST_PRE_REX;
							rm += REX_GPR_BASE;
						}
						// CALL NEAR defaults to 64 bits. --> INST_64BITS
						if ((dt == Decode64Bits) && ((instFlags & INST_64BITS) == INST_64BITS)) {
							str_x86def(operandText, &_REGS64[rm]);
						} else str_x86def(operandText, &_REGS32[rm]);
					break;
					case Decode64Bits:
						// CALL NEAR defaults to 64 bits. --> INST_64BITS, REX isn't required, thus ignored anyways.
						if ((instFlags & INST_64BITS) != INST_64BITS) ps->usedPrefixes |= INST_PRE_REX;
						str_x86def(operandText, &_REGS64[rm + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
					break;
				}
			break;
			case OT_RM32:
				if (rex & PREFIX_REX_B) {
					ps->usedPrefixes |= INST_PRE_REX;
					rm += REX_GPR_BASE;
				}
				str_x86def(operandText, &_REGS32[rm]);
			break;
			case OT_RM32_64: // Take care specifically in MOVNTI/MOVD/CVT's instructions, making it _REG64 with REX.
				if (rex & PREFIX_REX_B) {
					ps->usedPrefixes |= INST_PRE_REX;
					rm += REX_GPR_BASE;
				}
				if (rex & PREFIX_REX_W) {
					ps->usedPrefixes |= INST_PRE_REX;
					str_x86def(operandText, &_REGS64[rm]);
				} else str_x86def(operandText, &_REGS32[rm]);
			break;
			case OT_RM16:
				if (rex & PREFIX_REX_B) {
					ps->usedPrefixes |= INST_PRE_REX;
					rm += REX_GPR_BASE;
				}
				str_x86def(operandText, &_REGS16[rm]);
			break;
			case OT_RM8:
				if (ps->isREXPrefixValid) {
					ps->usedPrefixes |= INST_PRE_REX;
					str_x86def(operandText, &_REGS8_REX[rm + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
				} else str_x86def(operandText, &_REGS8[rm]);
			break;
			case OT_MM32:
			case OT_MM64:
				// MMX doesn't support extended registers.
				str_x86def(operandText, &_REGSMMX[rm]);
			break;
			case OT_XMM32:
			case OT_XMM64:
			case OT_XMM128:
				if (rex & PREFIX_REX_B) {
					ps->usedPrefixes |= INST_PRE_REX;
					rm += REX_GPR_BASE;
				}
				str_x86def(operandText, &_REGSSSE[rm]);
			break;
			case OT_R32M16:
				if (rex & PREFIX_REX_B) {
					ps->usedPrefixes |= INST_PRE_REX;
					rm += REX_GPR_BASE;
				}
				if (dt == Decode16Bits) str_x86def(operandText, &_REGS16[rm]);
				else str_x86def(operandText, &_REGS32[rm]);
			break;
                        default:
                        break;
		}
	}

	if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode16Bits) {
		// Decoding according to Table 2-1. (16 bits)
		switch (mod)
		{
			case 0x00: // Indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				if (rm == 6) {
					// 6 is a special case - only 16 bits displacement.
					codeLen -= sizeof(short);
					if (codeLen < 0) return 0;
					str_hex_sp_w(instructionHex, *(unsigned short*)code);

					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					chrcat_WS(operandText, OPEN_CHR);
					str_code_hw(operandText, *(unsigned short*)code);
					chrcat_WS(operandText, CLOSE_CHR);

					code += sizeof(short);
					codeOffset += sizeof(short);
				} else {
					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					str_x86def(operandText, &_MODS16[rm]);
					chrcat_WS(operandText, CLOSE_CHR);
				}
			break;
			case 0x01: // 8 bits displacement + indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				codeLen -= sizeof(char);
				if (codeLen < 0) return 0;
				str_hex_sp_b(instructionHex, *code);

				str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
				str_seg_text(operandText, ps, dt);
				str_x86def(operandText, &_MODS16[rm]);
				
				chrcat_WS(operandText, (*(char*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
				str_code_hb(operandText, abs(*(char*)code));
				chrcat_WS(operandText, CLOSE_CHR);

				code += sizeof(char);
				codeOffset += sizeof(char);
			break;
			case 0x02: // 16 bits displacement + indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				codeLen -= sizeof(short);
				if (codeLen < 0) return 0;
				str_hex_sp_w(instructionHex, *(unsigned short*)code);

				str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
				str_seg_text(operandText, ps, dt);
				str_x86def(operandText, &_MODS16[rm]);
				// Signed relative address:
				chrcat_WS(operandText, (*(short*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
				str_code_hw(operandText, abs(*(short*)code));
				chrcat_WS(operandText, CLOSE_CHR);

				code += sizeof(short);
				codeOffset += sizeof(short);
			break;
		}
	} else { /* Decode32Bits or Decode64Bits! */
		// Remember that from 32/64 bits ModR/M byte a SIB byte could follow!
		// Decodes 64 bits now as well.
		switch (mod)
		{
			case 0x00: // Indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				if (rm == 4) {
					// 4 is a special case - SIB byte follows!

					// Skip SIB byte.
					if (--codeLen < 0) return 0;
					sib = *code;
					str_hex_b(instructionHex, sib);

					code += sizeof(char);
					codeOffset += sizeof(char);
					if (!extract_sib(&code, &codeLen, &codeOffset, instructionHex, operandText, type, op2, sib, ps, dt, mod)) return 0;
				} else if (rm == 5) {
					ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
					// 5 is a special case - only 32 bits displacement.
					codeLen -= sizeof(long);
					if (codeLen < 0) return 0;
					str_hex_sp_dw(instructionHex, *(unsigned long*)code);

					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					chrcat_WS(operandText, OPEN_CHR);
					if (dt == Decode64Bits) {
						// In 64 bits decoding mode depsite of the address size, a RIP-relative address it is.
						strcat_WSN(operandText, REG_RIP_TEXT);
						// Make it a signed relative address:
						chrcat_WS(operandText, (*(long*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
						str_code_hdw(operandText, abs(*(long*)code));
					} else {
						// Absolute address:
						str_code_hdw(operandText, *(unsigned long*)code);
					}
					chrcat_WS(operandText, CLOSE_CHR);

					code += sizeof(long);
					codeOffset += sizeof(long);
				} else {
					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					if (rex & PREFIX_REX_B) {
						ps->usedPrefixes |= INST_PRE_REX;
						rm += REX_GPR_BASE;
					}
					if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits) str_x86def(operandText, &_MODS64[rm]);
					else str_x86def(operandText, &_MODS32[rm]);
					chrcat_WS(operandText, CLOSE_CHR);
				}
			break;
			case 0x01: // 8 bits displacement + indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				if (rm == 4) {
					// 4 is a special case - SIB byte + disp8 follows!

					// Skip SIB byte.
					if (--codeLen < 0) return 0;
					sib = *code;
					str_hex_b(instructionHex, sib);

					code += sizeof(char);
					codeOffset += sizeof(char);
					if (!extract_sib(&code, &codeLen, &codeOffset, instructionHex, operandText, type, op2, sib, ps, dt, mod)) return 0;
				} else {
					codeLen -= sizeof(char);
					if (codeLen < 0) return 0;
					str_hex_sp_b(instructionHex, *code);

					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					if (rex & PREFIX_REX_B) {
						ps->usedPrefixes |= INST_PRE_REX;
						rm += REX_GPR_BASE;
					}
					if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits) str_x86def(operandText, &_MODS64[rm]);
					else str_x86def(operandText, &_MODS32[rm]);
					chrcat_WS(operandText, (*(char*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
					str_code_hb(operandText, abs(*(char*)code));
					chrcat_WS(operandText, CLOSE_CHR);

					code += sizeof(char);
					codeOffset += sizeof(char);
				}
			break;
			case 0x02: // 32 bits displacement + indirection
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);
				if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

				if (rm == 4) {
					// 4 is a special case - SIB byte + disp32 follows!

					// Skip SIB byte.
					if (--codeLen < 0) return 0;
					sib = *code;
					str_hex_b(instructionHex, sib);

					code += sizeof(char);
					codeOffset += sizeof(char);
					if (!extract_sib(&code, &codeLen, &codeOffset, instructionHex, operandText, type, op2, sib, ps, dt, mod)) return 0;
				} else {
					codeLen -= sizeof(long);
					if (codeLen < 0) return 0;
					str_hex_sp_dw(instructionHex, *(unsigned long*)code);

					str_indirection_text(operandText, type, op2, OP_SIZE_AFFECT(dt, totalPrefixes, rex), ps);
					str_seg_text(operandText, ps, dt);
					if (rex & PREFIX_REX_B) {
						ps->usedPrefixes |= INST_PRE_REX;
						rm += REX_GPR_BASE;
					}
					if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode64Bits)str_x86def(operandText, &_MODS64[rm]);
					else str_x86def(operandText, &_MODS32[rm]);
					// Signed relative address:
					chrcat_WS(operandText, (*(long*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
					str_code_hdw(operandText, abs(*(long*)code));
					chrcat_WS(operandText, CLOSE_CHR);

					code += sizeof(long);
					codeOffset += sizeof(long);
				}
			break;
		}
	}

	// It's ok if we don't update the pointers parameters when we will return 0, because
	// they are to be ignored anyways.
	ci->code = code;
	ci->codeLen = codeLen;
	ci->codeOffset = codeOffset;

	return 1;
}


/*

This function is reponsible to textually format a required operand according to its type.
It is vital to understand that there are other operands than what the ModR/M byte specifies.

Only by decoding the operands of an instruction which got a LOCK prefix, we could tell whether it may use the LOCK prefix.
According to Intel, LOCK prefix must precede some specific instructions AND in their memory destination operand form (which means first operand).
LOCK INC EAX, would generate an exception, but LOCK INC [EAX] is alright.
Also LOCK ADD BX, [BP] would generate an exception.

Return code:
EO_CONTINUE - continue parsing the instruction and its operands, all was right till now.
EO_HALT - not enough bytes, or invalid operands.
EO_SUFFIX - explicit operands instructions (such as: xlat, movs, scas etc...) should be outputed by their implicit form (AKA LODSB, XLATB, and not XLAT BYTE [BX+AL])...
*/

_ExOpRCType extract_operand(_CodeInfo* ci,
                            _WString* instructionHex, _WString* operandText, _OpType type, _OpType op2,
                            _OperandNumberType opNum, _iflags instFlags, unsigned char modrm,
                            _PrefixState* ps, _DecodeType dt, int* lockableInstruction)
{
	int mod = 0, reg = 0, rm = 0;

	_iflags tmpPrefixes = 0;
	_iflags totalPrefixes = ps->totalPrefixes;

	const unsigned char* code = ci->code;
	long codeLen = ci->codeLen;
	_OffsetType codeOffset = ci->codeOffset;

	long joff = 0;
	_OffsetType reloff = 0;

	unsigned char rex = 0;

	*lockableInstruction = 0;

	/*
	ModRM bits:
	|7-6-5--------3-2-0|
	|MOD|REG/OPCODE|RM |
	|------------------|
	*/
	mod = (modrm >> 6) & 3; // Mode(register-indirection, disp8+reg+indirection, disp16+reg+indirection, general-purpose register)
	reg = (modrm >> 3) & 7; // Register(could be part of the opcode itself or general-purpose register)
	rm = modrm & 7; // Specifies which general-purpose register or disp+reg to use.

	/*
	In 64 bits, we have to take care for REX prefix, thus we have to extend the ModR/M and SIB values.
	REX.R 3rd bit, extends REG, only GPR, XMM, Control or Debug.
	REX.B 1st bit, extends 
	*/

	if (ps->isREXPrefixValid) rex = *ps->rexpos;

	switch (type)
	{
		case OT_IMM8:
			codeLen -= sizeof(char);
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_b(instructionHex, *code);

			str_code_hb(operandText, *code);
			code += sizeof(char);
			codeOffset += sizeof(char);
		break;
		case OT_IMM_FULL: // 16, 32 or 64, depends on prefixes.
			if (OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode16Bits) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
				// FALL THROUGH
		case OT_IMM16: // Force 16 bits imm.
			codeLen -= sizeof(short);
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_w(instructionHex, *(unsigned short*)code);

			str_code_hw(operandText, *(unsigned short*)code);
			code += sizeof(short);
			codeOffset += sizeof(short);
		break;
			// Extension: MOV imm64?, requires REX.
			} else if ((dt == Decode64Bits) && ((instFlags & (INST_64BITS | INST_PRE_REX)) == (INST_64BITS | INST_PRE_REX)) && (rex & PREFIX_REX_W)) {
				ps->usedPrefixes |= INST_PRE_REX;

				codeLen -= sizeof(long)*2;
				if (codeLen < 0) return EO_HALT;
				str_hex_sp_qw(instructionHex, (unsigned char*)code);

				str_code_hqw(operandText, (unsigned char*)code);
				code += sizeof(long)*2;
				codeOffset += sizeof(long)*2;
				break;
			} else if (dt == Decode32Bits) ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
			/* FALL THROUGH CUZ dt==Decoded32Bits @-<----*/
		case OT_IMM32:
			codeLen -= sizeof(long);
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_dw(instructionHex, *(unsigned long*)code);

			str_code_hdw(operandText, *(unsigned long*)code);
			code += sizeof(long);
			codeOffset += sizeof(long);
		break;
		case OT_IMM_AADM: // Special case for AAD & AAM, will output value only if not 0xa (default Decimal Base).
			codeLen -= sizeof(char);
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_b(instructionHex, *code);

			if (*code != 0xa) str_code_hb(operandText, *code);
			code += sizeof(char);
			codeOffset += sizeof(char);
		break;
		case OT_SEIMM8: // Sign extended immediate.
			codeLen -= sizeof(char);
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_b(instructionHex, *code);

			chrcat_WS(operandText, (*(char*)code >= 0) ? PLUS_DISP_CHR : MINUS_DISP_CHR);
			str_code_hb(operandText, abs(*(char*)code));
			code += sizeof(char);
			codeOffset += sizeof(char);
		break;
		case OT_REG8:
			if (ps->isREXPrefixValid) {
				// If REX prefix is valid then we will have to use low bytes.
				// This is a PASSIVE behaviour changer of REX prefix, it affects operands even if its value is 0x40 !
				ps->usedPrefixes |= INST_PRE_REX;
				str_x86def(operandText, &_REGS8_REX[reg + ((rex & PREFIX_REX_R) == PREFIX_REX_R ? REX_GPR_BASE : 0)]);
			} else str_x86def(operandText, &_REGS8[reg]);
		break;
		case OT_REG16:
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGS16[reg]);
		break;
		case OT_REG_FULL:
			switch (OP_SIZE_AFFECT(dt, totalPrefixes, rex))
			{
				case Decode16Bits:
					ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
					if (rex & PREFIX_REX_R) {
						ps->usedPrefixes |= INST_PRE_REX;
						reg += REX_GPR_BASE;
					}
					str_x86def(operandText, &_REGS16[reg]);
				break;
				case Decode32Bits:
					if (rex & PREFIX_REX_R) {
						ps->usedPrefixes |= INST_PRE_REX;
						reg += REX_GPR_BASE;
					} else ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
					str_x86def(operandText, &_REGS32[reg]);
				break;
				case Decode64Bits: // REX must be presented.
					ps->usedPrefixes |= INST_PRE_REX;
					str_x86def(operandText, &_REGS64[reg + ((rex & PREFIX_REX_R) == PREFIX_REX_R ? REX_GPR_BASE : 0)]);
				break;
			}
		break;
		case OT_REG32:
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGS32[reg]);
		break;
		case OT_REG32_64: // Handle CVT's, MOVxX and MOVNTI instructions which could be extended to 64 bits registers with REX.
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			}
			if (rex & PREFIX_REX_W) {
				ps->usedPrefixes |= INST_PRE_REX;
				str_x86def(operandText, &_REGS64[reg]);
			} else str_x86def(operandText, &_REGS32[reg]);
		break;
		case OT_REG64: // MOVSXD uses 64 bits register.
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGS32[reg]);
		break;
		case OT_REG32_RM: // R32, this time from the RM field
			if (rex & PREFIX_REX_B) {
				ps->usedPrefixes |= INST_PRE_REX;
				rm += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGS32[rm]);
		break;
		case OT_REG32_64_RM: // MOV CR(n)/DR(n) defaults of 64 bits operand size in 64 bits.
			if (rex & PREFIX_REX_B) {
				ps->usedPrefixes |= INST_PRE_REX;
				rm += REX_GPR_BASE;
			}
			if (dt == Decode64Bits) str_x86def(operandText, &_REGS64[rm]);
			else str_x86def(operandText, &_REGS32[rm]);
		break;
		case OT_MM: // MMX register
			str_x86def(operandText, &_REGSMMX[reg]);
		break;
		case OT_MM_RM: // MMX register, this time from the RM field
			str_x86def(operandText, &_REGSMMX[rm]);
		break;
		case OT_XMM: // SSE register
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGSSSE[reg]);
		break;
		case OT_XMM_RM: // SSE register, thie time from the RM field
			if (rex & PREFIX_REX_B) {
				ps->usedPrefixes |= INST_PRE_REX;
				rm += REX_GPR_BASE;
			}
			str_x86def(operandText, &_REGSSSE[rm]);
		break;
		case OT_MEM:
			// Make a specific check when the type is OT_MEM since the lockable CMPXCHG8B uses this one...
			if ((opNum == ONT_1) && (totalPrefixes & INST_PRE_LOCK)) *lockableInstruction = 1;

			/* FALL THROUGH keep parsing @-<----*/
		case OT_MEM64:
		case OT_MEM128:

		case OT_MEM1616:
		case OT_MEM1632:
		case OT_FPUM16:
		case OT_FPUM32:
		case OT_FPUM64:
		case OT_FPUM80:
			// Can't be a general-purpose register!
			if (mod == 0x3) {
				*lockableInstruction = 0;
				return EO_HALT;
			}
		case OT_RM8:
		case OT_RM16:
		case OT_RM_FULL:
		case OT_RM32:
		case OT_RM32_64:
		case OT_R32M16:
		case OT_RFULL_M16:
		case OT_MM32:
		case OT_MM64:
		case OT_XMM32:
		case OT_XMM64:
		case OT_XMM128:

			// --------------- MODR/M BYTE DECODING --------------------
			ci->code = code;
			ci->codeLen = codeLen;
			ci->codeOffset = codeOffset;
			if (!extract_modrm(ci, instructionHex,
				operandText, type, op2, opNum,
				ps, dt, lockableInstruction, mod, rm, instFlags)) return EO_HALT;
		return EO_CONTINUE;
		case OT_CREG:
			/*
			Don't parse if the reg exceeds the bounds of the array.
			Most of the CR's are not implemented, so if there's no matching string, the operand is invalid.
			*/
			if (rex & PREFIX_REX_R) {
				ps->usedPrefixes |= INST_PRE_REX;
				reg += REX_GPR_BASE;
			} else if ((dt == Decode32Bits) && (ps->totalPrefixes & INST_PRE_LOCK)) {
				// NOTE: In 32 bits decoding mode,
				// if the lock prefix is set before MOV CR(n) it will become the 4th bit of the REG field like REX.R in 64 bits.
				reg += REX_GPR_BASE;
				ps->usedPrefixes |= INST_PRE_LOCK;
			}
			if (reg >= CREGS_MAX) return EO_HALT;
			if (_CREGS[reg].size == 0) return EO_HALT;
			str_x86def(operandText, &_CREGS[reg]);
		break;
		case OT_DREG:
			// In 64 bits there are 16 debug registers, but dr8-15 aren't implemented anyways, thus they are ignored.
			if ((reg == 4) || (reg == 5)) return EO_HALT;
			str_x86def(operandText, &_DREGS[reg]);
		break;
		case OT_SREG: // Works with REG16 only!
			if ((opNum == ONT_1) && (reg == 1)) return EO_HALT; // Can't MOV CS, <REG>.
			// Don't parse if the reg exceeds the bounds of the array.
			if (reg <= SEG_REGS_MAX-1) str_x86def(operandText, &_SREGS[reg]);
			else return EO_HALT;
		break;
		case OT_ACC8:
			str_x86def(operandText, &_REGS8[0]);
		break;
		case OT_ACC_FULL_NOT64: // No REX.W support for IN/OUT.
			rex &= ~PREFIX_REX_W;
		case OT_ACC_FULL:
			if (OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode16Bits) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
				str_x86def(operandText, &_REGS16[0]);
			} else if ((OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode32Bits) && !((instFlags & INST_64BITS) && (dt == Decode64Bits))) { // Handle Mov-offset specially.
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
				str_x86def(operandText, &_REGS32[0]);
			} else { /* Decode64Bits */
				// Only non-promoted instructions need REX in order to decode in 64 bits.
				if ((instFlags & INST_64BITS) == 0) ps->usedPrefixes |= INST_PRE_REX; // Mov-offset default operand size in 64 bits is 64 bits.
				str_x86def(operandText, &_REGS64[0]);
			}
		break;
		case OT_PTR1616:
			codeLen -= sizeof(short)*2;
			if (codeLen < 0) return EO_HALT;
			str_hex_sp_w(instructionHex, *(unsigned short*)code);
			str_hex_sp_w(instructionHex, *(unsigned short*)(code+sizeof(short)));

			str_code_hw(operandText, *(unsigned short*)(code+sizeof(short)));
			chrcat_WS(operandText, SEG_OFF_CHR);
			str_code_hw(operandText, *(unsigned short*)code);

			code += sizeof(short)*2;
			codeOffset += sizeof(short)*2;
		break;
		case OT_RELCB:
			codeLen -= sizeof(char);
			if (codeLen < 0) return EO_HALT;
			joff = *(char*)code;
			str_hex_sp_b(instructionHex, (unsigned char)joff);

			//strcat_WSN(operandText, OFFSET_SHORT);

			// Just make sure the offset is output correctly.
			reloff = ((joff < 0) ? (codeOffset - abs(joff) + 1) : (codeOffset + joff + 1));
#ifdef SUPPORT_64BIT_OFFSET
			str_code_hqw(operandText, (unsigned char*)&reloff);
#else
			str_code_hdw(operandText, (_OffsetType)reloff);
#endif

			code += sizeof(char);
			codeOffset += sizeof(char);
		break;
		case OT_RELC_FULL:
			// Yep, operand size prefix affects relc also.
			if (OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode16Bits) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);

				codeLen -= sizeof(short);
				if (codeLen < 0) return EO_HALT;
				joff = *(short*)code;
				str_hex_sp_w(instructionHex, (unsigned short)joff);

				if (totalPrefixes & INST_PRE_OP_SIZE) strcat_WSN(operandText, OFFSET_SMALL);
				reloff = ((joff < 0) ? (codeOffset - abs(joff) + 2) : (codeOffset + joff + 2));

				str_code_hw(operandText, (unsigned short)((joff < 0) ? (codeOffset - abs(joff) + 2) : (codeOffset + joff + 2)));

				code += sizeof(short);
				codeOffset += sizeof(short);
			} else { /* Decode32Bits or Decode64Bits = for now they are the same */
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);

				codeLen -= sizeof(long);
				if (codeLen < 0) return EO_HALT;
				joff = *(long*)code;
				str_hex_sp_dw(instructionHex, *(unsigned long*)code);

				if (totalPrefixes & INST_PRE_OP_SIZE) strcat_WSN(operandText, OFFSET_LARGE);

				reloff = ((joff < 0) ? (codeOffset - abs(joff) + 4) : (codeOffset + joff + 4));
#ifdef SUPPORT_64BIT_OFFSET
				str_code_hqw(operandText, (unsigned char*)&reloff);
#else
				str_code_hdw(operandText, (_OffsetType)reloff);
#endif

				// We add 4 to the new offset because, when you make the branch the processor's IP points to the next instruction, which
				// in 32 bits should be $+5, AKA current IP + 5.
				// So it comes out we added 1 to to codeOffset for the jmp/call instruction itself we add 4 and not 5.
				code += sizeof(long);
				codeOffset += sizeof(long);
			}
		break;
		case OT_MOFFS:
			// Just a pointer to a BYTE, WORD, DWORD, QWORD. Works only with ACC8/16/32/64 respectively. 
			// MOV [0x1234], AL ; MOV AX, [0x1234] ; MOV EAX, [0x1234], note that R/E/AX will be chosen by OT_ACC_FULL.
			if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode16Bits) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);

				codeLen -= sizeof(short);
				if (codeLen < 0) return EO_HALT;
				str_hex_sp_w(instructionHex, *(unsigned short*)code);

				str_seg_text(operandText, ps, dt);
				chrcat_WS(operandText, OPEN_CHR);
				str_code_hw(operandText, *(unsigned short*)code);
				chrcat_WS(operandText, CLOSE_CHR);

				code += sizeof(short);
				codeOffset += sizeof(short);
			} else if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode32Bits) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);

				codeLen -= sizeof(long);
				if (codeLen < 0) return EO_HALT;
				str_hex_sp_dw(instructionHex, *(unsigned long*)code);

				str_seg_text(operandText, ps, dt);
				chrcat_WS(operandText, OPEN_CHR);
				str_code_hdw(operandText, *(unsigned long*)code);
				chrcat_WS(operandText, CLOSE_CHR);

				code += sizeof(long);
				codeOffset += sizeof(long);
			} else { /* Decode64Bits */
				codeLen -= sizeof(long)*2;
				if (codeLen < 0) return EO_HALT;
				str_hex_sp_qw(instructionHex, (unsigned char*)code);

				str_seg_text(operandText, ps, dt);
				chrcat_WS(operandText, OPEN_CHR);
				str_code_hqw(operandText, (unsigned char*)code);
				chrcat_WS(operandText, CLOSE_CHR);

				code += sizeof(long)*2;
				codeOffset += sizeof(long)*2;
			}
		break;
		case OT_CONST1:
			strcat_WSN(operandText, ONE_CONST_TEXT);
		break;
		case OT_REGCL:
			str_x86def(operandText, &_REGS8[1]);
		break;

		case OT_FPU_SI:
			// Low 3 bits specify the REG, similar to the MODR/M byte reg.
			reg = *(code-1) & 7;
			strcat_WSN(operandText, FPU_STACK_TEXT);
			chrcat_WS(operandText, OPEN_CHR0);
			chrcat_WS(operandText, (char)reg + 0x30);
			chrcat_WS(operandText, CLOSE_CHR0);
		break;
		case OT_FPU_SSI:
			reg = *(code-1) & 7;
			strcat_WSN(operandText, FPU_STACK_TEXT);
			strcat_WSN(operandText, SEP_STR);
			strcat_WSN(operandText, FPU_STACK_TEXT);
			chrcat_WS(operandText, OPEN_CHR0);
			chrcat_WS(operandText, (char)reg + 0x30);
			chrcat_WS(operandText, CLOSE_CHR0);
		break;
		case OT_FPU_SIS:
			reg = *(code-1) & 7;
			strcat_WSN(operandText, FPU_STACK_TEXT);
			chrcat_WS(operandText, OPEN_CHR0);
			chrcat_WS(operandText, (char)reg + 0x30);
			chrcat_WS(operandText, CLOSE_CHR0);
			strcat_WSN(operandText, SEP_STR);
			strcat_WSN(operandText, FPU_STACK_TEXT);
		break;

		/*
			Special treatment for Instructions-Block:
			INC/DEC (only 16/32 bits) /PUSH/POP/XCHG instructions, which get their REG from their own binary code.

			Notice these instructions are 1 or 2 byte long,
			code points after the byte which represents the instruction itself,
			thus, even if the instructions are 2 bytes long it will read its last byte which contains the REG info.
		*/
		case OT_IB_RB:
			// Low 3 bits specify the REG, similar to the MODR/M byte reg.
			reg = *(code-1) & 7;
			if (rex & PREFIX_REX_B) {
				ps->usedPrefixes |= INST_PRE_REX;
				str_x86def(operandText, &_REGS8_REX[reg + REX_GPR_BASE]);
			} else if (ps->isREXPrefixValid) {
				ps->usedPrefixes |= INST_PRE_REX;
				str_x86def(operandText, &_REGS8_REX[reg]);
			} else str_x86def(operandText, &_REGS8[reg]);
		break;
		case OT_IB_R_DW_QW: // BSWAP can't use 16 bits register.
			totalPrefixes &= ~INST_PRE_OP_SIZE;
		case OT_IB_R_FULL:
			reg = *(code-1) & 7;
			switch (OP_SIZE_AFFECT(dt, totalPrefixes, rex))
			{
				case Decode16Bits:
					ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
					if (rex & PREFIX_REX_B) {
						ps->usedPrefixes |= INST_PRE_REX;
						reg += REX_GPR_BASE;
					}
					str_x86def(operandText, &_REGS16[reg]);
				break;
				case Decode32Bits:
					// PUSH/POP defaults to 64 bits. --> INST_64BITS
					// MOV imm64 / BSWAP requires REX.B to be 64 bits --> INST_64BITS | INST_PRE_REX
					if (dt == Decode64Bits) {
						if (((instFlags & (INST_64BITS | INST_PRE_REX)) == (INST_64BITS | INST_PRE_REX)) && (rex & PREFIX_REX_W)) {
							ps->usedPrefixes |= INST_PRE_REX;
							str_x86def(operandText, &_REGS64[reg + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
							break;
						} else if ((instFlags & INST_64BITS) && ((instFlags & INST_PRE_REX) == 0)) {
							if (rex & PREFIX_REX_B) {
								ps->usedPrefixes |= INST_PRE_REX;
								reg += REX_GPR_BASE;
							}
							str_x86def(operandText, &_REGS64[reg]);
							break;
						}
					}
					if (rex & PREFIX_REX_B) {
						ps->usedPrefixes |= INST_PRE_REX;
						str_x86def(operandText, &_REGS32[reg + REX_GPR_BASE]);
					} else {
						ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);
						str_x86def(operandText, &_REGS32[reg]);
					}
				break;
				case Decode64Bits:
					// PUSH/POP can drop unused REX prefix.
					if ((instFlags & INST_64BITS) && ((instFlags & INST_PRE_REX) == 0)) {
						if (rex & PREFIX_REX_B) {
							ps->usedPrefixes |= INST_PRE_REX;
							reg += REX_GPR_BASE;
						}
						str_x86def(operandText, &_REGS64[reg]);
					} else {
						ps->usedPrefixes |= INST_PRE_REX;
						str_x86def(operandText, &_REGS64[reg + ((rex & PREFIX_REX_B) == PREFIX_REX_B ? REX_GPR_BASE : 0)]);
					}
				break;
			}
		break;

		/*
			Special treatment for repeatable instructions.

			We want the following output:
			If there's only the REP/NZ prefix, we won't output anything (All operands are implicit).
			If there's an operand size prefix, we will change the suffix letter of the mnemonic, which specifies the size of operand to the required one.
			If there's a segment override prefix, we will output the segment and the used index register (EDI/ESI).
			If there's an address size prefix, we will output the (segment if needed and) the used and inverted index register (DI/SI).

			Example:
			:: Decoding in 16 bits mode! ::
			AD ~ LODSW
			66 AD ~ LODSD
			F3 AC ~ REP LODSB
			F3 66 AD ~ REP LODSD
			F3 3E AC ~ REP LODS BYTE DS:[SI]
			F3 67 AD ~ REP LODS WORD [ESI]

			The basic form of a repeatable instruction has its operands hidden and has a suffix letter
			which implies on the size of operation being done.
			Therefore, we cannot change the mnemonic here when we encounter another prefix and its not the decoder's responsibility to do so.
			That's why the caller is responsible to add the suffix letter if no other prefixes are used.
			And all we are doing here is formatting the operand correctly.

		*/
		case OT_REGI_ESI:
			tmpPrefixes = totalPrefixes & (INST_PRE_SEGOVRD_MASK | INST_PRE_OP_SIZE | INST_PRE_ADDR_SIZE | INST_PRE_REPS);
			// First, make sure the instruction is repeatable before we make a move.
			if ((instFlags & INST_PRE_REPS) == 0) return EO_SUFFIX;

			ps->usedPrefixes |= (tmpPrefixes & INST_PRE_ADDR_SIZE);

			// This might be a 16, 32 or 64 bits instruction, depends on the decoding mode.
			if (instFlags & INST_16BITS) {
				ps->usedPrefixes |= (totalPrefixes & INST_PRE_OP_SIZE);

				// Explicit operands only when there's a segment override or address size prefix.
				if ((tmpPrefixes & INST_PRE_OP_SIZE) == tmpPrefixes) return EO_SUFFIX;
				if ((tmpPrefixes & (INST_PRE_OP_SIZE | (instFlags & INST_PRE_REPS))) == tmpPrefixes) return EO_SUFFIX;

				if (OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode16Bits) strcat_WSN(operandText, TEXT_16_BITS);
				else if ((OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode64Bits) && (instFlags & INST_64BITS)) {
					ps->usedPrefixes |= INST_PRE_REX;
					strcat_WSN(operandText, TEXT_64_BITS);
				} else strcat_WSN(operandText, TEXT_32_BITS);
			} else {
				// Explicit operands only when there's a segment override or address size prefix.
				// Not all repeatable string instructions support 64 bits (IN/OUT).
				if ((tmpPrefixes & INST_PRE_OP_SIZE) == tmpPrefixes) return EO_SUFFIX;
				if ((tmpPrefixes & (INST_PRE_OP_SIZE | (instFlags & INST_PRE_REPS))) == tmpPrefixes) return EO_SUFFIX;

				strcat_WSN(operandText, TEXT_8_BITS);
			}

			str_seg_text(operandText, ps, dt);
			chrcat_WS(operandText, OPEN_CHR);

			if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode16Bits) str_x86def(operandText, &_REGS16[6]);
			else if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode32Bits) str_x86def(operandText, &_REGS32[6]);
			else str_x86def(operandText, &_REGS64[6]);
			chrcat_WS(operandText, CLOSE_CHR);
		break;
		case OT_REGI_EDI:
			tmpPrefixes = totalPrefixes & (INST_PRE_SEGOVRD_MASK | INST_PRE_OP_SIZE | INST_PRE_ADDR_SIZE | INST_PRE_REPS);

			// First make sure the instruction is repeatable before we make a move.
			if ((instFlags & INST_PRE_REPS) == 0) return EO_SUFFIX; // Implicit operand form, needs instruction suffix.

			ps->usedPrefixes |= (tmpPrefixes & INST_PRE_ADDR_SIZE);

			// This might be a 16 or 32 bits instruction, depends on the decoding mode.
			if (instFlags & INST_16BITS) {
				ps->usedPrefixes |= (tmpPrefixes & INST_PRE_OP_SIZE);

				// Explicit operands only when there's a segment override or address size prefix.
				if ((tmpPrefixes & INST_PRE_OP_SIZE) == tmpPrefixes) return EO_SUFFIX;
				if ((tmpPrefixes & (INST_PRE_OP_SIZE | INST_PRE_REPS)) == tmpPrefixes) return EO_SUFFIX;

				if (OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode16Bits) strcat_WSN(operandText, TEXT_16_BITS);
				else if ((OP_SIZE_AFFECT(dt, totalPrefixes, rex) == Decode64Bits) && (instFlags & INST_64BITS)) {
					ps->usedPrefixes |= INST_PRE_REX;
					strcat_WSN(operandText, TEXT_64_BITS);
				} else strcat_WSN(operandText, TEXT_32_BITS);
			} else {
				// Explicit operands only when there's a segment override or address size prefix.
				if ((tmpPrefixes & INST_PRE_OP_SIZE) == tmpPrefixes) return EO_SUFFIX;
				if ((tmpPrefixes & (INST_PRE_OP_SIZE | (instFlags & INST_PRE_REPS))) == tmpPrefixes) return EO_SUFFIX;

				strcat_WSN(operandText, TEXT_8_BITS);
			}

			str_seg_text(operandText, ps, dt);
			chrcat_WS(operandText, OPEN_CHR);

			if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode16Bits) str_x86def(operandText, &_REGS16[7]);
			else if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode32Bits) str_x86def(operandText, &_REGS32[7]);
			else str_x86def(operandText, &_REGS64[7]);
			chrcat_WS(operandText, CLOSE_CHR);
		break;

			//	Used for In/Out instructions varying forms.
		case OT_REGDX:
			// Simple single IN/OUT instruction.
			if ((instFlags & INST_PRE_REPS) == 0) {
				str_x86def(operandText, &_REGS16[2]);
			} else { // String instruction.
				// Do we need to use the DX register? - Only if the instruction is prefixed, so you will need implicitly output the register.
				// Otherwise, we need a suffix letter for operation-size indication.

				// Exception is when there's only operand size prefix, suffix letter is enough then.
				if ((totalPrefixes & (INST_PRE_OP_SIZE | INST_PRE_REPS)) == totalPrefixes) return EO_SUFFIX;

				if ((totalPrefixes & (INST_PRE_SEGOVRD_MASK | INST_PRE_OP_SIZE | INST_PRE_ADDR_SIZE)) == 0) return EO_SUFFIX;
				str_x86def(operandText, &_REGS16[2]);
			}
		break;

			/* XLAT special treatment:
			32 bit decoding:
			D7 ~ XLATB
			67 D7 ~ XLAT BYTE [BX+AL]
			26 D7 ~ XLAT BYTE ES:[EBX+AL]
			// In 64 bits es is ignored.
			26 D7 ~ db 0x26; XLAT
			*/
		case OT_REGI_EBXAL:
			// Make sure there are other prefixes set.
			if ((totalPrefixes & (INST_PRE_SEGOVRD_MASK | INST_PRE_ADDR_SIZE)) == 0) return EO_SUFFIX; // Implicit operand form, needs instruction suffix.

			ps->usedPrefixes |= (totalPrefixes & INST_PRE_ADDR_SIZE);

			strcat_WSN(operandText, TEXT_8_BITS);
			str_seg_text(operandText, ps, dt);
			chrcat_WS(operandText, OPEN_CHR);

			if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode16Bits) str_x86def(operandText, &_REGS16[3]);
			else if (ADDR_SIZE_AFFECT(dt, totalPrefixes) == Decode32Bits) str_x86def(operandText, &_REGS32[3]);
			else {
				ps->usedPrefixes |= INST_PRE_REX;
				str_x86def(operandText, &_REGS64[3]);
			}

			chrcat_WS(operandText, PLUS_DISP_CHR);
			str_x86def(operandText, &_REGS8[0]);
			chrcat_WS(operandText, CLOSE_CHR);
		break;
                default:
                break;
	}

	// It's ok if we don't update the pointers parameters when we will return EO_HALT or EO_SUFFIX, because
	// they are to be ignored anyways.
	ci->code = code;
	ci->codeLen = codeLen;
	ci->codeOffset = codeOffset;

	return EO_CONTINUE;
}
