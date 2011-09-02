/* read.h                          Copyright (C) Codemist Ltd, 1989-2002 */

/*
 * Header defining the structure of the package system for use by
 * intern and its friends.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */



/* Signature: 31644019 08-Apr-2002 */

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
extern Lisp_Object iintern(Lisp_Object str, int32 h, Lisp_Object p,
                           int str_is_ok /* NOT a bool */);
extern Lisp_Object find_package(char *name, int len);
extern Lisp_Object read_from_vector(char *v);

extern char prompt_string[32];

#define INIT_OBVECI_SIZE      4096
#define INIT_OBVECX_SIZE      4096

#endif /* header_read_h */

/* end of read.h */
