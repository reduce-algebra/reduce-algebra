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

extern int color;

#ifdef HAVE_LIBEDIT

#include <filecomplete.h>

static EditLine *e;
static History *h;
static HistEvent ev;
static char line_prompt[50];

void line_init(void);
char *line_get_prompt(EditLine *);
char *line_get_rprompt(EditLine *);
unsigned char line_complete(EditLine *,int);
static const char *_rl_completion_append_character_function(const char *);
unsigned char line_help(EditLine *,int);
char *line_read(char *);
char *line_quit(const char *);
char *line_color_prompt(char *);
void line_end(void);
void line_init_history(void);
void line_add_history(char *);
void line_end_history(void);
char *line_histname(void);

void line_init(void) {
  e = el_init("redfront",stdin,stdout,stderr);
  el_set(e,EL_SIGNAL,0);
  el_set(e,EL_PROMPT,line_get_prompt);
  el_set(e,EL_EDITOR,"emacs");
  el_set(e,EL_BIND,"^R","em-inc-search-prev",NULL);
  el_set(e,EL_ADDFN,"line_complete","ReadLine style completion",line_complete);
  el_set(e,EL_BIND,"^I","line_complete",NULL);
  el_set(e,EL_ADDFN,"line_help","bind",line_help);
  el_set(e,EL_BIND,"\033OQ","line_help",NULL);
  el_source(e, NULL);
}

char *line_get_prompt(EditLine *e) {
  return line_prompt;
}

char *line_get_rprompt(EditLine *e) {
  return "";
}

unsigned char line_complete(EditLine *ignore,int invoking_key)
{
  if (rl_inhibit_completion) {
    char arr[2];
    arr[0] = (char)invoking_key;
    arr[1] = '\0';
    el_insertstr(e,arr);
    return (CC_REFRESH);
  }
  
  return fn_complete(e,(CPFunction *)rl_completion_entry_function,
		     rl_attempted_completion_function,
		     rl_basic_word_break_characters,rl_special_prefixes,
		     _rl_completion_append_character_function,
		     rl_completion_query_items,
		     &rl_completion_type, &rl_attempted_completion_over,
		     &rl_point, &rl_end);
}

static const char *_rl_completion_append_character_function(const char *dummy) {
  static char buf[2];
  buf[0] = rl_completion_append_character;
  buf[1] = '\0';
  return buf;
}

unsigned char line_help(EditLine *ignore,int invoking_key) {
  const char *argv[2];

  argv[0]="bind";
  argv[1]=(char *)0;
  textcolor(redfrontcolor);
  el_parse(e,1,argv);
  textcolor(inputcolor);
  return (CC_REFRESH);
}

char *line_read(char *prompt) {
  const char *ret;
  static char *line=NULL;
  int nchar;

  if (line)
    free(line);
  textcolor(inputcolor);
  strcpy(line_prompt,prompt);
  ret = el_gets(e,&nchar);
  if (ret && nchar > 0) {
    line = strdup(ret);
    if (line == NULL)
      return NULL;
    if (line[nchar - 1] == '\n')
      line[nchar - 1] = '\0';
  } else
    line = NULL;
  return line;
}

char *line_quit(const char *quit) {
  static char *line=NULL;

  if (line != NULL)
    free(line);
  line = malloc((strlen(quit) + 2) * sizeof(char));
  sprintf(line,"%s\n",quit);
  textcolor(inputcolor);
  printf("\b\b  \b\b%s",line);
  resetcolor();
  return line;
}

char *line_color_prompt(char der_prompt[]) {
  return der_prompt;
}

void line_end(void) {
  el_end(e);
}

void line_init_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  h = history_init();
  el_set(e,EL_HIST,history,h);
  history(h,&ev,H_SETSIZE,HISTFILESIZE);
  hname = line_histname();
  history(h,&ev,H_LOAD,hname);
  free(hname);
#endif
}

void line_add_history(char this_command[]) {
#ifdef HAVE_HISTORY
  if ((this_command != (char *)NULL) && *this_command != 0) {
    history(h,&ev,H_ENTER,this_command);
    free(this_command);
  }
#endif
}

void line_end_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  history(h,&ev,H_SETSIZE,HISTFILESIZE);
  hname = line_histname();
  history(h,&ev,H_SAVE,hname);
  free(hname);
#endif
}

#else

void line_init(void);
char *line_read(char *);
char *line_quit(const char *);
char *line_color_prompt(char *);
void line_end(void);
void line_init_history(void);
void line_add_history(char *);
void line_end_history(void);
char *line_histname(void);

void line_init(void) {
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
  if (color && HAVE_COLOR) {
    char help_prompt[50];
    
    strcpy(help_prompt,der_prompt);
    sprintf(der_prompt,"%c%c[%d;%d;%dm%c%s%c%c[%d;%d;%dm%c",
	    RL_PROMPT_START_IGNORE,
	    0x1B,0,promptcolor+30,9+40,
	    RL_PROMPT_END_IGNORE,
	    help_prompt,
	    RL_PROMPT_START_IGNORE,
	    0x1B,0,inputcolor+30,9+40,
	    RL_PROMPT_END_IGNORE);
  }
  return der_prompt;
}

void line_end(void) {
  rl_cleanup_after_signal();
}

void line_init_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  using_history();
  hname = line_histname();
  read_history(hname);
  free(hname);
#endif
}

void line_add_history(char this_command[]) {
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

void line_end_history(void) {
#ifdef HAVE_HISTORY
  char *hname;

  stifle_history(HISTFILESIZE);
  hname = line_histname();
  write_history(hname);
  free(hname);
#endif
}

#endif


char *line_histname(void) {
  char *hname;

  hname = (char *)malloc(strlen(getenv("HOME"))+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",getenv("HOME"));
  return hname;
}


/* obsolete ...

int line_startup(const char *c,int n) {
  char *editrc;

  editrc = (char *)malloc(strlen(REDFRONTSRCDIR)+strlen("/editrc")+1);
  sprintf(editrc,"%s%s",REDFRONTSRCDIR,"/editrc");
  rl_read_init_file(editrc);
  free(editrc);
  rl_read_init_file(NULL);
  return 0;
}

int line_pre_input(const char *c,int n) {
  textcolor(inputcolor);
  return 0;
}
*/
