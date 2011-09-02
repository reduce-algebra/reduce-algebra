/*  r36front.c                       Copyright (C) 1997-2001 Codemist Ltd */

/*
 * This is a Windows front-end for Reduce. It expects a server to
 * be running somewhere else and contactable using a socket-based
 * link.
 */

/* Signature: 4a1fdfb3 20-Mar-2001 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"

#include "tags.h"
#include "externs.h"
#include "arith.h"
#include "read.h"
#include "stream.h"
#include "entries.h"
#include "version.h"
#include "cslerror.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

#ifdef OLD_THINK_C
#include <console.h>
#include <memory.h>
#undef nil  /* Yuk - this is defined by <types.h> which <memory.h> loads */
#endif

#ifdef __WATCOMC__
#include <float.h>
#endif

#ifdef SOCKETS

#include "sockhdr.h"

#ifndef ms_windows
#include <sys/wait.h>
#endif

SOCKET socket_server;
int sockets_ready;

static int char_to_socket(int c);

#endif

#ifdef WINDOW_SYSTEM
bool use_wimp;
#endif

Lisp_Object C_nil=0xbad00000;

Lisp_Object Lstop(Lisp_Object env, Lisp_Object a)
{
    my_exit(0);
    return 0;
}

int init_flags = INIT_VERBOSE;

jmp_buf my_exit_buffer;

void my_exit(int n)
{
#ifdef BUFFERED_STDOUT
    ensure_screen();
#endif
#ifdef SOCKETS
    if (sockets_ready) WSACleanup();
#endif
#ifdef CWIN
    if (n == 0) n = 0x80000000;
    longjmp(my_exit_buffer, n);
#else
#if defined(WINDOWS_NT) && defined(NAG)
    {   extern void sys_abort(int);
        sys_abort(n);
    }
#else
    exit(n);
#endif
#endif
}

static int return_code = 0;
bool segvtrap = YES;
bool batch_flag = NO;
bool ignore_restart_fn = NO;

int tty_count;

character_reader *procedural_input;
character_writer *procedural_output;


void cslstart(int argc, char *argv[], character_writer *wout)
{
#ifdef WINDOW_SYSTEM
/*
 * On some systems (Archimedes/RISCOS) the same executable
 * may run either under a window manager or using a command line.
 * I select which to use based on a command line option, which
 * I scan for VERY early since until I know what I am doing
 * I can not report errors etc etc
 */
    use_wimp = YES;  /* Other than on RISCOS always enable window system */
#ifdef CWIN
    cwin_pause_at_end = 1;
#endif
    start_up_window_manager(use_wimp);
#endif
#ifdef SOCKETS
    sockets_ready = 0;
    socket_server = 0;
#endif
    procedural_input = NULL;
    procedural_output = wout;

    base_time = read_clock();
    consolidated_time[0] = gc_time = 0.0;
    clock_stack = &consolidated_time[0];
    push_clock();

    if (init_flags & INIT_VERBOSE)
    {
#ifndef WINDOW_SYSTEM
/*
 * If I do NOT have a window system I will print a newline here so that I
 * can be very certain that my banner appears at the start of a line.
 * With a window system I should have a brand-new fresh window for output
 * and the newline would intrude as an initial blank line.
 */
        term_printf("\n");
#endif
        term_printf("Codemist Standard Lisp %s for %s: %s\n",
                 VERSION, IMPNAME, __DATE__);
    }
#ifdef WINDOW_SYSTEM
    ensure_screen();
/* If the user hits the close button here I may be in trouble */
#endif

    gc_time += pop_clock();

    ensure_screen();
    procedural_output = NULL;
#ifdef CWIN
/*
 * OK, if I get this far I will suppose that any messages that report utter
 * disasters will have reached the user, so I can allow CWIN to terminate
 * rather more promptly.
 */
    cwin_pause_at_end = 0;
#endif
}

#ifdef SOCKETS

#define SOCKET_BUFFER_SIZE 1024

static char socket_in[SOCKET_BUFFER_SIZE], socket_out[SOCKET_BUFFER_SIZE];
static int socket_in_p = 0, socket_in_n = 0, socket_out_p = 0;

static int char_from_socket(void)
{
    int c;
    clock_t c0;
    time_t t0;
    if (socket_server == 0) return EOF;
    if (socket_in_n == 0)
    {   for (;;)
        {   socket_in_n = recv(socket_server, socket_in, SOCKET_BUFFER_SIZE, 0);            
            c0 = clock();
            t0 = time(NULL);
            if (socket_in_n <= 0)
#ifndef EWOULDBLOCK
#  define EWOULDBLOCK WSAEWOULDBLOCK
#endif
            {   if (errno == EWOULDBLOCK)
                {   sleep(1);  /* Delay 1 second before re-polling */
                    continue;
                }
                closesocket(socket_server);
                socket_server = 0;
                return EOF;
            }
            else break;
        }
        socket_in_p = 0;
    }
    c = socket_in[socket_in_p++];
    socket_in_n--;
    return c & 0xff;
}

static int char_to_socket(int c)
{
    if (socket_server == 0) return 1;
    socket_out[socket_out_p++] = c;
    if (c == '\n' || socket_out_p == SOCKET_BUFFER_SIZE)
    {   if (send(socket_server, socket_out, socket_out_p, 0) < 0)
        {   closesocket(socket_server);
            socket_server = 0;
            return 1;
        }
        socket_out_p = 0;
    }
    return 0;
}


#endif

void cslaction()
{
    char buffer[512];
    ensure_screen();
/*    procedural_input = char_from_socket;
    procedural_output = char_to_socket; */
    tty_count = 0;
    term_printf("Input:");
    ensure_screen();
    wimpget(buffer);
    term_printf("\nIt was <%s>\n", buffer);
    term_printf("Input:");
    ensure_screen();
    wimpget(buffer);
    term_printf("\nIt was <%s>\n", buffer);
    term_printf("Input:");
    ensure_screen();
    wimpget(buffer);
    term_printf("\nIt was <%s>\n", buffer);
    ensure_screen();
    procedural_input = NULL;
    procedural_output = NULL;
}

int cslfinish(character_writer *w)
{
    procedural_output = w;
/*
 * clock_t is an arithmetic type but I do not know what sort - so I
 * widen to double to do arithmetic on it.
 */
    if (init_flags & INIT_VERBOSE)
    {   long int t = (long int)(100.0 * (consolidated_time[0] +
                                  (double)(read_clock() - base_time)/
                                  (double)CLOCKS_PER_SEC));
        long int gct = (long int)(100.0 * gc_time);
        term_printf("\n\nEnd of Lisp run after %ld.%.2ld+%ld.%.2ld seconds\n",
                 t/100, t%100, gct/100, gct%100);
    }
    if (spool_file != NULL) 
    {
#ifdef COMMON
        fprintf(spool_file, "\nFinished dribbling to %s.\n", spool_file_name);
#else
        fprintf(spool_file, "\n+++ Transcript closed at end of run +++\n");
#endif
#ifndef _DEBUG
        fclose(spool_file);
        spool_file = NULL;
#endif
    }
    ensure_screen();
    procedural_output = NULL;
    return return_code;
}

static int submain(int argc, char *argv[])
{
    cslstart(argc, argv, NULL);
    cslaction();
    my_exit(cslfinish(NULL));
    return 0;
}

#if !defined(WINDOWS_NT) || defined(CWIN) || !defined(NAG)

#ifdef CWIN
#define ENTRYPOINT cwin_main
#else
#define ENTRYPOINT main
#endif

int ENTRYPOINT(int argc, char *argv[])
{
    int res;
#ifdef CWIN
#ifdef NAG
    strcpy(about_box_title, "About AXIOM for Windows");
    strcpy(about_box_description, "CWIN interface");
    strcpy(about_box_rights_1,"Copyright NAG Ltd.");
    strcpy(about_box_rights_2,"1991-6");
#else
    strcpy(about_box_title, "About CSL");
    strcpy(about_box_description, "Codemist Standard Lisp");
#endif
#endif
#ifdef __cplusplus
    try { res = submain(argc, argv); }
    catch(int r) { res = r; }
#else
    res = setjmp(my_exit_buffer);
    if (res == 0)  res = submain(argc, argv);
    if (res == 0x80000000) res = 0;
#endif
    return res;
}

#endif /* NAG */


FILE *spool_file = NULL;
char spool_file_name[32];

int32 terminal_column = 0;

int32 terminal_line_length = (int32)0x80000000;

#ifdef CWIN
#define default_terminal_line_length cwin_linelength
#else
#define default_terminal_line_length 80
#endif

#define VPRINTF_CHUNK 256

#ifdef BUFFERED_STDOUT

static int print_buffn = 0;
#define PRINT_BUFSIZE 8000
static char print_buffer[PRINT_BUFSIZE+VPRINTF_CHUNK];

clock_t last_flush = 0;

void ensure_screen()
{
/*
 * Some of what is going on here is that I arrange to discount time spent
 * actually writing characters to the screen.
 */
    if (spool_file != NULL) fflush(spool_file);  /* Maybe useful? */
    if (print_buffn != 0)
    {   push_clock();
/*
 * Time spend writing to the screen is explicitly discounted from measurements
 * of time spent in CSL...
 */
#ifdef WINDOW_SYSTEM
        {
#ifdef CWIN
            print_buffer[print_buffn] = 0;
            cwin_puts(print_buffer);
#else
            int i;
            for (i=0; i<print_buffn; i++)
                putc_stdout(print_buffer[i]);
#endif
            flush_screen();
        }
#else
        fwrite(print_buffer, 1, print_buffn, stdout);
        fflush(stdout); fflush(stderr);
#endif
        print_buffn = 0;
        pop_clock();
        last_flush = base_time;
    }
    else last_flush = read_clock();
}

#endif

void MS_CDECL term_printf(char *fmt, ...)
{
    va_list a;
    char print_temp[VPRINTF_CHUNK], *p;
    int n;
    va_start(a, fmt);
    n = vsprintf(print_temp, fmt, a);
    p = print_temp;
    while (n-- > 0) char_to_terminal(*p++, 0);
    va_end(a);
}

int char_to_terminal(int c, Lisp_Object dummy)
{
    CSL_IGNORE(dummy);
    if (c == '\n' || c == '\f') terminal_column = 0;
    else terminal_column++;
    if (spool_file != NULL)
    {   putc(c, spool_file);
    }
    if (procedural_output != NULL) return (*procedural_output)(c);
#ifdef BUFFERED_STDOUT
    print_buffer[print_buffn++] = c;
    if (print_buffn > PRINT_BUFSIZE) ensure_screen();
#else
/*
 * Note that if I have a windowed system then BUFFERED_STDOUT will always
 * be set, so the case here is JUST for when I have direct output to the
 * ordinary stdout file, with no Lisp-level buffering.
 */
    putchar(c);
#endif
    return 0;   /* indicate success */
}

#ifdef SOCKETS

/*
 * If a Winsock function fails it leaves an error code that
 * WSAGetLastError() can retrieve. This function converts the numeric
 * codes to some printable text. Still cryptic, but maybe better than
 * the raw numbers!
 */

static char error_name[32];

char *WSAErrName(int i)
{
    switch (i)
    {
default:                 sprintf(error_name, "Socket error %d", i);
                         return error_name;

#ifdef ms_windows

case WSAEINTR:           return "WSAEINTR";
case WSAEBADF:           return "WSAEBADF";
case WSAEACCES:          return "WSAEACCES";
#ifdef WSAEDISCON
case WSAEDISCON:         return "WSAEDISCON";
#endif
case WSAEFAULT:          return "WSAEFAULT";
case WSAEINVAL:          return "WSAEINVAL";
case WSAEMFILE:          return "WSAEMFILE";
case WSAEWOULDBLOCK:     return "WSAEWOULDBLOCK";
case WSAEINPROGRESS:     return "WSAEINPROGRESS";
case WSAEALREADY:        return "WSAEALREADY";
case WSAENOTSOCK:        return "WSAENOTSOCK";
case WSAEDESTADDRREQ:    return "WSAEDESTADDRREQ";
case WSAEMSGSIZE:        return "WSAEMSGSIZE";
case WSAEPROTOTYPE:      return "WSAEPROTOTYPE";
case WSAENOPROTOOPT:     return "WSAENOPROTOOPT";
case WSAEPROTONOSUPPORT: return "WSAEPROTONOSUPPORT";
case WSAESOCKTNOSUPPORT: return "WSAESOCKTNOSUPPORT";
case WSAEOPNOTSUPP:      return "WSAEOPNOTSUPP";
case WSAEPFNOSUPPORT:    return "WSAEPFNOSUPPORT";
case WSAEAFNOSUPPORT:    return "WSAEAFNOSUPPORT";
case WSAEADDRINUSE:      return "WSAEADDRINUSE";
case WSAEADDRNOTAVAIL:   return "WSAEADDRNOTAVAIL";
case WSAENETDOWN:        return "WSAENETDOWN";
case WSAENETUNREACH:     return "WSAENETUNREACH";
case WSAENETRESET:       return "WSAENETRESET";
case WSAECONNABORTED:    return "WSAECONNABORTED";
case WSAECONNRESET:      return "WSAECONNRESET";
case WSAENOBUFS:         return "WSAENOBUFS";
case WSAEISCONN:         return "WSAEISCONN";
case WSAENOTCONN:        return "WSAENOTCONN";
case WSAESHUTDOWN:       return "WSAESHUTDOWN";
case WSAETOOMANYREFS:    return "WSAETOOMANYREFS";
case WSAETIMEDOUT:       return "WSAETIMEDOUT";
case WSAECONNREFUSED:    return "WSAECONNREFUSED";
case WSAELOOP:           return "WSAELOOP";
case WSAENAMETOOLONG:    return "WSAENAMETOOLONG";
case WSAEHOSTDOWN:       return "WSAEHOSTDOWN";
case WSAEHOSTUNREACH:    return "WSAEHOSTUNREACH";
case WSASYSNOTREADY:     return "WSASYSNOTREADY";
case WSAVERNOTSUPPORTED: return "WSAVERNOTSUPPORTED";
case WSANOTINITIALISED:  return "WSANOTINITIALISED";
case WSAHOST_NOT_FOUND:  return "WSAHOST_NOT_FOUND";
case WSATRY_AGAIN:       return "WSATRY_AGAIN";
case WSANO_RECOVERY:     return "WSANO_RECOVERY";
case WSANO_DATA:         return "WSANO_DATA";

#else

/*
 * When I run under Unix I display both the Unix and Windows form of the
 * error code.  I guess that shows you which of those platforms is the one
 * I am doing initial development on!
 */
case EINTR:              return "WSAEINTR/EINTR";
case EBADF:              return "WSAEBADF/EBADF";
case EACCES:             return "WSAEACCES/EACCES";
case EFAULT:             return "WSAEFAULT/EFAULT";
case EINVAL:             return "WSAEINVAL/EINVAL";
case EMFILE:             return "WSAEMFILE/EMFILE";
case EWOULDBLOCK:        return "WSAEWOULDBLOCK/EWOULDBLOCK";
case EINPROGRESS:        return "WSAEINPROGRESS/EINPROGRESS";
case EALREADY:           return "WSAEALREADY/EALREADY";
case ENOTSOCK:           return "WSAENOTSOCK/ENOTSOCK";
case EDESTADDRREQ:       return "WSAEDESTADDRREQ/EDESTADDRREQ";
case EMSGSIZE:           return "WSAEMSGSIZE/EMSGSIZE";
case EPROTOTYPE:         return "WSAEPROTOTYPE/EPROTOTYPE";
case ENOPROTOOPT:        return "WSAENOPROTOOPT/ENOPROTOOPT";
case EPROTONOSUPPORT:    return "WSAEPROTONOSUPPORT/EPROTONOSUPPORT";
case ESOCKTNOSUPPORT:    return "WSAESOCKTNOSUPPORT/ESOCKTNOSUPPORT";
case EOPNOTSUPP:         return "WSAEOPNOTSUPP/EOPNOTSUPP";
case EPFNOSUPPORT:       return "WSAEPFNOSUPPORT/EPFNOSUPPORT";
case EAFNOSUPPORT:       return "WSAEAFNOSUPPORT/EAFNOSUPPORT";
case EADDRINUSE:         return "WSAEADDRINUSE/EADDRINUSE";
case EADDRNOTAVAIL:      return "WSAEADDRNOTAVAIL/EADDRNOTAVAIL";
case ENETDOWN:           return "WSAENETDOWN/ENETDOWN";
case ENETUNREACH:        return "WSAENETUNREACH/ENETUNREACH";
case ENETRESET:          return "WSAENETRESET/ENETRESET";
case ECONNABORTED:       return "WSAECONNABORTED/ECONNABORTED";
case ECONNRESET:         return "WSAECONNRESET/ECONNRESET";
case ENOBUFS:            return "WSAENOBUFS/ENOBUFS";
case EISCONN:            return "WSAEISCONN/EISCONN";
case ENOTCONN:           return "WSAENOTCONN/ENOTCONN";
case ESHUTDOWN:          return "WSAESHUTDOWN/ESHUTDOWN";
case ETOOMANYREFS:       return "WSAETOOMANYREFS/ETOOMANYREFS";
case ETIMEDOUT:          return "WSAETIMEDOUT/ETIMEDOUT";
case ECONNREFUSED:       return "WSAECONNREFUSED/ECONNREFUSED";
case ELOOP:              return "WSAELOOP/ELOOP";
case ENAMETOOLONG:       return "WSAENAMETOOLONG/ENAMETOOLONG";
case EHOSTDOWN:          return "WSAEHOSTDOWN/EHOSTDOWN";
case EHOSTUNREACH:       return "WSAEHOSTUNREACH/EHOSTUNREACH";
case HOST_NOT_FOUND:     return "WSAHOST_NOT_FOUND/HOST_NOT_FOUND";
case TRY_AGAIN:          return "WSATRY_AGAIN/TRY_AGAIN";
case NO_RECOVERY:        return "WSANO_RECOVERY/NO_RECOVERY";
#ifdef never
/*
 * Duplicated EINTR, at least on Linux.
 */
case NO_DATA:            return "WSANO_DATA/NO_DATA";
#endif

#endif

    }
}

int ensure_sockets_ready()
{
    if (!sockets_ready)
    {
#ifdef ms_windows
/*
 * Under Windows the socket stuff is not automatically active, so some
 * system calls have to be made at the start of a run. I demand a
 * Winsock 1.1, and fail if that is not available.
 */
        WSADATA wsadata;
        int i = WSAStartup(MAKEWORD(1,1), &wsadata);
        if (i) return i;   /* Failed to start winsock for some reason */;
        if (LOBYTE(wsadata.wVersion) != 1 ||
            HIBYTE(wsadata.wVersion) != 1)
        {   WSACleanup();
            return 1;      /* Version 1.1 of winsock needed */
        }
#endif
        sockets_ready = 1;
    }
    return 0;
}

#endif


clock_t base_time;
double *clock_stack, consolidated_time[10], gc_time;

void push_clock()
{
    clock_t t0 = read_clock();
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    *clock_stack += delta;
    *++clock_stack = 0.0;
}

double pop_clock()
{
    clock_t t0 = read_clock();
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    return delta + *clock_stack--;
}


#include <errno.h>
#include <io.h>
#include <dos.h>
#include <direct.h>
#include <sys\stat.h>

#ifdef _MSC_VER
#define strdup(x) _strdup(x)
#endif


void flush_screen()
{
    cwin_ensure_screen();
}

void start_up_window_manager(int use_wimp)
{
    use_wimp = use_wimp;
}

int wimpget(char *buf)
{
    int c, n=0;
    Lisp_Object nil;
    ensure_screen();
    nil = C_nil;
    if (exception_pending()) return 0;
    while (n < 255)
    {   c = cwin_getchar();
        nil = C_nil;
        if (exception_pending() || c == EOF) return 0;
        c = c & 0xff;
        buf[n++] = c;
        if (c == '\n') break;
    };
    return n;
}


/*
 * Slightly optional jollies re GC statistics...
 */
 
static char time_string[32], space_string[32];

void report_time(int32 t, int32 gct)
{
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    cwin_report_left(time_string);
}

void report_space(int n, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    cwin_report_right(space_string);
}


static char *eu_prices[] =
{
"<HTML>",
"<HEAD>",
"  <TITLE>European Union REDUCE Price List from Codemist Ltd</TITLE>",
"</HEAD>",
"<H1>",
"  European Union REDUCE Price List from Codemist Ltd",
"</H1>",
"<P>",
"This price list is valid for customers within the European Union. Others",
"should use the Worldwide price list. Note",
"that all payment should be in Sterling by cheque drawn on a London Bank or",
"by credit card (VISA or MasterCard). The prices quoted here are valid until",
"<U>30 August 1997</U>.",
"<UL>",
"  <LI>",
"    The <B>Professional Reduce</B> price for all systems is <B>340 pounds sterling",
"    + VAT</B> at the rate in force at the time of delivery. At present this is",
"    17.5% making a complete price of <B>399.50 pounds</B>. The price includes",
"    all sources, instruction sheets, a printed manual and postage and packing.",
"  <LI>",
"    The <B>Personal Reduce</B>, only available for PC clones, Acorn Archimedes,",
"    Atari ST and Macintosh, is <B>72.29 pounds sterling + VAT</B> which is <B>84.95",
"    pounds</B>. This system is pre-built, and delivered with documentation in",
"    machine readable form, instruction sheets, and the price includes postage",
"    and packing. It does <I>not</I> include a printed manual.",
"  <LI>",
"    The <B>Codemist REDUCE Manual</B>, a 450 page single volume manual, incorporating",
"    the Reduce manual, and the manuals for modules and libraries costs <B>15",
"    pounds</B> if ordered at the same time as a system, or <B>20 pounds</B> if",
"    ordered separately. There is no VAT on books in the UK. Please note that",
"    one copy of the manual is included in the Professional REDUCE package.",
"  <LI>",
"    <B>Reduce Site licences</B> are available for 2 or more systems for use at",
"    the same site, defined as a single postal address. The prices in the European",
"    Union are",
"    <UL>",
"      <LI>",
"	<B>510 pounds + VAT</B> for 2 systems",
"      <LI>",
"	<B>612 pounds + VAT</B> for 3 systems",
"      <LI>",
"	<B>640 pounds + VAT</B> for 4 systems",
"      <LI>",
"	<B>1020 pounds + VAT</B> for 5-8 systems",
"      <LI>",
"	<B>1340 pounds + VAT</B> for 9-15 systems",
"      <LI>",
"	<B>1700 pounds + VAT</B> for unlimited systems",
"    </UL>",
"  <LI>",
"    Note that the current applicable VAT rate is 17.5%.",
"</UL>",
"<P>",
"Customers who are VAT registered in an EU country other than the United Kingdom",
"may be able to account for VAT it their own country instead. In this case",
"the VAT registration number <I>must</I> be quoted at the time of order. ",
"  <HR>",
"<P>",
"jpff@maths.bath.ac.uk"
};



static char *world_prices[] =
{
"Worldwide REDUCE Price List from Codemist Ltd",
"",
"This price list is valid in all countries except those of the European Union,",
"for which the EU price list applies. Note that",
"all payment should be in Sterling by cheque drawn on a London Bank or by",
"credit card (VISA or MasterCard). The prices quoted here are valid until",
"30 August 1997.",
"<UL>",
"  <LI>",
"    The <B>Professional Reduce</B> price for all systems is <B>350 pounds",
"    sterling</B>. The price includes all sources of both REDUCE and CSL, instruction",
"    sheets, a printed manual and postage and packing.",
"  <LI>",
"    The <B>Personal Reduce</B>, only available for PC clones, Acorn Archimedes,",
"    Atari ST and Macintosh, is <B>80 pounds sterling</B>. This system is pre-built,",
"    and delivered with documentation in machine readable form, instruction sheets,",
"    and the price includes postage and packing. It does <I>not</I> include a",
"    printed manual.",
"  <LI>",
"    The <B>Codemist REDUCE Manual</B>, a 450 page single volume manual, incorporating",
"    the Reduce manual, and the manuals for modules and libraries costs <B>15",
"    pounds</B> if ordered at the same time as a system, or <B>20 pounds</B> if",
"    ordered separately. Please note that one copy of the manual is included in",
"    the Professional REDUCE package.",
"  <LI>",
"    <B>Reduce Site licences</B> are available for 2 or more systems for use at",
"    the same site, defined as a single postal address. The prices outside the",
"    European Union are",
"    <UL>",
"      <LI>",
"	<B>520 pounds</B> for 2 systems",
"      <LI>",
"	<B>622 pounds</B> for 3 systems",
"      <LI>",
"	<B>650 pounds</B> for 4 systems",
"      <LI>",
"	<B>1030 pounds</B> for 5-8 systems",
"      <LI>",
"	<B>1350 pounds</B> for 9-15 systems",
"      <LI>",
"	<B>1710 pounds</B> for unlimited systems",
"    </UL>",
"",
"  jpff@maths.bath.ac.uk"
};



static char *order_form[] =
{
"REDUCE Order Form",
"",
"",
"Send _____ REDUCE 3.6 system(s) for",
"           Archimedes, Macintosh(68K), Macintosh (Power), PC (DOS),",
"           PC(Windows), SUN, SGI, IBM/AIX,  Generic",
"           (please delete as required)",
"",
"       Professional/Personal/Personal+Manual(*) (please delete as required)",
"",
"       [For SUN, SGI, AIX or Generic] Preferred medium?",
"        DAT/DDS, QIC Tape, FTP, 3.5\" floppy, other........",
"to",
"",
"   Name _______________________________________________________ ",
"   ",
"   Organization _______________________________________________",
"",
"   Street _____________________________________________________",
"",
"   City _______________________________________________________",
"",
"   Country ____________________________________________________",
"",
"   Phone ____________________          Fax ____________________",
"",
"   email ____________________",
"",
"   Payment:     Cheque included (in Pounds",
"                Sterling drawn on London Bank)     ____",
"",
"                VISA or MasterCard Credit Card(**) ____",
"",
"                    Card number                    __________________",
"                    Expiry Date                    __________________",
"",
"      Invoice required at above Organisation       ____",
"",
"(*)  The Personal REDUCE is only available for Archimedes, Macintosh or",
"     any of the PC-clones.",
"(**) Please note that if payment is made by credit card, the address",
"     for delivery must be the same as the registered address of the card",
"     holder.  This is required as part of the credit card anti-fraud",
"     policy.",
"",
"I acknowledge the copyrights held in the software by Codemist Ltd",
"(CSL) and Dr. A.C. Hearn (The RAND Corporation) and that further",
"distribution is not allowed.  The royalty fee covers the installation",
"and use of REDUCE on one computer at one location.  The software is",
"delivered on an as-is basis without any warranty.",
"",
"",
"Date  _______________________   Signature __________________________",
"",
"",
"Send this order to: ",
"   Codemist Ltd",
"   \"Alta\", Horsecombe Vale",
"   Combe Down",
"   BATH",
"   BA2 5QR",
"   United Kingdom",
"",
"   FAX/Tel:  +44-1225-837430",
"",
"Contact Codemist at the address above or by e-mail to jpff@maths.bath.ac.uk",
"for information on site licences.",
"",
"  jpff@maths.bath.ac.uk"
};


/* End of r36front.c */
