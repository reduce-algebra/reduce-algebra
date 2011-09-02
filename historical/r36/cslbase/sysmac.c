
/*  sysmac.c                       Copyright (C) 1989-92 Codemist Ltd */

/*
 * Macintosh system-specific stuff
 */

/* Signature: 6546de39 07-Mar-2000 */

#include "machine.h"

#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include "tags.h"
#include "externs.h"

#include <sysequ.h>
#include <unix.h>
#include <files.h>
#include <unix.h>
#include <retrace.h>
#include <timer.h>

#undef nil          /* #define'd by Think C headers but not wanted (by me) */

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
    return 0;       /* Not available - sorry! */
}

static void get_home_directory(char *b, int length)
{
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, ":");     /* Not satisfactory */
}

static void get_users_home_directory(char *b, int length)
{
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, ":");     /* Not satisfactory */
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
/*
 * For the Macintosh I use the data fork of the application image as
 * a place to store useful stuff.
 */
    WDPBRec pb1;
    CInfoPBRec pb2;
    int i, j, r, p = LONGEST_LEGAL_FILENAME;
    long id;
    pgmname[--p] = 0;
    sprintf(image, "%#s", CurApName);       /* name of current application */
    strcpy(image, program_name);
    i = strlen(image);
    p -= i;
    memcpy(&pgmname[p], image, i);          /* copy to the end of a buffer */
    pb1.ioNamePtr = (unsigned char *)image;
    PBHGetVolSync(&pb1);                    /* find current working dir & volume */
    id = pb1.ioWDDirID;                     /* working directory identifier      */
    while (id != 0)
    {   pb2.dirInfo.ioFDirIndex = -1;       /* use directory ID, not file name/index */
        pb2.dirInfo.ioVRefNum = pb1.ioVRefNum;  /* look in this volume               */
        pb2.dirInfo.ioDrDirID = id;             /* get info about this directory     */
        pb2.dirInfo.ioNamePtr = (unsigned char *)image;
        r = PBGetCatInfoSync(&pb2);         /* Read catalogue - find name & parent   */
        if (r != 0) break;                  /* failed - must be at top of tree       */
        id = pb2.dirInfo.ioDrParID;         /* go on up to parent directory          */
        i = image[0] & 0xff;                /* length of name of this directory      */
        pgmname[--p] = ':';
        p -= i;
        if (p < 10)
        {   fprintf(stderr, "\nPlease re-install this package nearer the top of\n");
            fprintf(stderr, "your directory hierarchy.  It will not work this far down\n");
            abort();
        }
        memcpy(&pgmname[p], &image[1], i);  /* stick names together with ':'s        */
    }
    strcpy(image, &pgmname[p]);             /* Put complete name in convenient place */

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
    return SetEOF(fileno(f), where);  /* Returns zero if successs */
}

#ifdef TICK_STREAM

void accept_tick(void)
{
/*
 * This is where I can put things that need to be done regularly.
 * This will need to involve prodding the window manager etc etc.
 * At present I do NOTHING...
 */
    return;
}


#ifdef USE_VBL

static VBLTask VBL_control_block;

static pascal void deal_with_tick(void)
{
/*
 * This way of recovering register a5 was OK before the multi-finder,
 * but is UNSATISFACTORY now.  It is proper to use the time manager
 * instead of VBL, but only recent versions of the time manager are any good
 * so it is a bit of a mess.
 */
    asm { move.l a5, -(sp)
          movea.l CurrentA5, a5 }
    VBL_control_block.vblCount = 5;
    if (tick_pending == 0)
    {
        if (already_in_gc) tick_on_gc_exit = YES;
        else
        {   Lisp_Object nil = C_nil;
            CSLbool xxx = NO;
            if (exception_pending()) flip_exception(), xxx = YES;
            tick_pending = YES;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
            if (xxx) flip_exception();
        }
    }
    asm { movea.l (sp)+, a5 }
    return;
}

void remove_ticker(void)
{
    VRemove((QElemPtr)&VBL_control_block);
}

void add_ticker(void)
{
    VBL_control_block.qType = vType;
    VBL_control_block.vblAddr = deal_with_tick;
    VBL_control_block.vblCount = 1;
    VBL_control_block.vblPhase = 0;
    VInstall((QElemPtr)&VBL_control_block);
}

#else /* USE_VBL */

typedef struct xTMTask
{
    struct TMTask a;
    long int a5save;
} xTMTask;

static pascal void do_tick(void)
{
    QElemPtr w;
    long int savea5;
    asm { move.l a5, savea5
          move.l offsetof(xTMTask, a5save)(a1), a5
          move.l a1, w }
    if (tick_pending == 0)
    {
        if (already_in_gc) tick_on_gc_exit = YES;
        else
        {   Lisp_Object nil = C_nil;
            CSLbool xxx = NO;
            if (exception_pending()) flip_exception(), xxx = YES;
            tick_pending = YES;
            saveheaplimit = heaplimit;
            heaplimit = fringe;
            savevheaplimit = vheaplimit;
            vheaplimit = vfringe;
            savecodelimit = codelimit;
            codelimit = codefringe;
            savestacklimit = stacklimit;
            stacklimit = stackbase;
            if (xxx) flip_exception();
        }
    }
    PrimeTime(w, 1000);
    asm { move.l savea5, a5 }
    return;    
}

static xTMTask ticker;

void remove_ticker(void)
{
    RmvTime((QElemPtr)&ticker);
}

void add_ticker()
{
    ticker.a.tmAddr = do_tick;
    ticker.a.tmCount = 0;
    ticker.a.tmWakeUp = 0;
    ticker.a.tmReserved = 0;
    asm { move.l a5,ticker.a5save }
    InsTime((QElemPtr) &ticker);
    PrimeTime((QElemPtr) &ticker, 1000);
}

#endif /* USE_VBL */

#endif /* TICK_STREAM */

/* end of sysmac.c */

