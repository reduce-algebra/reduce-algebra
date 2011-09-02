/* read.h                               Copyright (C) Codemist Ltd, 1989-95 */

/*
 * Header defining the structure of the package system for use by
 * intern and its friends.
 */

/* Signature: 1a6e3642 07-Mar-2000 */

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
#define packhdr_(p)   (*(Header *)     ((char *)(p) + (0L - TAG_VECTOR)))
#define packid_(p)    (*(Lisp_Object *)((char *)(p) + (4L - TAG_VECTOR)))
#define packint_(p)   (*(Lisp_Object *)((char *)(p) + (8L - TAG_VECTOR)))
#define packvint_(p)  (*(Lisp_Object *)((char *)(p) + (12L - TAG_VECTOR)))
#define packnint_(p)  (*(Lisp_Object *)((char *)(p) + (16L - TAG_VECTOR)))
#define packflags_(p) (*(Lisp_Object *)((char *)(p) + (20L - TAG_VECTOR)))
#ifdef COMMON
#define packext_(p)   (*(Lisp_Object *)((char *)(p) + (24L - TAG_VECTOR)))
#define packvext_(p)  (*(Lisp_Object *)((char *)(p) + (28L - TAG_VECTOR)))
#define packnext_(p)  (*(Lisp_Object *)((char *)(p) + (32L - TAG_VECTOR)))
#define packname_(p)  (*(Lisp_Object *)((char *)(p) + (36L - TAG_VECTOR)))
#define packnick_(p)  (*(Lisp_Object *)((char *)(p) + (40L - TAG_VECTOR)))
#define packuses_(p)  (*(Lisp_Object *)((char *)(p) + (44L - TAG_VECTOR)))
#define packused_(p)  (*(Lisp_Object *)((char *)(p) + (48L - TAG_VECTOR)))
#define packshade_(p) (*(Lisp_Object *)((char *)(p) + (52L - TAG_VECTOR)))
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

#endif /* header_read_h */

/* end of read.h */
