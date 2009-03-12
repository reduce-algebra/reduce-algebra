/* ------------------------------------------------------------------
   $Id: redparent.c,v 1.19 2006/12/20 11:58:24 sturm Exp $
   ------------------------------------------------------------------
   Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
   ------------------------------------------------------------------
   $Log: redparent.c,v $
   Revision 1.19  2006/12/20 11:58:24  sturm
   Switched to ANSI C.In send_reduce() there was an undeclared and unsused second argument der_prompt.

   Revision 1.18  2006/07/21 11:07:22  sturm
   In redfront_oh call assgnpri with 3rd arg nil instead of 'only.
   Accordingly, read_until_prompt does not eat the first char anymore.
   This fixes 2 bugs: (1) With lisp write "Hallo", the first char did not
   appear. (2) There were two trailing $ with off nat.
   There is a cleaner treatment of control-d in read_valid_line now. Before
   (3) control-d within yesp freed a constant string.

   Revision 1.17  2006/06/28 09:28:35  sturm
   Typeout "quit;" on CTRL-D following the style of bash.
   
   Revision 1.16  2006/05/23 15:19:05  sturm
   Fixed bug in read_until_prompt and read_until_first_prompt: Prompt at
   buffer limit could cause buffer overrun.
   
   Revision 1.15  2006/05/19 08:44:16  sturm
   Explicit newline for EOF exit and SIGQUIT.
   
   Revision 1.14  2006/05/19 08:37:29  sturm
   Treatment of readline() return value NULL, which is caused by EOF (C-d).
   
   Revision 1.13  2006/05/17 18:15:43  sturm
   Check for using_history in linreadline first.
   This is essential at least on MacOS X.
   
   Revision 1.12  2004/09/23 09:55:49  sturm
   Fixed debugging output.
   Solaris Compilation.
   This is used for static binaries shipped with REDUCE 3.8.
   
   Revision 1.11  2004/09/02 13:55:44  sturm
   Moved evaluation of $reduce to redfront.c.
   Added evaluation of $reduce also for redfront root.
   
   Revision 1.10  2004/09/02 10:13:57  dolzmann
   redfront now uses getopt.
   Added new option -c for version without colors.
   Allows option -m for memory size.
   
   Revision 1.9  2004/09/02 09:26:54  sturm
   Fixed setenv of $reduce.
   
   Revision 1.8  2004/08/28 10:27:52  sturm
   Debug coloring.
   
   Revision 1.7  2003/07/02 07:38:49  sturm
   Added banner message.
   
   Revision 1.6  2003/06/27 12:12:23  sturm
   (x+1)**20 did not work.
   
   Revision 1.5  2003/06/26 13:52:37  sturm
   Put most of atoploop stuff into procedures.
   LITHIST is supposed to work now.
   
   Revision 1.4  2003/06/25 12:37:36  sturm
   Some fixes.
   
   Revision 1.3  2003/06/25 12:06:26  sturm
   Added lithist option.
   acconfig.h and redfront_color.red are obsolete.
   
   Revision 1.2  2003/06/23 08:12:10  sturm
   Implemented coloring and cmdhist option.
   
   Revision 1.1  1999/09/20 13:37:53  sturm
   Private autoconf-based REDFRONT development branch by A. Dolzmann
   and T. Sturm.
   Initial check-in.
   
------------------------------------------------------------------ */

#define SYSMAXBUFFER 198

#define READING_OUTPUT 1
#define READING_PROMPT 2
#define FINISHED 0

#include "redfront.h"

extern int MeToReduce[],ReduceToMe[],debug;

extern int color;

extern char *redfrontroot;

char *color_prompt(char der_prompt[]) {
	if (color && HAVE_COLOR) {
		char help_prompt[50];
		
		strcpy(help_prompt,der_prompt);
		sprintf(der_prompt,"%c%c[%d;%d;%dm%c%s%c%c[%d;%d;%dm%c",
			RL_PROMPT_START_IGNORE,
			0x1B,0,PROMPTCOLOR+30,9+40,
			RL_PROMPT_END_IGNORE,
			help_prompt,
			RL_PROMPT_START_IGNORE,
			0x1B,0,INPUTCOLOR+30,9+40,
			RL_PROMPT_END_IGNORE);
	}
	return der_prompt;
}

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
	
	line_read = readline(der_prompt);

	if (line_read)
		while (is_too_long(line_read)) {
			free(line_read);
			line_read = readline(der_prompt);
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
