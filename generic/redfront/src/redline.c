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

extern int dist;

extern int redfrontcolor;
extern int normalcolor;
extern int promptcolor;
extern int inputcolor;
extern int outputcolor;
extern int debugcolor;

extern int color;

#define SKIPPING_WHITESPACE 1
#define READING_PROMPT 2
#define LEARNING 3
#define FINISHED 0

extern int ReduceToMe[];

static strl line_switchlist = NULL;
static strl line_packlist = NULL;
static strl line_loadlist = NULL;
static strl line_adhoclist = NULL;


#ifdef HAVE_LIBEDIT

#ifdef HAVE_FILECOMPLETE_H
#include <filecomplete.h>
#else

int fn_complete(EditLine *,
    char *(*)(const char *, int),
    char **(*)(const char *, int, int),
    const char *, const char *, const char *(*)(const char *), size_t,
    int *, int *, int *, int *);

void fn_display_match_list(EditLine *, char **, size_t, size_t);
char *fn_tilde_expand(const char *);
char *fn_filename_completion_function(const char *, int);

#endif

#include <sys/stat.h>

#if LIBEDIT_MAJOR > 2
#define PROMPT_IGNORE '@'
#endif

#define QUERY_ITEMS 100

extern int verbose;

static EditLine *e;
static History *h;
static HistEvent ev;
static char line_prompt[50];

static char line_break_chars[] = {' ', '\t', '\n', '"', '\\', '\'', '`', '@',
				  '$', '>', '<', '=', ';', '|', '&', '{', '(',
				  ',', '\0'};

void line_init(void);
unsigned char _line_learn_completion(EditLine *,int);
void line_learn_completion(char *);
strl line_learn_until_prompt(char *,const char *);
char *line_get_prompt(EditLine *);
char *line_get_rprompt(EditLine *);
unsigned char line_complete(EditLine *,int);
unsigned char line_fn_complete(EditLine *,char *(*)(const char *, int),
			       const char *, const char *(*)(const char *),
			       size_t);
char *line_filename_completion_function(const char *, int);
const char *line_append_char_function(const char *);
char *line_switch_completion_function(const char *, int);
char *line_pack_completion_function(const char *, int);
char *line_load_completion_function(const char *, int);
char *line_strl_completion_function(const char *, int, strl);
char *line_adhoc_completion_function(const char *, int);
const char *line_append_no_char(const char *);
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
#if LIBEDIT_MAJOR > 2
  el_set(e,EL_PROMPT_ESC,line_get_prompt,PROMPT_IGNORE);
#else
  el_set(e,EL_PROMPT,line_get_prompt);
#endif
  /*  el_set(e,EL_RPROMPT,line_get_rprompt); */
  el_set(e,EL_EDITOR,"emacs");
  el_set(e,EL_BIND,"^R","em-inc-search-prev",NULL);
  el_set(e,EL_ADDFN,"line_complete","ReadLine style completion",line_complete);
  el_set(e,EL_BIND,"^I","line_complete",NULL);
  el_set(e,EL_ADDFN,"line_help","bind",line_help);
  el_set(e,EL_BIND,"\033OQ","line_help",NULL);
  el_set(e,EL_ADDFN,"line_learn_completion","learn completions",
	 _line_learn_completion);
  el_set(e,EL_BIND,"^[z","line_learn_completion",NULL);
  el_source(e, NULL);
}

unsigned char _line_learn_completion(EditLine *ignore,int invoking_key) {
  char dummy_prompt[50];

  line_learn_completion(dummy_prompt);
  return CC_REDISPLAY;
}


char *line_get_prompt(EditLine *e) {
  return line_prompt;
}

char *line_get_rprompt(EditLine *e) {
  return "***";
}

unsigned char line_complete(EditLine *ignore,int invoking_key)
{
  unsigned char hit=0;
  const LineInfo *li;
  const char *ctemp;

  li = el_line(e);

  for (ctemp = li->cursor; ctemp >= li->buffer; ctemp--) {

    if (strncmp(ctemp,"load_package",12) == 0) {
      hit = line_fn_complete(e,
			      line_pack_completion_function,
			      line_break_chars,
			      line_append_no_char,
			      QUERY_ITEMS);
      break;
    }

    else if (strncmp(ctemp,"load",4) == 0) {
      hit = line_fn_complete(e,
			      line_load_completion_function,
			      line_break_chars,
			      line_append_no_char,
			      QUERY_ITEMS);
      break;
    }

    else if (*ctemp == '"') {
      hit = line_fn_complete(e,
			      line_filename_completion_function,
			      line_break_chars,
			      line_append_char_function,
			      QUERY_ITEMS);
      break;
    }

    else if (strncmp(ctemp,"on",2) == 0 || strncmp(ctemp,"off",3) == 0) {
      hit = line_fn_complete(e,
			      line_switch_completion_function,
			      line_break_chars,
			      line_append_no_char,
			      QUERY_ITEMS);
      break;
    }
  }

  if (hit)
    return hit;

  return line_fn_complete(e,
			  line_adhoc_completion_function,
			  line_break_chars,
			  line_append_no_char,
			  QUERY_ITEMS);
}

unsigned char line_fn_complete(EditLine *el,
			       char *(*complet_func)(const char *, int),
			       const char *word_break,
			       const char *(*app_func)(const char *),
			       size_t query_items) {
  return (unsigned char )fn_complete(el,
				     complet_func,
				     NULL,
				     word_break,
				     NULL,
				     app_func,
				     query_items,
				     NULL,
				     NULL,
				     NULL,
				     NULL);
}

char *line_filename_completion_function(const char *text, int state) {
  char *completion;
  char *mycompletion;

  completion = fn_filename_completion_function(text,state);

  if (!completion)
    return completion;

  if (completion[0] == '.' && completion[1] == '/') {
    mycompletion = (char *)malloc((strlen(completion)-1)*sizeof(char));
    strcpy(mycompletion,completion+2*sizeof(char));
    free(completion);
    return mycompletion;
  }

  return completion;
}

const char *line_append_char_function(const char *name) {
  struct stat stbuf;
  char *expname = *name == '~' ? fn_tilde_expand(name) : NULL;
  const char *rs = "";

  if (stat(expname ? expname : name, &stbuf) == -1)
    goto out;
  if (S_ISDIR(stbuf.st_mode))
    rs = "/";
 out:
  if (expname)
    free(expname);
  return rs;
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
  static char init = 1;
  static strl clist_current = NULL;

  if (init) {
    init = 0;
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

  init = 1;
  return NULL;
}

char *line_adhoc_completion_function(const char *text, int state) {
  if (strcmp(text,"") == 0) {
    /* This is going to happen systematically and frequently when there
       is no match at the first TAB strike with the other completion
       functions. So I catch this asap here. */
    return (char *)0;
  }

  if (strncmp(text,"load_",5) == 0)
    return line_strl_completion_function(text,state,line_adhoclist);

  return (char *)0;
}

unsigned char line_help(EditLine *ignore,int invoking_key) {
  const char *argv[2];

  argv[0]="bind";
  argv[1]=(char *)0;
  textcolor(redfrontcolor);
  el_parse(e,1,argv);
  textcolor(inputcolor);
  return CC_REDISPLAY;
}

const char *line_append_no_char(const char *name) {
  return "";
}

char *line_read(char *prompt) {
  const char *ret;
  static char *line=NULL;
  int nchar;

  if (line)
    free(line);
  textcolor(inputcolor);
  strcpy(line_prompt,prompt);
  deb_fprintf(stderr,"before el_gets\n");
  ret = el_gets(e,&nchar);
  deb_fprintf(stderr,"after el_gets\n");
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
  if (color) {
    char tmp[50];

    strcpy(tmp,der_prompt);
#if LIBEDIT_MAJOR > 2        
    sprintf(der_prompt,"%c%c[%d;%d;%dm%c%s%c%c[%d;%d;%dm%c",
	    PROMPT_IGNORE,0x1B,0,promptcolor+30,9+40,PROMPT_IGNORE,
	    tmp,
	    PROMPT_IGNORE,0x1B,0,inputcolor+30,9+40,PROMPT_IGNORE);
#else
    sprintf(der_prompt,"%c[%d;%d;%dm%s%c[%d;%d;%dm",
	    0x1B,0,promptcolor+30,9+40,
	    tmp,
	    0x1B,0,inputcolor+30,9+40);
#endif
  }
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
  history(h,&ev,H_SETUNIQUE,IGNOREDUPS);
  hname = line_histname();
  history(h,&ev,H_LOAD,hname);
  free(hname);
#endif
}

void line_add_history(char this_command[]) {
#ifdef HAVE_HISTORY
  if (this_command != (char *)NULL && *this_command != 0) {
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
void line_learn_completion(char *);
strl line_learn_until_prompt(char *,const char *);
char *line_read(char *);
char *line_quit(const char *);
char *line_color_prompt(char *);
void line_end(void);
void line_init_history(void);
void line_add_history(char *);
void line_end_history(void);
char *line_histname(void);
char *line_switch_completion_function(const char *, int);
char *line_pack_completion_function(const char *, int);
char *line_load_completion_function(const char *, int);
char *line_strl_completion_function(const char *, int, strl);




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

void line_learn_completion(char der_prompt[]) {
  char tmp[1024];

  vbprintf("Redfront learned ");

  sprintf(tmp,"lisp redfront_send!-packages(\"%s\")$",PACKAGE_MAP);
  line_packlist = strl_delete(line_packlist);
  send_reduce(tmp);
  line_packlist = line_learn_until_prompt(der_prompt,"packages");

  if (dist == CSL) {
    vbprintf(", ");
    line_loadlist = strl_delete(line_loadlist);
    send_reduce("lisp redfront_send!-modules()$");
    line_loadlist = line_learn_until_prompt(der_prompt,"modules");
  } else
    line_loadlist = line_packlist;

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
    ncharread = read(ReduceToMe[0],buffer,1000);
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
