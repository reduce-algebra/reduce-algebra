/* ------------------------------------------------------------------
	$Id: redfront.h,v 1.10 2006/12/20 11:55:57 sturm Exp $
	------------------------------------------------------------------
	Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
	------------------------------------------------------------------
	$Log: redfront.h,v $
	Revision 1.10  2006/12/20 11:55:57  sturm
	Switched to ANSI C.
	
	Revision 1.9  2006/06/05 09:59:26  sturm
	Moved to version 2.1.
	
	Revision 1.8  2006/06/02 10:19:48  sturm
	The default location of redfront has moved from $reduce/redfront to
	$reduce/packages/redfront.
	
	Revision 1.7  2006/05/17 18:15:43  sturm
	Check for using_history in linreadline first.
	This is essential at least on MacOS X.
	
	Revision 1.6  2004/09/23 09:55:49  sturm
	Fixed debugging output.
	Solaris Compilation.
	This is used for static binaries shipped with REDUCE 3.8.
	
	Revision 1.5  2004/09/02 13:55:44  sturm
	Moved evaluation of $reduce to redfront.c.
	Added evaluation of $reduce also for redfront root.
	
	Revision 1.4  2004/09/02 08:53:42  sturm
	Improved color handling.
	Added support for $reduce.
	This is supposed to work with PSL-based REDUCE.
	
	Revision 1.3  2004/08/28 10:27:52  sturm
	Debug coloring.
	
	Revision 1.2  2003/07/02 07:38:49  sturm
	Added banner message.
	
	Revision 1.1  1999/09/20 13:37:52  sturm
	Private autoconf-based REDFRONT development branch by A. Dolzmann
	and T. Sturm.
	Initial check-in.
	
	------------------------------------------------------------------
   A VERY simple interface to REDUCE
   derived  from the XR interface by Chris Cannam
   Winfried Neun ZIB
	------------------------------------------------------------------ */

#define VERSION "2.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

#include <stdlib.h>

#include <strings.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <fcntl.h>

#include <sys/ioctl.h>

#include <unistd.h>

#include <readline/readline.h>

#ifdef HAVE_HISTORY
#include <readline/history.h>
#endif

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

#define REDFRONTCOLOR MAGENTA /* REDFRONT output */
#define NORMALCOLOR BLACK /* REDUCE terminal output */
#define PROMPTCOLOR BLACK /* REDUCE prompt */
#define INPUTCOLOR RED /* REDUCE input line */
#define OUTPUTCOLOR BLUE /* REDUCE mathprint output */
#define DEBUGCOLOR CYAN /* REDFRONT output with "#define DEBUG" */

#define RREDFRONTROOT "packages/redfront"
