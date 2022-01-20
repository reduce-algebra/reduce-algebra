// openmath.cpp                                 Copyright (C) 2022 NAG Ltd.

// This file was contributed to CSL by NAG Ltd

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


#ifdef OPENMATH

//
// Reading and writing of OpenMath objects, using the INRIA OpenMath library.
// Developed as a deliverable of the OpenMath Project (ESPRIT Project 24969).
//
// Initial version: Vilya Harvey, Nov 24th, 1998.
//
// Note: to add this to CCL, the following files had to be modified:
// Makefile
// cslbase\entries.h
// cslbase\externs.h
// cslbase\restart.c
// cclbase\exports.lsp
//
// Note: to make sure that the OpenMath support is compiled into CCL, the
// symbol OPENMATH must be #defined.
//

#include "headers.h"


#include <OM.h>
#include <OMconn.h>

#include "openmath.h"


#define OMCCL_ELEM_BITS 31                  // #bits in bignum element.
#define OMCCL_MAX_BITS  15                  // Must be < OMCCL_ELEM_BITS
#define OMCCL_MAX_VAL   (1 << OMCCL_MAX_BITS)
#define OMCCL_MAX_MASK  (OMCCL_MAX_VAL - 1)

#define OMCCL_INV_LOG_2 1.44269504          // 1 / ln(2)


//
// Error reporting macro. The status parameter should be of type OMstatus; the
// return value is a Lisp_Object representing the appropriate error.
//
#define om_error(status)        error(0, (int)(status) + 33)


//
// Local functions for dealing with property lists.
//

LispObject om_getLispProperty(LispObject obj, LispObject name);
LispObject om_setLispProperty(LispObject obj, LispObject name,
                              LispObject val);


//
// External CCL functions.
//

OMdev
om_toDev(LispObject obj)
// This routine converts a Lisp_Object to an OMdev. It does
// not check that the object it is given actually *is* an
// OMdev - that's the caller's responsibility.
//
{   OMdev dev;

    // DEBUG
    if (!is_bignum(obj))
    {   err_printf("[om_toDev] not a bignum!\n");
    }
    else
    {   int blen = (bignum_length(obj) >> 2) - 1;
        if (blen != 1)
            err_printf("[om_toDev] bignum length is %d (should be 1)!\n", blen);
    }
    // END DEBUG

    if (!is_bignum(obj))
        return nullptr;
    else if (((bignum_length(obj) >> 2) - 1) != 1)
        return nullptr;
    dev = (OMdev) ( bignum_digits(obj)[0] );
    return dev;
}


LispObject om_fromDev(OMdev dev)
{   LispObject obj;
    obj = make_one_word_bignum((int32_t)dev);
    return obj;
}


OMstatus
om_toStatus(LispObject obj)
{   OMstatus status;
    if (!is_fixnum(obj))
        return OMinternalError;
    status = (OMstatus)( int_of_fixnum(obj) );
    return status;
}


LispObject om_fromStatus(OMstatus status)
{   LispObject obj;
    obj = fixnum_of_int((int32_t)status);
    return obj;
}


OMencodingType
om_toEncodingType(LispObject obj)
{   OMencodingType enc;
    if (!is_fixnum(obj))
        return OMencodingUnknown;
    enc = (OMencodingType)( int_of_fixnum(obj) );
    return enc;
}


LispObject om_fromEncodingType(OMencodingType enc)
{   LispObject obj;
    obj = fixnum_of_int((int32_t)enc);
    return obj;
}


char *
om_toBigNumStr(LispObject num)
{   static char hexdigit[] = "0123456789ABCDEF";
    char *str;
    int numDigits, digit;
    int bdigit, boffset;
    int i, j, val;
    int strPos;
    int leading;

    // Determine the number of digits needed.
    i = ((bignum_length(num) >> 2) - 1) * 31;
    numDigits = (i >> 2) + (((i & 0x3) != 0) ? 1 : 0);

// If we are out of memory this will just crash with an exception thown.
    str = new char[numDigits + 1];
    std::memset(str, 0, (numDigits + 1) * sizeof(char));

    strPos = 0;
    leading = 1;
    digit = 0;
    while (digit < numDigits)
    {   i = (numDigits - digit - 1) << 2;
        bdigit = i / 31;
        boffset = i % 31;
        j = 31 - boffset;

        switch (j)
        {   case 3:
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
        if (hexdigit[val] != '0' || !leading)
        {   leading = 0;
            strPos++;
        }
    }

    return str;
}


LispObject om_fromBigNumStr(char *inData, int len, int sign,
                            OMbigIntType fmt)
{   LispObject obj, radix, digit;
    int i;

    if (len == 0)
        return fixnum_of_int(0);
    else
        obj = fixnum_of_int(0);

    switch (fmt)
    {   case OMbigIntBase10:
            radix = fixnum_of_int(10);
            break;
        case OMbigIntBase16:
            radix = fixnum_of_int(16);
            break;
        default:
            return om_error(OMinternalError);
    }

    for (i = 0; i < len; i++)
    {   obj = times2(obj, radix);

        switch (fmt)
        {   case OMbigIntBase10:
                digit = fixnum_of_int( static_cast<int>(inData[i] - '0') );
                break;
            case OMbigIntBase16:
                if (inData[i] >= 'a' && inData[i] <= 'f')
                    digit = fixnum_of_int( static_cast<int>(inData[i] - 'a') + 10 );
                else if (inData[i] >= 'A' && inData[i] <= 'F')
                    digit = fixnum_of_int( static_cast<int>(inData[i] - 'A') + 10 );
                else
                    digit = fixnum_of_int( static_cast<int>(inData[i] - '0') );
                break;
        }

        obj = plus2(obj, digit);
    }

    if (sign < 0)
        obj = negateb(obj);

    return obj;
}


OMconn
om_toConn(LispObject obj)
{   OMconn conn;

    // DEBUG
    if (!is_bignum(obj))
    {   err_printf("[om_toConn] not a bignum!\n");
    }
    else
    {   int blen = (bignum_length(obj) >> 2) - 1;
        if (blen != 1)
            err_printf("[om_toConn] bignum length is %d (should be 1)!\n", blen);
    }
    // END DEBUG

    if (!is_bignum(obj))
        return nullptr;
    else if (((bignum_length(obj) >> 2) - 1) != 1)
        return nullptr;
    conn = (OMconn)(bignum_digits(obj)[0]);
    return conn;
}


LispObject om_fromConn(OMconn conn)
{   LispObject obj;
    obj = make_one_word_bignum((int32_t)conn);
    return obj;
}


char **
om_toCString(LispObject obj)
// Converts a lisp object which wraps a C string into a C string (a char
// pointer, where the memory block is allocated on the heap, outside of the
// control of the CCL garbage collection). Does not check that the Lisp object
// *is* a C string though.
//
{   char **pstr = nullptr;

    // DEBUG
    if (!is_bignum(obj) && !stringp(obj))
    {   err_printf("[om_toCString] not a bignum or a string!\n");
    }
    else if (is_bignum(obj))
    {   int blen = (bignum_length(obj) >> 2) - 1;
        if (blen != 1)
            err_printf("[om_toCString] bignum length is %d (should be 1)!\n",
                       blen);
    }
    // END DEBUG

    if (!is_bignum(obj) && !stringp(obj))
        return nullptr;
    else if (is_bignum(obj))
    {   if (((bignum_length(obj) >> 2) - 1) != 1)
            return nullptr;
        pstr = (char **)(bignum_digits(obj)[0]);
    }
    else
    {   char *tmp = nullptr;
        int len = 0;
        tmp = get_string_data(obj, "om_toCString", len);
        tmp[len] = '\0';
        pstr = new char *();
        *pstr = strdup(tmp);
    }
    return pstr;
}


LispObject om_fromCString(char **str)
{   LispObject obj;
    obj = make_one_word_bignum((int32_t)str);
    return obj;
}


LispObject om_cStringFromLispString(LispObject lstr)
{   LispObject cstr;
    cstr = om_fromCString(om_toCString(lstr));
    return cstr;
}


LispObject om_lispStringFromCString(LispObject cstr)
{   LispObject lstr;
    char **pstr = om_toCString(cstr);
    lstr = make_string(*pstr);
    return lstr;
}


//
// Local functions for dealing with property lists.
//

LispObject om_getLispProperty(LispObject obj, LispObject name)
{   return get(obj, name, nil);
}


LispObject om_setLispProperty(LispObject obj, LispObject name,
                              LispObject val)
{   return putprop(obj, name, val);
}


//
// Exposed OpenMath Device manipulation functions.
//

LispObject om_openFileDev(LispObject env, LispObject lname, LispObject lmode, LispObject lenc)
// Opens a file and creates an OpenMath device for it. The return value is the
// LISP object which wraps the created device. The parameters are:
//   fname  - string    - the name of the file to open.
//   fmode  - string    - the mode, as passed to the fopen routine.
//   fenc   - string    - the OpenMath encoding type of the file.
//
    char *fname, *fmode;
    OMencodingType fenc;
    std::FILE *f;
    OMdev dev;
    int32_t len = 0;
    LispObject lispDev;
    THREADID;
    Save save(threadId, lname, lmode, lenc);

    // Convert the parameters into their C equivalents.
    if (!is_vector(lname) ||
        !(type_of_header(vechdr(lname)) == TYPE_STRING))
        return aerror("om_openFileDev");
    fname = get_string_data(lname, "om_openFileDev", len);
    fname[len] = '\0';

    if (!is_vector(lmode) ||
        !(type_of_header(vechdr(lmode)) == TYPE_STRING))
        return aerror("om_openFileDev");
    fmode = get_string_data(lmode, "om_openFileDev", len);
    fmode[len] = '\0';

    if (!is_fixnum(lenc))
        return aerror("om_openFileDev");
    // This gets OMencodingTypes as an integer then casts it to OMencodingType.
    //   * That may be a bit dodgy...
    fenc = om_toEncodingType(lenc);

    save.restore(lname, lmode, lenc);

    f = std::fopen(fname, fmode);
    if (f == nullptr)
        return aerror("om_openFileDev: couldn't open named file!");

    // Create an OpenMath device on the given file.
    dev = OMmakeDevice(fenc, OMmakeIOFile(f));

    // Wrap the OpenMath device in a LISP object and return it.
    lispDev = om_fromDev(dev);

    return onevalue(lispDev);
}


LispObject om_openStringDev(LispObject env, LispObject lstr,
                            LispObject lenc)
// Creates an OpenMath string device on an existing string. The return value is
// the LISP object which wraps the created device. The parameters are:
//  lstr    - string    - The string to create the device on. This must be a C
//                        string pointer wrapped in a Lisp object.
//  lenc    - int       - The OpenMath encoding type of the string.
//
{   // There may be a problem with the OM library directly accessing the string
//     data of a Lisp_Object - see if there is a way around that (if it is a
//     problem).
//

    char **pstr = nullptr;
    OMencodingType enc;
    OMdev dev;

    THREADID;
    Save save(threadId, lenc);
    pstr = om_toCString(lstr);
    errexit();
    save.restore(lenc);

    enc = om_toEncodingType(lenc);
    errexit();

    dev = OMmakeDevice(enc, OMmakeIOString(pstr));
    return om_fromDev(dev);
}


LispObject om_closeDev(LispObject env, LispObject ldev)
{   OMdev dev;

    dev = om_toDev(ldev);
    errexit();
    OMcloseDevice(dev);

    return lisp_true;
}


LispObject om_setDevEncoding(LispObject env, LispObject ldev,
                             LispObject lenc)
{   OMdev dev;
    OMencodingType enc;

    THREADIS;
    Save save(threadId, lenc);

    dev = om_toDev(ldev);
    errexit();
    if (!dev)
        return aerror("om_setDevEncoding: invalid device");

    if (!is_fixnum(lenc))
        return aerror("om_setDevEncoding: invalid encoding");
    // This gets OMencodingTypes as an integer then casts it to OMencodingType.
   //   * That may be a bit dodgy...
    save.restore(ldev);
    enc = om_toEncodingType(lenc);

    OMsetDeviceEncoding(dev, enc);
    return onevalue(om_fromDev(dev));
}


//
// Exposed OpenMath Connection manipulation functions.
//


LispObject om_makeConn(LispObject env, LispObject ltimeout)
{   OMconn conn;
    int32_t timeout;

    if (!is_fixnum(ltimeout))
        return aerror("om_makeConn: timeout value must be a fixnum");

    timeout = int_of_fixnum(ltimeout);
    conn = OMmakeConn(timeout);

    return onevalue(om_fromConn(conn));
}


LispObject om_closeConn(LispObject env, LispObject lconn)
{   OMconn conn;
    OMstatus status;

    conn = om_toConn(lconn);
    if (!conn)
        return aerror("om_toConn");

    status = OMconnClose(conn);
    if (status != OMsuccess)
        return om_error(status);
    else return lisp_true;
}


LispObject om_getConnInDev(LispObject env, LispObject lconn)
{   OMconn conn;
    OMdev dev;

    conn = om_toConn(lconn);
    errexit();
    if (!conn)
        return aerror("om_toConn");

    dev = OMconnIn(conn);
    return onevalue(om_fromDev(dev));
}


LispObject om_getConnOutDev(LispObject env, LispObject lconn)
{   OMconn conn;
    OMdev dev;

    conn = om_toConn(lconn);
    errexit();
    if (!conn)
        return aerror("om_toConn");

    dev = OMconnOut(conn);
    return om_fromDev(dev);
}


//
// Exposed OpenMath client/server functions.
//

LispObject om_connectTCP(LispObject env, LispObject lconn,
                         LispObject lhost, LispObject lport)
{   OMconn conn;
    char *host = nullptr;
    int32_t hostlen = 0;
    int32_t port;
    OMstatus status;

    if (!is_fixnum(lport))
        return aerror("om_connectTCP: port number must be a fixnum");
 
    THREADID;
    {   Save save(threadId, lhost);

    // Convert the parameters into their C equivalents.
        conn = om_toConn(lconn);
        errexit();
        if (!conn)
            return aerror("om_toConn");
        save.restore(lhost);
    }
    if (!stringp(lhost))
        return aerror("om_connectTCP: host name must be a string");

    host = get_string_data(lhost, "om_putString", hostlen);
    errexit();
    if (host != nullptr)
        host[hostlen] = '\0';
    port = int_of_fixnum(lport);

    status = OMconnTCP(conn, host, port);
    if (status != OMsuccess)
        return om_error(status);
    else
        return lisp_true;
}


LispObject om_bindTCP(LispObject env, LispObject lconn,
                      LispObject lport)
{   OMconn conn;
    int32_t port;
    OMstatus status;

    if (!is_fixnum(lport))
        return aerror("om_bindTCP: port number must be a fixnum");

    conn = om_toConn(lconn);
    if (!conn)
        return aerror("om_toConn");

    port = int_of_fixnum(lport);

    status = OMbindTCP(conn, port);
    if (status != OMsuccess)
        return om_error(status);
    else
        return lisp_true;
}


//
// Exposed OpenMath Device output functions.
//

LispObject om_putApp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndApp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putAtp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndAtp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putAttr(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndAttr(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putBind(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndBind(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putBVar(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndBVar(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putError(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndError(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putObject(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putEndObject(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_putInt(LispObject env, LispObject ldev, LispObject val)
// This routine expects val to be a Lisp integer of some sort.
// The decision of whether to put it as an int32_t or a bigint
// will be made by this routine.
//
{   OMdev dev;
    OMstatus status;
    int size, sign;
    char *data;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    if (!is_number(val) || is_float(val))
        return aerror("om_putInt");

    if (is_fixnum(val))
    {   int32_t ival = int_of_fixnum(val);
        status = OMputInt32(dev, ival);
    }
    else
    {   data = om_toBigNumStr(val);
        size = std::strlen(data);
        sign = minusp(val) ? -1 : 1;
        status = OMputBigInt(dev, data, size, sign, OMbigIntBase16);
        delete [] data;
    }

    if (status != OMsuccess)
        return om_error(status);
    else
        return lisp_true;
}


LispObject om_putFloat(LispObject env, LispObject ldev,
                       LispObject val)
// This routine expects val to be a real-valued number of some
// sort (this includes floats, rationals, etc.) and puts it
// out as an IEEE 64-bit floating point number.
//
{   // TODO: check this generates correct output for all real numbers.
    OMdev dev;
    OMstatus status;
    double fval;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    if (!is_number(val))
        return aerror("om_putFloat");

    fval = float_of_number(val);

    // err_printf("[om-putFloat] fval = %.30lf\n", fval);

    status = OMputFloat64(dev, &fval);
    if (status != OMsuccess)
        return om_error(status);
    else
        return lisp_true;
}


LispObject om_putByteArray(LispObject env, LispObject ldev,
                           LispObject val)
// This routine expects val to be a Lisp vector of 8-bit values.
//
{   OMdev dev;
    OMstatus status;
    int32_t len;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    if (!is_vector(val) || !(type_of_header(vechdr(val)) == TYPE_VEC8))
        return aerror("om_toDev");

    // Get the length of the array.
    len = length_of_byteheader(val) - CELL; // is this correct?

    // Write out the array data.
    status = OMputByteArray(dev,
                            (reinterpret_cast<char *>(val) - TAG_VECTOR + CELL), len);
    if (status != OMsuccess) return om_error(status);
    else return lisp_true;
}


LispObject om_putVar(LispObject env, LispObject ldev, LispObject val)
// This routine expects val to be a symbol.
//
{   OMdev dev;
    OMstatus status;
    char *name;
    int32_t len = 0;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    if (!is_symbol(val))
        return aerror("om_putVar");

    // Do I need to free the memory for name myself? I don't know...
    name = get_string_data(val, "om_putVar", len);
    if (name == nullptr)
        return om_error(OMinternalError);
    else
    {   status = OMputVarN(dev, name, len);
        if (status != OMsuccess)
            return om_error(status);
        else
            return lisp_true;
    }
}


LispObject om_putString(LispObject env, LispObject ldev,
                        LispObject val)
// This routine expects val to be a Lisp string.
//
{   OMdev dev;
    OMstatus status;
    char *name;
    int32_t len = 0;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    if (!is_vector(val) || !(type_of_header(vechdr(val)) == TYPE_STRING))
        return aerror("om_putString");

    // Do I need to free the memory for name myself? I don't know...
    name = get_string_data(val, "om_putString", len);
    if (name == nullptr)
        return om_error(OMinternalError);
    else
    {   status = OMputStringN(dev, name, len);
        if (status != OMsuccess)
            return om_error(status);
        else
            return lisp_true;
    }
}


LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val)
// This routine expects val to be a cons cell where the first element is the
// name of the content dictionary and the second (and final) element is the
// name of the symbol.
//
{   LispObject cdObj, nameObj;

    // Check that the value passed in is in the correct format.
    if (!is_cons(val))
        return aerror("om_putSymbol");

    // Get the cd and name properties (checking that they are set).
    cdObj = car(val);
    if (cdObj == nil)
        return aerror("om_putSymbol: The cd property was not set");
    nameObj = car(cdr(val));
    if (nameObj == nil)
        return aerror("om_putSymbol: The name property was not set");

    // Invoke the verbose form of the putSymbol routine to output the data.
    return om_putSymbol2(nil, 3, ldev, cdObj, nameObj);
}


LispObject om_putSymbol2(LispObject env,
                         LispObject ldev, LispObject lcd, LispObject lname)
//
// A different form of putSymbol, where the cd and symbol names are given as strings.
// The parameters are: (om-putSymbol omdevice "cdname" "symbolname")
//
{   OMdev dev;
    char *cd, *name;
    int32_t cdLen = 0, nameLen = 0;
    OMstatus status;
    THREADID;

    // err_printf("[om_putSymbol2] about to convert params to C equivalents...\n");

    // Convert the parameters into their C equivalents.
    {   Save save(threadId, lcd, lname);
        dev = om_toDev(ldev);
        errexit();
        if (!dev)
            return aerror("om_toDev");
        save.restore(lcd, lname);
    }

    if (!is_vector(lcd) || !(type_of_header(vechdr(lcd)) == TYPE_STRING))
        return aerror("om_putSymbol2");
    Save save(threadId, lname);
    cd = get_string_data(lcd, "om_putSymbol2", cdLen);
    errexit();
    if (cd == nullptr)
    {   status = OMinternalError;
        return om_error(status);
    }
    save.restore(lname);

    // err_printf("[om_putSymbol2] converted cd name (%s)\n", cd);

    if (!is_vector(lname) ||
        !(type_of_header(vechdr(lname)) == TYPE_STRING))
        return aerror("om_putSymbol2");
    name = get_string_data(lname, "om_putSymbol2", nameLen);
    if (name == nullptr)
    {   status = OMinternalError;
        return om_error(status);
    }

    // err_printf("[om_putSymbol2] converted symbol name (%s)\n", name);

    // Now write out the symbol.
    status = OMputSymbolN(dev, cd, cdLen, name, nameLen);
    if (status != OMsuccess)
        return om_error(status);
    else
        return lisp_true;
}


//
// OpenMath input routines.
//

LispObject om_getApp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndApp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getAtp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndAtp(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getAttr(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndAttr(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getBind(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndBind(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getBVar(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndBVar(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getError(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndError(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getObject(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getEndObject(LispObject env, LispObject ldev)
{   OMdev dev;
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


LispObject om_getInt(LispObject env, LispObject ldev)
{   OMdev dev;
    OMstatus status;
    OMtokenType ttype;
    LispObject obj;

    dev = om_toDev(ldev);
    if (!dev)
        return aerror("om_toDev");

    status = OMgetType(dev, &ttype);
    if (status == OMsuccess)
    {   switch (ttype)
        {   case OMtokenInt32:
            {   int32_t val;
                status = OMgetInt32(dev, &val);
                if (status == OMsuccess)
                {   // If none of the top 4 bits are set, we can make this a
//                   * fixnum
                    // On second thoughts, the top bit is the sign, and the <<
//                     operation is sign preserving (I believe), so we only
//                   * need to check bits 28-30.
                    if ((val & 0x70000000) == 0)
                        obj = fixnum_of_int(val);
                    else
                        obj = make_one_word_bignum(val);
                }
                break;
            }
            case OMtokenBigInt:
            {   // TODO: This is broken. Fix it.
                char *data;
                int len, sign;
                OMbigIntType fmt;

                status = OMgetBigInt(dev, &data, &len, &sign, &fmt);
                if (status == OMsuccess)
                    obj = om_fromBigNumStr(data, len, sign, fmt);
                delete [] data;
                break;
            }
            default:
            {   obj = om_error(OMmalformedInput);
                break;
            }
        }
    }
    else obj = om_error(status);

    return onevalue(obj);
}


LispObject om_getFloat(LispObject env, LispObject ldev)
{   OMdev dev;
    OMstatus status;
    OMtokenType ttype;
    double val;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetType(dev, &ttype);
    if (status == OMsuccess)
    {   status = OMgetFloat64(dev, &val);
        if (status == OMsuccess)
        {   // err_printf("[om_getFloat] fval = %.30lf\n", val);
            return make_boxfloat(val, TYPE_DOUBLE_FLOAT);
        }
        else
            return om_error(status);
    }
    else return om_error(status);
}


LispObject om_getByteArray(LispObject env, LispObject ldev)
{   OMdev dev;
    OMstatus status;
    int len;
    LispObject obj;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetLength(dev, &len);
    if (status != OMsuccess)
        return om_error(status);
    else
    {   // I hope this is right...
        obj = get_basic_vector(TAG_VECTOR, TYPE_VEC8, len + 4);
        status = OMgetByteArrayN(dev,
                                 (reinterpret_cast<char *>(obj) - TAG_VECTOR + 4), len);
        if (status != OMsuccess)
            return om_error(status);
        else
            return obj;
    }
}


LispObject om_getVar(LispObject env, LispObject ldev)
{   OMdev dev;
    OMstatus status;
    char *var;
    LispObject obj;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetVar(dev, &var);
    if (status != OMsuccess)
        return om_error(status);
    else
    {   obj = make_symbol(var, 2, // do not convert name to upper case
                          undefined1, undefined2, undefinedn);
        delete [] var;
        return obj;
    }
}


LispObject om_getString(LispObject env, LispObject ldev)
{   OMdev dev;
    OMstatus status;
    char *str;
    LispObject obj;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetString(dev, &str);
    if (status != OMsuccess)
        return om_error(status);
    else
    {   obj = make_string(str);
        delete [] str;
        return obj;
    }
}


LispObject om_getSymbol(LispObject env, LispObject ldev)
// This returns the Lisp symbol OMS, with a cd property and a name property set
// to appropriate string values.
//
{   OMdev dev;
    OMstatus status;
    char *cd, *name;
    int cdLen, nameLen;
    LispObject cdstr, namestr, obj;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetSymbolLength(dev, &cdLen, &nameLen);
    if (status != OMsuccess)
        return om_error(status);
    cd = new char[cdLen + 1];
    name = new (std::nothrow) char[nameLen + 1];
    if (cd == nullptr || name == nullptr)
    {   if (cd != nullptr) delete [] cd;
        else if (name != nullptr) delete [] name;
        return om_error(OMinternalError);
    }
    cd[cdLen] = '\0';
    name[nameLen] = '\0';

    status = OMgetSymbolN(dev, cd, cdLen, name, nameLen);
    if (status != OMsuccess)
        obj = om_error(status);
    else
    {   cdstr = make_string(cd);
        errexit();
        THREADID;
        Save save(threadId, cdstr);
        namestr = make_string(name);
        errexit();
        errexit();
        obj = list2(cdstr, namestr);
    }

    delete [] cd;
    delete [] name;
    //return onevalue(obj);
    return obj;
}


#define om_errmsg0(msg)         \
    err_printf("[om_getType] %s\n", msg)
#define om_errmsg1(msg,a1)      \
    err_printf("[om_getType] %s%s\n", msg,a1)
#define om_errmsg2(msg,a1,a2)   \
    err_printf("[om_getType] %s%s%s\n", msg,a1,a2)


LispObject om_getType(LispObject env, LispObject ldev)
{   static char *typenames[] =
    {   "OMtokenApp",       "OMtokenEndApp",
        "OMtokenAtp",       "OMtokenEndAtp",
        "OMtokenAttr",      "OMtokenEndAttr",
        "OMtokenBind",      "OMtokenEndBind",
        "OMtokenBVar",      "OMtokenEndBVar",
        "OMtokenError",     "OMtokenEndError",
        "OMtokenObject",    "OMtokenEndObject",
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
    LispObject obj;

    dev = om_toDev(ldev);
    if (dev == nullptr)
        return aerror("om_toDev");

    status = OMgetType(dev, &ttype);
    if (status != OMsuccess)
        return om_error(status);
    else
    {   switch (ttype)
        {   case OMtokenApp:        typename = typenames[0];    break;
            case OMtokenEndApp:     typename = typenames[1];    break;
            case OMtokenAtp:        typename = typenames[2];    break;
            case OMtokenEndAtp:     typename = typenames[3];    break;
            case OMtokenAttr:       typename = typenames[4];    break;
            case OMtokenEndAttr:            typename = typenames[5];    break;
            case OMtokenBind:       typename = typenames[6];    break;
            case OMtokenEndBind:            typename = typenames[7];    break;
            case OMtokenBVar:       typename = typenames[8];    break;
            case OMtokenEndBVar:            typename = typenames[9];    break;
            case OMtokenError:      typename = typenames[10];   break;
            case OMtokenEndError:           typename = typenames[11];   break;
            case OMtokenObject:     typename = typenames[12];   break;
            case OMtokenEndObject:          typename = typenames[13];   break;
            case OMtokenInt32:      typename = typenames[14];   break;
            case OMtokenBigInt:     typename = typenames[14];   break;
            case OMtokenFloat64:            typename = typenames[15];   break;
            case OMtokenByteArray:          typename = typenames[16];   break;
            case OMtokenVar:        typename = typenames[17];   break;
            case OMtokenString:     typename = typenames[18];   break;
            case OMtokenSymbol:     typename = typenames[19];   break;
        }

        obj = make_undefined_symbol(typename);
        return obj;
    }
}


LispObject om_stringToStringPtr(LispObject env, LispObject lstr)
{   return om_cStringFromLispString(lstr);
}


LispObject om_stringPtrToString(LispObject env, LispObject lpstr)
{   return om_lispStringFromCString(lpstr);
}

// This is OUT OF DATE code and will not at present work!

setup_type const om_setup[] =
{
    DEF_3("om-openFileDev",      om_openFileDev),
    DEF_2("om-openStringDev",    om_openStringDev),
    DEF_1("om-closeDev",         om_closeDev),
    DEF_2("om-setDevEncoding",   om_setDevEncoding),

    DEF_1("om-makeConn",         om_makeConn),
    DEF_1("om-closeConn",        om_closeConn),
    DEF_1("om-getConnInDev",     om_getConnInDev),
    DEF_1("om-getConnOutDev",    om_getConnOutDev),

    DEF_3("om-connectTCP",       om_connectTCP),
    DEF_2("om-bindTCP",          om_bindTCP),

    DEF_1("om-putApp",           om_putApp),
    DEF_1("om-putEndApp",        om_putEndApp),
    DEF_1("om-putAtp",           om_putAtp),
    DEF_1("om-putEndAtp",        om_putEndAtp),
    DEF_1("om-putAttr",          om_putAttr),
    DEF_1("om-putEndAttr",       om_putEndAttr),
    DEF_1("om-putBind",          om_putBind),
    DEF_1("om-putEndBind",       om_putEndBind),
    DEF_1("om-putBVar",          om_putBVar),
    DEF_1("om-putEndBVar",       om_putEndBVar),
    DEF_1("om-putError",         om_putError),
    DEF_1("om-putEndError",      om_putEndError),
    DEF_1("om-putObject",        om_putObject),
    DEF_1("om-putEndObject",     om_putEndObject),

    DEF_2("om-putInt",           om_putInt),
    DEF_2("om-putFloat",         om_putFloat),
    DEF_2("om-putByteArray",     om_putByteArray),
    DEF_2("om-putVar",           om_putVar),
    DEF_2("om-putString",        om_putString),
    {"om-putSymbol", G0Wother, G1Wother, om_putSymbol, om_putSymbol2, G4Wother},

    DEF_1("om-getApp",           om_getApp),
    DEF_1("om-getEndApp",        om_getEndApp),
    DEF_1("om-getAtp",           om_getAtp),
    DEF_1("om-getEndAtp",        om_getEndAtp),
    DEF_1("om-getAttr",          om_getAttr),
    DEF_1("om-getEndAttr",       om_getEndAttr),
    DEF_1("om-getBind",          om_getBind),
    DEF_1("om-getEndBind",       om_getEndBind),
    DEF_1("om-getBVar",          om_getBVar),
    DEF_1("om-getEndBVar",       om_getEndBVar),
    DEF_1("om-getError",         om_getError),
    DEF_1("om-getendError",      om_getEndError),
    DEF_1("om-getObject",        om_getObject),
    DEF_1("om-getEndObject",     om_getEndObject),

    DEF_1("om-getInt",           om_getInt),
    DEF_1("om-getFloat",         om_getFloat),
    DEF_1("om-getByteArray",     om_getByteArray),
    DEF_1("om-getVar",           om_getVar),
    DEF_1("om-getString",        om_getString),
    DEF_1("om-getSymbol",        om_getSymbol),

    DEF_1("om-getType",          om_getType),

    DEF_1("om-stringToStringPtr",om_stringToStringPtr),
    DEF_1("om-stringPtrToString",om_stringPtrToString),

    {nullptr,  nullptr,  nullptr,  nullptr, nullptr, nullptr}
};

#endif // OPENMATH
