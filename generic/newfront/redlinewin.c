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

/*
 * This variant on redline.c supports native Windows using the
 * winlibedit library.  A C Norman, May 2016.
 */

#include "redfront.h"

static strl line_switchlist = NULL;
static strl line_packlist = NULL;
static strl line_loadlist = NULL;
static strl line_adhoclist = NULL;



char **line_completion_list(const char *text, int start, int end) {
  char **matches = (char **)NULL;
  char *ctemp = rl_line_buffer;
  int i = 0;

  /* skip whitespace at beginning of line before completion */
  while (i < rl_point && isspace(rl_line_buffer[i])) {
    i++;
  }
  ctemp += i;

  if (strncmp(ctemp,"load_package",12) == 0) {
    return rl_completion_matches(text, line_pack_completion_function);
  }
  else if (strncmp(ctemp,"load",4) == 0) {
    return rl_completion_matches(text, line_load_completion_function);   
  }
  else if (*ctemp=='"') {
    return rl_completion_matches(text, rl_filename_completion_function);
  }
  else if (strncmp(ctemp,"on",2) == 0 || strncmp(ctemp,"off",3) == 0) {
    return rl_completion_matches(text, line_switch_completion_function);
  }

  return matches;
}

char *line_switch_completion_function(const char *text, int state) {
  return line_strl_completion_function(text,state,line_switchlist);
}

char *line_pack_completion_function(const char *text, int state) {
  return line_strl_completion_function(text,state,line_packlist);
}

char *line_load_completion_function(const char *text, int state) {
  return line_strl_completion_function(text,state,line_loadlist);
}

char *line_strl_completion_function(const char *text, int state,strl clist) {
  char *res;
  const char *this;
  static strl clist_current = NULL;

  if (!state) {
    clist_current = clist;
  }

  while (clist_current) {
    this = clist_current->this;
    clist_current = clist_current->next;
    // printf("\nclist_current=%d, text=%s, this=%s",clist_current,text,this);
    if (strncmp(text,this,strlen(text)) == 0) {
      // printf("\nHit!");
      res = malloc((strlen(this)+1)*sizeof(char));
      strcpy(res,this);
      return res;
    }
  }

  return NULL;
}



void line_init(void) {
  /* Allow conditional parsing of the ~/.inputrc file. */
  rl_readline_name = "redfront";

  /* Tell the completer that we want a crack first. */
  rl_attempted_completion_function = line_completion_list;
};

char *line_read(char *prompt) {
  static char *line=NULL;
  if (line)
    free(line);
  line = readline(prompt);
  return line;
}

char *line_quit(const char *quit) {
  static char *line=NULL;

  if (line != NULL)
    free(line);
  line = malloc((strlen(quit) + 2)* sizeof(char));
  sprintf(line,"%s\n",quit);
  textcolor(inputcolor);
  printf("%s",line);
  textcolor(normalcolor);
  return line;
}

char *line_color_prompt(char der_prompt[]) {
  if (color) {
    char help_prompt[50];
#if 0
/*
 * The scheme here that tried to set a color using ASI escape codes is
 * not at all suitable for use on native Windows!
 */
    strcpy(help_prompt,der_prompt);
    sprintf(der_prompt,"%c[%d;%d;%dm%s%c[%d;%d;%dm",
	    0x1B,0,promptcolor+30,9+40,
	    help_prompt,
	    0x1B,0,inputcolor+30,9+40);
#endif
  }
  return der_prompt;
}

void line_end(void) {
/*
 * I leave the "#ifdef" in here at least for now because it indicated
 * functionality that may need adding to winlibedit.
 */
#ifndef NATIVE_WINDOWS
  rl_cleanup_after_signal();
#endif
}

void line_init_history(void) {
  char *hname;

  using_history();
  hname = line_histname();
  read_history(hname);
  free(hname);
}

void line_add_history(char this_command[]) {
  HIST_ENTRY *ph;

  if ((this_command != (char *)NULL) && *this_command != 0) {
    while (next_history())
      ;
    if (!(ph = previous_history()) || strcmp(this_command,ph->line) != 0)
      add_history(this_command);
    free(this_command);
  }
}

void line_end_history(void) {
  char *hname;
/*
 * stifle_history discards all bu the last N items in the history list.
 * in this case the limit is 10000 and so it is really not liable to do
 * anything much!
 */
  stifle_history(HISTFILESIZE);
  hname = line_histname();
  write_history(hname);
  free(hname);
}


void line_learn_completion(char der_prompt[]) {
  char tmp[1024];

  vbprintf("Redfront learned ");

#define PACKAGE_MAP "package.map" // @@@
  sprintf(tmp,"lisp redfront_send!-packages(\"%s\")$",PACKAGE_MAP);
  line_packlist = strl_delete(line_packlist);
  send_reduce(tmp);
  line_packlist = line_learn_until_prompt(der_prompt,"packages");

#ifdef PSL
  line_loadlist = line_packlist;
#else
  vbprintf(", ");
  line_loadlist = strl_delete(line_loadlist);
  send_reduce("lisp redfront_send!-modules()$");
  line_loadlist = line_learn_until_prompt(der_prompt,"modules");
#endif

  vbprintf(", ");

  line_switchlist = strl_delete(line_switchlist);
  send_reduce("lisp redfront_send!-switches()$");
  line_switchlist = line_learn_until_prompt(der_prompt,"switches");

  vbprintf("\n");

  line_adhoclist = strl_delete(line_adhoclist);
  line_adhoclist = strl_cadd(line_adhoclist,"load_package ");
}

strl line_learn_until_prompt(char der_prompt[],const char *what){
  int status=SKIPPING_WHITESPACE;
  char buffer[1000];
  int ncharread;
  int ii;
  int pii=0;
  char ch;
  char current[256];  // I assume that there are no longer switch names for now
  int i = 0;
  int learned=0;
  strl clist=NULL;

  deb_fprintf(stderr,
	      "parent: entering line_learn_until_prompt() ... der_prompt=%s\n",
	      der_prompt);

  while(status != FINISHED) {
    ncharread = redread(ReduceToMe[0],buffer,1000);
    for (ii=0; ii < ncharread; ii++) {
      ch = buffer[ii];
      if (ch == (char) 0x01) {
	pii = 0;
	status = READING_PROMPT;
      } else if (ch == (char) 0x02) {
	status = FINISHED;
      } else if (ch == (char) 0x05) {
	i = 0;
	status = LEARNING;
      } else if (ch == (char) 0x06) {
	current[i] = 0;
	clist = strl_cadd(clist,current);
	learned++;
	status = SKIPPING_WHITESPACE;
      } else if (status == LEARNING) {
	current[i++] = ch;
      } else if (status == READING_PROMPT) {
	if ((int) ch > 31)
	  der_prompt[pii++] = ch;
      } else {	/* (status == FINISHED) */
	der_prompt[pii] = 0x00;
      }
    }
  }

  vbprintf("%d %s",learned,what);

  deb_fprintf(stderr,"parent: ... leaving learn_until_prompt()\n");

  return clist;
}

char *line_histname(void) {
  char *hname, *hname1;
  hname1 = getenv("USERPROFILE");
  if (hname1 == NULL) hname1 = ".";
  hname = (char *)malloc(strlen(hname1)+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",hname1);
  return hname;
}

/* end of redlinewin.c */
