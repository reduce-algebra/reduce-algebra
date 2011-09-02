/*  xdrfuns.c                                 Copyright (C) 1995 NAG Ltd */

/*
 * Functions to support reading and writing of objects in XDR format.
 *
 * Version 1.0   September 1995 
 *
 * Author: Mike Dewar
 *
 */

/* Signature: 4bbe58eb 08-Apr-2002 */

#include <stdio.h>
#ifdef AIX3
#include <sys/select.h>
#endif

/*
 * What I really mean here is ifdef(UNIX), but we don't know that until 
 * machine.h is included.  To simplify matters I'll just check to see if
 * we seem to be flagged as some version of Windows, or if we are
 * are using a Windows compiler...  Including machine.h earlier causes
 * some problems on the RS6000. This latter issue is what really needs
 * mending but I do not have an RS6000 at hand to try just now...
 * [ACN updating some comments of MCD]
 */


/* My changed version: */
#ifndef _WINDOWS
#ifndef WINDOWS_NT
#ifndef __WATCOMC__
#include <rpc/rpc.h>
#endif
#endif
#endif

#include <stdarg.h>
#include <ctype.h>

/* These are defined by the rpc code on the alpha */
#define int32 csl_int32
#define int64 csl_int64

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "stream.h"
#include "arith.h"

#ifdef UNIX

Lisp_Object LxdrOpen(Lisp_Object nil, Lisp_Object f, Lisp_Object d)
{
  XDR xdrs;
  Lisp_Object lxdr;

  /*
   * First argument must be an open stream. Since CCL streams are all
   * bi-directional we get the intended direction from the second argument.
   */
  if (!is_stream(f)) return aerror("xdrOpen");

  xdrstdio_create(&xdrs,stream_file(f),(d == lisp_true)?XDR_ENCODE:XDR_DECODE);

  /* Copy the XDR structure into a string to avoid alignment problems.  */
  lxdr = Lsmkvect(nil,fixnum_of_int(sizeof(XDR))); 
  memcpy(&celt(lxdr,0),&xdrs,sizeof(XDR));

  return onevalue(lxdr);
}

#define XW(x,u) ( (!x) ? aerror1("Bad XDR write for: ",u) : u )

Lisp_Object LxdrWrite(Lisp_Object nil, Lisp_Object lxdr,Lisp_Object u)
{
  XDR xdrs;

  /* Copy the XDR structure out of a CCL string.  */
  memcpy(&xdrs,&celt(lxdr,0),sizeof(XDR));

  /*
   * We include the bignum case since fixnums in CCL are 28 bits and we would
   * like to support 32 bit integers here.
   */
  if (is_fixnum(u) )
  { int32 temp = int_of_fixnum(u);
    return XW(xdr_int(&xdrs,&temp), u);
  }
  else if (is_float(u) )
  { double temp = float_of_number(u);
    return XW(xdr_double(&xdrs,&temp), u);
  }
  else if (is_numbers(u) && is_bignum(u) )
  { int32 temp=thirty_two_bits(u);
    return XW(xdr_int(&xdrs,&temp), u);
  }
  else if (is_vector(u) && type_of_header(vechdr(u)) == TYPE_STRING)
  { int32 len = length_of_header(vechdr(u))-4;
    char *temp=&celt(u,0);
    return XW(xdr_string(&xdrs,&temp,len),u);
  }
  else if (is_vector(u) )
  { int32 count, len = thirty_two_bits(Llength(nil,u));
    Lisp_Object v = elt(u,0);
    /*
     * Mimic the way that xdr_array works by writing the length of the
     * array first.
     */
    if (!xdr_int(&xdrs,&len)) aerror1("XDR Error writing length of:",u);

    /*
     * Although Common Lisp Vectors are not homogeneous, C vectors are,
     * so we will assume that u is homogeneous and only test the type
     * of the first element.  
     */
    if (is_float(v) )
    { double temp;
      for (count=0 ; count < len ; ++count)
      { temp = float_of_number(elt(u,count));
        if (!xdr_double(&xdrs,&temp))
          aerror1("Bad XDR write for Double-Float vector element: ",v);
      }
      return(u);
    }
    else if (is_fixnum(v) || ( is_numbers(v) && is_bignum(v) ) )
    { int32 temp;
      for (count=0 ; count < len ; ++count)
      { temp = thirty_two_bits(elt(u,count));
        if (!xdr_int(&xdrs,&temp))
          aerror1("Bad XDR write for integer vector element: ",v);
      }
      return(u);
    }
    else
      aerror1("XDR cannot handle a vector containing:",v);
  }
  else
    aerror1("XDR cannot handle:",u);
}

/* This checks a 32 bit integer's value and returns it as either a fixnum
   or a bignum. */
#define int2ccl(i) (i > -268435455 && i < 268435456) ? fixnum_of_int(i) : make_one_word_bignum(i)

Lisp_Object LxdrRead(Lisp_Object nil, Lisp_Object lxdr,Lisp_Object u)
{
  XDR xdrs;
  int temp;

  /* Copy the XDR structure out of a CCL string.  */
  memcpy(&xdrs,&celt(lxdr,0),sizeof(XDR));

  if (is_fixnum(u) || (is_numbers(u) && is_bignum(u) ) )
  { int32 temp;
    if (!xdr_int(&xdrs,&temp)) aerror("Integer XDR read");
    return onevalue(int2ccl(temp));
  }
  else if (is_float(u) )
  { double temp;
    if (!xdr_double(&xdrs,&temp)) aerror("Double-Float XDR read");
    return onevalue(make_boxfloat(temp,TYPE_DOUBLE_FLOAT));
  }
  else if (is_vector(u) && type_of_header(vechdr(u)) == TYPE_STRING)
  { char *temp=NULL;
    /* Value for maximum length of a string is fairly arbitrary! */
    if (!xdr_string(&xdrs,&temp,16777216)) aerror("String XDR read");
    return onevalue(make_string(temp));
  }
  else if (is_vector(u) )
  { int32 count, len;
    Lisp_Object new, v = elt(u,0);
    /* xdr_array writes the length of the array first. */
    if (!xdr_int(&xdrs,&len)) aerror1("XDR Error reading length of:",u);

    /* Create the new vector */
    new = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, 4*len+4);
    /* vectors must pad to an even number of words */
    if ((len & 1) == 0) elt(new,len) = nil;

    /*
     * Although Common Lisp Vectors are not homogeneous, C vectors are,
     * so we will assume that u is homogeneous and only test the type
     * of the first element.  
     */
    if (is_float(v) )
    { double temp;
      for (count=0 ; count < len ; ++count)
      { if (!xdr_double(&xdrs,&temp)) aerror("Double-Float vector XDR read");
        elt(new,count) = make_boxfloat(temp,TYPE_DOUBLE_FLOAT);
      }
    }
    else if ( is_fixnum(v) || ( is_numbers(v) && is_bignum(v) ))
    { int32 temp;
      for (count=0 ; count < len ; ++count)
      { if (!xdr_int(&xdrs,&temp)) aerror("Integer vector XDR read");
        elt(new,count) = int2ccl(temp);
      }
    }
    else
      aerror1("XDR cannot handle a vector containing:",v);
    return onevalue(new);
  }
  else
    aerror1("XDR cannot handle:",u);

}
#else /* UNIX */ 

Lisp_Object LxdrOpen(Lisp_Object nil, Lisp_Object f, Lisp_Object d)
{
  aerror("Attempt to call xdr-open on non-Unix platform");
  return nil;
}

Lisp_Object LxdrWrite(Lisp_Object nil, Lisp_Object lxdr, Lisp_Object u)
{
  aerror("Attempt to call xdr-write on non-Unix platform");
  return nil;
}

Lisp_Object LxdrRead(Lisp_Object nil, Lisp_Object lxdr, Lisp_Object u)
{
  aerror("Attempt to call xdr-read on non-Unix platform");
  return nil;
}


#endif /* UNIX */

setup_type const xdr_setup[] =
{
    {"xdr-open",	too_few_2,	LxdrOpen,	wrong_no_2},
    {"xdr-write",	too_few_2,	LxdrWrite,	wrong_no_2},
    {"xdr-read",	too_few_2,	LxdrRead,	wrong_no_2},
    {NULL,              0,              0,              0}
};
