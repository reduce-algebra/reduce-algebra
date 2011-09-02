
/*  sysdos.c                       Copyright (C) 1989-99 Codemist Ltd */

/*
 * MSDOS low-level support.  This file supports Watcom C using dos4gw.
 * It could probably be modified fairly easily for use with other DOS
 * compilers.
 */

/* Signature: 104a1b84 07-Mar-2000 */

#include "machine.h"

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <errno.h>
#include <time.h>
#include <math.h>

#include "tags.h"
#include "externs.h"
#include "read.h"
#include "cslerror.h"
#include "sys.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

#include <io.h>
#include <dos.h>
#include <sys\stat.h>
#include <direct.h>

#ifdef WINDOWS_NT
#include <windows.h>
#endif


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

#include <sys\types.h>
#include <direct.h>

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef _MSC_VER
    return _mkdir(filename);
#else
    return mkdir(filename);
#endif
}

int change_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef _MSC_VER
    if (_chdir(filename))
#else
    if (chdir(filename))
#endif
    {   char err_buf[LONGEST_LEGAL_FILENAME+100];
        switch (errno)
        {
    case ENOENT:  
            sprintf(err_buf,"The directory %s does not exist.",filename);
            break;
    default:
            sprintf(err_buf,"Cannot change directory to %s.",filename);
            break;
        }
        aerror0(err_buf);
        return 1;
    }
    else return 0;
}

int get_current_directory(char *s, int n)
{
#ifdef _MSC_VER
    char *r = _getcwd(s, n);
#else
    char *r = getcwd(s, n);
#endif
    if (r == NULL)
    {   aerror0("cannot get current directory name");
        return 0;
    }
    else return strlen(s);
}

static void remove_files(char *name, int dirp, long int size)
/* Remove a file, or a directory and all its contents */
{
#ifdef _MSC_VER
    if (dirp) _rmdir(name);
#else
    if (dirp) rmdir(name);
#endif
    else remove(name);
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    scan_directory(filename, remove_files);
    return 0;
}

int directoryp(char *filename, char *old, size_t n)
{
#ifdef _MSC_VER
    struct _stat buf;
#else
    struct stat buf;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
#ifdef _MSC_VER
    _stat(filename, &buf);
#else
    stat(filename, &buf);
#endif
#ifdef WINDOWS_NT
    return (GetFileAttributes(filename) == FILE_ATTRIBUTE_DIRECTORY);
#else
    return S_ISDIR(buf.st_mode);
#endif
}

int current_directory(char *s, int n)
{
#ifdef _MSC_VER
    if (_getcwd(s, n) == NULL) return 0;
#else
    if (getcwd(s, n) == NULL) return 0;
#endif
    else return strlen(s);
}

void list_directory_members(char *filename, char *old,
                            size_t n, directory_callback *fn)
{
    process_file_name(filename, old, n);
    scan_files(filename, fn);
}


int file_readable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /* The "correct" way to do this is via stat, but this is much simpler! */
    fp = fopen(filename,"r");
    if (fp == NULL) return 0;
    else 
    {   fclose(fp);
        return 1;
    }
}

int file_writeable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /* The "correct" way to do this is via stat, but this is much simpler! */
    fp = fopen(filename,"a");
    if (fp == NULL) return 0;
    else 
    {   fclose(fp);
        return 1;
    }
}

int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return rename(from_name,to_name);
}

#include <sys\stat.h>  /* Provided with Zortech C and others */

CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
{
#ifdef _MSC_VER
    struct _stat statbuff;
#else
    struct stat statbuff;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return NO;
#ifdef _MSC_VER
    if (_stat(filename, &statbuff) != 0) return NO;
#else
    if (stat(filename, &statbuff) != 0) return NO;
#endif
    strcpy(tt, ctime(&(statbuff.st_mtime)));
    return YES;
}

int my_system(char *s)
{
    int k;
    remove_ticker();
    k = system(s);
    add_ticker();
    return k;
}

char *my_getenv(char *s)
{
/*
 * Case fold for MSDOS
 */
    char uppercase[LONGEST_LEGAL_FILENAME];
    int c;
    char *p = uppercase;
    while ((c = *s++) != 0)
    {   if (islower(c)) c = toupper(c);
/*
 * Yes I do know that ANSI toupper does not need the islower test
 * first - but I have been bitten before by non-ANSI libraries.
 */
        *p++ = c;
    }
    *p = 0;
    s = uppercase;
    return getenv(s);
}

#ifdef WINDOWS_NT
int pipes_today = 1;
int win32s = 0;

FILE *my_popen(char *s, char *d)
{
    return _popen(s, d);
}

void my_pclose(FILE *s)
{
    _pclose(s);
}

#endif

/*
 * MSDOS does not support the idea of home directories for
 * users, so in case anybody still wants to use the notation "~" that
 * would indicate a home directory under Unix I implement something
 * in terms of environment variables.
 */

int get_home_directory(char *b, int len)
{
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

int get_users_home_directory(char *b, int len)
{
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

/*
 * The next bit of mess is jolly - I just want to see if stdin has been
 * redirected to come from a file, i.e. whether I am interactive in some
 * sense.  This may be used to decide what to do about error reports etc.
 * The IDEA seems generic across most systems, but the details vary in
 * frustrating ways.
 */


int batchp()
{
#ifdef WINDOWS_NT
    return 0;
#else
#ifdef __BORLANDC__
    return !isatty(fileno(stdin));
#else
    return !isatty(stdin->_handle);
#endif
#endif
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char image[LONGEST_LEGAL_FILENAME];
    char *w;
/*
 * If the current MSDOS program is called xxx.exe, then I look
 * for a file xxx.img. Well to cope with having both DOS and Windows
 * versions around I will arrange that if the executable is called
 * xxxc.exe then I look for xxx.img.  Ie I expect to call the command
 * line version cslc.exe, or r37c.exe or reducec.exe
 */
    if (argc > 0 && argv[0] != NULL)
    {   char *pgmname = argv[0];
        int len = strlen(pgmname) - 4, i;
/*
 * I expect here that argv[0] will be a fully rooted path to the
 * executable image, ending with the characters ".EXE".  I trim off
 * the last 4 chars and put in ".IMG" instead. If an extension ".exe"
 * is not present I just append ".img".
 */
        if (pgmname[len] != '.' ||
            !isalpha(pgmname[len+1]) ||
            !isalpha(pgmname[len+2]) ||
            !isalpha(pgmname[len+3])) len += 4;
        if (tolower(pgmname[len-1]) == 'c') len--;
        sprintf(image, "%.*s.img", len, pgmname);
        i = len;
        while (i>0 && pgmname[i-1] != '\\') i--;
        len -= i;
        sprintf(program_name, "%.*s", len, pgmname+i);
    }
    else sprintf(image, "csl.img");
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

clock_t prev_clock = 0;

#ifdef SOFTWARE_TICKS_PER_SECOND
int32 software_ticks = INITIAL_SOFTWARE_TICKS;
int32 software_tick_count = 0, prev_software_tick_count = 0;
#endif

void accept_tick(void)
{
    clock_t t0 = clock();
#ifdef SOFTWARE_TICKS_PER_SECOND
    software_tick_count++;
#endif
    if (prev_clock == 0 ||
        t0 > prev_clock+2*CLOCKS_PER_SEC)
    {   ensure_screen();
#ifdef SOFTWARE_TICKS_PER_SECOND
        if (prev_clock != 0)
        {   double t1 = (double)(t0-prev_clock)/(double)CLOCKS_PER_SEC;
            double ratio = 
               (double)(software_tick_count - prev_software_tick_count)/t1;
            int32 w;
/*
 * t1 is how long since I was last here, ratio is the number of
 * ticks per second over that time-span.
 */
            ratio = ratio / (double)SOFTWARE_TICKS_PER_SECOND;
            prev_software_tick_count = software_tick_count;
/*
 * Now ratio is the extent by which I was taking ticks too fast.
 * To dampen out my correction I will scale software_ticks by the
 * square root of this.
 */
            ratio = sqrt(ratio);
            w = (int)(1000.0 * ratio);
/*
 * I clamp the correction fator so I never adjust my clock rate by
 * a factor of more than (about) 3.
 */
            if (w > 3000) w = 3000;
            else if (w < 300) w = 300;
/*
 * Furthermore I attempt to keep software_ticks within integer range.
 */
            if (software_ticks < (0x7fffffff/3000) &&
                software_ticks > 50)
                software_ticks = (w*software_ticks)/1000;
        }
#endif
        prev_clock = t0;
    }
    return;
}

#ifdef DOS386
#ifndef OLD_ZORTECH_DOS_EXTENDER
extern int _x32_memlock(void _far *, unsigned int);
extern int _x32_memunlock(void _far *, unsigned int);
#endif
#endif

#ifndef SOFTWARE_TICKS

static int sometimes = 0, lockout = 0;


typedef void __interrupt __far interrupt_handler(void);

static interrupt_handler *original_tick_handler;

/*
 * The next (interrupt) routine MUST be compiled with stack-checking
 * disabled.
 */

static void before_tick()
{
}

static void __interrupt deal_with_tick()
{
/*
 * The basic clock ticks arrive 18.2 per second, but if I
 * respond to ALL of them it seems to hit my performance
 * somewhat.  The main issue is that the frequency with which I
 * accept a tick determines the latency before I respond to ^C,
 * so I now try to ignore 7 out of every 8 basic ticks, so polling
 * about twice per second.
 */
    if ((++sometimes & 0x7) == 0)
    {   if (tick_pending == 0 && lockout == 0)
        {   lockout = 1;
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
            lockout = 0;
        }
    }
    _chain_intr(original_tick_handler);
}

static void after_tick()
{
}

#endif

static CSLbool ticker_active = NO;

void MS_CDECL remove_ticker(void)
{
    if (!ticker_active) return;
#ifndef SOFTWARE_TICKS
    _dos_setvect(0x1c, original_tick_handler);
#endif
    ticker_active = NO;
}

CSLbool sigint_must_longjmp = NO;
jmp_buf sigint_buf;

void MS_CDECL sigint_handler(int code)
{
    CSL_IGNORE(code);
    interrupt_pending = 1;
    signal(SIGINT, sigint_handler);   /* reinstate handler */
    if (sigint_must_longjmp)
    {   sigint_must_longjmp = 0;
        longjmp(sigint_buf, 1);
    }
    return;
}

void add_ticker(void)
{
    if (ticker_active) return;
#ifdef SOFTWARE_TICKS
    countdown = SOFTWARE_TICKS;
#else
/*
 * I take an interrupt 18.2 times per second...
 */
    original_tick_handler = _dos_getvect(0x1c);
    _dos_setvect(0x1c, (interrupt_handler *)deal_with_tick);
#endif /* SOFTWARE_TICKS */
    ticker_active = YES;
}

void poll_for_attn()
{
#ifdef _MSC_VER
    _kbhit();  /* allows ^C to be noticed! */
#else
    kbhit();  /* allows ^C to be noticed! */
#endif
}

/*
 * The following function controls memory allocation policy
 */

int32 ok_to_grab_memory(int32 current)
{
#ifdef COMMON
    return current;
#else
    return 3*current + 2;
#endif
}

#include "fileops.c"

#include "scandir.c"

/* end of sysdos.c */

