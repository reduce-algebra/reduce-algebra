/*
 * Trace support for machine code stuff.
 * Only useful for 64-bit systems (at present)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>


#include <unistd.h>

//
// The next few functions read values of various widths from
// an address, or set read_ok to 0 and return 0. They are used in
// debug printing so that if bad pointers arise the result can
// still be some controlled output rather than an abort.
//

static int read_ok;

#ifdef __WIN32__

// At present (at least) I do not know a good way to see if a memory
// address can be read without crashing on Winows. There are functions
// such as IsBadReadPtr() which look encouraging, however further
// investigation shows several severe issues with that route:
// (1) It is not thread-safe, in that another thread could cause access
//     rights to a memory block to alter at any time. I am not that
//     worried about such problems at present!
// (2) Windows uses guard pages to implement lazy stack expansion. A
//     use of IsBadReadPtr() that investigated an address that was in a
//     guard page could trigger the trap, but then not reset it, so that
//     subsequent need for stack expansion could result in a fatal error.
//     Arbitrary other parts of library code may also use guard pages that
//     might be put into non-standard states by use of IsBadReadPrt().
//     This is potentially severe, and really to be sensible the function
//     should not have side effects.

#include <windows.h>

static int safe_read_byte(void *p)
{   if (IsBadReadPtr(p, 1))
    {   read_ok = 0;
        return 0;
    }
    read_ok = 1;
    return *(const char *)p;
}

static int safe_read_hw(void *p)
{   if (IsBadReadPtr(p, 2))
    {   read_ok = 0;
        return 0;
    }
    read_ok = 1;
    return *(const int16_t *)p;
}

static int32_t safe_read_int32(void *p)
{   if (IsBadReadPtr(p, 4))
    {   read_ok = 0;
        return 0;
    }
    read_ok = 1;
    return *(const int32_t *)p;
}

static int64_t safe_read_int64(void *p)
{   if (IsBadReadPtr(p, 8))
    {   read_ok = 0;
        return 0;
    }
    read_ok = 1;
    return *(const int64_t *)p;
}

#else

// For systems other than Windows I will exploit an expectation that
// write() returns with a nice error code if the buffer it is given is not
// accessible. I will write to /dev/random because doing so ought to be
// pretty harmless.
// I wonder if the use of write() here could have the adverse effects
// on guard pages ort suchlike here as it could on Windows?

#include <fcntl.h>

static int randfd = -1;

static void prepare_randfd()
{   if (randfd == -1)
    {   randfd = open("/dev/random", O_RDWR);
        if (randfd == -1)
        {   fprintf(stderr, "Unable to open /dev/rand\n");
            exit(1);
        }
    }
    read_ok = 0;
}

static int safe_read_byte(void *p)
{   prepare_randfd();
    if (write(randfd, p, 1) == -1 &&
        errno == EFAULT) return 0; /* Failure case */
    read_ok = 1;
    return *(const char *)p;
}

static int safe_read_hw(void *p)
{   prepare_randfd();
    if (write(randfd, p, 2) == -1 &&
        errno == EFAULT) return 0; /* Failure case */
    read_ok = 1;
    return *(const int16_t *)p;
}

static int32_t safe_read_int32(void *p)
{   prepare_randfd();
    if (write(randfd, p, 4) == -1 &&
        errno == EFAULT) return 0; /* Failure case */
    read_ok = 1;
    return *(const int32_t *)p;
}

static int64_t safe_read_int64(void *p)
{   prepare_randfd();
    if (write(randfd, p, 8) == -1 &&
        errno == EFAULT) return 0; /* Failure case */
    read_ok = 1;
    return *(const int64_t *)p;
}

#endif

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

#define TAGOF(a) ((int)((uint64_t)(a) >> 56) & 0xff)
#define INFOF(a) (((uint64_t)(a) << 8) >> 8)
#define CAR(a)   (((uint64_t *)INFOF(a))[0])
#define CDR(a)   (((uint64_t *)INFOF(a))[1])

int iscons(uint64_t a)
{   return (TAGOF(a) == TAG_PAIR);
}

void lisp_print(uint64_t a)
{   int tag = TAGOF(a);
    uint64_t v = INFOF(a);
    int64_t *q;
    int ch;
    switch (tag)
    {
    case TAG_POSINT: // posint
        fprintf(stderr, "%" PRId64, a);
        break;
    case TAG_STRING: // string
        safe_read_int64((void *)v);
        if (read_ok) 
        {   ch = 1 + (int)CAR(a);
            fprintf(stderr, "\"%.*s\"", ch, (char *)(v + 8));
        }
        else fprintf(stderr, "\"?BAD\"");
        break;
    case TAG_PAIR: // pair
        ch = '(';
        while (iscons(a))
        {   safe_read_int64((void *)INFOF(a));
            if (!read_ok)
            {   fprintf(stderr, "?BADCONS?");
                break;
            }
            putc(ch, stderr);
            ch = ' ';
            lisp_print(CAR(a));
            a = CDR(a);
        }
        safe_read_int64((void *)INFOF(a));
        if (!read_ok) break;
        fprintf(stderr, " . ");
        lisp_print(a);
        putc(')', stderr);
        break;
    case TAG_NEGINT: // negint
        fprintf(stderr, "%" PRId64, (int64_t)a);
        break;
    case TAG_ID: // id
        fprintf(stderr, "ID%" PRIx64, a);
        lisp_print(((intptr_t *)&_symnam)[INFOF(a)]);
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

