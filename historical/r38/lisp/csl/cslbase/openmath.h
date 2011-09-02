/* openmath.h                                 Copyright (C) 1998 NAG Ltd. */

#ifndef header_openmath_h
#define header_openmath_h

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 5537ffe6 08-Apr-2002 */


/*
 * OpenMath primitives map to Lisp objects in the following way:
 *
 * OpenMath				Lisp
 * --------				----
 * 32 bit integer		integer
 * big integer			integer
 * 64 bit float			real
 * byte array			vector of bytes
 * variable				symbol
 * string				string
 * symbol				OMS cd:="cdname" name:="symbolname" (Lisp properties).
 * 
 * <OMA>				(OMA ...)
 *   ...
 * </OMA>
 * 
 * <OMATTR>				(OMATTR ...)
 *   <OMATP>			(OMATP ...)
 *   	...
 *   </OMATP>
 *   obj
 * </OMATTR>
 * 
 * <OMBIND>				(OMBIND ...)
 *   binder
 *   <OMBVAR>			(OMBVAR ...)
 *     bvars
 *   </OMBVAR>
 *   obj
 * </OMBIND>
 *
 * <OME>				(OME ...)
 *   ...
 * </OME>
 *
 * <OMOBJ>				(OMOBJ ...)
 *   ...
 * </OMOBJ>
 */


/*
 * OpenMath / Lisp conversion functions.
 */

extern OMdev			om_toDev(Lisp_Object obj);
extern Lisp_Object		om_fromDev(OMdev dev);
extern OMstatus			om_toStatus(Lisp_Object obj);
extern Lisp_Object		om_fromStatus(OMstatus status);
extern OMencodingType	om_toEncodingType(Lisp_Object obj);
extern Lisp_Object		om_fromEncodingType(OMencodingType enc);
extern char *			om_toBigNumStr(Lisp_Object obj);
extern Lisp_Object		om_fromBigNumStr(char *data, int len, int sign, OMbigIntType fmt);
extern OMconn			om_toConn(Lisp_Object obj);
extern Lisp_Object		om_fromConn(OMconn conn);
extern char **			om_toCString(Lisp_Object obj);
extern Lisp_Object		om_fromCString(char **str);
extern Lisp_Object		om_lispStringFromCString(Lisp_Object cstr);
extern Lisp_Object		om_cStringFromLispString(Lisp_Object lstr);

/*
 * OpenMath Device manipulation functions.
 */

extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStrDev(Lisp_Object env, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);


/*
 * OpenMath Connection manipulation functions.
 */

extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDev(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDev(Lisp_Object nil, Lisp_Object lconn);


/*
 * OpenMath client/server functions.
 */

extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
/* TODO: prototypes for the other functions from OMconn.h */


/*
 * OpenMath Device input / output functions.
 */

extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);

extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);

extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);

extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);

extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);


extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);

#endif /* header_openmath_h */

/* end of openmath.h */
