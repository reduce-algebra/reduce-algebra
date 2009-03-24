/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   Copyright (c) 2009 Thomas Sturm
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

#include "redfront.h"

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

#ifdef USE_READLINE

#include <readline/readline.h>

#ifdef HAVE_HISTORY
#include <readline/history.h>
#endif

#else

#include <editline/readline.h>

#endif

extern int color;

void init_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  using_history();

  hname = (char *)malloc(strlen(getenv("HOME"))+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",getenv("HOME"));
  read_history(hname);
#endif
}

void rf_add_history(char this_command[]) {
#ifdef HAVE_HISTORY
  HIST_ENTRY *ph;
  
  if ((this_command != (char *)NULL) && *this_command != 0) {
    while (next_history())
      ;
    if (!(ph = previous_history()) || strcmp(this_command,ph->line) != 0)
      add_history(this_command);
    free(this_command);
  }
#endif
}

char *redline(const char *prompt) {
  return readline(prompt);
}

char *color_prompt(char der_prompt[]) {
  if (color && HAVE_COLOR) {
    char help_prompt[50];
    
    strcpy(help_prompt,der_prompt);
#ifdef USE_READLINE
    sprintf(der_prompt,"%c%c[%d;%d;%dm%c%s%c%c[%d;%d;%dm%c",
	    RL_PROMPT_START_IGNORE,
	    0x1B,0,promptcolor+30,9+40,
	    RL_PROMPT_END_IGNORE,
	    help_prompt,
	    RL_PROMPT_START_IGNORE,
	    0x1B,0,inputcolor+30,9+40,
	    RL_PROMPT_END_IGNORE);
#endif
  }
  return der_prompt;
}

void redline_cleanup_after_signal(void) {
#ifdef USE_READLINE
  return rl_cleanup_after_signal();
#endif
}

void redline_stifle_history(int size) {
  return stifle_history(size);
}

void redline_write_history(const char *histfile) {
  write_history(histfile);
}
