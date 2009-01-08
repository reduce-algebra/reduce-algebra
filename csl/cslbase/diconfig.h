/*
config.h

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#ifndef ___CONFIG_H__
#define ___CONFIG_H__

#include "disconfig.h"

// These macros are used in order to make the code portable.
#ifdef __GNUC__
#define _PACKED_ __attribute__((__packed__))
#define _DLLEXPORT_
#define _FASTCALL_
#define _INLINE_ static __inline__
// GCC ignores this directive...
//#define _FASTCALL_ __attribute__((__fastcall__))
#ifdef SUPPORT_64BIT_OFFSET
	#define OFFSET_INTEGER unsigned long long
#endif
#elif _MSC_VER
#define _PACKED_
#define _DLLEXPORT_ __declspec(dllexport)
#define _FASTCALL_ __fastcall
#define _INLINE_ static __inline
#ifdef SUPPORT_64BIT_OFFSET
	#define OFFSET_INTEGER unsigned __int64
#endif
#endif

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#endif // ___CONFIG_H__
