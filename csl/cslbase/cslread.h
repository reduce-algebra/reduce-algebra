/* cslread.h                      Copyright (C) Codemist Ltd, 1989-2008 */

/*
 * Header defining the structure of the package system for use by
 * intern and its friends.
 */



/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
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



/* Signature: 36b4d379 24-May-2008 */

#ifndef header_read_h
#define header_read_h 1

typedef struct Package
{
    Header header;
    Lisp_Object packageid;  /* 'package as type of this struct */
    Lisp_Object internals;  /* either vector or list of vectors */
    Lisp_Object vinternals; /* number of 16K vectors in this package */
    Lisp_Object ninternals; /* number of symbols in this package */
    Lisp_Object pkgflags;   /* place to put randomish flags etc */
#ifdef COMMON
/*
 * Standard Lisp can have a much simpler setup than Common Lisp here
 */
    Lisp_Object externals;  /* vector or list of vectors */
    Lisp_Object vexternals; /* number of vectors in above */
    Lisp_Object nexternals; /* number of symbols involved */
    Lisp_Object name;       /* name of this package */
    Lisp_Object nicknames;  /* list of nicknames */
    Lisp_Object use_list;   /* list of things that this package uses */
    Lisp_Object used_by_list;      /* list of packages that use this one */
    Lisp_Object shadowing_symbols; /* magic to cope with name clashes */
#endif
} Package;

/*
 * The following macros are coded the way they are so as to encourage the
 * C compiler into using the address modes I want...
 * Rationalize at your peril!
 */
#define packhdr_(p)   (*(Header *)     ((char *)(p) + (0 - TAG_VECTOR)))
#define packid_(p)    (*(Lisp_Object *)((char *)(p) + (CELL - TAG_VECTOR)))
#define packint_(p)   (*(Lisp_Object *)((char *)(p) + (2*CELL - TAG_VECTOR)))
#define packvint_(p)  (*(Lisp_Object *)((char *)(p) + (3*CELL - TAG_VECTOR)))
#define packnint_(p)  (*(Lisp_Object *)((char *)(p) + (4*CELL - TAG_VECTOR)))
#define packflags_(p) (*(Lisp_Object *)((char *)(p) + (5*CELL - TAG_VECTOR)))
#ifdef COMMON
#define packext_(p)   (*(Lisp_Object *)((char *)(p) + (6*CELL - TAG_VECTOR)))
#define packvext_(p)  (*(Lisp_Object *)((char *)(p) + (7*CELL - TAG_VECTOR)))
#define packnext_(p)  (*(Lisp_Object *)((char *)(p) + (8*CELL - TAG_VECTOR)))
#define packname_(p)  (*(Lisp_Object *)((char *)(p) + (9*CELL - TAG_VECTOR)))
#define packnick_(p)  (*(Lisp_Object *)((char *)(p) + (10*CELL - TAG_VECTOR)))
#define packuses_(p)  (*(Lisp_Object *)((char *)(p) + (11*CELL - TAG_VECTOR)))
#define packused_(p)  (*(Lisp_Object *)((char *)(p) + (12*CELL - TAG_VECTOR)))
#define packshade_(p) (*(Lisp_Object *)((char *)(p) + (13*CELL - TAG_VECTOR)))
#endif

#define CP  qvalue(current_package)

#ifdef COMMON
#  define ESCAPE_CHAR '\\'
#else
#  define ESCAPE_CHAR '!'
#endif

#define NO_PREFIX           'x'

extern CSLbool is_constituent(int c);
extern Lisp_Object intern(int len, CSLbool escaped);
extern Lisp_Object iintern(Lisp_Object str, int32_t h, Lisp_Object p,
                           int str_is_ok /* NOT a bool */);
extern Lisp_Object find_package(char *name, int len);
extern Lisp_Object read_from_vector(char *v);

#ifndef MAX_PROMPT_LENGTH
#  define MAX_PROMPT_LENGTH 256
#endif
extern char prompt_string[MAX_PROMPT_LENGTH];

#define INIT_OBVECI_SIZE      16384
#define INIT_OBVECX_SIZE      16384

#endif /* header_read_h */

/* end of cslread.h */
