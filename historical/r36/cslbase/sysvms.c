#error No longer supported
/*  sysvms.c                       Copyright (C) 1989-92 Codemist Ltd */

/*
 * Things that may usefully be rewritten in assembly code, or
 * that are heavily dependent on some particular computer
 * architecture or operating system.  This file may need some
 * extension or adjustment (especially as regards optional compilation)
 * when new computers are tried.
 *
 */

/* Signature: 0544d1a1 03-Feb-1999 */

#include "machine.h"

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "tags.h"
#include "externs.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

static void get_home_directory(char *b, int length);
static void get_users_home_directory(char *b, int length);

#include "filename.c"


/*
 * This is a dummy definition of get_truename, here so that everything
 * will link. Both the calling convention used here and the exact
 * meaning and implementation may be under gentle review!
 */

char *get_truename(char *filename, char *old, size_t n)
{
    char *w;
    process_file_name(filename, old, n);
    if (*filename == 0)
    {   aerror("truename");
        return NULL;
    }
    w = (char *)malloc(1+strlen(filename));
    if (w == NULL) return w;
    strcpy(w, filename);
    return w;
}

char *my_getenv(char *s)
{
    return getenv(s);
}

int my_system(char *s)
{
    return system(s);
}

/*
 * I do not expect that the following will work exactly unchanged
 * on all possible versions of Unix - e.g. header file names may need
 * altering and suchlike mess.  But the idea should be reasonable and
 * changes when needed ought to be small.
 */

static void get_home_directory(char *b, int length)
{
    strcpy(b, getenv("HOME"));  /* Probably works with most shells */
}

static void get_users_home_directory(char *b, int length)
{
    strcpy(b, ".");    /* use current directory if getpwnam() no available */
}

/*
 * This is a BSD-style clock facility, possibly giving a resolution of
 * only 1/100 second.  I believe that Portable Standard Lisp typically
 * reports user time, which is why I do this.  A further nasty here
 * is that I am probably compiling this file in ANSI mode, and on
 * at least some computers this makes #includ <sys/times.h> fairly
 * ineffective (ugh), so I declare all the structures and functions I
 * want directly (ugh ugh) and hope they are as needed.  Consider this
 * when you port to a new machine.
 */

unsigned long int read_clock(void)
{
    struct my_tms {
        clock_t tms_utime;
        clock_t tms_stime;
        clock_t tms_cutime;
        clock_t tms_cstime;
        } tmsbuf;
    extern void times(/*struct my_tms * */);
    times(&tmsbuf);
/*
 * Another dodgy assumption here - that times() reports in units of 1/100
 * second or 1/60 sec (as set up in the UNIX_TIMES macro). The curious
 * division here either does t/10/10 or t/6/10 but in either case ought not
 * to mangle the rounding too much.
 */
    return (tmsbuf.tms_utime*((10*UNIX_TIMES)/100))/10;
}

int batchp()
{
    return !isatty(fileno(stdin));
}


/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char image[LONGEST_LEGAL_FILENAME];
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    if (argc > 0 && argv[0] != NULL)
    {   int i;
        strcpy(image, argv[0]);
        w = &image;
        i = strlen(w);
        while (i > 0 && w[i] != ']') i--;
        if (i <= 0) 
        {   printf("argv[0] contains no ']' character\n");
            exit(EXIT_FAILURE);
        }
        w[i] = '.';
        do i++; while (w[i] != '.');
        sprintf(&w[i], "img]");
    }
    else sprintf(image, "[cslimg]");

/*
 * I copy from local vectors into malloc'd space to hand my
 * answer back.
 */
    w = (char *)malloc(1+strlen(image));
/*
 * The error exit here seem unsatisfactory...
 */
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        exit(EXIT_FAILURE);
    }
    strcpy(w, image);
    return w;
}

int truncate_file(FILE *f, long int where)
{
    if (fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  /* Returns zero if successs */
}

/* end of sysvms.c */

