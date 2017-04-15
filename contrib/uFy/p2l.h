// p2l.h                                     Copyright (C) A C Norman, 2017

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

// I suspect that a "proper" version of this would use a class
// hierarachy here. I will use what amount of old fashioned C style
// code only relying on C++ for a bit of function overloading.

// All the parse tree I generate will be made out of items that are
// of the union type "node". Each member of that union is a structure
// that starts off with a "const char *" and then an "int" field, and I
// will rely on those two fields being stored and accessible using any of
// the specialised types. C++ (at least from C++11) sanctions this:
//   6.5.2.3/6
//   One special guarantee is made in order to simplify the use of
//   unions: if a union contains several structures that share a common
//   initial sequence (see below), and if the union object currently
//   contains one of these structures, it is permitted to inspect the
//   common initial part of any of them anywhere that a declaration of
//   the completed type of the union is visible. Two structures share
//   a common initial sequence if corresponding members have compatible
//   types (and, for bit-fields, the same widths) for a sequence of one
//   or more initial members.


typedef struct __sym_node
{   const char *type;
    int fields;
    const char *s;
} sym_node;

typedef struct __n0_node
{   const char *type;
    int fields;
} n0_node;

union __node;

typedef struct __n1_node
{   const char *type;
    int fields;
    union __node *a1;
} n1_node;

typedef struct __n2_node
{   const char *type;
    int fields;
    union __node *a1;
    union __node *a2;
} n2_node;

typedef struct __n3_node
{   const char *type;
    int fields;
    union __node *a1;
    union __node *a2;
    union __node *a3;
} n3_node;

typedef struct __n4_node
{   const char *type;
    int fields;
    union __node *a1;
    union __node *a2;
    union __node *a3;
    union __node *a4;
} n4_node;

typedef struct __n5_node
{   const char *type;
    int fields;
    union __node *a1;
    union __node *a2;
    union __node *a3;
    union __node *a4;
    union __node *a5;
} n5_node;

typedef struct __n6_node
{   const char *type;
    int fields;
    union __node *a1;
    union __node *a2;
    union __node *a3;
    union __node *a4;
    union __node *a5;
    union __node *a6;
} n6_node;

typedef union __node
{   sym_node sym;
    n0_node n0;
    n1_node n1;
    n2_node n2;
    n3_node n3;
    n4_node n4;
    n5_node n5;
    n6_node n6;
} node;

extern node *string(const char *s);
extern node *symbol(const char *s);
extern node *symbol(const char *type, const char *s);
extern node *item(const char *type);
extern node *item(const char *type, node *a1);
extern node *item(const char *type, node *a1, node *a2);
extern node *item(const char *type, node *a1, node *a2, node *a3);
extern node *item(const char *type, node *a1, node *a2, node *a3, node *a4);
extern node *item(const char *type, node *a1, node *a2, node *a3,
                  node *a4, node *a5);
extern node *item(const char *type, node *a1, node *a2, node *a3,
                  node *a4, node *a5, node *a6);
extern void prnode(node *p);

extern char *yytext;

// end of p2l.h
