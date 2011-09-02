/*  sysarm.c                       Copyright (C) 1989-93 Codemist Ltd */

/*
 * Acorn Archimedes-specific code
 */

#error this version is no longer supported. The file is left in case
       it ever proves a useful prototype for anything else.


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


/* Signature: 3896bf7e 08-Apr-2002 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "bbc.h"
#include "akbd.h"
#include "flex.h"
#include "os.h"
#include "wimp.h"
#include "wimpt.h"
#include "werr.h"
#include "win.h"
#include "menu.h"
#define template acorn_template /* To avoid clash with C++ */
#include "template.h"
#include "dbox.h"
#include "txt.h"
#include "saveas.h"
#include "event.h"
#include "res.h"
#include "resspr.h"
#include "baricon.h"
#include "colourtran.h"
#include "xferrecv.h"
#include "xfersend.h"
#include "sprite.h"
#include "msgs.h"

/* #include <swis.h> */
#define Wimp_SendMessage               0x0400e7
#define OS_EvaluateExpression          0x00002d
#define OS_Claim                       0x00001f
#define OS_Release                     0x000020
#define OS_DelinkApplication           0x00004d
#define OS_RelinkApplication           0x00004e
#define Hourglass_On                   0x0406c0
#define Hourglass_Off                  0x0406c1
#define Wimp_ReadSysInfo               0x0400f2

#include "machine.h"
#include "version.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "read.h"
#include "entries.h"

#ifdef TIMEOUT
#include "timeout.h"
#endif

static void get_home_directory(char *b, int length);
static void get_users_home_directory(char *b, int length);

#include "filename.c"

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    return mkdir(filename);
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return NULL;
    return remove(filename);
}

CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
{
    os_filestr b;
    time_t t;
    unsigned int load, exec, w;
    process_file_name(filename, old, n);
    if (*filename == 0) return NO;
    b.action = 5;
    b.name = filename;
    if (os_file(&b) != 0) return NO;
    load = b.loadaddr; exec = b.execaddr;
    if ((load & 0xfff00000) != 0xfff00000) return NO;
    load = load & 0xff;
/* Now I need to divide the datestamp by 100 */
    w = (load << 16) | ((exec >> 16) & 0xffff);
    exec = (exec & 0xffff) | ((w % 100) << 16);
    w = w / 100;
    t = (w << 16) | (exec / 100);
    strcpy(tt, ctime(&t));
    return YES;
}

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
    w = (char *)(*malloc_hook)(1+strlen(filename));
    if (w == NULL) return w;
    strcpy(w, filename);
    return w;
}

char *my_getenv(char *s)
{
    return getenv(s);
}

static void delink(void), relink(void);

int my_system(char *s)
{
    int w;
    delink();
    w = system(s);
    relink();
    return w;
}

/*
 * RISCOS does not support the idea of home directories for
 * users, so in case anybody still wants to use the notation "~" that
 * would indicate a home directory under Unix I implement something
 * in terms of environment variables.
 */

static void get_home_directory(char *b, int length)
{
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, "@");
}

static void get_users_home_directory(char *b, int length)
{
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, "@");
}

/*
 * The following structure MUST match the layout of a FILE as used by
 * the library that is linked with.
 */

#define FILEHANDLE int

struct FILE_COPY
{ int icnt;      /* two separate _cnt fields so we can police ...        */
  unsigned char *ptr;
  int ocnt;      /* ... restrictions that read/write are fseek separated */
  int flag;
  unsigned char *base;     /* buffer base */
  int file;                /* RISCOS/Arthur/Brazil file handle */
  long pos;                /* position in file */
  int bufsiz;              /* maximum buffer size */
  int signature;           /* used with temporary files */

  unsigned char lilbuf[2]; /* single byte buffer for them that want it  */
                           /* plus an unget char is put in __lilbuf[1]  */
  long lspos;              /* what __pos should be (set after lazy seek)*/
  unsigned char *extent;   /* extent of writes into the current buffer  */
  int buflim;              /* used size of buffer                       */
  int icnt_save;           /* after unget contains old icnt             */
  int ocnt_save;           /* after unget contains old ocnt             */
};


static int pipe_ptr = 0;
static unsigned char pipe_buffer[20+256];
static CSLbool under_wimp = NO;


FILE *my_popen(char *cmd, char *dirn)
{
    if (!under_wimp) return NULL;
    pipe_ptr = 20;
    return (FILE *)1;
}

void my_pipe_putc(int c, FILE *f)
{
    if (pipe_ptr >= 20 && pipe_ptr < sizeof(pipe_buffer)-1)
    {   if (c == '\n') my_pipe_flush(f);
        else pipe_buffer[pipe_ptr++] = c;
    }
}

void my_pipe_flush(FILE *f)
{
    if (pipe_ptr > 20 && pipe_ptr < sizeof(pipe_buffer)-1)
    {   int32 *w = (int32 *)pipe_buffer;
        remove_ticker();
        delink();
        pipe_buffer[pipe_ptr] = 0;
        w[0] = (pipe_ptr + 4) & ~3;
        w[1] = 0;
        w[2] = 0;
        w[3] = 0;          /* An original message, this one */
        w[4] = 0x0c1202;   /* A magic number for GNUPLOT, I am told! */
        os_swi3(Wimp_SendMessage, 17, (int)w, 0);
        relink();
        add_ticker();
/* here w[2] is my reference for the message */
        accept_tick();
    }
    pipe_ptr = 20;
    return;
}

void my_pclose(FILE *f)
{
    
    return;
}

int batchp()
{
    return (((struct FILE_COPY *)stdin)->file != 0);
}

/*
 * The following function controls memory allocation policy
 */

int32 ok_to_grab_memory(int32 current)
{
    return 3*current + 2;
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */

static char appname[16] = "!CSL";
static char CSL_version_string[64];

static char LOADSTART[16] = "(rdf \"";
static char LOADEND[16]   = "\")";

char *find_image_directory(int argc, char *argv[])
{
    char image[LONGEST_LEGAL_FILENAME];
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    CSLbool riscos_application = NO;
    int i;
/*
 * For RISCOS there are a number of possibilities that can support
 * either window-launched uses or command-line driven uses of this code.
 *
 * When launched from the window manager I will be called with a full
 * path name for by executable binary available in argv[0], and this will
 * always be of the form xxx.yyy.!zzz.!runimage
 * In this case I will use
 *                       xxx.yyy.!zzz.-runimage
 * as the name for my checkpoint file, and I will treate zzz as the name
 * of the application, using that name to control what appears in menus
 * and what sprites I use to display things.
 *
 * The second possibility is that I am called from a command-line. In that
 * case if the command line request was of the form
 *              !zzz.!qqq
 * then I view zzz as the application name, and use !zzz.-qqq as the
 * checkpoint file.  The use of things like xxx.yyy.!zzz.!qqq will be
 * supported in this case too.
 *
 * A final strategy is used if the command line shows only one component
 * of a file name, or if either of the two final components in the path
 * fail to start with '!'.  In this case if the final component of the
 * name (i.e. of argv[0]) is xxx or !xxx then I look up the value of a shell
 * variable xxx$dir, and if look for a file called "-runimage" in that
 * directory.  If argv[0] is null I take it to be "csl" and if the
 * environment variable indicated here is unset I look for -runimage in
 * the current directory.  In such cases the application name is taken as xxx.
 */
    if (argc > 0 && argv[0] != NULL)
    {   int j, r0, r1;
        w = argv[0];
        sprintf(pgmname, "\"%s\"\n", w);
/*
 * The following line expands any shell-variables mentioned in the
 * command that launched me.  E.g. typically from the window manager
 * the raw command-line will have been
 *      <Obey$Dir>.!RunImage ...
 * and I need to expand <Obey$Dir>
 */
        os_swi3r(OS_EvaluateExpression,
                 (int)pgmname, (int)image, LONGEST_LEGAL_FILENAME,
                 &r0, &r1, &i);
        if (r1 == 0) sprintf(image, "%d", i);
        else image[i] = 0;
        w = image;
        i = strlen(w);
        while (i > 0 && w[i-1] != '.') i--;
        j = i-1;
        while (j > 0 && w[j-1] != '.') j--;
        if (j >= 0 && w[i] == '!' && w[j] == '!')
        {   w[i] = '-';
            if (i > j+16) i = j+16; /* Truncate name if necessary */
            sprintf(appname, "%.*s", i-j-1, &w[j]);
            riscos_application = YES;
        }
        else
        {   strcpy(pgmname, &w[i]);
            strcpy(image, pgmname);
        }
    }
    else strcpy(image, "!csl");    /* even argv[0] is not available! */
    if (!riscos_application)
    {
/*
 * If I get here then image contains the final component of the application
 * name, and I must use it to build the name of an environment variable to
 * check.
 */
        if (image[0] == '!')
        {   sprintf(pgmname, "%s$dir", &image[1]);
            sprintf(appname, "%.15s", image);
        }
        else
        {   sprintf(pgmname, "%s$dir", image);
            sprintf(appname, "!%.15s", image);
        }
        w = my_getenv(pgmname);
        if (w == NULL) w = "@";
        sprintf(image, "%s.-runimage", w);
    }
    w = appname;    /* Force application name into upper case */
    while ((i = *w) != 0)
    {   if (islower(i)) i = toupper(i);
        *w++ = i;
    }
    if (strcmp(appname, "!CSL") != 0)
    {   strcpy(LOADSTART, "in \"");
        strcpy(LOADEND,   "\";");
    }
/*
 * I copy from local vectors into malloc'd space to hand my
 * answer back.
 */
    w = (char *)(*malloc_hook)(1+strlen(image));
/*
 * The error exit here seem unsatisfactory...
 */
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        exit(EXIT_FAILURE);
    }
    strcpy(w, image);
    sprintf(CSL_version_string, "%s %s (%s)", appname+1, VERSION, __DATE__);
    return w;
}

#ifdef PROFILED
/*
 * The following are really part of the ARM C library, but are included here
 * first as prototypes in case the ideas are useful with other architectures.
 *
 * Support for gathering various sorts of information that shows where time
 * may be going in this system.  Un Unix machines try prof/monitor and friends.
 */

extern void *__RO_Base, *__RO_Limit;
extern void _count(void);
extern void _count1(void);

typedef union count_position
/*
 * This defines the format of the word that follows on from a call
 * to _count1(). The related constant values are related to the way that
 * file-name decoding tables are packed away.
 */
{
    int i;
    struct s
    {   unsigned int posn:12,
                     line:16,
                     file:4;
    } s;
} count_position;

#define file_name_map_start 0xfff12340  /* Magic number */
#define file_name_map_end   0x31415926  /* Magic number */

#define word_roundup(s) ((char *)(((int)s + 3) & (~3)))

static char *find_file_map(int p)
{
    int i, w;
    char *s;
    while (((w = *(int *)p) & 0xfffffff0) != file_name_map_start)
    {   if (p >= (int)__RO_Limit) return "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        p += 4;
    }
    s = (char *)(p + 4);
    for ( i = 0; i<=(w & 0xf); i++)
    {   s += 1 + strlen(s);
        s = word_roundup(s);
    }
    if (*(int *)s != file_name_map_end) return find_file_map((int)s);
    return (char *)(p + 4);
}

void show_counts(void)
{
    int count = (int)_count;  /* address of the function as an int */
    int p, onthisline = 0, w1 = 0, w2 = 0;
    myprintf("\nCounts from %p to %p\n", __RO_Base, __RO_Limit);
    for (p = (int)__RO_Base; p<(int)__RO_Limit; p += 4)
    {   int w = *(int *)p;
        if ((w & 0xff000000) == 0xeb000000) /* Unconditional BL instruction */
        {   int dest = (p + 8 + 4*(w & 0x00ffffff)) & 0x03fffffc;
            if (dest == count)
            {   myprintf("%.6x: %-10u ", p, *(int *)(p + 4));
                if (onthisline == 3) onthisline = 0, myprintf("\n");
                else onthisline++, myprintf(" ");
            }
        }
        if ((w & 0xfffe0000) == 0xe92c0000 &&  /* STMFD sp!,  sp = r12 or r13 */
            w1 == 0xe1a0b00c &&                /* MOV ip, sp  @@@@@   */
            (w2 & 0xffff0000) == 0xff000000)
        {   char *name = (char *)(p - 8 - (w2 & 0xffff));
            int len = 0;
            char *temp = name;
            /* I do not use strlen() here to keep the library more modular */
            while (*temp++ != 0) len++;
            if (len >= 10 && onthisline == 3)
            {   onthisline = 0;
                myprintf("\n");
            }
            myprintf( "%.6x: %s", p - 4, name);
            len = 11 - strlen(name);
            while (len < 0) len += 20, onthisline++;
            while (len > 0) len--, myprintf(" ");
            if (onthisline >= 3) onthisline = 0, myprintf("\n");
            else onthisline++, myprintf(" ");
        }
        w2 = w1;
        w1 = w;
    }
    if (onthisline != 0) myprintf(" ");
}

void write_profile(char *filename)
{
/* Create a (binary) file containing execution profile information for     */
/* the current program. The format is eccentric, and must be kept in step  */
/* with (a) parts of armgen.c that generate code that collects statistics  */
/* and (b) code in misc.c that reads in the binary file created here and   */
/* displays the counts attached to a source listing of the original code.  */
    int count1 = (int)_count1;
    int p, w1 = 0, w2 = 0, pass, nfiles = 0, namebytes = 0, ncounts = 0;
    int global_name_offset[256];
    char *global_file_map[256]; /* Limits total number of files allowed */
    FILE *map_file = fopen(filename, "wb");
    char *file_map;
    if (map_file == NULL)
    {   myprintf("\nUnable to open %s for execution profile log\n",
                 filename);
        return;
    }
    for (pass = 1; pass <=2; pass++)
    {
        if (pass == 2)
        /* Write file header indicating size of sub-parts */
        {   fwrite("\xff*COUNTFILE*", 4, 3, map_file);
            fwrite(&namebytes, 4, 1, map_file);
            fwrite(&nfiles,    4, 1, map_file);
            fwrite(&ncounts,   4, 1, map_file);
            for (p = 0; p < nfiles; p++)
            {   char *ss = global_file_map[p];
                int len = 1 + strlen(ss);
                len = ((len + 3) & (~3)) / 4;
                fwrite(ss, 4, len, map_file);
            }
            for (p = 0; p < nfiles; p++)
                fwrite(&global_name_offset[p], 4, 1, map_file);
        }
        file_map = NULL;
        for (p = (int)__RO_Base; p<(int)__RO_Limit; p += 4)
        {   int w = *(int *)p;
            if ((w & 0xff000000) == 0xeb000000) /* BL instruction */
            {   int dest = (p + 8 + 4*(w & 0x00ffffff)) & 0x03fffffc;
                if (dest == count1)
                {   count_position k;
                    int i;
                    char *s;
                    if (file_map == NULL ||
                        (int)file_map <= p) file_map = find_file_map(p+12);
                    s = file_map;
                    k.i = *(int *)(p + 8);
                    for (i = 0; i<k.s.file; i++)
                    {   s += 1 + strlen(s);
                        s = word_roundup(s);
                    }
                    if (pass == 1)
                    {   int i;
                        for (i = 0;;i++)
                        {   if (i >= nfiles)
                            {   global_name_offset[nfiles] = namebytes;
                                global_file_map[nfiles++] = s;
                                namebytes += 1 + strlen(s);
                                namebytes = (namebytes + 3) & (~3);
                                break;
                            }
                            else if (strcmp(s,global_file_map[i]) ==0) break;
                        }
                        ncounts++;
                    }
                    else
                    {   int i;
                        for (i = 0; strcmp(s, global_file_map[i]) !=0; i++);
                        fwrite((int *)(p + 4), 4, 1, map_file);
                        i = (k.s.line & 0xffff) | (i << 16);
                        fwrite(&i, 4, 1, map_file);
                    }
                    p += 8;
                }
            }
            w2 = w1;
            w1 = w;
        }
    }
    fwrite("\xff*ENDCOUNT*\n", 4, 3, map_file); /* Trailer data */
    fclose(map_file);
    myprintf("\nProfile information written to %s\n", filename);
}

#endif /* PROFILED */

/*
 *  Wimp interfaces...
 */

static CSLbool CSL_window_open = NO;

static menu Iconbar_menu = 0, Main_menu = 0;

static txt session;
static txt_marker session_marker;

#define MInfo     1 /* Icon-bar menu items */
#define MQuit     2

#define Vfield    4 /* version number field in "about" box */

#define MMInt     1 /* main window menu items */
#define MMAbort   2
#define MMQuit    3
#define MMSave    4
#define MMSelAll  5
#define MMCopy    6
#define MMDelete  7
#define MMClear   8

#define BUFLEN 256

/*
 * Text window event handling
 */

static char *clipboard = NULL;
static int clipboard_size = 0, clipboard_p, clipboard_n;

typedef enum wimp_source_t
{
    from_keyboard = 0,
    from_clipboard,
    from_file
} wimp_source_t;

static wimp_source_t wimp_source = from_keyboard;

#define TTYBUF_SIZE 256
static CSLbool tty_ready = NO;
static int tty_icount = 0;
static char tty_ibuffer[TTYBUF_SIZE];

#ifdef TICK_STREAM

extern void wimp_tick(void);

/*
 * wimp_tick behaves roughly as shown in the following code, but is
 * in assembly code (in asmarm.s) since it is an interrupt routine and I
 * am required to adhere to rigid register-use etc conventions...
 *
 *  void wimp_tick()
 *  {
 *      polltick_pending = YES;
 *      if (tick_pending) return;
 *      else if (already_in_gc) tick_on_gc_exit = YES;
 *      else
 *      {   Lisp_Object nil = C_nil;
 *          tick_pending = YES;
 *          saveheaplimit = heaplimit;
 *          heaplimit = fringe;
 *          savevheaplimit = vheaplimit;
 *          vheaplimit = vfringe;
 *          savecodelimit = codelimit;
 *          codelimit = codefringe;
 *          savestacklimit = stacklimit;
 *          stacklimit = stackbase;
 *      }
 *      return;
 *  }
 */

static CSLbool ticker_active = NO;

void remove_ticker()
{
    if (!ticker_active) return;
#ifndef SOFTWARE_TICKS
    os_swi3(OS_Release, 0x1c, (int)wimp_tick, 0x91494530);
#endif
    ticker_active = NO;
}


void add_ticker()
{
    if (ticker_active) return;
#ifdef SOFTWARE_TICKS
    countdown = SOFTWARE_TICKS;
#else
    os_swi3(OS_Claim, 0x1c, (int)wimp_tick, 0x91494530);
#endif
    ticker_active = YES;
}

#endif /* TICK_STREAM */

static char task_links[61];

static void delink()
{
    os_swi2(OS_DelinkApplication, (int)&task_links[0], sizeof(task_links));
}

static void relink()
{
    os_swi1(OS_RelinkApplication, (int)&task_links[0]);
}

static int selstart = -1, selend = -1, dragstart = -1;
static int done_something = 0;

static BOOL enlarge_clipboard(char **bufp, int *lenp)
{
    if (!flex_extend((flex_ptr)&clipboard, clipboard_size+128))
        return FALSE;
    clipboard_size += 128;
    *bufp = clipboard;
    *lenp = clipboard_size;
    return TRUE;
}

static void clip_selection()
{
    int p1 = txt_selectstart(session), p2 = txt_selectend(session), i;
    clipboard_p = clipboard_n = 0;
    wimp_source = from_clipboard;
    for (i=p1; i<p2; i++)
    {   int c = txt_charat(session, i);
        if (clipboard_n >= clipboard_size)
        {   if (!flex_extend((flex_ptr)&clipboard, clipboard_size+128)) return;
            clipboard_size += 128;
        }
        clipboard[clipboard_n++] = c;
    }
}

static void CSL_txthandler(txt t, void *handle)
{
    txt_eventcode e;
    CSL_IGNORE(t);       /* I only have one txt, so I use its global handle */
    CSL_IGNORE(handle);

    e = txt_get(session);
/*
 * An event is either a mouse one or it involves the keyboard.
 * The latter is taken to include all sorts of special cases such as
 * hits on various buttons.
 * For mouse hits I need to support region selection as well as just
 * positioning.
 */
    if (e & txt_MOUSECODE)
    {   int mousepos = e & 0xffffff;
        if (mousepos == 0xffffff) return;
        if (e & txt_MSELECT)
        {   txt_setdot(session, mousepos);
            if ((e & txt_MSELOLD) && (dragstart >= 0))
            {   if (mousepos >= dragstart)
                    selstart = dragstart, selend = mousepos;
                else selstart = mousepos, selend = dragstart;
                wimp_source = from_keyboard;
            }
            else dragstart = mousepos;
        }
        else if ((e & txt_MSELOLD) && (dragstart >= 0))
        {   if (mousepos >= dragstart)
                selstart = dragstart, selend = mousepos;
            else selstart = mousepos, selend = dragstart;
            dragstart = -1;
            wimp_source = from_keyboard;
        }
        else if ((e & txt_MEXTEND) && (selstart >= 0))
        {   if (2*mousepos <= (selstart+selend)) selstart = mousepos;
            else selend = mousepos;
            wimp_source = from_keyboard;
        }
        if (selstart != selend) txt_setselect(session, selstart, selend);
        else txt_setselect(session, 0, 0); /* Unset any selection */
        done_something = 1;
    }
    else switch(e)
    {
case txt_EXTRACODE + akbd_Sh + akbd_Ctl + akbd_UpK: /* Scroll up one line */
        txt_movevertical(session, -1, 1);
        break;

case txt_EXTRACODE + akbd_Sh + akbd_UpK:            /* Scroll up one page */
        txt_movevertical(session, -txt_visiblelinecount(session), 1);
        break;

case txt_EXTRACODE + akbd_Sh + akbd_Ctl + akbd_DownK: /* Down one line */
        txt_movevertical(session, 1, 1);
        break;

case txt_EXTRACODE + akbd_Sh + akbd_DownK:          /* Down one page */
        txt_movevertical(session, txt_visiblelinecount(session), 1);
        break;

case akbd_LeftK:                                    /* left arrow key */
        txt_movehorizontal(session, -1);
        break;

case akbd_RightK:                                   /* right arrow key */
        txt_movehorizontal(session, 1);
        break;

case akbd_UpK:                                      /* up arrow key */
        txt_movevertical(session, -1, 0);
        break;

case akbd_DownK:                                    /* down arrow key */
        txt_movevertical(session, 1, 0);
        break;

case txt_EXTRACODE + akbd_Fn +akbd_Sh + 2:          /* Insert drag file */
        {   char *filename;
            int filetype, len;
            if ((filetype = xferrecv_checkinsert(&filename)) != -1)
            {   len = strlen(LOADSTART) + strlen(filename) + strlen(LOADEND);
                if (tty_icount + len < TTYBUF_SIZE)
                {   sprintf(&tty_ibuffer[tty_icount], "%s%s%s",
                            LOADSTART, filename, LOADEND);
                    tty_icount += len;
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, LOADSTART);
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, filename);
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, LOADEND);
                    txt_setdot(session, txt_size(session));
                }
                xferrecv_insertfileok();
            }
            else if ((filetype = xferrecv_checkimport(&len)) != -1)
            {   clipboard_p = 0;
                clipboard_n = xferrecv_doimport(clipboard, clipboard_size,
                                                enlarge_clipboard);
                xferrecv_insertfileok();
                if (clipboard_n > 0) wimp_source = from_clipboard;
                txt_setdot(session, txt_size(session));
            }
        }
        break;

case txt_EXTRACODE + akbd_Fn + 127:                 /* close icon */
case akbd_Fn + akbd_Ctl + 2:                        /* Ctl-F2 also quits */
        txt_dispose(&session);
        exit(0);
        break;

case 127:    /* backspace and ^H */
case   8:
        txt_setdot(session, txt_size(session));
        txt_movehorizontal(session, -1);
        txt_delete(session, 1);
        if (tty_icount > 0) tty_icount--;
        break;

default:
        if (e & txt_EXTRACODE)
        {   sprintf(&tty_ibuffer[tty_icount], "<%.8x>", e);
            tty_ibuffer[tty_icount+10] = 0;
            txt_setdot(session, txt_size(session));
            txt_insertstring(session, &tty_ibuffer[tty_icount]);
            txt_setdot(session, txt_size(session));
            tty_icount += 10;
        }
        else if (e >= 256) wimp_processkey(e);  /* give back to wimp */
        else switch (e)
        {
   case 'C' & 0x1f:   /* ^C = copy selection */
            if (selstart == selend || selstart < 0) break;
            clip_selection();
            break;
   case 'X' & 0x1f:   /* ^X = delete selection */
            if (selstart == selend || selstart < 0) break;
            txt_movemarker(session, &session_marker, txt_dot(session));
            txt_setdot(session, txt_selectstart(session));
            txt_delete(session, txt_selectend(session)-txt_selectstart(session));
            txt_movedottomarker(session, &session_marker);
            wimp_source = from_keyboard;
            break;
   case 'Z' & 0x1f:   /* ^Z = cancel selection */
            selstart = selend = -1;
            txt_setselect(session, 0, 0); /* Unset any selection */
            wimp_source = from_keyboard;
            break;
   default:
            if (e == 4 || e == 13 ||
                e == 7 || e == 0x1b ||     /* bell and <escape> */
                e >= 32 && e < 127)
            {
                if (e == 13) e = 10;    /* newline char is special case */
                txt_setdot(session, txt_size(session));
                txt_insertchar(session, e);   /* insert the char */
                txt_movedot(session, 1);      /* advance the dot */
/*
 * I ignore characters (with no comment) if the user types in > 256
 * of them on one line.
 */
                if (tty_icount < TTYBUF_SIZE)
                {   tty_ibuffer[tty_icount++] = e;
                    if (e == 10) tty_ready = YES;
                }
            }
        }
        break;
    }
}

#define SCROLLBACK 4000
#define STDOUT_BUFSIZE 1024
#define LONGEST_PRINTF 120

static char stdout_buffer[STDOUT_BUFSIZE];
static char *stdout_p;
static int stdout_n;

static BOOL saveproc(char *filename, void *handle)
{
    FILE *f = fopen(filename, "w");
    int i;
    CSL_IGNORE(handle);
    if (f == NULL) return FALSE;
    if (selstart == selend || selstart < 0) return FALSE;
    for (i=txt_selectstart(session); i<=txt_selectend(session); i++)
       putc(txt_charat(session, i), f);
    fclose(f);
    return TRUE;
}

static BOOL sendproc(void *handle, int *maxbuf)
{
    int i;
    char buf[4];
    CSL_IGNORE(handle); CSL_IGNORE(maxbuf);
    for (i=txt_selectstart(session); i<=txt_selectend(session); i++)
    {   buf[0] = txt_charat(session, i);
        if (!xfersend_sendbuf(buf, 1)) return FALSE;
    }
    return TRUE;
}

/*
 * Menu to be generated by "menu" button when mouse is over our main
 * text window
 */

static void Main_menuproc(void *handle, char *hit)
{
    CSL_IGNORE(handle);
    switch (hit[0])
    {
case MMInt:
#ifdef SOFTWARE_TICKS
        countdown = -1;
#endif
        interrupt_pending = YES;
        wimp_source = from_keyboard;
        break;

case MMAbort:
#ifdef SOFTWARE_TICKS
        countdown = -1;
#endif
        interrupt_pending = YES;
        wimp_source = from_keyboard;
        break;

case MMQuit:
        exit(0);
        break;

case MMSave:
        wimp_source = from_keyboard;
        saveas(0xfff, "savetext", txt_size(session),
               saveproc, sendproc, NULL, NULL);
        break;

case MMSelAll:
        selstart = 0;
        selend = txt_size(session) - 1;
        if (selstart != selend) txt_setselect(session, selstart, selend);
        break;

case MMCopy:
        if (selstart == selend || selstart < 0) break;
        clip_selection();
        break;

case MMDelete:
        if (selstart == selend || selstart < 0) break;
        txt_movemarker(session, &session_marker, txt_dot(session));
        txt_setdot(session, txt_selectstart(session));
        txt_delete(session, txt_selectend(session)-txt_selectstart(session));
        txt_movedottomarker(session, &session_marker);
        wimp_source = from_keyboard;
        break;

case MMClear:
        selstart = selend = -1;
        txt_setselect(session, 0, 0); /* Unset any selection */
        wimp_source = from_keyboard;
        break;

    }
}

static CSLbool CSL_create_txt(char *title)
/*
 * returns YES if all went well
 */
{
    /* Create a new txt object.  The title passed here over-rides one in the
       template file (a bit of a pity, that?) */
    if ((session = txt_new(title)) == 0) return NO;
    txt_newmarker(session, &session_marker);
    clipboard_size = 128;
    if (!flex_alloc((flex_ptr)&clipboard, clipboard_size)) return NO;

    CSL_window_open = YES;

    if ((Main_menu = menu_new(appname+1,
         "Interrupt,Abort,Quit|>Save,SelectAll,Copy   ^C,Delete ^X,Clear  ^Z"
                              )) == NULL)
        return NO;
    if (!event_attachmenu(txt_syshandle(session), Main_menu, Main_menuproc, 0))
        return NO;

    /* Attach an event handler for the txt */
    txt_eventhandler(session, CSL_txthandler, 0);

    /* Show the txt to the user */
    txt_show(session);

    /* Set "dot" at beginning */
    txt_setdot(session, 0);

    stdout_p = stdout_buffer;
    stdout_n = 0;
    win_claim_idle_events(txt_syshandle(session));
    event_setmask((wimp_emask)0);   /* permits null events to show up */

    return YES;
}


/*
 * Icon Bar Icon.
 */

static void CSL_clickproc(wimp_i i)
{
    CSL_IGNORE(i);
    if (!CSL_window_open)
    {   if (!CSL_create_txt(appname+1))
            werr(YES, "Unable to create text object - exiting");
    }
}

static void Iconbar_menuproc(void *handle, char *hit)
{
    CSL_IGNORE(handle);
    switch (hit[0])
    {
case MInfo:
        {   dbox d;
            d = dbox_new("ProgInfo");
            if (d == 0) return;
            dbox_setfield(d, Vfield, CSL_version_string);
            dbox_show(d);
            dbox_fillin(d);
            dbox_dispose(&d);
        }
        break;

case MQuit:
        exit(0);
        break;
    }
}

/*
 * Arrange that files can be loaded into CSL by dragging
 */

static void CSL_load_events(wimp_eventstr *e, void *handle)
{
    CSL_IGNORE(handle);
    if (e->e == wimp_ESEND || e->e == wimp_ESENDWANTACK)
    {
        if (CSL_window_open && e->data.msg.hdr.action == wimp_MDATALOAD)
        {   char *filename;
            int filetype, len;
            filetype = xferrecv_checkinsert(&filename);
            if (filetype != -1)
            {   len = strlen(LOADSTART) + strlen(filename) + strlen(LOADEND);
                if (tty_icount + len < TTYBUF_SIZE)
                {   sprintf(&tty_ibuffer[tty_icount], "%s%s%s",
                            LOADSTART, filename, LOADEND);
                    tty_icount += len;
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, LOADSTART);
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, filename);
                    txt_setdot(session, txt_size(session));
                    txt_insertstring(session, LOADEND);
                    txt_setdot(session, txt_size(session));
                }
                xferrecv_insertfileok();
            }
        }
    }
}


/*
 * Output procedures
 */

static clock_t last_output_time;


void flush_screen()
/*
 * Bring screen up to date
 */
{
    int n;
    if (!under_wimp)
    {   fflush(stdout);
        return;
    }
    if (stdout_n == 0)
    {   last_output_time = clock();
        return;
    }
    remove_ticker();
    delink();
    n = txt_size(session);
/*
 * This code is intended to keep about around SCROLLBACK characters
 * buffered for the user to scroll back to.  If I have more than SCROLLBACK
 * stored when I come to update the display I will discard some.
 */
    if (n > SCROLLBACK)
    {   txt_setcharoptions(session, txt_DISPLAY, (txt_charoption)0);
        txt_setdot(session, 0);
        txt_delete(session, SCROLLBACK - n + stdout_n);
        txt_setdot(session, txt_size(session));
        txt_setcharoptions(session, txt_DISPLAY, txt_DISPLAY);
        n = txt_size(session);
    }
    if (n != txt_dot(session)) txt_setdot(session, txt_size(session));
    txt_insertstring(session, stdout_buffer);
    txt_setdot(session, txt_size(session));
    stdout_p = stdout_buffer;
    stdout_n = 0;
    last_output_time = clock();
    relink();
    add_ticker();
}

static void remove_hourglass(void);

void pause_for_user()
/*
 * This is called at the end of a run so that the user gets a chance to read
 * the final screen-full of output.  It pops up a dialog box that will
 * wait for a button push.  I take the view that if output is going to a
 * file then the delay is not needed, since the user can always check for
 * messages there. This has the effect that non-interactive build sequences
 * will often run without the pause - a good thing!  Note however that this
 * mean that you MUST use the close box to exit from a wimp session. Just
 * "quit;" or "(stop 0)" will not do.  At least "quit;" etc pops up the
 * dialog box you see here...
 */
{
    dbox d;
    if (spool_file != NULL || !use_wimp) return;
    ensure_screen();
    remove_ticker();
    delink();
    remove_hourglass();
    d = dbox_new("finished");
    if (d == 0) return;     /* Unable to find the "finish" dialog box */
    dbox_show(d);
    dbox_fillin(d);
    dbox_dispose(&d);
    return;
}

void putc_stdout(int c)
{
    if (under_wimp)
    {   *stdout_p++ = c;
        *stdout_p = 0;
        stdout_n++;
        if (stdout_n > STDOUT_BUFSIZE - LONGEST_PRINTF) ensure_screen();
        if (polltick_pending) accept_tick();
    }
    else putchar(c);
}

static char txt_title[64];
static int last_gc_count=-1, last_t=-1, last_gct=-1;
static double last_percent;

void report_time(int32 t, int32 gct)
{
    int pos;
    if (!under_wimp) return;
    sprintf(txt_title, "%s", appname+1);
    pos = strlen(txt_title);
    last_t = t;
    last_gct = gct;
    if (last_t != -1)
        sprintf(&txt_title[pos], "    time %ld.%.2ld+%ld.%.2ld secs",
                last_t/100L, last_t%100L, last_gct/100L, last_gct%100L);
    pos = strlen(txt_title);
    if (last_gc_count != -1)
        sprintf(&txt_title[pos], "   GC %d [%.2f%% full]", last_gc_count, last_percent);
    txt_settitle(session, txt_title);
}

void report_space(int gc_count, double percent)
{
    last_gc_count = gc_count;
    last_percent = percent;
    report_time(last_t, last_gct);
}

/*
 * Input procedures
 */

static CSLbool hourglass_showing;

static void remove_hourglass()
{
    if (hourglass_showing)
    {   os_swi0(Hourglass_Off);
        hourglass_showing = NO;
    }
}

int wimpget(char *tty_buffer)
/*
 * This is the main call from the body of CSL into the window manager
 * to obtain input from the user.  It is expected to copy some input
 * characters into tty_buffer and return the number of characters
 * provided.  In this implementation I keep a separate buffer called
 * tty_ibuffer that characters are collected into - when either this
 * gets full or a newline is inserted into it I copy it to tty_buffer
 * and return.
 * I will cancel copies from a selection if I have almost any mouse
 * activity.
 */
{
    int n;
    if (stdout_n != 0) ensure_screen();
mouse_directed_input:
    switch (wimp_source)
    {
case from_clipboard:
        while (wimp_source == from_clipboard)
        {   int c = clipboard[clipboard_p++];
            txt_setdot(session, txt_size(session));
            txt_insertchar(session, c);   /* insert the char */
            txt_movedot(session, 1);      /* advance the dot */
            if (clipboard_p >= clipboard_n) wimp_source = from_keyboard;
            tty_ibuffer[tty_icount++] = c;
/*
 * If the line ended at buffer full or with a newline I return
 * the completed buffer.  Otherwise I will drop through to wait for
 * keyboard input to finish off the line.
 */
            if (c == '\n' || tty_icount == TTYBUF_SIZE)
            {   memcpy(tty_buffer, tty_ibuffer, TTYBUF_SIZE);
                n = tty_icount;
                tty_icount = 0;
                tty_ready = NO;
                return n;
            }
        }
        break;

case from_file:

case from_keyboard:
        break;
    }
    remove_ticker();
    delink();
    remove_hourglass();
    win_claim_idle_events(txt_syshandle(session));
    event_setmask((wimp_emask)0);   /* permits null events to show up */
    while (!tty_ready && wimp_source == from_keyboard) event_process();
    memcpy(tty_buffer, tty_ibuffer, TTYBUF_SIZE);
    relink();
    add_ticker();
    if (wimp_source != from_keyboard) goto mouse_directed_input;
    n = tty_icount;
    tty_icount = 0;
    tty_ready = NO;
    return n;
}


/*
 * Start-up code for the window manager
 */

static int CSL_initialise()
{
    wimp_save_fp_state_on_poll();
    wimpt_init("Codemist Lisp");
    flex_init();
    res_init(appname+1);
    msgs_init();
    resspr_init();
    template_use_fancyfonts();
    template_init();
    dbox_init();
    txt_init();
/*
 * Create menu to associate with icon-bar object and attach it
 */
    if ((Iconbar_menu = menu_new(appname+1, ">Info,Quit")) == NULL) return NO;
    baricon(appname, 1, CSL_clickproc);
    if (!event_attachmenu(win_ICONBAR, Iconbar_menu, Iconbar_menuproc, 0))
        return NO;

/*
 * Register function to get "unknown" events
 */
    win_register_event_handler(win_ICONBARLOAD, CSL_load_events, 0);
    win_claim_unknown_events(win_ICONBARLOAD);
    tty_count = tty_icount = 0;
    tty_ready = NO;
    return YES;
}

void accept_tick()
/*
 * My clock ticks ensure that this procedure is called fairly regularly...
 */
{
    if (under_wimp)
    {
        clock_t c0 = clock();
/*
 * Here I ensure that the screen is brought up to date at least every 3
 * seconds or so.
 */
        if (last_output_time == 0 || c0 > last_output_time + 3*CLOCKS_PER_SEC)
        {   int t, gct;
            if (clock_stack == &consolidated_time[0])
            {   consolidated_time[0] += (double)(c0 - base_time)/(double)CLOCKS_PER_SEC;
                base_time = c0;
            }
            t = (int)(100.0 * consolidated_time[0]);
            gct = (int)(100.0 * gc_time);
            report_time(t, gct);
            push_clock();
            ensure_screen();
        }
        else push_clock();
/*
 * I also poll the window manager so that other tasks can get a look in
 * and so that my window responds to drag events and is generally kept
 * up to date on the screen.
 */
        remove_ticker();
        delink();
        win_claim_idle_events(txt_syshandle(session));
        event_setmask((wimp_emask)0);   /* permits null events to show up */
        do
        {   done_something = 0;
            event_process();
        } while (done_something);
        relink();
        add_ticker();
/*
 * Time spent doing all of this is counted as "overhead" or "system time"
 * and not included in the times that I will report to my users...
 */
        pop_clock();
        polltick_pending = NO;
    }
}

void start_up_window_manager(int use_wimp)
{
    int i, r0;
    if (!use_wimp)
    {   under_wimp = NO;
        last_output_time = clock();
        return;
    }
    os_swi1r(Wimp_ReadSysInfo, 0, &r0);
    if (r0 == 0) under_wimp = NO;
    else
    {   under_wimp = YES;
        if (!CSL_initialise())
        {   fprintf(stderr, "\nFailed to start the window manager - stopping\n");
            exit(EXIT_FAILURE);
        }
/*
 * Now I hang, doing not a lot, until the main window gets opened...
 */
        while (!CSL_window_open) event_process();
        os_swi0(Hourglass_On);
        hourglass_showing = YES;
        atexit(remove_hourglass);
        win_claim_idle_events(txt_syshandle(session));
        event_setmask((wimp_emask)0);   /* permits null events to show up */
        for (i=0; i<5; i++) event_process();
                             /* Maybe helps things become visible? */
        last_output_time = clock();
    }
}

#include "fileops.c"

/* end of sysarm.c */

