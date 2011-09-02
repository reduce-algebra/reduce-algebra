/* headers.h                       Copyright (C) 2005-2007 Codemist Ltd */

#ifndef header_headers_h
#define header_headers_h 1

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

/* Signature: 1ac34a7f 10-Aug-2008 */

/*
 * #include the majority of the header files needed by CSL code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#ifndef UNDER_CE
#include <signal.h>
#endif

#ifndef __cplusplus
#include <setjmp.h>
#endif

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "syscsl.h"
#include "arith.h"
#include "entries.h"
#include "stream.h"
#include "cslread.h"

#ifdef HAVE_FWIN
#include "fwin.h"
#endif

#endif /* this header included already */

/* end of headers.h */

