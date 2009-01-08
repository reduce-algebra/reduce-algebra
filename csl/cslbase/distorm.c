/*
distorm.c

:[diStorm64}: C Library Interface
The ultimate disassembler library (80x86, AMD64)
Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#include "decoder.h"
#include "x86defs.h"

// C LIBRARY EXPORTS //
_DLLEXPORT_ _DecodeResult distorm_decode(_OffsetType codeOffset, const unsigned char* code, long codeLen, _DecodeType dt, _DecodedInst result[], unsigned long maxInstructions, unsigned long* usedInstructionsCount)
{
	*usedInstructionsCount = 0;

	// I use codeLen as a signed variable in order to ease detection of underflow... and besides -
	if ((unsigned long)codeLen > 0x7fffffff) { // What is the chance for this??!
		return DECRES_INPUTERR;
	}

	if ((dt != Decode16Bits) && (dt != Decode32Bits) && (dt != Decode64Bits)) {
		return DECRES_INPUTERR;
	}

	if (code == NULL || result == NULL) {
		return DECRES_INPUTERR;
	}

	// Assume length=0 is success.
	if (codeLen == 0) {
		return DECRES_SUCCESS;
	}

	// We need to supply at least 15 entries so the internal_decoder could return anything possible.
	if (maxInstructions < INST_MAXIMUM_SIZE) {
		return DECRES_MEMORYERR;
	}

	return internal_decode(codeOffset, code, codeLen, dt, result, maxInstructions, usedInstructionsCount);
}

