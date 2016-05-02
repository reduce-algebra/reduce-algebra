/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 1999-2009 A. Dolzmann and T. Sturm, 1999-2014 T. Sturm
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * Further work by A C Norman, 2016, to remove any trace of us of the
 * full GPL readline library and to move towards support for Windows.
 *
 * Note that this code is keyed to the EXACT version of linedit that is
 * distributed in the Reduce tree with it. That version has been adjusted
 * so it builds under cygwin and so that a couple more header files are
 * exported (the latter because the redfront code relied on functions
 * defined in those headers, and it seems much better to export the
 * definitive headers than to transcribe definitions from them into the
 * redfront source code).
 */

#if defined WIN32 && ! defined __CYGWIN__
#define NATIVE_WINDOWS 1
#endif

#ifdef CSL
#ifdef PSL
#error Both CSL and PSL defined. This is a configuration error
#endif
#else
#ifndef PSL
#error One of CSL or PSL must be defined at compile time
#endif
#endif


#ifdef HAVE_CONFIG_H
/*
 * For the main build of this code I will *NOT* have a config.h file
 * present!
 */
#include "config.h"
#endif

#ifdef NATIVE_WINDOWS

#define RETSIGTYPE void
#define PACKAGE_NAME "winredfront"
#define PACKAGE_VERSION "0.073"
#define USE_PIPES 1
#define PACKAGE_BUGREPORT "'http://sourceforge.net/reduce-algebra"

#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>

#ifdef NATIVE_WINDOWS

#include <windows.h>
#include <unistd.h>
#include <fcntl.h>

typedef void (*sig_t)(int);

#else

#include <libgen.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#if defined HAVE_WAIT_H
#include <wait.h>
#elif defined HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#endif

#include "editline/readline.h"
#include "histedit.h"
/*
 * The redfront code access a number of things that where not initially
 * provided by the standard libexit/editline headers, so I adjusted
 * libedit to export the files that were needed. However the Windows
 * version is different...
 */
#ifndef __MINGW32__
#include "sys.h"
#include "chartype.h"
#endif

/*
 * This sets the amount of history that can be stored to a value so
 * large that it is in effect unlimited.
 */
#define HISTFILESIZE 10000

#ifdef NATIVE_WINDOWS
#define HANDLE_T HANDLE
#else
#define HANDLE_T int
#endif

HANDLE_T MeToReduce[2];
HANDLE_T ReduceToMe[2];
extern int redread(HANDLE_T h, void *buffer, int len);
extern int redwrite(HANDLE_T h, void *buffer, int len);
extern void redclose(HANDLE_T h);

struct strbuf {
  char c;
  struct strbuf *next,*prev;
};

struct oStrl {
  char *this;
  struct oStrl* next;
};

typedef struct oStrl *strl;

int textcolor(int);
void resetcolor(void);
int vbprintf(const char *,...);
void rf_exit(int);

void parent(void);
void send_reduce(char *);

void child(char **);

void line_init_history(void);
void line_add_history(char *);
char *line_read(char *);
char *line_quit(const char *);
char *line_color_prompt(char *);
void line_cleanup_after_signal(void);
void line_end_history(void);
void line_init(void);
void line_learn_completion(char *);
void line_end(void);

RETSIGTYPE sig_sigInt(int);
void sig_installHandlers(void);
void sig_killChild(void);

struct strbuf *addchar(char,struct strbuf *);
struct strbuf *remtail(struct strbuf *,struct strbuf *);
void prtbuf(struct strbuf *);
strl strl_cadd(strl,char *);
strl strl_delete(strl);

void deb_init(void);
int deb_fprintf(FILE *,const char *,...);
void deb_cleanup(void);

#ifdef DEBUG
#define Q deb_fprintf(stderr, "@line %d file %s\n", __LINE__, __FILE__)
#else
#define Q ((void)0)
#endif

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
#define USER 9

/* end of redfront.h */
