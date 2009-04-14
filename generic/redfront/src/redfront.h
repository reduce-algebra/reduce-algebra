/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   Copyright (c) 1999-2009 Andreas Dolzmann and Thomas Sturm
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

#include <stdarg.h>

#include <stdlib.h>

#include <errno.h>

#include <ctype.h>

#include <string.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <fcntl.h>

#include <sys/ioctl.h>

#include <unistd.h>

#include <signal.h>

#if defined HAVE_WAIT_H
#include <wait.h>
#elif defined HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#ifdef HAVE_LIBEDIT

#include <editline/readline.h>
#include <histedit.h>

/* obsolete */
int line_startup(const char *,int);
int line_pre_input(const char *,int);

#else

#include <readline/readline.h>

#ifdef HAVE_HISTORY
#include <readline/history.h>
#endif

#endif

extern int errno;

struct strbuf {
  char c;
  struct strbuf *next,*prev;
};

int textcolor(int);
void resetcolor(void);
void rf_exit(int);

void parent(void);

void child(int,char **,char **);

void line_init_history(void);
void line_add_history(char *);
char *line_read(char *);
char *line_quit(const char *);
char *line_color_prompt(char *);
void line_cleanup_after_signal(void);
void line_end_history(void);
void line_init(void);
void line_end(void);

RETSIGTYPE sig_sigInt(int);
void sig_installHandlers(void);
void sig_removeHandlers(void);
void sig_killChild(void);

struct strbuf *addchar(char,struct strbuf *);
struct strbuf *remtail(struct strbuf *,struct strbuf *);
void prtbuf(struct strbuf *);

void deb_init(void);
int deb_fprintf(FILE *,const char *,...);
void deb_cleanup(void);

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
