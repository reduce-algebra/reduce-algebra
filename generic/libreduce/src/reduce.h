/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   Copyright (c) 2008-2009 Thomas Sturm
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

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

struct oRedProc {
  pid_t processId;
  int meToReduce[2];
  int reduceToMe[2];
  FILE *rlgFile;
};

typedef struct oRedProc *RedProc;

struct oRedAns {
  int statcounter;
  int symbolic;
  char *pretext;
  char *result;
  char *posttext;
  char *nextprompt;
  int time;
  int gctime;
  int error;
};

typedef struct oRedAns *RedAns;

RedProc RedProc_new(const char *reduce);

void RedProc_delete(RedProc process);

void RedProc_error(RedProc process,const char *command,RedAns answer);

void RedProc_cfprint(FILE *stream,RedProc process);

RedAns RedAns_new(RedProc process,const char *command);

void RedAns_delete(RedAns answer);

void RedAns_cfprint(FILE *stream,RedAns ans);

/* The following definitions are for backward-compatibility only */
#define reduce_init RedProc_new
#define reduce_finish RedProc_delete
#define reduce_command RedAns_new
