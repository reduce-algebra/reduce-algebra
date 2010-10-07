
/* $destdir\u37.c        Machine generated C code */

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


/* Code for scar */

static Lisp_Object CC_scar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scar");
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

v10:
    v8 = stack[0];
    if (!consp(v8)) goto v11;
    v9 = stack[-1];
    v8 = stack[0];
    v8 = qcar(v8);
    if (equal(v9, v8)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v9 = stack[-1];
    v8 = stack[0];
    v8 = qcar(v8);
    v8 = CC_scar(env, v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-2];
    if (!(v8 == nil)) { popv(3); return onevalue(v8); }
    v9 = stack[-1];
    v8 = stack[0];
    v8 = qcdr(v8);
    stack[-1] = v9;
    stack[0] = v8;
    goto v10;

v11:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v8); }
/* error exit handlers */
v12:
    popv(3);
    return nil;
}



/* Code for spmatlength */

static Lisp_Object CC_spmatlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmatlength");
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
    v27 = v0;
/* end of prologue */
    v25 = v27;
    v25 = Lconsp(nil, v25);
    env = stack[0];
    if (v25 == nil) goto v4;
    v25 = v27;
    goto v29;

v29:
    v26 = v25;
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcar(v26);
    v26 = qcdr(v26);
    v28 = v26;
    v26 = v25;
    v25 = elt(env, 2); /* sparsemat */
    if (!consp(v26)) goto v8;
    v26 = qcar(v26);
    if (!(v26 == v25)) goto v8;
    v26 = elt(env, 7); /* list */
    v25 = v28;
    v25 = qcar(v25);
    v27 = v28;
    v27 = qcdr(v27);
    v27 = qcar(v27);
    popv(1);
    return list3(v26, v25, v27);

v8:
    v26 = elt(env, 3); /* "Matrix" */
    v25 = elt(env, 4); /* "not set" */
    v25 = list3(v26, v27, v25);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    v26 = v25;
    v25 = v26;
    qvalue(elt(env, 5)) = v25; /* errmsg!* */
    v25 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v25 == nil)) goto v31;
    v25 = v26;
    fn = elt(env, 8); /* lprie */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    goto v31;

v31:
    v25 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v25 = nil;
    { popv(1); return onevalue(v25); }

v4:
    v26 = v27;
    v25 = elt(env, 1); /* avalue */
    v25 = get(v26, v25);
    env = stack[0];
    v25 = qcdr(v25);
    v25 = qcar(v25);
    goto v29;
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for sroot1 */

static Lisp_Object CC_sroot1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroot1");
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
    stack[0] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* freevars */
    qvalue(elt(env, 1)) = nil; /* freevars */
    stack[-1] = qvalue(elt(env, 2)); /* substitution */
    qvalue(elt(env, 2)) = nil; /* substitution */
    v50 = qvalue(elt(env, 3)); /* rpt */
    v49 = elt(env, 4); /* inf */
    if (v50 == v49) goto v53;
    v50 = qvalue(elt(env, 3)); /* rpt */
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)lesseq2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (!(v49 == nil)) goto v55;

v53:
    v49 = stack[-3];
    if (!consp(v49)) goto v55;
    v49 = stack[-3];
    v50 = qcar(v49);
    v49 = stack[0];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v49 = qcar(v49);
    if (!(equal(v50, v49))) goto v55;
    v49 = stack[0];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    fn = elt(env, 12); /* findnewvars */
    v50 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 13); /* union */
    v49 = (*qfn2(fn))(qenv(fn), v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    qvalue(elt(env, 1)) = v49; /* freevars */
    v49 = stack[0];
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = qcar(v49);
    qvalue(elt(env, 2)) = v49; /* substitution */
    v49 = qvalue(elt(env, 1)); /* freevars */
    stack[-4] = v49;
    goto v56;

v56:
    v49 = stack[-4];
    if (v49 == nil) goto v57;
    v49 = stack[-4];
    v49 = qcar(v49);
    fn = elt(env, 14); /* newenv */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = stack[-4];
    v49 = qcdr(v49);
    stack[-4] = v49;
    goto v56;

v57:
    v49 = qvalue(elt(env, 6)); /* !*trpm */
    if (v49 == nil) goto v58;
    v49 = elt(env, 7); /* "Trying rule  " */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = stack[0];
    fn = elt(env, 15); /* rprint */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = elt(env, 8); /* "against      " */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = stack[-3];
    fn = elt(env, 15); /* rprint */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v58;

v58:
    v49 = stack[0];
    v49 = qcdr(v49);
    v52 = qcar(v49);
    v51 = stack[-3];
    v50 = qvalue(elt(env, 9)); /* t */
    v49 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* amatch */
    v49 = (*qfnn(fn))(qenv(fn), 4, v52, v51, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-4] = v49;
    v49 = qvalue(elt(env, 6)); /* !*trpm */
    if (v49 == nil) goto v59;
    v49 = stack[-4];
    if (v49 == nil) goto v60;
    v49 = elt(env, 10); /* "producing    " */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-4] = v49;
    fn = elt(env, 15); /* rprint */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v61;

v61:
    v49 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v59;

v59:
    v49 = qvalue(elt(env, 1)); /* freevars */
    stack[0] = v49;
    goto v62;

v62:
    v49 = stack[0];
    if (v49 == nil) goto v63;
    v49 = stack[0];
    v49 = qcar(v49);
    fn = elt(env, 18); /* restorenv */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v62;

v63:
    v49 = stack[-4];
    if (v49 == nil) goto v64;
    v50 = qvalue(elt(env, 3)); /* rpt */
    v49 = elt(env, 4); /* inf */
    if (v50 == v49) goto v65;
    v49 = qvalue(elt(env, 3)); /* rpt */
    v49 = sub1(v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    qvalue(elt(env, 3)) = v49; /* rpt */
    goto v65;

v65:
    v49 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v29;

v29:
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    { popv(6); return onevalue(v49); }

v64:
    v49 = stack[-3];
    goto v29;

v60:
    v49 = elt(env, 11); /* "failed" */
    v49 = Lprinc(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v49 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v61;

v55:
    v49 = stack[-3];
    goto v29;
/* error exit handlers */
v54:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    popv(6);
    return nil;
}



/* Code for precision1 */

static Lisp_Object CC_precision1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precision1");
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
    v91 = v1;
    stack[0] = v0;
/* end of prologue */
    v52 = stack[0];
    v51 = (Lisp_Object)1; /* 0 */
    if (v52 == v51) goto v92;
    v51 = v91;
    if (v51 == nil) goto v48;
    v52 = qvalue(elt(env, 2)); /* !*sqvar!* */
    v51 = qvalue(elt(env, 3)); /* nil */
    v51 = Lrplaca(nil, v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = qvalue(elt(env, 4)); /* t */
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 2)) = v51; /* !*sqvar!* */
    v51 = qvalue(elt(env, 3)); /* nil */
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 5)) = v51; /* alglist!* */
    goto v48;

v48:
    v51 = qvalue(elt(env, 1)); /* !!rdprec */
    stack[-3] = v51;
    v51 = qvalue(elt(env, 6)); /* !*roundbf */
    if (v51 == nil) goto v17;
    v51 = stack[0];
    v52 = v51;
    goto v93;

v93:
    qvalue(elt(env, 1)) = v52; /* !!rdprec */
    v51 = (Lisp_Object)33; /* 2 */
    v51 = plus2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 8)) = v51; /* !:prec!: */
    v51 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    if (v51 == nil) goto v94;
    v52 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    v51 = (Lisp_Object)33; /* 2 */
    v51 = plus2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = (Lisp_Object)lessp2(stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v51 = v51 ? lisp_true : nil;
    env = stack[-4];
    if (v51 == nil) goto v94;
    v51 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 9)) = v51; /* !:print!-prec!: */
    goto v94;

v94:
    v52 = qvalue(elt(env, 8)); /* !:prec!: */
    v51 = qvalue(elt(env, 10)); /* log2of10 */
    v51 = times2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    fn = elt(env, 18); /* ceiling */
    v52 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = (Lisp_Object)49; /* 3 */
    v51 = plus2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 11)) = v51; /* !:bprec!: */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v52 = qvalue(elt(env, 11)); /* !:bprec!: */
    v51 = (Lisp_Object)33; /* 2 */
    v51 = quot2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = negate(v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = list2star(stack[-1], stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 13)) = v51; /* epsqrt!* */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v52 = (Lisp_Object)97; /* 6 */
    v51 = qvalue(elt(env, 11)); /* !:bprec!: */
    v51 = difference2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = list2star(stack[-1], stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 14)) = v51; /* rd!-tolerance!* */
    stack[-2] = elt(env, 12); /* !:rd!: */
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)33; /* 2 */
    v52 = (Lisp_Object)97; /* 6 */
    v51 = qvalue(elt(env, 11)); /* !:bprec!: */
    v51 = difference2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = times2(stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v51 = list2star(stack[-2], stack[-1], v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    qvalue(elt(env, 15)) = v51; /* cr!-tolerance!* */
    v52 = qvalue(elt(env, 1)); /* !!rdprec */
    v51 = qvalue(elt(env, 16)); /* !!flprec */
    v51 = (Lisp_Object)greaterp2(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v51 = v51 ? lisp_true : nil;
    env = stack[-4];
    if (!(v51 == nil)) goto v95;
    v51 = qvalue(elt(env, 6)); /* !*roundbf */
    goto v95;

v95:
    qvalue(elt(env, 17)) = v51; /* !*!*roundbf */
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v17:
    v52 = stack[0];
    v51 = qvalue(elt(env, 7)); /* minprec!# */
    fn = elt(env, 19); /* max */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v52 = v51;
    goto v93;

v92:
    v51 = qvalue(elt(env, 1)); /* !!rdprec */
    { popv(5); return onevalue(v51); }
/* error exit handlers */
v54:
    popv(5);
    return nil;
}



/* Code for r2oreaction */

static Lisp_Object MS_CDECL CC_r2oreaction(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "r2oreaction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oreaction");
#endif
    if (stack >= stacklimit)
    {
        push4(v22,v16,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v16,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v22;
    v95 = v16;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = v95;
    v95 = stack[-1];
    stack[-2] = v95;
    goto v112;

v112:
    v95 = stack[-2];
    if (v95 == nil) goto v53;
    v95 = stack[-2];
    v95 = qcar(v95);
    stack[0] = elt(env, 2); /* times */
    stack[-3] = stack[-6];
    v36 = elt(env, 3); /* expt */
    v35 = v95;
    v35 = qcdr(v35);
    v95 = qcar(v95);
    v95 = list3(v36, v35, v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = list3(stack[0], stack[-3], v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    fn = elt(env, 6); /* aeval */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    stack[-6] = v95;
    v95 = stack[-2];
    v95 = qcdr(v95);
    stack[-2] = v95;
    goto v112;

v53:
    v95 = stack[-1];
    stack[-3] = v95;
    goto v17;

v17:
    v95 = stack[-3];
    if (v95 == nil) goto v19;
    v95 = stack[-3];
    v95 = qcar(v95);
    v35 = v95;
    v36 = qcdr(v35);
    v35 = stack[-4];
    v35 = Lassoc(nil, v36, v35);
    stack[-2] = v35;
    stack[-1] = elt(env, 4); /* difference */
    stack[0] = qcdr(v35);
    v36 = elt(env, 2); /* times */
    v35 = stack[-6];
    v95 = qcar(v95);
    v95 = list3(v36, v35, v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = list3(stack[-1], stack[0], v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = Lrplacd(nil, stack[-2], v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = stack[-3];
    v95 = qcdr(v95);
    stack[-3] = v95;
    goto v17;

v19:
    v95 = stack[-5];
    stack[-3] = v95;
    goto v80;

v80:
    v95 = stack[-3];
    if (v95 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v95 = stack[-3];
    v95 = qcar(v95);
    v35 = v95;
    v36 = qcdr(v35);
    v35 = stack[-4];
    v35 = Lassoc(nil, v36, v35);
    stack[-2] = v35;
    stack[-1] = elt(env, 5); /* plus */
    stack[0] = qcdr(v35);
    v36 = elt(env, 2); /* times */
    v35 = stack[-6];
    v95 = qcar(v95);
    v95 = list3(v36, v35, v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = list3(stack[-1], stack[0], v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = Lrplacd(nil, stack[-2], v95);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-7];
    v95 = stack[-3];
    v95 = qcdr(v95);
    stack[-3] = v95;
    goto v80;
/* error exit handlers */
v49:
    popv(8);
    return nil;
}



/* Code for cvitimes2 */

static Lisp_Object CC_cvitimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v31, v88, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvitimes2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v1;
    v42 = v0;
/* end of prologue */
    v31 = v42;
    v116 = (Lisp_Object)1; /* 0 */
    if (v31 == v116) goto v11;
    v31 = v88;
    v116 = (Lisp_Object)1; /* 0 */
    if (v31 == v116) goto v11;
    v31 = v42;
    v116 = (Lisp_Object)17; /* 1 */
    if (v31 == v116) return onevalue(v88);
    v31 = v88;
    v116 = (Lisp_Object)17; /* 1 */
    if (v31 == v116) return onevalue(v42);
    v116 = elt(env, 1); /* times */
    v31 = v42;
    return list3(v116, v31, v88);

v11:
    v116 = (Lisp_Object)1; /* 0 */
    return onevalue(v116);
}



/* Code for mapcarcar */

static Lisp_Object CC_mapcarcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcarcar");
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
    v9 = v0;
/* end of prologue */
    stack[-3] = v9;
    v9 = stack[-3];
    if (v9 == nil) goto v118;
    v9 = stack[-3];
    v9 = qcar(v9);
    v9 = qcar(v9);
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    stack[-1] = v9;
    stack[-2] = v9;
    goto v29;

v29:
    v9 = stack[-3];
    v9 = qcdr(v9);
    stack[-3] = v9;
    v9 = stack[-3];
    if (v9 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v9 = stack[-3];
    v9 = qcar(v9);
    v9 = qcar(v9);
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v9 = Lrplacd(nil, stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    goto v29;

v118:
    v9 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v9); }
/* error exit handlers */
v119:
    popv(5);
    return nil;
}



/* Code for reduce!-weights */

static Lisp_Object MS_CDECL CC_reduceKweights(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-weights");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-weights");
#endif
    if (stack >= stacklimit)
    {
        push3(v16,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v16;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v103 = stack[-5];
    v125 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    stack[-2] = v125;
    goto v23;

v23:
    v103 = stack[-5];
    v125 = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!+ */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    stack[-1] = v125;
    v103 = stack[-1];
    v125 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    stack[0] = v125;
    v103 = stack[0];
    v125 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    if (v125 == nil) goto v126;
    v125 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v125;
    v125 = stack[-1];
    stack[-5] = v125;
    v125 = stack[0];
    stack[-2] = v125;
    goto v23;

v126:
    v125 = stack[-6];
    if (!(v125 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v31:
    v103 = stack[-5];
    v125 = stack[-4];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    stack[-1] = v125;
    v103 = stack[-1];
    v125 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    stack[0] = v125;
    v103 = stack[0];
    v125 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v125 = (*qfn2(fn))(qenv(fn), v103, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-7];
    if (v125 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v125 = stack[-1];
    stack[-5] = v125;
    v125 = stack[0];
    stack[-2] = v125;
    goto v31;
/* error exit handlers */
v85:
    popv(8);
    return nil;
}



/* Code for dv_skel2factor */

static Lisp_Object CC_dv_skel2factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor");
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
    push(nil);
/* copy arguments values to proper place */
    v125 = v1;
    stack[-4] = v0;
/* end of prologue */
    v130 = stack[-4];
    v130 = qcdr(v130);
    if (v130 == nil) goto v131;
    v130 = stack[-4];
    v130 = qcdr(v130);
    v130 = Lsublis(nil, v125, v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-5] = v130;
    v130 = stack[-5];
    fn = elt(env, 2); /* st_ad_numsorttree */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-5] = v130;
    v130 = stack[-5];
    v130 = qcdr(v130);
    fn = elt(env, 3); /* st_flatten */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-3] = v130;
    v130 = stack[-3];
    if (v130 == nil) goto v126;
    v130 = stack[-3];
    v130 = qcar(v130);
    fn = elt(env, 4); /* dv_ind2var */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v130 = ncons(v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-1] = v130;
    stack[-2] = v130;
    goto v2;

v2:
    v130 = stack[-3];
    v130 = qcdr(v130);
    stack[-3] = v130;
    v130 = stack[-3];
    if (v130 == nil) goto v18;
    stack[0] = stack[-1];
    v130 = stack[-3];
    v130 = qcar(v130);
    fn = elt(env, 4); /* dv_ind2var */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v130 = ncons(v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v130 = Lrplacd(nil, stack[0], v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v130 = stack[-1];
    v130 = qcdr(v130);
    stack[-1] = v130;
    goto v2;

v18:
    v130 = stack[-2];
    goto v108;

v108:
    v125 = stack[-5];
    stack[0] = qcar(v125);
    v125 = stack[-4];
    v125 = qcar(v125);
    fn = elt(env, 5); /* dv_skel2factor1 */
    v130 = (*qfn2(fn))(qenv(fn), v125, v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v133 = stack[0];
        popv(7);
        return cons(v133, v130);
    }

v126:
    v130 = qvalue(elt(env, 1)); /* nil */
    goto v108;

v131:
    v130 = stack[-4];
    v130 = qcar(v130);
    { popv(7); return onevalue(v130); }
/* error exit handlers */
v132:
    popv(7);
    return nil;
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v54 = stack[-1];
    if (!consp(v54)) goto v53;
    v54 = stack[-1];
    v54 = qcar(v54);
    if (!consp(v54)) goto v53;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    stack[-2] = v54;
    v54 = stack[-2];
    v149 = qcar(v54);
    v54 = elt(env, 1); /* i */
    if (!(v149 == v54)) goto v114;
    v54 = elt(env, 2); /* (sqrt -1) */
    fn = elt(env, 5); /* fkern */
    v149 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v54 = stack[-2];
    v54 = qcdr(v54);
    fn = elt(env, 6); /* getpower */
    v54 = (*qfn2(fn))(qenv(fn), v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v54;
    goto v114;

v114:
    v54 = stack[-2];
    v149 = qcar(v54);
    v54 = elt(env, 3); /* sqrt */
    if (!consp(v149)) goto v152;
    v149 = qcar(v149);
    if (!(v149 == v54)) goto v152;
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = Lonep(nil, v54);
    env = stack[-3];
    if (!(v54 == nil)) goto v152;
    v54 = stack[-2];
    v149 = qcdr(v54);
    v54 = (Lisp_Object)33; /* 2 */
    v54 = Ldivide(nil, v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[0] = v54;
    v54 = stack[-2];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    fn = elt(env, 7); /* simp */
    v149 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v54 = stack[0];
    v54 = qcar(v54);
    fn = elt(env, 8); /* exptsq */
    v54 = (*qfn2(fn))(qenv(fn), v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v150 = v54;
    v54 = stack[0];
    v149 = qcdr(v54);
    v54 = (Lisp_Object)1; /* 0 */
    if (v149 == v54) goto v58;
    stack[0] = v150;
    v54 = stack[-2];
    v54 = qcar(v54);
    fn = elt(env, 5); /* fkern */
    v149 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v54 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* getpower */
    v149 = (*qfn2(fn))(qenv(fn), v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v54 = (Lisp_Object)17; /* 1 */
    v150 = cons(v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v149 = qvalue(elt(env, 4)); /* nil */
    v54 = (Lisp_Object)17; /* 1 */
    v54 = acons(v150, v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v54 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v150 = v54;
    goto v58;

v58:
    v54 = v150;
    fn = elt(env, 10); /* tidysqrt */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v150 = v54;
    goto v66;

v66:
    stack[0] = v150;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    v54 = CC_tidysqrtf(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v54 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v54;
    stack[0] = stack[-2];
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = CC_tidysqrtf(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    {
        Lisp_Object v153 = stack[0];
        popv(4);
        fn = elt(env, 11); /* addsq */
        return (*qfn2(fn))(qenv(fn), v153, v54);
    }

v152:
    v149 = stack[-2];
    v54 = (Lisp_Object)17; /* 1 */
    v150 = cons(v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v149 = qvalue(elt(env, 4)); /* nil */
    v54 = (Lisp_Object)17; /* 1 */
    v54 = acons(v150, v149, v54);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v150 = v54;
    goto v66;

v53:
    v149 = stack[-1];
    v54 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v149, v54);
/* error exit handlers */
v151:
    popv(4);
    return nil;
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v56, v121;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v16,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v56 = stack[-1];
    v57 = (Lisp_Object)1; /* 0 */
    v57 = (Lisp_Object)greaterp2(v56, v57);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v57 = v57 ? lisp_true : nil;
    env = stack[-5];
    if (v57 == nil) goto v31;
    v57 = stack[-3];
    stack[-4] = qcdr(v57);
    stack[0] = stack[-2];
    v57 = stack[-1];
    v57 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v57 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[0] = v57;
    v57 = stack[-3];
    v57 = qcar(v57);
    if (v57 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v56 = stack[-2];
    v57 = stack[-1];
    v121 = cons(v56, v57);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v57 = stack[-3];
    v56 = qcar(v57);
    v57 = stack[0];
    popv(6);
    return acons(v121, v56, v57);

v31:
    v57 = stack[-3];
    v57 = qcar(v57);
    { popv(6); return onevalue(v57); }
/* error exit handlers */
v107:
    popv(6);
    return nil;
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v118 = v55;
    v55 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v118, v55);
    }
}



/* Code for evalgreaterp */

static Lisp_Object CC_evalgreaterp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v104, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgreaterp");
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
    v104 = v1;
    v106 = v0;
/* end of prologue */
    v155 = elt(env, 1); /* difference */
    v106 = list3(v155, v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    fn = elt(env, 5); /* simp!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    stack[0] = v106;
    v106 = stack[0];
    v106 = qcdr(v106);
    if (!(!consp(v106))) goto v89;
    v106 = stack[0];
    v106 = qcar(v106);
    if (!consp(v106)) goto v42;
    v106 = stack[0];
    v106 = qcar(v106);
    v106 = qcar(v106);
    if (!(!consp(v106))) goto v89;

v42:
    v106 = stack[0];
    v106 = qcar(v106);
    if (v106 == nil) goto v121;
    v106 = stack[0];
    v106 = qcar(v106);
    if (!consp(v106)) goto v156;
    v106 = stack[0];
    v106 = qcar(v106);
    v104 = qcar(v106);
    v106 = elt(env, 4); /* minusp */
    v104 = get(v104, v106);
    v106 = stack[0];
    v106 = qcar(v106);
        popv(2);
        return Lapply1(nil, v104, v106);

v156:
    v106 = stack[0];
    v106 = qcar(v106);
        popv(2);
        return Lminusp(nil, v106);

v121:
    v106 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v106); }

v89:
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 6); /* minusf */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    if (v106 == nil) goto v114;
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 7); /* negf */
    v104 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = cons(v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    goto v44;

v44:
    fn = elt(env, 8); /* mk!*sq */
    v104 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    v106 = elt(env, 2); /* "number" */
    {
        popv(2);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v104, v106);
    }

v114:
    v106 = stack[0];
    goto v44;
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for maxfrom */

static Lisp_Object CC_maxfrom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom");
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
    v90 = v1;
    v4 = v0;
/* end of prologue */
    stack[0] = v4;
    v4 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v90 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v48 = stack[0];
        popv(2);
        fn = elt(env, 1); /* maxfrom1 */
        return (*qfnn(fn))(qenv(fn), 3, v48, v4, v90);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for mk!+equation */

static Lisp_Object CC_mkLequation(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v148, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+equation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v1;
    v148 = v0;
/* end of prologue */
    v5 = elt(env, 1); /* equal */
    return list3(v5, v148, v4);
}



/* Code for pasf_fact */

static Lisp_Object CC_pasf_fact(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_fact");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v134 = stack[-1];
    v91 = elt(env, 1); /* true */
    if (v134 == v91) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v134 = stack[-1];
    v91 = elt(env, 2); /* false */
    if (v134 == v91) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v91 = stack[-1];
    v91 = qcar(v91);
    stack[-5] = v91;
    v91 = stack[-1];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    fn = elt(env, 9); /* fctrf */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    stack[0] = v91;
    v91 = stack[0];
    v134 = Llength(nil, v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v91 = (Lisp_Object)49; /* 3 */
    v91 = (Lisp_Object)lessp2(v134, v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v91 = v91 ? lisp_true : nil;
    env = stack[-6];
    if (!(v91 == nil)) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v134 = stack[-5];
    v91 = elt(env, 3); /* (equal neq) */
    v91 = Lmemq(nil, v134, v91);
    if (v91 == nil) goto v96;
    v134 = stack[-5];
    v91 = elt(env, 4); /* equal */
    if (v134 == v91) goto v146;
    v91 = elt(env, 6); /* and */
    stack[-4] = v91;
    goto v56;

v56:
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[-3] = v91;
    v91 = stack[-3];
    if (v91 == nil) goto v102;
    v91 = stack[-3];
    v91 = qcar(v91);
    v135 = stack[-5];
    v134 = qcar(v91);
    v91 = qvalue(elt(env, 7)); /* nil */
    v91 = list3(v135, v134, v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    stack[-1] = v91;
    stack[-2] = v91;
    goto v128;

v128:
    v91 = stack[-3];
    v91 = qcdr(v91);
    stack[-3] = v91;
    v91 = stack[-3];
    if (v91 == nil) goto v61;
    stack[0] = stack[-1];
    v91 = stack[-3];
    v91 = qcar(v91);
    v135 = stack[-5];
    v134 = qcar(v91);
    v91 = qvalue(elt(env, 7)); /* nil */
    v91 = list3(v135, v134, v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v91 = Lrplacd(nil, stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-1] = v91;
    goto v128;

v61:
    v91 = stack[-2];
    goto v121;

v121:
    {
        Lisp_Object v162 = stack[-4];
        popv(7);
        return cons(v162, v91);
    }

v102:
    v91 = qvalue(elt(env, 7)); /* nil */
    goto v121;

v146:
    v91 = elt(env, 5); /* or */
    stack[-4] = v91;
    goto v56;

v96:
    v134 = stack[-5];
    v91 = elt(env, 8); /* (leq lessp geq greaterp) */
    v91 = Lmemq(nil, v134, v91);
    if (v91 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v91 = stack[0];
    stack[-1] = qcdr(v91);
    v91 = stack[0];
    v91 = qcar(v91);
    fn = elt(env, 10); /* minusf */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    if (v91 == nil) goto v49;
    v91 = stack[-5];
    fn = elt(env, 11); /* pasf_anegrel */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    goto v74;

v74:
    {
        Lisp_Object v151 = stack[-1];
        popv(7);
        fn = elt(env, 12); /* pasf_fact1 */
        return (*qfn2(fn))(qenv(fn), v151, v91);
    }

v49:
    v91 = stack[-5];
    goto v74;
/* error exit handlers */
v161:
    popv(7);
    return nil;
}



/* Code for aex_minus */

static Lisp_Object CC_aex_minus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_minus");
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
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v93 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    v93 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_minus */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    v93 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    v93 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v93 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    if (v93 == nil) goto v117;
    v93 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    goto v118;

v118:
    {
        Lisp_Object v19 = stack[-4];
        Lisp_Object v17 = stack[-1];
        Lisp_Object v113 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v19, v17, v113, v93);
    }

v117:
    v93 = qvalue(elt(env, 1)); /* nil */
    goto v118;
/* error exit handlers */
v18:
    popv(6);
    return nil;
}



/* Code for lowupperlimitrd */

static Lisp_Object MS_CDECL CC_lowupperlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lowupperlimitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowupperlimitrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    fn = elt(env, 5); /* mathml */
    v21 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[0] = v21;
    fn = elt(env, 6); /* lex */
    v21 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v6 = qvalue(elt(env, 1)); /* char */
    v21 = elt(env, 2); /* (!/ l o w l i m i t) */
    if (equal(v6, v21)) goto v131;
    v6 = elt(env, 3); /* "</lowlimit>" */
    v21 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v21 = (*qfn2(fn))(qenv(fn), v6, v21);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    goto v163;

v163:
    stack[-1] = elt(env, 4); /* lowupperlimit */
    v21 = stack[-2];
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v12 = stack[-1];
        Lisp_Object v164 = stack[0];
        popv(4);
        return list2star(v12, v164, v21);
    }

v131:
    fn = elt(env, 8); /* upperlimitrd */
    v21 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[-2] = v21;
    goto v163;
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for mkbc */

static Lisp_Object CC_mkbc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkbc");
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

v11:
    v169 = stack[-1];
    v169 = (is_number(v169) ? lisp_true : nil);
    if (!(v169 == nil)) goto v29;
    v169 = stack[-1];
    fn = elt(env, 5); /* f2dip11 */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    goto v29;

v29:
    v169 = stack[0];
    v169 = (is_number(v169) ? lisp_true : nil);
    if (!(v169 == nil)) goto v115;
    v169 = stack[0];
    fn = elt(env, 5); /* f2dip11 */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    goto v115;

v115:
    v169 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v169 == nil) goto v126;
    v169 = stack[0];
    v169 = Lmodular_reciprocal(nil, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v169 = times2(stack[-1], v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 6); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v169);
    }

v126:
    v170 = stack[0];
    v169 = (Lisp_Object)17; /* 1 */
    if (v170 == v169) goto v164;
    v169 = stack[0];
    fn = elt(env, 7); /* minusf */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    if (v169 == nil) goto v13;
    v169 = stack[-1];
    fn = elt(env, 8); /* negf */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-1] = v169;
    v169 = stack[0];
    fn = elt(env, 8); /* negf */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[0] = v169;
    goto v11;

v13:
    v170 = stack[-1];
    v169 = stack[0];
    fn = elt(env, 9); /* gcdf */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-2] = v169;
    v169 = qvalue(elt(env, 3)); /* !*exp */
    if (v169 == nil) goto v106;
    v169 = qvalue(elt(env, 4)); /* !*mcd */
    if (v169 == nil) goto v106;
    v170 = stack[-1];
    v169 = stack[-2];
    fn = elt(env, 10); /* quotfx1 */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-1] = v169;
    goto v125;

v125:
    v169 = qvalue(elt(env, 3)); /* !*exp */
    if (v169 == nil) goto v100;
    v169 = qvalue(elt(env, 4)); /* !*mcd */
    if (v169 == nil) goto v100;
    v170 = stack[0];
    v169 = stack[-2];
    fn = elt(env, 10); /* quotfx1 */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v103;

v103:
    {
        Lisp_Object v171 = stack[-1];
        popv(4);
        return cons(v171, v169);
    }

v100:
    v170 = stack[0];
    v169 = stack[-2];
    fn = elt(env, 11); /* quotf */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v103;

v106:
    v170 = stack[-1];
    v169 = stack[-2];
    fn = elt(env, 11); /* quotf */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[-1] = v169;
    goto v125;

v164:
    v170 = stack[-1];
    v169 = (Lisp_Object)17; /* 1 */
    if (v170 == v169) goto v122;
    v170 = stack[-1];
    v169 = stack[0];
    popv(4);
    return cons(v170, v169);

v122:
    v169 = elt(env, 2); /* (1 . 1) */
    { popv(4); return onevalue(v169); }
/* error exit handlers */
v96:
    popv(4);
    return nil;
}



/* Code for mkassign */

static Lisp_Object CC_mkassign(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v90, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v1;
    v90 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* setq */
    return list3(v4, v90, v115);
}



/* Code for mv2sf */

static Lisp_Object CC_mv2sf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v31, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf");
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
    goto v29;

v29:
    v116 = stack[-1];
    if (v116 == nil) goto v92;
    v116 = stack[-1];
    v116 = qcar(v116);
    v88 = qcar(v116);
    v116 = stack[-1];
    v116 = qcar(v116);
    v31 = qcdr(v116);
    v116 = stack[0];
    fn = elt(env, 2); /* mv2sf1 */
    v31 = (*qfnn(fn))(qenv(fn), 3, v88, v31, v116);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v116 = stack[-2];
    v116 = cons(v31, v116);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[-2] = v116;
    v116 = stack[-1];
    v116 = qcdr(v116);
    stack[-1] = v116;
    goto v29;

v92:
    v116 = qvalue(elt(env, 1)); /* nil */
    v31 = v116;
    goto v131;

v131:
    v116 = stack[-2];
    if (v116 == nil) { popv(4); return onevalue(v31); }
    v116 = stack[-2];
    v116 = qcar(v116);
    fn = elt(env, 3); /* addf */
    v116 = (*qfn2(fn))(qenv(fn), v116, v31);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v31 = v116;
    v116 = stack[-2];
    v116 = qcdr(v116);
    stack[-2] = v116;
    goto v131;
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for dp_from_ei */

static Lisp_Object CC_dp_from_ei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_from_ei");
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
    v112 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* bc_fi */
    stack[-1] = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v112 = stack[0];
    fn = elt(env, 2); /* mo_from_ei */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    fn = elt(env, 3); /* dp_term */
    v112 = (*qfn2(fn))(qenv(fn), stack[-1], v112);
    nil = C_nil;
    if (exception_pending()) goto v4;
    popv(3);
    return ncons(v112);
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for nonmult */

static Lisp_Object CC_nonmult(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonmult");
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
    v24 = qvalue(elt(env, 1)); /* vjets */
    v111 = Lreverse(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    v24 = stack[0];
    fn = elt(env, 2); /* pnth */
    v24 = (*qfn2(fn))(qenv(fn), v111, v24);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    stack[0] = qcar(v24);
    v24 = qvalue(elt(env, 1)); /* vjets */
    v24 = Lreverse(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v154;
    v24 = Lmember(nil, stack[0], v24);
    v24 = qcdr(v24);
        popv(2);
        return Lreverse(nil, v24);
/* error exit handlers */
v154:
    popv(2);
    return nil;
}



/* Code for pst_mkpst */

static Lisp_Object CC_pst_mkpst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_mkpst");
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
    v53 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* pst_mkpst1 */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-1];
    v53 = cons(stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pst_equitable */
        return (*qfn1(fn))(qenv(fn), v53);
    }
/* error exit handlers */
v115:
    popv(2);
    return nil;
}



/* Code for simpsqrt2 */

static Lisp_Object CC_simpsqrt2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrt2");
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
    v164 = stack[0];
    fn = elt(env, 2); /* minusf */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    if (v164 == nil) goto v9;
    v119 = stack[0];
    v164 = (Lisp_Object)-15; /* -1 */
    v164 = Leqn(nil, v119, v164);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    if (v164 == nil) goto v23;
    v164 = qvalue(elt(env, 1)); /* gaussiani */
    { popv(2); return onevalue(v164); }

v23:
    v164 = stack[0];
    fn = elt(env, 3); /* negf */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v119 = v164;
    v164 = v119;
    if (is_number(v164)) goto v109;
    v164 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v109:
    stack[0] = qvalue(elt(env, 1)); /* gaussiani */
    v164 = v119;
    fn = elt(env, 4); /* simpsqrt3 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    {
        Lisp_Object v19 = stack[0];
        popv(2);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v19, v164);
    }

v9:
    v164 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v164);
    }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for mksfpf */

static Lisp_Object CC_mksfpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksfpf");
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
    v100 = v0;
/* end of prologue */
    fn = elt(env, 4); /* mkprod */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-2];
    stack[-1] = v100;
    v78 = stack[0];
    v100 = (Lisp_Object)17; /* 1 */
    if (v78 == v100) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v100 = stack[-1];
    if (!consp(v100)) goto v123;
    v100 = stack[-1];
    v100 = qcar(v100);
    if (!consp(v100)) goto v123;
    v78 = stack[0];
    v100 = (Lisp_Object)1; /* 0 */
    v100 = (Lisp_Object)geq2(v78, v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v100 = v100 ? lisp_true : nil;
    env = stack[-2];
    if (v100 == nil) goto v99;
    v100 = stack[-1];
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v100 = Lonep(nil, v100);
    env = stack[-2];
    if (v100 == nil) goto v99;
    v100 = stack[-1];
    v100 = qcdr(v100);
    if (!(v100 == nil)) goto v99;
    v100 = stack[-1];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v78 = qcdr(v100);
    v100 = stack[0];
    v78 = times2(v78, v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-2];
    v100 = stack[-1];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v100 = qcar(v100);
    stack[-1] = v78;
    stack[0] = v100;
    v78 = stack[0];
    v100 = qvalue(elt(env, 1)); /* asymplis!* */
    v100 = Lassoc(nil, v78, v100);
    v78 = v100;
    v100 = qvalue(elt(env, 2)); /* subfg!* */
    if (v100 == nil) goto v38;
    v100 = v78;
    if (v100 == nil) goto v38;
    v100 = v78;
    v78 = qcdr(v100);
    v100 = stack[-1];
    v100 = (Lisp_Object)lesseq2(v78, v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v100 = v100 ? lisp_true : nil;
    env = stack[-2];
    if (v100 == nil) goto v38;
    v100 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v100); }

v38:
    v100 = stack[0];
    fn = elt(env, 5); /* fkern */
    v78 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-2];
    v100 = stack[-1];
    fn = elt(env, 6); /* getpower */
    v78 = (*qfn2(fn))(qenv(fn), v78, v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-2];
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v78, v100);
    nil = C_nil;
    if (exception_pending()) goto v175;
    popv(3);
    return ncons(v100);

v99:
    v78 = stack[-1];
    v100 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* exptf2 */
        return (*qfn2(fn))(qenv(fn), v78, v100);
    }

v123:
    v78 = stack[-1];
    v100 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v78, v100);
    }
/* error exit handlers */
v175:
    popv(3);
    return nil;
}



/* Code for cl_smsimpl!-junct1 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, Lisp_Object v22,
                         Lisp_Object v32, Lisp_Object v11,
                         Lisp_Object v33, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v212, v213, v214, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct1");
#endif
    if (stack >= stacklimit)
    {
        push6(v33,v11,v32,v22,v16,v1);
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v16,v22,v32,v11);
        pop(v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v33;
    stack[-4] = v11;
    stack[-5] = v32;
    stack[-6] = v22;
    stack[-7] = v16;
    v210 = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v5;

v5:
    v210 = stack[-7];
    if (v210 == nil) goto v216;
    v210 = stack[-7];
    v210 = qcar(v210);
    stack[-9] = v210;
    v210 = stack[-7];
    v210 = qcdr(v210);
    stack[-7] = v210;
    stack[-10] = stack[-9];
    stack[0] = stack[-5];
    v210 = stack[-4];
    v211 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    v210 = stack[-8];
    fn = elt(env, 15); /* cl_simpl1 */
    v210 = (*qfnn(fn))(qenv(fn), 4, stack[-10], stack[0], v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-10] = v210;
    v210 = stack[-10];
    if (!consp(v210)) goto v122;
    v210 = stack[-10];
    v210 = qcar(v210);
    goto v93;

v93:
    v212 = v210;
    v211 = v212;
    v210 = stack[-3];
    if (v211 == v210) goto v114;
    v211 = v212;
    v210 = stack[-8];
    if (v211 == v210) goto v174;
    v211 = v212;
    v210 = elt(env, 3); /* true */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 4); /* false */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 5); /* or */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 6); /* and */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 7); /* not */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 8); /* impl */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 9); /* repl */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 10); /* equiv */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 11); /* ex */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 12); /* all */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 13); /* bex */
    if (v211 == v210) goto v218;
    v211 = v212;
    v210 = elt(env, 14); /* ball */
    if (v211 == v210) goto v218;
    v210 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v210 == nil) goto v219;
    v210 = stack[-2];
    v211 = Lnreverse(nil, v210);
    env = stack[-11];
    v210 = stack[-7];
    v210 = Lnconc(nil, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-7] = v210;
    v210 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v210;
    goto v219;

v219:
    v210 = stack[-10];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-1] = v210;
    goto v43;

v43:
    v210 = stack[-1];
    if (v210 == nil) goto v5;
    v213 = stack[-8];
    v212 = stack[-1];
    v211 = stack[-5];
    v210 = stack[-4];
    fn = elt(env, 16); /* rl_smupdknowl */
    v210 = (*qfnn(fn))(qenv(fn), 4, v213, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-5] = v210;
    v211 = stack[-5];
    v210 = elt(env, 4); /* false */
    if (!(v211 == v210)) goto v220;
    v210 = stack[-3];
    stack[-9] = v210;
    v210 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v210;
    goto v220;

v220:
    v210 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v210;
    goto v5;

v218:
    stack[0] = v212;
    v210 = stack[-3];
    fn = elt(env, 17); /* cl_flip */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    if (equal(stack[0], v210)) goto v43;
    v211 = stack[-10];
    v210 = stack[-2];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-2] = v210;
    goto v43;

v174:
    v210 = stack[-10];
    v210 = qcdr(v210);
    stack[0] = v210;
    goto v15;

v15:
    v210 = stack[0];
    if (v210 == nil) goto v101;
    v210 = stack[0];
    v210 = qcar(v210);
    fn = elt(env, 18); /* cl_atfp */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    if (v210 == nil) goto v101;
    v210 = stack[0];
    v211 = qcar(v210);
    v210 = stack[-1];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-1] = v210;
    v210 = stack[0];
    v210 = qcdr(v210);
    stack[0] = v210;
    goto v15;

v101:
    v210 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v210 == nil) goto v172;
    v210 = stack[-1];
    if (v210 == nil) goto v172;
    v210 = stack[-2];
    v211 = Lnreverse(nil, v210);
    env = stack[-11];
    v210 = stack[-7];
    v210 = Lnconc(nil, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-7] = v210;
    v210 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v210;
    goto v172;

v172:
    v210 = stack[0];
    v210 = Lreverse(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    v210 = Lnconc(nil, stack[-2], v210);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-11];
    stack[-2] = v210;
    goto v43;

v114:
    v210 = stack[-3];
    stack[-9] = v210;
    v210 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v210;
    goto v43;

v122:
    v210 = stack[-10];
    goto v93;

v216:
    v211 = stack[-9];
    v210 = stack[-3];
    if (v211 == v210) goto v221;
    v215 = stack[-8];
    v214 = stack[-2];
    v213 = stack[-6];
    v212 = stack[-5];
    v211 = stack[-4];
    v210 = stack[-3];
    {
        popv(12);
        fn = elt(env, 19); /* cl_smsimpl!-junct2 */
        return (*qfnn(fn))(qenv(fn), 6, v215, v214, v213, v212, v211, v210);
    }

v221:
    v210 = stack[-3];
    popv(12);
    return ncons(v210);
/* error exit handlers */
v217:
    popv(12);
    return nil;
}



/* Code for ev_mtest!? */

static Lisp_Object CC_ev_mtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v21, v6, v8, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v1;
    v8 = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* t */
    v9 = v7;
    goto v131;

v131:
    v7 = v8;
    if (v7 == nil) return onevalue(v9);
    v7 = v9;
    if (v7 == nil) return onevalue(v9);
    v7 = v8;
    v21 = qcar(v7);
    v7 = v6;
    v7 = qcar(v7);
    if (((int32_t)(v21)) < ((int32_t)(v7))) goto v23;
    v7 = v8;
    v7 = qcdr(v7);
    v8 = v7;
    v7 = v6;
    v7 = qcdr(v7);
    v6 = v7;
    goto v131;

v23:
    v7 = qvalue(elt(env, 2)); /* nil */
    v9 = v7;
    v8 = v7;
    goto v131;
}



/* Code for vectorrd */

static Lisp_Object MS_CDECL CC_vectorrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vectorrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectorrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 3); /* matrixrowrd */
    v4 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    v148 = elt(env, 2); /* mat */
    v4 = list2(v148, v4);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v5:
    popv(1);
    return nil;
}



/* Code for addexptsdf */

static Lisp_Object CC_addexptsdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addexptsdf");
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
    goto v33;

v33:
    v168 = stack[-1];
    if (v168 == nil) goto v131;
    v168 = stack[0];
    if (v168 == nil) goto v109;
    v168 = stack[-1];
    v157 = qcar(v168);
    v168 = stack[0];
    v168 = qcar(v168);
    fn = elt(env, 3); /* exptplus */
    v157 = (*qfn2(fn))(qenv(fn), v157, v168);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    v168 = stack[-2];
    v168 = cons(v157, v168);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    stack[-2] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    v168 = stack[0];
    v168 = qcdr(v168);
    stack[0] = v168;
    goto v33;

v109:
    stack[0] = stack[-2];
    v168 = elt(env, 2); /* "Y too long" */
    fn = elt(env, 4); /* interr */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    {
        Lisp_Object v108 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v108, v168);
    }

v131:
    v168 = stack[0];
    if (v168 == nil) goto v115;
    stack[0] = stack[-2];
    v168 = elt(env, 1); /* "X too long" */
    fn = elt(env, 4); /* interr */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    {
        Lisp_Object v120 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v120, v168);
    }

v115:
    v168 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v168);
    }
/* error exit handlers */
v107:
    popv(4);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    v90 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ps!:value */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[0];
    v4 = v90;
    v90 = v4;
    if (is_number(v90)) goto v118;
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v90); }

v118:
    v90 = v4;
        popv(1);
        return Lzerop(nil, v90);
/* error exit handlers */
v148:
    popv(1);
    return nil;
}



/* Code for cr!:onep */

static Lisp_Object CC_crTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:onep");
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
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    if (!consp(v209)) goto v92;
    v158 = elt(env, 1); /* !:rd!: */
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    v209 = cons(v158, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    goto v29;

v29:
    v158 = v209;
    v209 = v158;
    if (!consp(v209)) goto v2;
    v209 = v158;
    v209 = qcdr(v209);
    v158 = qcar(v209);
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (v158 == v209 ? lisp_true : nil);
    goto v163;

v163:
    if (v209 == nil) goto v32;
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcar(v209);
    if (!consp(v209)) goto v17;
    v158 = elt(env, 1); /* !:rd!: */
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcar(v209);
    v209 = cons(v158, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    goto v19;

v19:
    v158 = v209;
    if (!(!consp(v158))) goto v14;
    v158 = elt(env, 1); /* !:rd!: */
    v209 = cons(v158, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    goto v14;

v14:
    v158 = v209;
    v158 = qcdr(v158);
    if (!consp(v158)) goto v40;
    stack[-1] = qvalue(elt(env, 5)); /* bfone!* */
    stack[0] = v209;
    v158 = qvalue(elt(env, 6)); /* !:bprec!: */
    v209 = (Lisp_Object)49; /* 3 */
    v209 = difference2(v158, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    fn = elt(env, 7); /* round!:mt */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    fn = elt(env, 8); /* csl_normbf */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    {
        Lisp_Object v170 = stack[-1];
        popv(3);
        fn = elt(env, 9); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v170, v209);
    }

v40:
    v158 = elt(env, 3); /* 1.0 */
    v209 = qcdr(v209);
    v209 = difference2(v158, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    v209 = Labsval(nil, v209);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-2];
    v158 = qvalue(elt(env, 4)); /* !!fleps1 */
        popv(3);
        return Llessp(nil, v209, v158);

v17:
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcar(v209);
    goto v19;

v32:
    v209 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v209); }

v2:
    v209 = v158;
    v209 = (Lisp_Object)zerop(v209);
    v209 = v209 ? lisp_true : nil;
    env = stack[-2];
    goto v163;

v92:
    v209 = stack[0];
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    goto v29;
/* error exit handlers */
v169:
    popv(3);
    return nil;
}



/* Code for newsym1 */

static Lisp_Object MS_CDECL CC_newsym1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v5;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "newsym1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newsym1");
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
    v148 = qvalue(elt(env, 1)); /* cindex!* */
    v148 = Lexplode(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    stack[0] = v148;
    v148 = qvalue(elt(env, 1)); /* cindex!* */
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    qvalue(elt(env, 1)) = v148; /* cindex!* */
    v5 = qvalue(elt(env, 2)); /* cname!* */
    v148 = stack[0];
    v148 = Lappend(nil, v5, v148);
    nil = C_nil;
    if (exception_pending()) goto v47;
        popv(2);
        return Lcompress(nil, v148);
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for replace2_parents */

static Lisp_Object MS_CDECL CC_replace2_parents(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v93;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace2_parents");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace2_parents");
#endif
    if (stack >= stacklimit)
    {
        push3(v16,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v93 = stack[-2];
    v9 = stack[0];
    v9 = qcar(v9);
    if (!(equal(v93, v9))) goto v45;
    v93 = stack[0];
    v9 = stack[-1];
    v9 = Lrplaca(nil, v93, v9);
    nil = C_nil;
    if (exception_pending()) goto v119;
    goto v45;

v45:
    v93 = stack[-2];
    v9 = stack[0];
    v9 = qcdr(v9);
    if (equal(v93, v9)) goto v126;
    v9 = nil;
    { popv(3); return onevalue(v9); }

v126:
    v93 = stack[0];
    v9 = stack[-1];
        popv(3);
        return Lrplacd(nil, v93, v9);
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for mo!=zero */

static Lisp_Object CC_moMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v123, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v123 = v0;
/* end of prologue */

v10:
    v154 = v123;
    v154 = (v154 == nil ? lisp_true : nil);
    if (!(v154 == nil)) return onevalue(v154);
    v154 = v123;
    v124 = qcar(v154);
    v154 = (Lisp_Object)1; /* 0 */
    if (v124 == v154) goto v47;
    v154 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v154);

v47:
    v154 = v123;
    v154 = qcdr(v154);
    v123 = v154;
    goto v10;
}



/* Code for st_sorttree1 */

static Lisp_Object MS_CDECL CC_st_sorttree1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v279, v280, v281;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
    if (stack >= stacklimit)
    {
        push3(v16,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v16;
    stack[-9] = v1;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v279 = (Lisp_Object)17; /* 1 */
    stack[-6] = v279;
    v279 = stack[-10];
    v279 = qcdr(v279);
    v279 = qcar(v279);
    if (is_number(v279)) goto v111;
    v279 = stack[-10];
    v280 = qcar(v279);
    v279 = elt(env, 1); /* !* */
    if (v280 == v279) goto v51;
    v279 = stack[-10];
    v279 = qcdr(v279);
    stack[0] = v279;
    goto v282;

v282:
    v279 = stack[0];
    if (v279 == nil) goto v283;
    v279 = stack[0];
    v279 = qcar(v279);
    v281 = v279;
    v280 = stack[-6];
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v183;
    v280 = stack[-9];
    v279 = stack[-8];
    v279 = CC_st_sorttree1(env, 3, v281, v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v279;
    v280 = stack[-6];
    v279 = stack[-2];
    v279 = qcdr(v279);
    v279 = qcar(v279);
    v279 = times2(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v279;
    v279 = stack[-2];
    v279 = qcdr(v279);
    v281 = qcdr(v279);
    v279 = stack[-2];
    v280 = qcar(v279);
    v279 = stack[-1];
    v279 = acons(v281, v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v279;
    goto v183;

v183:
    v279 = stack[0];
    v279 = qcdr(v279);
    stack[0] = v279;
    goto v282;

v283:
    v280 = stack[-6];
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v285;
    v279 = stack[-10];
    v280 = qcar(v279);
    v279 = elt(env, 3); /* !+ */
    if (v280 == v279) goto v286;
    v280 = stack[-1];
    v279 = stack[-8];
    fn = elt(env, 4); /* cdr_signsort */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v279;
    v279 = stack[-1];
    v280 = qcar(v279);
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v287;
    v280 = stack[-6];
    v279 = stack[-1];
    v279 = qcar(v279);
    v279 = times2(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v279;
    v279 = stack[-1];
    v279 = qcdr(v279);
    stack[-1] = v279;
    goto v288;

v288:
    v279 = stack[-1];
    if (v279 == nil) goto v289;
    v279 = stack[-1];
    v279 = qcar(v279);
    v280 = qcar(v279);
    v279 = stack[-7];
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v279;
    v279 = stack[-1];
    v279 = qcar(v279);
    v280 = qcdr(v279);
    v279 = stack[-11];
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v279;
    v279 = stack[-1];
    v279 = qcdr(v279);
    stack[-1] = v279;
    goto v288;

v289:
    v279 = stack[-10];
    stack[0] = qcar(v279);
    v279 = stack[-7];
    v279 = Lreverse(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = cons(stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v279;
    v279 = stack[-11];
    v279 = Lreverse(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    stack[-11] = v279;
    v281 = stack[-11];
    v280 = stack[-6];
    v279 = stack[-7];
    popv(13);
    return list2star(v281, v280, v279);

v287:
    v280 = qvalue(elt(env, 2)); /* nil */
    v279 = (Lisp_Object)1; /* 0 */
    v281 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v280, v279, v281);

v286:
    v280 = stack[-1];
    v279 = stack[-8];
    fn = elt(env, 5); /* cdr_sort */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-1] = v279;
    goto v288;

v285:
    v280 = qvalue(elt(env, 2)); /* nil */
    v279 = (Lisp_Object)1; /* 0 */
    v281 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v280, v279, v281);

v51:
    v279 = stack[-10];
    v279 = qcdr(v279);
    stack[0] = v279;
    goto v151;

v151:
    v279 = stack[0];
    if (v279 == nil) goto v219;
    v279 = stack[0];
    v279 = qcar(v279);
    v281 = v279;
    v280 = stack[-6];
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v290;
    v280 = stack[-9];
    v279 = stack[-8];
    v279 = CC_st_sorttree1(env, 3, v281, v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v279;
    v280 = stack[-6];
    v279 = stack[-2];
    v279 = qcdr(v279);
    v279 = qcar(v279);
    v279 = times2(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-6] = v279;
    v279 = stack[-2];
    v280 = qcar(v279);
    v279 = stack[-11];
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v279;
    v279 = stack[-2];
    v279 = qcdr(v279);
    v280 = qcdr(v279);
    v279 = stack[-7];
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v279;
    goto v290;

v290:
    v279 = stack[0];
    v279 = qcdr(v279);
    stack[0] = v279;
    goto v151;

v219:
    v280 = stack[-6];
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v291;
    v279 = stack[-7];
    v279 = Lreverse(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-7] = v279;
    v279 = stack[-11];
    v279 = Lreverse(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-11] = v279;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v280 = elt(env, 1); /* !* */
    v279 = stack[-7];
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    {
        Lisp_Object v292 = stack[0];
        Lisp_Object v293 = stack[-1];
        popv(13);
        return list2star(v292, v293, v279);
    }

v291:
    v280 = qvalue(elt(env, 2)); /* nil */
    v279 = (Lisp_Object)1; /* 0 */
    v281 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v280, v279, v281);

v111:
    v279 = stack[-10];
    v280 = qcar(v279);
    v279 = elt(env, 1); /* !* */
    if (v280 == v279) goto v23;
    v279 = stack[-10];
    v279 = qcdr(v279);
    stack[-5] = v279;
    v279 = stack[-5];
    if (v279 == nil) goto v80;
    v279 = stack[-5];
    v279 = qcar(v279);
    stack[-1] = v279;
    stack[0] = stack[-9];
    v279 = sub1(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = cons(stack[-1], v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-3] = v279;
    stack[-4] = v279;
    goto v145;

v145:
    v279 = stack[-5];
    v279 = qcdr(v279);
    stack[-5] = v279;
    v279 = stack[-5];
    if (v279 == nil) goto v142;
    stack[-2] = stack[-3];
    v279 = stack[-5];
    v279 = qcar(v279);
    stack[-1] = v279;
    stack[0] = stack[-9];
    v279 = sub1(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = cons(stack[-1], v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = Lrplacd(nil, stack[-2], v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = stack[-3];
    v279 = qcdr(v279);
    stack[-3] = v279;
    goto v145;

v142:
    v279 = stack[-4];
    goto v105;

v105:
    stack[-1] = v279;
    goto v283;

v80:
    v279 = qvalue(elt(env, 2)); /* nil */
    goto v105;

v23:
    v279 = stack[-10];
    v279 = qcdr(v279);
    stack[-4] = v279;
    v279 = stack[-4];
    if (v279 == nil) goto v21;
    v279 = stack[-4];
    v279 = qcar(v279);
    stack[0] = stack[-9];
    v279 = sub1(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    stack[-2] = v279;
    stack[-3] = v279;
    goto v117;

v117:
    v279 = stack[-4];
    v279 = qcdr(v279);
    stack[-4] = v279;
    v279 = stack[-4];
    if (v279 == nil) goto v57;
    stack[-1] = stack[-2];
    v279 = stack[-4];
    v279 = qcar(v279);
    stack[0] = stack[-9];
    v279 = sub1(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = ncons(v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = Lrplacd(nil, stack[-1], v279);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-12];
    v279 = stack[-2];
    v279 = qcdr(v279);
    stack[-2] = v279;
    goto v117;

v57:
    v279 = stack[-3];
    goto v110;

v110:
    stack[-11] = v279;
    v281 = stack[-11];
    v280 = (Lisp_Object)17; /* 1 */
    v279 = stack[-10];
    popv(13);
    return list2star(v281, v280, v279);

v21:
    v279 = qvalue(elt(env, 2)); /* nil */
    goto v110;
/* error exit handlers */
v284:
    popv(13);
    return nil;
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v298, v299;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v53;

v53:
    v298 = stack[-4];
    v297 = (Lisp_Object)1; /* 0 */
    v297 = (Lisp_Object)lessp2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v297 = v297 ? lisp_true : nil;
    env = stack[-6];
    if (v297 == nil) goto v110;
    v299 = (Lisp_Object)-15; /* -1 */
    v298 = (Lisp_Object)17; /* 1 */
    v297 = stack[0];
    v297 = acons(v299, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    stack[0] = v297;
    v297 = stack[-4];
    v297 = negate(v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    stack[-4] = v297;
    goto v53;

v110:
    v298 = stack[-4];
    v297 = (Lisp_Object)65; /* 4 */
    v297 = (Lisp_Object)lessp2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v297 = v297 ? lisp_true : nil;
    env = stack[-6];
    if (v297 == nil) goto v129;
    v298 = stack[-4];
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    v297 = ncons(v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    {
        Lisp_Object v301 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v301, v297);
    }

v129:
    stack[-5] = stack[0];
    v297 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v297;
    v297 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v297;
    goto v13;

v13:
    v297 = stack[-2];
    if (v297 == nil) goto v95;
    v297 = stack[-2];
    v297 = qcar(v297);
    stack[0] = v297;
    v297 = stack[-2];
    v297 = qcdr(v297);
    stack[-2] = v297;
    goto v104;

v104:
    v298 = stack[-4];
    v297 = stack[0];
    v297 = Ldivide(nil, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    v299 = v297;
    v298 = qcdr(v297);
    v297 = (Lisp_Object)1; /* 0 */
    if (v298 == v297) goto v94;
    v298 = stack[-4];
    v297 = (Lisp_Object)17; /* 1 */
    if (v298 == v297) goto v13;
    v298 = stack[0];
    v297 = stack[0];
    v298 = times2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    v297 = stack[-4];
    v297 = (Lisp_Object)greaterp2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v297 = v297 ? lisp_true : nil;
    env = stack[-6];
    if (v297 == nil) goto v13;
    v297 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v297;
    v298 = stack[-4];
    v297 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    stack[-1] = v297;
    v297 = (Lisp_Object)17; /* 1 */
    stack[-4] = v297;
    goto v13;

v94:
    v297 = v299;
    v297 = qcar(v297);
    stack[-4] = v297;
    v298 = stack[0];
    v297 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    stack[-1] = v297;
    goto v104;

v95:
    v298 = stack[-4];
    v297 = (Lisp_Object)17; /* 1 */
    if (v298 == v297) goto v75;
    v297 = stack[-3];
    if (v297 == nil) goto v51;
    v298 = stack[-4];
    v297 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    goto v121;

v121:
    {
        Lisp_Object v302 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v302, v297);
    }

v51:
    v299 = stack[-4];
    v298 = (Lisp_Object)17; /* 1 */
    v297 = stack[-1];
    v297 = acons(v299, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-6];
    goto v121;

v75:
    v297 = stack[-1];
    goto v121;
/* error exit handlers */
v300:
    popv(7);
    return nil;
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v304, v305, v300;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsq");
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
    v305 = stack[-1];
    v304 = (Lisp_Object)17; /* 1 */
    if (v305 == v304) goto v11;
    v305 = stack[0];
    v304 = (Lisp_Object)33; /* 2 */
    if (!(v305 == v304)) goto v119;
    v305 = stack[-1];
    v304 = (Lisp_Object)-15; /* -1 */
    if (v305 == v304) goto v4;
    v305 = stack[-1];
    v304 = elt(env, 1); /* (minus 1) */
    if (!(equal(v305, v304))) goto v119;

v4:
    v304 = elt(env, 2); /* i */
    {
        popv(4);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v304);
    }

v119:
    v305 = stack[-1];
    v304 = elt(env, 3); /* expt */
    if (!consp(v305)) goto v28;
    v305 = qcar(v305);
    if (!(v305 == v304)) goto v28;
    v304 = stack[-1];
    v304 = qcdr(v304);
    v304 = qcdr(v304);
    v304 = qcar(v304);
    v304 = integerp(v304);
    if (v304 == nil) goto v28;
    v304 = qvalue(elt(env, 4)); /* !*precise_complex */
    if (!(v304 == nil)) goto v28;
    v304 = stack[-1];
    v304 = qcdr(v304);
    v305 = qcar(v304);
    v304 = stack[0];
    v305 = CC_mkrootsq(env, v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    v304 = stack[-1];
    v304 = qcdr(v304);
    v304 = qcdr(v304);
    v304 = qcar(v304);
    {
        popv(4);
        fn = elt(env, 9); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v305, v304);
    }

v28:
    v304 = stack[-1];
    v304 = integerp(v304);
    if (v304 == nil) goto v152;
    v304 = stack[-1];
    v304 = Lminusp(nil, v304);
    env = stack[-3];
    if (!(v304 == nil)) goto v152;
    stack[-2] = stack[-1];
    v305 = stack[-1];
    v304 = qvalue(elt(env, 5)); /* factorbound!* */
    v304 = (Lisp_Object)lessp2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    v304 = v304 ? lisp_true : nil;
    env = stack[-3];
    if (!(v304 == nil)) goto v224;
    v304 = qvalue(elt(env, 6)); /* !*ifactor */
    goto v224;

v224:
    fn = elt(env, 10); /* zfactor1 */
    v304 = (*qfn2(fn))(qenv(fn), stack[-2], v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    stack[-2] = v304;
    v305 = Llength(nil, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    v304 = (Lisp_Object)17; /* 1 */
    v304 = (Lisp_Object)greaterp2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    v304 = v304 ? lisp_true : nil;
    env = stack[-3];
    if (!(v304 == nil)) goto v159;
    v304 = stack[-2];
    v304 = qcar(v304);
    v305 = qcdr(v304);
    v304 = (Lisp_Object)17; /* 1 */
    v304 = (Lisp_Object)greaterp2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    v304 = v304 ? lisp_true : nil;
    env = stack[-3];
    if (!(v304 == nil)) goto v159;

v152:
    v305 = stack[0];
    v304 = (Lisp_Object)33; /* 2 */
    if (v305 == v304) goto v34;
    stack[-2] = elt(env, 3); /* expt */
    v300 = elt(env, 7); /* quotient */
    v305 = (Lisp_Object)17; /* 1 */
    v304 = stack[0];
    v304 = list3(v300, v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    v304 = list3(stack[-2], stack[-1], v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    goto v171;

v171:
    stack[-2] = v304;
    v304 = stack[-2];
    fn = elt(env, 11); /* opmtch */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    v305 = v304;
    if (v304 == nil) goto v297;
    v304 = v305;
    {
        popv(4);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v304);
    }

v297:
    v305 = stack[-2];
    v304 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 12); /* mksq */
        return (*qfn2(fn))(qenv(fn), v305, v304);
    }

v34:
    v304 = stack[-1];
    fn = elt(env, 13); /* mksqrt */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-3];
    goto v171;

v159:
    v305 = stack[-2];
    v304 = stack[0];
    {
        popv(4);
        fn = elt(env, 14); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v305, v304);
    }

v11:
    v304 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 15); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v304);
    }
/* error exit handlers */
v202:
    popv(4);
    return nil;
}



/* Code for grpbf */

static Lisp_Object CC_grpbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v317;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for grpbf");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v316 = stack[-4];
    v316 = qcdr(v316);
    v317 = qcar(v316);
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    stack[-5] = v317;
    stack[-2] = v316;
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v111;
    v317 = stack[-2];
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v7;
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)greaterp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v120;
    v317 = stack[-2];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)lessp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v120;
    v316 = qvalue(elt(env, 1)); /* t */
    { popv(7); return onevalue(v316); }

v120:
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)lessp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v104;
    v317 = stack[-2];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)greaterp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v104;
    v316 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v316); }

v104:
    v316 = stack[-4];
    v316 = qcdr(v316);
    v317 = qcar(v316);
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v84;
    v316 = stack[-4];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = Labsval(nil, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = stack[-4];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = sub1(v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = plus2(stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    stack[-1] = v316;
    goto v37;

v37:
    v316 = stack[-3];
    v316 = qcdr(v316);
    v317 = qcar(v316);
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v175;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = Labsval(nil, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = sub1(v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = plus2(stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    goto v132;

v132:
    stack[0] = difference2(stack[-1], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = stack[-4];
    v316 = qcdr(v316);
    v317 = qcdr(v316);
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = difference2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    stack[-1] = stack[0];
    stack[0] = v316;
    v317 = stack[-1];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)greaterp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v298;
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Lgreaterp(nil, v317, v316);

v298:
    v317 = stack[-1];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)lessp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v319;
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Llessp(nil, v317, v316);

v319:
    v317 = stack[0];
    v316 = (Lisp_Object)1; /* 0 */
    if (v317 == v316) goto v275;
    v317 = stack[0];
    v316 = (Lisp_Object)1; /* 0 */
    v316 = (Lisp_Object)greaterp2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = v316 ? lisp_true : nil;
    env = stack[-6];
    if (v316 == nil) goto v320;
    v317 = stack[-5];
    v316 = stack[0];
    v317 = Lash1(nil, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v316 = stack[-2];
        popv(7);
        return Lgreaterp(nil, v317, v316);

v320:
    stack[-1] = stack[-5];
    v316 = stack[0];
    v316 = negate(v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-6];
    v316 = Lash1(nil, stack[-2], v316);
    nil = C_nil;
    if (exception_pending()) goto v318;
    {
        Lisp_Object v321 = stack[-1];
        popv(7);
        return Lgreaterp(nil, v321, v316);
    }

v275:
    v317 = stack[-5];
    v316 = stack[-2];
        popv(7);
        return Lgreaterp(nil, v317, v316);

v175:
    v316 = (Lisp_Object)1; /* 0 */
    goto v132;

v84:
    v316 = (Lisp_Object)1; /* 0 */
    stack[-1] = v316;
    goto v37;

v7:
    v317 = stack[-5];
    v316 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Lgreaterp(nil, v317, v316);

v111:
    v317 = stack[-2];
    v316 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Llessp(nil, v317, v316);
/* error exit handlers */
v318:
    popv(7);
    return nil;
}



/* Code for get!-min!-degreelist */

static Lisp_Object CC_getKminKdegreelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-min-degreelist");
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
    v144 = v0;
/* end of prologue */
    v99 = v144;
    if (v99 == nil) goto v32;
    v99 = v144;
    v99 = qcdr(v99);
    if (v99 == nil) goto v131;
    v99 = v144;
    v99 = qcar(v99);
    stack[0] = qcar(v99);
    v99 = v144;
    v99 = qcdr(v99);
    v99 = CC_getKminKdegreelist(env, v99);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    {
        Lisp_Object v78 = stack[0];
        popv(6);
        fn = elt(env, 2); /* taymindegreel */
        return (*qfn2(fn))(qenv(fn), v78, v99);
    }

v131:
    v99 = v144;
    v99 = qcar(v99);
    v99 = qcar(v99);
    stack[-4] = v99;
    v99 = stack[-4];
    if (v99 == nil) goto v226;
    v99 = stack[-4];
    v99 = qcar(v99);
    stack[0] = v99;
    v99 = (Lisp_Object)1; /* 0 */
    v144 = v99;
    goto v117;

v117:
    v99 = stack[0];
    if (v99 == nil) goto v21;
    v99 = stack[0];
    v99 = qcar(v99);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v99 = (*qfn2(fn))(qenv(fn), v99, v144);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v144 = v99;
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v117;

v21:
    v99 = v144;
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    stack[-2] = v99;
    stack[-3] = v99;
    goto v5;

v5:
    v99 = stack[-4];
    v99 = qcdr(v99);
    stack[-4] = v99;
    v99 = stack[-4];
    if (v99 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v99 = stack[-4];
    v99 = qcar(v99);
    stack[0] = v99;
    v99 = (Lisp_Object)1; /* 0 */
    v144 = v99;
    goto v25;

v25:
    v99 = stack[0];
    if (v99 == nil) goto v128;
    v99 = stack[0];
    v99 = qcar(v99);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v99 = (*qfn2(fn))(qenv(fn), v99, v144);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v144 = v99;
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v25;

v128:
    v99 = v144;
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v99 = Lrplacd(nil, stack[-1], v99);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    goto v5;

v226:
    v99 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v99); }

v32:
    v99 = elt(env, 0); /* get!-min!-degreelist */
    {
        popv(6);
        fn = elt(env, 4); /* confusion */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v100:
    popv(6);
    return nil;
}



setup_type const u37_setup[] =
{
    {"scar",                    too_few_2,      CC_scar,       wrong_no_2},
    {"spmatlength",             CC_spmatlength, too_many_1,    wrong_no_1},
    {"sroot1",                  too_few_2,      CC_sroot1,     wrong_no_2},
    {"precision1",              too_few_2,      CC_precision1, wrong_no_2},
    {"r2oreaction",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2oreaction},
    {"cvitimes2",               too_few_2,      CC_cvitimes2,  wrong_no_2},
    {"mapcarcar",               CC_mapcarcar,   too_many_1,    wrong_no_1},
    {"reduce-weights",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKweights},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"evalgreaterp",            too_few_2,      CC_evalgreaterp,wrong_no_2},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"mk+equation",             too_few_2,      CC_mkLequation,wrong_no_2},
    {"pasf_fact",               CC_pasf_fact,   too_many_1,    wrong_no_1},
    {"aex_minus",               too_few_2,      CC_aex_minus,  wrong_no_2},
    {"lowupperlimitrd",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowupperlimitrd},
    {"mkbc",                    too_few_2,      CC_mkbc,       wrong_no_2},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"mv2sf",                   too_few_2,      CC_mv2sf,      wrong_no_2},
    {"dp_from_ei",              CC_dp_from_ei,  too_many_1,    wrong_no_1},
    {"nonmult",                 CC_nonmult,     too_many_1,    wrong_no_1},
    {"pst_mkpst",               CC_pst_mkpst,   too_many_1,    wrong_no_1},
    {"simpsqrt2",               CC_simpsqrt2,   too_many_1,    wrong_no_1},
    {"mksfpf",                  too_few_2,      CC_mksfpf,     wrong_no_2},
    {"cl_smsimpl-junct1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct1},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"vectorrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorrd},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"cr:onep",                 CC_crTonep,     too_many_1,    wrong_no_1},
    {"newsym1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_newsym1},
    {"replace2_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace2_parents},
    {"mo=zero",                 CC_moMzero,     too_many_1,    wrong_no_1},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"grpbf",                   too_few_2,      CC_grpbf,      wrong_no_2},
    {"get-min-degreelist",      CC_getKminKdegreelist,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u37", (two_args *)"10654 6462122 8287896", 0}
};

/* end of generated code */
