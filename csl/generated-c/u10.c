
/* $destdir\u10.c        Machine generated C code */

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


/* Code for exchk1 */

static Lisp_Object MS_CDECL CC_exchk1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "exchk1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v53:
    v49 = stack[-4];
    if (v49 == nil) goto v54;
    v49 = stack[-4];
    v49 = qcar(v49);
    v50 = qcar(v49);
    v49 = elt(env, 1); /* expt */
    if (!consp(v50)) goto v55;
    v50 = qcar(v50);
    if (!(v50 == v49)) goto v55;
    v51 = elt(env, 2); /* times */
    v49 = stack[-4];
    v49 = qcar(v49);
    v50 = qcdr(v49);
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v50 = list3(v51, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = elt(env, 3); /* simp!* */
    fn = elt(env, 4); /* simpexpon1 */
    v49 = (*qfn2(fn))(qenv(fn), v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v49;
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v49 = qcar(v49);
    if (is_number(v49)) goto v57;
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = stack[-2];
    v49 = Lassoc(nil, v50, v49);
    v50 = v49;
    if (v50 == nil) goto v58;
    stack[0] = v49;
    v50 = stack[-5];
    v49 = qcdr(v49);
    fn = elt(env, 5); /* addsq */
    v49 = (*qfn2(fn))(qenv(fn), v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = Lrplacd(nil, stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v59;

v59:
    v49 = stack[-4];
    v52 = qcdr(v49);
    v51 = stack[-3];
    v50 = stack[-2];
    v49 = stack[-1];
    stack[-4] = v52;
    stack[-3] = v51;
    stack[-2] = v50;
    stack[-1] = v49;
    goto v53;

v58:
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v51 = qcar(v49);
    v50 = stack[-5];
    v49 = stack[-2];
    v49 = acons(v51, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-2] = v49;
    goto v59;

v57:
    v50 = stack[-5];
    v49 = stack[-1];
    fn = elt(env, 6); /* assoc2 */
    v49 = (*qfn2(fn))(qenv(fn), v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v50 = v49;
    if (v50 == nil) goto v60;
    stack[0] = v49;
    v50 = qcar(v49);
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v49 = times2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = Lrplaca(nil, stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v59;

v60:
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v51 = qcar(v49);
    v50 = stack[-5];
    v49 = stack[-1];
    v49 = acons(v51, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-1] = v49;
    goto v59;

v55:
    v49 = stack[-4];
    v49 = qcar(v49);
    v50 = qcdr(v49);
    v49 = (Lisp_Object)17; /* 1 */
    if (v50 == v49) goto v61;
    v49 = stack[-4];
    v49 = qcdr(v49);
    stack[-5] = v49;
    stack[0] = elt(env, 1); /* expt */
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    fn = elt(env, 7); /* sqchk */
    v50 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v50 = list3(stack[0], v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = stack[-3];
    v49 = cons(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-3] = v49;
    v49 = stack[-5];
    stack[-4] = v49;
    goto v53;

v61:
    v49 = stack[-4];
    v49 = qcdr(v49);
    stack[-5] = v49;
    v49 = stack[-4];
    v49 = qcar(v49);
    v49 = qcar(v49);
    fn = elt(env, 7); /* sqchk */
    v50 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = stack[-3];
    v49 = cons(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-3] = v49;
    v49 = stack[-5];
    stack[-4] = v49;
    goto v53;

v54:
    v50 = stack[-1];
    v49 = stack[-2];
    v50 = Lappend(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v49 = stack[-3];
    {
        popv(7);
        fn = elt(env, 8); /* exchk2 */
        return (*qfn2(fn))(qenv(fn), v50, v49);
    }
/* error exit handlers */
v56:
    popv(7);
    return nil;
}



/* Code for rl_simpat */

static Lisp_Object CC_rl_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpat");
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
    v63 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpat!* */
    v63 = ncons(v63);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    {
        Lisp_Object v65 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v65, v63);
    }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for naryrd */

static Lisp_Object MS_CDECL CC_naryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "naryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryrd");
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
    fn = elt(env, 1); /* mathml */
    v54 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v67 = v54;
    v54 = v67;
    if (v54 == nil) goto v69;
    stack[0] = v67;
    v54 = CC_naryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v70 = stack[0];
        popv(2);
        return cons(v70, v54);
    }

v69:
    v54 = nil;
    { popv(2); return onevalue(v54); }
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v38, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
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
    v38 = v0;
/* end of prologue */
    v39 = v38;
    if (!consp(v39)) { popv(1); return onevalue(v38); }
    v39 = v38;
    v16 = qcar(v39);
    v39 = elt(env, 1); /* !:ps!: */
    if (v16 == v39) goto v75;
    v39 = v38;
    v16 = qcar(v39);
    v39 = elt(env, 2); /* dname */
    v39 = get(v16, v39);
    env = stack[0];
    if (!(v39 == nil)) { popv(1); return onevalue(v38); }

v75:
    v39 = (Lisp_Object)97; /* 6 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v38, v39);
    }
}



/* Code for flatindxl */

static Lisp_Object CC_flatindxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v85, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindxl");
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
    v32 = v0;
/* end of prologue */
    stack[-3] = v32;
    v32 = stack[-3];
    if (v32 == nil) goto v63;
    v32 = stack[-3];
    v32 = qcar(v32);
    v86 = v32;
    v32 = v86;
    if (!consp(v32)) goto v54;
    v85 = v86;
    v32 = elt(env, 2); /* minus */
    if (!consp(v85)) goto v72;
    v85 = qcar(v85);
    if (!(v85 == v32)) goto v72;
    v32 = v86;
    v32 = qcdr(v32);
    v32 = qcar(v32);
    goto v40;

v40:
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-1] = v32;
    stack[-2] = v32;
    goto v69;

v69:
    v32 = stack[-3];
    v32 = qcdr(v32);
    stack[-3] = v32;
    v32 = stack[-3];
    if (v32 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v32 = stack[-3];
    v32 = qcar(v32);
    v86 = v32;
    v32 = v86;
    if (!consp(v32)) goto v88;
    v85 = v86;
    v32 = elt(env, 2); /* minus */
    if (!consp(v85)) goto v57;
    v85 = qcar(v85);
    if (!(v85 == v32)) goto v57;
    v32 = v86;
    v32 = qcdr(v32);
    v32 = qcar(v32);
    goto v35;

v35:
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v32 = Lrplacd(nil, stack[0], v32);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-1] = v32;
    goto v69;

v57:
    v32 = v86;
    v32 = qcdr(v32);
    goto v35;

v88:
    v32 = v86;
    goto v35;

v72:
    v32 = v86;
    v32 = qcdr(v32);
    goto v40;

v54:
    v32 = v86;
    goto v40;

v63:
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v32); }
/* error exit handlers */
v87:
    popv(5);
    return nil;
}



/* Code for fortranop */

static Lisp_Object CC_fortranop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v90, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranop");
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
    v74 = v0;
/* end of prologue */
    v90 = v74;
    v65 = elt(env, 1); /* !*fortranop!* */
    v65 = get(v90, v65);
    if (v65 == nil) return onevalue(v74);
    else return onevalue(v65);
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypesf");
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

v91:
    v42 = stack[0];
    if (v42 == nil) goto v82;
    v42 = stack[0];
    fn = elt(env, 2); /* domain!*p */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (!(v42 == nil)) goto v82;
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    fn = elt(env, 3); /* getphystype */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (!(v42 == nil)) { popv(2); return onevalue(v42); }
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v91;

v82:
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v42); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for split!-road */

static Lisp_Object CC_splitKroad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-road");
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
    v93 = stack[-1];
    stack[-3] = qcar(v93);
    v93 = stack[-2];
    v95 = qcar(v93);
    v93 = stack[-2];
    v94 = qcdr(v93);
    v93 = stack[-1];
    v93 = qcdr(v93);
    v93 = qcar(v93);
    fn = elt(env, 1); /* sroad */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v95, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v93 = stack[-2];
    v95 = qcar(v93);
    v93 = stack[-2];
    v94 = qcdr(v93);
    v93 = stack[-1];
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    fn = elt(env, 1); /* sroad */
    v93 = (*qfnn(fn))(qenv(fn), 3, v95, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v33;
    {
        Lisp_Object v96 = stack[-3];
        Lisp_Object v97 = stack[0];
        popv(5);
        return list3(v96, v97, v93);
    }
/* error exit handlers */
v33:
    popv(5);
    return nil;
}



/* Code for lpriw */

static Lisp_Object CC_lpriw(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpriw");
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
    v99 = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    v98 = v99;
    if (v98 == nil) goto v42;
    v98 = v99;
    if (!(!consp(v98))) goto v42;
    v98 = v99;
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    goto v64;

v64:
    v98 = cons(stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[0] = v98;
    v98 = qvalue(elt(env, 1)); /* ofl!* */
    if (v98 == nil) goto v100;
    v98 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v98 == nil)) goto v53;
    v98 = qvalue(elt(env, 3)); /* !*nat */
    if (v98 == nil) goto v53;
    v98 = qvalue(elt(env, 4)); /* !*defn */
    if (!(v98 == nil)) goto v53;

v100:
    v98 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    goto v101;

v101:
    v98 = stack[0];
    fn = elt(env, 6); /* lpri */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v98 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v98 = stack[-1];
    if (v98 == nil) goto v69;
    v98 = stack[-1];
    v98 = qcdr(v98);
    v98 = Lwrs(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v98 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v98); }

v69:
    v98 = qvalue(elt(env, 1)); /* ofl!* */
    if (!(v98 == nil)) goto v53;
    v98 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v98); }

v53:
    v98 = qvalue(elt(env, 1)); /* ofl!* */
    stack[-1] = v98;
    v98 = qvalue(elt(env, 5)); /* nil */
    v98 = Lwrs(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    goto v101;

v42:
    v98 = v99;
    goto v64;
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactfmatch2");
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
    v75 = stack[0];
    if (!consp(v75)) goto v82;
    v75 = stack[0];
    v103 = qcar(v75);
    v75 = elt(env, 2); /* !~ */
    if (v103 == v75) goto v53;
    v75 = stack[0];
    v75 = qcar(v75);
    stack[-1] = CC_compactfmatch2(env, v75);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = CC_compactfmatch2(env, v75);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v39 = stack[-1];
        popv(3);
        return Lappend(nil, v39, v75);
    }

v53:
    v75 = stack[0];
    popv(3);
    return ncons(v75);

v82:
    v75 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v75); }
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord");
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
    v41 = v0;
/* end of prologue */
    v43 = qvalue(elt(env, 1)); /* ordering */
    v42 = elt(env, 2); /* lex */
    if (v43 == v42) goto v90;
    v42 = v41;
    v42 = qcar(v42);
    { popv(1); return onevalue(v42); }

v90:
    v42 = elt(env, 3); /* plus */
    v43 = v41;
    v42 = cons(v42, v43);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v42);
    }
/* error exit handlers */
v104:
    popv(1);
    return nil;
}



/* Code for raiseind!: */

static Lisp_Object CC_raiseindT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raiseind:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v0;
/* end of prologue */
    v65 = v64;
    if (!consp(v65)) return onevalue(v64);
    v64 = qcdr(v64);
    v64 = qcar(v64);
    return onevalue(v64);
}



/* Code for ordexn */

static Lisp_Object CC_ordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexn");
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
    stack[0] = nil;
    stack[-3] = nil;
    goto v69;

v69:
    v108 = stack[-1];
    if (v108 == nil) goto v67;
    v87 = stack[-2];
    v108 = stack[-1];
    v108 = qcar(v108);
    if (v87 == v108) goto v104;
    v108 = stack[-2];
    if (v108 == nil) goto v57;
    v87 = stack[-2];
    v108 = stack[-1];
    v108 = qcar(v108);
    fn = elt(env, 2); /* ordop */
    v108 = (*qfn2(fn))(qenv(fn), v87, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    if (v108 == nil) goto v57;
    v87 = stack[-2];
    v108 = stack[-3];
    v108 = cons(v87, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    v87 = Lreverse(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    v108 = stack[-1];
    v108 = Lappend(nil, v87, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v28 = stack[0];
        popv(5);
        return cons(v28, v108);
    }

v57:
    v108 = stack[-1];
    v87 = qcar(v108);
    v108 = stack[-3];
    v108 = cons(v87, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-1];
    v108 = qcdr(v108);
    stack[-1] = v108;
    v108 = stack[0];
    v108 = (v108 == nil ? lisp_true : nil);
    stack[0] = v108;
    goto v69;

v104:
    v108 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v108); }

v67:
    v87 = stack[-2];
    v108 = stack[-3];
    v108 = cons(v87, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    v108 = Lreverse(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v109 = stack[0];
        popv(5);
        return cons(v109, v108);
    }
/* error exit handlers */
v27:
    popv(5);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v110 = stack[-1];
    if (v110 == nil) goto v82;
    v110 = stack[-1];
    if (!consp(v110)) goto v53;
    v110 = stack[-1];
    v110 = qcar(v110);
    if (!consp(v110)) goto v53;
    v110 = stack[-1];
    v110 = qcar(v110);
    stack[-2] = qcar(v110);
    v110 = stack[-1];
    v110 = qcar(v110);
    v110 = qcdr(v110);
    stack[0] = CC_reduceKmodKp(env, v110);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v110 = stack[-1];
    v110 = qcdr(v110);
    v110 = CC_reduceKmodKp(env, v110);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    {
        Lisp_Object v112 = stack[-2];
        Lisp_Object v113 = stack[0];
        popv(4);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v112, v113, v110);
    }

v53:
    v110 = stack[-1];
    v110 = Lmodular_number(nil, v110);
    env = stack[-3];
    v111 = v110;
    v110 = v111;
    v110 = (Lisp_Object)zerop(v110);
    v110 = v110 ? lisp_true : nil;
    env = stack[-3];
    if (v110 == nil) { popv(4); return onevalue(v111); }
    v110 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v110); }

v82:
    v110 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v110); }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v116, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompare");
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
    v116 = stack[-1];
    v86 = stack[0];
    if (equal(v116, v86)) goto v44;
    v116 = stack[-1];
    v86 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v86 = (*qfn2(fn))(qenv(fn), v116, v86);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (v86 == nil) goto v104;
    v86 = elt(env, 2); /* less */
    { popv(3); return onevalue(v86); }

v104:
    v116 = stack[0];
    v86 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v86 = (*qfn2(fn))(qenv(fn), v116, v86);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (v86 == nil) goto v43;
    v86 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v86); }

v43:
    v86 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (v86 == nil) goto v113;
    v116 = stack[-1];
    v86 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v116, v86);
    }

v113:
    v86 = stack[-1];
    v86 = qcar(v86);
    v116 = qcdr(v86);
    v86 = stack[0];
    v86 = qcar(v86);
    v86 = qcdr(v86);
    v86 = CC_totalcompare(env, v116, v86);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v117 = v86;
    v116 = v117;
    v86 = elt(env, 1); /* equal */
    if (!(v116 == v86)) { popv(3); return onevalue(v117); }
    v86 = stack[-1];
    v116 = qcdr(v86);
    v86 = stack[0];
    v86 = qcdr(v86);
    stack[-1] = v116;
    stack[0] = v86;
    goto v69;

v44:
    v86 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v86); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for qqe_ofsf_chsimpterm */

static Lisp_Object CC_qqe_ofsf_chsimpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_chsimpterm");
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
    v120 = v0;
/* end of prologue */
    v119 = v120;
    if (!consp(v119)) { popv(3); return onevalue(v120); }
    v119 = v120;
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v73;

v73:
    v119 = stack[-1];
    if (v119 == nil) goto v101;
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = Lconsp(nil, v119);
    env = stack[-2];
    if (v119 == nil) goto v43;
    v119 = stack[-1];
    v119 = qcar(v119);
    fn = elt(env, 4); /* qqe_op */
    v120 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v119 = elt(env, 2); /* expt */
    if (!(v120 == v119)) goto v43;
    v119 = stack[-1];
    v119 = qcar(v119);
    fn = elt(env, 5); /* qqe_arg2l */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v119 = Lconsp(nil, v119);
    env = stack[-2];
    if (v119 == nil) goto v43;
    v119 = stack[-1];
    v119 = qcar(v119);
    fn = elt(env, 5); /* qqe_arg2l */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    fn = elt(env, 4); /* qqe_op */
    v120 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v119 = elt(env, 3); /* (ltail rtail) */
    v119 = Lmemq(nil, v120, v119);
    if (v119 == nil) goto v43;
    stack[0] = stack[-1];
    v119 = stack[-1];
    v119 = qcar(v119);
    fn = elt(env, 6); /* qqe_chsimpterm */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    fn = elt(env, 7); /* setcar */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    goto v70;

v70:
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v73;

v43:
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = Lconsp(nil, v119);
    env = stack[-2];
    if (v119 == nil) goto v70;
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = CC_qqe_ofsf_chsimpterm(env, v119);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    goto v70;

v101:
    v119 = nil;
    { popv(3); return onevalue(v119); }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for qsort */

static Lisp_Object CC_qsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qsort");
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
    v122 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    v121 = v122;
    if (v121 == nil) goto v89;
    v121 = v122;
    v121 = qcar(v121);
    stack[-3] = v121;
    v121 = v122;
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v53;

v53:
    v121 = stack[0];
    if (v121 == nil) goto v78;
    v122 = stack[-3];
    v121 = stack[0];
    v121 = qcar(v121);
    fn = elt(env, 2); /* ordop */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    if (v121 == nil) goto v124;
    v121 = stack[0];
    v122 = qcar(v121);
    v121 = stack[-1];
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-1] = v121;
    goto v42;

v42:
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v53;

v124:
    v121 = stack[0];
    v122 = qcar(v121);
    v121 = stack[-2];
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-2] = v121;
    goto v42;

v78:
    v121 = stack[-2];
    stack[0] = CC_qsort(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-2] = stack[-3];
    v121 = stack[-1];
    v121 = CC_qsort(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v121 = cons(stack[-2], v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v125 = stack[0];
        popv(5);
        return Lappend(nil, v125, v121);
    }

v89:
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v121); }
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
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
    v130 = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    stack[-5] = v130;
    v130 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v130;
    v130 = stack[0];
    stack[-1] = v130;
    goto v74;

v74:
    v130 = stack[-1];
    if (v130 == nil) goto v119;
    v130 = stack[-1];
    v130 = qcar(v130);
    stack[0] = v130;
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcar(v130);
    if (!(v130 == nil)) goto v41;
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v131 = qcar(v130);
    stack[-2] = v131;
    v130 = stack[-3];
    v130 = (Lisp_Object)greaterp2(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v130 = v130 ? lisp_true : nil;
    env = stack[-6];
    if (v130 == nil) goto v41;
    v130 = stack[0];
    v131 = qcdr(v130);
    v130 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v130 = (*qfn2(fn))(qenv(fn), v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    if (v130 == nil) goto v41;
    v130 = stack[0];
    v130 = qcdr(v130);
    stack[-4] = v130;
    v130 = stack[-2];
    stack[-3] = v130;
    goto v41;

v41:
    v130 = stack[-1];
    v130 = qcdr(v130);
    stack[-1] = v130;
    goto v74;

v119:
    v130 = stack[-4];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v131 = qcar(v130);
    v130 = stack[-4];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcar(v130);
    v130 = (Lisp_Object)greaterp2(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v130 = v130 ? lisp_true : nil;
    if (v130 == nil) goto v132;
    v130 = (Lisp_Object)17; /* 1 */
    goto v133;

v133:
    v131 = stack[-4];
    popv(7);
    return cons(v131, v130);

v132:
    v130 = (Lisp_Object)1; /* 0 */
    goto v133;
/* error exit handlers */
v24:
    popv(7);
    return nil;
}



/* Code for ps!:putv */

static Lisp_Object MS_CDECL CC_psTputv(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v129, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:putv");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:putv");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    v135 = v0;
/* end of prologue */
    v129 = v135;
    v34 = elt(env, 1); /* !:ps!: */
    if (!consp(v129)) goto v124;
    v129 = qcar(v129);
    if (!(v129 == v34)) goto v124;
    v34 = v135;
    v34 = qcdr(v34);
    if (symbolp(v34)) goto v67;
    v34 = v135;
    v135 = qcdr(v34);
    v129 = stack[-1];
    v34 = stack[0];
    *(Lisp_Object *)((char *)v135 + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL))) = v34;
    { popv(3); return onevalue(v34); }

v67:
    v34 = v135;
    v34 = qcdr(v34);
    fn = elt(env, 5); /* eval */
    v135 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v129 = stack[-1];
    v34 = stack[0];
    *(Lisp_Object *)((char *)v135 + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL))) = v34;
    { popv(3); return onevalue(v34); }

v124:
    v34 = elt(env, 2); /* "PS:PUTV: not a ps" */
    v129 = v135;
    v34 = list2(v34, v129);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    v129 = v34;
    v34 = v129;
    qvalue(elt(env, 3)) = v34; /* errmsg!* */
    v34 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v34 == nil)) goto v35;
    v34 = v129;
    fn = elt(env, 6); /* lprie */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    goto v35;

v35:
    v34 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v34 = nil;
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v269, v270, v271, v272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp");
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
    v268 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v268; /* varstack!* */
    v268 = stack[-5];
    v268 = integerp(v268);
    if (v268 == nil) goto v111;
    v269 = stack[-5];
    v268 = (Lisp_Object)1; /* 0 */
    if (v269 == v268) goto v42;
    v268 = qvalue(elt(env, 3)); /* dmode!* */
    if (!(v268 == nil)) goto v81;
    v269 = stack[-5];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v69:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v268); }

v81:
    v269 = stack[-5];
    v268 = qvalue(elt(env, 1)); /* varstack!* */
    v268 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    qvalue(elt(env, 1)) = v268; /* varstack!* */
    v269 = qvalue(elt(env, 6)); /* simpcount!* */
    v268 = qvalue(elt(env, 7)); /* simplimit!* */
    v268 = (Lisp_Object)greaterp2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    v268 = v268 ? lisp_true : nil;
    env = stack[-7];
    if (v268 == nil) goto v133;
    v268 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v268; /* simpcount!* */
    v268 = elt(env, 8); /* "Simplification recursion too deep" */
    v269 = v268;
    v268 = v269;
    qvalue(elt(env, 9)) = v268; /* errmsg!* */
    v268 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v268 == nil)) goto v274;
    v268 = v269;
    fn = elt(env, 41); /* lprie */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v274;

v274:
    v268 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v123;

v123:
    v268 = qvalue(elt(env, 6)); /* simpcount!* */
    v268 = add1(v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    qvalue(elt(env, 6)) = v268; /* simpcount!* */
    v268 = stack[-5];
    if (!consp(v268)) goto v275;
    v268 = stack[-5];
    v268 = qcar(v268);
    if (!(symbolp(v268))) goto v276;
    v268 = stack[-5];
    v268 = qcar(v268);
    if (v268 == nil) goto v276;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 21); /* opfn */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-7];
    if (v268 == nil) goto v277;
    v268 = stack[-5];
    fn = elt(env, 42); /* opfneval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    fn = elt(env, 43); /* getrtype */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = v268;
    if (v268 == nil) goto v278;
    v268 = elt(env, 22); /* yetunknowntype */
    if (!(v269 == v268)) goto v279;
    v268 = stack[-1];
    fn = elt(env, 44); /* reval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    fn = elt(env, 43); /* getrtype */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    if (!(v268 == nil)) goto v279;
    v268 = stack[-1];
    v268 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v279:
    v269 = stack[-5];
    v268 = elt(env, 23); /* "scalar" */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v280:
    v268 = nil;
    goto v69;

v278:
    v268 = stack[-1];
    fn = elt(env, 46); /* simp_without_resimp */
    v269 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v277:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 24); /* psopfn */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v281;
    stack[0] = stack[-1];
    v268 = stack[-5];
    fn = elt(env, 48); /* argnochk */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = qcdr(v268);
    v268 = Lapply1(nil, stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    fn = elt(env, 43); /* getrtype */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    if (v268 == nil) goto v282;
    v269 = stack[-5];
    v268 = elt(env, 23); /* "scalar" */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v282:
    v269 = stack[-1];
    v268 = stack[-5];
    if (equal(v269, v268)) goto v283;
    v268 = stack[-1];
    fn = elt(env, 46); /* simp_without_resimp */
    v269 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v283:
    v270 = stack[-1];
    v269 = (Lisp_Object)17; /* 1 */
    v268 = (Lisp_Object)17; /* 1 */
    v268 = acons(v270, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = (Lisp_Object)17; /* 1 */
    v269 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v281:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 25); /* polyfn */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v284;
    v268 = stack[-5];
    fn = elt(env, 48); /* argnochk */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-1];
    if (!consp(v268)) goto v285;
    v269 = elt(env, 26); /* "Apply called with non-id arg" */
    v268 = stack[-1];
    v268 = list2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = v268;
    v268 = v269;
    qvalue(elt(env, 9)) = v268; /* errmsg!* */
    v268 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v268 == nil)) goto v286;
    v268 = v269;
    fn = elt(env, 41); /* lprie */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v286;

v286:
    v268 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = nil;
    v269 = v268;
    goto v287;

v287:
    v268 = (Lisp_Object)17; /* 1 */
    v269 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v285:
    stack[-4] = stack[-1];
    v268 = stack[-5];
    v268 = qcdr(v268);
    stack[-3] = v268;
    v268 = stack[-3];
    if (v268 == nil) goto v288;
    v268 = stack[-3];
    v268 = qcar(v268);
    fn = elt(env, 49); /* simp!* */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v270 = v268;
    v268 = v270;
    v269 = qcdr(v268);
    v268 = (Lisp_Object)17; /* 1 */
    if (v269 == v268) goto v289;
    v268 = v270;
    v268 = qcar(v268);
    if (v268 == nil) goto v290;
    v269 = v270;
    v268 = elt(env, 27); /* prepf */
    fn = elt(env, 50); /* sqform */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = v268;
    goto v291;

v291:
    v268 = elt(env, 28); /* polynomial */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v292;

v292:
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    stack[-2] = v268;
    goto v293;

v293:
    v268 = stack[-3];
    v268 = qcdr(v268);
    stack[-3] = v268;
    v268 = stack[-3];
    if (v268 == nil) goto v294;
    stack[0] = stack[-1];
    v268 = stack[-3];
    v268 = qcar(v268);
    fn = elt(env, 49); /* simp!* */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v270 = v268;
    v268 = v270;
    v269 = qcdr(v268);
    v268 = (Lisp_Object)17; /* 1 */
    if (v269 == v268) goto v295;
    v268 = v270;
    v268 = qcar(v268);
    if (v268 == nil) goto v296;
    v269 = v270;
    v268 = elt(env, 27); /* prepf */
    fn = elt(env, 50); /* sqform */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = v268;
    goto v297;

v297:
    v268 = elt(env, 28); /* polynomial */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v298;

v298:
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = Lrplacd(nil, stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-1];
    v268 = qcdr(v268);
    stack[-1] = v268;
    goto v293;

v296:
    v268 = (Lisp_Object)1; /* 0 */
    v269 = v268;
    goto v297;

v295:
    v268 = v270;
    v268 = qcar(v268);
    goto v298;

v294:
    v268 = stack[-2];
    goto v299;

v299:
    fn = elt(env, 51); /* apply */
    v268 = (*qfn2(fn))(qenv(fn), stack[-4], v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = v268;
    goto v287;

v290:
    v268 = (Lisp_Object)1; /* 0 */
    v269 = v268;
    goto v291;

v289:
    v268 = v270;
    v268 = qcar(v268);
    goto v292;

v288:
    v268 = qvalue(elt(env, 2)); /* nil */
    goto v299;

v284:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 29); /* opmtch */
    v268 = get(v269, v268);
    env = stack[-7];
    if (v268 == nil) goto v300;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 30); /* simpfn */
    v269 = get(v269, v268);
    env = stack[-7];
    v268 = elt(env, 31); /* simpiden */
    if (v269 == v268) goto v300;
    v268 = stack[-5];
    fn = elt(env, 52); /* opmtchrevop */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v300;
    v268 = stack[-1];
    v269 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v300:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 30); /* simpfn */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v301;
    stack[0] = stack[-1];
    v269 = stack[-1];
    v268 = elt(env, 31); /* simpiden */
    if (v269 == v268) goto v302;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 32); /* full */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-7];
    if (!(v268 == nil)) goto v302;
    v268 = stack[-5];
    fn = elt(env, 48); /* argnochk */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = qcdr(v268);
    goto v303;

v303:
    v269 = Lapply1(nil, stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v302:
    v268 = stack[-5];
    fn = elt(env, 48); /* argnochk */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v303;

v301:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 33); /* rtype */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v304;
    v269 = stack[-1];
    v268 = elt(env, 34); /* getelemfn */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v304;
    v269 = stack[-1];
    v268 = stack[-5];
    v268 = Lapply1(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v304:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 35); /* boolean */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-7];
    if (!(v268 == nil)) goto v305;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 36); /* infix */
    v268 = get(v269, v268);
    env = stack[-7];
    if (!(v268 == nil)) goto v305;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 39); /* nochange */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-7];
    if (v268 == nil) goto v306;
    v268 = stack[-5];
    fn = elt(env, 53); /* eval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v306:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 24); /* psopfn */
    v268 = get(v269, v268);
    env = stack[-7];
    if (!(v268 == nil)) goto v307;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 40); /* rtypefn */
    v268 = get(v269, v268);
    env = stack[-7];
    if (!(v268 == nil)) goto v307;
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 16); /* "operator" */
    fn = elt(env, 54); /* redmsg */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    v268 = qcar(v268);
    fn = elt(env, 55); /* mkop */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = stack[-5];
    v268 = qvalue(elt(env, 1)); /* varstack!* */
    v268 = Ldelete(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    qvalue(elt(env, 1)) = v268; /* varstack!* */
    v268 = stack[-5];
    v269 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v307:
    v269 = stack[-5];
    v268 = elt(env, 23); /* "scalar" */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v305:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 37); /* prtch */
    v268 = get(v269, v268);
    env = stack[-7];
    stack[-1] = v268;
    if (v268 == nil) goto v308;
    v268 = stack[-1];
    v269 = v268;
    goto v309;

v309:
    v268 = elt(env, 38); /* "algebraic operator" */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v308:
    v268 = stack[-5];
    v268 = qcar(v268);
    v269 = v268;
    goto v309;

v276:
    v268 = stack[-5];
    v268 = qcar(v268);
    if (!consp(v268)) goto v310;
    v268 = stack[-5];
    v268 = qcar(v268);
    v268 = qcar(v268);
    if (!(symbolp(v268))) goto v311;
    v268 = stack[-5];
    v268 = qcar(v268);
    v269 = qcar(v268);
    v268 = elt(env, 17); /* name */
    v268 = get(v269, v268);
    env = stack[-7];
    if (v268 == nil) goto v311;
    v269 = stack[-5];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v311:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 18); /* mat */
    if (!consp(v269)) goto v312;
    v269 = qcar(v269);
    if (!(v269 == v268)) goto v312;
    v268 = stack[-5];
    v268 = qcdr(v268);
    fn = elt(env, 56); /* revlis */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[-1] = v268;
    fn = elt(env, 57); /* numlis */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    if (v268 == nil) goto v312;
    v268 = stack[-1];
    v269 = Llength(nil, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = (Lisp_Object)33; /* 2 */
    if (!(v269 == v268)) goto v312;
    v268 = stack[-5];
    v268 = qcar(v268);
    v269 = qcdr(v268);
    v268 = stack[-1];
    v268 = qcar(v268);
    fn = elt(env, 58); /* pnth */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v269 = qcar(v268);
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = qcar(v268);
    fn = elt(env, 58); /* pnth */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = qcar(v268);
    v269 = CC_simp(env, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v312:
    v272 = elt(env, 19); /* "Syntax error:" */
    v271 = stack[-5];
    v270 = elt(env, 20); /* "invalid" */
    v269 = qvalue(elt(env, 2)); /* nil */
    v268 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 59); /* msgpri */
    v268 = (*qfnn(fn))(qenv(fn), 5, v272, v271, v270, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v310:
    v268 = stack[-5];
    v269 = qcar(v268);
    v268 = elt(env, 16); /* "operator" */
    fn = elt(env, 45); /* typerr */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v280;

v275:
    v268 = stack[-5];
    fn = elt(env, 60); /* simpatom */
    v269 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v268 = stack[-5];
    fn = elt(env, 47); /* !*ssave */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v133:
    v269 = stack[-5];
    v268 = elt(env, 11); /* !*sq */
    if (!consp(v269)) goto v313;
    v269 = qcar(v269);
    if (!(v269 == v268)) goto v313;
    v268 = stack[-5];
    v268 = qcdr(v268);
    v268 = qcdr(v268);
    v268 = qcar(v268);
    if (v268 == nil) goto v313;
    v268 = qvalue(elt(env, 12)); /* !*resimp */
    if (!(v268 == nil)) goto v313;
    v268 = stack[-5];
    v268 = qcdr(v268);
    v268 = qcar(v268);
    goto v69;

v313:
    v268 = qvalue(elt(env, 13)); /* !*uncached */
    if (!(v268 == nil)) goto v123;
    v269 = stack[-5];
    v268 = qvalue(elt(env, 14)); /* alglist!* */
    v268 = qcar(v268);
    v268 = Lassoc(nil, v269, v268);
    stack[-1] = v268;
    if (v268 == nil) goto v123;
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = qcar(v268);
    if (v268 == nil) goto v314;
    v268 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 15)) = v268; /* !*sub2 */
    goto v314;

v314:
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = qcdr(v268);
    goto v69;

v42:
    v269 = qvalue(elt(env, 2)); /* nil */
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v69;

v111:
    v269 = stack[-5];
    v268 = qvalue(elt(env, 1)); /* varstack!* */
    v268 = Lmember(nil, v269, v268);
    if (v268 == nil) goto v81;
    v272 = qvalue(elt(env, 2)); /* nil */
    v271 = stack[-5];
    v270 = elt(env, 4); /* "improperly defined in terms of itself" */
    v269 = qvalue(elt(env, 2)); /* nil */
    v268 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 59); /* msgpri */
    v268 = (*qfnn(fn))(qenv(fn), 5, v272, v271, v270, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    goto v81;
/* error exit handlers */
v273:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for getmat */

static Lisp_Object MS_CDECL CC_getmat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v88, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmat");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v35 = qvalue(elt(env, 1)); /* !*modular */
    if (v35 == nil) goto v44;
    v35 = elt(env, 2); /* modular */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    fn = elt(env, 6); /* off */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v35 = elt(env, 3); /* mod_was_on */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    fn = elt(env, 7); /* on */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    goto v44;

v44:
    v35 = stack[-1];
    v35 = integerp(v35);
    if (v35 == nil) goto v115;
    v35 = stack[-1];
    goto v73;

v73:
    stack[-1] = v35;
    v35 = stack[0];
    v35 = integerp(v35);
    if (v35 == nil) goto v75;
    v35 = stack[0];
    goto v41;

v41:
    stack[0] = v35;
    v35 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v35 == nil) goto v96;
    v35 = elt(env, 2); /* modular */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    fn = elt(env, 7); /* on */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v35 = elt(env, 3); /* mod_was_on */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    fn = elt(env, 6); /* off */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    goto v96;

v96:
    v98 = stack[-2];
    v88 = stack[-1];
    v35 = stack[0];
    v35 = list3(v98, v88, v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 8); /* unchecked_getmatelem */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v75:
    v35 = stack[0];
    fn = elt(env, 9); /* reval */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    goto v41;

v115:
    v35 = stack[-1];
    fn = elt(env, 9); /* reval */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    goto v73;
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for xord_lex */

static Lisp_Object CC_xord_lex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v98, v99, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_lex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v1;
    v99 = v0;
/* end of prologue */

v44:
    v88 = v99;
    if (v88 == nil) goto v53;
    v88 = v99;
    v118 = qcar(v88);
    v88 = (Lisp_Object)17; /* 1 */
    if (v118 == v88) goto v53;
    v88 = v98;
    if (v88 == nil) goto v67;
    v88 = v98;
    v118 = qcar(v88);
    v88 = (Lisp_Object)17; /* 1 */
    if (v118 == v88) goto v67;
    v88 = v99;
    v118 = qcar(v88);
    v88 = v98;
    v88 = qcar(v88);
    if (v118 == v88) goto v107;
    v88 = v99;
    v88 = qcar(v88);
    v98 = qcar(v98);
    {
        fn = elt(env, 3); /* factorordp */
        return (*qfn2(fn))(qenv(fn), v88, v98);
    }

v107:
    v88 = v99;
    v88 = qcdr(v88);
    v99 = v88;
    v88 = v98;
    v88 = qcdr(v88);
    v98 = v88;
    goto v44;

v67:
    v88 = qvalue(elt(env, 2)); /* t */
    return onevalue(v88);

v53:
    v88 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v88);
}



/* Code for deletemult!* */

static Lisp_Object CC_deletemultH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113, v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletemult*");
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
    stack[0] = v0;
/* end of prologue */
    v112 = stack[0];
    if (v112 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v112 = stack[0];
    v112 = qcar(v112);
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-2] = v112;
    v112 = stack[0];
    v112 = qcdr(v112);
    stack[0] = v112;
    v112 = stack[0];
    stack[-1] = v112;
    goto v66;

v66:
    v112 = stack[-1];
    if (v112 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v112 = stack[-1];
    v112 = qcar(v112);
    v76 = v112;
    v113 = v76;
    v112 = stack[-2];
    v112 = Lmember(nil, v113, v112);
    if (!(v112 == nil)) goto v102;
    stack[0] = stack[-2];
    v112 = v76;
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v112 = Lnconc(nil, stack[0], v112);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    goto v102;

v102:
    v112 = stack[-1];
    v112 = qcdr(v112);
    stack[-1] = v112;
    goto v66;
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for contr2!-strand */

static Lisp_Object MS_CDECL CC_contr2Kstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v126, v130, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "contr2-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2-strand");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v91:
    v127 = stack[-3];
    if (v127 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v127 = stack[-3];
    v126 = qcar(v127);
    v127 = stack[-2];
    fn = elt(env, 3); /* contrsp */
    v127 = (*qfn2(fn))(qenv(fn), v126, v127);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v130 = v127;
    v127 = v130;
    if (v127 == nil) goto v128;
    v127 = v130;
    v126 = qcar(v127);
    v127 = v130;
    v127 = qcdr(v127);
    v127 = Lmember(nil, v126, v127);
    if (v127 == nil) goto v102;
    v126 = stack[-3];
    v127 = stack[-1];
        popv(5);
        return Lappend(nil, v126, v127);

v102:
    v127 = stack[0];
    if (v127 == nil) goto v118;
    v127 = stack[-3];
    v126 = qcdr(v127);
    v127 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* contr2 */
        return (*qfnn(fn))(qenv(fn), 3, v130, v126, v127);
    }

v118:
    v127 = stack[-3];
    v126 = qcdr(v127);
    v127 = stack[-1];
    fn = elt(env, 4); /* contr2 */
    v131 = (*qfnn(fn))(qenv(fn), 3, v130, v126, v127);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v130 = stack[-2];
    v126 = qvalue(elt(env, 1)); /* nil */
    v127 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v131;
    stack[-2] = v130;
    stack[-1] = v126;
    stack[0] = v127;
    goto v91;

v128:
    v127 = stack[-3];
    stack[0] = qcdr(v127);
    v127 = stack[-3];
    v126 = qcar(v127);
    v127 = stack[-1];
    v126 = cons(v126, v127);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-4];
    v127 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = stack[0];
    stack[-1] = v126;
    stack[0] = v127;
    goto v91;
/* error exit handlers */
v320:
    popv(5);
    return nil;
}



/* Code for copyd */

static Lisp_Object CC_copyd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copyd");
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
    v27 = stack[0];
    fn = elt(env, 6); /* getd */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    v28 = v27;
    if (v28 == nil) goto v73;
    v109 = stack[-1];
    v28 = v27;
    v28 = qcar(v28);
    v27 = qcdr(v27);
    fn = elt(env, 7); /* putd */
    v27 = (*qfnn(fn))(qenv(fn), 3, v109, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    v27 = stack[0];
    if (!symbolp(v27)) v27 = nil;
    else { v27 = qfastgets(v27);
           if (v27 != nil) { v27 = elt(v27, 1); /* lose */
#ifdef RECORD_GET
             if (v27 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v27 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v27 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v27 == SPID_NOPROP) v27 = nil; else v27 = lisp_true; }}
#endif
    if (v27 == nil) goto v324;
    v27 = stack[-1];
    v28 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    v27 = elt(env, 5); /* lose */
    v27 = Lflag(nil, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    goto v324;

v324:
    v28 = stack[0];
    v27 = elt(env, 1); /* !*savedef */
    v28 = get(v28, v27);
    env = stack[-2];
    v27 = v28;
    if (v28 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v109 = stack[-1];
    v28 = elt(env, 1); /* !*savedef */
    v27 = Lputprop(nil, 3, v109, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v73:
    v28 = qvalue(elt(env, 1)); /* !*savedef */
    v27 = elt(env, 1); /* !*savedef */
    if (v28 == v27) goto v324;
    v28 = stack[0];
    v27 = elt(env, 2); /* "has no definition in copyd" */
    v27 = list2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    v28 = v27;
    v27 = v28;
    qvalue(elt(env, 3)) = v27; /* errmsg!* */
    v27 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v27 == nil)) goto v71;
    v27 = v28;
    fn = elt(env, 8); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    goto v71;

v71:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    goto v324;
/* error exit handlers */
v323:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
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
    goto v101;

v101:
    v71 = stack[-1];
    if (v71 == nil) goto v62;
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = stack[0];
    v71 = qcar(v71);
    v72 = difference2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v71 = stack[-2];
    v71 = cons(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-2] = v71;
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v101;

v62:
    v71 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formop");
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
    stack[-2] = nil;
    goto v101;

v101:
    v322 = stack[-1];
    if (!consp(v322)) goto v69;
    v322 = stack[-1];
    v322 = qcar(v322);
    if (!consp(v322)) goto v69;
    v322 = stack[-1];
    v322 = qcar(v322);
    stack[0] = qcar(v322);
    v322 = stack[-1];
    v322 = qcar(v322);
    v322 = qcdr(v322);
    v322 = CC_formop(env, v322);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    fn = elt(env, 1); /* multop */
    v37 = (*qfn2(fn))(qenv(fn), stack[0], v322);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v322 = stack[-2];
    v322 = cons(v37, v322);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    stack[-2] = v322;
    v322 = stack[-1];
    v322 = qcdr(v322);
    stack[-1] = v322;
    goto v101;

v69:
    v322 = stack[-1];
    v37 = v322;
    goto v53;

v53:
    v322 = stack[-2];
    if (v322 == nil) { popv(4); return onevalue(v37); }
    v322 = stack[-2];
    v322 = qcar(v322);
    fn = elt(env, 2); /* raddf */
    v322 = (*qfn2(fn))(qenv(fn), v322, v37);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v37 = v322;
    v322 = stack[-2];
    v322 = qcdr(v322);
    stack[-2] = v322;
    goto v53;
/* error exit handlers */
v88:
    popv(4);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_diff");
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
    v89 = v1;
    v64 = v0;
/* end of prologue */
    stack[0] = v64;
    fn = elt(env, 1); /* mo_neg */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    {
        Lisp_Object v74 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v74, v89);
    }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for ofsf_smwmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v16, v21, v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v3;
    v21 = v2;
    v92 = v1;
    v93 = v0;
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v38 == nil) goto v43;
    v38 = v93;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v38, v92, v21, v16);
    }

v43:
    v38 = v93;
    {
        fn = elt(env, 3); /* ofsf_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v38, v92, v21, v16);
    }
}



/* Code for qqe_ofsf_prepat */

static Lisp_Object CC_qqe_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_prepat");
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
    v90 = stack[0];
    fn = elt(env, 1); /* qqe_op */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    fn = elt(env, 2); /* qqe_rqopp */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    if (v90 == nil) goto v63;
    v90 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* qqe_prepat */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v63:
    v90 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* ofsf_prepat */
        return (*qfn1(fn))(qenv(fn), v90);
    }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for cl_susiminlevel */

static Lisp_Object CC_cl_susiminlevel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v107, v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiminlevel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v1;
    v72 = v0;
/* end of prologue */
    v107 = v72;
    v103 = elt(env, 1); /* ignore */
    if (v107 == v103) return onevalue(v71);
    v107 = v71;
    v103 = elt(env, 1); /* ignore */
    if (v107 == v103) return onevalue(v72);
    v103 = v72;
    v107 = v71;
    {
        fn = elt(env, 2); /* min */
        return (*qfn2(fn))(qenv(fn), v103, v107);
    }
}



/* Code for ibalp_getnewwl */

static Lisp_Object CC_ibalp_getnewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v265, v326, v27, v28, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getnewwl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v27 = nil;
    v265 = v28;
    v265 = qcar(v265);
    v109 = v265;
    goto v325;

v325:
    v265 = v109;
    if (v265 == nil) goto v62;
    v265 = v27;
    if (!(v265 == nil)) goto v62;
    v265 = v109;
    v265 = qcar(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    if (!(v265 == nil)) goto v54;
    v265 = v109;
    v326 = qcar(v265);
    v265 = v28;
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = Lmemq(nil, v326, v265);
    if (!(v265 == nil)) goto v54;
    v265 = v109;
    v265 = qcar(v265);
    v27 = v265;
    goto v54;

v54:
    v265 = v109;
    v265 = qcdr(v265);
    v109 = v265;
    goto v325;

v62:
    v265 = v28;
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v109 = v265;
    goto v113;

v113:
    v265 = v109;
    if (v265 == nil) return onevalue(v27);
    v265 = v27;
    if (!(v265 == nil)) return onevalue(v27);
    v265 = v109;
    v265 = qcar(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    if (!(v265 == nil)) goto v118;
    v265 = v109;
    v326 = qcar(v265);
    v265 = v28;
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = Lmemq(nil, v326, v265);
    if (!(v265 == nil)) goto v118;
    v265 = v109;
    v265 = qcar(v265);
    v27 = v265;
    goto v118;

v118:
    v265 = v109;
    v265 = qcdr(v265);
    v109 = v265;
    goto v113;
}



/* Code for aex_simplenullp */

static Lisp_Object CC_aex_simplenullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_simplenullp");
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
    v44 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_nullp */
        return (*qfn1(fn))(qenv(fn), v44);
    }
/* error exit handlers */
v101:
    popv(1);
    return nil;
}



/* Code for sub_math */

static Lisp_Object MS_CDECL CC_sub_math(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "sub_math");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub_math");
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
    stack[-1] = nil;
    v60 = qvalue(elt(env, 1)); /* char */
    v315 = elt(env, 2); /* (a p p l y) */
    if (equal(v60, v315)) goto v69;
    v60 = qvalue(elt(env, 1)); /* char */
    v315 = elt(env, 5); /* (v e c t o r) */
    if (equal(v60, v315)) goto v107;
    v315 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v60 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v315 = qvalue(elt(env, 8)); /* rdelems!* */
    v315 = Lassoc(nil, v60, v315);
    stack[0] = v315;
    if (v315 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v315 = stack[0];
    v315 = qcdr(v315);
    v60 = qcar(v315);
    v315 = nil;
    fn = elt(env, 10); /* apply */
    v315 = (*qfn2(fn))(qenv(fn), v60, v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    stack[-1] = v315;
    v315 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v60 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v315 = stack[0];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcar(v315);
    if (equal(v60, v315)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v315 = stack[0];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v60 = qcar(v315);
    v315 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 11); /* errorml */
    v315 = (*qfn2(fn))(qenv(fn), v60, v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v107:
    fn = elt(env, 12); /* vectorrd */
    v315 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    stack[-1] = v315;
    v60 = qvalue(elt(env, 1)); /* char */
    v315 = elt(env, 6); /* (!/ v e c t o r) */
    if (equal(v60, v315)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v60 = elt(env, 7); /* "</vector>" */
    v315 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 11); /* errorml */
    v315 = (*qfn2(fn))(qenv(fn), v60, v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v69:
    fn = elt(env, 13); /* applyml */
    v315 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    stack[-1] = v315;
    v60 = qvalue(elt(env, 1)); /* char */
    v315 = elt(env, 3); /* (!/ a p p l y) */
    if (equal(v60, v315)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v60 = elt(env, 4); /* "</apply>" */
    v315 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 11); /* errorml */
    v315 = (*qfn2(fn))(qenv(fn), v60, v315);
    nil = C_nil;
    if (exception_pending()) goto v126;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v21, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcone?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v0;
/* end of prologue */
    v16 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v16 == nil) goto v54;
    v21 = v92;
    v16 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v21, v16);

v54:
    v16 = v92;
    v21 = qcdr(v16);
    v16 = (Lisp_Object)17; /* 1 */
    if (v21 == v16) goto v134;
    v16 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v16);

v134:
    v16 = v92;
    v21 = qcar(v16);
    v16 = (Lisp_Object)17; /* 1 */
    v16 = (v21 == v16 ? lisp_true : nil);
    return onevalue(v16);
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksgnsq");
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
    v97 = v0;
/* end of prologue */
    v96 = v97;
    fn = elt(env, 1); /* evenfree */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v97 = v96;
    if (v96 == nil) goto v62;
    v112 = v97;
    v96 = (Lisp_Object)17; /* 1 */
    if (v112 == v96) goto v42;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v96 = (Lisp_Object)17; /* 1 */
    v96 = cons(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v96 = list2(stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v42:
    v97 = (Lisp_Object)-15; /* -1 */
    v96 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v97, v96);

v62:
    v97 = (Lisp_Object)17; /* 1 */
    v96 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v97, v96);
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for intexprnp */

static Lisp_Object CC_intexprnp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v129, v135, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intexprnp");
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
    v129 = v1;
    v135 = v0;
/* end of prologue */
    v34 = v135;
    if (!consp(v34)) goto v44;
    v34 = v135;
    v34 = qcar(v34);
    if (symbolp(v34)) goto v111;
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v34); }

v111:
    v34 = v135;
    v266 = qcar(v34);
    v34 = elt(env, 3); /* intfn */
    v34 = Lflagp(nil, v266, v34);
    env = stack[0];
    if (v34 == nil) goto v95;
    v34 = v135;
    v34 = qcdr(v34);
    {
        popv(1);
        fn = elt(env, 4); /* intexprlisp */
        return (*qfn2(fn))(qenv(fn), v34, v129);
    }

v95:
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v34); }

v44:
    v34 = v135;
    if (is_number(v34)) goto v325;
    v34 = v135;
    v34 = Latsoc(nil, v34, v129);
    v135 = v34;
    if (v34 == nil) goto v75;
    v34 = v135;
    v34 = qcdr(v34);
    v129 = elt(env, 1); /* integer */
    v34 = (v34 == v129 ? lisp_true : nil);
    { popv(1); return onevalue(v34); }

v75:
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v34); }

v325:
    v34 = v135;
    v34 = integerp(v34);
    { popv(1); return onevalue(v34); }
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsqxx");
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
    v112 = v0;
/* end of prologue */
    v97 = qvalue(elt(env, 1)); /* !*intstr */
    if (v97 == nil) goto v62;
    v97 = v112;
    fn = elt(env, 4); /* prepsq!* */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    goto v3;

v3:
    v112 = v97;
    v97 = v112;
    v113 = elt(env, 3); /* minus */
    if (!consp(v97)) { popv(1); return onevalue(v112); }
    v97 = qcar(v97);
    if (!(v97 == v113)) { popv(1); return onevalue(v112); }
    v97 = v112;
    v97 = qcdr(v97);
    v97 = qcar(v97);
    if (!(is_number(v97))) { popv(1); return onevalue(v112); }
    v97 = v112;
    v97 = qcdr(v97);
    v97 = qcar(v97);
    popv(1);
    return negate(v97);

v62:
    v97 = v112;
    v97 = qcar(v97);
    if (v97 == nil) goto v64;
    v97 = elt(env, 2); /* prepf */
    fn = elt(env, 5); /* sqform */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    goto v3;

v64:
    v97 = (Lisp_Object)1; /* 0 */
    goto v3;
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for list!+list */

static Lisp_Object CC_listLlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list+list");
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
    goto v101;

v101:
    v71 = stack[-1];
    if (v71 == nil) goto v62;
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = stack[0];
    v71 = qcar(v71);
    fn = elt(env, 1); /* !:plus */
    v72 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v71 = stack[-2];
    v71 = cons(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-2] = v71;
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v101;

v62:
    v71 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v93 = qvalue(elt(env, 2)); /* nil */
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    qvalue(elt(env, 1)) = v93; /* alglist!* */
    v93 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v93;
    v93 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v93; /* subfg!* */
    v95 = elt(env, 4); /* !0 */
    v94 = (Lisp_Object)1; /* 0 */
    v93 = stack[-1];
    v93 = Lsubst(nil, 3, v95, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    stack[-1] = v93;
    v93 = stack[-1];
    fn = elt(env, 6); /* simp */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v94 = v93;
    v93 = v94;
    v93 = qcar(v93);
    if (v93 == nil) goto v43;
    v93 = elt(env, 5); /* prepf */
    fn = elt(env, 7); /* sqform */
    v93 = (*qfn2(fn))(qenv(fn), v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    goto v42;

v42:
    v94 = v93;
    v93 = stack[-2];
    qvalue(elt(env, 3)) = v93; /* subfg!* */
    v93 = v94;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v93); }

v43:
    v93 = (Lisp_Object)1; /* 0 */
    goto v42;
/* error exit handlers */
v124:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v102, v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for has_parents");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v100 = v0;
/* end of prologue */
    v100 = qcdr(v100);
    v100 = qcar(v100);
    v134 = v100;
    v100 = v134;
    v102 = qcar(v100);
    v100 = elt(env, 1); /* !? */
    if (v102 == v100) goto v53;
    v100 = v134;
    v100 = qcdr(v100);
    v102 = elt(env, 1); /* !? */
        return Lneq(nil, v100, v102);

v53:
    v100 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v100);
}



/* Code for begin1 */

static Lisp_Object MS_CDECL CC_begin1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v357, v186, v358;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "begin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin1");
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
    v357 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    qvalue(elt(env, 1)) = v357; /* otime!* */
    v357 = elt(env, 2); /* gctime */
    fn = elt(env, 57); /* getd */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    if (v357 == nil) goto v40;
    v357 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    qvalue(elt(env, 3)) = v357; /* ogctime!* */
    goto v65;

v65:
    v357 = elt(env, 4); /* !*semicol!* */
    qvalue(elt(env, 5)) = v357; /* cursym!* */
    goto v101;

v101:
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v70;
    v357 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v357 == nil)) goto v70;
    v357 = qvalue(elt(env, 8)); /* !*nosave!* */
    if (!(v357 == nil)) goto v84;
    v186 = qvalue(elt(env, 9)); /* statcounter */
    v357 = (Lisp_Object)1; /* 0 */
    if (v186 == v357) goto v84;
    fn = elt(env, 58); /* add2buflis */
    v357 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v84;

v84:
    fn = elt(env, 59); /* update_prompt */
    v357 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v70;

v70:
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 8)) = v357; /* !*nosave!* */
    v357 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 11)) = v357; /* !*strind */
    v357 = qvalue(elt(env, 10)); /* nil */
    stack[-2] = v357;
    v357 = qvalue(elt(env, 12)); /* !*time */
    if (v357 == nil) goto v113;
    v357 = elt(env, 13); /* (showtime) */
    fn = elt(env, 60); /* eval */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v113;

v113:
    v357 = qvalue(elt(env, 14)); /* !*output */
    if (v357 == nil) goto v35;
    v357 = qvalue(elt(env, 15)); /* ofl!* */
    if (!(v357 == nil)) goto v35;
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v35;
    v357 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v357 == nil)) goto v35;
    v357 = qvalue(elt(env, 16)); /* !*defn */
    if (!(v357 == nil)) goto v35;
    v357 = qvalue(elt(env, 17)); /* !*lessspace */
    if (!(v357 == nil)) goto v35;
    v357 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v35;

v35:
    v357 = qvalue(elt(env, 18)); /* tslin!* */
    if (v357 == nil) goto v57;
    v357 = qvalue(elt(env, 18)); /* tslin!* */
    v357 = qcar(v357);
    qvalue(elt(env, 19)) = v357; /* !*slin */
    v357 = qvalue(elt(env, 18)); /* tslin!* */
    v357 = qcdr(v357);
    qvalue(elt(env, 20)) = v357; /* lreadfn!* */
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 18)) = v357; /* tslin!* */
    goto v57;

v57:
    v357 = qvalue(elt(env, 21)); /* initl!* */
    stack[-1] = v357;
    goto v69;

v69:
    v357 = stack[-1];
    if (v357 == nil) goto v317;
    v357 = stack[-1];
    stack[0] = qcar(v357);
    v357 = stack[-1];
    v186 = qcar(v357);
    v357 = elt(env, 22); /* initl */
    v357 = get(v186, v357);
    env = stack[-3];
    fn = elt(env, 60); /* eval */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v357 = Lset(nil, stack[0], v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v357 = stack[-1];
    v357 = qcdr(v357);
    stack[-1] = v357;
    goto v69;

v317:
    v186 = qvalue(elt(env, 23)); /* forkeywords!* */
    v357 = elt(env, 24); /* delim */
    v357 = Lremflag(nil, v186, v357);
    env = stack[-3];
    v186 = qvalue(elt(env, 25)); /* repeatkeywords!* */
    v357 = elt(env, 24); /* delim */
    v357 = Lremflag(nil, v186, v357);
    env = stack[-3];
    v186 = qvalue(elt(env, 26)); /* whilekeywords!* */
    v357 = elt(env, 24); /* delim */
    v357 = Lremflag(nil, v186, v357);
    env = stack[-3];
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v360;
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v357; /* erfg!* */
    goto v360;

v360:
    v186 = qvalue(elt(env, 5)); /* cursym!* */
    v357 = elt(env, 28); /* end */
    if (v186 == v357) goto v361;
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v362;
    v357 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v357 == nil)) goto v362;
    v186 = qvalue(elt(env, 29)); /* key!* */
    v357 = elt(env, 30); /* ed */
    if (v186 == v357) goto v362;
    v357 = qvalue(elt(env, 31)); /* promptexp!* */
    fn = elt(env, 61); /* printprompt */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v362;

v362:
    v358 = elt(env, 32); /* (command) */
    v186 = qvalue(elt(env, 33)); /* t */
    v357 = qvalue(elt(env, 34)); /* !*backtrace */
    fn = elt(env, 62); /* errorset */
    v357 = (*qfnn(fn))(qenv(fn), 3, v358, v186, v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    stack[-1] = v357;
    v357 = qvalue(elt(env, 14)); /* !*output */
    if (v357 == nil) goto v363;
    v357 = qvalue(elt(env, 35)); /* !*echo */
    if (v357 == nil) goto v363;
    v357 = qvalue(elt(env, 36)); /* !*extraecho */
    if (v357 == nil) goto v363;
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v364;
    v357 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v357 == nil)) goto v364;

v363:
    v357 = stack[-1];
    if (!consp(v357)) goto v365;
    v357 = stack[-1];
    v357 = qcdr(v357);
    if (!(v357 == nil)) goto v365;
    v357 = stack[-1];
    v357 = qcar(v357);
    stack[-1] = v357;
    v357 = stack[-1];
    v186 = qcar(v357);
    v357 = elt(env, 38); /* symbolic */
    if (!(v186 == v357)) goto v56;
    v357 = stack[-1];
    v357 = qcdr(v357);
    v186 = qcar(v357);
    v357 = elt(env, 39); /* xmodule */
    if (!consp(v186)) goto v56;
    v186 = qcar(v186);
    if (!(v186 == v357)) goto v56;
    v357 = stack[-1];
    v357 = qcdr(v357);
    v357 = qcar(v357);
    fn = elt(env, 60); /* eval */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    fn = elt(env, 63); /* xmodloop */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v358 = v357;
    goto v4;

v4:
    v357 = v358;
    if (v357 == nil) goto v101;
    v186 = v358;
    v357 = elt(env, 28); /* end */
    if (v186 == v357) goto v250;
    v186 = v358;
    v357 = elt(env, 40); /* err2 */
    if (v186 == v357) goto v325;
    v186 = v358;
    v357 = elt(env, 41); /* err3 */
    if (!(v186 == v357)) goto v53;

v63:
    v357 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 27)) = v357; /* erfg!* */
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (!(v357 == nil)) goto v226;
    v357 = qvalue(elt(env, 54)); /* !*errcont */
    if (!(v357 == nil)) goto v226;
    v357 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 16)) = v357; /* !*defn */
    v357 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 35)) = v357; /* !*echo */
    v357 = qvalue(elt(env, 55)); /* cmsg!* */
    if (!(v357 == nil)) goto v366;
    v357 = elt(env, 56); /* "Continuing with parsing only ..." */
    fn = elt(env, 64); /* lprie */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v366;

v366:
    v357 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 55)) = v357; /* cmsg!* */
    goto v101;

v226:
    v357 = qvalue(elt(env, 54)); /* !*errcont */
    if (v357 == nil) goto v367;
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v357; /* erfg!* */
    goto v101;

v367:
    v357 = stack[-2];
    fn = elt(env, 65); /* pause1 */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v358 = v357;
    v357 = v358;
    if (v357 == nil) goto v368;
    v357 = v358;
    fn = elt(env, 60); /* eval */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    v357 = (v357 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v357); }

v368:
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v357; /* erfg!* */
    goto v101;

v53:
    v357 = qvalue(elt(env, 42)); /* crbuf1!* */
    if (v357 == nil) goto v369;
    v357 = qvalue(elt(env, 43)); /* !*msg */
    if (v357 == nil) goto v242;
    v186 = elt(env, 44); /* "***" */
    v357 = elt(env, 45); /* "Closing object improperly removed. Redo edit." 
*/
    fn = elt(env, 66); /* lpriw */
    v357 = (*qfn2(fn))(qenv(fn), v186, v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v242;

v242:
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 42)) = v357; /* crbuf1!* */
    v357 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v357); }

v369:
    v186 = qvalue(elt(env, 46)); /* eof!* */
    v357 = (Lisp_Object)65; /* 4 */
    v357 = (Lisp_Object)greaterp2(v186, v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    v357 = v357 ? lisp_true : nil;
    env = stack[-3];
    if (v357 == nil) goto v370;
    v357 = qvalue(elt(env, 43)); /* !*msg */
    if (v357 == nil) goto v371;
    v186 = elt(env, 44); /* "***" */
    v357 = elt(env, 47); /* "End-of-file read" */
    fn = elt(env, 66); /* lpriw */
    v357 = (*qfn2(fn))(qenv(fn), v186, v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v371;

v371:
    v357 = elt(env, 48); /* (bye) */
    {
        popv(4);
        fn = elt(env, 60); /* eval */
        return (*qfn1(fn))(qenv(fn), v357);
    }

v370:
    v357 = qvalue(elt(env, 6)); /* !*int */
    if (v357 == nil) goto v234;
    v357 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v357 == nil)) goto v234;
    v357 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 49)) = v357; /* crbuf!* */
    v357 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 8)) = v357; /* !*nosave!* */
    goto v101;

v234:
    v357 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v357); }

v325:
    v357 = qvalue(elt(env, 19)); /* !*slin */
    if (!(v357 == nil)) goto v63;
    v357 = qvalue(elt(env, 33)); /* t */
    fn = elt(env, 67); /* comm1 */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v63;

v250:
    v357 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v357); }

v56:
    v357 = stack[-1];
    fn = elt(env, 68); /* begin11 */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v358 = v357;
    goto v4;

v365:
    v186 = qvalue(elt(env, 50)); /* program!* */
    v357 = qvalue(elt(env, 51)); /* !$eof!$ */
    if (!(v186 == v357)) goto v372;
    v186 = qvalue(elt(env, 52)); /* ttype!* */
    v357 = (Lisp_Object)49; /* 3 */
    if (!(v186 == v357)) goto v372;
    v357 = qvalue(elt(env, 46)); /* eof!* */
    v357 = add1(v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    qvalue(elt(env, 46)) = v357; /* eof!* */
    if (!(v357 == nil)) goto v53;

v372:
    v186 = qvalue(elt(env, 46)); /* eof!* */
    v357 = (Lisp_Object)1; /* 0 */
    v357 = (Lisp_Object)greaterp2(v186, v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    v357 = v357 ? lisp_true : nil;
    env = stack[-3];
    if (!(v357 == nil)) goto v53;
    v186 = stack[-1];
    v357 = elt(env, 53); /* "BEGIN invalid" */
    if (equal(v186, v357)) goto v101;
    v357 = qvalue(elt(env, 33)); /* t */
    stack[-2] = v357;
    goto v325;

v364:
    v357 = qvalue(elt(env, 16)); /* !*defn */
    if (!(v357 == nil)) goto v363;
    v357 = qvalue(elt(env, 37)); /* !*demo */
    if (!(v357 == nil)) goto v363;
    v357 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    goto v363;

v361:
    v357 = elt(env, 28); /* end */
    fn = elt(env, 67); /* comm1 */
    v357 = (*qfn1(fn))(qenv(fn), v357);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-3];
    v357 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v357); }

v40:
    v357 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v357; /* ogctime!* */
    goto v65;
/* error exit handlers */
v359:
    popv(4);
    return nil;
}



/* Code for red!-weight!-less!-p */

static Lisp_Object CC_redKweightKlessKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v39, v38, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v1;
    v38 = v0;
/* end of prologue */
    v72 = v38;
    v16 = qcar(v72);
    v72 = v39;
    v72 = qcar(v72);
    if (equal(v16, v72)) goto v73;
    v72 = v38;
    v72 = qcar(v72);
    v39 = qcar(v39);
        return Llessp(nil, v72, v39);

v73:
    v72 = v38;
    v72 = qcdr(v72);
    v39 = qcdr(v39);
        return Llessp(nil, v72, v39);
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v376, v377, v378, v350;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
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
    v377 = v1;
    v378 = v0;
/* end of prologue */
    v350 = v378;
    v376 = (Lisp_Object)17; /* 1 */
    if (v350 == v376) goto v44;
    v350 = v377;
    v376 = (Lisp_Object)17; /* 1 */
    if (v350 == v376) goto v44;
    v376 = v378;
    if (!consp(v376)) goto v68;
    v376 = v377;
    if (!consp(v376)) goto v80;
    v376 = v378;
    v350 = qcar(v376);
    v376 = elt(env, 1); /* field */
    v376 = Lflagp(nil, v350, v376);
    env = stack[0];
    if (!(v376 == nil)) goto v27;
    v376 = v377;
    v350 = qcar(v376);
    v376 = elt(env, 1); /* field */
    v376 = Lflagp(nil, v350, v376);
    env = stack[0];
    if (!(v376 == nil)) goto v27;
    v376 = elt(env, 2); /* gcd */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v378, v377, v376);
    }

v27:
    v376 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v376); }

v80:
    v376 = v378;
    v350 = qcar(v376);
    v376 = elt(env, 1); /* field */
    v376 = Lflagp(nil, v350, v376);
    env = stack[0];
    if (v376 == nil) goto v108;
    v376 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v376); }

v108:
    v376 = elt(env, 2); /* gcd */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v378, v377, v376);
    }

v68:
    v376 = v377;
    if (!consp(v376)) goto v84;
    v376 = v377;
    if (!consp(v376)) goto v35;
    v376 = v377;
    v350 = qcar(v376);
    v376 = elt(env, 1); /* field */
    v376 = Lflagp(nil, v350, v376);
    env = stack[0];
    if (v376 == nil) goto v35;
    v376 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v376); }

v35:
    v376 = elt(env, 2); /* gcd */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v378, v377, v376);
    }

v84:
    v376 = v378;
        popv(1);
        return Lgcd(nil, v376, v377);

v44:
    v376 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v376); }
}



/* Code for b!:extmult */

static Lisp_Object CC_bTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extmult");
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
    v22 = stack[-3];
    if (v22 == nil) goto v44;
    v22 = stack[-2];
    if (v22 == nil) goto v44;
    v23 = stack[-2];
    v22 = (Lisp_Object)17; /* 1 */
    if (v23 == v22) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v22 = stack[-3];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v23 = qcar(v22);
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcar(v22);
    fn = elt(env, 2); /* b!:ordexn */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v23 = v22;
    v22 = v23;
    if (v22 == nil) goto v354;
    v22 = v23;
    stack[-4] = qcdr(v22);
    v22 = v23;
    v22 = qcar(v22);
    if (v22 == nil) goto v81;
    v22 = stack[-3];
    v22 = qcar(v22);
    v23 = qcdr(v22);
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 3); /* multf */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    fn = elt(env, 4); /* negf */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-1] = v22;
    goto v87;

v87:
    v22 = stack[-3];
    v22 = qcar(v22);
    v23 = ncons(v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[0] = CC_bTextmult(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v22 = stack[-3];
    v23 = qcdr(v22);
    v22 = stack[-2];
    v22 = CC_bTextmult(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    fn = elt(env, 5); /* b!:extadd */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    {
        Lisp_Object v380 = stack[-4];
        Lisp_Object v360 = stack[-1];
        popv(6);
        return acons(v380, v360, v22);
    }

v81:
    v22 = stack[-3];
    v22 = qcar(v22);
    v23 = qcdr(v22);
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 3); /* multf */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-1] = v22;
    goto v87;

v354:
    v22 = stack[-3];
    v23 = qcdr(v22);
    v22 = stack[-2];
    stack[0] = CC_bTextmult(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v22 = stack[-3];
    v22 = qcar(v22);
    v23 = ncons(v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v22 = stack[-2];
    v22 = qcdr(v22);
    v22 = CC_bTextmult(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    {
        Lisp_Object v381 = stack[0];
        popv(6);
        fn = elt(env, 5); /* b!:extadd */
        return (*qfn2(fn))(qenv(fn), v381, v22);
    }

v44:
    v22 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v22); }
/* error exit handlers */
v361:
    popv(6);
    return nil;
}



/* Code for sfto_tsqsumf */

static Lisp_Object CC_sfto_tsqsumf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_tsqsumf");
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

v82:
    v113 = stack[0];
    if (!consp(v113)) goto v69;
    v113 = stack[0];
    v113 = qcar(v113);
    if (!consp(v113)) goto v69;
    v113 = stack[0];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = qcdr(v113);
    v113 = Levenp(nil, v113);
    env = stack[-1];
    if (v113 == nil) goto v96;
    v113 = stack[0];
    v113 = qcar(v113);
    v113 = qcdr(v113);
    v113 = CC_sfto_tsqsumf(env, v113);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    if (v113 == nil) goto v111;
    v113 = stack[0];
    v113 = qcdr(v113);
    stack[0] = v113;
    goto v82;

v111:
    v113 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v113); }

v96:
    v113 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v113); }

v69:
    v113 = stack[0];
    if (v113 == nil) goto v74;
    v113 = stack[0];
    fn = elt(env, 4); /* minusf */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    if (v113 == nil) goto v40;
    v113 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v113); }

v40:
    v113 = elt(env, 2); /* stsq */
    { popv(2); return onevalue(v113); }

v74:
    v113 = elt(env, 1); /* tsq */
    { popv(2); return onevalue(v113); }
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp1");
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
    v96 = v1;
    v112 = v0;
/* end of prologue */
    v97 = v112;
    v97 = qcar(v97);
    if (v97 == v96) goto v83;
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v96); }

v83:
    v96 = v112;
    v97 = qcdr(v96);
    v96 = (Lisp_Object)17; /* 1 */
    if (v97 == v96) goto v74;
    v96 = v112;
    stack[-1] = qcdr(v96);
    v96 = v112;
    stack[0] = qcar(v96);
    v96 = v112;
    v96 = qcdr(v96);
    v97 = sub1(v96);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v96 = (Lisp_Object)17; /* 1 */
    v96 = acons(stack[0], v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    {
        Lisp_Object v322 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* multd */
        return (*qfn2(fn))(qenv(fn), v322, v96);
    }

v74:
    v96 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v96); }
/* error exit handlers */
v77:
    popv(3);
    return nil;
}



/* Code for ev_tdeg */

static Lisp_Object CC_ev_tdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v41, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_tdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v43 = (Lisp_Object)1; /* 0 */
    goto v53;

v53:
    v104 = v41;
    if (v104 == nil) return onevalue(v43);
    v104 = v41;
    v104 = qcar(v104);
    v43 = (Lisp_Object)(int32_t)((int32_t)v104 + (int32_t)v43 - TAG_FIXNUM);
    v41 = qcdr(v41);
    goto v53;
}



/* Code for omvir */

static Lisp_Object MS_CDECL CC_omvir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omvir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omvir");
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
    v112 = qvalue(elt(env, 1)); /* atts */
    v97 = elt(env, 2); /* name */
    fn = elt(env, 6); /* find */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    stack[0] = v97;
    v112 = qvalue(elt(env, 1)); /* atts */
    v97 = elt(env, 3); /* hex */
    fn = elt(env, 6); /* find */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    if (v97 == nil) goto v71;
    v112 = elt(env, 4); /* "wrong att" */
    v97 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    goto v71;

v71:
    v112 = qvalue(elt(env, 1)); /* atts */
    v97 = elt(env, 5); /* dec */
    fn = elt(env, 6); /* find */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    if (v97 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v112 = elt(env, 4); /* "wrong att" */
    v97 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v97 = (*qfn2(fn))(qenv(fn), v112, v97);
    nil = C_nil;
    if (exception_pending()) goto v76;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



setup_type const u10_setup[] =
{
    {"exchk1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exchk1},
    {"rl_simpat",               CC_rl_simpat,   too_many_1,    wrong_no_1},
    {"naryrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_naryrd},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"flatindxl",               CC_flatindxl,   too_many_1,    wrong_no_1},
    {"fortranop",               CC_fortranop,   too_many_1,    wrong_no_1},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"lpriw",                   too_few_2,      CC_lpriw,      wrong_no_2},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"raiseind:",               CC_raiseindT,   too_many_1,    wrong_no_1},
    {"ordexn",                  too_few_2,      CC_ordexn,     wrong_no_2},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,too_many_1,wrong_no_1},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"ps:putv",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTputv},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"getmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getmat},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"deletemult*",             CC_deletemultH, too_many_1,    wrong_no_1},
    {"contr2-strand",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2Kstrand},
    {"copyd",                   too_few_2,      CC_copyd,      wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,too_many_1, wrong_no_1},
    {"cl_susiminlevel",         too_few_2,      CC_cl_susiminlevel,wrong_no_2},
    {"ibalp_getnewwl",          CC_ibalp_getnewwl,too_many_1,  wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"sub_math",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_sub_math},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"intexprnp",               too_few_2,      CC_intexprnp,  wrong_no_2},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"list+list",               too_few_2,      CC_listLlist,  wrong_no_2},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"begin1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_begin1},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"sfto_tsqsumf",            CC_sfto_tsqsumf,too_many_1,    wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"ev_tdeg",                 CC_ev_tdeg,     too_many_1,    wrong_no_1},
    {"omvir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omvir},
    {NULL, (one_args *)"u10", (two_args *)"22970 9542535 8502087", 0}
};

/* end of generated code */
