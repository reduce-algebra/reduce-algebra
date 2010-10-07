
/* $destdir\u48.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 0
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
                    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for opfchk!! */

static Lisp_Object CC_opfchkB(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opfchk!");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v52 = stack[-5];
    v52 = qcar(v52);
    stack[0] = v52;
    stack[-6] = v52;
    v52 = stack[-5];
    v52 = qcdr(v52);
    stack[-5] = v52;
    v53 = stack[0];
    v52 = elt(env, 1); /* integer */
    v52 = Lflagp(nil, v53, v52);
    env = stack[-7];
    if (v52 == nil) goto v55;
    v52 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v52;
    v53 = stack[0];
    v52 = elt(env, 3); /* !:rn!: */
    v52 = get(v53, v52);
    env = stack[-7];
    goto v56;

v56:
    stack[0] = v52;
    v52 = stack[0];
    if (v52 == nil) goto v57;
    v52 = stack[-3];
    if (v52 == nil) goto v58;
    v52 = elt(env, 9); /* simprn */
    goto v59;

v59:
    stack[-4] = v52;
    v52 = stack[-3];
    if (!(v52 == nil)) goto v60;
    v52 = qvalue(elt(env, 12)); /* !*complex */
    if (v52 == nil) goto v60;
    v52 = stack[-5];
    v53 = qcar(v52);
    v52 = elt(env, 13); /* list */
    if (!consp(v53)) goto v61;
    v53 = qcar(v53);
    if (!(v53 == v52)) goto v61;
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = qcdr(v52);
    fn = elt(env, 22); /* revlis */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v53 = v52;
    if (v52 == nil) goto v60;
    v52 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v53)) goto v60;
    v53 = qcar(v53);
    if (!(v53 == v52)) goto v60;

v63:
    v53 = stack[-6];
    v52 = elt(env, 16); /* "is not defined as complex function" */
    v52 = list2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v53 = v52;
    v52 = v53;
    qvalue(elt(env, 17)) = v52; /* errmsg!* */
    v52 = qvalue(elt(env, 18)); /* !*protfg */
    if (!(v52 == nil)) goto v64;
    v52 = v53;
    fn = elt(env, 24); /* lprie */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    goto v64;

v64:
    v52 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    goto v60;

v60:
    stack[-1] = stack[-4];
    v52 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v52 = Lapply1(nil, stack[-1], v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-5] = v52;
    if (!(v52 == nil)) goto v65;
    v52 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v52); }

v65:
    stack[-1] = elt(env, 19); /* apply */
    v52 = stack[0];
    stack[0] = Lmkquote(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v52 = stack[-5];
    v52 = Lmkquote(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v54 = list3(stack[-1], stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v53 = qvalue(elt(env, 8)); /* nil */
    v52 = qvalue(elt(env, 20)); /* !*backtrace */
    fn = elt(env, 25); /* errorset */
    v52 = (*qfnn(fn))(qenv(fn), 3, v54, v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-5] = v52;
    v52 = stack[-5];
    if (!consp(v52)) goto v66;
    v52 = stack[-5];
    v52 = qcdr(v52);
    if (!(v52 == nil)) goto v66;
    v52 = stack[-3];
    if (v52 == nil) goto v67;
    v52 = qvalue(elt(env, 5)); /* dmode!* */
    if (v52 == nil) goto v68;
    v53 = qvalue(elt(env, 5)); /* dmode!* */
    v52 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v52 = Lmemq(nil, v53, v52);
    if (!(v52 == nil)) goto v68;
    v53 = qvalue(elt(env, 5)); /* dmode!* */
    v52 = elt(env, 21); /* i2d */
    v53 = get(v53, v52);
    v52 = stack[-5];
    v52 = qcar(v52);
        popv(8);
        return Lapply1(nil, v53, v52);

v68:
    v52 = stack[-5];
    v52 = qcar(v52);
    { popv(8); return onevalue(v52); }

v67:
    v52 = stack[-5];
    v52 = qcar(v52);
    { popv(8); return onevalue(v52); }

v66:
    v52 = stack[-2];
    if (v52 == nil) goto v69;
    v52 = stack[-2];
    stack[-5] = v52;
    v52 = qvalue(elt(env, 8)); /* nil */
    stack[-2] = v52;
    goto v70;

v70:
    v53 = stack[-6];
    v52 = elt(env, 15); /* !:cr!: */
    v52 = get(v53, v52);
    env = stack[-7];
    stack[0] = v52;
    if (v52 == nil) goto v63;
    else goto v65;

v69:
    v52 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v52); }

v61:
    v52 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-5] = v52;
    if (v52 == nil) goto v71;
    v53 = stack[-5];
    v52 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v53)) goto v72;
    v53 = qcar(v53);
    if (!(v53 == v52)) goto v72;

v73:
    v52 = stack[-5];
    v52 = qcdr(v52);
    stack[-5] = v52;
    goto v70;

v72:
    v53 = stack[-6];
    v52 = elt(env, 14); /* expt */
    if (!(v53 == v52)) goto v74;
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcdr(v52);
    if (!consp(v52)) goto v75;
    v52 = stack[-5];
    v52 = qcar(v52);
    v53 = qcar(v52);
    v52 = elt(env, 7); /* !:rd!: */
    if (!consp(v53)) goto v76;
    v53 = qcar(v53);
    if (!(v53 == v52)) goto v76;
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcdr(v52);
    if (!consp(v52)) goto v76;
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v53 = qcar(v52);
    v52 = (Lisp_Object)1; /* 0 */
    v52 = (Lisp_Object)lessp2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v52 = v52 ? lisp_true : nil;
    env = stack[-7];
    goto v77;

v77:
    if (!(v52 == nil)) goto v73;

v74:
    v52 = stack[-5];
    v52 = qcdr(v52);
    stack[-2] = v52;
    v52 = stack[-5];
    v52 = qcar(v52);
    stack[-5] = v52;
    goto v60;

v76:
    v52 = qvalue(elt(env, 8)); /* nil */
    goto v77;

v75:
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v52 = Lminusp(nil, v52);
    env = stack[-7];
    goto v77;

v71:
    v52 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v52); }

v58:
    v53 = stack[0];
    v52 = elt(env, 10); /* simparg */
    v52 = get(v53, v52);
    env = stack[-7];
    stack[-4] = v52;
    if (v52 == nil) goto v78;
    v52 = stack[-4];
    goto v59;

v78:
    v52 = elt(env, 11); /* simprd */
    goto v59;

v57:
    v52 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v52); }

v55:
    v52 = qvalue(elt(env, 4)); /* !*numval */
    if (v52 == nil) goto v79;
    v53 = qvalue(elt(env, 5)); /* dmode!* */
    v52 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v52 = Lmemq(nil, v53, v52);
    if (v52 == nil) goto v79;
    v53 = stack[0];
    v52 = elt(env, 7); /* !:rd!: */
    v52 = get(v53, v52);
    env = stack[-7];
    goto v56;

v79:
    v52 = nil;
    goto v56;
/* error exit handlers */
v62:
    popv(8);
    return nil;
}



/* Code for vp1 */

static Lisp_Object MS_CDECL CC_vp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v57, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v15;
    stack[-1] = v80;
    stack[-2] = v0;
/* end of prologue */
    v88 = nil;
    goto v8;

v8:
    v87 = stack[0];
    if (v87 == nil) goto v89;
    v57 = stack[-2];
    v87 = stack[0];
    v87 = qcar(v87);
    if (equal(v57, v87)) goto v90;
    v87 = (Lisp_Object)1; /* 0 */
    v57 = v88;
    v87 = cons(v87, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v88 = v87;
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[0] = v87;
    goto v8;

v90:
    stack[-2] = v88;
    v87 = stack[0];
    v87 = qcdr(v87);
    fn = elt(env, 2); /* vp2 */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    v87 = cons(stack[-1], v87);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    {
        Lisp_Object v91 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v91, v87);
    }

v89:
    stack[0] = v88;
    v87 = elt(env, 1); /* "Var not in z-list after all" */
    fn = elt(env, 4); /* interr */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    {
        Lisp_Object v92 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v92, v87);
    }
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for exceeds!-order!-variant */

static Lisp_Object CC_exceedsKorderKvariant(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order-variant");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */

v99:
    v45 = stack[-1];
    if (v45 == nil) goto v37;
    v45 = stack[0];
    v45 = qcar(v45);
    stack[-2] = v45;
    v45 = (Lisp_Object)1; /* 0 */
    v98 = v45;
    goto v100;

v100:
    v45 = stack[-2];
    if (v45 == nil) goto v101;
    v45 = stack[-2];
    v45 = qcar(v45);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v45 = (*qfn2(fn))(qenv(fn), v45, v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v98 = v45;
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    goto v100;

v101:
    v45 = v98;
    v98 = v45;
    v45 = stack[-1];
    v45 = qcar(v45);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v45 = (*qfn2(fn))(qenv(fn), v98, v45);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    if (!(v45 == nil)) { popv(4); return onevalue(v45); }
    v45 = stack[-1];
    v98 = qcdr(v45);
    v45 = stack[0];
    v45 = qcdr(v45);
    stack[-1] = v98;
    stack[0] = v45;
    goto v99;

v37:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v45); }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for ps!:expt!-erule */

static Lisp_Object CC_psTexptKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expt-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v80;
    v149 = v0;
/* end of prologue */
    v148 = v149;
    v148 = qcdr(v148);
    v148 = qcar(v148);
    stack[-10] = v148;
    v148 = v149;
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    stack[-6] = v148;
    v148 = v149;
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    stack[-5] = v148;
    v148 = stack[-10];
    fn = elt(env, 4); /* ps!:order */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[-8] = v148;
    v148 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:order */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[-7] = v148;
    v149 = stack[-9];
    v148 = stack[-7];
    if (equal(v149, v148)) goto v151;
    v149 = qvalue(elt(env, 3)); /* nil */
    v148 = (Lisp_Object)17; /* 1 */
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = v148;
    v148 = (Lisp_Object)17; /* 1 */
    stack[-4] = v148;
    goto v152;

v152:
    v149 = stack[-9];
    v148 = stack[-7];
    v149 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = stack[-4];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = Lminusp(nil, v148);
    env = stack[-11];
    if (v148 == nil) goto v153;
    v149 = stack[-9];
    v148 = stack[-7];
    v149 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v149 = stack[-10];
    v148 = stack[-8];
    fn = elt(env, 5); /* ps!:evaluate */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[-1], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 7); /* invsq */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    {
        Lisp_Object v12 = stack[0];
        popv(12);
        fn = elt(env, 6); /* multsq */
        return (*qfn2(fn))(qenv(fn), v12, v148);
    }

v153:
    stack[-3] = stack[0];
    v149 = stack[-4];
    v148 = stack[-6];
    stack[-1] = times2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = stack[-5];
    v149 = stack[-4];
    v148 = stack[-9];
    v149 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = stack[-7];
    v148 = plus2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = times2(stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = plus2(stack[-1], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v150 = v148;
    v149 = v150;
    v148 = (Lisp_Object)1; /* 0 */
    if (v149 == v148) goto v76;
    v148 = v150;
    v149 = v148;
    goto v154;

v154:
    v148 = stack[-5];
    stack[-2] = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = stack[-10];
    v149 = stack[-4];
    v148 = stack[-8];
    v148 = plus2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 5); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v149 = stack[-9];
    v148 = stack[-4];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 5); /* ps!:evaluate */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[-1], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[-2], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 8); /* addsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[-3], v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = v148;
    v148 = stack[-4];
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[-4] = v148;
    goto v152;

v76:
    v148 = qvalue(elt(env, 3)); /* nil */
    v149 = v148;
    goto v154;

v151:
    v149 = stack[-5];
    v148 = (Lisp_Object)17; /* 1 */
    if (v149 == v148) goto v79;
    v150 = elt(env, 2); /* quotient */
    v149 = stack[-6];
    v148 = stack[-5];
    v148 = list3(v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    stack[0] = v148;
    goto v155;

v155:
    v149 = stack[-10];
    v148 = stack[-8];
    fn = elt(env, 5); /* ps!:evaluate */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    fn = elt(env, 9); /* prepsqxx */
    v149 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    v148 = stack[0];
    v148 = list2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-11];
    {
        popv(12);
        fn = elt(env, 10); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v148);
    }

v79:
    v148 = stack[-6];
    stack[0] = v148;
    goto v155;
/* error exit handlers */
v14:
    popv(12);
    return nil;
}



/* Code for dipcontenti1 */

static Lisp_Object MS_CDECL CC_dipcontenti1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipcontenti1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti1");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v15;
    stack[-1] = v80;
    v159 = v0;
/* end of prologue */

v99:
    v155 = stack[0];
    if (v155 == nil) goto v161;
    v155 = stack[0];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    fn = elt(env, 1); /* vbcgcd */
    v155 = (*qfn2(fn))(qenv(fn), v159, v155);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v155;
    v155 = stack[-1];
    if (v155 == nil) goto v90;
    v155 = stack[0];
    v159 = qcar(v155);
    v155 = stack[-1];
    fn = elt(env, 2); /* dipcontevmin */
    v155 = (*qfn2(fn))(qenv(fn), v159, v155);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-1] = v155;
    goto v90;

v90:
    v155 = stack[-2];
    fn = elt(env, 3); /* bcone!? */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    if (v155 == nil) goto v98;
    v155 = stack[-1];
    if (!(v155 == nil)) goto v98;
    v155 = stack[-2];
    popv(4);
    return ncons(v155);

v98:
    v159 = stack[-2];
    v160 = stack[-1];
    v155 = stack[0];
    v155 = qcdr(v155);
    v155 = qcdr(v155);
    stack[-1] = v160;
    stack[0] = v155;
    goto v99;

v161:
    v155 = stack[-1];
    popv(4);
    return cons(v159, v155);
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for remove_root_item */

static Lisp_Object CC_remove_root_item(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_root_item");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcar(v158);
    stack[-2] = v158;
    v158 = stack[-1];
    v158 = qcar(v158);
    stack[0] = v158;
    v155 = stack[-1];
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcar(v158);
    fn = elt(env, 2); /* setcar */
    v158 = (*qfn2(fn))(qenv(fn), v155, v158);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v155 = stack[-1];
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    fn = elt(env, 3); /* setcdr */
    v158 = (*qfn2(fn))(qenv(fn), v155, v158);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v158 = stack[-2];
    v158 = qcdr(v158);
    if (v158 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else goto v165;

v165:
    v158 = stack[-1];
    v158 = qcdr(v158);
    if (v158 == nil) goto v166;
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcar(v158);
    stack[-1] = v158;
    goto v165;

v166:
    v155 = stack[-1];
    v158 = stack[-2];
    v158 = qcar(v158);
    fn = elt(env, 2); /* setcar */
    v158 = (*qfn2(fn))(qenv(fn), v155, v158);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v155 = stack[-1];
    v158 = stack[-2];
    v158 = qcdr(v158);
    fn = elt(env, 3); /* setcdr */
    v158 = (*qfn2(fn))(qenv(fn), v155, v158);
    nil = C_nil;
    if (exception_pending()) goto v164;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v164:
    popv(4);
    return nil;
}



/* Code for randpoly */

static Lisp_Object CC_randpoly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v277, v278, v279, v280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for randpoly");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-14] = v0;
/* end of prologue */
    stack[-15] = nil;
    stack[-12] = nil;
    stack[-7] = nil;
    v276 = elt(env, 1); /* lambda_l9xqtv_12 */
    stack[-13] = v276;
    v276 = (Lisp_Object)81; /* 5 */
    stack[-10] = v276;
    v276 = (Lisp_Object)1; /* 0 */
    stack[-9] = v276;
    v276 = (Lisp_Object)97; /* 6 */
    stack[-11] = v276;
    v276 = elt(env, 2); /* sparse */
    stack[-8] = v276;
    stack[-6] = qvalue(elt(env, 3)); /* wtl!* */
    qvalue(elt(env, 3)) = nil; /* wtl!* */
    v276 = stack[-14];
    fn = elt(env, 17); /* revlis */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-14] = v276;
    v276 = qcar(v276);
    stack[0] = v276;
    v277 = stack[0];
    v276 = elt(env, 4); /* list */
    if (!consp(v277)) goto v82;
    v277 = qcar(v277);
    if (!(v277 == v276)) goto v82;
    v276 = stack[0];
    v276 = qcdr(v276);
    goto v282;

v282:
    stack[0] = v276;
    v276 = stack[0];
    stack[-5] = v276;
    v276 = stack[-5];
    if (v276 == nil) goto v166;
    v276 = stack[-5];
    v276 = qcar(v276);
    stack[-1] = v276;
    v276 = stack[-1];
    if (!consp(v276)) goto v59;
    v276 = stack[-1];
    v277 = qcar(v276);
    v276 = elt(env, 7); /* equalopr */
    v276 = Lflagp(nil, v277, v276);
    env = stack[-16];
    if (v276 == nil) goto v59;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (v276 == nil) goto v59;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (!(v276 == nil)) goto v59;
    v276 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-1] = v276;
    v276 = (Lisp_Object)17; /* 1 */
    stack[-9] = v276;
    goto v283;

v283:
    v276 = elt(env, 8); /* g */
    v276 = Lgensym1(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[0] = v276;
    v278 = elt(env, 9); /* equal */
    v277 = stack[0];
    v276 = stack[-1];
    v277 = list3(v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    v276 = stack[-7];
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-7] = v276;
    v276 = stack[0];
    goto v88;

v88:
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-3] = v276;
    stack[-4] = v276;
    goto v46;

v46:
    v276 = stack[-5];
    v276 = qcdr(v276);
    stack[-5] = v276;
    v276 = stack[-5];
    if (v276 == nil) goto v111;
    stack[-2] = stack[-3];
    v276 = stack[-5];
    v276 = qcar(v276);
    stack[-1] = v276;
    v276 = stack[-1];
    if (!consp(v276)) goto v284;
    v276 = stack[-1];
    v277 = qcar(v276);
    v276 = elt(env, 7); /* equalopr */
    v276 = Lflagp(nil, v277, v276);
    env = stack[-16];
    if (v276 == nil) goto v284;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (v276 == nil) goto v284;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (!(v276 == nil)) goto v284;
    v276 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-1] = v276;
    v276 = (Lisp_Object)17; /* 1 */
    stack[-9] = v276;
    goto v285;

v285:
    v276 = elt(env, 8); /* g */
    v276 = Lgensym1(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[0] = v276;
    v278 = elt(env, 9); /* equal */
    v277 = stack[0];
    v276 = stack[-1];
    v277 = list3(v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    v276 = stack[-7];
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    stack[-7] = v276;
    v276 = stack[0];
    goto v286;

v286:
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    v276 = Lrplacd(nil, stack[-2], v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[-3] = v276;
    goto v46;

v284:
    v276 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    if (v276 == nil) goto v285;
    v276 = stack[-1];
    goto v286;

v111:
    v276 = stack[-4];
    goto v94;

v94:
    stack[0] = v276;
    v276 = stack[-15];
    if (v276 == nil) goto v55;
    v276 = stack[0];
    v276 = qcar(v276);
    stack[0] = v276;
    goto v55;

v55:
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    v276 = stack[-14];
    v276 = qcdr(v276);
    stack[-2] = v276;
    goto v123;

v123:
    v276 = stack[-2];
    if (v276 == nil) goto v287;
    v276 = stack[-2];
    v276 = qcar(v276);
    stack[-1] = v276;
    v277 = stack[-1];
    v276 = elt(env, 10); /* dense */
    if (v277 == v276) goto v118;
    v277 = stack[-1];
    v276 = elt(env, 2); /* sparse */
    if (v277 == v276) goto v118;
    v276 = stack[-1];
    if (!consp(v276)) goto v288;
    v276 = stack[-1];
    v277 = qcar(v276);
    v276 = elt(env, 7); /* equalopr */
    v276 = Lflagp(nil, v277, v276);
    env = stack[-16];
    if (v276 == nil) goto v288;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (v276 == nil) goto v288;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    if (!(v276 == nil)) goto v288;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 11); /* coeffs */
    if (!(v277 == v276)) goto v289;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 21); /* functionp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    if (v276 == nil) goto v289;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-13] = v276;
    goto v291;

v291:
    if (!(v276 == nil)) goto v292;

v288:
    v277 = stack[-1];
    v276 = elt(env, 16); /* "optional randpoly argument" */
    fn = elt(env, 22); /* typerr */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    goto v292;

v292:
    v276 = stack[-2];
    v276 = qcdr(v276);
    stack[-2] = v276;
    goto v123;

v289:
    v276 = stack[-1];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 12); /* expons */
    if (!(v277 == v276)) goto v293;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 21); /* functionp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    if (v276 == nil) goto v293;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-12] = v276;
    goto v291;

v293:
    v276 = stack[-1];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 13); /* (degree deg maxdeg) */
    v276 = Lmemq(nil, v277, v276);
    if (v276 == nil) goto v294;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 23); /* natnump */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    if (v276 == nil) goto v294;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-10] = v276;
    goto v291;

v294:
    v276 = stack[-1];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 14); /* (ord mindeg) */
    v276 = Lmemq(nil, v277, v276);
    if (v276 == nil) goto v295;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 23); /* natnump */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    if (v276 == nil) goto v295;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-9] = v276;
    goto v291;

v295:
    v276 = stack[-1];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 15); /* terms */
    if (!(v277 == v276)) goto v62;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 23); /* natnump */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    if (v276 == nil) goto v62;
    v276 = stack[-1];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v276 = qcar(v276);
    stack[-11] = v276;
    goto v291;

v62:
    v276 = nil;
    goto v291;

v118:
    v276 = stack[-1];
    stack[-8] = v276;
    goto v292;

v287:
    v277 = qvalue(elt(env, 6)); /* nil */
    v276 = (Lisp_Object)17; /* 1 */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v277 = stack[-9];
    v276 = stack[-10];
    v276 = (Lisp_Object)lesseq2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    v276 = v276 ? lisp_true : nil;
    env = stack[-16];
    if (v276 == nil) goto v296;
    v277 = stack[-8];
    v276 = elt(env, 2); /* sparse */
    if (v277 == v276) goto v297;
    v276 = stack[-15];
    if (v276 == nil) goto v298;
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v277 = stack[-9];
    v276 = (Lisp_Object)1; /* 0 */
    v276 = (Lisp_Object)greaterp2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    v276 = v276 ? lisp_true : nil;
    env = stack[-16];
    if (v276 == nil) goto v299;
    v277 = stack[0];
    v276 = stack[-9];
    fn = elt(env, 25); /* mksq */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    goto v299;

v299:
    v276 = stack[-9];
    v276 = add1(v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-2] = v276;
    goto v300;

v300:
    v277 = stack[-10];
    v276 = stack[-2];
    v276 = difference2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v276 = Lminusp(nil, v276);
    env = stack[-16];
    if (!(v276 == nil)) goto v296;
    stack[-3] = stack[-1];
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-1] = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v277 = stack[0];
    v276 = stack[-2];
    fn = elt(env, 25); /* mksq */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-3], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v276 = stack[-2];
    v276 = add1(v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-2] = v276;
    goto v300;

v296:
    v276 = stack[-7];
    if (v276 == nil) { Lisp_Object res = stack[-1]; popv(17); return onevalue(res); }
    stack[0] = stack[-7];
    v276 = stack[-1];
    fn = elt(env, 28); /* mk!*sq */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v276 = Lappend(nil, stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 29); /* subeval */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    {
        popv(17);
        fn = elt(env, 19); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v298:
    v278 = stack[0];
    v277 = stack[-10];
    v276 = stack[-9];
    fn = elt(env, 30); /* rand!-mons!-dense */
    v276 = (*qfnn(fn))(qenv(fn), 3, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-3] = v276;
    goto v301;

v301:
    v276 = stack[-3];
    if (v276 == nil) goto v296;
    v276 = stack[-3];
    v276 = qcar(v276);
    stack[-2] = v276;
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v277 = stack[-2];
    v276 = (Lisp_Object)17; /* 1 */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[-3] = v276;
    goto v301;

v297:
    v276 = stack[-12];
    if (v276 == nil) goto v302;
    v276 = stack[-15];
    if (v276 == nil) goto v303;
    v276 = (Lisp_Object)17; /* 1 */
    stack[-3] = v276;
    goto v304;

v304:
    v277 = stack[-11];
    v276 = stack[-3];
    v276 = difference2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v276 = Lminusp(nil, v276);
    env = stack[-16];
    if (!(v276 == nil)) goto v296;
    stack[-4] = stack[-1];
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = stack[0];
    v276 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-2], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-4], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v276 = stack[-3];
    v276 = add1(v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-3] = v276;
    goto v304;

v303:
    v276 = (Lisp_Object)17; /* 1 */
    stack[-4] = v276;
    goto v305;

v305:
    v277 = stack[-11];
    v276 = stack[-4];
    v276 = difference2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v276 = Lminusp(nil, v276);
    env = stack[-16];
    if (!(v276 == nil)) goto v296;
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v277 = v276;
    v276 = v277;
    v276 = qcar(v276);
    if (v276 == nil) goto v306;
    stack[-5] = stack[-1];
    v276 = stack[0];
    stack[-3] = v276;
    goto v307;

v307:
    v276 = stack[-3];
    if (v276 == nil) goto v308;
    v276 = stack[-3];
    v276 = qcar(v276);
    stack[-2] = v277;
    stack[-1] = v276;
    v276 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-2], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v277 = v276;
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[-3] = v276;
    goto v307;

v308:
    v276 = v277;
    fn = elt(env, 27); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-5], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    goto v306;

v306:
    v276 = stack[-4];
    v276 = add1(v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-4] = v276;
    goto v305;

v302:
    v280 = stack[0];
    v279 = stack[-11];
    v278 = stack[-10];
    v277 = stack[-9];
    v276 = stack[-15];
    fn = elt(env, 33); /* rand!-mons!-sparse */
    v276 = (*qfnn(fn))(qenv(fn), 5, v280, v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-3] = v276;
    goto v309;

v309:
    v276 = stack[-3];
    if (v276 == nil) goto v296;
    v276 = stack[-3];
    v276 = qcar(v276);
    stack[-2] = v276;
    v277 = stack[-13];
    v276 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    v277 = stack[-2];
    v276 = (Lisp_Object)17; /* 1 */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v276 = (*qfn2(fn))(qenv(fn), stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-16];
    stack[-1] = v276;
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[-3] = v276;
    goto v309;

v59:
    v276 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    if (v276 == nil) goto v283;
    v276 = stack[-1];
    goto v88;

v166:
    v276 = qvalue(elt(env, 6)); /* nil */
    goto v94;

v82:
    v276 = qvalue(elt(env, 5)); /* t */
    stack[-15] = v276;
    v276 = stack[0];
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-16];
    goto v282;
/* error exit handlers */
v290:
    popv(17);
    return nil;
v281:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    popv(17);
    return nil;
}



/* Code for lambda_l9xqtv_12 */

static Lisp_Object MS_CDECL CC_lambda_l9xqtv_12(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lambda_l9xqtv_12");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqtv_12");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v169 = (Lisp_Object)3185; /* 199 */
    fn = elt(env, 1); /* random */
    v170 = (*qfn1(fn))(qenv(fn), v169);
    errexit();
    v169 = (Lisp_Object)1585; /* 99 */
    return difference2(v170, v169);
}



/* Code for chksymmetries!&subst */

static Lisp_Object MS_CDECL CC_chksymmetriesGsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160, v58, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&subst");
#endif
    if (stack >= stacklimit)
    {
        push4(v22,v15,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v80,v15,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v15;
    stack[-2] = v80;
    stack[-3] = v0;
/* end of prologue */

v99:
    v159 = stack[-1];
    if (v159 == nil) goto v8;
    v164 = stack[-3];
    v58 = stack[-2];
    v159 = stack[-1];
    v160 = qcar(v159);
    v159 = stack[0];
    fn = elt(env, 2); /* chksymmetries!&sub1 */
    v159 = (*qfnn(fn))(qenv(fn), 4, v164, v58, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-5];
    v160 = v159;
    v159 = v160;
    if (v159 == nil) goto v45;
    stack[-4] = v160;
    v164 = stack[-3];
    v58 = stack[-2];
    v159 = stack[-1];
    v160 = qcdr(v159);
    v159 = stack[0];
    v159 = CC_chksymmetriesGsubst(env, 4, v164, v58, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v316;
    {
        Lisp_Object v78 = stack[-4];
        popv(6);
        return cons(v78, v159);
    }

v45:
    v164 = stack[-3];
    v58 = stack[-2];
    v159 = stack[-1];
    v160 = qcdr(v159);
    v159 = stack[0];
    stack[-3] = v164;
    stack[-2] = v58;
    stack[-1] = v160;
    stack[0] = v159;
    goto v99;

v8:
    v159 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v159); }
/* error exit handlers */
v316:
    popv(6);
    return nil;
}



/* Code for free */

static Lisp_Object CC_free(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 2); /* freeind */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    if (v43 == nil) goto v18;
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    {
        popv(2);
        fn = elt(env, 2); /* freeind */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v18:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for lengthreval */

static Lisp_Object CC_lengthreval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v323, v324;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthreval");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v322 = stack[0];
    v323 = Llength(nil, v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v322 = (Lisp_Object)17; /* 1 */
    if (v323 == v322) goto v125;
    v322 = elt(env, 1); /* "LENGTH called with wrong number of arguments" 
*/
    v323 = v322;
    v322 = v323;
    qvalue(elt(env, 2)) = v322; /* errmsg!* */
    v322 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v322 == nil)) goto v274;
    v322 = v323;
    fn = elt(env, 11); /* lprie */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v274;

v274:
    v322 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v125;

v125:
    v322 = stack[0];
    v322 = qcar(v322);
    stack[0] = v322;
    v322 = stack[0];
    if (!(symbolp(v322))) goto v275;
    v323 = stack[0];
    v322 = elt(env, 4); /* rtype */
    v323 = get(v323, v322);
    env = stack[-2];
    v322 = elt(env, 5); /* array */
    if (!(v323 == v322)) goto v275;
    v324 = elt(env, 6); /* list */
    v323 = stack[0];
    v322 = elt(env, 7); /* dimension */
    v322 = get(v323, v322);
    popv(3);
    return cons(v324, v322);

v275:
    v322 = stack[0];
    fn = elt(env, 12); /* aeval */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    stack[-1] = v322;
    v322 = stack[-1];
    fn = elt(env, 13); /* getrtype */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v324 = v322;
    if (v322 == nil) goto v58;
    v323 = v324;
    v322 = elt(env, 8); /* lengthfn */
    v322 = get(v323, v322);
    env = stack[-2];
    v323 = v322;
    if (v322 == nil) goto v58;
    v322 = stack[-1];
        popv(3);
        return Lapply1(nil, v323, v322);

v58:
    v322 = stack[-1];
    if (!consp(v322)) goto v325;
    v322 = stack[-1];
    v322 = qcar(v322);
    if (!(symbolp(v322))) goto v326;
    v322 = stack[-1];
    v323 = qcar(v322);
    v322 = elt(env, 8); /* lengthfn */
    v322 = get(v323, v322);
    env = stack[-2];
    v323 = v322;
    if (v322 == nil) goto v326;
    v322 = stack[-1];
    v322 = qcdr(v322);
        popv(3);
        return Lapply1(nil, v323, v322);

v326:
    v322 = v324;
    if (v322 == nil) goto v154;
    v322 = elt(env, 9); /* "LENGTH not defined for argument of type" */
    v323 = v324;
    v322 = list2(v322, v323);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    fn = elt(env, 11); /* lprie */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    goto v159;

v159:
    v322 = nil;
    { popv(3); return onevalue(v322); }

v154:
    v323 = stack[0];
    v322 = elt(env, 10); /* "LENGTH argument" */
    fn = elt(env, 14); /* typerr */
    v322 = (*qfn2(fn))(qenv(fn), v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v32;
    goto v159;

v325:
    v322 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v322); }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v100 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v100; /* dmode!* */
    v100 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-1] = v100;
    v274 = stack[-1];
    v100 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v100 = (*qfn2(fn))(qenv(fn), v274, v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v100 = stack[-1];
    v274 = qcar(v100);
    v100 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v100 = (*qfn2(fn))(qenv(fn), v274, v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v100); }
/* error exit handlers */
v51:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for lto_alunion */

static Lisp_Object CC_lto_alunion(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_alunion");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v169 = v0;
/* end of prologue */
    v170 = v169;
    v169 = elt(env, 1); /* union */
    {
        fn = elt(env, 2); /* lto_almerge */
        return (*qfn2(fn))(qenv(fn), v170, v169);
    }
}



/* Code for get!*order */

static Lisp_Object CC_getHorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*order");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    fn = elt(env, 1); /* get!*elements */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    errexit();
        return Llength(nil, v8);
}



/* Code for qqe_simplqequal */

static Lisp_Object CC_qqe_simplqequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v360, v361, v362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplqequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v360 = v80;
    stack[0] = v0;
/* end of prologue */

v99:
    v360 = stack[0];
    fn = elt(env, 6); /* qqe_arg2r */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-7] = v360;
    v360 = stack[0];
    fn = elt(env, 7); /* qqe_arg2l */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-8] = v360;
    v361 = stack[-7];
    v360 = stack[-8];
    if (equal(v361, v360)) goto v55;
    v360 = stack[-8];
    fn = elt(env, 8); /* qqe_qprefix!-var */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-6] = v360;
    v360 = stack[-7];
    fn = elt(env, 8); /* qqe_qprefix!-var */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-5] = v360;
    v361 = stack[-6];
    v360 = stack[-5];
    if (v361 == v360) goto v48;
    v361 = stack[-6];
    v360 = elt(env, 2); /* qepsilon */
    if (v361 == v360) goto v48;
    v361 = stack[-5];
    v360 = elt(env, 2); /* qepsilon */
    if (!(v361 == v360)) goto v147;

v48:
    v360 = stack[-7];
    fn = elt(env, 9); /* qqe_number!-of!-adds!-in!-qterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-3] = v360;
    v360 = stack[-8];
    fn = elt(env, 9); /* qqe_number!-of!-adds!-in!-qterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-4] = v360;
    v360 = stack[-7];
    fn = elt(env, 10); /* qqe_number!-of!-tails!-in!-qterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-1] = v360;
    v360 = stack[-8];
    fn = elt(env, 10); /* qqe_number!-of!-tails!-in!-qterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[-2] = v360;
    v361 = stack[-6];
    v360 = stack[-5];
    if (!(v361 == v360)) goto v113;
    v361 = stack[-3];
    v360 = stack[-1];
    v360 = (Lisp_Object)geq2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v360 = v360 ? lisp_true : nil;
    env = stack[-9];
    if (!(v360 == nil)) goto v363;
    v361 = stack[-4];
    v360 = stack[-2];
    v360 = (Lisp_Object)geq2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v360 = v360 ? lisp_true : nil;
    env = stack[-9];
    if (!(v360 == nil)) goto v363;

v113:
    v361 = stack[-7];
    v360 = elt(env, 2); /* qepsilon */
    if (!(v361 == v360)) goto v72;
    v361 = stack[-4];
    v360 = stack[-2];
    v360 = (Lisp_Object)greaterp2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v360 = v360 ? lisp_true : nil;
    env = stack[-9];
    if (v360 == nil) goto v72;
    v360 = elt(env, 3); /* false */
    { popv(10); return onevalue(v360); }

v72:
    v361 = stack[-8];
    v360 = elt(env, 2); /* qepsilon */
    if (!(v361 == v360)) goto v134;
    v361 = stack[-3];
    v360 = stack[-1];
    v360 = (Lisp_Object)greaterp2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v360 = v360 ? lisp_true : nil;
    env = stack[-9];
    if (v360 == nil) goto v134;
    v360 = elt(env, 3); /* false */
    { popv(10); return onevalue(v360); }

v134:
    v361 = stack[-7];
    v360 = elt(env, 2); /* qepsilon */
    if (!(v361 == v360)) goto v119;
    v361 = stack[-3];
    v360 = (Lisp_Object)1; /* 0 */
    if (!(v361 == v360)) goto v119;
    v361 = stack[-4];
    v360 = (Lisp_Object)1; /* 0 */
    if (!(v361 == v360)) goto v119;
    v361 = stack[-6];
    v360 = elt(env, 2); /* qepsilon */
    if (v361 == v360) goto v115;
    v360 = stack[-8];
    fn = elt(env, 11); /* qqe_simplterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    v361 = elt(env, 5); /* qequal */
    v362 = v360;
    v360 = stack[-7];
    {
        popv(10);
        fn = elt(env, 12); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v361, v362, v360);
    }

v115:
    v360 = elt(env, 1); /* true */
    { popv(10); return onevalue(v360); }

v119:
    v361 = stack[-8];
    v360 = elt(env, 2); /* qepsilon */
    if (!(v361 == v360)) goto v147;
    v361 = stack[-3];
    v360 = (Lisp_Object)1; /* 0 */
    if (!(v361 == v360)) goto v147;
    v361 = stack[-4];
    v360 = (Lisp_Object)1; /* 0 */
    if (!(v361 == v360)) goto v147;
    v361 = stack[-5];
    v360 = elt(env, 2); /* qepsilon */
    if (v361 == v360) goto v364;
    v360 = stack[-7];
    fn = elt(env, 11); /* qqe_simplterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[0] = v360;
    v362 = elt(env, 5); /* qequal */
    v361 = stack[-8];
    v360 = stack[0];
    {
        popv(10);
        fn = elt(env, 12); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v362, v361, v360);
    }

v364:
    v360 = elt(env, 1); /* true */
    { popv(10); return onevalue(v360); }

v147:
    v360 = stack[-7];
    fn = elt(env, 11); /* qqe_simplterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[0] = v360;
    v360 = stack[-8];
    fn = elt(env, 11); /* qqe_simplterm */
    v360 = (*qfn1(fn))(qenv(fn), v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    v362 = stack[-7];
    v361 = stack[0];
    if (!(equal(v362, v361))) goto v365;
    v362 = stack[-8];
    v361 = v360;
    if (!(equal(v362, v361))) goto v365;
    v362 = elt(env, 5); /* qequal */
    v361 = v360;
    v360 = stack[0];
    {
        popv(10);
        fn = elt(env, 12); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v362, v361, v360);
    }

v365:
    v362 = elt(env, 5); /* qequal */
    v361 = v360;
    v360 = stack[0];
    fn = elt(env, 12); /* qqe_mk2 */
    v360 = (*qfnn(fn))(qenv(fn), 3, v362, v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    stack[0] = v360;
    goto v99;

v363:
    v361 = stack[-3];
    v360 = stack[-1];
    stack[0] = difference2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    v361 = stack[-4];
    v360 = stack[-2];
    v360 = difference2(v361, v360);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-9];
    if (equal(stack[0], v360)) goto v113;
    v360 = elt(env, 3); /* false */
    { popv(10); return onevalue(v360); }

v55:
    v360 = elt(env, 1); /* true */
    { popv(10); return onevalue(v360); }
/* error exit handlers */
v3:
    popv(10);
    return nil;
}



/* Code for pasf_mkop */

static Lisp_Object CC_pasf_mkop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v83, v84, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_mkop");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v84 = v80;
    v146 = v0;
/* end of prologue */
    v83 = v146;
    v96 = elt(env, 1); /* (cong ncong) */
    v96 = Lmemq(nil, v83, v96);
    if (v96 == nil) { popv(2); return onevalue(v146); }
    stack[0] = v146;
    v96 = v84;
    if (v96 == nil) goto v100;
    v96 = v84;
    goto v56;

v56:
    {
        Lisp_Object v46 = stack[0];
        popv(2);
        return cons(v46, v96);
    }

v100:
    v96 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v96 == nil)) goto v101;
    v96 = elt(env, 3); /* "Modulo 0 congruence created" */
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    fn = elt(env, 4); /* lprie */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    goto v101;

v101:
    v96 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v96 = nil;
    goto v56;
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for vdp_sugar */

static Lisp_Object CC_vdp_sugar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v314;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_sugar");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v282 = stack[0];
    fn = elt(env, 3); /* vdp_zero!? */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    if (!(v282 == nil)) goto v18;
    v282 = qvalue(elt(env, 1)); /* !*cgbsugar */
    if (v282 == nil) goto v18;
    v314 = stack[0];
    v282 = elt(env, 2); /* sugar */
    fn = elt(env, 4); /* vdp_getprop */
    v282 = (*qfn2(fn))(qenv(fn), v314, v282);
    nil = C_nil;
    if (exception_pending()) goto v51;
    if (!(v282 == nil)) { popv(2); return onevalue(v282); }
    v282 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v282); }

v18:
    v282 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v282); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for applyml */

static Lisp_Object MS_CDECL CC_applyml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyml");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 8); /* lex */
    v142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    v142 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v158 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    v142 = qvalue(elt(env, 2)); /* rdlist!* */
    v158 = Lassoc(nil, v158, v142);
    v142 = v158;
    if (v158 == nil) goto v90;
    v158 = v142;
    v158 = qcdr(v158);
    v158 = qcar(v158);
    v142 = qcdr(v142);
    v142 = qcdr(v142);
    {
        popv(1);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v158, v142);
    }

v90:
    v158 = qvalue(elt(env, 1)); /* char */
    v142 = elt(env, 3); /* (i d e n t !/) */
    if (equal(v158, v142)) goto v101;
    v158 = qvalue(elt(env, 1)); /* char */
    v142 = elt(env, 4); /* (c o m p o s e !/) */
    if (equal(v158, v142)) goto v101;
    v158 = qvalue(elt(env, 1)); /* char */
    v142 = elt(env, 6); /* (i n v e r s e !/) */
    if (equal(v158, v142)) goto v46;
    v142 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v158 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    v142 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v142 = (*qfn2(fn))(qenv(fn), v158, v142);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v142 = nil;
    { popv(1); return onevalue(v142); }

v46:
    v142 = qvalue(elt(env, 7)); /* t */
    { popv(1); return onevalue(v142); }

v101:
    v142 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v142); }
/* error exit handlers */
v155:
    popv(1);
    return nil;
}



/* Code for xpdiff */

static Lisp_Object CC_xpdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v41 = stack[-1];
    if (v41 == nil) goto v37;
    v41 = stack[0];
    if (v41 == nil) goto v43;
    v41 = stack[0];
    v42 = qcar(v41);
    v41 = stack[-1];
    v41 = qcar(v41);
    v41 = (Lisp_Object)greaterp2(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v367;
    v41 = v41 ? lisp_true : nil;
    env = stack[-3];
    if (v41 == nil) goto v82;
    v41 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v41); }

v82:
    v41 = stack[-1];
    v42 = qcdr(v41);
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = CC_xpdiff(env, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-3];
    stack[-2] = v41;
    v42 = stack[-2];
    v41 = elt(env, 4); /* failed */
    if (v42 == v41) goto v313;
    v41 = stack[-1];
    v42 = qcar(v41);
    v41 = stack[0];
    v41 = qcar(v41);
    v42 = difference2(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v367;
    v41 = stack[-2];
    popv(4);
    return cons(v42, v41);

v313:
    v41 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v41); }

v43:
    v41 = elt(env, 3); /* "A too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v41);
    }

v37:
    v41 = stack[0];
    if (v41 == nil) goto v169;
    v41 = elt(env, 2); /* "B too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v41);
    }

v169:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v41); }
/* error exit handlers */
v367:
    popv(4);
    return nil;
}



/* Code for ps!:constmult!-erule */

static Lisp_Object CC_psTconstmultKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v100, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:constmult-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v100 = v80;
    v274 = v0;
/* end of prologue */
    v315 = v274;
    v315 = qcdr(v315);
    stack[0] = qcar(v315);
    v315 = v274;
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcar(v315);
    fn = elt(env, 1); /* ps!:evaluate */
    v315 = (*qfn2(fn))(qenv(fn), v315, v100);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-1];
    {
        Lisp_Object v50 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v50, v315);
    }
/* error exit handlers */
v314:
    popv(2);
    return nil;
}



/* Code for mkuniquewedge */

static Lisp_Object CC_mkuniquewedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v310, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuniquewedge");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v7;

v7:
    v310 = stack[0];
    if (v310 == nil) goto v8;
    v310 = stack[0];
    v310 = qcar(v310);
    v310 = qcar(v310);
    fn = elt(env, 2); /* mkuniquewedge1 */
    v311 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v310 = stack[0];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    fn = elt(env, 3); /* multpfsq */
    v311 = (*qfn2(fn))(qenv(fn), v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v310 = stack[-1];
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    stack[-1] = v310;
    v310 = stack[0];
    v310 = qcdr(v310);
    stack[0] = v310;
    goto v7;

v8:
    v310 = qvalue(elt(env, 1)); /* nil */
    v311 = v310;
    goto v125;

v125:
    v310 = stack[-1];
    if (v310 == nil) { popv(3); return onevalue(v311); }
    v310 = stack[-1];
    v310 = qcar(v310);
    fn = elt(env, 4); /* addpf */
    v310 = (*qfn2(fn))(qenv(fn), v310, v311);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v311 = v310;
    v310 = stack[-1];
    v310 = qcdr(v310);
    stack[-1] = v310;
    goto v125;
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for dvertex!-to!-projector */

static Lisp_Object MS_CDECL CC_dvertexKtoKprojector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v357, v358, v368;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvertex-to-projector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvertex-to-projector");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v15;
    stack[-1] = v80;
    stack[-2] = v0;
/* end of prologue */
    v357 = stack[-2];
    v357 = qcdr(v357);
    v368 = qcar(v357);
    v358 = stack[-1];
    v357 = stack[0];
    fn = elt(env, 1); /* mktails */
    v357 = (*qfnn(fn))(qenv(fn), 3, v368, v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    stack[-3] = v357;
    v357 = stack[-3];
    v357 = qcar(v357);
    fn = elt(env, 2); /* repeatsp */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    if (v357 == nil) goto v162;
    v357 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v357); }

v162:
    v357 = stack[-2];
    v357 = qcdr(v357);
    v357 = qcdr(v357);
    v368 = qcar(v357);
    v358 = stack[-1];
    v357 = stack[-3];
    v357 = qcdr(v357);
    fn = elt(env, 1); /* mktails */
    v357 = (*qfnn(fn))(qenv(fn), 3, v368, v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    stack[-1] = v357;
    v357 = stack[-1];
    v357 = qcar(v357);
    fn = elt(env, 2); /* repeatsp */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    if (v357 == nil) goto v146;
    v357 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v357); }

v146:
    v357 = stack[-1];
    v357 = qcdr(v357);
    stack[0] = v357;
    v357 = stack[-3];
    stack[-2] = qcar(v357);
    v357 = stack[-1];
    v357 = qcar(v357);
    v357 = Lreverse(nil, v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    fn = elt(env, 3); /* prop!-simp */
    v357 = (*qfn2(fn))(qenv(fn), stack[-2], v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    stack[-2] = v357;
    v357 = stack[-2];
    fn = elt(env, 4); /* mk!-contract!-coeff */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-4];
    stack[-1] = v357;
    v357 = stack[-2];
    v357 = qcdr(v357);
    v368 = qcar(v357);
    v357 = stack[-2];
    v357 = qcdr(v357);
    v358 = qcdr(v357);
    v357 = stack[0];
    fn = elt(env, 5); /* dpropagator */
    v357 = (*qfnn(fn))(qenv(fn), 3, v368, v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v369;
    {
        Lisp_Object v370 = stack[-1];
        popv(5);
        return cons(v370, v357);
    }
/* error exit handlers */
v369:
    popv(5);
    return nil;
}



/* Code for dp_prod */

static Lisp_Object CC_dp_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v275 = stack[-1];
    stack[-2] = Llength(nil, v275);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v275 = stack[0];
    v275 = Llength(nil, v275);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v275 = (Lisp_Object)lesseq2(stack[-2], v275);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v275 = v275 ? lisp_true : nil;
    env = stack[-3];
    if (v275 == nil) goto v50;
    v147 = stack[-1];
    v275 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v147, v275);
    }

v50:
    v147 = stack[0];
    v275 = stack[-1];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v147, v275);
    }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for find!-null!-space */

static Lisp_Object CC_findKnullKspace(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v312, v166, v310, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-null-space");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v80;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    v312 = (Lisp_Object)17; /* 1 */
    stack[0] = v312;
    goto v157;

v157:
    v166 = stack[-1];
    v312 = stack[0];
    v312 = (Lisp_Object)(int32_t)((int32_t)v166 - (int32_t)v312 + TAG_FIXNUM);
    v312 = ((intptr_t)(v312) < 0 ? lisp_true : nil);
    if (v312 == nil) goto v282;
    v310 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v166 = stack[-2];
    v312 = stack[-1];
    fn = elt(env, 3); /* tidy!-up!-null!-vectors */
    v312 = (*qfnn(fn))(qenv(fn), 3, v310, v166, v312);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v312); }

v282:
    v311 = stack[0];
    v310 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v166 = stack[-2];
    v312 = stack[-1];
    fn = elt(env, 4); /* clear!-column */
    v312 = (*qfnn(fn))(qenv(fn), 4, v311, v310, v166, v312);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    qvalue(elt(env, 1)) = v312; /* null!-space!-basis */
    v312 = stack[0];
    v312 = (Lisp_Object)((int32_t)(v312) + 0x10);
    stack[0] = v312;
    goto v157;
/* error exit handlers */
v98:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for lowestdeg */

static Lisp_Object MS_CDECL CC_lowestdeg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v83, v84;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "lowestdeg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowestdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v15;
    v96 = v80;
    v83 = v0;
/* end of prologue */

v8:
    v84 = v83;
    if (v84 == nil) return onevalue(v95);
    v95 = v83;
    if (!consp(v95)) goto v89;
    v95 = v83;
    v95 = qcar(v95);
    if (!consp(v95)) goto v89;
    v95 = v83;
    v95 = qcar(v95);
    v95 = qcar(v95);
    v84 = qcar(v95);
    v95 = v96;
    if (!(equal(v84, v95))) goto v89;
    v95 = v83;
    v95 = qcdr(v95);
    v84 = v95;
    v95 = v83;
    v95 = qcar(v95);
    v95 = qcar(v95);
    v95 = qcdr(v95);
    v83 = v84;
    goto v8;

v89:
    v95 = (Lisp_Object)1; /* 0 */
    return onevalue(v95);
}



/* Code for simprad */

static Lisp_Object CC_simprad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprad");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v80;
    stack[0] = v0;
/* end of prologue */
    v3 = qvalue(elt(env, 1)); /* !*reduced */
    if (v3 == nil) goto v90;
    v3 = stack[0];
    v4 = qcar(v3);
    v3 = stack[-3];
    fn = elt(env, 8); /* radfa */
    stack[-1] = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[0];
    v4 = qcdr(v3);
    v3 = stack[-3];
    fn = elt(env, 8); /* radfa */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 9); /* invsq */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    {
        Lisp_Object v53 = stack[-1];
        popv(7);
        fn = elt(env, 10); /* multsq */
        return (*qfn2(fn))(qenv(fn), v53, v3);
    }

v90:
    stack[-4] = nil;
    v3 = qvalue(elt(env, 2)); /* !*rationalize */
    if (v3 == nil) goto v78;
    v3 = stack[0];
    v4 = qcdr(v3);
    v3 = (Lisp_Object)17; /* 1 */
    v3 = list2(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-1] = v3;
    v3 = stack[0];
    stack[-2] = qcar(v3);
    v3 = stack[0];
    stack[0] = qcdr(v3);
    v3 = stack[-3];
    v3 = sub1(v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 11); /* exptf */
    v3 = (*qfn2(fn))(qenv(fn), stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 12); /* multf */
    v4 = (*qfn2(fn))(qenv(fn), stack[-2], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = (Lisp_Object)17; /* 1 */
    v3 = cons(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[0] = v3;
    goto v325;

v325:
    v4 = stack[-3];
    v3 = (Lisp_Object)33; /* 2 */
    if (!(v4 == v3)) goto v389;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 13); /* minusf */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    if (v3 == nil) goto v389;
    v3 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v3;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 14); /* negf */
    v4 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[-3];
    fn = elt(env, 15); /* radf */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-2] = v3;
    goto v390;

v390:
    stack[-5] = elt(env, 4); /* quotient */
    v3 = stack[-2];
    v3 = qcdr(v3);
    fn = elt(env, 16); /* retimes */
    stack[0] = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[-1];
    v3 = qcdr(v3);
    fn = elt(env, 16); /* retimes */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = list3(stack[-5], stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 17); /* simp */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v3;
    v3 = stack[-5];
    v3 = qcar(v3);
    if (!consp(v3)) goto v72;
    v3 = stack[-5];
    v3 = qcar(v3);
    v3 = qcar(v3);
    if (!(!consp(v3))) goto v24;

v72:
    v3 = stack[-5];
    v3 = qcdr(v3);
    if (!consp(v3)) goto v391;
    v3 = stack[-5];
    v3 = qcdr(v3);
    v3 = qcar(v3);
    if (!(!consp(v3))) goto v24;

v391:
    v3 = stack[-5];
    v4 = qcar(v3);
    v3 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 18); /* prepf1 */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v4 = v3;
    v3 = v4;
    if (v3 == nil) goto v392;
    v3 = v4;
    fn = elt(env, 19); /* replus */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v4 = v3;
    goto v76;

v76:
    v3 = stack[-3];
    fn = elt(env, 20); /* mkrootsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[-5];
    v4 = qcdr(v3);
    v3 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 18); /* prepf1 */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v4 = v3;
    v3 = v4;
    if (v3 == nil) goto v346;
    v3 = v4;
    fn = elt(env, 19); /* replus */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v4 = v3;
    goto v348;

v348:
    v3 = stack[-3];
    fn = elt(env, 20); /* mkrootsq */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 9); /* invsq */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v3 = (*qfn2(fn))(qenv(fn), stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v3;
    goto v393;

v393:
    v3 = qvalue(elt(env, 7)); /* !*precise */
    if (v3 == nil) goto v394;
    v3 = stack[-3];
    v3 = Levenp(nil, v3);
    env = stack[-6];
    if (v3 == nil) goto v394;
    v3 = stack[-2];
    v4 = qcar(v3);
    v3 = (Lisp_Object)17; /* 1 */
    v3 = cons(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[0] = v3;
    goto v395;

v395:
    v4 = (Lisp_Object)17; /* 1 */
    v3 = stack[-1];
    v3 = qcar(v3);
    v3 = cons(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v4 = (*qfn2(fn))(qenv(fn), stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[-5];
    fn = elt(env, 10); /* multsq */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v3;
    v3 = stack[-4];
    if (v3 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v4 = (Lisp_Object)-15; /* -1 */
    v3 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 20); /* mkrootsq */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v3 = (*qfn2(fn))(qenv(fn), stack[0], v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    stack[-5] = v3;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v394:
    v3 = stack[-2];
    v4 = qcar(v3);
    v3 = (Lisp_Object)17; /* 1 */
    v3 = cons(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[0] = v3;
    goto v395;

v346:
    v3 = (Lisp_Object)1; /* 0 */
    v4 = v3;
    goto v348;

v392:
    v3 = (Lisp_Object)1; /* 0 */
    v4 = v3;
    goto v76;

v24:
    v3 = stack[-4];
    if (v3 == nil) goto v107;
    v3 = qvalue(elt(env, 5)); /* nil */
    stack[-4] = v3;
    v3 = stack[-5];
    v3 = qcar(v3);
    fn = elt(env, 14); /* negf */
    v4 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v3 = stack[-5];
    v3 = qcdr(v3);
    v3 = cons(v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v3;
    goto v107;

v107:
    v3 = stack[-5];
    v3 = qcar(v3);
    if (v3 == nil) goto v109;
    v4 = stack[-5];
    v3 = elt(env, 6); /* prepf */
    fn = elt(env, 21); /* sqform */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v4 = v3;
    goto v364;

v364:
    v3 = stack[-3];
    fn = elt(env, 20); /* mkrootsq */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v3;
    goto v393;

v109:
    v3 = (Lisp_Object)1; /* 0 */
    v4 = v3;
    goto v364;

v389:
    v3 = stack[0];
    v4 = qcar(v3);
    v3 = stack[-3];
    fn = elt(env, 15); /* radf */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-2] = v3;
    goto v390;

v78:
    v3 = stack[0];
    v4 = qcdr(v3);
    v3 = stack[-3];
    fn = elt(env, 15); /* radf */
    v3 = (*qfn2(fn))(qenv(fn), v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-1] = v3;
    goto v325;
/* error exit handlers */
v52:
    popv(7);
    return nil;
}



/* Code for reduce!-mod!-eig */

static Lisp_Object CC_reduceKmodKeig(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v398, v399, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eig");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v398 = v80;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = v398;
    goto v169;

v169:
    v398 = stack[0];
    if (v398 == nil) goto v245;
    v399 = stack[-1];
    v398 = stack[0];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    fn = elt(env, 2); /* reduce!-mod!-eigf */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    stack[-6] = v398;
    v398 = qcar(v398);
    if (v398 == nil) goto v56;
    v398 = stack[0];
    v398 = qcar(v398);
    v133 = qcar(v398);
    v399 = stack[-6];
    v398 = stack[-2];
    v398 = acons(v133, v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    stack[-2] = v398;
    goto v56;

v56:
    v398 = stack[0];
    v398 = qcdr(v398);
    stack[0] = v398;
    goto v169;

v245:
    v398 = (Lisp_Object)17; /* 1 */
    stack[-6] = v398;
    v398 = stack[-2];
    stack[0] = v398;
    goto v312;

v312:
    v398 = stack[0];
    if (v398 == nil) goto v313;
    v399 = stack[-6];
    v398 = stack[0];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = qcdr(v398);
    fn = elt(env, 3); /* lcm */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    stack[-6] = v398;
    v398 = stack[0];
    v398 = qcdr(v398);
    stack[0] = v398;
    goto v312;

v313:
    v398 = stack[-2];
    v398 = Lreverse(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    stack[-5] = v398;
    v398 = stack[-5];
    if (v398 == nil) goto v78;
    v398 = stack[-5];
    v398 = qcar(v398);
    stack[-1] = qcar(v398);
    v398 = stack[-5];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    stack[0] = qcar(v398);
    v399 = stack[-6];
    v398 = stack[-5];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = qcdr(v398);
    fn = elt(env, 4); /* quotf */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v398 = (*qfn2(fn))(qenv(fn), stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = cons(stack[-1], v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    stack[-3] = v398;
    stack[-4] = v398;
    goto v145;

v145:
    v398 = stack[-5];
    v398 = qcdr(v398);
    stack[-5] = v398;
    v398 = stack[-5];
    if (v398 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    stack[-2] = stack[-3];
    v398 = stack[-5];
    v398 = qcar(v398);
    stack[-1] = qcar(v398);
    v398 = stack[-5];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    stack[0] = qcar(v398);
    v399 = stack[-6];
    v398 = stack[-5];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = qcdr(v398);
    fn = elt(env, 4); /* quotf */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v398 = (*qfn2(fn))(qenv(fn), stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = cons(stack[-1], v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = Lrplacd(nil, stack[-2], v398);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-7];
    v398 = stack[-3];
    v398 = qcdr(v398);
    stack[-3] = v398;
    goto v145;

v78:
    v398 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v398); }
/* error exit handlers */
v400:
    popv(8);
    return nil;
}



/* Code for preptaylor!*2 */

static Lisp_Object CC_preptaylorH2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v357, v358;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*2");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v112 = stack[-1];
    v112 = qcdr(v112);
    fn = elt(env, 4); /* prepsq!* */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v358 = v112;
    v357 = (Lisp_Object)1; /* 0 */
    if (v358 == v357) goto v245;
    v358 = v112;
    v357 = elt(env, 2); /* quotient */
    if (!consp(v358)) goto v145;
    v358 = qcar(v358);
    if (!(v358 == v357)) goto v145;
    v357 = v112;
    v357 = qcdr(v357);
    v358 = qcar(v357);
    v357 = elt(env, 3); /* minus */
    if (!consp(v358)) goto v145;
    v358 = qcar(v358);
    if (!(v358 == v357)) goto v145;
    stack[-2] = elt(env, 3); /* minus */
    v358 = elt(env, 2); /* quotient */
    v357 = v112;
    v357 = qcdr(v357);
    v357 = qcar(v357);
    v357 = qcdr(v357);
    v357 = qcar(v357);
    v112 = qcdr(v112);
    v112 = qcdr(v112);
    v112 = qcar(v112);
    v112 = list3(v358, v357, v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v112 = list2(stack[-2], v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-2] = v112;
    goto v316;

v316:
    v112 = stack[-1];
    v357 = qcar(v112);
    v112 = stack[0];
    fn = elt(env, 5); /* preptaycoeff */
    v112 = (*qfn2(fn))(qenv(fn), v357, v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v112 = cons(stack[-2], v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v325;
    popv(4);
    return ncons(v112);

v145:
    stack[-2] = v112;
    goto v316;

v245:
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v112); }
/* error exit handlers */
v325:
    popv(4);
    return nil;
}



/* Code for conjgd */

static Lisp_Object CC_conjgd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v354, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjgd");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v354 = stack[-1];
    if (!consp(v354)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v354 = stack[-1];
    if (!consp(v354)) goto v55;
    v354 = stack[-1];
    v354 = qcar(v354);
    if (!(!consp(v354))) goto v161;

v55:
    v354 = stack[-1];
    v73 = qcar(v354);
    v354 = elt(env, 1); /* cmpxfn */
    v354 = get(v73, v354);
    env = stack[-3];
    v73 = v354;
    if (v354 == nil) goto v161;
    stack[-2] = v73;
    v354 = stack[-1];
    v354 = qcdr(v354);
    stack[0] = qcar(v354);
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    if (is_number(v354)) goto v95;
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    if (!consp(v354)) goto v310;
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    if (!(!consp(v354))) goto v78;

v310:
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    if (is_number(v354)) goto v78;
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    fn = elt(env, 3); /* !:minus */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    goto v275;

v275:
    {
        Lisp_Object v129 = stack[-2];
        Lisp_Object v285 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v129, v285, v354);
    }

v78:
    v354 = stack[-1];
    v73 = qcar(v354);
    v354 = elt(env, 2); /* realtype */
    v73 = get(v73, v354);
    env = stack[-3];
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    v354 = cons(v73, v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    fn = elt(env, 3); /* !:minus */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    v354 = qcdr(v354);
    goto v275;

v95:
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    v354 = negate(v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    goto v275;

v161:
    v354 = stack[-1];
    if (!consp(v354)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v354 = stack[-1];
    v354 = qcar(v354);
    if (!consp(v354)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v354 = stack[-1];
    v354 = qcar(v354);
    v73 = qcar(v354);
    v354 = (Lisp_Object)17; /* 1 */
    v354 = cons(v73, v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    stack[0] = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    v354 = stack[-1];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = CC_conjgd(env, v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    v354 = stack[-1];
    v354 = qcdr(v354);
    v354 = CC_conjgd(env, v354);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-3];
    {
        Lisp_Object v353 = stack[0];
        popv(4);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v353, v354);
    }
/* error exit handlers */
v286:
    popv(4);
    return nil;
}



/* Code for numpoly_red */

static Lisp_Object CC_numpoly_red(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_red");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v157 = v156;
    if (v157 == nil) goto v18;
    v157 = v156;
    if (is_number(v157)) goto v18;
    v157 = v156;
    v157 = qcdr(v157);
    return onevalue(v157);

v18:
    {
        fn = elt(env, 1); /* numpoly_null */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for letscalar */

static Lisp_Object MS_CDECL CC_letscalar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v15, Lisp_Object v22,
                         Lisp_Object v18, Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v430, v431, v432, v433, v434, v435;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "letscalar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letscalar");
#endif
    if (stack >= stacklimit)
    {
        push6(v37,v18,v22,v15,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v80,v15,v22,v18,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v37;
    stack[-3] = v18;
    stack[-4] = v22;
    stack[-5] = v15;
    stack[-6] = v80;
    stack[-7] = v0;
/* end of prologue */
    v430 = stack[-4];
    if (!consp(v430)) goto v161;
    v430 = stack[-4];
    v430 = qcar(v430);
    if (symbolp(v430)) goto v82;
    v434 = elt(env, 1); /* "Syntax error:" */
    v433 = stack[-7];
    v432 = elt(env, 2); /* "invalid" */
    v431 = qvalue(elt(env, 3)); /* nil */
    v430 = elt(env, 4); /* hold */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v434, v433, v432, v431, v430);
    }

v82:
    v430 = stack[-4];
    v431 = qcar(v430);
    v430 = elt(env, 5); /* df */
    if (v431 == v430) goto v312;
    v430 = stack[-4];
    v430 = qcar(v430);
    fn = elt(env, 32); /* getrtype */
    v430 = (*qfn1(fn))(qenv(fn), v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    if (v430 == nil) goto v61;
    v430 = stack[-4];
    fn = elt(env, 33); /* reval */
    v433 = (*qfn1(fn))(qenv(fn), v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v432 = stack[-6];
    v431 = stack[-5];
    v430 = stack[-3];
    {
        popv(10);
        fn = elt(env, 34); /* let2 */
        return (*qfnn(fn))(qenv(fn), 4, v433, v432, v431, v430);
    }

v61:
    v430 = stack[-4];
    v431 = qcar(v430);
    v430 = elt(env, 6); /* simpfn */
    v430 = get(v431, v430);
    env = stack[-9];
    if (!(v430 == nil)) goto v437;
    v430 = stack[-4];
    v431 = qcar(v430);
    v430 = elt(env, 7); /* "operator" */
    fn = elt(env, 35); /* redmsg */
    v430 = (*qfn2(fn))(qenv(fn), v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = stack[-4];
    v430 = qcar(v430);
    fn = elt(env, 36); /* mkop */
    v430 = (*qfn1(fn))(qenv(fn), v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v434 = stack[-7];
    v433 = stack[-6];
    v432 = stack[-5];
    v431 = stack[-3];
    v430 = stack[-2];
    {
        popv(10);
        fn = elt(env, 37); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v434, v433, v432, v431, v430);
    }

v437:
    v431 = stack[-4];
    v430 = elt(env, 23); /* expt */
    if (!consp(v431)) goto v67;
    v431 = qcar(v431);
    if (!(v431 == v430)) goto v67;
    v430 = stack[-4];
    v430 = qcdr(v430);
    v430 = qcdr(v430);
    v431 = qcar(v430);
    v430 = qvalue(elt(env, 24)); /* frlis!* */
    v430 = Lmemq(nil, v431, v430);
    if (v430 == nil) goto v67;
    stack[-8] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v432 = stack[-4];
    v431 = (Lisp_Object)17; /* 1 */
    v430 = (Lisp_Object)17; /* 1 */
    v430 = acons(v432, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = (Lisp_Object)17; /* 1 */
    v432 = cons(v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v431 = stack[-3];
    v430 = stack[-2];
    fn = elt(env, 38); /* letexprn */
    v430 = (*qfnn(fn))(qenv(fn), 6, stack[-8], stack[-1], stack[0], v432, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    goto v13;

v13:
    v430 = qvalue(elt(env, 21)); /* t */
    stack[0] = qvalue(elt(env, 28)); /* !*precise */
    qvalue(elt(env, 28)) = v430; /* !*precise */
    v430 = stack[-4];
    fn = elt(env, 39); /* simp0 */
    v430 = (*qfn1(fn))(qenv(fn), v430);
    nil = C_nil;
    if (exception_pending()) goto v438;
    env = stack[-9];
    stack[-4] = v430;
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    v430 = stack[-4];
    v430 = qcar(v430);
    if (!consp(v430)) goto v439;
    v430 = stack[-4];
    v430 = qcar(v430);
    v430 = qcar(v430);
    if (!consp(v430)) goto v439;
    v435 = stack[-7];
    v434 = stack[-6];
    v433 = stack[-5];
    v432 = stack[-4];
    v431 = stack[-3];
    v430 = stack[-2];
    {
        popv(10);
        fn = elt(env, 38); /* letexprn */
        return (*qfnn(fn))(qenv(fn), 6, v435, v434, v433, v432, v431, v430);
    }

v439:
    v434 = elt(env, 29); /* "Substitution for" */
    v433 = stack[-7];
    v432 = elt(env, 30); /* "not allowed" */
    v431 = qvalue(elt(env, 3)); /* nil */
    v430 = qvalue(elt(env, 21)); /* t */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v434, v433, v432, v431, v430);
    }

v67:
    v431 = stack[-4];
    v430 = elt(env, 25); /* sqrt */
    if (!consp(v431)) goto v13;
    v431 = qcar(v431);
    if (!(v431 == v430)) goto v13;
    v430 = qvalue(elt(env, 21)); /* t */
    qvalue(elt(env, 26)) = v430; /* !*sqrtrulep */
    v432 = elt(env, 23); /* expt */
    v430 = stack[-4];
    v430 = qcdr(v430);
    v431 = qcar(v430);
    v430 = elt(env, 27); /* (quotient 1 2) */
    v433 = list3(v432, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v432 = stack[-6];
    v431 = stack[-5];
    v430 = stack[-3];
    fn = elt(env, 34); /* let2 */
    v430 = (*qfnn(fn))(qenv(fn), 4, v433, v432, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    goto v13;

v312:
    v434 = stack[-7];
    v433 = stack[-6];
    v432 = stack[-5];
    v431 = stack[-4];
    v430 = stack[-3];
    fn = elt(env, 40); /* letdf */
    v430 = (*qfnn(fn))(qenv(fn), 5, v434, v433, v432, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    if (v430 == nil) goto v437;
    v430 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v430); }

v161:
    v430 = stack[-3];
    if (!(v430 == nil)) goto v437;
    v430 = stack[-5];
    if (!(v430 == nil)) goto v437;
    v431 = stack[-4];
    v430 = elt(env, 8); /* avalue */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 9); /* rtype */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v430 = stack[-4];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = elt(env, 10); /* antisymmetric */
    v430 = Lremflag(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 11); /* infix */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 12); /* kvalue */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v430 = stack[-4];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = elt(env, 13); /* linear */
    v430 = Lremflag(nil, v431, v430);
    env = stack[-9];
    v430 = stack[-4];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = elt(env, 14); /* noncom */
    v430 = Lremflag(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 15); /* op */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 16); /* opmtch */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = elt(env, 6); /* simpfn */
    v430 = Lremprop(nil, v431, v430);
    env = stack[-9];
    v430 = stack[-4];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = elt(env, 17); /* symmetric */
    v430 = Lremflag(nil, v431, v430);
    env = stack[-9];
    v431 = stack[-4];
    v430 = qvalue(elt(env, 18)); /* wtl!* */
    fn = elt(env, 41); /* delasc */
    v430 = (*qfn2(fn))(qenv(fn), v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    qvalue(elt(env, 18)) = v430; /* wtl!* */
    v431 = stack[-4];
    v430 = elt(env, 19); /* opfn */
    v430 = Lflagp(nil, v431, v430);
    env = stack[-9];
    if (v430 == nil) goto v291;
    v430 = stack[-4];
    v431 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = elt(env, 19); /* opfn */
    v430 = Lremflag(nil, v431, v430);
    env = stack[-9];
    v430 = stack[-4];
    v430 = Lremd(nil, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    goto v291;

v291:
    v431 = qvalue(elt(env, 20)); /* !*sqvar!* */
    v430 = qvalue(elt(env, 3)); /* nil */
    v430 = Lrplaca(nil, v431, v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    v430 = qvalue(elt(env, 21)); /* t */
    v430 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    qvalue(elt(env, 20)) = v430; /* !*sqvar!* */
    v430 = qvalue(elt(env, 3)); /* nil */
    v430 = ncons(v430);
    nil = C_nil;
    if (exception_pending()) goto v436;
    env = stack[-9];
    qvalue(elt(env, 22)) = v430; /* alglist!* */
    v430 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v430); }
/* error exit handlers */
v438:
    env = stack[-9];
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    popv(10);
    return nil;
v436:
    popv(10);
    return nil;
}



/* Code for make!-image!-mod!-p */

static Lisp_Object CC_makeKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v95 = stack[-1];
    v151 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v151 = (*qfn2(fn))(qenv(fn), v95, v151);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-2] = v151;
    v95 = stack[-1];
    v151 = stack[0];
    fn = elt(env, 4); /* make!-univariate!-image!-mod!-p */
    v151 = (*qfn2(fn))(qenv(fn), v95, v151);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-1] = v151;
    v95 = stack[-1];
    v151 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v95 = (*qfn2(fn))(qenv(fn), v95, v151);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v151 = stack[-2];
    if (equal(v95, v151)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v151; /* unlucky!-case */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for subeval1 */

static Lisp_Object CC_subeval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v388, v440;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval1");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */

v245:
    v356 = stack[-1];
    if (v356 == nil) goto v125;
    v356 = stack[-1];
    v356 = qcar(v356);
    v388 = qcar(v356);
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = qcdr(v356);
    if (!(equal(v388, v356))) goto v125;
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v245;

v125:
    v356 = stack[-1];
    if (v356 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v356 = stack[0];
    fn = elt(env, 8); /* getrtype */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v440 = v356;
    if (v356 == nil) goto v321;
    v388 = v440;
    v356 = elt(env, 2); /* subfn */
    v356 = get(v388, v356);
    env = stack[-2];
    v388 = v356;
    if (v356 == nil) goto v59;
    v440 = v388;
    v388 = stack[-1];
    v356 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v440, v388, v356);

v59:
    v356 = elt(env, 3); /* "No substitution defined for type" */
    v388 = v440;
    v356 = list2(v356, v388);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v388 = v356;
    v356 = v388;
    qvalue(elt(env, 4)) = v356; /* errmsg!* */
    v356 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v356 == nil)) goto v143;
    v356 = v388;
    fn = elt(env, 9); /* lprie */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    goto v143;

v143:
    v356 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    goto v321;

v321:
    v356 = stack[0];
    fn = elt(env, 10); /* simp */
    v388 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v356 = stack[-1];
    fn = elt(env, 11); /* subsq */
    v356 = (*qfn2(fn))(qenv(fn), v388, v356);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    stack[-1] = v356;
    v356 = qvalue(elt(env, 6)); /* t */
    stack[0] = qvalue(elt(env, 7)); /* !*sub2 */
    qvalue(elt(env, 7)) = v356; /* !*sub2 */
    v356 = stack[-1];
    fn = elt(env, 12); /* subs2 */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    stack[-1] = v356;
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    v356 = stack[-1];
    {
        popv(3);
        fn = elt(env, 13); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v356);
    }
/* error exit handlers */
v152:
    env = stack[-2];
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    popv(3);
    return nil;
v38:
    popv(3);
    return nil;
}



setup_type const u48_setup[] =
{
    {"opfchk!",                 CC_opfchkB,     too_many_1,    wrong_no_1},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"exceeds-order-variant",   too_few_2,      CC_exceedsKorderKvariant,wrong_no_2},
    {"ps:expt-erule",           too_few_2,      CC_psTexptKerule,wrong_no_2},
    {"dipcontenti1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipcontenti1},
    {"remove_root_item",        CC_remove_root_item,too_many_1,wrong_no_1},
    {"randpoly",                CC_randpoly,    too_many_1,    wrong_no_1},
    {"lambda_l9xqtv_12",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_lambda_l9xqtv_12},
    {"chksymmetries&subst",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsubst},
    {"free",                    CC_free,        too_many_1,    wrong_no_1},
    {"lengthreval",             CC_lengthreval, too_many_1,    wrong_no_1},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"lto_alunion",             CC_lto_alunion, too_many_1,    wrong_no_1},
    {"get*order",               CC_getHorder,   too_many_1,    wrong_no_1},
    {"qqe_simplqequal",         too_few_2,      CC_qqe_simplqequal,wrong_no_2},
    {"pasf_mkop",               too_few_2,      CC_pasf_mkop,  wrong_no_2},
    {"vdp_sugar",               CC_vdp_sugar,   too_many_1,    wrong_no_1},
    {"applyml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyml},
    {"xpdiff",                  too_few_2,      CC_xpdiff,     wrong_no_2},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"mkuniquewedge",           CC_mkuniquewedge,too_many_1,   wrong_no_1},
    {"dvertex-to-projector",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvertexKtoKprojector},
    {"dp_prod",                 too_few_2,      CC_dp_prod,    wrong_no_2},
    {"find-null-space",         too_few_2,      CC_findKnullKspace,wrong_no_2},
    {"lowestdeg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowestdeg},
    {"simprad",                 too_few_2,      CC_simprad,    wrong_no_2},
    {"reduce-mod-eig",          too_few_2,      CC_reduceKmodKeig,wrong_no_2},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {"numpoly_red",             CC_numpoly_red, too_many_1,    wrong_no_1},
    {"letscalar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_letscalar},
    {"make-image-mod-p",        too_few_2,      CC_makeKimageKmodKp,wrong_no_2},
    {"subeval1",                too_few_2,      CC_subeval1,   wrong_no_2},
    {NULL, (one_args *)"u48", (two_args *)"13727 4100654 1626915", 0}
};

/* end of generated code */
