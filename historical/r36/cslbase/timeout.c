/* timeout.c                  Copyright (C) 1997 Codemist Ltd */

/*
 * Support code for demo version locking, invoked (generally) as a result
 * of macros defined in "timeout.h".  If TIMEOUT is not defined this module
 * will have no contents.
 */

/* Signature: 049097bf 31-May-1997 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "entries.h"

#ifdef TIMEOUT
#include "timeout.h"
#endif


/* end of timeout.c */


