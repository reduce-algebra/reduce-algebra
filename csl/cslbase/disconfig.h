/*
disconfig.h

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#ifndef ___DISCONFIG_H__
#define ___DISCONFIG_H__

// diStorm64 supports 64 bit offsets:

// Comment out this macro if you wish to use 32 bits offsets only!
#define SUPPORT_64BIT_OFFSET 1

#ifdef SUPPORT_64BIT_OFFSET
// PyArg_ParseTuple/Py_BuildValue uses a format string in order to parse/build the offset.
// type: int 64
	#define _PY_OFF_INT_SIZE_ "K"
#else
	#define OFFSET_INTEGER unsigned long
	#define _PY_OFF_INT_SIZE_ "k"
#endif

#endif // ___DISCONFIG_H__

