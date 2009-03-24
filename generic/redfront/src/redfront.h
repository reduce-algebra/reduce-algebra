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

#include <stdlib.h>

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

extern int errno;

struct strbuf {
  char c;
  struct strbuf *next,*prev;
};

void textcolor(int);

void parent(void);

void child(int,char **,char **);

void init_history(void);

void rf_add_history(char *);

char *redline(const char *);

char *color_prompt(char *);

void redline_cleanup_after_signal(void);

void redline_stifle_history(int);

void redline_write_history(const char *);

struct strbuf *addchar(char,struct strbuf *);
struct strbuf *remtail(struct strbuf *,struct strbuf *);
void prtbuf(struct strbuf *);

void installSignalHandlers(void);
void removeSignalHandlers(void);
void red_kill(void);

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
