
/* $destdir\u41.c        Machine generated C code */

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


/* Code for simpx1 */

static Lisp_Object MS_CDECL CC_simpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpx1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-6] = nil;
    v154 = stack[-4];
    v153 = elt(env, 1); /* !*minus!* */
    if (!consp(v154)) goto v156;
    v154 = qcar(v154);
    if (!(v154 == v153)) goto v156;
    v154 = stack[-1];
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v157;
    v153 = stack[-3];
    v153 = integerp(v153);
    if (v153 == nil) goto v157;
    v154 = stack[-3];
    v153 = (Lisp_Object)33; /* 2 */
    v154 = Cremainder(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = (Lisp_Object)1; /* 0 */
    if (!(v154 == v153)) goto v157;

v159:
    stack[-6] = elt(env, 3); /* expt */
    stack[-5] = elt(env, 4); /* i */
    stack[-2] = elt(env, 2); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v154 = stack[-3];
    v153 = (Lisp_Object)33; /* 2 */
    v153 = quot2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = list3(stack[-2], stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = list3(stack[-6], stack[-5], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = stack[-4];
    v153 = qcdr(v153);
    stack[-2] = qcar(v153);
    v155 = elt(env, 2); /* quotient */
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = list2(stack[-2], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    {
        Lisp_Object v160 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v160, v153);
    }

v157:
    v154 = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v161;
    v154 = stack[-1];
    v153 = elt(env, 2); /* quotient */
    if (!consp(v154)) goto v161;
    v154 = qcar(v154);
    if (!(v154 == v153)) goto v161;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v154 = qcar(v153);
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v161;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = integerp(v153);
    if (v153 == nil) goto v161;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v154 = qcar(v153);
    v153 = (Lisp_Object)33; /* 2 */
    v154 = Cremainder(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = (Lisp_Object)1; /* 0 */
    if (v154 == v153) goto v159;
    else goto v161;

v161:
    v154 = stack[-1];
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v156;
    v153 = stack[-3];
    v153 = integerp(v153);
    if (v153 == nil) goto v156;
    v153 = stack[-4];
    v153 = qcdr(v153);
    stack[0] = qcar(v153);
    v155 = elt(env, 2); /* quotient */
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = list2(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v153;
    v153 = stack[0];
    v153 = qcar(v153);
    fn = elt(env, 23); /* negf */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    v153 = stack[0];
    v153 = qcdr(v153);
    popv(8);
    return cons(v154, v153);

v156:
    v153 = stack[-1];
    if (!(is_number(v153))) goto v162;
    v153 = stack[-3];
    if (!(is_number(v153))) goto v162;

v163:
    v153 = stack[-1];
    if (is_number(v153)) goto v164;
    v153 = stack[-1];
    if (!consp(v153)) goto v165;
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = elt(env, 11); /* minus */
    if (v154 == v153) goto v166;
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = elt(env, 12); /* plus */
    if (!(v154 == v153)) goto v167;
    v153 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v153 == nil) goto v167;
    v154 = (Lisp_Object)17; /* 1 */
    v153 = (Lisp_Object)17; /* 1 */
    v153 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    v153 = stack[-1];
    v153 = qcdr(v153);
    stack[-2] = v153;
    goto v168;

v168:
    v153 = stack[-2];
    if (v153 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v153 = stack[-2];
    v153 = qcar(v153);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 2); /* quotient */
    v154 = stack[-6];
    if (v154 == nil) goto v169;
    v154 = elt(env, 11); /* minus */
    v153 = list2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v154 = v153;
    goto v170;

v170:
    v153 = stack[-3];
    v153 = list3(stack[0], v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = list2(stack[-1], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = stack[-5];
    fn = elt(env, 22); /* multsq */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    v153 = stack[-2];
    v153 = qcdr(v153);
    stack[-2] = v153;
    goto v168;

v169:
    v154 = v153;
    goto v170;

v167:
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = elt(env, 15); /* times */
    if (!(v154 == v153)) goto v171;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = integerp(v153);
    if (v153 == nil) goto v171;
    v153 = stack[-3];
    if (is_number(v153)) goto v172;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    stack[-5] = v153;
    goto v173;

v173:
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    if (v153 == nil) goto v174;
    v154 = elt(env, 15); /* times */
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v175;

v175:
    stack[-1] = v153;
    goto v176;

v176:
    v153 = stack[-4];
    if (!(symbolp(v153))) goto v177;
    v154 = stack[-4];
    v153 = elt(env, 16); /* used!* */
    v153 = Lflagp(nil, v154, v153);
    env = stack[-7];
    if (!(v153 == nil)) goto v177;
    v153 = stack[-4];
    v154 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = elt(env, 16); /* used!* */
    v153 = Lflag(nil, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v177;

v177:
    v154 = stack[-4];
    v153 = elt(env, 17); /* (minus 1) */
    if (!(equal(v154, v153))) goto v178;
    v154 = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v178;
    v155 = elt(env, 18); /* difference */
    v154 = stack[-1];
    v153 = elt(env, 19); /* (quotient 1 2) */
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = qcar(v153);
    if (!(v153 == nil)) goto v178;
    v153 = elt(env, 4); /* i */
    fn = elt(env, 20); /* simp */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-4] = v153;
    v153 = stack[-6];
    if (v153 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v153 = stack[-4];
    v153 = qcar(v153);
    fn = elt(env, 23); /* negf */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    v153 = stack[-4];
    v153 = qcdr(v153);
    popv(8);
    return cons(v154, v153);

v178:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v154 = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v179;
    v155 = elt(env, 2); /* quotient */
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v180;

v180:
    v153 = list3(stack[0], stack[-2], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-4] = v153;
    stack[0] = stack[-4];
    v153 = stack[-6];
    if (v153 == nil) goto v181;
    v153 = stack[-5];
    v153 = negate(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v182;

v182:
    {
        Lisp_Object v183 = stack[0];
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v183, v153);
    }

v181:
    v153 = stack[-5];
    goto v182;

v179:
    v153 = stack[-1];
    goto v180;

v174:
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    goto v175;

v172:
    v154 = stack[-3];
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = Lgcd(nil, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    v154 = stack[-3];
    v153 = stack[-5];
    v153 = quot2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-3] = v153;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v154 = qcar(v153);
    v153 = stack[-5];
    v153 = quot2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    goto v173;

v171:
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = elt(env, 2); /* quotient */
    if (!(v154 == v153)) goto v184;
    v154 = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    if (!(v154 == v153)) goto v184;
    v153 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v153 == nil) goto v184;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    stack[-3] = v153;
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    stack[-1] = v153;
    goto v163;

v184:
    v153 = (Lisp_Object)17; /* 1 */
    stack[-5] = v153;
    goto v176;

v166:
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    stack[-1] = v153;
    goto v185;

v185:
    v153 = qvalue(elt(env, 6)); /* !*mcd */
    if (v153 == nil) goto v186;
    v155 = stack[-4];
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = CC_simpx1(env, 3, v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 25); /* invsq */
        return (*qfn1(fn))(qenv(fn), v153);
    }

v186:
    v153 = stack[-6];
    v153 = (v153 == nil ? lisp_true : nil);
    stack[-6] = v153;
    goto v163;

v165:
    v153 = (Lisp_Object)17; /* 1 */
    stack[-5] = v153;
    goto v176;

v164:
    v153 = stack[-1];
    v153 = Lminusp(nil, v153);
    env = stack[-7];
    if (v153 == nil) goto v187;
    v153 = stack[-1];
    v153 = negate(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v153;
    goto v185;

v187:
    v153 = stack[-1];
    v153 = integerp(v153);
    if (v153 == nil) goto v188;
    v153 = stack[-3];
    v153 = integerp(v153);
    if (v153 == nil) goto v189;
    v153 = stack[-6];
    if (v153 == nil) goto v190;
    v153 = stack[-1];
    v153 = negate(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v153;
    goto v190;

v190:
    v153 = stack[-1];
    stack[-5] = v153;
    v153 = qvalue(elt(env, 6)); /* !*mcd */
    if (v153 == nil) goto v191;
    v153 = stack[-4];
    v153 = integerp(v153);
    if (!(v153 == nil)) goto v192;
    v153 = qvalue(elt(env, 7)); /* !*notseparate */
    if (!(v153 == nil)) goto v191;

v192:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = quot2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v153;
    v153 = times2(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = difference2(stack[-2], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    v154 = stack[-5];
    v153 = (Lisp_Object)1; /* 0 */
    v153 = (Lisp_Object)lessp2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    v153 = v153 ? lisp_true : nil;
    env = stack[-7];
    if (v153 == nil) goto v193;
    v153 = stack[-1];
    v153 = sub1(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v153;
    v154 = stack[-5];
    v153 = stack[-3];
    v153 = plus2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    goto v193;

v193:
    v154 = stack[-4];
    v153 = stack[-1];
    v153 = list2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v153;
    v154 = stack[-5];
    v153 = (Lisp_Object)1; /* 0 */
    if (v154 == v153) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v154 = stack[-3];
    v153 = (Lisp_Object)33; /* 2 */
    if (!(v154 == v153)) goto v194;
    v153 = qvalue(elt(env, 8)); /* !*keepsqrts */
    if (v153 == nil) goto v194;
    stack[-1] = stack[0];
    v154 = elt(env, 9); /* sqrt */
    v153 = elt(env, 10); /* simpfn */
    stack[0] = get(v154, v153);
    env = stack[-7];
    v153 = stack[-4];
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = Lapply1(nil, stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v153 = (*qfn2(fn))(qenv(fn), stack[-1], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v153;
    v154 = stack[-5];
    v153 = (Lisp_Object)1; /* 0 */
    v153 = (Lisp_Object)lessp2(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    v153 = v153 ? lisp_true : nil;
    env = stack[-7];
    if (v153 == nil) goto v195;
    v153 = stack[0];
    fn = elt(env, 25); /* invsq */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v153;
    v153 = stack[-5];
    v153 = negate(v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-5] = v153;
    goto v195;

v195:
    v154 = stack[0];
    v153 = stack[-5];
    {
        popv(8);
        fn = elt(env, 26); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v194:
    v153 = stack[-4];
    fn = elt(env, 27); /* simp!* */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = stack[-3];
    fn = elt(env, 28); /* simprad */
    v154 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = stack[-5];
    fn = elt(env, 26); /* exptsq */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    {
        Lisp_Object v196 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v196, v153);
    }

v191:
    v153 = (Lisp_Object)1; /* 0 */
    stack[-1] = v153;
    goto v193;

v189:
    v153 = stack[-1];
    stack[-5] = v153;
    v153 = (Lisp_Object)17; /* 1 */
    stack[-1] = v153;
    goto v176;

v188:
    v153 = (Lisp_Object)17; /* 1 */
    stack[-5] = v153;
    goto v176;

v162:
    v154 = qvalue(elt(env, 5)); /* frlis!* */
    v153 = stack[-1];
    fn = elt(env, 29); /* smemqlp */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    if (!(v153 == nil)) goto v197;
    v154 = qvalue(elt(env, 5)); /* frlis!* */
    v153 = stack[-3];
    fn = elt(env, 29); /* smemqlp */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    if (v153 == nil) goto v163;
    else goto v197;

v197:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v154 = stack[-3];
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v198;
    v155 = elt(env, 2); /* quotient */
    v154 = stack[-1];
    v153 = stack[-3];
    v153 = list3(v155, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v199;

v199:
    v154 = list3(stack[0], stack[-2], v153);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v153 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v198:
    v153 = stack[-1];
    goto v199;
/* error exit handlers */
v158:
    popv(8);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repartf");
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
    stack[0] = v0;
/* end of prologue */
    v128 = elt(env, 1); /* i */
    v127 = qvalue(elt(env, 2)); /* kord!* */
    v127 = cons(v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v127; /* kord!* */
    v127 = stack[0];
    fn = elt(env, 5); /* reorder */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    stack[-2] = v127;
    v127 = stack[-2];
    if (!consp(v127)) goto v219;
    v127 = stack[-2];
    v127 = qcar(v127);
    if (!consp(v127)) goto v219;
    v127 = stack[-2];
    v127 = qcar(v127);
    v127 = qcar(v127);
    v128 = qcar(v127);
    v127 = elt(env, 1); /* i */
    if (v128 == v127) goto v220;
    v127 = stack[-2];
    v127 = qcar(v127);
    v128 = qcar(v127);
    v127 = (Lisp_Object)17; /* 1 */
    v127 = cons(v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    stack[0] = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v127 = stack[-2];
    v127 = qcar(v127);
    v127 = qcdr(v127);
    v127 = CC_repartf(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v127 = stack[-2];
    v127 = qcdr(v127);
    v127 = CC_repartf(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v127 = (*qfn2(fn))(qenv(fn), stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    goto v221;

v221:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v127); }

v220:
    v127 = stack[-2];
    v127 = qcdr(v127);
    v127 = CC_repartf(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    goto v221;

v219:
    v127 = stack[-2];
    if (!consp(v127)) goto v222;
    v127 = stack[-2];
    v128 = qcar(v127);
    v127 = elt(env, 3); /* cmpxfn */
    v127 = get(v128, v127);
    env = stack[-4];
    if (v127 == nil) goto v223;
    v127 = stack[-2];
    stack[-1] = qcar(v127);
    v127 = stack[-2];
    v127 = qcdr(v127);
    stack[0] = qcar(v127);
    v127 = stack[-2];
    v128 = qcar(v127);
    v127 = elt(env, 4); /* i2d */
    v128 = get(v128, v127);
    env = stack[-4];
    v127 = (Lisp_Object)1; /* 0 */
    v127 = Lapply1(nil, v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v127 = qcdr(v127);
    v127 = qcar(v127);
    v127 = list2star(stack[-1], stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    fn = elt(env, 8); /* int!-equiv!-chk */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    goto v221;

v223:
    v127 = stack[-2];
    goto v221;

v222:
    v127 = stack[-2];
    goto v221;
/* error exit handlers */
v218:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v217:
    popv(5);
    return nil;
}



/* Code for pasf_negateat */

static Lisp_Object CC_pasf_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_negateat");
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
    v243 = stack[0];
    v242 = elt(env, 1); /* true */
    if (v243 == v242) goto v245;
    v243 = stack[0];
    v242 = elt(env, 2); /* false */
    if (v243 == v242) goto v245;
    v243 = stack[0];
    v242 = elt(env, 1); /* true */
    if (v243 == v242) goto v246;
    v243 = stack[0];
    v242 = elt(env, 2); /* false */
    if (v243 == v242) goto v246;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = Lconsp(nil, v242);
    env = stack[-1];
    if (v242 == nil) goto v247;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v243 = v242;
    goto v248;

v248:
    v242 = elt(env, 3); /* (cong ncong) */
    v242 = Lmemq(nil, v243, v242);
    if (v242 == nil) goto v249;
    v243 = stack[0];
    v242 = elt(env, 1); /* true */
    if (v243 == v242) goto v250;
    v243 = stack[0];
    v242 = elt(env, 2); /* false */
    if (v243 == v242) goto v250;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = Lconsp(nil, v242);
    env = stack[-1];
    if (v242 == nil) goto v128;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    goto v251;

v251:
    fn = elt(env, 4); /* pasf_lnegrel */
    v243 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-1];
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcdr(v242);
    fn = elt(env, 5); /* pasf_mkop */
    v244 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v242 = stack[0];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    v242 = qcar(v242);
    popv(2);
    return list3(v244, v243, v242);

v128:
    v242 = stack[0];
    v242 = qcar(v242);
    goto v251;

v250:
    v242 = stack[0];
    goto v251;

v249:
    v243 = stack[0];
    v242 = elt(env, 1); /* true */
    if (v243 == v242) goto v122;
    v243 = stack[0];
    v242 = elt(env, 2); /* false */
    if (v243 == v242) goto v122;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = Lconsp(nil, v242);
    env = stack[-1];
    if (v242 == nil) goto v253;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    goto v254;

v254:
    fn = elt(env, 4); /* pasf_lnegrel */
    v244 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v242 = stack[0];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    v242 = qcar(v242);
    popv(2);
    return list3(v244, v243, v242);

v253:
    v242 = stack[0];
    v242 = qcar(v242);
    goto v254;

v122:
    v242 = stack[0];
    goto v254;

v247:
    v242 = stack[0];
    v242 = qcar(v242);
    v243 = v242;
    goto v248;

v246:
    v242 = stack[0];
    v243 = v242;
    goto v248;

v245:
    v243 = stack[0];
    v242 = elt(env, 2); /* false */
    if (v243 == v242) goto v255;
    v242 = elt(env, 2); /* false */
    { popv(2); return onevalue(v242); }

v255:
    v242 = elt(env, 1); /* true */
    { popv(2); return onevalue(v242); }
/* error exit handlers */
v252:
    popv(2);
    return nil;
}



/* Code for ratpoly_sub */

static Lisp_Object MS_CDECL CC_ratpoly_sub(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v152, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratpoly_sub");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_sub");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v241 = v2;
    v152 = v1;
    v151 = v0;
/* end of prologue */
    stack[0] = v151;
    v241 = cons(v152, v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    env = stack[-1];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    env = stack[-1];
    {
        Lisp_Object v222 = stack[0];
        popv(2);
        fn = elt(env, 1); /* subsq */
        return (*qfn2(fn))(qenv(fn), v222, v241);
    }
/* error exit handlers */
v255:
    popv(2);
    return nil;
}



/* Code for vdp_getprop */

static Lisp_Object CC_vdp_getprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_getprop");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v208 = v1;
    v255 = v0;
/* end of prologue */
    stack[0] = v208;
    v208 = v255;
    fn = elt(env, 2); /* vdp_plist */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-1];
    v208 = Latsoc(nil, stack[0], v208);
    v255 = v208;
    v208 = v255;
    if (v208 == nil) goto v241;
    v208 = v255;
    v208 = qcdr(v208);
    { popv(2); return onevalue(v208); }

v241:
    v208 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v208); }
/* error exit handlers */
v245:
    popv(2);
    return nil;
}



/* Code for impartsq */

static Lisp_Object CC_impartsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v231, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartsq");
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
    stack[0] = v0;
/* end of prologue */
    v206 = stack[0];
    v206 = qcar(v206);
    fn = elt(env, 1); /* splitcomplex */
    stack[-1] = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v206 = stack[0];
    v206 = qcdr(v206);
    fn = elt(env, 1); /* splitcomplex */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v207 = stack[-1];
    v231 = v207;
    v267 = qcar(v231);
    v231 = qcdr(v207);
    v207 = v206;
    v207 = qcar(v207);
    v206 = qcdr(v206);
    stack[0] = v267;
    stack[-3] = v207;
    stack[-2] = v206;
    v207 = v231;
    v206 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v207 = stack[0];
    v206 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    stack[0] = v206;
    v206 = stack[0];
    v206 = qcar(v206);
    fn = elt(env, 3); /* negf */
    v207 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v206 = stack[0];
    v206 = qcdr(v206);
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v207 = stack[-3];
    v206 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    v207 = stack[-2];
    v206 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v206 = (*qfn2(fn))(qenv(fn), stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    fn = elt(env, 5); /* invsq */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    {
        Lisp_Object v136 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v136, v206);
    }
/* error exit handlers */
v233:
    popv(5);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v237;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v237 = qvalue(elt(env, 2)); /* maxvar */
    v238 = stack[0];
    v238 = plus2(v237, v238);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-2];
    v237 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v238/(16/CELL)));
    v238 = (Lisp_Object)81; /* 5 */
    v238 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v238/(16/CELL)));
    if (v238 == nil) goto v271;
    v238 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v238); }

v271:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v237 = qvalue(elt(env, 2)); /* maxvar */
    v238 = stack[0];
    v238 = plus2(v237, v238);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v237 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v238/(16/CELL)));
    v238 = (Lisp_Object)49; /* 3 */
    v238 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v238/(16/CELL)));
    v238 = (is_number(v238) ? lisp_true : nil);
    { popv(3); return onevalue(v238); }
/* error exit handlers */
v270:
    popv(3);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpwedge");
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
    v69 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitwedge */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v8:
    popv(1);
    return nil;
}



/* Code for ratmean */

static Lisp_Object CC_ratmean(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v221, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratmean");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v200 = v1;
    v221 = v0;
/* end of prologue */
    v219 = v221;
    v221 = v200;
    v200 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v219, v221, v200);
    }
}



/* Code for endofstmtp */

static Lisp_Object MS_CDECL CC_endofstmtp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v221;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v221 = qvalue(elt(env, 1)); /* cursym!* */
    v200 = elt(env, 2); /* (!*semicol!* !*rsqbkt!* end) */
    v200 = Lmember(nil, v221, v200);
    if (v200 == nil) goto v9;
    v200 = qvalue(elt(env, 3)); /* t */
    return onevalue(v200);

v9:
    v200 = nil;
    return onevalue(v200);
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lndepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v274:
    v240 = stack[-1];
    if (v240 == nil) goto v69;
    v240 = stack[-1];
    v273 = qcar(v240);
    v240 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v240 = (*qfn2(fn))(qenv(fn), v273, v240);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (!(v240 == nil)) { popv(3); return onevalue(v240); }
    v240 = stack[-1];
    v273 = qcdr(v240);
    v240 = stack[0];
    stack[-1] = v273;
    stack[0] = v240;
    goto v274;

v69:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v240); }
/* error exit handlers */
v271:
    popv(3);
    return nil;
}



/* Code for mk_binding */

static Lisp_Object CC_mk_binding(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v276;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_binding");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v259 = stack[-1];
    v276 = qcar(v259);
    v259 = stack[0];
    fn = elt(env, 2); /* can_be_proved */
    v259 = (*qfn2(fn))(qenv(fn), v276, v259);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-2];
    if (v259 == nil) goto v69;
    v259 = stack[-1];
    v276 = qcdr(v259);
    v259 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* edge_bind */
        return (*qfn2(fn))(qenv(fn), v276, v259);
    }

v69:
    v259 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v259); }
/* error exit handlers */
v240:
    popv(3);
    return nil;
}



/* Code for compactf1 */

static Lisp_Object MS_CDECL CC_compactf1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v277, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v266, v248, v268, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "compactf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf1");
#endif
    if (stack >= stacklimit)
    {
        push4(v277,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v277);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v277;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v266 = stack[-1];
    v215 = stack[0];
    fn = elt(env, 1); /* intersection */
    v215 = (*qfn2(fn))(qenv(fn), v266, v215);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-4];
    v266 = v215;
    if (v266 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v279 = stack[-3];
    v268 = stack[-2];
    v248 = stack[-1];
    v266 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* compactf11 */
        return (*qfnn(fn))(qenv(fn), 5, v279, v268, v248, v266, v215);
    }
/* error exit handlers */
v264:
    popv(5);
    return nil;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v240, v273;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for baglistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v273 = v0;
/* end of prologue */
    v239 = v273;
    if (!consp(v239)) goto v9;
    v239 = v273;
    v240 = qcar(v239);
    v239 = elt(env, 2); /* list */
    v239 = (v240 == v239 ? lisp_true : nil);
    if (!(v239 == nil)) return onevalue(v239);
    v239 = v273;
    v239 = qcar(v239);
    v240 = elt(env, 3); /* bag */
        return Lflagp(nil, v239, v240);

v9:
    v239 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v239);
}



/* Code for proper!-simpsqrt */

static Lisp_Object CC_properKsimpsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for proper-simpsqrt");
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
    v150 = v0;
/* end of prologue */
    v273 = v150;
    v273 = qcdr(v273);
    if (v273 == nil) goto v69;
    v150 = elt(env, 1); /* "Wrong number of arguments to" */
    v273 = elt(env, 0); /* proper!-simpsqrt */
    v273 = list2(v150, v273);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[0];
    v150 = v273;
    v273 = v150;
    qvalue(elt(env, 2)) = v273; /* errmsg!* */
    v273 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v273 == nil)) goto v245;
    v273 = v150;
    fn = elt(env, 4); /* lprie */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[0];
    goto v245;

v245:
    v273 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[0];
    v273 = nil;
    goto v9;

v9:
    {
        popv(1);
        fn = elt(env, 5); /* simpsqrti */
        return (*qfn1(fn))(qenv(fn), v273);
    }

v69:
    v273 = v150;
    v273 = qcar(v273);
    goto v9;
/* error exit handlers */
v149:
    popv(1);
    return nil;
}



/* Code for ofsf_irl2atl */

static Lisp_Object MS_CDECL CC_ofsf_irl2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v247, v282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_irl2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_irl2atl");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    v223 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v223;
    goto v163;

v163:
    v223 = stack[-5];
    if (v223 == nil) goto v200;
    v223 = stack[-5];
    v223 = qcar(v223);
    v282 = stack[-4];
    v247 = v223;
    v223 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v223 = (*qfnn(fn))(qenv(fn), 3, v282, v247, v223);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    stack[-2] = v223;
    v223 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    stack[-1] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-5] = v223;
    v223 = stack[-1];
    if (!consp(v223)) goto v163;
    else goto v185;

v185:
    v223 = stack[-5];
    if (v223 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v223 = stack[-5];
    v223 = qcar(v223);
    v282 = stack[-4];
    v247 = v223;
    v223 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v223 = (*qfnn(fn))(qenv(fn), 3, v282, v247, v223);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    v223 = Lrplacd(nil, stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    v223 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-6];
    stack[-1] = v223;
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-5] = v223;
    goto v185;

v200:
    v223 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v223); }
/* error exit handlers */
v139:
    popv(7);
    return nil;
}



/* Code for impartf */

static Lisp_Object CC_impartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartf");
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
    stack[0] = v0;
/* end of prologue */
    v130 = elt(env, 1); /* i */
    v132 = qvalue(elt(env, 2)); /* kord!* */
    v132 = cons(v130, v132);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v132; /* kord!* */
    v132 = stack[0];
    fn = elt(env, 6); /* reorder */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    stack[-2] = v132;
    v132 = stack[-2];
    if (!consp(v132)) goto v219;
    v132 = stack[-2];
    v132 = qcar(v132);
    if (!consp(v132)) goto v219;
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v130 = qcar(v132);
    v132 = elt(env, 1); /* i */
    if (v130 == v132) goto v267;
    v132 = stack[-2];
    v132 = qcar(v132);
    v130 = qcar(v132);
    v132 = (Lisp_Object)17; /* 1 */
    v132 = cons(v130, v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    stack[0] = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    v132 = CC_impartf(env, v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    v132 = stack[-2];
    v132 = qcdr(v132);
    v132 = CC_impartf(env, v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    goto v221;

v221:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v132); }

v267:
    v132 = stack[-2];
    v132 = qcar(v132);
    stack[0] = qcdr(v132);
    v132 = stack[-2];
    v132 = qcdr(v132);
    v132 = CC_impartf(env, v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    goto v221;

v219:
    v132 = stack[-2];
    if (!consp(v132)) goto v222;
    v132 = stack[-2];
    v130 = qcar(v132);
    v132 = elt(env, 4); /* cmpxfn */
    v132 = get(v130, v132);
    env = stack[-4];
    if (v132 == nil) goto v223;
    v132 = stack[-2];
    stack[-1] = qcar(v132);
    v132 = stack[-2];
    v132 = qcdr(v132);
    stack[0] = qcdr(v132);
    v132 = stack[-2];
    v130 = qcar(v132);
    v132 = elt(env, 5); /* i2d */
    v130 = get(v130, v132);
    env = stack[-4];
    v132 = (Lisp_Object)1; /* 0 */
    v132 = Lapply1(nil, v130, v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = list2star(stack[-1], stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    fn = elt(env, 9); /* int!-equiv!-chk */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    goto v221;

v223:
    v132 = qvalue(elt(env, 3)); /* nil */
    goto v221;

v222:
    v132 = qvalue(elt(env, 3)); /* nil */
    goto v221;
/* error exit handlers */
v286:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v285:
    popv(5);
    return nil;
}



/* Code for pasf_lnegrel */

static Lisp_Object CC_pasf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v135 = v0;
/* end of prologue */
    v138 = v135;
    v137 = elt(env, 1); /* equal */
    if (v138 == v137) goto v9;
    v138 = v135;
    v137 = elt(env, 2); /* neq */
    if (v138 == v137) goto v200;
    v138 = v135;
    v137 = elt(env, 3); /* leq */
    if (v138 == v137) goto v255;
    v138 = v135;
    v137 = elt(env, 5); /* lessp */
    if (v138 == v137) goto v150;
    v138 = v135;
    v137 = elt(env, 6); /* geq */
    if (v138 == v137) goto v234;
    v138 = v135;
    v137 = elt(env, 4); /* greaterp */
    if (v138 == v137) goto v238;
    v138 = v135;
    v137 = elt(env, 7); /* cong */
    if (v138 == v137) goto v290;
    v138 = v135;
    v137 = elt(env, 8); /* ncong */
    if (v138 == v137) goto v282;
    v137 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v137 == nil)) goto v291;
    v137 = elt(env, 10); /* "pasf_lnegrel: unknown operator" */
    v138 = v135;
    v137 = list2(v137, v138);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[0];
    goto v291;

v291:
    v137 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v292;
    v137 = nil;
    { popv(1); return onevalue(v137); }

v282:
    v137 = elt(env, 7); /* cong */
    { popv(1); return onevalue(v137); }

v290:
    v137 = elt(env, 8); /* ncong */
    { popv(1); return onevalue(v137); }

v238:
    v137 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v137); }

v234:
    v137 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v137); }

v150:
    v137 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v137); }

v255:
    v137 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v137); }

v200:
    v137 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v137); }

v9:
    v137 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v137); }
/* error exit handlers */
v292:
    popv(1);
    return nil;
}



/* Code for transposerd */

static Lisp_Object MS_CDECL CC_transposerd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transposerd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 2); /* mathml */
    v269 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-1];
    v257 = elt(env, 1); /* tp */
    v269 = list2(v257, v269);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-1];
    fn = elt(env, 3); /* aeval */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-1];
    stack[0] = v269;
    fn = elt(env, 4); /* lex */
    v269 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v241:
    popv(2);
    return nil;
}



/* Code for reprod */

static Lisp_Object CC_reprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v69:
    v240 = stack[-1];
    if (v240 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v240 = stack[-1];
    v273 = qcar(v240);
    v240 = (Lisp_Object)17; /* 1 */
    v240 = cons(v273, v240);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    v273 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    v240 = stack[0];
    fn = elt(env, 2); /* multf */
    v240 = (*qfn2(fn))(qenv(fn), v273, v240);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    stack[0] = v240;
    v240 = stack[-1];
    v240 = qcdr(v240);
    stack[-1] = v240;
    goto v69;
/* error exit handlers */
v271:
    popv(3);
    return nil;
}



/* Code for ps!:term!-rthpow */

static Lisp_Object MS_CDECL CC_psTtermKrthpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:term-rthpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:term-rthpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v143 = stack[-3];
    v144 = stack[-2];
    fn = elt(env, 2); /* ps!:get!-term */
    v144 = (*qfn2(fn))(qenv(fn), v143, v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[-4] = v144;
    v144 = stack[-4];
    if (!(v144 == nil)) goto v145;
    v144 = stack[-3];
    fn = elt(env, 3); /* ps!:last!-term */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[0] = v144;
    goto v150;

v150:
    v143 = stack[-2];
    v144 = stack[0];
    v144 = difference2(v143, v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v144 = Lminusp(nil, v144);
    env = stack[-5];
    if (!(v144 == nil)) goto v145;
    v143 = stack[-3];
    v144 = stack[0];
    fn = elt(env, 4); /* ps!:set!-rthpow */
    v144 = (*qfn2(fn))(qenv(fn), v143, v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[-4] = v144;
    v144 = stack[0];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[0] = v144;
    goto v150;

v145:
    v143 = stack[-4];
    v144 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* ps!:evaluate */
        return (*qfn2(fn))(qenv(fn), v143, v144);
    }
/* error exit handlers */
v213:
    popv(6);
    return nil;
}



/* Code for ldf!-deg */

static Lisp_Object CC_ldfKdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    v210 = v0;
/* end of prologue */
    stack[-4] = v210;
    v210 = stack[-4];
    if (v210 == nil) goto v203;
    v210 = stack[-4];
    v210 = qcar(v210);
    v144 = qcdr(v210);
    v210 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v210 = (*qfn2(fn))(qenv(fn), v144, v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-5];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-5];
    stack[-1] = v210;
    stack[-2] = v210;
    goto v163;

v163:
    v210 = stack[-4];
    v210 = qcdr(v210);
    stack[-4] = v210;
    v210 = stack[-4];
    if (v210 == nil) goto v150;
    stack[0] = stack[-1];
    v210 = stack[-4];
    v210 = qcar(v210);
    v144 = qcdr(v210);
    v210 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v210 = (*qfn2(fn))(qenv(fn), v144, v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-5];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-5];
    v210 = Lrplacd(nil, stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-5];
    v210 = stack[-1];
    v210 = qcdr(v210);
    stack[-1] = v210;
    goto v163;

v150:
    v210 = stack[-2];
    goto v216;

v216:
    {
        popv(6);
        fn = elt(env, 3); /* maxl */
        return (*qfn1(fn))(qenv(fn), v210);
    }

v203:
    v210 = qvalue(elt(env, 1)); /* nil */
    goto v216;
/* error exit handlers */
v212:
    popv(6);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2pf");
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

v274:
    v214 = stack[0];
    if (v214 == nil) goto v69;
    v214 = stack[0];
    v214 = qcar(v214);
    v214 = qcdr(v214);
    fn = elt(env, 1); /* resimp */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-1];
    v215 = v214;
    v215 = qcar(v215);
    if (v215 == nil) goto v273;
    v215 = stack[0];
    v215 = qcar(v215);
    v266 = qcar(v215);
    v215 = v214;
    v214 = stack[0];
    v214 = qcdr(v214);
    popv(2);
    return acons(v266, v215, v214);

v273:
    v214 = stack[0];
    v214 = qcdr(v214);
    stack[0] = v214;
    goto v274;

v69:
    v214 = nil;
    { popv(2); return onevalue(v214); }
/* error exit handlers */
v268:
    popv(2);
    return nil;
}



/* Code for preproc1 */

static Lisp_Object CC_preproc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v358, v186, v359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preproc1");
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
    stack[-1] = v0;
/* end of prologue */

v9:
    v358 = stack[-1];
    if (!consp(v358)) goto v294;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 1); /* !:rd!: */
    if (v186 == v358) goto v156;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 2); /* !:dn!: */
    if (v186 == v358) goto v207;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 3); /* !*sq */
    if (v186 == v358) goto v360;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 5); /* procedure */
    if (v186 == v358) goto v133;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 11); /* declare */
    if (v186 == v358) goto v71;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 14); /* setq */
    if (!(v186 == v358)) goto v361;
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    v358 = Lconsp(nil, v358);
    env = stack[-5];
    if (v358 == nil) goto v361;
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    v186 = qcar(v358);
    v358 = elt(env, 15); /* (cond progn) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v361;
    v358 = stack[-1];
    {
        popv(6);
        fn = elt(env, 21); /* migrate!-setqs */
        return (*qfn1(fn))(qenv(fn), v358);
    }

v361:
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 16); /* (plus times difference quotient minus) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v362;
    v358 = stack[-1];
    fn = elt(env, 22); /* simp!* */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v359 = v358;
    v358 = qcar(v358);
    v358 = Lconsp(nil, v358);
    env = stack[-5];
    if (v358 == nil) goto v364;
    v358 = v359;
    v358 = qcar(v358);
    v186 = qcar(v358);
    v358 = elt(env, 17); /* (!:cr!: !:crn!: !:gi!:) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v364;
    v358 = v359;
    v358 = qcdr(v358);
    v358 = Lonep(nil, v358);
    env = stack[-5];
    if (v358 == nil) goto v365;
    v358 = v359;
    v358 = qcar(v358);
    popv(6);
    return ncons(v358);

v365:
    stack[-1] = elt(env, 18); /* quotient */
    v358 = v359;
    stack[0] = qcar(v358);
    v358 = v359;
    v186 = qcdr(v358);
    v358 = (Lisp_Object)17; /* 1 */
    v358 = cons(v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v186 = v358;
    v358 = v186;
    v358 = qcar(v358);
    if (v358 == nil) goto v366;
    v358 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v358 = (*qfn2(fn))(qenv(fn), v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v33;

v33:
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = qcar(v358);
    v358 = list3(stack[-1], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    popv(6);
    return ncons(v358);

v366:
    v358 = (Lisp_Object)1; /* 0 */
    goto v33;

v364:
    v358 = stack[-1];
    stack[-3] = v358;
    goto v367;

v367:
    v358 = stack[-3];
    if (v358 == nil) goto v368;
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-2] = v358;
    v358 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    v358 = stack[-1];
    if (!consp(v358)) goto v367;
    else goto v369;

v369:
    v358 = stack[-3];
    if (v358 == nil) goto v177;
    stack[0] = stack[-1];
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = Lrplacd(nil, stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v369;

v177:
    v358 = stack[-2];
    goto v370;

v370:
    popv(6);
    return ncons(v358);

v368:
    v358 = qvalue(elt(env, 9)); /* nil */
    goto v370;

v362:
    v358 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v358 == nil) goto v371;
    v358 = stack[-1];
    v186 = qcar(v358);
    v358 = elt(env, 19); /* (!~for for) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v371;
    v359 = qvalue(elt(env, 9)); /* nil */
    v358 = stack[-1];
    v358 = qcdr(v358);
    v186 = qcar(v358);
    v358 = elt(env, 20); /* (integer) */
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, v359, v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v371;

v371:
    v358 = stack[-1];
    stack[-3] = v358;
    goto v372;

v372:
    v358 = stack[-3];
    if (v358 == nil) goto v179;
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-2] = v358;
    v358 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    v358 = stack[-1];
    if (!consp(v358)) goto v372;
    else goto v12;

v12:
    v358 = stack[-3];
    if (v358 == nil) goto v15;
    stack[0] = stack[-1];
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = Lrplacd(nil, stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v12;

v15:
    v358 = stack[-2];
    goto v180;

v180:
    popv(6);
    return ncons(v358);

v179:
    v358 = qvalue(elt(env, 9)); /* nil */
    goto v180;

v71:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = qcar(v358);
    stack[-1] = v358;
    v358 = stack[-1];
    fn = elt(env, 26); /* preprocdec */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-1];
    stack[-4] = v358;
    goto v373;

v373:
    v358 = stack[-4];
    if (v358 == nil) goto v374;
    v358 = stack[-4];
    v358 = qcar(v358);
    stack[-3] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v165;

v165:
    v358 = stack[-2];
    if (v358 == nil) goto v375;
    v358 = stack[-2];
    v358 = qcar(v358);
    v359 = v358;
    v358 = stack[-3];
    v186 = qcar(v358);
    v358 = elt(env, 12); /* (subroutine function) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v376;
    v186 = elt(env, 13); /* !*type!* */
    v358 = stack[-3];
    v358 = qcar(v358);
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, v359, v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v61;

v61:
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v165;

v376:
    stack[-1] = qvalue(elt(env, 9)); /* nil */
    v358 = v359;
    if (!consp(v358)) goto v377;
    v358 = v359;
    v358 = qcar(v358);
    stack[0] = v358;
    goto v378;

v378:
    v358 = v359;
    if (!consp(v358)) goto v379;
    v358 = stack[-3];
    v358 = qcar(v358);
    v186 = v359;
    v186 = qcdr(v186);
    v358 = cons(v358, v186);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v380;

v380:
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v61;

v379:
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v380;

v377:
    v358 = v359;
    stack[0] = v358;
    goto v378;

v375:
    v358 = stack[-4];
    v358 = qcdr(v358);
    stack[-4] = v358;
    goto v373;

v374:
    v358 = qvalue(elt(env, 9)); /* nil */
    { popv(6); return onevalue(v358); }

v133:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcar(v358);
    v186 = elt(env, 6); /* !*params!* */
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, v359, v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v358 == nil) goto v381;
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v186 = qcar(v358);
    v358 = elt(env, 8); /* (real integer) */
    v358 = Lmemq(nil, v186, v358);
    if (v358 == nil) goto v382;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-2] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[0] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    stack[-3] = v358;
    goto v383;

v383:
    v358 = stack[-3];
    if (v358 == nil) goto v384;
    v358 = stack[-3];
    v358 = qcar(v358);
    v186 = v358;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-2] = qcar(v358);
    stack[0] = v186;
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v383;

v384:
    v359 = elt(env, 5); /* procedure */
    v358 = stack[-1];
    v358 = qcdr(v358);
    v186 = qcar(v358);
    v358 = nil;
    stack[-4] = list3(v359, v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v385;

v385:
    v358 = stack[-3];
    if (v358 == nil) goto v386;
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-2] = v358;
    v358 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    v358 = stack[-1];
    if (!consp(v358)) goto v385;
    else goto v387;

v387:
    v358 = stack[-3];
    if (v358 == nil) goto v187;
    stack[0] = stack[-1];
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = Lrplacd(nil, stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v387;

v187:
    v358 = stack[-2];
    goto v388;

v388:
    v358 = Lnconc(nil, stack[-4], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    popv(6);
    return ncons(v358);

v386:
    v358 = qvalue(elt(env, 9)); /* nil */
    goto v388;

v382:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = qcar(v358);
    stack[-3] = v358;
    goto v389;

v389:
    v358 = stack[-3];
    if (v358 == nil) goto v390;
    v358 = stack[-3];
    v358 = qcar(v358);
    v186 = v358;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-2] = qcar(v358);
    stack[0] = v186;
    v358 = qvalue(elt(env, 10)); /* deftype!* */
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v358 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v389;

v390:
    v358 = stack[-1];
    stack[-3] = v358;
    goto v391;

v391:
    v358 = stack[-3];
    if (v358 == nil) goto v89;
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-2] = v358;
    v358 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    v358 = stack[-1];
    if (!consp(v358)) goto v391;
    else goto v392;

v392:
    v358 = stack[-3];
    if (v358 == nil) goto v393;
    stack[0] = stack[-1];
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = Lrplacd(nil, stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v392;

v393:
    v358 = stack[-2];
    goto v394;

v394:
    popv(6);
    return ncons(v358);

v89:
    v358 = qvalue(elt(env, 9)); /* nil */
    goto v394;

v381:
    v358 = stack[-1];
    stack[-3] = v358;
    goto v395;

v395:
    v358 = stack[-3];
    if (v358 == nil) goto v74;
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-2] = v358;
    v358 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    v358 = stack[-1];
    if (!consp(v358)) goto v395;
    else goto v396;

v396:
    v358 = stack[-3];
    if (v358 == nil) goto v397;
    stack[0] = stack[-1];
    v358 = stack[-3];
    v358 = qcar(v358);
    v358 = CC_preproc1(env, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = Lrplacd(nil, stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    v358 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v396;

v397:
    v358 = stack[-2];
    goto v398;

v398:
    popv(6);
    return ncons(v358);

v74:
    v358 = qvalue(elt(env, 9)); /* nil */
    goto v398;

v360:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcar(v358);
    v358 = qcar(v358);
    if (v358 == nil) goto v399;
    v358 = stack[-1];
    v358 = qcdr(v358);
    v186 = qcar(v358);
    v358 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v358 = (*qfn2(fn))(qenv(fn), v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v400;

v400:
    stack[-1] = v358;
    goto v9;

v399:
    v358 = (Lisp_Object)1; /* 0 */
    goto v400;

v207:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v186 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    fn = elt(env, 27); /* decimal2internal */
    v358 = (*qfn2(fn))(qenv(fn), v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    stack[-1] = v358;
    goto v9;

v156:
    v358 = stack[-1];
    v358 = qcdr(v358);
    if (!consp(v358)) goto v222;
    v358 = stack[-1];
    goto v255;

v255:
    popv(6);
    return ncons(v358);

v222:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = Lfloatp(nil, v358);
    env = stack[-5];
    if (v358 == nil) goto v215;
    v358 = stack[-1];
    v358 = qcdr(v358);
    fn = elt(env, 28); /* fl2bf */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    goto v255;

v215:
    v358 = stack[-1];
    v358 = qcdr(v358);
    if (!consp(v358)) goto v146;
    v358 = stack[-1];
    v358 = qcdr(v358);
    goto v279;

v279:
    fn = elt(env, 29); /* csl_normbf */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    goto v255;

v146:
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = integerp(v358);
    if (v358 == nil) goto v212;
    v359 = elt(env, 1); /* !:rd!: */
    v358 = stack[-1];
    v186 = qcdr(v358);
    v358 = (Lisp_Object)1; /* 0 */
    v358 = list2star(v359, v186, v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v279;

v212:
    v358 = stack[-1];
    v358 = qcdr(v358);
    fn = elt(env, 30); /* read!:num */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-5];
    goto v279;

v294:
    v358 = stack[-1];
    popv(6);
    return ncons(v358);
/* error exit handlers */
v363:
    popv(6);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v277, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v271, v278, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
    if (stack >= stacklimit)
    {
        push4(v277,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v277);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v277;
    v271 = v2;
    v278 = v1;
    v214 = v0;
/* end of prologue */
    v271 = Lsubst(nil, 3, v214, v278, v271);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    stack[-1] = v271;
    v271 = stack[0];
    if (v271 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v278 = stack[-1];
    v271 = stack[0];
    fn = elt(env, 2); /* indxsymp */
    v271 = (*qfn2(fn))(qenv(fn), v278, v271);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    if (!(v271 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v271 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v271); }
/* error exit handlers */
v248:
    popv(3);
    return nil;
}



/* Code for delete_edge */

static Lisp_Object CC_delete_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v265, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v209 = nil;
    goto v8;

v8:
    v264 = stack[0];
    if (v264 == nil) goto v163;
    v264 = stack[-1];
    v265 = qcar(v264);
    v264 = stack[0];
    v264 = qcar(v264);
    v264 = qcar(v264);
    if (v265 == v264) goto v275;
    v264 = stack[0];
    v264 = qcar(v264);
    v265 = v209;
    v264 = cons(v264, v265);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    v209 = v264;
    v264 = stack[0];
    v264 = qcdr(v264);
    stack[0] = v264;
    goto v8;

v275:
    v265 = v209;
    v264 = stack[0];
    v264 = qcdr(v264);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v265, v264);
    }

v163:
    v264 = v209;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v264);
    }
/* error exit handlers */
v145:
    popv(3);
    return nil;
}



/* Code for mo_support */

static Lisp_Object CC_mo_support(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_support");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v146 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 3); /* ring_names */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    stack[-1] = v146;
    goto v216;

v216:
    v146 = stack[-1];
    if (v146 == nil) goto v294;
    v146 = stack[-1];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    fn = elt(env, 4); /* mo_from_a */
    v246 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    v146 = stack[-2];
    fn = elt(env, 5); /* mo_divides!? */
    v146 = (*qfn2(fn))(qenv(fn), v246, v146);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    if (v146 == nil) goto v152;
    v246 = stack[0];
    v146 = stack[-3];
    v146 = cons(v246, v146);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    stack[-3] = v146;
    goto v152;

v152:
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v216;

v294:
    v146 = stack[-3];
        popv(5);
        return Lnreverse(nil, v146);
/* error exit handlers */
v147:
    popv(5);
    return nil;
}



/* Code for sub01 */

static Lisp_Object CC_sub01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v268, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub01");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v279 = nil;
    goto v8;

v8:
    v248 = stack[0];
    if (v248 == nil) goto v278;
    v248 = stack[0];
    v268 = qcar(v248);
    v248 = stack[-1];
    if (equal(v268, v248)) goto v241;
    v248 = (Lisp_Object)1; /* 0 */
    goto v221;

v221:
    v268 = v279;
    v248 = cons(v248, v268);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    v279 = v248;
    v248 = stack[0];
    v248 = qcdr(v248);
    stack[0] = v248;
    goto v8;

v241:
    v248 = (Lisp_Object)17; /* 1 */
    goto v221;

v278:
    v248 = v279;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v248);
    }
/* error exit handlers */
v246:
    popv(3);
    return nil;
}



/* Code for gd_gcasesimpl */

static Lisp_Object CC_gd_gcasesimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_gcasesimpl");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v241 = stack[0];
    stack[-1] = qcar(v241);
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 1); /* gd_simpl */
    v152 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    {
        Lisp_Object v222 = stack[-1];
        popv(2);
        return list3(v222, v152, v241);
    }
/* error exit handlers */
v255:
    popv(2);
    return nil;
}



/* Code for cols2rows2 */

static Lisp_Object CC_cols2rows2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cols2rows2");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v266 = stack[0];
    v215 = (Lisp_Object)1; /* 0 */
    if (v266 == v215) goto v8;
    v266 = stack[-1];
    v215 = stack[0];
    fn = elt(env, 1); /* ithlistelem */
    stack[-2] = (*qfn2(fn))(qenv(fn), v266, v215);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    v215 = stack[0];
    v215 = sub1(v215);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    v215 = CC_cols2rows2(env, stack[-1], v215);
    nil = C_nil;
    if (exception_pending()) goto v234;
    {
        Lisp_Object v146 = stack[-2];
        popv(4);
        return cons(v146, v215);
    }

v8:
    v215 = nil;
    { popv(4); return onevalue(v215); }
/* error exit handlers */
v234:
    popv(4);
    return nil;
}



/* Code for dm!-quotient */

static Lisp_Object CC_dmKquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v152 = v0;
/* end of prologue */
    v241 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v241; /* !*noequiv */
    v241 = v152;
    fn = elt(env, 3); /* dm!-mkfloat */
    stack[-1] = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    env = stack[-2];
    v241 = stack[0];
    fn = elt(env, 3); /* dm!-mkfloat */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    env = stack[-2];
    fn = elt(env, 4); /* !:quotient */
    v241 = (*qfn2(fn))(qenv(fn), stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v255;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v241);
    }
/* error exit handlers */
v255:
    popv(3);
    return nil;
}



/* Code for normmat */

static Lisp_Object CC_normmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v407, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for normmat");
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
    v225 = v0;
/* end of prologue */
    stack[-6] = nil;
    v407 = (Lisp_Object)17; /* 1 */
    stack[-8] = v407;
    v407 = v225;
    stack[-5] = v407;
    goto v256;

v256:
    v407 = stack[-5];
    if (v407 == nil) goto v286;
    v407 = stack[-5];
    v407 = qcar(v407);
    stack[-1] = v407;
    v407 = (Lisp_Object)17; /* 1 */
    stack[-7] = v407;
    v407 = stack[-1];
    stack[0] = v407;
    goto v245;

v245:
    v407 = stack[0];
    if (v407 == nil) goto v265;
    v407 = stack[0];
    v407 = qcar(v407);
    v225 = stack[-7];
    v407 = qcdr(v407);
    fn = elt(env, 2); /* lcm */
    v407 = (*qfn2(fn))(qenv(fn), v225, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    stack[-7] = v407;
    v407 = stack[0];
    v407 = qcdr(v407);
    stack[0] = v407;
    goto v245;

v265:
    v407 = stack[-1];
    stack[-4] = v407;
    v407 = stack[-4];
    if (v407 == nil) goto v236;
    v407 = stack[-4];
    v407 = qcar(v407);
    v225 = v407;
    stack[0] = qcar(v225);
    v225 = stack[-7];
    v407 = qcdr(v407);
    fn = elt(env, 3); /* quotf */
    v407 = (*qfn2(fn))(qenv(fn), v225, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v407 = (*qfn2(fn))(qenv(fn), stack[0], v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    v407 = ncons(v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    stack[-2] = v407;
    stack[-3] = v407;
    goto v293;

v293:
    v407 = stack[-4];
    v407 = qcdr(v407);
    stack[-4] = v407;
    v407 = stack[-4];
    if (v407 == nil) goto v409;
    stack[-1] = stack[-2];
    v407 = stack[-4];
    v407 = qcar(v407);
    v225 = v407;
    stack[0] = qcar(v225);
    v225 = stack[-7];
    v407 = qcdr(v407);
    fn = elt(env, 3); /* quotf */
    v407 = (*qfn2(fn))(qenv(fn), v225, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v407 = (*qfn2(fn))(qenv(fn), stack[0], v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    v407 = ncons(v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    v407 = Lrplacd(nil, stack[-1], v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    v407 = stack[-2];
    v407 = qcdr(v407);
    stack[-2] = v407;
    goto v293;

v409:
    v407 = stack[-3];
    v225 = v407;
    goto v147;

v147:
    v407 = stack[-6];
    v407 = cons(v225, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    stack[-6] = v407;
    v225 = stack[-7];
    v407 = stack[-8];
    fn = elt(env, 4); /* multf */
    v407 = (*qfn2(fn))(qenv(fn), v225, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[-9];
    stack[-8] = v407;
    v407 = stack[-5];
    v407 = qcdr(v407);
    stack[-5] = v407;
    goto v256;

v236:
    v407 = qvalue(elt(env, 1)); /* nil */
    v225 = v407;
    goto v147;

v286:
    v407 = stack[-6];
    v225 = Lreverse(nil, v407);
    nil = C_nil;
    if (exception_pending()) goto v408;
    v407 = stack[-8];
    popv(10);
    return cons(v225, v407);
/* error exit handlers */
v408:
    popv(10);
    return nil;
}



/* Code for mo!=expvec2a1 */

static Lisp_Object CC_moMexpvec2a1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v405, v406;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=expvec2a1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v8;

v8:
    v235 = stack[-1];
    if (v235 == nil) goto v163;
    v235 = stack[-1];
    v405 = qcar(v235);
    v235 = (Lisp_Object)1; /* 0 */
    if (v405 == v235) goto v200;
    v235 = stack[-1];
    v405 = qcar(v235);
    v235 = (Lisp_Object)17; /* 1 */
    if (v405 == v235) goto v215;
    v406 = elt(env, 1); /* expt */
    v235 = stack[0];
    v405 = qcar(v235);
    v235 = stack[-1];
    v235 = qcar(v235);
    v405 = list3(v406, v405, v235);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    v235 = stack[-2];
    v235 = cons(v405, v235);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    stack[-2] = v235;
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    v235 = stack[0];
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v8;

v215:
    v235 = stack[0];
    v405 = qcar(v235);
    v235 = stack[-2];
    v235 = cons(v405, v235);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    stack[-2] = v235;
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    v235 = stack[0];
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v8;

v200:
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    v235 = stack[0];
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v8;

v163:
    v235 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v235);
    }
/* error exit handlers */
v260:
    popv(4);
    return nil;
}



/* Code for addinds */

static Lisp_Object CC_addinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v280, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addinds");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v8;

v8:
    v280 = stack[-1];
    if (v280 == nil) goto v163;
    v280 = stack[0];
    if (v280 == nil) goto v150;
    v280 = stack[-1];
    v212 = qcar(v280);
    v280 = stack[0];
    v280 = qcar(v280);
    v280 = qcar(v280);
    v212 = plus2(v212, v280);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v280 = stack[-2];
    v280 = cons(v212, v280);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-2] = v280;
    v280 = stack[-1];
    v280 = qcdr(v280);
    stack[-1] = v280;
    v280 = stack[0];
    v280 = qcdr(v280);
    stack[0] = v280;
    goto v8;

v150:
    stack[0] = stack[-2];
    v280 = elt(env, 2); /* "Powu too long" */
    fn = elt(env, 3); /* interr */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    {
        Lisp_Object v223 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v223, v280);
    }

v163:
    v280 = stack[0];
    if (v280 == nil) goto v200;
    stack[0] = stack[-2];
    v280 = elt(env, 1); /* "Powrhs too long" */
    fn = elt(env, 3); /* interr */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    {
        Lisp_Object v247 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v247, v280);
    }

v200:
    v280 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v280);
    }
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for ofsf_simplequal */

static Lisp_Object CC_ofsf_simplequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v409, v233, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simplequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v409 = stack[-2];
    fn = elt(env, 8); /* ofsf_posdefp */
    v409 = (*qfn1(fn))(qenv(fn), v409);
    nil = C_nil;
    if (exception_pending()) goto v412;
    env = stack[-4];
    stack[-3] = v409;
    v233 = stack[-3];
    v409 = elt(env, 1); /* stsq */
    if (v233 == v409) goto v156;
    v409 = stack[-2];
    fn = elt(env, 9); /* sfto_sqfpartf */
    v409 = (*qfn1(fn))(qenv(fn), v409);
    nil = C_nil;
    if (exception_pending()) goto v412;
    env = stack[-4];
    stack[0] = v409;
    v409 = stack[0];
    fn = elt(env, 8); /* ofsf_posdefp */
    v409 = (*qfn1(fn))(qenv(fn), v409);
    nil = C_nil;
    if (exception_pending()) goto v412;
    env = stack[-4];
    v136 = v409;
    v233 = v136;
    v409 = elt(env, 1); /* stsq */
    if (v233 == v409) goto v259;
    v409 = qvalue(elt(env, 3)); /* !*rlsitsqspl */
    if (v409 == nil) goto v206;
    v409 = qvalue(elt(env, 4)); /* !*rlsiexpla */
    if (!(v409 == nil)) goto v143;
    v409 = qvalue(elt(env, 5)); /* !*rlsiexpl */
    if (v409 == nil) goto v206;
    v233 = stack[-1];
    v409 = elt(env, 6); /* and */
    if (!(v233 == v409)) goto v206;

v143:
    v233 = v136;
    v409 = elt(env, 7); /* tsq */
    if (v233 == v409) goto v210;
    v233 = stack[-3];
    v409 = elt(env, 7); /* tsq */
    if (!(v233 == v409)) goto v206;
    v409 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v409);
    }

v206:
    v233 = stack[0];
    v409 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_facequal!* */
        return (*qfn2(fn))(qenv(fn), v233, v409);
    }

v210:
    v409 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v409);
    }

v259:
    v409 = elt(env, 2); /* false */
    { popv(5); return onevalue(v409); }

v156:
    v409 = elt(env, 2); /* false */
    { popv(5); return onevalue(v409); }
/* error exit handlers */
v412:
    popv(5);
    return nil;
}



/* Code for pasf_ordatp */

static Lisp_Object CC_pasf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v135, v292, v283, v400, v399;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ordatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v283 = v1;
    v400 = v0;
/* end of prologue */
    v138 = v400;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v399 = v138;
    v138 = v283;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v292 = v138;
    v135 = v399;
    v138 = v292;
    if (equal(v135, v138)) goto v279;
    v138 = v399;
    v135 = v292;
    {
        popv(1);
        fn = elt(env, 3); /* ordp */
        return (*qfn2(fn))(qenv(fn), v138, v135);
    }

v279:
    v135 = v400;
    v138 = elt(env, 1); /* true */
    if (v135 == v138) goto v266;
    v135 = v400;
    v138 = elt(env, 2); /* false */
    if (v135 == v138) goto v266;
    v138 = v400;
    v138 = qcar(v138);
    v138 = Lconsp(nil, v138);
    env = stack[0];
    if (v138 == nil) goto v212;
    v138 = v400;
    v138 = qcar(v138);
    v138 = qcar(v138);
    v292 = v138;
    goto v262;

v262:
    v135 = v283;
    v138 = elt(env, 1); /* true */
    if (v135 == v138) goto v247;
    v135 = v283;
    v138 = elt(env, 2); /* false */
    if (v135 == v138) goto v247;
    v138 = v283;
    v138 = qcar(v138);
    v138 = Lconsp(nil, v138);
    env = stack[0];
    if (v138 == nil) goto v287;
    v138 = v283;
    v138 = qcar(v138);
    v138 = qcar(v138);
    goto v271;

v271:
    {
        popv(1);
        fn = elt(env, 4); /* pasf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v292, v138);
    }

v287:
    v138 = v283;
    v138 = qcar(v138);
    goto v271;

v247:
    v138 = v283;
    goto v271;

v212:
    v138 = v400;
    v138 = qcar(v138);
    v292 = v138;
    goto v262;

v266:
    v138 = v400;
    v292 = v138;
    goto v262;
}



/* Code for conditionrd */

static Lisp_Object MS_CDECL CC_conditionrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "conditionrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 3); /* lex */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-1];
    v208 = qvalue(elt(env, 1)); /* char */
    v151 = elt(env, 2); /* (r e l n) */
    if (equal(v208, v151)) goto v294;
    fn = elt(env, 4); /* mathml */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-1];
    stack[0] = v151;
    goto v8;

v8:
    fn = elt(env, 3); /* lex */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v294:
    fn = elt(env, 5); /* relnrd */
    v151 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-1];
    stack[0] = v151;
    goto v8;
/* error exit handlers */
v222:
    popv(2);
    return nil;
}



/* Code for ps!:quotient!-erule */

static Lisp_Object CC_psTquotientKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:quotient-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v1;
    v227 = v0;
/* end of prologue */
    v225 = v227;
    v225 = qcdr(v225);
    v225 = qcar(v225);
    stack[-8] = v225;
    v225 = v227;
    v225 = qcdr(v225);
    v225 = qcdr(v225);
    v225 = qcar(v225);
    stack[-6] = v225;
    v227 = qvalue(elt(env, 1)); /* nil */
    v225 = (Lisp_Object)17; /* 1 */
    v225 = cons(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[0] = v225;
    v225 = stack[-6];
    fn = elt(env, 3); /* ps!:order */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[-4] = v225;
    v225 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 3); /* ps!:order */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[-5] = v225;
    v225 = (Lisp_Object)17; /* 1 */
    stack[-3] = v225;
    goto v246;

v246:
    v227 = stack[-7];
    v225 = stack[-5];
    v227 = difference2(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    v225 = stack[-3];
    v225 = difference2(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    v225 = Lminusp(nil, v225);
    env = stack[-9];
    if (v225 == nil) goto v157;
    stack[-1] = stack[-8];
    v227 = stack[-7];
    v225 = stack[-4];
    v225 = plus2(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    v225 = stack[0];
    v225 = qcar(v225);
    fn = elt(env, 5); /* negf */
    v227 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    v225 = stack[0];
    v225 = qcdr(v225);
    v225 = cons(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    v227 = stack[-6];
    v225 = stack[-4];
    fn = elt(env, 4); /* ps!:evaluate */
    v225 = (*qfn2(fn))(qenv(fn), v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 7); /* invsq */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    {
        Lisp_Object v126 = stack[0];
        popv(10);
        fn = elt(env, 8); /* multsq */
        return (*qfn2(fn))(qenv(fn), v126, v225);
    }

v157:
    stack[-2] = stack[0];
    stack[0] = stack[-6];
    v227 = stack[-3];
    v225 = stack[-4];
    v225 = plus2(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); /* ps */
    v227 = stack[-7];
    v225 = stack[-3];
    v225 = difference2(v227, v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    v225 = (*qfn2(fn))(qenv(fn), stack[0], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 8); /* multsq */
    v225 = (*qfn2(fn))(qenv(fn), stack[-1], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    v225 = (*qfn2(fn))(qenv(fn), stack[-2], v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[0] = v225;
    v225 = stack[-3];
    v225 = add1(v225);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-9];
    stack[-3] = v225;
    goto v246;
/* error exit handlers */
v230:
    popv(10);
    return nil;
}



/* Code for !*rd2cr */

static Lisp_Object CC_Hrd2cr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v237, v157, v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *rd2cr");
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
    v237 = v0;
/* end of prologue */
    v238 = v237;
    v238 = qcdr(v238);
    if (!consp(v238)) goto v69;
    v238 = v237;
    goto v9;

v9:
    fn = elt(env, 4); /* convchk */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[0];
    v237 = v238;
    if (!consp(v237)) goto v269;
    v237 = qvalue(elt(env, 2)); /* bfz!* */
    goto v219;

v219:
    v157 = v237;
    v237 = elt(env, 3); /* !:cr!: */
    v263 = v238;
    if (!consp(v263)) goto v271;
    v238 = qcdr(v238);
    v263 = v238;
    goto v272;

v272:
    v238 = v157;
    if (!consp(v238)) goto v246;
    v238 = v157;
    v238 = qcdr(v238);
    goto v239;

v239:
    popv(1);
    return list2star(v237, v263, v238);

v246:
    v238 = v157;
    goto v239;

v271:
    v263 = v238;
    goto v272;

v269:
    v237 = elt(env, 1); /* 0.0 */
    goto v219;

v69:
    v238 = v237;
    v238 = qcdr(v238);
    goto v9;
/* error exit handlers */
v270:
    popv(1);
    return nil;
}



/* Code for ldf!-spf!-var */

static Lisp_Object CC_ldfKspfKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v400;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-spf-var");
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
    v283 = v0;
/* end of prologue */
    v400 = nil;
    stack[-3] = nil;
    stack[-1] = v283;
    goto v163;

v163:
    v283 = stack[-1];
    if (v283 == nil) goto v216;
    v283 = stack[-1];
    v283 = qcar(v283);
    stack[0] = v400;
    v400 = qcdr(v283);
    v283 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* kernels1 */
    v283 = (*qfn2(fn))(qenv(fn), v400, v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v283 = Lappend(nil, stack[0], v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v400 = v283;
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v163;

v216:
    v283 = v400;
    fn = elt(env, 5); /* makeset */
    v283 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    fn = elt(env, 6); /* prlist */
    v283 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[-2] = v283;
    goto v248;

v248:
    v283 = stack[-2];
    if (v283 == nil) goto v266;
    v283 = stack[-2];
    v283 = qcar(v283);
    stack[-1] = v283;
    v400 = stack[-1];
    v283 = elt(env, 2); /* x */
    if (!consp(v400)) goto v211;
    v400 = qcar(v400);
    if (!(v400 == v283)) goto v211;

v237:
    v283 = stack[-2];
    v283 = qcdr(v283);
    stack[-2] = v283;
    goto v248;

v211:
    v400 = stack[-1];
    v283 = elt(env, 3); /* u */
    if (!consp(v400)) goto v206;
    v400 = qcar(v400);
    if (v400 == v283) goto v237;
    else goto v206;

v206:
    v400 = elt(env, 2); /* x */
    v283 = stack[-1];
    v283 = qcdr(v283);
    fn = elt(env, 7); /* sacar */
    stack[0] = (*qfn2(fn))(qenv(fn), v400, v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v400 = elt(env, 3); /* u */
    v283 = stack[-1];
    v283 = qcdr(v283);
    fn = elt(env, 7); /* sacar */
    v400 = (*qfn2(fn))(qenv(fn), v400, v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v283 = stack[-3];
    fn = elt(env, 8); /* appends */
    v283 = (*qfnn(fn))(qenv(fn), 3, stack[0], v400, v283);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[-3] = v283;
    goto v237;

v266:
    v283 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* makeset */
        return (*qfn1(fn))(qenv(fn), v283);
    }
/* error exit handlers */
v205:
    popv(5);
    return nil;
}



/* Code for vdpcleanup */

static Lisp_Object MS_CDECL CC_vdpcleanup(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpcleanup");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcleanup");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v277 = qvalue(elt(env, 1)); /* nil */
    v277 = ncons(v277);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[0];
    qvalue(elt(env, 2)) = v277; /* dipevlist!* */
    { popv(1); return onevalue(v277); }
/* error exit handlers */
v9:
    popv(1);
    return nil;
}



setup_type const u41_setup[] =
{
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"ratpoly_sub",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_sub},
    {"vdp_getprop",             too_few_2,      CC_vdp_getprop,wrong_no_2},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"mk_binding",              too_few_2,      CC_mk_binding, wrong_no_2},
    {"compactf1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf1},
    {"baglistp",                CC_baglistp,    too_many_1,    wrong_no_1},
    {"proper-simpsqrt",         CC_properKsimpsqrt,too_many_1, wrong_no_1},
    {"ofsf_irl2atl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_irl2atl},
    {"impartf",                 CC_impartf,     too_many_1,    wrong_no_1},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"ps:term-rthpow",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTtermKrthpow},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"preproc1",                CC_preproc1,    too_many_1,    wrong_no_1},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"mo_support",              CC_mo_support,  too_many_1,    wrong_no_1},
    {"sub01",                   too_few_2,      CC_sub01,      wrong_no_2},
    {"gd_gcasesimpl",           CC_gd_gcasesimpl,too_many_1,   wrong_no_1},
    {"cols2rows2",              too_few_2,      CC_cols2rows2, wrong_no_2},
    {"dm-quotient",             too_few_2,      CC_dmKquotient,wrong_no_2},
    {"normmat",                 CC_normmat,     too_many_1,    wrong_no_1},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"addinds",                 too_few_2,      CC_addinds,    wrong_no_2},
    {"ofsf_simplequal",         too_few_2,      CC_ofsf_simplequal,wrong_no_2},
    {"pasf_ordatp",             too_few_2,      CC_pasf_ordatp,wrong_no_2},
    {"conditionrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_conditionrd},
    {"ps:quotient-erule",       too_few_2,      CC_psTquotientKerule,wrong_no_2},
    {"*rd2cr",                  CC_Hrd2cr,      too_many_1,    wrong_no_1},
    {"ldf-spf-var",             CC_ldfKspfKvar, too_many_1,    wrong_no_1},
    {"vdpcleanup",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpcleanup},
    {NULL, (one_args *)"u41", (two_args *)"10765 3225925 1648619", 0}
};

/* end of generated code */
