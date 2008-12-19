/* ------------------------------------------------------------------
   $Id: redstrings.c,v 1.2 2006/12/20 11:59:24 sturm Exp $
   ------------------------------------------------------------------
   Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
   ------------------------------------------------------------------
   $Log: redstrings.c,v $
   Revision 1.2  2006/12/20 11:59:24  sturm
   Swicthed to ANSI C.

   Revision 1.1  1999/09/20 13:37:53  sturm
   Private autoconf-based REDFRONT development branch by A. Dolzmann
   and T. Sturm.
   Initial check-in.

   ------------------------------------------------------------------ */

#include "redfront.h"

int bufmatch(struct strbuf *,struct strbuf *);

struct strbuf *addchar(char c,struct strbuf *b) {
  struct strbuf *new;

  new = (struct strbuf *)malloc(sizeof(struct strbuf));
  new->c = c;
  new->next = (struct strbuf *)0;
  new->prev = b;
  if (b)
    b->next = new;
  return new;
}

void prtbuf(struct strbuf *b) {
  struct strbuf *scan,*old;

  if (!b)
    return;

  scan = b;
  while (scan->prev)
    scan = scan->prev;

  while (scan) {
    printf("%c",scan->c);
    old = scan;
    scan = scan->next;
    free(old);
  }
}

struct strbuf *remtail(struct strbuf *t,struct strbuf *b) {
  while (!bufmatch(t,b))
    b = b->prev;
  
  while (t) {
    t = t->prev;
    b = b-> prev;
    free(b->next);
  }

  b->next = (struct strbuf *)0;
  
  return b;
}

int bufmatch(struct strbuf *t,struct strbuf *b) {
  while (t) {
    if (t->c != b->c)
      return 0;
    t = t->prev;
    b = b->prev;
  }
  return 1;
}
