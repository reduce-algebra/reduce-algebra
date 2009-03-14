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

#define SYSMAXBUFFER 198

#define READING_OUTPUT 1
#define READING_PROMPT 2
#define FINISHED 0

#include "redfront.h"

extern int MeToReduce[],ReduceToMe[],debug;

extern char *redfrontroot;

char* load_redfront_red(void) {
  char *in_redfront_red;
  char ch;
	
  in_redfront_red = (char *)malloc(strlen(redfrontroot)+20);
  sprintf(in_redfront_red,"in \"%s/redfront.red\"$",redfrontroot);
  write(MeToReduce[1],in_redfront_red,strlen(redfrontroot)+19);
	
  ch = 0x0a;
  write(MeToReduce[1],&ch,1);

  return in_redfront_red;
}

void read_until_first_prompt(char der_prompt[]) {
  int status=READING_OUTPUT;
  char buffer[1000];
  int ncharread;
  int ii;
  int pii=0;
  char ch;
  struct strbuf *b=(struct strbuf *)0,*t=(struct strbuf *)0;
	
  textcolor(NORMALCOLOR);
	
  while(status != FINISHED) {
    ncharread = read(ReduceToMe[0],buffer,1000); 
    for (ii=0; ii < ncharread; ii++) {
      ch = buffer[ii];
      if (ch == (char) 0x01 ) {
	status = READING_PROMPT;
	pii = 0;
      } else if (ch == (char) 0x02) {
	status = FINISHED;
      }
      if (status == READING_OUTPUT) {
	b = addchar(ch,b);
      } else if (status == READING_PROMPT) {
	if ((int) ch > 31) {
	  der_prompt[pii++] = ch;
	  t = addchar(ch,t);
	}
      } else {	/* (status == FINISHED) */
	der_prompt[pii] = 0x00; 
      }
    }
  }
  b = remtail(t,b);
  prtbuf(b);
  fflush(stdout);
}

int badline(char line[]) {
  int i=0,n=0;
	
  while (n <= SYSMAXBUFFER && line[i]) {
    if (line[i] == 0x0a)
      n = 0;
    i++;
    n++;
  }
  return (n > SYSMAXBUFFER);
}

int is_too_long(char line_read[]) {
#ifndef RBPSL
  return 0;
#else
  if (badline(line_read)) {
    textcolor(REDFRONTCOLOR);
    printf("redfront: overlong input line\n");
    textcolor(INPUTCOLOR);
    return 1;
  }
  else
    return 0;
#endif
}

char* read_valid_line(char der_prompt[]) {
  char orig_prompt[50];
  char *line_read;

  strcpy(orig_prompt,der_prompt);

  der_prompt = color_prompt(der_prompt);
	
  line_read = redline(der_prompt);

  if (line_read)
    while (is_too_long(line_read)) {
      free(line_read);
      line_read = redline(der_prompt);
    }
  else {
    if (strcmp(orig_prompt,"?") == 0) {
      line_read = malloc(3 * sizeof(char));
      strcpy(line_read,"n\n");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == '>') {
      line_read = malloc(3 * sizeof(char));
      strcpy(line_read,"q\n");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == ':') {
      line_read = malloc(7 * sizeof(char));
      strcpy(line_read,"quit;\n");
    } else if (orig_prompt[strlen(orig_prompt) - 2] == '*') {
      line_read = malloc(7 * sizeof(char));
      strcpy(line_read,"quit;\n");
    } else {
      line_read = malloc(2 * sizeof(char));
      strcpy(line_read,"\n");
    }
    textcolor(INPUTCOLOR);
    printf("%s",line_read);
    textcolor(NORMALCOLOR);
  }
  return line_read;
}

void read_until_prompt(char der_prompt[]){
  int status=READING_OUTPUT;
  char buffer[1000];
  int ncharread;
  int ii;
  int pii=0;
  char ch;

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: entering read_until_prompt() ... der_prompt=%s\n",
	    der_prompt);
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

  textcolor(NORMALCOLOR);

  while(status != FINISHED) {
    ncharread = read(ReduceToMe[0],buffer,1000);
    for (ii=0; ii < ncharread; ii++) {
      ch = buffer[ii];
      if (ch == (char) 0x01) {
	status = READING_PROMPT;
	pii = 0;
      } else if (ch == (char) 0x02) {
	status = FINISHED;
      }
      if (status == READING_OUTPUT) {
	if (ch == (char) 0x03 ) {
	  textcolor(OUTPUTCOLOR);
	}
	else if (ch == (char) 0x04 ) {
	  textcolor(NORMALCOLOR);
	}
	else {
	  printf("%c",ch);
	}
      } else if (status == READING_PROMPT) {
	if ((int) ch > 31)
	  der_prompt[pii++] = ch;
      } else	{	/* (status == FINISHED) */
	der_prompt[pii] = 0x00; 
      } 
    }
    fflush(stdout);	
  }

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: ... leaving read_until_prompt()\n");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

}

char* append_line(char* c,char* l) {
#ifdef HAVE_HISTORY
  char* s;
  int lenc,lenl;

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: entering append_line() ... c=%s, l=%s\n",
	    (c != (char *)NULL) ? c : "NULL",(l != (char *)NULL) ? l : "NULL");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif
  lenc = (c != (char *)NULL) ? strlen(c) : 0;
  lenl = (l != (char *)NULL) ? strlen(l) : 0;

  s = malloc((lenc + lenl + 2) * sizeof(char)); /* 2 >= [ |\x0a| ] + |\0| */
  *s = 0;
  if (c != (char *)NULL) {
    strcpy(s,c);
    if (CMDHIST && LITHIST && lenc != 0 && lenl != 0) {
      strcat(s,"\x0a");
    }
  }
  if (l != (char *)NULL)
    strcat(s,l);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: s=%s ... leaving append_line()\n",s);
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

  return s;
#endif
}

void send_reduce(char line_read[]) {
  char dummy_prompt[50];
  char ch;
  int ii;

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: entering send_reduce() ... line_read=%s\n",
	    line_read);
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif
	
  if (line_read == (char *)NULL) {
    ch=0x04;
    write(MeToReduce[1],&ch,1);
    ch = 0x0a;
    write(MeToReduce[1],&ch,1);
  } else {
    for (ii=0; line_read[ii] != 0; ii++) {
      ch = line_read[ii] & 0x7f;
      write(MeToReduce[1],&ch,1);
      if (ch == 0x0a) {
	strcpy(dummy_prompt,"dummy_prompt");
	read_until_prompt(dummy_prompt);
      }
    }
    ch = 0x0a;
    write(MeToReduce[1],&ch,1);
  }

#ifdef DEBUG
  if(debug) {
    textcolor(DEBUGCOLOR);
    fprintf(stderr,"parent: ... leaving send_reduce()\n");
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

}

void atoploop(void) {
  char *in_redfront_red;
  char der_prompt[50],old_prompt[50];
  char *line_read = (char *)NULL;
  char *this_command = (char *)NULL;

  in_redfront_red = load_redfront_red();

  read_until_first_prompt(der_prompt);

#ifdef DEBUG
  if (debug) {
    textcolor(DEBUGCOLOR);
    /* fprintf(stderr,"0: %s	%% ;-)\n\n",in_redfront_red); */
    fprintf(stderr,"parent: sending %s\n",in_redfront_red);
    textcolor(NORMALCOLOR);
    fflush(stderr);
  }
#endif

  while (1) {

    if (line_read != (char *)NULL)
      free(line_read);
    line_read = read_valid_line(der_prompt);

    this_command = append_line(this_command,line_read);

    send_reduce(line_read);

    strcpy(old_prompt,der_prompt);

    read_until_prompt(der_prompt);

    if (!CMDHIST || strcmp(old_prompt,der_prompt) != 0) {
      rf_add_history(this_command);
      this_command = NULL;
    }
  }
}

void parent(void) {
  installSignalHandlers(); 
	
#ifdef HAVE_SETLINEBUF
  setlinebuf(stdout);
#endif
	
  /* sleep (2); */

  textcolor(REDFRONTCOLOR);
	
  /*		printf("REDFRONT %s%s by A. Dolzmann and T. Sturm, built %s ...\nALPHA RELEASE - DO NOT DISTRIBUTE!\n", */
  /*		 VERSION,STATIC,BUILDTIME); */
  printf("REDFRONT %s%s by A. Dolzmann and T. Sturm, built %s ...\n",
	 VERSION,STATIC,BUILDTIME);
	
  atoploop();
}
