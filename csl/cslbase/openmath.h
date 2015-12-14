// openmath.h                                 Copyright (C) 2015 NAG Ltd.

#ifndef header_openmath_h
#define header_openmath_h



/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
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
// OpenMath primitives map to Lisp objects in the following way:
//
// OpenMath             Lisp
// --------             ----
// 32 bit integer       integer
// big integer          integer
// 64 bit float         real
// byte array           vector of bytes
// variable             symbol
// string               string
// symbol               OMS cd:="cdname" name:="symbolname" (Lisp properties).
//
// <OMA>                (OMA ...)
//   ...
// </OMA>
//
// <OMATTR>             (OMATTR ...)
//   <OMATP>            (OMATP ...)
//      ...
//   </OMATP>
//   obj
// </OMATTR>
//
// <OMBIND>             (OMBIND ...)
//   binder
//   <OMBVAR>           (OMBVAR ...)
//     bvars
//   </OMBVAR>
//   obj
// </OMBIND>
//
// <OME>                (OME ...)
//   ...
// </OME>
//
// <OMOBJ>              (OMOBJ ...)
//   ...
// </OMOBJ>
//


//
// OpenMath / Lisp conversion functions.
//

extern OMdev            om_toDev(LispObject obj);
extern LispObject       om_fromDev(OMdev dev);
extern OMstatus         om_toStatus(LispObject obj);
extern LispObject       om_fromStatus(OMstatus status);
extern OMencodingType   om_toEncodingType(LispObject obj);
extern LispObject       om_fromEncodingType(OMencodingType enc);
extern char *           om_toBigNumStr(LispObject obj);
extern LispObject       om_fromBigNumStr(char *data, int len, int sign, OMbigIntType fmt);
extern OMconn           om_toConn(LispObject obj);
extern LispObject       om_fromConn(OMconn conn);
extern char **          om_toCString(LispObject obj);
extern LispObject       om_fromCString(char **str);
extern LispObject       om_lispStringFromCString(LispObject cstr);
extern LispObject       om_cStringFromLispString(LispObject lstr);

//
// OpenMath Device manipulation functions.
//

extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStrDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);


//
// OpenMath Connection manipulation functions.
//

extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDev(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDev(LispObject nil, LispObject lconn);


//
// OpenMath client/server functions.
//

extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
// TODO: prototypes for the other functions from OMconn.h


//
// OpenMath Device input / output functions.
//

extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);

extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);

extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);

extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);

extern LispObject om_getType(LispObject nil, LispObject ldev);


extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);

#endif // header_openmath_h

// end of openmath.h
