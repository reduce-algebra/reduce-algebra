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

#define SKIPPING_WHITESPACE 1
#define READING_PROMPT 2
#define LEARNING 3
#define FINISHED 0

static strl line_switchlist = NULL;
static strl line_packlist = NULL;
static strl line_loadlist = NULL;
static strl line_adhoclist = NULL;


#ifndef __MINGW32__
#include <filecomplete.h>
#endif

#include <sys/stat.h>

#define PROMPT_IGNORE '@'
#define QUERY_ITEMS 100

extern int verbose;

#ifndef __MINGW32__
static EditLine *e;
static History *h;
static HistEvent ev;
#endif

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
#ifdef EL_PROMPT_ESC
  el_set(e,EL_PROMPT_ESC,line_get_prompt,PROMPT_IGNORE);
#else
  el_set(e,EL_PROMPT,line_get_prompt);
#endif
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
/*
 * Note two big constraints here. The first is that that prompt passed
 * down may not be longer than around 24 or 25 characters because all the
 * escape sequences here use up half the 50-characters of buffer space
 * allocated. The second is that the prompt must not contain an instance of
 * the character PROMPT_IGNORE (which appears to be '@' at present).
 */
    strcpy(tmp,der_prompt);
#ifdef EL_PROMPT_ESC
    sprintf(der_prompt,"%c%c[%d;%d;%dm%c%s%c%c[%d;%d;%dm%c",
	    PROMPT_IGNORE,0x1B,0,promptcolor+30,9+40,PROMPT_IGNORE,
	    tmp,
	    PROMPT_IGNORE,0x1B,0,inputcolor+30,9+40,PROMPT_IGNORE);
#else
    sprintf(der_prompt, "%s", tmp);
#endif
  }
  return der_prompt;
}

void line_end(void) {
  el_end(e);
}

void line_init_history(void) {
  char *hname;

  h = history_init();
  el_set(e,EL_HIST,history,h);
  history(h,&ev,H_SETSIZE,HISTFILESIZE);
  history(h,&ev,H_SETUNIQUE,1); /* Ignore duplicates */
  hname = line_histname();
  history(h,&ev,H_LOAD,hname);
  free(hname);
}

void line_add_history(char this_command[]) {
  if (this_command != (char *)NULL && *this_command != 0) {
    history(h,&ev,H_ENTER,this_command);
    free(this_command);
  }
}

void line_end_history(void) {
  char *hname;

  history(h,&ev,H_SETSIZE,HISTFILESIZE);
  hname = line_histname();
  history(h,&ev,H_SAVE,hname);
  free(hname);
}

void line_learn_completion(char der_prompt[]) {
  char tmp[1024];

  vbprintf("Redfront learned ");

  sprintf(tmp,"lisp redfront_send!-packages(nil)$");
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
#ifdef NATIVE_WINDOWS
  hname1 = getenv("USERPROFILE");
  if (hname1 == NULL) hname1 = ".";
  hname = (char *)malloc(strlen(hname1)+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",hname1);
#else
  hname1 = getenv("HOME");
  if (hname1 == NULL) hname1 = "/tmp";
  hname = (char *)malloc(strlen(hname1)+strlen("/.reduce_history")+1);
  sprintf(hname,"%s/.reduce_history",hname1);
#endif
  return hname;
}

/* end of redline.c */
