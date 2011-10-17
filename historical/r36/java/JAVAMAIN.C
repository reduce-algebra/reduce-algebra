/* javamain.c:  Copyright (C) Codemist Ltd., 1996.                      */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <setjmp.h>
#include "machine.h"
#include "tags.h"
#undef IGNORE
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#include "javahost.h"
#include "javaglb.h"
/* #include "javatype.h" */

#include <winsock.h>

int debugging;

void jdebug(char *fmt, ...)
{    va_list ap;
     char buffer[256];
     va_start(ap, fmt);
     vsprintf(buffer, fmt, ap);
     va_end(ap);
     err_printf("CJ-debug: %s\n", buffer);
}

jmp_buf java_exit;

void jsyserr(char *fmt, ...)
{    va_list ap;
     char buffer[256];
     va_start(ap, fmt);
     vsprintf(buffer, fmt, ap);
     va_end(ap);
     err_printf("\nFatal Codemist-Java error: %s\n", buffer);
     longjmp(java_exit, 1);
}

void *jmalloc(unsigned32 n)
{   void *p;
    if (n == 0) return 0;
    p = malloc(n);
    if (p == 0) jsyserr("out of memory");
    return p;
}

static void dbg_set(char *p)
{   for (;;) switch (*p++)
    {
case 0:     return;
case 'c':   if (isdigit(*p)) debugging |= 1 << (*p-'0');
            break;
    }
}

int JAVAmain(int argc, char *argv[])
{   ClassFile *p = 0;
    int seen = 0;
    int i;
    debugging = 0;
    for (i = 1; i<argc; i++)
    {   char *a = argv[i];
        if (a[0] == '-') switch (a[1])
        {
case 'q':   dbg_set(&a[2]); break;
default:    err_printf("Unknown option %s\n", a); break;
        }
        else
        {   p = rdClassFile(a), seen++;
        }
    }
    if (!setjmp(java_exit))
    {   if (!seen) err_printf("usage: %s [-<opt>] file.java\n", argv[0]);
        else if (p) javaint(p);
    }
    return 0;
}

void process_java_file(FILE *f)
{
    ClassFile *p;
    p = rdClassFILE1(f, "<from Lisp>");
    if (p && !setjmp(java_exit)) javaint(p);
    err_printf("exiting from Java sub-system\n");
}

Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    return onevalue(nil);
}

Lisp_Object MS_CDECL java1(Lisp_Object env, Lisp_Object a)
{
    Lisp_Object nil = C_nil;
    return onevalue(nil);
}

Lisp_Object MS_CDECL java2(Lisp_Object env, Lisp_Object a, Lisp_Object b)
{
    Lisp_Object nil = C_nil;
    return onevalue(nil);
}

Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    return onevalue(nil);
}

Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    return onevalue(nil);
}



/* end of javamain.c */
