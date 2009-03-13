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
