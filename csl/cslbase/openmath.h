// openmath.h                                    Copyright (C) 2017 NAG Ltd

#ifndef header_openmath_h
#define header_openmath_h



/**************************************************************************
 * Copyright (C) 2017, Codemist and NAG Ltd.             A C Norman       *
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

extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDev(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDev(LispObject env, LispObject lconn);


//
// OpenMath client/server functions.
//

extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
// TODO: prototypes for the other functions from OMconn.h


//
// OpenMath Device input / output functions.
//

extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);

extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);

extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);

extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);

extern LispObject om_getType(LispObject env, LispObject ldev);


extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);

#endif // header_openmath_h

// end of openmath.h
