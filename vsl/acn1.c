/*
 * Trace support for machine code stuff.
 * Only useful for 64-bit systems (at present)
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

/*
 * In principle PSL could use different tag values on each architecture.
 * Well it will certainly do different things on 32 and 64-bit ones. But
 * It looks as if all 64-bit systems match what I am using here.
 */

#define TAG_POSINT    0
#define TAG_FIXNUM    1
#define TAG_BIGNUM    2
#define TAG_FLOATNUM  3
#define TAG_STRING    4
#define TAG_BYTES     5
#define TAG_HALFWORDS 6
#define TAG_WORDS     7
#define TAG_VECTOR    8
#define TAG_PAIR      9

#define TAG_NEGINT    0xff
#define TAG_ID        0xfe
#define TAG_UNBOUND   0xfd

extern intptr_t **symnam, **_symnam;

int iscons(uint64_t a)
{   return ((a >> 56) & 0xff) == TAG_PAIR;
}

void lisp_print(uint64_t a)
{   int tag = (a >> 56) & 0xff;
    uint64_t v = a - ((uint64_t)tag << 56);
    int ch;
    switch (tag)
    {
    case TAG_POSINT: // posint
        fprintf(stderr, "%" PRId64, a);
        break;
    case TAG_STRING: // string
        ch = 1 + (int)*((intptr_t *)((a<<8)>>8));
        fprintf(stderr, "\"%.*s\"", ch, (char *)(v + 8));
        break;
    case TAG_PAIR: // pair
        ch = '(';
        while (iscons(a))
        {   putc(ch, stderr);
            ch = ' ';
            lisp_print(((intptr_t *)((a<<8)>>8))[0]);
            a = ((intptr_t *)((a<<8)>>8))[1];
        }
        fprintf(stderr, " . ");
        lisp_print(a);
        putc(')', stderr);
        break;
    case TAG_NEGINT: // negint
        fprintf(stderr, "%" PRId64, (int64_t)a);
        break;
    case TAG_ID: // id
        fprintf(stderr, "ID%" PRIx64, a);
        lisp_print(((intptr_t *)&_symnam)[(a<<8)>>8]);
        break;
    default:
        fprintf(stderr, "??%" PRIx64, a);
        break;
    }
}

const void *acn1(const char *fmt, void *a, void *b, void *c)
{   void *v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    void **vp = v;
    int ch;
    void *arg;
    while ((ch = *fmt++) != 0)
    {   if (ch != '%')
        {   putc(ch, stderr);
            continue;
        }
        if ((ch = *fmt++) == 0) break;
        switch (ch)
        {
        case '%':
            putc(ch, stderr);
            break;
        default:
            arg = *vp++;
            fprintf(stderr, "%p :", arg);
            lisp_print((uint64_t)arg);
            break;
        }
    }
    fprintf(stderr, "\n");
    fflush(stderr);
    return fmt;
}

const void *_acn1(const char *fmt, void *a, void *b, void *c)
{   return acn1(fmt, a, b, c);
}

/* end of acn1.c */

