// cslread.h                             Copyright (C) Codemist, 1989-2022

//
// Header defining the structure of the package system for use by
// intern and its friends.
//


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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


// $Id$

#ifndef header_read_h
#define header_read_h 1

typedef struct Package
{   Header header;
    LispObject packageid;  // 'package as type of this struct
    LispObject internals;  // either vector or list of vectors
    LispObject vinternals; // number of 16K vectors in this package
    LispObject ninternals; // number of symbols in this package
    LispObject pkgflags;   // place to put randomish flags etc
#ifdef COMMON
//
// Standard Lisp can have a much simpler setup than Common Lisp here
//
    LispObject externals;  // vector or list of vectors
    LispObject vexternals; // number of vectors in above
    LispObject nexternals; // number of symbols involved
    LispObject name;       // name of this package
    LispObject nicknames;  // list of nicknames
    LispObject use_list;   // list of things that this package uses
    LispObject used_by_list;      // list of packages that use this one
    LispObject shadowing_symbols; // magic to cope with name clashes
#endif
} Package;

inline Header& packhdr_(LispObject p)
{    return     *csl_cast<Header *>(p + (0*CELL - TAG_VECTOR));
}

inline LispObject& packid_(LispObject p)
{    return *csl_cast<LispObject *>(p + (1*CELL - TAG_VECTOR));
}

inline LispObject& packint_(LispObject p)
{    return *csl_cast<LispObject *>(p + (2*CELL - TAG_VECTOR));
}

inline LispObject& packnint_(LispObject p)
{    return *csl_cast<LispObject *>(p + (3*CELL - TAG_VECTOR));
}

inline LispObject& packflags_(LispObject p)
{    return *csl_cast<LispObject *>(p + (4*CELL - TAG_VECTOR));
}

#ifdef COMMON
inline LispObject& packext_(LispObject p)
{    return *csl_cast<LispObject *>(p + (5*CELL - TAG_VECTOR));
}

inline LispObject& packnext_(LispObject p)
{    return *csl_cast<LispObject *>(p + (6*CELL - TAG_VECTOR));
}

inline LispObject& packname_(LispObject p)
{    return *csl_cast<LispObject *>(p + (7*CELL - TAG_VECTOR));
}

inline LispObject& packnick_(LispObject p)
{    return *csl_cast<LispObject *>(p + (8*CELL - TAG_VECTOR));
}

inline LispObject& packuses_(LispObject p)
{    return *csl_cast<LispObject *>(p + (9*CELL - TAG_VECTOR));
}

inline LispObject& packused_(LispObject p)
{    return *csl_cast<LispObject *>(p + (10*CELL - TAG_VECTOR));
}

inline LispObject& packshade_(LispObject p)
{    return *csl_cast<LispObject *>(p + (11*CELL - TAG_VECTOR));
}

#endif

#define CP  qvalue(current_package)

#ifdef COMMON
#  define ESCAPE_CHAR '\\'
#else
#  define ESCAPE_CHAR '!'
#endif

#define NO_PREFIX           'x'

extern bool is_constituent(int c);
extern LispObject intern(size_t len, bool escaped);
extern LispObject iintern(LispObject str, size_t h, LispObject p,
                          int str_is_ok /* NOT a bool */);
extern LispObject get_symbol(bool gensymp);
extern LispObject find_package(char *name, size_t len);
extern LispObject read_from_vector(char *v);

#define MAX_PROMPT_LENGTH 80
extern char prompt_string[MAX_PROMPT_LENGTH];

// These two are now specified in LispObject units not bytes
#define INIT_OBVECI_SIZE      2048
#define INIT_OBVECX_SIZE      2048

#endif // header_read_h

// end of cslread.h
