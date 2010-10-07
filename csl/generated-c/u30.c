
/* $destdir\u30.c        Machine generated C code */

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


/* Code for xreadlist */

static Lisp_Object MS_CDECL CC_xreadlist(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreadlist");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); /* scan */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = elt(env, 1); /* !*rcbkt!* */
    if (!(v25 == v24)) goto v27;
    fn = elt(env, 10); /* scan */
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = elt(env, 2); /* list */
    popv(5);
    return ncons(v24);

v27:
    v24 = stack[-1];
    if (v24 == nil) goto v28;
    v24 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    fn = elt(env, 12); /* nconc2 */
    v24 = (*qfn2(fn))(qenv(fn), stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    stack[0] = v24;
    goto v29;

v29:
    v24 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-3] = v24;
    v25 = stack[-3];
    v24 = elt(env, 5); /* !*semicol!* */
    if (v25 == v24) goto v30;
    fn = elt(env, 10); /* scan */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = elt(env, 1); /* !*rcbkt!* */
    if (!(v25 == v24)) goto v31;
    v25 = stack[-3];
    v24 = elt(env, 8); /* !*comma!* */
    if (!(v25 == v24)) goto v31;
    v25 = elt(env, 9); /* "Syntax error: invalid comma in list" */
    v24 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v24 = (*qfn2(fn))(qenv(fn), v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    goto v31;

v31:
    v25 = stack[-3];
    v24 = elt(env, 1); /* !*rcbkt!* */
    if (v25 == v24) goto v32;
    v24 = stack[-2];
    if (!(v24 == nil)) goto v27;
    v24 = stack[-3];
    stack[-2] = v24;
    goto v27;

v32:
    v25 = elt(env, 2); /* list */
    v24 = stack[-1];
    popv(5);
    return cons(v25, v24);

v30:
    v25 = elt(env, 6); /* "Syntax error: semicolon in list" */
    v24 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v24 = (*qfn2(fn))(qenv(fn), v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    goto v31;

v28:
    stack[0] = stack[-1];
    v24 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = Lnconc(nil, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    stack[0] = v24;
    stack[-1] = v24;
    goto v29;
/* error exit handlers */
v26:
    popv(5);
    return nil;
}



/* Code for toolongexpp */

static Lisp_Object CC_toolongexpp(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongexpp");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v36 = v33;
/* end of prologue */
    fn = elt(env, 2); /* numprintlen */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    v37 = qvalue(elt(env, 1)); /* maxexpprintlen!* */
        popv(1);
        return Lgreaterp(nil, v36, v37);
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for calc_coeff */

static Lisp_Object CC_calc_coeff(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_coeff");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v48 = stack[-1];
    if (v48 == nil) goto v51;
    v48 = stack[-1];
    v49 = qcar(v48);
    v48 = stack[0];
    fn = elt(env, 1); /* calc_world */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    v50 = v48;
    v49 = v50;
    v48 = (Lisp_Object)1; /* 0 */
    if (v49 == v48) goto v52;
    stack[-2] = v50;
    v48 = stack[-1];
    v49 = qcdr(v48);
    v48 = stack[0];
    v48 = CC_calc_coeff(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v15;
    {
        Lisp_Object v16 = stack[-2];
        popv(4);
        return cons(v16, v48);
    }

v52:
    v48 = (Lisp_Object)1; /* 0 */
    popv(4);
    return ncons(v48);

v51:
    v48 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v48);
/* error exit handlers */
v15:
    popv(4);
    return nil;
}



/* Code for vunion */

static Lisp_Object CC_vunion(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vunion");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v33;
/* end of prologue */
    v64 = stack[-2];
    if (v64 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v64 = stack[-2];
    v64 = qcar(v64);
    v4 = qcar(v64);
    v64 = stack[-1];
    v64 = Lassoc(nil, v4, v64);
    stack[-3] = v64;
    if (v64 == nil) goto v65;
    v64 = stack[-2];
    v64 = qcar(v64);
    v4 = qcdr(v64);
    v64 = stack[-3];
    v64 = qcdr(v64);
    v64 = (Lisp_Object)greaterp2(v4, v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v64 = v64 ? lisp_true : nil;
    env = stack[-4];
    if (v64 == nil) goto v67;
    v64 = stack[-2];
    stack[0] = qcar(v64);
    v64 = stack[-2];
    stack[-2] = qcdr(v64);
    v4 = stack[-3];
    v64 = stack[-1];
    v64 = Ldelete(nil, v4, v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v64 = CC_vunion(env, stack[-2], v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    {
        Lisp_Object v68 = stack[0];
        popv(5);
        return cons(v68, v64);
    }

v67:
    stack[0] = stack[-3];
    v64 = stack[-2];
    stack[-2] = qcdr(v64);
    v4 = stack[-3];
    v64 = stack[-1];
    v64 = Ldelete(nil, v4, v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v64 = CC_vunion(env, stack[-2], v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    {
        Lisp_Object v69 = stack[0];
        popv(5);
        return cons(v69, v64);
    }

v65:
    v64 = stack[-2];
    stack[0] = qcar(v64);
    v64 = stack[-2];
    v4 = qcdr(v64);
    v64 = stack[-1];
    v64 = CC_vunion(env, v4, v64);
    nil = C_nil;
    if (exception_pending()) goto v66;
    {
        Lisp_Object v1 = stack[0];
        popv(5);
        return cons(v1, v64);
    }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for procstat1 */

static Lisp_Object CC_procstat1(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat1");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v33;
/* end of prologue */
    stack[-4] = nil;
    stack[0] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v110 = qvalue(elt(env, 1)); /* erfg!* */
    stack[-6] = v110;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    if (v110 == nil) goto v52;
    v110 = qvalue(elt(env, 3)); /* t */
    stack[-6] = v110;
    goto v113;

v113:
    v112 = elt(env, 21); /* (symerr (quote procedure) t) */
    v111 = qvalue(elt(env, 9)); /* nil */
    v110 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v110 = (*qfnn(fn))(qenv(fn), 3, v112, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v115;

v115:
    v111 = qvalue(elt(env, 18)); /* eof!* */
    v110 = (Lisp_Object)1; /* 0 */
    v110 = (Lisp_Object)greaterp2(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v110 = v110 ? lisp_true : nil;
    env = stack[-7];
    if (v110 == nil) goto v116;
    v110 = elt(env, 19); /* !*semicol!* */
    qvalue(elt(env, 4)) = v110; /* cursym!* */
    goto v117;

v117:
    v110 = qvalue(elt(env, 2)); /* fname!* */
    v111 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v110 = elt(env, 17); /* fnc */
    v110 = Lremflag(nil, v111, v110);
    env = stack[-7];
    v110 = qvalue(elt(env, 9)); /* nil */
    qvalue(elt(env, 2)) = v110; /* fname!* */
    v110 = qvalue(elt(env, 1)); /* erfg!* */
    if (v110 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v110 = qvalue(elt(env, 9)); /* nil */
    stack[-2] = v110;
    v110 = stack[-6];
    if (!(v110 == nil)) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v110 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }

v116:
    v112 = elt(env, 20); /* (xread t) */
    v111 = qvalue(elt(env, 9)); /* nil */
    v110 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v110 = (*qfnn(fn))(qenv(fn), 3, v112, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v110;
    v110 = stack[-2];
    if (!consp(v110)) goto v118;
    v110 = stack[-2];
    v110 = qcdr(v110);
    if (!(v110 == nil)) goto v118;
    v110 = stack[-2];
    v110 = qcar(v110);
    stack[-2] = v110;
    goto v118;

v118:
    v110 = qvalue(elt(env, 1)); /* erfg!* */
    if (!(v110 == nil)) goto v117;
    stack[-1] = elt(env, 5); /* procedure */
    v110 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v110 == nil) goto v119;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    stack[0] = v110;
    goto v120;

v120:
    v112 = stack[-4];
    v111 = stack[-3];
    v110 = stack[-2];
    v110 = list3(v112, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v110 = list3star(stack[-1], stack[0], stack[-5], v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v110;
    goto v117;

v119:
    v110 = stack[0];
    v110 = qcar(v110);
    stack[0] = v110;
    goto v120;

v52:
    v111 = qvalue(elt(env, 4)); /* cursym!* */
    v110 = elt(env, 5); /* procedure */
    if (v111 == v110) goto v63;
    v110 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-4] = v110;
    fn = elt(env, 23); /* scan */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v62;

v62:
    v111 = qvalue(elt(env, 4)); /* cursym!* */
    v110 = elt(env, 5); /* procedure */
    if (!(v111 == v110)) goto v113;
    v110 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v110 == nil) goto v48;
    fn = elt(env, 23); /* scan */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    qvalue(elt(env, 2)) = v110; /* fname!* */
    v110 = qvalue(elt(env, 2)); /* fname!* */
    if (symbolp(v110)) goto v121;
    v111 = qvalue(elt(env, 2)); /* fname!* */
    v110 = elt(env, 14); /* "procedure name" */
    fn = elt(env, 24); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v115;

v121:
    fn = elt(env, 23); /* scan */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-1] = elt(env, 15); /* read_param_list */
    v110 = stack[-5];
    v110 = Lmkquote(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v112 = list2(stack[-1], v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = qvalue(elt(env, 9)); /* nil */
    v110 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v110 = (*qfnn(fn))(qenv(fn), 3, v112, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-3] = v110;
    v110 = stack[-3];
    if (!consp(v110)) goto v115;
    v110 = stack[-3];
    v110 = qcdr(v110);
    if (!(v110 == nil)) goto v115;
    v110 = stack[-3];
    v110 = qcar(v110);
    stack[-3] = v110;
    v111 = qvalue(elt(env, 4)); /* cursym!* */
    v110 = elt(env, 16); /* !*colon!* */
    if (!(v111 == v110)) goto v36;
    fn = elt(env, 25); /* read_type */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-5] = v110;
    goto v36;

v36:
    v110 = qvalue(elt(env, 2)); /* fname!* */
    if (!(symbolp(v110))) goto v115;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    fn = elt(env, 26); /* getd */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (!(v110 == nil)) goto v115;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    v111 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v110 = elt(env, 17); /* fnc */
    v110 = Lflag(nil, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v115;

v48:
    v112 = elt(env, 8); /* (xread (quote proc)) */
    v111 = qvalue(elt(env, 9)); /* nil */
    v110 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v110 = (*qfnn(fn))(qenv(fn), 3, v112, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[0] = v110;
    v110 = stack[0];
    if (!consp(v110)) goto v115;
    v110 = stack[0];
    v110 = qcdr(v110);
    if (!(v110 == nil)) goto v115;
    v110 = stack[0];
    v110 = qcar(v110);
    stack[0] = v110;
    if (!(!consp(v110))) goto v122;
    v110 = stack[0];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[0] = v110;
    goto v122;

v122:
    v110 = stack[0];
    v110 = qcar(v110);
    qvalue(elt(env, 2)) = v110; /* fname!* */
    v110 = qvalue(elt(env, 2)); /* fname!* */
    if (!(symbolp(v110))) goto v67;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    if (v110 == nil) goto v66;
    v110 = qvalue(elt(env, 2)); /* fname!* */
    fn = elt(env, 27); /* gettype */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v110;
    if (v110 == nil) goto v67;
    v111 = stack[-2];
    v110 = elt(env, 11); /* (procedure operator) */
    v110 = Lmemq(nil, v111, v110);
    if (!(v110 == nil)) goto v67;

v66:
    v111 = stack[-2];
    v110 = qvalue(elt(env, 2)); /* fname!* */
    v111 = list2(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v110 = elt(env, 12); /* "procedure" */
    fn = elt(env, 24); /* typerr */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v115;

v67:
    v110 = stack[0];
    v110 = qcdr(v110);
    stack[-3] = v110;
    v110 = stack[-3];
    fn = elt(env, 28); /* idlistp */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v110 == nil) goto v123;
    v110 = stack[0];
    v111 = qcar(v110);
    v110 = stack[-3];
    v110 = cons(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[0] = v110;
    goto v36;

v123:
    v111 = stack[-3];
    v110 = elt(env, 13); /* "invalid as parameter list" */
    v110 = list2(v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    fn = elt(env, 29); /* lprie */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    goto v36;

v63:
    v110 = elt(env, 6); /* expr */
    stack[-4] = v110;
    goto v62;
/* error exit handlers */
v114:
    popv(8);
    return nil;
}



/* Code for equiv!-coeffs */

static Lisp_Object CC_equivKcoeffs(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    stack[-2] = nil;
    goto v82;

v82:
    v128 = stack[-1];
    if (v128 == nil) goto v38;
    v128 = stack[0];
    if (v128 == nil) goto v63;
    v128 = stack[-1];
    v128 = qcar(v128);
    v129 = qcar(v128);
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcar(v128);
    if (equal(v129, v128)) goto v130;
    v128 = stack[-1];
    v128 = qcar(v128);
    v129 = qcar(v128);
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcar(v128);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (v128 == nil) goto v131;
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    goto v82;

v131:
    v129 = (Lisp_Object)1; /* 0 */
    v128 = stack[-2];
    v128 = cons(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[0];
    v128 = qcdr(v128);
    stack[0] = v128;
    goto v82;

v130:
    v128 = stack[-1];
    v128 = qcar(v128);
    v129 = qcdr(v128);
    v128 = stack[-2];
    v128 = cons(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    v128 = stack[0];
    v128 = qcdr(v128);
    stack[0] = v128;
    goto v82;

v63:
    v128 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v128);
    }

v38:
    stack[-1] = stack[-2];
    v128 = stack[0];
    v128 = Llength(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 3); /* nzeros */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    {
        Lisp_Object v132 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v132, v128);
    }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for red_tailreddriver */

static Lisp_Object MS_CDECL CC_red_tailreddriver(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v6,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_tailreddriver");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailreddriver");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v33,v6,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v6;
    stack[-3] = v33;
/* end of prologue */
    v18 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    if (v18 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v18 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    v18 = qcdr(v18);
    if (v18 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v18 = stack[-3];
    if (v18 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    else goto v52;

v52:
    v18 = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    if (v18 == nil) goto v29;
    stack[-4] = stack[-1];
    stack[0] = stack[-3];
    v18 = stack[-2];
    fn = elt(env, 3); /* red!=hidelt */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    v18 = Lapply2(nil, 3, stack[-4], stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    stack[-2] = v18;
    goto v52;

v29:
    v18 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* red!=recover */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v42:
    popv(6);
    return nil;
}



/* Code for xnsiz */

static Lisp_Object CC_xnsiz(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xnsiz");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v37 = v33;
/* end of prologue */
    fn = elt(env, 2); /* xnsiz1 */
    v38 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[0];
    v37 = qvalue(elt(env, 1)); /* log2of10 */
    v37 = quot2(v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* ceiling */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v135:
    popv(1);
    return nil;
}



/* Code for component_action */

static Lisp_Object MS_CDECL CC_component_action(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v6,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v141, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "component_action");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for component_action");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v33,v6,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v3;
    stack[-3] = v6;
    stack[0] = v33;
/* end of prologue */
    v141 = qvalue(elt(env, 1)); /* nil */
    v140 = (Lisp_Object)17; /* 1 */
    v140 = cons(v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    stack[-4] = v140;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[-1] = v140;
    goto v23;

v23:
    v140 = stack[-1];
    if (v140 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v140 = stack[-1];
    v140 = qcar(v140);
    stack[0] = v140;
    v140 = stack[0];
    v141 = qcar(v140);
    v140 = stack[-3];
    fn = elt(env, 2); /* ext_mult */
    v141 = (*qfn2(fn))(qenv(fn), v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    v140 = stack[0];
    v140 = qcdr(v140);
    v60 = v141;
    v141 = v140;
    v140 = v60;
    v140 = qcar(v140);
    if (v140 == nil) goto v39;
    stack[0] = stack[-4];
    v140 = v60;
    fn = elt(env, 3); /* multsq */
    v141 = (*qfn2(fn))(qenv(fn), v140, v141);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    v140 = stack[-2];
    fn = elt(env, 3); /* multsq */
    v140 = (*qfn2(fn))(qenv(fn), v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    fn = elt(env, 4); /* addsq */
    v140 = (*qfn2(fn))(qenv(fn), stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    stack[-4] = v140;
    goto v39;

v39:
    v140 = stack[-1];
    v140 = qcdr(v140);
    stack[-1] = v140;
    goto v23;
/* error exit handlers */
v128:
    popv(6);
    return nil;
}



/* Code for ofsf_at2ir */

static Lisp_Object CC_ofsf_at2ir(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_at2ir");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v6;
    v7 = v33;
/* end of prologue */
    v148 = v7;
    v148 = qcar(v148);
    stack[-4] = v148;
    v148 = v7;
    v148 = qcdr(v148);
    v148 = qcar(v148);
    stack[-2] = v148;
    stack[0] = v148;
    goto v149;

v149:
    v148 = stack[0];
    if (!consp(v148)) goto v108;
    v148 = stack[0];
    v148 = qcar(v148);
    if (!consp(v148)) goto v108;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v149;

v108:
    stack[-1] = stack[-2];
    v148 = stack[0];
    fn = elt(env, 2); /* negf */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    fn = elt(env, 3); /* addf */
    v148 = (*qfn2(fn))(qenv(fn), stack[-1], v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-2] = v148;
    v148 = stack[-2];
    fn = elt(env, 4); /* sfto_dcontentf */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-1] = v148;
    v7 = stack[-2];
    v148 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v148 = (*qfn2(fn))(qenv(fn), v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-2] = v148;
    v7 = stack[0];
    v148 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v7 = stack[-1];
    v148 = (Lisp_Object)17; /* 1 */
    v148 = cons(v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    fn = elt(env, 6); /* invsq */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    fn = elt(env, 7); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[0] = v148;
    stack[-1] = stack[-2];
    v8 = stack[-3];
    v7 = stack[-4];
    v148 = stack[0];
    v148 = list2star(v8, v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v7 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v55 = stack[-1];
        popv(6);
        return list2star(v55, v148, v7);
    }
/* error exit handlers */
v107:
    popv(6);
    return nil;
}



/* Code for testord */

static Lisp_Object CC_testord(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testord");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */

v51:
    v44 = stack[-1];
    if (v44 == nil) goto v35;
    v44 = stack[-1];
    v45 = qcar(v44);
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = (Lisp_Object)lesseq2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v44 = v44 ? lisp_true : nil;
    env = stack[-2];
    if (v44 == nil) goto v28;
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v51;

v28:
    v44 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v44); }

v35:
    v44 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for mk!+resimp!+mat */

static Lisp_Object CC_mkLresimpLmat(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+resimp+mat");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v154 = v33;
/* end of prologue */
    stack[-7] = v154;
    v154 = stack[-7];
    if (v154 == nil) goto v149;
    v154 = stack[-7];
    v154 = qcar(v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v20;
    v154 = stack[-3];
    v154 = qcar(v154);
    fn = elt(env, 2); /* resimp */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    stack[-1] = v154;
    stack[-2] = v154;
    goto v109;

v109:
    v154 = stack[-3];
    v154 = qcdr(v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v146;
    stack[0] = stack[-1];
    v154 = stack[-3];
    v154 = qcar(v154);
    fn = elt(env, 2); /* resimp */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = Lrplacd(nil, stack[0], v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = stack[-1];
    v154 = qcdr(v154);
    stack[-1] = v154;
    goto v109;

v146:
    v154 = stack[-2];
    goto v28;

v28:
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    stack[-5] = v154;
    stack[-6] = v154;
    goto v37;

v37:
    v154 = stack[-7];
    v154 = qcdr(v154);
    stack[-7] = v154;
    v154 = stack[-7];
    if (v154 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v154 = stack[-7];
    v154 = qcar(v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v8;
    v154 = stack[-3];
    v154 = qcar(v154);
    fn = elt(env, 2); /* resimp */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    stack[-1] = v154;
    stack[-2] = v154;
    goto v145;

v145:
    v154 = stack[-3];
    v154 = qcdr(v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v103;
    stack[0] = stack[-1];
    v154 = stack[-3];
    v154 = qcar(v154);
    fn = elt(env, 2); /* resimp */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = Lrplacd(nil, stack[0], v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = stack[-1];
    v154 = qcdr(v154);
    stack[-1] = v154;
    goto v145;

v103:
    v154 = stack[-2];
    goto v144;

v144:
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = Lrplacd(nil, stack[-4], v154);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-8];
    v154 = stack[-5];
    v154 = qcdr(v154);
    stack[-5] = v154;
    goto v37;

v8:
    v154 = qvalue(elt(env, 1)); /* nil */
    goto v144;

v20:
    v154 = qvalue(elt(env, 1)); /* nil */
    goto v28;

v149:
    v154 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v154); }
/* error exit handlers */
v123:
    popv(9);
    return nil;
}



/* Code for aex_0 */

static Lisp_Object MS_CDECL CC_aex_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "aex_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_0");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 1); /* ratpoly_0 */
    v2 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aex_fromrp */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for bvarrd */

static Lisp_Object MS_CDECL CC_bvarrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "bvarrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    fn = elt(env, 8); /* lex */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v7 = qvalue(elt(env, 1)); /* char */
    v148 = elt(env, 2); /* (d e g r e e) */
    if (!(equal(v7, v148))) goto v27;
    v7 = elt(env, 3); /* "<bvar>" */
    v148 = (Lisp_Object)241; /* 15 */
    fn = elt(env, 9); /* errorml */
    v148 = (*qfn2(fn))(qenv(fn), v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    goto v27;

v27:
    fn = elt(env, 10); /* mathml2 */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    stack[-1] = v148;
    fn = elt(env, 8); /* lex */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v7 = qvalue(elt(env, 1)); /* char */
    v148 = elt(env, 2); /* (d e g r e e) */
    if (equal(v7, v148)) goto v109;
    v148 = (Lisp_Object)17; /* 1 */
    stack[0] = v148;
    goto v13;

v13:
    v7 = qvalue(elt(env, 1)); /* char */
    v148 = elt(env, 6); /* (!/ b v a r) */
    if (equal(v7, v148)) goto v141;
    v7 = elt(env, 7); /* "</bvar>" */
    v148 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* errorml */
    v148 = (*qfn2(fn))(qenv(fn), v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v148 = nil;
    { popv(3); return onevalue(v148); }

v141:
    v7 = stack[-1];
    v148 = stack[0];
    popv(3);
    return list2(v7, v148);

v109:
    fn = elt(env, 11); /* mathml */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    stack[0] = v148;
    fn = elt(env, 8); /* lex */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v7 = qvalue(elt(env, 1)); /* char */
    v148 = elt(env, 4); /* (!/ d e g r e e) */
    if (equal(v7, v148)) goto v130;
    v7 = elt(env, 5); /* "</degree>" */
    v148 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 12); /* error */
    v148 = (*qfn2(fn))(qenv(fn), v7, v148);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    goto v130;

v130:
    fn = elt(env, 8); /* lex */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    goto v13;
/* error exit handlers */
v157:
    popv(3);
    return nil;
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308, v309, v310, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v6;
    stack[-5] = v33;
/* end of prologue */
    stack[-1] = nil;
    v308 = stack[-5];
    v308 = qcdr(v308);
    stack[-6] = v308;
    v308 = stack[-5];
    v308 = qcar(v308);
    stack[-5] = v308;
    v309 = stack[-6];
    v308 = (Lisp_Object)17; /* 1 */
    v308 = (Lisp_Object)greaterp2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    v308 = v308 ? lisp_true : nil;
    env = stack[-7];
    if (v308 == nil) goto v313;
    v308 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v308 == nil) goto v313;
    v308 = stack[-5];
    fn = elt(env, 21); /* noncomp1 */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    if (v308 == nil) goto v313;
    v309 = stack[-5];
    v308 = stack[-4];
    v308 = list2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 22); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[0] = stack[-5];
    v308 = stack[-6];
    v308 = sub1(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = list2(stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 23); /* simpexpt */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v310 = stack[-5];
    v309 = (Lisp_Object)17; /* 1 */
    v308 = (Lisp_Object)17; /* 1 */
    v308 = acons(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v309 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-2] = stack[-5];
    v308 = stack[-6];
    v308 = sub1(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v309 = cons(stack[-2], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-4];
    v308 = CC_diffp(env, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v308 = (*qfn2(fn))(qenv(fn), stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    {
        Lisp_Object v314 = stack[-1];
        popv(8);
        fn = elt(env, 25); /* addsq */
        return (*qfn2(fn))(qenv(fn), v314, v308);
    }

v313:
    v309 = stack[-5];
    v308 = stack[-4];
    if (!(v309 == v308)) goto v106;
    v309 = (Lisp_Object)17; /* 1 */
    v308 = (Lisp_Object)17; /* 1 */
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    if (!(v308 == nil)) goto v315;

v106:
    v308 = stack[-5];
    if (!consp(v308)) goto v316;
    v308 = stack[-5];
    v308 = qcar(v308);
    if (!consp(v308)) goto v317;
    v309 = stack[-5];
    v308 = stack[-4];
    fn = elt(env, 26); /* difff */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    if (!(v308 == nil)) goto v315;

v317:
    v308 = stack[-5];
    v309 = qcar(v308);
    v308 = elt(env, 2); /* !*sq */
    if (!(v309 == v308)) goto v95;
    v308 = stack[-5];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    if (!(v308 == nil)) goto v315;

v95:
    v308 = stack[-5];
    v309 = qcar(v308);
    v308 = elt(env, 3); /* dfform */
    v308 = get(v309, v308);
    env = stack[-7];
    stack[-3] = v308;
    if (v308 == nil) goto v90;
    v311 = stack[-3];
    v310 = stack[-5];
    v309 = stack[-4];
    v308 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v311, v310, v309, v308);

v90:
    v308 = stack[-5];
    stack[0] = qcar(v308);
    v308 = stack[-5];
    fn = elt(env, 28); /* dfn_prop */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = get(stack[0], v308);
    env = stack[-7];
    stack[-3] = v308;
    if (v308 == nil) goto v318;
    v308 = stack[-3];
    stack[-2] = v308;
    v308 = stack[-5];
    v308 = qcdr(v308);
    stack[0] = v308;
    goto v83;

v83:
    v308 = stack[0];
    v308 = qcar(v308);
    fn = elt(env, 29); /* simp */
    v309 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v309 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-1];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[-1];
    v308 = qcar(v308);
    v308 = qcar(v308);
    if (v308 == nil) goto v319;
    v308 = stack[-2];
    v308 = qcar(v308);
    if (!(v308 == nil)) goto v319;

v320:
    v308 = stack[-5];
    v309 = qcar(v308);
    v308 = elt(env, 15); /* df */
    if (v309 == v308) goto v321;
    v310 = elt(env, 15); /* df */
    v309 = stack[-5];
    v308 = stack[-4];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v22;

v22:
    v308 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-3] = v308;
    if (v308 == nil) goto v322;
    v308 = stack[-3];
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v315;

v315:
    v309 = stack[-5];
    v308 = qvalue(elt(env, 6)); /* wtl!* */
    v308 = Latsoc(nil, v309, v308);
    stack[-3] = v308;
    if (v308 == nil) goto v323;
    stack[0] = elt(env, 7); /* k!* */
    v308 = stack[-3];
    v308 = qcdr(v308);
    v309 = negate(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = (Lisp_Object)17; /* 1 */
    v308 = acons(stack[0], v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v309 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = (Lisp_Object)17; /* 1 */
    v309 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-1];
    fn = elt(env, 24); /* multsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v323;

v323:
    v308 = stack[-6];
    v308 = sub1(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[0] = v308;
    v309 = stack[-6];
    v308 = (Lisp_Object)17; /* 1 */
    if (v309 == v308) goto v324;
    v309 = qvalue(elt(env, 8)); /* dmode!* */
    v308 = elt(env, 9); /* convert */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-7];
    if (v308 == nil) goto v325;
    v309 = qvalue(elt(env, 8)); /* dmode!* */
    v308 = elt(env, 10); /* i2d */
    v309 = get(v309, v308);
    env = stack[-7];
    v308 = stack[-6];
    v308 = Lapply1(nil, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 31); /* int!-equiv!-chk */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-6] = v308;
    if (!(v308 == nil)) goto v325;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    goto v326;

v326:
    {
        popv(8);
        fn = elt(env, 32); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v308);
    }

v325:
    v310 = stack[-5];
    v309 = stack[0];
    v308 = stack[-6];
    v308 = acons(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v309 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = (Lisp_Object)17; /* 1 */
    v309 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-1];
    fn = elt(env, 24); /* multsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    goto v326;

v324:
    v308 = stack[-1];
    goto v326;

v322:
    v309 = stack[-5];
    v308 = stack[-4];
    fn = elt(env, 33); /* depends */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    if (!(v308 == nil)) goto v327;
    v308 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v308 == nil)) goto v327;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v309, v308);

v327:
    v309 = stack[-1];
    v308 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v315;

v321:
    v308 = stack[-5];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-4];
    if (!(v309 == v308)) goto v328;
    v308 = qvalue(elt(env, 16)); /* !*commutedf */
    if (v308 == nil) goto v329;
    v308 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v308 == nil)) goto v329;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v309, v308);

v329:
    v308 = qvalue(elt(env, 17)); /* !*simpnoncomdf */
    if (v308 == nil) goto v330;
    v309 = stack[-4];
    v308 = qvalue(elt(env, 14)); /* depl!* */
    v308 = Latsoc(nil, v309, v308);
    stack[-1] = v308;
    if (v308 == nil) goto v330;
    v308 = stack[-1];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    if (!(v308 == nil)) goto v330;
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = qcar(v308);
    stack[-3] = v308;
    v310 = elt(env, 15); /* df */
    v309 = stack[-5];
    v308 = stack[-3];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v310 = elt(env, 15); /* df */
    v309 = stack[-4];
    v308 = stack[-3];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 35); /* invsq */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v308 = (*qfn2(fn))(qenv(fn), stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v315;

v330:
    v308 = stack[-5];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = elt(env, 18); /* int */
    if (!consp(v309)) goto v328;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v328;
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-4];
    if (v309 == v308) goto v331;
    v308 = qvalue(elt(env, 19)); /* !*allowdfint */
    if (v308 == nil) goto v328;
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v308 = qcar(v308);
    fn = elt(env, 36); /* simp!* */
    v309 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    fn = elt(env, 37); /* not_df_p */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    if (v308 == nil) goto v328;
    stack[-2] = elt(env, 15); /* df */
    stack[0] = elt(env, 18); /* int */
    v308 = stack[-1];
    fn = elt(env, 38); /* mk!*sq */
    v309 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = qcar(v308);
    v308 = list3(stack[0], v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 39); /* reval */
    v309 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = list2star(stack[-2], v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v22;

v328:
    v308 = stack[-5];
    v308 = qcdr(v308);
    stack[0] = qcar(v308);
    v309 = stack[-5];
    v308 = stack[-4];
    fn = elt(env, 40); /* merge!-ind!-vars */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v310 = cons(stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v310;
    v309 = elt(env, 15); /* df */
    v308 = elt(env, 20); /* kvalue */
    v308 = get(v309, v308);
    env = stack[-7];
    fn = elt(env, 41); /* find_sub_df */
    v308 = (*qfn2(fn))(qenv(fn), v310, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-3] = v308;
    if (v308 == nil) goto v332;
    v308 = stack[-3];
    v308 = qcar(v308);
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[-3];
    v308 = qcdr(v308);
    stack[-3] = v308;
    goto v333;

v333:
    v308 = stack[-3];
    if (v308 == nil) goto v315;
    v308 = stack[-3];
    v308 = qcar(v308);
    stack[-2] = v308;
    v308 = (Lisp_Object)17; /* 1 */
    stack[0] = v308;
    goto v334;

v334:
    v308 = stack[-2];
    v309 = qcdr(v308);
    v308 = stack[0];
    v308 = difference2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = Lminusp(nil, v308);
    env = stack[-7];
    if (v308 == nil) goto v335;
    v308 = stack[-3];
    v308 = qcdr(v308);
    stack[-3] = v308;
    goto v333;

v335:
    v309 = stack[-1];
    v308 = stack[-2];
    v308 = qcar(v308);
    fn = elt(env, 27); /* diffsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[0];
    v308 = add1(v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[0] = v308;
    goto v334;

v332:
    v309 = elt(env, 15); /* df */
    v308 = stack[-1];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v22;

v331:
    v310 = elt(env, 15); /* df */
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-5];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = list2star(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v22;

v319:
    v308 = stack[-2];
    v308 = qcdr(v308);
    stack[-2] = v308;
    v308 = stack[0];
    v308 = qcdr(v308);
    stack[0] = v308;
    v308 = stack[0];
    if (v308 == nil) goto v78;
    v308 = stack[-2];
    if (!(v308 == nil)) goto v83;

v78:
    v308 = stack[0];
    if (!(v308 == nil)) goto v320;
    v308 = stack[-2];
    if (!(v308 == nil)) goto v320;
    v308 = stack[-1];
    v308 = Lreverse(nil, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-2] = v308;
    v308 = stack[-5];
    v308 = qcdr(v308);
    stack[0] = v308;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v37;

v37:
    v308 = stack[-2];
    v308 = qcar(v308);
    v308 = qcar(v308);
    if (v308 == nil) goto v117;
    v308 = stack[-2];
    stack[-4] = qcar(v308);
    v308 = stack[-3];
    v308 = qcar(v308);
    v309 = qcar(v308);
    v308 = stack[0];
    fn = elt(env, 42); /* pair */
    v309 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-3];
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v308 = Lsubla(nil, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v309 = (*qfn2(fn))(qenv(fn), stack[-4], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-1];
    fn = elt(env, 25); /* addsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    goto v117;

v117:
    v308 = stack[-3];
    v308 = qcdr(v308);
    stack[-3] = v308;
    v308 = stack[-2];
    v308 = qcdr(v308);
    stack[-2] = v308;
    v308 = stack[-2];
    if (v308 == nil) goto v315;
    else goto v37;

v318:
    v308 = stack[-5];
    v309 = qcar(v308);
    v308 = elt(env, 5); /* plus */
    if (!(v309 == v308)) goto v320;
    v308 = stack[-5];
    fn = elt(env, 29); /* simp */
    v309 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v308 = stack[-4];
    fn = elt(env, 27); /* diffsq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    if (v308 == nil) goto v320;
    else goto v315;

v316:
    v309 = stack[-5];
    v308 = stack[-4];
    fn = elt(env, 33); /* depends */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    if (!(v308 == nil)) goto v336;
    v309 = stack[-5];
    v308 = qvalue(elt(env, 11)); /* powlis!* */
    v308 = Latsoc(nil, v309, v308);
    stack[-3] = v308;
    if (v308 == nil) goto v337;
    v308 = stack[-3];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-4];
    fn = elt(env, 33); /* depends */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    if (!(v308 == nil)) goto v336;

v337:
    v308 = qvalue(elt(env, 12)); /* !*depend */
    if (!(v308 == nil)) goto v336;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v309, v308);

v336:
    v308 = qvalue(elt(env, 13)); /* !*expanddf */
    if (v308 == nil) goto v338;
    v310 = stack[-4];
    v309 = stack[-5];
    v308 = qvalue(elt(env, 14)); /* depl!* */
    v308 = Latsoc(nil, v309, v308);
    v308 = qcdr(v308);
    stack[-3] = v308;
    v308 = Lmemq(nil, v310, v308);
    if (!(v308 == nil)) goto v338;
    v309 = qvalue(elt(env, 4)); /* nil */
    v308 = (Lisp_Object)17; /* 1 */
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[-3];
    stack[-3] = v308;
    goto v339;

v339:
    v308 = stack[-3];
    if (v308 == nil) goto v315;
    v308 = stack[-3];
    v308 = qcar(v308);
    stack[-2] = v308;
    v310 = elt(env, 15); /* df */
    v309 = stack[-5];
    v308 = stack[-2];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    v310 = elt(env, 15); /* df */
    v309 = stack[-2];
    v308 = stack[-4];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 24); /* multsq */
    v308 = (*qfn2(fn))(qenv(fn), stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    fn = elt(env, 25); /* addsq */
    v308 = (*qfn2(fn))(qenv(fn), stack[-1], v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[-3];
    v308 = qcdr(v308);
    stack[-3] = v308;
    goto v339;

v338:
    v310 = elt(env, 15); /* df */
    v309 = stack[-5];
    v308 = stack[-4];
    v308 = list3(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-1] = v308;
    v308 = stack[-1];
    fn = elt(env, 30); /* opmtch */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    stack[-3] = v308;
    if (v308 == nil) goto v340;
    v308 = stack[-3];
    fn = elt(env, 29); /* simp */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    goto v341;

v341:
    stack[-1] = v308;
    goto v315;

v340:
    v309 = stack[-1];
    v308 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 34); /* mksq */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-7];
    goto v341;
/* error exit handlers */
v312:
    popv(8);
    return nil;
}



/* Code for simpimpart */

static Lisp_Object CC_simpimpart(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpimpart");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v134 = v33;
/* end of prologue */
    v35 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = v35; /* !*factor */
    v35 = v134;
    v35 = qcar(v35);
    fn = elt(env, 3); /* simp!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    fn = elt(env, 4); /* impartsq */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    { popv(2); return onevalue(v35); }
/* error exit handlers */
v36:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    popv(2);
    return nil;
}



/* Code for extbrsea */

static Lisp_Object MS_CDECL CC_extbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v364, v365, v366;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extbrsea");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v364 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v364;
    goto v139;

v139:
    v365 = qvalue(elt(env, 2)); /* rowmax */
    v364 = stack[-1];
    v364 = difference2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v364 = Lminusp(nil, v364);
    env = stack[-2];
    if (v364 == nil) goto v138;
    fn = elt(env, 8); /* initbrsea */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    goto v368;

v368:
    fn = elt(env, 10); /* expandprod */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v364 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v364;
    goto v369;

v369:
    v365 = qvalue(elt(env, 2)); /* rowmax */
    v364 = stack[-1];
    v364 = difference2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v364 = Lminusp(nil, v364);
    env = stack[-2];
    if (v364 == nil) goto v370;
    fn = elt(env, 8); /* initbrsea */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    fn = elt(env, 11); /* shrinkprod */
    v364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    if (!(v364 == nil)) goto v368;
    v364 = nil;
    { popv(3); return onevalue(v364); }

v370:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v365 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)49; /* 3 */
    v365 = *(Lisp_Object *)((char *)v365 + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)-15; /* -1 */
    if (v365 == v364) goto v371;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v365 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)33; /* 2 */
    v365 = *(Lisp_Object *)((char *)v365 + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = elt(env, 7); /* times */
    if (!(v365 == v364)) goto v371;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v366 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v365 = (Lisp_Object)1; /* 0 */
    v364 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v366 + (CELL-TAG_VECTOR) + ((int32_t)v365/(16/CELL))) = v364;
    goto v372;

v372:
    v364 = stack[-1];
    v364 = add1(v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    stack[-1] = v364;
    goto v369;

v371:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v366 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v365 = (Lisp_Object)1; /* 0 */
    v364 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v366 + (CELL-TAG_VECTOR) + ((int32_t)v365/(16/CELL))) = v364;
    goto v372;

v138:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v365 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)49; /* 3 */
    v365 = *(Lisp_Object *)((char *)v365 + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)-15; /* -1 */
    if (v365 == v364) goto v148;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v365 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)49; /* 3 */
    v365 = *(Lisp_Object *)((char *)v365 + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v364 = (Lisp_Object)-31; /* -2 */
    if (v365 == v364) goto v148;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v366 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v365 = (Lisp_Object)1; /* 0 */
    v364 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v366 + (CELL-TAG_VECTOR) + ((int32_t)v365/(16/CELL))) = v364;
    goto v52;

v52:
    v364 = stack[-1];
    v364 = add1(v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    stack[-1] = v364;
    goto v139;

v148:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v365 = qvalue(elt(env, 5)); /* maxvar */
    v364 = stack[-1];
    v364 = plus2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v366 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v364/(16/CELL)));
    v365 = (Lisp_Object)1; /* 0 */
    v364 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v366 + (CELL-TAG_VECTOR) + ((int32_t)v365/(16/CELL))) = v364;
    goto v52;
/* error exit handlers */
v367:
    popv(3);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip11");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v33;
/* end of prologue */

v373:
    v58 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v58 == nil)) { popv(2); return onevalue(v58); }
    v59 = stack[0];
    v58 = qvalue(elt(env, 2)); /* vdpvars!* */
    v58 = Lmember(nil, v59, v58);
    if (v58 == nil) goto v27;
    v58 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v58 == nil)) goto v43;
    v59 = stack[0];
    v58 = elt(env, 4); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v58 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    fn = elt(env, 7); /* lprie */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    goto v43;

v43:
    v58 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    goto v27;

v27:
    v58 = stack[0];
    if (!consp(v58)) goto v39;
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = CC_f2dip11(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v373;

v39:
    v59 = stack[0];
    v58 = elt(env, 5); /* list */
    if (v59 == v58) goto v133;
    v58 = nil;
    { popv(2); return onevalue(v58); }

v133:
    v58 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v58 == nil)) goto v49;
    v58 = elt(env, 6); /* "groebner: LIST not allowed." */
    fn = elt(env, 7); /* lprie */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    goto v49;

v49:
    v58 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v58 = nil;
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v155:
    popv(2);
    return nil;
}



/* Code for indordl2 */

static Lisp_Object CC_indordl2(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordl2");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v21 = stack[-1];
    v20 = stack[0];
    fn = elt(env, 1); /* indordlp */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v137;
    if (v20 == nil) goto v153;
    v21 = stack[-1];
    v20 = stack[0];
    popv(2);
    return list2(v21, v20);

v153:
    v21 = stack[0];
    v20 = stack[-1];
    popv(2);
    return list2(v21, v20);
/* error exit handlers */
v137:
    popv(2);
    return nil;
}



/* Code for contr2 */

static Lisp_Object MS_CDECL CC_contr2(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v6,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v374, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contr2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v33,v6,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v6;
    stack[-2] = v33;
/* end of prologue */
    stack[-3] = nil;
    goto v27;

v27:
    v374 = stack[-1];
    if (v374 == nil) goto v135;
    v374 = stack[0];
    if (v374 == nil) goto v45;
    v13 = stack[-2];
    v374 = stack[-1];
    v374 = qcar(v374);
    fn = elt(env, 1); /* split!-road */
    v13 = (*qfn2(fn))(qenv(fn), v13, v374);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v374 = stack[-3];
    v374 = cons(v13, v374);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-3] = v374;
    v374 = stack[-1];
    v374 = qcdr(v374);
    stack[-1] = v374;
    goto v27;

v45:
    stack[0] = stack[-3];
    v13 = stack[-2];
    v374 = stack[-1];
    fn = elt(env, 2); /* contr */
    v374 = (*qfn2(fn))(qenv(fn), v13, v374);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    {
        Lisp_Object v131 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v374);
    }

v135:
    stack[-1] = stack[-3];
    v13 = stack[-2];
    v374 = stack[0];
    fn = elt(env, 2); /* contr */
    v374 = (*qfn2(fn))(qenv(fn), v13, v374);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    {
        Lisp_Object v140 = stack[-1];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v140, v374);
    }
/* error exit handlers */
v155:
    popv(5);
    return nil;
}



/* Code for remchkf1 */

static Lisp_Object CC_remchkf1(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v125 = stack[-1];
    fn = elt(env, 3); /* termsf */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[-2] = v125;
    v156 = stack[-1];
    v126 = stack[0];
    v125 = stack[-2];
    fn = elt(env, 4); /* xremf */
    v125 = (*qfnn(fn))(qenv(fn), 3, v156, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[0] = v125;
    v125 = stack[0];
    if (v125 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v125 = stack[0];
    v125 = qcar(v125);
    stack[0] = v125;
    fn = elt(env, 3); /* termsf */
    v126 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v125 = stack[-2];
    v125 = (Lisp_Object)geq2(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v125 = v125 ? lisp_true : nil;
    env = stack[-3];
    if (!(v125 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v125 = qvalue(elt(env, 1)); /* !*trcompact */
    if (v125 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v125 = elt(env, 2); /* "*** Remainder smaller" */
    v125 = Lprinc(nil, v125);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v125 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v49;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for harmonicp */

static Lisp_Object CC_harmonicp(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for harmonicp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v33;
/* end of prologue */
    v36 = elt(env, 1); /* fourier!-angle */
    return get(v34, v36);
}



/* Code for dp_neworder */

static Lisp_Object CC_dp_neworder(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neworder");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v58 = v33;
/* end of prologue */
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v22;
    v58 = stack[-4];
    v58 = qcar(v58);
    stack[0] = v58;
    v58 = stack[0];
    v58 = qcar(v58);
    fn = elt(env, 3); /* mo_neworder */
    v59 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[-2] = v58;
    stack[-3] = v58;
    goto v38;

v38:
    v58 = stack[-4];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v62;
    stack[-1] = stack[-2];
    v58 = stack[-4];
    v58 = qcar(v58);
    stack[0] = v58;
    v58 = stack[0];
    v58 = qcar(v58);
    fn = elt(env, 3); /* mo_neworder */
    v59 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = Lrplacd(nil, stack[-1], v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v38;

v62:
    v58 = stack[-3];
    v59 = v58;
    goto v51;

v51:
    v58 = elt(env, 2); /* dp!=mocompare */
    {
        popv(6);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }

v22:
    v58 = qvalue(elt(env, 1)); /* nil */
    v59 = v58;
    goto v51;
/* error exit handlers */
v60:
    popv(6);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multerm");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v20 = stack[-1];
    v21 = qcdr(v20);
    v20 = stack[0];
    v20 = qcdr(v20);
    fn = elt(env, 1); /* !*multsq */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[-2] = v20;
    v20 = stack[-1];
    v21 = qcar(v20);
    v20 = stack[0];
    v20 = qcar(v20);
    fn = elt(env, 2); /* mulpower */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    {
        Lisp_Object v61 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v61, v20);
    }
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for tayfkern */

static Lisp_Object CC_tayfkern(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayfkern");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v59 = v33;
/* end of prologue */
    v58 = qvalue(elt(env, 1)); /* !*tayinternal!* */
    if (!(v58 == nil)) { popv(3); return onevalue(v59); }
    v306 = elt(env, 2); /* taylor!* */
    v58 = elt(env, 3); /* klist */
    v58 = get(v306, v58);
    env = stack[-2];
    stack[0] = v58;
    v306 = v59;
    v58 = stack[0];
    v58 = Lassoc(nil, v306, v58);
    stack[-1] = v58;
    v58 = stack[-1];
    if (!(v58 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v58 = qvalue(elt(env, 4)); /* nil */
    v58 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[-1] = v58;
    v59 = stack[-1];
    v58 = stack[0];
    fn = elt(env, 7); /* ordad */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[0] = v58;
    v59 = elt(env, 5); /* (taylor!*) */
    v58 = qvalue(elt(env, 6)); /* kprops!* */
    fn = elt(env, 8); /* union */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    qvalue(elt(env, 6)) = v58; /* kprops!* */
    v306 = elt(env, 2); /* taylor!* */
    v59 = elt(env, 3); /* klist */
    v58 = stack[0];
    v58 = Lputprop(nil, 3, v306, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v140;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for mk!+squared!+norm */

static Lisp_Object CC_mkLsquaredLnorm(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+squared+norm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v33;
/* end of prologue */
    v38 = v37;
    {
        fn = elt(env, 1); /* mk!+inner!+product */
        return (*qfn2(fn))(qenv(fn), v38, v37);
    }
}



/* Code for cl_susiinter */

static Lisp_Object MS_CDECL CC_cl_susiinter(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v6,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v378, v379, v380;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiinter");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiinter");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v33,v6,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[-4] = v6;
    v26 = v33;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v26;
    goto v37;

v37:
    v26 = stack[0];
    if (v26 == nil) goto v69;
    v26 = stack[0];
    v26 = qcar(v26);
    v379 = v26;
    v26 = v379;
    v378 = qcar(v26);
    v26 = elt(env, 2); /* ignore */
    if (v378 == v26) goto v65;
    v26 = v379;
    v378 = qcar(v26);
    v26 = elt(env, 4); /* delete */
    if (v378 == v26) goto v30;
    v26 = v379;
    v378 = qcar(v26);
    v26 = elt(env, 5); /* add */
    if (!(v378 == v26)) goto v52;
    v26 = v379;
    v378 = qcdr(v26);
    v26 = stack[-5];
    v26 = cons(v378, v26);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    stack[-5] = v26;
    goto v52;

v52:
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v37;

v30:
    v26 = v379;
    v26 = qcdr(v26);
    if (v26 == nil) goto v128;
    v26 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v26;
    goto v52;

v128:
    v378 = stack[-3];
    v26 = stack[-4];
    fn = elt(env, 6); /* delqip */
    v26 = (*qfn2(fn))(qenv(fn), v378, v26);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    stack[-4] = v26;
    goto v52;

v65:
    v26 = v379;
    v26 = qcdr(v26);
    if (v26 == nil) goto v50;
    v26 = qvalue(elt(env, 3)); /* t */
    stack[-2] = v26;
    v26 = v379;
    v378 = qcdr(v26);
    v26 = stack[-5];
    v26 = cons(v378, v26);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    stack[-5] = v26;
    goto v52;

v50:
    v378 = stack[-3];
    v26 = elt(env, 2); /* ignore */
    fn = elt(env, 7); /* setcdr */
    v26 = (*qfn2(fn))(qenv(fn), v378, v26);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    goto v52;

v69:
    v380 = stack[-4];
    v379 = stack[-5];
    v378 = stack[-2];
    v26 = stack[-1];
    popv(7);
    return list4(v380, v379, v378, v26);
/* error exit handlers */
v102:
    popv(7);
    return nil;
}



/* Code for ratpoly_0 */

static Lisp_Object MS_CDECL CC_ratpoly_0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_0");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v2 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v2);
    }
}



/* Code for minusml */

static Lisp_Object CC_minusml(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusml");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v33;
/* end of prologue */
    v153 = elt(env, 1); /* "<apply><minus/>" */
    fn = elt(env, 4); /* printout */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v150 = qvalue(elt(env, 2)); /* indent */
    v153 = (Lisp_Object)49; /* 3 */
    v153 = plus2(v150, v153);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    qvalue(elt(env, 2)) = v153; /* indent */
    v153 = stack[0];
    fn = elt(env, 5); /* multiminus */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v150 = qvalue(elt(env, 2)); /* indent */
    v153 = (Lisp_Object)49; /* 3 */
    v153 = difference2(v150, v153);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    qvalue(elt(env, 2)) = v153; /* indent */
    v153 = elt(env, 3); /* "</apply>" */
    fn = elt(env, 4); /* printout */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v153 = nil;
    { popv(2); return onevalue(v153); }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v33;
/* end of prologue */
    stack[-1] = nil;
    goto v82;

v82:
    v40 = stack[0];
    if (v40 == nil) goto v27;
    v40 = stack[0];
    v39 = qcar(v40);
    v40 = stack[-1];
    v40 = cons(v39, v40);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    stack[-1] = v40;
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[0] = v40;
    goto v82;

v27:
    v40 = (Lisp_Object)-159999; /* -10000 */
    v39 = v40;
    goto v35;

v35:
    v40 = stack[-1];
    if (v40 == nil) { popv(3); return onevalue(v39); }
    v40 = stack[-1];
    v40 = qcar(v40);
    fn = elt(env, 1); /* max */
    v40 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v39 = v40;
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-1] = v40;
    goto v35;
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for remzzzz */

static Lisp_Object CC_remzzzz(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remzzzz");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v42 = nil;
    goto v82;

v82:
    v156 = stack[-1];
    if (v156 == nil) goto v38;
    v156 = stack[-1];
    v156 = qcar(v156);
    v41 = qcar(v156);
    v156 = stack[0];
    v156 = qcar(v156);
    v156 = qcar(v156);
    if (equal(v41, v156)) goto v47;
    v156 = stack[0];
    v156 = qcar(v156);
    v41 = v42;
    v156 = cons(v156, v41);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v42 = v156;
    v156 = stack[0];
    v156 = qcdr(v156);
    stack[0] = v156;
    goto v82;

v47:
    v156 = stack[-1];
    v156 = qcdr(v156);
    stack[-1] = v156;
    v156 = stack[0];
    v156 = qcdr(v156);
    stack[0] = v156;
    goto v82;

v38:
    v41 = v42;
    v156 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v41, v156);
    }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for dipequal */

static Lisp_Object CC_dipequal(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */

v51:
    v16 = stack[-1];
    if (v16 == nil) goto v35;
    v16 = stack[0];
    if (v16 == nil) goto v38;
    v16 = stack[-1];
    v16 = qcdr(v16);
    v57 = qcar(v16);
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    if (equal(v57, v16)) goto v61;
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v16); }

v61:
    v16 = stack[-1];
    v57 = qcar(v16);
    v16 = stack[0];
    v16 = qcar(v16);
    fn = elt(env, 2); /* evequal */
    v16 = (*qfn2(fn))(qenv(fn), v57, v16);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    if (v16 == nil) goto v49;
    v16 = stack[-1];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    stack[-1] = v16;
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    stack[0] = v16;
    goto v51;

v49:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v16); }

v38:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v16); }

v35:
    v16 = stack[0];
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v16); }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for evinsert */

static Lisp_Object MS_CDECL CC_evinsert(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v6,
                         Lisp_Object v3, Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v57, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "evinsert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinsert");
#endif
    if (stack >= stacklimit)
    {
        push4(v2,v3,v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v33,v6,v3,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v3;
    stack[-2] = v6;
    stack[-3] = v33;
/* end of prologue */
    v30 = nil;
    goto v35;

v35:
    v16 = stack[-3];
    if (v16 == nil) goto v36;
    v16 = stack[0];
    if (v16 == nil) goto v36;
    v16 = stack[0];
    v57 = qcar(v16);
    v16 = stack[-2];
    if (equal(v57, v16)) goto v108;
    v16 = stack[-3];
    v16 = qcar(v16);
    v57 = v30;
    v16 = cons(v16, v57);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    v30 = v16;
    v16 = stack[-3];
    v16 = qcdr(v16);
    stack[-3] = v16;
    v16 = stack[0];
    v16 = qcdr(v16);
    stack[0] = v16;
    goto v35;

v108:
    stack[0] = v30;
    v57 = stack[-1];
    v16 = stack[-3];
    v16 = qcdr(v16);
    v16 = cons(v57, v16);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    {
        Lisp_Object v14 = stack[0];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v14, v16);
    }

v36:
    v16 = v30;
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v13:
    popv(5);
    return nil;
}



/* Code for getrlist */

static Lisp_Object CC_getrlist(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v30, v305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrlist");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v305 = v33;
/* end of prologue */
    v30 = v305;
    v57 = elt(env, 1); /* list */
    if (!consp(v30)) goto v109;
    v30 = qcar(v30);
    if (!(v30 == v57)) goto v109;
    v57 = v305;
    v57 = qcdr(v57);
    { popv(1); return onevalue(v57); }

v109:
    v30 = v305;
    v57 = elt(env, 2); /* !*sq */
    if (!consp(v30)) goto v151;
    v30 = qcar(v30);
    if (!(v30 == v57)) goto v151;
    v57 = v305;
    v57 = qcdr(v57);
    v57 = qcar(v57);
    v57 = qcar(v57);
    if (v57 == nil) goto v138;
    v57 = v305;
    v57 = qcdr(v57);
    v30 = qcar(v57);
    v57 = elt(env, 3); /* prepf */
    fn = elt(env, 5); /* sqform */
    v57 = (*qfn2(fn))(qenv(fn), v30, v57);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[0];
    goto v137;

v137:
    v30 = v57;
    goto v43;

v43:
    v57 = elt(env, 4); /* "list" */
    {
        popv(1);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v30, v57);
    }

v138:
    v57 = (Lisp_Object)1; /* 0 */
    goto v137;

v151:
    v57 = v305;
    v30 = v57;
    goto v43;
/* error exit handlers */
v122:
    popv(1);
    return nil;
}



/* Code for reduce */

static Lisp_Object CC_reduce(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    v136 = v33;
/* end of prologue */
    stack[0] = v136;
    v136 = qvalue(elt(env, 1)); /* !*yyy */
    if (v136 == nil) goto v134;
    v151 = stack[0];
    v136 = stack[-1];
    fn = elt(env, 3); /* reduce!-ratios */
    v136 = (*qfn2(fn))(qenv(fn), v151, v136);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[0] = v136;
    goto v134;

v134:
    v136 = stack[-1];
    fn = elt(env, 4); /* set!-weights */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v136;
    v136 = qvalue(elt(env, 2)); /* !*xxx */
    if (v136 == nil) goto v52;
    v152 = stack[0];
    v151 = stack[-1];
    v136 = stack[-2];
    fn = elt(env, 5); /* reduce!-columns */
    v136 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v136);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[0] = v136;
    goto v52;

v52:
    v136 = qvalue(elt(env, 2)); /* !*xxx */
    if (v136 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v152 = stack[0];
    v151 = stack[-1];
    v136 = stack[-2];
    fn = elt(env, 6); /* reduce!-weights */
    v136 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v136);
    nil = C_nil;
    if (exception_pending()) goto v30;
    stack[0] = v136;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for sqprint */

static Lisp_Object CC_sqprint(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v291, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprint");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v33;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*prin!# */
    qvalue(elt(env, 1)) = nil; /* !*prin!# */
    v288 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v288; /* !*prin!# */
    v288 = qvalue(elt(env, 3)); /* orig!* */
    stack[-1] = v288;
    v288 = qvalue(elt(env, 4)); /* !*nat */
    if (v288 == nil) goto v34;
    v291 = qvalue(elt(env, 5)); /* posn!* */
    v288 = (Lisp_Object)321; /* 20 */
    v288 = (Lisp_Object)lessp2(v291, v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v288 = v288 ? lisp_true : nil;
    env = stack[-4];
    if (v288 == nil) goto v34;
    v288 = qvalue(elt(env, 5)); /* posn!* */
    qvalue(elt(env, 3)) = v288; /* orig!* */
    goto v34;

v34:
    v288 = qvalue(elt(env, 6)); /* !*pri */
    if (!(v288 == nil)) goto v21;
    v288 = qvalue(elt(env, 7)); /* wtl!* */
    if (!(v288 == nil)) goto v21;
    v288 = stack[-2];
    v291 = qcdr(v288);
    v288 = (Lisp_Object)17; /* 1 */
    if (v291 == v288) goto v384;
    v288 = stack[-2];
    v288 = qcar(v288);
    if (!consp(v288)) goto v145;
    v288 = stack[-2];
    v288 = qcar(v288);
    v288 = qcar(v288);
    if (!consp(v288)) goto v145;
    v288 = stack[-2];
    v288 = qcar(v288);
    v288 = qcdr(v288);
    goto v144;

v144:
    stack[-3] = v288;
    v288 = stack[-3];
    if (v288 == nil) goto v103;
    v288 = elt(env, 14); /* "(" */
    fn = elt(env, 17); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v103;

v103:
    v288 = stack[-2];
    v288 = qcar(v288);
    fn = elt(env, 18); /* xprinf2 */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v288 = stack[-3];
    if (v288 == nil) goto v362;
    v288 = elt(env, 15); /* ")" */
    fn = elt(env, 17); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v362;

v362:
    v288 = elt(env, 16); /* " / " */
    fn = elt(env, 17); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v288 = stack[-2];
    v288 = qcdr(v288);
    if (!consp(v288)) goto v102;
    v288 = stack[-2];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    if (!consp(v288)) goto v102;
    v288 = stack[-2];
    v288 = qcdr(v288);
    v288 = qcdr(v288);
    if (!(v288 == nil)) goto v101;
    v288 = stack[-2];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    v291 = qcdr(v288);
    v288 = (Lisp_Object)17; /* 1 */
    v288 = Lneq(nil, v291, v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v101;

v101:
    stack[-3] = v288;
    v288 = stack[-3];
    if (v288 == nil) goto v385;
    v288 = elt(env, 14); /* "(" */
    fn = elt(env, 17); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v385;

v385:
    v288 = stack[-2];
    v288 = qcdr(v288);
    fn = elt(env, 18); /* xprinf2 */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v288 = stack[-3];
    if (v288 == nil) goto v153;
    v288 = elt(env, 15); /* ")" */
    fn = elt(env, 17); /* prin2!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v153;

v153:
    v288 = stack[-1];
    qvalue(elt(env, 3)) = v288; /* orig!* */
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    { popv(5); return onevalue(v288); }

v102:
    v288 = qvalue(elt(env, 13)); /* nil */
    goto v101;

v145:
    v288 = qvalue(elt(env, 13)); /* nil */
    goto v144;

v384:
    v288 = stack[-2];
    v288 = qcar(v288);
    fn = elt(env, 18); /* xprinf2 */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v153;

v21:
    v288 = stack[-2];
    fn = elt(env, 19); /* sqhorner!* */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    fn = elt(env, 20); /* prepsq!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v291 = qvalue(elt(env, 8)); /* ordl!* */
    v288 = qvalue(elt(env, 9)); /* factors!* */
    v288 = Lappend(nil, v291, v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    fn = elt(env, 21); /* prepreform1 */
    v288 = (*qfn2(fn))(qenv(fn), stack[-2], v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v291 = qvalue(elt(env, 10)); /* outputhandler!* */
    if (v291 == nil) goto v49;
    v290 = qvalue(elt(env, 10)); /* outputhandler!* */
    v291 = elt(env, 11); /* maprin */
    v288 = Lapply2(nil, 3, v290, v291, v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v153;

v49:
    v291 = qvalue(elt(env, 12)); /* overflowed!* */
    if (!(v291 == nil)) goto v153;
    v291 = v288;
    v288 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 22); /* maprint */
    v288 = (*qfn2(fn))(qenv(fn), v291, v288);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    goto v153;
/* error exit handlers */
v91:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*prin!# */
    popv(5);
    return nil;
}



/* Code for skp_ordp */

static Lisp_Object CC_skp_ordp(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v149 = v6;
    v22 = v33;
/* end of prologue */
    v23 = qcar(v22);
    v22 = qcar(v149);
    v149 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v23, v22, v149);
    }
}



/* Code for lpos */

static Lisp_Object CC_lpos(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v109, v108, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpos");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v6;
    v44 = v33;
/* end of prologue */
    v109 = v44;
    v28 = v108;
    v28 = qcar(v28);
    if (v109 == v28) goto v51;
    v28 = v44;
    v109 = v108;
    v109 = qcdr(v109);
    v28 = CC_lpos(env, v28, v109);
    errexit();
    return add1(v28);

v51:
    v28 = (Lisp_Object)17; /* 1 */
    return onevalue(v28);
}



/* Code for nonlnr */

static Lisp_Object CC_nonlnr(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnr");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */

v373:
    v303 = stack[-1];
    if (!consp(v303)) goto v51;
    v303 = stack[-1];
    v303 = qcar(v303);
    if (!consp(v303)) goto v51;
    v303 = stack[-1];
    v303 = qcar(v303);
    v303 = qcar(v303);
    v31 = qcar(v303);
    v303 = stack[0];
    v303 = Lmember(nil, v31, v303);
    if (v303 == nil) goto v13;
    v303 = stack[-1];
    v303 = qcar(v303);
    v303 = qcar(v303);
    v31 = qcdr(v303);
    v303 = (Lisp_Object)17; /* 1 */
    v303 = (Lisp_Object)greaterp2(v31, v303);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v303 = v303 ? lisp_true : nil;
    env = stack[-2];
    if (!(v303 == nil)) { popv(3); return onevalue(v303); }
    v303 = stack[-1];
    v303 = qcar(v303);
    v31 = qcdr(v303);
    v303 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v303 = (*qfn2(fn))(qenv(fn), v31, v303);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v303 = (v303 == nil ? lisp_true : nil);
    if (!(v303 == nil)) { popv(3); return onevalue(v303); }
    v303 = stack[-1];
    v31 = qcdr(v303);
    v303 = stack[0];
    stack[-1] = v31;
    stack[0] = v303;
    goto v373;

v13:
    v303 = stack[-1];
    v303 = qcar(v303);
    v303 = qcar(v303);
    v31 = qcar(v303);
    v303 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v303 = (*qfn2(fn))(qenv(fn), v31, v303);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v303 = (v303 == nil ? lisp_true : nil);
    if (!(v303 == nil)) { popv(3); return onevalue(v303); }
    v303 = stack[-1];
    v303 = qcar(v303);
    v31 = qcdr(v303);
    v303 = stack[0];
    v303 = CC_nonlnr(env, v31, v303);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    if (!(v303 == nil)) { popv(3); return onevalue(v303); }
    v303 = stack[-1];
    v31 = qcdr(v303);
    v303 = stack[0];
    stack[-1] = v31;
    stack[0] = v303;
    goto v373;

v51:
    v303 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v303); }
/* error exit handlers */
v56:
    popv(3);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v140 = v33;
/* end of prologue */
    stack[-4] = v140;
    v140 = stack[-4];
    if (v140 == nil) goto v36;
    v140 = stack[-4];
    v140 = qcar(v140);
    v141 = v140;
    v140 = v141;
    stack[0] = qcar(v140);
    v140 = v141;
    v141 = qcdr(v140);
    v140 = qvalue(elt(env, 1)); /* nil */
    v140 = Lappend(nil, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = cons(stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = ncons(v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    stack[-2] = v140;
    stack[-3] = v140;
    goto v27;

v27:
    v140 = stack[-4];
    v140 = qcdr(v140);
    stack[-4] = v140;
    v140 = stack[-4];
    if (v140 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v140 = stack[-4];
    v140 = qcar(v140);
    v141 = v140;
    v140 = v141;
    stack[0] = qcar(v140);
    v140 = v141;
    v141 = qcdr(v140);
    v140 = qvalue(elt(env, 1)); /* nil */
    v140 = Lappend(nil, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = cons(stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = ncons(v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = Lrplacd(nil, stack[-1], v140);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v140 = stack[-2];
    v140 = qcdr(v140);
    stack[-2] = v140;
    goto v27;

v36:
    v140 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v140); }
/* error exit handlers */
v67:
    popv(6);
    return nil;
}



/* Code for mk!+conjugate!+sq */

static Lisp_Object CC_mkLconjugateLsq(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v33;
/* end of prologue */
    {
        fn = elt(env, 1); /* conjsq */
        return (*qfn1(fn))(qenv(fn), v82);
    }
}



/* Code for multiminus */

static Lisp_Object CC_multiminus(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiminus");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v33;
/* end of prologue */
    v29 = stack[0];
    v29 = qcar(v29);
    fn = elt(env, 1); /* expression */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-1];
    v29 = stack[0];
    v52 = Llength(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-1];
    v29 = (Lisp_Object)33; /* 2 */
    if (!(v52 == v29)) goto v35;
    v29 = stack[0];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    fn = elt(env, 1); /* expression */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v153;
    goto v35;

v35:
    v29 = nil;
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v153:
    popv(2);
    return nil;
}



/* Code for close_forall */

static Lisp_Object MS_CDECL CC_close_forall(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "close_forall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for close_forall");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* flagg */
    v149 = (Lisp_Object)17; /* 1 */
    if (!(v22 == v149)) goto v19;
    v149 = elt(env, 2); /* "</apply>" */
    fn = elt(env, 3); /* printout */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    errexit();
    goto v19;

v19:
    v149 = nil;
    return onevalue(v149);
}



/* Code for degreef */

static Lisp_Object CC_degreef(Lisp_Object env,
                         Lisp_Object v33, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degreef");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v33,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v33;
/* end of prologue */
    v136 = stack[-1];
    if (!consp(v136)) goto v51;
    v136 = stack[-1];
    v136 = qcar(v136);
    if (!consp(v136)) goto v51;
    v136 = stack[-1];
    v136 = qcar(v136);
    v136 = qcar(v136);
    v151 = qcar(v136);
    v136 = stack[0];
    if (v151 == v136) goto v38;
    v136 = stack[-1];
    v136 = qcar(v136);
    v151 = qcdr(v136);
    v136 = stack[0];
    stack[-2] = CC_degreef(env, v151, v136);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    v136 = stack[-1];
    v151 = qcdr(v136);
    v136 = stack[0];
    v136 = CC_degreef(env, v151, v136);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    {
        Lisp_Object v30 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v30, v136);
    }

v38:
    v136 = stack[-1];
    v136 = qcar(v136);
    v136 = qcar(v136);
    v136 = qcdr(v136);
    { popv(4); return onevalue(v136); }

v51:
    v136 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v136); }
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for a2vdp */

static Lisp_Object CC_a2vdp(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v140, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2vdp");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v141 = v33;
/* end of prologue */
    v140 = v141;
    v131 = (Lisp_Object)1; /* 0 */
    if (v140 == v131) goto v22;
    v131 = v141;
    if (v131 == nil) goto v22;
    v131 = v141;
    fn = elt(env, 3); /* a2dip */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v140 = v131;
    stack[-2] = elt(env, 1); /* vdp */
    v131 = v140;
    stack[-1] = qcar(v131);
    v131 = v140;
    v131 = qcdr(v131);
    stack[0] = qcar(v131);
    v131 = qvalue(elt(env, 2)); /* nil */
    v131 = list2(v140, v131);
    nil = C_nil;
    if (exception_pending()) goto v124;
    {
        Lisp_Object v142 = stack[-2];
        Lisp_Object v67 = stack[-1];
        Lisp_Object v128 = stack[0];
        popv(4);
        return list3star(v142, v67, v128, v131);
    }

v22:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v140 = qvalue(elt(env, 2)); /* nil */
    v131 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v140, v131);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v140 = qvalue(elt(env, 2)); /* nil */
    v131 = qvalue(elt(env, 2)); /* nil */
    v131 = list2(v140, v131);
    nil = C_nil;
    if (exception_pending()) goto v124;
    {
        Lisp_Object v129 = stack[-2];
        Lisp_Object v363 = stack[-1];
        Lisp_Object v9 = stack[0];
        popv(4);
        return list3star(v129, v363, v9, v131);
    }
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v40 = v33;
/* end of prologue */
    v17 = v40;
    v39 = elt(env, 1); /* times */
    if (!consp(v17)) goto v127;
    v17 = qcar(v17);
    if (!(v17 == v39)) goto v127;
    v39 = v40;
    v39 = qcdr(v39);
    v17 = qcar(v39);
    v39 = v40;
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v40 = qcdr(v40);
    v40 = qcdr(v40);
    v40 = qcdr(v40);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v17, v39, v40);
    }

v127:
    v39 = (Lisp_Object)17; /* 1 */
    return cons(v39, v40);
}



/* Code for apply_e */

static Lisp_Object CC_apply_e(Lisp_Object env,
                         Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for apply_e");
#endif
    if (stack >= stacklimit)
    {
        push(v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v28 = v33;
/* end of prologue */
    v109 = v28;
    v28 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* apply */
    v109 = (*qfn2(fn))(qenv(fn), v109, v28);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    v28 = v109;
    v109 = integerp(v109);
    if (!(v109 == nil)) { popv(1); return onevalue(v28); }
    v28 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v28 == nil)) goto v43;
    v28 = elt(env, 3); /* "randpoly expons function must return an integer" 
*/
    fn = elt(env, 5); /* lprie */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    goto v43;

v43:
    v28 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v28 = nil;
    { popv(1); return onevalue(v28); }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



setup_type const u30_setup[] =
{
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"toolongexpp",             CC_toolongexpp, too_many_1,    wrong_no_1},
    {"calc_coeff",              too_few_2,      CC_calc_coeff, wrong_no_2},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"procstat1",               CC_procstat1,   too_many_1,    wrong_no_1},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"red_tailreddriver",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_tailreddriver},
    {"xnsiz",                   CC_xnsiz,       too_many_1,    wrong_no_1},
    {"component_action",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_component_action},
    {"ofsf_at2ir",              too_few_2,      CC_ofsf_at2ir, wrong_no_2},
    {"testord",                 too_few_2,      CC_testord,    wrong_no_2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"aex_0",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_0},
    {"bvarrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bvarrd},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"contr2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"tayfkern",                CC_tayfkern,    too_many_1,    wrong_no_1},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,too_many_1, wrong_no_1},
    {"cl_susiinter",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiinter},
    {"ratpoly_0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_0},
    {"minusml",                 CC_minusml,     too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"remzzzz",                 too_few_2,      CC_remzzzz,    wrong_no_2},
    {"dipequal",                too_few_2,      CC_dipequal,   wrong_no_2},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"sqprint",                 CC_sqprint,     too_many_1,    wrong_no_1},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"nonlnr",                  too_few_2,      CC_nonlnr,     wrong_no_2},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"multiminus",              CC_multiminus,  too_many_1,    wrong_no_1},
    {"close_forall",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_close_forall},
    {"degreef",                 too_few_2,      CC_degreef,    wrong_no_2},
    {"a2vdp",                   CC_a2vdp,       too_many_1,    wrong_no_1},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"apply_e",                 CC_apply_e,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u30", (two_args *)"3551 9689844 9643999", 0}
};

/* end of generated code */
