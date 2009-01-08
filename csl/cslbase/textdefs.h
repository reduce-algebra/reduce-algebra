/*
textdefs.h

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#ifndef ___TEXTDEFS_H__
#define ___TEXTDEFS_H__

#include "diconfig.h"
#include "wstring.h"

#define PLUS_DISP_CHR '+'
#define MINUS_DISP_CHR '-'
// CHR0 is used for FPU, ST(i) register
#define OPEN_CHR0 '('
#define CLOSE_CHR0 ')'
#define OPEN_CHR '['
#define CLOSE_CHR ']'
#define SEP_STR ", "
#define SEP_CHR ','
#define SP_CHR ' '
#define SEG_OFF_CHR ':'

/* Naming Convention:

get - returns a pointer to a string.
str - concatenates to string.

hex - means the function is used for hex dump (number is padded to required size).
code - means the function is used for disassembled instruction.

sp - space character in front of the string.
h - '0x' in front of the string.

b - byte
w - word
dw - double word
qw - quad word

all numbers are in HEX.
*/

extern char TextBTable[256][4];
extern char TextHBTable[256][6];

_INLINE_ char* get_hex_b(unsigned long x)
{
	return &TextBTable[x & 255][1]; // Skip space character.
}

_INLINE_ char* get_code_sp_hb(unsigned long x)
{
	return TextHBTable[x & 255];
}

void _FASTCALL_ str_hex_b(_WString* s, unsigned long x);
void _FASTCALL_ str_code_hb(_WString* s, unsigned long x);

void _FASTCALL_ str_hex_sp_b(_WString* s, unsigned long x);
void _FASTCALL_ str_code_sp_hb(_WString* s, unsigned long x);

void _FASTCALL_ str_hex_sp_w(_WString* s, unsigned long x);
void _FASTCALL_ str_code_hw(_WString* s, unsigned long x);

void _FASTCALL_ str_hex_sp_dw(_WString* s, unsigned long x);
void _FASTCALL_ str_code_hdw(_WString* s, unsigned long x);

void _FASTCALL_ str_hex_sp_qw(_WString* s, unsigned char src[8]);
void _FASTCALL_ str_code_hqw(_WString* s, unsigned char src[8]);

#endif // ___TEXTDEFS_H__
