// p2l.cpp                                   Copyright (C) A C Norman, 2017

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


// $Id: $

// Support for Pascal to Lisp translation

// This is NOT good tidy code. It is more of a "jiffy program" without
// careful use of class hierarchy, without error checking and almost
// without comments. That is because I intend it to be used basically
// just once on one set of input data, and because it is short enough that
// I am not terribly worried about support for it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p2l.h"

// A string comes from the lexer enclosed in single quotes and with any
// embedded single quotes doubled. I need to map it onto the form that
// Standard Lisp will quote with, which uses double quotes in a rather
// similar way. This can change the length!

node *string(const char *s)
{   const char *s1 = s;
    size_t len = 1;
    while (*s1 != 0)
    {   if (*s1 == '"') len++;
        len++;
        s1++;
    }
    char *ss = new char[len];
    s1 = s;
    char *s2 = ss;
// First map the initial ' onto a "
    s1++;
    *s2++ = '"';
// Now scan turning " into "" and '' into '
    while (s1[0] != '\'' && s1[1] != 0)
    {   if (s1[0] == '\'' && s1[2] == '\'') s1++;
        if (s1[0] == '"') *s2++ = '"';
        *s2++ = *s1++;
    }
// finally sort out the finsl " and termination.
    *s2++ = '"';
    *s2 = 0;
    sym_node *r = new sym_node;
    r->type = "string";
    r->fields = -1;
    r->s = ss;
    return (node *)r;
}

node *symbol(const char *s)
{   char *ss = new char[strlen(s)+1];
    strcpy(ss, s);
    sym_node *r = new sym_node;
    r->type = "symbol";
    r->fields = -1;
    r->s = ss;
    return (node *)r;
}

node *symbol(const char *type, const char *s)
{   char *ss = new char[strlen(s)+1];
    strcpy(ss, s);
    sym_node *r = new sym_node;
    r->type = type;
    r->fields = -1;
    r->s = ss;
    return (node *)r;
}

node *item(const char *type)
{   n0_node *r = new n0_node;
    r->type = type;
    r->fields = 0;
    return (node *)r;
}

node *item(const char *type, node *a1)
{   n1_node *r = new n1_node;
    r->type = type;
    r->fields = 1;
    r->a1 = a1;
    return (node *)r;
}

node *item(const char *type, node *a1, node *a2)
{   n2_node *r = new n2_node;
    r->type = type;
    r->fields = 2;
    r->a1 = a1;
    r->a2 = a2;
    return (node *)r;
}

node *item(const char *type, node *a1, node *a2, node *a3)
{   n3_node *r = new n3_node;
    r->type = type;
    r->fields = 3;
    r->a1 = a1;
    r->a2 = a2;
    r->a3 = a3;
    return (node *)r;
}

node *item(const char *type, node *a1, node *a2, node *a3, node *a4)
{   n4_node *r = new n4_node;
    r->type = type;
    r->fields = 4;
    r->a1 = a1;
    r->a2 = a2;
    r->a3 = a3;
    r->a4 = a4;
    return (node *)r;
}

node *item(const char *type, node *a1, node *a2, node *a3,
           node *a4, node *a5)
{   n5_node *r = new n5_node;
    r->type = type;
    r->fields = 5;
    r->a1 = a1;
    r->a2 = a2;
    r->a3 = a3;
    r->a4 = a4;
    r->a5 = a5;
    return (node *)r;
}

node *item(const char *type, node *a1, node *a2, node *a3,
           node *a4, node *a5, node *a6)
{   n6_node *r = new n6_node;
    r->type = type;
    r->fields = 6;
    r->a1 = a1;
    r->a2 = a2;
    r->a3 = a3;
    r->a4 = a4;
    r->a5 = a5;
    r->a6 = a6;
    return (node *)r;
}

static int posn = 0;

const char *node_type(node *p)
{   return ((n0_node *)p)->type;
}

int node_fields(node *p)
{   return ((n0_node *)p)->fields;
}

void linesplit()
{   if (posn > 70)
    {   printf("\n");
        posn = 0;
    }
}

void linesplit(const char *s)
{   if (posn+strlen(s) > 70)
    {   printf("\n");
        posn = 0;
    }
}

void prnode(node *p)
{   linesplit();
    if (p == NULL)
    {   posn += printf("nil");
        return;
    }
    switch (node_fields(p))
    {
    case -1:
        linesplit(((sym_node *)p)->s);
        posn += printf("%s", ((sym_node *)p)->s);
        return;
    case 0:
        linesplit(((sym_node *)p)->type);
        posn += printf("%s", ((n0_node *)p)->type);
        return;
    case 1:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n1_node *)p)->type);
        linesplit();
        prnode(((n1_node *)p)->a1);
        linesplit();
        posn += printf(")");
        return;
    case 2:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n2_node *)p)->type);
        linesplit();
        prnode(((n2_node *)p)->a1);
        posn += printf(" ");
        linesplit();
        prnode(((n2_node *)p)->a2);
        linesplit();
        posn += printf(")");
        return;
    case 3:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n3_node *)p)->type);
        linesplit();
        prnode(((n3_node *)p)->a1);
        posn += printf(" ");
        linesplit();
        prnode(((n3_node *)p)->a2);
        posn += printf(" ");
        linesplit();
        prnode(((n3_node *)p)->a3);
        linesplit();
        posn += printf(")");
        return;
    case 4:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n4_node *)p)->type);
        linesplit();
        prnode(((n4_node *)p)->a1);
        posn += printf(" ");
        linesplit();
        prnode(((n4_node *)p)->a2);
        posn += printf(" ");
        linesplit();
        prnode(((n4_node *)p)->a3);
        posn += printf(" ");
        linesplit();
        prnode(((n4_node *)p)->a4);
        linesplit();
        posn += printf(")");
        return;
    case 5:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n5_node *)p)->type);
        linesplit();
        prnode(((n5_node *)p)->a1);
        posn += printf(" ");
        linesplit();
        prnode(((n5_node *)p)->a2);
        posn += printf(" ");
        linesplit();
        prnode(((n5_node *)p)->a3);
        posn += printf(" ");
        linesplit();
        prnode(((n5_node *)p)->a4);
        posn += printf(" ");
        linesplit();
        prnode(((n5_node *)p)->a5);
        linesplit();
        posn += printf(")");
        return;
    case 6:
        linesplit(((sym_node *)p)->type);
        posn += printf("(%s ", ((n6_node *)p)->type);
        linesplit();
        prnode(((n6_node *)p)->a1);
        posn += printf(" ");
        linesplit();
        prnode(((n6_node *)p)->a2);
        posn += printf(" ");
        linesplit();
        prnode(((n6_node *)p)->a3);
        posn += printf(" ");
        linesplit();
        prnode(((n6_node *)p)->a4);
        posn += printf(" ");
        linesplit();
        prnode(((n6_node *)p)->a5);
        posn += printf(" ");
        linesplit();
        prnode(((n6_node *)p)->a6);
        linesplit();
        posn += printf(")");
        return;
    }
}


// end of p2l.c
