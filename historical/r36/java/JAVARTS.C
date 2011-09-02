/* javarts.c:  Copyright (C) Codemist Ltd., 1996.                       */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#include "javahost.h"
#include "javaops.h"
#include "javaglb.h"

static int32 *println(int32 *spbase)
{   err_printf("%s\n", (char *)spbase[1]);
    return spbase-1;
}
static JavaBuiltin sanitycheck = println;

static Cp_Info Java_PrintStream_constant_pool[1];
static unsigned16 Java_PrintStream_interfaces[1];
static Field_Info Java_PrintStream_fields[1];
static Method_Info Java_PrintStream_methods[1] =
{   /* access_flags */ ACC_NATIVE,
    /* name_index */ 0,
    /* signature_index */ 0,
    /* attributes_count; */ 2,
    /* attributes; */ (Attribute_Info *)println
};
static Attribute_Info Java_PrintStream_attributes[1];

ClassFile java_PrintStream = 
{
    /* access_flags */ 0,
    /* this_class */ 0,
    /* super_class */ 0,

    /* constant_pool_count */ 0,
    /* interfaces_count */ 0,
    /* fields_count */ 1,          /* out */
    /* methods_count */ 1,	   /* outs */
    /* attributes_count */ 0,

    /* constant_pool */ Java_PrintStream_constant_pool,
    /* interfaces */ Java_PrintStream_interfaces,
    /* fields */ Java_PrintStream_fields,
    /* methods */ Java_PrintStream_methods,
    /* attributes */ Java_PrintStream_attributes
};
