
/* $destdir\u44.c        Machine generated C code */

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


/* Code for sep_tens_from_other */

static Lisp_Object CC_sep_tens_from_other(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sep_tens_from_other");
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
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v30 = (Lisp_Object)17; /* 1 */
    v30 = (Lisp_Object)zerop(v30);
    v30 = v30 ? lisp_true : nil;
    env = stack[-5];
    if (v30 == nil) goto v32;
    v30 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v33:
    stack[-2] = v30;
    goto v34;

v34:
    v30 = stack[-3];
    if (is_number(v30)) goto v35;
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!consp(v30)) goto v36;
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcar(v30);
    v30 = elt(env, 2); /* translate1 */
    v30 = get(v31, v30);
    env = stack[-5];
    stack[-1] = v30;
    if (v30 == nil) goto v37;
    v30 = stack[-3];
    fn = elt(env, 3); /* fullcopy */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-3] = v30;
    v30 = stack[-3];
    v30 = qcar(v30);
    stack[0] = qcar(v30);
    v31 = stack[-1];
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = Lapply1(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    fn = elt(env, 4); /* setcar */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    goto v37;

v37:
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    stack[0] = v30;
    fn = elt(env, 5); /* tensorp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    if (v30 == nil) goto v39;
    v30 = stack[0];
    fn = elt(env, 6); /* no_dum_varp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    if (v30 == nil) goto v40;
    v30 = stack[0];
    v30 = qcar(v30);
    if (!symbolp(v30)) v30 = nil;
    else { v30 = qfastgets(v30);
           if (v30 != nil) { v30 = elt(v30, 0); /* noncom */
#ifdef RECORD_GET
             if (v30 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v30 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v30 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v30 == SPID_NOPROP) v30 = nil; else v30 = lisp_true; }}
#endif
    if (!(v30 == nil)) goto v40;
    stack[0] = stack[-2];
    v30 = stack[-3];
    v30 = qcar(v30);
    v31 = qcar(v30);
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-2] = v30;
    goto v41;

v41:
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcdr(v30);
    stack[-3] = v30;
    goto v34;

v40:
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v31 = qcar(v30);
    v30 = stack[-4];
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-4] = v30;
    goto v41;

v39:
    stack[0] = stack[-2];
    v30 = stack[-3];
    v30 = qcar(v30);
    v31 = qcar(v30);
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-2] = v30;
    goto v41;

v36:
    stack[0] = stack[-2];
    v30 = stack[-3];
    v30 = qcar(v30);
    v31 = qcar(v30);
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-2] = v30;
    goto v41;

v35:
    v30 = stack[-4];
    stack[0] = Lnreverse(nil, v30);
    env = stack[-5];
    v31 = stack[-2];
    v30 = stack[-3];
    v30 = (Lisp_Object)zerop(v30);
    v30 = v30 ? lisp_true : nil;
    env = stack[-5];
    if (v30 == nil) goto v42;
    v30 = qvalue(elt(env, 1)); /* nil */
    goto v43;

v43:
    fn = elt(env, 7); /* multf */
    v30 = (*qfn2(fn))(qenv(fn), v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v38;
    {
        Lisp_Object v44 = stack[0];
        popv(6);
        return list2(v44, v30);
    }

v42:
    v30 = stack[-3];
    goto v43;

v32:
    v30 = (Lisp_Object)17; /* 1 */
    goto v33;
/* error exit handlers */
v38:
    popv(6);
    return nil;
}



/* Code for mk_character */

static Lisp_Object CC_mk_character(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_character");
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
    v20 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    stack[-6] = v20;
    v20 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    stack[-4] = v20;
    v20 = stack[-4];
    if (v20 == nil) goto v61;
    v20 = stack[-4];
    v20 = qcar(v20);
    stack[0] = v20;
    v59 = v20;
    v20 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v20 = (*qfn2(fn))(qenv(fn), v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = list2(stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    stack[-2] = v20;
    stack[-3] = v20;
    goto v62;

v62:
    v20 = stack[-4];
    v20 = qcdr(v20);
    stack[-4] = v20;
    v20 = stack[-4];
    if (v20 == nil) goto v63;
    stack[-1] = stack[-2];
    v20 = stack[-4];
    v20 = qcar(v20);
    stack[0] = v20;
    v59 = v20;
    v20 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v20 = (*qfn2(fn))(qenv(fn), v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = list2(stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = Lrplacd(nil, stack[-1], v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-7];
    v20 = stack[-2];
    v20 = qcdr(v20);
    stack[-2] = v20;
    goto v62;

v63:
    v20 = stack[-3];
    goto v64;

v64:
    stack[0] = v20;
    v20 = stack[-6];
    v59 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v20 = stack[0];
        popv(8);
        return Lappend(nil, v59, v20);

v61:
    v20 = qvalue(elt(env, 1)); /* nil */
    goto v64;
/* error exit handlers */
v60:
    popv(8);
    return nil;
}



/* Code for limitom */

static Lisp_Object CC_limitom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for limitom");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v15 = v73;
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    stack[-2] = v15;
    v15 = v73;
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    stack[0] = v15;
    v15 = v73;
    v15 = Lreverse(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = qcar(v15);
    stack[-3] = v15;
    v15 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 13); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = elt(env, 3); /* "<OMS cd=""limit1"" name=""limit""/>" */
    fn = elt(env, 12); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = stack[0];
    v73 = qcar(v15);
    v15 = elt(env, 4); /* lowlimit */
    if (!(v73 == v15)) goto v76;
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcar(v15);
    fn = elt(env, 14); /* objectom */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = elt(env, 5); /* "<OMS cd=""limit1"" name=""null""/>" */
    fn = elt(env, 12); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    goto v76;

v76:
    v15 = stack[0];
    v73 = qcar(v15);
    v15 = elt(env, 6); /* condition */
    if (!(v73 == v15)) goto v77;
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcar(v15);
    v15 = Lreverse(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = qcar(v15);
    fn = elt(env, 14); /* objectom */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcar(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    v15 = qcar(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    stack[0] = v15;
    v15 = elt(env, 7); /* "<OMS cd=""limit1"" name=""" */
    fn = elt(env, 12); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = stack[0];
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = elt(env, 8); /* """/>" */
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    goto v77;

v77:
    stack[-1] = elt(env, 9); /* limit */
    stack[0] = qvalue(elt(env, 10)); /* nil */
    v74 = stack[-2];
    v73 = stack[-3];
    v15 = qvalue(elt(env, 10)); /* nil */
    v15 = list2star(v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = list2star(stack[-1], stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    fn = elt(env, 15); /* lambdaom */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v15 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v15 = nil;
    { popv(5); return onevalue(v15); }
/* error exit handlers */
v75:
    popv(5);
    return nil;
}



/* Code for make!-ps */

static Lisp_Object MS_CDECL CC_makeKps(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "make-ps");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-ps");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v78,v13,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v13;
    stack[-2] = v78;
    stack[-3] = v0;
/* end of prologue */
    v73 = elt(env, 1); /* tps */
    v15 = elt(env, 2); /* tag */
    stack[-4] = get(v73, v15);
    env = stack[-5];
    v15 = (Lisp_Object)113; /* 7 */
    v15 = Lmkvect(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v15 = cons(stack[-4], v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    stack[-4] = v15;
    v74 = stack[-4];
    v73 = (Lisp_Object)1; /* 0 */
    v15 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v74 = stack[-4];
    v73 = (Lisp_Object)97; /* 6 */
    v15 = stack[-3];
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v74 = stack[-4];
    v73 = (Lisp_Object)65; /* 4 */
    v15 = stack[-2];
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v74 = stack[-4];
    v73 = (Lisp_Object)33; /* 2 */
    v15 = stack[-1];
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v74 = stack[-4];
    v73 = (Lisp_Object)49; /* 3 */
    v15 = stack[0];
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v74 = stack[-4];
    v73 = (Lisp_Object)17; /* 1 */
    v15 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 4); /* ps!:putv */
    v15 = (*qfnn(fn))(qenv(fn), 3, v74, v73, v15);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v15 = stack[-4];
    v73 = qcdr(v15);
    v15 = (Lisp_Object)113; /* 7 */
    v74 = qvalue(elt(env, 3)); /* !*sqvar!* */
    *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v15/(16/CELL))) = v74;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v89:
    popv(6);
    return nil;
}



/* Code for get_num_part */

static Lisp_Object CC_get_num_part(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_num_part");
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
    goto v33;

v33:
    v110 = stack[0];
    v109 = (Lisp_Object)1; /* 0 */
    if (v110 == v109) goto v111;
    v109 = stack[0];
    if (is_number(v109)) goto v112;
    v109 = stack[0];
    if (!consp(v109)) goto v56;
    v110 = stack[0];
    v109 = elt(env, 1); /* !:rd!: */
    if (!consp(v110)) goto v65;
    v110 = qcar(v110);
    if (!(v110 == v109)) goto v65;
    v109 = stack[0];
    v109 = qcdr(v109);
    if (!consp(v109)) goto v83;
    v109 = stack[0];
    fn = elt(env, 5); /* bf2flr */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    {
        Lisp_Object v113 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v113, v109);
    }

v83:
    v110 = stack[-1];
    v109 = stack[0];
    v109 = qcdr(v109);
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v65:
    v110 = stack[0];
    v109 = elt(env, 2); /* !:dn!: */
    if (!consp(v110)) goto v114;
    v110 = qcar(v110);
    if (!(v110 == v109)) goto v114;
    v109 = stack[0];
    v109 = qcdr(v109);
    fn = elt(env, 7); /* rdwrap2 */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    {
        Lisp_Object v115 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v115, v109);
    }

v114:
    v110 = stack[0];
    v109 = elt(env, 3); /* minus */
    if (!consp(v110)) goto v116;
    v110 = qcar(v110);
    if (!(v110 == v109)) goto v116;
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = CC_get_num_part(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v110 = v109;
    if (is_number(v110)) goto v117;
    v110 = elt(env, 3); /* minus */
    v109 = list2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    goto v118;

v118:
    {
        Lisp_Object v119 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v119, v109);
    }

v117:
    v109 = Lfloat(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v109 = negate(v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    goto v118;

v116:
    v110 = stack[0];
    v109 = elt(env, 4); /* expt */
    if (!consp(v110)) goto v120;
    v110 = qcar(v110);
    if (!(v110 == v109)) goto v120;
    v109 = stack[0];
    fn = elt(env, 8); /* rdwrap!-expt */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    {
        Lisp_Object v30 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v30, v109);
    }

v120:
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = CC_get_num_part(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v109 = stack[-1];
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    stack[-1] = v109;
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v33;

v56:
    v110 = stack[-1];
    v109 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v112:
    v109 = stack[0];
    v109 = Lfloat(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    {
        Lisp_Object v31 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v31, v109);
    }

v111:
    v110 = stack[-1];
    v109 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v78,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v78;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v123;

v123:
    v122 = stack[-2];
    if (v122 == nil) goto v33;
    v122 = stack[-2];
    v70 = qcar(v122);
    v122 = stack[0];
    fn = elt(env, 1); /* evdif */
    v70 = (*qfn2(fn))(qenv(fn), v70, v122);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    v122 = stack[-3];
    v122 = cons(v70, v122);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-2];
    v122 = qcdr(v122);
    v70 = qcar(v122);
    v122 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v70 = (*qfn2(fn))(qenv(fn), v70, v122);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    v122 = stack[-3];
    v122 = cons(v70, v122);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-2];
    v122 = qcdr(v122);
    v122 = qcdr(v122);
    stack[-2] = v122;
    goto v123;

v33:
    v122 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v122);
    }
/* error exit handlers */
v124:
    popv(5);
    return nil;
}



/* Code for f2dip2 */

static Lisp_Object MS_CDECL CC_f2dip2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v66, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "f2dip2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip2");
#endif
    if (stack >= stacklimit)
    {
        push5(v5,v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v78,v13,v12,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v12;
    stack[-2] = v13;
    stack[-3] = v78;
    stack[-4] = v0;
/* end of prologue */
    v132 = stack[-4];
    v131 = qvalue(elt(env, 1)); /* dipvars!* */
    v131 = Lmemq(nil, v132, v131);
    if (v131 == nil) goto v25;
    v46 = stack[-1];
    v66 = stack[-4];
    v132 = stack[-3];
    v131 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 3); /* evinsert */
    v131 = (*qfnn(fn))(qenv(fn), 4, v46, v66, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-5];
    goto v123;

v123:
    v132 = v131;
    v131 = v132;
    if (v131 == nil) goto v133;
    v131 = v132;
    stack[-1] = v131;
    goto v134;

v134:
    v66 = stack[-2];
    v132 = stack[-1];
    v131 = stack[0];
    {
        popv(6);
        fn = elt(env, 4); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v66, v132, v131);
    }

v133:
    v66 = stack[-4];
    v132 = stack[-3];
    v131 = (Lisp_Object)17; /* 1 */
    v66 = acons(v66, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-5];
    v132 = qvalue(elt(env, 2)); /* nil */
    v131 = (Lisp_Object)17; /* 1 */
    v131 = acons(v66, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-5];
    fn = elt(env, 5); /* multsq */
    v131 = (*qfn2(fn))(qenv(fn), stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-5];
    stack[0] = v131;
    goto v134;

v25:
    v131 = qvalue(elt(env, 2)); /* nil */
    goto v123;
/* error exit handlers */
v101:
    popv(6);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v18;

v18:
    v54 = stack[0];
    if (v54 == nil) goto v34;
    v54 = stack[0];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v105 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v54 = stack[0];
    v54 = qcar(v54);
    v55 = qcdr(v54);
    v54 = stack[-1];
    v54 = acons(v105, v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    stack[-1] = v54;
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v18;

v34:
    v54 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v54);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for drop_rl_with */

static Lisp_Object CC_drop_rl_with(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v129, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_rl_with");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v130 = v78;
    v129 = v0;
/* end of prologue */
    stack[-1] = v130;
    stack[0] = elt(env, 1); /* rl_with */
    v26 = v129;
    v129 = v130;
    v130 = elt(env, 1); /* rl_with */
    v130 = get(v129, v130);
    env = stack[-2];
    v130 = Ldelete(nil, v26, v130);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v55 = stack[-1];
        Lisp_Object v105 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v55, v105, v130);
    }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v58, v135, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v135 = v78;
    v130 = v0;
/* end of prologue */
    v58 = v130;
    v35 = elt(env, 1); /* dfp */
    v35 = Leqcar(nil, v58, v35);
    v35 = (v35 == nil ? lisp_true : nil);
    if (!(v35 == nil)) return onevalue(v35);
    v35 = v130;
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v58 = v135;
        return Lneq(nil, v35, v58);
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v0;
/* end of prologue */
    v137 = stack[-1];
    if (v137 == nil) goto v18;
    v56 = stack[-1];
    v137 = (Lisp_Object)49; /* 3 */
    v56 = *(Lisp_Object *)((char *)v56 + (CELL-TAG_VECTOR) + ((int32_t)v137/(16/CELL)));
    v137 = stack[0];
    stack[-2] = CC_hdiff(env, v56, v137);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v56 = stack[-1];
    v137 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v137 = (*qfn2(fn))(qenv(fn), v56, v137);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    {
        Lisp_Object v42 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v42, v137);
    }

v18:
    v137 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v137); }
/* error exit handlers */
v85:
    popv(4);
    return nil;
}



/* Code for mo_deletecomp */

static Lisp_Object CC_mo_deletecomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_deletecomp");
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
    v85 = v0;
/* end of prologue */
    v42 = v85;
    v42 = qcar(v42);
    if (v42 == nil) { popv(2); return onevalue(v85); }
    v42 = v85;
    v42 = qcar(v42);
    v42 = qcdr(v42);
    if (v42 == nil) goto v108;
    v42 = (Lisp_Object)1; /* 0 */
    v85 = qcar(v85);
    v85 = qcdr(v85);
    v85 = cons(v42, v85);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    stack[0] = v85;
    fn = elt(env, 2); /* mo!=deglist */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v76;
    {
        Lisp_Object v121 = stack[0];
        popv(2);
        return cons(v121, v85);
    }

v108:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v85 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v76;
    {
        Lisp_Object v126 = stack[0];
        popv(2);
        return cons(v126, v85);
    }
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for rl_qe */

static Lisp_Object CC_rl_qe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qe");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v111 = v78;
    v61 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_qe!* */
    v111 = list2(v61, v111);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    {
        Lisp_Object v87 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v87, v111);
    }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for addcoeffs */

static Lisp_Object MS_CDECL CC_addcoeffs(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v145, v95, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "addcoeffs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addcoeffs");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v78,v13,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v13;
    stack[-3] = v78;
    stack[-4] = v0;
/* end of prologue */
    v145 = qvalue(elt(env, 1)); /* nil */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[0] = v144;
    v144 = stack[-4];
    fn = elt(env, 2); /* smallest!-increment */
    stack[-5] = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v144 = stack[-3];
    fn = elt(env, 2); /* smallest!-increment */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    fn = elt(env, 3); /* common!-increment */
    v144 = (*qfn2(fn))(qenv(fn), stack[-5], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v146 = stack[-2];
    v95 = stack[-1];
    v145 = stack[-3];
    v145 = qcar(v145);
    v145 = qcar(v145);
    fn = elt(env, 4); /* makecoeffpairs */
    v144 = (*qfnn(fn))(qenv(fn), 4, v146, v95, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-5] = v144;
    goto v26;

v26:
    v144 = stack[-5];
    if (v144 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v144 = stack[-5];
    v144 = qcar(v144);
    stack[-2] = v144;
    stack[-1] = stack[0];
    v144 = stack[-2];
    v145 = qcar(v144);
    v144 = stack[-4];
    v144 = Lassoc(nil, v145, v144);
    v145 = v144;
    v144 = v145;
    if (v144 == nil) goto v66;
    v144 = v145;
    v144 = qcdr(v144);
    stack[0] = v144;
    goto v67;

v67:
    v144 = stack[-2];
    v145 = qcdr(v144);
    v144 = stack[-3];
    v144 = Lassoc(nil, v145, v144);
    v145 = v144;
    v144 = v145;
    if (v144 == nil) goto v17;
    v144 = v145;
    v144 = qcdr(v144);
    goto v82;

v82:
    fn = elt(env, 5); /* multsq */
    v144 = (*qfn2(fn))(qenv(fn), stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v144 = (*qfn2(fn))(qenv(fn), stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[0] = v144;
    v144 = stack[-5];
    v144 = qcdr(v144);
    stack[-5] = v144;
    goto v26;

v17:
    v145 = qvalue(elt(env, 1)); /* nil */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    goto v82;

v66:
    v145 = qvalue(elt(env, 1)); /* nil */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[0] = v144;
    goto v67;
/* error exit handlers */
v147:
    popv(7);
    return nil;
}



/* Code for pasf_pnf */

static Lisp_Object CC_pasf_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pnf");
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
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_pnf1 */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v128:
    popv(1);
    return nil;
}



/* Code for pdiffvars */

static Lisp_Object CC_pdiffvars(Lisp_Object env,
                         Lisp_Object v78, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdiffvars");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v78);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v78,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    v137 = v78;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* ind */
    qvalue(elt(env, 1)) = nil; /* ind */
    qvalue(elt(env, 1)) = v137; /* ind */
    v137 = qvalue(elt(env, 1)); /* ind */
    if (v137 == nil) goto v64;
    v56 = stack[-1];
    v137 = qvalue(elt(env, 1)); /* ind */
    v137 = qcar(v137);
    fn = elt(env, 2); /* pnth */
    v137 = (*qfn2(fn))(qenv(fn), v56, v137);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    stack[0] = qcar(v137);
    v137 = qvalue(elt(env, 1)); /* ind */
    v56 = qcdr(v137);
    v137 = stack[-1];
    v137 = CC_pdiffvars(env, v56, v137);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v137 = cons(stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    goto v128;

v128:
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    { popv(4); return onevalue(v137); }

v64:
    v137 = nil;
    goto v128;
/* error exit handlers */
v85:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    popv(4);
    return nil;
}



/* Code for fac!-part */

static Lisp_Object CC_facKpart(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fac-part");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v0;
/* end of prologue */
    v143 = stack[-1];
    v149 = stack[0];
    if (equal(v143, v149)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v149 = stack[0];
    v149 = sub1(v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    if (equal(stack[-2], v149)) goto v58;
    v143 = stack[-1];
    v149 = stack[0];
    v143 = plus2(v143, v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v149 = (Lisp_Object)33; /* 2 */
    v149 = quot2(v143, v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[-2] = v149;
    v143 = stack[-1];
    v149 = stack[-2];
    stack[-1] = CC_facKpart(env, v143, v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v149 = stack[-2];
    v143 = add1(v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v149 = stack[0];
    v149 = CC_facKpart(env, v143, v149);
    nil = C_nil;
    if (exception_pending()) goto v139;
    {
        Lisp_Object v125 = stack[-1];
        popv(4);
        return times2(v125, v149);
    }

v58:
    v143 = stack[-1];
    v149 = stack[0];
    popv(4);
    return times2(v143, v149);
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for addns */

static Lisp_Object CC_addns(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v114, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addns");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v128;

v128:
    v140 = stack[0];
    if (v140 == nil) goto v64;
    v140 = stack[-1];
    v114 = qcdr(v140);
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcdr(v140);
    if (equal(v114, v140)) goto v56;
    v140 = stack[-1];
    v114 = qcdr(v140);
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcdr(v140);
    fn = elt(env, 1); /* ordp */
    v140 = (*qfn2(fn))(qenv(fn), v114, v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    if (v140 == nil) goto v67;
    v114 = stack[-1];
    v140 = stack[0];
    v140 = cons(v114, v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    {
        Lisp_Object v99 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v99, v140);
    }

v67:
    v140 = stack[0];
    v114 = qcar(v140);
    v140 = stack[-2];
    v140 = cons(v114, v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    stack[-2] = v140;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v128;

v56:
    v140 = stack[-1];
    v114 = qcar(v140);
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcar(v140);
    fn = elt(env, 3); /* addsq */
    v140 = (*qfn2(fn))(qenv(fn), v114, v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    v16 = v140;
    v140 = stack[-1];
    v114 = qcdr(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = acons(v16, v114, v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    {
        Lisp_Object v151 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v151, v140);
    }

v64:
    stack[0] = stack[-2];
    v140 = stack[-1];
    v140 = ncons(v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    {
        Lisp_Object v152 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v152, v140);
    }
/* error exit handlers */
v17:
    popv(4);
    return nil;
}



/* Code for f2dip */

static Lisp_Object CC_f2dip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip");
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
    v62 = v0;
/* end of prologue */
    stack[-1] = v62;
    fn = elt(env, 1); /* evzero */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v62 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* bcfd */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    {
        Lisp_Object v111 = stack[-1];
        Lisp_Object v61 = stack[0];
        popv(3);
        fn = elt(env, 3); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v111, v61, v62);
    }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for xexptpf */

static Lisp_Object CC_xexptpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xexptpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v62;

v62:
    v126 = stack[0];
    v121 = (Lisp_Object)17; /* 1 */
    if (v126 == v121) goto v34;
    v126 = stack[-1];
    v121 = stack[-2];
    v121 = cons(v126, v121);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[0];
    v121 = sub1(v121);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    stack[0] = v121;
    goto v62;

v34:
    v121 = stack[-1];
    v126 = v121;
    goto v29;

v29:
    v121 = stack[-2];
    if (v121 == nil) { popv(4); return onevalue(v126); }
    v121 = stack[-2];
    v121 = qcar(v121);
    fn = elt(env, 1); /* wedgepf */
    v121 = (*qfn2(fn))(qenv(fn), v121, v126);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    v126 = v121;
    v121 = stack[-2];
    v121 = qcdr(v121);
    stack[-2] = v121;
    goto v29;
/* error exit handlers */
v70:
    popv(4);
    return nil;
}



/* Code for simpintersection */

static Lisp_Object CC_simpintersection(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpintersection");
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
    v125 = v0;
/* end of prologue */
    v102 = elt(env, 1); /* intersection */
    fn = elt(env, 3); /* applysetop */
    v125 = (*qfn2(fn))(qenv(fn), v102, v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v103 = v125;
    v125 = v103;
    v102 = qcar(v125);
    v125 = elt(env, 1); /* intersection */
    if (v102 == v125) goto v63;
    v125 = v103;
    goto v25;

v25:
    fn = elt(env, 4); /* fkern */
    v102 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v125 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* getpower */
    v102 = (*qfn2(fn))(qenv(fn), v102, v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v125 = (Lisp_Object)17; /* 1 */
    v125 = cons(v102, v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v102 = ncons(v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v125 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v102, v125);

v63:
    v102 = qvalue(elt(env, 2)); /* empty_set */
    v125 = v103;
    v125 = qcdr(v125);
    v103 = v125;
    v125 = Lmember(nil, v102, v125);
    if (v125 == nil) goto v42;
    v125 = qvalue(elt(env, 2)); /* empty_set */
    goto v25;

v42:
    v125 = v103;
    v125 = qcdr(v125);
    if (v125 == nil) goto v104;
    stack[0] = elt(env, 1); /* intersection */
    v125 = v103;
    fn = elt(env, 6); /* ordn */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v125 = cons(stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    goto v25;

v104:
    v125 = v103;
    v125 = qcar(v125);
    goto v25;
/* error exit handlers */
v132:
    popv(2);
    return nil;
}



/* Code for forttab */

static Lisp_Object CC_forttab(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for forttab");
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
    v63 = qvalue(elt(env, 1)); /* fortlinelen!* */
    v42 = qvalue(elt(env, 2)); /* minfortlinelen!* */
    v42 = difference2(v63, v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    fn = elt(env, 5); /* min0 */
    v63 = (*qfn2(fn))(qenv(fn), stack[0], v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v42 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 6); /* max */
    v42 = (*qfn2(fn))(qenv(fn), v63, v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    qvalue(elt(env, 3)) = v42; /* !*fortcurrind!* */
    v63 = qvalue(elt(env, 3)); /* !*fortcurrind!* */
    v42 = qvalue(elt(env, 4)); /* !*posn!* */
    v63 = difference2(v63, v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    stack[0] = v63;
    v42 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)greaterp2(v63, v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v42 = v42 ? lisp_true : nil;
    env = stack[-1];
    if (v42 == nil) goto v135;
    v42 = stack[0];
    fn = elt(env, 7); /* nspaces */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* pprin2 */
        return (*qfn1(fn))(qenv(fn), v42);
    }

v135:
    v42 = nil;
    { popv(2); return onevalue(v42); }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



/* Code for al1_defined_vertex */

static Lisp_Object MS_CDECL CC_al1_defined_vertex(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "al1_defined_vertex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for al1_defined_vertex");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v78,v13,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v13;
    stack[-2] = v78;
    stack[-3] = v0;
/* end of prologue */

v34:
    v132 = stack[-3];
    if (v132 == nil) goto v53;
    v132 = stack[-3];
    v66 = qcar(v132);
    v132 = stack[0];
    fn = elt(env, 3); /* defined_edge */
    v132 = (*qfn2(fn))(qenv(fn), v66, v132);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    if (v132 == nil) goto v104;
    v66 = stack[-2];
    v132 = stack[-3];
    v132 = qcdr(v132);
    v132 = Lnconc(nil, v66, v132);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    stack[-4] = v132;
    v132 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v132;
    v132 = stack[-3];
    v66 = qcar(v132);
    v132 = stack[-1];
    v132 = cons(v66, v132);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    stack[-1] = v132;
    v132 = stack[-3];
    v66 = qcar(v132);
    v132 = stack[0];
    v132 = cons(v66, v132);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    stack[0] = v132;
    v132 = stack[-4];
    stack[-3] = v132;
    goto v34;

v104:
    v132 = stack[-3];
    v132 = qcdr(v132);
    stack[-4] = v132;
    v132 = stack[-3];
    v66 = qcar(v132);
    v132 = stack[-2];
    v132 = cons(v66, v132);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    stack[-2] = v132;
    v132 = stack[-4];
    stack[-3] = v132;
    goto v34;

v53:
    v132 = stack[-2];
    if (v132 == nil) goto v32;
    v66 = stack[-2];
    v132 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* re_parents */
        return (*qfn2(fn))(qenv(fn), v66, v132);
    }

v32:
    v132 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v132); }
/* error exit handlers */
v59:
    popv(6);
    return nil;
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v85 = v0;
/* end of prologue */

v29:
    v84 = v85;
    v42 = qcar(v84);
    v84 = (Lisp_Object)17; /* 1 */
    if (v42 == v84) goto v123;
    v84 = v85;
    v84 = qcdr(v84);
    if (v84 == nil) goto v130;
    v84 = elt(env, 1); /* times */
    return cons(v84, v85);

v130:
    v84 = v85;
    v84 = qcar(v84);
    return onevalue(v84);

v123:
    v84 = v85;
    v84 = qcdr(v84);
    if (v84 == nil) goto v35;
    v84 = v85;
    v84 = qcdr(v84);
    v85 = v84;
    goto v29;

v35:
    v84 = (Lisp_Object)17; /* 1 */
    return onevalue(v84);
}



/* Code for uterm */

static Lisp_Object CC_uterm(Lisp_Object env,
                         Lisp_Object v78, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for uterm");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v78);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v78,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v20 = v13;
    stack[-1] = v78;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 1)) = nil; /* rhs!* */
    qvalue(elt(env, 1)) = v20; /* rhs!* */
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    if (v20 == nil) goto v33;
    v59 = stack[-1];
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    v20 = qcar(v20);
    v20 = qcar(v20);
    fn = elt(env, 3); /* addinds */
    v20 = (*qfn2(fn))(qenv(fn), v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[0] = v20;
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    v20 = qcar(v20);
    v20 = qcdr(v20);
    v59 = qcar(v20);
    v20 = stack[-1];
    fn = elt(env, 4); /* evaluatecoeffts */
    v20 = (*qfn2(fn))(qenv(fn), v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v59 = v20;
    if (v59 == nil) goto v63;
    v59 = v20;
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    v20 = qcar(v20);
    v20 = qcdr(v20);
    v20 = qcdr(v20);
    v20 = cons(v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v59 = stack[0];
    v20 = cons(v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[0] = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v59 = stack[-1];
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    v20 = qcdr(v20);
    v20 = CC_uterm(env, v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    fn = elt(env, 5); /* plusdf */
    v20 = (*qfn2(fn))(qenv(fn), stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    goto v128;

v128:
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    { popv(4); return onevalue(v20); }

v63:
    v59 = stack[-1];
    v20 = qvalue(elt(env, 1)); /* rhs!* */
    v20 = qcdr(v20);
    v20 = CC_uterm(env, v59, v20);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    goto v128;

v33:
    v20 = qvalue(elt(env, 2)); /* nil */
    goto v128;
/* error exit handlers */
v69:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    popv(4);
    return nil;
}



/* Code for multtaylorsq */

static Lisp_Object CC_multtaylorsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multtaylorsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v78;
    stack[-6] = v0;
/* end of prologue */
    v156 = stack[-6];
    if (v156 == nil) goto v18;
    v156 = stack[-5];
    v156 = qcar(v156);
    if (v156 == nil) goto v18;
    stack[-7] = elt(env, 2); /* taylor!* */
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcar(v156);
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) goto v72;
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = v156;
    v156 = v157;
    stack[0] = qcar(v156);
    v156 = v157;
    v157 = qcdr(v156);
    v156 = stack[-5];
    fn = elt(env, 4); /* multsq */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    fn = elt(env, 5); /* subs2!* */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    fn = elt(env, 6); /* resimp */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = cons(stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    stack[-2] = v156;
    stack[-3] = v156;
    goto v112;

v112:
    v156 = stack[-4];
    v156 = qcdr(v156);
    stack[-4] = v156;
    v156 = stack[-4];
    if (v156 == nil) goto v50;
    stack[-1] = stack[-2];
    v156 = stack[-4];
    v156 = qcar(v156);
    v157 = v156;
    v156 = v157;
    stack[0] = qcar(v156);
    v156 = v157;
    v157 = qcdr(v156);
    v156 = stack[-5];
    fn = elt(env, 4); /* multsq */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    fn = elt(env, 5); /* subs2!* */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    fn = elt(env, 6); /* resimp */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = cons(stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = Lrplacd(nil, stack[-1], v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v156 = stack[-2];
    v156 = qcdr(v156);
    stack[-2] = v156;
    goto v112;

v50:
    v156 = stack[-3];
    stack[-1] = v156;
    goto v41;

v41:
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    stack[0] = qcar(v156);
    v156 = qvalue(elt(env, 3)); /* !*taylorkeeporiginal */
    if (v156 == nil) goto v159;
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcar(v156);
    if (v156 == nil) goto v159;
    v157 = stack[-5];
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcar(v156);
    fn = elt(env, 4); /* multsq */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-8];
    v157 = v156;
    goto v160;

v160:
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcar(v156);
    v156 = list2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v158;
    {
        Lisp_Object v161 = stack[-7];
        Lisp_Object v162 = stack[-1];
        Lisp_Object v163 = stack[0];
        popv(9);
        return list3star(v161, v162, v163, v156);
    }

v159:
    v156 = qvalue(elt(env, 1)); /* nil */
    v157 = v156;
    goto v160;

v72:
    v156 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v156;
    goto v41;

v18:
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v156); }
/* error exit handlers */
v158:
    popv(9);
    return nil;
}



/* Code for get_rep_of_generator */

static Lisp_Object CC_get_rep_of_generator(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v45, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_of_generator");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v19 = v78;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v45 = stack[-2];
    v65 = elt(env, 1); /* id */
    if (v45 == v65) goto v33;
    v65 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v65;
    v65 = v19;
    stack[0] = v65;
    goto v129;

v129:
    v65 = stack[-3];
    if (!(v65 == nil)) goto v130;
    v65 = stack[0];
    v45 = Llength(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    v65 = (Lisp_Object)1; /* 0 */
    v65 = (Lisp_Object)greaterp2(v45, v65);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v65 = v65 ? lisp_true : nil;
    env = stack[-4];
    if (v65 == nil) goto v130;
    v65 = stack[0];
    v65 = qcar(v65);
    v45 = qcar(v65);
    v65 = stack[-2];
    if (!(equal(v45, v65))) goto v76;
    v65 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v65;
    v65 = stack[0];
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v65 = qcar(v65);
    stack[-1] = v65;
    goto v76;

v76:
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v129;

v130:
    v65 = stack[-3];
    if (!(v65 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v65 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v65 == nil)) goto v125;
    v65 = elt(env, 5); /* " error in get rep of generators" */
    fn = elt(env, 6); /* lprie */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    goto v125;

v125:
    v65 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v65 = nil;
    { popv(5); return onevalue(v65); }

v33:
    v65 = v19;
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v65 = qcar(v65);
    fn = elt(env, 7); /* get!+row!+nr */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v65);
    }
/* error exit handlers */
v164:
    popv(5);
    return nil;
}



/* Code for diff2 */

static Lisp_Object CC_diff2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v98, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff2");
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
    v94 = v0;
/* end of prologue */
    v93 = v94;
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    stack[-5] = v93;
    v93 = v94;
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    stack[-4] = v93;
    v98 = stack[-5];
    v93 = (Lisp_Object)17; /* 1 */
    if (v98 == v93) { popv(8); return onevalue(v94); }
    v93 = v94;
    v93 = Lreverse(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = qcar(v93);
    stack[-6] = v93;
    stack[-3] = elt(env, 1); /* diff */
    stack[-2] = qvalue(elt(env, 2)); /* nil */
    stack[-1] = elt(env, 3); /* bvar */
    v94 = stack[-4];
    v98 = (Lisp_Object)17; /* 1 */
    v93 = qvalue(elt(env, 2)); /* nil */
    stack[0] = list2star(v94, v98, v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = stack[-6];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = acons(stack[-1], stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = list2star(stack[-3], stack[-2], v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-6] = v93;
    v93 = stack[-5];
    v93 = sub1(v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-5] = v93;
    goto v149;

v149:
    v98 = stack[-5];
    v93 = (Lisp_Object)1; /* 0 */
    v93 = (Lisp_Object)greaterp2(v98, v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v93 = v93 ? lisp_true : nil;
    env = stack[-7];
    if (v93 == nil) goto v82;
    stack[-3] = elt(env, 1); /* diff */
    stack[-2] = qvalue(elt(env, 2)); /* nil */
    stack[-1] = elt(env, 3); /* bvar */
    v94 = stack[-4];
    v98 = (Lisp_Object)17; /* 1 */
    v93 = qvalue(elt(env, 2)); /* nil */
    stack[0] = list2star(v94, v98, v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = stack[-6];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = acons(stack[-1], stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v93 = list2star(stack[-3], stack[-2], v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-6] = v93;
    v93 = stack[-5];
    v93 = sub1(v93);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-5] = v93;
    goto v149;

v82:
    v93 = stack[-6];
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    { popv(8); return onevalue(v93); }
/* error exit handlers */
v117:
    popv(8);
    return nil;
}



/* Code for varsinsf */

static Lisp_Object CC_varsinsf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for varsinsf");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v70 = v78;
    stack[-1] = v0;
/* end of prologue */
    v71 = stack[-1];
    if (!consp(v71)) { popv(4); return onevalue(v70); }
    v71 = stack[-1];
    v71 = qcar(v71);
    if (!consp(v71)) { popv(4); return onevalue(v70); }
    else goto v61;

v61:
    v71 = stack[-1];
    if (!consp(v71)) { popv(4); return onevalue(v70); }
    v71 = stack[-1];
    v71 = qcar(v71);
    if (!consp(v71)) { popv(4); return onevalue(v70); }
    v71 = stack[-1];
    v71 = qcar(v71);
    stack[-2] = qcdr(v71);
    stack[0] = v70;
    v70 = stack[-1];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    fn = elt(env, 2); /* union */
    v70 = (*qfn2(fn))(qenv(fn), stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v70 = CC_varsinsf(env, stack[-2], v70);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    goto v61;
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for mkratnum */

static Lisp_Object CC_mkratnum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v138;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkratnum");
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
    v138 = v0;
/* end of prologue */
    v21 = v138;
    if (!consp(v21)) goto v34;
    v21 = v138;
    v22 = qcar(v21);
    v21 = elt(env, 2); /* !:gi!: */
    if (v22 == v21) goto v105;
    v21 = v138;
    v22 = qcar(v21);
    v21 = elt(env, 1); /* !:rn!: */
    v21 = get(v22, v21);
    v22 = v138;
        return Lapply1(nil, v21, v22);

v105:
    v22 = elt(env, 2); /* !:gi!: */
    v21 = elt(env, 3); /* !:crn!: */
    v21 = get(v22, v21);
    v22 = v138;
        return Lapply1(nil, v21, v22);

v34:
    v22 = elt(env, 1); /* !:rn!: */
    v21 = (Lisp_Object)17; /* 1 */
    return list2star(v22, v138, v21);
}



/* Code for fast_setmat */

static Lisp_Object MS_CDECL CC_fast_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "fast_setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v78,v13,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v12;
    v165 = v13;
    v166 = v78;
    stack[0] = v0;
/* end of prologue */
    v167 = stack[0];
    v165 = list3(v167, v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    stack[-6] = v165;
    v165 = stack[0];
    stack[-4] = qcdr(v165);
    v165 = stack[-6];
    v165 = qcdr(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v63;
    v165 = stack[-3];
    v165 = qcar(v165);
    v166 = v165;
    v165 = v166;
    v165 = integerp(v165);
    if (v165 == nil) goto v22;
    v165 = v166;
    goto v36;

v36:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    stack[-1] = v165;
    stack[-2] = v165;
    goto v57;

v57:
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v104;
    stack[0] = stack[-1];
    v165 = stack[-3];
    v165 = qcar(v165);
    v166 = v165;
    v165 = v166;
    v165 = integerp(v165);
    if (v165 == nil) goto v101;
    v165 = v166;
    goto v46;

v46:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    v165 = Lrplacd(nil, stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    goto v57;

v101:
    v165 = v166;
    fn = elt(env, 2); /* reval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    goto v46;

v104:
    v165 = stack[-2];
    goto v56;

v56:
    v165 = qcar(v165);
    fn = elt(env, 3); /* pnth */
    v165 = (*qfn2(fn))(qenv(fn), stack[-4], v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    stack[-3] = qcar(v165);
    v165 = stack[-6];
    v165 = qcdr(v165);
    stack[-4] = v165;
    v165 = stack[-4];
    if (v165 == nil) goto v89;
    v165 = stack[-4];
    v165 = qcar(v165);
    v166 = v165;
    v165 = v166;
    v165 = integerp(v165);
    if (v165 == nil) goto v169;
    v165 = v166;
    goto v170;

v170:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    stack[-1] = v165;
    stack[-2] = v165;
    goto v141;

v141:
    v165 = stack[-4];
    v165 = qcdr(v165);
    stack[-4] = v165;
    v165 = stack[-4];
    if (v165 == nil) goto v171;
    stack[0] = stack[-1];
    v165 = stack[-4];
    v165 = qcar(v165);
    v166 = v165;
    v165 = v166;
    v165 = integerp(v165);
    if (v165 == nil) goto v91;
    v165 = v166;
    goto v116;

v116:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    v165 = Lrplacd(nil, stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    goto v141;

v91:
    v165 = v166;
    fn = elt(env, 2); /* reval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    goto v116;

v171:
    v165 = stack[-2];
    goto v74;

v74:
    v165 = qcdr(v165);
    v165 = qcar(v165);
    fn = elt(env, 3); /* pnth */
    v166 = (*qfn2(fn))(qenv(fn), stack[-3], v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v165 = stack[-5];
        popv(8);
        return Lrplaca(nil, v166, v165);

v169:
    v165 = v166;
    fn = elt(env, 2); /* reval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    goto v170;

v89:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v74;

v22:
    v165 = v166;
    fn = elt(env, 2); /* reval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-7];
    goto v36;

v63:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v56;
/* error exit handlers */
v168:
    popv(8);
    return nil;
}



/* Code for groebcplistsort */

static Lisp_Object CC_groebcplistsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsort");
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
    v129 = v0;
/* end of prologue */
    v26 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v129;
    goto v123;

v123:
    v129 = stack[0];
    if (v129 == nil) { popv(2); return onevalue(v26); }
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 2); /* groebcplistsortin */
    v129 = (*qfn2(fn))(qenv(fn), v129, v26);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v26 = v129;
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v123;
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for partitindexvar */

static Lisp_Object CC_partitindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v309, v310, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitindexvar");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    v309 = stack[-7];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v87;
    v309 = stack[-4];
    v309 = qcar(v309);
    fn = elt(env, 7); /* revalind */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v310 = v309;
    v309 = v310;
    if (!consp(v309)) goto v105;
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    if (is_number(v309)) goto v24;
    v309 = v310;
    goto v55;

v55:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-2] = v309;
    stack[-3] = v309;
    goto v136;

v136:
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v19;
    stack[-1] = stack[-2];
    v309 = stack[-4];
    v309 = qcar(v309);
    fn = elt(env, 7); /* revalind */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v310 = v309;
    v309 = v310;
    if (!consp(v309)) goto v75;
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    if (is_number(v309)) goto v153;
    v309 = v310;
    goto v16;

v16:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lrplacd(nil, stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-2];
    v309 = qcdr(v309);
    stack[-2] = v309;
    goto v136;

v153:
    stack[0] = elt(env, 2); /* minus */
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = list2(stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v16;

v75:
    v309 = v310;
    if (is_number(v309)) goto v151;
    v309 = v310;
    goto v16;

v151:
    v309 = v310;
    v309 = Lminusp(nil, v309);
    env = stack[-9];
    if (v309 == nil) goto v171;
    stack[0] = elt(env, 2); /* minus */
    v309 = v310;
    v309 = Labsval(nil, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = list2(stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v16;

v171:
    v309 = v310;
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v16;

v19:
    v309 = stack[-3];
    goto v32;

v32:
    stack[0] = v309;
    v309 = stack[-7];
    fn = elt(env, 9); /* deg!*form */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-3] = v309;
    v309 = qvalue(elt(env, 3)); /* metricu!* */
    if (v309 == nil) goto v53;
    v309 = stack[0];
    stack[-2] = v309;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = elt(env, 4); /* covariant */
    v309 = Lflagp(nil, v310, v309);
    env = stack[-9];
    if (!(v309 == nil)) goto v313;

v113:
    v309 = stack[-2];
    if (v309 == nil) goto v4;
    v309 = stack[-2];
    v309 = qcar(v309);
    if (!consp(v309)) goto v314;
    v309 = stack[-2];
    v309 = qcar(v309);
    v309 = qcdr(v309);
    v310 = qcar(v309);
    v309 = qvalue(elt(env, 3)); /* metricu!* */
    v309 = Latsoc(nil, v310, v309);
    if (!(v309 == nil)) goto v4;

v314:
    v309 = stack[-2];
    v310 = qcar(v309);
    v309 = stack[-6];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-6] = v309;
    v309 = stack[-2];
    v309 = qcar(v309);
    if (!consp(v309)) goto v315;
    v309 = stack[-2];
    v309 = qcar(v309);
    v309 = qcdr(v309);
    v310 = qcar(v309);
    v309 = stack[-8];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-8] = v309;
    goto v315;

v315:
    v309 = stack[-2];
    v309 = qcdr(v309);
    stack[-2] = v309;
    goto v113;

v4:
    v309 = stack[-2];
    if (v309 == nil) goto v53;
    v309 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v309;
    v309 = stack[-6];
    v309 = Lreverse(nil, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-6] = v309;
    v309 = stack[-2];
    v309 = qcar(v309);
    v309 = qcdr(v309);
    v309 = qcar(v309);
    fn = elt(env, 10); /* getlower */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-4] = v309;
    goto v316;

v316:
    v309 = stack[-4];
    if (v309 == nil) { Lisp_Object res = stack[-5]; popv(10); return onevalue(res); }
    v309 = stack[-4];
    v309 = qcar(v309);
    stack[-3] = v309;
    v309 = stack[-7];
    stack[-1] = qcar(v309);
    stack[0] = stack[-6];
    v309 = stack[-3];
    v310 = qcar(v309);
    v309 = stack[-2];
    v309 = qcdr(v309);
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lappend(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = cons(stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[0] = CC_partitindexvar(env, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-3];
    v309 = qcdr(v309);
    fn = elt(env, 11); /* simp */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 12); /* multpfsq */
    v310 = (*qfn2(fn))(qenv(fn), stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-5];
    fn = elt(env, 13); /* addpf */
    v309 = (*qfn2(fn))(qenv(fn), v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-5] = v309;
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    goto v316;

v53:
    v309 = stack[0];
    fn = elt(env, 14); /* coposp */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    if (v309 == nil) goto v317;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = elt(env, 5); /* indxsymmetries */
    v309 = get(v310, v309);
    env = stack[-9];
    if (v309 == nil) goto v317;
    v309 = stack[0];
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v318;
    v309 = stack[-4];
    v309 = qcar(v309);
    v310 = v309;
    v309 = v310;
    if (!consp(v309)) goto v319;
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    goto v320;

v320:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-1] = v309;
    stack[-2] = v309;
    goto v321;

v321:
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v322;
    stack[0] = stack[-1];
    v309 = stack[-4];
    v309 = qcar(v309);
    v310 = v309;
    v309 = v310;
    if (!consp(v309)) goto v323;
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    goto v324;

v324:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lrplacd(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-1];
    v309 = qcdr(v309);
    stack[-1] = v309;
    goto v321;

v323:
    v309 = v310;
    goto v324;

v322:
    v309 = stack[-2];
    goto v325;

v325:
    stack[0] = v309;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 15); /* indexsymmetrize */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[0] = v309;
    v309 = stack[0];
    if (v309 == nil) goto v326;
    v309 = stack[0];
    v310 = qcar(v309);
    v309 = (Lisp_Object)-15; /* -1 */
    if (!(v310 == v309)) goto v327;
    v309 = qvalue(elt(env, 6)); /* t */
    stack[-5] = v309;
    goto v327;

v327:
    v309 = stack[0];
    v309 = qcdr(v309);
    v309 = qcdr(v309);
    stack[0] = v309;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = elt(env, 4); /* covariant */
    v309 = Lflagp(nil, v310, v309);
    env = stack[-9];
    if (v309 == nil) goto v328;
    v309 = stack[0];
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v329;
    v309 = stack[-4];
    v309 = qcar(v309);
    v311 = v309;
    v310 = v311;
    v309 = stack[-8];
    v309 = Lmemq(nil, v310, v309);
    if (v309 == nil) goto v330;
    v309 = v311;
    goto v331;

v331:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-1] = v309;
    stack[-2] = v309;
    goto v332;

v332:
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v333;
    stack[0] = stack[-1];
    v309 = stack[-4];
    v309 = qcar(v309);
    v311 = v309;
    v310 = v311;
    v309 = stack[-8];
    v309 = Lmemq(nil, v310, v309);
    if (v309 == nil) goto v334;
    v309 = v311;
    goto v335;

v335:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lrplacd(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-1];
    v309 = qcdr(v309);
    stack[-1] = v309;
    goto v332;

v334:
    v309 = elt(env, 2); /* minus */
    v310 = v311;
    v309 = list2(v309, v310);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v335;

v333:
    v309 = stack[-2];
    goto v336;

v336:
    stack[0] = v309;
    goto v337;

v337:
    v309 = stack[-3];
    if (v309 == nil) goto v338;
    v309 = stack[-5];
    if (v309 == nil) goto v339;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 16); /* mkupf */
    stack[0] = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v310 = (Lisp_Object)-15; /* -1 */
    v309 = (Lisp_Object)17; /* 1 */
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    {
        Lisp_Object v340 = stack[0];
        popv(10);
        fn = elt(env, 12); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v340, v309);
    }

v339:
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 16); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v309);
    }

v338:
    v309 = stack[-5];
    if (v309 == nil) goto v341;
    stack[-1] = (Lisp_Object)17; /* 1 */
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v310 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* mksq */
    v309 = (*qfn2(fn))(qenv(fn), v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[0] = v309;
    v309 = stack[0];
    v309 = qcar(v309);
    fn = elt(env, 18); /* negf */
    v310 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[0];
    v309 = qcdr(v309);
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = cons(stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    popv(10);
    return ncons(v309);

v341:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v310 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* mksq */
    v309 = (*qfn2(fn))(qenv(fn), v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = cons(stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    popv(10);
    return ncons(v309);

v330:
    v309 = elt(env, 2); /* minus */
    v310 = v311;
    v309 = list2(v309, v310);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v331;

v329:
    v309 = qvalue(elt(env, 1)); /* nil */
    goto v336;

v328:
    v309 = qvalue(elt(env, 3)); /* metricu!* */
    if (!(v309 == nil)) goto v342;
    v309 = stack[-7];
    v309 = qcdr(v309);
    v309 = qcar(v309);
    if (!consp(v309)) goto v342;
    v309 = stack[0];
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v343;
    v309 = stack[-4];
    v309 = qcar(v309);
    v310 = elt(env, 2); /* minus */
    v309 = list2(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-1] = v309;
    stack[-2] = v309;
    goto v344;

v344:
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v345;
    stack[0] = stack[-1];
    v309 = stack[-4];
    v309 = qcar(v309);
    v310 = elt(env, 2); /* minus */
    v309 = list2(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lrplacd(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-1];
    v309 = qcdr(v309);
    stack[-1] = v309;
    goto v344;

v345:
    v309 = stack[-2];
    goto v346;

v346:
    stack[0] = v309;
    goto v337;

v343:
    v309 = qvalue(elt(env, 1)); /* nil */
    goto v346;

v342:
    v309 = stack[0];
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v347;
    v309 = stack[-4];
    v309 = qcar(v309);
    v311 = v309;
    v310 = v311;
    v309 = stack[-8];
    v309 = Lmemq(nil, v310, v309);
    if (v309 == nil) goto v348;
    v309 = elt(env, 2); /* minus */
    v310 = v311;
    v309 = list2(v309, v310);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v349;

v349:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-1] = v309;
    stack[-2] = v309;
    goto v350;

v350:
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    v309 = stack[-4];
    if (v309 == nil) goto v351;
    stack[0] = stack[-1];
    v309 = stack[-4];
    v309 = qcar(v309);
    v311 = v309;
    v310 = v311;
    v309 = stack[-8];
    v309 = Lmemq(nil, v310, v309);
    if (v309 == nil) goto v352;
    v309 = elt(env, 2); /* minus */
    v310 = v311;
    v309 = list2(v309, v310);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v353;

v353:
    v309 = ncons(v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lrplacd(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-1];
    v309 = qcdr(v309);
    stack[-1] = v309;
    goto v350;

v352:
    v309 = v311;
    goto v353;

v351:
    v309 = stack[-2];
    goto v354;

v354:
    stack[0] = v309;
    goto v337;

v348:
    v309 = v311;
    goto v349;

v347:
    v309 = qvalue(elt(env, 1)); /* nil */
    goto v354;

v326:
    v309 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v309); }

v319:
    v309 = v310;
    goto v320;

v318:
    v309 = qvalue(elt(env, 1)); /* nil */
    goto v325;

v317:
    v309 = stack[-3];
    if (v309 == nil) goto v355;
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 16); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v309);
    }

v355:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v309 = stack[-7];
    v310 = qcar(v309);
    v309 = stack[0];
    v310 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* mksq */
    v309 = (*qfn2(fn))(qenv(fn), v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = cons(stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    popv(10);
    return ncons(v309);

v313:
    v309 = stack[-2];
    if (v309 == nil) goto v356;
    v309 = stack[-2];
    v309 = qcar(v309);
    if (!(!consp(v309))) goto v357;
    v309 = stack[-2];
    v310 = qcar(v309);
    v309 = qvalue(elt(env, 3)); /* metricu!* */
    v309 = Latsoc(nil, v310, v309);
    if (!(v309 == nil)) goto v356;

v357:
    v309 = stack[-2];
    v310 = qcar(v309);
    v309 = stack[-6];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-6] = v309;
    v309 = stack[-2];
    v309 = qcar(v309);
    if (!(!consp(v309))) goto v358;
    v309 = stack[-2];
    v310 = qcar(v309);
    v309 = stack[-8];
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-8] = v309;
    goto v358;

v358:
    v309 = stack[-2];
    v309 = qcdr(v309);
    stack[-2] = v309;
    goto v313;

v356:
    v309 = stack[-2];
    if (v309 == nil) goto v53;
    v309 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v309;
    v309 = stack[-6];
    v309 = Lreverse(nil, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-6] = v309;
    v309 = stack[-2];
    v309 = qcar(v309);
    fn = elt(env, 19); /* getupper */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-4] = v309;
    goto v359;

v359:
    v309 = stack[-4];
    if (v309 == nil) { Lisp_Object res = stack[-5]; popv(10); return onevalue(res); }
    v309 = stack[-4];
    v309 = qcar(v309);
    stack[-3] = v309;
    v309 = stack[-7];
    stack[-1] = qcar(v309);
    stack[0] = stack[-6];
    v310 = elt(env, 2); /* minus */
    v309 = stack[-3];
    v309 = qcar(v309);
    v310 = list2(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-2];
    v309 = qcdr(v309);
    v309 = cons(v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = Lappend(nil, stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = cons(stack[-1], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[0] = CC_partitindexvar(env, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-3];
    v309 = qcdr(v309);
    fn = elt(env, 11); /* simp */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 12); /* multpfsq */
    v310 = (*qfn2(fn))(qenv(fn), stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = stack[-5];
    fn = elt(env, 13); /* addpf */
    v309 = (*qfn2(fn))(qenv(fn), v310, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-5] = v309;
    v309 = stack[-4];
    v309 = qcdr(v309);
    stack[-4] = v309;
    goto v359;

v24:
    stack[0] = elt(env, 2); /* minus */
    v309 = v310;
    v309 = qcdr(v309);
    v309 = qcar(v309);
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = list2(stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v55;

v105:
    v309 = v310;
    if (is_number(v309)) goto v137;
    v309 = v310;
    goto v55;

v137:
    v309 = v310;
    v309 = Lminusp(nil, v309);
    env = stack[-9];
    if (v309 == nil) goto v124;
    stack[0] = elt(env, 2); /* minus */
    v309 = v310;
    v309 = Labsval(nil, v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v309 = list2(stack[0], v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v55;

v124:
    v309 = v310;
    fn = elt(env, 8); /* !*num2id */
    v309 = (*qfn1(fn))(qenv(fn), v309);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v55;

v87:
    v309 = qvalue(elt(env, 1)); /* nil */
    goto v32;
/* error exit handlers */
v312:
    popv(10);
    return nil;
}



/* Code for listminimize */

static Lisp_Object CC_listminimize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listminimize");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v78;
    v107 = v0;
/* end of prologue */
    v35 = v107;
    if (v35 == nil) goto v18;
    v35 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* cali!=min */
    v106 = (*qfnn(fn))(qenv(fn), 3, v35, v107, v106);
    errexit();
        return Lreverse(nil, v106);

v18:
    v106 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v106);
}



/* Code for remk */

static Lisp_Object CC_remk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remk");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v78;
    stack[-5] = v0;
/* end of prologue */
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    stack[-6] = v99;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v99 = qcar(v99);
    stack[-3] = v99;
    v99 = stack[-4];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v86;

v86:
    v151 = stack[-5];
    v99 = stack[-3];
    fn = elt(env, 2); /* degr */
    v151 = (*qfn2(fn))(qenv(fn), v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v99 = stack[0];
    v151 = difference2(v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-1] = v151;
    v99 = (Lisp_Object)1; /* 0 */
    v99 = (Lisp_Object)geq2(v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    v99 = v99 ? lisp_true : nil;
    env = stack[-7];
    if (v99 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v99 = stack[-5];
    v99 = qcar(v99);
    v151 = qcdr(v99);
    v99 = stack[-4];
    v99 = qcdr(v99);
    fn = elt(env, 3); /* multf */
    v99 = (*qfn2(fn))(qenv(fn), v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    fn = elt(env, 4); /* negf */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-2] = v99;
    v151 = stack[-1];
    v99 = (Lisp_Object)1; /* 0 */
    v99 = (Lisp_Object)greaterp2(v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    v99 = v99 ? lisp_true : nil;
    env = stack[-7];
    if (v99 == nil) goto v73;
    v152 = stack[-3];
    v151 = stack[-1];
    v99 = (Lisp_Object)17; /* 1 */
    v99 = acons(v152, v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v151 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v99 = stack[-2];
    fn = elt(env, 3); /* multf */
    v99 = (*qfn2(fn))(qenv(fn), v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-2] = v99;
    goto v73;

v73:
    v151 = stack[-6];
    v99 = stack[-5];
    v99 = qcdr(v99);
    fn = elt(env, 3); /* multf */
    v151 = (*qfn2(fn))(qenv(fn), v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    v99 = stack[-2];
    fn = elt(env, 5); /* addf */
    v99 = (*qfn2(fn))(qenv(fn), v151, v99);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-7];
    stack[-5] = v99;
    goto v86;
/* error exit handlers */
v360:
    popv(8);
    return nil;
}



/* Code for mod!/ */

static Lisp_Object CC_modV(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v25, v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod/");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v112 = v78;
    v25 = v0;
/* end of prologue */
    stack[0] = v25;
    v55 = qvalue(elt(env, 1)); /* current!-modulus */
    v54 = v112;
    v25 = (Lisp_Object)1; /* 0 */
    v112 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* general!-reciprocal!-by!-gcd */
    v112 = (*qfnn(fn))(qenv(fn), 4, v55, v54, v25, v112);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v112 = times2(stack[0], v112);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v25 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return Cremainder(v112, v25);
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for ofsf_smwrmknowl */

static Lisp_Object CC_ofsf_smwrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v135, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwrmknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v135 = v78;
    v130 = v0;
/* end of prologue */
    v58 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v58 == nil) goto v61;
    v58 = v130;
    {
        fn = elt(env, 2); /* ofsf_susirmknowl */
        return (*qfn2(fn))(qenv(fn), v58, v135);
    }

v61:
    v58 = v130;
    {
        fn = elt(env, 3); /* ofsf_smrmknowl */
        return (*qfn2(fn))(qenv(fn), v58, v135);
    }
}



/* Code for depend!-l */

static Lisp_Object CC_dependKl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v78)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-l");
#endif
    if (stack >= stacklimit)
    {
        push2(v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v78);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v78;
    stack[-1] = v0;
/* end of prologue */

v18:
    v129 = stack[-1];
    if (v129 == nil) goto v34;
    v129 = stack[-1];
    v129 = qcar(v129);
    fn = elt(env, 3); /* simp */
    v26 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v129 = stack[0];
    fn = elt(env, 4); /* depend!-sq */
    v129 = (*qfn2(fn))(qenv(fn), v26, v129);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (v129 == nil) goto v35;
    v129 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v129); }

v35:
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v18;

v34:
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v129); }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for pasf_dnf */

static Lisp_Object CC_pasf_dnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dnf");
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
/* copy arguments values to proper place */
    v53 = v0;
/* end of prologue */
    fn = elt(env, 2); /* pasf_pnf */
    v47 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[0];
    v53 = elt(env, 1); /* dnf */
    {
        popv(1);
        fn = elt(env, 3); /* pasf_pbnf */
        return (*qfn2(fn))(qenv(fn), v47, v53);
    }
/* error exit handlers */
v64:
    popv(1);
    return nil;
}



/* Code for operator_fn */

static Lisp_Object CC_operator_fn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator_fn");
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
    v71 = stack[0];
    v36 = qcar(v71);
    v71 = elt(env, 1); /* ((arcsinh . sinh) (arcsech . sech) (arccosh . cosh) (arccsch csch) (arctanh . tanh) (arccoth . coth)) 
*/
    v71 = Latsoc(nil, v36, v71);
    stack[-1] = v71;
    v71 = stack[-1];
    if (v71 == nil) goto v35;
    v71 = elt(env, 2); /* "<apply><inverse/>" */
    fn = elt(env, 8); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v71 = stack[-1];
    v71 = qcdr(v71);
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    goto v105;

v105:
    v36 = qvalue(elt(env, 6)); /* indent */
    v71 = (Lisp_Object)49; /* 3 */
    v71 = plus2(v36, v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    qvalue(elt(env, 6)) = v71; /* indent */
    v71 = stack[0];
    v71 = qcdr(v71);
    fn = elt(env, 9); /* multi_args */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v36 = qvalue(elt(env, 6)); /* indent */
    v71 = (Lisp_Object)49; /* 3 */
    v71 = difference2(v36, v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    qvalue(elt(env, 6)) = v71; /* indent */
    v71 = elt(env, 7); /* "</apply>" */
    fn = elt(env, 8); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v71 = nil;
    { popv(3); return onevalue(v71); }

v35:
    v71 = elt(env, 4); /* "<apply><fn><ci>" */
    fn = elt(env, 8); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v71 = stack[0];
    v71 = qcar(v71);
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v71 = elt(env, 5); /* "</ci></fn>" */
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    goto v105;
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for row_dim */

static Lisp_Object CC_row_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for row_dim");
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
    v58 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v58 == nil)) goto v18;
    v58 = stack[0];
    fn = elt(env, 4); /* matrixp */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    if (!(v58 == nil)) goto v18;
    v58 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v58 == nil)) goto v32;
    v58 = elt(env, 3); /* "Error in row_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    goto v32;

v32:
    v58 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    goto v18;

v18:
    v58 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v130;
    v58 = qcar(v58);
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for xpartitop */

static Lisp_Object CC_xpartitop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitop");
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
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* xpartitsq */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v128:
    popv(1);
    return nil;
}



/* Code for let2 */

static Lisp_Object MS_CDECL CC_let2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v78,
                         Lisp_Object v13, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v393, v359, v394, v395, v396;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "let2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let2");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v13,v78,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v78,v13,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v12;
    stack[-4] = v13;
    stack[-5] = v78;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v393 = stack[-6];
    fn = elt(env, 19); /* getrtype */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-1] = v393;
    if (v393 == nil) goto v62;
    v359 = stack[-1];
    v393 = elt(env, 1); /* typeletfn */
    v393 = get(v359, v393);
    env = stack[-8];
    v394 = v393;
    if (v393 == nil) goto v62;
    v359 = v394;
    v393 = elt(env, 2); /* direct */
    v393 = Lflagp(nil, v359, v393);
    env = stack[-8];
    if (v393 == nil) goto v62;
    v393 = v394;
    if (!consp(v393)) goto v148;
    v393 = elt(env, 3); /* "Apply called with non-id arg" */
    v359 = v394;
    v393 = list2(v393, v359);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v359 = v393;
    v393 = v359;
    qvalue(elt(env, 4)) = v393; /* errmsg!* */
    v393 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v393 == nil)) goto v70;
    v393 = v359;
    fn = elt(env, 20); /* lprie */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    goto v70;

v70:
    v393 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v273;
    v393 = nil;
    { popv(9); return onevalue(v393); }

v148:
    stack[-2] = v394;
    stack[-4] = stack[-6];
    stack[0] = stack[-5];
    v393 = stack[-5];
    fn = elt(env, 19); /* getrtype */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v393 = list2(stack[-3], v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v393 = list3star(stack[-4], stack[0], stack[-1], v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    {
        Lisp_Object v397 = stack[-2];
        popv(9);
        fn = elt(env, 21); /* apply */
        return (*qfn2(fn))(qenv(fn), v397, v393);
    }

v62:
    v393 = stack[-5];
    fn = elt(env, 19); /* getrtype */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-1] = v393;
    if (v393 == nil) goto v398;
    v359 = stack[-1];
    v393 = elt(env, 1); /* typeletfn */
    v393 = get(v359, v393);
    env = stack[-8];
    v394 = v393;
    if (v393 == nil) goto v398;
    v359 = v394;
    v393 = elt(env, 2); /* direct */
    v393 = Lflagp(nil, v359, v393);
    env = stack[-8];
    if (v393 == nil) goto v398;
    v393 = v394;
    if (!consp(v393)) goto v11;
    v393 = elt(env, 3); /* "Apply called with non-id arg" */
    v359 = v394;
    v393 = list2(v393, v359);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v359 = v393;
    v393 = v359;
    qvalue(elt(env, 4)) = v393; /* errmsg!* */
    v393 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v393 == nil)) goto v171;
    v393 = v359;
    fn = elt(env, 20); /* lprie */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    goto v171;

v171:
    v393 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v273;
    v393 = nil;
    { popv(9); return onevalue(v393); }

v11:
    stack[-2] = v394;
    stack[-4] = stack[-6];
    stack[0] = qvalue(elt(env, 6)); /* nil */
    v359 = stack[-3];
    v393 = stack[-1];
    v393 = list2(v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v393 = list3star(stack[-4], stack[-5], stack[0], v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    {
        Lisp_Object v399 = stack[-2];
        popv(9);
        fn = elt(env, 21); /* apply */
        return (*qfn2(fn))(qenv(fn), v399, v393);
    }

v398:
    v359 = qvalue(elt(env, 7)); /* frasc!* */
    v393 = stack[-6];
    v393 = Lsubla(nil, v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-2] = v393;
    v359 = stack[-2];
    v393 = stack[-6];
    if (equal(v359, v393)) goto v304;
    v393 = stack[-2];
    if (!consp(v393)) goto v44;
    v393 = qvalue(elt(env, 10)); /* t */
    stack[-7] = v393;
    v393 = stack[-2];
    stack[-6] = v393;
    goto v304;

v304:
    v359 = qvalue(elt(env, 7)); /* frasc!* */
    v393 = stack[-5];
    v393 = Lsubla(nil, v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-2] = v393;
    v359 = stack[-2];
    v393 = stack[-5];
    if (equal(v359, v393)) goto v400;
    v393 = stack[-2];
    stack[-5] = v393;
    v359 = stack[-5];
    v393 = elt(env, 11); /* !*sq!* */
    if (!consp(v359)) goto v400;
    v359 = qcar(v359);
    if (!(v359 == v393)) goto v400;
    v393 = stack[-5];
    v393 = qcdr(v393);
    v393 = qcar(v393);
    fn = elt(env, 22); /* prepsq!* */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-5] = v393;
    goto v400;

v400:
    v359 = qvalue(elt(env, 12)); /* frlis!* */
    v393 = qvalue(elt(env, 13)); /* mcond!* */
    fn = elt(env, 23); /* smemql */
    v393 = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-2] = v393;
    v359 = qvalue(elt(env, 12)); /* frlis!* */
    v393 = stack[-6];
    fn = elt(env, 23); /* smemql */
    v393 = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-1] = v393;
    v359 = stack[-2];
    v393 = stack[-1];
    fn = elt(env, 24); /* setdiff */
    v393 = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v394 = v393;
    if (!(v393 == nil)) goto v401;
    v359 = qvalue(elt(env, 12)); /* frlis!* */
    v393 = stack[-5];
    fn = elt(env, 23); /* smemql */
    v359 = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v393 = stack[-2];
    fn = elt(env, 24); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v359 = stack[-1];
    v393 = stack[-2];
    fn = elt(env, 24); /* setdiff */
    v393 = (*qfn2(fn))(qenv(fn), v359, v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    fn = elt(env, 24); /* setdiff */
    v393 = (*qfn2(fn))(qenv(fn), stack[0], v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v394 = v393;
    if (!(v393 == nil)) goto v401;
    v393 = stack[-6];
    if (!consp(v393)) goto v402;
    v393 = stack[-6];
    v359 = qcar(v393);
    v393 = elt(env, 17); /* getel */
    if (v359 == v393) goto v403;
    v393 = stack[-6];
    v359 = qcar(v393);
    v393 = elt(env, 18); /* immediate */
    v393 = Lflagp(nil, v359, v393);
    env = stack[-8];
    if (v393 == nil) goto v402;
    v393 = stack[-6];
    fn = elt(env, 25); /* reval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-6] = v393;
    goto v402;

v402:
    v396 = stack[-6];
    v395 = stack[-5];
    v394 = stack[-4];
    v359 = stack[-3];
    v393 = stack[-7];
    {
        popv(9);
        fn = elt(env, 26); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v396, v395, v394, v359, v393);
    }

v403:
    v393 = stack[-6];
    v393 = qcdr(v393);
    v393 = qcar(v393);
    fn = elt(env, 27); /* eval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    stack[-6] = v393;
    goto v402;

v401:
    v393 = elt(env, 14); /* "Unmatched free variable(s)" */
    v359 = v394;
    v393 = cons(v393, v359);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    fn = elt(env, 20); /* lprie */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-8];
    v393 = elt(env, 15); /* hold */
    qvalue(elt(env, 16)) = v393; /* erfg!* */
    v393 = qvalue(elt(env, 6)); /* nil */
    { popv(9); return onevalue(v393); }

v44:
    v396 = elt(env, 8); /* "Substitution for" */
    v395 = stack[-6];
    v394 = elt(env, 9); /* "not allowed" */
    v359 = qvalue(elt(env, 6)); /* nil */
    v393 = qvalue(elt(env, 10)); /* t */
    {
        popv(9);
        fn = elt(env, 28); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v396, v395, v394, v359, v393);
    }
/* error exit handlers */
v273:
    popv(9);
    return nil;
}



setup_type const u44_setup[] =
{
    {"sep_tens_from_other",     CC_sep_tens_from_other,too_many_1,wrong_no_1},
    {"mk_character",            CC_mk_character,too_many_1,    wrong_no_1},
    {"limitom",                 CC_limitom,     too_many_1,    wrong_no_1},
    {"make-ps",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKps},
    {"get_num_part",            CC_get_num_part,too_many_1,    wrong_no_1},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"f2dip2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip2},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"drop_rl_with",            too_few_2,      CC_drop_rl_with,wrong_no_2},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {"mo_deletecomp",           CC_mo_deletecomp,too_many_1,   wrong_no_1},
    {"rl_qe",                   too_few_2,      CC_rl_qe,      wrong_no_2},
    {"addcoeffs",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_addcoeffs},
    {"pasf_pnf",                CC_pasf_pnf,    too_many_1,    wrong_no_1},
    {"pdiffvars",               too_few_2,      CC_pdiffvars,  wrong_no_2},
    {"fac-part",                too_few_2,      CC_facKpart,   wrong_no_2},
    {"addns",                   too_few_2,      CC_addns,      wrong_no_2},
    {"f2dip",                   CC_f2dip,       too_many_1,    wrong_no_1},
    {"xexptpf",                 too_few_2,      CC_xexptpf,    wrong_no_2},
    {"simpintersection",        CC_simpintersection,too_many_1,wrong_no_1},
    {"forttab",                 CC_forttab,     too_many_1,    wrong_no_1},
    {"al1_defined_vertex",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_al1_defined_vertex},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"uterm",                   too_few_2,      CC_uterm,      wrong_no_2},
    {"multtaylorsq",            too_few_2,      CC_multtaylorsq,wrong_no_2},
    {"get_rep_of_generator",    too_few_2,      CC_get_rep_of_generator,wrong_no_2},
    {"diff2",                   CC_diff2,       too_many_1,    wrong_no_1},
    {"varsinsf",                too_few_2,      CC_varsinsf,   wrong_no_2},
    {"mkratnum",                CC_mkratnum,    too_many_1,    wrong_no_1},
    {"fast_setmat",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_fast_setmat},
    {"groebcplistsort",         CC_groebcplistsort,too_many_1, wrong_no_1},
    {"partitindexvar",          CC_partitindexvar,too_many_1,  wrong_no_1},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"remk",                    too_few_2,      CC_remk,       wrong_no_2},
    {"mod/",                    too_few_2,      CC_modV,       wrong_no_2},
    {"ofsf_smwrmknowl",         too_few_2,      CC_ofsf_smwrmknowl,wrong_no_2},
    {"depend-l",                too_few_2,      CC_dependKl,   wrong_no_2},
    {"pasf_dnf",                CC_pasf_dnf,    too_many_1,    wrong_no_1},
    {"operator_fn",             CC_operator_fn, too_many_1,    wrong_no_1},
    {"row_dim",                 CC_row_dim,     too_many_1,    wrong_no_1},
    {"xpartitop",               CC_xpartitop,   too_many_1,    wrong_no_1},
    {"let2",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let2},
    {NULL, (one_args *)"u44", (two_args *)"21445 1479647 3936109", 0}
};

/* end of generated code */
