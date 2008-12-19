/* openmath.c                                  Copyright (C) 1998 NAG Ltd. */

/* This file wascontributed to CSL by NAG Ltd */

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



#ifdef OPENMATH

/*
 * Reading and writing of OpenMath objects, using the INRIA OpenMath library.
 * Developed as a deliverable of the OpenMath Project (ESPRIT Project 24969).
 *
 * Initial version: Vilya Harvey, Nov 24th, 1998.
 *
 * Note: to add this to CCL, the following files had to be modified:
 * Makefile
 * cslbase\entries.h
 * cslbase\externs.h
 * cslbase\restart.c
 * cclbase\exports.lsp
 *
 * Note: to make sure that the OpenMath support is compiled into CCL, the
 * symbol OPENMATH must be #defined.
 */


/* Signature: 3ba819d1 24-May-2008 */

#inclkude "headers.h"


#include <OM.h>
#include <OMconn.h>

#include "openmath.h"


#define OMCCL_ELEM_BITS	31					/* #bits in bignum element. */
#define OMCCL_MAX_BITS	15					/* Must be < OMCCL_ELEM_BITS */
#define OMCCL_MAX_VAL	(1 << OMCCL_MAX_BITS)
#define OMCCL_MAX_MASK	(OMCCL_MAX_VAL - 1)

#define OMCCL_INV_LOG_2	1.44269504			/* 1 / ln(2) */


/*
 * Error reporting macro. The status parameter should be of type OMstatus; the
 * return value is a Lisp_Object representing the appropriate error.
 */
#define om_error(status)		error(0, (int)(status) + 33)


/*
 * Local functions for dealing with property lists.
 */

Lisp_Object om_getLispProperty(Lisp_Object obj, Lisp_Object name);
Lisp_Object om_setLispProperty(Lisp_Object obj, Lisp_Object name, Lisp_Object val);


/*
 * External CCL functions.
 */
extern char *get_string_data(Lisp_Object name, char *why, int32_t *l);


OMdev
om_toDev(Lisp_Object obj)
/* This routine converts a Lisp_Object to an OMdev. It does
 * not check that the object it is given actually *is* an
 * OMdev - that's the caller's responsibility.
 */
{
	OMdev dev;
	
	/* DEBUG */
	if (!is_bignum(obj)) {
		err_printf("[om_toDev] not a bignum!\n");
	}
	else {
		int blen = (bignum_length(obj) >> 2) - 1;
		if (blen != 1)
			err_printf("[om_toDev] bignum length is %d (should be 1)!\n", blen);
	}
	/* END DEBUG */
	
	if (!is_bignum(obj))
		return NULL;
	else if (((bignum_length(obj) >> 2) - 1) != 1)
		return NULL;
	dev = (OMdev) ( bignum_digits(obj)[0] );
	return dev;
}


Lisp_Object
om_fromDev(OMdev dev)
{
	Lisp_Object obj;
	obj = make_one_word_bignum((int32_t)dev);
	return obj;
}


OMstatus
om_toStatus(Lisp_Object obj)
{
	OMstatus status;
	if (!is_fixnum(obj))
		return OMinternalError;
	status = (OMstatus)( int_of_fixnum(obj) );
	return status;
}


Lisp_Object
om_fromStatus(OMstatus status)
{
	Lisp_Object obj;
	obj = fixnum_of_int((int32_t)status);
	return obj;
}


OMencodingType
om_toEncodingType(Lisp_Object obj)
{
	OMencodingType enc;
	if (!is_fixnum(obj))
		return OMencodingUnknown;
	enc = (OMencodingType)( int_of_fixnum(obj) );
	return enc;
}


Lisp_Object
om_fromEncodingType(OMencodingType enc)
{
	Lisp_Object obj;
	obj = fixnum_of_int((int32_t)enc);
	return obj;
}


char *
om_toBigNumStr(Lisp_Object num)
{
	static char hexdigit[] = "0123456789ABCDEF";
	char *str;
	int numDigits, digit;
	int bdigit, boffset;
	int i, j, val;
	int strPos;
	int leading;

	/* Determine the number of digits needed. */
	i = ((bignum_length(num) >> 2) - 1) * 31;
	numDigits = (i >> 2) + (((i & 0x3) != 0) ? 1 : 0);

	str = (char *)malloc((numDigits + 1) * sizeof(char));
	memset(str, 0, (numDigits + 1) * sizeof(char));

	strPos = 0;
	leading = 1;
	digit = 0;
	while (digit < numDigits) {
		i = (numDigits - digit - 1) << 2;
		bdigit = i / 31;
		boffset = i % 31;
		j = 31 - boffset;
		
		switch (j) {
		case 3:
			val = (bignum_digits(num)[bdigit] >> boffset) & 0x7;
			val |= ((bignum_digits(num)[bdigit+1] & 0x1) << 3);
			break;
		case 2:
			val = (bignum_digits(num)[bdigit] >> boffset) & 0x3;
			val |= ((bignum_digits(num)[bdigit+1] & 0x3) << 2);
			break;
		case 1:
			val = (bignum_digits(num)[bdigit] >> boffset) & 0x1;
			val |= ((bignum_digits(num)[bdigit+1] & 0x7) << 1);
			break;
		default:
			val = (bignum_digits(num)[bdigit] >> boffset) & 0xF;
			break;
		}
		
		str[strPos] = hexdigit[val];
		digit++;
		if (hexdigit[val] != '0' || !leading) {
			leading = 0;
			strPos++;
		}
	}

	return str;
}


Lisp_Object
om_fromBigNumStr(char *inData, int len, int sign, OMbigIntType fmt)
{
	Lisp_Object obj, radix, digit;
	int i;

	if (len == 0)
		return fixnum_of_int(0);
	else
		obj = fixnum_of_int(0);

	switch (fmt) {
	case OMbigIntBase10:
		radix = fixnum_of_int(10);
		break;
	case OMbigIntBase16:
		radix = fixnum_of_int(16);
		break;
	default:
		return om_error(OMinternalError);
	}

	for (i = 0; i < len; i++) {
		obj = times2(obj, radix);

		switch (fmt) {
		case OMbigIntBase10:
			digit = fixnum_of_int( (int)(inData[i] - '0') );
			break;
		case OMbigIntBase16:
			if (inData[i] >= 'a' && inData[i] <= 'f')
				digit = fixnum_of_int( (int)(inData[i] - 'a') + 10 );
			else if (inData[i] >= 'A' && inData[i] <= 'F')
				digit = fixnum_of_int( (int)(inData[i] - 'A') + 10 );
			else
				digit = fixnum_of_int( (int)(inData[i] - '0') );
			break;
		}

		obj = plus2(obj, digit);
	}

	if (sign < 0)
		obj = negateb(obj);

	return obj;
}


OMconn
om_toConn(Lisp_Object obj)
{
	OMconn conn;
	
	/* DEBUG */
	if (!is_bignum(obj)) {
		err_printf("[om_toConn] not a bignum!\n");
	}
	else {
		int blen = (bignum_length(obj) >> 2) - 1;
		if (blen != 1)
			err_printf("[om_toConn] bignum length is %d (should be 1)!\n", blen);
	}
	/* END DEBUG */
	
	if (!is_bignum(obj))
		return NULL;
	else if (((bignum_length(obj) >> 2) - 1) != 1)
		return NULL;
	conn = (OMconn)(bignum_digits(obj)[0]);
	return conn;
}


Lisp_Object
om_fromConn(OMconn conn)
{
	Lisp_Object obj;
	obj = make_one_word_bignum((int32_t)conn);
	return obj;
}


char **
om_toCString(Lisp_Object obj)
/* Converts a lisp object which wraps a C string into a C string (a char
 * pointer, where the memory block is allocated on the heap, outside of the
 * control of the CCL garbage collection). Does not check that the Lisp object
 * *is* a C string though.
 */
{
	char **pstr = NULL;
	
	/* DEBUG */
	if (!is_bignum(obj) && !stringp(obj)) {
		err_printf("[om_toCString] not a bignum or a string!\n");
	}
	else if (is_bignum(obj)) {
		int blen = (bignum_length(obj) >> 2) - 1;
		if (blen != 1)
			err_printf("[om_toCString] bignum length is %d (should be 1)!\n", blen);
	}
	/* END DEBUG */
	
	if (!is_bignum(obj) && !stringp(obj))
		return NULL;
	else if (is_bignum(obj)) {
		if (((bignum_length(obj) >> 2) - 1) != 1)
			return NULL;
		pstr = (char **)(bignum_digits(obj)[0]);
	}
	else {
		char *tmp = NULL;
		int len = 0;
		tmp = get_string_data(obj, "om_toCString", &len);
		tmp[len] = '\0';
		pstr = (char **)malloc(sizeof(char *));
		*pstr = strdup(tmp);
	}
	return pstr;
}


Lisp_Object
om_fromCString(char **str)
{
	Lisp_Object obj;
	obj = make_one_word_bignum((int32_t)str);
	return obj;
}


Lisp_Object
om_cStringFromLispString(Lisp_Object lstr)
{
	Lisp_Object cstr;
	cstr = om_fromCString(om_toCString(lstr));
	return cstr;
}


Lisp_Object
om_lispStringFromCString(Lisp_Object cstr)
{
	Lisp_Object lstr;
	char **pstr = om_toCString(cstr);
	lstr = make_string(*pstr);
	return lstr;
}


/*
 * Local functions for dealing with property lists.
 */

Lisp_Object
om_getLispProperty(Lisp_Object obj, Lisp_Object name)
{
	return get(obj, name, C_nil);
}


Lisp_Object
om_setLispProperty(Lisp_Object obj, Lisp_Object name, Lisp_Object val)
{
	return putprop(obj, name, val);
}


/*
 * Exposed OpenMath Device manipulation functions.
 */

Lisp_Object MS_CDECL
om_openFileDev(Lisp_Object nil, int nargs, ...)
/* Opens a file and creates an OpenMath device for it. The return value is the
 * LISP object which wraps the created device. The parameters are:
 *   fname	- string	- the name of the file to open.
 *   fmode	- string	- the mode, as passed to the fopen routine.
 *   fenc	- string	- the OpenMath encoding type of the file.
 */
{
	va_list args;
	Lisp_Object lname, lmode, lenc;
	char *fname, *fmode;
	OMencodingType fenc;
	FILE *f;
	OMdev dev;
	int32_t len;
	Lisp_Object lispDev;

	CSL_IGNORE(nil);

	/* Unpack the parameters into Lisp_Objects. */
	argcheck(nargs, 3, "om_openFileDev");
	va_start(args, nargs);
	lname = va_arg(args, Lisp_Object);
	lmode = va_arg(args, Lisp_Object);
	lenc = va_arg(args, Lisp_Object);
	va_end(args);

	push3(lname, lmode, lenc);

	/* Convert the parameters into their C equivalents. */
	if (!is_vector(lname) || !(type_of_header(vechdr(lname)) == TYPE_STRING))
		return aerror("om_openFileDev");
	errexitn(3);
	fname = get_string_data(lname, "om_openFileDev", &len);
	errexitn(3);
	fname[len] = '\0';

	if (!is_vector(lmode) || !(type_of_header(vechdr(lmode)) == TYPE_STRING))
		return aerror("om_openFileDev");
	errexitn(3);
	fmode = get_string_data(lmode, "om_openFileDev", &len);
	errexitn(3);
	fmode[len] = '\0';

	if (!is_fixnum(lenc))
		return aerror("om_openFileDev");
	errexitn(3);
	/* This gets OMencodingTypes as an integer then casts it to OMencodingType.
	 * That may be a bit dodgy... */
	fenc = om_toEncodingType(lenc);

	pop3(lname, lmode, lenc);

	f = fopen(fname, fmode);
	if (f == NULL)
		return aerror("om_openFileDev: couldn't open named file!");

	/* Create an OpenMath device on the given file. */
	dev = OMmakeDevice(fenc, OMmakeIOFile(f));

	/* Wrap the OpenMath device in a LISP object and return it. */
	lispDev = om_fromDev(dev);

	return onevalue(lispDev);
}


Lisp_Object
om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc)
/* Creates an OpenMath string device on an existing string. The return value is
 * the LISP object which wraps the created device. The parameters are:
 *	lstr	- string	- The string to create the device on. This must be a C
						  string pointer wrapped in a Lisp object.
 *	lenc	- int		- The OpenMath encoding type of the string.
 */
{
	/* There may be a problem with the OM library directly accessing the string
	 * data of a Lisp_Object - see if there is a way around that (if it is a
	 * problem).
	 */

	char **pstr = NULL;
	OMencodingType enc;
	OMdev dev;
	Lisp_Object ldev;

	CSL_IGNORE(nil);
	push2(lstr, lenc);

	pstr = om_toCString(lstr);
	errexitn(2);

	enc = om_toEncodingType(lenc);
	errexitn(2);
	
	dev = OMmakeDevice(enc, OMmakeIOString(pstr));
	ldev = om_fromDev(dev);

	pop2(lstr, lenc);
	return onevalue(ldev);
}


Lisp_Object
om_closeDev(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;

	CSL_IGNORE(nil);
	push(ldev);

	dev = om_toDev(ldev);
	errexitn(1);
	OMcloseDevice(dev);

	pop(ldev);
	return lisp_true;
}


Lisp_Object
om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc)
{
	OMdev dev;
	OMencodingType enc;

	CSL_IGNORE(nil);
	push2(ldev, lenc);

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_setDevEncoding: invalid device");
	errexitn(2);

	if (!is_fixnum(lenc))
		return aerror("om_setDevEncoding: invalid encoding");
	errexitn(2);
	/* This gets OMencodingTypes as an integer then casts it to OMencodingType.
	 * That may be a bit dodgy... */
	enc = om_toEncodingType(lenc);
	errexitn(2);

	pop2(ldev, lenc);

	OMsetDeviceEncoding(dev, enc);
	return onevalue(om_fromDev(dev));
}


/*
 * Exposed OpenMath Connection manipulation functions.
 */


Lisp_Object
om_makeConn(Lisp_Object nil, Lisp_Object ltimeout)
{
	OMconn conn;
	int32_t timeout;

	CSL_IGNORE(nil);
	push(ltimeout);

	if (!is_fixnum(ltimeout))
		return aerror("om_makeConn: timeout value must be a fixnum");
	errexitn(1);

	timeout = int_of_fixnum(ltimeout);
	errexitn(1);
	conn = OMmakeConn(timeout);

	pop(ltimeout);

	return onevalue(om_fromConn(conn));
}


Lisp_Object
om_closeConn(Lisp_Object nil, Lisp_Object lconn)
{
	OMconn conn;
	OMstatus status;

	CSL_IGNORE(nil);
	push(lconn);

	conn = om_toConn(lconn);
	errexitn(1);
	if (!conn)
		return aerror("om_toConn");
	errexitn(1);

	pop(lconn);

	status = OMconnClose(conn);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_getConnInDev(Lisp_Object nil, Lisp_Object lconn)
{
	OMconn conn;
	OMdev dev;

	CSL_IGNORE(nil);
	push(lconn);

	conn = om_toConn(lconn);
	errexitn(1);
	if (!conn)
		return aerror("om_toConn");
	errexitn(1);

	pop(lconn);

	dev = OMconnIn(conn);
	return onevalue(om_fromDev(dev));
}


Lisp_Object
om_getConnOutDev(Lisp_Object nil, Lisp_Object lconn)
{
	OMconn conn;
	OMdev dev;

	CSL_IGNORE(nil);
	push(lconn);

	conn = om_toConn(lconn);
	errexitn(1);
	if (!conn)
		return aerror("om_toConn");
	errexitn(1);

	pop(lconn);

	dev = OMconnOut(conn);
	return om_fromDev(dev);
}


/*
 * Exposed OpenMath client/server functions.
 */

Lisp_Object MS_CDECL
om_connectTCP(Lisp_Object nil, int nargs, ...)
{
	va_list args;
	Lisp_Object lconn, lhost, lport;
	OMconn conn;
	char *host = NULL;
	int32_t hostlen;
	int32_t port;
	OMstatus status;

	CSL_IGNORE(nil);

	/* Unpack the parameters into Lisp_Objects. */
	argcheck(nargs, 3, "om_connectTCP");
	va_start(args, nargs);
	lconn = va_arg(args, Lisp_Object);
	lhost = va_arg(args, Lisp_Object);
	lport = va_arg(args, Lisp_Object);
	va_end(args);

	push3(lconn, lhost, lport);

	/* Convert the parameters into their C equivalents. */
	conn = om_toConn(lconn);
	errexitn(3);
	if (!conn)
		return aerror("om_toConn");
	errexitn(3);
	
	if (!stringp(lhost))
		return aerror("om_connectTCP: host name must be a string");
	errexitn(3);
	host = get_string_data(lhost, "om_putString", &hostlen);
	errexitn(3);
	if (host != NULL)
		host[hostlen] = '\0';

	if (!is_fixnum(lport))
		return aerror("om_connectTCP: port number must be a fixnum");
	errexitn(3);
	port = int_of_fixnum(lport);
	errexitn(3);

	pop3(lconn, lhost, lport);

	status = OMconnTCP(conn, host, port);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport)
{
	OMconn conn;
	int32_t port;
	OMstatus status;

	CSL_IGNORE(nil);
	push2(lconn, lport);

	conn = om_toConn(lconn);
	errexitn(2);
	if (!conn)
		return aerror("om_toConn");
	errexitn(2);

	if (!is_fixnum(lport))
		return aerror("om_bindTCP: port number must be a fixnum");
	errexitn(2);
	port = int_of_fixnum(lport);
	errexitn(2);

	pop2(lconn, lport);

	status = OMbindTCP(conn, port);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


/*
 * Exposed OpenMath Device output functions.
 */

Lisp_Object
om_putApp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputApp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndApp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndApp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putAtp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputAtp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndAtp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndAtp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putAttr(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputAttr(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndAttr(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndAttr(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putBind(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputBind(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndBind(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndBind(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putBVar(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputBVar(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndBVar(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndBVar(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putError(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputError(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndError(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndError(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putObject(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputObject(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putEndObject(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMputEndObject(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a Lisp integer of some sort.
 * The decision of whether to put it as an int32_t or a bigint
 * will be made by this routine.
 */
{
	OMdev dev;
	OMstatus status;
	int size, sign;
	char *data;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_number(val) || is_float(val))
		return aerror("om_putInt");
	
	if (is_fixnum(val)) {
		int32_t ival = int_of_fixnum(val);
		status = OMputInt32(dev, ival);
	}
	else {
		data = om_toBigNumStr(val);
		size = strlen(data);
		sign = minusp(val) ? -1 : 1;
		status = OMputBigInt(dev, data, size, sign, OMbigIntBase16);
		free(data);
	}

	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a real-valued number of some
 * sort (this includes floats, rationals, etc.) and puts it
 * out as an IEEE 64-bit floating point number.
 */
{
	/* TODO: check this generates correct output for all real numbers. */
	OMdev dev;
	OMstatus status;
	double fval;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_number(val))
		return aerror("om_putFloat");

	fval = float_of_number(val);

	/* err_printf("[om-putFloat] fval = %.30lf\n", fval); */

	status = OMputFloat64(dev, &fval);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


Lisp_Object
om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a Lisp vector of 8-bit values.
 */
{
	OMdev dev;
	OMstatus status;
	int32_t len;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_vector(val) || !(type_of_header(vechdr(val)) == TYPE_VEC8))
		return aerror("om_toDev");
	
	/* Get the length of the array. */
	len = length_of_header(val) - 4; /* is this correct??? */

	/* Write out the array data. */
	status = OMputByteArray(dev, ((char *)val - TAG_VECTOR + 4), len);
	if (status != OMsuccess) return om_error(status);
	else return lisp_true;
}


Lisp_Object
om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a symbol.
 */
{
	OMdev dev;
	OMstatus status;
	char *name;
	int32_t len;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_symbol(val))
		return aerror("om_putVar");
	
	/* Do I need to free the memory for name myself? I don't know... */
	name = get_string_data(val, "om_putVar", &len);
	if (name == NULL)
		return om_error(OMinternalError);
	else {
		status = OMputVarN(dev, name, len);
		if (status != OMsuccess)
			return om_error(status);
		else
			return lisp_true;
	}
}


Lisp_Object
om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a Lisp string.
 */
{
	OMdev dev;
	OMstatus status;
	char *name;
	int32_t len;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_vector(val) || !(type_of_header(vechdr(val)) == TYPE_STRING))
		return aerror("om_putString");

	/* Do I need to free the memory for name myself? I don't know... */
	name = get_string_data(val, "om_putString", &len);
	if (name == NULL)
		return om_error(OMinternalError);
	else {
		status = OMputStringN(dev, name, len);
		if (status != OMsuccess)
			return om_error(status);
		else
			return lisp_true;
	}
}


Lisp_Object
om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val)
/* This routine expects val to be a cons cell where the first element is the
 * name of the content dictionary and the second (and final) element is the
 * name of the symbol.
 */
{
	Lisp_Object cdObj, nameObj;

	/* Check that the value passed in is in the correct format. */
	if (!is_cons(val))
		return aerror("om_putSymbol");

	/* Get the cd and name properties (checking that they are set). */
	cdObj = qcar(val);
	if (cdObj == nil)
		return aerror("om_putSymbol: The cd property was not set");
	nameObj = qcar(qcdr(val));
	if (nameObj == nil)
		return aerror("om_putSymbol: The name property was not set");

	/* Invoke the verbose form of the putSymbol routine to output the data. */
	return om_putSymbol2(nil, 3, ldev, cdObj, nameObj);
}


Lisp_Object MS_CDECL
om_putSymbol2(Lisp_Object nil, int nargs, ...)
/*
 * A different form of putSymbol, where the cd and symbol names are given as strings.
 * The parameters are: (om-putSymbol omdevice "cdname" "symbolname")
 */
{
	va_list args;
	Lisp_Object ldev;
	Lisp_Object lcd, lname;
	OMdev dev;
	char *cd, *name;
	int32_t cdLen, nameLen;
	OMstatus status;

	/* Get the arguments from the arglist. */
	argcheck(nargs, 3, "om_putSymbol2");
	va_start(args, nargs);
	ldev = va_arg(args, Lisp_Object);
	lcd = va_arg(args, Lisp_Object);
	lname = va_arg(args, Lisp_Object);
	va_end(args);

	/* err_printf("[om_putSymbol2] about to convert params to C equivalents...\n"); */
	
	/* Convert the parameters into their C equivalents. */
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	if (!is_vector(lcd) || !(type_of_header(vechdr(lcd)) == TYPE_STRING))
		return aerror("om_putSymbol2");
	cd = get_string_data(lcd, "om_putSymbol2", &cdLen);
	if (cd == NULL) {
		status = OMinternalError;
		return om_error(status);
	}

	/* err_printf("[om_putSymbol2] converted cd name (%s)\n", cd); */

	if (!is_vector(lname) || !(type_of_header(vechdr(lname)) == TYPE_STRING))
		return aerror("om_putSymbol2");
	name = get_string_data(lname, "om_putSymbol2", &nameLen);
	if (name == NULL) {
		status = OMinternalError;
		return om_error(status);
	}

	/* err_printf("[om_putSymbol2] converted symbol name (%s)\n", name); */

	/* Now write out the symbol. */
	status = OMputSymbolN(dev, cd, cdLen, name, nameLen);
	if (status != OMsuccess)
		return om_error(status);
	else
		return lisp_true;
}


/*
 * OpenMath input routines.
 */

Lisp_Object
om_getApp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetApp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMA");
}


Lisp_Object
om_getEndApp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndApp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMA-END");
}


Lisp_Object
om_getAtp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetAtp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMATP");
}


Lisp_Object
om_getEndAtp(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndAtp(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMATP-END");
}


Lisp_Object
om_getAttr(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetAttr(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMATTR");
}


Lisp_Object
om_getEndAttr(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndAttr(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OMATTR-END");
}


Lisp_Object
om_getBind(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");
	
	status = OMgetBind(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMBIND");
}


Lisp_Object
om_getEndBind(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndBind(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMBIND-END");
}


Lisp_Object
om_getBVar(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetBVar(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMBVAR");
}


Lisp_Object
om_getEndBVar(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndBVar(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMBVAR-END");
}


Lisp_Object
om_getError(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetError(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OME");
}


Lisp_Object
om_getEndError(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndError(dev);
	if (status != OMsuccess)
		return om_error(status);
	else 
		return make_undefined_symbol("OME-END");
}


Lisp_Object
om_getObject(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetObject(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMOBJ");
}


Lisp_Object
om_getEndObject(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	
	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetEndObject(dev);
	if (status != OMsuccess)
		return om_error(status);
	else
		return make_undefined_symbol("OMOBJ-END");
}


Lisp_Object
om_getInt(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	OMtokenType ttype;
	Lisp_Object obj;

	dev = om_toDev(ldev);
	if (!dev)
		return aerror("om_toDev");

	status = OMgetType(dev, &ttype);
	if (status == OMsuccess) {
		switch (ttype) {
			case OMtokenInt32:
			{
				int32_t val;
				status = OMgetInt32(dev, &val);
				if (status == OMsuccess) {
					/* If none of the top 4 bits are set, we can make this a
					 * fixnum */
					/* On second thoughts, the top bit is the sign, and the <<
					 * operation is sign preserving (I believe), so we only
					 * need to check bits 28-30. */
					if ((val & 0x70000000) == 0)
						obj = fixnum_of_int(val);
					else
						obj = make_one_word_bignum(val);
				}
				break;
			}
			case OMtokenBigInt:
			{
				/* TODO: This is broken. Fix it. */
				char *data;
				int len, sign;
				OMbigIntType fmt;

				status = OMgetBigInt(dev, &data, &len, &sign, &fmt);
				if (status == OMsuccess)
					obj = om_fromBigNumStr(data, len, sign, fmt);
				free(data);
				break;
			}
			default:
			{
				obj = om_error(OMmalformedInput);
				break;
			}
		}
	}
	else obj = om_error(status);

	return onevalue(obj);
}


Lisp_Object
om_getFloat(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	OMtokenType ttype;
	double val;

	dev = om_toDev(ldev);
	if (dev == NULL)
		return aerror("om_toDev");

	status = OMgetType(dev, &ttype);
	if (status == OMsuccess) {
		status = OMgetFloat64(dev, &val);
		if (status == OMsuccess) {
			/* err_printf("[om_getFloat] fval = %.30lf\n", val); */
			return make_boxfloat(val, TYPE_DOUBLE_FLOAT);
		}
		else
			return om_error(status);
	}
	else return om_error(status);
}


Lisp_Object
om_getByteArray(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	int len;
	Lisp_Object obj;

	dev = om_toDev(ldev);
	if (dev == NULL)
		return aerror("om_toDev");
	
	status = OMgetLength(dev, &len);
	if (status != OMsuccess)
		return om_error(status);
	else {
		/* I hope this is right... */
		obj = getvector(TAG_VECTOR, TYPE_VEC8, len + 4);
		status = OMgetByteArrayN(dev, ((char *)obj - TAG_VECTOR + 4), len);
		if (status != OMsuccess)
			return om_error(status);
		else
			return obj;
	}
}


Lisp_Object
om_getVar(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	char *var;
	Lisp_Object obj;

	dev = om_toDev(ldev);
	if (dev == NULL)
		return aerror("om_toDev");

	status = OMgetVar(dev, &var);
	if (status != OMsuccess)
		return om_error(status);
	else {
		obj = make_symbol(var, 2, /* do not convert name to upper case */
			undefined1, undefined2, undefinedn);
		free(var);
		return obj;
	}
}


Lisp_Object
om_getString(Lisp_Object nil, Lisp_Object ldev)
{
	OMdev dev;
	OMstatus status;
	char *str;
	Lisp_Object obj;

	dev = om_toDev(ldev);
	if (dev == NULL)
		return aerror("om_toDev");

	status = OMgetString(dev, &str);
	if (status != OMsuccess)
		return om_error(status);
	else {
		obj = make_string(str);
		free(str);
		return obj;
	}
}


Lisp_Object
om_getSymbol(Lisp_Object nil, Lisp_Object ldev)
/* This returns the Lisp symbol OMS, with a cd property and a name property set
 * to appropriate string values.
 */
{
  OMdev dev;
  OMstatus status;
  char *cd, *name;
  int cdLen, nameLen;
  Lisp_Object cdstr, namestr, obj;

  CSL_IGNORE(nil);
  push(ldev);

  dev = om_toDev(ldev);
  errexitn(1);
  if (dev == NULL)
    return aerror("om_toDev");
  errexitn(1);

  pop(ldev);

  status = OMgetSymbolLength(dev, &cdLen, &nameLen);
  if (status != OMsuccess)
    return om_error(status);
  cd = (char *)malloc(sizeof(char) * (cdLen + 1));
  name = (char *)malloc(sizeof(char) * (nameLen + 1));
  if (cd == NULL || name == NULL) {
    if (cd != NULL) free(cd);
    else if (name != NULL) free(name);
    return om_error(OMinternalError);
  }
  cd[cdLen] = '\0';
  name[nameLen] = '\0';

  status = OMgetSymbolN(dev, cd, cdLen, name, nameLen);
  if (status != OMsuccess)
    obj = om_error(status);
  else {
    cdstr = make_string(cd);
    namestr = make_string(name);
    /* FIXME: is this needed?  push2(cdstr, namestr);*/
    obj = cons(cdstr, cons(namestr, C_nil));
  }

  free(cd);
  free(name);
  /*return onevalue(obj);*/
  return obj;
}


#define om_errmsg0(msg)			\
	err_printf("[om_getType] %s\n", msg)
#define om_errmsg1(msg,a1)		\
	err_printf("[om_getType] %s%s\n", msg,a1)
#define om_errmsg2(msg,a1,a2)	\
	err_printf("[om_getType] %s%s%s\n", msg,a1,a2)


Lisp_Object
om_getType(Lisp_Object nil, Lisp_Object ldev)
{
	static char *typenames[] = {
		"OMtokenApp",		"OMtokenEndApp",
		"OMtokenAtp",		"OMtokenEndAtp",
		"OMtokenAttr",		"OMtokenEndAttr",
		"OMtokenBind",		"OMtokenEndBind",
		"OMtokenBVar",		"OMtokenEndBVar",
		"OMtokenError",		"OMtokenEndError",
		"OMtokenObject",	"OMtokenEndObject",
		"OMtokenInt",
		"OMtokenFloat",
		"OMtokenByteArray",
		"OMtokenVar",
		"OMtokenString",
		"OMtokenSymbol"
	};
	
	OMdev dev;
	OMstatus status;
	OMtokenType ttype;
	char *typename;
	Lisp_Object obj;

	dev = om_toDev(ldev);
	if (dev == NULL)
		return aerror("om_toDev");

	status = OMgetType(dev, &ttype);
	if (status != OMsuccess)
		return om_error(status);
	else {
		switch (ttype) {
			case OMtokenApp:		typename = typenames[0];	break;
			case OMtokenEndApp:		typename = typenames[1];	break;
			case OMtokenAtp:		typename = typenames[2];	break;
			case OMtokenEndAtp:		typename = typenames[3];	break;
			case OMtokenAttr:		typename = typenames[4];	break;
			case OMtokenEndAttr:	        typename = typenames[5];	break;
			case OMtokenBind:		typename = typenames[6];	break;
			case OMtokenEndBind:	        typename = typenames[7];	break;
			case OMtokenBVar:		typename = typenames[8];	break;
			case OMtokenEndBVar:	        typename = typenames[9];	break;
			case OMtokenError:		typename = typenames[10];	break;
			case OMtokenEndError:	        typename = typenames[11];	break;
			case OMtokenObject:		typename = typenames[12];	break;
			case OMtokenEndObject:	        typename = typenames[13];	break;
			case OMtokenInt32:		typename = typenames[14];	break;
			case OMtokenBigInt:		typename = typenames[14];	break;
			case OMtokenFloat64:	        typename = typenames[15];	break;
			case OMtokenByteArray:	        typename = typenames[16];	break;
			case OMtokenVar:		typename = typenames[17];	break;
			case OMtokenString:		typename = typenames[18];	break;
			case OMtokenSymbol:		typename = typenames[19];	break;
		}

		obj = make_undefined_symbol(typename);
		return obj;
	}
}


Lisp_Object
om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr)
{
	return om_cStringFromLispString(lstr);
}


Lisp_Object
om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr)
{
	return om_lispStringFromCString(lpstr);
}


setup_type const om_setup[] = {
	/* LISP Name */			/* Unary */			/* Binary */		/* Nary */
	{"om-openFileDev",		wrong_no_3a,		wrong_no_3b,		om_openFileDev},
	{"om-openStringDev",            too_few_2,		om_openStringDev,	wrong_no_2},
	{"om-closeDev",			om_closeDev,		too_many_1,		wrong_no_1},
	{"om-setDevEncoding",	        too_few_2,		om_setDevEncoding,	wrong_no_2},

	{"om-makeConn",			om_makeConn,		too_many_1,		wrong_no_1},
	{"om-closeConn",		om_closeConn,		too_many_1,		wrong_no_1},
	{"om-getConnInDev",		om_getConnInDev,	too_many_1,		wrong_no_1},
	{"om-getConnOutDev",	        om_getConnOutDev,	too_many_1,		wrong_no_1},

	{"om-connectTCP",		wrong_no_3a,		wrong_no_3b,		om_connectTCP},
	{"om-bindTCP",			too_few_2,		om_bindTCP,		wrong_no_2},

	{"om-putApp",			om_putApp,		too_many_1,		wrong_no_1},
	{"om-putEndApp",		om_putEndApp,		too_many_1,		wrong_no_1},
	{"om-putAtp",			om_putAtp,		too_many_1,		wrong_no_1},
	{"om-putEndAtp",		om_putEndAtp,		too_many_1,		wrong_no_1},
	{"om-putAttr",			om_putAttr,		too_many_1,		wrong_no_1},
	{"om-putEndAttr",		om_putEndAttr,		too_many_1,		wrong_no_1},
	{"om-putBind",			om_putBind,		too_many_1,		wrong_no_1},
	{"om-putEndBind",		om_putEndBind,		too_many_1,		wrong_no_1},
	{"om-putBVar",			om_putBVar,		too_many_1,		wrong_no_1},
	{"om-putEndBVar",		om_putEndBVar,		too_many_1,		wrong_no_1},
	{"om-putError",			om_putError,		too_many_1,		wrong_no_1},
	{"om-putEndError",		om_putEndError,		too_many_1,		wrong_no_1},
	{"om-putObject",		om_putObject,		too_many_1,		wrong_no_1},
	{"om-putEndObject",		om_putEndObject,	too_many_1,		wrong_no_1},

	{"om-putInt",			too_few_2,		om_putInt,		wrong_no_2},
	{"om-putFloat",			too_few_2,		om_putFloat,		wrong_no_2},
	{"om-putByteArray",		too_few_2,		om_putByteArray,	wrong_no_2},
	{"om-putVar",			too_few_2,		om_putVar,		wrong_no_2},
	{"om-putString",		too_few_2,		om_putString,		wrong_no_2},
	{"om-putSymbol",		too_few_2,		om_putSymbol,		om_putSymbol2},

	{"om-getApp",			om_getApp,		too_many_1,		wrong_no_1},
	{"om-getEndApp",		om_getEndApp,		too_many_1,		wrong_no_1},
	{"om-getAtp",			om_getAtp,		too_many_1,		wrong_no_1},
	{"om-getEndAtp",		om_getEndAtp,		too_many_1,		wrong_no_1},
	{"om-getAttr",			om_getAttr,		too_many_1,		wrong_no_1},
	{"om-getEndAttr",		om_getEndAttr,		too_many_1,		wrong_no_1},
	{"om-getBind",			om_getBind,		too_many_1,		wrong_no_1},
	{"om-getEndBind",		om_getEndBind,		too_many_1,		wrong_no_1},
	{"om-getBVar",			om_getBVar,		too_many_1,		wrong_no_1},
	{"om-getEndBVar",		om_getEndBVar,		too_many_1,		wrong_no_1},
	{"om-getError",			om_getError,		too_many_1,		wrong_no_1},
	{"om-getendError",		om_getEndError,		too_many_1,		wrong_no_1},
	{"om-getObject",		om_getObject,		too_many_1,		wrong_no_1},
	{"om-getEndObject",		om_getEndObject,	too_many_1,		wrong_no_1},

	{"om-getInt",			om_getInt,		too_many_1,		wrong_no_1},
	{"om-getFloat",			om_getFloat,		too_many_1,		wrong_no_1},
	{"om-getByteArray",		om_getByteArray,	too_many_1,		wrong_no_1},
	{"om-getVar",			om_getVar,		too_many_1,		wrong_no_1},
	{"om-getString",		om_getString,		too_many_1,		wrong_no_1},
	{"om-getSymbol",		om_getSymbol,		too_many_1,		wrong_no_1},

	{"om-getType",			om_getType,		too_many_1,		wrong_no_1},

	{"om-stringToStringPtr",     om_stringToStringPtr,      too_many_1,		wrong_no_1},
	{"om-stringPtrToString",     om_stringPtrToString,      too_many_1,		wrong_no_1},

	{NULL,	0,	0,	0}
};

#endif /* OPENMATH */
