/*
 * Trace support for machine code stuff.
 */

#include <stdio.h>
#include <string.h>

void *acn1(const char *fmt, void *a, void *b, void *c)
{   fprintf(stderr, fmt, a, b, c);
    fprintf(stderr, "\n");
    fflush(stderr);
    return (void *)(fmt + strlen(fmt) + 1);
}

void *_acn1(const char *fmt, void *a, void *b, void *c)
{   return acn1(fmt, a, b, c);
}

/* end of acn1.c */

